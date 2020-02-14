#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
struct TYPE_2__ {char* name; int* properties; int num_properties; int (* get_property ) (struct power_supply*,int,union power_supply_propval*) ;int /*<<< orphan*/  type; } ;
struct rx51_device_info {struct iio_channel* channel_temp; struct iio_channel* channel_bsi; struct iio_channel* channel_vbat; struct iio_channel* bat; TYPE_1__ bat_desc; int /*<<< orphan*/ * dev; } ;
struct power_supply_config {struct rx51_device_info* drv_data; } ;
struct power_supply {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct iio_channel {int dummy; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INT_MAX ; 
 int INT_MIN ; 
 scalar_t__ IS_ERR (struct iio_channel*) ; 
#define  POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN 133 
#define  POWER_SUPPLY_PROP_PRESENT 132 
#define  POWER_SUPPLY_PROP_TECHNOLOGY 131 
#define  POWER_SUPPLY_PROP_TEMP 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int POWER_SUPPLY_TECHNOLOGY_LION ; 
 int /*<<< orphan*/  POWER_SUPPLY_TYPE_BATTERY ; 
 int PTR_ERR (struct iio_channel*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct rx51_device_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* iio_channel_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  iio_channel_release (struct iio_channel*) ; 
 int iio_read_channel_average_raw (struct iio_channel*,int*) ; 
 struct rx51_device_info* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rx51_device_info*) ; 
 struct rx51_device_info* power_supply_get_drvdata (struct power_supply*) ; 
 struct iio_channel* power_supply_register (int /*<<< orphan*/ *,TYPE_1__*,struct power_supply_config*) ; 
 int /*<<< orphan*/  power_supply_unregister (struct iio_channel*) ; 
 int* rx51_battery_props ; 
 int* rx51_temp_table1 ; 
 int* rx51_temp_table2 ; 
 int rx51_temp_table2_first ; 

__attribute__((used)) static int rx51_battery_read_adc(struct iio_channel *channel)
{
	int val, err;
	err = iio_read_channel_average_raw(channel, &val);
	if (err < 0)
		return err;
	return val;
}

__attribute__((used)) static int rx51_battery_read_voltage(struct rx51_device_info *di)
{
	int voltage = rx51_battery_read_adc(di->channel_vbat);

	if (voltage < 0) {
		dev_err(di->dev, "Could not read ADC: %d\n", voltage);
		return voltage;
	}

	return 1000 * (10000 * voltage / 1705);
}

__attribute__((used)) static int rx51_battery_read_temperature(struct rx51_device_info *di)
{
	int min = 0;
	int max = ARRAY_SIZE(rx51_temp_table2) - 1;
	int raw = rx51_battery_read_adc(di->channel_temp);

	if (raw < 0)
		dev_err(di->dev, "Could not read ADC: %d\n", raw);

	/* Zero and negative values are undefined */
	if (raw <= 0)
		return INT_MAX;

	/* ADC channels are 10 bit, higher value are undefined */
	if (raw >= (1 << 10))
		return INT_MIN;

	/* First check for temperature in first direct table */
	if (raw < ARRAY_SIZE(rx51_temp_table1))
		return rx51_temp_table1[raw] * 10;

	/* Binary search RAW value in second inverse table */
	while (max - min > 1) {
		int mid = (max + min) / 2;
		if (rx51_temp_table2[mid] <= raw)
			min = mid;
		else if (rx51_temp_table2[mid] > raw)
			max = mid;
		if (rx51_temp_table2[mid] == raw)
			break;
	}

	return (rx51_temp_table2_first - min) * 10;
}

__attribute__((used)) static int rx51_battery_read_capacity(struct rx51_device_info *di)
{
	int capacity = rx51_battery_read_adc(di->channel_bsi);

	if (capacity < 0) {
		dev_err(di->dev, "Could not read ADC: %d\n", capacity);
		return capacity;
	}

	return 1280 * (1200 * capacity)/(1024 - capacity);
}

__attribute__((used)) static int rx51_battery_get_property(struct power_supply *psy,
					enum power_supply_property psp,
					union power_supply_propval *val)
{
	struct rx51_device_info *di = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
		val->intval = 4200000;
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = rx51_battery_read_voltage(di) ? 1 : 0;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = rx51_battery_read_voltage(di);
		break;
	case POWER_SUPPLY_PROP_TEMP:
		val->intval = rx51_battery_read_temperature(di);
		break;
	case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
		val->intval = rx51_battery_read_capacity(di);
		break;
	default:
		return -EINVAL;
	}

	if (val->intval == INT_MAX || val->intval == INT_MIN)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int rx51_battery_probe(struct platform_device *pdev)
{
	struct power_supply_config psy_cfg = {};
	struct rx51_device_info *di;
	int ret;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	platform_set_drvdata(pdev, di);

	di->dev = &pdev->dev;
	di->bat_desc.name = "rx51-battery";
	di->bat_desc.type = POWER_SUPPLY_TYPE_BATTERY;
	di->bat_desc.properties = rx51_battery_props;
	di->bat_desc.num_properties = ARRAY_SIZE(rx51_battery_props);
	di->bat_desc.get_property = rx51_battery_get_property;

	psy_cfg.drv_data = di;

	di->channel_temp = iio_channel_get(di->dev, "temp");
	if (IS_ERR(di->channel_temp)) {
		ret = PTR_ERR(di->channel_temp);
		goto error;
	}

	di->channel_bsi  = iio_channel_get(di->dev, "bsi");
	if (IS_ERR(di->channel_bsi)) {
		ret = PTR_ERR(di->channel_bsi);
		goto error_channel_temp;
	}

	di->channel_vbat = iio_channel_get(di->dev, "vbat");
	if (IS_ERR(di->channel_vbat)) {
		ret = PTR_ERR(di->channel_vbat);
		goto error_channel_bsi;
	}

	di->bat = power_supply_register(di->dev, &di->bat_desc, &psy_cfg);
	if (IS_ERR(di->bat)) {
		ret = PTR_ERR(di->bat);
		goto error_channel_vbat;
	}

	return 0;

error_channel_vbat:
	iio_channel_release(di->channel_vbat);
error_channel_bsi:
	iio_channel_release(di->channel_bsi);
error_channel_temp:
	iio_channel_release(di->channel_temp);
error:

	return ret;
}

__attribute__((used)) static int rx51_battery_remove(struct platform_device *pdev)
{
	struct rx51_device_info *di = platform_get_drvdata(pdev);

	power_supply_unregister(di->bat);

	iio_channel_release(di->channel_vbat);
	iio_channel_release(di->channel_bsi);
	iio_channel_release(di->channel_temp);

	return 0;
}

