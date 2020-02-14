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
typedef  int uint32_t ;
typedef  int u32 ;
struct socrates_fpga_irq_info {unsigned int irq_line; scalar_t__ type; } ;
struct irq_domain {int dummy; } ;
struct irq_desc {int /*<<< orphan*/  irq_data; } ;
struct irq_data {int dummy; } ;
struct irq_chip {int /*<<< orphan*/  (* irq_eoi ) (int /*<<< orphan*/ *) ;} ;
struct device_node {int dummy; } ;
typedef  int irq_hw_number_t ;

/* Variables and functions */
 int EINVAL ; 
 int FPGA_PIC_IRQCFG ; 
 int FPGA_PIC_IRQMASK (int) ; 
 int /*<<< orphan*/  IRQ_LEVEL ; 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 scalar_t__ IRQ_TYPE_NONE ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 int SOCRATES_FPGA_IRQ_MASK ; 
 int SOCRATES_FPGA_NUM_IRQS ; 
 struct socrates_fpga_irq_info* fpga_irqs ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int /*<<< orphan*/  handle_fasteoi_irq ; 
 int in_be32 (scalar_t__) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 unsigned int irq_desc_get_irq (struct irq_desc*) ; 
 int /*<<< orphan*/ * irq_domain_add_linear (struct device_node*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned int irq_linear_revmap (int /*<<< orphan*/ *,int) ; 
 unsigned int irq_of_parse_and_map (struct device_node*,int) ; 
 int /*<<< orphan*/  irq_set_chained_handler (unsigned int,void (*) (struct irq_desc*)) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int irqd_to_hwirq (struct irq_data*) ; 
 scalar_t__ of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_be32 (scalar_t__,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int* socrates_fpga_irqs ; 
 int /*<<< orphan*/  socrates_fpga_pic_chip ; 
 int /*<<< orphan*/  socrates_fpga_pic_host_ops ; 
 scalar_t__ socrates_fpga_pic_iobase ; 
 int /*<<< orphan*/ * socrates_fpga_pic_irq_host ; 
 int /*<<< orphan*/  socrates_fpga_pic_lock ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline uint32_t socrates_fpga_pic_read(int reg)
{
	return in_be32(socrates_fpga_pic_iobase + reg);
}

__attribute__((used)) static inline void socrates_fpga_pic_write(int reg, uint32_t val)
{
	out_be32(socrates_fpga_pic_iobase + reg, val);
}

__attribute__((used)) static inline unsigned int socrates_fpga_pic_get_irq(unsigned int irq)
{
	uint32_t cause;
	unsigned long flags;
	int i;

	/* Check irq line routed to the MPIC */
	for (i = 0; i < 3; i++) {
		if (irq == socrates_fpga_irqs[i])
			break;
	}
	if (i == 3)
		return 0;

	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	cause = socrates_fpga_pic_read(FPGA_PIC_IRQMASK(i));
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
	for (i = SOCRATES_FPGA_NUM_IRQS - 1; i >= 0; i--) {
		if (cause >> (i + 16))
			break;
	}
	return irq_linear_revmap(socrates_fpga_pic_irq_host,
			(irq_hw_number_t)i);
}

__attribute__((used)) static void socrates_fpga_pic_cascade(struct irq_desc *desc)
{
	struct irq_chip *chip = irq_desc_get_chip(desc);
	unsigned int irq = irq_desc_get_irq(desc);
	unsigned int cascade_irq;

	/*
	 * See if we actually have an interrupt, call generic handling code if
	 * we do.
	 */
	cascade_irq = socrates_fpga_pic_get_irq(irq);

	if (cascade_irq)
		generic_handle_irq(cascade_irq);
	chip->irq_eoi(&desc->irq_data);
}

__attribute__((used)) static void socrates_fpga_pic_ack(struct irq_data *d)
{
	unsigned long flags;
	unsigned int irq_line, hwirq = irqd_to_hwirq(d);
	uint32_t mask;

	irq_line = fpga_irqs[hwirq].irq_line;
	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	mask = socrates_fpga_pic_read(FPGA_PIC_IRQMASK(irq_line))
		& SOCRATES_FPGA_IRQ_MASK;
	mask |= (1 << (hwirq + 16));
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(irq_line), mask);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
}

__attribute__((used)) static void socrates_fpga_pic_mask(struct irq_data *d)
{
	unsigned long flags;
	unsigned int hwirq = irqd_to_hwirq(d);
	int irq_line;
	u32 mask;

	irq_line = fpga_irqs[hwirq].irq_line;
	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	mask = socrates_fpga_pic_read(FPGA_PIC_IRQMASK(irq_line))
		& SOCRATES_FPGA_IRQ_MASK;
	mask &= ~(1 << hwirq);
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(irq_line), mask);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
}

__attribute__((used)) static void socrates_fpga_pic_mask_ack(struct irq_data *d)
{
	unsigned long flags;
	unsigned int hwirq = irqd_to_hwirq(d);
	int irq_line;
	u32 mask;

	irq_line = fpga_irqs[hwirq].irq_line;
	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	mask = socrates_fpga_pic_read(FPGA_PIC_IRQMASK(irq_line))
		& SOCRATES_FPGA_IRQ_MASK;
	mask &= ~(1 << hwirq);
	mask |= (1 << (hwirq + 16));
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(irq_line), mask);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
}

__attribute__((used)) static void socrates_fpga_pic_unmask(struct irq_data *d)
{
	unsigned long flags;
	unsigned int hwirq = irqd_to_hwirq(d);
	int irq_line;
	u32 mask;

	irq_line = fpga_irqs[hwirq].irq_line;
	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	mask = socrates_fpga_pic_read(FPGA_PIC_IRQMASK(irq_line))
		& SOCRATES_FPGA_IRQ_MASK;
	mask |= (1 << hwirq);
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(irq_line), mask);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
}

__attribute__((used)) static void socrates_fpga_pic_eoi(struct irq_data *d)
{
	unsigned long flags;
	unsigned int hwirq = irqd_to_hwirq(d);
	int irq_line;
	u32 mask;

	irq_line = fpga_irqs[hwirq].irq_line;
	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	mask = socrates_fpga_pic_read(FPGA_PIC_IRQMASK(irq_line))
		& SOCRATES_FPGA_IRQ_MASK;
	mask |= (1 << (hwirq + 16));
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(irq_line), mask);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
}

__attribute__((used)) static int socrates_fpga_pic_set_type(struct irq_data *d,
		unsigned int flow_type)
{
	unsigned long flags;
	unsigned int hwirq = irqd_to_hwirq(d);
	int polarity;
	u32 mask;

	if (fpga_irqs[hwirq].type != IRQ_TYPE_NONE)
		return -EINVAL;

	switch (flow_type & IRQ_TYPE_SENSE_MASK) {
	case IRQ_TYPE_LEVEL_HIGH:
		polarity = 1;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		polarity = 0;
		break;
	default:
		return -EINVAL;
	}
	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	mask = socrates_fpga_pic_read(FPGA_PIC_IRQCFG);
	if (polarity)
		mask |= (1 << hwirq);
	else
		mask &= ~(1 << hwirq);
	socrates_fpga_pic_write(FPGA_PIC_IRQCFG, mask);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);
	return 0;
}

__attribute__((used)) static int socrates_fpga_pic_host_map(struct irq_domain *h, unsigned int virq,
		irq_hw_number_t hwirq)
{
	/* All interrupts are LEVEL sensitive */
	irq_set_status_flags(virq, IRQ_LEVEL);
	irq_set_chip_and_handler(virq, &socrates_fpga_pic_chip,
				 handle_fasteoi_irq);

	return 0;
}

__attribute__((used)) static int socrates_fpga_pic_host_xlate(struct irq_domain *h,
		struct device_node *ct,	const u32 *intspec, unsigned int intsize,
		irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
	struct socrates_fpga_irq_info *fpga_irq = &fpga_irqs[intspec[0]];

	*out_hwirq = intspec[0];
	if  (fpga_irq->type == IRQ_TYPE_NONE) {
		/* type is configurable */
		if (intspec[1] != IRQ_TYPE_LEVEL_LOW &&
		    intspec[1] != IRQ_TYPE_LEVEL_HIGH) {
			pr_warn("FPGA PIC: invalid irq type, setting default active low\n");
			*out_flags = IRQ_TYPE_LEVEL_LOW;
		} else {
			*out_flags = intspec[1];
		}
	} else {
		/* type is fixed */
		*out_flags = fpga_irq->type;
	}

	/* Use specified interrupt routing */
	if (intspec[2] <= 2)
		fpga_irq->irq_line = intspec[2];
	else
		pr_warn("FPGA PIC: invalid irq routing\n");

	return 0;
}

void socrates_fpga_pic_init(struct device_node *pic)
{
	unsigned long flags;
	int i;

	/* Setup an irq_domain structure */
	socrates_fpga_pic_irq_host = irq_domain_add_linear(pic,
		    SOCRATES_FPGA_NUM_IRQS, &socrates_fpga_pic_host_ops, NULL);
	if (socrates_fpga_pic_irq_host == NULL) {
		pr_err("FPGA PIC: Unable to allocate host\n");
		return;
	}

	for (i = 0; i < 3; i++) {
		socrates_fpga_irqs[i] = irq_of_parse_and_map(pic, i);
		if (!socrates_fpga_irqs[i]) {
			pr_warn("FPGA PIC: can't get irq%d\n", i);
			continue;
		}
		irq_set_chained_handler(socrates_fpga_irqs[i],
					socrates_fpga_pic_cascade);
	}

	socrates_fpga_pic_iobase = of_iomap(pic, 0);

	raw_spin_lock_irqsave(&socrates_fpga_pic_lock, flags);
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(0),
			SOCRATES_FPGA_IRQ_MASK << 16);
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(1),
			SOCRATES_FPGA_IRQ_MASK << 16);
	socrates_fpga_pic_write(FPGA_PIC_IRQMASK(2),
			SOCRATES_FPGA_IRQ_MASK << 16);
	raw_spin_unlock_irqrestore(&socrates_fpga_pic_lock, flags);

	pr_info("FPGA PIC: Setting up Socrates FPGA PIC\n");
}

