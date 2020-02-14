#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct mtk_cirq_chip_data {scalar_t__ base; } ;
struct irq_fwspec {int param_count; unsigned long* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {TYPE_2__* parent; int /*<<< orphan*/  host_data; } ;
struct irq_data {unsigned int hwirq; TYPE_1__* chip; struct irq_data* parent_data; struct mtk_cirq_chip_data* chip_data; } ;
typedef  unsigned long irq_hw_number_t ;
struct TYPE_6__ {unsigned long ext_irq_start; unsigned long ext_irq_end; } ;
struct TYPE_5__ {int /*<<< orphan*/  fwnode; } ;
struct TYPE_4__ {int (* irq_set_type ) (struct irq_data*,unsigned int) ;} ;

/* Variables and functions */
 unsigned int CIRQ_MASK_CLR ; 
 unsigned int CIRQ_MASK_SET ; 
 unsigned int CIRQ_POL_CLR ; 
 unsigned int CIRQ_POL_SET ; 
 unsigned int CIRQ_SENS_CLR ; 
 unsigned int CIRQ_SENS_SET ; 
 int EINVAL ; 
#define  IRQ_TYPE_EDGE_FALLING 131 
#define  IRQ_TYPE_EDGE_RISING 130 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ WARN_ON (int) ; 
 TYPE_3__* cirq_data ; 
 int /*<<< orphan*/  irq_chip_mask_parent (struct irq_data*) ; 
 int /*<<< orphan*/  irq_chip_unmask_parent (struct irq_data*) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,unsigned int,struct irq_fwspec*) ; 
 int /*<<< orphan*/  irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ is_of_node (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_cirq_chip ; 
 int stub1 (struct irq_data*,unsigned int) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void mtk_cirq_write_mask(struct irq_data *data, unsigned int offset)
{
	struct mtk_cirq_chip_data *chip_data = data->chip_data;
	unsigned int cirq_num = data->hwirq;
	u32 mask = 1 << (cirq_num % 32);

	writel_relaxed(mask, chip_data->base + offset + (cirq_num / 32) * 4);
}

__attribute__((used)) static void mtk_cirq_mask(struct irq_data *data)
{
	mtk_cirq_write_mask(data, CIRQ_MASK_SET);
	irq_chip_mask_parent(data);
}

__attribute__((used)) static void mtk_cirq_unmask(struct irq_data *data)
{
	mtk_cirq_write_mask(data, CIRQ_MASK_CLR);
	irq_chip_unmask_parent(data);
}

__attribute__((used)) static int mtk_cirq_set_type(struct irq_data *data, unsigned int type)
{
	int ret;

	switch (type & IRQ_TYPE_SENSE_MASK) {
	case IRQ_TYPE_EDGE_FALLING:
		mtk_cirq_write_mask(data, CIRQ_POL_CLR);
		mtk_cirq_write_mask(data, CIRQ_SENS_CLR);
		break;
	case IRQ_TYPE_EDGE_RISING:
		mtk_cirq_write_mask(data, CIRQ_POL_SET);
		mtk_cirq_write_mask(data, CIRQ_SENS_CLR);
		break;
	case IRQ_TYPE_LEVEL_LOW:
		mtk_cirq_write_mask(data, CIRQ_POL_CLR);
		mtk_cirq_write_mask(data, CIRQ_SENS_SET);
		break;
	case IRQ_TYPE_LEVEL_HIGH:
		mtk_cirq_write_mask(data, CIRQ_POL_SET);
		mtk_cirq_write_mask(data, CIRQ_SENS_SET);
		break;
	default:
		break;
	}

	data = data->parent_data;
	ret = data->chip->irq_set_type(data, type);
	return ret;
}

__attribute__((used)) static int mtk_cirq_domain_translate(struct irq_domain *d,
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

		/* cirq support irq number check */
		if (fwspec->param[1] < cirq_data->ext_irq_start ||
		    fwspec->param[1] > cirq_data->ext_irq_end)
			return -EINVAL;

		*hwirq = fwspec->param[1] - cirq_data->ext_irq_start;
		*type = fwspec->param[2] & IRQ_TYPE_SENSE_MASK;
		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int mtk_cirq_domain_alloc(struct irq_domain *domain, unsigned int virq,
				 unsigned int nr_irqs, void *arg)
{
	int ret;
	irq_hw_number_t hwirq;
	unsigned int type;
	struct irq_fwspec *fwspec = arg;
	struct irq_fwspec parent_fwspec = *fwspec;

	ret = mtk_cirq_domain_translate(domain, fwspec, &hwirq, &type);
	if (ret)
		return ret;

	if (WARN_ON(nr_irqs != 1))
		return -EINVAL;

	irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
				      &mtk_cirq_chip,
				      domain->host_data);

	parent_fwspec.fwnode = domain->parent->fwnode;
	return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
					    &parent_fwspec);
}

__attribute__((used)) static inline void mtk_cirq_syscore_init(void) {}

