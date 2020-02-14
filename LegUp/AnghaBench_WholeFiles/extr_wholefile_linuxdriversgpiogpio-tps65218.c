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
struct TYPE_6__ {TYPE_2__* parent; } ;
struct tps65218_gpio {TYPE_1__ gpio_chip; struct tps65218* tps65218; } ;
struct tps65218 {int /*<<< orphan*/  regmap; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;
typedef  enum pin_config_param { ____Placeholder_pin_config_param } pin_config_param ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PIN_CONFIG_DRIVE_OPEN_DRAIN ; 
 int PIN_CONFIG_DRIVE_PUSH_PULL ; 
 unsigned int TPS65218_CONFIG1_GPO2_BUF ; 
 unsigned int TPS65218_CONFIG1_IO1_SEL ; 
 unsigned int TPS65218_CONFIG2_DC12_RST ; 
 unsigned int TPS65218_ENABLE2_GPIO1 ; 
 int /*<<< orphan*/  TPS65218_PROTECT_L1 ; 
 int /*<<< orphan*/  TPS65218_REG_CONFIG1 ; 
 int /*<<< orphan*/  TPS65218_REG_CONFIG2 ; 
 int /*<<< orphan*/  TPS65218_REG_ENABLE2 ; 
 int /*<<< orphan*/  TPS65218_REG_SEQ7 ; 
 unsigned int TPS65218_SEQ7_GPO1_SEQ_MASK ; 
 unsigned int TPS65218_SEQ7_GPO3_SEQ_MASK ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct tps65218* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct tps65218_gpio*) ; 
 struct tps65218_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct tps65218_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_line_is_open_drain (struct gpio_chip*,unsigned int) ; 
 scalar_t__ gpiochip_line_is_open_source (struct gpio_chip*,unsigned int) ; 
 int pinconf_to_config_param (unsigned long) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65218_gpio*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 TYPE_1__ template_chip ; 
 int tps65218_clear_bits (struct tps65218*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int tps65218_set_bits (struct tps65218*,int /*<<< orphan*/ ,unsigned int,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tps65218_gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
	struct tps65218 *tps65218 = tps65218_gpio->tps65218;
	unsigned int val;
	int ret;

	ret = regmap_read(tps65218->regmap, TPS65218_REG_ENABLE2, &val);
	if (ret)
		return ret;

	return !!(val & (TPS65218_ENABLE2_GPIO1 << offset));
}

__attribute__((used)) static void tps65218_gpio_set(struct gpio_chip *gc, unsigned offset,
			      int value)
{
	struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
	struct tps65218 *tps65218 = tps65218_gpio->tps65218;

	if (value)
		tps65218_set_bits(tps65218, TPS65218_REG_ENABLE2,
				  TPS65218_ENABLE2_GPIO1 << offset,
				  TPS65218_ENABLE2_GPIO1 << offset,
				  TPS65218_PROTECT_L1);
	else
		tps65218_clear_bits(tps65218, TPS65218_REG_ENABLE2,
				    TPS65218_ENABLE2_GPIO1 << offset,
				    TPS65218_PROTECT_L1);
}

__attribute__((used)) static int tps65218_gpio_output(struct gpio_chip *gc, unsigned offset,
				int value)
{
	/* Only drives GPOs */
	tps65218_gpio_set(gc, offset, value);
	return 0;
}

__attribute__((used)) static int tps65218_gpio_input(struct gpio_chip *gc, unsigned offset)
{
	return -EPERM;
}

__attribute__((used)) static int tps65218_gpio_request(struct gpio_chip *gc, unsigned offset)
{
	struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
	struct tps65218 *tps65218 = tps65218_gpio->tps65218;
	int ret;

	if (gpiochip_line_is_open_source(gc, offset)) {
		dev_err(gc->parent, "can't work as open source\n");
		return -EINVAL;
	}

	switch (offset) {
	case 0:
		if (!gpiochip_line_is_open_drain(gc, offset)) {
			dev_err(gc->parent, "GPO1 works only as open drain\n");
			return -EINVAL;
		}

		/* Disable sequencer for GPO1 */
		ret = tps65218_clear_bits(tps65218, TPS65218_REG_SEQ7,
					  TPS65218_SEQ7_GPO1_SEQ_MASK,
					  TPS65218_PROTECT_L1);
		if (ret)
			return ret;

		/* Setup GPO1 */
		ret = tps65218_clear_bits(tps65218, TPS65218_REG_CONFIG1,
					  TPS65218_CONFIG1_IO1_SEL,
					  TPS65218_PROTECT_L1);
		if (ret)
			return ret;

		break;
	case 1:
		/* Setup GPO2 */
		ret = tps65218_clear_bits(tps65218, TPS65218_REG_CONFIG1,
					  TPS65218_CONFIG1_IO1_SEL,
					  TPS65218_PROTECT_L1);
		if (ret)
			return ret;

		break;

	case 2:
		if (!gpiochip_line_is_open_drain(gc, offset)) {
			dev_err(gc->parent, "GPO3 works only as open drain\n");
			return -EINVAL;
		}

		/* Disable sequencer for GPO3 */
		ret = tps65218_clear_bits(tps65218, TPS65218_REG_SEQ7,
					  TPS65218_SEQ7_GPO3_SEQ_MASK,
					  TPS65218_PROTECT_L1);
		if (ret)
			return ret;

		/* Setup GPO3 */
		ret = tps65218_clear_bits(tps65218, TPS65218_REG_CONFIG2,
					  TPS65218_CONFIG2_DC12_RST,
					  TPS65218_PROTECT_L1);
		if (ret)
			return ret;

		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int tps65218_gpio_set_config(struct gpio_chip *gc, unsigned offset,
				    unsigned long config)
{
	struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
	struct tps65218 *tps65218 = tps65218_gpio->tps65218;
	enum pin_config_param param = pinconf_to_config_param(config);

	switch (offset) {
	case 0:
	case 2:
		/* GPO1 is hardwired to be open drain */
		if (param == PIN_CONFIG_DRIVE_OPEN_DRAIN)
			return 0;
		return -ENOTSUPP;
	case 1:
		/* GPO2 is push-pull by default, can be set as open drain. */
		if (param == PIN_CONFIG_DRIVE_OPEN_DRAIN)
			return tps65218_clear_bits(tps65218,
						   TPS65218_REG_CONFIG1,
						   TPS65218_CONFIG1_GPO2_BUF,
						   TPS65218_PROTECT_L1);
		if (param == PIN_CONFIG_DRIVE_PUSH_PULL)
			return tps65218_set_bits(tps65218,
						 TPS65218_REG_CONFIG1,
						 TPS65218_CONFIG1_GPO2_BUF,
						 TPS65218_CONFIG1_GPO2_BUF,
						 TPS65218_PROTECT_L1);
		return -ENOTSUPP;
	default:
		break;
	}
	return -ENOTSUPP;
}

__attribute__((used)) static int tps65218_gpio_probe(struct platform_device *pdev)
{
	struct tps65218 *tps65218 = dev_get_drvdata(pdev->dev.parent);
	struct tps65218_gpio *tps65218_gpio;
	int ret;

	tps65218_gpio = devm_kzalloc(&pdev->dev, sizeof(*tps65218_gpio),
				     GFP_KERNEL);
	if (!tps65218_gpio)
		return -ENOMEM;

	tps65218_gpio->tps65218 = tps65218;
	tps65218_gpio->gpio_chip = template_chip;
	tps65218_gpio->gpio_chip.parent = &pdev->dev;
#ifdef CONFIG_OF_GPIO
	tps65218_gpio->gpio_chip.of_node = pdev->dev.of_node;
#endif

	ret = devm_gpiochip_add_data(&pdev->dev, &tps65218_gpio->gpio_chip,
				     tps65218_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register gpiochip, %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, tps65218_gpio);

	return ret;
}

