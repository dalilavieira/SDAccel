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
union power_supply_propval {void* intval; } ;
typedef  int uint32_t ;
struct resource {int /*<<< orphan*/  start; } ;
struct power_supply_config {struct goldfish_battery_data* drv_data; } ;
struct power_supply {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct goldfish_battery_data {scalar_t__ irq; void* ac; void* battery; int /*<<< orphan*/ * reg_base; int /*<<< orphan*/  lock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int AC_STATUS_CHANGED ; 
 int /*<<< orphan*/  BATTERY_AC_ONLINE ; 
 int /*<<< orphan*/  BATTERY_CAPACITY ; 
 int /*<<< orphan*/  BATTERY_HEALTH ; 
 int /*<<< orphan*/  BATTERY_INT_ENABLE ; 
 int BATTERY_INT_MASK ; 
 int /*<<< orphan*/  BATTERY_INT_STATUS ; 
 int /*<<< orphan*/  BATTERY_PRESENT ; 
 int /*<<< orphan*/  BATTERY_STATUS ; 
 int BATTERY_STATUS_CHANGED ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* GOLDFISH_BATTERY_READ (struct goldfish_battery_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GOLDFISH_BATTERY_WRITE (struct goldfish_battery_data*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (void*) ; 
#define  POWER_SUPPLY_PROP_CAPACITY 133 
#define  POWER_SUPPLY_PROP_HEALTH 132 
#define  POWER_SUPPLY_PROP_ONLINE 131 
#define  POWER_SUPPLY_PROP_PRESENT 130 
#define  POWER_SUPPLY_PROP_STATUS 129 
#define  POWER_SUPPLY_PROP_TECHNOLOGY 128 
 void* POWER_SUPPLY_TECHNOLOGY_LION ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  ac_desc ; 
 struct goldfish_battery_data* battery_data ; 
 int /*<<< orphan*/  battery_desc ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * devm_ioremap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct goldfish_battery_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct goldfish_battery_data*) ; 
 struct goldfish_battery_data* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct goldfish_battery_data*) ; 
 int /*<<< orphan*/  power_supply_changed (void*) ; 
 struct goldfish_battery_data* power_supply_get_drvdata (struct power_supply*) ; 
 void* power_supply_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 int /*<<< orphan*/  power_supply_unregister (void*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int goldfish_ac_get_property(struct power_supply *psy,
			enum power_supply_property psp,
			union power_supply_propval *val)
{
	struct goldfish_battery_data *data = power_supply_get_drvdata(psy);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_AC_ONLINE);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

__attribute__((used)) static int goldfish_battery_get_property(struct power_supply *psy,
				 enum power_supply_property psp,
				 union power_supply_propval *val)
{
	struct goldfish_battery_data *data = power_supply_get_drvdata(psy);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_STATUS);
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_HEALTH);
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_PRESENT);
		break;
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
		break;
	case POWER_SUPPLY_PROP_CAPACITY:
		val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_CAPACITY);
		break;
	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}

__attribute__((used)) static irqreturn_t goldfish_battery_interrupt(int irq, void *dev_id)
{
	unsigned long irq_flags;
	struct goldfish_battery_data *data = dev_id;
	uint32_t status;

	spin_lock_irqsave(&data->lock, irq_flags);

	/* read status flags, which will clear the interrupt */
	status = GOLDFISH_BATTERY_READ(data, BATTERY_INT_STATUS);
	status &= BATTERY_INT_MASK;

	if (status & BATTERY_STATUS_CHANGED)
		power_supply_changed(data->battery);
	if (status & AC_STATUS_CHANGED)
		power_supply_changed(data->ac);

	spin_unlock_irqrestore(&data->lock, irq_flags);
	return status ? IRQ_HANDLED : IRQ_NONE;
}

__attribute__((used)) static int goldfish_battery_probe(struct platform_device *pdev)
{
	int ret;
	struct resource *r;
	struct goldfish_battery_data *data;
	struct power_supply_config psy_cfg = {};

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	spin_lock_init(&data->lock);

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (r == NULL) {
		dev_err(&pdev->dev, "platform_get_resource failed\n");
		return -ENODEV;
	}

	data->reg_base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (data->reg_base == NULL) {
		dev_err(&pdev->dev, "unable to remap MMIO\n");
		return -ENOMEM;
	}

	data->irq = platform_get_irq(pdev, 0);
	if (data->irq < 0) {
		dev_err(&pdev->dev, "platform_get_irq failed\n");
		return -ENODEV;
	}

	ret = devm_request_irq(&pdev->dev, data->irq, goldfish_battery_interrupt,
						IRQF_SHARED, pdev->name, data);
	if (ret)
		return ret;

	psy_cfg.drv_data = data;

	data->ac = power_supply_register(&pdev->dev, &ac_desc, &psy_cfg);
	if (IS_ERR(data->ac))
		return PTR_ERR(data->ac);

	data->battery = power_supply_register(&pdev->dev, &battery_desc,
						&psy_cfg);
	if (IS_ERR(data->battery)) {
		power_supply_unregister(data->ac);
		return PTR_ERR(data->battery);
	}

	platform_set_drvdata(pdev, data);
	battery_data = data;

	GOLDFISH_BATTERY_WRITE(data, BATTERY_INT_ENABLE, BATTERY_INT_MASK);
	return 0;
}

__attribute__((used)) static int goldfish_battery_remove(struct platform_device *pdev)
{
	struct goldfish_battery_data *data = platform_get_drvdata(pdev);

	power_supply_unregister(data->battery);
	power_supply_unregister(data->ac);
	battery_data = NULL;
	return 0;
}

