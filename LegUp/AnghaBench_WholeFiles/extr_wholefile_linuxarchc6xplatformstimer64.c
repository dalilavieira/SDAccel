#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u32 ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  prdlo; int /*<<< orphan*/  tcr; int /*<<< orphan*/  tgcr; int /*<<< orphan*/  cntlo; } ;

/* Variables and functions */
 int /*<<< orphan*/  DSCR_DEVSTATE_DISABLED ; 
 int /*<<< orphan*/  DSCR_DEVSTATE_ENABLED ; 
 unsigned long HZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned long TCR_CLKSRCLO ; 
 unsigned long TCR_ENAMODELO_MASK ; 
 unsigned long TCR_PWIDLO_MASK ; 
 unsigned long TGCR_TIMLORS ; 
 unsigned long TGCR_TIMMODE_MASK ; 
 unsigned long TGCR_TIMMODE_UD32 ; 
 unsigned long TIMER64_MODE_DISABLED ; 
 unsigned long TIMER64_MODE_ONE_SHOT ; 
 unsigned long TIMER64_MODE_PERIODIC ; 
 unsigned long TIMER64_RATE ; 
 int /*<<< orphan*/  dscr_set_devstate (scalar_t__,int /*<<< orphan*/ ) ; 
 unsigned long soc_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  soc_writel (unsigned long,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 struct clock_event_device t64_clockevent_device ; 
 TYPE_1__* timer ; 
 scalar_t__ timer64_devstate_id ; 
 unsigned long timer64_mode ; 

__attribute__((used)) static void timer64_config(unsigned long period)
{
	u32 tcr = soc_readl(&timer->tcr) & ~TCR_ENAMODELO_MASK;

	soc_writel(tcr, &timer->tcr);
	soc_writel(period - 1, &timer->prdlo);
	soc_writel(0, &timer->cntlo);
	tcr |= timer64_mode;
	soc_writel(tcr, &timer->tcr);
}

__attribute__((used)) static void timer64_enable(void)
{
	u32 val;

	if (timer64_devstate_id >= 0)
		dscr_set_devstate(timer64_devstate_id, DSCR_DEVSTATE_ENABLED);

	/* disable timer, reset count */
	soc_writel(soc_readl(&timer->tcr) & ~TCR_ENAMODELO_MASK, &timer->tcr);
	soc_writel(0, &timer->prdlo);

	/* use internal clock and 1 cycle pulse width */
	val = soc_readl(&timer->tcr);
	soc_writel(val & ~(TCR_CLKSRCLO | TCR_PWIDLO_MASK), &timer->tcr);

	/* dual 32-bit unchained mode */
	val = soc_readl(&timer->tgcr) & ~TGCR_TIMMODE_MASK;
	soc_writel(val, &timer->tgcr);
	soc_writel(val | (TGCR_TIMLORS | TGCR_TIMMODE_UD32), &timer->tgcr);
}

__attribute__((used)) static void timer64_disable(void)
{
	/* disable timer, reset count */
	soc_writel(soc_readl(&timer->tcr) & ~TCR_ENAMODELO_MASK, &timer->tcr);
	soc_writel(0, &timer->prdlo);

	if (timer64_devstate_id >= 0)
		dscr_set_devstate(timer64_devstate_id, DSCR_DEVSTATE_DISABLED);
}

__attribute__((used)) static int next_event(unsigned long delta,
		      struct clock_event_device *evt)
{
	timer64_config(delta);
	return 0;
}

__attribute__((used)) static int set_periodic(struct clock_event_device *evt)
{
	timer64_enable();
	timer64_mode = TIMER64_MODE_PERIODIC;
	timer64_config(TIMER64_RATE / HZ);
	return 0;
}

__attribute__((used)) static int set_oneshot(struct clock_event_device *evt)
{
	timer64_enable();
	timer64_mode = TIMER64_MODE_ONE_SHOT;
	return 0;
}

__attribute__((used)) static int shutdown(struct clock_event_device *evt)
{
	timer64_mode = TIMER64_MODE_DISABLED;
	timer64_disable();
	return 0;
}

__attribute__((used)) static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *cd = &t64_clockevent_device;

	cd->event_handler(cd);

	return IRQ_HANDLED;
}

