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
struct TYPE_6__ {char* label; int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int (* get_direction ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int can_sleep; int base; TYPE_1__* parent; int /*<<< orphan*/  ngpio; int /*<<< orphan*/  names; int /*<<< orphan*/  owner; } ;
struct tps68470_gpio_data {TYPE_3__ gc; struct regmap* tps68470_regmap; } ;
struct regmap {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 unsigned int TPS68470_GPIO_CTL_REG_A (unsigned int) ; 
 int TPS68470_GPIO_MODE_MASK ; 
 int TPS68470_GPIO_MODE_OUT_CMOS ; 
 int /*<<< orphan*/  TPS68470_N_GPIO ; 
 unsigned int TPS68470_N_REGULAR_GPIO ; 
 unsigned int TPS68470_REG_GPDO ; 
 int TPS68470_REG_SGPO ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct regmap* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_1__*,TYPE_3__*,struct tps68470_gpio_data*) ; 
 struct tps68470_gpio_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct tps68470_gpio_data* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps68470_gpio_data*) ; 
 int regmap_read (struct regmap*,unsigned int,int*) ; 
 int regmap_update_bits (struct regmap*,unsigned int,int,int) ; 
 int /*<<< orphan*/  tps68470_names ; 

__attribute__((used)) static int tps68470_gpio_get(struct gpio_chip *gc, unsigned int offset)
{
	struct tps68470_gpio_data *tps68470_gpio = gpiochip_get_data(gc);
	struct regmap *regmap = tps68470_gpio->tps68470_regmap;
	unsigned int reg = TPS68470_REG_GPDO;
	int val, ret;

	if (offset >= TPS68470_N_REGULAR_GPIO) {
		offset -= TPS68470_N_REGULAR_GPIO;
		reg = TPS68470_REG_SGPO;
	}

	ret = regmap_read(regmap, reg, &val);
	if (ret) {
		dev_err(tps68470_gpio->gc.parent, "reg 0x%x read failed\n",
			TPS68470_REG_SGPO);
		return ret;
	}
	return !!(val & BIT(offset));
}

__attribute__((used)) static int tps68470_gpio_get_direction(struct gpio_chip *gc,
				       unsigned int offset)
{
	struct tps68470_gpio_data *tps68470_gpio = gpiochip_get_data(gc);
	struct regmap *regmap = tps68470_gpio->tps68470_regmap;
	int val, ret;

	/* rest are always outputs */
	if (offset >= TPS68470_N_REGULAR_GPIO)
		return 0;

	ret = regmap_read(regmap, TPS68470_GPIO_CTL_REG_A(offset), &val);
	if (ret) {
		dev_err(tps68470_gpio->gc.parent, "reg 0x%x read failed\n",
			TPS68470_GPIO_CTL_REG_A(offset));
		return ret;
	}

	val &= TPS68470_GPIO_MODE_MASK;
	return val >= TPS68470_GPIO_MODE_OUT_CMOS ? 0 : 1;
}

__attribute__((used)) static void tps68470_gpio_set(struct gpio_chip *gc, unsigned int offset,
				int value)
{
	struct tps68470_gpio_data *tps68470_gpio = gpiochip_get_data(gc);
	struct regmap *regmap = tps68470_gpio->tps68470_regmap;
	unsigned int reg = TPS68470_REG_GPDO;

	if (offset >= TPS68470_N_REGULAR_GPIO) {
		reg = TPS68470_REG_SGPO;
		offset -= TPS68470_N_REGULAR_GPIO;
	}

	regmap_update_bits(regmap, reg, BIT(offset), value ? BIT(offset) : 0);
}

__attribute__((used)) static int tps68470_gpio_output(struct gpio_chip *gc, unsigned int offset,
				int value)
{
	struct tps68470_gpio_data *tps68470_gpio = gpiochip_get_data(gc);
	struct regmap *regmap = tps68470_gpio->tps68470_regmap;

	/* rest are always outputs */
	if (offset >= TPS68470_N_REGULAR_GPIO)
		return 0;

	/* Set the initial value */
	tps68470_gpio_set(gc, offset, value);

	return regmap_update_bits(regmap, TPS68470_GPIO_CTL_REG_A(offset),
				 TPS68470_GPIO_MODE_MASK,
				 TPS68470_GPIO_MODE_OUT_CMOS);
}

__attribute__((used)) static int tps68470_gpio_input(struct gpio_chip *gc, unsigned int offset)
{
	struct tps68470_gpio_data *tps68470_gpio = gpiochip_get_data(gc);
	struct regmap *regmap = tps68470_gpio->tps68470_regmap;

	/* rest are always outputs */
	if (offset >= TPS68470_N_REGULAR_GPIO)
		return -EINVAL;

	return regmap_update_bits(regmap, TPS68470_GPIO_CTL_REG_A(offset),
				   TPS68470_GPIO_MODE_MASK, 0x00);
}

__attribute__((used)) static int tps68470_gpio_probe(struct platform_device *pdev)
{
	struct tps68470_gpio_data *tps68470_gpio;
	int ret;

	tps68470_gpio = devm_kzalloc(&pdev->dev, sizeof(*tps68470_gpio),
				     GFP_KERNEL);
	if (!tps68470_gpio)
		return -ENOMEM;

	tps68470_gpio->tps68470_regmap = dev_get_drvdata(pdev->dev.parent);
	tps68470_gpio->gc.label = "tps68470-gpio";
	tps68470_gpio->gc.owner = THIS_MODULE;
	tps68470_gpio->gc.direction_input = tps68470_gpio_input;
	tps68470_gpio->gc.direction_output = tps68470_gpio_output;
	tps68470_gpio->gc.get = tps68470_gpio_get;
	tps68470_gpio->gc.get_direction = tps68470_gpio_get_direction;
	tps68470_gpio->gc.set = tps68470_gpio_set;
	tps68470_gpio->gc.can_sleep = true;
	tps68470_gpio->gc.names = tps68470_names;
	tps68470_gpio->gc.ngpio = TPS68470_N_GPIO;
	tps68470_gpio->gc.base = -1;
	tps68470_gpio->gc.parent = &pdev->dev;

	ret = devm_gpiochip_add_data(&pdev->dev, &tps68470_gpio->gc,
				     tps68470_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register gpio_chip: %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, tps68470_gpio);

	return ret;
}

