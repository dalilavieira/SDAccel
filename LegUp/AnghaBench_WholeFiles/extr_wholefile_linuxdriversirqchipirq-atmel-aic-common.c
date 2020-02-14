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
typedef  unsigned int u32 ;
struct irq_domain {int dummy; } ;
struct irq_data {int mask; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* irq_mask ) (struct irq_data*) ;} ;
struct irq_chip_type {TYPE_1__ chip; } ;
struct irq_chip_generic {struct aic_chip_data* private; } ;
struct device_node {int dummy; } ;
struct aic_chip_data {int ext_irqs; } ;
typedef  unsigned int irq_hw_number_t ;

/* Variables and functions */
 unsigned int const AT91_AIC_IRQ_MAX_PRIORITY ; 
 unsigned int const AT91_AIC_IRQ_MIN_PRIORITY ; 
 unsigned int AT91_AIC_PRIOR ; 
 unsigned int AT91_AIC_SRCTYPE ; 
 unsigned int AT91_AIC_SRCTYPE_FALLING ; 
 unsigned int AT91_AIC_SRCTYPE_HIGH ; 
 unsigned int AT91_AIC_SRCTYPE_LOW ; 
 unsigned int AT91_AIC_SRCTYPE_RISING ; 
 int EINVAL ; 
#define  IRQ_TYPE_EDGE_FALLING 131 
#define  IRQ_TYPE_EDGE_RISING 130 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 unsigned int const IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ WARN_ON (int) ; 
 struct irq_chip_type* irq_data_get_chip_type (struct irq_data*) ; 
 struct irq_chip_generic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int /*<<< orphan*/  stub1 (struct irq_data*) ; 

__attribute__((used)) static void aic_common_shutdown(struct irq_data *d)
{
	struct irq_chip_type *ct = irq_data_get_chip_type(d);

	ct->chip.irq_mask(d);
}

int aic_common_set_type(struct irq_data *d, unsigned type, unsigned *val)
{
	struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
	struct aic_chip_data *aic = gc->private;
	unsigned aic_type;

	switch (type) {
	case IRQ_TYPE_LEVEL_HIGH:
		aic_type = AT91_AIC_SRCTYPE_HIGH;
		break;
	case IRQ_TYPE_EDGE_RISING:
		aic_type = AT91_AIC_SRCTYPE_RISING;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		if (!(d->mask & aic->ext_irqs))
			return -EINVAL;

		aic_type = AT91_AIC_SRCTYPE_LOW;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		if (!(d->mask & aic->ext_irqs))
			return -EINVAL;

		aic_type = AT91_AIC_SRCTYPE_FALLING;
		break;
	default:
		return -EINVAL;
	}

	*val &= ~AT91_AIC_SRCTYPE;
	*val |= aic_type;

	return 0;
}

void aic_common_set_priority(int priority, unsigned *val)
{
	*val &= ~AT91_AIC_PRIOR;
	*val |= priority;
}

int aic_common_irq_domain_xlate(struct irq_domain *d,
				struct device_node *ctrlr,
				const u32 *intspec,
				unsigned int intsize,
				irq_hw_number_t *out_hwirq,
				unsigned int *out_type)
{
	if (WARN_ON(intsize < 3))
		return -EINVAL;

	if (WARN_ON((intspec[2] < AT91_AIC_IRQ_MIN_PRIORITY) ||
		    (intspec[2] > AT91_AIC_IRQ_MAX_PRIORITY)))
		return -EINVAL;

	*out_hwirq = intspec[0];
	*out_type = intspec[1] & IRQ_TYPE_SENSE_MASK;

	return 0;
}

