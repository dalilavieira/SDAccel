#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct clock_event_device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {unsigned long freq; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* event_handler ) (TYPE_1__*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int TIMER1_EN ; 
 scalar_t__ TIMER1_RELOAD ; 
 int TIMER1_RELOAD_EN ; 
 scalar_t__ TIMER1_VAL ; 
 scalar_t__ TIMER_CTRL ; 
 int /*<<< orphan*/  atomic_io_modify (scalar_t__,int,int) ; 
 TYPE_1__ orion_clkevt ; 
 TYPE_2__ orion_delay_timer ; 
 int /*<<< orphan*/  register_current_timer_delay (TYPE_2__*) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*) ; 
 int ticks_per_jiffy ; 
 scalar_t__ timer_base ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void orion_delay_timer_init(unsigned long rate)
{
	orion_delay_timer.freq = rate;
	register_current_timer_delay(&orion_delay_timer);
}

__attribute__((used)) static int orion_clkevt_next_event(unsigned long delta,
				   struct clock_event_device *dev)
{
	/* setup and enable one-shot timer */
	writel(delta, timer_base + TIMER1_VAL);
	atomic_io_modify(timer_base + TIMER_CTRL,
		TIMER1_RELOAD_EN | TIMER1_EN, TIMER1_EN);

	return 0;
}

__attribute__((used)) static int orion_clkevt_shutdown(struct clock_event_device *dev)
{
	/* disable timer */
	atomic_io_modify(timer_base + TIMER_CTRL,
			 TIMER1_RELOAD_EN | TIMER1_EN, 0);
	return 0;
}

__attribute__((used)) static int orion_clkevt_set_periodic(struct clock_event_device *dev)
{
	/* setup and enable periodic timer at 1/HZ intervals */
	writel(ticks_per_jiffy - 1, timer_base + TIMER1_RELOAD);
	writel(ticks_per_jiffy - 1, timer_base + TIMER1_VAL);
	atomic_io_modify(timer_base + TIMER_CTRL,
			 TIMER1_RELOAD_EN | TIMER1_EN,
			 TIMER1_RELOAD_EN | TIMER1_EN);
	return 0;
}

__attribute__((used)) static irqreturn_t orion_clkevt_irq_handler(int irq, void *dev_id)
{
	orion_clkevt.event_handler(&orion_clkevt);
	return IRQ_HANDLED;
}

