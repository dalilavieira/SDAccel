#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {scalar_t__ id; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct gpio_chip {int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int can_sleep; int ngpio; int /*<<< orphan*/  owner; int /*<<< orphan*/  label; int /*<<< orphan*/  base; } ;
struct adp5520_gpio_platform_data {int gpio_en_mask; unsigned char gpio_pullup_mask; int /*<<< orphan*/  gpio_start; } ;
struct adp5520_gpio {int* lut; struct gpio_chip gpio_chip; int /*<<< orphan*/  master; int /*<<< orphan*/  output; } ;

/* Variables and functions */
 unsigned char ADP5520_C3_MODE ; 
 int ADP5520_GPIO_C3 ; 
 int /*<<< orphan*/  ADP5520_GPIO_CFG_1 ; 
 int /*<<< orphan*/  ADP5520_GPIO_CFG_2 ; 
 int /*<<< orphan*/  ADP5520_GPIO_IN ; 
 int /*<<< orphan*/  ADP5520_GPIO_OUT ; 
 int /*<<< orphan*/  ADP5520_GPIO_PULLUP ; 
 int ADP5520_GPIO_R3 ; 
 int /*<<< orphan*/  ADP5520_LED_CONTROL ; 
 int ADP5520_MAXGPIOS ; 
 unsigned char ADP5520_R3_MODE ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ ID_ADP5520 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int adp5520_clr_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  adp5520_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int adp5520_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  clear_bit (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 struct adp5520_gpio_platform_data* dev_get_platdata (TYPE_1__*) ; 
 int devm_gpiochip_add_data (TYPE_1__*,struct gpio_chip*,struct adp5520_gpio*) ; 
 struct adp5520_gpio* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct adp5520_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct adp5520_gpio*) ; 
 int /*<<< orphan*/  set_bit (unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (unsigned int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int adp5520_gpio_get_value(struct gpio_chip *chip, unsigned off)
{
	struct adp5520_gpio *dev;
	uint8_t reg_val;

	dev = gpiochip_get_data(chip);

	/*
	 * There are dedicated registers for GPIO IN/OUT.
	 * Make sure we return the right value, even when configured as output
	 */

	if (test_bit(off, &dev->output))
		adp5520_read(dev->master, ADP5520_GPIO_OUT, &reg_val);
	else
		adp5520_read(dev->master, ADP5520_GPIO_IN, &reg_val);

	return !!(reg_val & dev->lut[off]);
}

__attribute__((used)) static void adp5520_gpio_set_value(struct gpio_chip *chip,
		unsigned off, int val)
{
	struct adp5520_gpio *dev;
	dev = gpiochip_get_data(chip);

	if (val)
		adp5520_set_bits(dev->master, ADP5520_GPIO_OUT, dev->lut[off]);
	else
		adp5520_clr_bits(dev->master, ADP5520_GPIO_OUT, dev->lut[off]);
}

__attribute__((used)) static int adp5520_gpio_direction_input(struct gpio_chip *chip, unsigned off)
{
	struct adp5520_gpio *dev;
	dev = gpiochip_get_data(chip);

	clear_bit(off, &dev->output);

	return adp5520_clr_bits(dev->master, ADP5520_GPIO_CFG_2,
				dev->lut[off]);
}

__attribute__((used)) static int adp5520_gpio_direction_output(struct gpio_chip *chip,
		unsigned off, int val)
{
	struct adp5520_gpio *dev;
	int ret = 0;
	dev = gpiochip_get_data(chip);

	set_bit(off, &dev->output);

	if (val)
		ret |= adp5520_set_bits(dev->master, ADP5520_GPIO_OUT,
					dev->lut[off]);
	else
		ret |= adp5520_clr_bits(dev->master, ADP5520_GPIO_OUT,
					dev->lut[off]);

	ret |= adp5520_set_bits(dev->master, ADP5520_GPIO_CFG_2,
					dev->lut[off]);

	return ret;
}

__attribute__((used)) static int adp5520_gpio_probe(struct platform_device *pdev)
{
	struct adp5520_gpio_platform_data *pdata = dev_get_platdata(&pdev->dev);
	struct adp5520_gpio *dev;
	struct gpio_chip *gc;
	int ret, i, gpios;
	unsigned char ctl_mask = 0;

	if (pdata == NULL) {
		dev_err(&pdev->dev, "missing platform data\n");
		return -ENODEV;
	}

	if (pdev->id != ID_ADP5520) {
		dev_err(&pdev->dev, "only ADP5520 supports GPIO\n");
		return -ENODEV;
	}

	dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
	if (dev == NULL)
		return -ENOMEM;

	dev->master = pdev->dev.parent;

	for (gpios = 0, i = 0; i < ADP5520_MAXGPIOS; i++)
		if (pdata->gpio_en_mask & (1 << i))
			dev->lut[gpios++] = 1 << i;

	if (gpios < 1) {
		ret = -EINVAL;
		goto err;
	}

	gc = &dev->gpio_chip;
	gc->direction_input  = adp5520_gpio_direction_input;
	gc->direction_output = adp5520_gpio_direction_output;
	gc->get = adp5520_gpio_get_value;
	gc->set = adp5520_gpio_set_value;
	gc->can_sleep = true;

	gc->base = pdata->gpio_start;
	gc->ngpio = gpios;
	gc->label = pdev->name;
	gc->owner = THIS_MODULE;

	ret = adp5520_clr_bits(dev->master, ADP5520_GPIO_CFG_1,
		pdata->gpio_en_mask);

	if (pdata->gpio_en_mask & ADP5520_GPIO_C3)
		ctl_mask |= ADP5520_C3_MODE;

	if (pdata->gpio_en_mask & ADP5520_GPIO_R3)
		ctl_mask |= ADP5520_R3_MODE;

	if (ctl_mask)
		ret = adp5520_set_bits(dev->master, ADP5520_LED_CONTROL,
			ctl_mask);

	ret |= adp5520_set_bits(dev->master, ADP5520_GPIO_PULLUP,
		pdata->gpio_pullup_mask);

	if (ret) {
		dev_err(&pdev->dev, "failed to write\n");
		goto err;
	}

	ret = devm_gpiochip_add_data(&pdev->dev, &dev->gpio_chip, dev);
	if (ret)
		goto err;

	platform_set_drvdata(pdev, dev);
	return 0;

err:
	return ret;
}

