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
typedef  unsigned long u64 ;
struct clocksource {int dummy; } ;

/* Variables and functions */
 unsigned long long CYC2NS_SCALE ; 
 unsigned long long CYC2NS_SCALE_FACTOR ; 
 int /*<<< orphan*/  DTCN0 ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u64 cf_dt_get_cycles(struct clocksource *cs)
{
	return __raw_readl(DTCN0);
}

__attribute__((used)) static unsigned long long cycles2ns(unsigned long cycl)
{
	return (unsigned long long) ((unsigned long long)cycl *
			CYC2NS_SCALE) >> CYC2NS_SCALE_FACTOR;
}

unsigned long long sched_clock(void)
{
	unsigned long cycl = __raw_readl(DTCN0);

	return cycles2ns(cycl);
}

