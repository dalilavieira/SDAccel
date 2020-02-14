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
union power_supply_propval {int intval; } ;
struct twl4030_madc_battery {struct iio_channel* channel_temp; struct iio_channel* channel_ichg; struct iio_channel* channel_vbat; struct iio_channel* psy; struct twl4030_madc_bat_platform_data* pdata; } ;
struct twl4030_madc_bat_platform_data {int capacity; int /*<<< orphan*/  discharging_size; struct twl4030_madc_bat_calibration* discharging; int /*<<< orphan*/  charging_size; struct twl4030_madc_bat_calibration* charging; } ;
struct twl4030_madc_bat_calibration {int voltage; int level; } ;
struct power_supply_config {struct twl4030_madc_battery* drv_data; } ;
struct power_supply {int dummy; } ;
struct TYPE_4__ {struct twl4030_madc_bat_platform_data* platform_data; } ;
struct platform_device {TYPE_1__ dev; } ;
struct iio_channel {int dummy; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct iio_channel*) ; 
#define  POWER_SUPPLY_PROP_CAPACITY 137 
#define  POWER_SUPPLY_PROP_CHARGE_FULL 136 
#define  POWER_SUPPLY_PROP_CHARGE_NOW 135 
#define  POWER_SUPPLY_PROP_CURRENT_NOW 134 
#define  POWER_SUPPLY_PROP_PRESENT 133 
#define  POWER_SUPPLY_PROP_STATUS 132 
#define  POWER_SUPPLY_PROP_TECHNOLOGY 131 
#define  POWER_SUPPLY_PROP_TEMP 130 
#define  POWER_SUPPLY_PROP_TIME_TO_EMPTY_NOW 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_FULL ; 
 int POWER_SUPPLY_TECHNOLOGY_LION ; 
 int PTR_ERR (struct iio_channel*) ; 
 struct twl4030_madc_battery* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 void* iio_channel_get (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  iio_channel_release (struct iio_channel*) ; 
 int iio_read_channel_processed (struct iio_channel*,int*) ; 
 struct twl4030_madc_battery* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct twl4030_madc_battery*) ; 
 int /*<<< orphan*/  power_supply_changed (struct power_supply*) ; 
 struct twl4030_madc_battery* power_supply_get_drvdata (struct power_supply*) ; 
 struct iio_channel* power_supply_register (TYPE_1__*,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 int /*<<< orphan*/  power_supply_unregister (struct iio_channel*) ; 
 int /*<<< orphan*/  sort (struct twl4030_madc_bat_calibration*,int /*<<< orphan*/ ,int,int (*) (void const*,void const*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  twl4030_madc_bat_desc ; 

__attribute__((used)) static int madc_read(struct iio_channel *channel)
{
	int val, err;
	err = iio_read_channel_processed(channel, &val);
	if (err < 0)
		return err;

	return val;
}

__attribute__((used)) static int twl4030_madc_bat_get_charging_status(struct twl4030_madc_battery *bt)
{
	return (madc_read(bt->channel_ichg) > 0) ? 1 : 0;
}

__attribute__((used)) static int twl4030_madc_bat_get_voltage(struct twl4030_madc_battery *bt)
{
	return madc_read(bt->channel_vbat);
}

__attribute__((used)) static int twl4030_madc_bat_get_current(struct twl4030_madc_battery *bt)
{
	return madc_read(bt->channel_ichg) * 1000;
}

__attribute__((used)) static int twl4030_madc_bat_get_temp(struct twl4030_madc_battery *bt)
{
	return madc_read(bt->channel_temp) * 10;
}

__attribute__((used)) static int twl4030_madc_bat_voltscale(struct twl4030_madc_battery *bat,
					int volt)
{
	struct twl4030_madc_bat_calibration *calibration;
	int i, res = 0;

	/* choose charging curve */
	if (twl4030_madc_bat_get_charging_status(bat))
		calibration = bat->pdata->charging;
	else
		calibration = bat->pdata->discharging;

	if (volt > calibration[0].voltage) {
		res = calibration[0].level;
	} else {
		for (i = 0; calibration[i+1].voltage >= 0; i++) {
			if (volt <= calibration[i].voltage &&
					volt >= calibration[i+1].voltage) {
				/* interval found - interpolate within range */
				res = calibration[i].level -
					((calibration[i].voltage - volt) *
					(calibration[i].level -
					calibration[i+1].level)) /
					(calibration[i].voltage -
					calibration[i+1].voltage);
				break;
			}
		}
	}
	return res;
}

__attribute__((used)) static int twl4030_madc_bat_get_property(struct power_supply *psy,
					enum power_supply_property psp,
					union power_supply_propval *val)
{
	struct twl4030_madc_battery *bat = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		if (twl4030_madc_bat_voltscale(bat,
				twl4030_madc_bat_get_voltage(bat)) > 95)
			val->intval = POWER_SUPPLY_STATUS_FULL;
		else {
			if (twl4030_madc_bat_get_charging_status(bat))
				val->intval = POWER_SUPPLY_STATUS_CHARGING;
			else
				val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
		}
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = twl4030_madc_bat_get_voltage(bat) * 1000;
		break;
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		val->intval = twl4030_madc_bat_get_current(bat);
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		/* assume battery is always present */
		val->intval = 1;
		break;
	case POWER_SUPPLY_PROP_CHARGE_NOW: {
			int percent = twl4030_madc_bat_voltscale(bat,
					twl4030_madc_bat_get_voltage(bat));
			val->intval = (percent * bat->pdata->capacity) / 100;
			break;
		}
	case POWER_SUPPLY_PROP_CAPACITY:
		val->intval = twl4030_madc_bat_voltscale(bat,
					twl4030_madc_bat_get_voltage(bat));
		break;
	case POWER_SUPPLY_PROP_CHARGE_FULL:
		val->intval = bat->pdata->capacity;
		break;
	case POWER_SUPPLY_PROP_TEMP:
		val->intval = twl4030_madc_bat_get_temp(bat);
		break;
	case POWER_SUPPLY_PROP_TIME_TO_EMPTY_NOW: {
			int percent = twl4030_madc_bat_voltscale(bat,
					twl4030_madc_bat_get_voltage(bat));
			/* in mAh */
			int chg = (percent * (bat->pdata->capacity/1000))/100;

			/* assume discharge with 400 mA (ca. 1.5W) */
			val->intval = (3600l * chg) / 400;
			break;
		}
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static void twl4030_madc_bat_ext_changed(struct power_supply *psy)
{
	power_supply_changed(psy);
}

__attribute__((used)) static int twl4030_cmp(const void *a, const void *b)
{
	return ((struct twl4030_madc_bat_calibration *)b)->voltage -
		((struct twl4030_madc_bat_calibration *)a)->voltage;
}

__attribute__((used)) static int twl4030_madc_battery_probe(struct platform_device *pdev)
{
	struct twl4030_madc_battery *twl4030_madc_bat;
	struct twl4030_madc_bat_platform_data *pdata = pdev->dev.platform_data;
	struct power_supply_config psy_cfg = {};
	int ret = 0;

	twl4030_madc_bat = devm_kzalloc(&pdev->dev, sizeof(*twl4030_madc_bat),
				GFP_KERNEL);
	if (!twl4030_madc_bat)
		return -ENOMEM;

	twl4030_madc_bat->channel_temp = iio_channel_get(&pdev->dev, "temp");
	if (IS_ERR(twl4030_madc_bat->channel_temp)) {
		ret = PTR_ERR(twl4030_madc_bat->channel_temp);
		goto err;
	}

	twl4030_madc_bat->channel_ichg = iio_channel_get(&pdev->dev, "ichg");
	if (IS_ERR(twl4030_madc_bat->channel_ichg)) {
		ret = PTR_ERR(twl4030_madc_bat->channel_ichg);
		goto err_temp;
	}

	twl4030_madc_bat->channel_vbat = iio_channel_get(&pdev->dev, "vbat");
	if (IS_ERR(twl4030_madc_bat->channel_vbat)) {
		ret = PTR_ERR(twl4030_madc_bat->channel_vbat);
		goto err_ichg;
	}

	/* sort charging and discharging calibration data */
	sort(pdata->charging, pdata->charging_size,
		sizeof(struct twl4030_madc_bat_calibration),
		twl4030_cmp, NULL);
	sort(pdata->discharging, pdata->discharging_size,
		sizeof(struct twl4030_madc_bat_calibration),
		twl4030_cmp, NULL);

	twl4030_madc_bat->pdata = pdata;
	platform_set_drvdata(pdev, twl4030_madc_bat);
	psy_cfg.drv_data = twl4030_madc_bat;
	twl4030_madc_bat->psy = power_supply_register(&pdev->dev,
						      &twl4030_madc_bat_desc,
						      &psy_cfg);
	if (IS_ERR(twl4030_madc_bat->psy)) {
		ret = PTR_ERR(twl4030_madc_bat->psy);
		goto err_vbat;
	}

	return 0;

err_vbat:
	iio_channel_release(twl4030_madc_bat->channel_vbat);
err_ichg:
	iio_channel_release(twl4030_madc_bat->channel_ichg);
err_temp:
	iio_channel_release(twl4030_madc_bat->channel_temp);
err:
	return ret;
}

__attribute__((used)) static int twl4030_madc_battery_remove(struct platform_device *pdev)
{
	struct twl4030_madc_battery *bat = platform_get_drvdata(pdev);

	power_supply_unregister(bat->psy);

	iio_channel_release(bat->channel_vbat);
	iio_channel_release(bat->channel_ichg);
	iio_channel_release(bat->channel_temp);

	return 0;
}

