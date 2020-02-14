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
struct watchdog_device {unsigned int timeout; int bootstatus; int /*<<< orphan*/  status; int /*<<< orphan*/  max_timeout; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (unsigned int) ; 
 int PTR_ERR (unsigned int) ; 
 int /*<<< orphan*/  SYSC_RSTSTAT ; 
 unsigned int TIMER_REG_TMR1CTL ; 
 unsigned int TIMER_REG_TMR1LOAD ; 
 unsigned int TIMER_REG_TMRSTAT ; 
 int TMR1CTL_ENABLE ; 
 int TMR1CTL_PRESCALE_SHIFT ; 
 int TMR1CTL_RESTART ; 
 int WDIOF_CARDRESET ; 
 int /*<<< orphan*/  WDOG_HW_RUNNING ; 
 int WDT_RST_CAUSE ; 
 unsigned int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 unsigned int devm_reset_control_get_exclusive (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int devm_watchdog_register_device (int /*<<< orphan*/ *,struct watchdog_device*) ; 
 int ioread32 (unsigned int) ; 
 int /*<<< orphan*/  iowrite32 (int,unsigned int) ; 
 unsigned int mt7621_wdt_base ; 
 struct watchdog_device mt7621_wdt_dev ; 
 unsigned int mt7621_wdt_reset ; 
 int /*<<< orphan*/  nowayout ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reset_control_deassert (unsigned int) ; 
 int rt_sysc_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void rt_wdt_w32(unsigned reg, u32 val)
{
	iowrite32(val, mt7621_wdt_base + reg);
}

__attribute__((used)) static inline u32 rt_wdt_r32(unsigned reg)
{
	return ioread32(mt7621_wdt_base + reg);
}

__attribute__((used)) static int mt7621_wdt_ping(struct watchdog_device *w)
{
	rt_wdt_w32(TIMER_REG_TMRSTAT, TMR1CTL_RESTART);

	return 0;
}

__attribute__((used)) static int mt7621_wdt_set_timeout(struct watchdog_device *w, unsigned int t)
{
	w->timeout = t;
	rt_wdt_w32(TIMER_REG_TMR1LOAD, t * 1000);
	mt7621_wdt_ping(w);

	return 0;
}

__attribute__((used)) static int mt7621_wdt_start(struct watchdog_device *w)
{
	u32 t;

	/* set the prescaler to 1ms == 1000us */
	rt_wdt_w32(TIMER_REG_TMR1CTL, 1000 << TMR1CTL_PRESCALE_SHIFT);

	mt7621_wdt_set_timeout(w, w->timeout);

	t = rt_wdt_r32(TIMER_REG_TMR1CTL);
	t |= TMR1CTL_ENABLE;
	rt_wdt_w32(TIMER_REG_TMR1CTL, t);

	return 0;
}

__attribute__((used)) static int mt7621_wdt_stop(struct watchdog_device *w)
{
	u32 t;

	mt7621_wdt_ping(w);

	t = rt_wdt_r32(TIMER_REG_TMR1CTL);
	t &= ~TMR1CTL_ENABLE;
	rt_wdt_w32(TIMER_REG_TMR1CTL, t);

	return 0;
}

__attribute__((used)) static int mt7621_wdt_bootcause(void)
{
	if (rt_sysc_r32(SYSC_RSTSTAT) & WDT_RST_CAUSE)
		return WDIOF_CARDRESET;

	return 0;
}

__attribute__((used)) static int mt7621_wdt_is_running(struct watchdog_device *w)
{
	return !!(rt_wdt_r32(TIMER_REG_TMR1CTL) & TMR1CTL_ENABLE);
}

__attribute__((used)) static int mt7621_wdt_probe(struct platform_device *pdev)
{
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	mt7621_wdt_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mt7621_wdt_base))
		return PTR_ERR(mt7621_wdt_base);

	mt7621_wdt_reset = devm_reset_control_get_exclusive(&pdev->dev, NULL);
	if (!IS_ERR(mt7621_wdt_reset))
		reset_control_deassert(mt7621_wdt_reset);

	mt7621_wdt_dev.bootstatus = mt7621_wdt_bootcause();

	watchdog_init_timeout(&mt7621_wdt_dev, mt7621_wdt_dev.max_timeout,
			      &pdev->dev);
	watchdog_set_nowayout(&mt7621_wdt_dev, nowayout);
	if (mt7621_wdt_is_running(&mt7621_wdt_dev)) {
		/*
		 * Make sure to apply timeout from watchdog core, taking
		 * the prescaler of this driver here into account (the
		 * boot loader might be using a different prescaler).
		 *
		 * To avoid spurious resets because of different scaling,
		 * we first disable the watchdog, set the new prescaler
		 * and timeout, and then re-enable the watchdog.
		 */
		mt7621_wdt_stop(&mt7621_wdt_dev);
		mt7621_wdt_start(&mt7621_wdt_dev);
		set_bit(WDOG_HW_RUNNING, &mt7621_wdt_dev.status);
	}

	return devm_watchdog_register_device(&pdev->dev, &mt7621_wdt_dev);
}

__attribute__((used)) static void mt7621_wdt_shutdown(struct platform_device *pdev)
{
	mt7621_wdt_stop(&mt7621_wdt_dev);
}

