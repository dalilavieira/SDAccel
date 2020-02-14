#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int /*<<< orphan*/  intval; } ;
struct power_supply_desc {int (* get_property ) (struct power_supply*,int,union power_supply_propval*) ;int /*<<< orphan*/  num_properties; int /*<<< orphan*/  properties; int /*<<< orphan*/  type; int /*<<< orphan*/  name; } ;
struct power_supply_config {struct ltc3651_charger* drv_data; TYPE_1__* of_node; } ;
struct power_supply {int dummy; } ;
struct TYPE_11__ {TYPE_1__* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct ltc3651_charger {void* charger; void* chrg_gpio; void* fault_gpio; void* acpr_gpio; struct power_supply_desc charger_desc; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
struct TYPE_10__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (void*) ; 
 int /*<<< orphan*/  POWER_SUPPLY_HEALTH_DEAD ; 
 int /*<<< orphan*/  POWER_SUPPLY_HEALTH_GOOD ; 
 int /*<<< orphan*/  POWER_SUPPLY_HEALTH_OVERHEAT ; 
 int /*<<< orphan*/  POWER_SUPPLY_HEALTH_UNKNOWN ; 
 int /*<<< orphan*/  POWER_SUPPLY_HEALTH_UNSPEC_FAILURE ; 
#define  POWER_SUPPLY_PROP_HEALTH 130 
#define  POWER_SUPPLY_PROP_ONLINE 129 
#define  POWER_SUPPLY_PROP_STATUS 128 
 int /*<<< orphan*/  POWER_SUPPLY_STATUS_CHARGING ; 
 int /*<<< orphan*/  POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 int /*<<< orphan*/  POWER_SUPPLY_STATUS_UNKNOWN ; 
 int /*<<< orphan*/  POWER_SUPPLY_TYPE_MAINS ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 void* devm_gpiod_get (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 void* devm_gpiod_get_optional (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 struct ltc3651_charger* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 void* devm_power_supply_register (TYPE_2__*,struct power_supply_desc*,struct power_supply_config*) ; 
 int devm_request_any_context_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  gpiod_get_value (void*) ; 
 int gpiod_to_irq (void*) ; 
 int /*<<< orphan*/  ltc3651_charger_properties ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ltc3651_charger*) ; 
 int /*<<< orphan*/  power_supply_changed (struct power_supply*) ; 
 struct ltc3651_charger* power_supply_get_drvdata (struct power_supply*) ; 

__attribute__((used)) static irqreturn_t ltc3651_charger_irq(int irq, void *devid)
{
	struct power_supply *charger = devid;

	power_supply_changed(charger);

	return IRQ_HANDLED;
}

__attribute__((used)) static inline struct ltc3651_charger *psy_to_ltc3651_charger(
	struct power_supply *psy)
{
	return power_supply_get_drvdata(psy);
}

__attribute__((used)) static int ltc3651_charger_get_property(struct power_supply *psy,
		enum power_supply_property psp, union power_supply_propval *val)
{
	struct ltc3651_charger *ltc3651_charger = psy_to_ltc3651_charger(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		if (!ltc3651_charger->chrg_gpio) {
			val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
			break;
		}
		if (gpiod_get_value(ltc3651_charger->chrg_gpio))
			val->intval = POWER_SUPPLY_STATUS_CHARGING;
		else
			val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
		break;
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = gpiod_get_value(ltc3651_charger->acpr_gpio);
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		if (!ltc3651_charger->fault_gpio) {
			val->intval = POWER_SUPPLY_HEALTH_UNKNOWN;
			break;
		}
		if (!gpiod_get_value(ltc3651_charger->fault_gpio)) {
			val->intval = POWER_SUPPLY_HEALTH_GOOD;
			break;
		}
		/*
		 * If the fault pin is active, the chrg pin explains the type
		 * of failure.
		 */
		if (!ltc3651_charger->chrg_gpio) {
			val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
			break;
		}
		val->intval = gpiod_get_value(ltc3651_charger->chrg_gpio) ?
				POWER_SUPPLY_HEALTH_OVERHEAT :
				POWER_SUPPLY_HEALTH_DEAD;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int ltc3651_charger_probe(struct platform_device *pdev)
{
	struct power_supply_config psy_cfg = {};
	struct ltc3651_charger *ltc3651_charger;
	struct power_supply_desc *charger_desc;
	int ret;

	ltc3651_charger = devm_kzalloc(&pdev->dev, sizeof(*ltc3651_charger),
					GFP_KERNEL);
	if (!ltc3651_charger)
		return -ENOMEM;

	ltc3651_charger->acpr_gpio = devm_gpiod_get(&pdev->dev,
					"lltc,acpr", GPIOD_IN);
	if (IS_ERR(ltc3651_charger->acpr_gpio)) {
		ret = PTR_ERR(ltc3651_charger->acpr_gpio);
		dev_err(&pdev->dev, "Failed to acquire acpr GPIO: %d\n", ret);
		return ret;
	}
	ltc3651_charger->fault_gpio = devm_gpiod_get_optional(&pdev->dev,
					"lltc,fault", GPIOD_IN);
	if (IS_ERR(ltc3651_charger->fault_gpio)) {
		ret = PTR_ERR(ltc3651_charger->fault_gpio);
		dev_err(&pdev->dev, "Failed to acquire fault GPIO: %d\n", ret);
		return ret;
	}
	ltc3651_charger->chrg_gpio = devm_gpiod_get_optional(&pdev->dev,
					"lltc,chrg", GPIOD_IN);
	if (IS_ERR(ltc3651_charger->chrg_gpio)) {
		ret = PTR_ERR(ltc3651_charger->chrg_gpio);
		dev_err(&pdev->dev, "Failed to acquire chrg GPIO: %d\n", ret);
		return ret;
	}

	charger_desc = &ltc3651_charger->charger_desc;
	charger_desc->name = pdev->dev.of_node->name;
	charger_desc->type = POWER_SUPPLY_TYPE_MAINS;
	charger_desc->properties = ltc3651_charger_properties;
	charger_desc->num_properties = ARRAY_SIZE(ltc3651_charger_properties);
	charger_desc->get_property = ltc3651_charger_get_property;
	psy_cfg.of_node = pdev->dev.of_node;
	psy_cfg.drv_data = ltc3651_charger;

	ltc3651_charger->charger = devm_power_supply_register(&pdev->dev,
						      charger_desc, &psy_cfg);
	if (IS_ERR(ltc3651_charger->charger)) {
		ret = PTR_ERR(ltc3651_charger->charger);
		dev_err(&pdev->dev, "Failed to register power supply: %d\n",
			ret);
		return ret;
	}

	/*
	 * Acquire IRQs for the GPIO pins if possible. If the system does not
	 * support IRQs on these pins, userspace will have to poll the sysfs
	 * files manually.
	 */
	if (ltc3651_charger->acpr_gpio) {
		ret = gpiod_to_irq(ltc3651_charger->acpr_gpio);
		if (ret >= 0)
			ret = devm_request_any_context_irq(&pdev->dev, ret,
				ltc3651_charger_irq,
				IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
				dev_name(&pdev->dev), ltc3651_charger->charger);
		if (ret < 0)
			dev_warn(&pdev->dev, "Failed to request acpr irq\n");
	}
	if (ltc3651_charger->fault_gpio) {
		ret = gpiod_to_irq(ltc3651_charger->fault_gpio);
		if (ret >= 0)
			ret = devm_request_any_context_irq(&pdev->dev, ret,
				ltc3651_charger_irq,
				IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
				dev_name(&pdev->dev), ltc3651_charger->charger);
		if (ret < 0)
			dev_warn(&pdev->dev, "Failed to request fault irq\n");
	}
	if (ltc3651_charger->chrg_gpio) {
		ret = gpiod_to_irq(ltc3651_charger->chrg_gpio);
		if (ret >= 0)
			ret = devm_request_any_context_irq(&pdev->dev, ret,
				ltc3651_charger_irq,
				IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
				dev_name(&pdev->dev), ltc3651_charger->charger);
		if (ret < 0)
			dev_warn(&pdev->dev, "Failed to request chrg irq\n");
	}

	platform_set_drvdata(pdev, ltc3651_charger);

	return 0;
}

