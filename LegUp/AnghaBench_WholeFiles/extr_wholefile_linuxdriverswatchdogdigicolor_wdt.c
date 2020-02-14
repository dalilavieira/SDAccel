#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint32_t ;
typedef  int u32 ;
struct watchdog_device {unsigned int timeout; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct dc_wdt {int /*<<< orphan*/  lock; scalar_t__ clk; scalar_t__ base; } ;
struct TYPE_7__ {unsigned int max_timeout; unsigned int timeout; struct device* parent; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ TIMER_A_CONTROL ; 
 scalar_t__ TIMER_A_COUNT ; 
 int TIMER_A_ENABLE_COUNT ; 
 int TIMER_A_ENABLE_WATCHDOG ; 
 unsigned int U32_MAX ; 
 unsigned int clk_get_rate (scalar_t__) ; 
 TYPE_1__ dc_wdt_wdd ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct dc_wdt* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_watchdog_register_device (struct device*,TYPE_1__*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  timeout ; 
 struct dc_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (TYPE_1__*,int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (TYPE_1__*,struct dc_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_restart_priority (TYPE_1__*,int) ; 
 int /*<<< orphan*/  watchdog_stop_on_reboot (TYPE_1__*) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void dc_wdt_set(struct dc_wdt *wdt, u32 ticks)
{
	unsigned long flags;

	spin_lock_irqsave(&wdt->lock, flags);

	writel_relaxed(0, wdt->base + TIMER_A_CONTROL);
	writel_relaxed(ticks, wdt->base + TIMER_A_COUNT);
	writel_relaxed(TIMER_A_ENABLE_COUNT | TIMER_A_ENABLE_WATCHDOG,
		       wdt->base + TIMER_A_CONTROL);

	spin_unlock_irqrestore(&wdt->lock, flags);
}

__attribute__((used)) static int dc_wdt_restart(struct watchdog_device *wdog, unsigned long action,
			  void *data)
{
	struct dc_wdt *wdt = watchdog_get_drvdata(wdog);

	dc_wdt_set(wdt, 1);
	/* wait for reset to assert... */
	mdelay(500);

	return 0;
}

__attribute__((used)) static int dc_wdt_start(struct watchdog_device *wdog)
{
	struct dc_wdt *wdt = watchdog_get_drvdata(wdog);

	dc_wdt_set(wdt, wdog->timeout * clk_get_rate(wdt->clk));

	return 0;
}

__attribute__((used)) static int dc_wdt_stop(struct watchdog_device *wdog)
{
	struct dc_wdt *wdt = watchdog_get_drvdata(wdog);

	writel_relaxed(0, wdt->base + TIMER_A_CONTROL);

	return 0;
}

__attribute__((used)) static int dc_wdt_set_timeout(struct watchdog_device *wdog, unsigned int t)
{
	struct dc_wdt *wdt = watchdog_get_drvdata(wdog);

	dc_wdt_set(wdt, t * clk_get_rate(wdt->clk));
	wdog->timeout = t;

	return 0;
}

__attribute__((used)) static unsigned int dc_wdt_get_timeleft(struct watchdog_device *wdog)
{
	struct dc_wdt *wdt = watchdog_get_drvdata(wdog);
	uint32_t count = readl_relaxed(wdt->base + TIMER_A_COUNT);

	return count / clk_get_rate(wdt->clk);
}

__attribute__((used)) static int dc_wdt_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct device *dev = &pdev->dev;
	struct dc_wdt *wdt;
	int ret;

	wdt = devm_kzalloc(dev, sizeof(struct dc_wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	wdt->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(wdt->base))
		return PTR_ERR(wdt->base);

	wdt->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(wdt->clk))
		return PTR_ERR(wdt->clk);
	dc_wdt_wdd.max_timeout = U32_MAX / clk_get_rate(wdt->clk);
	dc_wdt_wdd.timeout = dc_wdt_wdd.max_timeout;
	dc_wdt_wdd.parent = dev;

	spin_lock_init(&wdt->lock);

	watchdog_set_drvdata(&dc_wdt_wdd, wdt);
	watchdog_set_restart_priority(&dc_wdt_wdd, 128);
	watchdog_init_timeout(&dc_wdt_wdd, timeout, dev);
	watchdog_stop_on_reboot(&dc_wdt_wdd);
	ret = devm_watchdog_register_device(dev, &dc_wdt_wdd);
	if (ret) {
		dev_err(dev, "Failed to register watchdog device");
		return ret;
	}

	return 0;
}

