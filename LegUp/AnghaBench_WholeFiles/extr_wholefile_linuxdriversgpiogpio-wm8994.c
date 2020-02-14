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
struct wm8994_pdata {int gpio_base; } ;
struct TYPE_6__ {int base; TYPE_2__* parent; int /*<<< orphan*/  ngpio; } ;
struct wm8994_gpio {TYPE_1__ gpio_chip; struct wm8994* wm8994; } ;
struct wm8994 {int type; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq_data; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 130 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 129 
#define  WM8958 128 
 unsigned int WM8994_GPIO_1 ; 
 int /*<<< orphan*/  WM8994_GPIO_MAX ; 
 int WM8994_GPN_DIR ; 
 int WM8994_GPN_LVL ; 
 int WM8994_GPN_OP_CFG ; 
 int WM8994_GPN_OP_CFG_MASK ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct wm8994* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct wm8994_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct wm8994_gpio*) ; 
 struct wm8994_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct wm8994_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int pinconf_to_config_param (unsigned long) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm8994_gpio*) ; 
 int regmap_irq_get_virq (int /*<<< orphan*/ ,unsigned int) ; 
 TYPE_1__ template_chip ; 
 int wm8994_reg_read (struct wm8994*,unsigned int) ; 
 int wm8994_set_bits (struct wm8994*,unsigned int,int,int) ; 

__attribute__((used)) static int wm8994_gpio_request(struct gpio_chip *chip, unsigned offset)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;

	switch (wm8994->type) {
	case WM8958:
		switch (offset) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 6:
			return -EINVAL;
		}
		break;
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int wm8994_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;

	return wm8994_set_bits(wm8994, WM8994_GPIO_1 + offset,
			       WM8994_GPN_DIR, WM8994_GPN_DIR);
}

__attribute__((used)) static int wm8994_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;
	int ret;

	ret = wm8994_reg_read(wm8994, WM8994_GPIO_1 + offset);
	if (ret < 0)
		return ret;

	if (ret & WM8994_GPN_LVL)
		return 1;
	else
		return 0;
}

__attribute__((used)) static int wm8994_gpio_direction_out(struct gpio_chip *chip,
				     unsigned offset, int value)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;

	if (value)
		value = WM8994_GPN_LVL;

	return wm8994_set_bits(wm8994, WM8994_GPIO_1 + offset,
			       WM8994_GPN_DIR | WM8994_GPN_LVL, value);
}

__attribute__((used)) static void wm8994_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;

	if (value)
		value = WM8994_GPN_LVL;

	wm8994_set_bits(wm8994, WM8994_GPIO_1 + offset, WM8994_GPN_LVL, value);
}

__attribute__((used)) static int wm8994_gpio_set_config(struct gpio_chip *chip, unsigned int offset,
				  unsigned long config)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;

	switch (pinconf_to_config_param(config)) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		return wm8994_set_bits(wm8994, WM8994_GPIO_1 + offset,
				       WM8994_GPN_OP_CFG_MASK,
				       WM8994_GPN_OP_CFG);
	case PIN_CONFIG_DRIVE_PUSH_PULL:
		return wm8994_set_bits(wm8994, WM8994_GPIO_1 + offset,
				       WM8994_GPN_OP_CFG_MASK, 0);
	default:
		break;
	}

	return -ENOTSUPP;
}

__attribute__((used)) static int wm8994_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
	struct wm8994_gpio *wm8994_gpio = gpiochip_get_data(chip);
	struct wm8994 *wm8994 = wm8994_gpio->wm8994;

	return regmap_irq_get_virq(wm8994->irq_data, offset);
}

__attribute__((used)) static int wm8994_gpio_probe(struct platform_device *pdev)
{
	struct wm8994 *wm8994 = dev_get_drvdata(pdev->dev.parent);
	struct wm8994_pdata *pdata = dev_get_platdata(wm8994->dev);
	struct wm8994_gpio *wm8994_gpio;
	int ret;

	wm8994_gpio = devm_kzalloc(&pdev->dev, sizeof(*wm8994_gpio),
				   GFP_KERNEL);
	if (wm8994_gpio == NULL)
		return -ENOMEM;

	wm8994_gpio->wm8994 = wm8994;
	wm8994_gpio->gpio_chip = template_chip;
	wm8994_gpio->gpio_chip.ngpio = WM8994_GPIO_MAX;
	wm8994_gpio->gpio_chip.parent = &pdev->dev;
	if (pdata && pdata->gpio_base)
		wm8994_gpio->gpio_chip.base = pdata->gpio_base;
	else
		wm8994_gpio->gpio_chip.base = -1;

	ret = devm_gpiochip_add_data(&pdev->dev, &wm8994_gpio->gpio_chip,
				     wm8994_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n",
			ret);
		return ret;
	}

	platform_set_drvdata(pdev, wm8994_gpio);

	return ret;
}

