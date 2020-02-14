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
typedef  unsigned long u64 ;
typedef  int u32 ;
struct watchdog_device {unsigned int timeout; int min_timeout; struct device* parent; int /*<<< orphan*/  max_timeout; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct davinci_wdt_device {scalar_t__ clk; struct watchdog_device wdd; scalar_t__ base; } ;

/* Variables and functions */
 unsigned int DEFAULT_HEARTBEAT ; 
 int ENAMODE12_PERIODIC ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int /*<<< orphan*/  MAX_HEARTBEAT ; 
 scalar_t__ PRD12 ; 
 scalar_t__ PRD34 ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ TCR ; 
 scalar_t__ TGCR ; 
 scalar_t__ TIM12 ; 
 int TIM12RS_UNRESET ; 
 scalar_t__ TIM34 ; 
 int TIM34RS_UNRESET ; 
 int TIMMODE_64BIT_WDOG ; 
 int WDEN ; 
 int WDFLAG ; 
 int WDKEY_SEQ0 ; 
 int WDKEY_SEQ1 ; 
 scalar_t__ WDTCR ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  davinci_wdt_info ; 
 int /*<<< orphan*/  davinci_wdt_ops ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,unsigned int) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct davinci_wdt_device* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  heartbeat ; 
 void* ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (int,scalar_t__) ; 
 struct davinci_wdt_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct davinci_wdt_device*) ; 
 struct davinci_wdt_device* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,struct device*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct davinci_wdt_device*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int) ; 
 int /*<<< orphan*/  watchdog_set_restart_priority (struct watchdog_device*,int) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 

__attribute__((used)) static int davinci_wdt_start(struct watchdog_device *wdd)
{
	u32 tgcr;
	u32 timer_margin;
	unsigned long wdt_freq;
	struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);

	wdt_freq = clk_get_rate(davinci_wdt->clk);

	/* disable, internal clock source */
	iowrite32(0, davinci_wdt->base + TCR);
	/* reset timer, set mode to 64-bit watchdog, and unreset */
	iowrite32(0, davinci_wdt->base + TGCR);
	tgcr = TIMMODE_64BIT_WDOG | TIM12RS_UNRESET | TIM34RS_UNRESET;
	iowrite32(tgcr, davinci_wdt->base + TGCR);
	/* clear counter regs */
	iowrite32(0, davinci_wdt->base + TIM12);
	iowrite32(0, davinci_wdt->base + TIM34);
	/* set timeout period */
	timer_margin = (((u64)wdd->timeout * wdt_freq) & 0xffffffff);
	iowrite32(timer_margin, davinci_wdt->base + PRD12);
	timer_margin = (((u64)wdd->timeout * wdt_freq) >> 32);
	iowrite32(timer_margin, davinci_wdt->base + PRD34);
	/* enable run continuously */
	iowrite32(ENAMODE12_PERIODIC, davinci_wdt->base + TCR);
	/* Once the WDT is in pre-active state write to
	 * TIM12, TIM34, PRD12, PRD34, TCR, TGCR, WDTCR are
	 * write protected (except for the WDKEY field)
	 */
	/* put watchdog in pre-active state */
	iowrite32(WDKEY_SEQ0 | WDEN, davinci_wdt->base + WDTCR);
	/* put watchdog in active state */
	iowrite32(WDKEY_SEQ1 | WDEN, davinci_wdt->base + WDTCR);
	return 0;
}

__attribute__((used)) static int davinci_wdt_ping(struct watchdog_device *wdd)
{
	struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);

	/* put watchdog in service state */
	iowrite32(WDKEY_SEQ0, davinci_wdt->base + WDTCR);
	/* put watchdog in active state */
	iowrite32(WDKEY_SEQ1, davinci_wdt->base + WDTCR);
	return 0;
}

__attribute__((used)) static unsigned int davinci_wdt_get_timeleft(struct watchdog_device *wdd)
{
	u64 timer_counter;
	unsigned long freq;
	u32 val;
	struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);

	/* if timeout has occured then return 0 */
	val = ioread32(davinci_wdt->base + WDTCR);
	if (val & WDFLAG)
		return 0;

	freq = clk_get_rate(davinci_wdt->clk);

	if (!freq)
		return 0;

	timer_counter = ioread32(davinci_wdt->base + TIM12);
	timer_counter |= ((u64)ioread32(davinci_wdt->base + TIM34) << 32);

	do_div(timer_counter, freq);

	return wdd->timeout - timer_counter;
}

__attribute__((used)) static int davinci_wdt_restart(struct watchdog_device *wdd,
			       unsigned long action, void *data)
{
	struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);
	u32 tgcr, wdtcr;

	/* disable, internal clock source */
	iowrite32(0, davinci_wdt->base + TCR);

	/* reset timer, set mode to 64-bit watchdog, and unreset */
	tgcr = 0;
	iowrite32(tgcr, davinci_wdt->base + TGCR);
	tgcr = TIMMODE_64BIT_WDOG | TIM12RS_UNRESET | TIM34RS_UNRESET;
	iowrite32(tgcr, davinci_wdt->base + TGCR);

	/* clear counter and period regs */
	iowrite32(0, davinci_wdt->base + TIM12);
	iowrite32(0, davinci_wdt->base + TIM34);
	iowrite32(0, davinci_wdt->base + PRD12);
	iowrite32(0, davinci_wdt->base + PRD34);

	/* put watchdog in pre-active state */
	wdtcr = WDKEY_SEQ0 | WDEN;
	iowrite32(wdtcr, davinci_wdt->base + WDTCR);

	/* put watchdog in active state */
	wdtcr = WDKEY_SEQ1 | WDEN;
	iowrite32(wdtcr, davinci_wdt->base + WDTCR);

	/* write an invalid value to the WDKEY field to trigger a restart */
	wdtcr = 0x00004000;
	iowrite32(wdtcr, davinci_wdt->base + WDTCR);

	return 0;
}

__attribute__((used)) static int davinci_wdt_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct device *dev = &pdev->dev;
	struct resource  *wdt_mem;
	struct watchdog_device *wdd;
	struct davinci_wdt_device *davinci_wdt;

	davinci_wdt = devm_kzalloc(dev, sizeof(*davinci_wdt), GFP_KERNEL);
	if (!davinci_wdt)
		return -ENOMEM;

	davinci_wdt->clk = devm_clk_get(dev, NULL);

	if (IS_ERR(davinci_wdt->clk)) {
		if (PTR_ERR(davinci_wdt->clk) != -EPROBE_DEFER)
			dev_err(&pdev->dev, "failed to get clock node\n");
		return PTR_ERR(davinci_wdt->clk);
	}

	ret = clk_prepare_enable(davinci_wdt->clk);
	if (ret) {
		dev_err(&pdev->dev, "failed to prepare clock\n");
		return ret;
	}

	platform_set_drvdata(pdev, davinci_wdt);

	wdd			= &davinci_wdt->wdd;
	wdd->info		= &davinci_wdt_info;
	wdd->ops		= &davinci_wdt_ops;
	wdd->min_timeout	= 1;
	wdd->max_timeout	= MAX_HEARTBEAT;
	wdd->timeout		= DEFAULT_HEARTBEAT;
	wdd->parent		= &pdev->dev;

	watchdog_init_timeout(wdd, heartbeat, dev);

	dev_info(dev, "heartbeat %d sec\n", wdd->timeout);

	watchdog_set_drvdata(wdd, davinci_wdt);
	watchdog_set_nowayout(wdd, 1);
	watchdog_set_restart_priority(wdd, 128);

	wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	davinci_wdt->base = devm_ioremap_resource(dev, wdt_mem);
	if (IS_ERR(davinci_wdt->base)) {
		ret = PTR_ERR(davinci_wdt->base);
		goto err_clk_disable;
	}

	ret = watchdog_register_device(wdd);
	if (ret) {
		dev_err(dev, "cannot register watchdog device\n");
		goto err_clk_disable;
	}

	return 0;

err_clk_disable:
	clk_disable_unprepare(davinci_wdt->clk);

	return ret;
}

__attribute__((used)) static int davinci_wdt_remove(struct platform_device *pdev)
{
	struct davinci_wdt_device *davinci_wdt = platform_get_drvdata(pdev);

	watchdog_unregister_device(&davinci_wdt->wdd);
	clk_disable_unprepare(davinci_wdt->clk);

	return 0;
}

