/* 
* Copyright (c) 2024 - 2025 Renesas Electronics Corporation and/or its affiliates 
* 
* SPDX-License-Identifier: BSD-3-Clause 
*/
/***********************************************************************************************************************
* File Name    : qe_ble_profile.c
* Description  : This file includes definitions.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History      : MM/DD/YYYY Version Description
*              : 10/28/2024 1.00    First Release
*              : 17/12/2024 1.01    Support Read Indication
*              : 05/22/2025 1.02    Added write_cmd_cb to attribute structure
***********************************************************************************************************************/

#include "qe_ble_profile.h"

static uint16_t qe_uuid1 = 0x2800;
static uint16_t qe_value1 = 0x1800;
static uint16_t qe_uuid2 = 0x2803;
static uint16_t qe_uuid3 = 0x2A00;
static uint16_t qe_uuid4 = 0x2803;
static uint16_t qe_uuid5 = 0x2A01;
static uint16_t qe_uuid6 = 0x2803;
static uint16_t qe_uuid7 = 0x2A04;
static uint16_t qe_uuid8 = 0x2800;
static uint16_t qe_value8 = 0x1801;
static uint16_t qe_uuid9 = 0x2803;
static uint16_t qe_uuid10 = 0x2A05;
static uint16_t qe_uuid11 = 0x2902;
static uint16_t qe_uuid12 = 0x2800;
static uint16_t qe_value12[] = {0x2661,0x0FEC,0xE608,0x9CA4,0x4EBA,0x0540,0x4392,0x9D24};
static uint16_t qe_uuid13 = 0x2803;
static uint16_t qe_uuid15 = 0x2902;
static uint16_t qe_uuid16 = 0x2803;
static uint16_t qe_uuid18 = 0x2902;
static uint16_t qe_uuid19 = 0x2803;
static uint16_t qe_uuid21 = 0x2902;
static uint16_t qe_uuid22 = 0x2803;
static uint16_t qe_uuid24 = 0x2902;
static uint16_t qe_uuid25 = 0x2803;
static uint16_t qe_uuid27 = 0x2902;

static r_ble_gtl_attr_write_cmd_t qe_write_cmd_cb_array[QE_BLE_PROFILE_NUMBER_OF_ATTRIBUTES];

const attribute_t qe_ble_profile[QE_ATTRIBUTE_HANDLE_PROFILE_END] =
{

	// Profile Declaration
	[0] =
	{
		.handle = 0,
		.encapsulated_attributes = 27,
		.permissions = 0x00, 
		.uuid_length = 0x00,
		.value_length = 0x00,
		.notify_write = 0,
		.notify_read = 0,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[0])
	},
	// Service Declaration: GAP Service
	[1] =
	{
		.handle = 1,
		.encapsulated_attributes = 7,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid1,
		.value = (uint8_t *)&qe_value1,
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[1])
	},
	// Characteristic Declaration: Device Name
	[2] =
	{
		.handle = 2,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x05,
		.uuid = (uint8_t *)&qe_uuid2,
		.value = (uint8_t []){0x0A,0x03,0x00,0x00,0x2A},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[2])
	},
	// Characteristic Value: Device Name
	[3] =
	{
		.handle = 3,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x80,
		.uuid = (uint8_t *)&qe_uuid3,
		.value = (uint8_t []){0x53,0x6F,0x6C,0x47,0x75,0x61,0x72,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[3])
	},
	// Characteristic Declaration: Appearance
	[4] =
	{
		.handle = 4,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x05,
		.uuid = (uint8_t *)&qe_uuid4,
		.value = (uint8_t []){0x02,0x05,0x00,0x01,0x2A},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[4])
	},
	// Characteristic Value: Appearance
	[5] =
	{
		.handle = 5,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid5,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[5])
	},
	// Characteristic Declaration: Peripheral Preferred Connection Parameters
	[6] =
	{
		.handle = 6,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x05,
		.uuid = (uint8_t *)&qe_uuid6,
		.value = (uint8_t []){0x02,0x07,0x00,0x04,0x2A},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[6])
	},
	// Characteristic Value: Peripheral Preferred Connection Parameters
	[7] =
	{
		.handle = 7,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x08,
		.uuid = (uint8_t *)&qe_uuid7,
		.value = (uint8_t []){0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[7])
	},
	// Service Declaration: GATT Service
	[8] =
	{
		.handle = 8,
		.encapsulated_attributes = 4,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid8,
		.value = (uint8_t *)&qe_value8,
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[8])
	},
	// Characteristic Declaration: Service Changed
	[9] =
	{
		.handle = 9,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x05,
		.uuid = (uint8_t *)&qe_uuid9,
		.value = (uint8_t []){0x20,0x0A,0x00,0x05,0x2A},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[9])
	},
	// Characteristic Value: Service Changed
	[10] =
	{
		.handle = 10,
		.encapsulated_attributes = 0,
		.permissions = 0x00,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x04,
		.uuid = (uint8_t *)&qe_uuid10,
		.value = (uint8_t []){0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[10])
	},
	// Descriptor: Client Characteristic Configuration
	[11] =
	{
		.handle = 11,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid11,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 1,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[11])
	},
	// Service Declaration: SoleGuard
	[12] =
	{
		.handle = 12,
		.encapsulated_attributes = 16,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x10,
		.uuid = (uint8_t *)&qe_uuid12,
		.value = (uint8_t *)&qe_value12,
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[12])
	},
	// Characteristic Declaration: pressure
	[13] =
	{
		.handle = 13,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x13,
		.uuid = (uint8_t *)&qe_uuid13,
		.value = (uint8_t []){0x12,0x0E,0x00,0xEE,0x68,0xCE,0x25,0xCC,0x4E,0x2E,0xA9,0x19,0x43,0x98,0x41,0x4B,0xCD,0xA9,0xC8},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[13])
	},
	// Characteristic Value: pressure
	[14] =
	{
		.handle = 14,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_CUSTOM,
		.value_length = 0x14,
		.uuid = (uint8_t []){0xEE,0x68,0xCE,0x25,0xCC,0x4E,0x2E,0xA9,0x19,0x43,0x98,0x41,0x4B,0xCD,0xA9,0xC8},
		.value = (uint8_t []){0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[14])
	},
	// Descriptor: Client Characteristic Configuration
	[15] =
	{
		.handle = 15,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid15,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 1,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[15])
	},
	// Characteristic Declaration: vitals
	[16] =
	{
		.handle = 16,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x13,
		.uuid = (uint8_t *)&qe_uuid16,
		.value = (uint8_t []){0x12,0x11,0x00,0x3F,0x24,0x24,0xAF,0x63,0x8E,0xB4,0x86,0x30,0x4F,0xF4,0x08,0x5C,0x3C,0x33,0x9F},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[16])
	},
	// Characteristic Value: vitals
	[17] =
	{
		.handle = 17,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_CUSTOM,
		.value_length = 0x14,
		.uuid = (uint8_t []){0x3F,0x24,0x24,0xAF,0x63,0x8E,0xB4,0x86,0x30,0x4F,0xF4,0x08,0x5C,0x3C,0x33,0x9F},
		.value = (uint8_t []){0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[17])
	},
	// Descriptor: Client Characteristic Configuration
	[18] =
	{
		.handle = 18,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid18,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 1,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[18])
	},
	// Characteristic Declaration: Environment
	[19] =
	{
		.handle = 19,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x13,
		.uuid = (uint8_t *)&qe_uuid19,
		.value = (uint8_t []){0x12,0x14,0x00,0x5D,0xF6,0x60,0xB3,0x60,0x49,0x10,0x8E,0x11,0x4D,0x43,0xA9,0x69,0xE7,0x4E,0x6A},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[19])
	},
	// Characteristic Value: Environment
	[20] =
	{
		.handle = 20,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_CUSTOM,
		.value_length = 0x14,
		.uuid = (uint8_t []){0x5D,0xF6,0x60,0xB3,0x60,0x49,0x10,0x8E,0x11,0x4D,0x43,0xA9,0x69,0xE7,0x4E,0x6A},
		.value = (uint8_t []){0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[20])
	},
	// Descriptor: Client Characteristic Configuration
	[21] =
	{
		.handle = 21,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid21,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 1,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[21])
	},
	// Characteristic Declaration: Motion
	[22] =
	{
		.handle = 22,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x13,
		.uuid = (uint8_t *)&qe_uuid22,
		.value = (uint8_t []){0x12,0x17,0x00,0x9F,0xFC,0x51,0x30,0xC1,0xFF,0x2A,0x87,0x47,0x4A,0x5D,0xDA,0x0D,0x09,0x8A,0x13},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[22])
	},
	// Characteristic Value: Motion
	[23] =
	{
		.handle = 23,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_CUSTOM,
		.value_length = 0x14,
		.uuid = (uint8_t []){0x9F,0xFC,0x51,0x30,0xC1,0xFF,0x2A,0x87,0x47,0x4A,0x5D,0xDA,0x0D,0x09,0x8A,0x13},
		.value = (uint8_t []){0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[23])
	},
	// Descriptor: Client Characteristic Configuration
	[24] =
	{
		.handle = 24,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid24,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 1,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[24])
	},
	// Characteristic Declaration: ML
	[25] =
	{
		.handle = 25,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x13,
		.uuid = (uint8_t *)&qe_uuid25,
		.value = (uint8_t []){0x12,0x1A,0x00,0x43,0x86,0xAD,0x49,0xA0,0x1B,0x4A,0x8C,0xBD,0x45,0x1C,0x1D,0x60,0x8F,0x4C,0x3E},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[25])
	},
	// Characteristic Value: ML
	[26] =
	{
		.handle = 26,
		.encapsulated_attributes = 0,
		.permissions = 0x01,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_CUSTOM,
		.value_length = 0x14,
		.uuid = (uint8_t []){0x43,0x86,0xAD,0x49,0xA0,0x1B,0x4A,0x8C,0xBD,0x45,0x1C,0x1D,0x60,0x8F,0x4C,0x3E},
		.value = (uint8_t []){0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 0,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[26])
	},
	// Descriptor: Client Characteristic Configuration
	[27] =
	{
		.handle = 27,
		.encapsulated_attributes = 0,
		.permissions = 0x03,
		.uuid_length = QE_BLE_PROFILE_UUID_SIZE_ADOPTED,
		.value_length = 0x02,
		.uuid = (uint8_t *)&qe_uuid27,
		.value = (uint8_t []){0x00,0x00},
		.notify_write = 1,
		.notify_read = 1,
		.read_indication = 1,
		.p_write_cmd_cb = &(qe_write_cmd_cb_array[27])
	}

};
