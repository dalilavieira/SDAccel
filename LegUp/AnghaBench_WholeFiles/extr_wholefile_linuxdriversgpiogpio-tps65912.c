#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct tps65912_gpio {TYPE_2__ gpio_chip; TYPE_1__* tps; } ;
struct tps65912 {int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIOF_DIR_IN ; 
 int GPIOF_DIR_OUT ; 
 int GPIO_CFG_MASK ; 
 int GPIO_SET_MASK ; 
 int GPIO_STS_MASK ; 
 unsigned int TPS65912_GPIO1 ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 void* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_3__*,TYPE_2__*,struct tps65912_gpio*) ; 
 struct tps65912_gpio* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 struct tps65912_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65912_gpio*) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,int,int) ; 
 TYPE_2__ template_chip ; 

__attribute__((used)) static int tps65912_gpio_get_direction(struct gpio_chip *gc,
				       unsigned offset)
{
	struct tps65912_gpio *gpio = gpiochip_get_data(gc);

	int ret, val;

	ret = regmap_read(gpio->tps->regmap, TPS65912_GPIO1 + offset, &val);
	if (ret)
		return ret;

	if (val & GPIO_CFG_MASK)
		return GPIOF_DIR_OUT;
	else
		return GPIOF_DIR_IN;
}

__attribute__((used)) static int tps65912_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
	struct tps65912_gpio *gpio = gpiochip_get_data(gc);

	return regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
				  GPIO_CFG_MASK, 0);
}

__attribute__((used)) static int tps65912_gpio_direction_output(struct gpio_chip *gc,
					  unsigned offset, int value)
{
	struct tps65912_gpio *gpio = gpiochip_get_data(gc);

	/* Set the initial value */
	regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
			   GPIO_SET_MASK, value ? GPIO_SET_MASK : 0);

	return regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
				  GPIO_CFG_MASK, GPIO_CFG_MASK);
}

__attribute__((used)) static int tps65912_gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct tps65912_gpio *gpio = gpiochip_get_data(gc);
	int ret, val;

	ret = regmap_read(gpio->tps->regmap, TPS65912_GPIO1 + offset, &val);
	if (ret)
		return ret;

	if (val & GPIO_STS_MASK)
		return 1;

	return 0;
}

__attribute__((used)) static void tps65912_gpio_set(struct gpio_chip *gc, unsigned offset,
			      int value)
{
	struct tps65912_gpio *gpio = gpiochip_get_data(gc);

	regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
			   GPIO_SET_MASK, value ? GPIO_SET_MASK : 0);
}

__attribute__((used)) static int tps65912_gpio_probe(struct platform_device *pdev)
{
	struct tps65912 *tps = dev_get_drvdata(pdev->dev.parent);
	struct tps65912_gpio *gpio;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	gpio->tps = dev_get_drvdata(pdev->dev.parent);
	gpio->gpio_chip = template_chip;
	gpio->gpio_chip.parent = tps->dev;

	ret = devm_gpiochip_add_data(&pdev->dev, &gpio->gpio_chip,
				     gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, gpio);

	return 0;
}

