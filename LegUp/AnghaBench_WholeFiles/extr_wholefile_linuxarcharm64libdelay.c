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
typedef  unsigned long const cycles_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARCH_TIMER_EVT_STREAM_PERIOD_US ; 
 unsigned long HZ ; 
 unsigned long USECS_TO_CYCLES (int /*<<< orphan*/ ) ; 
 scalar_t__ arch_timer_evtstrm_available () ; 
 int /*<<< orphan*/  cpu_relax () ; 
 unsigned long const get_cycles () ; 
 unsigned long loops_per_jiffy ; 
 int /*<<< orphan*/  wfe () ; 

__attribute__((used)) static inline unsigned long xloops_to_cycles(unsigned long xloops)
{
	return (xloops * loops_per_jiffy * HZ) >> 32;
}

void __delay(unsigned long cycles)
{
	cycles_t start = get_cycles();

	if (arch_timer_evtstrm_available()) {
		const cycles_t timer_evt_period =
			USECS_TO_CYCLES(ARCH_TIMER_EVT_STREAM_PERIOD_US);

		while ((get_cycles() - start + timer_evt_period) < cycles)
			wfe();
	}

	while ((get_cycles() - start) < cycles)
		cpu_relax();
}

inline void __const_udelay(unsigned long xloops)
{
	__delay(xloops_to_cycles(xloops));
}

void __udelay(unsigned long usecs)
{
	__const_udelay(usecs * 0x10C7UL); /* 2**32 / 1000000 (rounded up) */
}

void __ndelay(unsigned long nsecs)
{
	__const_udelay(nsecs * 0x5UL); /* 2**32 / 1000000000 (rounded up) */
}

