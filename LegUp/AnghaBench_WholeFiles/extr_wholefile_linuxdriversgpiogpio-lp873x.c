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
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct lp873x_gpio {TYPE_1__ chip; TYPE_5__* lp873; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 unsigned int BITS_PER_GPO ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int LP873X_CONFIG_CLKIN_PIN_SEL ; 
 int /*<<< orphan*/  LP873X_GPO_CTRL_OD ; 
 int /*<<< orphan*/  LP873X_REG_CONFIG ; 
 int /*<<< orphan*/  LP873X_REG_GPO_CTRL ; 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 129 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 128 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 TYPE_5__* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct lp873x_gpio*) ; 
 struct lp873x_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct lp873x_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int pinconf_to_config_param (unsigned long) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lp873x_gpio*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ template_chip ; 

__attribute__((used)) static int lp873x_gpio_get_direction(struct gpio_chip *chip,
				     unsigned int offset)
{
	/* This device is output only */
	return 0;
}

__attribute__((used)) static int lp873x_gpio_direction_input(struct gpio_chip *chip,
				       unsigned int offset)
{
	/* This device is output only */
	return -EINVAL;
}

__attribute__((used)) static int lp873x_gpio_direction_output(struct gpio_chip *chip,
					unsigned int offset, int value)
{
	struct lp873x_gpio *gpio = gpiochip_get_data(chip);

	/* Set the initial value */
	return regmap_update_bits(gpio->lp873->regmap, LP873X_REG_GPO_CTRL,
				  BIT(offset * BITS_PER_GPO),
				  value ? BIT(offset * BITS_PER_GPO) : 0);
}

__attribute__((used)) static int lp873x_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct lp873x_gpio *gpio = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(gpio->lp873->regmap, LP873X_REG_GPO_CTRL, &val);
	if (ret < 0)
		return ret;

	return val & BIT(offset * BITS_PER_GPO);
}

__attribute__((used)) static void lp873x_gpio_set(struct gpio_chip *chip, unsigned int offset,
			    int value)
{
	struct lp873x_gpio *gpio = gpiochip_get_data(chip);

	regmap_update_bits(gpio->lp873->regmap, LP873X_REG_GPO_CTRL,
			   BIT(offset * BITS_PER_GPO),
			   value ? BIT(offset * BITS_PER_GPO) : 0);
}

__attribute__((used)) static int lp873x_gpio_request(struct gpio_chip *gc, unsigned int offset)
{
	struct lp873x_gpio *gpio = gpiochip_get_data(gc);
	int ret;

	switch (offset) {
	case 0:
		/* No MUX Set up Needed for GPO */
		break;
	case 1:
		/* Setup the CLKIN_PIN_SEL MUX to GPO2 */
		ret = regmap_update_bits(gpio->lp873->regmap, LP873X_REG_CONFIG,
					 LP873X_CONFIG_CLKIN_PIN_SEL, 0);
		if (ret)
			return ret;

		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int lp873x_gpio_set_config(struct gpio_chip *gc, unsigned offset,
				  unsigned long config)
{
	struct lp873x_gpio *gpio = gpiochip_get_data(gc);

	switch (pinconf_to_config_param(config)) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		return regmap_update_bits(gpio->lp873->regmap,
					  LP873X_REG_GPO_CTRL,
					  BIT(offset * BITS_PER_GPO +
					  LP873X_GPO_CTRL_OD),
					  BIT(offset * BITS_PER_GPO +
					  LP873X_GPO_CTRL_OD));

	case PIN_CONFIG_DRIVE_PUSH_PULL:
		return regmap_update_bits(gpio->lp873->regmap,
					  LP873X_REG_GPO_CTRL,
					  BIT(offset * BITS_PER_GPO +
					  LP873X_GPO_CTRL_OD), 0);
	default:
		return -ENOTSUPP;
	}
}

__attribute__((used)) static int lp873x_gpio_probe(struct platform_device *pdev)
{
	struct lp873x_gpio *gpio;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	platform_set_drvdata(pdev, gpio);

	gpio->lp873 = dev_get_drvdata(pdev->dev.parent);
	gpio->chip = template_chip;
	gpio->chip.parent = gpio->lp873->dev;

	ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	return 0;
}

