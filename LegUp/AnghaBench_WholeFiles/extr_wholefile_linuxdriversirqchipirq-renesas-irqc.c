#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_9__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_18__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_5__ dev; } ;
struct irqc_priv {int number_of_irqs; scalar_t__ iomem; int /*<<< orphan*/  irq_domain; struct irqc_irq* irq; TYPE_9__* gc; scalar_t__ cpu_int_base; struct platform_device* pdev; int /*<<< orphan*/  wakeup_path; } ;
struct irqc_irq {int hw_irq; int /*<<< orphan*/  requested_irq; struct irqc_priv* p; } ;
struct irq_data {TYPE_4__* domain; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_19__ {TYPE_3__* chip_types; scalar_t__ reg_base; } ;
struct TYPE_17__ {struct irqc_priv* host_data; } ;
struct TYPE_15__ {int (* irq_set_type ) (struct irq_data*,unsigned int) ;int (* irq_set_wake ) (struct irq_data*,unsigned int) ;int /*<<< orphan*/  flags; int /*<<< orphan*/  irq_unmask; int /*<<< orphan*/  irq_mask; } ;
struct TYPE_14__ {int /*<<< orphan*/  disable; int /*<<< orphan*/  enable; } ;
struct TYPE_16__ {TYPE_2__ chip; TYPE_1__ regs; } ;

/* Variables and functions */
 int BIT (int) ; 
 scalar_t__ DETECT_STATUS ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQCHIP_MASK_ON_SUSPEND ; 
 scalar_t__ IRQC_CONFIG (int) ; 
 int /*<<< orphan*/  IRQC_EN_SET ; 
 int /*<<< orphan*/  IRQC_EN_STS ; 
 scalar_t__ IRQC_INT_CPU_BASE (int /*<<< orphan*/ ) ; 
 int IRQC_IRQ_MAX ; 
 int /*<<< orphan*/  IRQ_GC_INIT_NESTED_LOCK ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_5__*,char*,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_5__*,char*,int) ; 
 char* dev_name (TYPE_5__*) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct irqc_irq*) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int ioread32 (scalar_t__) ; 
 scalar_t__ ioremap_nocache (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (int,scalar_t__) ; 
 int irq_alloc_domain_generic_chips (int /*<<< orphan*/ ,int,int,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_domain_add_linear (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,struct irqc_priv*) ; 
 int /*<<< orphan*/  irq_domain_remove (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_find_mapping (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irq_gc_mask_disable_reg ; 
 int /*<<< orphan*/  irq_gc_unmask_enable_reg ; 
 int /*<<< orphan*/  irq_generic_chip_ops ; 
 TYPE_9__* irq_get_domain_generic_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_irq_wake (int /*<<< orphan*/ ,unsigned int) ; 
 unsigned char* irqc_sense ; 
 int irqd_to_hwirq (struct irq_data*) ; 
 int /*<<< orphan*/  kfree (struct irqc_priv*) ; 
 struct irqc_priv* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct irqc_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct irqc_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_5__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_5__*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (TYPE_5__*) ; 
 int /*<<< orphan*/  pm_runtime_put (TYPE_5__*) ; 
 scalar_t__ request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char const*,struct irqc_irq*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 

__attribute__((used)) static struct irqc_priv *irq_data_to_priv(struct irq_data *data)
{
	return data->domain->host_data;
}

__attribute__((used)) static void irqc_dbg(struct irqc_irq *i, char *str)
{
	dev_dbg(&i->p->pdev->dev, "%s (%d:%d)\n",
		str, i->requested_irq, i->hw_irq);
}

__attribute__((used)) static int irqc_irq_set_type(struct irq_data *d, unsigned int type)
{
	struct irqc_priv *p = irq_data_to_priv(d);
	int hw_irq = irqd_to_hwirq(d);
	unsigned char value = irqc_sense[type & IRQ_TYPE_SENSE_MASK];
	u32 tmp;

	irqc_dbg(&p->irq[hw_irq], "sense");

	if (!value)
		return -EINVAL;

	tmp = ioread32(p->iomem + IRQC_CONFIG(hw_irq));
	tmp &= ~0x3f;
	tmp |= value;
	iowrite32(tmp, p->iomem + IRQC_CONFIG(hw_irq));
	return 0;
}

__attribute__((used)) static int irqc_irq_set_wake(struct irq_data *d, unsigned int on)
{
	struct irqc_priv *p = irq_data_to_priv(d);
	int hw_irq = irqd_to_hwirq(d);

	irq_set_irq_wake(p->irq[hw_irq].requested_irq, on);
	if (on)
		atomic_inc(&p->wakeup_path);
	else
		atomic_dec(&p->wakeup_path);

	return 0;
}

__attribute__((used)) static irqreturn_t irqc_irq_handler(int irq, void *dev_id)
{
	struct irqc_irq *i = dev_id;
	struct irqc_priv *p = i->p;
	u32 bit = BIT(i->hw_irq);

	irqc_dbg(i, "demux1");

	if (ioread32(p->iomem + DETECT_STATUS) & bit) {
		iowrite32(bit, p->iomem + DETECT_STATUS);
		irqc_dbg(i, "demux2");
		generic_handle_irq(irq_find_mapping(p->irq_domain, i->hw_irq));
		return IRQ_HANDLED;
	}
	return IRQ_NONE;
}

__attribute__((used)) static int irqc_probe(struct platform_device *pdev)
{
	struct irqc_priv *p;
	struct resource *io;
	struct resource *irq;
	const char *name = dev_name(&pdev->dev);
	int ret;
	int k;

	p = kzalloc(sizeof(*p), GFP_KERNEL);
	if (!p) {
		dev_err(&pdev->dev, "failed to allocate driver data\n");
		ret = -ENOMEM;
		goto err0;
	}

	p->pdev = pdev;
	platform_set_drvdata(pdev, p);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_get_sync(&pdev->dev);

	/* get hold of manadatory IOMEM */
	io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!io) {
		dev_err(&pdev->dev, "not enough IOMEM resources\n");
		ret = -EINVAL;
		goto err1;
	}

	/* allow any number of IRQs between 1 and IRQC_IRQ_MAX */
	for (k = 0; k < IRQC_IRQ_MAX; k++) {
		irq = platform_get_resource(pdev, IORESOURCE_IRQ, k);
		if (!irq)
			break;

		p->irq[k].p = p;
		p->irq[k].hw_irq = k;
		p->irq[k].requested_irq = irq->start;
	}

	p->number_of_irqs = k;
	if (p->number_of_irqs < 1) {
		dev_err(&pdev->dev, "not enough IRQ resources\n");
		ret = -EINVAL;
		goto err1;
	}

	/* ioremap IOMEM and setup read/write callbacks */
	p->iomem = ioremap_nocache(io->start, resource_size(io));
	if (!p->iomem) {
		dev_err(&pdev->dev, "failed to remap IOMEM\n");
		ret = -ENXIO;
		goto err2;
	}

	p->cpu_int_base = p->iomem + IRQC_INT_CPU_BASE(0); /* SYS-SPI */

	p->irq_domain = irq_domain_add_linear(pdev->dev.of_node,
					      p->number_of_irqs,
					      &irq_generic_chip_ops, p);
	if (!p->irq_domain) {
		ret = -ENXIO;
		dev_err(&pdev->dev, "cannot initialize irq domain\n");
		goto err2;
	}

	ret = irq_alloc_domain_generic_chips(p->irq_domain, p->number_of_irqs,
					     1, name, handle_level_irq,
					     0, 0, IRQ_GC_INIT_NESTED_LOCK);
	if (ret) {
		dev_err(&pdev->dev, "cannot allocate generic chip\n");
		goto err3;
	}

	p->gc = irq_get_domain_generic_chip(p->irq_domain, 0);
	p->gc->reg_base = p->cpu_int_base;
	p->gc->chip_types[0].regs.enable = IRQC_EN_SET;
	p->gc->chip_types[0].regs.disable = IRQC_EN_STS;
	p->gc->chip_types[0].chip.irq_mask = irq_gc_mask_disable_reg;
	p->gc->chip_types[0].chip.irq_unmask = irq_gc_unmask_enable_reg;
	p->gc->chip_types[0].chip.irq_set_type	= irqc_irq_set_type;
	p->gc->chip_types[0].chip.irq_set_wake	= irqc_irq_set_wake;
	p->gc->chip_types[0].chip.flags	= IRQCHIP_MASK_ON_SUSPEND;

	/* request interrupts one by one */
	for (k = 0; k < p->number_of_irqs; k++) {
		if (request_irq(p->irq[k].requested_irq, irqc_irq_handler,
				0, name, &p->irq[k])) {
			dev_err(&pdev->dev, "failed to request IRQ\n");
			ret = -ENOENT;
			goto err4;
		}
	}

	dev_info(&pdev->dev, "driving %d irqs\n", p->number_of_irqs);

	return 0;
err4:
	while (--k >= 0)
		free_irq(p->irq[k].requested_irq, &p->irq[k]);

err3:
	irq_domain_remove(p->irq_domain);
err2:
	iounmap(p->iomem);
err1:
	pm_runtime_put(&pdev->dev);
	pm_runtime_disable(&pdev->dev);
	kfree(p);
err0:
	return ret;
}

__attribute__((used)) static int irqc_remove(struct platform_device *pdev)
{
	struct irqc_priv *p = platform_get_drvdata(pdev);
	int k;

	for (k = 0; k < p->number_of_irqs; k++)
		free_irq(p->irq[k].requested_irq, &p->irq[k]);

	irq_domain_remove(p->irq_domain);
	iounmap(p->iomem);
	pm_runtime_put(&pdev->dev);
	pm_runtime_disable(&pdev->dev);
	kfree(p);
	return 0;
}

