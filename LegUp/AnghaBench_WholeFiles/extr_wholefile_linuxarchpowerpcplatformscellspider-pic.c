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
struct spider_pic {int /*<<< orphan*/  host; scalar_t__ regs; } ;
struct irq_domain {int /*<<< orphan*/  host_data; } ;
struct irq_desc {int /*<<< orphan*/  irq_data; } ;
struct irq_data {int dummy; } ;
struct irq_chip {int /*<<< orphan*/  (* irq_eoi ) (int /*<<< orphan*/ *) ;} ;
struct device_node {int dummy; } ;
typedef  int irq_hw_number_t ;

/* Variables and functions */
 unsigned int IRQ_TYPE_LEVEL_HIGH ; 
 int /*<<< orphan*/  IRQ_TYPE_NONE ; 
 unsigned int SPIDER_IRQ_INVALID ; 
 scalar_t__ TIR_CS ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int in_be32 (scalar_t__) ; 
 struct spider_pic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 struct spider_pic* irq_desc_get_handler_data (struct irq_desc*) ; 
 unsigned int irq_linear_revmap (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_irq_type (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spider_pic ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct spider_pic *spider_irq_data_to_pic(struct irq_data *d)
{
	return irq_data_get_irq_chip_data(d);
}

__attribute__((used)) static int spider_host_map(struct irq_domain *h, unsigned int virq,
			irq_hw_number_t hw)
{
	irq_set_chip_data(virq, h->host_data);
	irq_set_chip_and_handler(virq, &spider_pic, handle_level_irq);

	/* Set default irq type */
	irq_set_irq_type(virq, IRQ_TYPE_NONE);

	return 0;
}

__attribute__((used)) static int spider_host_xlate(struct irq_domain *h, struct device_node *ct,
			   const u32 *intspec, unsigned int intsize,
			   irq_hw_number_t *out_hwirq, unsigned int *out_flags)

{
	/* Spider interrupts have 2 cells, first is the interrupt source,
	 * second, well, I don't know for sure yet ... We mask the top bits
	 * because old device-trees encode a node number in there
	 */
	*out_hwirq = intspec[0] & 0x3f;
	*out_flags = IRQ_TYPE_LEVEL_HIGH;
	return 0;
}

__attribute__((used)) static void spider_irq_cascade(struct irq_desc *desc)
{
	struct irq_chip *chip = irq_desc_get_chip(desc);
	struct spider_pic *pic = irq_desc_get_handler_data(desc);
	unsigned int cs, virq;

	cs = in_be32(pic->regs + TIR_CS) >> 24;
	if (cs == SPIDER_IRQ_INVALID)
		virq = 0;
	else
		virq = irq_linear_revmap(pic->host, cs);

	if (virq)
		generic_handle_irq(virq);

	chip->irq_eoi(&desc->irq_data);
}

