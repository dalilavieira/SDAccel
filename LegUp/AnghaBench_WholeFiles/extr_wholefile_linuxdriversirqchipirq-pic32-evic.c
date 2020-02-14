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
typedef  int u32 ;
struct irq_domain {struct evic_chip_data* host_data; } ;
struct irq_data {scalar_t__ hwirq; TYPE_1__* domain; } ;
struct evic_chip_data {scalar_t__* ext_irqs; int* irq_types; } ;
struct device_node {int dummy; } ;
typedef  size_t irq_hw_number_t ;
struct TYPE_2__ {scalar_t__ host_data; } ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 int BIT (int) ; 
 int EBADR ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_REG_MASK (size_t,int,int) ; 
 int IRQ_SET_MASK_OK ; 
 unsigned int IRQ_TYPE_EDGE_BOTH ; 
#define  IRQ_TYPE_EDGE_FALLING 129 
#define  IRQ_TYPE_EDGE_RISING 128 
 int IRQ_TYPE_SENSE_MASK ; 
 int const NR_IRQS ; 
 int PIC32_CLR (scalar_t__) ; 
 int PIC32_INT_PRI (int,int /*<<< orphan*/ ) ; 
 int PIC32_SET (scalar_t__) ; 
 int PRIORITY_MASK ; 
 scalar_t__ REG_IEC_OFFSET ; 
 scalar_t__ REG_IFS_OFFSET ; 
 scalar_t__ REG_INTCON ; 
 scalar_t__ REG_IPC_OFFSET ; 
 int REG_OFF_OFFSET ; 
 scalar_t__ WARN_ON (int) ; 
 int evic_base ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int irq_map_generic_chip (struct irq_domain*,unsigned int,size_t) ; 
 int /*<<< orphan*/  irq_setup_alt_chip (struct irq_data*,unsigned int) ; 
 int /*<<< orphan*/  irqd_set_trigger_type (struct irq_data*,unsigned int) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static struct evic_chip_data *irqd_to_priv(struct irq_data *data)
{
	return (struct evic_chip_data *)data->domain->host_data;
}

__attribute__((used)) static int pic32_set_ext_polarity(int bit, u32 type)
{
	/*
	 * External interrupts can be either edge rising or edge falling,
	 * but not both.
	 */
	switch (type) {
	case IRQ_TYPE_EDGE_RISING:
		writel(BIT(bit), evic_base + PIC32_SET(REG_INTCON));
		break;
	case IRQ_TYPE_EDGE_FALLING:
		writel(BIT(bit), evic_base + PIC32_CLR(REG_INTCON));
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int pic32_set_type_edge(struct irq_data *data,
			       unsigned int flow_type)
{
	struct evic_chip_data *priv = irqd_to_priv(data);
	int ret;
	int i;

	if (!(flow_type & IRQ_TYPE_EDGE_BOTH))
		return -EBADR;

	/* set polarity for external interrupts only */
	for (i = 0; i < ARRAY_SIZE(priv->ext_irqs); i++) {
		if (priv->ext_irqs[i] == data->hwirq) {
			ret = pic32_set_ext_polarity(i, flow_type);
			if (ret)
				return ret;
		}
	}

	irqd_set_trigger_type(data, flow_type);

	return IRQ_SET_MASK_OK;
}

__attribute__((used)) static void pic32_bind_evic_interrupt(int irq, int set)
{
	writel(set, evic_base + REG_OFF_OFFSET + irq * 4);
}

__attribute__((used)) static void pic32_set_irq_priority(int irq, int priority)
{
	u32 reg, shift;

	reg = irq / 4;
	shift = (irq % 4) * 8;

	writel(PRIORITY_MASK << shift,
		evic_base + PIC32_CLR(REG_IPC_OFFSET + reg * 0x10));
	writel(priority << shift,
		evic_base + PIC32_SET(REG_IPC_OFFSET + reg * 0x10));
}

__attribute__((used)) static int pic32_irq_domain_map(struct irq_domain *d, unsigned int virq,
				irq_hw_number_t hw)
{
	struct evic_chip_data *priv = d->host_data;
	struct irq_data *data;
	int ret;
	u32 iecclr, ifsclr;
	u32 reg, mask;

	ret = irq_map_generic_chip(d, virq, hw);
	if (ret)
		return ret;

	/*
	 * Piggyback on xlate function to move to an alternate chip as necessary
	 * at time of mapping instead of allowing the flow handler/chip to be
	 * changed later. This requires all interrupts to be configured through
	 * DT.
	 */
	if (priv->irq_types[hw] & IRQ_TYPE_SENSE_MASK) {
		data = irq_domain_get_irq_data(d, virq);
		irqd_set_trigger_type(data, priv->irq_types[hw]);
		irq_setup_alt_chip(data, priv->irq_types[hw]);
	}

	IRQ_REG_MASK(hw, reg, mask);

	iecclr = PIC32_CLR(REG_IEC_OFFSET + reg * 0x10);
	ifsclr = PIC32_CLR(REG_IFS_OFFSET + reg * 0x10);

	/* mask and clear flag */
	writel(mask, evic_base + iecclr);
	writel(mask, evic_base + ifsclr);

	/* default priority is required */
	pic32_set_irq_priority(hw, PIC32_INT_PRI(2, 0));

	return ret;
}

int pic32_irq_domain_xlate(struct irq_domain *d, struct device_node *ctrlr,
			   const u32 *intspec, unsigned int intsize,
			   irq_hw_number_t *out_hwirq, unsigned int *out_type)
{
	struct evic_chip_data *priv = d->host_data;

	if (WARN_ON(intsize < 2))
		return -EINVAL;

	if (WARN_ON(intspec[0] >= NR_IRQS))
		return -EINVAL;

	*out_hwirq = intspec[0];
	*out_type = intspec[1] & IRQ_TYPE_SENSE_MASK;

	priv->irq_types[intspec[0]] = intspec[1] & IRQ_TYPE_SENSE_MASK;

	return 0;
}

