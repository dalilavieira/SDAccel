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
struct irq_data {int irq; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 scalar_t__ IPR ; 
 int /*<<< orphan*/  ctrl_bclr (int,scalar_t__) ; 
 int /*<<< orphan*/  ctrl_bset (int,scalar_t__) ; 
 int /*<<< orphan*/  h8300h_irq_chip ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 int* ipr_bit ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void h8300h_disable_irq(struct irq_data *data)
{
	int bit;
	int irq = data->irq - 12;

	bit = ipr_bit[irq];
	if (bit >= 0) {
		if (bit < 8)
			ctrl_bclr(bit & 7, IPR);
		else
			ctrl_bclr(bit & 7, (IPR+1));
	}
}

__attribute__((used)) static void h8300h_enable_irq(struct irq_data *data)
{
	int bit;
	int irq = data->irq - 12;

	bit = ipr_bit[irq];
	if (bit >= 0) {
		if (bit < 8)
			ctrl_bset(bit & 7, IPR);
		else
			ctrl_bset(bit & 7, (IPR+1));
	}
}

__attribute__((used)) static int irq_map(struct irq_domain *h, unsigned int virq,
		   irq_hw_number_t hw_irq_num)
{
       irq_set_chip_and_handler(virq, &h8300h_irq_chip, handle_simple_irq);

       return 0;
}

