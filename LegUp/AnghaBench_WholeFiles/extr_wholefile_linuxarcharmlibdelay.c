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
typedef  int u64 ;
typedef  int u32 ;
typedef  unsigned long cycles_t ;
struct TYPE_4__ {unsigned long long ticks_per_jiffy; } ;
struct TYPE_3__ {unsigned long (* read_current_timer ) () ;} ;

/* Variables and functions */
 int ENXIO ; 
 unsigned long UDELAY_MULT ; 
 unsigned long long UDELAY_SHIFT ; 
 TYPE_2__ arm_delay_ops ; 
 int /*<<< orphan*/  cpu_relax () ; 
 TYPE_1__* delay_timer ; 
 unsigned long get_cycles () ; 
 unsigned long stub1 () ; 

int read_current_timer(unsigned long *timer_val)
{
	if (!delay_timer)
		return -ENXIO;

	*timer_val = delay_timer->read_current_timer();
	return 0;
}

__attribute__((used)) static inline u64 cyc_to_ns(u64 cyc, u32 mult, u32 shift)
{
	return (cyc * mult) >> shift;
}

__attribute__((used)) static void __timer_delay(unsigned long cycles)
{
	cycles_t start = get_cycles();

	while ((get_cycles() - start) < cycles)
		cpu_relax();
}

__attribute__((used)) static void __timer_const_udelay(unsigned long xloops)
{
	unsigned long long loops = xloops;
	loops *= arm_delay_ops.ticks_per_jiffy;
	__timer_delay(loops >> UDELAY_SHIFT);
}

__attribute__((used)) static void __timer_udelay(unsigned long usecs)
{
	__timer_const_udelay(usecs * UDELAY_MULT);
}

