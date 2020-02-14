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
struct irq_data {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  ia64_resend_irq (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int
lsapic_noop_startup (struct irq_data *data)
{
	return 0;
}

__attribute__((used)) static void
lsapic_noop (struct irq_data *data)
{
	/* nothing to do... */
}

__attribute__((used)) static int lsapic_retrigger(struct irq_data *data)
{
	ia64_resend_irq(data->irq);

	return 1;
}

