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
typedef  unsigned int u32 ;
struct irq_chip {void (* irq_mask ) (struct irq_data*) ;void (* irq_unmask ) (struct irq_data*) ;int (* irq_set_type ) (struct irq_data*,unsigned int) ;int /*<<< orphan*/  irq_set_affinity; int /*<<< orphan*/  irq_eoi; void* name; } ;
struct gpio_chip {int ngpio; int (* get_direction ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;void (* set_multiple ) (struct gpio_chip*,unsigned long*,unsigned long*) ;int (* to_irq ) (struct gpio_chip*,unsigned int) ;int base; int /*<<< orphan*/  free; int /*<<< orphan*/  request; struct device* parent; void* label; } ;
struct uniphier_gpio_priv {int /*<<< orphan*/  domain; struct irq_chip irq_chip; struct gpio_chip chip; int /*<<< orphan*/  lock; scalar_t__ regs; } ;
struct resource {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct irq_fwspec {int param_count; unsigned int* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {struct uniphier_gpio_priv* host_data; TYPE_1__* parent; } ;
struct irq_data {unsigned int hwirq; struct uniphier_gpio_priv* chip_data; } ;
struct device_node {int dummy; } ;
typedef  unsigned int irq_hw_number_t ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {int /*<<< orphan*/  fwnode; } ;

/* Variables and functions */
 unsigned int BIT (unsigned int) ; 
 int BITS_PER_LONG ; 
 size_t BIT_WORD (int) ; 
 unsigned int DIV_ROUND_UP (unsigned int,unsigned int) ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 unsigned int IRQ_TYPE_EDGE_BOTH ; 
 unsigned int IRQ_TYPE_EDGE_FALLING ; 
 unsigned int IRQ_TYPE_LEVEL_HIGH ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long UNIPHIER_GPIO_BANK_MASK ; 
 unsigned int UNIPHIER_GPIO_IRQ_EN ; 
 scalar_t__ UNIPHIER_GPIO_IRQ_FLT_CYC ; 
 unsigned int UNIPHIER_GPIO_IRQ_FLT_EN ; 
 int /*<<< orphan*/  UNIPHIER_GPIO_IRQ_MAX_NUM ; 
 unsigned int UNIPHIER_GPIO_IRQ_MODE ; 
 unsigned int UNIPHIER_GPIO_IRQ_OFFSET ; 
 unsigned int UNIPHIER_GPIO_LINES_PER_BANK ; 
 unsigned int UNIPHIER_GPIO_PORT_DATA ; 
 unsigned int UNIPHIER_GPIO_PORT_DIR ; 
 scalar_t__ WARN_ON (int) ; 
 unsigned int be32_to_cpu (int /*<<< orphan*/ ) ; 
 void* dev_name (struct device*) ; 
 int devm_gpiochip_add_data (struct device*,struct gpio_chip*,struct uniphier_gpio_priv*) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct uniphier_gpio_priv* devm_kzalloc (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiochip_generic_free ; 
 int /*<<< orphan*/  gpiochip_generic_request ; 
 struct uniphier_gpio_priv* gpiochip_get_data (struct gpio_chip*) ; 
 int gpiochip_lock_as_irq (struct gpio_chip*,unsigned int) ; 
 int /*<<< orphan*/  gpiochip_unlock_as_irq (struct gpio_chip*,unsigned int) ; 
 int /*<<< orphan*/  irq_chip_eoi_parent ; 
 void irq_chip_mask_parent (struct irq_data*) ; 
 int /*<<< orphan*/  irq_chip_set_affinity_parent ; 
 int irq_chip_set_type_parent (struct irq_data*,unsigned int) ; 
 void irq_chip_unmask_parent (struct irq_data*) ; 
 int irq_create_fwspec_mapping (struct irq_fwspec*) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,int,struct irq_fwspec*) ; 
 int /*<<< orphan*/  irq_domain_create_hierarchy (struct irq_domain*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct uniphier_gpio_priv*) ; 
 int /*<<< orphan*/  irq_domain_remove (int /*<<< orphan*/ ) ; 
 int irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,unsigned int,struct irq_chip*,struct uniphier_gpio_priv*) ; 
 struct irq_domain* irq_find_host (struct device_node*) ; 
 int /*<<< orphan*/ * of_get_property (struct device_node*,char*,int*) ; 
 struct device_node* of_irq_find_parent (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_node_to_fwnode (struct device_node*) ; 
 int of_property_read_u32 (struct device_node*,char*,unsigned int*) ; 
 struct uniphier_gpio_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct uniphier_gpio_priv*) ; 
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  saved_vals ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  struct_size (struct uniphier_gpio_priv*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  uniphier_gpio_irq_domain_ops ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static unsigned int uniphier_gpio_bank_to_reg(unsigned int bank)
{
	unsigned int reg;

	reg = (bank + 1) * 8;

	/*
	 * Unfortunately, the GPIO port registers are not contiguous because
	 * offset 0x90-0x9f is used for IRQ.  Add 0x10 when crossing the region.
	 */
	if (reg >= UNIPHIER_GPIO_IRQ_EN)
		reg += 0x10;

	return reg;
}

__attribute__((used)) static void uniphier_gpio_get_bank_and_mask(unsigned int offset,
					    unsigned int *bank, u32 *mask)
{
	*bank = offset / UNIPHIER_GPIO_LINES_PER_BANK;
	*mask = BIT(offset % UNIPHIER_GPIO_LINES_PER_BANK);
}

__attribute__((used)) static void uniphier_gpio_reg_update(struct uniphier_gpio_priv *priv,
				     unsigned int reg, u32 mask, u32 val)
{
	unsigned long flags;
	u32 tmp;

	spin_lock_irqsave(&priv->lock, flags);
	tmp = readl(priv->regs + reg);
	tmp &= ~mask;
	tmp |= mask & val;
	writel(tmp, priv->regs + reg);
	spin_unlock_irqrestore(&priv->lock, flags);
}

__attribute__((used)) static void uniphier_gpio_bank_write(struct gpio_chip *chip, unsigned int bank,
				     unsigned int reg, u32 mask, u32 val)
{
	struct uniphier_gpio_priv *priv = gpiochip_get_data(chip);

	if (!mask)
		return;

	uniphier_gpio_reg_update(priv, uniphier_gpio_bank_to_reg(bank) + reg,
				 mask, val);
}

__attribute__((used)) static void uniphier_gpio_offset_write(struct gpio_chip *chip,
				       unsigned int offset, unsigned int reg,
				       int val)
{
	unsigned int bank;
	u32 mask;

	uniphier_gpio_get_bank_and_mask(offset, &bank, &mask);

	uniphier_gpio_bank_write(chip, bank, reg, mask, val ? mask : 0);
}

__attribute__((used)) static int uniphier_gpio_offset_read(struct gpio_chip *chip,
				     unsigned int offset, unsigned int reg)
{
	struct uniphier_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int bank, reg_offset;
	u32 mask;

	uniphier_gpio_get_bank_and_mask(offset, &bank, &mask);
	reg_offset = uniphier_gpio_bank_to_reg(bank) + reg;

	return !!(readl(priv->regs + reg_offset) & mask);
}

__attribute__((used)) static int uniphier_gpio_get_direction(struct gpio_chip *chip,
				       unsigned int offset)
{
	return uniphier_gpio_offset_read(chip, offset, UNIPHIER_GPIO_PORT_DIR);
}

__attribute__((used)) static int uniphier_gpio_direction_input(struct gpio_chip *chip,
					 unsigned int offset)
{
	uniphier_gpio_offset_write(chip, offset, UNIPHIER_GPIO_PORT_DIR, 1);

	return 0;
}

__attribute__((used)) static int uniphier_gpio_direction_output(struct gpio_chip *chip,
					  unsigned int offset, int val)
{
	uniphier_gpio_offset_write(chip, offset, UNIPHIER_GPIO_PORT_DATA, val);
	uniphier_gpio_offset_write(chip, offset, UNIPHIER_GPIO_PORT_DIR, 0);

	return 0;
}

__attribute__((used)) static int uniphier_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	return uniphier_gpio_offset_read(chip, offset, UNIPHIER_GPIO_PORT_DATA);
}

__attribute__((used)) static void uniphier_gpio_set(struct gpio_chip *chip,
			      unsigned int offset, int val)
{
	uniphier_gpio_offset_write(chip, offset, UNIPHIER_GPIO_PORT_DATA, val);
}

__attribute__((used)) static void uniphier_gpio_set_multiple(struct gpio_chip *chip,
				       unsigned long *mask, unsigned long *bits)
{
	unsigned int bank, shift, bank_mask, bank_bits;
	int i;

	for (i = 0; i < chip->ngpio; i += UNIPHIER_GPIO_LINES_PER_BANK) {
		bank = i / UNIPHIER_GPIO_LINES_PER_BANK;
		shift = i % BITS_PER_LONG;
		bank_mask = (mask[BIT_WORD(i)] >> shift) &
						UNIPHIER_GPIO_BANK_MASK;
		bank_bits = bits[BIT_WORD(i)] >> shift;

		uniphier_gpio_bank_write(chip, bank, UNIPHIER_GPIO_PORT_DATA,
					 bank_mask, bank_bits);
	}
}

__attribute__((used)) static int uniphier_gpio_to_irq(struct gpio_chip *chip, unsigned int offset)
{
	struct irq_fwspec fwspec;

	if (offset < UNIPHIER_GPIO_IRQ_OFFSET)
		return -ENXIO;

	fwspec.fwnode = of_node_to_fwnode(chip->parent->of_node);
	fwspec.param_count = 2;
	fwspec.param[0] = offset - UNIPHIER_GPIO_IRQ_OFFSET;
	/*
	 * IRQ_TYPE_NONE is rejected by the parent irq domain. Set LEVEL_HIGH
	 * temporarily. Anyway, ->irq_set_type() will override it later.
	 */
	fwspec.param[1] = IRQ_TYPE_LEVEL_HIGH;

	return irq_create_fwspec_mapping(&fwspec);
}

__attribute__((used)) static void uniphier_gpio_irq_mask(struct irq_data *data)
{
	struct uniphier_gpio_priv *priv = data->chip_data;
	u32 mask = BIT(data->hwirq);

	uniphier_gpio_reg_update(priv, UNIPHIER_GPIO_IRQ_EN, mask, 0);

	return irq_chip_mask_parent(data);
}

__attribute__((used)) static void uniphier_gpio_irq_unmask(struct irq_data *data)
{
	struct uniphier_gpio_priv *priv = data->chip_data;
	u32 mask = BIT(data->hwirq);

	uniphier_gpio_reg_update(priv, UNIPHIER_GPIO_IRQ_EN, mask, mask);

	return irq_chip_unmask_parent(data);
}

__attribute__((used)) static int uniphier_gpio_irq_set_type(struct irq_data *data, unsigned int type)
{
	struct uniphier_gpio_priv *priv = data->chip_data;
	u32 mask = BIT(data->hwirq);
	u32 val = 0;

	if (type == IRQ_TYPE_EDGE_BOTH) {
		val = mask;
		type = IRQ_TYPE_EDGE_FALLING;
	}

	uniphier_gpio_reg_update(priv, UNIPHIER_GPIO_IRQ_MODE, mask, val);
	/* To enable both edge detection, the noise filter must be enabled. */
	uniphier_gpio_reg_update(priv, UNIPHIER_GPIO_IRQ_FLT_EN, mask, val);

	return irq_chip_set_type_parent(data, type);
}

__attribute__((used)) static int uniphier_gpio_irq_get_parent_hwirq(struct uniphier_gpio_priv *priv,
					      unsigned int hwirq)
{
	struct device_node *np = priv->chip.parent->of_node;
	const __be32 *range;
	u32 base, parent_base, size;
	int len;

	range = of_get_property(np, "socionext,interrupt-ranges", &len);
	if (!range)
		return -EINVAL;

	len /= sizeof(*range);

	for (; len >= 3; len -= 3) {
		base = be32_to_cpu(*range++);
		parent_base = be32_to_cpu(*range++);
		size = be32_to_cpu(*range++);

		if (base <= hwirq && hwirq < base + size)
			return hwirq - base + parent_base;
	}

	return -ENOENT;
}

__attribute__((used)) static int uniphier_gpio_irq_domain_translate(struct irq_domain *domain,
					      struct irq_fwspec *fwspec,
					      unsigned long *out_hwirq,
					      unsigned int *out_type)
{
	if (WARN_ON(fwspec->param_count < 2))
		return -EINVAL;

	*out_hwirq = fwspec->param[0];
	*out_type = fwspec->param[1] & IRQ_TYPE_SENSE_MASK;

	return 0;
}

__attribute__((used)) static int uniphier_gpio_irq_domain_alloc(struct irq_domain *domain,
					  unsigned int virq,
					  unsigned int nr_irqs, void *arg)
{
	struct uniphier_gpio_priv *priv = domain->host_data;
	struct irq_fwspec parent_fwspec;
	irq_hw_number_t hwirq;
	unsigned int type;
	int ret;

	if (WARN_ON(nr_irqs != 1))
		return -EINVAL;

	ret = uniphier_gpio_irq_domain_translate(domain, arg, &hwirq, &type);
	if (ret)
		return ret;

	ret = uniphier_gpio_irq_get_parent_hwirq(priv, hwirq);
	if (ret < 0)
		return ret;

	/* parent is UniPhier AIDET */
	parent_fwspec.fwnode = domain->parent->fwnode;
	parent_fwspec.param_count = 2;
	parent_fwspec.param[0] = ret;
	parent_fwspec.param[1] = (type == IRQ_TYPE_EDGE_BOTH) ?
						IRQ_TYPE_EDGE_FALLING : type;

	ret = irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
					    &priv->irq_chip, priv);
	if (ret)
		return ret;

	return irq_domain_alloc_irqs_parent(domain, virq, 1, &parent_fwspec);
}

__attribute__((used)) static int uniphier_gpio_irq_domain_activate(struct irq_domain *domain,
					     struct irq_data *data, bool early)
{
	struct uniphier_gpio_priv *priv = domain->host_data;
	struct gpio_chip *chip = &priv->chip;

	return gpiochip_lock_as_irq(chip, data->hwirq + UNIPHIER_GPIO_IRQ_OFFSET);
}

__attribute__((used)) static void uniphier_gpio_irq_domain_deactivate(struct irq_domain *domain,
						struct irq_data *data)
{
	struct uniphier_gpio_priv *priv = domain->host_data;
	struct gpio_chip *chip = &priv->chip;

	gpiochip_unlock_as_irq(chip, data->hwirq + UNIPHIER_GPIO_IRQ_OFFSET);
}

__attribute__((used)) static void uniphier_gpio_hw_init(struct uniphier_gpio_priv *priv)
{
	/*
	 * Due to the hardware design, the noise filter must be enabled to
	 * detect both edge interrupts.  This filter is intended to remove the
	 * noise from the irq lines.  It does not work for GPIO input, so GPIO
	 * debounce is not supported.  Unfortunately, the filter period is
	 * shared among all irq lines.  Just choose a sensible period here.
	 */
	writel(0xff, priv->regs + UNIPHIER_GPIO_IRQ_FLT_CYC);
}

__attribute__((used)) static unsigned int uniphier_gpio_get_nbanks(unsigned int ngpio)
{
	return DIV_ROUND_UP(ngpio, UNIPHIER_GPIO_LINES_PER_BANK);
}

__attribute__((used)) static int uniphier_gpio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *parent_np;
	struct irq_domain *parent_domain;
	struct uniphier_gpio_priv *priv;
	struct gpio_chip *chip;
	struct irq_chip *irq_chip;
	struct resource *regs;
	unsigned int nregs;
	u32 ngpios;
	int ret;

	parent_np = of_irq_find_parent(dev->of_node);
	if (!parent_np)
		return -ENXIO;

	parent_domain = irq_find_host(parent_np);
	of_node_put(parent_np);
	if (!parent_domain)
		return -EPROBE_DEFER;

	ret = of_property_read_u32(dev->of_node, "ngpios", &ngpios);
	if (ret)
		return ret;

	nregs = uniphier_gpio_get_nbanks(ngpios) * 2 + 3;
	priv = devm_kzalloc(dev, struct_size(priv, saved_vals, nregs),
			    GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->regs = devm_ioremap_resource(dev, regs);
	if (IS_ERR(priv->regs))
		return PTR_ERR(priv->regs);

	spin_lock_init(&priv->lock);

	chip = &priv->chip;
	chip->label = dev_name(dev);
	chip->parent = dev;
	chip->request = gpiochip_generic_request;
	chip->free = gpiochip_generic_free;
	chip->get_direction = uniphier_gpio_get_direction;
	chip->direction_input = uniphier_gpio_direction_input;
	chip->direction_output = uniphier_gpio_direction_output;
	chip->get = uniphier_gpio_get;
	chip->set = uniphier_gpio_set;
	chip->set_multiple = uniphier_gpio_set_multiple;
	chip->to_irq = uniphier_gpio_to_irq;
	chip->base = -1;
	chip->ngpio = ngpios;

	irq_chip = &priv->irq_chip;
	irq_chip->name = dev_name(dev);
	irq_chip->irq_mask = uniphier_gpio_irq_mask;
	irq_chip->irq_unmask = uniphier_gpio_irq_unmask;
	irq_chip->irq_eoi = irq_chip_eoi_parent;
	irq_chip->irq_set_affinity = irq_chip_set_affinity_parent;
	irq_chip->irq_set_type = uniphier_gpio_irq_set_type;

	uniphier_gpio_hw_init(priv);

	ret = devm_gpiochip_add_data(dev, chip, priv);
	if (ret)
		return ret;

	priv->domain = irq_domain_create_hierarchy(
					parent_domain, 0,
					UNIPHIER_GPIO_IRQ_MAX_NUM,
					of_node_to_fwnode(dev->of_node),
					&uniphier_gpio_irq_domain_ops, priv);
	if (!priv->domain)
		return -ENOMEM;

	platform_set_drvdata(pdev, priv);

	return 0;
}

__attribute__((used)) static int uniphier_gpio_remove(struct platform_device *pdev)
{
	struct uniphier_gpio_priv *priv = platform_get_drvdata(pdev);

	irq_domain_remove(priv->domain);

	return 0;
}

