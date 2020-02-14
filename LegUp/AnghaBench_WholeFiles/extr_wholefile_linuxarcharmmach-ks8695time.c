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
typedef  unsigned long u32 ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned long DIV_ROUND_CLOSEST (unsigned long,int) ; 
 int HZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned long KS8695_CLOCK_RATE ; 
 scalar_t__ KS8695_T1PD ; 
 scalar_t__ KS8695_T1TC ; 
 scalar_t__ KS8695_TMCON ; 
 scalar_t__ KS8695_TMR_VA ; 
 unsigned long TMCON_T0EN ; 
 unsigned long TMCON_T1EN ; 
 struct clock_event_device clockevent_ks8695 ; 
 int /*<<< orphan*/  clockevents_config_and_register (struct clock_event_device*,unsigned long,int,int) ; 
 unsigned long readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,scalar_t__) ; 

__attribute__((used)) static int ks8695_set_periodic(struct clock_event_device *evt)
{
	u32 rate = DIV_ROUND_CLOSEST(KS8695_CLOCK_RATE, HZ);
	u32 half = DIV_ROUND_CLOSEST(rate, 2);
	u32 tmcon;

	/* Disable timer 1 */
	tmcon = readl_relaxed(KS8695_TMR_VA + KS8695_TMCON);
	tmcon &= ~TMCON_T1EN;
	writel_relaxed(tmcon, KS8695_TMR_VA + KS8695_TMCON);

	/* Both registers need to count down */
	writel_relaxed(half, KS8695_TMR_VA + KS8695_T1TC);
	writel_relaxed(half, KS8695_TMR_VA + KS8695_T1PD);

	/* Re-enable timer1 */
	tmcon |= TMCON_T1EN;
	writel_relaxed(tmcon, KS8695_TMR_VA + KS8695_TMCON);
	return 0;
}

__attribute__((used)) static int ks8695_set_next_event(unsigned long cycles,
				 struct clock_event_device *evt)

{
	u32 half = DIV_ROUND_CLOSEST(cycles, 2);
	u32 tmcon;

	/* Disable timer 1 */
	tmcon = readl_relaxed(KS8695_TMR_VA + KS8695_TMCON);
	tmcon &= ~TMCON_T1EN;
	writel_relaxed(tmcon, KS8695_TMR_VA + KS8695_TMCON);

	/* Both registers need to count down */
	writel_relaxed(half, KS8695_TMR_VA + KS8695_T1TC);
	writel_relaxed(half, KS8695_TMR_VA + KS8695_T1PD);

	/* Re-enable timer1 */
	tmcon |= TMCON_T1EN;
	writel_relaxed(tmcon, KS8695_TMR_VA + KS8695_TMCON);

	return 0;
}

__attribute__((used)) static irqreturn_t ks8695_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &clockevent_ks8695;

	evt->event_handler(evt);
	return IRQ_HANDLED;
}

__attribute__((used)) static void ks8695_timer_setup(void)
{
	unsigned long tmcon;

	/* Disable timer 0 and 1 */
	tmcon = readl_relaxed(KS8695_TMR_VA + KS8695_TMCON);
	tmcon &= ~TMCON_T0EN;
	tmcon &= ~TMCON_T1EN;
	writel_relaxed(tmcon, KS8695_TMR_VA + KS8695_TMCON);

	/*
	 * Use timer 1 to fire IRQs on the timeline, minimum 2 cycles
	 * (one on each counter) maximum 2*2^32, but the API will only
	 * accept up to a 32bit full word (0xFFFFFFFFU).
	 */
	clockevents_config_and_register(&clockevent_ks8695,
					KS8695_CLOCK_RATE, 2,
					0xFFFFFFFFU);
}

