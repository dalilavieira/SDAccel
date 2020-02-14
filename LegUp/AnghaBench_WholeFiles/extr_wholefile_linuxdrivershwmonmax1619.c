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
struct sensor_device_attribute {size_t index; } ;
struct max1619_data {int valid; int* temp; int alarms; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; int /*<<< orphan*/  addr; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int /*<<< orphan*/  MAX1619_REG_R_CHIP_ID ; 
 int /*<<< orphan*/  MAX1619_REG_R_CONFIG ; 
 int /*<<< orphan*/  MAX1619_REG_R_CONVRATE ; 
 int /*<<< orphan*/  MAX1619_REG_R_MAN_ID ; 
 int /*<<< orphan*/  MAX1619_REG_R_STATUS ; 
 int /*<<< orphan*/  MAX1619_REG_W_CONFIG ; 
 int /*<<< orphan*/  MAX1619_REG_W_CONVRATE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct max1619_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,int) ; 
 struct device* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct max1619_data*,int /*<<< orphan*/ ) ; 
 struct max1619_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 void* i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  max1619_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * regs_read ; 
 int /*<<< orphan*/ * regs_write ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int t_num_regs ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int temp_from_reg(int val)
{
	return (val & 0x80 ? val-0x100 : val) * 1000;
}

__attribute__((used)) static int temp_to_reg(int val)
{
	return (val < 0 ? val+0x100*1000 : val) / 1000;
}

__attribute__((used)) static struct max1619_data *max1619_update_device(struct device *dev)
{
	struct max1619_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int config, i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ * 2) || !data->valid) {
		dev_dbg(&client->dev, "Updating max1619 data.\n");
		for (i = 0; i < t_num_regs; i++)
			data->temp[i] = i2c_smbus_read_byte_data(client,
					regs_read[i]);
		data->alarms = i2c_smbus_read_byte_data(client,
					MAX1619_REG_R_STATUS);
		/* If OVERT polarity is low, reverse alarm bit */
		config = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONFIG);
		if (!(config & 0x20))
			data->alarms ^= 0x02;

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
			 char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct max1619_data *data = max1619_update_device(dev);

	return sprintf(buf, "%d\n", temp_from_reg(data->temp[attr->index]));
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
			   const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct max1619_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp[attr->index] = temp_to_reg(val);
	i2c_smbus_write_byte_data(client, regs_write[attr->index],
				  data->temp[attr->index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct max1619_data *data = max1619_update_device(dev);
	return sprintf(buf, "%d\n", data->alarms);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct max1619_data *data = max1619_update_device(dev);
	return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static int max1619_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	u8 reg_config, reg_convrate, reg_status, man_id, chip_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* detection */
	reg_config = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONFIG);
	reg_convrate = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONVRATE);
	reg_status = i2c_smbus_read_byte_data(client, MAX1619_REG_R_STATUS);
	if ((reg_config & 0x03) != 0x00
	 || reg_convrate > 0x07 || (reg_status & 0x61) != 0x00) {
		dev_dbg(&adapter->dev, "MAX1619 detection failed at 0x%02x\n",
			client->addr);
		return -ENODEV;
	}

	/* identification */
	man_id = i2c_smbus_read_byte_data(client, MAX1619_REG_R_MAN_ID);
	chip_id = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CHIP_ID);
	if (man_id != 0x4D || chip_id != 0x04) {
		dev_info(&adapter->dev,
			 "Unsupported chip (man_id=0x%02X, chip_id=0x%02X).\n",
			 man_id, chip_id);
		return -ENODEV;
	}

	strlcpy(info->type, "max1619", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void max1619_init_client(struct i2c_client *client)
{
	u8 config;

	/*
	 * Start the conversions.
	 */
	i2c_smbus_write_byte_data(client, MAX1619_REG_W_CONVRATE,
				  5); /* 2 Hz */
	config = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONFIG);
	if (config & 0x40)
		i2c_smbus_write_byte_data(client, MAX1619_REG_W_CONFIG,
					  config & 0xBF); /* run */
}

__attribute__((used)) static int max1619_probe(struct i2c_client *new_client,
			 const struct i2c_device_id *id)
{
	struct max1619_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(&new_client->dev, sizeof(struct max1619_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = new_client;
	mutex_init(&data->update_lock);

	/* Initialize the MAX1619 chip */
	max1619_init_client(new_client);

	hwmon_dev = devm_hwmon_device_register_with_groups(&new_client->dev,
							   new_client->name,
							   data,
							   max1619_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

