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
struct irq_data {int dummy; } ;
struct irq_chip {int dummy; } ;
struct cpumask {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUTO_ASSIGN ; 
 int /*<<< orphan*/  SSC_CONNECT_INTERRUPT ; 
 int assign_irq_vector (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 int /*<<< orphan*/  ia64_ssc (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct irq_chip* irq_get_chip (int) ; 
 int /*<<< orphan*/  irq_set_chip (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_set_handler (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_type_hp_sim ; 
 struct irq_chip no_irq_chip ; 

__attribute__((used)) static unsigned int
hpsim_irq_startup(struct irq_data *data)
{
	return 0;
}

__attribute__((used)) static void
hpsim_irq_noop(struct irq_data *data)
{
}

__attribute__((used)) static int
hpsim_set_affinity_noop(struct irq_data *d, const struct cpumask *b, bool f)
{
	return 0;
}

__attribute__((used)) static void hpsim_irq_set_chip(int irq)
{
	struct irq_chip *chip = irq_get_chip(irq);

	if (chip == &no_irq_chip)
		irq_set_chip(irq, &irq_type_hp_sim);
}

__attribute__((used)) static void hpsim_connect_irq(int intr, int irq)
{
	ia64_ssc(intr, irq, 0, 0, SSC_CONNECT_INTERRUPT);
}

int hpsim_get_irq(int intr)
{
	int irq = assign_irq_vector(AUTO_ASSIGN);

	if (irq >= 0) {
		hpsim_irq_set_chip(irq);
		irq_set_handler(irq, handle_simple_irq);
		hpsim_connect_irq(intr, irq);
	}

	return irq;
}

