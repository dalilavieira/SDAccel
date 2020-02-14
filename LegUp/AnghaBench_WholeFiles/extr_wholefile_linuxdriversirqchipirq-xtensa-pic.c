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
typedef  int /*<<< orphan*/  u32 ;
struct irq_domain {int dummy; } ;
struct irq_data {int hwirq; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int cached_irq_mask ; 
 int /*<<< orphan*/  intclear ; 
 int /*<<< orphan*/  intenable ; 
 int /*<<< orphan*/  intset ; 
 int /*<<< orphan*/  set_sr (int,int /*<<< orphan*/ ) ; 
 int xtensa_irq_domain_xlate (int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/  const,int /*<<< orphan*/  const,unsigned long*,unsigned int*) ; 

__attribute__((used)) static int xtensa_pic_irq_domain_xlate(struct irq_domain *d,
		struct device_node *ctrlr,
		const u32 *intspec, unsigned int intsize,
		unsigned long *out_hwirq, unsigned int *out_type)
{
	return xtensa_irq_domain_xlate(intspec, intsize,
			intspec[0], intspec[0],
			out_hwirq, out_type);
}

__attribute__((used)) static void xtensa_irq_mask(struct irq_data *d)
{
	cached_irq_mask &= ~(1 << d->hwirq);
	set_sr(cached_irq_mask, intenable);
}

__attribute__((used)) static void xtensa_irq_unmask(struct irq_data *d)
{
	cached_irq_mask |= 1 << d->hwirq;
	set_sr(cached_irq_mask, intenable);
}

__attribute__((used)) static void xtensa_irq_enable(struct irq_data *d)
{
	xtensa_irq_unmask(d);
}

__attribute__((used)) static void xtensa_irq_disable(struct irq_data *d)
{
	xtensa_irq_mask(d);
}

__attribute__((used)) static void xtensa_irq_ack(struct irq_data *d)
{
	set_sr(1 << d->hwirq, intclear);
}

__attribute__((used)) static int xtensa_irq_retrigger(struct irq_data *d)
{
	set_sr(1 << d->hwirq, intset);
	return 1;
}

