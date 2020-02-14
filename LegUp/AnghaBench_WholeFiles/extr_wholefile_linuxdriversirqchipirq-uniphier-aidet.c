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
struct uniphier_aidet_priv {int /*<<< orphan*/  domain; int /*<<< orphan*/  lock; scalar_t__ reg_base; } ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct irq_fwspec {int param_count; unsigned long* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {TYPE_1__* parent; int /*<<< orphan*/  host_data; } ;
struct irq_data {unsigned long hwirq; struct uniphier_aidet_priv* chip_data; } ;
struct device_node {int dummy; } ;
typedef  unsigned long irq_hw_number_t ;
struct TYPE_2__ {int /*<<< orphan*/  fwnode; } ;

/* Variables and functions */
 int BIT (unsigned long) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
#define  IRQ_TYPE_EDGE_FALLING 131 
#define  IRQ_TYPE_EDGE_RISING 130 
#define  IRQ_TYPE_LEVEL_HIGH 129 
#define  IRQ_TYPE_LEVEL_LOW 128 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long UNIPHIER_AIDET_DETCONF ; 
 unsigned long UNIPHIER_AIDET_NR_IRQS ; 
 scalar_t__ WARN_ON (int) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct uniphier_aidet_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int irq_chip_set_type_parent (struct irq_data*,unsigned int) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,int,struct irq_fwspec*) ; 
 int /*<<< orphan*/  irq_domain_create_hierarchy (struct irq_domain*,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct uniphier_aidet_priv*) ; 
 int irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct irq_domain* irq_find_host (struct device_node*) ; 
 struct device_node* of_irq_find_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_node_to_fwnode (int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct uniphier_aidet_priv*) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  uniphier_aidet_domain_ops ; 
 int /*<<< orphan*/  uniphier_aidet_irq_chip ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void uniphier_aidet_reg_update(struct uniphier_aidet_priv *priv,
				      unsigned int reg, u32 mask, u32 val)
{
	unsigned long flags;
	u32 tmp;

	spin_lock_irqsave(&priv->lock, flags);
	tmp = readl_relaxed(priv->reg_base + reg);
	tmp &= ~mask;
	tmp |= mask & val;
	writel_relaxed(tmp, priv->reg_base + reg);
	spin_unlock_irqrestore(&priv->lock, flags);
}

__attribute__((used)) static void uniphier_aidet_detconf_update(struct uniphier_aidet_priv *priv,
					  unsigned long index, unsigned int val)
{
	unsigned int reg;
	u32 mask;

	reg = UNIPHIER_AIDET_DETCONF + index / 32 * 4;
	mask = BIT(index % 32);

	uniphier_aidet_reg_update(priv, reg, mask, val ? mask : 0);
}

__attribute__((used)) static int uniphier_aidet_irq_set_type(struct irq_data *data, unsigned int type)
{
	struct uniphier_aidet_priv *priv = data->chip_data;
	unsigned int val;

	/* enable inverter for active low triggers */
	switch (type) {
	case IRQ_TYPE_EDGE_RISING:
	case IRQ_TYPE_LEVEL_HIGH:
		val = 0;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		val = 1;
		type = IRQ_TYPE_EDGE_RISING;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		val = 1;
		type = IRQ_TYPE_LEVEL_HIGH;
		break;
	default:
		return -EINVAL;
	}

	uniphier_aidet_detconf_update(priv, data->hwirq, val);

	return irq_chip_set_type_parent(data, type);
}

__attribute__((used)) static int uniphier_aidet_domain_translate(struct irq_domain *domain,
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

__attribute__((used)) static int uniphier_aidet_domain_alloc(struct irq_domain *domain,
				       unsigned int virq, unsigned int nr_irqs,
				       void *arg)
{
	struct irq_fwspec parent_fwspec;
	irq_hw_number_t hwirq;
	unsigned int type;
	int ret;

	if (nr_irqs != 1)
		return -EINVAL;

	ret = uniphier_aidet_domain_translate(domain, arg, &hwirq, &type);
	if (ret)
		return ret;

	switch (type) {
	case IRQ_TYPE_EDGE_RISING:
	case IRQ_TYPE_LEVEL_HIGH:
		break;
	case IRQ_TYPE_EDGE_FALLING:
		type = IRQ_TYPE_EDGE_RISING;
		break;
	case IRQ_TYPE_LEVEL_LOW:
		type = IRQ_TYPE_LEVEL_HIGH;
		break;
	default:
		return -EINVAL;
	}

	if (hwirq >= UNIPHIER_AIDET_NR_IRQS)
		return -ENXIO;

	ret = irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
					    &uniphier_aidet_irq_chip,
					    domain->host_data);
	if (ret)
		return ret;

	/* parent is GIC */
	parent_fwspec.fwnode = domain->parent->fwnode;
	parent_fwspec.param_count = 3;
	parent_fwspec.param[0] = 0;		/* SPI */
	parent_fwspec.param[1] = hwirq;
	parent_fwspec.param[2] = type;

	return irq_domain_alloc_irqs_parent(domain, virq, 1, &parent_fwspec);
}

__attribute__((used)) static int uniphier_aidet_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *parent_np;
	struct irq_domain *parent_domain;
	struct uniphier_aidet_priv *priv;
	struct resource *res;

	parent_np = of_irq_find_parent(dev->of_node);
	if (!parent_np)
		return -ENXIO;

	parent_domain = irq_find_host(parent_np);
	of_node_put(parent_np);
	if (!parent_domain)
		return -EPROBE_DEFER;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->reg_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(priv->reg_base))
		return PTR_ERR(priv->reg_base);

	spin_lock_init(&priv->lock);

	priv->domain = irq_domain_create_hierarchy(
					parent_domain, 0,
					UNIPHIER_AIDET_NR_IRQS,
					of_node_to_fwnode(dev->of_node),
					&uniphier_aidet_domain_ops, priv);
	if (!priv->domain)
		return -ENOMEM;

	platform_set_drvdata(pdev, priv);

	return 0;
}

