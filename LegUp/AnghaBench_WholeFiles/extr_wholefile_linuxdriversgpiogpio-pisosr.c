#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct device {int /*<<< orphan*/  of_node; } ;
struct spi_device {struct device dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  ngpio; struct device* parent; } ;
struct pisosr_gpio {unsigned int* buffer; int buffer_size; int /*<<< orphan*/  lock; TYPE_1__ chip; scalar_t__ load_gpio; struct spi_device* spi; } ;
struct gpio_chip {int /*<<< orphan*/  ngpio; } ;

/* Variables and functions */
 void* DIV_ROUND_UP (int /*<<< orphan*/ ,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  bitmap_zero (unsigned long*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 scalar_t__ devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int gpiochip_add_data (TYPE_1__*,struct pisosr_gpio*) ; 
 struct pisosr_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (TYPE_1__*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (scalar_t__,int) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_property_read_u16 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 struct pisosr_gpio* spi_get_drvdata (struct spi_device*) ; 
 int spi_read (struct spi_device*,unsigned int*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct pisosr_gpio*) ; 
 TYPE_1__ template_chip ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int pisosr_gpio_refresh(struct pisosr_gpio *gpio)
{
	int ret;

	mutex_lock(&gpio->lock);

	if (gpio->load_gpio) {
		gpiod_set_value_cansleep(gpio->load_gpio, 1);
		udelay(1); /* registers load time (~10ns) */
		gpiod_set_value_cansleep(gpio->load_gpio, 0);
		udelay(1); /* registers recovery time (~5ns) */
	}

	ret = spi_read(gpio->spi, gpio->buffer, gpio->buffer_size);

	mutex_unlock(&gpio->lock);

	return ret;
}

__attribute__((used)) static int pisosr_gpio_get_direction(struct gpio_chip *chip,
				     unsigned offset)
{
	/* This device always input */
	return 1;
}

__attribute__((used)) static int pisosr_gpio_direction_input(struct gpio_chip *chip,
				       unsigned offset)
{
	/* This device always input */
	return 0;
}

__attribute__((used)) static int pisosr_gpio_direction_output(struct gpio_chip *chip,
					unsigned offset, int value)
{
	/* This device is input only */
	return -EINVAL;
}

__attribute__((used)) static int pisosr_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct pisosr_gpio *gpio = gpiochip_get_data(chip);

	/* Refresh may not always be needed */
	pisosr_gpio_refresh(gpio);

	return (gpio->buffer[offset / 8] >> (offset % 8)) & 0x1;
}

__attribute__((used)) static int pisosr_gpio_get_multiple(struct gpio_chip *chip,
				    unsigned long *mask, unsigned long *bits)
{
	struct pisosr_gpio *gpio = gpiochip_get_data(chip);
	unsigned int nbytes = DIV_ROUND_UP(chip->ngpio, 8);
	unsigned int i, j;

	pisosr_gpio_refresh(gpio);

	bitmap_zero(bits, chip->ngpio);
	for (i = 0; i < nbytes; i++) {
		j = i / sizeof(unsigned long);
		bits[j] |= ((unsigned long) gpio->buffer[i])
			   << (8 * (i % sizeof(unsigned long)));
	}

	return 0;
}

__attribute__((used)) static int pisosr_gpio_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	struct pisosr_gpio *gpio;
	int ret;

	gpio = devm_kzalloc(dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	spi_set_drvdata(spi, gpio);

	gpio->chip = template_chip;
	gpio->chip.parent = dev;
	of_property_read_u16(dev->of_node, "ngpios", &gpio->chip.ngpio);

	gpio->spi = spi;

	gpio->buffer_size = DIV_ROUND_UP(gpio->chip.ngpio, 8);
	gpio->buffer = devm_kzalloc(dev, gpio->buffer_size, GFP_KERNEL);
	if (!gpio->buffer)
		return -ENOMEM;

	gpio->load_gpio = devm_gpiod_get_optional(dev, "load", GPIOD_OUT_LOW);
	if (IS_ERR(gpio->load_gpio)) {
		ret = PTR_ERR(gpio->load_gpio);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "Unable to allocate load GPIO\n");
		return ret;
	}

	mutex_init(&gpio->lock);

	ret = gpiochip_add_data(&gpio->chip, gpio);
	if (ret < 0) {
		dev_err(dev, "Unable to register gpiochip\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int pisosr_gpio_remove(struct spi_device *spi)
{
	struct pisosr_gpio *gpio = spi_get_drvdata(spi);

	gpiochip_remove(&gpio->chip);

	mutex_destroy(&gpio->lock);

	return 0;
}

