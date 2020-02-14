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
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_MCLR ; 
 int /*<<< orphan*/  IRQ_MSET ; 
 int /*<<< orphan*/  __raw_writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soft_restart (int) ; 

__attribute__((used)) static void ebsa110_mask_irq(struct irq_data *d)
{
	__raw_writeb(1 << d->irq, IRQ_MCLR);
}

__attribute__((used)) static void ebsa110_unmask_irq(struct irq_data *d)
{
	__raw_writeb(1 << d->irq, IRQ_MSET);
}

__attribute__((used)) static void ebsa110_idle(void)
{
	const char *irq_stat = (char *)0xff000000;

	/* disable clock switching */
	asm volatile ("mcr p15, 0, ip, c15, c2, 2" : : : "cc");

	/* wait for an interrupt to occur */
	while (!*irq_stat);

	/* enable clock switching */
	asm volatile ("mcr p15, 0, ip, c15, c1, 2" : : : "cc");
}

__attribute__((used)) static void ebsa110_restart(enum reboot_mode mode, const char *cmd)
{
	soft_restart(0x80000000);
}

