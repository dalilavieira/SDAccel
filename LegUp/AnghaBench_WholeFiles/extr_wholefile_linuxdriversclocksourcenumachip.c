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
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  cycles_t ;

/* Variables and functions */
 scalar_t__ NUMACHIP2_TIMER_DEADLINE ; 
 int /*<<< orphan*/  NUMACHIP2_TIMER_NOW ; 
 int /*<<< orphan*/  numachip2_ced ; 
 int /*<<< orphan*/  numachip2_read64_lcsr (int /*<<< orphan*/ ) ; 
 scalar_t__ numachip2_timer () ; 
 int /*<<< orphan*/  numachip2_write64_lcsr (scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 struct clock_event_device* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static cycles_t numachip2_timer_read(struct clocksource *cs)
{
	return numachip2_read64_lcsr(NUMACHIP2_TIMER_NOW);
}

__attribute__((used)) static int numachip2_set_next_event(unsigned long delta, struct clock_event_device *ced)
{
	numachip2_write64_lcsr(NUMACHIP2_TIMER_DEADLINE + numachip2_timer(),
		delta);
	return 0;
}

__attribute__((used)) static void numachip_timer_interrupt(void)
{
	struct clock_event_device *ced = this_cpu_ptr(&numachip2_ced);

	ced->event_handler(ced);
}

