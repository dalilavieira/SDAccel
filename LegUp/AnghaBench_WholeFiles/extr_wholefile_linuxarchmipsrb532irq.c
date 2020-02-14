#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct irq_data {unsigned int irq; } ;
struct TYPE_2__ {unsigned int* base_addr; unsigned int mask; } ;

/* Variables and functions */
 int EINVAL ; 
 int GPIO_MAPPED_IRQ_BASE ; 
 unsigned int GPIO_MAPPED_IRQ_GROUP ; 
 unsigned int GROUP0_IRQ_BASE ; 
 int GROUP4_IRQ_BASE ; 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 unsigned int READ_MASK (unsigned int volatile*) ; 
 int /*<<< orphan*/  WRITE_MASK (unsigned int volatile*,unsigned int) ; 
 int /*<<< orphan*/  clear_c0_cause (int) ; 
 int /*<<< orphan*/  clear_c0_status (int) ; 
 TYPE_1__* intr_group ; 
 int /*<<< orphan*/  rb532_gpio_set_ilevel (int,int) ; 
 int /*<<< orphan*/  rb532_gpio_set_istat (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  set_c0_status (int) ; 

__attribute__((used)) static inline int irq_to_group(unsigned int irq_nr)
{
	return (irq_nr - GROUP0_IRQ_BASE) >> 5;
}

__attribute__((used)) static inline int group_to_ip(unsigned int group)
{
	return group + 2;
}

__attribute__((used)) static inline void enable_local_irq(unsigned int ip)
{
	int ipnum = 0x100 << ip;

	set_c0_status(ipnum);
}

__attribute__((used)) static inline void disable_local_irq(unsigned int ip)
{
	int ipnum = 0x100 << ip;

	clear_c0_status(ipnum);
}

__attribute__((used)) static inline void ack_local_irq(unsigned int ip)
{
	int ipnum = 0x100 << ip;

	clear_c0_cause(ipnum);
}

__attribute__((used)) static void rb532_enable_irq(struct irq_data *d)
{
	unsigned int group, intr_bit, irq_nr = d->irq;
	int ip = irq_nr - GROUP0_IRQ_BASE;
	volatile unsigned int *addr;

	if (ip < 0)
		enable_local_irq(irq_nr);
	else {
		group = ip >> 5;

		ip &= (1 << 5) - 1;
		intr_bit = 1 << ip;

		enable_local_irq(group_to_ip(group));

		addr = intr_group[group].base_addr;
		WRITE_MASK(addr, READ_MASK(addr) & ~intr_bit);
	}
}

__attribute__((used)) static void rb532_disable_irq(struct irq_data *d)
{
	unsigned int group, intr_bit, mask, irq_nr = d->irq;
	int ip = irq_nr - GROUP0_IRQ_BASE;
	volatile unsigned int *addr;

	if (ip < 0) {
		disable_local_irq(irq_nr);
	} else {
		group = ip >> 5;

		ip &= (1 << 5) - 1;
		intr_bit = 1 << ip;
		addr = intr_group[group].base_addr;
		mask = READ_MASK(addr);
		mask |= intr_bit;
		WRITE_MASK(addr, mask);

		/* There is a maximum of 14 GPIO interrupts */
		if (group == GPIO_MAPPED_IRQ_GROUP && irq_nr <= (GROUP4_IRQ_BASE + 13))
			rb532_gpio_set_istat(0, irq_nr - GPIO_MAPPED_IRQ_BASE);

		/*
		 * if there are no more interrupts enabled in this
		 * group, disable corresponding IP
		 */
		if (mask == intr_group[group].mask)
			disable_local_irq(group_to_ip(group));
	}
}

__attribute__((used)) static void rb532_mask_and_ack_irq(struct irq_data *d)
{
	rb532_disable_irq(d);
	ack_local_irq(group_to_ip(irq_to_group(d->irq)));
}

__attribute__((used)) static int rb532_set_type(struct irq_data *d,  unsigned type)
{
	int gpio = d->irq - GPIO_MAPPED_IRQ_BASE;
	int group = irq_to_group(d->irq);

	if (group != GPIO_MAPPED_IRQ_GROUP || d->irq > (GROUP4_IRQ_BASE + 13))
		return (type == IRQ_TYPE_LEVEL_HIGH) ? 0 : -EINVAL;

	switch (type) {
	case IRQ_TYPE_LEVEL_HIGH:
		rb532_gpio_set_ilevel(1, gpio);
		break;
	case IRQ_TYPE_LEVEL_LOW:
		rb532_gpio_set_ilevel(0, gpio);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

