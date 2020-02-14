#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get_direction ) (struct gpio_chip*,unsigned int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int ngpio; char* label; int base; int can_sleep; int /*<<< orphan*/  owner; int /*<<< orphan*/ * parent; int /*<<< orphan*/  dbg_show; } ;
struct xra1403 {TYPE_1__ chip; struct gpio_desc* regmap; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct gpio_desc {int dummy; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 unsigned int BIT (unsigned int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int PTR_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 unsigned int XRA_GCR ; 
 unsigned int XRA_GSR ; 
 unsigned int XRA_OCR ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int devm_gpiochip_add_data (int /*<<< orphan*/ *,TYPE_1__*,struct xra1403*) ; 
 struct gpio_desc* devm_gpiod_get_optional (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct xra1403* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct gpio_desc* devm_regmap_init_spi (struct spi_device*,int /*<<< orphan*/ *) ; 
 struct xra1403* gpiochip_get_data (struct gpio_chip*) ; 
 int regmap_read (struct gpio_desc*,unsigned int,unsigned int*) ; 
 int regmap_update_bits (struct gpio_desc*,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct xra1403*) ; 
 int /*<<< orphan*/  xra1403_dbg_show ; 
 int /*<<< orphan*/  xra1403_regmap_cfg ; 

__attribute__((used)) static unsigned int to_reg(unsigned int reg, unsigned int offset)
{
	return reg + (offset > 7);
}

__attribute__((used)) static int xra1403_direction_input(struct gpio_chip *chip, unsigned int offset)
{
	struct xra1403 *xra = gpiochip_get_data(chip);

	return regmap_update_bits(xra->regmap, to_reg(XRA_GCR, offset),
			BIT(offset % 8), BIT(offset % 8));
}

__attribute__((used)) static int xra1403_direction_output(struct gpio_chip *chip, unsigned int offset,
				    int value)
{
	int ret;
	struct xra1403 *xra = gpiochip_get_data(chip);

	ret = regmap_update_bits(xra->regmap, to_reg(XRA_GCR, offset),
			BIT(offset % 8), 0);
	if (ret)
		return ret;

	ret = regmap_update_bits(xra->regmap, to_reg(XRA_OCR, offset),
			BIT(offset % 8), value ? BIT(offset % 8) : 0);

	return ret;
}

__attribute__((used)) static int xra1403_get_direction(struct gpio_chip *chip, unsigned int offset)
{
	int ret;
	unsigned int val;
	struct xra1403 *xra = gpiochip_get_data(chip);

	ret = regmap_read(xra->regmap, to_reg(XRA_GCR, offset), &val);
	if (ret)
		return ret;

	return !!(val & BIT(offset % 8));
}

__attribute__((used)) static int xra1403_get(struct gpio_chip *chip, unsigned int offset)
{
	int ret;
	unsigned int val;
	struct xra1403 *xra = gpiochip_get_data(chip);

	ret = regmap_read(xra->regmap, to_reg(XRA_GSR, offset), &val);
	if (ret)
		return ret;

	return !!(val & BIT(offset % 8));
}

__attribute__((used)) static void xra1403_set(struct gpio_chip *chip, unsigned int offset, int value)
{
	int ret;
	struct xra1403 *xra = gpiochip_get_data(chip);

	ret = regmap_update_bits(xra->regmap, to_reg(XRA_OCR, offset),
			BIT(offset % 8), value ? BIT(offset % 8) : 0);
	if (ret)
		dev_err(chip->parent, "Failed to set pin: %d, ret: %d\n",
				offset, ret);
}

__attribute__((used)) static int xra1403_probe(struct spi_device *spi)
{
	struct xra1403 *xra;
	struct gpio_desc *reset_gpio;
	int ret;

	xra = devm_kzalloc(&spi->dev, sizeof(*xra), GFP_KERNEL);
	if (!xra)
		return -ENOMEM;

	/* bring the chip out of reset if reset pin is provided*/
	reset_gpio = devm_gpiod_get_optional(&spi->dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(reset_gpio))
		dev_warn(&spi->dev, "Could not get reset-gpios\n");

	xra->chip.direction_input = xra1403_direction_input;
	xra->chip.direction_output = xra1403_direction_output;
	xra->chip.get_direction = xra1403_get_direction;
	xra->chip.get = xra1403_get;
	xra->chip.set = xra1403_set;

	xra->chip.dbg_show = xra1403_dbg_show;

	xra->chip.ngpio = 16;
	xra->chip.label = "xra1403";

	xra->chip.base = -1;
	xra->chip.can_sleep = true;
	xra->chip.parent = &spi->dev;
	xra->chip.owner = THIS_MODULE;

	xra->regmap = devm_regmap_init_spi(spi, &xra1403_regmap_cfg);
	if (IS_ERR(xra->regmap)) {
		ret = PTR_ERR(xra->regmap);
		dev_err(&spi->dev, "Failed to allocate regmap: %d\n", ret);
		return ret;
	}

	ret = devm_gpiochip_add_data(&spi->dev, &xra->chip, xra);
	if (ret < 0) {
		dev_err(&spi->dev, "Unable to register gpiochip\n");
		return ret;
	}

	spi_set_drvdata(spi, xra);

	return 0;
}

