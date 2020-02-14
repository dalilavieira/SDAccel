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
struct irq_data {int irq; } ;

/* Variables and functions */
 int RM7K_CPU_IRQ_BASE ; 
 int /*<<< orphan*/  clear_c0_intcontrol (int) ; 
 int /*<<< orphan*/  set_c0_intcontrol (int) ; 

__attribute__((used)) static inline void unmask_rm7k_irq(struct irq_data *d)
{
	set_c0_intcontrol(0x100 << (d->irq - RM7K_CPU_IRQ_BASE));
}

__attribute__((used)) static inline void mask_rm7k_irq(struct irq_data *d)
{
	clear_c0_intcontrol(0x100 << (d->irq - RM7K_CPU_IRQ_BASE));
}

