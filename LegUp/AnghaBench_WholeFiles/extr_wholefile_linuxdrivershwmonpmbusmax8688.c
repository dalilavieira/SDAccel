#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int ENODATA ; 
 int ENXIO ; 
 int /*<<< orphan*/  MAX8688_MFG_STATUS ; 
 int /*<<< orphan*/  MAX8688_MFR_IOUT_PEAK ; 
 int /*<<< orphan*/  MAX8688_MFR_TEMPERATURE_PEAK ; 
 int /*<<< orphan*/  MAX8688_MFR_VOUT_PEAK ; 
 int MAX8688_STATUS_OC_FAULT ; 
 int MAX8688_STATUS_OC_WARNING ; 
 int MAX8688_STATUS_OT_FAULT ; 
 int MAX8688_STATUS_OT_WARNING ; 
 int MAX8688_STATUS_OV_FAULT ; 
 int MAX8688_STATUS_OV_WARNING ; 
 int MAX8688_STATUS_UC_FAULT ; 
 int MAX8688_STATUS_UV_FAULT ; 
 int MAX8688_STATUS_UV_WARNING ; 
 int PB_IOUT_OC_FAULT ; 
 int PB_IOUT_OC_WARNING ; 
 int PB_IOUT_UC_FAULT ; 
 int PB_TEMP_OT_FAULT ; 
 int PB_TEMP_OT_WARNING ; 
 int PB_VOLTAGE_OV_FAULT ; 
 int PB_VOLTAGE_OV_WARNING ; 
 int PB_VOLTAGE_UV_FAULT ; 
 int PB_VOLTAGE_UV_WARNING ; 
#define  PMBUS_STATUS_IOUT 136 
#define  PMBUS_STATUS_TEMPERATURE 135 
#define  PMBUS_STATUS_VOUT 134 
#define  PMBUS_VIRT_READ_IOUT_MAX 133 
#define  PMBUS_VIRT_READ_TEMP_MAX 132 
#define  PMBUS_VIRT_READ_VOUT_MAX 131 
#define  PMBUS_VIRT_RESET_IOUT_HISTORY 130 
#define  PMBUS_VIRT_RESET_TEMP_HISTORY 129 
#define  PMBUS_VIRT_RESET_VOUT_HISTORY 128 
 int /*<<< orphan*/  max8688_info ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,int /*<<< orphan*/ *) ; 
 int pmbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pmbus_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int max8688_read_word_data(struct i2c_client *client, int page, int reg)
{
	int ret;

	if (page > 0)
		return -ENXIO;

	switch (reg) {
	case PMBUS_VIRT_READ_VOUT_MAX:
		ret = pmbus_read_word_data(client, 0, MAX8688_MFR_VOUT_PEAK);
		break;
	case PMBUS_VIRT_READ_IOUT_MAX:
		ret = pmbus_read_word_data(client, 0, MAX8688_MFR_IOUT_PEAK);
		break;
	case PMBUS_VIRT_READ_TEMP_MAX:
		ret = pmbus_read_word_data(client, 0,
					   MAX8688_MFR_TEMPERATURE_PEAK);
		break;
	case PMBUS_VIRT_RESET_VOUT_HISTORY:
	case PMBUS_VIRT_RESET_IOUT_HISTORY:
	case PMBUS_VIRT_RESET_TEMP_HISTORY:
		ret = 0;
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int max8688_write_word_data(struct i2c_client *client, int page, int reg,
				   u16 word)
{
	int ret;

	switch (reg) {
	case PMBUS_VIRT_RESET_VOUT_HISTORY:
		ret = pmbus_write_word_data(client, 0, MAX8688_MFR_VOUT_PEAK,
					    0);
		break;
	case PMBUS_VIRT_RESET_IOUT_HISTORY:
		ret = pmbus_write_word_data(client, 0, MAX8688_MFR_IOUT_PEAK,
					    0);
		break;
	case PMBUS_VIRT_RESET_TEMP_HISTORY:
		ret = pmbus_write_word_data(client, 0,
					    MAX8688_MFR_TEMPERATURE_PEAK,
					    0xffff);
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int max8688_read_byte_data(struct i2c_client *client, int page, int reg)
{
	int ret = 0;
	int mfg_status;

	if (page > 0)
		return -ENXIO;

	switch (reg) {
	case PMBUS_STATUS_VOUT:
		mfg_status = pmbus_read_word_data(client, 0,
						  MAX8688_MFG_STATUS);
		if (mfg_status < 0)
			return mfg_status;
		if (mfg_status & MAX8688_STATUS_UV_WARNING)
			ret |= PB_VOLTAGE_UV_WARNING;
		if (mfg_status & MAX8688_STATUS_UV_FAULT)
			ret |= PB_VOLTAGE_UV_FAULT;
		if (mfg_status & MAX8688_STATUS_OV_WARNING)
			ret |= PB_VOLTAGE_OV_WARNING;
		if (mfg_status & MAX8688_STATUS_OV_FAULT)
			ret |= PB_VOLTAGE_OV_FAULT;
		break;
	case PMBUS_STATUS_IOUT:
		mfg_status = pmbus_read_word_data(client, 0,
						  MAX8688_MFG_STATUS);
		if (mfg_status < 0)
			return mfg_status;
		if (mfg_status & MAX8688_STATUS_UC_FAULT)
			ret |= PB_IOUT_UC_FAULT;
		if (mfg_status & MAX8688_STATUS_OC_WARNING)
			ret |= PB_IOUT_OC_WARNING;
		if (mfg_status & MAX8688_STATUS_OC_FAULT)
			ret |= PB_IOUT_OC_FAULT;
		break;
	case PMBUS_STATUS_TEMPERATURE:
		mfg_status = pmbus_read_word_data(client, 0,
						  MAX8688_MFG_STATUS);
		if (mfg_status < 0)
			return mfg_status;
		if (mfg_status & MAX8688_STATUS_OT_WARNING)
			ret |= PB_TEMP_OT_WARNING;
		if (mfg_status & MAX8688_STATUS_OT_FAULT)
			ret |= PB_TEMP_OT_FAULT;
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int max8688_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	return pmbus_do_probe(client, id, &max8688_info);
}

