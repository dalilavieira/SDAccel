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
typedef  unsigned long* vuip ;
struct irq_data {int irq; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 scalar_t__ GRU_INT_CLEAR ; 
 scalar_t__ GRU_INT_MASK ; 
 scalar_t__ GRU_INT_REQ ; 
 unsigned long GRU_INT_REQ_BITS ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 unsigned long cached_irq_mask ; 
 unsigned int ffz (unsigned long) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int /*<<< orphan*/  i8259a_mask_and_ack_irq (struct irq_data*) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isa_device_interrupt (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 

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

__attribute__((used)) static inline void
alcor_update_irq_hw(unsigned long mask)
{
	*(vuip)GRU_INT_MASK = mask;
	mb();
}

__attribute__((used)) static inline void
alcor_enable_irq(struct irq_data *d)
{
	alcor_update_irq_hw(cached_irq_mask |= 1UL << (d->irq - 16));
}

__attribute__((used)) static void
alcor_disable_irq(struct irq_data *d)
{
	alcor_update_irq_hw(cached_irq_mask &= ~(1UL << (d->irq - 16)));
}

__attribute__((used)) static void
alcor_mask_and_ack_irq(struct irq_data *d)
{
	alcor_disable_irq(d);

	/* On ALCOR/XLT, need to dismiss interrupt via GRU. */
	*(vuip)GRU_INT_CLEAR = 1 << (d->irq - 16); mb();
	*(vuip)GRU_INT_CLEAR = 0; mb();
}

__attribute__((used)) static void
alcor_isa_mask_and_ack_irq(struct irq_data *d)
{
	i8259a_mask_and_ack_irq(d);

	/* On ALCOR/XLT, need to dismiss interrupt via GRU. */
	*(vuip)GRU_INT_CLEAR = 0x80000000; mb();
	*(vuip)GRU_INT_CLEAR = 0; mb();
}

__attribute__((used)) static void
alcor_device_interrupt(unsigned long vector)
{
	unsigned long pld;
	unsigned int i;

	/* Read the interrupt summary register of the GRU */
	pld = (*(vuip)GRU_INT_REQ) & GRU_INT_REQ_BITS;

	/*
	 * Now for every possible bit set, work through them and call
	 * the appropriate interrupt handler.
	 */
	while (pld) {
		i = ffz(~pld);
		pld &= pld - 1; /* clear least bit set */
		if (i == 31) {
			isa_device_interrupt(vector);
		} else {
			handle_irq(16 + i);
		}
	}
}

