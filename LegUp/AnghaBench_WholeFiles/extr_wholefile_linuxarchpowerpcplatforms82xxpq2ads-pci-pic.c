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
typedef  int u32 ;
struct pq2ads_pci_pic {int /*<<< orphan*/  host; TYPE_1__* regs; } ;
struct irq_domain {int /*<<< orphan*/  host_data; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int dummy; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
struct TYPE_2__ {int /*<<< orphan*/  mask; int /*<<< orphan*/  stat; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_LEVEL ; 
 int NUM_IRQS ; 
 int /*<<< orphan*/  clrbits32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  generic_handle_irq (int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int in_be32 (int /*<<< orphan*/ *) ; 
 struct pq2ads_pci_pic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct pq2ads_pci_pic* irq_desc_get_handler_data (struct irq_desc*) ; 
 int irq_linear_revmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 int irqd_to_hwirq (struct irq_data*) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  pci_pic_lock ; 
 int /*<<< orphan*/  pq2ads_pci_ic ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  setbits32 (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline int pq2ads_pci_init_irq(void)
{
	return 0;
}

__attribute__((used)) static inline void pq2_init_pci(void)
{
}

__attribute__((used)) static void pq2ads_pci_mask_irq(struct irq_data *d)
{
	struct pq2ads_pci_pic *priv = irq_data_get_irq_chip_data(d);
	int irq = NUM_IRQS - irqd_to_hwirq(d) - 1;

	if (irq != -1) {
		unsigned long flags;
		raw_spin_lock_irqsave(&pci_pic_lock, flags);

		setbits32(&priv->regs->mask, 1 << irq);
		mb();

		raw_spin_unlock_irqrestore(&pci_pic_lock, flags);
	}
}

__attribute__((used)) static void pq2ads_pci_unmask_irq(struct irq_data *d)
{
	struct pq2ads_pci_pic *priv = irq_data_get_irq_chip_data(d);
	int irq = NUM_IRQS - irqd_to_hwirq(d) - 1;

	if (irq != -1) {
		unsigned long flags;

		raw_spin_lock_irqsave(&pci_pic_lock, flags);
		clrbits32(&priv->regs->mask, 1 << irq);
		raw_spin_unlock_irqrestore(&pci_pic_lock, flags);
	}
}

__attribute__((used)) static void pq2ads_pci_irq_demux(struct irq_desc *desc)
{
	struct pq2ads_pci_pic *priv = irq_desc_get_handler_data(desc);
	u32 stat, mask, pend;
	int bit;

	for (;;) {
		stat = in_be32(&priv->regs->stat);
		mask = in_be32(&priv->regs->mask);

		pend = stat & ~mask;

		if (!pend)
			break;

		for (bit = 0; pend != 0; ++bit, pend <<= 1) {
			if (pend & 0x80000000) {
				int virq = irq_linear_revmap(priv->host, bit);
				generic_handle_irq(virq);
			}
		}
	}
}

__attribute__((used)) static int pci_pic_host_map(struct irq_domain *h, unsigned int virq,
			    irq_hw_number_t hw)
{
	irq_set_status_flags(virq, IRQ_LEVEL);
	irq_set_chip_data(virq, h->host_data);
	irq_set_chip_and_handler(virq, &pq2ads_pci_ic, handle_level_irq);
	return 0;
}

