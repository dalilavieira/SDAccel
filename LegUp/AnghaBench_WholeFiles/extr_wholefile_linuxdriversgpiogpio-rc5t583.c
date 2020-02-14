#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct rc5t583_platform_data {int gpio_base; } ;
struct TYPE_5__ {char* label; void (* free ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int (* to_irq ) (struct gpio_chip*,unsigned int) ;unsigned int ngpio; int can_sleep; int base; TYPE_1__* parent; int /*<<< orphan*/  owner; } ;
struct rc5t583_gpio {TYPE_3__ gpio_chip; struct rc5t583* rc5t583; } ;
struct rc5t583 {int irq_base; struct device* dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct gpio_chip {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  RC5T583_GPIO_IOOUT ; 
 int /*<<< orphan*/  RC5T583_GPIO_IOSEL ; 
 int /*<<< orphan*/  RC5T583_GPIO_MON_IOIN ; 
 int /*<<< orphan*/  RC5T583_GPIO_PGSEL ; 
 int RC5T583_IRQ_GPIO0 ; 
 unsigned int RC5T583_MAX_GPIO ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct rc5t583* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct rc5t583_platform_data* dev_get_platdata (struct device*) ; 
 int devm_gpiochip_add_data (TYPE_1__*,TYPE_3__*,struct rc5t583_gpio*) ; 
 struct rc5t583_gpio* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct rc5t583_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rc5t583_gpio*) ; 
 int rc5t583_clear_bits (struct device*,int /*<<< orphan*/ ,int) ; 
 int rc5t583_read (struct device*,int /*<<< orphan*/ ,int*) ; 
 int rc5t583_set_bits (struct device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int rc5t583_gpio_get(struct gpio_chip *gc, unsigned int offset)
{
	struct rc5t583_gpio *rc5t583_gpio = gpiochip_get_data(gc);
	struct device *parent = rc5t583_gpio->rc5t583->dev;
	uint8_t val = 0;
	int ret;

	ret = rc5t583_read(parent, RC5T583_GPIO_MON_IOIN, &val);
	if (ret < 0)
		return ret;

	return !!(val & BIT(offset));
}

__attribute__((used)) static void rc5t583_gpio_set(struct gpio_chip *gc, unsigned int offset, int val)
{
	struct rc5t583_gpio *rc5t583_gpio = gpiochip_get_data(gc);
	struct device *parent = rc5t583_gpio->rc5t583->dev;
	if (val)
		rc5t583_set_bits(parent, RC5T583_GPIO_IOOUT, BIT(offset));
	else
		rc5t583_clear_bits(parent, RC5T583_GPIO_IOOUT, BIT(offset));
}

__attribute__((used)) static int rc5t583_gpio_dir_input(struct gpio_chip *gc, unsigned int offset)
{
	struct rc5t583_gpio *rc5t583_gpio = gpiochip_get_data(gc);
	struct device *parent = rc5t583_gpio->rc5t583->dev;
	int ret;

	ret = rc5t583_clear_bits(parent, RC5T583_GPIO_IOSEL, BIT(offset));
	if (ret < 0)
		return ret;

	/* Set pin to gpio mode */
	return rc5t583_clear_bits(parent, RC5T583_GPIO_PGSEL, BIT(offset));
}

__attribute__((used)) static int rc5t583_gpio_dir_output(struct gpio_chip *gc, unsigned offset,
			int value)
{
	struct rc5t583_gpio *rc5t583_gpio = gpiochip_get_data(gc);
	struct device *parent = rc5t583_gpio->rc5t583->dev;
	int ret;

	rc5t583_gpio_set(gc, offset, value);
	ret = rc5t583_set_bits(parent, RC5T583_GPIO_IOSEL, BIT(offset));
	if (ret < 0)
		return ret;

	/* Set pin to gpio mode */
	return rc5t583_clear_bits(parent, RC5T583_GPIO_PGSEL, BIT(offset));
}

__attribute__((used)) static int rc5t583_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
	struct rc5t583_gpio *rc5t583_gpio = gpiochip_get_data(gc);

	if (offset < RC5T583_MAX_GPIO)
		return rc5t583_gpio->rc5t583->irq_base +
				RC5T583_IRQ_GPIO0 + offset;
	return -EINVAL;
}

__attribute__((used)) static void rc5t583_gpio_free(struct gpio_chip *gc, unsigned offset)
{
	struct rc5t583_gpio *rc5t583_gpio = gpiochip_get_data(gc);
	struct device *parent = rc5t583_gpio->rc5t583->dev;

	rc5t583_set_bits(parent, RC5T583_GPIO_PGSEL, BIT(offset));
}

__attribute__((used)) static int rc5t583_gpio_probe(struct platform_device *pdev)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(pdev->dev.parent);
	struct rc5t583_platform_data *pdata = dev_get_platdata(rc5t583->dev);
	struct rc5t583_gpio *rc5t583_gpio;

	rc5t583_gpio = devm_kzalloc(&pdev->dev, sizeof(*rc5t583_gpio),
					GFP_KERNEL);
	if (!rc5t583_gpio)
		return -ENOMEM;

	rc5t583_gpio->gpio_chip.label = "gpio-rc5t583",
	rc5t583_gpio->gpio_chip.owner = THIS_MODULE,
	rc5t583_gpio->gpio_chip.free = rc5t583_gpio_free,
	rc5t583_gpio->gpio_chip.direction_input = rc5t583_gpio_dir_input,
	rc5t583_gpio->gpio_chip.direction_output = rc5t583_gpio_dir_output,
	rc5t583_gpio->gpio_chip.set = rc5t583_gpio_set,
	rc5t583_gpio->gpio_chip.get = rc5t583_gpio_get,
	rc5t583_gpio->gpio_chip.to_irq = rc5t583_gpio_to_irq,
	rc5t583_gpio->gpio_chip.ngpio = RC5T583_MAX_GPIO,
	rc5t583_gpio->gpio_chip.can_sleep = true,
	rc5t583_gpio->gpio_chip.parent = &pdev->dev;
	rc5t583_gpio->gpio_chip.base = -1;
	rc5t583_gpio->rc5t583 = rc5t583;

	if (pdata && pdata->gpio_base)
		rc5t583_gpio->gpio_chip.base = pdata->gpio_base;

	platform_set_drvdata(pdev, rc5t583_gpio);

	return devm_gpiochip_add_data(&pdev->dev, &rc5t583_gpio->gpio_chip,
				      rc5t583_gpio);
}

