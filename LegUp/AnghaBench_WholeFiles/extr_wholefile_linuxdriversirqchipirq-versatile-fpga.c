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
struct pt_regs {int dummy; } ;
struct irq_domain {struct fpga_irq_data* host_data; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int hwirq; } ;
struct fpga_irq_data {int valid; int /*<<< orphan*/  chip; int /*<<< orphan*/  domain; scalar_t__ base; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int EPERM ; 
 scalar_t__ IRQ_ENABLE_CLEAR ; 
 scalar_t__ IRQ_ENABLE_SET ; 
 scalar_t__ IRQ_STATUS ; 
 int /*<<< orphan*/  do_bad_IRQ (struct irq_desc*) ; 
 int ffs (int) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_domain_irq (int /*<<< orphan*/ ,int,struct pt_regs*) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 struct fpga_irq_data* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct fpga_irq_data* irq_desc_get_handler_data (struct irq_desc*) ; 
 int /*<<< orphan*/  irq_find_mapping (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct fpga_irq_data*) ; 
 int /*<<< orphan*/  irq_set_probe (unsigned int) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void fpga_irq_mask(struct irq_data *d)
{
	struct fpga_irq_data *f = irq_data_get_irq_chip_data(d);
	u32 mask = 1 << d->hwirq;

	writel(mask, f->base + IRQ_ENABLE_CLEAR);
}

__attribute__((used)) static void fpga_irq_unmask(struct irq_data *d)
{
	struct fpga_irq_data *f = irq_data_get_irq_chip_data(d);
	u32 mask = 1 << d->hwirq;

	writel(mask, f->base + IRQ_ENABLE_SET);
}

__attribute__((used)) static void fpga_irq_handle(struct irq_desc *desc)
{
	struct fpga_irq_data *f = irq_desc_get_handler_data(desc);
	u32 status = readl(f->base + IRQ_STATUS);

	if (status == 0) {
		do_bad_IRQ(desc);
		return;
	}

	do {
		unsigned int irq = ffs(status) - 1;

		status &= ~(1 << irq);
		generic_handle_irq(irq_find_mapping(f->domain, irq));
	} while (status);
}

__attribute__((used)) static int handle_one_fpga(struct fpga_irq_data *f, struct pt_regs *regs)
{
	int handled = 0;
	int irq;
	u32 status;

	while ((status  = readl(f->base + IRQ_STATUS))) {
		irq = ffs(status) - 1;
		handle_domain_irq(f->domain, irq, regs);
		handled = 1;
	}

	return handled;
}

__attribute__((used)) static int fpga_irqdomain_map(struct irq_domain *d, unsigned int irq,
		irq_hw_number_t hwirq)
{
	struct fpga_irq_data *f = d->host_data;

	/* Skip invalid IRQs, only register handlers for the real ones */
	if (!(f->valid & BIT(hwirq)))
		return -EPERM;
	irq_set_chip_data(irq, f);
	irq_set_chip_and_handler(irq, &f->chip,
				handle_level_irq);
	irq_set_probe(irq);
	return 0;
}

