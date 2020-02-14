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
typedef  unsigned long long u64 ;

/* Variables and functions */
 unsigned long MAX_UDELAY_US ; 
 unsigned long NDELAY_MULT ; 
 unsigned long long NDELAY_SHIFT ; 
 unsigned long UDELAY_MULT ; 
 unsigned long UDELAY_SHIFT ; 
 int /*<<< orphan*/  cpu_relax () ; 
 unsigned long long get_cycles () ; 
 unsigned long lpj_fine ; 
 unsigned long long riscv_timebase ; 
 scalar_t__ unlikely (int) ; 

void __delay(unsigned long cycles)
{
	u64 t0 = get_cycles();

	while ((unsigned long)(get_cycles() - t0) < cycles)
		cpu_relax();
}

void udelay(unsigned long usecs)
{
	unsigned long ucycles = usecs * lpj_fine * UDELAY_MULT;

	if (unlikely(usecs > MAX_UDELAY_US)) {
		__delay((u64)usecs * riscv_timebase / 1000000ULL);
		return;
	}

	__delay(ucycles >> UDELAY_SHIFT);
}

void ndelay(unsigned long nsecs)
{
	/*
	 * This doesn't bother checking for overflow, as it won't happen (it's
	 * an hour) of delay.
	 */
	unsigned long long ncycles = nsecs * lpj_fine * NDELAY_MULT;
	__delay(ncycles >> NDELAY_SHIFT);
}

