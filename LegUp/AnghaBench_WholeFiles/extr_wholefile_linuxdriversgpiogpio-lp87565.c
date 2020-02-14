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
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  parent; } ;
struct lp87565_gpio {TYPE_1__ chip; int /*<<< orphan*/  map; } ;
struct lp87565 {int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LP87565_GOIO1_OD ; 
 int /*<<< orphan*/  LP87565_REG_GPIO_CONFIG ; 
 int /*<<< orphan*/  LP87565_REG_GPIO_IN ; 
 int /*<<< orphan*/  LP87565_REG_GPIO_OUT ; 
 int /*<<< orphan*/  LP87565_REG_PIN_FUNCTION ; 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 129 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 128 
 int /*<<< orphan*/  __ffs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct lp87565* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct lp87565_gpio*) ; 
 struct lp87565_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct lp87565_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int pinconf_to_config_param (unsigned long) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ template_chip ; 

__attribute__((used)) static int lp87565_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(gpio->map, LP87565_REG_GPIO_IN, &val);
	if (ret < 0)
		return ret;

	return !!(val & BIT(offset));
}

__attribute__((used)) static void lp87565_gpio_set(struct gpio_chip *chip, unsigned int offset,
			     int value)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(chip);

	regmap_update_bits(gpio->map, LP87565_REG_GPIO_OUT,
			   BIT(offset), value ? BIT(offset) : 0);
}

__attribute__((used)) static int lp87565_gpio_get_direction(struct gpio_chip *chip,
				      unsigned int offset)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(gpio->map, LP87565_REG_GPIO_CONFIG, &val);
	if (ret < 0)
		return ret;

	return !(val & BIT(offset));
}

__attribute__((used)) static int lp87565_gpio_direction_input(struct gpio_chip *chip,
					unsigned int offset)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(chip);

	return regmap_update_bits(gpio->map,
				  LP87565_REG_GPIO_CONFIG,
				  BIT(offset), 0);
}

__attribute__((used)) static int lp87565_gpio_direction_output(struct gpio_chip *chip,
					 unsigned int offset, int value)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(chip);

	lp87565_gpio_set(chip, offset, value);

	return regmap_update_bits(gpio->map,
				  LP87565_REG_GPIO_CONFIG,
				  BIT(offset), BIT(offset));
}

__attribute__((used)) static int lp87565_gpio_request(struct gpio_chip *gc, unsigned int offset)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(gc);
	int ret;

	switch (offset) {
	case 0:
	case 1:
	case 2:
		/*
		 * MUX can program the pin to be in EN1/2/3 pin mode
		 * Or GPIO1/2/3 mode.
		 * Setup the GPIO*_SEL MUX to GPIO mode
		 */
		ret = regmap_update_bits(gpio->map,
					 LP87565_REG_PIN_FUNCTION,
					 BIT(offset), BIT(offset));
		if (ret)
			return ret;

		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int lp87565_gpio_set_config(struct gpio_chip *gc, unsigned int offset,
				   unsigned long config)
{
	struct lp87565_gpio *gpio = gpiochip_get_data(gc);

	switch (pinconf_to_config_param(config)) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		return regmap_update_bits(gpio->map,
					  LP87565_REG_GPIO_CONFIG,
					  BIT(offset +
					      __ffs(LP87565_GOIO1_OD)),
					  BIT(offset +
					      __ffs(LP87565_GOIO1_OD)));
	case PIN_CONFIG_DRIVE_PUSH_PULL:
		return regmap_update_bits(gpio->map,
					  LP87565_REG_GPIO_CONFIG,
					  BIT(offset +
					      __ffs(LP87565_GOIO1_OD)), 0);
	default:
		return -ENOTSUPP;
	}
}

__attribute__((used)) static int lp87565_gpio_probe(struct platform_device *pdev)
{
	struct lp87565_gpio *gpio;
	struct lp87565 *lp87565;
	int ret;

	gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	lp87565 = dev_get_drvdata(pdev->dev.parent);
	gpio->chip = template_chip;
	gpio->chip.parent = lp87565->dev;
	gpio->map = lp87565->regmap;

	ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	return 0;
}

