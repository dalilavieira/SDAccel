#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {unsigned long csr; } ;
struct TYPE_9__ {unsigned long csr; } ;
struct TYPE_8__ {unsigned long csr; } ;
struct TYPE_7__ {unsigned long csr; } ;
struct TYPE_11__ {TYPE_4__ dim3; TYPE_3__ dim2; TYPE_2__ dim1; TYPE_1__ dim0; } ;
typedef  TYPE_5__ titan_cchip ;
struct irq_data {unsigned int irq; } ;
struct cpumask {int dummy; } ;
typedef  int /*<<< orphan*/  pgprot_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  struct cpumask cpumask_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 TYPE_5__* TITAN_cchip ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int boot_cpuid ; 
 scalar_t__ cpumask_test_cpu (int,struct cpumask*) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  printk (char*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 unsigned long titan_cached_irq_mask ; 
 unsigned long* titan_cpu_irq_affinity ; 
 int /*<<< orphan*/  titan_irq_lock ; 

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
titan_update_irq_hw(unsigned long mask)
{
	register titan_cchip *cchip = TITAN_cchip;
	unsigned long isa_enable = 1UL << 55;
	register int bcpu = boot_cpuid;

#ifdef CONFIG_SMP
	cpumask_t cpm;
	volatile unsigned long *dim0, *dim1, *dim2, *dim3;
	unsigned long mask0, mask1, mask2, mask3, dummy;

	cpumask_copy(&cpm, cpu_present_mask);
	mask &= ~isa_enable;
	mask0 = mask & titan_cpu_irq_affinity[0];
	mask1 = mask & titan_cpu_irq_affinity[1];
	mask2 = mask & titan_cpu_irq_affinity[2];
	mask3 = mask & titan_cpu_irq_affinity[3];

	if (bcpu == 0) mask0 |= isa_enable;
	else if (bcpu == 1) mask1 |= isa_enable;
	else if (bcpu == 2) mask2 |= isa_enable;
	else mask3 |= isa_enable;

	dim0 = &cchip->dim0.csr;
	dim1 = &cchip->dim1.csr;
	dim2 = &cchip->dim2.csr;
	dim3 = &cchip->dim3.csr;
	if (!cpumask_test_cpu(0, &cpm)) dim0 = &dummy;
	if (!cpumask_test_cpu(1, &cpm)) dim1 = &dummy;
	if (!cpumask_test_cpu(2, &cpm)) dim2 = &dummy;
	if (!cpumask_test_cpu(3, &cpm)) dim3 = &dummy;

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
	dimB = &cchip->dim0.csr;
	if (bcpu == 1) dimB = &cchip->dim1.csr;
	else if (bcpu == 2) dimB = &cchip->dim2.csr;
	else if (bcpu == 3) dimB = &cchip->dim3.csr;

	*dimB = mask | isa_enable;
	mb();
	*dimB;
#endif
}

__attribute__((used)) static inline void
titan_enable_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;
	spin_lock(&titan_irq_lock);
	titan_cached_irq_mask |= 1UL << (irq - 16);
	titan_update_irq_hw(titan_cached_irq_mask);
	spin_unlock(&titan_irq_lock);
}

__attribute__((used)) static inline void
titan_disable_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;
	spin_lock(&titan_irq_lock);
	titan_cached_irq_mask &= ~(1UL << (irq - 16));
	titan_update_irq_hw(titan_cached_irq_mask);
	spin_unlock(&titan_irq_lock);
}

__attribute__((used)) static void
titan_cpu_set_irq_affinity(unsigned int irq, cpumask_t affinity)
{
	int cpu;

	for (cpu = 0; cpu < 4; cpu++) {
		if (cpumask_test_cpu(cpu, &affinity))
			titan_cpu_irq_affinity[cpu] |= 1UL << irq;
		else
			titan_cpu_irq_affinity[cpu] &= ~(1UL << irq);
	}

}

__attribute__((used)) static int
titan_set_irq_affinity(struct irq_data *d, const struct cpumask *affinity,
		       bool force)
{ 
	unsigned int irq = d->irq;
	spin_lock(&titan_irq_lock);
	titan_cpu_set_irq_affinity(irq - 16, *affinity);
	titan_update_irq_hw(titan_cached_irq_mask);
	spin_unlock(&titan_irq_lock);

	return 0;
}

__attribute__((used)) static void
titan_device_interrupt(unsigned long vector)
{
	printk("titan_device_interrupt: NOT IMPLEMENTED YET!!\n");
}

__attribute__((used)) static void 
titan_srm_device_interrupt(unsigned long vector)
{
	int irq;

	irq = (vector - 0x800) >> 4;
	handle_irq(irq);
}

__attribute__((used)) static irqreturn_t
titan_intr_nop(int irq, void *dev_id)
{
      /*
       * This is a NOP interrupt handler for the purposes of
       * event counting -- just return.
       */                                                                     
       return IRQ_HANDLED;
}

