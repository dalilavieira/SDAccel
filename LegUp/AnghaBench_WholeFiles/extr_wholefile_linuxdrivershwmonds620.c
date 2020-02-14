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
typedef  int u16 ;
struct sensor_device_attribute {size_t index; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct ds620_platform_data {int pomode; } ;
struct ds620_data {int valid; int* temp; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  DS620_COM_START ; 
 int /*<<< orphan*/  DS620_REG_CONF ; 
 int DS620_REG_CONFIG_1SHOT ; 
 int DS620_REG_CONFIG_PO1 ; 
 int DS620_REG_CONFIG_PO2 ; 
 int DS620_REG_CONFIG_R0 ; 
 int DS620_REG_CONFIG_R1 ; 
 int /*<<< orphan*/ * DS620_REG_TEMP ; 
 int ENOMEM ; 
 struct ds620_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 scalar_t__ IS_ERR (struct ds620_data*) ; 
 int PTR_ERR (struct ds620_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct ds620_data* dev_get_drvdata (struct device*) ; 
 struct ds620_platform_data* dev_get_platdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ds620_data*,int /*<<< orphan*/ ) ; 
 struct ds620_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ds620_groups ; 
 void* i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static void ds620_init_client(struct i2c_client *client)
{
	struct ds620_platform_data *ds620_info = dev_get_platdata(&client->dev);
	u16 conf, new_conf;

	new_conf = conf =
	    i2c_smbus_read_word_swapped(client, DS620_REG_CONF);

	/* switch to continuous conversion mode */
	new_conf &= ~DS620_REG_CONFIG_1SHOT;
	/* already high at power-on, but don't trust the BIOS! */
	new_conf |= DS620_REG_CONFIG_PO2;
	/* thermostat mode according to platform data */
	if (ds620_info && ds620_info->pomode == 1)
		new_conf &= ~DS620_REG_CONFIG_PO1; /* PO_LOW */
	else if (ds620_info && ds620_info->pomode == 2)
		new_conf |= DS620_REG_CONFIG_PO1; /* PO_HIGH */
	else
		new_conf &= ~DS620_REG_CONFIG_PO2; /* always low */
	/* with highest precision */
	new_conf |= DS620_REG_CONFIG_R1 | DS620_REG_CONFIG_R0;

	if (conf != new_conf)
		i2c_smbus_write_word_swapped(client, DS620_REG_CONF, new_conf);

	/* start conversion */
	i2c_smbus_write_byte(client, DS620_COM_START);
}

__attribute__((used)) static struct ds620_data *ds620_update_client(struct device *dev)
{
	struct ds620_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct ds620_data *ret = data;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {
		int i;
		int res;

		dev_dbg(&client->dev, "Starting ds620 update\n");

		for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
			res = i2c_smbus_read_word_swapped(client,
							  DS620_REG_TEMP[i]);
			if (res < 0) {
				ret = ERR_PTR(res);
				goto abort;
			}

			data->temp[i] = res;
		}

		data->last_updated = jiffies;
		data->valid = 1;
	}
abort:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *da,
			 char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ds620_data *data = ds620_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", ((data->temp[attr->index] / 8) * 625) / 10);
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *da,
			const char *buf, size_t count)
{
	int res;
	long val;

	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ds620_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	res = kstrtol(buf, 10, &val);

	if (res)
		return res;

	val = (clamp_val(val, -128000, 128000) * 10 / 625) * 8;

	mutex_lock(&data->update_lock);
	data->temp[attr->index] = val;
	i2c_smbus_write_word_swapped(client, DS620_REG_TEMP[attr->index],
				     data->temp[attr->index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
			  char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ds620_data *data = ds620_update_client(dev);
	struct i2c_client *client;
	u16 conf, new_conf;
	int res;

	if (IS_ERR(data))
		return PTR_ERR(data);

	client = data->client;

	/* reset alarms if necessary */
	res = i2c_smbus_read_word_swapped(client, DS620_REG_CONF);
	if (res < 0)
		return res;

	new_conf = conf = res;
	new_conf &= ~attr->index;
	if (conf != new_conf) {
		res = i2c_smbus_write_word_swapped(client, DS620_REG_CONF,
						   new_conf);
		if (res < 0)
			return res;
	}

	return sprintf(buf, "%d\n", !!(conf & attr->index));
}

__attribute__((used)) static int ds620_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct ds620_data *data;

	data = devm_kzalloc(dev, sizeof(struct ds620_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the DS620 chip */
	ds620_init_client(client);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, ds620_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

