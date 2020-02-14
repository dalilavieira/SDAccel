#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  unsigned int u32 ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {int bits_per_word; TYPE_1__ dev; int /*<<< orphan*/  modalias; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_8__ {int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;void (* set_multiple ) (struct gpio_chip*,unsigned long*,unsigned long*) ;int base; int ngpio; int can_sleep; int /*<<< orphan*/  owner; TYPE_1__* parent; int /*<<< orphan*/  label; } ;
struct gen_74x164_chip {size_t* buffer; int registers; int /*<<< orphan*/  lock; TYPE_2__ gpio_chip; int /*<<< orphan*/  gpiod_oe; } ;

/* Variables and functions */
 unsigned int BITS_PER_BYTE ; 
 int EINVAL ; 
 int ENOMEM ; 
 int GEN_74X164_NUMBER_GPIOS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  devm_gpiod_get_optional (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 struct gen_74x164_chip* devm_kzalloc (TYPE_1__*,unsigned int,int /*<<< orphan*/ ) ; 
 int gpiochip_add_data (TYPE_2__*,struct gen_74x164_chip*) ; 
 struct gen_74x164_chip* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (TYPE_2__*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,unsigned int*) ; 
 struct gen_74x164_chip* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct gen_74x164_chip*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_write (int /*<<< orphan*/ ,size_t*,int) ; 
 int /*<<< orphan*/  to_spi_device (TYPE_1__*) ; 

__attribute__((used)) static int __gen_74x164_write_config(struct gen_74x164_chip *chip)
{
	return spi_write(to_spi_device(chip->gpio_chip.parent), chip->buffer,
			 chip->registers);
}

__attribute__((used)) static int gen_74x164_get_value(struct gpio_chip *gc, unsigned offset)
{
	struct gen_74x164_chip *chip = gpiochip_get_data(gc);
	u8 bank = chip->registers - 1 - offset / 8;
	u8 pin = offset % 8;
	int ret;

	mutex_lock(&chip->lock);
	ret = (chip->buffer[bank] >> pin) & 0x1;
	mutex_unlock(&chip->lock);

	return ret;
}

__attribute__((used)) static void gen_74x164_set_value(struct gpio_chip *gc,
		unsigned offset, int val)
{
	struct gen_74x164_chip *chip = gpiochip_get_data(gc);
	u8 bank = chip->registers - 1 - offset / 8;
	u8 pin = offset % 8;

	mutex_lock(&chip->lock);
	if (val)
		chip->buffer[bank] |= (1 << pin);
	else
		chip->buffer[bank] &= ~(1 << pin);

	__gen_74x164_write_config(chip);
	mutex_unlock(&chip->lock);
}

__attribute__((used)) static void gen_74x164_set_multiple(struct gpio_chip *gc, unsigned long *mask,
				    unsigned long *bits)
{
	struct gen_74x164_chip *chip = gpiochip_get_data(gc);
	unsigned int i, idx, shift;
	u8 bank, bankmask;

	mutex_lock(&chip->lock);
	for (i = 0, bank = chip->registers - 1; i < chip->registers;
	     i++, bank--) {
		idx = i / sizeof(*mask);
		shift = i % sizeof(*mask) * BITS_PER_BYTE;
		bankmask = mask[idx] >> shift;
		if (!bankmask)
			continue;

		chip->buffer[bank] &= ~bankmask;
		chip->buffer[bank] |= bankmask & (bits[idx] >> shift);
	}
	__gen_74x164_write_config(chip);
	mutex_unlock(&chip->lock);
}

__attribute__((used)) static int gen_74x164_direction_output(struct gpio_chip *gc,
		unsigned offset, int val)
{
	gen_74x164_set_value(gc, offset, val);
	return 0;
}

__attribute__((used)) static int gen_74x164_probe(struct spi_device *spi)
{
	struct gen_74x164_chip *chip;
	u32 nregs;
	int ret;

	/*
	 * bits_per_word cannot be configured in platform data
	 */
	spi->bits_per_word = 8;

	ret = spi_setup(spi);
	if (ret < 0)
		return ret;

	if (of_property_read_u32(spi->dev.of_node, "registers-number",
				 &nregs)) {
		dev_err(&spi->dev,
			"Missing registers-number property in the DT.\n");
		return -EINVAL;
	}

	chip = devm_kzalloc(&spi->dev, sizeof(*chip) + nregs, GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	chip->gpiod_oe = devm_gpiod_get_optional(&spi->dev, "enable",
						 GPIOD_OUT_LOW);
	if (IS_ERR(chip->gpiod_oe))
		return PTR_ERR(chip->gpiod_oe);

	gpiod_set_value_cansleep(chip->gpiod_oe, 1);

	spi_set_drvdata(spi, chip);

	chip->gpio_chip.label = spi->modalias;
	chip->gpio_chip.direction_output = gen_74x164_direction_output;
	chip->gpio_chip.get = gen_74x164_get_value;
	chip->gpio_chip.set = gen_74x164_set_value;
	chip->gpio_chip.set_multiple = gen_74x164_set_multiple;
	chip->gpio_chip.base = -1;

	chip->registers = nregs;
	chip->gpio_chip.ngpio = GEN_74X164_NUMBER_GPIOS * chip->registers;

	chip->gpio_chip.can_sleep = true;
	chip->gpio_chip.parent = &spi->dev;
	chip->gpio_chip.owner = THIS_MODULE;

	mutex_init(&chip->lock);

	ret = __gen_74x164_write_config(chip);
	if (ret) {
		dev_err(&spi->dev, "Failed writing: %d\n", ret);
		goto exit_destroy;
	}

	ret = gpiochip_add_data(&chip->gpio_chip, chip);
	if (!ret)
		return 0;

exit_destroy:
	mutex_destroy(&chip->lock);

	return ret;
}

__attribute__((used)) static int gen_74x164_remove(struct spi_device *spi)
{
	struct gen_74x164_chip *chip = spi_get_drvdata(spi);

	gpiod_set_value_cansleep(chip->gpiod_oe, 0);
	gpiochip_remove(&chip->gpio_chip);
	mutex_destroy(&chip->lock);

	return 0;
}

