#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct input_dev {char* phys; char* name; TYPE_1__ dev; int /*<<< orphan*/  key; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {int /*<<< orphan*/  name; int /*<<< orphan*/  handler; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KEY_POWER ; 
 int /*<<< orphan*/  KEY_RESTART ; 
 int /*<<< orphan*/  MAX_HELD_TIME ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 int devm_request_any_context_irq (struct device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct input_dev*) ; 
 TYPE_2__* hi65xx_irq_info ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int platform_get_irq_byname (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t hi65xx_power_press_isr(int irq, void *q)
{
	struct input_dev *input = q;

	pm_wakeup_event(input->dev.parent, MAX_HELD_TIME);
	input_report_key(input, KEY_POWER, 1);
	input_sync(input);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t hi65xx_power_release_isr(int irq, void *q)
{
	struct input_dev *input = q;

	pm_wakeup_event(input->dev.parent, MAX_HELD_TIME);
	input_report_key(input, KEY_POWER, 0);
	input_sync(input);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t hi65xx_restart_toggle_isr(int irq, void *q)
{
	struct input_dev *input = q;
	int value = test_bit(KEY_RESTART, input->key);

	pm_wakeup_event(input->dev.parent, MAX_HELD_TIME);
	input_report_key(input, KEY_RESTART, !value);
	input_sync(input);

	return IRQ_HANDLED;
}

__attribute__((used)) static int hi65xx_powerkey_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct input_dev *input;
	int irq, i, error;

	input = devm_input_allocate_device(dev);
	if (!input) {
		dev_err(dev, "failed to allocate input device\n");
		return -ENOMEM;
	}

	input->phys = "hisi_on/input0";
	input->name = "HISI 65xx PowerOn Key";

	input_set_capability(input, EV_KEY, KEY_POWER);
	input_set_capability(input, EV_KEY, KEY_RESTART);

	for (i = 0; i < ARRAY_SIZE(hi65xx_irq_info); i++) {

		irq = platform_get_irq_byname(pdev, hi65xx_irq_info[i].name);
		if (irq < 0) {
			error = irq;
			dev_err(dev, "couldn't get irq %s: %d\n",
				hi65xx_irq_info[i].name, error);
			return error;
		}

		error = devm_request_any_context_irq(dev, irq,
						     hi65xx_irq_info[i].handler,
						     IRQF_ONESHOT,
						     hi65xx_irq_info[i].name,
						     input);
		if (error < 0) {
			dev_err(dev, "couldn't request irq %s: %d\n",
				hi65xx_irq_info[i].name, error);
			return error;
		}
	}

	error = input_register_device(input);
	if (error) {
		dev_err(dev, "failed to register input device: %d\n", error);
		return error;
	}

	device_init_wakeup(dev, 1);

	return 0;
}

