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
struct irq_domain {int dummy; } ;
struct irq_data {unsigned long hwirq; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 unsigned int BIT_MASK (unsigned long) ; 
 unsigned int BIT_WORD (unsigned long) ; 
 unsigned int CP_INTC_HOST_ENABLE_IDX_CLR ; 
 unsigned int CP_INTC_HOST_ENABLE_IDX_SET ; 
 unsigned int CP_INTC_SYS_ENABLE_IDX_CLR ; 
 unsigned int CP_INTC_SYS_ENABLE_IDX_SET ; 
 unsigned int CP_INTC_SYS_POLARITY (unsigned int) ; 
 unsigned int CP_INTC_SYS_STAT_IDX_CLR ; 
 unsigned int CP_INTC_SYS_TYPE (unsigned int) ; 
 int EINVAL ; 
#define  IRQ_TYPE_EDGE_FALLING 131 
#define  IRQ_TYPE_EDGE_RISING 130 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 unsigned int __raw_readl (unsigned int) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,unsigned int) ; 
 int /*<<< orphan*/  cp_intc_irq_chip ; 
 unsigned int davinci_intc_base ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  irq_set_chip (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_set_handler (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_probe (unsigned int) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int cp_intc_read(unsigned offset)
{
	return __raw_readl(davinci_intc_base + offset);
}

__attribute__((used)) static inline void cp_intc_write(unsigned long value, unsigned offset)
{
	__raw_writel(value, davinci_intc_base + offset);
}

__attribute__((used)) static void cp_intc_ack_irq(struct irq_data *d)
{
	cp_intc_write(d->hwirq, CP_INTC_SYS_STAT_IDX_CLR);
}

__attribute__((used)) static void cp_intc_mask_irq(struct irq_data *d)
{
	/* XXX don't know why we need to disable nIRQ here... */
	cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_CLR);
	cp_intc_write(d->hwirq, CP_INTC_SYS_ENABLE_IDX_CLR);
	cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_SET);
}

__attribute__((used)) static void cp_intc_unmask_irq(struct irq_data *d)
{
	cp_intc_write(d->hwirq, CP_INTC_SYS_ENABLE_IDX_SET);
}

__attribute__((used)) static int cp_intc_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
	unsigned reg		= BIT_WORD(d->hwirq);
	unsigned mask		= BIT_MASK(d->hwirq);
	unsigned polarity	= cp_intc_read(CP_INTC_SYS_POLARITY(reg));
	unsigned type		= cp_intc_read(CP_INTC_SYS_TYPE(reg));

	switch (flow_type) {
	case IRQ_TYPE_EDGE_RISING:
		polarity |= mask;
		type |= mask;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		polarity &= ~mask;
		type |= mask;
		break;
	case IRQ_TYPE_LEVEL_HIGH:
		polarity |= mask;
		type &= ~mask;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		polarity &= ~mask;
		type &= ~mask;
		break;
	default:
		return -EINVAL;
	}

	cp_intc_write(polarity, CP_INTC_SYS_POLARITY(reg));
	cp_intc_write(type, CP_INTC_SYS_TYPE(reg));

	return 0;
}

__attribute__((used)) static int cp_intc_host_map(struct irq_domain *h, unsigned int virq,
			  irq_hw_number_t hw)
{
	pr_debug("cp_intc_host_map(%d, 0x%lx)\n", virq, hw);

	irq_set_chip(virq, &cp_intc_irq_chip);
	irq_set_probe(virq);
	irq_set_handler(virq, handle_edge_irq);
	return 0;
}

