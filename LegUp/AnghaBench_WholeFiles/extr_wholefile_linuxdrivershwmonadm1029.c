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
typedef  int u16 ;
struct sensor_device_attribute {size_t index; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct adm1029_data {int valid; int* fan; int* fan_div; int /*<<< orphan*/  update_lock; struct i2c_client* client; void** temp; scalar_t__ last_updated; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADM1029_REG_CHIP_ID ; 
 int /*<<< orphan*/  ADM1029_REG_CONFIG ; 
 int /*<<< orphan*/ * ADM1029_REG_FAN ; 
 int /*<<< orphan*/ * ADM1029_REG_FAN_DIV ; 
 int /*<<< orphan*/  ADM1029_REG_MAN_ID ; 
 int /*<<< orphan*/  ADM1029_REG_NB_FAN_SUPPORT ; 
 int /*<<< orphan*/ * ADM1029_REG_TEMP ; 
 int /*<<< orphan*/  ADM1029_REG_TEMP_DEVICES_INSTALLED ; 
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int DIV_FROM_REG (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int TEMP_FROM_REG (void*) ; 
 int /*<<< orphan*/  adm1029_groups ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct adm1029_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct adm1029_data*,int /*<<< orphan*/ ) ; 
 struct adm1029_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 void* i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*,int) ; 
 int sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static struct adm1029_data *adm1029_update_device(struct device *dev)
{
	struct adm1029_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->update_lock);
	/*
	 * Use the "cache" Luke, don't recheck values
	 * if there are already checked not a long time later
	 */
	if (time_after(jiffies, data->last_updated + HZ * 2)
	 || !data->valid) {
		int nr;

		dev_dbg(&client->dev, "Updating adm1029 data\n");

		for (nr = 0; nr < ARRAY_SIZE(ADM1029_REG_TEMP); nr++) {
			data->temp[nr] =
			    i2c_smbus_read_byte_data(client,
						     ADM1029_REG_TEMP[nr]);
		}
		for (nr = 0; nr < ARRAY_SIZE(ADM1029_REG_FAN); nr++) {
			data->fan[nr] =
			    i2c_smbus_read_byte_data(client,
						     ADM1029_REG_FAN[nr]);
		}
		for (nr = 0; nr < ARRAY_SIZE(ADM1029_REG_FAN_DIV); nr++) {
			data->fan_div[nr] =
			    i2c_smbus_read_byte_data(client,
						     ADM1029_REG_FAN_DIV[nr]);
		}

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t
show_temp(struct device *dev, struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct adm1029_data *data = adm1029_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}

__attribute__((used)) static ssize_t
show_fan(struct device *dev, struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct adm1029_data *data = adm1029_update_device(dev);
	u16 val;
	if (data->fan[attr->index] == 0
	    || (data->fan_div[attr->index] & 0xC0) == 0
	    || data->fan[attr->index] == 255) {
		return sprintf(buf, "0\n");
	}

	val = 1880 * 120 / DIV_FROM_REG(data->fan_div[attr->index])
	    / data->fan[attr->index];
	return sprintf(buf, "%d\n", val);
}

__attribute__((used)) static ssize_t
show_fan_div(struct device *dev, struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct adm1029_data *data = adm1029_update_device(dev);
	if ((data->fan_div[attr->index] & 0xC0) == 0)
		return sprintf(buf, "0\n");
	return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[attr->index]));
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev,
	    struct device_attribute *devattr, const char *buf, size_t count)
{
	struct adm1029_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	u8 reg;
	long val;
	int ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	mutex_lock(&data->update_lock);

	/*Read actual config */
	reg = i2c_smbus_read_byte_data(client,
				       ADM1029_REG_FAN_DIV[attr->index]);

	switch (val) {
	case 1:
		val = 1;
		break;
	case 2:
		val = 2;
		break;
	case 4:
		val = 3;
		break;
	default:
		mutex_unlock(&data->update_lock);
		dev_err(&client->dev,
			"fan_div value %ld not supported. Choose one of 1, 2 or 4!\n",
			val);
		return -EINVAL;
	}
	/* Update the value */
	reg = (reg & 0x3F) | (val << 6);

	/* Update the cache */
	data->fan_div[attr->index] = reg;

	/* Write value */
	i2c_smbus_write_byte_data(client,
				  ADM1029_REG_FAN_DIV[attr->index], reg);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static int adm1029_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	u8 man_id, chip_id, temp_devices_installed, nb_fan_support;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/*
	 * ADM1029 doesn't have CHIP ID, check just MAN ID
	 * For better detection we check also ADM1029_TEMP_DEVICES_INSTALLED,
	 * ADM1029_REG_NB_FAN_SUPPORT and compare it with possible values
	 * documented
	 */

	man_id = i2c_smbus_read_byte_data(client, ADM1029_REG_MAN_ID);
	chip_id = i2c_smbus_read_byte_data(client, ADM1029_REG_CHIP_ID);
	temp_devices_installed = i2c_smbus_read_byte_data(client,
					ADM1029_REG_TEMP_DEVICES_INSTALLED);
	nb_fan_support = i2c_smbus_read_byte_data(client,
						ADM1029_REG_NB_FAN_SUPPORT);
	/* 0x41 is Analog Devices */
	if (man_id != 0x41 || (temp_devices_installed & 0xf9) != 0x01
	    || nb_fan_support != 0x03)
		return -ENODEV;

	if ((chip_id & 0xF0) != 0x00) {
		/*
		 * There are no "official" CHIP ID, so actually
		 * we use Major/Minor revision for that
		 */
		pr_info("Unknown major revision %x, please let us know\n",
			chip_id);
		return -ENODEV;
	}

	strlcpy(info->type, "adm1029", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int adm1029_init_client(struct i2c_client *client)
{
	u8 config;

	config = i2c_smbus_read_byte_data(client, ADM1029_REG_CONFIG);
	if ((config & 0x10) == 0) {
		i2c_smbus_write_byte_data(client, ADM1029_REG_CONFIG,
					  config | 0x10);
	}
	/* recheck config */
	config = i2c_smbus_read_byte_data(client, ADM1029_REG_CONFIG);
	if ((config & 0x10) == 0) {
		dev_err(&client->dev, "Initialization failed!\n");
		return 0;
	}
	return 1;
}

__attribute__((used)) static int adm1029_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct adm1029_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(dev, sizeof(struct adm1029_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/*
	 * Initialize the ADM1029 chip
	 * Check config register
	 */
	if (adm1029_init_client(client) == 0)
		return -ENODEV;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   adm1029_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

