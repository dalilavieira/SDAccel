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
struct ltc4215_data {int valid; size_t* regs; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int ARRAY_SIZE (size_t*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
#define  LTC4215_ADIN 130 
 int /*<<< orphan*/  LTC4215_FAULT ; 
#define  LTC4215_SENSE 129 
#define  LTC4215_SOURCE 128 
 size_t LTC4215_STATUS ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 unsigned int abs (int const) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct ltc4215_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ltc4215_data*,int /*<<< orphan*/ ) ; 
 struct ltc4215_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  ltc4215_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int const) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct ltc4215_data *ltc4215_update_device(struct device *dev)
{
	struct ltc4215_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	s32 val;
	int i;

	mutex_lock(&data->update_lock);

	/* The chip's A/D updates 10 times per second */
	if (time_after(jiffies, data->last_updated + HZ / 10) || !data->valid) {

		dev_dbg(&client->dev, "Starting ltc4215 update\n");

		/* Read all registers */
		for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
			val = i2c_smbus_read_byte_data(client, i);
			if (unlikely(val < 0))
				data->regs[i] = 0;
			else
				data->regs[i] = val;
		}

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static int ltc4215_get_voltage(struct device *dev, u8 reg)
{
	struct ltc4215_data *data = ltc4215_update_device(dev);
	const u8 regval = data->regs[reg];
	u32 voltage = 0;

	switch (reg) {
	case LTC4215_SENSE:
		/* 151 uV per increment */
		voltage = regval * 151 / 1000;
		break;
	case LTC4215_SOURCE:
		/* 60.5 mV per increment */
		voltage = regval * 605 / 10;
		break;
	case LTC4215_ADIN:
		/*
		 * The ADIN input is divided by 12.5, and has 4.82 mV
		 * per increment, so we have the additional multiply
		 */
		voltage = regval * 482 * 125 / 1000;
		break;
	default:
		/* If we get here, the developer messed up */
		WARN_ON_ONCE(1);
		break;
	}

	return voltage;
}

__attribute__((used)) static unsigned int ltc4215_get_current(struct device *dev)
{
	struct ltc4215_data *data = ltc4215_update_device(dev);

	/*
	 * The strange looking conversions that follow are fixed-point
	 * math, since we cannot do floating point in the kernel.
	 *
	 * Step 1: convert sense register to microVolts
	 * Step 2: convert voltage to milliAmperes
	 *
	 * If you play around with the V=IR equation, you come up with
	 * the following: X uV / Y mOhm == Z mA
	 *
	 * With the resistors that are fractions of a milliOhm, we multiply
	 * the voltage and resistance by 10, to shift the decimal point.
	 * Now we can use the normal division operator again.
	 */

	/* Calculate voltage in microVolts (151 uV per increment) */
	const unsigned int voltage = data->regs[LTC4215_SENSE] * 151;

	/* Calculate current in milliAmperes (4 milliOhm sense resistor) */
	const unsigned int curr = voltage / 4;

	return curr;
}

__attribute__((used)) static ssize_t ltc4215_show_voltage(struct device *dev,
				    struct device_attribute *da,
				    char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	const int voltage = ltc4215_get_voltage(dev, attr->index);

	return snprintf(buf, PAGE_SIZE, "%d\n", voltage);
}

__attribute__((used)) static ssize_t ltc4215_show_current(struct device *dev,
				    struct device_attribute *da,
				    char *buf)
{
	const unsigned int curr = ltc4215_get_current(dev);

	return snprintf(buf, PAGE_SIZE, "%u\n", curr);
}

__attribute__((used)) static ssize_t ltc4215_show_power(struct device *dev,
				  struct device_attribute *da,
				  char *buf)
{
	const unsigned int curr = ltc4215_get_current(dev);
	const int output_voltage = ltc4215_get_voltage(dev, LTC4215_ADIN);

	/* current in mA * voltage in mV == power in uW */
	const unsigned int power = abs(output_voltage * curr);

	return snprintf(buf, PAGE_SIZE, "%u\n", power);
}

__attribute__((used)) static ssize_t ltc4215_show_alarm(struct device *dev,
					  struct device_attribute *da,
					  char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ltc4215_data *data = ltc4215_update_device(dev);
	const u8 reg = data->regs[LTC4215_STATUS];
	const u32 mask = attr->index;

	return snprintf(buf, PAGE_SIZE, "%u\n", !!(reg & mask));
}

__attribute__((used)) static int ltc4215_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct device *dev = &client->dev;
	struct ltc4215_data *data;
	struct device *hwmon_dev;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the LTC4215 chip */
	i2c_smbus_write_byte_data(client, LTC4215_FAULT, 0x00);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   ltc4215_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

