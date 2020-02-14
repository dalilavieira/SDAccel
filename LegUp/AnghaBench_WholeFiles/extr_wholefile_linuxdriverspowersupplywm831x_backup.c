#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
struct wm831x_pdata {int wm831x_num; struct wm831x_backup_pdata* backup; } ;
struct wm831x_backup_pdata {int vlim; int ilim; scalar_t__ no_constant_voltage; scalar_t__ charger_enable; } ;
struct TYPE_9__ {int (* get_property ) (struct power_supply*,int,union power_supply_propval*) ;int /*<<< orphan*/  num_properties; int /*<<< orphan*/  properties; int /*<<< orphan*/  type; int /*<<< orphan*/  name; } ;
struct wm831x_backup {int /*<<< orphan*/  backup; TYPE_3__ backup_desc; int /*<<< orphan*/  name; struct wm831x* wm831x; } ;
struct wm831x {TYPE_5__* dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct power_supply {TYPE_1__ dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
typedef  enum wm831x_auxadc { ____Placeholder_wm831x_auxadc } wm831x_auxadc ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
struct TYPE_10__ {struct wm831x_pdata* platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  POWER_SUPPLY_PROP_PRESENT 130 
#define  POWER_SUPPLY_PROP_STATUS 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 int /*<<< orphan*/  POWER_SUPPLY_TYPE_BATTERY ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int WM831X_AUX_BKUP_BATT ; 
 int /*<<< orphan*/  WM831X_BACKUP_CHARGER_CONTROL ; 
 int WM831X_BKUP_BATT_DET_ENA ; 
 int WM831X_BKUP_BATT_DET_ENA_MASK ; 
 int WM831X_BKUP_CHG_ENA ; 
 int WM831X_BKUP_CHG_ENA_MASK ; 
 int WM831X_BKUP_CHG_ILIM_MASK ; 
 int WM831X_BKUP_CHG_MODE ; 
 int WM831X_BKUP_CHG_MODE_MASK ; 
 int WM831X_BKUP_CHG_STS ; 
 int WM831X_BKUP_CHG_VLIM ; 
 int WM831X_BKUP_CHG_VLIM_MASK ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,int) ; 
 void* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_5__*,char*) ; 
 struct wm831x_backup* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct wm831x_backup* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm831x_backup*) ; 
 int /*<<< orphan*/  power_supply_register (TYPE_2__*,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  power_supply_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,...) ; 
 int wm831x_auxadc_read_uv (struct wm831x*,int) ; 
 int /*<<< orphan*/  wm831x_backup_props ; 
 int /*<<< orphan*/  wm831x_reg_lock (struct wm831x*) ; 
 int wm831x_reg_read (struct wm831x*,int /*<<< orphan*/ ) ; 
 int wm831x_reg_unlock (struct wm831x*) ; 
 int wm831x_set_bits (struct wm831x*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int wm831x_backup_read_voltage(struct wm831x *wm831x,
				     enum wm831x_auxadc src,
				     union power_supply_propval *val)
{
	int ret;

	ret = wm831x_auxadc_read_uv(wm831x, src);
	if (ret >= 0)
		val->intval = ret;

	return ret;
}

__attribute__((used)) static void wm831x_config_backup(struct wm831x *wm831x)
{
	struct wm831x_pdata *wm831x_pdata = wm831x->dev->platform_data;
	struct wm831x_backup_pdata *pdata;
	int ret, reg;

	if (!wm831x_pdata || !wm831x_pdata->backup) {
		dev_warn(wm831x->dev,
			 "No backup battery charger configuration\n");
		return;
	}

	pdata = wm831x_pdata->backup;

	reg = 0;

	if (pdata->charger_enable)
		reg |= WM831X_BKUP_CHG_ENA | WM831X_BKUP_BATT_DET_ENA;
	if (pdata->no_constant_voltage)
		reg |= WM831X_BKUP_CHG_MODE;

	switch (pdata->vlim) {
	case 2500:
		break;
	case 3100:
		reg |= WM831X_BKUP_CHG_VLIM;
		break;
	default:
		dev_err(wm831x->dev, "Invalid backup voltage limit %dmV\n",
			pdata->vlim);
	}

	switch (pdata->ilim) {
	case 100:
		break;
	case 200:
		reg |= 1;
		break;
	case 300:
		reg |= 2;
		break;
	case 400:
		reg |= 3;
		break;
	default:
		dev_err(wm831x->dev, "Invalid backup current limit %duA\n",
			pdata->ilim);
	}

	ret = wm831x_reg_unlock(wm831x);
	if (ret != 0) {
		dev_err(wm831x->dev, "Failed to unlock registers: %d\n", ret);
		return;
	}

	ret = wm831x_set_bits(wm831x, WM831X_BACKUP_CHARGER_CONTROL,
			      WM831X_BKUP_CHG_ENA_MASK |
			      WM831X_BKUP_CHG_MODE_MASK |
			      WM831X_BKUP_BATT_DET_ENA_MASK |
			      WM831X_BKUP_CHG_VLIM_MASK |
			      WM831X_BKUP_CHG_ILIM_MASK,
			      reg);
	if (ret != 0)
		dev_err(wm831x->dev,
			"Failed to set backup charger config: %d\n", ret);

	wm831x_reg_lock(wm831x);
}

__attribute__((used)) static int wm831x_backup_get_prop(struct power_supply *psy,
				  enum power_supply_property psp,
				  union power_supply_propval *val)
{
	struct wm831x_backup *devdata = dev_get_drvdata(psy->dev.parent);
	struct wm831x *wm831x = devdata->wm831x;
	int ret = 0;

	ret = wm831x_reg_read(wm831x, WM831X_BACKUP_CHARGER_CONTROL);
	if (ret < 0)
		return ret;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		if (ret & WM831X_BKUP_CHG_STS)
			val->intval = POWER_SUPPLY_STATUS_CHARGING;
		else
			val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
		break;

	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		ret = wm831x_backup_read_voltage(wm831x, WM831X_AUX_BKUP_BATT,
						val);
		break;

	case POWER_SUPPLY_PROP_PRESENT:
		if (ret & WM831X_BKUP_CHG_STS)
			val->intval = 1;
		else
			val->intval = 0;
		break;

	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}

__attribute__((used)) static int wm831x_backup_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_pdata *wm831x_pdata = wm831x->dev->platform_data;
	struct wm831x_backup *devdata;

	devdata = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_backup),
				GFP_KERNEL);
	if (devdata == NULL)
		return -ENOMEM;

	devdata->wm831x = wm831x;
	platform_set_drvdata(pdev, devdata);

	/* We ignore configuration failures since we can still read
	 * back the status without enabling the charger (which may
	 * already be enabled anyway).
	 */
	wm831x_config_backup(wm831x);

	if (wm831x_pdata && wm831x_pdata->wm831x_num)
		snprintf(devdata->name, sizeof(devdata->name),
			 "wm831x-backup.%d", wm831x_pdata->wm831x_num);
	else
		snprintf(devdata->name, sizeof(devdata->name),
			 "wm831x-backup");

	devdata->backup_desc.name = devdata->name;
	devdata->backup_desc.type = POWER_SUPPLY_TYPE_BATTERY;
	devdata->backup_desc.properties = wm831x_backup_props;
	devdata->backup_desc.num_properties = ARRAY_SIZE(wm831x_backup_props);
	devdata->backup_desc.get_property = wm831x_backup_get_prop;
	devdata->backup = power_supply_register(&pdev->dev,
						&devdata->backup_desc, NULL);

	return PTR_ERR_OR_ZERO(devdata->backup);
}

__attribute__((used)) static int wm831x_backup_remove(struct platform_device *pdev)
{
	struct wm831x_backup *devdata = platform_get_drvdata(pdev);

	power_supply_unregister(devdata->backup);

	return 0;
}

