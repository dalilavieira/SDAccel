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
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct i2c_adapter* adapter; struct device dev; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct attribute_group {int dummy; } ;
struct ad7418_data {int valid; int* temp; int adc_max; int* in; scalar_t__ type; struct i2c_client* client; int /*<<< orphan*/  lock; scalar_t__ last_updated; } ;
typedef  int ssize_t ;
typedef  int s16 ;

/* Variables and functions */
 int AD7418_CH_TEMP ; 
 int /*<<< orphan*/  AD7418_REG_ADC ; 
 int AD7418_REG_ADC_CH (int) ; 
 int /*<<< orphan*/  AD7418_REG_CONF ; 
 int /*<<< orphan*/  AD7418_REG_CONF2 ; 
 int /*<<< orphan*/ * AD7418_REG_TEMP ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  LM75_TEMP_MAX ; 
 int /*<<< orphan*/  LM75_TEMP_MIN ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
#define  ad7416 130 
 struct attribute_group** ad7416_groups ; 
#define  ad7417 129 
 struct attribute_group** ad7417_groups ; 
#define  ad7418 128 
 struct attribute_group** ad7418_groups ; 
 int clamp_val (long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ad7418_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ad7418_data*,struct attribute_group const**) ; 
 struct ad7418_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 struct ad7418_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ad7418_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 void* i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline u16 LM75_TEMP_TO_REG(long temp)
{
	int ntemp = clamp_val(temp, LM75_TEMP_MIN, LM75_TEMP_MAX);
	ntemp += (ntemp < 0 ? -250 : 250);
	return (u16)((ntemp / 500) << 7);
}

__attribute__((used)) static inline int LM75_TEMP_FROM_REG(u16 reg)
{
	/* use integer division instead of equivalent right shift to
	   guarantee arithmetic shift and preserve the sign */
	return ((s16)reg / 128) * 500;
}

__attribute__((used)) static struct ad7418_data *ad7418_update_device(struct device *dev)
{
	struct ad7418_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
		|| !data->valid) {
		u8 cfg;
		int i, ch;

		/* read config register and clear channel bits */
		cfg = i2c_smbus_read_byte_data(client, AD7418_REG_CONF);
		cfg &= 0x1F;

		i2c_smbus_write_byte_data(client, AD7418_REG_CONF,
						cfg | AD7418_CH_TEMP);
		udelay(30);

		for (i = 0; i < 3; i++) {
			data->temp[i] =
				i2c_smbus_read_word_swapped(client,
						AD7418_REG_TEMP[i]);
		}

		for (i = 0, ch = 4; i < data->adc_max; i++, ch--) {
			i2c_smbus_write_byte_data(client,
					AD7418_REG_CONF,
					cfg | AD7418_REG_ADC_CH(ch));

			udelay(15);
			data->in[data->adc_max - 1 - i] =
				i2c_smbus_read_word_swapped(client,
						AD7418_REG_ADC);
		}

		/* restore old configuration value */
		i2c_smbus_write_word_swapped(client, AD7418_REG_CONF, cfg);

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->lock);

	return data;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
			char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct ad7418_data *data = ad7418_update_device(dev);
	return sprintf(buf, "%d\n",
		LM75_TEMP_FROM_REG(data->temp[attr->index]));
}

__attribute__((used)) static ssize_t show_adc(struct device *dev, struct device_attribute *devattr,
			char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct ad7418_data *data = ad7418_update_device(dev);

	return sprintf(buf, "%d\n",
		((data->in[attr->index] >> 6) * 2500 + 512) / 1024);
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
			const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct ad7418_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long temp;
	int ret = kstrtol(buf, 10, &temp);

	if (ret < 0)
		return ret;

	mutex_lock(&data->lock);
	data->temp[attr->index] = LM75_TEMP_TO_REG(temp);
	i2c_smbus_write_word_swapped(client,
				     AD7418_REG_TEMP[attr->index],
				     data->temp[attr->index]);
	mutex_unlock(&data->lock);
	return count;
}

__attribute__((used)) static void ad7418_init_client(struct i2c_client *client)
{
	struct ad7418_data *data = i2c_get_clientdata(client);

	int reg = i2c_smbus_read_byte_data(client, AD7418_REG_CONF);
	if (reg < 0) {
		dev_err(&client->dev, "cannot read configuration register\n");
	} else {
		dev_info(&client->dev, "configuring for mode 1\n");
		i2c_smbus_write_byte_data(client, AD7418_REG_CONF, reg & 0xfe);

		if (data->type == ad7417 || data->type == ad7418)
			i2c_smbus_write_byte_data(client,
						AD7418_REG_CONF2, 0x00);
	}
}

__attribute__((used)) static int ad7418_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct i2c_adapter *adapter = client->adapter;
	struct ad7418_data *data;
	struct device *hwmon_dev;
	const struct attribute_group **attr_groups = NULL;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
					I2C_FUNC_SMBUS_WORD_DATA))
		return -EOPNOTSUPP;

	data = devm_kzalloc(dev, sizeof(struct ad7418_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);

	mutex_init(&data->lock);
	data->client = client;
	data->type = id->driver_data;

	switch (data->type) {
	case ad7416:
		data->adc_max = 0;
		attr_groups = ad7416_groups;
		break;

	case ad7417:
		data->adc_max = 4;
		attr_groups = ad7417_groups;
		break;

	case ad7418:
		data->adc_max = 1;
		attr_groups = ad7418_groups;
		break;
	}

	dev_info(dev, "%s chip found\n", client->name);

	/* Initialize the AD7418 chip */
	ad7418_init_client(client);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev,
							   client->name,
							   data, attr_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

