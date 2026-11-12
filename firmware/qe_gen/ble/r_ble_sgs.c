/* 
* Copyright (c) 2019 - 2025 Renesas Electronics Corporation and/or its affiliates 
* 
* SPDX-License-Identifier: BSD-3-Clause 
*/
/***********************************************************************************************************************
 * File Name: r_ble_sgs.c
 * Version : 1.0
 * Description : The source file for SoleGuard service.
 **********************************************************************************************************************/

#include "r_ble_sgs.h"
#include "profile_cmn/r_ble_servs_if.h"
#include "gatt_db.h"

static st_ble_servs_info_t gs_servs_info;

/*----------------------------------------------------------------------------------------------------------------------
    pressure Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

static const st_ble_servs_desc_info_t gs_press_cli_cnfg = {
    .attr_hdl = BLE_SGS_PRESS_CLI_CNFG_DESC_HDL,
    .app_size = sizeof(uint16_t),
    .desc_idx = BLE_SGS_PRESS_CLI_CNFG_IDX,
    .db_size  = BLE_SGS_PRESS_CLI_CNFG_LEN,
    .decode   = (ble_servs_attr_decode_t)decode_uint16_t,
    .encode   = (ble_servs_attr_encode_t)encode_uint16_t,
};

ble_status_t R_BLE_SGS_SetPressCliCnfg(uint16_t conn_hdl, const uint16_t *p_value)
{
    return R_BLE_SERVS_SetDesc(&gs_press_cli_cnfg, conn_hdl, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetPressCliCnfg(uint16_t conn_hdl, uint16_t *p_value)
{
    return R_BLE_SERVS_GetDesc(&gs_press_cli_cnfg, conn_hdl, (void *)p_value);
}

/*----------------------------------------------------------------------------------------------------------------------
    pressure characteristic
----------------------------------------------------------------------------------------------------------------------*/

static ble_status_t decode_st_ble_sgs_press_t(st_ble_sgs_press_t *p_app_value, const st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for pressure characteristic value decode function. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

static ble_status_t encode_st_ble_sgs_press_t(const st_ble_sgs_press_t *p_app_value, st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for pressure characteristic value encode function. Do not edit comment generated here */
    for (uint16_t i = 0; i < BLE_SGS_PRESS_LEN; i++) { p_gatt_value->p_value[i] = (uint8_t) p_app_value->text[i]; }
    p_gatt_value->value_len = BLE_SGS_PRESS_LEN;
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

/* pressure characteristic descriptor definition */
static const st_ble_servs_desc_info_t *gspp_press_descs[] = { 
    &gs_press_cli_cnfg,
};

/* pressure characteristic definition */
static const st_ble_servs_char_info_t gs_press_char = {
    .start_hdl    = BLE_SGS_PRESS_DECL_HDL,
    .end_hdl      = BLE_SGS_PRESS_CLI_CNFG_DESC_HDL,
    .char_idx     = BLE_SGS_PRESS_IDX,
    .app_size     = sizeof(st_ble_sgs_press_t),
    .db_size      = BLE_SGS_PRESS_LEN,
    .decode       = (ble_servs_attr_decode_t)decode_st_ble_sgs_press_t,
    .encode       = (ble_servs_attr_encode_t)encode_st_ble_sgs_press_t,
    .pp_descs     = gspp_press_descs,
    .num_of_descs = ARRAY_SIZE(gspp_press_descs),
};

ble_status_t R_BLE_SGS_SetPress(const st_ble_sgs_press_t *p_value)
{
    return R_BLE_SERVS_SetChar(&gs_press_char, BLE_GAP_INVALID_CONN_HDL, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetPress(st_ble_sgs_press_t *p_value)
{
    return R_BLE_SERVS_GetChar(&gs_press_char, BLE_GAP_INVALID_CONN_HDL, (void *)p_value);
}

ble_status_t R_BLE_SGS_NotifyPress(uint16_t conn_hdl, const st_ble_sgs_press_t *p_value)
{
    return R_BLE_SERVS_SendHdlVal(&gs_press_char, conn_hdl, (const void *)p_value, true);
}

/*----------------------------------------------------------------------------------------------------------------------
    vitals Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

static const st_ble_servs_desc_info_t gs_vital_cli_cnfg = {
    .attr_hdl = BLE_SGS_VITAL_CLI_CNFG_DESC_HDL,
    .app_size = sizeof(uint16_t),
    .desc_idx = BLE_SGS_VITAL_CLI_CNFG_IDX,
    .db_size  = BLE_SGS_VITAL_CLI_CNFG_LEN,
    .decode   = (ble_servs_attr_decode_t)decode_uint16_t,
    .encode   = (ble_servs_attr_encode_t)encode_uint16_t,
};

ble_status_t R_BLE_SGS_SetVitalCliCnfg(uint16_t conn_hdl, const uint16_t *p_value)
{
    return R_BLE_SERVS_SetDesc(&gs_vital_cli_cnfg, conn_hdl, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetVitalCliCnfg(uint16_t conn_hdl, uint16_t *p_value)
{
    return R_BLE_SERVS_GetDesc(&gs_vital_cli_cnfg, conn_hdl, (void *)p_value);
}

/*----------------------------------------------------------------------------------------------------------------------
    vitals characteristic
----------------------------------------------------------------------------------------------------------------------*/

static ble_status_t decode_st_ble_sgs_vital_t(st_ble_sgs_vital_t *p_app_value, const st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for vitals characteristic value decode function. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

static ble_status_t encode_st_ble_sgs_vital_t(const st_ble_sgs_vital_t *p_app_value, st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for vitals characteristic value encode function. Do not edit comment generated here */
    for (uint16_t i = 0; i < BLE_SGS_VITAL_LEN; i++) { p_gatt_value->p_value[i] = (uint8_t) p_app_value->text[i]; }
    p_gatt_value->value_len = BLE_SGS_VITAL_LEN;
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

/* vitals characteristic descriptor definition */
static const st_ble_servs_desc_info_t *gspp_vital_descs[] = { 
    &gs_vital_cli_cnfg,
};

/* vitals characteristic definition */
static const st_ble_servs_char_info_t gs_vital_char = {
    .start_hdl    = BLE_SGS_VITAL_DECL_HDL,
    .end_hdl      = BLE_SGS_VITAL_CLI_CNFG_DESC_HDL,
    .char_idx     = BLE_SGS_VITAL_IDX,
    .app_size     = sizeof(st_ble_sgs_vital_t),
    .db_size      = BLE_SGS_VITAL_LEN,
    .decode       = (ble_servs_attr_decode_t)decode_st_ble_sgs_vital_t,
    .encode       = (ble_servs_attr_encode_t)encode_st_ble_sgs_vital_t,
    .pp_descs     = gspp_vital_descs,
    .num_of_descs = ARRAY_SIZE(gspp_vital_descs),
};

ble_status_t R_BLE_SGS_SetVital(const st_ble_sgs_vital_t *p_value)
{
    return R_BLE_SERVS_SetChar(&gs_vital_char, BLE_GAP_INVALID_CONN_HDL, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetVital(st_ble_sgs_vital_t *p_value)
{
    return R_BLE_SERVS_GetChar(&gs_vital_char, BLE_GAP_INVALID_CONN_HDL, (void *)p_value);
}

ble_status_t R_BLE_SGS_NotifyVital(uint16_t conn_hdl, const st_ble_sgs_vital_t *p_value)
{
    return R_BLE_SERVS_SendHdlVal(&gs_vital_char, conn_hdl, (const void *)p_value, true);
}

/*----------------------------------------------------------------------------------------------------------------------
    Environment Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

static const st_ble_servs_desc_info_t gs_env_cli_cnfg = {
    .attr_hdl = BLE_SGS_ENV_CLI_CNFG_DESC_HDL,
    .app_size = sizeof(uint16_t),
    .desc_idx = BLE_SGS_ENV_CLI_CNFG_IDX,
    .db_size  = BLE_SGS_ENV_CLI_CNFG_LEN,
    .decode   = (ble_servs_attr_decode_t)decode_uint16_t,
    .encode   = (ble_servs_attr_encode_t)encode_uint16_t,
};

ble_status_t R_BLE_SGS_SetEnvCliCnfg(uint16_t conn_hdl, const uint16_t *p_value)
{
    return R_BLE_SERVS_SetDesc(&gs_env_cli_cnfg, conn_hdl, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetEnvCliCnfg(uint16_t conn_hdl, uint16_t *p_value)
{
    return R_BLE_SERVS_GetDesc(&gs_env_cli_cnfg, conn_hdl, (void *)p_value);
}

/*----------------------------------------------------------------------------------------------------------------------
    Environment characteristic
----------------------------------------------------------------------------------------------------------------------*/

static ble_status_t decode_st_ble_sgs_env_t(st_ble_sgs_env_t *p_app_value, const st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for Environment characteristic value decode function. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

static ble_status_t encode_st_ble_sgs_env_t(const st_ble_sgs_env_t *p_app_value, st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for Environment characteristic value encode function. Do not edit comment generated here */
    for (uint16_t i = 0; i < BLE_SGS_ENV_LEN; i++) { p_gatt_value->p_value[i] = (uint8_t) p_app_value->text[i]; }
    p_gatt_value->value_len = BLE_SGS_ENV_LEN;
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

/* Environment characteristic descriptor definition */
static const st_ble_servs_desc_info_t *gspp_env_descs[] = { 
    &gs_env_cli_cnfg,
};

/* Environment characteristic definition */
static const st_ble_servs_char_info_t gs_env_char = {
    .start_hdl    = BLE_SGS_ENV_DECL_HDL,
    .end_hdl      = BLE_SGS_ENV_CLI_CNFG_DESC_HDL,
    .char_idx     = BLE_SGS_ENV_IDX,
    .app_size     = sizeof(st_ble_sgs_env_t),
    .db_size      = BLE_SGS_ENV_LEN,
    .decode       = (ble_servs_attr_decode_t)decode_st_ble_sgs_env_t,
    .encode       = (ble_servs_attr_encode_t)encode_st_ble_sgs_env_t,
    .pp_descs     = gspp_env_descs,
    .num_of_descs = ARRAY_SIZE(gspp_env_descs),
};

ble_status_t R_BLE_SGS_SetEnv(const st_ble_sgs_env_t *p_value)
{
    return R_BLE_SERVS_SetChar(&gs_env_char, BLE_GAP_INVALID_CONN_HDL, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetEnv(st_ble_sgs_env_t *p_value)
{
    return R_BLE_SERVS_GetChar(&gs_env_char, BLE_GAP_INVALID_CONN_HDL, (void *)p_value);
}

ble_status_t R_BLE_SGS_NotifyEnv(uint16_t conn_hdl, const st_ble_sgs_env_t *p_value)
{
    return R_BLE_SERVS_SendHdlVal(&gs_env_char, conn_hdl, (const void *)p_value, true);
}

/*----------------------------------------------------------------------------------------------------------------------
    Motion Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

static const st_ble_servs_desc_info_t gs_motion_cli_cnfg = {
    .attr_hdl = BLE_SGS_MOTION_CLI_CNFG_DESC_HDL,
    .app_size = sizeof(uint16_t),
    .desc_idx = BLE_SGS_MOTION_CLI_CNFG_IDX,
    .db_size  = BLE_SGS_MOTION_CLI_CNFG_LEN,
    .decode   = (ble_servs_attr_decode_t)decode_uint16_t,
    .encode   = (ble_servs_attr_encode_t)encode_uint16_t,
};

ble_status_t R_BLE_SGS_SetMotionCliCnfg(uint16_t conn_hdl, const uint16_t *p_value)
{
    return R_BLE_SERVS_SetDesc(&gs_motion_cli_cnfg, conn_hdl, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetMotionCliCnfg(uint16_t conn_hdl, uint16_t *p_value)
{
    return R_BLE_SERVS_GetDesc(&gs_motion_cli_cnfg, conn_hdl, (void *)p_value);
}

/*----------------------------------------------------------------------------------------------------------------------
    Motion characteristic
----------------------------------------------------------------------------------------------------------------------*/

static ble_status_t decode_st_ble_sgs_motion_t(st_ble_sgs_motion_t *p_app_value, const st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for Motion characteristic value decode function. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

static ble_status_t encode_st_ble_sgs_motion_t(const st_ble_sgs_motion_t *p_app_value, st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for Motion characteristic value encode function. Do not edit comment generated here */
    for (uint16_t i = 0; i < BLE_SGS_MOTION_LEN; i++) { p_gatt_value->p_value[i] = (uint8_t) p_app_value->text[i]; }
    p_gatt_value->value_len = BLE_SGS_MOTION_LEN;
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

/* Motion characteristic descriptor definition */
static const st_ble_servs_desc_info_t *gspp_motion_descs[] = { 
    &gs_motion_cli_cnfg,
};

/* Motion characteristic definition */
static const st_ble_servs_char_info_t gs_motion_char = {
    .start_hdl    = BLE_SGS_MOTION_DECL_HDL,
    .end_hdl      = BLE_SGS_MOTION_CLI_CNFG_DESC_HDL,
    .char_idx     = BLE_SGS_MOTION_IDX,
    .app_size     = sizeof(st_ble_sgs_motion_t),
    .db_size      = BLE_SGS_MOTION_LEN,
    .decode       = (ble_servs_attr_decode_t)decode_st_ble_sgs_motion_t,
    .encode       = (ble_servs_attr_encode_t)encode_st_ble_sgs_motion_t,
    .pp_descs     = gspp_motion_descs,
    .num_of_descs = ARRAY_SIZE(gspp_motion_descs),
};

ble_status_t R_BLE_SGS_SetMotion(const st_ble_sgs_motion_t *p_value)
{
    return R_BLE_SERVS_SetChar(&gs_motion_char, BLE_GAP_INVALID_CONN_HDL, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetMotion(st_ble_sgs_motion_t *p_value)
{
    return R_BLE_SERVS_GetChar(&gs_motion_char, BLE_GAP_INVALID_CONN_HDL, (void *)p_value);
}

ble_status_t R_BLE_SGS_NotifyMotion(uint16_t conn_hdl, const st_ble_sgs_motion_t *p_value)
{
    return R_BLE_SERVS_SendHdlVal(&gs_motion_char, conn_hdl, (const void *)p_value, true);
}

/*----------------------------------------------------------------------------------------------------------------------
    ML Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

static const st_ble_servs_desc_info_t gs_ml_cli_cnfg = {
    .attr_hdl = BLE_SGS_ML_CLI_CNFG_DESC_HDL,
    .app_size = sizeof(uint16_t),
    .desc_idx = BLE_SGS_ML_CLI_CNFG_IDX,
    .db_size  = BLE_SGS_ML_CLI_CNFG_LEN,
    .decode   = (ble_servs_attr_decode_t)decode_uint16_t,
    .encode   = (ble_servs_attr_encode_t)encode_uint16_t,
};

ble_status_t R_BLE_SGS_SetMlCliCnfg(uint16_t conn_hdl, const uint16_t *p_value)
{
    return R_BLE_SERVS_SetDesc(&gs_ml_cli_cnfg, conn_hdl, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetMlCliCnfg(uint16_t conn_hdl, uint16_t *p_value)
{
    return R_BLE_SERVS_GetDesc(&gs_ml_cli_cnfg, conn_hdl, (void *)p_value);
}

/*----------------------------------------------------------------------------------------------------------------------
    ML characteristic
----------------------------------------------------------------------------------------------------------------------*/

static ble_status_t decode_st_ble_sgs_ml_t(st_ble_sgs_ml_t *p_app_value, const st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for ML characteristic value decode function. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

static ble_status_t encode_st_ble_sgs_ml_t(const st_ble_sgs_ml_t *p_app_value, st_ble_gatt_value_t *p_gatt_value)
{
    /* Start user code for ML characteristic value encode function. Do not edit comment generated here */
    for (uint16_t i = 0; i < BLE_SGS_ML_LEN; i++) { p_gatt_value->p_value[i] = (uint8_t) p_app_value->text[i]; }
    p_gatt_value->value_len = BLE_SGS_ML_LEN;
    /* End user code. Do not edit comment generated here */
    return BLE_SUCCESS;
}

/* ML characteristic descriptor definition */
static const st_ble_servs_desc_info_t *gspp_ml_descs[] = { 
    &gs_ml_cli_cnfg,
};

/* ML characteristic definition */
static const st_ble_servs_char_info_t gs_ml_char = {
    .start_hdl    = BLE_SGS_ML_DECL_HDL,
    .end_hdl      = BLE_SGS_ML_CLI_CNFG_DESC_HDL,
    .char_idx     = BLE_SGS_ML_IDX,
    .app_size     = sizeof(st_ble_sgs_ml_t),
    .db_size      = BLE_SGS_ML_LEN,
    .decode       = (ble_servs_attr_decode_t)decode_st_ble_sgs_ml_t,
    .encode       = (ble_servs_attr_encode_t)encode_st_ble_sgs_ml_t,
    .pp_descs     = gspp_ml_descs,
    .num_of_descs = ARRAY_SIZE(gspp_ml_descs),
};

ble_status_t R_BLE_SGS_SetMl(const st_ble_sgs_ml_t *p_value)
{
    return R_BLE_SERVS_SetChar(&gs_ml_char, BLE_GAP_INVALID_CONN_HDL, (const void *)p_value);
}

ble_status_t R_BLE_SGS_GetMl(st_ble_sgs_ml_t *p_value)
{
    return R_BLE_SERVS_GetChar(&gs_ml_char, BLE_GAP_INVALID_CONN_HDL, (void *)p_value);
}

ble_status_t R_BLE_SGS_NotifyMl(uint16_t conn_hdl, const st_ble_sgs_ml_t *p_value)
{
    return R_BLE_SERVS_SendHdlVal(&gs_ml_char, conn_hdl, (const void *)p_value, true);
}

/*----------------------------------------------------------------------------------------------------------------------
    SoleGuard server
----------------------------------------------------------------------------------------------------------------------*/

/* SoleGuard characteristics definition */
static const st_ble_servs_char_info_t *gspp_chars[] = {
    &gs_press_char,
    &gs_vital_char,
    &gs_env_char,
    &gs_motion_char,
    &gs_ml_char,
};

/* SoleGuard service definition */
static st_ble_servs_info_t gs_servs_info = {
    .pp_chars     = gspp_chars,
    .num_of_chars = ARRAY_SIZE(gspp_chars),
};

ble_status_t R_BLE_SGS_Init(ble_servs_app_cb_t cb)
{
    if (NULL == cb)
    {
        return BLE_ERR_INVALID_PTR;
    }

    gs_servs_info.cb = cb;

    return R_BLE_SERVS_RegisterServer(&gs_servs_info);
}
