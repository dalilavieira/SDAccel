#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct gpio_chip {int dummy; } ;
struct da9055_pdata {scalar_t__ gpio_base; } ;
struct TYPE_6__ {scalar_t__ base; } ;
struct da9055_gpio {TYPE_1__ gp; struct da9055* da9055; } ;
struct da9055 {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq_data; } ;

/* Variables and functions */
 int DA9055_ACT_LOW ; 
 int DA9055_GPI ; 
#define  DA9055_INPUT 129 
 scalar_t__ DA9055_IRQ_GPI0 ; 
#define  DA9055_OUTPUT 128 
 int DA9055_PORT_MASK ; 
 int DA9055_PORT_SHIFT (unsigned int) ; 
 int DA9055_PUSH_PULL ; 
 scalar_t__ DA9055_REG_GPIO0_1 ; 
 scalar_t__ DA9055_REG_GPIO_MODE0_2 ; 
 scalar_t__ DA9055_REG_STATUS_B ; 
 int DA9055_VDD_IO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int da9055_reg_read (struct da9055*,scalar_t__) ; 
 int da9055_reg_update (struct da9055*,scalar_t__,int,unsigned char) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct da9055* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct da9055_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct da9055_gpio*) ; 
 struct da9055_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct da9055_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da9055_gpio*) ; 
 TYPE_1__ reference_gp ; 
 int regmap_irq_get_virq (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int da9055_gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct da9055_gpio *gpio = gpiochip_get_data(gc);
	int gpio_direction = 0;
	int ret;

	/* Get GPIO direction */
	ret = da9055_reg_read(gpio->da9055, (offset >> 1) + DA9055_REG_GPIO0_1);
	if (ret < 0)
		return ret;

	gpio_direction = ret & (DA9055_PORT_MASK) << DA9055_PORT_SHIFT(offset);
	gpio_direction >>= DA9055_PORT_SHIFT(offset);
	switch (gpio_direction) {
	case DA9055_INPUT:
		ret = da9055_reg_read(gpio->da9055, DA9055_REG_STATUS_B);
		if (ret < 0)
			return ret;
		break;
	case DA9055_OUTPUT:
		ret = da9055_reg_read(gpio->da9055, DA9055_REG_GPIO_MODE0_2);
		if (ret < 0)
			return ret;
	}

	return ret & (1 << offset);

}

__attribute__((used)) static void da9055_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
	struct da9055_gpio *gpio = gpiochip_get_data(gc);

	da9055_reg_update(gpio->da9055,
			DA9055_REG_GPIO_MODE0_2,
			1 << offset,
			value << offset);
}

__attribute__((used)) static int da9055_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
	struct da9055_gpio *gpio = gpiochip_get_data(gc);
	unsigned char reg_byte;

	reg_byte = (DA9055_ACT_LOW | DA9055_GPI)
				<< DA9055_PORT_SHIFT(offset);

	return da9055_reg_update(gpio->da9055, (offset >> 1) +
				DA9055_REG_GPIO0_1,
				DA9055_PORT_MASK <<
				DA9055_PORT_SHIFT(offset),
				reg_byte);
}

__attribute__((used)) static int da9055_gpio_direction_output(struct gpio_chip *gc,
					unsigned offset, int value)
{
	struct da9055_gpio *gpio = gpiochip_get_data(gc);
	unsigned char reg_byte;
	int ret;

	reg_byte = (DA9055_VDD_IO | DA9055_PUSH_PULL)
					<< DA9055_PORT_SHIFT(offset);

	ret = da9055_reg_update(gpio->da9055, (offset >> 1) +
				DA9055_REG_GPIO0_1,
				DA9055_PORT_MASK <<
				DA9055_PORT_SHIFT(offset),
				reg_byte);
	if (ret < 0)
		return ret;

	da9055_gpio_set(gc, offset, value);

	return 0;
}

__attribute__((used)) static int da9055_gpio_to_irq(struct gpio_chip *gc, u32 offset)
{
	struct da9055_gpio *gpio = gpiochip_get_data(gc);
	struct da9055 *da9055 = gpio->da9055;

	return regmap_irq_get_virq(da9055->irq_data,
				  DA9055_IRQ_GPI0 + offset);
}

__attribute__((used)) static int da9055_gpio_probe(struct platform_device *pdev)
{
	struct da9055_gpio *gpio;
	struct da9055_pdata *pdata;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	gpio->da9055 = dev_get_drvdata(pdev->dev.parent);
	pdata = dev_get_platdata(gpio->da9055->dev);

	gpio->gp = reference_gp;
	if (pdata && pdata->gpio_base)
		gpio->gp.base = pdata->gpio_base;

	ret = devm_gpiochip_add_data(&pdev->dev, &gpio->gp, gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, gpio);

	return 0;
}

