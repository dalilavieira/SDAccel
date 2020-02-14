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
struct watchdog_device {int max_hw_heartbeat_ms; unsigned int timeout; int min_timeout; int /*<<< orphan*/ * parent; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct ls1x_wdt_drvdata {unsigned int clk_rate; scalar_t__ clk; struct watchdog_device wdt; scalar_t__ base; } ;

/* Variables and functions */
 unsigned int DEFAULT_HEARTBEAT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long U32_MAX ; 
 scalar_t__ WDT_EN ; 
 scalar_t__ WDT_SET ; 
 scalar_t__ WDT_TIMER ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct ls1x_wdt_drvdata* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heartbeat ; 
 int /*<<< orphan*/  ls1x_wdt_info ; 
 int /*<<< orphan*/  ls1x_wdt_ops ; 
 unsigned int min (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  nowayout ; 
 struct ls1x_wdt_drvdata* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ls1x_wdt_drvdata*) ; 
 struct ls1x_wdt_drvdata* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct ls1x_wdt_drvdata*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int ls1x_wdt_ping(struct watchdog_device *wdt_dev)
{
	struct ls1x_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);

	writel(0x1, drvdata->base + WDT_SET);

	return 0;
}

__attribute__((used)) static int ls1x_wdt_set_timeout(struct watchdog_device *wdt_dev,
				unsigned int timeout)
{
	struct ls1x_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);
	unsigned int max_hw_heartbeat = wdt_dev->max_hw_heartbeat_ms / 1000;
	unsigned int counts;

	wdt_dev->timeout = timeout;

	counts = drvdata->clk_rate * min(timeout, max_hw_heartbeat);
	writel(counts, drvdata->base + WDT_TIMER);

	return 0;
}

__attribute__((used)) static int ls1x_wdt_start(struct watchdog_device *wdt_dev)
{
	struct ls1x_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);

	writel(0x1, drvdata->base + WDT_EN);

	return 0;
}

__attribute__((used)) static int ls1x_wdt_stop(struct watchdog_device *wdt_dev)
{
	struct ls1x_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);

	writel(0x0, drvdata->base + WDT_EN);

	return 0;
}

__attribute__((used)) static int ls1x_wdt_probe(struct platform_device *pdev)
{
	struct ls1x_wdt_drvdata *drvdata;
	struct watchdog_device *ls1x_wdt;
	unsigned long clk_rate;
	struct resource *res;
	int err;

	drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
	if (!drvdata)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	drvdata->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(drvdata->base))
		return PTR_ERR(drvdata->base);

	drvdata->clk = devm_clk_get(&pdev->dev, pdev->name);
	if (IS_ERR(drvdata->clk))
		return PTR_ERR(drvdata->clk);

	err = clk_prepare_enable(drvdata->clk);
	if (err) {
		dev_err(&pdev->dev, "clk enable failed\n");
		return err;
	}

	clk_rate = clk_get_rate(drvdata->clk);
	if (!clk_rate) {
		err = -EINVAL;
		goto err0;
	}
	drvdata->clk_rate = clk_rate;

	ls1x_wdt = &drvdata->wdt;
	ls1x_wdt->info = &ls1x_wdt_info;
	ls1x_wdt->ops = &ls1x_wdt_ops;
	ls1x_wdt->timeout = DEFAULT_HEARTBEAT;
	ls1x_wdt->min_timeout = 1;
	ls1x_wdt->max_hw_heartbeat_ms = U32_MAX / clk_rate * 1000;
	ls1x_wdt->parent = &pdev->dev;

	watchdog_init_timeout(ls1x_wdt, heartbeat, &pdev->dev);
	watchdog_set_nowayout(ls1x_wdt, nowayout);
	watchdog_set_drvdata(ls1x_wdt, drvdata);

	err = watchdog_register_device(&drvdata->wdt);
	if (err) {
		dev_err(&pdev->dev, "failed to register watchdog device\n");
		goto err0;
	}

	platform_set_drvdata(pdev, drvdata);

	dev_info(&pdev->dev, "Loongson1 Watchdog driver registered\n");

	return 0;
err0:
	clk_disable_unprepare(drvdata->clk);
	return err;
}

__attribute__((used)) static int ls1x_wdt_remove(struct platform_device *pdev)
{
	struct ls1x_wdt_drvdata *drvdata = platform_get_drvdata(pdev);

	watchdog_unregister_device(&drvdata->wdt);
	clk_disable_unprepare(drvdata->clk);

	return 0;
}

