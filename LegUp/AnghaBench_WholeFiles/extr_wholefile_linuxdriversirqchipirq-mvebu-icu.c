#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u32 ;
struct resource {scalar_t__ start; } ;
struct TYPE_8__ {int /*<<< orphan*/  msi_domain; struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct mvebu_icu_irq_data {int type; unsigned int icu_group; struct mvebu_icu* icu; } ;
struct TYPE_9__ {int /*<<< orphan*/  irq_set_type; int /*<<< orphan*/  irq_eoi; int /*<<< orphan*/  irq_unmask; int /*<<< orphan*/  irq_mask; int /*<<< orphan*/  name; } ;
struct mvebu_icu {int /*<<< orphan*/  domain; scalar_t__ base; TYPE_3__ irq_chip; TYPE_1__* dev; int /*<<< orphan*/  initialized; } ;
struct msi_msg {int address_hi; int address_lo; unsigned int data; } ;
struct msi_desc {unsigned int irq; } ;
struct irq_fwspec {int param_count; unsigned int* param; } ;
struct irq_domain {struct mvebu_icu* host_data; } ;
struct irq_data {int hwirq; struct mvebu_icu_irq_data* chip_data; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DOMAIN_BUS_PLATFORM_MSI ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ ICU_CLRSPI_NSR_AH ; 
 scalar_t__ ICU_CLRSPI_NSR_AL ; 
 unsigned int ICU_GROUP_SHIFT ; 
 unsigned int ICU_GRP_NSR ; 
 unsigned int ICU_GRP_REI ; 
 unsigned int ICU_GRP_SEI ; 
 unsigned int ICU_GRP_SR ; 
 scalar_t__ ICU_INT_CFG (int) ; 
 unsigned int ICU_INT_ENABLE ; 
 unsigned int ICU_IS_EDGE ; 
 unsigned long ICU_MAX_IRQS ; 
 scalar_t__ ICU_SATA0_ICU_ID ; 
 scalar_t__ ICU_SATA1_ICU_ID ; 
 scalar_t__ ICU_SETSPI_NSR_AH ; 
 scalar_t__ ICU_SETSPI_NSR_AL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQCHIP_STATE_PENDING ; 
 int IRQ_TYPE_EDGE_RISING ; 
 unsigned int IRQ_TYPE_SENSE_MASK ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ WARN_ON (int) ; 
 scalar_t__ atomic_cmpxchg (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 int /*<<< orphan*/  devm_kasprintf (TYPE_1__*,int /*<<< orphan*/ ,char*,unsigned int) ; 
 struct mvebu_icu* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_chip_eoi_parent ; 
 int /*<<< orphan*/  irq_chip_mask_parent ; 
 int /*<<< orphan*/  irq_chip_set_type_parent ; 
 int /*<<< orphan*/  irq_chip_unmask_parent ; 
 struct device_node* irq_domain_get_of_node (int /*<<< orphan*/ ) ; 
 int irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,unsigned long,TYPE_3__*,struct mvebu_icu_irq_data*) ; 
 struct irq_data* irq_get_irq_data (unsigned int) ; 
 int irq_set_irqchip_state (unsigned int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kfree (struct mvebu_icu_irq_data*) ; 
 struct mvebu_icu_irq_data* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mvebu_icu_domain_ops ; 
 int /*<<< orphan*/  of_msi_get_domain (TYPE_1__*,struct device_node*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_msi_create_device_domain (TYPE_1__*,unsigned long,void (*) (struct msi_desc*,struct msi_msg*),int /*<<< orphan*/ *,struct mvebu_icu*) ; 
 int platform_msi_domain_alloc (struct irq_domain*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  platform_msi_domain_free (struct irq_domain*,unsigned int,unsigned int) ; 
 struct mvebu_icu* platform_msi_get_host_data (struct irq_domain*) ; 
 unsigned int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void mvebu_icu_init(struct mvebu_icu *icu, struct msi_msg *msg)
{
	if (atomic_cmpxchg(&icu->initialized, false, true))
		return;

	/* Set Clear/Set ICU SPI message address in AP */
	writel_relaxed(msg[0].address_hi, icu->base + ICU_SETSPI_NSR_AH);
	writel_relaxed(msg[0].address_lo, icu->base + ICU_SETSPI_NSR_AL);
	writel_relaxed(msg[1].address_hi, icu->base + ICU_CLRSPI_NSR_AH);
	writel_relaxed(msg[1].address_lo, icu->base + ICU_CLRSPI_NSR_AL);
}

__attribute__((used)) static void mvebu_icu_write_msg(struct msi_desc *desc, struct msi_msg *msg)
{
	struct irq_data *d = irq_get_irq_data(desc->irq);
	struct mvebu_icu_irq_data *icu_irqd = d->chip_data;
	struct mvebu_icu *icu = icu_irqd->icu;
	unsigned int icu_int;

	if (msg->address_lo || msg->address_hi) {
		/* One off initialization */
		mvebu_icu_init(icu, msg);
		/* Configure the ICU with irq number & type */
		icu_int = msg->data | ICU_INT_ENABLE;
		if (icu_irqd->type & IRQ_TYPE_EDGE_RISING)
			icu_int |= ICU_IS_EDGE;
		icu_int |= icu_irqd->icu_group << ICU_GROUP_SHIFT;
	} else {
		/* De-configure the ICU */
		icu_int = 0;
	}

	writel_relaxed(icu_int, icu->base + ICU_INT_CFG(d->hwirq));

	/*
	 * The SATA unit has 2 ports, and a dedicated ICU entry per
	 * port. The ahci sata driver supports only one irq interrupt
	 * per SATA unit. To solve this conflict, we configure the 2
	 * SATA wired interrupts in the south bridge into 1 GIC
	 * interrupt in the north bridge. Even if only a single port
	 * is enabled, if sata node is enabled, both interrupts are
	 * configured (regardless of which port is actually in use).
	 */
	if (d->hwirq == ICU_SATA0_ICU_ID || d->hwirq == ICU_SATA1_ICU_ID) {
		writel_relaxed(icu_int,
			       icu->base + ICU_INT_CFG(ICU_SATA0_ICU_ID));
		writel_relaxed(icu_int,
			       icu->base + ICU_INT_CFG(ICU_SATA1_ICU_ID));
	}
}

__attribute__((used)) static int
mvebu_icu_irq_domain_translate(struct irq_domain *d, struct irq_fwspec *fwspec,
			       unsigned long *hwirq, unsigned int *type)
{
	struct mvebu_icu *icu = d->host_data;
	unsigned int icu_group;

	/* Check the count of the parameters in dt */
	if (WARN_ON(fwspec->param_count < 3)) {
		dev_err(icu->dev, "wrong ICU parameter count %d\n",
			fwspec->param_count);
		return -EINVAL;
	}

	/* Only ICU group type is handled */
	icu_group = fwspec->param[0];
	if (icu_group != ICU_GRP_NSR && icu_group != ICU_GRP_SR &&
	    icu_group != ICU_GRP_SEI && icu_group != ICU_GRP_REI) {
		dev_err(icu->dev, "wrong ICU group type %x\n", icu_group);
		return -EINVAL;
	}

	*hwirq = fwspec->param[1];
	if (*hwirq >= ICU_MAX_IRQS) {
		dev_err(icu->dev, "invalid interrupt number %ld\n", *hwirq);
		return -EINVAL;
	}

	/* Mask the type to prevent wrong DT configuration */
	*type = fwspec->param[2] & IRQ_TYPE_SENSE_MASK;

	return 0;
}

__attribute__((used)) static int
mvebu_icu_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
			   unsigned int nr_irqs, void *args)
{
	int err;
	unsigned long hwirq;
	struct irq_fwspec *fwspec = args;
	struct mvebu_icu *icu = platform_msi_get_host_data(domain);
	struct mvebu_icu_irq_data *icu_irqd;

	icu_irqd = kmalloc(sizeof(*icu_irqd), GFP_KERNEL);
	if (!icu_irqd)
		return -ENOMEM;

	err = mvebu_icu_irq_domain_translate(domain, fwspec, &hwirq,
					     &icu_irqd->type);
	if (err) {
		dev_err(icu->dev, "failed to translate ICU parameters\n");
		goto free_irqd;
	}

	icu_irqd->icu_group = fwspec->param[0];
	icu_irqd->icu = icu;

	err = platform_msi_domain_alloc(domain, virq, nr_irqs);
	if (err) {
		dev_err(icu->dev, "failed to allocate ICU interrupt in parent domain\n");
		goto free_irqd;
	}

	/* Make sure there is no interrupt left pending by the firmware */
	err = irq_set_irqchip_state(virq, IRQCHIP_STATE_PENDING, false);
	if (err)
		goto free_msi;

	err = irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
					    &icu->irq_chip, icu_irqd);
	if (err) {
		dev_err(icu->dev, "failed to set the data to IRQ domain\n");
		goto free_msi;
	}

	return 0;

free_msi:
	platform_msi_domain_free(domain, virq, nr_irqs);
free_irqd:
	kfree(icu_irqd);
	return err;
}

__attribute__((used)) static void
mvebu_icu_irq_domain_free(struct irq_domain *domain, unsigned int virq,
			  unsigned int nr_irqs)
{
	struct irq_data *d = irq_get_irq_data(virq);
	struct mvebu_icu_irq_data *icu_irqd = d->chip_data;

	kfree(icu_irqd);

	platform_msi_domain_free(domain, virq, nr_irqs);
}

__attribute__((used)) static int mvebu_icu_probe(struct platform_device *pdev)
{
	struct mvebu_icu *icu;
	struct device_node *node = pdev->dev.of_node;
	struct device_node *gicp_dn;
	struct resource *res;
	int i;

	icu = devm_kzalloc(&pdev->dev, sizeof(struct mvebu_icu),
			   GFP_KERNEL);
	if (!icu)
		return -ENOMEM;

	icu->dev = &pdev->dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	icu->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(icu->base)) {
		dev_err(&pdev->dev, "Failed to map icu base address.\n");
		return PTR_ERR(icu->base);
	}

	icu->irq_chip.name = devm_kasprintf(&pdev->dev, GFP_KERNEL,
					    "ICU.%x",
					    (unsigned int)res->start);
	if (!icu->irq_chip.name)
		return -ENOMEM;

	icu->irq_chip.irq_mask = irq_chip_mask_parent;
	icu->irq_chip.irq_unmask = irq_chip_unmask_parent;
	icu->irq_chip.irq_eoi = irq_chip_eoi_parent;
	icu->irq_chip.irq_set_type = irq_chip_set_type_parent;
#ifdef CONFIG_SMP
	icu->irq_chip.irq_set_affinity = irq_chip_set_affinity_parent;
#endif

	/*
	 * We're probed after MSI domains have been resolved, so force
	 * resolution here.
	 */
	pdev->dev.msi_domain = of_msi_get_domain(&pdev->dev, node,
						 DOMAIN_BUS_PLATFORM_MSI);
	if (!pdev->dev.msi_domain)
		return -EPROBE_DEFER;

	gicp_dn = irq_domain_get_of_node(pdev->dev.msi_domain);
	if (!gicp_dn)
		return -ENODEV;

	/*
	 * Clean all ICU interrupts with type SPI_NSR, required to
	 * avoid unpredictable SPI assignments done by firmware.
	 */
	for (i = 0 ; i < ICU_MAX_IRQS ; i++) {
		u32 icu_int = readl_relaxed(icu->base + ICU_INT_CFG(i));
		if ((icu_int >> ICU_GROUP_SHIFT) == ICU_GRP_NSR)
			writel_relaxed(0x0, icu->base + ICU_INT_CFG(i));
	}

	icu->domain =
		platform_msi_create_device_domain(&pdev->dev, ICU_MAX_IRQS,
						  mvebu_icu_write_msg,
						  &mvebu_icu_domain_ops, icu);
	if (!icu->domain) {
		dev_err(&pdev->dev, "Failed to create ICU domain\n");
		return -ENOMEM;
	}

	return 0;
}

