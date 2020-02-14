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
struct irq_data {size_t irq; } ;
typedef  int /*<<< orphan*/  pgprot_t ;
struct TYPE_2__ {unsigned long* irq_to_mask; unsigned long shadow_mask; int* mask_to_irq; int /*<<< orphan*/  (* ack_irq_hw ) (unsigned long) ;int /*<<< orphan*/  (* update_irq_hw ) (unsigned long,unsigned long) ;} ;

/* Variables and functions */
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sable_lynx_irq_lock ; 
 TYPE_1__* sable_lynx_irq_swizzle ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  stub2 (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  stub3 (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  stub4 (unsigned long) ; 

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
sable_lynx_enable_irq(struct irq_data *d)
{
	unsigned long bit, mask;

	bit = sable_lynx_irq_swizzle->irq_to_mask[d->irq];
	spin_lock(&sable_lynx_irq_lock);
	mask = sable_lynx_irq_swizzle->shadow_mask &= ~(1UL << bit);
	sable_lynx_irq_swizzle->update_irq_hw(bit, mask);
	spin_unlock(&sable_lynx_irq_lock);
#if 0
	printk("%s: mask 0x%lx bit 0x%lx irq 0x%x\n",
	       __func__, mask, bit, irq);
#endif
}

__attribute__((used)) static void
sable_lynx_disable_irq(struct irq_data *d)
{
	unsigned long bit, mask;

	bit = sable_lynx_irq_swizzle->irq_to_mask[d->irq];
	spin_lock(&sable_lynx_irq_lock);
	mask = sable_lynx_irq_swizzle->shadow_mask |= 1UL << bit;
	sable_lynx_irq_swizzle->update_irq_hw(bit, mask);
	spin_unlock(&sable_lynx_irq_lock);
#if 0
	printk("%s: mask 0x%lx bit 0x%lx irq 0x%x\n",
	       __func__, mask, bit, irq);
#endif
}

__attribute__((used)) static void
sable_lynx_mask_and_ack_irq(struct irq_data *d)
{
	unsigned long bit, mask;

	bit = sable_lynx_irq_swizzle->irq_to_mask[d->irq];
	spin_lock(&sable_lynx_irq_lock);
	mask = sable_lynx_irq_swizzle->shadow_mask |= 1UL << bit;
	sable_lynx_irq_swizzle->update_irq_hw(bit, mask);
	sable_lynx_irq_swizzle->ack_irq_hw(bit);
	spin_unlock(&sable_lynx_irq_lock);
}

__attribute__((used)) static void 
sable_lynx_srm_device_interrupt(unsigned long vector)
{
	/* Note that the vector reported by the SRM PALcode corresponds
	   to the interrupt mask bits, but we have to manage via the
	   so-called legacy IRQs for many common devices.  */

	int bit, irq;

	bit = (vector - 0x800) >> 4;
	irq = sable_lynx_irq_swizzle->mask_to_irq[bit];
#if 0
	printk("%s: vector 0x%lx bit 0x%x irq 0x%x\n",
	       __func__, vector, bit, irq);
#endif
	handle_irq(irq);
}

