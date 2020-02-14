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
struct power_supply_config {struct max8903_data* drv_data; struct device_node* of_node; } ;
struct power_supply {int dummy; } ;
struct device {struct device_node* of_node; struct max8903_pdata* platform_data; } ;
struct platform_device {struct device dev; } ;
struct max8903_pdata {int chg; int dok; int dcm; int cen; int uok; int flt; int dc_valid; int usb_valid; int usus; } ;
struct TYPE_2__ {int type; char* name; int (* get_property ) (struct power_supply*,int,union power_supply_propval*) ;int /*<<< orphan*/  num_properties; int /*<<< orphan*/  properties; } ;
struct max8903_data {int usb_in; int ta_in; int fault; int /*<<< orphan*/  psy; TYPE_1__ psy_desc; struct device* dev; struct max8903_pdata* pdata; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_type { ____Placeholder_power_supply_type } power_supply_type ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int POWER_SUPPLY_HEALTH_GOOD ; 
 int POWER_SUPPLY_HEALTH_UNSPEC_FAILURE ; 
#define  POWER_SUPPLY_PROP_HEALTH 130 
#define  POWER_SUPPLY_PROP_ONLINE 129 
#define  POWER_SUPPLY_PROP_STATUS 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 int POWER_SUPPLY_STATUS_UNKNOWN ; 
 void* POWER_SUPPLY_TYPE_BATTERY ; 
 void* POWER_SUPPLY_TYPE_MAINS ; 
 void* POWER_SUPPLY_TYPE_USB ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int devm_gpio_request (struct device*,int,char*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_power_supply_register (struct device*,TYPE_1__*,struct power_supply_config*) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct max8903_data*) ; 
 scalar_t__ gpio_get_value (int) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int gpio_to_irq (int) ; 
 int /*<<< orphan*/  max8903_charger_props ; 
 void* of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct max8903_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max8903_data*) ; 
 int /*<<< orphan*/  power_supply_changed (int /*<<< orphan*/ ) ; 
 struct max8903_data* power_supply_get_drvdata (struct power_supply*) ; 

__attribute__((used)) static int max8903_get_property(struct power_supply *psy,
		enum power_supply_property psp,
		union power_supply_propval *val)
{
	struct max8903_data *data = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
		if (gpio_is_valid(data->pdata->chg)) {
			if (gpio_get_value(data->pdata->chg) == 0)
				val->intval = POWER_SUPPLY_STATUS_CHARGING;
			else if (data->usb_in || data->ta_in)
				val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
			else
				val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
		}
		break;
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = 0;
		if (data->usb_in || data->ta_in)
			val->intval = 1;
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = POWER_SUPPLY_HEALTH_GOOD;
		if (data->fault)
			val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static irqreturn_t max8903_dcin(int irq, void *_data)
{
	struct max8903_data *data = _data;
	struct max8903_pdata *pdata = data->pdata;
	bool ta_in;
	enum power_supply_type old_type;

	ta_in = gpio_get_value(pdata->dok) ? false : true;

	if (ta_in == data->ta_in)
		return IRQ_HANDLED;

	data->ta_in = ta_in;

	/* Set Current-Limit-Mode 1:DC 0:USB */
	if (gpio_is_valid(pdata->dcm))
		gpio_set_value(pdata->dcm, ta_in ? 1 : 0);

	/* Charger Enable / Disable (cen is negated) */
	if (gpio_is_valid(pdata->cen))
		gpio_set_value(pdata->cen, ta_in ? 0 :
				(data->usb_in ? 0 : 1));

	dev_dbg(data->dev, "TA(DC-IN) Charger %s.\n", ta_in ?
			"Connected" : "Disconnected");

	old_type = data->psy_desc.type;

	if (data->ta_in)
		data->psy_desc.type = POWER_SUPPLY_TYPE_MAINS;
	else if (data->usb_in)
		data->psy_desc.type = POWER_SUPPLY_TYPE_USB;
	else
		data->psy_desc.type = POWER_SUPPLY_TYPE_BATTERY;

	if (old_type != data->psy_desc.type)
		power_supply_changed(data->psy);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t max8903_usbin(int irq, void *_data)
{
	struct max8903_data *data = _data;
	struct max8903_pdata *pdata = data->pdata;
	bool usb_in;
	enum power_supply_type old_type;

	usb_in = gpio_get_value(pdata->uok) ? false : true;

	if (usb_in == data->usb_in)
		return IRQ_HANDLED;

	data->usb_in = usb_in;

	/* Do not touch Current-Limit-Mode */

	/* Charger Enable / Disable (cen is negated) */
	if (gpio_is_valid(pdata->cen))
		gpio_set_value(pdata->cen, usb_in ? 0 :
				(data->ta_in ? 0 : 1));

	dev_dbg(data->dev, "USB Charger %s.\n", usb_in ?
			"Connected" : "Disconnected");

	old_type = data->psy_desc.type;

	if (data->ta_in)
		data->psy_desc.type = POWER_SUPPLY_TYPE_MAINS;
	else if (data->usb_in)
		data->psy_desc.type = POWER_SUPPLY_TYPE_USB;
	else
		data->psy_desc.type = POWER_SUPPLY_TYPE_BATTERY;

	if (old_type != data->psy_desc.type)
		power_supply_changed(data->psy);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t max8903_fault(int irq, void *_data)
{
	struct max8903_data *data = _data;
	struct max8903_pdata *pdata = data->pdata;
	bool fault;

	fault = gpio_get_value(pdata->flt) ? false : true;

	if (fault == data->fault)
		return IRQ_HANDLED;

	data->fault = fault;

	if (fault)
		dev_err(data->dev, "Charger suffers a fault and stops.\n");
	else
		dev_err(data->dev, "Charger recovered from a fault.\n");

	return IRQ_HANDLED;
}

__attribute__((used)) static struct max8903_pdata *max8903_parse_dt_data(struct device *dev)
{
	struct device_node *np = dev->of_node;
	struct max8903_pdata *pdata = NULL;

	if (!np)
		return NULL;

	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;

	pdata->dc_valid = false;
	pdata->usb_valid = false;

	pdata->cen = of_get_named_gpio(np, "cen-gpios", 0);
	if (!gpio_is_valid(pdata->cen))
		pdata->cen = -EINVAL;

	pdata->chg = of_get_named_gpio(np, "chg-gpios", 0);
	if (!gpio_is_valid(pdata->chg))
		pdata->chg = -EINVAL;

	pdata->flt = of_get_named_gpio(np, "flt-gpios", 0);
	if (!gpio_is_valid(pdata->flt))
		pdata->flt = -EINVAL;

	pdata->usus = of_get_named_gpio(np, "usus-gpios", 0);
	if (!gpio_is_valid(pdata->usus))
		pdata->usus = -EINVAL;

	pdata->dcm = of_get_named_gpio(np, "dcm-gpios", 0);
	if (!gpio_is_valid(pdata->dcm))
		pdata->dcm = -EINVAL;

	pdata->dok = of_get_named_gpio(np, "dok-gpios", 0);
	if (!gpio_is_valid(pdata->dok))
		pdata->dok = -EINVAL;
	else
		pdata->dc_valid = true;

	pdata->uok = of_get_named_gpio(np, "uok-gpios", 0);
	if (!gpio_is_valid(pdata->uok))
		pdata->uok = -EINVAL;
	else
		pdata->usb_valid = true;

	return pdata;
}

__attribute__((used)) static int max8903_setup_gpios(struct platform_device *pdev)
{
	struct max8903_data *data = platform_get_drvdata(pdev);
	struct device *dev = &pdev->dev;
	struct max8903_pdata *pdata = pdev->dev.platform_data;
	int ret = 0;
	int gpio;
	int ta_in = 0;
	int usb_in = 0;

	if (pdata->dc_valid) {
		if (gpio_is_valid(pdata->dok)) {
			ret = devm_gpio_request(dev, pdata->dok,
						data->psy_desc.name);
			if (ret) {
				dev_err(dev,
					"Failed GPIO request for dok: %d err %d\n",
					pdata->dok, ret);
				return ret;
			}

			gpio = pdata->dok; /* PULL_UPed Interrupt */
			ta_in = gpio_get_value(gpio) ? 0 : 1;
		} else {
			dev_err(dev, "When DC is wired, DOK should be wired as well.\n");
			return -EINVAL;
		}
	}

	if (gpio_is_valid(pdata->dcm)) {
		ret = devm_gpio_request(dev, pdata->dcm, data->psy_desc.name);
		if (ret) {
			dev_err(dev,
				"Failed GPIO request for dcm: %d err %d\n",
				pdata->dcm, ret);
			return ret;
		}

		gpio = pdata->dcm; /* Output */
		gpio_set_value(gpio, ta_in);
	}

	if (pdata->usb_valid) {
		if (gpio_is_valid(pdata->uok)) {
			ret = devm_gpio_request(dev, pdata->uok,
						data->psy_desc.name);
			if (ret) {
				dev_err(dev,
					"Failed GPIO request for uok: %d err %d\n",
					pdata->uok, ret);
				return ret;
			}

			gpio = pdata->uok;
			usb_in = gpio_get_value(gpio) ? 0 : 1;
		} else {
			dev_err(dev, "When USB is wired, UOK should be wired."
					"as well.\n");
			return -EINVAL;
		}
	}

	if (gpio_is_valid(pdata->cen)) {
		ret = devm_gpio_request(dev, pdata->cen, data->psy_desc.name);
		if (ret) {
			dev_err(dev,
				"Failed GPIO request for cen: %d err %d\n",
				pdata->cen, ret);
			return ret;
		}

		gpio_set_value(pdata->cen, (ta_in || usb_in) ? 0 : 1);
	}

	if (gpio_is_valid(pdata->chg)) {
		ret = devm_gpio_request(dev, pdata->chg, data->psy_desc.name);
		if (ret) {
			dev_err(dev,
				"Failed GPIO request for chg: %d err %d\n",
				pdata->chg, ret);
			return ret;
		}
	}

	if (gpio_is_valid(pdata->flt)) {
		ret = devm_gpio_request(dev, pdata->flt, data->psy_desc.name);
		if (ret) {
			dev_err(dev,
				"Failed GPIO request for flt: %d err %d\n",
				pdata->flt, ret);
			return ret;
		}
	}

	if (gpio_is_valid(pdata->usus)) {
		ret = devm_gpio_request(dev, pdata->usus, data->psy_desc.name);
		if (ret) {
			dev_err(dev,
				"Failed GPIO request for usus: %d err %d\n",
				pdata->usus, ret);
			return ret;
		}
	}

	data->fault = false;
	data->ta_in = ta_in;
	data->usb_in = usb_in;

	return 0;
}

__attribute__((used)) static int max8903_probe(struct platform_device *pdev)
{
	struct max8903_data *data;
	struct device *dev = &pdev->dev;
	struct max8903_pdata *pdata = pdev->dev.platform_data;
	struct power_supply_config psy_cfg = {};
	int ret = 0;

	data = devm_kzalloc(dev, sizeof(struct max8903_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	if (IS_ENABLED(CONFIG_OF) && !pdata && dev->of_node)
		pdata = max8903_parse_dt_data(dev);

	if (!pdata) {
		dev_err(dev, "No platform data.\n");
		return -EINVAL;
	}

	pdev->dev.platform_data = pdata;
	data->pdata = pdata;
	data->dev = dev;
	platform_set_drvdata(pdev, data);

	if (pdata->dc_valid == false && pdata->usb_valid == false) {
		dev_err(dev, "No valid power sources.\n");
		return -EINVAL;
	}

	ret = max8903_setup_gpios(pdev);
	if (ret)
		return ret;

	data->psy_desc.name = "max8903_charger";
	data->psy_desc.type = (data->ta_in) ? POWER_SUPPLY_TYPE_MAINS :
			((data->usb_in) ? POWER_SUPPLY_TYPE_USB :
			 POWER_SUPPLY_TYPE_BATTERY);
	data->psy_desc.get_property = max8903_get_property;
	data->psy_desc.properties = max8903_charger_props;
	data->psy_desc.num_properties = ARRAY_SIZE(max8903_charger_props);

	psy_cfg.of_node = dev->of_node;
	psy_cfg.drv_data = data;

	data->psy = devm_power_supply_register(dev, &data->psy_desc, &psy_cfg);
	if (IS_ERR(data->psy)) {
		dev_err(dev, "failed: power supply register.\n");
		return PTR_ERR(data->psy);
	}

	if (pdata->dc_valid) {
		ret = devm_request_threaded_irq(dev, gpio_to_irq(pdata->dok),
					NULL, max8903_dcin,
					IRQF_TRIGGER_FALLING |
					IRQF_TRIGGER_RISING | IRQF_ONESHOT,
					"MAX8903 DC IN", data);
		if (ret) {
			dev_err(dev, "Cannot request irq %d for DC (%d)\n",
					gpio_to_irq(pdata->dok), ret);
			return ret;
		}
	}

	if (pdata->usb_valid) {
		ret = devm_request_threaded_irq(dev, gpio_to_irq(pdata->uok),
					NULL, max8903_usbin,
					IRQF_TRIGGER_FALLING |
					IRQF_TRIGGER_RISING | IRQF_ONESHOT,
					"MAX8903 USB IN", data);
		if (ret) {
			dev_err(dev, "Cannot request irq %d for USB (%d)\n",
					gpio_to_irq(pdata->uok), ret);
			return ret;
		}
	}

	if (gpio_is_valid(pdata->flt)) {
		ret = devm_request_threaded_irq(dev, gpio_to_irq(pdata->flt),
					NULL, max8903_fault,
					IRQF_TRIGGER_FALLING |
					IRQF_TRIGGER_RISING | IRQF_ONESHOT,
					"MAX8903 Fault", data);
		if (ret) {
			dev_err(dev, "Cannot request irq %d for Fault (%d)\n",
					gpio_to_irq(pdata->flt), ret);
			return ret;
		}
	}

	return 0;
}

