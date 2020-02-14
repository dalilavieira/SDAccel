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
 int EINVAL ; 
 unsigned long IOPC_IOEINT0TM ; 
 unsigned long IOPC_IOEINT0_MODE (unsigned long) ; 
 unsigned long IOPC_IOEINT1TM ; 
 unsigned long IOPC_IOEINT1_MODE (unsigned long) ; 
 unsigned long IOPC_IOEINT2TM ; 
 unsigned long IOPC_IOEINT2_MODE (unsigned long) ; 
 unsigned long IOPC_IOEINT3TM ; 
 unsigned long IOPC_IOEINT3_MODE (unsigned long) ; 
 unsigned long IOPC_TM_EDGE ; 
 unsigned long IOPC_TM_FALLING ; 
 unsigned long IOPC_TM_HIGH ; 
 unsigned long IOPC_TM_LOW ; 
 unsigned long IOPC_TM_RISING ; 
#define  IRQ_TYPE_EDGE_BOTH 136 
#define  IRQ_TYPE_EDGE_FALLING 135 
#define  IRQ_TYPE_EDGE_RISING 134 
#define  IRQ_TYPE_LEVEL_HIGH 133 
#define  IRQ_TYPE_LEVEL_LOW 132 
 scalar_t__ KS8695_GPIO_VA ; 
 scalar_t__ KS8695_INTEN ; 
 scalar_t__ KS8695_INTST ; 
 scalar_t__ KS8695_IOPC ; 
#define  KS8695_IRQ_EXTERN0 131 
#define  KS8695_IRQ_EXTERN1 130 
#define  KS8695_IRQ_EXTERN2 129 
#define  KS8695_IRQ_EXTERN3 128 
 scalar_t__ KS8695_IRQ_VA ; 
 unsigned long __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ks8695_irq_edge_chip ; 
 int /*<<< orphan*/  ks8695_irq_level_chip ; 

__attribute__((used)) static void ks8695_irq_mask(struct irq_data *d)
{
	unsigned long inten;

	inten = __raw_readl(KS8695_IRQ_VA + KS8695_INTEN);
	inten &= ~(1 << d->irq);

	__raw_writel(inten, KS8695_IRQ_VA + KS8695_INTEN);
}

__attribute__((used)) static void ks8695_irq_unmask(struct irq_data *d)
{
	unsigned long inten;

	inten = __raw_readl(KS8695_IRQ_VA + KS8695_INTEN);
	inten |= (1 << d->irq);

	__raw_writel(inten, KS8695_IRQ_VA + KS8695_INTEN);
}

__attribute__((used)) static void ks8695_irq_ack(struct irq_data *d)
{
	__raw_writel((1 << d->irq), KS8695_IRQ_VA + KS8695_INTST);
}

__attribute__((used)) static int ks8695_irq_set_type(struct irq_data *d, unsigned int type)
{
	unsigned long ctrl, mode;
	unsigned short level_triggered = 0;

	ctrl = __raw_readl(KS8695_GPIO_VA + KS8695_IOPC);

	switch (type) {
		case IRQ_TYPE_LEVEL_HIGH:
			mode = IOPC_TM_HIGH;
			level_triggered = 1;
			break;
		case IRQ_TYPE_LEVEL_LOW:
			mode = IOPC_TM_LOW;
			level_triggered = 1;
			break;
		case IRQ_TYPE_EDGE_RISING:
			mode = IOPC_TM_RISING;
			break;
		case IRQ_TYPE_EDGE_FALLING:
			mode = IOPC_TM_FALLING;
			break;
		case IRQ_TYPE_EDGE_BOTH:
			mode = IOPC_TM_EDGE;
			break;
		default:
			return -EINVAL;
	}

	switch (d->irq) {
		case KS8695_IRQ_EXTERN0:
			ctrl &= ~IOPC_IOEINT0TM;
			ctrl |= IOPC_IOEINT0_MODE(mode);
			break;
		case KS8695_IRQ_EXTERN1:
			ctrl &= ~IOPC_IOEINT1TM;
			ctrl |= IOPC_IOEINT1_MODE(mode);
			break;
		case KS8695_IRQ_EXTERN2:
			ctrl &= ~IOPC_IOEINT2TM;
			ctrl |= IOPC_IOEINT2_MODE(mode);
			break;
		case KS8695_IRQ_EXTERN3:
			ctrl &= ~IOPC_IOEINT3TM;
			ctrl |= IOPC_IOEINT3_MODE(mode);
			break;
		default:
			return -EINVAL;
	}

	if (level_triggered) {
		irq_set_chip_and_handler(d->irq, &ks8695_irq_level_chip,
					 handle_level_irq);
	}
	else {
		irq_set_chip_and_handler(d->irq, &ks8695_irq_edge_chip,
					 handle_edge_irq);
	}

	__raw_writel(ctrl, KS8695_GPIO_VA + KS8695_IOPC);
	return 0;
}

