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
typedef  size_t u8 ;
typedef  int u32 ;
struct sensor_device_attribute {size_t index; } ;
struct ltc4151_data {int valid; int* regs; int shunt; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct ltc4151_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 scalar_t__ IS_ERR (struct ltc4151_data*) ; 
#define  LTC4151_ADIN_H 130 
#define  LTC4151_SENSE_H 129 
#define  LTC4151_VIN_H 128 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PTR_ERR (struct ltc4151_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 struct ltc4151_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ltc4151_data*,int /*<<< orphan*/ ) ; 
 struct ltc4151_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  ltc4151_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct ltc4151_data *ltc4151_update_device(struct device *dev)
{
	struct ltc4151_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct ltc4151_data *ret = data;

	mutex_lock(&data->update_lock);

	/*
	 * The chip's A/D updates 6 times per second
	 * (Conversion Rate 6 - 9 Hz)
	 */
	if (time_after(jiffies, data->last_updated + HZ / 6) || !data->valid) {
		int i;

		dev_dbg(&client->dev, "Starting ltc4151 update\n");

		/* Read all registers */
		for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
			int val;

			val = i2c_smbus_read_byte_data(client, i);
			if (unlikely(val < 0)) {
				dev_dbg(dev,
					"Failed to read ADC value: error %d\n",
					val);
				ret = ERR_PTR(val);
				goto abort;
			}
			data->regs[i] = val;
		}
		data->last_updated = jiffies;
		data->valid = 1;
	}
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static int ltc4151_get_value(struct ltc4151_data *data, u8 reg)
{
	u32 val;

	val = (data->regs[reg] << 4) + (data->regs[reg + 1] >> 4);

	switch (reg) {
	case LTC4151_ADIN_H:
		/* 500uV resolution. Convert to mV. */
		val = val * 500 / 1000;
		break;
	case LTC4151_SENSE_H:
		/*
		 * 20uV resolution. Convert to current as measured with
		 * a given sense resistor, in mA.
		 */
		val = val * 20 * 1000 / data->shunt;
		break;
	case LTC4151_VIN_H:
		/* 25 mV per increment */
		val = val * 25;
		break;
	default:
		/* If we get here, the developer messed up */
		WARN_ON_ONCE(1);
		val = 0;
		break;
	}

	return val;
}

__attribute__((used)) static ssize_t ltc4151_show_value(struct device *dev,
				  struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ltc4151_data *data = ltc4151_update_device(dev);
	int value;

	if (IS_ERR(data))
		return PTR_ERR(data);

	value = ltc4151_get_value(data, attr->index);
	return snprintf(buf, PAGE_SIZE, "%d\n", value);
}

__attribute__((used)) static int ltc4151_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct device *dev = &client->dev;
	struct ltc4151_data *data;
	struct device *hwmon_dev;
	u32 shunt;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	if (of_property_read_u32(client->dev.of_node,
				 "shunt-resistor-micro-ohms", &shunt))
		shunt = 1000; /* 1 mOhm if not set via DT */

	if (shunt == 0)
		return -EINVAL;

	data->shunt = shunt;

	data->client = client;
	mutex_init(&data->update_lock);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   ltc4151_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

