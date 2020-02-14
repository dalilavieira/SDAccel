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
struct irq_domain {struct irq_chip* host_data; } ;
struct irq_data {unsigned int hwirq; } ;
struct irq_chip {int dummy; } ;
struct device_node {int dummy; } ;
struct cpumask {int dummy; } ;
typedef  scalar_t__ irq_hw_number_t ;

/* Variables and functions */
 scalar_t__ const HW_IRQ_EXTERN_BASE ; 
 scalar_t__ HW_IRQ_IPI_COUNT ; 
 unsigned int HW_IRQ_MX_BASE ; 
 int /*<<< orphan*/  IRQ_LEVEL ; 
 int /*<<< orphan*/  MIENG ; 
 int /*<<< orphan*/  MIENGSET ; 
 int /*<<< orphan*/  MIROUT (unsigned int) ; 
 unsigned int XCHAL_INTTYPE_MASK_EXTERN_EDGE ; 
 unsigned int XCHAL_INTTYPE_MASK_EXTERN_LEVEL ; 
 unsigned int __this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __this_cpu_write (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  cached_irq_mask ; 
 int /*<<< orphan*/  cpu_online_mask ; 
 int cpumask_any_and (struct cpumask const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_of (int) ; 
 int /*<<< orphan*/  handle_percpu_irq ; 
 int /*<<< orphan*/  intclear ; 
 int /*<<< orphan*/  intenable ; 
 int /*<<< orphan*/  intset ; 
 int /*<<< orphan*/  irq_data_update_effective_affinity (struct irq_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_desc_get_irq_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler_name (unsigned int,struct irq_chip*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_to_desc (unsigned int) ; 
 int /*<<< orphan*/  irqd_set_single_target (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_er (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_sr (int,int /*<<< orphan*/ ) ; 
 unsigned int xtensa_get_ext_irq_no (unsigned int) ; 
 int xtensa_irq_domain_xlate (scalar_t__ const*,unsigned int,scalar_t__ const,scalar_t__ const,unsigned long*,unsigned int*) ; 
 int xtensa_irq_map (struct irq_domain*,unsigned int,scalar_t__) ; 

__attribute__((used)) static int xtensa_mx_irq_map(struct irq_domain *d, unsigned int irq,
		irq_hw_number_t hw)
{
	if (hw < HW_IRQ_IPI_COUNT) {
		struct irq_chip *irq_chip = d->host_data;
		irq_set_chip_and_handler_name(irq, irq_chip,
				handle_percpu_irq, "ipi");
		irq_set_status_flags(irq, IRQ_LEVEL);
		return 0;
	}
	irqd_set_single_target(irq_desc_get_irq_data(irq_to_desc(irq)));
	return xtensa_irq_map(d, irq, hw);
}

__attribute__((used)) static int xtensa_mx_irq_domain_xlate(struct irq_domain *d,
		struct device_node *ctrlr,
		const u32 *intspec, unsigned int intsize,
		unsigned long *out_hwirq, unsigned int *out_type)
{
	return xtensa_irq_domain_xlate(intspec, intsize,
			intspec[0], intspec[0] + HW_IRQ_EXTERN_BASE,
			out_hwirq, out_type);
}

void secondary_init_irq(void)
{
	__this_cpu_write(cached_irq_mask,
			XCHAL_INTTYPE_MASK_EXTERN_EDGE |
			XCHAL_INTTYPE_MASK_EXTERN_LEVEL);
	set_sr(XCHAL_INTTYPE_MASK_EXTERN_EDGE |
			XCHAL_INTTYPE_MASK_EXTERN_LEVEL, intenable);
}

__attribute__((used)) static void xtensa_mx_irq_mask(struct irq_data *d)
{
	unsigned int mask = 1u << d->hwirq;

	if (mask & (XCHAL_INTTYPE_MASK_EXTERN_EDGE |
				XCHAL_INTTYPE_MASK_EXTERN_LEVEL)) {
		set_er(1u << (xtensa_get_ext_irq_no(d->hwirq) -
					HW_IRQ_MX_BASE), MIENG);
	} else {
		mask = __this_cpu_read(cached_irq_mask) & ~mask;
		__this_cpu_write(cached_irq_mask, mask);
		set_sr(mask, intenable);
	}
}

__attribute__((used)) static void xtensa_mx_irq_unmask(struct irq_data *d)
{
	unsigned int mask = 1u << d->hwirq;

	if (mask & (XCHAL_INTTYPE_MASK_EXTERN_EDGE |
				XCHAL_INTTYPE_MASK_EXTERN_LEVEL)) {
		set_er(1u << (xtensa_get_ext_irq_no(d->hwirq) -
					HW_IRQ_MX_BASE), MIENGSET);
	} else {
		mask |= __this_cpu_read(cached_irq_mask);
		__this_cpu_write(cached_irq_mask, mask);
		set_sr(mask, intenable);
	}
}

__attribute__((used)) static void xtensa_mx_irq_enable(struct irq_data *d)
{
	xtensa_mx_irq_unmask(d);
}

__attribute__((used)) static void xtensa_mx_irq_disable(struct irq_data *d)
{
	xtensa_mx_irq_mask(d);
}

__attribute__((used)) static void xtensa_mx_irq_ack(struct irq_data *d)
{
	set_sr(1 << d->hwirq, intclear);
}

__attribute__((used)) static int xtensa_mx_irq_retrigger(struct irq_data *d)
{
	set_sr(1 << d->hwirq, intset);
	return 1;
}

__attribute__((used)) static int xtensa_mx_irq_set_affinity(struct irq_data *d,
		const struct cpumask *dest, bool force)
{
	int cpu = cpumask_any_and(dest, cpu_online_mask);
	unsigned mask = 1u << cpu;

	set_er(mask, MIROUT(d->hwirq - HW_IRQ_MX_BASE));
	irq_data_update_effective_affinity(d, cpumask_of(cpu));

	return 0;

}

