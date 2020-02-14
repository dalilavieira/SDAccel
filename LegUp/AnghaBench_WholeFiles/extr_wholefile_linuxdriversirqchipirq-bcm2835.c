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
typedef  scalar_t__ u32 ;
struct irq_domain {int dummy; } ;
struct irq_data {scalar_t__ hwirq; } ;
struct device_node {int dummy; } ;
struct TYPE_2__ {scalar_t__* enable; scalar_t__ base; scalar_t__ local_base; scalar_t__* disable; } ;

/* Variables and functions */
 scalar_t__ ARM_LOCAL_GPU_INT_ROUTING ; 
 int EINVAL ; 
 size_t HWIRQ_BANK (scalar_t__) ; 
 unsigned int HWIRQ_BIT (scalar_t__) ; 
 scalar_t__ const IRQS_PER_BANK ; 
 unsigned int IRQ_TYPE_NONE ; 
 unsigned long MAKE_HWIRQ (scalar_t__ const,scalar_t__ const) ; 
 scalar_t__ const NR_BANKS ; 
 scalar_t__ const NR_IRQS_BANK0 ; 
 scalar_t__ NUMBER_IRQS ; 
 scalar_t__ REG_FIQ_CONTROL ; 
 unsigned int REG_FIQ_DISABLE ; 
 unsigned int REG_FIQ_ENABLE ; 
 scalar_t__ WARN_ON (int) ; 
 TYPE_1__ intc ; 
 int num_online_cpus () ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 unsigned int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned int,scalar_t__) ; 

__attribute__((used)) static inline unsigned int hwirq_to_fiq(unsigned long hwirq)
{
	hwirq -= NUMBER_IRQS;
	/*
	 * The hwirq numbering used in this driver is:
	 *   BASE (0-7) GPU1 (32-63) GPU2 (64-95).
	 * This differ from the one used in the FIQ register:
	 *   GPU1 (0-31) GPU2 (32-63) BASE (64-71)
	 */
	if (hwirq >= 32)
		return hwirq - 32;

	return hwirq + 64;
}

__attribute__((used)) static void armctrl_mask_irq(struct irq_data *d)
{
	if (d->hwirq >= NUMBER_IRQS)
		writel_relaxed(REG_FIQ_DISABLE, intc.base + REG_FIQ_CONTROL);
	else
		writel_relaxed(HWIRQ_BIT(d->hwirq),
			       intc.disable[HWIRQ_BANK(d->hwirq)]);
}

__attribute__((used)) static void armctrl_unmask_irq(struct irq_data *d)
{
	if (d->hwirq >= NUMBER_IRQS) {
		if (num_online_cpus() > 1) {
			unsigned int data;

			if (!intc.local_base) {
				pr_err("FIQ is disabled due to missing arm_local_intc\n");
				return;
			}

			data = readl_relaxed(intc.local_base +
					     ARM_LOCAL_GPU_INT_ROUTING);

			data &= ~0xc;
			data |= (1 << 2);
			writel_relaxed(data,
				       intc.local_base +
				       ARM_LOCAL_GPU_INT_ROUTING);
		}

		writel_relaxed(REG_FIQ_ENABLE | hwirq_to_fiq(d->hwirq),
			       intc.base + REG_FIQ_CONTROL);
	} else {
		writel_relaxed(HWIRQ_BIT(d->hwirq),
			       intc.enable[HWIRQ_BANK(d->hwirq)]);
	}
}

__attribute__((used)) static int armctrl_xlate(struct irq_domain *d, struct device_node *ctrlr,
	const u32 *intspec, unsigned int intsize,
	unsigned long *out_hwirq, unsigned int *out_type)
{
	if (WARN_ON(intsize != 2))
		return -EINVAL;

	if (WARN_ON(intspec[0] >= NR_BANKS))
		return -EINVAL;

	if (WARN_ON(intspec[1] >= IRQS_PER_BANK))
		return -EINVAL;

	if (WARN_ON(intspec[0] == 0 && intspec[1] >= NR_IRQS_BANK0))
		return -EINVAL;

	*out_hwirq = MAKE_HWIRQ(intspec[0], intspec[1]);
	*out_type = IRQ_TYPE_NONE;
	return 0;
}

