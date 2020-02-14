#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct cpcap_power_button {TYPE_3__* idev; TYPE_2__* dev; int /*<<< orphan*/  regmap; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_13__ {TYPE_2__* parent; } ;
struct TYPE_15__ {char* name; char* phys; TYPE_1__ dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KEY_POWER ; 
 int cpcap_sense_virq (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_2__*,int) ; 
 TYPE_3__* devm_input_allocate_device (TYPE_2__*) ; 
 struct cpcap_power_button* devm_kmalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_2__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct cpcap_power_button*) ; 
 int input_register_device (TYPE_3__*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (TYPE_3__*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_wakeup_event (TYPE_2__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t powerbutton_irq(int irq, void *_button)
{
	struct cpcap_power_button *button = _button;
	int val;

	val = cpcap_sense_virq(button->regmap, irq);
	if (val < 0) {
		dev_err(button->dev, "irq read failed: %d", val);
		return IRQ_HANDLED;
	}

	pm_wakeup_event(button->dev, 0);
	input_report_key(button->idev, KEY_POWER, val);
	input_sync(button->idev);

	return IRQ_HANDLED;
}

__attribute__((used)) static int cpcap_power_button_probe(struct platform_device *pdev)
{
	struct cpcap_power_button *button;
	int irq = platform_get_irq(pdev, 0);
	int err;

	button = devm_kmalloc(&pdev->dev, sizeof(*button), GFP_KERNEL);
	if (!button)
		return -ENOMEM;

	button->idev = devm_input_allocate_device(&pdev->dev);
	if (!button->idev)
		return -ENOMEM;

	button->regmap = dev_get_regmap(pdev->dev.parent, NULL);
	if (!button->regmap)
		return -ENODEV;

	button->dev = &pdev->dev;

	button->idev->name = "cpcap-pwrbutton";
	button->idev->phys = "cpcap-pwrbutton/input0";
	button->idev->dev.parent = button->dev;
	input_set_capability(button->idev, EV_KEY, KEY_POWER);

	err = devm_request_threaded_irq(&pdev->dev, irq, NULL,
		powerbutton_irq, IRQF_ONESHOT, "cpcap_pwrbutton", button);
	if (err < 0) {
		dev_err(&pdev->dev, "IRQ request failed: %d\n", err);
		return err;
	}

	err = input_register_device(button->idev);
	if (err) {
		dev_err(&pdev->dev, "Input register failed: %d\n", err);
		return err;
	}

	device_init_wakeup(&pdev->dev, true);

	return 0;
}

