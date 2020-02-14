#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_10__ {int /*<<< orphan*/  domain; } ;
struct TYPE_11__ {int base; struct device_node* of_node; TYPE_5__* parent; int /*<<< orphan*/  ngpio; TYPE_1__ irq; } ;
struct tc3589x_gpio {int** regs; int** oldregs; TYPE_2__ chip; struct tc3589x* tc3589x; TYPE_5__* dev; int /*<<< orphan*/  irq_lock; } ;
struct tc3589x {int /*<<< orphan*/  num_gpio; } ;
struct TYPE_12__ {struct device_node* of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_5__ dev; } ;
struct irq_data {int hwirq; } ;
struct gpio_chip {int dummy; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int BIT (int) ; 
 int CACHE_NR_BANKS ; 
 int CACHE_NR_REGS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int IRQ_TYPE_EDGE_BOTH ; 
 unsigned int IRQ_TYPE_EDGE_RISING ; 
 unsigned int IRQ_TYPE_LEVEL_HIGH ; 
 unsigned int IRQ_TYPE_LEVEL_LOW ; 
 int /*<<< orphan*/  IRQ_TYPE_NONE ; 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 138 
#define  PIN_CONFIG_DRIVE_OPEN_SOURCE 137 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 136 
#define  REG_IBE 135 
#define  REG_IE 134 
#define  REG_IEV 133 
#define  REG_IS 132 
 int TC3589x_GPIODATA0 ; 
 int TC3589x_GPIODIR0 ; 
#define  TC3589x_GPIOIBE0 131 
 int const TC3589x_GPIOIC0 ; 
#define  TC3589x_GPIOIE0 130 
#define  TC3589x_GPIOIEV0 129 
#define  TC3589x_GPIOIS0 128 
 int /*<<< orphan*/  TC3589x_GPIOMIS0 ; 
 int TC3589x_GPIOODE0 ; 
 int TC3589x_GPIOODM0 ; 
 int TC3589x_RSTCTRL ; 
 int TC3589x_RSTCTRL_GPIRST ; 
 int __ffs (unsigned int) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 struct tc3589x* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_5__*,TYPE_2__*,struct tc3589x_gpio*) ; 
 struct tc3589x_gpio* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_5__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct tc3589x_gpio*) ; 
 struct tc3589x_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int gpiochip_irqchip_add_nested (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiochip_set_nested_irqchip (TYPE_2__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  handle_nested_irq (int) ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 struct gpio_chip* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int irq_find_mapping (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int pinconf_to_config_param (unsigned long) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tc3589x_gpio*) ; 
 int tc3589x_block_read (struct tc3589x*,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  tc3589x_block_write (struct tc3589x*,int,int,int*) ; 
 int /*<<< orphan*/  tc3589x_gpio_irq_chip ; 
 int tc3589x_reg_read (struct tc3589x*,int) ; 
 int /*<<< orphan*/  tc3589x_reg_write (struct tc3589x*,int const,int) ; 
 int tc3589x_set_bits (struct tc3589x*,int,int,int) ; 
 TYPE_2__ template_chip ; 

__attribute__((used)) static int tc3589x_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(chip);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	u8 reg = TC3589x_GPIODATA0 + (offset / 8) * 2;
	u8 mask = BIT(offset % 8);
	int ret;

	ret = tc3589x_reg_read(tc3589x, reg);
	if (ret < 0)
		return ret;

	return !!(ret & mask);
}

__attribute__((used)) static void tc3589x_gpio_set(struct gpio_chip *chip, unsigned int offset, int val)
{
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(chip);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	u8 reg = TC3589x_GPIODATA0 + (offset / 8) * 2;
	unsigned int pos = offset % 8;
	u8 data[] = {val ? BIT(pos) : 0, BIT(pos)};

	tc3589x_block_write(tc3589x, reg, ARRAY_SIZE(data), data);
}

__attribute__((used)) static int tc3589x_gpio_direction_output(struct gpio_chip *chip,
					 unsigned int offset, int val)
{
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(chip);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	u8 reg = TC3589x_GPIODIR0 + offset / 8;
	unsigned int pos = offset % 8;

	tc3589x_gpio_set(chip, offset, val);

	return tc3589x_set_bits(tc3589x, reg, BIT(pos), BIT(pos));
}

__attribute__((used)) static int tc3589x_gpio_direction_input(struct gpio_chip *chip,
					unsigned int offset)
{
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(chip);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	u8 reg = TC3589x_GPIODIR0 + offset / 8;
	unsigned int pos = offset % 8;

	return tc3589x_set_bits(tc3589x, reg, BIT(pos), 0);
}

__attribute__((used)) static int tc3589x_gpio_get_direction(struct gpio_chip *chip,
				      unsigned int offset)
{
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(chip);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	u8 reg = TC3589x_GPIODIR0 + offset / 8;
	unsigned int pos = offset % 8;
	int ret;

	ret = tc3589x_reg_read(tc3589x, reg);
	if (ret < 0)
		return ret;

	return !(ret & BIT(pos));
}

__attribute__((used)) static int tc3589x_gpio_set_config(struct gpio_chip *chip, unsigned int offset,
				   unsigned long config)
{
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(chip);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	/*
	 * These registers are alterated at each second address
	 * ODM bit 0 = drive to GND or Hi-Z (open drain)
	 * ODM bit 1 = drive to VDD or Hi-Z (open source)
	 */
	u8 odmreg = TC3589x_GPIOODM0 + (offset / 8) * 2;
	u8 odereg = TC3589x_GPIOODE0 + (offset / 8) * 2;
	unsigned int pos = offset % 8;
	int ret;

	switch (pinconf_to_config_param(config)) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		/* Set open drain mode */
		ret = tc3589x_set_bits(tc3589x, odmreg, BIT(pos), 0);
		if (ret)
			return ret;
		/* Enable open drain/source mode */
		return tc3589x_set_bits(tc3589x, odereg, BIT(pos), BIT(pos));
	case PIN_CONFIG_DRIVE_OPEN_SOURCE:
		/* Set open source mode */
		ret = tc3589x_set_bits(tc3589x, odmreg, BIT(pos), BIT(pos));
		if (ret)
			return ret;
		/* Enable open drain/source mode */
		return tc3589x_set_bits(tc3589x, odereg, BIT(pos), BIT(pos));
	case PIN_CONFIG_DRIVE_PUSH_PULL:
		/* Disable open drain/source mode */
		return tc3589x_set_bits(tc3589x, odereg, BIT(pos), 0);
	default:
		break;
	}
	return -ENOTSUPP;
}

__attribute__((used)) static int tc3589x_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(gc);
	int offset = d->hwirq;
	int regoffset = offset / 8;
	int mask = BIT(offset % 8);

	if (type == IRQ_TYPE_EDGE_BOTH) {
		tc3589x_gpio->regs[REG_IBE][regoffset] |= mask;
		return 0;
	}

	tc3589x_gpio->regs[REG_IBE][regoffset] &= ~mask;

	if (type == IRQ_TYPE_LEVEL_LOW || type == IRQ_TYPE_LEVEL_HIGH)
		tc3589x_gpio->regs[REG_IS][regoffset] |= mask;
	else
		tc3589x_gpio->regs[REG_IS][regoffset] &= ~mask;

	if (type == IRQ_TYPE_EDGE_RISING || type == IRQ_TYPE_LEVEL_HIGH)
		tc3589x_gpio->regs[REG_IEV][regoffset] |= mask;
	else
		tc3589x_gpio->regs[REG_IEV][regoffset] &= ~mask;

	return 0;
}

__attribute__((used)) static void tc3589x_gpio_irq_lock(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(gc);

	mutex_lock(&tc3589x_gpio->irq_lock);
}

__attribute__((used)) static void tc3589x_gpio_irq_sync_unlock(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(gc);
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	static const u8 regmap[] = {
		[REG_IBE]	= TC3589x_GPIOIBE0,
		[REG_IEV]	= TC3589x_GPIOIEV0,
		[REG_IS]	= TC3589x_GPIOIS0,
		[REG_IE]	= TC3589x_GPIOIE0,
	};
	int i, j;

	for (i = 0; i < CACHE_NR_REGS; i++) {
		for (j = 0; j < CACHE_NR_BANKS; j++) {
			u8 old = tc3589x_gpio->oldregs[i][j];
			u8 new = tc3589x_gpio->regs[i][j];

			if (new == old)
				continue;

			tc3589x_gpio->oldregs[i][j] = new;
			tc3589x_reg_write(tc3589x, regmap[i] + j * 8, new);
		}
	}

	mutex_unlock(&tc3589x_gpio->irq_lock);
}

__attribute__((used)) static void tc3589x_gpio_irq_mask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(gc);
	int offset = d->hwirq;
	int regoffset = offset / 8;
	int mask = BIT(offset % 8);

	tc3589x_gpio->regs[REG_IE][regoffset] &= ~mask;
}

__attribute__((used)) static void tc3589x_gpio_irq_unmask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct tc3589x_gpio *tc3589x_gpio = gpiochip_get_data(gc);
	int offset = d->hwirq;
	int regoffset = offset / 8;
	int mask = BIT(offset % 8);

	tc3589x_gpio->regs[REG_IE][regoffset] |= mask;
}

__attribute__((used)) static irqreturn_t tc3589x_gpio_irq(int irq, void *dev)
{
	struct tc3589x_gpio *tc3589x_gpio = dev;
	struct tc3589x *tc3589x = tc3589x_gpio->tc3589x;
	u8 status[CACHE_NR_BANKS];
	int ret;
	int i;

	ret = tc3589x_block_read(tc3589x, TC3589x_GPIOMIS0,
				 ARRAY_SIZE(status), status);
	if (ret < 0)
		return IRQ_NONE;

	for (i = 0; i < ARRAY_SIZE(status); i++) {
		unsigned int stat = status[i];
		if (!stat)
			continue;

		while (stat) {
			int bit = __ffs(stat);
			int line = i * 8 + bit;
			int irq = irq_find_mapping(tc3589x_gpio->chip.irq.domain,
						   line);

			handle_nested_irq(irq);
			stat &= ~(1 << bit);
		}

		tc3589x_reg_write(tc3589x, TC3589x_GPIOIC0 + i, status[i]);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int tc3589x_gpio_probe(struct platform_device *pdev)
{
	struct tc3589x *tc3589x = dev_get_drvdata(pdev->dev.parent);
	struct device_node *np = pdev->dev.of_node;
	struct tc3589x_gpio *tc3589x_gpio;
	int ret;
	int irq;

	if (!np) {
		dev_err(&pdev->dev, "No Device Tree node found\n");
		return -EINVAL;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	tc3589x_gpio = devm_kzalloc(&pdev->dev, sizeof(struct tc3589x_gpio),
				    GFP_KERNEL);
	if (!tc3589x_gpio)
		return -ENOMEM;

	mutex_init(&tc3589x_gpio->irq_lock);

	tc3589x_gpio->dev = &pdev->dev;
	tc3589x_gpio->tc3589x = tc3589x;

	tc3589x_gpio->chip = template_chip;
	tc3589x_gpio->chip.ngpio = tc3589x->num_gpio;
	tc3589x_gpio->chip.parent = &pdev->dev;
	tc3589x_gpio->chip.base = -1;
	tc3589x_gpio->chip.of_node = np;

	/* Bring the GPIO module out of reset */
	ret = tc3589x_set_bits(tc3589x, TC3589x_RSTCTRL,
			       TC3589x_RSTCTRL_GPIRST, 0);
	if (ret < 0)
		return ret;

	ret = devm_request_threaded_irq(&pdev->dev,
					irq, NULL, tc3589x_gpio_irq,
					IRQF_ONESHOT, "tc3589x-gpio",
					tc3589x_gpio);
	if (ret) {
		dev_err(&pdev->dev, "unable to get irq: %d\n", ret);
		return ret;
	}

	ret = devm_gpiochip_add_data(&pdev->dev, &tc3589x_gpio->chip,
				     tc3589x_gpio);
	if (ret) {
		dev_err(&pdev->dev, "unable to add gpiochip: %d\n", ret);
		return ret;
	}

	ret =  gpiochip_irqchip_add_nested(&tc3589x_gpio->chip,
					   &tc3589x_gpio_irq_chip,
					   0,
					   handle_simple_irq,
					   IRQ_TYPE_NONE);
	if (ret) {
		dev_err(&pdev->dev,
			"could not connect irqchip to gpiochip\n");
		return ret;
	}

	gpiochip_set_nested_irqchip(&tc3589x_gpio->chip,
				    &tc3589x_gpio_irq_chip,
				    irq);

	platform_set_drvdata(pdev, tc3589x_gpio);

	return 0;
}

