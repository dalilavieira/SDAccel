#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct pps_gpio_platform_data {int gpio_pin; char* gpio_label; int assert_falling_edge; int capture_clear; } ;
struct TYPE_11__ {int mode; int /*<<< orphan*/  name; int /*<<< orphan*/  owner; } ;
struct pps_gpio_device_data {int gpio_pin; int assert_falling_edge; int capture_clear; int irq; TYPE_1__* pps; TYPE_3__ info; } ;
struct pps_event_time {int dummy; } ;
struct TYPE_12__ {struct device_node* of_node; struct pps_gpio_platform_data* platform_data; } ;
struct platform_device {char* name; int id; TYPE_5__ dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {TYPE_5__* dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long IRQF_TRIGGER_FALLING ; 
 unsigned long IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int PPS_CANWAIT ; 
 int PPS_CAPTUREASSERT ; 
 int PPS_CAPTURECLEAR ; 
 int PPS_ECHOASSERT ; 
 int PPS_ECHOCLEAR ; 
 char* PPS_GPIO_NAME ; 
 scalar_t__ PPS_MAX_NAME_LEN ; 
 int PPS_OFFSETASSERT ; 
 int PPS_OFFSETCLEAR ; 
 int PPS_TSFMT_TSPEC ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_5__*,char*,int) ; 
 int devm_gpio_request (TYPE_5__*,int,char const*) ; 
 struct pps_gpio_device_data* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_5__*,int,int /*<<< orphan*/  (*) (int,void*),unsigned long,int /*<<< orphan*/ ,struct pps_gpio_device_data*) ; 
 int gpio_direction_input (int) ; 
 int gpio_get_value (int) ; 
 int gpio_to_irq (int) ; 
 int of_get_gpio (struct device_node*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_get_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct pps_gpio_device_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pps_gpio_device_data*) ; 
 int /*<<< orphan*/  pps_event (TYPE_1__*,struct pps_event_time*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pps_get_ts (struct pps_event_time*) ; 
 TYPE_1__* pps_register_source (TYPE_3__*,int) ; 
 int /*<<< orphan*/  pps_unregister_source (TYPE_1__*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,scalar_t__,char*,char*,int) ; 

__attribute__((used)) static irqreturn_t pps_gpio_irq_handler(int irq, void *data)
{
	const struct pps_gpio_device_data *info;
	struct pps_event_time ts;
	int rising_edge;

	/* Get the time stamp first */
	pps_get_ts(&ts);

	info = data;

	rising_edge = gpio_get_value(info->gpio_pin);
	if ((rising_edge && !info->assert_falling_edge) ||
			(!rising_edge && info->assert_falling_edge))
		pps_event(info->pps, &ts, PPS_CAPTUREASSERT, NULL);
	else if (info->capture_clear &&
			((rising_edge && info->assert_falling_edge) ||
			 (!rising_edge && !info->assert_falling_edge)))
		pps_event(info->pps, &ts, PPS_CAPTURECLEAR, NULL);

	return IRQ_HANDLED;
}

__attribute__((used)) static unsigned long
get_irqf_trigger_flags(const struct pps_gpio_device_data *data)
{
	unsigned long flags = data->assert_falling_edge ?
		IRQF_TRIGGER_FALLING : IRQF_TRIGGER_RISING;

	if (data->capture_clear) {
		flags |= ((flags & IRQF_TRIGGER_RISING) ?
				IRQF_TRIGGER_FALLING : IRQF_TRIGGER_RISING);
	}

	return flags;
}

__attribute__((used)) static int pps_gpio_probe(struct platform_device *pdev)
{
	struct pps_gpio_device_data *data;
	const char *gpio_label;
	int ret;
	int pps_default_params;
	const struct pps_gpio_platform_data *pdata = pdev->dev.platform_data;
	struct device_node *np = pdev->dev.of_node;

	/* allocate space for device info */
	data = devm_kzalloc(&pdev->dev, sizeof(struct pps_gpio_device_data),
			GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	if (pdata) {
		data->gpio_pin = pdata->gpio_pin;
		gpio_label = pdata->gpio_label;

		data->assert_falling_edge = pdata->assert_falling_edge;
		data->capture_clear = pdata->capture_clear;
	} else {
		ret = of_get_gpio(np, 0);
		if (ret < 0) {
			dev_err(&pdev->dev, "failed to get GPIO from device tree\n");
			return ret;
		}
		data->gpio_pin = ret;
		gpio_label = PPS_GPIO_NAME;

		if (of_get_property(np, "assert-falling-edge", NULL))
			data->assert_falling_edge = true;

                if (of_get_property(np, "capture-clear", NULL))
                        data->capture_clear = true;
	}

	/* GPIO setup */
	ret = devm_gpio_request(&pdev->dev, data->gpio_pin, gpio_label);
	if (ret) {
		dev_err(&pdev->dev, "failed to request GPIO %u\n",
			data->gpio_pin);
		return ret;
	}

	ret = gpio_direction_input(data->gpio_pin);
	if (ret) {
		dev_err(&pdev->dev, "failed to set pin direction\n");
		return -EINVAL;
	}

	/* IRQ setup */
	ret = gpio_to_irq(data->gpio_pin);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to map GPIO to IRQ: %d\n", ret);
		return -EINVAL;
	}
	data->irq = ret;

	/* initialize PPS specific parts of the bookkeeping data structure. */
	data->info.mode = PPS_CAPTUREASSERT | PPS_OFFSETASSERT |
		PPS_ECHOASSERT | PPS_CANWAIT | PPS_TSFMT_TSPEC;
	if (data->capture_clear)
		data->info.mode |= PPS_CAPTURECLEAR | PPS_OFFSETCLEAR |
			PPS_ECHOCLEAR;
	data->info.owner = THIS_MODULE;
	snprintf(data->info.name, PPS_MAX_NAME_LEN - 1, "%s.%d",
		 pdev->name, pdev->id);

	/* register PPS source */
	pps_default_params = PPS_CAPTUREASSERT | PPS_OFFSETASSERT;
	if (data->capture_clear)
		pps_default_params |= PPS_CAPTURECLEAR | PPS_OFFSETCLEAR;
	data->pps = pps_register_source(&data->info, pps_default_params);
	if (data->pps == NULL) {
		dev_err(&pdev->dev, "failed to register IRQ %d as PPS source\n",
			data->irq);
		return -EINVAL;
	}

	/* register IRQ interrupt handler */
	ret = devm_request_irq(&pdev->dev, data->irq, pps_gpio_irq_handler,
			get_irqf_trigger_flags(data), data->info.name, data);
	if (ret) {
		pps_unregister_source(data->pps);
		dev_err(&pdev->dev, "failed to acquire IRQ %d\n", data->irq);
		return -EINVAL;
	}

	platform_set_drvdata(pdev, data);
	dev_info(data->pps->dev, "Registered IRQ %d as PPS source\n",
		 data->irq);

	return 0;
}

__attribute__((used)) static int pps_gpio_remove(struct platform_device *pdev)
{
	struct pps_gpio_device_data *data = platform_get_drvdata(pdev);

	pps_unregister_source(data->pps);
	dev_info(&pdev->dev, "removed IRQ %d as PPS source\n", data->irq);
	return 0;
}

