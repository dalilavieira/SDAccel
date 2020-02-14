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
struct irq_data {int irq; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 scalar_t__ POLARIS_DENSE_CONFIG_BASE ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 unsigned long cached_irq_mask ; 
 long ffz (unsigned long) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isa_no_iack_sc_device_interrupt (unsigned long) ; 
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
rx164_update_irq_hw(unsigned long mask)
{
	volatile unsigned int *irq_mask;

	irq_mask = (void *)(POLARIS_DENSE_CONFIG_BASE + 0x74);
	*irq_mask = mask;
	mb();
	*irq_mask;
}

__attribute__((used)) static inline void
rx164_enable_irq(struct irq_data *d)
{
	rx164_update_irq_hw(cached_irq_mask |= 1UL << (d->irq - 16));
}

__attribute__((used)) static void
rx164_disable_irq(struct irq_data *d)
{
	rx164_update_irq_hw(cached_irq_mask &= ~(1UL << (d->irq - 16)));
}

__attribute__((used)) static void 
rx164_device_interrupt(unsigned long vector)
{
	unsigned long pld;
	volatile unsigned int *dirr;
	long i;

	/* Read the interrupt summary register.  On Polaris, this is
	   the DIRR register in PCI config space (offset 0x84).  */
	dirr = (void *)(POLARIS_DENSE_CONFIG_BASE + 0x84);
	pld = *dirr;

	/*
	 * Now for every possible bit set, work through them and call
	 * the appropriate interrupt handler.
	 */
	while (pld) {
		i = ffz(~pld);
		pld &= pld - 1; /* clear least bit set */
		if (i == 20) {
			isa_no_iack_sc_device_interrupt(vector);
		} else {
			handle_irq(16+i);
		}
	}
}

