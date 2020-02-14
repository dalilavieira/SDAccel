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
typedef  scalar_t__ u8 ;
struct sensor_device_attribute {scalar_t__ index; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  long long ssize_t ;

/* Variables and functions */
 unsigned int CONTROL_MULT_SELECT ; 
 unsigned int CONTROL_TEST_MODE ; 
 int DIV_ROUND_CLOSEST (unsigned long,int) ; 
 long long EINVAL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
#define  LTC2945_ADIN_H 147 
 int /*<<< orphan*/  LTC2945_CONTROL ; 
 int /*<<< orphan*/  LTC2945_FAULT ; 
#define  LTC2945_MAX_ADIN_H 146 
#define  LTC2945_MAX_ADIN_THRES_H 145 
#define  LTC2945_MAX_POWER_H 144 
#define  LTC2945_MAX_POWER_THRES_H 143 
#define  LTC2945_MAX_SENSE_H 142 
#define  LTC2945_MAX_SENSE_THRES_H 141 
#define  LTC2945_MAX_VIN_H 140 
#define  LTC2945_MAX_VIN_THRES_H 139 
#define  LTC2945_MIN_ADIN_H 138 
#define  LTC2945_MIN_ADIN_THRES_H 137 
#define  LTC2945_MIN_POWER_H 136 
#define  LTC2945_MIN_POWER_THRES_H 135 
#define  LTC2945_MIN_SENSE_H 134 
#define  LTC2945_MIN_SENSE_THRES_H 133 
#define  LTC2945_MIN_VIN_H 132 
#define  LTC2945_MIN_VIN_THRES_H 131 
#define  LTC2945_POWER_H 130 
#define  LTC2945_SENSE_H 129 
#define  LTC2945_VIN_H 128 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct regmap*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*,scalar_t__) ; 
 int clamp_val (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct regmap* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct regmap*,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  ltc2945_groups ; 
 int /*<<< orphan*/  ltc2945_regmap_config ; 
 int regmap_bulk_read (struct regmap*,scalar_t__,scalar_t__*,int) ; 
 int regmap_bulk_write (struct regmap*,scalar_t__,scalar_t__*,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 long long snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline bool is_power_reg(u8 reg)
{
	return reg < LTC2945_SENSE_H;
}

__attribute__((used)) static long long ltc2945_reg_to_val(struct device *dev, u8 reg)
{
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int control;
	u8 buf[3];
	long long val;
	int ret;

	ret = regmap_bulk_read(regmap, reg, buf,
			       is_power_reg(reg) ? 3 : 2);
	if (ret < 0)
		return ret;

	if (is_power_reg(reg)) {
		/* power */
		val = (buf[0] << 16) + (buf[1] << 8) + buf[2];
	} else {
		/* current, voltage */
		val = (buf[0] << 4) + (buf[1] >> 4);
	}

	switch (reg) {
	case LTC2945_POWER_H:
	case LTC2945_MAX_POWER_H:
	case LTC2945_MIN_POWER_H:
	case LTC2945_MAX_POWER_THRES_H:
	case LTC2945_MIN_POWER_THRES_H:
		/*
		 * Convert to uW by assuming current is measured with
		 * an 1mOhm sense resistor, similar to current
		 * measurements.
		 * Control register bit 0 selects if voltage at SENSE+/VDD
		 * or voltage at ADIN is used to measure power.
		 */
		ret = regmap_read(regmap, LTC2945_CONTROL, &control);
		if (ret < 0)
			return ret;
		if (control & CONTROL_MULT_SELECT) {
			/* 25 mV * 25 uV = 0.625 uV resolution. */
			val *= 625LL;
		} else {
			/* 0.5 mV * 25 uV = 0.0125 uV resolution. */
			val = (val * 25LL) >> 1;
		}
		break;
	case LTC2945_VIN_H:
	case LTC2945_MAX_VIN_H:
	case LTC2945_MIN_VIN_H:
	case LTC2945_MAX_VIN_THRES_H:
	case LTC2945_MIN_VIN_THRES_H:
		/* 25 mV resolution. Convert to mV. */
		val *= 25;
		break;
	case LTC2945_ADIN_H:
	case LTC2945_MAX_ADIN_H:
	case LTC2945_MIN_ADIN_THRES_H:
	case LTC2945_MAX_ADIN_THRES_H:
	case LTC2945_MIN_ADIN_H:
		/* 0.5mV resolution. Convert to mV. */
		val = val >> 1;
		break;
	case LTC2945_SENSE_H:
	case LTC2945_MAX_SENSE_H:
	case LTC2945_MIN_SENSE_H:
	case LTC2945_MAX_SENSE_THRES_H:
	case LTC2945_MIN_SENSE_THRES_H:
		/*
		 * 25 uV resolution. Convert to current as measured with
		 * an 1 mOhm sense resistor, in mA. If a different sense
		 * resistor is installed, calculate the actual current by
		 * dividing the reported current by the sense resistor value
		 * in mOhm.
		 */
		val *= 25;
		break;
	default:
		return -EINVAL;
	}
	return val;
}

__attribute__((used)) static int ltc2945_val_to_reg(struct device *dev, u8 reg,
			      unsigned long val)
{
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int control;
	int ret;

	switch (reg) {
	case LTC2945_POWER_H:
	case LTC2945_MAX_POWER_H:
	case LTC2945_MIN_POWER_H:
	case LTC2945_MAX_POWER_THRES_H:
	case LTC2945_MIN_POWER_THRES_H:
		/*
		 * Convert to register value by assuming current is measured
		 * with an 1mOhm sense resistor, similar to current
		 * measurements.
		 * Control register bit 0 selects if voltage at SENSE+/VDD
		 * or voltage at ADIN is used to measure power, which in turn
		 * determines register calculations.
		 */
		ret = regmap_read(regmap, LTC2945_CONTROL, &control);
		if (ret < 0)
			return ret;
		if (control & CONTROL_MULT_SELECT) {
			/* 25 mV * 25 uV = 0.625 uV resolution. */
			val = DIV_ROUND_CLOSEST(val, 625);
		} else {
			/*
			 * 0.5 mV * 25 uV = 0.0125 uV resolution.
			 * Divide first to avoid overflow;
			 * accept loss of accuracy.
			 */
			val = DIV_ROUND_CLOSEST(val, 25) * 2;
		}
		break;
	case LTC2945_VIN_H:
	case LTC2945_MAX_VIN_H:
	case LTC2945_MIN_VIN_H:
	case LTC2945_MAX_VIN_THRES_H:
	case LTC2945_MIN_VIN_THRES_H:
		/* 25 mV resolution. */
		val /= 25;
		break;
	case LTC2945_ADIN_H:
	case LTC2945_MAX_ADIN_H:
	case LTC2945_MIN_ADIN_THRES_H:
	case LTC2945_MAX_ADIN_THRES_H:
	case LTC2945_MIN_ADIN_H:
		/* 0.5mV resolution. */
		val *= 2;
		break;
	case LTC2945_SENSE_H:
	case LTC2945_MAX_SENSE_H:
	case LTC2945_MIN_SENSE_H:
	case LTC2945_MAX_SENSE_THRES_H:
	case LTC2945_MIN_SENSE_THRES_H:
		/*
		 * 25 uV resolution. Convert to current as measured with
		 * an 1 mOhm sense resistor, in mA. If a different sense
		 * resistor is installed, calculate the actual current by
		 * dividing the reported current by the sense resistor value
		 * in mOhm.
		 */
		val = DIV_ROUND_CLOSEST(val, 25);
		break;
	default:
		return -EINVAL;
	}
	return val;
}

__attribute__((used)) static ssize_t ltc2945_show_value(struct device *dev,
				  struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	long long value;

	value = ltc2945_reg_to_val(dev, attr->index);
	if (value < 0)
		return value;
	return snprintf(buf, PAGE_SIZE, "%lld\n", value);
}

__attribute__((used)) static ssize_t ltc2945_set_value(struct device *dev,
				     struct device_attribute *da,
				     const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct regmap *regmap = dev_get_drvdata(dev);
	u8 reg = attr->index;
	unsigned long val;
	u8 regbuf[3];
	int num_regs;
	int regval;
	int ret;

	ret = kstrtoul(buf, 10, &val);
	if (ret)
		return ret;

	/* convert to register value, then clamp and write result */
	regval = ltc2945_val_to_reg(dev, reg, val);
	if (is_power_reg(reg)) {
		regval = clamp_val(regval, 0, 0xffffff);
		regbuf[0] = regval >> 16;
		regbuf[1] = (regval >> 8) & 0xff;
		regbuf[2] = regval;
		num_regs = 3;
	} else {
		regval = clamp_val(regval, 0, 0xfff) << 4;
		regbuf[0] = regval >> 8;
		regbuf[1] = regval & 0xff;
		num_regs = 2;
	}
	ret = regmap_bulk_write(regmap, reg, regbuf, num_regs);
	return ret < 0 ? ret : count;
}

__attribute__((used)) static ssize_t ltc2945_reset_history(struct device *dev,
				     struct device_attribute *da,
				     const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct regmap *regmap = dev_get_drvdata(dev);
	u8 reg = attr->index;
	int num_regs = is_power_reg(reg) ? 3 : 2;
	u8 buf_min[3] = { 0xff, 0xff, 0xff };
	u8 buf_max[3] = { 0, 0, 0 };
	unsigned long val;
	int ret;

	ret = kstrtoul(buf, 10, &val);
	if (ret)
		return ret;
	if (val != 1)
		return -EINVAL;

	ret = regmap_update_bits(regmap, LTC2945_CONTROL, CONTROL_TEST_MODE,
				 CONTROL_TEST_MODE);

	/* Reset minimum */
	ret = regmap_bulk_write(regmap, reg, buf_min, num_regs);
	if (ret)
		return ret;

	switch (reg) {
	case LTC2945_MIN_POWER_H:
		reg = LTC2945_MAX_POWER_H;
		break;
	case LTC2945_MIN_SENSE_H:
		reg = LTC2945_MAX_SENSE_H;
		break;
	case LTC2945_MIN_VIN_H:
		reg = LTC2945_MAX_VIN_H;
		break;
	case LTC2945_MIN_ADIN_H:
		reg = LTC2945_MAX_ADIN_H;
		break;
	default:
		WARN_ONCE(1, "Bad register: 0x%x\n", reg);
		return -EINVAL;
	}
	/* Reset maximum */
	ret = regmap_bulk_write(regmap, reg, buf_max, num_regs);

	/* Try resetting test mode even if there was an error */
	regmap_update_bits(regmap, LTC2945_CONTROL, CONTROL_TEST_MODE, 0);

	return ret ? : count;
}

__attribute__((used)) static ssize_t ltc2945_show_bool(struct device *dev,
				 struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int fault;
	int ret;

	ret = regmap_read(regmap, LTC2945_FAULT, &fault);
	if (ret < 0)
		return ret;

	fault &= attr->index;
	if (fault)		/* Clear reported faults in chip register */
		regmap_update_bits(regmap, LTC2945_FAULT, attr->index, 0);

	return snprintf(buf, PAGE_SIZE, "%d\n", !!fault);
}

__attribute__((used)) static int ltc2945_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct regmap *regmap;

	regmap = devm_regmap_init_i2c(client, &ltc2945_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(dev, "failed to allocate register map\n");
		return PTR_ERR(regmap);
	}

	/* Clear faults */
	regmap_write(regmap, LTC2945_FAULT, 0x00);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   regmap,
							   ltc2945_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

