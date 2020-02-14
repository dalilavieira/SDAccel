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
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct madera_pdata {int gpio_base; } ;
struct TYPE_8__ {int base; int /*<<< orphan*/  ngpio; int /*<<< orphan*/  parent; } ;
struct madera_gpio {TYPE_1__ gpio_chip; struct madera* madera; } ;
struct madera {int type; int /*<<< orphan*/  dev; int /*<<< orphan*/  regmap; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
#define  CS47L35 132 
 int /*<<< orphan*/  CS47L35_NUM_GPIOS ; 
#define  CS47L85 131 
 int /*<<< orphan*/  CS47L85_NUM_GPIOS ; 
#define  CS47L90 130 
 int /*<<< orphan*/  CS47L90_NUM_GPIOS ; 
#define  CS47L91 129 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int MADERA_GP1_DIR ; 
 unsigned int MADERA_GP1_DIR_MASK ; 
 unsigned int MADERA_GP1_LVL ; 
 unsigned int MADERA_GP1_LVL_MASK ; 
 scalar_t__ MADERA_GPIO1_CTRL_1 ; 
 scalar_t__ MADERA_GPIO1_CTRL_2 ; 
#define  WM1840 128 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 struct madera* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct madera_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,scalar_t__,int) ; 
 int devm_gpiochip_add_data (TYPE_3__*,TYPE_1__*,struct madera_gpio*) ; 
 struct madera_gpio* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int gpiochip_add_pin_range (TYPE_1__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct madera_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 TYPE_1__ madera_gpio_chip ; 
 int regmap_read (int /*<<< orphan*/ ,scalar_t__,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,scalar_t__,unsigned int,unsigned int) ; 

__attribute__((used)) static int madera_gpio_get_direction(struct gpio_chip *chip,
				     unsigned int offset)
{
	struct madera_gpio *madera_gpio = gpiochip_get_data(chip);
	struct madera *madera = madera_gpio->madera;
	unsigned int reg_offset = 2 * offset;
	unsigned int val;
	int ret;

	ret = regmap_read(madera->regmap, MADERA_GPIO1_CTRL_2 + reg_offset,
			  &val);
	if (ret < 0)
		return ret;

	return !!(val & MADERA_GP1_DIR_MASK);
}

__attribute__((used)) static int madera_gpio_direction_in(struct gpio_chip *chip, unsigned int offset)
{
	struct madera_gpio *madera_gpio = gpiochip_get_data(chip);
	struct madera *madera = madera_gpio->madera;
	unsigned int reg_offset = 2 * offset;

	return regmap_update_bits(madera->regmap,
				  MADERA_GPIO1_CTRL_2 + reg_offset,
				  MADERA_GP1_DIR_MASK, MADERA_GP1_DIR);
}

__attribute__((used)) static int madera_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct madera_gpio *madera_gpio = gpiochip_get_data(chip);
	struct madera *madera = madera_gpio->madera;
	unsigned int reg_offset = 2 * offset;
	unsigned int val;
	int ret;

	ret = regmap_read(madera->regmap, MADERA_GPIO1_CTRL_1 + reg_offset,
			  &val);
	if (ret < 0)
		return ret;

	return !!(val & MADERA_GP1_LVL_MASK);
}

__attribute__((used)) static int madera_gpio_direction_out(struct gpio_chip *chip,
				     unsigned int offset, int value)
{
	struct madera_gpio *madera_gpio = gpiochip_get_data(chip);
	struct madera *madera = madera_gpio->madera;
	unsigned int reg_offset = 2 * offset;
	unsigned int reg_val = value ? MADERA_GP1_LVL : 0;
	int ret;

	ret = regmap_update_bits(madera->regmap,
				 MADERA_GPIO1_CTRL_2 + reg_offset,
				 MADERA_GP1_DIR_MASK, 0);
	if (ret < 0)
		return ret;

	return regmap_update_bits(madera->regmap,
				  MADERA_GPIO1_CTRL_1 + reg_offset,
				  MADERA_GP1_LVL_MASK, reg_val);
}

__attribute__((used)) static void madera_gpio_set(struct gpio_chip *chip, unsigned int offset,
			    int value)
{
	struct madera_gpio *madera_gpio = gpiochip_get_data(chip);
	struct madera *madera = madera_gpio->madera;
	unsigned int reg_offset = 2 * offset;
	unsigned int reg_val = value ? MADERA_GP1_LVL : 0;
	int ret;

	ret = regmap_update_bits(madera->regmap,
				 MADERA_GPIO1_CTRL_1 + reg_offset,
				 MADERA_GP1_LVL_MASK, reg_val);

	/* set() doesn't return an error so log a warning */
	if (ret)
		dev_warn(madera->dev, "Failed to write to 0x%x (%d)\n",
			 MADERA_GPIO1_CTRL_1 + reg_offset, ret);
}

__attribute__((used)) static int madera_gpio_probe(struct platform_device *pdev)
{
	struct madera *madera = dev_get_drvdata(pdev->dev.parent);
	struct madera_pdata *pdata = dev_get_platdata(madera->dev);
	struct madera_gpio *madera_gpio;
	int ret;

	madera_gpio = devm_kzalloc(&pdev->dev, sizeof(*madera_gpio),
				   GFP_KERNEL);
	if (!madera_gpio)
		return -ENOMEM;

	madera_gpio->madera = madera;

	/* Construct suitable gpio_chip from the template in madera_gpio_chip */
	madera_gpio->gpio_chip = madera_gpio_chip;
	madera_gpio->gpio_chip.parent = pdev->dev.parent;

	switch (madera->type) {
	case CS47L35:
		madera_gpio->gpio_chip.ngpio = CS47L35_NUM_GPIOS;
		break;
	case CS47L85:
	case WM1840:
		madera_gpio->gpio_chip.ngpio = CS47L85_NUM_GPIOS;
		break;
	case CS47L90:
	case CS47L91:
		madera_gpio->gpio_chip.ngpio = CS47L90_NUM_GPIOS;
		break;
	default:
		dev_err(&pdev->dev, "Unknown chip variant %d\n", madera->type);
		return -EINVAL;
	}

	/* We want to be usable on systems that don't use devicetree or acpi */
	if (pdata && pdata->gpio_base)
		madera_gpio->gpio_chip.base = pdata->gpio_base;
	else
		madera_gpio->gpio_chip.base = -1;

	ret = devm_gpiochip_add_data(&pdev->dev,
				     &madera_gpio->gpio_chip,
				     madera_gpio);
	if (ret < 0) {
		dev_dbg(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	/*
	 * This is part of a composite MFD device which can only be used with
	 * the corresponding pinctrl driver. On all supported silicon the GPIO
	 * to pinctrl mapping is fixed in the silicon, so we register it
	 * explicitly instead of requiring a redundant gpio-ranges in the
	 * devicetree.
	 * In any case we also want to work on systems that don't use devicetree
	 * or acpi.
	 */
	ret = gpiochip_add_pin_range(&madera_gpio->gpio_chip, "madera-pinctrl",
				     0, 0, madera_gpio->gpio_chip.ngpio);
	if (ret) {
		dev_dbg(&pdev->dev, "Failed to add pin range (%d)\n", ret);
		return ret;
	}

	return 0;
}

