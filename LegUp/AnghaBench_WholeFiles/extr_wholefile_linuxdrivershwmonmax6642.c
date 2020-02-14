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
struct sensor_device_attribute_2 {size_t nr; int /*<<< orphan*/  index; } ;
struct sensor_device_attribute {size_t index; } ;
struct max6642_data {int* temp_high; int valid; int* temp_input; int alarms; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int MAX6642_REG_R_CONFIG ; 
 int MAX6642_REG_R_LOCAL_HIGH ; 
 int MAX6642_REG_R_LOCAL_TEMP ; 
 int MAX6642_REG_R_LOCAL_TEMPL ; 
 int MAX6642_REG_R_MAN_ID ; 
 int MAX6642_REG_R_REMOTE_HIGH ; 
 int MAX6642_REG_R_REMOTE_TEMP ; 
 int MAX6642_REG_R_REMOTE_TEMPL ; 
 int MAX6642_REG_R_STATUS ; 
 int /*<<< orphan*/  MAX6642_REG_W_CONFIG ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int clamp_val (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct max6642_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct max6642_data*,int /*<<< orphan*/ ) ; 
 struct max6642_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  max6642_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static int temp_from_reg10(int val)
{
	return val * 250;
}

__attribute__((used)) static int temp_from_reg(int val)
{
	return val * 1000;
}

__attribute__((used)) static int temp_to_reg(int val)
{
	return val / 1000;
}

__attribute__((used)) static void max6642_init_client(struct max6642_data *data,
				struct i2c_client *client)
{
	u8 config;

	/*
	 * Start the conversions.
	 */
	config = i2c_smbus_read_byte_data(client, MAX6642_REG_R_CONFIG);
	if (config & 0x40)
		i2c_smbus_write_byte_data(client, MAX6642_REG_W_CONFIG,
					  config & 0xBF); /* run */

	data->temp_high[0] = i2c_smbus_read_byte_data(client,
				MAX6642_REG_R_LOCAL_HIGH);
	data->temp_high[1] = i2c_smbus_read_byte_data(client,
				MAX6642_REG_R_REMOTE_HIGH);
}

__attribute__((used)) static int max6642_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	u8 reg_config, reg_status, man_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* identification */
	man_id = i2c_smbus_read_byte_data(client, MAX6642_REG_R_MAN_ID);
	if (man_id != 0x4D)
		return -ENODEV;

	/* sanity check */
	if (i2c_smbus_read_byte_data(client, 0x04) != 0x4D
	    || i2c_smbus_read_byte_data(client, 0x06) != 0x4D
	    || i2c_smbus_read_byte_data(client, 0xff) != 0x4D)
		return -ENODEV;

	/*
	 * We read the config and status register, the 4 lower bits in the
	 * config register should be zero and bit 5, 3, 1 and 0 should be
	 * zero in the status register.
	 */
	reg_config = i2c_smbus_read_byte_data(client, MAX6642_REG_R_CONFIG);
	if ((reg_config & 0x0f) != 0x00)
		return -ENODEV;

	/* in between, another round of sanity checks */
	if (i2c_smbus_read_byte_data(client, 0x04) != reg_config
	    || i2c_smbus_read_byte_data(client, 0x06) != reg_config
	    || i2c_smbus_read_byte_data(client, 0xff) != reg_config)
		return -ENODEV;

	reg_status = i2c_smbus_read_byte_data(client, MAX6642_REG_R_STATUS);
	if ((reg_status & 0x2b) != 0x00)
		return -ENODEV;

	strlcpy(info->type, "max6642", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static struct max6642_data *max6642_update_device(struct device *dev)
{
	struct max6642_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u16 val, tmp;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		dev_dbg(dev, "Updating max6642 data.\n");
		val = i2c_smbus_read_byte_data(client,
					MAX6642_REG_R_LOCAL_TEMPL);
		tmp = (val >> 6) & 3;
		val = i2c_smbus_read_byte_data(client,
					MAX6642_REG_R_LOCAL_TEMP);
		val = (val << 2) | tmp;
		data->temp_input[0] = val;
		val = i2c_smbus_read_byte_data(client,
					MAX6642_REG_R_REMOTE_TEMPL);
		tmp = (val >> 6) & 3;
		val = i2c_smbus_read_byte_data(client,
					MAX6642_REG_R_REMOTE_TEMP);
		val = (val << 2) | tmp;
		data->temp_input[1] = val;
		data->alarms = i2c_smbus_read_byte_data(client,
					MAX6642_REG_R_STATUS);

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_temp_max10(struct device *dev,
			       struct device_attribute *dev_attr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6642_data *data = max6642_update_device(dev);

	return sprintf(buf, "%d\n",
		       temp_from_reg10(data->temp_input[attr->index]));
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(attr);
	struct max6642_data *data = max6642_update_device(dev);

	return sprintf(buf, "%d\n", temp_from_reg(data->temp_high[attr2->nr]));
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(attr);
	struct max6642_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_high[attr2->nr] = clamp_val(temp_to_reg(val), 0, 255);
	i2c_smbus_write_byte_data(data->client, attr2->index,
				  data->temp_high[attr2->nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct max6642_data *data = max6642_update_device(dev);
	return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static int max6642_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct max6642_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(dev, sizeof(struct max6642_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the MAX6642 chip */
	max6642_init_client(data, client);

	hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
							   client->name, data,
							   max6642_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

