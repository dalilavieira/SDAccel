#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct msi_msg {int /*<<< orphan*/  data; void* address_lo; void* address_hi; } ;
struct mbi_range {int spi_start; int /*<<< orphan*/  nr_spis; int /*<<< orphan*/  bm; } ;
struct irq_fwspec {int param_count; int* param; int /*<<< orphan*/  fwnode; } ;
struct irq_domain {int /*<<< orphan*/  fwnode; struct irq_domain* parent; } ;
struct irq_data {unsigned int hwirq; int /*<<< orphan*/  irq; TYPE_2__* parent_data; TYPE_1__* chip; } ;
typedef  int irq_hw_number_t ;
struct TYPE_4__ {int /*<<< orphan*/  hwirq; } ;
struct TYPE_3__ {int (* irq_set_type ) (struct irq_data*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DOMAIN_BUS_NEXUS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSPC ; 
 scalar_t__ GICD_CLRSPI_NSR ; 
 scalar_t__ GICD_SETSPI_NSR ; 
 int IRQ_TYPE_EDGE_RISING ; 
 int bitmap_find_free_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_release_region (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_count_order (unsigned int) ; 
 int /*<<< orphan*/  iommu_dma_map_msi_msg (int /*<<< orphan*/ ,struct msi_msg*) ; 
 struct mbi_range* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,int,struct irq_fwspec*) ; 
 struct irq_domain* irq_domain_create_tree (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_domain_free_irqs_parent (struct irq_domain*,unsigned int,unsigned int) ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_domain_remove (struct irq_domain*) ; 
 int /*<<< orphan*/  irq_domain_set_hwirq_and_chip (struct irq_domain*,unsigned int,int,int /*<<< orphan*/ *,struct mbi_range*) ; 
 int /*<<< orphan*/  irq_domain_update_bus_token (struct irq_domain*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  is_of_node (int /*<<< orphan*/ ) ; 
 void* lower_32_bits (scalar_t__) ; 
 int /*<<< orphan*/  mbi_domain_ops ; 
 int /*<<< orphan*/  mbi_irq_chip ; 
 int /*<<< orphan*/  mbi_lock ; 
 scalar_t__ mbi_phys_base ; 
 int /*<<< orphan*/  mbi_pmsi_domain_info ; 
 int mbi_range_nr ; 
 struct mbi_range* mbi_ranges ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct irq_domain* platform_msi_create_irq_domain (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct irq_domain*) ; 
 int stub1 (struct irq_data*,int) ; 
 void* upper_32_bits (scalar_t__) ; 

__attribute__((used)) static int mbi_irq_gic_domain_alloc(struct irq_domain *domain,
				       unsigned int virq,
				       irq_hw_number_t hwirq)
{
	struct irq_fwspec fwspec;
	struct irq_data *d;
	int err;

	/*
	 * Using ACPI? There is no MBI support in the spec, you
	 * shouldn't even be here.
	 */
	if (!is_of_node(domain->parent->fwnode))
		return -EINVAL;

	/*
	 * Let's default to edge. This is consistent with traditional
	 * MSIs, and systems requiring level signaling will just
	 * enforce the trigger on their own.
	 */
	fwspec.fwnode = domain->parent->fwnode;
	fwspec.param_count = 3;
	fwspec.param[0] = 0;
	fwspec.param[1] = hwirq - 32;
	fwspec.param[2] = IRQ_TYPE_EDGE_RISING;

	err = irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
	if (err)
		return err;

	d = irq_domain_get_irq_data(domain->parent, virq);
	return d->chip->irq_set_type(d, IRQ_TYPE_EDGE_RISING);
}

__attribute__((used)) static void mbi_free_msi(struct mbi_range *mbi, unsigned int hwirq,
			 int nr_irqs)
{
	mutex_lock(&mbi_lock);
	bitmap_release_region(mbi->bm, hwirq - mbi->spi_start,
			      get_count_order(nr_irqs));
	mutex_unlock(&mbi_lock);
}

__attribute__((used)) static int mbi_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
				   unsigned int nr_irqs, void *args)
{
	struct mbi_range *mbi = NULL;
	int hwirq, offset, i, err = 0;

	mutex_lock(&mbi_lock);
	for (i = 0; i < mbi_range_nr; i++) {
		offset = bitmap_find_free_region(mbi_ranges[i].bm,
						 mbi_ranges[i].nr_spis,
						 get_count_order(nr_irqs));
		if (offset >= 0) {
			mbi = &mbi_ranges[i];
			break;
		}
	}
	mutex_unlock(&mbi_lock);

	if (!mbi)
		return -ENOSPC;

	hwirq = mbi->spi_start + offset;

	for (i = 0; i < nr_irqs; i++) {
		err = mbi_irq_gic_domain_alloc(domain, virq + i, hwirq + i);
		if (err)
			goto fail;

		irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
					      &mbi_irq_chip, mbi);
	}

	return 0;

fail:
	irq_domain_free_irqs_parent(domain, virq, nr_irqs);
	mbi_free_msi(mbi, hwirq, nr_irqs);
	return err;
}

__attribute__((used)) static void mbi_irq_domain_free(struct irq_domain *domain,
				unsigned int virq, unsigned int nr_irqs)
{
	struct irq_data *d = irq_domain_get_irq_data(domain, virq);
	struct mbi_range *mbi = irq_data_get_irq_chip_data(d);

	mbi_free_msi(mbi, d->hwirq, nr_irqs);
	irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}

__attribute__((used)) static void mbi_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
	msg[0].address_hi = upper_32_bits(mbi_phys_base + GICD_SETSPI_NSR);
	msg[0].address_lo = lower_32_bits(mbi_phys_base + GICD_SETSPI_NSR);
	msg[0].data = data->parent_data->hwirq;

	iommu_dma_map_msi_msg(data->irq, msg);
}

__attribute__((used)) static int mbi_allocate_pci_domain(struct irq_domain *nexus_domain,
				   struct irq_domain **pci_domain)
{
	*pci_domain = NULL;
	return 0;
}

__attribute__((used)) static void mbi_compose_mbi_msg(struct irq_data *data, struct msi_msg *msg)
{
	mbi_compose_msi_msg(data, msg);

	msg[1].address_hi = upper_32_bits(mbi_phys_base + GICD_CLRSPI_NSR);
	msg[1].address_lo = lower_32_bits(mbi_phys_base + GICD_CLRSPI_NSR);
	msg[1].data = data->parent_data->hwirq;

	iommu_dma_map_msi_msg(data->irq, &msg[1]);
}

__attribute__((used)) static int mbi_allocate_domains(struct irq_domain *parent)
{
	struct irq_domain *nexus_domain, *pci_domain, *plat_domain;
	int err;

	nexus_domain = irq_domain_create_tree(parent->fwnode,
					      &mbi_domain_ops, NULL);
	if (!nexus_domain)
		return -ENOMEM;

	irq_domain_update_bus_token(nexus_domain, DOMAIN_BUS_NEXUS);
	nexus_domain->parent = parent;

	err = mbi_allocate_pci_domain(nexus_domain, &pci_domain);

	plat_domain = platform_msi_create_irq_domain(parent->fwnode,
						     &mbi_pmsi_domain_info,
						     nexus_domain);

	if (err || !plat_domain) {
		if (plat_domain)
			irq_domain_remove(plat_domain);
		if (pci_domain)
			irq_domain_remove(pci_domain);
		irq_domain_remove(nexus_domain);
		return -ENOMEM;
	}

	return 0;
}

