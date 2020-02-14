#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct palmas_platform_data {int gpio_base; } ;
struct TYPE_8__ {int can_sleep; int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* to_irq ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int base; TYPE_1__* parent; int /*<<< orphan*/  ngpio; int /*<<< orphan*/  label; int /*<<< orphan*/  owner; } ;
struct palmas_gpio {TYPE_4__ gpio_chip; struct palmas* palmas; } ;
struct palmas_device_data {int /*<<< orphan*/  ngpio; } ;
struct palmas {int /*<<< orphan*/  dev; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 unsigned int BIT (unsigned int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int PALMAS_GPIO_0_IRQ ; 
 int /*<<< orphan*/  PALMAS_GPIO_BASE ; 
 unsigned int PALMAS_GPIO_CLEAR_DATA_OUT ; 
 unsigned int PALMAS_GPIO_CLEAR_DATA_OUT2 ; 
 unsigned int PALMAS_GPIO_DATA_DIR ; 
 unsigned int PALMAS_GPIO_DATA_DIR2 ; 
 unsigned int PALMAS_GPIO_DATA_IN ; 
 unsigned int PALMAS_GPIO_DATA_IN2 ; 
 unsigned int PALMAS_GPIO_DATA_OUT ; 
 unsigned int PALMAS_GPIO_DATA_OUT2 ; 
 unsigned int PALMAS_GPIO_SET_DATA_OUT ; 
 unsigned int PALMAS_GPIO_SET_DATA_OUT2 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int,...) ; 
 struct palmas* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct palmas_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_1__*) ; 
 int devm_gpiochip_add_data (TYPE_1__*,TYPE_4__*,struct palmas_gpio*) ; 
 struct palmas_gpio* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct palmas_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 struct palmas_device_data* of_device_get_match_data (TYPE_1__*) ; 
 struct palmas_device_data palmas_dev_data ; 
 int palmas_irq_get_virq (struct palmas*,unsigned int) ; 
 int palmas_read (struct palmas*,int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int palmas_update_bits (struct palmas*,int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int) ; 
 int palmas_write (struct palmas*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct palmas_gpio*) ; 

__attribute__((used)) static int palmas_gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct palmas_gpio *pg = gpiochip_get_data(gc);
	struct palmas *palmas = pg->palmas;
	unsigned int val;
	int ret;
	unsigned int reg;
	int gpio16 = (offset/8);

	offset %= 8;
	reg = (gpio16) ? PALMAS_GPIO_DATA_DIR2 : PALMAS_GPIO_DATA_DIR;

	ret = palmas_read(palmas, PALMAS_GPIO_BASE, reg, &val);
	if (ret < 0) {
		dev_err(gc->parent, "Reg 0x%02x read failed, %d\n", reg, ret);
		return ret;
	}

	if (val & BIT(offset))
		reg = (gpio16) ? PALMAS_GPIO_DATA_OUT2 : PALMAS_GPIO_DATA_OUT;
	else
		reg = (gpio16) ? PALMAS_GPIO_DATA_IN2 : PALMAS_GPIO_DATA_IN;

	ret = palmas_read(palmas, PALMAS_GPIO_BASE, reg, &val);
	if (ret < 0) {
		dev_err(gc->parent, "Reg 0x%02x read failed, %d\n", reg, ret);
		return ret;
	}
	return !!(val & BIT(offset));
}

__attribute__((used)) static void palmas_gpio_set(struct gpio_chip *gc, unsigned offset,
			int value)
{
	struct palmas_gpio *pg = gpiochip_get_data(gc);
	struct palmas *palmas = pg->palmas;
	int ret;
	unsigned int reg;
	int gpio16 = (offset/8);

	offset %= 8;
	if (gpio16)
		reg = (value) ?
			PALMAS_GPIO_SET_DATA_OUT2 : PALMAS_GPIO_CLEAR_DATA_OUT2;
	else
		reg = (value) ?
			PALMAS_GPIO_SET_DATA_OUT : PALMAS_GPIO_CLEAR_DATA_OUT;

	ret = palmas_write(palmas, PALMAS_GPIO_BASE, reg, BIT(offset));
	if (ret < 0)
		dev_err(gc->parent, "Reg 0x%02x write failed, %d\n", reg, ret);
}

__attribute__((used)) static int palmas_gpio_output(struct gpio_chip *gc, unsigned offset,
				int value)
{
	struct palmas_gpio *pg = gpiochip_get_data(gc);
	struct palmas *palmas = pg->palmas;
	int ret;
	unsigned int reg;
	int gpio16 = (offset/8);

	offset %= 8;
	reg = (gpio16) ? PALMAS_GPIO_DATA_DIR2 : PALMAS_GPIO_DATA_DIR;

	/* Set the initial value */
	palmas_gpio_set(gc, offset, value);

	ret = palmas_update_bits(palmas, PALMAS_GPIO_BASE, reg,
				BIT(offset), BIT(offset));
	if (ret < 0)
		dev_err(gc->parent, "Reg 0x%02x update failed, %d\n", reg,
			ret);
	return ret;
}

__attribute__((used)) static int palmas_gpio_input(struct gpio_chip *gc, unsigned offset)
{
	struct palmas_gpio *pg = gpiochip_get_data(gc);
	struct palmas *palmas = pg->palmas;
	int ret;
	unsigned int reg;
	int gpio16 = (offset/8);

	offset %= 8;
	reg = (gpio16) ? PALMAS_GPIO_DATA_DIR2 : PALMAS_GPIO_DATA_DIR;

	ret = palmas_update_bits(palmas, PALMAS_GPIO_BASE, reg, BIT(offset), 0);
	if (ret < 0)
		dev_err(gc->parent, "Reg 0x%02x update failed, %d\n", reg,
			ret);
	return ret;
}

__attribute__((used)) static int palmas_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
	struct palmas_gpio *pg = gpiochip_get_data(gc);
	struct palmas *palmas = pg->palmas;

	return palmas_irq_get_virq(palmas, PALMAS_GPIO_0_IRQ + offset);
}

__attribute__((used)) static int palmas_gpio_probe(struct platform_device *pdev)
{
	struct palmas *palmas = dev_get_drvdata(pdev->dev.parent);
	struct palmas_platform_data *palmas_pdata;
	struct palmas_gpio *palmas_gpio;
	int ret;
	const struct palmas_device_data *dev_data;

	dev_data = of_device_get_match_data(&pdev->dev);
	if (!dev_data)
		dev_data = &palmas_dev_data;

	palmas_gpio = devm_kzalloc(&pdev->dev,
				sizeof(*palmas_gpio), GFP_KERNEL);
	if (!palmas_gpio)
		return -ENOMEM;

	palmas_gpio->palmas = palmas;
	palmas_gpio->gpio_chip.owner = THIS_MODULE;
	palmas_gpio->gpio_chip.label = dev_name(&pdev->dev);
	palmas_gpio->gpio_chip.ngpio = dev_data->ngpio;
	palmas_gpio->gpio_chip.can_sleep = true;
	palmas_gpio->gpio_chip.direction_input = palmas_gpio_input;
	palmas_gpio->gpio_chip.direction_output = palmas_gpio_output;
	palmas_gpio->gpio_chip.to_irq = palmas_gpio_to_irq;
	palmas_gpio->gpio_chip.set	= palmas_gpio_set;
	palmas_gpio->gpio_chip.get	= palmas_gpio_get;
	palmas_gpio->gpio_chip.parent = &pdev->dev;
#ifdef CONFIG_OF_GPIO
	palmas_gpio->gpio_chip.of_node = pdev->dev.of_node;
#endif
	palmas_pdata = dev_get_platdata(palmas->dev);
	if (palmas_pdata && palmas_pdata->gpio_base)
		palmas_gpio->gpio_chip.base = palmas_pdata->gpio_base;
	else
		palmas_gpio->gpio_chip.base = -1;

	ret = devm_gpiochip_add_data(&pdev->dev, &palmas_gpio->gpio_chip,
				     palmas_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, palmas_gpio);
	return ret;
}

