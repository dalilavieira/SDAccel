#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct irq_fwspec {int param_count; int* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {TYPE_1__* parent; } ;
struct irq_data {size_t hwirq; } ;
typedef  scalar_t__ irq_hw_number_t ;
struct TYPE_4__ {int int_max; scalar_t__* irq_map; scalar_t__ max_crossbar_sources; scalar_t__ safe_map; int /*<<< orphan*/  lock; int /*<<< orphan*/  (* write ) (size_t,scalar_t__) ;scalar_t__* register_offsets; scalar_t__ crossbar_base; } ;
struct TYPE_3__ {int /*<<< orphan*/  fwnode; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ IRQ_FREE ; 
 int IRQ_TYPE_LEVEL_HIGH ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 TYPE_2__* cb ; 
 int /*<<< orphan*/  crossbar_chip ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,int,struct irq_fwspec*) ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_domain_get_of_node (TYPE_1__*) ; 
 int /*<<< orphan*/  irq_domain_reset_irq_data (struct irq_data*) ; 
 int /*<<< orphan*/  irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ is_of_node (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int,scalar_t__) ; 
 int /*<<< orphan*/  stub2 (size_t,scalar_t__) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

__attribute__((used)) static void crossbar_writel(int irq_no, int cb_no)
{
	writel(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}

__attribute__((used)) static void crossbar_writew(int irq_no, int cb_no)
{
	writew(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}

__attribute__((used)) static void crossbar_writeb(int irq_no, int cb_no)
{
	writeb(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}

__attribute__((used)) static int allocate_gic_irq(struct irq_domain *domain, unsigned virq,
			    irq_hw_number_t hwirq)
{
	struct irq_fwspec fwspec;
	int i;
	int err;

	if (!irq_domain_get_of_node(domain->parent))
		return -EINVAL;

	raw_spin_lock(&cb->lock);
	for (i = cb->int_max - 1; i >= 0; i--) {
		if (cb->irq_map[i] == IRQ_FREE) {
			cb->irq_map[i] = hwirq;
			break;
		}
	}
	raw_spin_unlock(&cb->lock);

	if (i < 0)
		return -ENODEV;

	fwspec.fwnode = domain->parent->fwnode;
	fwspec.param_count = 3;
	fwspec.param[0] = 0;	/* SPI */
	fwspec.param[1] = i;
	fwspec.param[2] = IRQ_TYPE_LEVEL_HIGH;

	err = irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
	if (err)
		cb->irq_map[i] = IRQ_FREE;
	else
		cb->write(i, hwirq);

	return err;
}

__attribute__((used)) static int crossbar_domain_alloc(struct irq_domain *d, unsigned int virq,
				 unsigned int nr_irqs, void *data)
{
	struct irq_fwspec *fwspec = data;
	irq_hw_number_t hwirq;
	int i;

	if (fwspec->param_count != 3)
		return -EINVAL;	/* Not GIC compliant */
	if (fwspec->param[0] != 0)
		return -EINVAL;	/* No PPI should point to this domain */

	hwirq = fwspec->param[1];
	if ((hwirq + nr_irqs) > cb->max_crossbar_sources)
		return -EINVAL;	/* Can't deal with this */

	for (i = 0; i < nr_irqs; i++) {
		int err = allocate_gic_irq(d, virq + i, hwirq + i);

		if (err)
			return err;

		irq_domain_set_hwirq_and_chip(d, virq + i, hwirq + i,
					      &crossbar_chip, NULL);
	}

	return 0;
}

__attribute__((used)) static void crossbar_domain_free(struct irq_domain *domain, unsigned int virq,
				 unsigned int nr_irqs)
{
	int i;

	raw_spin_lock(&cb->lock);
	for (i = 0; i < nr_irqs; i++) {
		struct irq_data *d = irq_domain_get_irq_data(domain, virq + i);

		irq_domain_reset_irq_data(d);
		cb->irq_map[d->hwirq] = IRQ_FREE;
		cb->write(d->hwirq, cb->safe_map);
	}
	raw_spin_unlock(&cb->lock);
}

__attribute__((used)) static int crossbar_domain_translate(struct irq_domain *d,
				     struct irq_fwspec *fwspec,
				     unsigned long *hwirq,
				     unsigned int *type)
{
	if (is_of_node(fwspec->fwnode)) {
		if (fwspec->param_count != 3)
			return -EINVAL;

		/* No PPI should point to this domain */
		if (fwspec->param[0] != 0)
			return -EINVAL;

		*hwirq = fwspec->param[1];
		*type = fwspec->param[2] & IRQ_TYPE_SENSE_MASK;
		return 0;
	}

	return -EINVAL;
}

