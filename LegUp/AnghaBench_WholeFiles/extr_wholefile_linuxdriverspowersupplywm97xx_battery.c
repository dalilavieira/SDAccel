#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
struct work_struct {int dummy; } ;
struct wm97xx_batt_pdata {scalar_t__ batt_aux; unsigned long batt_mult; unsigned long batt_div; scalar_t__ temp_aux; unsigned long temp_mult; unsigned long temp_div; scalar_t__ batt_tech; scalar_t__ max_voltage; scalar_t__ min_voltage; scalar_t__ charge_gpio; char* batt_name; } ;
struct power_supply_config {struct wm97xx_batt_pdata* drv_data; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct power_supply {TYPE_2__* desc; TYPE_1__ dev; } ;
struct TYPE_10__ {struct wm97xx_batt_pdata* platform_data; } ;
struct platform_device {int id; TYPE_3__ dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
struct TYPE_11__ {char* name; int* properties; int num_properties; } ;
struct TYPE_9__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,void (*) (struct work_struct*)) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IS_ERR (struct power_supply*) ; 
#define  POWER_SUPPLY_PROP_PRESENT 134 
#define  POWER_SUPPLY_PROP_STATUS 133 
#define  POWER_SUPPLY_PROP_TECHNOLOGY 132 
#define  POWER_SUPPLY_PROP_TEMP 131 
#define  POWER_SUPPLY_PROP_VOLTAGE_MAX 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_MIN 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_UNKNOWN ; 
 int PTR_ERR (struct power_supply*) ; 
 struct power_supply* bat_psy ; 
 TYPE_4__ bat_psy_desc ; 
 int bat_status ; 
 int /*<<< orphan*/  bat_work ; 
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct platform_device*) ; 
 int gpio_direction_input (scalar_t__) ; 
 int /*<<< orphan*/  gpio_free (scalar_t__) ; 
 scalar_t__ gpio_get_value (scalar_t__) ; 
 scalar_t__ gpio_is_valid (scalar_t__) ; 
 int gpio_request (scalar_t__,char*) ; 
 int /*<<< orphan*/  gpio_to_irq (scalar_t__) ; 
 int* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  power_supply_changed (struct power_supply*) ; 
 struct wm97xx_batt_pdata* power_supply_get_drvdata (struct power_supply*) ; 
 struct power_supply* power_supply_register (TYPE_3__*,TYPE_4__*,struct power_supply_config*) ; 
 int /*<<< orphan*/  power_supply_unregister (struct power_supply*) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,int,int) ; 
 int* prop ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct platform_device*) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 unsigned long wm97xx_read_aux_adc (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  work_lock ; 

__attribute__((used)) static unsigned long wm97xx_read_bat(struct power_supply *bat_ps)
{
	struct wm97xx_batt_pdata *pdata = power_supply_get_drvdata(bat_ps);

	return wm97xx_read_aux_adc(dev_get_drvdata(bat_ps->dev.parent),
					pdata->batt_aux) * pdata->batt_mult /
					pdata->batt_div;
}

__attribute__((used)) static unsigned long wm97xx_read_temp(struct power_supply *bat_ps)
{
	struct wm97xx_batt_pdata *pdata = power_supply_get_drvdata(bat_ps);

	return wm97xx_read_aux_adc(dev_get_drvdata(bat_ps->dev.parent),
					pdata->temp_aux) * pdata->temp_mult /
					pdata->temp_div;
}

__attribute__((used)) static int wm97xx_bat_get_property(struct power_supply *bat_ps,
			    enum power_supply_property psp,
			    union power_supply_propval *val)
{
	struct wm97xx_batt_pdata *pdata = power_supply_get_drvdata(bat_ps);

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = bat_status;
		break;
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = pdata->batt_tech;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		if (pdata->batt_aux >= 0)
			val->intval = wm97xx_read_bat(bat_ps);
		else
			return -EINVAL;
		break;
	case POWER_SUPPLY_PROP_TEMP:
		if (pdata->temp_aux >= 0)
			val->intval = wm97xx_read_temp(bat_ps);
		else
			return -EINVAL;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MAX:
		if (pdata->max_voltage >= 0)
			val->intval = pdata->max_voltage;
		else
			return -EINVAL;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MIN:
		if (pdata->min_voltage >= 0)
			val->intval = pdata->min_voltage;
		else
			return -EINVAL;
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = 1;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static void wm97xx_bat_external_power_changed(struct power_supply *bat_ps)
{
	schedule_work(&bat_work);
}

__attribute__((used)) static void wm97xx_bat_update(struct power_supply *bat_ps)
{
	int old_status = bat_status;
	struct wm97xx_batt_pdata *pdata = power_supply_get_drvdata(bat_ps);

	mutex_lock(&work_lock);

	bat_status = (pdata->charge_gpio >= 0) ?
			(gpio_get_value(pdata->charge_gpio) ?
			POWER_SUPPLY_STATUS_DISCHARGING :
			POWER_SUPPLY_STATUS_CHARGING) :
			POWER_SUPPLY_STATUS_UNKNOWN;

	if (old_status != bat_status) {
		pr_debug("%s: %i -> %i\n", bat_ps->desc->name, old_status,
					bat_status);
		power_supply_changed(bat_ps);
	}

	mutex_unlock(&work_lock);
}

__attribute__((used)) static void wm97xx_bat_work(struct work_struct *work)
{
	wm97xx_bat_update(bat_psy);
}

__attribute__((used)) static irqreturn_t wm97xx_chrg_irq(int irq, void *data)
{
	schedule_work(&bat_work);
	return IRQ_HANDLED;
}

__attribute__((used)) static int wm97xx_bat_probe(struct platform_device *dev)
{
	int ret = 0;
	int props = 1;	/* POWER_SUPPLY_PROP_PRESENT */
	int i = 0;
	struct wm97xx_batt_pdata *pdata = dev->dev.platform_data;
	struct power_supply_config cfg = {};

	if (!pdata) {
		dev_err(&dev->dev, "No platform data supplied\n");
		return -EINVAL;
	}

	cfg.drv_data = pdata;

	if (dev->id != -1)
		return -EINVAL;

	if (gpio_is_valid(pdata->charge_gpio)) {
		ret = gpio_request(pdata->charge_gpio, "BATT CHRG");
		if (ret)
			goto err;
		ret = gpio_direction_input(pdata->charge_gpio);
		if (ret)
			goto err2;
		ret = request_irq(gpio_to_irq(pdata->charge_gpio),
				wm97xx_chrg_irq, 0,
				"AC Detect", dev);
		if (ret)
			goto err2;
		props++;	/* POWER_SUPPLY_PROP_STATUS */
	}

	if (pdata->batt_tech >= 0)
		props++;	/* POWER_SUPPLY_PROP_TECHNOLOGY */
	if (pdata->temp_aux >= 0)
		props++;	/* POWER_SUPPLY_PROP_TEMP */
	if (pdata->batt_aux >= 0)
		props++;	/* POWER_SUPPLY_PROP_VOLTAGE_NOW */
	if (pdata->max_voltage >= 0)
		props++;	/* POWER_SUPPLY_PROP_VOLTAGE_MAX */
	if (pdata->min_voltage >= 0)
		props++;	/* POWER_SUPPLY_PROP_VOLTAGE_MIN */

	prop = kcalloc(props, sizeof(*prop), GFP_KERNEL);
	if (!prop) {
		ret = -ENOMEM;
		goto err3;
	}

	prop[i++] = POWER_SUPPLY_PROP_PRESENT;
	if (pdata->charge_gpio >= 0)
		prop[i++] = POWER_SUPPLY_PROP_STATUS;
	if (pdata->batt_tech >= 0)
		prop[i++] = POWER_SUPPLY_PROP_TECHNOLOGY;
	if (pdata->temp_aux >= 0)
		prop[i++] = POWER_SUPPLY_PROP_TEMP;
	if (pdata->batt_aux >= 0)
		prop[i++] = POWER_SUPPLY_PROP_VOLTAGE_NOW;
	if (pdata->max_voltage >= 0)
		prop[i++] = POWER_SUPPLY_PROP_VOLTAGE_MAX;
	if (pdata->min_voltage >= 0)
		prop[i++] = POWER_SUPPLY_PROP_VOLTAGE_MIN;

	INIT_WORK(&bat_work, wm97xx_bat_work);

	if (!pdata->batt_name) {
		dev_info(&dev->dev, "Please consider setting proper battery "
				"name in platform definition file, falling "
				"back to name \"wm97xx-batt\"\n");
		bat_psy_desc.name = "wm97xx-batt";
	} else
		bat_psy_desc.name = pdata->batt_name;

	bat_psy_desc.properties = prop;
	bat_psy_desc.num_properties = props;

	bat_psy = power_supply_register(&dev->dev, &bat_psy_desc, &cfg);
	if (!IS_ERR(bat_psy)) {
		schedule_work(&bat_work);
	} else {
		ret = PTR_ERR(bat_psy);
		goto err4;
	}

	return 0;
err4:
	kfree(prop);
err3:
	if (gpio_is_valid(pdata->charge_gpio))
		free_irq(gpio_to_irq(pdata->charge_gpio), dev);
err2:
	if (gpio_is_valid(pdata->charge_gpio))
		gpio_free(pdata->charge_gpio);
err:
	return ret;
}

__attribute__((used)) static int wm97xx_bat_remove(struct platform_device *dev)
{
	struct wm97xx_batt_pdata *pdata = dev->dev.platform_data;

	if (pdata && gpio_is_valid(pdata->charge_gpio)) {
		free_irq(gpio_to_irq(pdata->charge_gpio), dev);
		gpio_free(pdata->charge_gpio);
	}
	cancel_work_sync(&bat_work);
	power_supply_unregister(bat_psy);
	kfree(prop);
	return 0;
}

