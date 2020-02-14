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
struct pmbus_driver_info {int (* read_word_data ) (struct i2c_client*,int,int) ;int pages; int* func; void** format; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int ENODATA ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_READ_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_READ_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_READ_WORD_DATA ; 
 int I2C_SMBUS_BLOCK_MAX ; 
 int /*<<< orphan*/  IR35221_MFR_IOUT_PEAK ; 
 int /*<<< orphan*/  IR35221_MFR_IOUT_VALLEY ; 
 int /*<<< orphan*/  IR35221_MFR_TEMP_PEAK ; 
 int /*<<< orphan*/  IR35221_MFR_TEMP_VALLEY ; 
 int /*<<< orphan*/  IR35221_MFR_VIN_PEAK ; 
 int /*<<< orphan*/  IR35221_MFR_VIN_VALLEY ; 
 int /*<<< orphan*/  IR35221_MFR_VOUT_PEAK ; 
 int /*<<< orphan*/  IR35221_MFR_VOUT_VALLEY ; 
 int PMBUS_HAVE_IIN ; 
 int PMBUS_HAVE_IOUT ; 
 int PMBUS_HAVE_PIN ; 
 int PMBUS_HAVE_POUT ; 
 int PMBUS_HAVE_STATUS_INPUT ; 
 int PMBUS_HAVE_STATUS_IOUT ; 
 int PMBUS_HAVE_STATUS_TEMP ; 
 int PMBUS_HAVE_STATUS_VOUT ; 
 int PMBUS_HAVE_TEMP ; 
 int PMBUS_HAVE_VIN ; 
 int PMBUS_HAVE_VOUT ; 
 int /*<<< orphan*/  PMBUS_MFR_ID ; 
 int /*<<< orphan*/  PMBUS_MFR_MODEL ; 
#define  PMBUS_VIRT_READ_IOUT_MAX 135 
#define  PMBUS_VIRT_READ_IOUT_MIN 134 
#define  PMBUS_VIRT_READ_TEMP_MAX 133 
#define  PMBUS_VIRT_READ_TEMP_MIN 132 
#define  PMBUS_VIRT_READ_VIN_MAX 131 
#define  PMBUS_VIRT_READ_VIN_MIN 130 
#define  PMBUS_VIRT_READ_VOUT_MAX 129 
#define  PMBUS_VIRT_READ_VOUT_MIN 128 
 size_t PSC_CURRENT_IN ; 
 size_t PSC_CURRENT_OUT ; 
 size_t PSC_POWER ; 
 size_t PSC_TEMPERATURE ; 
 size_t PSC_VOLTAGE_IN ; 
 size_t PSC_VOLTAGE_OUT ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct pmbus_driver_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_block_data (struct i2c_client*,int /*<<< orphan*/ ,int*) ; 
 void* linear ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,struct pmbus_driver_info*) ; 
 int pmbus_read_word_data (struct i2c_client*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 scalar_t__ strncmp (int*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ir35221_read_word_data(struct i2c_client *client, int page, int reg)
{
	int ret;

	switch (reg) {
	case PMBUS_VIRT_READ_VIN_MAX:
		ret = pmbus_read_word_data(client, page, IR35221_MFR_VIN_PEAK);
		break;
	case PMBUS_VIRT_READ_VOUT_MAX:
		ret = pmbus_read_word_data(client, page, IR35221_MFR_VOUT_PEAK);
		break;
	case PMBUS_VIRT_READ_IOUT_MAX:
		ret = pmbus_read_word_data(client, page, IR35221_MFR_IOUT_PEAK);
		break;
	case PMBUS_VIRT_READ_TEMP_MAX:
		ret = pmbus_read_word_data(client, page, IR35221_MFR_TEMP_PEAK);
		break;
	case PMBUS_VIRT_READ_VIN_MIN:
		ret = pmbus_read_word_data(client, page,
					   IR35221_MFR_VIN_VALLEY);
		break;
	case PMBUS_VIRT_READ_VOUT_MIN:
		ret = pmbus_read_word_data(client, page,
					   IR35221_MFR_VOUT_VALLEY);
		break;
	case PMBUS_VIRT_READ_IOUT_MIN:
		ret = pmbus_read_word_data(client, page,
					   IR35221_MFR_IOUT_VALLEY);
		break;
	case PMBUS_VIRT_READ_TEMP_MIN:
		ret = pmbus_read_word_data(client, page,
					   IR35221_MFR_TEMP_VALLEY);
		break;
	default:
		ret = -ENODATA;
		break;
	}

	return ret;
}

__attribute__((used)) static int ir35221_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct pmbus_driver_info *info;
	u8 buf[I2C_SMBUS_BLOCK_MAX];
	int ret;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_READ_BYTE_DATA
				| I2C_FUNC_SMBUS_READ_WORD_DATA
				| I2C_FUNC_SMBUS_READ_BLOCK_DATA))
		return -ENODEV;

	ret = i2c_smbus_read_block_data(client, PMBUS_MFR_ID, buf);
	if (ret < 0) {
		dev_err(&client->dev, "Failed to read PMBUS_MFR_ID\n");
		return ret;
	}
	if (ret != 2 || strncmp(buf, "RI", strlen("RI"))) {
		dev_err(&client->dev, "MFR_ID unrecognised\n");
		return -ENODEV;
	}

	ret = i2c_smbus_read_block_data(client, PMBUS_MFR_MODEL, buf);
	if (ret < 0) {
		dev_err(&client->dev, "Failed to read PMBUS_MFR_MODEL\n");
		return ret;
	}
	if (ret != 2 || !(buf[0] == 0x6c && buf[1] == 0x00)) {
		dev_err(&client->dev, "MFR_MODEL unrecognised\n");
		return -ENODEV;
	}

	info = devm_kzalloc(&client->dev, sizeof(struct pmbus_driver_info),
			    GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->read_word_data = ir35221_read_word_data;

	info->pages = 2;
	info->format[PSC_VOLTAGE_IN] = linear;
	info->format[PSC_VOLTAGE_OUT] = linear;
	info->format[PSC_CURRENT_IN] = linear;
	info->format[PSC_CURRENT_OUT] = linear;
	info->format[PSC_POWER] = linear;
	info->format[PSC_TEMPERATURE] = linear;

	info->func[0] = PMBUS_HAVE_VIN
		| PMBUS_HAVE_VOUT | PMBUS_HAVE_IIN
		| PMBUS_HAVE_IOUT | PMBUS_HAVE_PIN
		| PMBUS_HAVE_POUT | PMBUS_HAVE_TEMP
		| PMBUS_HAVE_STATUS_VOUT | PMBUS_HAVE_STATUS_IOUT
		| PMBUS_HAVE_STATUS_INPUT | PMBUS_HAVE_STATUS_TEMP;
	info->func[1] = info->func[0];

	return pmbus_do_probe(client, id, info);
}

