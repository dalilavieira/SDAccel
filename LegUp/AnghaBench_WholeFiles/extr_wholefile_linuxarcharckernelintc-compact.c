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
struct irq_data {int hwirq; } ;
typedef  int irq_hw_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  AUX_IENABLE ; 
 int /*<<< orphan*/  AUX_IRQ_LEV ; 
 int /*<<< orphan*/  CONFIG_ARC_COMPACT_IRQ_LEVELS ; 
 unsigned int IS_ENABLED (int /*<<< orphan*/ ) ; 
 unsigned int NR_CPU_IRQS ; 
#define  TIMER0_IRQ 128 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  handle_percpu_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_percpu_devid (unsigned int) ; 
 int /*<<< orphan*/  onchip_intc ; 
 int /*<<< orphan*/  pr_info (char*,unsigned int) ; 
 unsigned int read_aux_reg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_aux_reg (int /*<<< orphan*/ ,unsigned int) ; 

void arc_init_IRQ(void)
{
	unsigned int level_mask = 0, i;

       /* Is timer high priority Interrupt (Level2 in ARCompact jargon) */
	level_mask |= IS_ENABLED(CONFIG_ARC_COMPACT_IRQ_LEVELS) << TIMER0_IRQ;

	/*
	 * Write to register, even if no LV2 IRQs configured to reset it
	 * in case bootloader had mucked with it
	 */
	write_aux_reg(AUX_IRQ_LEV, level_mask);

	if (level_mask)
		pr_info("Level-2 interrupts bitset %x\n", level_mask);

	/*
	 * Disable all IRQ lines so faulty external hardware won't
	 * trigger interrupt that kernel is not ready to handle.
	 */
	for (i = TIMER0_IRQ; i < NR_CPU_IRQS; i++) {
		unsigned int ienb;

		ienb = read_aux_reg(AUX_IENABLE);
		ienb &= ~(1 << i);
		write_aux_reg(AUX_IENABLE, ienb);
	}
}

__attribute__((used)) static void arc_irq_mask(struct irq_data *data)
{
	unsigned int ienb;

	ienb = read_aux_reg(AUX_IENABLE);
	ienb &= ~(1 << data->hwirq);
	write_aux_reg(AUX_IENABLE, ienb);
}

__attribute__((used)) static void arc_irq_unmask(struct irq_data *data)
{
	unsigned int ienb;

	ienb = read_aux_reg(AUX_IENABLE);
	ienb |= (1 << data->hwirq);
	write_aux_reg(AUX_IENABLE, ienb);
}

__attribute__((used)) static int arc_intc_domain_map(struct irq_domain *d, unsigned int irq,
			       irq_hw_number_t hw)
{
	switch (hw) {
	case TIMER0_IRQ:
		irq_set_percpu_devid(irq);
		irq_set_chip_and_handler(irq, &onchip_intc, handle_percpu_irq);
		break;
	default:
		irq_set_chip_and_handler(irq, &onchip_intc, handle_level_irq);
	}
	return 0;
}

