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
typedef  int u64 ;
typedef  int u32 ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int hz_period; scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned long PRD12 ; 
 unsigned long PRD34 ; 
 unsigned long TCR ; 
 int TCR_ENAMODE_MASK ; 
 int TCR_ENAMODE_ONESHOT_MASK ; 
 int TCR_ENAMODE_PERIODIC_MASK ; 
 unsigned long TIM12 ; 
 unsigned long TIM34 ; 
 int /*<<< orphan*/  __iowmb () ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 TYPE_1__ timer ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline u32 keystone_timer_readl(unsigned long rg)
{
	return readl_relaxed(timer.base + rg);
}

__attribute__((used)) static inline void keystone_timer_writel(u32 val, unsigned long rg)
{
	writel_relaxed(val, timer.base + rg);
}

__attribute__((used)) static inline void keystone_timer_barrier(void)
{
	__iowmb();
}

__attribute__((used)) static int keystone_timer_config(u64 period, int mask)
{
	u32 tcr;
	u32 off;

	tcr = keystone_timer_readl(TCR);
	off = tcr & ~(TCR_ENAMODE_MASK);

	/* set enable mode */
	tcr |= mask;

	/* disable timer */
	keystone_timer_writel(off, TCR);
	/* here we have to be sure the timer has been disabled */
	keystone_timer_barrier();

	/* reset counter to zero, set new period */
	keystone_timer_writel(0, TIM12);
	keystone_timer_writel(0, TIM34);
	keystone_timer_writel(period & 0xffffffff, PRD12);
	keystone_timer_writel(period >> 32, PRD34);

	/*
	 * enable timer
	 * here we have to be sure that CNTLO, CNTHI, PRDLO, PRDHI registers
	 * have been written.
	 */
	keystone_timer_barrier();
	keystone_timer_writel(tcr, TCR);
	return 0;
}

__attribute__((used)) static void keystone_timer_disable(void)
{
	u32 tcr;

	tcr = keystone_timer_readl(TCR);

	/* disable timer */
	tcr &= ~(TCR_ENAMODE_MASK);
	keystone_timer_writel(tcr, TCR);
}

__attribute__((used)) static irqreturn_t keystone_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = dev_id;

	evt->event_handler(evt);
	return IRQ_HANDLED;
}

__attribute__((used)) static int keystone_set_next_event(unsigned long cycles,
				  struct clock_event_device *evt)
{
	return keystone_timer_config(cycles, TCR_ENAMODE_ONESHOT_MASK);
}

__attribute__((used)) static int keystone_shutdown(struct clock_event_device *evt)
{
	keystone_timer_disable();
	return 0;
}

__attribute__((used)) static int keystone_set_periodic(struct clock_event_device *evt)
{
	keystone_timer_config(timer.hz_period, TCR_ENAMODE_PERIODIC_MASK);
	return 0;
}

