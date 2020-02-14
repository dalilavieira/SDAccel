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
typedef  unsigned int u32 ;
struct irq_domain {int dummy; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int hwirq; } ;
struct irq_chip {int dummy; } ;
typedef  int irq_hw_number_t ;
struct TYPE_2__ {int intr_mask; int /*<<< orphan*/  root_domain; scalar_t__ base; } ;

/* Variables and functions */
 int CIE ; 
 int IAR ; 
 int /*<<< orphan*/  IRQ_LEVEL ; 
 int IVR ; 
 int SIE ; 
 int /*<<< orphan*/  chained_irq_enter (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  chained_irq_exit (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  intc_dev ; 
 unsigned int ioread32 (scalar_t__) ; 
 unsigned int ioread32be (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite32be (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  irq_clear_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 unsigned int irq_find_mapping (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler_name (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 scalar_t__ irqd_is_level_type (struct irq_data*) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned int,...) ; 
 scalar_t__ static_branch_unlikely (int /*<<< orphan*/ *) ; 
 TYPE_1__* xintc_irqc ; 
 int /*<<< orphan*/  xintc_is_be ; 

__attribute__((used)) static void xintc_write(int reg, u32 data)
{
	if (static_branch_unlikely(&xintc_is_be))
		iowrite32be(data, xintc_irqc->base + reg);
	else
		iowrite32(data, xintc_irqc->base + reg);
}

__attribute__((used)) static unsigned int xintc_read(int reg)
{
	if (static_branch_unlikely(&xintc_is_be))
		return ioread32be(xintc_irqc->base + reg);
	else
		return ioread32(xintc_irqc->base + reg);
}

__attribute__((used)) static void intc_enable_or_unmask(struct irq_data *d)
{
	unsigned long mask = 1 << d->hwirq;

	pr_debug("irq-xilinx: enable_or_unmask: %ld\n", d->hwirq);

	/* ack level irqs because they can't be acked during
	 * ack function since the handle_level_irq function
	 * acks the irq before calling the interrupt handler
	 */
	if (irqd_is_level_type(d))
		xintc_write(IAR, mask);

	xintc_write(SIE, mask);
}

__attribute__((used)) static void intc_disable_or_mask(struct irq_data *d)
{
	pr_debug("irq-xilinx: disable: %ld\n", d->hwirq);
	xintc_write(CIE, 1 << d->hwirq);
}

__attribute__((used)) static void intc_ack(struct irq_data *d)
{
	pr_debug("irq-xilinx: ack: %ld\n", d->hwirq);
	xintc_write(IAR, 1 << d->hwirq);
}

__attribute__((used)) static void intc_mask_ack(struct irq_data *d)
{
	unsigned long mask = 1 << d->hwirq;

	pr_debug("irq-xilinx: disable_and_ack: %ld\n", d->hwirq);
	xintc_write(CIE, mask);
	xintc_write(IAR, mask);
}

unsigned int xintc_get_irq(void)
{
	unsigned int hwirq, irq = -1;

	hwirq = xintc_read(IVR);
	if (hwirq != -1U)
		irq = irq_find_mapping(xintc_irqc->root_domain, hwirq);

	pr_debug("irq-xilinx: hwirq=%d, irq=%d\n", hwirq, irq);

	return irq;
}

__attribute__((used)) static int xintc_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
	if (xintc_irqc->intr_mask & (1 << hw)) {
		irq_set_chip_and_handler_name(irq, &intc_dev,
						handle_edge_irq, "edge");
		irq_clear_status_flags(irq, IRQ_LEVEL);
	} else {
		irq_set_chip_and_handler_name(irq, &intc_dev,
						handle_level_irq, "level");
		irq_set_status_flags(irq, IRQ_LEVEL);
	}
	return 0;
}

__attribute__((used)) static void xil_intc_irq_handler(struct irq_desc *desc)
{
	struct irq_chip *chip = irq_desc_get_chip(desc);
	u32 pending;

	chained_irq_enter(chip, desc);
	do {
		pending = xintc_get_irq();
		if (pending == -1U)
			break;
		generic_handle_irq(pending);
	} while (true);
	chained_irq_exit(chip, desc);
}

