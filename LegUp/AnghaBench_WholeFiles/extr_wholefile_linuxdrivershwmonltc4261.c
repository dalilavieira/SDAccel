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
struct ltc4261_data {int valid; int* regs; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct ltc4261_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 scalar_t__ IS_ERR (struct ltc4261_data*) ; 
#define  LTC4261_ADIN2_H 130 
#define  LTC4261_ADIN_H 129 
 size_t LTC4261_FAULT ; 
#define  LTC4261_SENSE_H 128 
 int LTC4261_STATUS ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PTR_ERR (struct ltc4261_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ltc4261_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ltc4261_data*,int /*<<< orphan*/ ) ; 
 struct ltc4261_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,size_t,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  ltc4261_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct ltc4261_data *ltc4261_update_device(struct device *dev)
{
	struct ltc4261_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct ltc4261_data *ret = data;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ / 4) || !data->valid) {
		int i;

		/* Read registers -- 0x00 to 0x09 */
		for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
			int val;

			val = i2c_smbus_read_byte_data(client, i);
			if (unlikely(val < 0)) {
				dev_dbg(dev,
					"Failed to read ADC value: error %d\n",
					val);
				ret = ERR_PTR(val);
				data->valid = 0;
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

__attribute__((used)) static int ltc4261_get_value(struct ltc4261_data *data, u8 reg)
{
	u32 val;

	val = (data->regs[reg] << 2) + (data->regs[reg + 1] >> 6);

	switch (reg) {
	case LTC4261_ADIN_H:
	case LTC4261_ADIN2_H:
		/* 2.5mV resolution. Convert to mV. */
		val = val * 25 / 10;
		break;
	case LTC4261_SENSE_H:
		/*
		 * 62.5uV resolution. Convert to current as measured with
		 * an 1 mOhm sense resistor, in mA. If a different sense
		 * resistor is installed, calculate the actual current by
		 * dividing the reported current by the sense resistor value
		 * in mOhm.
		 */
		val = val * 625 / 10;
		break;
	default:
		/* If we get here, the developer messed up */
		WARN_ON_ONCE(1);
		val = 0;
		break;
	}

	return val;
}

__attribute__((used)) static ssize_t ltc4261_show_value(struct device *dev,
				  struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ltc4261_data *data = ltc4261_update_device(dev);
	int value;

	if (IS_ERR(data))
		return PTR_ERR(data);

	value = ltc4261_get_value(data, attr->index);
	return snprintf(buf, PAGE_SIZE, "%d\n", value);
}

__attribute__((used)) static ssize_t ltc4261_show_bool(struct device *dev,
				 struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ltc4261_data *data = ltc4261_update_device(dev);
	u8 fault;

	if (IS_ERR(data))
		return PTR_ERR(data);

	fault = data->regs[LTC4261_FAULT] & attr->index;
	if (fault)		/* Clear reported faults in chip register */
		i2c_smbus_write_byte_data(data->client, LTC4261_FAULT, ~fault);

	return snprintf(buf, PAGE_SIZE, "%d\n", fault ? 1 : 0);
}

__attribute__((used)) static int ltc4261_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct device *dev = &client->dev;
	struct ltc4261_data *data;
	struct device *hwmon_dev;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	if (i2c_smbus_read_byte_data(client, LTC4261_STATUS) < 0) {
		dev_err(dev, "Failed to read status register\n");
		return -ENODEV;
	}

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Clear faults */
	i2c_smbus_write_byte_data(client, LTC4261_FAULT, 0x00);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   ltc4261_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

