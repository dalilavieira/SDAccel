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
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  get_irq_regs () ; 
 unsigned int kstat_irqs_cpu (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * led_pattern ; 
 void sun3_disable_irq (unsigned int) ; 
 void sun3_enable_irq (unsigned int) ; 
 int* sun3_intreg ; 
 int /*<<< orphan*/  sun3_leds (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  update_process_times (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  user_mode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xtime_update (int) ; 

void sun3_disable_interrupts(void)
{
	sun3_disable_irq(0);
}

void sun3_enable_interrupts(void)
{
	sun3_enable_irq(0);
}

void sun3_enable_irq(unsigned int irq)
{
	*sun3_intreg |=  (1 << irq);
}

void sun3_disable_irq(unsigned int irq)
{
	*sun3_intreg &= ~(1 << irq);
}

__attribute__((used)) static irqreturn_t sun3_int7(int irq, void *dev_id)
{
	unsigned int cnt;

	cnt = kstat_irqs_cpu(irq, 0);
	if (!(cnt % 2000))
		sun3_leds(led_pattern[cnt % 16000 / 2000]);
	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t sun3_int5(int irq, void *dev_id)
{
	unsigned int cnt;

#ifdef CONFIG_SUN3
	intersil_clear();
#endif
	sun3_disable_irq(5);
	sun3_enable_irq(5);
#ifdef CONFIG_SUN3
	intersil_clear();
#endif
	xtime_update(1);
	update_process_times(user_mode(get_irq_regs()));
	cnt = kstat_irqs_cpu(irq, 0);
	if (!(cnt % 20))
		sun3_leds(led_pattern[cnt % 160 / 20]);
	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t sun3_vec255(int irq, void *dev_id)
{
	return IRQ_HANDLED;
}

