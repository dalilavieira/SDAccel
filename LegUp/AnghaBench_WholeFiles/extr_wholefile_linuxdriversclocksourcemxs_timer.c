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
typedef  int u64 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int BM_TIMROT_TIMCTRLn_IRQ ; 
 int BM_TIMROT_TIMCTRLn_IRQ_EN ; 
 scalar_t__ HW_TIMROT_FIXED_COUNTn (int) ; 
 scalar_t__ HW_TIMROT_TIMCOUNTn (int) ; 
 scalar_t__ HW_TIMROT_TIMCTRLn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ STMP_OFFSET_REG_CLR ; 
 scalar_t__ STMP_OFFSET_REG_SET ; 
 int __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int,scalar_t__) ; 
 scalar_t__ clockevent_state_oneshot (struct clock_event_device*) ; 
 scalar_t__ mxs_timrot_base ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 scalar_t__ timrot_is_v1 () ; 

__attribute__((used)) static inline void timrot_irq_disable(void)
{
	__raw_writel(BM_TIMROT_TIMCTRLn_IRQ_EN, mxs_timrot_base +
		     HW_TIMROT_TIMCTRLn(0) + STMP_OFFSET_REG_CLR);
}

__attribute__((used)) static inline void timrot_irq_enable(void)
{
	__raw_writel(BM_TIMROT_TIMCTRLn_IRQ_EN, mxs_timrot_base +
		     HW_TIMROT_TIMCTRLn(0) + STMP_OFFSET_REG_SET);
}

__attribute__((used)) static void timrot_irq_acknowledge(void)
{
	__raw_writel(BM_TIMROT_TIMCTRLn_IRQ, mxs_timrot_base +
		     HW_TIMROT_TIMCTRLn(0) + STMP_OFFSET_REG_CLR);
}

__attribute__((used)) static u64 timrotv1_get_cycles(struct clocksource *cs)
{
	return ~((__raw_readl(mxs_timrot_base + HW_TIMROT_TIMCOUNTn(1))
			& 0xffff0000) >> 16);
}

__attribute__((used)) static int timrotv1_set_next_event(unsigned long evt,
					struct clock_event_device *dev)
{
	/* timrot decrements the count */
	__raw_writel(evt, mxs_timrot_base + HW_TIMROT_TIMCOUNTn(0));

	return 0;
}

__attribute__((used)) static int timrotv2_set_next_event(unsigned long evt,
					struct clock_event_device *dev)
{
	/* timrot decrements the count */
	__raw_writel(evt, mxs_timrot_base + HW_TIMROT_FIXED_COUNTn(0));

	return 0;
}

__attribute__((used)) static irqreturn_t mxs_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = dev_id;

	timrot_irq_acknowledge();
	evt->event_handler(evt);

	return IRQ_HANDLED;
}

__attribute__((used)) static void mxs_irq_clear(char *state)
{
	/* Disable interrupt in timer module */
	timrot_irq_disable();

	/* Set event time into the furthest future */
	if (timrot_is_v1())
		__raw_writel(0xffff, mxs_timrot_base + HW_TIMROT_TIMCOUNTn(1));
	else
		__raw_writel(0xffffffff,
			     mxs_timrot_base + HW_TIMROT_FIXED_COUNTn(1));

	/* Clear pending interrupt */
	timrot_irq_acknowledge();

#ifdef DEBUG
	pr_info("%s: changing mode to %s\n", __func__, state)
#endif /* DEBUG */
}

__attribute__((used)) static int mxs_shutdown(struct clock_event_device *evt)
{
	mxs_irq_clear("shutdown");

	return 0;
}

__attribute__((used)) static int mxs_set_oneshot(struct clock_event_device *evt)
{
	if (clockevent_state_oneshot(evt))
		mxs_irq_clear("oneshot");
	timrot_irq_enable();
	return 0;
}

