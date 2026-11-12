/* 
* Copyright (c) 2019 - 2025 Renesas Electronics Corporation and/or its affiliates 
* 
* SPDX-License-Identifier: BSD-3-Clause 
*/
/***********************************************************************************************************************
 * File Name: r_ble_sgs.h
 * Version : 1.0
 * Description : The header file for SoleGuard service.
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.12.2999 1.00 First Release
 ***********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @file
 * @defgroup sgs SoleGuard Service
 * @{
 * @ingroup profile
 * @brief   
 **********************************************************************************************************************/
#include "profile_cmn/r_ble_servs_if.h"
#include "gatt_db.h"

#ifndef R_BLE_SGS_H
#define R_BLE_SGS_H

/*----------------------------------------------------------------------------------------------------------------------
    pressure Characteristic
        Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************//**
 * @brief pressure value structure.
*******************************************************************************/
typedef struct {
    char text[20]; /**< text */
} st_ble_sgs_press_t;

/***************************************************************************//**
 * @brief     Set pressure characteristic value to the local GATT database.
 * @param[in] p_value  Characteristic value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetPress(const st_ble_sgs_press_t *p_value);

/***************************************************************************//**
 * @brief     Get pressure characteristic value from the local GATT database.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetPress(st_ble_sgs_press_t *p_value);

/***************************************************************************//**
 * @brief     Send notification of  pressure characteristic value to the remote device.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Characteristic value to send.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_NotifyPress(uint16_t conn_hdl, const st_ble_sgs_press_t *p_value);

/***************************************************************************//**
 * @brief     Set pressure cli cnfg descriptor value to the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Descriptor value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetPressCliCnfg(uint16_t conn_hdl, const uint16_t *p_value);

/***************************************************************************//**
 * @brief     Get pressure cli cnfg descriptor value from the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetPressCliCnfg(uint16_t conn_hdl, uint16_t *p_value);

/*----------------------------------------------------------------------------------------------------------------------
    vitals Characteristic
        Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************//**
 * @brief vitals value structure.
*******************************************************************************/
typedef struct {
    char text[20]; /**< text */
} st_ble_sgs_vital_t;

/***************************************************************************//**
 * @brief     Set vitals characteristic value to the local GATT database.
 * @param[in] p_value  Characteristic value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetVital(const st_ble_sgs_vital_t *p_value);

/***************************************************************************//**
 * @brief     Get vitals characteristic value from the local GATT database.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetVital(st_ble_sgs_vital_t *p_value);

/***************************************************************************//**
 * @brief     Send notification of  vitals characteristic value to the remote device.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Characteristic value to send.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_NotifyVital(uint16_t conn_hdl, const st_ble_sgs_vital_t *p_value);

/***************************************************************************//**
 * @brief     Set vitals cli cnfg descriptor value to the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Descriptor value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetVitalCliCnfg(uint16_t conn_hdl, const uint16_t *p_value);

/***************************************************************************//**
 * @brief     Get vitals cli cnfg descriptor value from the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetVitalCliCnfg(uint16_t conn_hdl, uint16_t *p_value);

/*----------------------------------------------------------------------------------------------------------------------
    Environment Characteristic
        Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************//**
 * @brief Environment value structure.
*******************************************************************************/
typedef struct {
    char text[20]; /**< text */
} st_ble_sgs_env_t;

/***************************************************************************//**
 * @brief     Set Environment characteristic value to the local GATT database.
 * @param[in] p_value  Characteristic value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetEnv(const st_ble_sgs_env_t *p_value);

/***************************************************************************//**
 * @brief     Get Environment characteristic value from the local GATT database.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetEnv(st_ble_sgs_env_t *p_value);

/***************************************************************************//**
 * @brief     Send notification of  Environment characteristic value to the remote device.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Characteristic value to send.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_NotifyEnv(uint16_t conn_hdl, const st_ble_sgs_env_t *p_value);

/***************************************************************************//**
 * @brief     Set Environment cli cnfg descriptor value to the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Descriptor value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetEnvCliCnfg(uint16_t conn_hdl, const uint16_t *p_value);

/***************************************************************************//**
 * @brief     Get Environment cli cnfg descriptor value from the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetEnvCliCnfg(uint16_t conn_hdl, uint16_t *p_value);

/*----------------------------------------------------------------------------------------------------------------------
    Motion Characteristic
        Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************//**
 * @brief Motion value structure.
*******************************************************************************/
typedef struct {
    char text[20]; /**< text */
} st_ble_sgs_motion_t;

/***************************************************************************//**
 * @brief     Set Motion characteristic value to the local GATT database.
 * @param[in] p_value  Characteristic value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetMotion(const st_ble_sgs_motion_t *p_value);

/***************************************************************************//**
 * @brief     Get Motion characteristic value from the local GATT database.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetMotion(st_ble_sgs_motion_t *p_value);

/***************************************************************************//**
 * @brief     Send notification of  Motion characteristic value to the remote device.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Characteristic value to send.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_NotifyMotion(uint16_t conn_hdl, const st_ble_sgs_motion_t *p_value);

/***************************************************************************//**
 * @brief     Set Motion cli cnfg descriptor value to the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Descriptor value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetMotionCliCnfg(uint16_t conn_hdl, const uint16_t *p_value);

/***************************************************************************//**
 * @brief     Get Motion cli cnfg descriptor value from the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetMotionCliCnfg(uint16_t conn_hdl, uint16_t *p_value);

/*----------------------------------------------------------------------------------------------------------------------
    ML Characteristic
        Client Characteristic Configuration descriptor : Client Characteristic Configuration Descriptor
----------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************//**
 * @brief ML value structure.
*******************************************************************************/
typedef struct {
    char text[20]; /**< text */
} st_ble_sgs_ml_t;

/***************************************************************************//**
 * @brief     Set ML characteristic value to the local GATT database.
 * @param[in] p_value  Characteristic value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetMl(const st_ble_sgs_ml_t *p_value);

/***************************************************************************//**
 * @brief     Get ML characteristic value from the local GATT database.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetMl(st_ble_sgs_ml_t *p_value);

/***************************************************************************//**
 * @brief     Send notification of  ML characteristic value to the remote device.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Characteristic value to send.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_NotifyMl(uint16_t conn_hdl, const st_ble_sgs_ml_t *p_value);

/***************************************************************************//**
 * @brief     Set ML cli cnfg descriptor value to the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[in] p_value  Descriptor value to set.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_SetMlCliCnfg(uint16_t conn_hdl, const uint16_t *p_value);

/***************************************************************************//**
 * @brief     Get ML cli cnfg descriptor value from the local GATT database.
 * @param[in] conn_hdl Connection handle.
 * @param[out] p_value  Output location for the acquired descriptor value.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_GetMlCliCnfg(uint16_t conn_hdl, uint16_t *p_value);

/*----------------------------------------------------------------------------------------------------------------------
    SoleGuard Service
----------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************//**
 * @brief SoleGuard characteristic Index.
*******************************************************************************/
typedef enum {
    BLE_SGS_PRESS_IDX,
    BLE_SGS_PRESS_CLI_CNFG_IDX,
    BLE_SGS_VITAL_IDX,
    BLE_SGS_VITAL_CLI_CNFG_IDX,
    BLE_SGS_ENV_IDX,
    BLE_SGS_ENV_CLI_CNFG_IDX,
    BLE_SGS_MOTION_IDX,
    BLE_SGS_MOTION_CLI_CNFG_IDX,
    BLE_SGS_ML_IDX,
    BLE_SGS_ML_CLI_CNFG_IDX,
} e_ble_sgs_char_idx_t;

/***************************************************************************//**
 * @brief SoleGuard event type.
*******************************************************************************/
typedef enum {
    /* pressure */
    BLE_SGS_EVENT_PRESS_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_PRESS_IDX, BLE_SERVS_READ_REQ),
    BLE_SGS_EVENT_PRESS_CLI_CNFG_WRITE_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_PRESS_CLI_CNFG_IDX, BLE_SERVS_WRITE_REQ),
    BLE_SGS_EVENT_PRESS_CLI_CNFG_WRITE_COMP = BLE_SERVS_ATTR_EVENT(BLE_SGS_PRESS_CLI_CNFG_IDX, BLE_SERVS_WRITE_COMP),
    BLE_SGS_EVENT_PRESS_CLI_CNFG_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_PRESS_CLI_CNFG_IDX, BLE_SERVS_READ_REQ),
    /* vitals */
    BLE_SGS_EVENT_VITAL_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_VITAL_IDX, BLE_SERVS_READ_REQ),
    BLE_SGS_EVENT_VITAL_CLI_CNFG_WRITE_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_VITAL_CLI_CNFG_IDX, BLE_SERVS_WRITE_REQ),
    BLE_SGS_EVENT_VITAL_CLI_CNFG_WRITE_COMP = BLE_SERVS_ATTR_EVENT(BLE_SGS_VITAL_CLI_CNFG_IDX, BLE_SERVS_WRITE_COMP),
    BLE_SGS_EVENT_VITAL_CLI_CNFG_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_VITAL_CLI_CNFG_IDX, BLE_SERVS_READ_REQ),
    /* Environment */
    BLE_SGS_EVENT_ENV_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_ENV_IDX, BLE_SERVS_READ_REQ),
    BLE_SGS_EVENT_ENV_CLI_CNFG_WRITE_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_ENV_CLI_CNFG_IDX, BLE_SERVS_WRITE_REQ),
    BLE_SGS_EVENT_ENV_CLI_CNFG_WRITE_COMP = BLE_SERVS_ATTR_EVENT(BLE_SGS_ENV_CLI_CNFG_IDX, BLE_SERVS_WRITE_COMP),
    BLE_SGS_EVENT_ENV_CLI_CNFG_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_ENV_CLI_CNFG_IDX, BLE_SERVS_READ_REQ),
    /* Motion */
    BLE_SGS_EVENT_MOTION_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_MOTION_IDX, BLE_SERVS_READ_REQ),
    BLE_SGS_EVENT_MOTION_CLI_CNFG_WRITE_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_MOTION_CLI_CNFG_IDX, BLE_SERVS_WRITE_REQ),
    BLE_SGS_EVENT_MOTION_CLI_CNFG_WRITE_COMP = BLE_SERVS_ATTR_EVENT(BLE_SGS_MOTION_CLI_CNFG_IDX, BLE_SERVS_WRITE_COMP),
    BLE_SGS_EVENT_MOTION_CLI_CNFG_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_MOTION_CLI_CNFG_IDX, BLE_SERVS_READ_REQ),
    /* ML */
    BLE_SGS_EVENT_ML_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_ML_IDX, BLE_SERVS_READ_REQ),
    BLE_SGS_EVENT_ML_CLI_CNFG_WRITE_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_ML_CLI_CNFG_IDX, BLE_SERVS_WRITE_REQ),
    BLE_SGS_EVENT_ML_CLI_CNFG_WRITE_COMP = BLE_SERVS_ATTR_EVENT(BLE_SGS_ML_CLI_CNFG_IDX, BLE_SERVS_WRITE_COMP),
    BLE_SGS_EVENT_ML_CLI_CNFG_READ_REQ = BLE_SERVS_ATTR_EVENT(BLE_SGS_ML_CLI_CNFG_IDX, BLE_SERVS_READ_REQ),
} e_ble_sgs_event_t;

/***************************************************************************//**
 * @brief     Initialize SoleGuard service.
 * @param[in] cb Service callback.
 * @return    @ref ble_status_t
*******************************************************************************/
ble_status_t R_BLE_SGS_Init(ble_servs_app_cb_t cb);

#endif /* R_BLE_SGS_H */

/** @} */
