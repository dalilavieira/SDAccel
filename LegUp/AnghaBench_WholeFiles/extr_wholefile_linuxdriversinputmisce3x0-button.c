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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct input_dev {char* name; char* phys; TYPE_1__ dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KEY_POWER ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  device_init_wakeup (int /*<<< orphan*/ *,int) ; 
 struct input_dev* devm_input_allocate_device (int /*<<< orphan*/ *) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int platform_get_irq_byname (struct platform_device*,char*) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t e3x0_button_release_handler(int irq, void *data)
{
	struct input_dev *idev = data;

	input_report_key(idev, KEY_POWER, 0);
	input_sync(idev);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t e3x0_button_press_handler(int irq, void *data)
{
	struct input_dev *idev = data;

	input_report_key(idev, KEY_POWER, 1);
	pm_wakeup_event(idev->dev.parent, 0);
	input_sync(idev);

	return IRQ_HANDLED;
}

__attribute__((used)) static int e3x0_button_probe(struct platform_device *pdev)
{
	struct input_dev *input;
	int irq_press, irq_release;
	int error;

	irq_press = platform_get_irq_byname(pdev, "press");
	if (irq_press < 0) {
		dev_err(&pdev->dev, "No IRQ for 'press', error=%d\n",
			irq_press);
		return irq_press;
	}

	irq_release = platform_get_irq_byname(pdev, "release");
	if (irq_release < 0) {
		dev_err(&pdev->dev, "No IRQ for 'release', error=%d\n",
			irq_release);
		return irq_release;
	}

	input = devm_input_allocate_device(&pdev->dev);
	if (!input)
		return -ENOMEM;

	input->name = "NI Ettus Research USRP E3x0 Button Driver";
	input->phys = "e3x0_button/input0";
	input->dev.parent = &pdev->dev;

	input_set_capability(input, EV_KEY, KEY_POWER);

	error = devm_request_irq(&pdev->dev, irq_press,
				 e3x0_button_press_handler, 0,
				 "e3x0-button", input);
	if (error) {
		dev_err(&pdev->dev, "Failed to request 'press' IRQ#%d: %d\n",
			irq_press, error);
		return error;
	}

	error = devm_request_irq(&pdev->dev, irq_release,
				 e3x0_button_release_handler, 0,
				 "e3x0-button", input);
	if (error) {
		dev_err(&pdev->dev, "Failed to request 'release' IRQ#%d: %d\n",
			irq_release, error);
		return error;
	}

	error = input_register_device(input);
	if (error) {
		dev_err(&pdev->dev, "Can't register input device: %d\n", error);
		return error;
	}

	device_init_wakeup(&pdev->dev, 1);
	return 0;
}

