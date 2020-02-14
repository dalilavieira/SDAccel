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
struct sensor_device_attribute_2 {unsigned int index; int /*<<< orphan*/  nr; } ;
struct sensor_device_attribute {int index; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 unsigned int DIV_ROUND_CLOSEST (unsigned int,int) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
#define  LTC4222_ADIN1 133 
#define  LTC4222_ADIN2 132 
 int /*<<< orphan*/  LTC4222_FAULT1 ; 
 int /*<<< orphan*/  LTC4222_FAULT2 ; 
#define  LTC4222_SENSE1 131 
#define  LTC4222_SENSE2 130 
#define  LTC4222_SOURCE1 129 
#define  LTC4222_SOURCE2 128 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct regmap*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct regmap* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct regmap*,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ltc4222_groups ; 
 int /*<<< orphan*/  ltc4222_regmap_config ; 
 int regmap_bulk_read (struct regmap*,int,int*,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static int ltc4222_get_value(struct device *dev, u8 reg)
{
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int val;
	u8 buf[2];
	int ret;

	ret = regmap_bulk_read(regmap, reg, buf, 2);
	if (ret < 0)
		return ret;

	val = ((buf[0] << 8) + buf[1]) >> 6;

	switch (reg) {
	case LTC4222_ADIN1:
	case LTC4222_ADIN2:
		/* 1.25 mV resolution. Convert to mV. */
		val = DIV_ROUND_CLOSEST(val * 5, 4);
		break;
	case LTC4222_SOURCE1:
	case LTC4222_SOURCE2:
		/* 31.25 mV resolution. Convert to mV. */
		val = DIV_ROUND_CLOSEST(val * 125, 4);
		break;
	case LTC4222_SENSE1:
	case LTC4222_SENSE2:
		/*
		 * 62.5 uV resolution. Convert to current as measured with
		 * an 1 mOhm sense resistor, in mA. If a different sense
		 * resistor is installed, calculate the actual current by
		 * dividing the reported current by the sense resistor value
		 * in mOhm.
		 */
		val = DIV_ROUND_CLOSEST(val * 125, 2);
		break;
	default:
		return -EINVAL;
	}
	return val;
}

__attribute__((used)) static ssize_t ltc4222_show_value(struct device *dev,
				  struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	int value;

	value = ltc4222_get_value(dev, attr->index);
	if (value < 0)
		return value;
	return snprintf(buf, PAGE_SIZE, "%d\n", value);
}

__attribute__((used)) static ssize_t ltc4222_show_bool(struct device *dev,
				 struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int fault;
	int ret;

	ret = regmap_read(regmap, attr->nr, &fault);
	if (ret < 0)
		return ret;
	fault &= attr->index;
	if (fault)		/* Clear reported faults in chip register */
		regmap_update_bits(regmap, attr->nr, attr->index, 0);

	return snprintf(buf, PAGE_SIZE, "%d\n", !!fault);
}

__attribute__((used)) static int ltc4222_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct regmap *regmap;

	regmap = devm_regmap_init_i2c(client, &ltc4222_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(dev, "failed to allocate register map\n");
		return PTR_ERR(regmap);
	}

	/* Clear faults */
	regmap_write(regmap, LTC4222_FAULT1, 0x00);
	regmap_write(regmap, LTC4222_FAULT2, 0x00);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   regmap,
							   ltc4222_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

