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
typedef  int u32 ;
struct x86_cpu_id {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct irq_data {int dummy; } ;
struct TYPE_2__ {int need_valid_mask; int /*<<< orphan*/  valid_mask; int /*<<< orphan*/  domain; } ;
struct gpio_chip {int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int base; TYPE_1__ irq; scalar_t__ ngpio; int /*<<< orphan*/  owner; struct device* parent; int /*<<< orphan*/  label; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_NAME ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPE0A_EN_PORT ; 
 int GPE0A_PME_B0_EN_BIT ; 
 int GPE0A_PME_B0_STS_BIT ; 
 scalar_t__ GPE0A_PME_B0_VIRT_GPIO_PIN ; 
 int /*<<< orphan*/  GPE0A_STS_PORT ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_TYPE_NONE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  bitmap_clear (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 int devm_gpiochip_add_data (struct device*,struct gpio_chip*,int /*<<< orphan*/ *) ; 
 struct gpio_chip* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct gpio_chip*) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 int gpiochip_irqchip_add (struct gpio_chip*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiochip_set_chained_irqchip (struct gpio_chip*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int inl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  int0002_cpu_ids ; 
 int /*<<< orphan*/  int0002_irqchip ; 
 int /*<<< orphan*/  irq_find_mapping (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  outl (int,int /*<<< orphan*/ ) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_system_wakeup () ; 
 struct x86_cpu_id* x86_match_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int int0002_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	return 0;
}

__attribute__((used)) static void int0002_gpio_set(struct gpio_chip *chip, unsigned int offset,
			     int value)
{
}

__attribute__((used)) static int int0002_gpio_direction_output(struct gpio_chip *chip,
					 unsigned int offset, int value)
{
	return 0;
}

__attribute__((used)) static void int0002_irq_ack(struct irq_data *data)
{
	outl(GPE0A_PME_B0_STS_BIT, GPE0A_STS_PORT);
}

__attribute__((used)) static void int0002_irq_unmask(struct irq_data *data)
{
	u32 gpe_en_reg;

	gpe_en_reg = inl(GPE0A_EN_PORT);
	gpe_en_reg |= GPE0A_PME_B0_EN_BIT;
	outl(gpe_en_reg, GPE0A_EN_PORT);
}

__attribute__((used)) static void int0002_irq_mask(struct irq_data *data)
{
	u32 gpe_en_reg;

	gpe_en_reg = inl(GPE0A_EN_PORT);
	gpe_en_reg &= ~GPE0A_PME_B0_EN_BIT;
	outl(gpe_en_reg, GPE0A_EN_PORT);
}

__attribute__((used)) static irqreturn_t int0002_irq(int irq, void *data)
{
	struct gpio_chip *chip = data;
	u32 gpe_sts_reg;

	gpe_sts_reg = inl(GPE0A_STS_PORT);
	if (!(gpe_sts_reg & GPE0A_PME_B0_STS_BIT))
		return IRQ_NONE;

	generic_handle_irq(irq_find_mapping(chip->irq.domain,
					    GPE0A_PME_B0_VIRT_GPIO_PIN));

	pm_system_wakeup();

	return IRQ_HANDLED;
}

__attribute__((used)) static int int0002_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	const struct x86_cpu_id *cpu_id;
	struct gpio_chip *chip;
	int irq, ret;

	/* Menlow has a different INT0002 device? <sigh> */
	cpu_id = x86_match_cpu(int0002_cpu_ids);
	if (!cpu_id)
		return -ENODEV;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(dev, "Error getting IRQ: %d\n", irq);
		return irq;
	}

	chip = devm_kzalloc(dev, sizeof(*chip), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	chip->label = DRV_NAME;
	chip->parent = dev;
	chip->owner = THIS_MODULE;
	chip->get = int0002_gpio_get;
	chip->set = int0002_gpio_set;
	chip->direction_input = int0002_gpio_get;
	chip->direction_output = int0002_gpio_direction_output;
	chip->base = -1;
	chip->ngpio = GPE0A_PME_B0_VIRT_GPIO_PIN + 1;
	chip->irq.need_valid_mask = true;

	ret = devm_gpiochip_add_data(&pdev->dev, chip, NULL);
	if (ret) {
		dev_err(dev, "Error adding gpio chip: %d\n", ret);
		return ret;
	}

	bitmap_clear(chip->irq.valid_mask, 0, GPE0A_PME_B0_VIRT_GPIO_PIN);

	/*
	 * We manually request the irq here instead of passing a flow-handler
	 * to gpiochip_set_chained_irqchip, because the irq is shared.
	 */
	ret = devm_request_irq(dev, irq, int0002_irq,
			       IRQF_SHARED, "INT0002", chip);
	if (ret) {
		dev_err(dev, "Error requesting IRQ %d: %d\n", irq, ret);
		return ret;
	}

	ret = gpiochip_irqchip_add(chip, &int0002_irqchip, 0, handle_edge_irq,
				   IRQ_TYPE_NONE);
	if (ret) {
		dev_err(dev, "Error adding irqchip: %d\n", ret);
		return ret;
	}

	gpiochip_set_chained_irqchip(chip, &int0002_irqchip, irq, NULL);

	return 0;
}

