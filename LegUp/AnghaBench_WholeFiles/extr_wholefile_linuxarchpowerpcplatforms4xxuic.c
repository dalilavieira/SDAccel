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
typedef  int u32 ;
struct uic {int /*<<< orphan*/  irqhost; scalar_t__ dcrbase; int /*<<< orphan*/  lock; } ;
struct irq_domain {struct uic* host_data; } ;
struct irq_desc {int /*<<< orphan*/  lock; } ;
struct irq_data {int dummy; } ;
struct irq_chip {int /*<<< orphan*/  (* irq_unmask ) (struct irq_data*) ;int /*<<< orphan*/  (* irq_ack ) (struct irq_data*) ;int /*<<< orphan*/  (* irq_mask_ack ) (struct irq_data*) ;int /*<<< orphan*/  (* irq_mask ) (struct irq_data*) ;} ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int EINVAL ; 
#define  IRQ_TYPE_EDGE_FALLING 132 
#define  IRQ_TYPE_EDGE_RISING 131 
#define  IRQ_TYPE_LEVEL_HIGH 130 
#define  IRQ_TYPE_LEVEL_LOW 129 
#define  IRQ_TYPE_NONE 128 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ UIC_ER ; 
 scalar_t__ UIC_MSR ; 
 scalar_t__ UIC_PR ; 
 scalar_t__ UIC_SR ; 
 scalar_t__ UIC_TR ; 
 int ffs (int) ; 
 int /*<<< orphan*/  generic_handle_irq (int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 struct uic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 struct uic* irq_desc_get_handler_data (struct irq_desc*) ; 
 struct irq_data* irq_desc_get_irq_data (struct irq_desc*) ; 
 int irq_linear_revmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct uic*) ; 
 int /*<<< orphan*/  irq_set_irq_type (unsigned int,int const) ; 
 int /*<<< orphan*/  irqd_irq_disabled (struct irq_data*) ; 
 scalar_t__ irqd_is_level_type (struct irq_data*) ; 
 unsigned int irqd_to_hwirq (struct irq_data*) ; 
 int mfdcr (scalar_t__) ; 
 int /*<<< orphan*/  mtdcr (scalar_t__,int) ; 
 int /*<<< orphan*/  raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct irq_data*) ; 
 int /*<<< orphan*/  stub2 (struct irq_data*) ; 
 int /*<<< orphan*/  stub3 (struct irq_data*) ; 
 int /*<<< orphan*/  stub4 (struct irq_data*) ; 
 int /*<<< orphan*/  uic_irq_chip ; 

__attribute__((used)) static void uic_unmask_irq(struct irq_data *d)
{
	struct uic *uic = irq_data_get_irq_chip_data(d);
	unsigned int src = irqd_to_hwirq(d);
	unsigned long flags;
	u32 er, sr;

	sr = 1 << (31-src);
	raw_spin_lock_irqsave(&uic->lock, flags);
	/* ack level-triggered interrupts here */
	if (irqd_is_level_type(d))
		mtdcr(uic->dcrbase + UIC_SR, sr);
	er = mfdcr(uic->dcrbase + UIC_ER);
	er |= sr;
	mtdcr(uic->dcrbase + UIC_ER, er);
	raw_spin_unlock_irqrestore(&uic->lock, flags);
}

__attribute__((used)) static void uic_mask_irq(struct irq_data *d)
{
	struct uic *uic = irq_data_get_irq_chip_data(d);
	unsigned int src = irqd_to_hwirq(d);
	unsigned long flags;
	u32 er;

	raw_spin_lock_irqsave(&uic->lock, flags);
	er = mfdcr(uic->dcrbase + UIC_ER);
	er &= ~(1 << (31 - src));
	mtdcr(uic->dcrbase + UIC_ER, er);
	raw_spin_unlock_irqrestore(&uic->lock, flags);
}

__attribute__((used)) static void uic_ack_irq(struct irq_data *d)
{
	struct uic *uic = irq_data_get_irq_chip_data(d);
	unsigned int src = irqd_to_hwirq(d);
	unsigned long flags;

	raw_spin_lock_irqsave(&uic->lock, flags);
	mtdcr(uic->dcrbase + UIC_SR, 1 << (31-src));
	raw_spin_unlock_irqrestore(&uic->lock, flags);
}

__attribute__((used)) static void uic_mask_ack_irq(struct irq_data *d)
{
	struct uic *uic = irq_data_get_irq_chip_data(d);
	unsigned int src = irqd_to_hwirq(d);
	unsigned long flags;
	u32 er, sr;

	sr = 1 << (31-src);
	raw_spin_lock_irqsave(&uic->lock, flags);
	er = mfdcr(uic->dcrbase + UIC_ER);
	er &= ~sr;
	mtdcr(uic->dcrbase + UIC_ER, er);
 	/* On the UIC, acking (i.e. clearing the SR bit)
	 * a level irq will have no effect if the interrupt
	 * is still asserted by the device, even if
	 * the interrupt is already masked. Therefore
	 * we only ack the egde interrupts here, while
	 * level interrupts are ack'ed after the actual
	 * isr call in the uic_unmask_irq()
	 */
	if (!irqd_is_level_type(d))
		mtdcr(uic->dcrbase + UIC_SR, sr);
	raw_spin_unlock_irqrestore(&uic->lock, flags);
}

__attribute__((used)) static int uic_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
	struct uic *uic = irq_data_get_irq_chip_data(d);
	unsigned int src = irqd_to_hwirq(d);
	unsigned long flags;
	int trigger, polarity;
	u32 tr, pr, mask;

	switch (flow_type & IRQ_TYPE_SENSE_MASK) {
	case IRQ_TYPE_NONE:
		uic_mask_irq(d);
		return 0;

	case IRQ_TYPE_EDGE_RISING:
		trigger = 1; polarity = 1;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		trigger = 1; polarity = 0;
		break;
	case IRQ_TYPE_LEVEL_HIGH:
		trigger = 0; polarity = 1;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		trigger = 0; polarity = 0;
		break;
	default:
		return -EINVAL;
	}

	mask = ~(1 << (31 - src));

	raw_spin_lock_irqsave(&uic->lock, flags);
	tr = mfdcr(uic->dcrbase + UIC_TR);
	pr = mfdcr(uic->dcrbase + UIC_PR);
	tr = (tr & mask) | (trigger << (31-src));
	pr = (pr & mask) | (polarity << (31-src));

	mtdcr(uic->dcrbase + UIC_PR, pr);
	mtdcr(uic->dcrbase + UIC_TR, tr);

	raw_spin_unlock_irqrestore(&uic->lock, flags);

	return 0;
}

__attribute__((used)) static int uic_host_map(struct irq_domain *h, unsigned int virq,
			irq_hw_number_t hw)
{
	struct uic *uic = h->host_data;

	irq_set_chip_data(virq, uic);
	/* Despite the name, handle_level_irq() works for both level
	 * and edge irqs on UIC.  FIXME: check this is correct */
	irq_set_chip_and_handler(virq, &uic_irq_chip, handle_level_irq);

	/* Set default irq type */
	irq_set_irq_type(virq, IRQ_TYPE_NONE);

	return 0;
}

__attribute__((used)) static void uic_irq_cascade(struct irq_desc *desc)
{
	struct irq_chip *chip = irq_desc_get_chip(desc);
	struct irq_data *idata = irq_desc_get_irq_data(desc);
	struct uic *uic = irq_desc_get_handler_data(desc);
	u32 msr;
	int src;
	int subvirq;

	raw_spin_lock(&desc->lock);
	if (irqd_is_level_type(idata))
		chip->irq_mask(idata);
	else
		chip->irq_mask_ack(idata);
	raw_spin_unlock(&desc->lock);

	msr = mfdcr(uic->dcrbase + UIC_MSR);
	if (!msr) /* spurious interrupt */
		goto uic_irq_ret;

	src = 32 - ffs(msr);

	subvirq = irq_linear_revmap(uic->irqhost, src);
	generic_handle_irq(subvirq);

uic_irq_ret:
	raw_spin_lock(&desc->lock);
	if (irqd_is_level_type(idata))
		chip->irq_ack(idata);
	if (!irqd_irq_disabled(idata) && chip->irq_unmask)
		chip->irq_unmask(idata);
	raw_spin_unlock(&desc->lock);
}

