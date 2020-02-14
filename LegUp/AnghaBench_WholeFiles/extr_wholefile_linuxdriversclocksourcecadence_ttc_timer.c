#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  unsigned long u32 ;
struct TYPE_4__ {int /*<<< orphan*/  (* event_handler ) (TYPE_2__*) ;} ;
struct ttc_timer {scalar_t__ base_addr; } ;
struct ttc_timer_clockevent {TYPE_2__ ce; struct ttc_timer ttc; } ;
struct clocksource {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {struct ttc_timer ttc; } ;

/* Variables and functions */
 unsigned long CNT_CNTRL_RESET ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned long TTC_CNT_CNTRL_DISABLE_MASK ; 
 scalar_t__ TTC_CNT_CNTRL_OFFSET ; 
 scalar_t__ TTC_COUNT_VAL_OFFSET ; 
 scalar_t__ TTC_INTR_VAL_OFFSET ; 
 scalar_t__ TTC_ISR_OFFSET ; 
 unsigned long readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 TYPE_1__* to_ttc_timer_clksrc (struct clocksource*) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,scalar_t__) ; 

__attribute__((used)) static void ttc_set_interval(struct ttc_timer *timer,
					unsigned long cycles)
{
	u32 ctrl_reg;

	/* Disable the counter, set the counter value  and re-enable counter */
	ctrl_reg = readl_relaxed(timer->base_addr + TTC_CNT_CNTRL_OFFSET);
	ctrl_reg |= TTC_CNT_CNTRL_DISABLE_MASK;
	writel_relaxed(ctrl_reg, timer->base_addr + TTC_CNT_CNTRL_OFFSET);

	writel_relaxed(cycles, timer->base_addr + TTC_INTR_VAL_OFFSET);

	/*
	 * Reset the counter (0x10) so that it starts from 0, one-shot
	 * mode makes this needed for timing to be right.
	 */
	ctrl_reg |= CNT_CNTRL_RESET;
	ctrl_reg &= ~TTC_CNT_CNTRL_DISABLE_MASK;
	writel_relaxed(ctrl_reg, timer->base_addr + TTC_CNT_CNTRL_OFFSET);
}

__attribute__((used)) static irqreturn_t ttc_clock_event_interrupt(int irq, void *dev_id)
{
	struct ttc_timer_clockevent *ttce = dev_id;
	struct ttc_timer *timer = &ttce->ttc;

	/* Acknowledge the interrupt and call event handler */
	readl_relaxed(timer->base_addr + TTC_ISR_OFFSET);

	ttce->ce.event_handler(&ttce->ce);

	return IRQ_HANDLED;
}

__attribute__((used)) static u64 __ttc_clocksource_read(struct clocksource *cs)
{
	struct ttc_timer *timer = &to_ttc_timer_clksrc(cs)->ttc;

	return (u64)readl_relaxed(timer->base_addr +
				TTC_COUNT_VAL_OFFSET);
}

