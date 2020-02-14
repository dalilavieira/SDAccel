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
struct irq_domain {int dummy; } ;
struct irq_data {unsigned int hwirq; } ;
typedef  int irq_hw_number_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IER ; 
 int /*<<< orphan*/  IRQ_LEVEL ; 
 int NR_PRIORITY_IRQS ; 
 int /*<<< orphan*/  and_creg (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  core_chip ; 
 int /*<<< orphan*/  core_irq_lock ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  or_creg (int /*<<< orphan*/ ,int) ; 
 unsigned int* prio_to_virq ; 
 int /*<<< orphan*/  raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mask_core_irq(struct irq_data *data)
{
	unsigned int prio = data->hwirq;

	raw_spin_lock(&core_irq_lock);
	and_creg(IER, ~(1 << prio));
	raw_spin_unlock(&core_irq_lock);
}

__attribute__((used)) static void unmask_core_irq(struct irq_data *data)
{
	unsigned int prio = data->hwirq;

	raw_spin_lock(&core_irq_lock);
	or_creg(IER, 1 << prio);
	raw_spin_unlock(&core_irq_lock);
}

__attribute__((used)) static int core_domain_map(struct irq_domain *h, unsigned int virq,
			   irq_hw_number_t hw)
{
	if (hw < 4 || hw >= NR_PRIORITY_IRQS)
		return -EINVAL;

	prio_to_virq[hw] = virq;

	irq_set_status_flags(virq, IRQ_LEVEL);
	irq_set_chip_and_handler(virq, &core_chip, handle_level_irq);
	return 0;
}

