#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int /*<<< orphan*/  dev; } ;
struct input_polled_dev {void (* poll ) (struct input_polled_dev*) ;TYPE_3__* input; int /*<<< orphan*/  poll_interval; } ;
struct TYPE_7__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_6__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_8__ {char* name; char* phys; TYPE_2__ dev; TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GPIO_BTN_S1 ; 
 int /*<<< orphan*/  LO_FOFF ; 
 int /*<<< orphan*/  RB532_BTN_KSYM ; 
 int /*<<< orphan*/  RB532_BTN_RATE ; 
 struct input_polled_dev* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct input_polled_dev*) ; 
 int /*<<< orphan*/  gpio_direction_input (int /*<<< orphan*/ ) ; 
 int gpio_get_value (int /*<<< orphan*/ ) ; 
 struct input_polled_dev* input_allocate_polled_device () ; 
 int /*<<< orphan*/  input_free_polled_device (struct input_polled_dev*) ; 
 int input_register_polled_device (struct input_polled_dev*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  input_unregister_polled_device (struct input_polled_dev*) ; 
 int /*<<< orphan*/  rb532_gpio_set_func (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_latch_u5 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool rb532_button_pressed(void)
{
	int val;

	set_latch_u5(0, LO_FOFF);
	gpio_direction_input(GPIO_BTN_S1);

	val = gpio_get_value(GPIO_BTN_S1);

	rb532_gpio_set_func(GPIO_BTN_S1);
	set_latch_u5(LO_FOFF, 0);

	return !val;
}

__attribute__((used)) static void rb532_button_poll(struct input_polled_dev *poll_dev)
{
	input_report_key(poll_dev->input, RB532_BTN_KSYM,
			 rb532_button_pressed());
	input_sync(poll_dev->input);
}

__attribute__((used)) static int rb532_button_probe(struct platform_device *pdev)
{
	struct input_polled_dev *poll_dev;
	int error;

	poll_dev = input_allocate_polled_device();
	if (!poll_dev)
		return -ENOMEM;

	poll_dev->poll = rb532_button_poll;
	poll_dev->poll_interval = RB532_BTN_RATE;

	poll_dev->input->name = "rb532 button";
	poll_dev->input->phys = "rb532/button0";
	poll_dev->input->id.bustype = BUS_HOST;
	poll_dev->input->dev.parent = &pdev->dev;

	dev_set_drvdata(&pdev->dev, poll_dev);

	input_set_capability(poll_dev->input, EV_KEY, RB532_BTN_KSYM);

	error = input_register_polled_device(poll_dev);
	if (error) {
		input_free_polled_device(poll_dev);
		return error;
	}

	return 0;
}

__attribute__((used)) static int rb532_button_remove(struct platform_device *pdev)
{
	struct input_polled_dev *poll_dev = dev_get_drvdata(&pdev->dev);

	input_unregister_polled_device(poll_dev);
	input_free_polled_device(poll_dev);

	return 0;
}

