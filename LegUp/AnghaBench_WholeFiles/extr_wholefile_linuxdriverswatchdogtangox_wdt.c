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
typedef  int u32 ;
struct watchdog_device {unsigned int timeout; int min_timeout; int max_hw_heartbeat_ms; int /*<<< orphan*/  status; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; int /*<<< orphan*/ * parent; } ;
struct tangox_wdt_device {int clk_rate; struct watchdog_device wdt; scalar_t__ clk; scalar_t__ base; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 unsigned int DEFAULT_TIMEOUT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int U32_MAX ; 
 int /*<<< orphan*/  WDOG_HW_RUNNING ; 
 scalar_t__ WD_CONFIG ; 
 int WD_CONFIG_DISABLE ; 
 int WD_CONFIG_XTAL_IN ; 
 scalar_t__ WD_COUNTER ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct tangox_wdt_device* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nowayout ; 
 struct tangox_wdt_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tangox_wdt_device*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tangox_wdt_info ; 
 int /*<<< orphan*/  tangox_wdt_ops ; 
 int /*<<< orphan*/  timeout ; 
 struct tangox_wdt_device* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct tangox_wdt_device*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_set_restart_priority (struct watchdog_device*,int) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int tangox_wdt_set_timeout(struct watchdog_device *wdt,
				  unsigned int new_timeout)
{
	wdt->timeout = new_timeout;

	return 0;
}

__attribute__((used)) static int tangox_wdt_start(struct watchdog_device *wdt)
{
	struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);
	u32 ticks;

	ticks = 1 + wdt->timeout * dev->clk_rate;
	writel(ticks, dev->base + WD_COUNTER);

	return 0;
}

__attribute__((used)) static int tangox_wdt_stop(struct watchdog_device *wdt)
{
	struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);

	writel(0, dev->base + WD_COUNTER);

	return 0;
}

__attribute__((used)) static unsigned int tangox_wdt_get_timeleft(struct watchdog_device *wdt)
{
	struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);
	u32 count;

	count = readl(dev->base + WD_COUNTER);

	if (!count)
		return 0;

	return (count - 1) / dev->clk_rate;
}

__attribute__((used)) static int tangox_wdt_restart(struct watchdog_device *wdt,
			      unsigned long action, void *data)
{
	struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);

	writel(1, dev->base + WD_COUNTER);

	return 0;
}

__attribute__((used)) static int tangox_wdt_probe(struct platform_device *pdev)
{
	struct tangox_wdt_device *dev;
	struct resource *res;
	u32 config;
	int err;

	dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	dev->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(dev->base))
		return PTR_ERR(dev->base);

	dev->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(dev->clk))
		return PTR_ERR(dev->clk);

	err = clk_prepare_enable(dev->clk);
	if (err)
		return err;

	dev->clk_rate = clk_get_rate(dev->clk);
	if (!dev->clk_rate) {
		err = -EINVAL;
		goto err;
	}

	dev->wdt.parent = &pdev->dev;
	dev->wdt.info = &tangox_wdt_info;
	dev->wdt.ops = &tangox_wdt_ops;
	dev->wdt.timeout = DEFAULT_TIMEOUT;
	dev->wdt.min_timeout = 1;
	dev->wdt.max_hw_heartbeat_ms = (U32_MAX - 1) / dev->clk_rate;

	watchdog_init_timeout(&dev->wdt, timeout, &pdev->dev);
	watchdog_set_nowayout(&dev->wdt, nowayout);
	watchdog_set_drvdata(&dev->wdt, dev);

	/*
	 * Deactivate counter if disable bit is set to avoid
	 * accidental reset.
	 */
	config = readl(dev->base + WD_CONFIG);
	if (config & WD_CONFIG_DISABLE)
		writel(0, dev->base + WD_COUNTER);

	writel(WD_CONFIG_XTAL_IN, dev->base + WD_CONFIG);

	/*
	 * Mark as active and restart with configured timeout if
	 * already running.
	 */
	if (readl(dev->base + WD_COUNTER)) {
		set_bit(WDOG_HW_RUNNING, &dev->wdt.status);
		tangox_wdt_start(&dev->wdt);
	}

	watchdog_set_restart_priority(&dev->wdt, 128);

	err = watchdog_register_device(&dev->wdt);
	if (err)
		goto err;

	platform_set_drvdata(pdev, dev);

	dev_info(&pdev->dev, "SMP86xx/SMP87xx watchdog registered\n");

	return 0;

 err:
	clk_disable_unprepare(dev->clk);
	return err;
}

__attribute__((used)) static int tangox_wdt_remove(struct platform_device *pdev)
{
	struct tangox_wdt_device *dev = platform_get_drvdata(pdev);

	tangox_wdt_stop(&dev->wdt);
	clk_disable_unprepare(dev->clk);

	watchdog_unregister_device(&dev->wdt);

	return 0;
}

