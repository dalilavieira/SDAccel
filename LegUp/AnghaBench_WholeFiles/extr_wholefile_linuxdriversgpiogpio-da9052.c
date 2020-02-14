#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct gpio_chip {int dummy; } ;
struct da9052_pdata {scalar_t__ gpio_base; } ;
struct TYPE_7__ {scalar_t__ base; } ;
struct da9052_gpio {TYPE_1__ gp; struct da9052* da9052; } ;
struct da9052 {TYPE_2__* dev; int /*<<< orphan*/  irq_data; } ;

/* Variables and functions */
 int DA9052_ACTIVE_LOW ; 
 int DA9052_DEBOUNCING_ON ; 
 scalar_t__ DA9052_GPIO_0_1_REG ; 
 int DA9052_GPIO_EVEN_PORT_MODE ; 
 int DA9052_GPIO_EVEN_PORT_PIN ; 
 int DA9052_GPIO_EVEN_SHIFT ; 
 int DA9052_GPIO_MASK_LOWER_NIBBLE ; 
 int DA9052_GPIO_MASK_UPPER_NIBBLE ; 
 unsigned int DA9052_GPIO_MAX_PORTS_PER_REGISTER ; 
 unsigned char DA9052_GPIO_NIBBLE_SHIFT ; 
 int DA9052_GPIO_ODD_PORT_MODE ; 
 int DA9052_GPIO_ODD_PORT_PIN ; 
 int DA9052_GPIO_ODD_SHIFT ; 
 int DA9052_GPIO_SHIFT_COUNT (unsigned int) ; 
#define  DA9052_INPUT 129 
 scalar_t__ DA9052_IRQ_GPI0 ; 
#define  DA9052_OUTPUT_PUSHPULL 128 
 scalar_t__ DA9052_STATUS_C_REG ; 
 scalar_t__ DA9052_STATUS_D_REG ; 
 int DA9052_SUPPLY_VDD_IO1 ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int da9052_reg_read (struct da9052*,scalar_t__) ; 
 int da9052_reg_update (struct da9052*,scalar_t__,int,unsigned char) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct da9052* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct da9052_pdata* dev_get_platdata (TYPE_2__*) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct da9052_gpio*) ; 
 struct da9052_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct da9052_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da9052_gpio*) ; 
 TYPE_1__ reference_gp ; 
 int regmap_irq_get_virq (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static unsigned char da9052_gpio_port_odd(unsigned offset)
{
	return offset % 2;
}

__attribute__((used)) static int da9052_gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct da9052_gpio *gpio = gpiochip_get_data(gc);
	int da9052_port_direction = 0;
	int ret;

	ret = da9052_reg_read(gpio->da9052,
			      DA9052_GPIO_0_1_REG + (offset >> 1));
	if (ret < 0)
		return ret;

	if (da9052_gpio_port_odd(offset)) {
		da9052_port_direction = ret & DA9052_GPIO_ODD_PORT_PIN;
		da9052_port_direction >>= 4;
	} else {
		da9052_port_direction = ret & DA9052_GPIO_EVEN_PORT_PIN;
	}

	switch (da9052_port_direction) {
	case DA9052_INPUT:
		if (offset < DA9052_GPIO_MAX_PORTS_PER_REGISTER)
			ret = da9052_reg_read(gpio->da9052,
					      DA9052_STATUS_C_REG);
		else
			ret = da9052_reg_read(gpio->da9052,
					      DA9052_STATUS_D_REG);
		if (ret < 0)
			return ret;
		return !!(ret & (1 << DA9052_GPIO_SHIFT_COUNT(offset)));
	case DA9052_OUTPUT_PUSHPULL:
		if (da9052_gpio_port_odd(offset))
			return !!(ret & DA9052_GPIO_ODD_PORT_MODE);
		else
			return !!(ret & DA9052_GPIO_EVEN_PORT_MODE);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static void da9052_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
	struct da9052_gpio *gpio = gpiochip_get_data(gc);
	int ret;

	if (da9052_gpio_port_odd(offset)) {
			ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
						DA9052_GPIO_0_1_REG,
						DA9052_GPIO_ODD_PORT_MODE,
						value << DA9052_GPIO_ODD_SHIFT);
			if (ret != 0)
				dev_err(gpio->da9052->dev,
					"Failed to updated gpio odd reg,%d",
					ret);
	} else {
			ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
						DA9052_GPIO_0_1_REG,
						DA9052_GPIO_EVEN_PORT_MODE,
						value << DA9052_GPIO_EVEN_SHIFT);
			if (ret != 0)
				dev_err(gpio->da9052->dev,
					"Failed to updated gpio even reg,%d",
					ret);
	}
}

__attribute__((used)) static int da9052_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
	struct da9052_gpio *gpio = gpiochip_get_data(gc);
	unsigned char register_value;
	int ret;

	/* Format: function - 2 bits type - 1 bit mode - 1 bit */
	register_value = DA9052_INPUT | DA9052_ACTIVE_LOW << 2 |
			 DA9052_DEBOUNCING_ON << 3;

	if (da9052_gpio_port_odd(offset))
		ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
					DA9052_GPIO_0_1_REG,
					DA9052_GPIO_MASK_UPPER_NIBBLE,
					(register_value <<
					DA9052_GPIO_NIBBLE_SHIFT));
	else
		ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
					DA9052_GPIO_0_1_REG,
					DA9052_GPIO_MASK_LOWER_NIBBLE,
					register_value);

	return ret;
}

__attribute__((used)) static int da9052_gpio_direction_output(struct gpio_chip *gc,
					unsigned offset, int value)
{
	struct da9052_gpio *gpio = gpiochip_get_data(gc);
	unsigned char register_value;
	int ret;

	/* Format: Function - 2 bits Type - 1 bit Mode - 1 bit */
	register_value = DA9052_OUTPUT_PUSHPULL | DA9052_SUPPLY_VDD_IO1 << 2 |
			 value << 3;

	if (da9052_gpio_port_odd(offset))
		ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
					DA9052_GPIO_0_1_REG,
					DA9052_GPIO_MASK_UPPER_NIBBLE,
					(register_value <<
					DA9052_GPIO_NIBBLE_SHIFT));
	else
		ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
					DA9052_GPIO_0_1_REG,
					DA9052_GPIO_MASK_LOWER_NIBBLE,
					register_value);

	return ret;
}

__attribute__((used)) static int da9052_gpio_to_irq(struct gpio_chip *gc, u32 offset)
{
	struct da9052_gpio *gpio = gpiochip_get_data(gc);
	struct da9052 *da9052 = gpio->da9052;

	int irq;

	irq = regmap_irq_get_virq(da9052->irq_data, DA9052_IRQ_GPI0 + offset);

	return irq;
}

__attribute__((used)) static int da9052_gpio_probe(struct platform_device *pdev)
{
	struct da9052_gpio *gpio;
	struct da9052_pdata *pdata;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	gpio->da9052 = dev_get_drvdata(pdev->dev.parent);
	pdata = dev_get_platdata(gpio->da9052->dev);

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

