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
struct pt_regs {int dummy; } ;
struct or1k_pic_dev {int /*<<< orphan*/  flags; int /*<<< orphan*/  handle; int /*<<< orphan*/  chip; } ;
struct irq_domain {struct or1k_pic_dev* host_data; } ;
struct irq_data {unsigned long hwirq; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int NO_IRQ ; 
 int /*<<< orphan*/  SPR_PICMR ; 
 int /*<<< orphan*/  SPR_PICSR ; 
 int ffs (int) ; 
 int /*<<< orphan*/  handle_domain_irq (int /*<<< orphan*/ ,int,struct pt_regs*) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  root_domain ; 

__attribute__((used)) static void or1k_pic_mask(struct irq_data *data)
{
	mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(1UL << data->hwirq));
}

__attribute__((used)) static void or1k_pic_unmask(struct irq_data *data)
{
	mtspr(SPR_PICMR, mfspr(SPR_PICMR) | (1UL << data->hwirq));
}

__attribute__((used)) static void or1k_pic_ack(struct irq_data *data)
{
	mtspr(SPR_PICSR, (1UL << data->hwirq));
}

__attribute__((used)) static void or1k_pic_mask_ack(struct irq_data *data)
{
	mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(1UL << data->hwirq));
	mtspr(SPR_PICSR, (1UL << data->hwirq));
}

__attribute__((used)) static void or1k_pic_or1200_ack(struct irq_data *data)
{
	mtspr(SPR_PICSR, mfspr(SPR_PICSR) & ~(1UL << data->hwirq));
}

__attribute__((used)) static void or1k_pic_or1200_mask_ack(struct irq_data *data)
{
	mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(1UL << data->hwirq));
	mtspr(SPR_PICSR, mfspr(SPR_PICSR) & ~(1UL << data->hwirq));
}

__attribute__((used)) static inline int pic_get_irq(int first)
{
	int hwirq;

	hwirq = ffs(mfspr(SPR_PICSR) >> first);
	if (!hwirq)
		return NO_IRQ;
	else
		hwirq = hwirq + first - 1;

	return hwirq;
}

__attribute__((used)) static void or1k_pic_handle_irq(struct pt_regs *regs)
{
	int irq = -1;

	while ((irq = pic_get_irq(irq + 1)) != NO_IRQ)
		handle_domain_irq(root_domain, irq, regs);
}

__attribute__((used)) static int or1k_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
	struct or1k_pic_dev *pic = d->host_data;

	irq_set_chip_and_handler(irq, &pic->chip, pic->handle);
	irq_set_status_flags(irq, pic->flags);

	return 0;
}

