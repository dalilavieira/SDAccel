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
struct irq_data {unsigned int irq; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int cached_irq_mask ; 
 unsigned int ffz (unsigned long) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int inb (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isa_device_interrupt (unsigned long) ; 
 int /*<<< orphan*/  outb (unsigned long,int) ; 

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
eb64p_update_irq_hw(unsigned int irq, unsigned long mask)
{
	outb(mask >> (irq >= 24 ? 24 : 16), (irq >= 24 ? 0x27 : 0x26));
}

__attribute__((used)) static inline void
eb64p_enable_irq(struct irq_data *d)
{
	eb64p_update_irq_hw(d->irq, cached_irq_mask &= ~(1 << d->irq));
}

__attribute__((used)) static void
eb64p_disable_irq(struct irq_data *d)
{
	eb64p_update_irq_hw(d->irq, cached_irq_mask |= 1 << d->irq);
}

__attribute__((used)) static void 
eb64p_device_interrupt(unsigned long vector)
{
	unsigned long pld;
	unsigned int i;

	/* Read the interrupt summary registers */
	pld = inb(0x26) | (inb(0x27) << 8);

	/*
	 * Now, for every possible bit set, work through
	 * them and call the appropriate interrupt handler.
	 */
	while (pld) {
		i = ffz(~pld);
		pld &= pld - 1;	/* clear least bit set */

		if (i == 5) {
			isa_device_interrupt(vector);
		} else {
			handle_irq(16 + i);
		}
	}
}

