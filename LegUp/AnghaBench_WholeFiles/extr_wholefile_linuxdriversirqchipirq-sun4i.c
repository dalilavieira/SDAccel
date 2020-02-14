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
struct irq_domain {int dummy; } ;
struct irq_data {int dummy; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 scalar_t__ SUN4I_IRQ_ENABLE_REG (int) ; 
 scalar_t__ SUN4I_IRQ_PENDING_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_fasteoi_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_probe (unsigned int) ; 
 unsigned int irqd_to_hwirq (struct irq_data*) ; 
 int readl (scalar_t__) ; 
 scalar_t__ sun4i_irq_base ; 
 int /*<<< orphan*/  sun4i_irq_chip ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void sun4i_irq_ack(struct irq_data *irqd)
{
	unsigned int irq = irqd_to_hwirq(irqd);

	if (irq != 0)
		return; /* Only IRQ 0 / the ENMI needs to be acked */

	writel(BIT(0), sun4i_irq_base + SUN4I_IRQ_PENDING_REG(0));
}

__attribute__((used)) static void sun4i_irq_mask(struct irq_data *irqd)
{
	unsigned int irq = irqd_to_hwirq(irqd);
	unsigned int irq_off = irq % 32;
	int reg = irq / 32;
	u32 val;

	val = readl(sun4i_irq_base + SUN4I_IRQ_ENABLE_REG(reg));
	writel(val & ~(1 << irq_off),
	       sun4i_irq_base + SUN4I_IRQ_ENABLE_REG(reg));
}

__attribute__((used)) static void sun4i_irq_unmask(struct irq_data *irqd)
{
	unsigned int irq = irqd_to_hwirq(irqd);
	unsigned int irq_off = irq % 32;
	int reg = irq / 32;
	u32 val;

	val = readl(sun4i_irq_base + SUN4I_IRQ_ENABLE_REG(reg));
	writel(val | (1 << irq_off),
	       sun4i_irq_base + SUN4I_IRQ_ENABLE_REG(reg));
}

__attribute__((used)) static int sun4i_irq_map(struct irq_domain *d, unsigned int virq,
			 irq_hw_number_t hw)
{
	irq_set_chip_and_handler(virq, &sun4i_irq_chip, handle_fasteoi_irq);
	irq_set_probe(virq);

	return 0;
}

