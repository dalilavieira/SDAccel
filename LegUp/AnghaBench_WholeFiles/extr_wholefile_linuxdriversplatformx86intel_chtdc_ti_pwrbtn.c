#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct regmap {int dummy; } ;
struct device {struct device* parent; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct intel_soc_pmic {int /*<<< orphan*/  regmap; } ;
struct TYPE_4__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_3__ {struct device* parent; } ;
struct input_dev {char* phys; TYPE_2__ id; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int /*<<< orphan*/  CHTDC_TI_SIRQ_REG ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int /*<<< orphan*/  KEY_POWER ; 
 int SIRQ_PWRBTN_REL ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_pm_clear_wake_irq (struct device*) ; 
 int /*<<< orphan*/  dev_pm_set_wake_irq (struct device*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static irqreturn_t chtdc_ti_pwrbtn_interrupt(int irq, void *dev_id)
{
	struct input_dev *input = dev_id;
	struct device *dev = input->dev.parent;
	struct regmap *regmap = dev_get_drvdata(dev);
	int state;

	if (!regmap_read(regmap, CHTDC_TI_SIRQ_REG, &state)) {
		dev_dbg(dev, "SIRQ_REG=0x%x\n", state);
		input_report_key(input, KEY_POWER, !(state & SIRQ_PWRBTN_REL));
		input_sync(input);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int chtdc_ti_pwrbtn_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct intel_soc_pmic *pmic = dev_get_drvdata(dev->parent);
	struct input_dev *input;
	int irq, err;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;
	input = devm_input_allocate_device(dev);
	if (!input)
		return -ENOMEM;
	input->name = pdev->name;
	input->phys = "power-button/input0";
	input->id.bustype = BUS_HOST;
	input_set_capability(input, EV_KEY, KEY_POWER);
	err = input_register_device(input);
	if (err)
		return err;

	dev_set_drvdata(dev, pmic->regmap);

	err = devm_request_threaded_irq(dev, irq, NULL,
					chtdc_ti_pwrbtn_interrupt,
					0, KBUILD_MODNAME, input);
	if (err)
		return err;

	device_init_wakeup(dev, true);
	dev_pm_set_wake_irq(dev, irq);
	return 0;
}

__attribute__((used)) static int chtdc_ti_pwrbtn_remove(struct platform_device *pdev)
{
	dev_pm_clear_wake_irq(&pdev->dev);
	device_init_wakeup(&pdev->dev, false);
	return 0;
}

