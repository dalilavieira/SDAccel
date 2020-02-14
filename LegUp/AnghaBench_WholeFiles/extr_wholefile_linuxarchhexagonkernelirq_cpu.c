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
struct irq_data {scalar_t__ irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  __vmintop_globen (long) ; 
 int /*<<< orphan*/  __vmintop_locdis (long) ; 
 int /*<<< orphan*/  __vmintop_locen (long) ; 

__attribute__((used)) static void mask_irq(struct irq_data *data)
{
	__vmintop_locdis((long) data->irq);
}

__attribute__((used)) static void mask_irq_num(unsigned int irq)
{
	__vmintop_locdis((long) irq);
}

__attribute__((used)) static void unmask_irq(struct irq_data *data)
{
	__vmintop_locen((long) data->irq);
}

__attribute__((used)) static void eoi_irq(struct irq_data *data)
{
	__vmintop_globen((long) data->irq);
}

__attribute__((used)) static int set_wake(struct irq_data *data, unsigned int on)
{
	return 0;
}

