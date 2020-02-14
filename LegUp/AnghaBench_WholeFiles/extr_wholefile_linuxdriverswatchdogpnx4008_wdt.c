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
struct watchdog_device {int timeout; int /*<<< orphan*/ * parent; int /*<<< orphan*/  bootstatus; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int COUNT_ENAB ; 
 int DEBUG_EN ; 
 int EXT_MATCH0 ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MATCH_INT ; 
 int MATCH_OUTPUT_HIGH ; 
 int M_RES1 ; 
 int M_RES2 ; 
 int NOTIFY_DONE ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned long REBOOT_HARD ; 
 unsigned long REBOOT_SOFT ; 
 int RESET_COUNT ; 
 int RESET_COUNT0 ; 
 int RESFRC1 ; 
 int RESFRC2 ; 
 int STOP_COUNT0 ; 
 int /*<<< orphan*/  WDIOF_CARDRESET ; 
 int WDOG_COUNTER_RATE ; 
 int WDOG_RESET ; 
 int /*<<< orphan*/  WDTIM_COUNTER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_CTRL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_EMR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_INT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_MATCH0 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_MCTRL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_PULSE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WDTIM_RES (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int /*<<< orphan*/  devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 int /*<<< orphan*/  heartbeat ; 
 int /*<<< orphan*/  io_lock ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  nowayout ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct watchdog_device pnx4008_wdd ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_set_restart_priority (struct watchdog_device*,int) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  wdt_base ; 
 int /*<<< orphan*/  wdt_clk ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pnx4008_wdt_start(struct watchdog_device *wdd)
{
	spin_lock(&io_lock);

	/* stop counter, initiate counter reset */
	writel(RESET_COUNT, WDTIM_CTRL(wdt_base));
	/*wait for reset to complete. 100% guarantee event */
	while (readl(WDTIM_COUNTER(wdt_base)))
		cpu_relax();
	/* internal and external reset, stop after that */
	writel(M_RES2 | STOP_COUNT0 | RESET_COUNT0, WDTIM_MCTRL(wdt_base));
	/* configure match output */
	writel(MATCH_OUTPUT_HIGH, WDTIM_EMR(wdt_base));
	/* clear interrupt, just in case */
	writel(MATCH_INT, WDTIM_INT(wdt_base));
	/* the longest pulse period 65541/(13*10^6) seconds ~ 5 ms. */
	writel(0xFFFF, WDTIM_PULSE(wdt_base));
	writel(wdd->timeout * WDOG_COUNTER_RATE, WDTIM_MATCH0(wdt_base));
	/*enable counter, stop when debugger active */
	writel(COUNT_ENAB | DEBUG_EN, WDTIM_CTRL(wdt_base));

	spin_unlock(&io_lock);
	return 0;
}

__attribute__((used)) static int pnx4008_wdt_stop(struct watchdog_device *wdd)
{
	spin_lock(&io_lock);

	writel(0, WDTIM_CTRL(wdt_base));	/*stop counter */

	spin_unlock(&io_lock);
	return 0;
}

__attribute__((used)) static int pnx4008_wdt_set_timeout(struct watchdog_device *wdd,
				    unsigned int new_timeout)
{
	wdd->timeout = new_timeout;
	return 0;
}

__attribute__((used)) static int pnx4008_restart_handler(struct watchdog_device *wdd,
				   unsigned long mode, void *cmd)
{
	const char *boot_cmd = cmd;

	/*
	 * Verify if a "cmd" passed from the userspace program rebooting
	 * the system; if available, handle it.
	 * - For details, see the 'reboot' syscall in kernel/reboot.c
	 * - If the received "cmd" is not supported, use the default mode.
	 */
	if (boot_cmd) {
		if (boot_cmd[0] == 'h')
			mode = REBOOT_HARD;
		else if (boot_cmd[0] == 's')
			mode = REBOOT_SOFT;
	}

	if (mode == REBOOT_SOFT) {
		/* Force match output active */
		writel(EXT_MATCH0, WDTIM_EMR(wdt_base));
		/* Internal reset on match output (RESOUT_N not asserted) */
		writel(M_RES1, WDTIM_MCTRL(wdt_base));
	} else {
		/* Instant assert of RESETOUT_N with pulse length 1mS */
		writel(13000, WDTIM_PULSE(wdt_base));
		writel(M_RES2 | RESFRC1 | RESFRC2, WDTIM_MCTRL(wdt_base));
	}

	/* Wait for watchdog to reset system */
	mdelay(1000);

	return NOTIFY_DONE;
}

__attribute__((used)) static int pnx4008_wdt_probe(struct platform_device *pdev)
{
	struct resource *r;
	int ret = 0;

	watchdog_init_timeout(&pnx4008_wdd, heartbeat, &pdev->dev);

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	wdt_base = devm_ioremap_resource(&pdev->dev, r);
	if (IS_ERR(wdt_base))
		return PTR_ERR(wdt_base);

	wdt_clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(wdt_clk))
		return PTR_ERR(wdt_clk);

	ret = clk_prepare_enable(wdt_clk);
	if (ret)
		return ret;

	pnx4008_wdd.bootstatus = (readl(WDTIM_RES(wdt_base)) & WDOG_RESET) ?
			WDIOF_CARDRESET : 0;
	pnx4008_wdd.parent = &pdev->dev;
	watchdog_set_nowayout(&pnx4008_wdd, nowayout);
	watchdog_set_restart_priority(&pnx4008_wdd, 128);

	pnx4008_wdt_stop(&pnx4008_wdd);	/* disable for now */

	ret = watchdog_register_device(&pnx4008_wdd);
	if (ret < 0) {
		dev_err(&pdev->dev, "cannot register watchdog device\n");
		goto disable_clk;
	}

	dev_info(&pdev->dev, "heartbeat %d sec\n", pnx4008_wdd.timeout);

	return 0;

disable_clk:
	clk_disable_unprepare(wdt_clk);
	return ret;
}

__attribute__((used)) static int pnx4008_wdt_remove(struct platform_device *pdev)
{
	watchdog_unregister_device(&pnx4008_wdd);

	clk_disable_unprepare(wdt_clk);

	return 0;
}

