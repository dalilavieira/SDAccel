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
 int CAUSEB_IP2 ; 
 int CAUSEF_IP7 ; 
 int /*<<< orphan*/  JMR3927_IOC_INTM_ADDR ; 
 int /*<<< orphan*/  JMR3927_IOC_INTS2_ADDR ; 
 int /*<<< orphan*/  JMR3927_IOC_REV_ADDR ; 
 int JMR3927_IRQ_IOC ; 
 int JMR3927_IRQ_IOCINT ; 
 scalar_t__ JMR3927_IRQ_IRC ; 
 int JMR3927_NR_IRQ_IOC ; 
 unsigned char jmr3927_ioc_reg_in (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jmr3927_ioc_reg_out (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void mask_irq_ioc(struct irq_data *d)
{
	/* 0: mask */
	unsigned int irq_nr = d->irq - JMR3927_IRQ_IOC;
	unsigned char imask = jmr3927_ioc_reg_in(JMR3927_IOC_INTM_ADDR);
	unsigned int bit = 1 << irq_nr;
	jmr3927_ioc_reg_out(imask & ~bit, JMR3927_IOC_INTM_ADDR);
	/* flush write buffer */
	(void)jmr3927_ioc_reg_in(JMR3927_IOC_REV_ADDR);
}

__attribute__((used)) static void unmask_irq_ioc(struct irq_data *d)
{
	/* 0: mask */
	unsigned int irq_nr = d->irq - JMR3927_IRQ_IOC;
	unsigned char imask = jmr3927_ioc_reg_in(JMR3927_IOC_INTM_ADDR);
	unsigned int bit = 1 << irq_nr;
	jmr3927_ioc_reg_out(imask | bit, JMR3927_IOC_INTM_ADDR);
	/* flush write buffer */
	(void)jmr3927_ioc_reg_in(JMR3927_IOC_REV_ADDR);
}

__attribute__((used)) static int jmr3927_ioc_irqroute(void)
{
	unsigned char istat = jmr3927_ioc_reg_in(JMR3927_IOC_INTS2_ADDR);
	int i;

	for (i = 0; i < JMR3927_NR_IRQ_IOC; i++) {
		if (istat & (1 << i))
			return JMR3927_IRQ_IOC + i;
	}
	return -1;
}

__attribute__((used)) static int jmr3927_irq_dispatch(int pending)
{
	int irq;

	if ((pending & CAUSEF_IP7) == 0)
		return -1;
	irq = (pending >> CAUSEB_IP2) & 0x0f;
	irq += JMR3927_IRQ_IRC;
	if (irq == JMR3927_IRQ_IOCINT)
		irq = jmr3927_ioc_irqroute();
	return irq;
}

