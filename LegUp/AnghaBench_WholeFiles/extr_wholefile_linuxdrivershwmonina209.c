#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sensor_device_attribute {int index; } ;
struct ina2xx_platform_data {scalar_t__ shunt_uohms; } ;
struct ina209_data {int valid; int last_updated; int update_interval; size_t* regs; int config_orig; int calibration_orig; int /*<<< orphan*/  update_lock; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {int /*<<< orphan*/  name; TYPE_1__ dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int valid; int last_updated; int update_interval; size_t* regs; int config_orig; int calibration_orig; int /*<<< orphan*/  update_lock; struct i2c_client* client; } ;
typedef  int ssize_t ;
typedef  scalar_t__ s32 ;
typedef  long s16 ;

/* Variables and functions */
 int ARRAY_SIZE (size_t*) ; 
 int DIV_ROUND_CLOSEST (long,int) ; 
 int EACCES ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct ina209_data* ERR_PTR (scalar_t__) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WORD_DATA ; 
#define  INA209_BUS_VOLTAGE 146 
#define  INA209_BUS_VOLTAGE_MAX_PEAK 145 
#define  INA209_BUS_VOLTAGE_MIN_PEAK 144 
#define  INA209_BUS_VOLTAGE_OVER_LIMIT 143 
#define  INA209_BUS_VOLTAGE_OVER_WARN 142 
#define  INA209_BUS_VOLTAGE_UNDER_LIMIT 141 
#define  INA209_BUS_VOLTAGE_UNDER_WARN 140 
 size_t INA209_CALIBRATION ; 
 size_t INA209_CONFIGURATION ; 
 int INA209_CONFIG_DEFAULT ; 
#define  INA209_CRITICAL_DAC_NEG 139 
#define  INA209_CRITICAL_DAC_POS 138 
#define  INA209_CURRENT 137 
#define  INA209_POWER 136 
#define  INA209_POWER_OVER_LIMIT 135 
#define  INA209_POWER_PEAK 134 
#define  INA209_POWER_WARN 133 
 int INA209_SHUNT_DEFAULT ; 
#define  INA209_SHUNT_VOLTAGE 132 
#define  INA209_SHUNT_VOLTAGE_NEG_PEAK 131 
#define  INA209_SHUNT_VOLTAGE_NEG_WARN 130 
#define  INA209_SHUNT_VOLTAGE_POS_PEAK 129 
#define  INA209_SHUNT_VOLTAGE_POS_WARN 128 
 size_t INA209_STATUS ; 
 scalar_t__ IS_ERR (struct ina209_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct ina209_data*) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int clamp_val (int,int,int) ; 
 struct ina209_data* dev_get_drvdata (struct ina209_data*) ; 
 struct ina2xx_platform_data* dev_get_platdata (TYPE_1__*) ; 
 struct ina209_data* devm_hwmon_device_register_with_groups (TYPE_1__*,int /*<<< orphan*/ ,struct ina209_data*,int /*<<< orphan*/ ) ; 
 struct ina209_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct ina209_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ina209_data*) ; 
 void* i2c_smbus_read_word_swapped (struct i2c_client*,size_t) ; 
 int /*<<< orphan*/  i2c_smbus_write_word_swapped (struct i2c_client*,size_t,int) ; 
 int /*<<< orphan*/  ina209_groups ; 
 size_t* ina209_reset_history_regs ; 
 int jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ time_after (int,int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static struct ina209_data *ina209_update_device(struct device *dev)
{
	struct ina209_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct ina209_data *ret = data;
	s32 val;
	int i;

	mutex_lock(&data->update_lock);

	if (!data->valid ||
	    time_after(jiffies, data->last_updated + data->update_interval)) {
		for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
			val = i2c_smbus_read_word_swapped(client, i);
			if (val < 0) {
				ret = ERR_PTR(val);
				goto abort;
			}
			data->regs[i] = val;
		}
		data->last_updated = jiffies;
		data->valid = true;
	}
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static long ina209_from_reg(const u8 reg, const u16 val)
{
	switch (reg) {
	case INA209_SHUNT_VOLTAGE:
	case INA209_SHUNT_VOLTAGE_POS_PEAK:
	case INA209_SHUNT_VOLTAGE_NEG_PEAK:
	case INA209_SHUNT_VOLTAGE_POS_WARN:
	case INA209_SHUNT_VOLTAGE_NEG_WARN:
		/* LSB=10 uV. Convert to mV. */
		return DIV_ROUND_CLOSEST((s16)val, 100);

	case INA209_BUS_VOLTAGE:
	case INA209_BUS_VOLTAGE_MAX_PEAK:
	case INA209_BUS_VOLTAGE_MIN_PEAK:
	case INA209_BUS_VOLTAGE_OVER_WARN:
	case INA209_BUS_VOLTAGE_UNDER_WARN:
	case INA209_BUS_VOLTAGE_OVER_LIMIT:
	case INA209_BUS_VOLTAGE_UNDER_LIMIT:
		/* LSB=4 mV, last 3 bits unused */
		return (val >> 3) * 4;

	case INA209_CRITICAL_DAC_POS:
		/* LSB=1 mV, in the upper 8 bits */
		return val >> 8;

	case INA209_CRITICAL_DAC_NEG:
		/* LSB=1 mV, in the upper 8 bits */
		return -1 * (val >> 8);

	case INA209_POWER:
	case INA209_POWER_PEAK:
	case INA209_POWER_WARN:
	case INA209_POWER_OVER_LIMIT:
		/* LSB=20 mW. Convert to uW */
		return val * 20 * 1000L;

	case INA209_CURRENT:
		/* LSB=1 mA (selected). Is in mA */
		return (s16)val;
	}

	/* programmer goofed */
	WARN_ON_ONCE(1);
	return 0;
}

__attribute__((used)) static int ina209_to_reg(u8 reg, u16 old, long val)
{
	switch (reg) {
	case INA209_SHUNT_VOLTAGE_POS_WARN:
	case INA209_SHUNT_VOLTAGE_NEG_WARN:
		/* Limit to +- 320 mV, 10 uV LSB */
		return clamp_val(val, -320, 320) * 100;

	case INA209_BUS_VOLTAGE_OVER_WARN:
	case INA209_BUS_VOLTAGE_UNDER_WARN:
	case INA209_BUS_VOLTAGE_OVER_LIMIT:
	case INA209_BUS_VOLTAGE_UNDER_LIMIT:
		/*
		 * Limit to 0-32000 mV, 4 mV LSB
		 *
		 * The last three bits aren't part of the value, but we'll
		 * preserve them in their original state.
		 */
		return (DIV_ROUND_CLOSEST(clamp_val(val, 0, 32000), 4) << 3)
		  | (old & 0x7);

	case INA209_CRITICAL_DAC_NEG:
		/*
		 * Limit to -255-0 mV, 1 mV LSB
		 * Convert the value to a positive value for the register
		 *
		 * The value lives in the top 8 bits only, be careful
		 * and keep original value of other bits.
		 */
		return (clamp_val(-val, 0, 255) << 8) | (old & 0xff);

	case INA209_CRITICAL_DAC_POS:
		/*
		 * Limit to 0-255 mV, 1 mV LSB
		 *
		 * The value lives in the top 8 bits only, be careful
		 * and keep original value of other bits.
		 */
		return (clamp_val(val, 0, 255) << 8) | (old & 0xff);

	case INA209_POWER_WARN:
	case INA209_POWER_OVER_LIMIT:
		/* 20 mW LSB */
		return DIV_ROUND_CLOSEST(val, 20 * 1000);
	}

	/* Other registers are read-only, return access error */
	return -EACCES;
}

__attribute__((used)) static int ina209_interval_from_reg(u16 reg)
{
	return 68 >> (15 - ((reg >> 3) & 0x0f));
}

__attribute__((used)) static u16 ina209_reg_from_interval(u16 config, long interval)
{
	int i, adc;

	if (interval <= 0) {
		adc = 8;
	} else {
		adc = 15;
		for (i = 34 + 34 / 2; i; i >>= 1) {
			if (i < interval)
				break;
			adc--;
		}
	}
	return (config & 0xf807) | (adc << 3) | (adc << 7);
}

__attribute__((used)) static ssize_t ina209_set_interval(struct device *dev,
				   struct device_attribute *da,
				   const char *buf, size_t count)
{
	struct ina209_data *data = ina209_update_device(dev);
	long val;
	u16 regval;
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	mutex_lock(&data->update_lock);
	regval = ina209_reg_from_interval(data->regs[INA209_CONFIGURATION],
					  val);
	i2c_smbus_write_word_swapped(data->client, INA209_CONFIGURATION,
				     regval);
	data->regs[INA209_CONFIGURATION] = regval;
	data->update_interval = ina209_interval_from_reg(regval);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t ina209_show_interval(struct device *dev,
				    struct device_attribute *da, char *buf)
{
	struct ina209_data *data = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", data->update_interval);
}

__attribute__((used)) static ssize_t ina209_reset_history(struct device *dev,
				    struct device_attribute *da,
				    const char *buf,
				    size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ina209_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u32 mask = attr->index;
	long val;
	int i, ret;

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	mutex_lock(&data->update_lock);
	for (i = 0; i < ARRAY_SIZE(ina209_reset_history_regs); i++) {
		if (mask & (1 << i))
			i2c_smbus_write_word_swapped(client,
					ina209_reset_history_regs[i], 1);
	}
	data->valid = false;
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t ina209_set_value(struct device *dev,
				struct device_attribute *da,
				const char *buf,
				size_t count)
{
	struct ina209_data *data = ina209_update_device(dev);
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	int reg = attr->index;
	long val;
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	mutex_lock(&data->update_lock);
	ret = ina209_to_reg(reg, data->regs[reg], val);
	if (ret < 0) {
		count = ret;
		goto abort;
	}
	i2c_smbus_write_word_swapped(data->client, reg, ret);
	data->regs[reg] = ret;
abort:
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t ina209_show_value(struct device *dev,
				 struct device_attribute *da,
				 char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ina209_data *data = ina209_update_device(dev);
	long val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = ina209_from_reg(attr->index, data->regs[attr->index]);
	return snprintf(buf, PAGE_SIZE, "%ld\n", val);
}

__attribute__((used)) static ssize_t ina209_show_alarm(struct device *dev,
				 struct device_attribute *da,
				 char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct ina209_data *data = ina209_update_device(dev);
	const unsigned int mask = attr->index;
	u16 status;

	if (IS_ERR(data))
		return PTR_ERR(data);

	status = data->regs[INA209_STATUS];

	/*
	 * All alarms are in the INA209_STATUS register. To avoid a long
	 * switch statement, the mask is passed in attr->index
	 */
	return snprintf(buf, PAGE_SIZE, "%u\n", !!(status & mask));
}

__attribute__((used)) static void ina209_restore_conf(struct i2c_client *client,
				struct ina209_data *data)
{
	/* Restore initial configuration */
	i2c_smbus_write_word_swapped(client, INA209_CONFIGURATION,
				     data->config_orig);
	i2c_smbus_write_word_swapped(client, INA209_CALIBRATION,
				     data->calibration_orig);
}

__attribute__((used)) static int ina209_init_client(struct i2c_client *client,
			      struct ina209_data *data)
{
	struct ina2xx_platform_data *pdata = dev_get_platdata(&client->dev);
	u32 shunt;
	int reg;

	reg = i2c_smbus_read_word_swapped(client, INA209_CALIBRATION);
	if (reg < 0)
		return reg;
	data->calibration_orig = reg;

	reg = i2c_smbus_read_word_swapped(client, INA209_CONFIGURATION);
	if (reg < 0)
		return reg;
	data->config_orig = reg;

	if (pdata) {
		if (pdata->shunt_uohms <= 0)
			return -EINVAL;
		shunt = pdata->shunt_uohms;
	} else if (!of_property_read_u32(client->dev.of_node, "shunt-resistor",
					 &shunt)) {
		if (shunt == 0)
			return -EINVAL;
	} else {
		shunt = data->calibration_orig ?
		  40960000 / data->calibration_orig : INA209_SHUNT_DEFAULT;
	}

	i2c_smbus_write_word_swapped(client, INA209_CONFIGURATION,
				     INA209_CONFIG_DEFAULT);
	data->update_interval = ina209_interval_from_reg(INA209_CONFIG_DEFAULT);

	/*
	 * Calibrate current LSB to 1mA. Shunt is in uOhms.
	 * See equation 13 in datasheet.
	 */
	i2c_smbus_write_word_swapped(client, INA209_CALIBRATION,
				     clamp_val(40960000 / shunt, 1, 65535));

	/* Clear status register */
	i2c_smbus_read_word_swapped(client, INA209_STATUS);

	return 0;
}

__attribute__((used)) static int ina209_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct ina209_data *data;
	struct device *hwmon_dev;
	int ret;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	data->client = client;
	mutex_init(&data->update_lock);

	ret = ina209_init_client(client, data);
	if (ret)
		return ret;

	hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
							   client->name,
							   data, ina209_groups);
	if (IS_ERR(hwmon_dev)) {
		ret = PTR_ERR(hwmon_dev);
		goto out_restore_conf;
	}

	return 0;

out_restore_conf:
	ina209_restore_conf(client, data);
	return ret;
}

__attribute__((used)) static int ina209_remove(struct i2c_client *client)
{
	struct ina209_data *data = i2c_get_clientdata(client);

	ina209_restore_conf(client, data);

	return 0;
}

