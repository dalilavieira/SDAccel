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
struct slice_data {int* level_to_irq; } ;
typedef  unsigned long hubreg_t ;
typedef  size_t cpuid_t ;
struct TYPE_2__ {struct slice_data* data; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOCAL_HUB_CLR_INTR (int) ; 
 unsigned long LOCAL_HUB_L (int) ; 
 int PI_INT_MASK0_A ; 
 int PI_INT_MASK0_B ; 
 int PI_INT_MASK1_A ; 
 int PI_INT_MASK1_B ; 
 int PI_INT_PEND0 ; 
 int PI_INT_PEND1 ; 
 TYPE_1__* cpu_data ; 
 scalar_t__ cputoslice (size_t) ; 
 int /*<<< orphan*/  do_IRQ (int) ; 
 int /*<<< orphan*/  panic (char*,size_t) ; 
 size_t smp_processor_id () ; 

__attribute__((used)) static int ms1bit(unsigned long x)
{
	int b = 0, s;

	s = 16; if (x >> 16 == 0) s = 0; b += s; x >>= s;
	s =  8; if (x >>  8 == 0) s = 0; b += s; x >>= s;
	s =  4; if (x >>  4 == 0) s = 0; b += s; x >>= s;
	s =  2; if (x >>  2 == 0) s = 0; b += s; x >>= s;
	s =  1; if (x >>  1 == 0) s = 0; b += s;

	return b;
}

__attribute__((used)) static void ip27_do_irq_mask0(void)
{
	int irq, swlevel;
	hubreg_t pend0, mask0;
	cpuid_t cpu = smp_processor_id();
	int pi_int_mask0 =
		(cputoslice(cpu) == 0) ?  PI_INT_MASK0_A : PI_INT_MASK0_B;

	/* copied from Irix intpend0() */
	pend0 = LOCAL_HUB_L(PI_INT_PEND0);
	mask0 = LOCAL_HUB_L(pi_int_mask0);

	pend0 &= mask0;		/* Pick intrs we should look at */
	if (!pend0)
		return;

	swlevel = ms1bit(pend0);
#ifdef CONFIG_SMP
	if (pend0 & (1UL << CPU_RESCHED_A_IRQ)) {
		LOCAL_HUB_CLR_INTR(CPU_RESCHED_A_IRQ);
		scheduler_ipi();
	} else if (pend0 & (1UL << CPU_RESCHED_B_IRQ)) {
		LOCAL_HUB_CLR_INTR(CPU_RESCHED_B_IRQ);
		scheduler_ipi();
	} else if (pend0 & (1UL << CPU_CALL_A_IRQ)) {
		LOCAL_HUB_CLR_INTR(CPU_CALL_A_IRQ);
		irq_enter();
		generic_smp_call_function_interrupt();
		irq_exit();
	} else if (pend0 & (1UL << CPU_CALL_B_IRQ)) {
		LOCAL_HUB_CLR_INTR(CPU_CALL_B_IRQ);
		irq_enter();
		generic_smp_call_function_interrupt();
		irq_exit();
	} else
#endif
	{
		/* "map" swlevel to irq */
		struct slice_data *si = cpu_data[cpu].data;

		irq = si->level_to_irq[swlevel];
		do_IRQ(irq);
	}

	LOCAL_HUB_L(PI_INT_PEND0);
}

__attribute__((used)) static void ip27_do_irq_mask1(void)
{
	int irq, swlevel;
	hubreg_t pend1, mask1;
	cpuid_t cpu = smp_processor_id();
	int pi_int_mask1 = (cputoslice(cpu) == 0) ?  PI_INT_MASK1_A : PI_INT_MASK1_B;
	struct slice_data *si = cpu_data[cpu].data;

	/* copied from Irix intpend0() */
	pend1 = LOCAL_HUB_L(PI_INT_PEND1);
	mask1 = LOCAL_HUB_L(pi_int_mask1);

	pend1 &= mask1;		/* Pick intrs we should look at */
	if (!pend1)
		return;

	swlevel = ms1bit(pend1);
	/* "map" swlevel to irq */
	irq = si->level_to_irq[swlevel];
	LOCAL_HUB_CLR_INTR(swlevel);
	do_IRQ(irq);

	LOCAL_HUB_L(PI_INT_PEND1);
}

__attribute__((used)) static void ip27_prof_timer(void)
{
	panic("CPU %d got a profiling interrupt", smp_processor_id());
}

__attribute__((used)) static void ip27_hub_error(void)
{
	panic("CPU %d got a hub error interrupt", smp_processor_id());
}

