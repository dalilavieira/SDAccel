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
struct irq_desc {int dummy; } ;
struct irq_data {unsigned int irq; } ;
struct fpga_irq {unsigned short mask; unsigned int base; int /*<<< orphan*/  sraddr; int /*<<< orphan*/  mraddr; } ;

/* Variables and functions */
 unsigned int IRQ0_BASE ; 
 unsigned int IRQ0_END ; 
#define  IRQ0_IRQ 129 
 unsigned short IRQ0_MASK ; 
 int /*<<< orphan*/  IRQ0_MR ; 
 int /*<<< orphan*/  IRQ0_SR ; 
 unsigned int IRQ1_BASE ; 
 unsigned int IRQ1_END ; 
#define  IRQ1_IRQ 128 
 unsigned short IRQ1_MASK ; 
 int /*<<< orphan*/  IRQ1_MR ; 
 int /*<<< orphan*/  IRQ1_SR ; 
 unsigned int IRQ2_BASE ; 
 unsigned int IRQ2_IRQ ; 
 unsigned short IRQ2_MASK ; 
 int /*<<< orphan*/  IRQ2_MR ; 
 int /*<<< orphan*/  IRQ2_SR ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 unsigned int irq_desc_get_irq (struct irq_desc*) ; 

__attribute__((used)) static unsigned int fpga2irq(unsigned int irq)
{
	if (irq >= IRQ0_BASE &&
	    irq <= IRQ0_END)
		return IRQ0_IRQ;
	else if (irq >= IRQ1_BASE &&
		 irq <= IRQ1_END)
		return IRQ1_IRQ;
	else
		return IRQ2_IRQ;
}

__attribute__((used)) static struct fpga_irq get_fpga_irq(unsigned int irq)
{
	struct fpga_irq set;

	switch (irq) {
	case IRQ0_IRQ:
		set.sraddr = IRQ0_SR;
		set.mraddr = IRQ0_MR;
		set.mask   = IRQ0_MASK;
		set.base   = IRQ0_BASE;
		break;
	case IRQ1_IRQ:
		set.sraddr = IRQ1_SR;
		set.mraddr = IRQ1_MR;
		set.mask   = IRQ1_MASK;
		set.base   = IRQ1_BASE;
		break;
	default:
		set.sraddr = IRQ2_SR;
		set.mraddr = IRQ2_MR;
		set.mask   = IRQ2_MASK;
		set.base   = IRQ2_BASE;
		break;
	}

	return set;
}

__attribute__((used)) static void disable_se7724_irq(struct irq_data *data)
{
	unsigned int irq = data->irq;
	struct fpga_irq set = get_fpga_irq(fpga2irq(irq));
	unsigned int bit = irq - set.base;
	__raw_writew(__raw_readw(set.mraddr) | 0x0001 << bit, set.mraddr);
}

__attribute__((used)) static void enable_se7724_irq(struct irq_data *data)
{
	unsigned int irq = data->irq;
	struct fpga_irq set = get_fpga_irq(fpga2irq(irq));
	unsigned int bit = irq - set.base;
	__raw_writew(__raw_readw(set.mraddr) & ~(0x0001 << bit), set.mraddr);
}

__attribute__((used)) static void se7724_irq_demux(struct irq_desc *desc)
{
	unsigned int irq = irq_desc_get_irq(desc);
	struct fpga_irq set = get_fpga_irq(irq);
	unsigned short intv = __raw_readw(set.sraddr);
	unsigned int ext_irq = set.base;

	intv &= set.mask;

	for (; intv; intv >>= 1, ext_irq++) {
		if (!(intv & 1))
			continue;

		generic_handle_irq(ext_irq);
	}
}

