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
struct resource {int start; } ;
struct msi_msg {scalar_t__ data; int /*<<< orphan*/  address_lo; int /*<<< orphan*/  address_hi; } ;
struct irq_fwspec {int param_count; int* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {struct irq_domain* parent; struct alpine_msix_data* host_data; int /*<<< orphan*/  fwnode; } ;
struct irq_data {int hwirq; TYPE_1__* chip; } ;
struct device_node {int dummy; } ;
struct alpine_msix_data {int num_spis; int spi_first; int addr; struct alpine_msix_data* msi_map; int /*<<< orphan*/  msi_map_lock; } ;
typedef  int phys_addr_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* irq_set_type ) (struct irq_data*,int) ;} ;

/* Variables and functions */
 int ALPINE_MSIX_SPI_TARGET_CLUSTER0 ; 
 int /*<<< orphan*/  BITS_TO_LONGS (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int ENXIO ; 
 int GENMASK_ULL (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQ_TYPE_EDGE_RISING ; 
 int /*<<< orphan*/  alpine_msix_domain_info ; 
 int /*<<< orphan*/  alpine_msix_middle_domain_ops ; 
 int /*<<< orphan*/  bitmap_clear (struct alpine_msix_data*,int,int) ; 
 int bitmap_find_next_zero_area (struct alpine_msix_data*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_set (struct alpine_msix_data*,int,int) ; 
 int /*<<< orphan*/  irq_chip_mask_parent (struct irq_data*) ; 
 int /*<<< orphan*/  irq_chip_unmask_parent (struct irq_data*) ; 
 struct alpine_msix_data* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct irq_domain* irq_domain_add_tree (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct alpine_msix_data*) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,int,struct irq_fwspec*) ; 
 int /*<<< orphan*/  irq_domain_free_irqs_parent (struct irq_domain*,unsigned int,unsigned int) ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_domain_remove (struct irq_domain*) ; 
 int /*<<< orphan*/  irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,int,int /*<<< orphan*/ *,struct alpine_msix_data*) ; 
 struct irq_domain* irq_find_host (struct device_node*) ; 
 int /*<<< orphan*/  is_of_node (int /*<<< orphan*/ ) ; 
 struct alpine_msix_data* kcalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct alpine_msix_data*) ; 
 struct alpine_msix_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lower_32_bits (int) ; 
 int /*<<< orphan*/  middle_irq_chip ; 
 int of_address_to_resource (struct device_node*,int /*<<< orphan*/ ,struct resource*) ; 
 struct device_node* of_irq_find_parent (struct device_node*) ; 
 int /*<<< orphan*/  of_node_to_fwnode (struct device_node*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct irq_domain* pci_msi_create_irq_domain (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct irq_domain*) ; 
 int /*<<< orphan*/  pci_msi_mask_irq (struct irq_data*) ; 
 int /*<<< orphan*/  pci_msi_unmask_irq (struct irq_data*) ; 
 int /*<<< orphan*/  pr_debug (char*,int,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct irq_data*,int) ; 
 int /*<<< orphan*/  upper_32_bits (int) ; 

__attribute__((used)) static void alpine_msix_mask_msi_irq(struct irq_data *d)
{
	pci_msi_mask_irq(d);
	irq_chip_mask_parent(d);
}

__attribute__((used)) static void alpine_msix_unmask_msi_irq(struct irq_data *d)
{
	pci_msi_unmask_irq(d);
	irq_chip_unmask_parent(d);
}

__attribute__((used)) static int alpine_msix_allocate_sgi(struct alpine_msix_data *priv, int num_req)
{
	int first;

	spin_lock(&priv->msi_map_lock);

	first = bitmap_find_next_zero_area(priv->msi_map, priv->num_spis, 0,
					   num_req, 0);
	if (first >= priv->num_spis) {
		spin_unlock(&priv->msi_map_lock);
		return -ENOSPC;
	}

	bitmap_set(priv->msi_map, first, num_req);

	spin_unlock(&priv->msi_map_lock);

	return priv->spi_first + first;
}

__attribute__((used)) static void alpine_msix_free_sgi(struct alpine_msix_data *priv, unsigned sgi,
				 int num_req)
{
	int first = sgi - priv->spi_first;

	spin_lock(&priv->msi_map_lock);

	bitmap_clear(priv->msi_map, first, num_req);

	spin_unlock(&priv->msi_map_lock);
}

__attribute__((used)) static void alpine_msix_compose_msi_msg(struct irq_data *data,
					struct msi_msg *msg)
{
	struct alpine_msix_data *priv = irq_data_get_irq_chip_data(data);
	phys_addr_t msg_addr = priv->addr;

	msg_addr |= (data->hwirq << 3);

	msg->address_hi = upper_32_bits(msg_addr);
	msg->address_lo = lower_32_bits(msg_addr);
	msg->data = 0;
}

__attribute__((used)) static int alpine_msix_gic_domain_alloc(struct irq_domain *domain,
					unsigned int virq, int sgi)
{
	struct irq_fwspec fwspec;
	struct irq_data *d;
	int ret;

	if (!is_of_node(domain->parent->fwnode))
		return -EINVAL;

	fwspec.fwnode = domain->parent->fwnode;
	fwspec.param_count = 3;
	fwspec.param[0] = 0;
	fwspec.param[1] = sgi;
	fwspec.param[2] = IRQ_TYPE_EDGE_RISING;

	ret = irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
	if (ret)
		return ret;

	d = irq_domain_get_irq_data(domain->parent, virq);
	d->chip->irq_set_type(d, IRQ_TYPE_EDGE_RISING);

	return 0;
}

__attribute__((used)) static int alpine_msix_middle_domain_alloc(struct irq_domain *domain,
					   unsigned int virq,
					   unsigned int nr_irqs, void *args)
{
	struct alpine_msix_data *priv = domain->host_data;
	int sgi, err, i;

	sgi = alpine_msix_allocate_sgi(priv, nr_irqs);
	if (sgi < 0)
		return sgi;

	for (i = 0; i < nr_irqs; i++) {
		err = alpine_msix_gic_domain_alloc(domain, virq + i, sgi + i);
		if (err)
			goto err_sgi;

		irq_domain_set_hwirq_and_chip(domain, virq + i, sgi + i,
					      &middle_irq_chip, priv);
	}

	return 0;

err_sgi:
	while (--i >= 0)
		irq_domain_free_irqs_parent(domain, virq, i);
	alpine_msix_free_sgi(priv, sgi, nr_irqs);
	return err;
}

__attribute__((used)) static void alpine_msix_middle_domain_free(struct irq_domain *domain,
					   unsigned int virq,
					   unsigned int nr_irqs)
{
	struct irq_data *d = irq_domain_get_irq_data(domain, virq);
	struct alpine_msix_data *priv = irq_data_get_irq_chip_data(d);

	irq_domain_free_irqs_parent(domain, virq, nr_irqs);
	alpine_msix_free_sgi(priv, d->hwirq, nr_irqs);
}

__attribute__((used)) static int alpine_msix_init_domains(struct alpine_msix_data *priv,
				    struct device_node *node)
{
	struct irq_domain *middle_domain, *msi_domain, *gic_domain;
	struct device_node *gic_node;

	gic_node = of_irq_find_parent(node);
	if (!gic_node) {
		pr_err("Failed to find the GIC node\n");
		return -ENODEV;
	}

	gic_domain = irq_find_host(gic_node);
	if (!gic_domain) {
		pr_err("Failed to find the GIC domain\n");
		return -ENXIO;
	}

	middle_domain = irq_domain_add_tree(NULL,
					    &alpine_msix_middle_domain_ops,
					    priv);
	if (!middle_domain) {
		pr_err("Failed to create the MSIX middle domain\n");
		return -ENOMEM;
	}

	middle_domain->parent = gic_domain;

	msi_domain = pci_msi_create_irq_domain(of_node_to_fwnode(node),
					       &alpine_msix_domain_info,
					       middle_domain);
	if (!msi_domain) {
		pr_err("Failed to create MSI domain\n");
		irq_domain_remove(middle_domain);
		return -ENOMEM;
	}

	return 0;
}

__attribute__((used)) static int alpine_msix_init(struct device_node *node,
			    struct device_node *parent)
{
	struct alpine_msix_data *priv;
	struct resource res;
	int ret;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	spin_lock_init(&priv->msi_map_lock);

	ret = of_address_to_resource(node, 0, &res);
	if (ret) {
		pr_err("Failed to allocate resource\n");
		goto err_priv;
	}

	/*
	 * The 20 least significant bits of addr provide direct information
	 * regarding the interrupt destination.
	 *
	 * To select the primary GIC as the target GIC, bits [18:17] must be set
	 * to 0x0. In this case, bit 16 (SPI_TARGET_CLUSTER0) must be set.
	 */
	priv->addr = res.start & GENMASK_ULL(63,20);
	priv->addr |= ALPINE_MSIX_SPI_TARGET_CLUSTER0;

	if (of_property_read_u32(node, "al,msi-base-spi", &priv->spi_first)) {
		pr_err("Unable to parse MSI base\n");
		ret = -EINVAL;
		goto err_priv;
	}

	if (of_property_read_u32(node, "al,msi-num-spis", &priv->num_spis)) {
		pr_err("Unable to parse MSI numbers\n");
		ret = -EINVAL;
		goto err_priv;
	}

	priv->msi_map = kcalloc(BITS_TO_LONGS(priv->num_spis),
				sizeof(*priv->msi_map),
				GFP_KERNEL);
	if (!priv->msi_map) {
		ret = -ENOMEM;
		goto err_priv;
	}

	pr_debug("Registering %d msixs, starting at %d\n",
		 priv->num_spis, priv->spi_first);

	ret = alpine_msix_init_domains(priv, node);
	if (ret)
		goto err_map;

	return 0;

err_map:
	kfree(priv->msi_map);
err_priv:
	kfree(priv);
	return ret;
}

