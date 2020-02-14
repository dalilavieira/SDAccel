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
struct irq_data {scalar_t__ hwirq; } ;
typedef  scalar_t__ irq_hw_number_t ;

/* Variables and functions */
 unsigned long BIT (scalar_t__) ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_RISING ; 
 int /*<<< orphan*/  IRQ_TYPE_LEVEL_HIGH ; 
 unsigned long ITYPE_mskVECTOR ; 
 unsigned long ITYPE_offVECTOR ; 
 int /*<<< orphan*/  NDS32_SR_INT_MASK2 ; 
 int /*<<< orphan*/  NDS32_SR_INT_PEND2 ; 
 int /*<<< orphan*/  NDS32_SR_INT_TRIGGER ; 
 int /*<<< orphan*/  NDS32_SR_ITYPE ; 
 scalar_t__ NDS32_VECTOR_offINTERRUPT ; 
 unsigned long __nds32__mfsr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nds32__mtsr_dsb (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ativic32_chip ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  handle_level_irq ; 
 struct irq_data* irq_get_irq_data (unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irqd_set_trigger_type (struct irq_data*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ativic32_ack_irq(struct irq_data *data)
{
	__nds32__mtsr_dsb(BIT(data->hwirq), NDS32_SR_INT_PEND2);
}

__attribute__((used)) static void ativic32_mask_irq(struct irq_data *data)
{
	unsigned long int_mask2 = __nds32__mfsr(NDS32_SR_INT_MASK2);
	__nds32__mtsr_dsb(int_mask2 & (~(BIT(data->hwirq))), NDS32_SR_INT_MASK2);
}

__attribute__((used)) static void ativic32_unmask_irq(struct irq_data *data)
{
	unsigned long int_mask2 = __nds32__mfsr(NDS32_SR_INT_MASK2);
	__nds32__mtsr_dsb(int_mask2 | (BIT(data->hwirq)), NDS32_SR_INT_MASK2);
}

__attribute__((used)) static int ativic32_irq_domain_map(struct irq_domain *id, unsigned int virq,
				  irq_hw_number_t hw)
{

	unsigned long int_trigger_type;
	u32 type;
	struct irq_data *irq_data;
	int_trigger_type = __nds32__mfsr(NDS32_SR_INT_TRIGGER);
	irq_data = irq_get_irq_data(virq);
	if (!irq_data)
		return -EINVAL;

	if (int_trigger_type & (BIT(hw))) {
		irq_set_chip_and_handler(virq, &ativic32_chip, handle_edge_irq);
		type = IRQ_TYPE_EDGE_RISING;
	} else {
		irq_set_chip_and_handler(virq, &ativic32_chip, handle_level_irq);
		type = IRQ_TYPE_LEVEL_HIGH;
	}

	irqd_set_trigger_type(irq_data, type);
	return 0;
}

__attribute__((used)) static irq_hw_number_t get_intr_src(void)
{
	return ((__nds32__mfsr(NDS32_SR_ITYPE) & ITYPE_mskVECTOR) >> ITYPE_offVECTOR)
		- NDS32_VECTOR_offINTERRUPT;
}

