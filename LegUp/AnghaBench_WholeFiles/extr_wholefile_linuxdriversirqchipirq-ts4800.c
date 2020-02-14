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
typedef  int u16 ;
struct irq_chip {void (* irq_mask ) (struct irq_data*) ;void (* irq_unmask ) (struct irq_data*) ;int /*<<< orphan*/  name; } ;
struct ts4800_irq_data {int /*<<< orphan*/  domain; struct irq_chip irq_chip; scalar_t__ base; } ;
struct resource {int dummy; } ;
struct TYPE_5__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct irq_domain {struct ts4800_irq_data* host_data; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int hwirq; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IRQ_MASK ; 
 scalar_t__ IRQ_STATUS ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned int __ffs (int) ; 
 int /*<<< orphan*/  chained_irq_enter (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  chained_irq_exit (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_1__*) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 struct ts4800_irq_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_handle_irq (int) ; 
 int /*<<< orphan*/  handle_bad_irq (struct irq_desc*) ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 struct ts4800_irq_data* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 struct ts4800_irq_data* irq_desc_get_handler_data (struct irq_desc*) ; 
 int /*<<< orphan*/  irq_domain_add_linear (struct device_node*,int,int /*<<< orphan*/ *,struct ts4800_irq_data*) ; 
 int /*<<< orphan*/  irq_domain_remove (int /*<<< orphan*/ ) ; 
 int irq_find_mapping (int /*<<< orphan*/ ,unsigned int) ; 
 int irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chained_handler_and_data (int,void (*) (struct irq_desc*),struct ts4800_irq_data*) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,struct irq_chip*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct ts4800_irq_data*) ; 
 int /*<<< orphan*/  irq_set_noprobe (unsigned int) ; 
 struct ts4800_irq_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ts4800_irq_data*) ; 
 int readw (scalar_t__) ; 
 int /*<<< orphan*/  ts4800_ic_ops ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

__attribute__((used)) static void ts4800_irq_mask(struct irq_data *d)
{
	struct ts4800_irq_data *data = irq_data_get_irq_chip_data(d);
	u16 reg = readw(data->base + IRQ_MASK);
	u16 mask = 1 << d->hwirq;

	writew(reg | mask, data->base + IRQ_MASK);
}

__attribute__((used)) static void ts4800_irq_unmask(struct irq_data *d)
{
	struct ts4800_irq_data *data = irq_data_get_irq_chip_data(d);
	u16 reg = readw(data->base + IRQ_MASK);
	u16 mask = 1 << d->hwirq;

	writew(reg & ~mask, data->base + IRQ_MASK);
}

__attribute__((used)) static int ts4800_irqdomain_map(struct irq_domain *d, unsigned int irq,
				irq_hw_number_t hwirq)
{
	struct ts4800_irq_data *data = d->host_data;

	irq_set_chip_and_handler(irq, &data->irq_chip, handle_simple_irq);
	irq_set_chip_data(irq, data);
	irq_set_noprobe(irq);

	return 0;
}

__attribute__((used)) static void ts4800_ic_chained_handle_irq(struct irq_desc *desc)
{
	struct ts4800_irq_data *data = irq_desc_get_handler_data(desc);
	struct irq_chip *chip = irq_desc_get_chip(desc);
	u16 status = readw(data->base + IRQ_STATUS);

	chained_irq_enter(chip, desc);

	if (unlikely(status == 0)) {
		handle_bad_irq(desc);
		goto out;
	}

	do {
		unsigned int bit = __ffs(status);
		int irq = irq_find_mapping(data->domain, bit);

		status &= ~(1 << bit);
		generic_handle_irq(irq);
	} while (status);

out:
	chained_irq_exit(chip, desc);
}

__attribute__((used)) static int ts4800_ic_probe(struct platform_device *pdev)
{
	struct device_node *node = pdev->dev.of_node;
	struct ts4800_irq_data *data;
	struct irq_chip *irq_chip;
	struct resource *res;
	int parent_irq;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	data->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(data->base))
		return PTR_ERR(data->base);

	writew(0xFFFF, data->base + IRQ_MASK);

	parent_irq = irq_of_parse_and_map(node, 0);
	if (!parent_irq) {
		dev_err(&pdev->dev, "failed to get parent IRQ\n");
		return -EINVAL;
	}

	irq_chip = &data->irq_chip;
	irq_chip->name = dev_name(&pdev->dev);
	irq_chip->irq_mask = ts4800_irq_mask;
	irq_chip->irq_unmask = ts4800_irq_unmask;

	data->domain = irq_domain_add_linear(node, 8, &ts4800_ic_ops, data);
	if (!data->domain) {
		dev_err(&pdev->dev, "cannot add IRQ domain\n");
		return -ENOMEM;
	}

	irq_set_chained_handler_and_data(parent_irq,
					 ts4800_ic_chained_handle_irq, data);

	platform_set_drvdata(pdev, data);

	return 0;
}

__attribute__((used)) static int ts4800_ic_remove(struct platform_device *pdev)
{
	struct ts4800_irq_data *data = platform_get_drvdata(pdev);

	irq_domain_remove(data->domain);

	return 0;
}

