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
typedef  int /*<<< orphan*/  u64 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  enable; int /*<<< orphan*/  match; int /*<<< orphan*/  clear; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int TIMER_ENABLE ; 
 unsigned long long __vmgettime () ; 
 int /*<<< orphan*/  cpu_relax () ; 
 unsigned long fudgefactor ; 
 struct clock_event_device hexagon_clockevent_dev ; 
 int /*<<< orphan*/  iowrite32 (int,int /*<<< orphan*/ *) ; 
 unsigned long pcycle_freq_mhz ; 
 TYPE_1__* rtos_timer ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

__attribute__((used)) static u64 timer_get_cycles(struct clocksource *cs)
{
	return (u64) __vmgettime();
}

__attribute__((used)) static int set_next_event(unsigned long delta, struct clock_event_device *evt)
{
	/*  Assuming the timer will be disabled when we enter here.  */

	iowrite32(1, &rtos_timer->clear);
	iowrite32(0, &rtos_timer->clear);

	iowrite32(delta, &rtos_timer->match);
	iowrite32(1 << TIMER_ENABLE, &rtos_timer->enable);
	return 0;
}

__attribute__((used)) static irqreturn_t timer_interrupt(int irq, void *devid)
{
	struct clock_event_device *ce_dev = &hexagon_clockevent_dev;

	iowrite32(0, &rtos_timer->enable);
	ce_dev->event_handler(ce_dev);

	return IRQ_HANDLED;
}

void __udelay(unsigned long usecs)
{
	unsigned long long start = __vmgettime();
	unsigned long long finish = (pcycle_freq_mhz * usecs) - fudgefactor;

	while ((__vmgettime() - start) < finish)
		cpu_relax(); /*  not sure how this improves readability  */
}

