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
 unsigned long cached_irq_mask ; 
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
cabriolet_update_irq_hw(unsigned int irq, unsigned long mask)
{
	int ofs = (irq - 16) / 8;
	outb(mask >> (16 + ofs * 8), 0x804 + ofs);
}

__attribute__((used)) static inline void
cabriolet_enable_irq(struct irq_data *d)
{
	cabriolet_update_irq_hw(d->irq, cached_irq_mask &= ~(1UL << d->irq));
}

__attribute__((used)) static void
cabriolet_disable_irq(struct irq_data *d)
{
	cabriolet_update_irq_hw(d->irq, cached_irq_mask |= 1UL << d->irq);
}

__attribute__((used)) static void 
cabriolet_device_interrupt(unsigned long v)
{
	unsigned long pld;
	unsigned int i;

	/* Read the interrupt summary registers */
	pld = inb(0x804) | (inb(0x805) << 8) | (inb(0x806) << 16);

	/*
	 * Now for every possible bit set, work through them and call
	 * the appropriate interrupt handler.
	 */
	while (pld) {
		i = ffz(~pld);
		pld &= pld - 1;	/* clear least bit set */
		if (i == 4) {
			isa_device_interrupt(v);
		} else {
			handle_irq(16 + i);
		}
	}
}

