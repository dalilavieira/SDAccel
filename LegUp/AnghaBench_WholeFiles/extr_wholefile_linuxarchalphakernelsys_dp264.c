#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {unsigned long csr; } ;
struct TYPE_11__ {unsigned long csr; } ;
struct TYPE_10__ {unsigned long csr; } ;
struct TYPE_9__ {unsigned long csr; } ;
struct TYPE_8__ {unsigned long csr; } ;
struct TYPE_13__ {TYPE_5__ dir0; TYPE_4__ dim3; TYPE_3__ dim2; TYPE_2__ dim1; TYPE_1__ dim0; } ;
typedef  TYPE_6__ tsunami_cchip ;
struct irq_data {unsigned long irq; } ;
struct cpumask {int dummy; } ;
typedef  int /*<<< orphan*/  pgprot_t ;
typedef  struct cpumask cpumask_t ;

/* Variables and functions */
 TYPE_6__* TSUNAMI_cchip ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int boot_cpuid ; 
 unsigned long cached_irq_mask ; 
 unsigned long* cpu_irq_affinity ; 
 scalar_t__ cpumask_test_cpu (int,struct cpumask*) ; 
 int /*<<< orphan*/  dp264_irq_lock ; 
 unsigned int ffz (unsigned long) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isa_device_interrupt (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void find_console_vga_hose(void) { }

__attribute__((used)) static inline void locate_and_init_vga(void *(*sel_func)(void *, void *)) { }

__attribute__((used)) static inline int
__alpha_remap_area_pages(unsigned long address, unsigned long phys_addr,
			 unsigned long size, unsigned long flags)
{
	pgprot_t prot;

	prot = __pgprot(_PAGE_VALID | _PAGE_ASM | _PAGE_KRE
			| _PAGE_KWE | flags);
	return ioremap_page_range(address, address + size, phys_addr, prot);
}

__attribute__((used)) static void
tsunami_update_irq_hw(unsigned long mask)
{
	register tsunami_cchip *cchip = TSUNAMI_cchip;
	unsigned long isa_enable = 1UL << 55;
	register int bcpu = boot_cpuid;

#ifdef CONFIG_SMP
	volatile unsigned long *dim0, *dim1, *dim2, *dim3;
	unsigned long mask0, mask1, mask2, mask3, dummy;

	mask &= ~isa_enable;
	mask0 = mask & cpu_irq_affinity[0];
	mask1 = mask & cpu_irq_affinity[1];
	mask2 = mask & cpu_irq_affinity[2];
	mask3 = mask & cpu_irq_affinity[3];

	if (bcpu == 0) mask0 |= isa_enable;
	else if (bcpu == 1) mask1 |= isa_enable;
	else if (bcpu == 2) mask2 |= isa_enable;
	else mask3 |= isa_enable;

	dim0 = &cchip->dim0.csr;
	dim1 = &cchip->dim1.csr;
	dim2 = &cchip->dim2.csr;
	dim3 = &cchip->dim3.csr;
	if (!cpu_possible(0)) dim0 = &dummy;
	if (!cpu_possible(1)) dim1 = &dummy;
	if (!cpu_possible(2)) dim2 = &dummy;
	if (!cpu_possible(3)) dim3 = &dummy;

	*dim0 = mask0;
	*dim1 = mask1;
	*dim2 = mask2;
	*dim3 = mask3;
	mb();
	*dim0;
	*dim1;
	*dim2;
	*dim3;
#else
	volatile unsigned long *dimB;
	if (bcpu == 0) dimB = &cchip->dim0.csr;
	else if (bcpu == 1) dimB = &cchip->dim1.csr;
	else if (bcpu == 2) dimB = &cchip->dim2.csr;
	else dimB = &cchip->dim3.csr;

	*dimB = mask | isa_enable;
	mb();
	*dimB;
#endif
}

__attribute__((used)) static void
dp264_enable_irq(struct irq_data *d)
{
	spin_lock(&dp264_irq_lock);
	cached_irq_mask |= 1UL << d->irq;
	tsunami_update_irq_hw(cached_irq_mask);
	spin_unlock(&dp264_irq_lock);
}

__attribute__((used)) static void
dp264_disable_irq(struct irq_data *d)
{
	spin_lock(&dp264_irq_lock);
	cached_irq_mask &= ~(1UL << d->irq);
	tsunami_update_irq_hw(cached_irq_mask);
	spin_unlock(&dp264_irq_lock);
}

__attribute__((used)) static void
clipper_enable_irq(struct irq_data *d)
{
	spin_lock(&dp264_irq_lock);
	cached_irq_mask |= 1UL << (d->irq - 16);
	tsunami_update_irq_hw(cached_irq_mask);
	spin_unlock(&dp264_irq_lock);
}

__attribute__((used)) static void
clipper_disable_irq(struct irq_data *d)
{
	spin_lock(&dp264_irq_lock);
	cached_irq_mask &= ~(1UL << (d->irq - 16));
	tsunami_update_irq_hw(cached_irq_mask);
	spin_unlock(&dp264_irq_lock);
}

__attribute__((used)) static void
cpu_set_irq_affinity(unsigned int irq, cpumask_t affinity)
{
	int cpu;

	for (cpu = 0; cpu < 4; cpu++) {
		unsigned long aff = cpu_irq_affinity[cpu];
		if (cpumask_test_cpu(cpu, &affinity))
			aff |= 1UL << irq;
		else
			aff &= ~(1UL << irq);
		cpu_irq_affinity[cpu] = aff;
	}
}

__attribute__((used)) static int
dp264_set_affinity(struct irq_data *d, const struct cpumask *affinity,
		   bool force)
{
	spin_lock(&dp264_irq_lock);
	cpu_set_irq_affinity(d->irq, *affinity);
	tsunami_update_irq_hw(cached_irq_mask);
	spin_unlock(&dp264_irq_lock);

	return 0;
}

__attribute__((used)) static int
clipper_set_affinity(struct irq_data *d, const struct cpumask *affinity,
		     bool force)
{
	spin_lock(&dp264_irq_lock);
	cpu_set_irq_affinity(d->irq - 16, *affinity);
	tsunami_update_irq_hw(cached_irq_mask);
	spin_unlock(&dp264_irq_lock);

	return 0;
}

__attribute__((used)) static void
dp264_device_interrupt(unsigned long vector)
{
	unsigned long pld;
	unsigned int i;

	/* Read the interrupt summary register of TSUNAMI */
	pld = TSUNAMI_cchip->dir0.csr;

	/*
	 * Now for every possible bit set, work through them and call
	 * the appropriate interrupt handler.
	 */
	while (pld) {
		i = ffz(~pld);
		pld &= pld - 1; /* clear least bit set */
		if (i == 55)
			isa_device_interrupt(vector);
		else
			handle_irq(16 + i);
	}
}

__attribute__((used)) static void 
dp264_srm_device_interrupt(unsigned long vector)
{
	int irq;

	irq = (vector - 0x800) >> 4;

	/*
	 * The SRM console reports PCI interrupts with a vector calculated by:
	 *
	 *	0x900 + (0x10 * DRIR-bit)
	 *
	 * So bit 16 shows up as IRQ 32, etc.
	 * 
	 * On DP264/BRICK/MONET, we adjust it down by 16 because at least
	 * that many of the low order bits of the DRIR are not used, and
	 * so we don't count them.
	 */
	if (irq >= 32)
		irq -= 16;

	handle_irq(irq);
}

__attribute__((used)) static void 
clipper_srm_device_interrupt(unsigned long vector)
{
	int irq;

	irq = (vector - 0x800) >> 4;

/*
	 * The SRM console reports PCI interrupts with a vector calculated by:
	 *
	 *	0x900 + (0x10 * DRIR-bit)
	 *
	 * So bit 16 shows up as IRQ 32, etc.
	 * 
	 * CLIPPER uses bits 8-47 for PCI interrupts, so we do not need
	 * to scale down the vector reported, we just use it.
	 *
	 * Eg IRQ 24 is DRIR bit 8, etc, etc
	 */
	handle_irq(irq);
}

