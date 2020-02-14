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
typedef  int u16 ;
struct vf610_mscm_ir_chip_data {int* saved_irsprc; int cpu_mask; scalar_t__ is_nvic; scalar_t__ mscm_ir_base; } ;
struct notifier_block {int dummy; } ;
struct irq_fwspec {int param_count; int* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {TYPE_1__* parent; int /*<<< orphan*/  host_data; } ;
struct irq_data {int hwirq; struct vf610_mscm_ir_chip_data* chip_data; } ;
typedef  int irq_hw_number_t ;
struct TYPE_2__ {int /*<<< orphan*/  fwnode; } ;

/* Variables and functions */
#define  CPU_CLUSTER_PM_ENTER 130 
#define  CPU_CLUSTER_PM_ENTER_FAILED 129 
#define  CPU_CLUSTER_PM_EXIT 128 
 int EINVAL ; 
 int GIC_SPI ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ MSCM_IRSPRC (int) ; 
 int MSCM_IRSPRC_CPEN_MASK ; 
 int MSCM_IRSPRC_NUM ; 
 int NOTIFY_OK ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  irq_chip_disable_parent (struct irq_data*) ; 
 int /*<<< orphan*/  irq_chip_enable_parent (struct irq_data*) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,unsigned int,struct irq_fwspec*) ; 
 int /*<<< orphan*/  irq_domain_get_of_node (TYPE_1__*) ; 
 int /*<<< orphan*/  irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct vf610_mscm_ir_chip_data* mscm_ir_data ; 
 void* readw_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  vf610_mscm_ir_irq_chip ; 
 int /*<<< orphan*/  writew_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline void vf610_mscm_ir_save(struct vf610_mscm_ir_chip_data *data)
{
	int i;

	for (i = 0; i < MSCM_IRSPRC_NUM; i++)
		data->saved_irsprc[i] = readw_relaxed(data->mscm_ir_base + MSCM_IRSPRC(i));
}

__attribute__((used)) static inline void vf610_mscm_ir_restore(struct vf610_mscm_ir_chip_data *data)
{
	int i;

	for (i = 0; i < MSCM_IRSPRC_NUM; i++)
		writew_relaxed(data->saved_irsprc[i], data->mscm_ir_base + MSCM_IRSPRC(i));
}

__attribute__((used)) static int vf610_mscm_ir_notifier(struct notifier_block *self,
				  unsigned long cmd, void *v)
{
	switch (cmd) {
	case CPU_CLUSTER_PM_ENTER:
		vf610_mscm_ir_save(mscm_ir_data);
		break;
	case CPU_CLUSTER_PM_ENTER_FAILED:
	case CPU_CLUSTER_PM_EXIT:
		vf610_mscm_ir_restore(mscm_ir_data);
		break;
	}

	return NOTIFY_OK;
}

__attribute__((used)) static void vf610_mscm_ir_enable(struct irq_data *data)
{
	irq_hw_number_t hwirq = data->hwirq;
	struct vf610_mscm_ir_chip_data *chip_data = data->chip_data;
	u16 irsprc;

	irsprc = readw_relaxed(chip_data->mscm_ir_base + MSCM_IRSPRC(hwirq));
	irsprc &= MSCM_IRSPRC_CPEN_MASK;

	WARN_ON(irsprc & ~chip_data->cpu_mask);

	writew_relaxed(chip_data->cpu_mask,
		       chip_data->mscm_ir_base + MSCM_IRSPRC(hwirq));

	irq_chip_enable_parent(data);
}

__attribute__((used)) static void vf610_mscm_ir_disable(struct irq_data *data)
{
	irq_hw_number_t hwirq = data->hwirq;
	struct vf610_mscm_ir_chip_data *chip_data = data->chip_data;

	writew_relaxed(0x0, chip_data->mscm_ir_base + MSCM_IRSPRC(hwirq));

	irq_chip_disable_parent(data);
}

__attribute__((used)) static int vf610_mscm_ir_domain_alloc(struct irq_domain *domain, unsigned int virq,
				      unsigned int nr_irqs, void *arg)
{
	int i;
	irq_hw_number_t hwirq;
	struct irq_fwspec *fwspec = arg;
	struct irq_fwspec parent_fwspec;

	if (!irq_domain_get_of_node(domain->parent))
		return -EINVAL;

	if (fwspec->param_count != 2)
		return -EINVAL;

	hwirq = fwspec->param[0];
	for (i = 0; i < nr_irqs; i++)
		irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
					      &vf610_mscm_ir_irq_chip,
					      domain->host_data);

	parent_fwspec.fwnode = domain->parent->fwnode;

	if (mscm_ir_data->is_nvic) {
		parent_fwspec.param_count = 1;
		parent_fwspec.param[0] = fwspec->param[0];
	} else {
		parent_fwspec.param_count = 3;
		parent_fwspec.param[0] = GIC_SPI;
		parent_fwspec.param[1] = fwspec->param[0];
		parent_fwspec.param[2] = fwspec->param[1];
	}

	return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
					    &parent_fwspec);
}

__attribute__((used)) static int vf610_mscm_ir_domain_translate(struct irq_domain *d,
					  struct irq_fwspec *fwspec,
					  unsigned long *hwirq,
					  unsigned int *type)
{
	if (WARN_ON(fwspec->param_count < 2))
		return -EINVAL;
	*hwirq = fwspec->param[0];
	*type = fwspec->param[1] & IRQ_TYPE_SENSE_MASK;
	return 0;
}

