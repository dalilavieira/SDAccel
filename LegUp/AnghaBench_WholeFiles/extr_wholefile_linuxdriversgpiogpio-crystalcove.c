#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct seq_file {int dummy; } ;
struct TYPE_10__ {struct device* parent; } ;
struct platform_device {TYPE_4__ dev; } ;
struct irq_data {int hwirq; } ;
struct intel_soc_pmic {int /*<<< orphan*/  regmap; } ;
struct gpio_chip {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  domain; } ;
struct TYPE_9__ {int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int base; int can_sleep; void (* dbg_show ) (struct seq_file*,struct gpio_chip*) ;struct device* parent; int /*<<< orphan*/  ngpio; int /*<<< orphan*/  label; TYPE_1__ irq; } ;
struct crystalcove_gpio {int set_irq_mask; int intcnt_value; int update; TYPE_2__ chip; int /*<<< orphan*/  regmap; int /*<<< orphan*/  buslock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum ctrl_register { ____Placeholder_ctrl_register } ctrl_register ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int CRYSTALCOVE_GPIO_NUM ; 
 int /*<<< orphan*/  CRYSTALCOVE_VGPIO_NUM ; 
 int CTLI_INTCNT_BE ; 
 int CTLI_INTCNT_DIS ; 
 unsigned int CTLI_INTCNT_NE ; 
 unsigned int CTLI_INTCNT_PE ; 
 unsigned int CTLO_DIR_OUT ; 
 unsigned int CTLO_INPUT_SET ; 
 int CTLO_OUTPUT_SET ; 
 int CTRL_IN ; 
 int CTRL_OUT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIO0IRQ ; 
 int GPIO0P0CTLI ; 
 int GPIO0P0CTLO ; 
 int GPIO1IRQ ; 
 int GPIO1P0CTLI ; 
 int GPIO1P0CTLO ; 
 int GPIOPANELCTL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
#define  IRQ_TYPE_EDGE_BOTH 131 
#define  IRQ_TYPE_EDGE_FALLING 130 
#define  IRQ_TYPE_EDGE_RISING 129 
#define  IRQ_TYPE_NONE 128 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int MGPIO0IRQS0 ; 
 int MGPIO0IRQSX ; 
 int MGPIO1IRQS0 ; 
 int MGPIO1IRQSX ; 
 int UPDATE_IRQ_MASK ; 
 int UPDATE_IRQ_TYPE ; 
 int /*<<< orphan*/  crystalcove_irqchip ; 
 struct intel_soc_pmic* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_4__*,char*,int) ; 
 int devm_gpiochip_add_data (TYPE_4__*,TYPE_2__*,struct crystalcove_gpio*) ; 
 struct crystalcove_gpio* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,struct crystalcove_gpio*) ; 
 struct crystalcove_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_irqchip_add_nested (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  gpiochip_set_nested_irqchip (TYPE_2__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  handle_nested_irq (unsigned int) ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 struct gpio_chip* irq_data_get_irq_chip_data (struct irq_data*) ; 
 unsigned int irq_find_mapping (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct crystalcove_gpio* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct crystalcove_gpio*) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int,unsigned int) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct crystalcove_gpio*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int,char*,char*,char*,char*,unsigned int,char*,char*,char*) ; 

__attribute__((used)) static inline int to_reg(int gpio, enum ctrl_register reg_type)
{
	int reg;

	if (gpio >= CRYSTALCOVE_GPIO_NUM) {
		/*
		 * Virtual GPIO called from ACPI, for now we only support
		 * the panel ctl.
		 */
		switch (gpio) {
		case 0x5e:
			return GPIOPANELCTL;
		default:
			return -EOPNOTSUPP;
		}
	}

	if (reg_type == CTRL_IN) {
		if (gpio < 8)
			reg = GPIO0P0CTLI;
		else
			reg = GPIO1P0CTLI;
	} else {
		if (gpio < 8)
			reg = GPIO0P0CTLO;
		else
			reg = GPIO1P0CTLO;
	}

	return reg + gpio % 8;
}

__attribute__((used)) static void crystalcove_update_irq_mask(struct crystalcove_gpio *cg,
					int gpio)
{
	u8 mirqs0 = gpio < 8 ? MGPIO0IRQS0 : MGPIO1IRQS0;
	int mask = BIT(gpio % 8);

	if (cg->set_irq_mask)
		regmap_update_bits(cg->regmap, mirqs0, mask, mask);
	else
		regmap_update_bits(cg->regmap, mirqs0, mask, 0);
}

__attribute__((used)) static void crystalcove_update_irq_ctrl(struct crystalcove_gpio *cg, int gpio)
{
	int reg = to_reg(gpio, CTRL_IN);

	regmap_update_bits(cg->regmap, reg, CTLI_INTCNT_BE, cg->intcnt_value);
}

__attribute__((used)) static int crystalcove_gpio_dir_in(struct gpio_chip *chip, unsigned gpio)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	int reg = to_reg(gpio, CTRL_OUT);

	if (reg < 0)
		return 0;

	return regmap_write(cg->regmap, reg, CTLO_INPUT_SET);
}

__attribute__((used)) static int crystalcove_gpio_dir_out(struct gpio_chip *chip, unsigned gpio,
				    int value)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	int reg = to_reg(gpio, CTRL_OUT);

	if (reg < 0)
		return 0;

	return regmap_write(cg->regmap, reg, CTLO_OUTPUT_SET | value);
}

__attribute__((used)) static int crystalcove_gpio_get(struct gpio_chip *chip, unsigned gpio)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	unsigned int val;
	int ret, reg = to_reg(gpio, CTRL_IN);

	if (reg < 0)
		return 0;

	ret = regmap_read(cg->regmap, reg, &val);
	if (ret)
		return ret;

	return val & 0x1;
}

__attribute__((used)) static void crystalcove_gpio_set(struct gpio_chip *chip,
				 unsigned gpio, int value)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	int reg = to_reg(gpio, CTRL_OUT);

	if (reg < 0)
		return;

	if (value)
		regmap_update_bits(cg->regmap, reg, 1, 1);
	else
		regmap_update_bits(cg->regmap, reg, 1, 0);
}

__attribute__((used)) static int crystalcove_irq_type(struct irq_data *data, unsigned type)
{
	struct crystalcove_gpio *cg =
		gpiochip_get_data(irq_data_get_irq_chip_data(data));

	if (data->hwirq >= CRYSTALCOVE_GPIO_NUM)
		return 0;

	switch (type) {
	case IRQ_TYPE_NONE:
		cg->intcnt_value = CTLI_INTCNT_DIS;
		break;
	case IRQ_TYPE_EDGE_BOTH:
		cg->intcnt_value = CTLI_INTCNT_BE;
		break;
	case IRQ_TYPE_EDGE_RISING:
		cg->intcnt_value = CTLI_INTCNT_PE;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		cg->intcnt_value = CTLI_INTCNT_NE;
		break;
	default:
		return -EINVAL;
	}

	cg->update |= UPDATE_IRQ_TYPE;

	return 0;
}

__attribute__((used)) static void crystalcove_bus_lock(struct irq_data *data)
{
	struct crystalcove_gpio *cg =
		gpiochip_get_data(irq_data_get_irq_chip_data(data));

	mutex_lock(&cg->buslock);
}

__attribute__((used)) static void crystalcove_bus_sync_unlock(struct irq_data *data)
{
	struct crystalcove_gpio *cg =
		gpiochip_get_data(irq_data_get_irq_chip_data(data));
	int gpio = data->hwirq;

	if (cg->update & UPDATE_IRQ_TYPE)
		crystalcove_update_irq_ctrl(cg, gpio);
	if (cg->update & UPDATE_IRQ_MASK)
		crystalcove_update_irq_mask(cg, gpio);
	cg->update = 0;

	mutex_unlock(&cg->buslock);
}

__attribute__((used)) static void crystalcove_irq_unmask(struct irq_data *data)
{
	struct crystalcove_gpio *cg =
		gpiochip_get_data(irq_data_get_irq_chip_data(data));

	if (data->hwirq < CRYSTALCOVE_GPIO_NUM) {
		cg->set_irq_mask = false;
		cg->update |= UPDATE_IRQ_MASK;
	}
}

__attribute__((used)) static void crystalcove_irq_mask(struct irq_data *data)
{
	struct crystalcove_gpio *cg =
		gpiochip_get_data(irq_data_get_irq_chip_data(data));

	if (data->hwirq < CRYSTALCOVE_GPIO_NUM) {
		cg->set_irq_mask = true;
		cg->update |= UPDATE_IRQ_MASK;
	}
}

__attribute__((used)) static irqreturn_t crystalcove_gpio_irq_handler(int irq, void *data)
{
	struct crystalcove_gpio *cg = data;
	unsigned int p0, p1;
	int pending;
	int gpio;
	unsigned int virq;

	if (regmap_read(cg->regmap, GPIO0IRQ, &p0) ||
	    regmap_read(cg->regmap, GPIO1IRQ, &p1))
		return IRQ_NONE;

	regmap_write(cg->regmap, GPIO0IRQ, p0);
	regmap_write(cg->regmap, GPIO1IRQ, p1);

	pending = p0 | p1 << 8;

	for (gpio = 0; gpio < CRYSTALCOVE_GPIO_NUM; gpio++) {
		if (pending & BIT(gpio)) {
			virq = irq_find_mapping(cg->chip.irq.domain, gpio);
			handle_nested_irq(virq);
		}
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static void crystalcove_gpio_dbg_show(struct seq_file *s,
				      struct gpio_chip *chip)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	int gpio, offset;
	unsigned int ctlo, ctli, mirqs0, mirqsx, irq;

	for (gpio = 0; gpio < CRYSTALCOVE_GPIO_NUM; gpio++) {
		regmap_read(cg->regmap, to_reg(gpio, CTRL_OUT), &ctlo);
		regmap_read(cg->regmap, to_reg(gpio, CTRL_IN), &ctli);
		regmap_read(cg->regmap, gpio < 8 ? MGPIO0IRQS0 : MGPIO1IRQS0,
			    &mirqs0);
		regmap_read(cg->regmap, gpio < 8 ? MGPIO0IRQSX : MGPIO1IRQSX,
			    &mirqsx);
		regmap_read(cg->regmap, gpio < 8 ? GPIO0IRQ : GPIO1IRQ,
			    &irq);

		offset = gpio % 8;
		seq_printf(s, " gpio-%-2d %s %s %s %s ctlo=%2x,%s %s %s\n",
			   gpio, ctlo & CTLO_DIR_OUT ? "out" : "in ",
			   ctli & 0x1 ? "hi" : "lo",
			   ctli & CTLI_INTCNT_NE ? "fall" : "    ",
			   ctli & CTLI_INTCNT_PE ? "rise" : "    ",
			   ctlo,
			   mirqs0 & BIT(offset) ? "s0 mask  " : "s0 unmask",
			   mirqsx & BIT(offset) ? "sx mask  " : "sx unmask",
			   irq & BIT(offset) ? "pending" : "       ");
	}
}

__attribute__((used)) static int crystalcove_gpio_probe(struct platform_device *pdev)
{
	int irq = platform_get_irq(pdev, 0);
	struct crystalcove_gpio *cg;
	int retval;
	struct device *dev = pdev->dev.parent;
	struct intel_soc_pmic *pmic = dev_get_drvdata(dev);

	if (irq < 0)
		return irq;

	cg = devm_kzalloc(&pdev->dev, sizeof(*cg), GFP_KERNEL);
	if (!cg)
		return -ENOMEM;

	platform_set_drvdata(pdev, cg);

	mutex_init(&cg->buslock);
	cg->chip.label = KBUILD_MODNAME;
	cg->chip.direction_input = crystalcove_gpio_dir_in;
	cg->chip.direction_output = crystalcove_gpio_dir_out;
	cg->chip.get = crystalcove_gpio_get;
	cg->chip.set = crystalcove_gpio_set;
	cg->chip.base = -1;
	cg->chip.ngpio = CRYSTALCOVE_VGPIO_NUM;
	cg->chip.can_sleep = true;
	cg->chip.parent = dev;
	cg->chip.dbg_show = crystalcove_gpio_dbg_show;
	cg->regmap = pmic->regmap;

	retval = devm_gpiochip_add_data(&pdev->dev, &cg->chip, cg);
	if (retval) {
		dev_warn(&pdev->dev, "add gpio chip error: %d\n", retval);
		return retval;
	}

	gpiochip_irqchip_add_nested(&cg->chip, &crystalcove_irqchip, 0,
				    handle_simple_irq, IRQ_TYPE_NONE);

	retval = request_threaded_irq(irq, NULL, crystalcove_gpio_irq_handler,
				      IRQF_ONESHOT, KBUILD_MODNAME, cg);

	if (retval) {
		dev_warn(&pdev->dev, "request irq failed: %d\n", retval);
		return retval;
	}

	gpiochip_set_nested_irqchip(&cg->chip, &crystalcove_irqchip, irq);

	return 0;
}

__attribute__((used)) static int crystalcove_gpio_remove(struct platform_device *pdev)
{
	struct crystalcove_gpio *cg = platform_get_drvdata(pdev);
	int irq = platform_get_irq(pdev, 0);

	if (irq >= 0)
		free_irq(irq, cg);
	return 0;
}

