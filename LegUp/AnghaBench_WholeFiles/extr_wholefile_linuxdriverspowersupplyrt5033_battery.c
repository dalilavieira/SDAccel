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
typedef  int u32 ;
struct rt5033_battery {int /*<<< orphan*/  psy; int /*<<< orphan*/  regmap; struct i2c_client* client; } ;
struct power_supply_config {struct rt5033_battery* drv_data; } ;
struct power_supply {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct i2c_client {TYPE_1__ dev; } ;
struct i2c_adapter {int dummy; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  POWER_SUPPLY_PROP_CAPACITY 132 
#define  POWER_SUPPLY_PROP_PRESENT 131 
#define  POWER_SUPPLY_PROP_VOLTAGE_AVG 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_OCV 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RT5033_FUEL_BAT_PRESENT ; 
 unsigned int RT5033_FUEL_REG_AVG_VOLT_H ; 
 unsigned int RT5033_FUEL_REG_AVG_VOLT_L ; 
 unsigned int RT5033_FUEL_REG_CONFIG_L ; 
 unsigned int RT5033_FUEL_REG_OCV_H ; 
 unsigned int RT5033_FUEL_REG_OCV_L ; 
 unsigned int RT5033_FUEL_REG_SOC_H ; 
 unsigned int RT5033_FUEL_REG_VBAT_H ; 
 unsigned int RT5033_FUEL_REG_VBAT_L ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 struct rt5033_battery* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct rt5033_battery* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct rt5033_battery*) ; 
 struct rt5033_battery* power_supply_get_drvdata (struct power_supply*) ; 
 int /*<<< orphan*/  power_supply_register (TYPE_1__*,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 int /*<<< orphan*/  power_supply_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,unsigned int,int*) ; 
 int /*<<< orphan*/  rt5033_battery_desc ; 
 int /*<<< orphan*/  rt5033_battery_regmap_config ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rt5033_battery_get_capacity(struct i2c_client *client)
{
	struct rt5033_battery *battery = i2c_get_clientdata(client);
	u32 msb;

	regmap_read(battery->regmap, RT5033_FUEL_REG_SOC_H, &msb);

	return msb;
}

__attribute__((used)) static int rt5033_battery_get_present(struct i2c_client *client)
{
	struct rt5033_battery *battery = i2c_get_clientdata(client);
	u32 val;

	regmap_read(battery->regmap, RT5033_FUEL_REG_CONFIG_L, &val);

	return (val & RT5033_FUEL_BAT_PRESENT) ? true : false;
}

__attribute__((used)) static int rt5033_battery_get_watt_prop(struct i2c_client *client,
		enum power_supply_property psp)
{
	struct rt5033_battery *battery = i2c_get_clientdata(client);
	unsigned int regh, regl;
	int ret;
	u32 msb, lsb;

	switch (psp) {
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		regh = RT5033_FUEL_REG_VBAT_H;
		regl = RT5033_FUEL_REG_VBAT_L;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
		regh = RT5033_FUEL_REG_AVG_VOLT_H;
		regl = RT5033_FUEL_REG_AVG_VOLT_L;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_OCV:
		regh = RT5033_FUEL_REG_OCV_H;
		regl = RT5033_FUEL_REG_OCV_L;
		break;
	default:
		return -EINVAL;
	}

	regmap_read(battery->regmap, regh, &msb);
	regmap_read(battery->regmap, regl, &lsb);

	ret = ((msb << 4) + (lsb >> 4)) * 1250 / 1000;

	return ret;
}

__attribute__((used)) static int rt5033_battery_get_property(struct power_supply *psy,
		enum power_supply_property psp,
		union power_supply_propval *val)
{
	struct rt5033_battery *battery = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
	case POWER_SUPPLY_PROP_VOLTAGE_OCV:
		val->intval = rt5033_battery_get_watt_prop(battery->client,
									psp);
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = rt5033_battery_get_present(battery->client);
		break;
	case POWER_SUPPLY_PROP_CAPACITY:
		val->intval = rt5033_battery_get_capacity(battery->client);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int rt5033_battery_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
	struct power_supply_config psy_cfg = {};
	struct rt5033_battery *battery;
	u32 ret;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
		return -EIO;

	battery = devm_kzalloc(&client->dev, sizeof(*battery), GFP_KERNEL);
	if (!battery)
		return -EINVAL;

	battery->client = client;
	battery->regmap = devm_regmap_init_i2c(client,
			&rt5033_battery_regmap_config);
	if (IS_ERR(battery->regmap)) {
		dev_err(&client->dev, "Failed to initialize regmap\n");
		return -EINVAL;
	}

	i2c_set_clientdata(client, battery);
	psy_cfg.drv_data = battery;

	battery->psy = power_supply_register(&client->dev,
					     &rt5033_battery_desc, &psy_cfg);
	if (IS_ERR(battery->psy)) {
		dev_err(&client->dev, "Failed to register power supply\n");
		ret = PTR_ERR(battery->psy);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int rt5033_battery_remove(struct i2c_client *client)
{
	struct rt5033_battery *battery = i2c_get_clientdata(client);

	power_supply_unregister(battery->psy);

	return 0;
}

