#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {int timeout; TYPE_4__* parent; } ;
struct TYPE_15__ {struct device_node* of_node; } ;
struct platform_device {TYPE_4__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_14__ {int /*<<< orphan*/  bootstatus; TYPE_4__* parent; } ;
struct a21_wdt_drv {int* gpios; TYPE_1__ wdt; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 size_t GPIO_WD_ENAB ; 
 size_t GPIO_WD_FAST ; 
 size_t GPIO_WD_RST0 ; 
 size_t GPIO_WD_RST1 ; 
 size_t GPIO_WD_RST2 ; 
 size_t GPIO_WD_TRIG ; 
 int NUM_GPIOS ; 
 int /*<<< orphan*/  WDIOF_CARDRESET ; 
 int /*<<< orphan*/  WDIOF_EXTERN1 ; 
 int /*<<< orphan*/  WDIOF_EXTERN2 ; 
 int /*<<< orphan*/  WDIOF_POWERUNDER ; 
 TYPE_1__ a21_wdt ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 struct a21_wdt_drv* dev_get_drvdata (TYPE_4__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_4__*,struct a21_wdt_drv*) ; 
 int devm_gpio_request (TYPE_4__*,int,char*) ; 
 struct a21_wdt_drv* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int devm_watchdog_register_device (TYPE_4__*,TYPE_1__*) ; 
 int gpio_direction_input (int) ; 
 int gpio_direction_output (int,scalar_t__) ; 
 scalar_t__ gpio_get_value (int) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  ndelay (int) ; 
 int /*<<< orphan*/  nowayout ; 
 int of_get_gpio (struct device_node*,int) ; 
 int of_gpio_count (struct device_node*) ; 
 struct a21_wdt_drv* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (TYPE_1__*,int,TYPE_4__*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (TYPE_1__*,struct a21_wdt_drv*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int a21_wdt_get_bootstatus(struct a21_wdt_drv *drv)
{
	int reset = 0;

	reset |= gpio_get_value(drv->gpios[GPIO_WD_RST0]) ? (1 << 0) : 0;
	reset |= gpio_get_value(drv->gpios[GPIO_WD_RST1]) ? (1 << 1) : 0;
	reset |= gpio_get_value(drv->gpios[GPIO_WD_RST2]) ? (1 << 2) : 0;

	return reset;
}

__attribute__((used)) static int a21_wdt_start(struct watchdog_device *wdt)
{
	struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);

	gpio_set_value(drv->gpios[GPIO_WD_ENAB], 1);

	return 0;
}

__attribute__((used)) static int a21_wdt_stop(struct watchdog_device *wdt)
{
	struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);

	gpio_set_value(drv->gpios[GPIO_WD_ENAB], 0);

	return 0;
}

__attribute__((used)) static int a21_wdt_ping(struct watchdog_device *wdt)
{
	struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);

	gpio_set_value(drv->gpios[GPIO_WD_TRIG], 0);
	ndelay(10);
	gpio_set_value(drv->gpios[GPIO_WD_TRIG], 1);

	return 0;
}

__attribute__((used)) static int a21_wdt_set_timeout(struct watchdog_device *wdt,
			       unsigned int timeout)
{
	struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);

	if (timeout != 1 && timeout != 30) {
		dev_err(wdt->parent, "Only 1 and 30 allowed as timeout\n");
		return -EINVAL;
	}

	if (timeout == 30 && wdt->timeout == 1) {
		dev_err(wdt->parent,
			"Transition from fast to slow mode not allowed\n");
		return -EINVAL;
	}

	if (timeout == 1)
		gpio_set_value(drv->gpios[GPIO_WD_FAST], 1);
	else
		gpio_set_value(drv->gpios[GPIO_WD_FAST], 0);

	wdt->timeout = timeout;

	return 0;
}

__attribute__((used)) static int a21_wdt_probe(struct platform_device *pdev)
{
	struct device_node *node;
	struct a21_wdt_drv *drv;
	unsigned int reset = 0;
	int num_gpios;
	int ret;
	int i;

	drv = devm_kzalloc(&pdev->dev, sizeof(struct a21_wdt_drv), GFP_KERNEL);
	if (!drv)
		return -ENOMEM;

	/* Fill GPIO pin array */
	node = pdev->dev.of_node;

	num_gpios = of_gpio_count(node);
	if (num_gpios != NUM_GPIOS) {
		dev_err(&pdev->dev, "gpios DT property wrong, got %d want %d",
			num_gpios, NUM_GPIOS);
		return -ENODEV;
	}

	for (i = 0; i < num_gpios; i++) {
		int val;

		val = of_get_gpio(node, i);
		if (val < 0)
			return val;

		drv->gpios[i] = val;
	}

	/* Request the used GPIOs */
	for (i = 0; i < num_gpios; i++) {
		ret = devm_gpio_request(&pdev->dev, drv->gpios[i],
					"MEN A21 Watchdog");
		if (ret)
			return ret;

		if (i < GPIO_WD_RST0)
			ret = gpio_direction_output(drv->gpios[i],
						gpio_get_value(drv->gpios[i]));
		else		/* GPIO_WD_RST[0..2] are inputs */
			ret = gpio_direction_input(drv->gpios[i]);
		if (ret)
			return ret;
	}

	watchdog_init_timeout(&a21_wdt, 30, &pdev->dev);
	watchdog_set_nowayout(&a21_wdt, nowayout);
	watchdog_set_drvdata(&a21_wdt, drv);
	a21_wdt.parent = &pdev->dev;

	reset = a21_wdt_get_bootstatus(drv);
	if (reset == 2)
		a21_wdt.bootstatus |= WDIOF_EXTERN1;
	else if (reset == 4)
		a21_wdt.bootstatus |= WDIOF_CARDRESET;
	else if (reset == 5)
		a21_wdt.bootstatus |= WDIOF_POWERUNDER;
	else if (reset == 7)
		a21_wdt.bootstatus |= WDIOF_EXTERN2;

	drv->wdt = a21_wdt;
	dev_set_drvdata(&pdev->dev, drv);

	ret = devm_watchdog_register_device(&pdev->dev, &a21_wdt);
	if (ret) {
		dev_err(&pdev->dev, "Cannot register watchdog device\n");
		return ret;
	}

	dev_info(&pdev->dev, "MEN A21 watchdog timer driver enabled\n");

	return 0;
}

__attribute__((used)) static void a21_wdt_shutdown(struct platform_device *pdev)
{
	struct a21_wdt_drv *drv = dev_get_drvdata(&pdev->dev);

	gpio_set_value(drv->gpios[GPIO_WD_ENAB], 0);
}

