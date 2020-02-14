#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct max77620_therm_info {int irq_tjalarm1; int irq_tjalarm2; int /*<<< orphan*/  tz_device; int /*<<< orphan*/  rmap; TYPE_1__* dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned int MAX77620_IRQ_TJALRM1_MASK ; 
 unsigned int MAX77620_IRQ_TJALRM2_MASK ; 
 int MAX77620_NORMAL_OPERATING_TEMP ; 
 int /*<<< orphan*/  MAX77620_REG_STATLBT ; 
 int MAX77620_TJALARM1_TEMP ; 
 int MAX77620_TJALARM2_TEMP ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THERMAL_EVENT_UNSPECIFIED ; 
 int /*<<< orphan*/  dev_crit (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_name (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  device_set_of_node_from_dev (TYPE_1__*,int /*<<< orphan*/ ) ; 
 struct max77620_therm_info* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct max77620_therm_info*) ; 
 int /*<<< orphan*/  devm_thermal_zone_of_sensor_register (TYPE_1__*,int /*<<< orphan*/ ,struct max77620_therm_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  max77620_thermal_ops ; 
 void* platform_get_irq (struct platform_device*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max77620_therm_info*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  thermal_zone_device_update (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int max77620_thermal_read_temp(void *data, int *temp)
{
	struct max77620_therm_info *mtherm = data;
	unsigned int val;
	int ret;

	ret = regmap_read(mtherm->rmap, MAX77620_REG_STATLBT, &val);
	if (ret < 0) {
		dev_err(mtherm->dev, "Failed to read STATLBT: %d\n", ret);
		return ret;
	}

	if (val & MAX77620_IRQ_TJALRM2_MASK)
		*temp = MAX77620_TJALARM2_TEMP;
	else if (val & MAX77620_IRQ_TJALRM1_MASK)
		*temp = MAX77620_TJALARM1_TEMP;
	else
		*temp = MAX77620_NORMAL_OPERATING_TEMP;

	return 0;
}

__attribute__((used)) static irqreturn_t max77620_thermal_irq(int irq, void *data)
{
	struct max77620_therm_info *mtherm = data;

	if (irq == mtherm->irq_tjalarm1)
		dev_warn(mtherm->dev, "Junction Temp Alarm1(120C) occurred\n");
	else if (irq == mtherm->irq_tjalarm2)
		dev_crit(mtherm->dev, "Junction Temp Alarm2(140C) occurred\n");

	thermal_zone_device_update(mtherm->tz_device,
				   THERMAL_EVENT_UNSPECIFIED);

	return IRQ_HANDLED;
}

__attribute__((used)) static int max77620_thermal_probe(struct platform_device *pdev)
{
	struct max77620_therm_info *mtherm;
	int ret;

	mtherm = devm_kzalloc(&pdev->dev, sizeof(*mtherm), GFP_KERNEL);
	if (!mtherm)
		return -ENOMEM;

	mtherm->irq_tjalarm1 = platform_get_irq(pdev, 0);
	mtherm->irq_tjalarm2 = platform_get_irq(pdev, 1);
	if ((mtherm->irq_tjalarm1 < 0) || (mtherm->irq_tjalarm2 < 0)) {
		dev_err(&pdev->dev, "Alarm irq number not available\n");
		return -EINVAL;
	}

	mtherm->dev = &pdev->dev;
	mtherm->rmap = dev_get_regmap(pdev->dev.parent, NULL);
	if (!mtherm->rmap) {
		dev_err(&pdev->dev, "Failed to get parent regmap\n");
		return -ENODEV;
	}

	/*
	 * The reference taken to the parent's node which will be balanced on
	 * reprobe or on platform-device release.
	 */
	device_set_of_node_from_dev(&pdev->dev, pdev->dev.parent);

	mtherm->tz_device = devm_thermal_zone_of_sensor_register(&pdev->dev, 0,
				mtherm, &max77620_thermal_ops);
	if (IS_ERR(mtherm->tz_device)) {
		ret = PTR_ERR(mtherm->tz_device);
		dev_err(&pdev->dev, "Failed to register thermal zone: %d\n",
			ret);
		return ret;
	}

	ret = devm_request_threaded_irq(&pdev->dev, mtherm->irq_tjalarm1, NULL,
					max77620_thermal_irq,
					IRQF_ONESHOT | IRQF_SHARED,
					dev_name(&pdev->dev), mtherm);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to request irq1: %d\n", ret);
		return ret;
	}

	ret = devm_request_threaded_irq(&pdev->dev, mtherm->irq_tjalarm2, NULL,
					max77620_thermal_irq,
					IRQF_ONESHOT | IRQF_SHARED,
					dev_name(&pdev->dev), mtherm);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to request irq2: %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, mtherm);

	return 0;
}

