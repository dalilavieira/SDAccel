#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct tps6586x_platform_data {int gpio_base; } ;
struct TYPE_6__ {int ngpio; int can_sleep; int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int (* to_irq ) (struct gpio_chip*,unsigned int) ;int base; TYPE_1__* parent; int /*<<< orphan*/  label; int /*<<< orphan*/  owner; } ;
struct tps6586x_gpio {TYPE_3__ gpio_chip; int /*<<< orphan*/  parent; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  TPS6586X_GPIOSET1 ; 
 int /*<<< orphan*/  TPS6586X_GPIOSET2 ; 
 unsigned int TPS6586X_INT_PLDO_0 ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct tps6586x_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_1__*,TYPE_3__*,struct tps6586x_gpio*) ; 
 struct tps6586x_gpio* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct tps6586x_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps6586x_gpio*) ; 
 int tps6586x_irq_get_virq (int /*<<< orphan*/ ,unsigned int) ; 
 int tps6586x_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int tps6586x_update (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int tps6586x_gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct tps6586x_gpio *tps6586x_gpio = gpiochip_get_data(gc);
	uint8_t val;
	int ret;

	ret = tps6586x_read(tps6586x_gpio->parent, TPS6586X_GPIOSET2, &val);
	if (ret)
		return ret;

	return !!(val & (1 << offset));
}

__attribute__((used)) static void tps6586x_gpio_set(struct gpio_chip *gc, unsigned offset,
			      int value)
{
	struct tps6586x_gpio *tps6586x_gpio = gpiochip_get_data(gc);

	tps6586x_update(tps6586x_gpio->parent, TPS6586X_GPIOSET2,
			value << offset, 1 << offset);
}

__attribute__((used)) static int tps6586x_gpio_output(struct gpio_chip *gc, unsigned offset,
				int value)
{
	struct tps6586x_gpio *tps6586x_gpio = gpiochip_get_data(gc);
	uint8_t val, mask;

	tps6586x_gpio_set(gc, offset, value);

	val = 0x1 << (offset * 2);
	mask = 0x3 << (offset * 2);

	return tps6586x_update(tps6586x_gpio->parent, TPS6586X_GPIOSET1,
				val, mask);
}

__attribute__((used)) static int tps6586x_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
	struct tps6586x_gpio *tps6586x_gpio = gpiochip_get_data(gc);

	return tps6586x_irq_get_virq(tps6586x_gpio->parent,
				TPS6586X_INT_PLDO_0 + offset);
}

__attribute__((used)) static int tps6586x_gpio_probe(struct platform_device *pdev)
{
	struct tps6586x_platform_data *pdata;
	struct tps6586x_gpio *tps6586x_gpio;
	int ret;

	pdata = dev_get_platdata(pdev->dev.parent);
	tps6586x_gpio = devm_kzalloc(&pdev->dev,
				sizeof(*tps6586x_gpio), GFP_KERNEL);
	if (!tps6586x_gpio)
		return -ENOMEM;

	tps6586x_gpio->parent = pdev->dev.parent;

	tps6586x_gpio->gpio_chip.owner = THIS_MODULE;
	tps6586x_gpio->gpio_chip.label = pdev->name;
	tps6586x_gpio->gpio_chip.parent = &pdev->dev;
	tps6586x_gpio->gpio_chip.ngpio = 4;
	tps6586x_gpio->gpio_chip.can_sleep = true;

	/* FIXME: add handling of GPIOs as dedicated inputs */
	tps6586x_gpio->gpio_chip.direction_output = tps6586x_gpio_output;
	tps6586x_gpio->gpio_chip.set	= tps6586x_gpio_set;
	tps6586x_gpio->gpio_chip.get	= tps6586x_gpio_get;
	tps6586x_gpio->gpio_chip.to_irq	= tps6586x_gpio_to_irq;

#ifdef CONFIG_OF_GPIO
	tps6586x_gpio->gpio_chip.of_node = pdev->dev.parent->of_node;
#endif
	if (pdata && pdata->gpio_base)
		tps6586x_gpio->gpio_chip.base = pdata->gpio_base;
	else
		tps6586x_gpio->gpio_chip.base = -1;

	ret = devm_gpiochip_add_data(&pdev->dev, &tps6586x_gpio->gpio_chip,
				     tps6586x_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, tps6586x_gpio);

	return ret;
}

