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
typedef  int u32 ;
struct irq_data {size_t irq; } ;
struct gpio_chip {int dummy; } ;
typedef  enum ixp4xx_irq_type { ____Placeholder_ixp4xx_irq_type } ixp4xx_irq_type ;

/* Variables and functions */
 int EINVAL ; 
#define  IRQ_TYPE_EDGE_BOTH 132 
#define  IRQ_TYPE_EDGE_FALLING 131 
#define  IRQ_TYPE_EDGE_RISING 130 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 int* IXP4XX_GPIO_GPISR ; 
 int* IXP4XX_GPIO_GPIT1R ; 
 int* IXP4XX_GPIO_GPIT2R ; 
 int /*<<< orphan*/  IXP4XX_GPIO_IN ; 
 int /*<<< orphan*/  IXP4XX_GPIO_OUT ; 
 int IXP4XX_GPIO_STYLE_ACTIVE_HIGH ; 
 int IXP4XX_GPIO_STYLE_ACTIVE_LOW ; 
 int IXP4XX_GPIO_STYLE_CLEAR ; 
 int IXP4XX_GPIO_STYLE_FALLING_EDGE ; 
 int IXP4XX_GPIO_STYLE_RISING_EDGE ; 
 int IXP4XX_GPIO_STYLE_SIZE ; 
 int IXP4XX_GPIO_STYLE_TRANSITIONAL ; 
 int* IXP4XX_ICMR ; 
 int* IXP4XX_ICMR2 ; 
 int IXP4XX_IRQ_EDGE ; 
 int IXP4XX_IRQ_LEVEL ; 
 scalar_t__ cpu_is_ixp43x () ; 
 scalar_t__ cpu_is_ixp46x () ; 
 int /*<<< orphan*/  gpio_line_config (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_line_get (unsigned int,int*) ; 
 int /*<<< orphan*/  gpio_line_set (unsigned int,int) ; 
 unsigned int* irq2gpio ; 
 int ixp4xx_irq_edge ; 

__attribute__((used)) static int ixp4xx_gpio_to_irq(struct gpio_chip *chip, unsigned gpio)
{
	int irq;

	for (irq = 0; irq < 32; irq++) {
		if (irq2gpio[irq] == gpio)
			return irq;
	}
	return -EINVAL;
}

__attribute__((used)) static int ixp4xx_set_irq_type(struct irq_data *d, unsigned int type)
{
	int line = irq2gpio[d->irq];
	u32 int_style;
	enum ixp4xx_irq_type irq_type;
	volatile u32 *int_reg;

	/*
	 * Only for GPIO IRQs
	 */
	if (line < 0)
		return -EINVAL;

	switch (type){
	case IRQ_TYPE_EDGE_BOTH:
		int_style = IXP4XX_GPIO_STYLE_TRANSITIONAL;
		irq_type = IXP4XX_IRQ_EDGE;
		break;
	case IRQ_TYPE_EDGE_RISING:
		int_style = IXP4XX_GPIO_STYLE_RISING_EDGE;
		irq_type = IXP4XX_IRQ_EDGE;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		int_style = IXP4XX_GPIO_STYLE_FALLING_EDGE;
		irq_type = IXP4XX_IRQ_EDGE;
		break;
	case IRQ_TYPE_LEVEL_HIGH:
		int_style = IXP4XX_GPIO_STYLE_ACTIVE_HIGH;
		irq_type = IXP4XX_IRQ_LEVEL;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		int_style = IXP4XX_GPIO_STYLE_ACTIVE_LOW;
		irq_type = IXP4XX_IRQ_LEVEL;
		break;
	default:
		return -EINVAL;
	}

	if (irq_type == IXP4XX_IRQ_EDGE)
		ixp4xx_irq_edge |= (1 << d->irq);
	else
		ixp4xx_irq_edge &= ~(1 << d->irq);

	if (line >= 8) {	/* pins 8-15 */
		line -= 8;
		int_reg = IXP4XX_GPIO_GPIT2R;
	} else {		/* pins 0-7 */
		int_reg = IXP4XX_GPIO_GPIT1R;
	}

	/* Clear the style for the appropriate pin */
	*int_reg &= ~(IXP4XX_GPIO_STYLE_CLEAR <<
	    		(line * IXP4XX_GPIO_STYLE_SIZE));

	*IXP4XX_GPIO_GPISR = (1 << line);

	/* Set the new style */
	*int_reg |= (int_style << (line * IXP4XX_GPIO_STYLE_SIZE));

	/* Configure the line as an input */
	gpio_line_config(irq2gpio[d->irq], IXP4XX_GPIO_IN);

	return 0;
}

__attribute__((used)) static void ixp4xx_irq_mask(struct irq_data *d)
{
	if ((cpu_is_ixp46x() || cpu_is_ixp43x()) && d->irq >= 32)
		*IXP4XX_ICMR2 &= ~(1 << (d->irq - 32));
	else
		*IXP4XX_ICMR &= ~(1 << d->irq);
}

__attribute__((used)) static void ixp4xx_irq_ack(struct irq_data *d)
{
	int line = (d->irq < 32) ? irq2gpio[d->irq] : -1;

	if (line >= 0)
		*IXP4XX_GPIO_GPISR = (1 << line);
}

__attribute__((used)) static void ixp4xx_irq_unmask(struct irq_data *d)
{
	if (!(ixp4xx_irq_edge & (1 << d->irq)))
		ixp4xx_irq_ack(d);

	if ((cpu_is_ixp46x() || cpu_is_ixp43x()) && d->irq >= 32)
		*IXP4XX_ICMR2 |= (1 << (d->irq - 32));
	else
		*IXP4XX_ICMR |= (1 << d->irq);
}

__attribute__((used)) static int ixp4xx_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
	gpio_line_config(gpio, IXP4XX_GPIO_IN);

	return 0;
}

__attribute__((used)) static int ixp4xx_gpio_direction_output(struct gpio_chip *chip, unsigned gpio,
					int level)
{
	gpio_line_set(gpio, level);
	gpio_line_config(gpio, IXP4XX_GPIO_OUT);

	return 0;
}

__attribute__((used)) static int ixp4xx_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
	int value;

	gpio_line_get(gpio, &value);

	return value;
}

__attribute__((used)) static void ixp4xx_gpio_set_value(struct gpio_chip *chip, unsigned gpio,
				  int value)
{
	gpio_line_set(gpio, value);
}

