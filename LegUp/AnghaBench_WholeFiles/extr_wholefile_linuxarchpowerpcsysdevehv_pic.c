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
typedef  size_t u32 ;
struct irq_domain {struct ehv_pic* host_data; } ;
struct irq_data {int /*<<< orphan*/  irq; } ;
struct irq_chip {int dummy; } ;
struct ehv_pic {struct irq_chip hc_irq; } ;
struct device_node {int dummy; } ;
struct cpumask {int dummy; } ;
typedef  size_t irq_hw_number_t ;
typedef  enum irq_domain_bus_token { ____Placeholder_irq_domain_bus_token } irq_domain_bus_token ;
struct TYPE_2__ {int /*<<< orphan*/  irqhost; scalar_t__ coreint_flag; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 unsigned int EHV_PIC_INFO (int /*<<< orphan*/ ) ; 
 int IRQ_SET_MASK_OK ; 
 int IRQ_SET_MASK_OK_NOCOPY ; 
#define  IRQ_TYPE_EDGE_BOTH 132 
#define  IRQ_TYPE_EDGE_FALLING 131 
#define  IRQ_TYPE_EDGE_RISING 130 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 int IRQ_TYPE_MPIC_DIRECT ; 
 unsigned int IRQ_TYPE_NONE ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 int MPIC_EOI ; 
 int /*<<< orphan*/  SPRN_EPR ; 
 int /*<<< orphan*/  VECPRI_POLARITY_MASK ; 
 int /*<<< orphan*/  VECPRI_POLARITY_NEGATIVE ; 
 int /*<<< orphan*/  VECPRI_POLARITY_POSITIVE ; 
 int /*<<< orphan*/  VECPRI_SENSE_EDGE ; 
 int /*<<< orphan*/  VECPRI_SENSE_LEVEL ; 
 int /*<<< orphan*/  VECPRI_SENSE_MASK ; 
 struct irq_chip ehv_pic_direct_eoi_irq_chip ; 
 int /*<<< orphan*/  ehv_pic_lock ; 
 int /*<<< orphan*/  ev_int_eoi (unsigned int) ; 
 int /*<<< orphan*/  ev_int_get_config (unsigned int,unsigned int*,unsigned int*,unsigned int*) ; 
 int /*<<< orphan*/  ev_int_iack (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  ev_int_set_config (unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  ev_int_set_mask (unsigned int,int) ; 
 TYPE_1__* global_ehv_pic ; 
 int /*<<< orphan*/  handle_fasteoi_irq ; 
 int* hwirq_intspec ; 
 int irq_choose_cpu (struct cpumask const*) ; 
 struct device_node* irq_domain_get_of_node (struct irq_domain*) ; 
 unsigned int irq_linear_revmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,struct irq_chip*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct irq_chip*) ; 
 int /*<<< orphan*/  irq_set_irq_type (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  irqd_set_trigger_type (struct irq_data*,unsigned int) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 scalar_t__ mpic_percpu_base_vaddr ; 
 int /*<<< orphan*/  out_be32 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int virq_to_hw (int /*<<< orphan*/ ) ; 

void ehv_pic_unmask_irq(struct irq_data *d)
{
	unsigned int src = virq_to_hw(d->irq);

	ev_int_set_mask(src, 0);
}

void ehv_pic_mask_irq(struct irq_data *d)
{
	unsigned int src = virq_to_hw(d->irq);

	ev_int_set_mask(src, 1);
}

void ehv_pic_end_irq(struct irq_data *d)
{
	unsigned int src = virq_to_hw(d->irq);

	ev_int_eoi(src);
}

void ehv_pic_direct_end_irq(struct irq_data *d)
{
	out_be32(mpic_percpu_base_vaddr + MPIC_EOI / 4, 0);
}

int ehv_pic_set_affinity(struct irq_data *d, const struct cpumask *dest,
			 bool force)
{
	unsigned int src = virq_to_hw(d->irq);
	unsigned int config, prio, cpu_dest;
	int cpuid = irq_choose_cpu(dest);
	unsigned long flags;

	spin_lock_irqsave(&ehv_pic_lock, flags);
	ev_int_get_config(src, &config, &prio, &cpu_dest);
	ev_int_set_config(src, config, prio, cpuid);
	spin_unlock_irqrestore(&ehv_pic_lock, flags);

	return IRQ_SET_MASK_OK;
}

__attribute__((used)) static unsigned int ehv_pic_type_to_vecpri(unsigned int type)
{
	/* Now convert sense value */

	switch (type & IRQ_TYPE_SENSE_MASK) {
	case IRQ_TYPE_EDGE_RISING:
		return EHV_PIC_INFO(VECPRI_SENSE_EDGE) |
		       EHV_PIC_INFO(VECPRI_POLARITY_POSITIVE);

	case IRQ_TYPE_EDGE_FALLING:
	case IRQ_TYPE_EDGE_BOTH:
		return EHV_PIC_INFO(VECPRI_SENSE_EDGE) |
		       EHV_PIC_INFO(VECPRI_POLARITY_NEGATIVE);

	case IRQ_TYPE_LEVEL_HIGH:
		return EHV_PIC_INFO(VECPRI_SENSE_LEVEL) |
		       EHV_PIC_INFO(VECPRI_POLARITY_POSITIVE);

	case IRQ_TYPE_LEVEL_LOW:
	default:
		return EHV_PIC_INFO(VECPRI_SENSE_LEVEL) |
		       EHV_PIC_INFO(VECPRI_POLARITY_NEGATIVE);
	}
}

int ehv_pic_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
	unsigned int src = virq_to_hw(d->irq);
	unsigned int vecpri, vold, vnew, prio, cpu_dest;
	unsigned long flags;

	if (flow_type == IRQ_TYPE_NONE)
		flow_type = IRQ_TYPE_LEVEL_LOW;

	irqd_set_trigger_type(d, flow_type);

	vecpri = ehv_pic_type_to_vecpri(flow_type);

	spin_lock_irqsave(&ehv_pic_lock, flags);
	ev_int_get_config(src, &vold, &prio, &cpu_dest);
	vnew = vold & ~(EHV_PIC_INFO(VECPRI_POLARITY_MASK) |
			EHV_PIC_INFO(VECPRI_SENSE_MASK));
	vnew |= vecpri;

	/*
	 * TODO : Add specific interface call for platform to set
	 * individual interrupt priorities.
	 * platform currently using static/default priority for all ints
	 */

	prio = 8;

	ev_int_set_config(src, vecpri, prio, cpu_dest);

	spin_unlock_irqrestore(&ehv_pic_lock, flags);
	return IRQ_SET_MASK_OK_NOCOPY;
}

unsigned int ehv_pic_get_irq(void)
{
	int irq;

	BUG_ON(global_ehv_pic == NULL);

	if (global_ehv_pic->coreint_flag)
		irq = mfspr(SPRN_EPR); /* if core int mode */
	else
		ev_int_iack(0, &irq); /* legacy mode */

	if (irq == 0xFFFF)    /* 0xFFFF --> no irq is pending */
		return 0;

	/*
	 * this will also setup revmap[] in the slow path for the first
	 * time, next calls will always use fast path by indexing revmap
	 */
	return irq_linear_revmap(global_ehv_pic->irqhost, irq);
}

__attribute__((used)) static int ehv_pic_host_match(struct irq_domain *h, struct device_node *node,
			      enum irq_domain_bus_token bus_token)
{
	/* Exact match, unless ehv_pic node is NULL */
	struct device_node *of_node = irq_domain_get_of_node(h);
	return of_node == NULL || of_node == node;
}

__attribute__((used)) static int ehv_pic_host_map(struct irq_domain *h, unsigned int virq,
			 irq_hw_number_t hw)
{
	struct ehv_pic *ehv_pic = h->host_data;
	struct irq_chip *chip;

	/* Default chip */
	chip = &ehv_pic->hc_irq;

	if (mpic_percpu_base_vaddr)
		if (hwirq_intspec[hw] & IRQ_TYPE_MPIC_DIRECT)
			chip = &ehv_pic_direct_eoi_irq_chip;

	irq_set_chip_data(virq, chip);
	/*
	 * using handle_fasteoi_irq as our irq handler, this will
	 * only call the eoi callback and suitable for the MPIC
	 * controller which set ISR/IPR automatically and clear the
	 * highest priority active interrupt in ISR/IPR when we do
	 * a specific eoi
	 */
	irq_set_chip_and_handler(virq, chip, handle_fasteoi_irq);

	/* Set default irq type */
	irq_set_irq_type(virq, IRQ_TYPE_NONE);

	return 0;
}

__attribute__((used)) static int ehv_pic_host_xlate(struct irq_domain *h, struct device_node *ct,
			   const u32 *intspec, unsigned int intsize,
			   irq_hw_number_t *out_hwirq, unsigned int *out_flags)

{
	/*
	 * interrupt sense values coming from the guest device tree
	 * interrupt specifiers can have four possible sense and
	 * level encoding information and they need to
	 * be translated between firmware type & linux type.
	 */

	static unsigned char map_of_senses_to_linux_irqtype[4] = {
		IRQ_TYPE_EDGE_FALLING,
		IRQ_TYPE_EDGE_RISING,
		IRQ_TYPE_LEVEL_LOW,
		IRQ_TYPE_LEVEL_HIGH,
	};

	*out_hwirq = intspec[0];
	if (intsize > 1) {
		hwirq_intspec[intspec[0]] = intspec[1];
		*out_flags = map_of_senses_to_linux_irqtype[intspec[1] &
							~IRQ_TYPE_MPIC_DIRECT];
	} else {
		*out_flags = IRQ_TYPE_NONE;
	}

	return 0;
}

