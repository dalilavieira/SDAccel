#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct TYPE_8__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct of_phandle_args {size_t* args; } ;
struct lpc32xx_gpio_chip {TYPE_1__* gpio_grp; } ;
struct gpio_chip {unsigned int ngpio; int (* of_xlate ) (struct gpio_chip*,struct of_phandle_args const*,size_t*) ;int of_gpio_n_cells; scalar_t__ of_node; } ;
struct TYPE_7__ {struct gpio_chip chip; } ;
struct TYPE_6__ {int /*<<< orphan*/  outp_state; int /*<<< orphan*/  inp_state; int /*<<< orphan*/  outp_clr; int /*<<< orphan*/  outp_set; int /*<<< orphan*/  dir_set; int /*<<< orphan*/  dir_clr; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int ENXIO ; 
 int GPI3_PIN_IN_SEL (int,unsigned int) ; 
 int GPIO012_PIN_IN_SEL (int,unsigned int) ; 
 size_t GPIO012_PIN_TO_BIT (unsigned int) ; 
 int GPIO3_PIN_IN_SEL (int,unsigned int) ; 
 size_t GPIO3_PIN_TO_BIT (unsigned int) ; 
 int GPO3_PIN_IN_SEL (int,unsigned int) ; 
 size_t GPO3_PIN_TO_BIT (unsigned int) ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_gpiochip_add_data (TYPE_3__*,struct gpio_chip*,TYPE_2__*) ; 
 struct lpc32xx_gpio_chip* gpiochip_get_data (struct gpio_chip*) ; 
 TYPE_2__* lpc32xx_gpiochip ; 

__attribute__((used)) static void __set_gpio_dir_p012(struct lpc32xx_gpio_chip *group,
	unsigned pin, int input)
{
	if (input)
		__raw_writel(GPIO012_PIN_TO_BIT(pin),
			group->gpio_grp->dir_clr);
	else
		__raw_writel(GPIO012_PIN_TO_BIT(pin),
			group->gpio_grp->dir_set);
}

__attribute__((used)) static void __set_gpio_dir_p3(struct lpc32xx_gpio_chip *group,
	unsigned pin, int input)
{
	u32 u = GPIO3_PIN_TO_BIT(pin);

	if (input)
		__raw_writel(u, group->gpio_grp->dir_clr);
	else
		__raw_writel(u, group->gpio_grp->dir_set);
}

__attribute__((used)) static void __set_gpio_level_p012(struct lpc32xx_gpio_chip *group,
	unsigned pin, int high)
{
	if (high)
		__raw_writel(GPIO012_PIN_TO_BIT(pin),
			group->gpio_grp->outp_set);
	else
		__raw_writel(GPIO012_PIN_TO_BIT(pin),
			group->gpio_grp->outp_clr);
}

__attribute__((used)) static void __set_gpio_level_p3(struct lpc32xx_gpio_chip *group,
	unsigned pin, int high)
{
	u32 u = GPIO3_PIN_TO_BIT(pin);

	if (high)
		__raw_writel(u, group->gpio_grp->outp_set);
	else
		__raw_writel(u, group->gpio_grp->outp_clr);
}

__attribute__((used)) static void __set_gpo_level_p3(struct lpc32xx_gpio_chip *group,
	unsigned pin, int high)
{
	if (high)
		__raw_writel(GPO3_PIN_TO_BIT(pin), group->gpio_grp->outp_set);
	else
		__raw_writel(GPO3_PIN_TO_BIT(pin), group->gpio_grp->outp_clr);
}

__attribute__((used)) static int __get_gpio_state_p012(struct lpc32xx_gpio_chip *group,
	unsigned pin)
{
	return GPIO012_PIN_IN_SEL(__raw_readl(group->gpio_grp->inp_state),
		pin);
}

__attribute__((used)) static int __get_gpio_state_p3(struct lpc32xx_gpio_chip *group,
	unsigned pin)
{
	int state = __raw_readl(group->gpio_grp->inp_state);

	/*
	 * P3 GPIO pin input mapping is not contiguous, GPIOP3-0..4 is mapped
	 * to bits 10..14, while GPIOP3-5 is mapped to bit 24.
	 */
	return GPIO3_PIN_IN_SEL(state, pin);
}

__attribute__((used)) static int __get_gpi_state_p3(struct lpc32xx_gpio_chip *group,
	unsigned pin)
{
	return GPI3_PIN_IN_SEL(__raw_readl(group->gpio_grp->inp_state), pin);
}

__attribute__((used)) static int __get_gpo_state_p3(struct lpc32xx_gpio_chip *group,
	unsigned pin)
{
	return GPO3_PIN_IN_SEL(__raw_readl(group->gpio_grp->outp_state), pin);
}

__attribute__((used)) static int lpc32xx_gpio_dir_input_p012(struct gpio_chip *chip,
	unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpio_dir_p012(group, pin, 1);

	return 0;
}

__attribute__((used)) static int lpc32xx_gpio_dir_input_p3(struct gpio_chip *chip,
	unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpio_dir_p3(group, pin, 1);

	return 0;
}

__attribute__((used)) static int lpc32xx_gpio_dir_in_always(struct gpio_chip *chip,
	unsigned pin)
{
	return 0;
}

__attribute__((used)) static int lpc32xx_gpio_get_value_p012(struct gpio_chip *chip, unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	return !!__get_gpio_state_p012(group, pin);
}

__attribute__((used)) static int lpc32xx_gpio_get_value_p3(struct gpio_chip *chip, unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	return !!__get_gpio_state_p3(group, pin);
}

__attribute__((used)) static int lpc32xx_gpi_get_value(struct gpio_chip *chip, unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	return !!__get_gpi_state_p3(group, pin);
}

__attribute__((used)) static int lpc32xx_gpio_dir_output_p012(struct gpio_chip *chip, unsigned pin,
	int value)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpio_level_p012(group, pin, value);
	__set_gpio_dir_p012(group, pin, 0);

	return 0;
}

__attribute__((used)) static int lpc32xx_gpio_dir_output_p3(struct gpio_chip *chip, unsigned pin,
	int value)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpio_level_p3(group, pin, value);
	__set_gpio_dir_p3(group, pin, 0);

	return 0;
}

__attribute__((used)) static int lpc32xx_gpio_dir_out_always(struct gpio_chip *chip, unsigned pin,
	int value)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpo_level_p3(group, pin, value);
	return 0;
}

__attribute__((used)) static void lpc32xx_gpio_set_value_p012(struct gpio_chip *chip, unsigned pin,
	int value)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpio_level_p012(group, pin, value);
}

__attribute__((used)) static void lpc32xx_gpio_set_value_p3(struct gpio_chip *chip, unsigned pin,
	int value)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpio_level_p3(group, pin, value);
}

__attribute__((used)) static void lpc32xx_gpo_set_value(struct gpio_chip *chip, unsigned pin,
	int value)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	__set_gpo_level_p3(group, pin, value);
}

__attribute__((used)) static int lpc32xx_gpo_get_value(struct gpio_chip *chip, unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	return !!__get_gpo_state_p3(group, pin);
}

__attribute__((used)) static int lpc32xx_gpio_request(struct gpio_chip *chip, unsigned pin)
{
	if (pin < chip->ngpio)
		return 0;

	return -EINVAL;
}

__attribute__((used)) static int lpc32xx_gpio_to_irq_p01(struct gpio_chip *chip, unsigned offset)
{
	return -ENXIO;
}

__attribute__((used)) static int lpc32xx_gpio_to_irq_gpio_p3(struct gpio_chip *chip, unsigned offset)
{
	return -ENXIO;
}

__attribute__((used)) static int lpc32xx_gpio_to_irq_gpi_p3(struct gpio_chip *chip, unsigned offset)
{
	return -ENXIO;
}

__attribute__((used)) static int lpc32xx_of_xlate(struct gpio_chip *gc,
			    const struct of_phandle_args *gpiospec, u32 *flags)
{
	/* Is this the correct bank? */
	u32 bank = gpiospec->args[0];
	if ((bank >= ARRAY_SIZE(lpc32xx_gpiochip) ||
	    (gc != &lpc32xx_gpiochip[bank].chip)))
		return -EINVAL;

	if (flags)
		*flags = gpiospec->args[2];
	return gpiospec->args[1];
}

__attribute__((used)) static int lpc32xx_gpio_probe(struct platform_device *pdev)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(lpc32xx_gpiochip); i++) {
		if (pdev->dev.of_node) {
			lpc32xx_gpiochip[i].chip.of_xlate = lpc32xx_of_xlate;
			lpc32xx_gpiochip[i].chip.of_gpio_n_cells = 3;
			lpc32xx_gpiochip[i].chip.of_node = pdev->dev.of_node;
		}
		devm_gpiochip_add_data(&pdev->dev, &lpc32xx_gpiochip[i].chip,
				  &lpc32xx_gpiochip[i]);
	}

	return 0;
}

