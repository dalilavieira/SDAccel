#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; int /*<<< orphan*/  adapter; } ;
struct device_attribute {int dummy; } ;
struct ad7414_data {int valid; int temp_input; int* temps; int /*<<< orphan*/  lock; struct i2c_client* client; scalar_t__ next_update; } ;
typedef  int ssize_t ;
typedef  int s16 ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int AD7414_REG_CONF ; 
 int* AD7414_REG_LIMIT ; 
 int AD7414_REG_TEMP ; 
 int ARRAY_SIZE (int*) ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_READ_WORD_DATA ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  ad7414_groups ; 
 long clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 struct ad7414_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ad7414_data*,int /*<<< orphan*/ ) ; 
 struct ad7414_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline int ad7414_temp_from_reg(s16 reg)
{
	/*
	 * use integer division instead of equivalent right shift to
	 * guarantee arithmetic shift and preserve the sign
	 */
	return ((int)reg / 64) * 250;
}

__attribute__((used)) static inline int ad7414_read(struct i2c_client *client, u8 reg)
{
	if (reg == AD7414_REG_TEMP)
		return i2c_smbus_read_word_swapped(client, reg);
	else
		return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static inline int ad7414_write(struct i2c_client *client, u8 reg, u8 value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static struct ad7414_data *ad7414_update_device(struct device *dev)
{
	struct ad7414_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->lock);

	if (time_after(jiffies, data->next_update) || !data->valid) {
		int value, i;

		dev_dbg(&client->dev, "starting ad7414 update\n");

		value = ad7414_read(client, AD7414_REG_TEMP);
		if (value < 0)
			dev_dbg(&client->dev, "AD7414_REG_TEMP err %d\n",
				value);
		else
			data->temp_input = value;

		for (i = 0; i < ARRAY_SIZE(AD7414_REG_LIMIT); ++i) {
			value = ad7414_read(client, AD7414_REG_LIMIT[i]);
			if (value < 0)
				dev_dbg(&client->dev, "AD7414 reg %d err %d\n",
					AD7414_REG_LIMIT[i], value);
			else
				data->temps[i] = value;
		}

		data->next_update = jiffies + HZ + HZ / 2;
		data->valid = 1;
	}

	mutex_unlock(&data->lock);

	return data;
}

__attribute__((used)) static ssize_t show_temp_input(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct ad7414_data *data = ad7414_update_device(dev);
	return sprintf(buf, "%d\n", ad7414_temp_from_reg(data->temp_input));
}

__attribute__((used)) static ssize_t show_max_min(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct ad7414_data *data = ad7414_update_device(dev);
	return sprintf(buf, "%d\n", data->temps[index] * 1000);
}

__attribute__((used)) static ssize_t set_max_min(struct device *dev,
			   struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct ad7414_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int index = to_sensor_dev_attr(attr)->index;
	u8 reg = AD7414_REG_LIMIT[index];
	long temp;
	int ret = kstrtol(buf, 10, &temp);

	if (ret < 0)
		return ret;

	temp = clamp_val(temp, -40000, 85000);
	temp = (temp + (temp < 0 ? -500 : 500)) / 1000;

	mutex_lock(&data->lock);
	data->temps[index] = temp;
	ad7414_write(client, reg, temp);
	mutex_unlock(&data->lock);
	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct ad7414_data *data = ad7414_update_device(dev);
	int value = (data->temp_input >> bitnr) & 1;
	return sprintf(buf, "%d\n", value);
}

__attribute__((used)) static int ad7414_probe(struct i2c_client *client,
			const struct i2c_device_id *dev_id)
{
	struct device *dev = &client->dev;
	struct ad7414_data *data;
	struct device *hwmon_dev;
	int conf;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_READ_WORD_DATA))
		return -EOPNOTSUPP;

	data = devm_kzalloc(dev, sizeof(struct ad7414_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->lock);

	dev_info(&client->dev, "chip found\n");

	/* Make sure the chip is powered up. */
	conf = i2c_smbus_read_byte_data(client, AD7414_REG_CONF);
	if (conf < 0)
		dev_warn(dev, "ad7414_probe unable to read config register.\n");
	else {
		conf &= ~(1 << 7);
		i2c_smbus_write_byte_data(client, AD7414_REG_CONF, conf);
	}

	hwmon_dev = devm_hwmon_device_register_with_groups(dev,
							   client->name,
							   data, ad7414_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

