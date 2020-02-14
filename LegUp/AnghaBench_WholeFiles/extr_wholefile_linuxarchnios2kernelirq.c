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
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  CTL_IENABLE ; 
 int /*<<< orphan*/  WRCTL (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int ienable ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m_irq_chip ; 

__attribute__((used)) static void chip_unmask(struct irq_data *d)
{
	ienable |= (1 << d->hwirq);
	WRCTL(CTL_IENABLE, ienable);
}

__attribute__((used)) static void chip_mask(struct irq_data *d)
{
	ienable &= ~(1 << d->hwirq);
	WRCTL(CTL_IENABLE, ienable);
}

__attribute__((used)) static int irq_map(struct irq_domain *h, unsigned int virq,
				irq_hw_number_t hw_irq_num)
{
	irq_set_chip_and_handler(virq, &m_irq_chip, handle_level_irq);

	return 0;
}

