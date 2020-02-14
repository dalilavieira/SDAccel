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
typedef  int umode_t ;
typedef  int u8 ;
typedef  int u32 ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
typedef  int s8 ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  W83773_CONVERSION_RATE_REG_READ ; 
 int /*<<< orphan*/  W83773_CONVERSION_RATE_REG_WRITE ; 
 int /*<<< orphan*/  W83773_LOCAL_TEMP ; 
 int /*<<< orphan*/ * W83773_OFFSET_LSB ; 
 int /*<<< orphan*/ * W83773_OFFSET_MSB ; 
 int /*<<< orphan*/ * W83773_STATUS ; 
 int /*<<< orphan*/ * W83773_TEMP_LSB ; 
 int /*<<< orphan*/ * W83773_TEMP_MSB ; 
 int __fls (long) ; 
 int clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct regmap* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct regmap*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
#define  hwmon_chip 133 
#define  hwmon_chip_update_interval 132 
#define  hwmon_temp 131 
#define  hwmon_temp_fault 130 
#define  hwmon_temp_input 129 
#define  hwmon_temp_offset 128 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct regmap*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  w83773_chip_info ; 
 int /*<<< orphan*/  w83773_regmap_config ; 

__attribute__((used)) static inline long temp_of_local(s8 reg)
{
	return reg * 1000;
}

__attribute__((used)) static inline long temp_of_remote(s8 hb, u8 lb)
{
	return (hb << 3 | lb >> 5) * 125;
}

__attribute__((used)) static int get_local_temp(struct regmap *regmap, long *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(regmap, W83773_LOCAL_TEMP, &regval);
	if (ret < 0)
		return ret;

	*val = temp_of_local(regval);
	return 0;
}

__attribute__((used)) static int get_remote_temp(struct regmap *regmap, int index, long *val)
{
	unsigned int regval_high;
	unsigned int regval_low;
	int ret;

	ret = regmap_read(regmap, W83773_TEMP_MSB[index], &regval_high);
	if (ret < 0)
		return ret;

	ret = regmap_read(regmap, W83773_TEMP_LSB[index], &regval_low);
	if (ret < 0)
		return ret;

	*val = temp_of_remote(regval_high, regval_low);
	return 0;
}

__attribute__((used)) static int get_fault(struct regmap *regmap, int index, long *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(regmap, W83773_STATUS[index], &regval);
	if (ret < 0)
		return ret;

	*val = (regval & 0x04) >> 2;
	return 0;
}

__attribute__((used)) static int get_offset(struct regmap *regmap, int index, long *val)
{
	unsigned int regval_high;
	unsigned int regval_low;
	int ret;

	ret = regmap_read(regmap, W83773_OFFSET_MSB[index], &regval_high);
	if (ret < 0)
		return ret;

	ret = regmap_read(regmap, W83773_OFFSET_LSB[index], &regval_low);
	if (ret < 0)
		return ret;

	*val = temp_of_remote(regval_high, regval_low);
	return 0;
}

__attribute__((used)) static int set_offset(struct regmap *regmap, int index, long val)
{
	int ret;
	u8 high_byte;
	u8 low_byte;

	val = clamp_val(val, -127825, 127825);
	/* offset value equals to (high_byte << 3 | low_byte >> 5) * 125 */
	val /= 125;
	high_byte = val >> 3;
	low_byte = (val & 0x07) << 5;

	ret = regmap_write(regmap, W83773_OFFSET_MSB[index], high_byte);
	if (ret < 0)
		return ret;

	return regmap_write(regmap, W83773_OFFSET_LSB[index], low_byte);
}

__attribute__((used)) static int get_update_interval(struct regmap *regmap, long *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(regmap, W83773_CONVERSION_RATE_REG_READ, &regval);
	if (ret < 0)
		return ret;

	*val = 16000 >> regval;
	return 0;
}

__attribute__((used)) static int set_update_interval(struct regmap *regmap, long val)
{
	int rate;

	/*
	 * For valid rates, interval can be calculated as
	 *	interval = (1 << (8 - rate)) * 62.5;
	 * Rounded rate is therefore
	 *	rate = 8 - __fls(interval * 8 / (62.5 * 7));
	 * Use clamp_val() to avoid overflows, and to ensure valid input
	 * for __fls.
	 */
	val = clamp_val(val, 62, 16000) * 10;
	rate = 8 - __fls((val * 8 / (625 * 7)));
	return regmap_write(regmap, W83773_CONVERSION_RATE_REG_WRITE, rate);
}

__attribute__((used)) static int w83773_read(struct device *dev, enum hwmon_sensor_types type,
		       u32 attr, int channel, long *val)
{
	struct regmap *regmap = dev_get_drvdata(dev);

	if (type == hwmon_chip) {
		if (attr == hwmon_chip_update_interval)
			return get_update_interval(regmap, val);
		return -EOPNOTSUPP;
	}

	switch (attr) {
	case hwmon_temp_input:
		if (channel == 0)
			return get_local_temp(regmap, val);
		return get_remote_temp(regmap, channel - 1, val);
	case hwmon_temp_fault:
		return get_fault(regmap, channel - 1, val);
	case hwmon_temp_offset:
		return get_offset(regmap, channel - 1, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int w83773_write(struct device *dev, enum hwmon_sensor_types type,
			u32 attr, int channel, long val)
{
	struct regmap *regmap = dev_get_drvdata(dev);

	if (type == hwmon_chip && attr == hwmon_chip_update_interval)
		return set_update_interval(regmap, val);

	if (type == hwmon_temp && attr == hwmon_temp_offset)
		return set_offset(regmap, channel - 1, val);

	return -EOPNOTSUPP;
}

__attribute__((used)) static umode_t w83773_is_visible(const void *data, enum hwmon_sensor_types type,
				 u32 attr, int channel)
{
	switch (type) {
	case hwmon_chip:
		switch (attr) {
		case hwmon_chip_update_interval:
			return 0644;
		}
		break;
	case hwmon_temp:
		switch (attr) {
		case hwmon_temp_input:
		case hwmon_temp_fault:
			return 0444;
		case hwmon_temp_offset:
			return 0644;
		}
		break;
	default:
		break;
	}
	return 0;
}

__attribute__((used)) static int w83773_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct regmap *regmap;
	int ret;

	regmap = devm_regmap_init_i2c(client, &w83773_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(dev, "failed to allocate register map\n");
		return PTR_ERR(regmap);
	}

	/* Set the conversion rate to 2 Hz */
	ret = regmap_write(regmap, W83773_CONVERSION_RATE_REG_WRITE, 0x05);
	if (ret < 0) {
		dev_err(&client->dev, "error writing config rate register\n");
		return ret;
	}

	i2c_set_clientdata(client, regmap);

	hwmon_dev = devm_hwmon_device_register_with_info(dev,
							 client->name,
							 regmap,
							 &w83773_chip_info,
							 NULL);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

