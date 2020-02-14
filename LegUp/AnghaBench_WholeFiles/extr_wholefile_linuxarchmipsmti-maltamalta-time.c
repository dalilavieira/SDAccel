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

/* Variables and functions */
 unsigned int MIPS_CPU_IRQ_BASE ; 
 unsigned int MSC01E_INT_BASE ; 
 unsigned int MSC01E_INT_CPUCTR ; 
 unsigned int cp0_compare_irq ; 
 scalar_t__ cpu_has_veic ; 
 int /*<<< orphan*/  do_IRQ (unsigned int) ; 
 unsigned int gic_get_c0_compare_int () ; 
 unsigned int mips_cpu_perf_irq ; 
 unsigned int mips_cpu_timer_irq ; 
 scalar_t__ mips_gic_present () ; 
 int /*<<< orphan*/  set_vi_handler (unsigned int,void (*) ()) ; 

__attribute__((used)) static void mips_timer_dispatch(void)
{
	do_IRQ(mips_cpu_timer_irq);
}

__attribute__((used)) static void mips_perf_dispatch(void)
{
	do_IRQ(mips_cpu_perf_irq);
}

__attribute__((used)) static unsigned int freqround(unsigned int freq, unsigned int amount)
{
	freq += amount;
	freq -= freq % (amount*2);
	return freq;
}

unsigned int get_c0_compare_int(void)
{
	if (cpu_has_veic) {
		set_vi_handler(MSC01E_INT_CPUCTR, mips_timer_dispatch);
		mips_cpu_timer_irq = MSC01E_INT_BASE + MSC01E_INT_CPUCTR;
	} else if (mips_gic_present()) {
		mips_cpu_timer_irq = gic_get_c0_compare_int();
	} else {
		mips_cpu_timer_irq = MIPS_CPU_IRQ_BASE + cp0_compare_irq;
	}

	return mips_cpu_timer_irq;
}

