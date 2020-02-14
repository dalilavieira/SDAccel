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
struct watchdog_device {int timeout; int /*<<< orphan*/  bootstatus; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct pic32_wdt {scalar_t__ clk; scalar_t__ rst_base; scalar_t__ regs; } ;

/* Variables and functions */
 int BIT (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int /*<<< orphan*/  PIC32_BASE_RESET ; 
 int /*<<< orphan*/  PIC32_CLR (scalar_t__) ; 
 int /*<<< orphan*/  PIC32_SET (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int RESETCON_WDT_TIMEOUT ; 
 int /*<<< orphan*/  WATCHDOG_NOWAYOUT ; 
 int /*<<< orphan*/  WDIOF_CARDRESET ; 
 int /*<<< orphan*/  WDTCON_CLR_KEY ; 
 int WDTCON_ON ; 
 scalar_t__ WDTCON_REG ; 
 int WDTCON_RMCS_MASK ; 
 int WDTCON_RMCS_SHIFT ; 
 int WDTCON_RMPS_MASK ; 
 int WDTCON_RMPS_SHIFT ; 
 int WDTCON_WIN_EN ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned long,int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct pic32_wdt* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nop () ; 
 struct watchdog_device pic32_wdd ; 
 struct watchdog_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct watchdog_device*) ; 
 int readl (scalar_t__) ; 
 struct pic32_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct pic32_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline bool pic32_wdt_is_win_enabled(struct pic32_wdt *wdt)
{
	return !!(readl(wdt->regs + WDTCON_REG) & WDTCON_WIN_EN);
}

__attribute__((used)) static inline u32 pic32_wdt_get_post_scaler(struct pic32_wdt *wdt)
{
	u32 v = readl(wdt->regs + WDTCON_REG);

	return (v >> WDTCON_RMPS_SHIFT) & WDTCON_RMPS_MASK;
}

__attribute__((used)) static inline u32 pic32_wdt_get_clk_id(struct pic32_wdt *wdt)
{
	u32 v = readl(wdt->regs + WDTCON_REG);

	return (v >> WDTCON_RMCS_SHIFT) & WDTCON_RMCS_MASK;
}

__attribute__((used)) static int pic32_wdt_bootstatus(struct pic32_wdt *wdt)
{
	u32 v = readl(wdt->rst_base);

	writel(RESETCON_WDT_TIMEOUT, PIC32_CLR(wdt->rst_base));

	return v & RESETCON_WDT_TIMEOUT;
}

__attribute__((used)) static u32 pic32_wdt_get_timeout_secs(struct pic32_wdt *wdt, struct device *dev)
{
	unsigned long rate;
	u32 period, ps, terminal;

	rate = clk_get_rate(wdt->clk);

	dev_dbg(dev, "wdt: clk_id %d, clk_rate %lu (prescale)\n",
		pic32_wdt_get_clk_id(wdt), rate);

	/* default, prescaler of 32 (i.e. div-by-32) is implicit. */
	rate >>= 5;
	if (!rate)
		return 0;

	/* calculate terminal count from postscaler. */
	ps = pic32_wdt_get_post_scaler(wdt);
	terminal = BIT(ps);

	/* find time taken (in secs) to reach terminal count */
	period = terminal / rate;
	dev_dbg(dev,
		"wdt: clk_rate %lu (postscale) / terminal %d, timeout %dsec\n",
		rate, terminal, period);

	return period;
}

__attribute__((used)) static void pic32_wdt_keepalive(struct pic32_wdt *wdt)
{
	/* write key through single half-word */
	writew(WDTCON_CLR_KEY, wdt->regs + WDTCON_REG + 2);
}

__attribute__((used)) static int pic32_wdt_start(struct watchdog_device *wdd)
{
	struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);

	writel(WDTCON_ON, PIC32_SET(wdt->regs + WDTCON_REG));
	pic32_wdt_keepalive(wdt);

	return 0;
}

__attribute__((used)) static int pic32_wdt_stop(struct watchdog_device *wdd)
{
	struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);

	writel(WDTCON_ON, PIC32_CLR(wdt->regs + WDTCON_REG));

	/*
	 * Cannot touch registers in the CPU cycle following clearing the
	 * ON bit.
	 */
	nop();

	return 0;
}

__attribute__((used)) static int pic32_wdt_ping(struct watchdog_device *wdd)
{
	struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);

	pic32_wdt_keepalive(wdt);

	return 0;
}

__attribute__((used)) static int pic32_wdt_drv_probe(struct platform_device *pdev)
{
	int ret;
	struct watchdog_device *wdd = &pic32_wdd;
	struct pic32_wdt *wdt;
	struct resource *mem;

	wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	wdt->regs = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(wdt->regs))
		return PTR_ERR(wdt->regs);

	wdt->rst_base = devm_ioremap(&pdev->dev, PIC32_BASE_RESET, 0x10);
	if (!wdt->rst_base)
		return -ENOMEM;

	wdt->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(wdt->clk)) {
		dev_err(&pdev->dev, "clk not found\n");
		return PTR_ERR(wdt->clk);
	}

	ret = clk_prepare_enable(wdt->clk);
	if (ret) {
		dev_err(&pdev->dev, "clk enable failed\n");
		return ret;
	}

	if (pic32_wdt_is_win_enabled(wdt)) {
		dev_err(&pdev->dev, "windowed-clear mode is not supported.\n");
		ret = -ENODEV;
		goto out_disable_clk;
	}

	wdd->timeout = pic32_wdt_get_timeout_secs(wdt, &pdev->dev);
	if (!wdd->timeout) {
		dev_err(&pdev->dev,
			"failed to read watchdog register timeout\n");
		ret = -EINVAL;
		goto out_disable_clk;
	}

	dev_info(&pdev->dev, "timeout %d\n", wdd->timeout);

	wdd->bootstatus = pic32_wdt_bootstatus(wdt) ? WDIOF_CARDRESET : 0;

	watchdog_set_nowayout(wdd, WATCHDOG_NOWAYOUT);
	watchdog_set_drvdata(wdd, wdt);

	ret = watchdog_register_device(wdd);
	if (ret) {
		dev_err(&pdev->dev, "watchdog register failed, err %d\n", ret);
		goto out_disable_clk;
	}

	platform_set_drvdata(pdev, wdd);

	return 0;

out_disable_clk:
	clk_disable_unprepare(wdt->clk);

	return ret;
}

__attribute__((used)) static int pic32_wdt_drv_remove(struct platform_device *pdev)
{
	struct watchdog_device *wdd = platform_get_drvdata(pdev);
	struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);

	watchdog_unregister_device(wdd);
	clk_disable_unprepare(wdt->clk);

	return 0;
}

