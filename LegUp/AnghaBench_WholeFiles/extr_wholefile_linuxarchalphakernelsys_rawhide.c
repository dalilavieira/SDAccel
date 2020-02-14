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
typedef  int* vuip ;
struct irq_data {unsigned int irq; } ;
typedef  int /*<<< orphan*/  pgprot_t ;

/* Variables and functions */
 int /*<<< orphan*/  MCPCIA_HOSE2MID (unsigned int) ; 
 scalar_t__ MCPCIA_INT_MASK0 (int /*<<< orphan*/ ) ; 
 scalar_t__ MCPCIA_INT_REQ (int /*<<< orphan*/ ) ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 unsigned int* cached_irq_masks ; 
 int /*<<< orphan*/  handle_irq (int) ; 
 int /*<<< orphan*/  hose_exists (unsigned int) ; 
 int* hose_irq_masks ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  rawhide_irq_lock ; 
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

__attribute__((used)) static inline void
rawhide_update_irq_hw(int hose, int mask)
{
	*(vuip)MCPCIA_INT_MASK0(MCPCIA_HOSE2MID(hose)) = mask;
	mb();
	*(vuip)MCPCIA_INT_MASK0(MCPCIA_HOSE2MID(hose));
}

__attribute__((used)) static inline void 
rawhide_enable_irq(struct irq_data *d)
{
	unsigned int mask, hose;
	unsigned int irq = d->irq;

	irq -= 16;
	hose = irq / 24;
	if (!hose_exists(hose)) /* if hose non-existent, exit */
		return;

	irq -= hose * 24;
	mask = 1 << irq;

	spin_lock(&rawhide_irq_lock);
	mask |= cached_irq_masks[hose];
	cached_irq_masks[hose] = mask;
	rawhide_update_irq_hw(hose, mask);
	spin_unlock(&rawhide_irq_lock);
}

__attribute__((used)) static void 
rawhide_disable_irq(struct irq_data *d)
{
	unsigned int mask, hose;
	unsigned int irq = d->irq;

	irq -= 16;
	hose = irq / 24;
	if (!hose_exists(hose)) /* if hose non-existent, exit */
		return;

	irq -= hose * 24;
	mask = ~(1 << irq) | hose_irq_masks[hose];

	spin_lock(&rawhide_irq_lock);
	mask &= cached_irq_masks[hose];
	cached_irq_masks[hose] = mask;
	rawhide_update_irq_hw(hose, mask);
	spin_unlock(&rawhide_irq_lock);
}

__attribute__((used)) static void
rawhide_mask_and_ack_irq(struct irq_data *d)
{
	unsigned int mask, mask1, hose;
	unsigned int irq = d->irq;

	irq -= 16;
	hose = irq / 24;
	if (!hose_exists(hose)) /* if hose non-existent, exit */
		return;

	irq -= hose * 24;
	mask1 = 1 << irq;
	mask = ~mask1 | hose_irq_masks[hose];

	spin_lock(&rawhide_irq_lock);

	mask &= cached_irq_masks[hose];
	cached_irq_masks[hose] = mask;
	rawhide_update_irq_hw(hose, mask);

	/* Clear the interrupt.  */
	*(vuip)MCPCIA_INT_REQ(MCPCIA_HOSE2MID(hose)) = mask1;

	spin_unlock(&rawhide_irq_lock);
}

__attribute__((used)) static void 
rawhide_srm_device_interrupt(unsigned long vector)
{
	int irq;

	irq = (vector - 0x800) >> 4;

        /*
         * The RAWHIDE SRM console reports PCI interrupts with a vector
	 * 0x80 *higher* than one might expect, as PCI IRQ 0 (ie bit 0)
	 * shows up as IRQ 24, etc, etc. We adjust it down by 8 to have
	 * it line up with the actual bit numbers from the REQ registers,
	 * which is how we manage the interrupts/mask. Sigh...
	 *
	 * Also, PCI #1 interrupts are offset some more... :-(
         */

	if (irq == 52) {
		/* SCSI on PCI1 is special.  */
		irq = 72;
	}

	/* Adjust by which hose it is from.  */
	irq -= ((irq + 16) >> 2) & 0x38;

	handle_irq(irq);
}

