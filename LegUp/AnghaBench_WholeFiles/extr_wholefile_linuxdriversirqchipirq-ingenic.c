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
typedef  int /*<<< orphan*/  uint32_t ;
struct irq_data {int dummy; } ;
struct irq_chip_regs {scalar_t__ disable; scalar_t__ enable; } ;
struct irq_chip_generic {int /*<<< orphan*/  mask_cache; int /*<<< orphan*/  wake_active; scalar_t__ reg_base; TYPE_1__* chip_types; } ;
struct ingenic_intc_data {unsigned int num_chips; scalar_t__ base; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {struct irq_chip_regs regs; } ;

/* Variables and functions */
 unsigned int CHIP_SIZE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ JZ4740_IRQ_BASE ; 
 scalar_t__ JZ_REG_INTC_PENDING ; 
 scalar_t__ __fls (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_handle_irq (scalar_t__) ; 
 struct irq_chip_generic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct ingenic_intc_data* irq_get_handler_data (int) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static irqreturn_t intc_cascade(int irq, void *data)
{
	struct ingenic_intc_data *intc = irq_get_handler_data(irq);
	uint32_t irq_reg;
	unsigned i;

	for (i = 0; i < intc->num_chips; i++) {
		irq_reg = readl(intc->base + (i * CHIP_SIZE) +
				JZ_REG_INTC_PENDING);
		if (!irq_reg)
			continue;

		generic_handle_irq(__fls(irq_reg) + (i * 32) + JZ4740_IRQ_BASE);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static void intc_irq_set_mask(struct irq_chip_generic *gc, uint32_t mask)
{
	struct irq_chip_regs *regs = &gc->chip_types->regs;

	writel(mask, gc->reg_base + regs->enable);
	writel(~mask, gc->reg_base + regs->disable);
}

void ingenic_intc_irq_suspend(struct irq_data *data)
{
	struct irq_chip_generic *gc = irq_data_get_irq_chip_data(data);
	intc_irq_set_mask(gc, gc->wake_active);
}

void ingenic_intc_irq_resume(struct irq_data *data)
{
	struct irq_chip_generic *gc = irq_data_get_irq_chip_data(data);
	intc_irq_set_mask(gc, gc->mask_cache);
}

