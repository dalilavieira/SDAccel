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
typedef  int u8 ;
struct power_supply_config {struct charger_data* drv_data; } ;
struct power_supply {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct max8997_platform_data {int eoc_mA; int timeout; } ;
struct max8997_dev {struct i2c_client* i2c; int /*<<< orphan*/  dev; } ;
struct i2c_client {int dummy; } ;
struct charger_data {int /*<<< orphan*/  battery; struct max8997_dev* iodev; TYPE_1__* dev; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX8997_REG_MBCCTRL1 ; 
 int /*<<< orphan*/  MAX8997_REG_MBCCTRL5 ; 
 int /*<<< orphan*/  MAX8997_REG_STATUS4 ; 
#define  POWER_SUPPLY_PROP_ONLINE 130 
#define  POWER_SUPPLY_PROP_PRESENT 129 
#define  POWER_SUPPLY_PROP_STATUS 128 
 int POWER_SUPPLY_STATUS_FULL ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct max8997_dev* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct max8997_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 struct charger_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_power_supply_register (TYPE_1__*,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 int /*<<< orphan*/  max8997_battery_desc ; 
 int max8997_read_reg (struct i2c_client*,int /*<<< orphan*/ ,int*) ; 
 int max8997_update_reg (struct i2c_client*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct charger_data*) ; 
 struct charger_data* power_supply_get_drvdata (struct power_supply*) ; 

__attribute__((used)) static int max8997_battery_get_property(struct power_supply *psy,
		enum power_supply_property psp,
		union power_supply_propval *val)
{
	struct charger_data *charger = power_supply_get_drvdata(psy);
	struct i2c_client *i2c = charger->iodev->i2c;
	int ret;
	u8 reg;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = 0;
		ret = max8997_read_reg(i2c, MAX8997_REG_STATUS4, &reg);
		if (ret)
			return ret;
		if ((reg & (1 << 0)) == 0x1)
			val->intval = POWER_SUPPLY_STATUS_FULL;

		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = 0;
		ret = max8997_read_reg(i2c, MAX8997_REG_STATUS4, &reg);
		if (ret)
			return ret;
		if ((reg & (1 << 2)) == 0x0)
			val->intval = 1;

		break;
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = 0;
		ret = max8997_read_reg(i2c, MAX8997_REG_STATUS4, &reg);
		if (ret)
			return ret;
		/* DCINOK */
		if (reg & (1 << 1))
			val->intval = 1;

		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int max8997_battery_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct charger_data *charger;
	struct max8997_dev *iodev = dev_get_drvdata(pdev->dev.parent);
	struct max8997_platform_data *pdata = dev_get_platdata(iodev->dev);
	struct power_supply_config psy_cfg = {};

	if (!pdata)
		return -EINVAL;

	if (pdata->eoc_mA) {
		int val = (pdata->eoc_mA - 50) / 10;
		if (val < 0)
			val = 0;
		if (val > 0xf)
			val = 0xf;

		ret = max8997_update_reg(iodev->i2c,
				MAX8997_REG_MBCCTRL5, val, 0xf);
		if (ret < 0) {
			dev_err(&pdev->dev, "Cannot use i2c bus.\n");
			return ret;
		}
	}

	switch (pdata->timeout) {
	case 5:
		ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
				0x2 << 4, 0x7 << 4);
		break;
	case 6:
		ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
				0x3 << 4, 0x7 << 4);
		break;
	case 7:
		ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
				0x4 << 4, 0x7 << 4);
		break;
	case 0:
		ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
				0x7 << 4, 0x7 << 4);
		break;
	default:
		dev_err(&pdev->dev, "incorrect timeout value (%d)\n",
				pdata->timeout);
		return -EINVAL;
	}
	if (ret < 0) {
		dev_err(&pdev->dev, "Cannot use i2c bus.\n");
		return ret;
	}

	charger = devm_kzalloc(&pdev->dev, sizeof(*charger), GFP_KERNEL);
	if (!charger)
		return -ENOMEM;

	platform_set_drvdata(pdev, charger);


	charger->dev = &pdev->dev;
	charger->iodev = iodev;

	psy_cfg.drv_data = charger;

	charger->battery = devm_power_supply_register(&pdev->dev,
						 &max8997_battery_desc,
						 &psy_cfg);
	if (IS_ERR(charger->battery)) {
		dev_err(&pdev->dev, "failed: power supply register\n");
		return PTR_ERR(charger->battery);
	}

	return 0;
}

