#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct tps65086_gpio {TYPE_1__ chip; TYPE_5__* tps; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_4__ dev; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  TPS65086_GPOCTRL ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,int) ; 
 TYPE_5__* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct tps65086_gpio* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int gpiochip_add_data (TYPE_1__*,struct tps65086_gpio*) ; 
 struct tps65086_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (TYPE_1__*) ; 
 struct tps65086_gpio* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65086_gpio*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ template_chip ; 

__attribute__((used)) static int tps65086_gpio_get_direction(struct gpio_chip *chip,
				       unsigned offset)
{
	/* This device is output only */
	return 0;
}

__attribute__((used)) static int tps65086_gpio_direction_input(struct gpio_chip *chip,
					 unsigned offset)
{
	/* This device is output only */
	return -EINVAL;
}

__attribute__((used)) static int tps65086_gpio_direction_output(struct gpio_chip *chip,
					  unsigned offset, int value)
{
	struct tps65086_gpio *gpio = gpiochip_get_data(chip);

	/* Set the initial value */
	regmap_update_bits(gpio->tps->regmap, TPS65086_GPOCTRL,
			   BIT(4 + offset), value ? BIT(4 + offset) : 0);

	return 0;
}

__attribute__((used)) static int tps65086_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct tps65086_gpio *gpio = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(gpio->tps->regmap, TPS65086_GPOCTRL, &val);
	if (ret < 0)
		return ret;

	return val & BIT(4 + offset);
}

__attribute__((used)) static void tps65086_gpio_set(struct gpio_chip *chip, unsigned offset,
			      int value)
{
	struct tps65086_gpio *gpio = gpiochip_get_data(chip);

	regmap_update_bits(gpio->tps->regmap, TPS65086_GPOCTRL,
			   BIT(4 + offset), value ? BIT(4 + offset) : 0);
}

__attribute__((used)) static int tps65086_gpio_probe(struct platform_device *pdev)
{
	struct tps65086_gpio *gpio;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	platform_set_drvdata(pdev, gpio);

	gpio->tps = dev_get_drvdata(pdev->dev.parent);
	gpio->chip = template_chip;
	gpio->chip.parent = gpio->tps->dev;

	ret = gpiochip_add_data(&gpio->chip, gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int tps65086_gpio_remove(struct platform_device *pdev)
{
	struct tps65086_gpio *gpio = platform_get_drvdata(pdev);

	gpiochip_remove(&gpio->chip);

	return 0;
}

