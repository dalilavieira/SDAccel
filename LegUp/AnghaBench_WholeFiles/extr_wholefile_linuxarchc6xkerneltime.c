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

/* Variables and functions */
 int SCHED_CLOCK_SHIFT ; 
 int get_cycles () ; 
 int sched_clock_multiplier ; 

__attribute__((used)) static u64 tsc_read(struct clocksource *cs)
{
	return get_cycles();
}

u64 sched_clock(void)
{
	u64 tsc = get_cycles();

	return (tsc * sched_clock_multiplier) >> SCHED_CLOCK_SHIFT;
}

