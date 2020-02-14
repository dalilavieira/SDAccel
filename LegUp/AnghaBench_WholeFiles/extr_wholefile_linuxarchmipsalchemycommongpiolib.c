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
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 unsigned int ALCHEMY_GPIO1_BASE ; 
 unsigned int ALCHEMY_GPIO2_BASE ; 
 scalar_t__ AU1300_GPIO_BASE ; 
 int alchemy_gpio1_direction_input (unsigned int) ; 
 int alchemy_gpio1_direction_output (unsigned int,int) ; 
 int /*<<< orphan*/  alchemy_gpio1_get_value (unsigned int) ; 
 int /*<<< orphan*/  alchemy_gpio1_set_value (unsigned int,int) ; 
 int alchemy_gpio1_to_irq (unsigned int) ; 
 int alchemy_gpio2_direction_input (unsigned int) ; 
 int alchemy_gpio2_direction_output (unsigned int,int) ; 
 int /*<<< orphan*/  alchemy_gpio2_get_value (unsigned int) ; 
 int /*<<< orphan*/  alchemy_gpio2_set_value (unsigned int,int) ; 
 int alchemy_gpio2_to_irq (unsigned int) ; 
 int au1300_gpio_direction_input (scalar_t__) ; 
 int au1300_gpio_direction_output (scalar_t__,int) ; 
 int /*<<< orphan*/  au1300_gpio_get_value (scalar_t__) ; 
 int /*<<< orphan*/  au1300_gpio_set_value (scalar_t__,int) ; 
 int au1300_gpio_to_irq (scalar_t__) ; 

__attribute__((used)) static int gpio2_get(struct gpio_chip *chip, unsigned offset)
{
	return !!alchemy_gpio2_get_value(offset + ALCHEMY_GPIO2_BASE);
}

__attribute__((used)) static void gpio2_set(struct gpio_chip *chip, unsigned offset, int value)
{
	alchemy_gpio2_set_value(offset + ALCHEMY_GPIO2_BASE, value);
}

__attribute__((used)) static int gpio2_direction_input(struct gpio_chip *chip, unsigned offset)
{
	return alchemy_gpio2_direction_input(offset + ALCHEMY_GPIO2_BASE);
}

__attribute__((used)) static int gpio2_direction_output(struct gpio_chip *chip, unsigned offset,
				  int value)
{
	return alchemy_gpio2_direction_output(offset + ALCHEMY_GPIO2_BASE,
						value);
}

__attribute__((used)) static int gpio2_to_irq(struct gpio_chip *chip, unsigned offset)
{
	return alchemy_gpio2_to_irq(offset + ALCHEMY_GPIO2_BASE);
}

__attribute__((used)) static int gpio1_get(struct gpio_chip *chip, unsigned offset)
{
	return !!alchemy_gpio1_get_value(offset + ALCHEMY_GPIO1_BASE);
}

__attribute__((used)) static void gpio1_set(struct gpio_chip *chip,
				unsigned offset, int value)
{
	alchemy_gpio1_set_value(offset + ALCHEMY_GPIO1_BASE, value);
}

__attribute__((used)) static int gpio1_direction_input(struct gpio_chip *chip, unsigned offset)
{
	return alchemy_gpio1_direction_input(offset + ALCHEMY_GPIO1_BASE);
}

__attribute__((used)) static int gpio1_direction_output(struct gpio_chip *chip,
					unsigned offset, int value)
{
	return alchemy_gpio1_direction_output(offset + ALCHEMY_GPIO1_BASE,
					     value);
}

__attribute__((used)) static int gpio1_to_irq(struct gpio_chip *chip, unsigned offset)
{
	return alchemy_gpio1_to_irq(offset + ALCHEMY_GPIO1_BASE);
}

__attribute__((used)) static int alchemy_gpic_get(struct gpio_chip *chip, unsigned int off)
{
	return !!au1300_gpio_get_value(off + AU1300_GPIO_BASE);
}

__attribute__((used)) static void alchemy_gpic_set(struct gpio_chip *chip, unsigned int off, int v)
{
	au1300_gpio_set_value(off + AU1300_GPIO_BASE, v);
}

__attribute__((used)) static int alchemy_gpic_dir_input(struct gpio_chip *chip, unsigned int off)
{
	return au1300_gpio_direction_input(off + AU1300_GPIO_BASE);
}

__attribute__((used)) static int alchemy_gpic_dir_output(struct gpio_chip *chip, unsigned int off,
				   int v)
{
	return au1300_gpio_direction_output(off + AU1300_GPIO_BASE, v);
}

__attribute__((used)) static int alchemy_gpic_gpio_to_irq(struct gpio_chip *chip, unsigned int off)
{
	return au1300_gpio_to_irq(off + AU1300_GPIO_BASE);
}

