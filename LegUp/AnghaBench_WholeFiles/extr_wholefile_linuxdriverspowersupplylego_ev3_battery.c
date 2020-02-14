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
union power_supply_propval {int intval; } ;
struct power_supply_config {struct lego_ev3_battery* drv_data; int /*<<< orphan*/  of_node; } ;
struct power_supply {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct lego_ev3_battery {int technology; int v_max; int v_min; void* psy; void* rechargeable_gpio; void* iio_i; void* iio_v; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
#define  POWER_SUPPLY_PROP_CURRENT_NOW 134 
#define  POWER_SUPPLY_PROP_SCOPE 133 
#define  POWER_SUPPLY_PROP_TECHNOLOGY 132 
#define  POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN 131 
#define  POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 129 
 int POWER_SUPPLY_SCOPE_SYSTEM ; 
 scalar_t__ POWER_SUPPLY_TECHNOLOGY_LION ; 
#define  POWER_SUPPLY_TECHNOLOGY_NiMH 128 
 scalar_t__ POWER_SUPPLY_TECHNOLOGY_UNKNOWN ; 
 int PTR_ERR_OR_ZERO (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_iio_channel_get (struct device*,char*) ; 
 struct lego_ev3_battery* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* devm_power_supply_register (struct device*,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 scalar_t__ gpiod_get_value (void*) ; 
 int iio_read_channel_processed (void*,int*) ; 
 int /*<<< orphan*/  lego_ev3_battery_desc ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lego_ev3_battery*) ; 
 struct lego_ev3_battery* power_supply_get_drvdata (struct power_supply*) ; 

__attribute__((used)) static int lego_ev3_battery_get_property(struct power_supply *psy,
					 enum power_supply_property psp,
					 union power_supply_propval *val)
{
	struct lego_ev3_battery *batt = power_supply_get_drvdata(psy);
	int ret, val2;

	switch (psp) {
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = batt->technology;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		/* battery voltage is iio channel * 2 + Vce of transistor */
		ret = iio_read_channel_processed(batt->iio_v, &val->intval);
		if (ret)
			return ret;

		val->intval *= 2000;
		val->intval += 50000;

		/* plus adjust for shunt resistor drop */
		ret = iio_read_channel_processed(batt->iio_i, &val2);
		if (ret)
			return ret;

		val2 *= 1000;
		val2 /= 15;
		val->intval += val2;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
		val->intval = batt->v_max;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
		val->intval = batt->v_min;
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		/* battery current is iio channel / 15 / 0.05 ohms */
		ret = iio_read_channel_processed(batt->iio_i, &val->intval);
		if (ret)
			return ret;

		val->intval *= 20000;
		val->intval /= 15;
		break;
	case POWER_SUPPLY_PROP_SCOPE:
		val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int lego_ev3_battery_set_property(struct power_supply *psy,
					 enum power_supply_property psp,
					 const union power_supply_propval *val)
{
	struct lego_ev3_battery *batt = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		/*
		 * Only allow changing technology from Unknown to NiMH. Li-ion
		 * batteries are automatically detected and should not be
		 * overridden. Rechargeable AA batteries, on the other hand,
		 * cannot be automatically detected, and so must be manually
		 * specified. This should only be set once during system init,
		 * so there is no mechanism to go back to Unknown.
		 */
		if (batt->technology != POWER_SUPPLY_TECHNOLOGY_UNKNOWN)
			return -EINVAL;
		switch (val->intval) {
		case POWER_SUPPLY_TECHNOLOGY_NiMH:
			batt->technology = POWER_SUPPLY_TECHNOLOGY_NiMH;
			batt->v_max = 7800000;
			batt->v_min = 5400000;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int lego_ev3_battery_property_is_writeable(struct power_supply *psy,
						  enum power_supply_property psp)
{
	struct lego_ev3_battery *batt = power_supply_get_drvdata(psy);

	return psp == POWER_SUPPLY_PROP_TECHNOLOGY &&
		batt->technology == POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
}

__attribute__((used)) static int lego_ev3_battery_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct lego_ev3_battery *batt;
	struct power_supply_config psy_cfg = {};
	int err;

	batt = devm_kzalloc(dev, sizeof(*batt), GFP_KERNEL);
	if (!batt)
		return -ENOMEM;

	platform_set_drvdata(pdev, batt);

	batt->iio_v = devm_iio_channel_get(dev, "voltage");
	err = PTR_ERR_OR_ZERO(batt->iio_v);
	if (err) {
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get voltage iio channel\n");
		return err;
	}

	batt->iio_i = devm_iio_channel_get(dev, "current");
	err = PTR_ERR_OR_ZERO(batt->iio_i);
	if (err) {
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get current iio channel\n");
		return err;
	}

	batt->rechargeable_gpio = devm_gpiod_get(dev, "rechargeable", GPIOD_IN);
	err = PTR_ERR_OR_ZERO(batt->rechargeable_gpio);
	if (err) {
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get rechargeable gpio\n");
		return err;
	}

	/*
	 * The rechargeable battery indication switch cannot be changed without
	 * removing the battery, so we only need to read it once.
	 */
	if (gpiod_get_value(batt->rechargeable_gpio)) {
		/* 2-cell Li-ion, 7.4V nominal */
		batt->technology = POWER_SUPPLY_TECHNOLOGY_LION;
		batt->v_max = 84000000;
		batt->v_min = 60000000;
	} else {
		/* 6x AA Alkaline, 9V nominal */
		batt->technology = POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
		batt->v_max = 90000000;
		batt->v_min = 48000000;
	}

	psy_cfg.of_node = pdev->dev.of_node;
	psy_cfg.drv_data = batt;

	batt->psy = devm_power_supply_register(dev, &lego_ev3_battery_desc,
					       &psy_cfg);
	err = PTR_ERR_OR_ZERO(batt->psy);
	if (err) {
		dev_err(dev, "failed to register power supply\n");
		return err;
	}

	return 0;
}

