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
struct TYPE_8__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct mvebu_gicp_spi_range {int count; int start; } ;
struct mvebu_gicp {int spi_ranges_cnt; unsigned int spi_cnt; void* spi_bitmap; struct mvebu_gicp_spi_range* spi_ranges; TYPE_2__* res; int /*<<< orphan*/  spi_lock; TYPE_3__* dev; } ;
struct msi_msg {unsigned int data; void* address_hi; void* address_lo; } ;
struct irq_fwspec {int param_count; int* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {struct mvebu_gicp* host_data; TYPE_1__* parent; } ;
struct irq_data {unsigned int hwirq; struct mvebu_gicp* chip_data; } ;
struct device_node {int dummy; } ;
typedef  scalar_t__ phys_addr_t ;
struct TYPE_7__ {scalar_t__ start; } ;
struct TYPE_6__ {int /*<<< orphan*/  fwnode; } ;

/* Variables and functions */
 int BITS_TO_LONGS (unsigned int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ GICP_CLRSPI_NSR_OFFSET ; 
 scalar_t__ GICP_SETSPI_NSR_OFFSET ; 
 int GIC_SPI ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int IRQ_TYPE_EDGE_RISING ; 
 int /*<<< orphan*/  __clear_bit (unsigned int,void*) ; 
 int /*<<< orphan*/  __set_bit (unsigned int,void*) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 void* devm_kcalloc (TYPE_3__*,int,int,int /*<<< orphan*/ ) ; 
 struct mvebu_gicp* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 unsigned int find_first_zero_bit (void*,unsigned int) ; 
 int /*<<< orphan*/  gicp_domain_ops ; 
 int /*<<< orphan*/  gicp_irq_chip ; 
 int /*<<< orphan*/  gicp_msi_domain_info ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,int,struct irq_fwspec*) ; 
 struct irq_domain* irq_domain_create_hierarchy (struct irq_domain*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct mvebu_gicp*) ; 
 int /*<<< orphan*/  irq_domain_free_irqs_parent (struct irq_domain*,unsigned int,unsigned int) ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_domain_remove (struct irq_domain*) ; 
 int irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,unsigned int,int /*<<< orphan*/ *,struct mvebu_gicp*) ; 
 struct irq_domain* irq_find_host (struct device_node*) ; 
 void* lower_32_bits (scalar_t__) ; 
 struct device_node* of_irq_find_parent (struct device_node*) ; 
 int /*<<< orphan*/  of_node_to_fwnode (struct device_node*) ; 
 int of_property_count_u32_elems (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_property_read_u32_index (struct device_node*,char*,int,int*) ; 
 TYPE_2__* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct irq_domain* platform_msi_create_irq_domain (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct irq_domain*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mvebu_gicp*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 void* upper_32_bits (scalar_t__) ; 

__attribute__((used)) static int gicp_idx_to_spi(struct mvebu_gicp *gicp, int idx)
{
	int i;

	for (i = 0; i < gicp->spi_ranges_cnt; i++) {
		struct mvebu_gicp_spi_range *r = &gicp->spi_ranges[i];

		if (idx < r->count)
			return r->start + idx;

		idx -= r->count;
	}

	return -EINVAL;
}

__attribute__((used)) static void gicp_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
	struct mvebu_gicp *gicp = data->chip_data;
	phys_addr_t setspi = gicp->res->start + GICP_SETSPI_NSR_OFFSET;
	phys_addr_t clrspi = gicp->res->start + GICP_CLRSPI_NSR_OFFSET;

	msg[0].data = data->hwirq;
	msg[0].address_lo = lower_32_bits(setspi);
	msg[0].address_hi = upper_32_bits(setspi);
	msg[1].data = data->hwirq;
	msg[1].address_lo = lower_32_bits(clrspi);
	msg[1].address_hi = upper_32_bits(clrspi);
}

__attribute__((used)) static int gicp_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
				 unsigned int nr_irqs, void *args)
{
	struct mvebu_gicp *gicp = domain->host_data;
	struct irq_fwspec fwspec;
	unsigned int hwirq;
	int ret;

	spin_lock(&gicp->spi_lock);
	hwirq = find_first_zero_bit(gicp->spi_bitmap, gicp->spi_cnt);
	if (hwirq == gicp->spi_cnt) {
		spin_unlock(&gicp->spi_lock);
		return -ENOSPC;
	}
	__set_bit(hwirq, gicp->spi_bitmap);
	spin_unlock(&gicp->spi_lock);

	fwspec.fwnode = domain->parent->fwnode;
	fwspec.param_count = 3;
	fwspec.param[0] = GIC_SPI;
	fwspec.param[1] = gicp_idx_to_spi(gicp, hwirq) - 32;
	/*
	 * Assume edge rising for now, it will be properly set when
	 * ->set_type() is called
	 */
	fwspec.param[2] = IRQ_TYPE_EDGE_RISING;

	ret = irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
	if (ret) {
		dev_err(gicp->dev, "Cannot allocate parent IRQ\n");
		goto free_hwirq;
	}

	ret = irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
					    &gicp_irq_chip, gicp);
	if (ret)
		goto free_irqs_parent;

	return 0;

free_irqs_parent:
	irq_domain_free_irqs_parent(domain, virq, nr_irqs);
free_hwirq:
	spin_lock(&gicp->spi_lock);
	__clear_bit(hwirq, gicp->spi_bitmap);
	spin_unlock(&gicp->spi_lock);
	return ret;
}

__attribute__((used)) static void gicp_irq_domain_free(struct irq_domain *domain,
				 unsigned int virq, unsigned int nr_irqs)
{
	struct mvebu_gicp *gicp = domain->host_data;
	struct irq_data *d = irq_domain_get_irq_data(domain, virq);

	if (d->hwirq >= gicp->spi_cnt) {
		dev_err(gicp->dev, "Invalid hwirq %lu\n", d->hwirq);
		return;
	}

	irq_domain_free_irqs_parent(domain, virq, nr_irqs);

	spin_lock(&gicp->spi_lock);
	__clear_bit(d->hwirq, gicp->spi_bitmap);
	spin_unlock(&gicp->spi_lock);
}

__attribute__((used)) static int mvebu_gicp_probe(struct platform_device *pdev)
{
	struct mvebu_gicp *gicp;
	struct irq_domain *inner_domain, *plat_domain, *parent_domain;
	struct device_node *node = pdev->dev.of_node;
	struct device_node *irq_parent_dn;
	int ret, i;

	gicp = devm_kzalloc(&pdev->dev, sizeof(*gicp), GFP_KERNEL);
	if (!gicp)
		return -ENOMEM;

	gicp->dev = &pdev->dev;
	spin_lock_init(&gicp->spi_lock);

	gicp->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!gicp->res)
		return -ENODEV;

	ret = of_property_count_u32_elems(node, "marvell,spi-ranges");
	if (ret < 0)
		return ret;

	gicp->spi_ranges_cnt = ret / 2;

	gicp->spi_ranges =
		devm_kcalloc(&pdev->dev,
			     gicp->spi_ranges_cnt,
			     sizeof(struct mvebu_gicp_spi_range),
			     GFP_KERNEL);
	if (!gicp->spi_ranges)
		return -ENOMEM;

	for (i = 0; i < gicp->spi_ranges_cnt; i++) {
		of_property_read_u32_index(node, "marvell,spi-ranges",
					   i * 2,
					   &gicp->spi_ranges[i].start);

		of_property_read_u32_index(node, "marvell,spi-ranges",
					   i * 2 + 1,
					   &gicp->spi_ranges[i].count);

		gicp->spi_cnt += gicp->spi_ranges[i].count;
	}

	gicp->spi_bitmap = devm_kcalloc(&pdev->dev,
				BITS_TO_LONGS(gicp->spi_cnt), sizeof(long),
				GFP_KERNEL);
	if (!gicp->spi_bitmap)
		return -ENOMEM;

	irq_parent_dn = of_irq_find_parent(node);
	if (!irq_parent_dn) {
		dev_err(&pdev->dev, "failed to find parent IRQ node\n");
		return -ENODEV;
	}

	parent_domain = irq_find_host(irq_parent_dn);
	if (!parent_domain) {
		dev_err(&pdev->dev, "failed to find parent IRQ domain\n");
		return -ENODEV;
	}

	inner_domain = irq_domain_create_hierarchy(parent_domain, 0,
						   gicp->spi_cnt,
						   of_node_to_fwnode(node),
						   &gicp_domain_ops, gicp);
	if (!inner_domain)
		return -ENOMEM;


	plat_domain = platform_msi_create_irq_domain(of_node_to_fwnode(node),
						     &gicp_msi_domain_info,
						     inner_domain);
	if (!plat_domain) {
		irq_domain_remove(inner_domain);
		return -ENOMEM;
	}

	platform_set_drvdata(pdev, gicp);

	return 0;
}

