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
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct bd9571mwv_gpio {TYPE_1__ chip; TYPE_5__* bd; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  BD9571MWV_GPIO_DIR ; 
 int /*<<< orphan*/  BD9571MWV_GPIO_IN ; 
 int /*<<< orphan*/  BD9571MWV_GPIO_OUT ; 
 int BIT (unsigned int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 TYPE_5__* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct bd9571mwv_gpio*) ; 
 struct bd9571mwv_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct bd9571mwv_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bd9571mwv_gpio*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ template_chip ; 

__attribute__((used)) static int bd9571mwv_gpio_get_direction(struct gpio_chip *chip,
				       unsigned int offset)
{
	struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(gpio->bd->regmap, BD9571MWV_GPIO_DIR, &val);
	if (ret < 0)
		return ret;

	return val & BIT(offset);
}

__attribute__((used)) static int bd9571mwv_gpio_direction_input(struct gpio_chip *chip,
					 unsigned int offset)
{
	struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);

	regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_DIR,
			   BIT(offset), 0);

	return 0;
}

__attribute__((used)) static int bd9571mwv_gpio_direction_output(struct gpio_chip *chip,
					  unsigned int offset, int value)
{
	struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);

	/* Set the initial value */
	regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_OUT,
			   BIT(offset), value ? BIT(offset) : 0);
	regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_DIR,
			   BIT(offset), BIT(offset));

	return 0;
}

__attribute__((used)) static int bd9571mwv_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(gpio->bd->regmap, BD9571MWV_GPIO_IN, &val);
	if (ret < 0)
		return ret;

	return val & BIT(offset);
}

__attribute__((used)) static void bd9571mwv_gpio_set(struct gpio_chip *chip, unsigned int offset,
			      int value)
{
	struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);

	regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_OUT,
			   BIT(offset), value ? BIT(offset) : 0);
}

__attribute__((used)) static int bd9571mwv_gpio_probe(struct platform_device *pdev)
{
	struct bd9571mwv_gpio *gpio;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	platform_set_drvdata(pdev, gpio);

	gpio->bd = dev_get_drvdata(pdev->dev.parent);
	gpio->chip = template_chip;
	gpio->chip.parent = gpio->bd->dev;

	ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	return 0;
}

