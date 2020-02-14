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
struct wm831x_pdata {int gpio_base; } ;
struct TYPE_6__ {int base; TYPE_2__* parent; int /*<<< orphan*/  ngpio; } ;
struct wm831x_gpio {TYPE_1__ gpio_chip; struct wm831x* wm831x; } ;
struct wm831x {int /*<<< orphan*/  num_gpio; struct wm831x_pdata pdata; int /*<<< orphan*/  irq_domain; scalar_t__ has_gpio_ena; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 130 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 129 
#define  PIN_CONFIG_INPUT_DEBOUNCE 128 
 unsigned int WM831X_GPIO1_CONTROL ; 
 int WM831X_GPIO_LEVEL ; 
 int WM831X_GPN_DIR ; 
 int WM831X_GPN_FN_MASK ; 
 int WM831X_GPN_OD ; 
 int WM831X_GPN_OD_MASK ; 
 int WM831X_GPN_TRI ; 
 unsigned int WM831X_IRQ_GPIO_1 ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct wm831x* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct wm831x_gpio*) ; 
 struct wm831x_gpio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct wm831x_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int irq_create_mapping (int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int pinconf_to_config_argument (unsigned long) ; 
 int pinconf_to_config_param (unsigned long) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm831x_gpio*) ; 
 TYPE_1__ template_chip ; 
 int wm831x_reg_read (struct wm831x*,int) ; 
 int wm831x_set_bits (struct wm831x*,int,int,int) ; 

__attribute__((used)) static int wm831x_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
	struct wm831x_gpio *wm831x_gpio = gpiochip_get_data(chip);
	struct wm831x *wm831x = wm831x_gpio->wm831x;
	int val = WM831X_GPN_DIR;

	if (wm831x->has_gpio_ena)
		val |= WM831X_GPN_TRI;

	return wm831x_set_bits(wm831x, WM831X_GPIO1_CONTROL + offset,
			       WM831X_GPN_DIR | WM831X_GPN_TRI |
			       WM831X_GPN_FN_MASK, val);
}

__attribute__((used)) static int wm831x_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct wm831x_gpio *wm831x_gpio = gpiochip_get_data(chip);
	struct wm831x *wm831x = wm831x_gpio->wm831x;
	int ret;

	ret = wm831x_reg_read(wm831x, WM831X_GPIO_LEVEL);
	if (ret < 0)
		return ret;

	if (ret & 1 << offset)
		return 1;
	else
		return 0;
}

__attribute__((used)) static void wm831x_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
	struct wm831x_gpio *wm831x_gpio = gpiochip_get_data(chip);
	struct wm831x *wm831x = wm831x_gpio->wm831x;

	wm831x_set_bits(wm831x, WM831X_GPIO_LEVEL, 1 << offset,
			value << offset);
}

__attribute__((used)) static int wm831x_gpio_direction_out(struct gpio_chip *chip,
				     unsigned offset, int value)
{
	struct wm831x_gpio *wm831x_gpio = gpiochip_get_data(chip);
	struct wm831x *wm831x = wm831x_gpio->wm831x;
	int val = 0;
	int ret;

	if (wm831x->has_gpio_ena)
		val |= WM831X_GPN_TRI;

	ret = wm831x_set_bits(wm831x, WM831X_GPIO1_CONTROL + offset,
			      WM831X_GPN_DIR | WM831X_GPN_TRI |
			      WM831X_GPN_FN_MASK, val);
	if (ret < 0)
		return ret;

	/* Can only set GPIO state once it's in output mode */
	wm831x_gpio_set(chip, offset, value);

	return 0;
}

__attribute__((used)) static int wm831x_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
	struct wm831x_gpio *wm831x_gpio = gpiochip_get_data(chip);
	struct wm831x *wm831x = wm831x_gpio->wm831x;

	return irq_create_mapping(wm831x->irq_domain,
				  WM831X_IRQ_GPIO_1 + offset);
}

__attribute__((used)) static int wm831x_gpio_set_debounce(struct wm831x *wm831x, unsigned offset,
				    unsigned debounce)
{
	int reg = WM831X_GPIO1_CONTROL + offset;
	int ret, fn;

	ret = wm831x_reg_read(wm831x, reg);
	if (ret < 0)
		return ret;

	switch (ret & WM831X_GPN_FN_MASK) {
	case 0:
	case 1:
		break;
	default:
		/* Not in GPIO mode */
		return -EBUSY;
	}

	if (debounce >= 32 && debounce <= 64)
		fn = 0;
	else if (debounce >= 4000 && debounce <= 8000)
		fn = 1;
	else
		return -EINVAL;

	return wm831x_set_bits(wm831x, reg, WM831X_GPN_FN_MASK, fn);
}

__attribute__((used)) static int wm831x_set_config(struct gpio_chip *chip, unsigned int offset,
			     unsigned long config)
{
	struct wm831x_gpio *wm831x_gpio = gpiochip_get_data(chip);
	struct wm831x *wm831x = wm831x_gpio->wm831x;
	int reg = WM831X_GPIO1_CONTROL + offset;

	switch (pinconf_to_config_param(config)) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		return wm831x_set_bits(wm831x, reg,
				       WM831X_GPN_OD_MASK, WM831X_GPN_OD);
	case PIN_CONFIG_DRIVE_PUSH_PULL:
		return wm831x_set_bits(wm831x, reg,
				       WM831X_GPN_OD_MASK, 0);
	case PIN_CONFIG_INPUT_DEBOUNCE:
		return wm831x_gpio_set_debounce(wm831x, offset,
			pinconf_to_config_argument(config));
	default:
		break;
	}

	return -ENOTSUPP;
}

__attribute__((used)) static int wm831x_gpio_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_pdata *pdata = &wm831x->pdata;
	struct wm831x_gpio *wm831x_gpio;
	int ret;

	wm831x_gpio = devm_kzalloc(&pdev->dev, sizeof(*wm831x_gpio),
				   GFP_KERNEL);
	if (wm831x_gpio == NULL)
		return -ENOMEM;

	wm831x_gpio->wm831x = wm831x;
	wm831x_gpio->gpio_chip = template_chip;
	wm831x_gpio->gpio_chip.ngpio = wm831x->num_gpio;
	wm831x_gpio->gpio_chip.parent = &pdev->dev;
	if (pdata && pdata->gpio_base)
		wm831x_gpio->gpio_chip.base = pdata->gpio_base;
	else
		wm831x_gpio->gpio_chip.base = -1;
#ifdef CONFIG_OF_GPIO
	wm831x_gpio->gpio_chip.of_node = wm831x->dev->of_node;
#endif

	ret = devm_gpiochip_add_data(&pdev->dev, &wm831x_gpio->gpio_chip,
				     wm831x_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, wm831x_gpio);

	return ret;
}

