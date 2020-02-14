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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int ENODATA ; 
 int ENODEV ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_READ_WORD_DATA ; 
 int LTC3815_ID ; 
 int LTC3815_ID_MASK ; 
 int /*<<< orphan*/  LTC3815_MFR_IIN_PEAK ; 
 int /*<<< orphan*/  LTC3815_MFR_IOUT_PEAK ; 
 int /*<<< orphan*/  LTC3815_MFR_SPECIAL_ID ; 
 int /*<<< orphan*/  LTC3815_MFR_TEMP_PEAK ; 
 int /*<<< orphan*/  LTC3815_MFR_VIN_PEAK ; 
 int /*<<< orphan*/  LTC3815_MFR_VOUT_PEAK ; 
#define  PMBUS_CLEAR_FAULTS 139 
 int /*<<< orphan*/  PMBUS_STATUS_WORD ; 
#define  PMBUS_VIRT_READ_IIN_MAX 138 
#define  PMBUS_VIRT_READ_IOUT_MAX 137 
#define  PMBUS_VIRT_READ_TEMP_MAX 136 
#define  PMBUS_VIRT_READ_VIN_MAX 135 
#define  PMBUS_VIRT_READ_VOUT_MAX 134 
#define  PMBUS_VIRT_RESET_IIN_HISTORY 133 
#define  PMBUS_VIRT_RESET_IOUT_HISTORY 132 
#define  PMBUS_VIRT_RESET_TEMP_HISTORY 131 
#define  PMBUS_VIRT_RESET_VIN_HISTORY 130 
#define  PMBUS_VIRT_RESET_VOUT_HISTORY 129 
#define  PMBUS_VOUT_MODE 128 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltc3815_info ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,int /*<<< orphan*/ *) ; 
 int pmbus_read_word_data (struct i2c_client*,int,int /*<<< orphan*/ ) ; 
 int pmbus_write_word_data (struct i2c_client*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ltc3815_read_byte_data(struct i2c_client *client, int page, int reg)
{
	int ret;

	switch (reg) {
	case PMBUS_VOUT_MODE:
		/*
		 * The chip returns 0x3e, suggesting VID mode with manufacturer
		 * specific VID codes. Since the output voltage is reported
		 * with a LSB of 0.5mV, override and report direct mode with
		 * appropriate coefficients.
		 */
		ret = 0x40;
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int ltc3815_write_byte(struct i2c_client *client, int page, u8 reg)
{
	int ret;

	switch (reg) {
	case PMBUS_CLEAR_FAULTS:
		/*
		 * LTC3815 does not support the CLEAR_FAULTS command.
		 * Emulate it by clearing the status register.
		 */
		ret = pmbus_read_word_data(client, 0, PMBUS_STATUS_WORD);
		if (ret > 0) {
			pmbus_write_word_data(client, 0, PMBUS_STATUS_WORD,
					      ret);
			ret = 0;
		}
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int ltc3815_read_word_data(struct i2c_client *client, int page, int reg)
{
	int ret;

	switch (reg) {
	case PMBUS_VIRT_READ_VIN_MAX:
		ret = pmbus_read_word_data(client, page, LTC3815_MFR_VIN_PEAK);
		break;
	case PMBUS_VIRT_READ_VOUT_MAX:
		ret = pmbus_read_word_data(client, page, LTC3815_MFR_VOUT_PEAK);
		break;
	case PMBUS_VIRT_READ_TEMP_MAX:
		ret = pmbus_read_word_data(client, page, LTC3815_MFR_TEMP_PEAK);
		break;
	case PMBUS_VIRT_READ_IOUT_MAX:
		ret = pmbus_read_word_data(client, page, LTC3815_MFR_IOUT_PEAK);
		break;
	case PMBUS_VIRT_READ_IIN_MAX:
		ret = pmbus_read_word_data(client, page, LTC3815_MFR_IIN_PEAK);
		break;
	case PMBUS_VIRT_RESET_VOUT_HISTORY:
	case PMBUS_VIRT_RESET_VIN_HISTORY:
	case PMBUS_VIRT_RESET_TEMP_HISTORY:
	case PMBUS_VIRT_RESET_IOUT_HISTORY:
	case PMBUS_VIRT_RESET_IIN_HISTORY:
		ret = 0;
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int ltc3815_write_word_data(struct i2c_client *client, int page,
				   int reg, u16 word)
{
	int ret;

	switch (reg) {
	case PMBUS_VIRT_RESET_IIN_HISTORY:
		ret = pmbus_write_word_data(client, page,
					    LTC3815_MFR_IIN_PEAK, 0);
		break;
	case PMBUS_VIRT_RESET_IOUT_HISTORY:
		ret = pmbus_write_word_data(client, page,
					    LTC3815_MFR_IOUT_PEAK, 0);
		break;
	case PMBUS_VIRT_RESET_VOUT_HISTORY:
		ret = pmbus_write_word_data(client, page,
					    LTC3815_MFR_VOUT_PEAK, 0);
		break;
	case PMBUS_VIRT_RESET_VIN_HISTORY:
		ret = pmbus_write_word_data(client, page,
					    LTC3815_MFR_VIN_PEAK, 0);
		break;
	case PMBUS_VIRT_RESET_TEMP_HISTORY:
		ret = pmbus_write_word_data(client, page,
					    LTC3815_MFR_TEMP_PEAK, 0);
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int ltc3815_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	int chip_id;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_READ_WORD_DATA))
		return -ENODEV;

	chip_id = i2c_smbus_read_word_data(client, LTC3815_MFR_SPECIAL_ID);
	if (chip_id < 0)
		return chip_id;
	if ((chip_id & LTC3815_ID_MASK) != LTC3815_ID)
		return -ENODEV;

	return pmbus_do_probe(client, id, &ltc3815_info);
}

