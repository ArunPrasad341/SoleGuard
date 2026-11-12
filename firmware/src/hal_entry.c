#include "hal_data.h"
#include <stdio.h>
#include <string.h>
#include "r_ble_sgs.h"

#if defined(__has_include)
 #if __has_include("RTT/SEGGER_RTT.h")
  #include "RTT/SEGGER_RTT.h"
  #define SOLEGUARD_HAVE_RTT    (1)
 #endif
#endif

#ifndef SOLEGUARD_HAVE_RTT
 #warning "SEGGER RTT not found in src/RTT - dbg_print() output is disabled"
#endif

#define TICKS_PER_SECOND    (100U)
#define ADC_SCAN_TIMEOUT    (100000U)

/* I2C addresses */
#define MPU6050_ADDR   (0x68U)
#define MAX30102_ADDR  (0x57U)
#define HS4001_ADDR    (0x44U)

void app_main(void);
extern uint16_t g_conn_hdl;

/* ── Globals: watch all of these in Expressions panel ── */
uint16_t          g_fsr1       = 0;
uint16_t          g_fsr2       = 0;
volatile uint32_t g_tick       = 0;
int16_t           g_accel_x    = 0;
int16_t           g_accel_y    = 0;
int16_t           g_accel_z    = 0;
int16_t           g_gyro_x     = 0;
int16_t           g_gyro_y     = 0;
int16_t           g_gyro_z     = 0;
uint32_t          g_heart_rate = 0;
uint32_t          g_spo2_ir    = 0;
float             g_temperature = 0.0f;
float             g_humidity    = 0.0f;

static const adc_channel_cfg_t g_fsr_channel_cfg =
{
    .scan_mask          = ADC_MASK_CHANNEL_0 | ADC_MASK_CHANNEL_1,
    .scan_mask_group_b  = 0,
    .priority_group_a   = ADC_GROUP_A_PRIORITY_OFF,
    .add_mask           = 0,
    .sample_hold_mask   = 0,
    .sample_hold_states = 24,
    .p_window_cfg       = NULL,
};

void SysTick_Handler(void) { g_tick++; }

static void dbg_print(const char *message)
{
#ifdef SOLEGUARD_HAVE_RTT
    SEGGER_RTT_WriteString(0, message);
#else
    FSP_PARAMETER_NOT_USED(message);
#endif
}

static void dbg_check(const char *label, fsp_err_t err)
{
    char msg[64];
    if (FSP_SUCCESS == err)
        snprintf(msg, sizeof(msg), "%s: OK\r\n", label);
    else
        snprintf(msg, sizeof(msg), "%s: FAILED err=%d\r\n", label, (int) err);
    dbg_print(msg);
}

/* ────────────────────────────────────────────────────────────────
   I2C helpers
   ──────────────────────────────────────────────────────────────── */
static volatile bool g_i2c_done  = false;
static volatile bool g_i2c_error = false;

void sci_i2c_master_callback(i2c_master_callback_args_t * p_args)
{
    if (I2C_MASTER_EVENT_TX_COMPLETE == p_args->event ||
        I2C_MASTER_EVENT_RX_COMPLETE == p_args->event)
        g_i2c_done = true;
    else
        g_i2c_error = true;
}

static bool i2c_wait(void)
{
	uint32_t t = 10000U;
    while (!g_i2c_done && !g_i2c_error && --t) {}
    bool ok = g_i2c_done && !g_i2c_error;
    g_i2c_done = g_i2c_error = false;
    return ok;
}

static bool i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t val)
{
    uint8_t buf[2] = {reg, val};
    g_i2c0.p_api->slaveAddressSet(g_i2c0.p_ctrl, addr, I2C_MASTER_ADDR_MODE_7BIT);
    g_i2c0.p_api->write(g_i2c0.p_ctrl, buf, 2, false);
    return i2c_wait();
}

static bool i2c_read_regs(uint8_t addr, uint8_t reg, uint8_t * buf, uint32_t len)
{
    g_i2c0.p_api->slaveAddressSet(g_i2c0.p_ctrl, addr, I2C_MASTER_ADDR_MODE_7BIT);
    g_i2c0.p_api->write(g_i2c0.p_ctrl, &reg, 1, true);
    if (!i2c_wait()) return false;
    g_i2c0.p_api->read(g_i2c0.p_ctrl, buf, len, false);
    return i2c_wait();
}

/* ────────────────────────────────────────────────────────────────
   FSR (ADC)
   ──────────────────────────────────────────────────────────────── */
static void fsr_read(void)
{
    adc_status_t status;
    uint32_t     timeout = ADC_SCAN_TIMEOUT;

    if (FSP_SUCCESS != R_ADC_ScanStart(&g_adc0_ctrl))
    {
        dbg_print("ADC scan start failed\r\n");
        return;
    }
    do { R_ADC_StatusGet(&g_adc0_ctrl, &status); }
    while ((ADC_STATE_SCAN_IN_PROGRESS == status.state) && (--timeout > 0U));

    if (0U == timeout) { dbg_print("ADC timeout\r\n"); return; }

    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_0, &g_fsr1);
    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_1, &g_fsr2);
}

/* ────────────────────────────────────────────────────────────────
   MPU6050
   ──────────────────────────────────────────────────────────────── */
static void mpu6050_read(void)
{
    uint8_t raw[14];
    if (!i2c_read_regs(MPU6050_ADDR, 0x3B, raw, 14)) return;
    g_accel_x = (int16_t)((raw[0]  << 8) | raw[1]);
    g_accel_y = (int16_t)((raw[2]  << 8) | raw[3]);
    g_accel_z = (int16_t)((raw[4]  << 8) | raw[5]);
    g_gyro_x  = (int16_t)((raw[8]  << 8) | raw[9]);
    g_gyro_y  = (int16_t)((raw[10] << 8) | raw[11]);
    g_gyro_z  = (int16_t)((raw[12] << 8) | raw[13]);
}

/* ────────────────────────────────────────────────────────────────
   MAX30102
   ──────────────────────────────────────────────────────────────── */
static void max30102_read(void)
{
    uint8_t raw[6];
    if (!i2c_read_regs(MAX30102_ADDR, 0x07, raw, 6)) return;
    g_heart_rate = ((uint32_t)(raw[0] & 0x03) << 16) | ((uint32_t)raw[1] << 8) | raw[2];
    g_spo2_ir    = ((uint32_t)(raw[3] & 0x03) << 16) | ((uint32_t)raw[4] << 8) | raw[5];
}

/* ────────────────────────────────────────────────────────────────
   HS4001
   ──────────────────────────────────────────────────────────────── */
static void hs4001_read(void)
{
    uint8_t dummy = 0;
    g_i2c0.p_api->slaveAddressSet(g_i2c0.p_ctrl, HS4001_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    g_i2c0.p_api->write(g_i2c0.p_ctrl, &dummy, 1, false);
    i2c_wait();
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

    uint8_t raw[4];
    g_i2c0.p_api->slaveAddressSet(g_i2c0.p_ctrl, HS4001_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    g_i2c0.p_api->read(g_i2c0.p_ctrl, raw, 4, false);
    if (!i2c_wait()) return;

    uint16_t rh_raw   = (uint16_t)(((raw[0] & 0x3F) << 8) | raw[1]);
    uint16_t temp_raw = (uint16_t)((raw[2] << 6) | (raw[3] >> 2));
    g_humidity    = (float)rh_raw   / 16383.0f * 100.0f;
    g_temperature = (float)temp_raw / 16383.0f * 165.0f - 40.0f;
}

/* ────────────────────────────────────────────────────────────────
   BLE notify
   ──────────────────────────────────────────────────────────────── */
static void ble_send_sensors(void)
{
    if (BLE_GAP_INVALID_CONN_HDL == g_conn_hdl) return;

    char buf[80];
    snprintf(buf, sizeof(buf),
             "F1:%u,F2:%u,AX:%d,AY:%d,AZ:%d,T:%.1f,H:%.1f,HR:%lu,IR:%lu\r\n",
             g_fsr1, g_fsr2,
             g_accel_x, g_accel_y, g_accel_z,
             (double)g_temperature, (double)g_humidity,
             (unsigned long)g_heart_rate, (unsigned long)g_spo2_ir);

    st_ble_sgs_press_t press = {0};
    snprintf(press.text, sizeof(press.text), "%s", buf);
    R_BLE_SGS_SetPress(&press);
    R_BLE_SGS_NotifyPress(g_conn_hdl, &press);
}

/* ────────────────────────────────────────────────────────────────
   Public API called from app_main.c
   ──────────────────────────────────────────────────────────────── */
void sensors_init(void)
{
    dbg_print("sensors_init() reached\r\n");
    dbg_check("ADC open",     R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg));
    dbg_check("ADC scan cfg", R_ADC_ScanCfg(&g_adc0_ctrl, &g_fsr_channel_cfg));
    // dbg_check("I2C open", (fsp_err_t) g_i2c0.p_api->open(g_i2c0.p_ctrl, g_i2c0.p_cfg));

    /* Wake MPU6050 from sleep */
    // i2c_write_reg(MPU6050_ADDR, 0x6B, 0x00);

    /* MAX30102 config */
    // i2c_write_reg(MAX30102_ADDR, 0x09, 0x03);
    // i2c_write_reg(MAX30102_ADDR, 0x0A, 0x27);
    // i2c_write_reg(MAX30102_ADDR, 0x0C, 0x24);
    // i2c_write_reg(MAX30102_ADDR, 0x0D, 0x24);

    SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);
    dbg_print("SysTick started (10 ms)\r\n");
}

void sensors_task(void)
{
    static uint32_t last = 0;
    if ((g_tick - last) < TICKS_PER_SECOND) return;
    last = g_tick;

    fsr_read();
    // mpu6050_read();
    // max30102_read();
    // hs4001_read();

    char line[80];
    snprintf(line, sizeof(line),
             "FSR1:%u FSR2:%u AX:%d AY:%d AZ:%d T:%.1f H:%.1f\r\n",
             g_fsr1, g_fsr2,
             g_accel_x, g_accel_y, g_accel_z,
             (double)g_temperature, (double)g_humidity);
    dbg_print(line);

    // ble_send_sensors();
}

void hal_entry(void)
{
    dbg_print("\r\nSoleGuard boot (BGK-RA6E2, bare metal)\r\n");
    sensors_init();
       while (1)
       {
           sensors_task();
       }
}
