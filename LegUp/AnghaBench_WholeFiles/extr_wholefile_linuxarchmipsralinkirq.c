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
typedef  scalar_t__ u32 ;
struct irq_domain {int dummy; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int /*<<< orphan*/  hwirq; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 scalar_t__ BIT (int /*<<< orphan*/ ) ; 
 unsigned int CP0_LEGACY_COMPARE_IRQ ; 
 unsigned int INTC_REG_DISABLE ; 
 unsigned int INTC_REG_ENABLE ; 
 unsigned int INTC_REG_STATUS0 ; 
 int /*<<< orphan*/  __ffs (scalar_t__) ; 
 scalar_t__ __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 struct irq_domain* irq_desc_get_handler_data (struct irq_desc*) ; 
 int /*<<< orphan*/  irq_find_mapping (struct irq_domain*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ralink_intc_irq_chip ; 
 scalar_t__ rt_intc_membase ; 
 scalar_t__* rt_intc_regs ; 
 int rt_perfcount_irq ; 
 int /*<<< orphan*/  spurious_interrupt () ; 

__attribute__((used)) static inline void rt_intc_w32(u32 val, unsigned reg)
{
	__raw_writel(val, rt_intc_membase + rt_intc_regs[reg]);
}

__attribute__((used)) static inline u32 rt_intc_r32(unsigned reg)
{
	return __raw_readl(rt_intc_membase + rt_intc_regs[reg]);
}

__attribute__((used)) static void ralink_intc_irq_unmask(struct irq_data *d)
{
	rt_intc_w32(BIT(d->hwirq), INTC_REG_ENABLE);
}

__attribute__((used)) static void ralink_intc_irq_mask(struct irq_data *d)
{
	rt_intc_w32(BIT(d->hwirq), INTC_REG_DISABLE);
}

int get_c0_perfcount_int(void)
{
	return rt_perfcount_irq;
}

unsigned int get_c0_compare_int(void)
{
	return CP0_LEGACY_COMPARE_IRQ;
}

__attribute__((used)) static void ralink_intc_irq_handler(struct irq_desc *desc)
{
	u32 pending = rt_intc_r32(INTC_REG_STATUS0);

	if (pending) {
		struct irq_domain *domain = irq_desc_get_handler_data(desc);
		generic_handle_irq(irq_find_mapping(domain, __ffs(pending)));
	} else {
		spurious_interrupt();
	}
}

__attribute__((used)) static int intc_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
	irq_set_chip_and_handler(irq, &ralink_intc_irq_chip, handle_level_irq);

	return 0;
}

