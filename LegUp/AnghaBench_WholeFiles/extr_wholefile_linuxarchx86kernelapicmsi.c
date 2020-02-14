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
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct msi_msg {int address_lo; int data; int /*<<< orphan*/  address_hi; } ;
struct msi_domain_info {int dummy; } ;
struct TYPE_3__ {scalar_t__ is_msix; } ;
struct msi_desc {TYPE_1__ msi_attrib; } ;
struct irq_domain {int dummy; } ;
struct irq_data {int dummy; } ;
struct irq_cfg {int /*<<< orphan*/  vector; int /*<<< orphan*/  dest_apicid; } ;
struct irq_alloc_info {struct pci_dev* msi_dev; int /*<<< orphan*/  msi_hwirq; int /*<<< orphan*/  flags; void* type; } ;
struct device {int dummy; } ;
typedef  struct irq_alloc_info msi_alloc_info_t ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
struct TYPE_4__ {scalar_t__ irq_dest_mode; } ;

/* Variables and functions */
 int ENOSYS ; 
 int /*<<< orphan*/  MSI_ADDR_BASE_HI ; 
 int MSI_ADDR_BASE_LO ; 
 int MSI_ADDR_DEST_ID (int /*<<< orphan*/ ) ; 
 int MSI_ADDR_DEST_MODE_LOGICAL ; 
 int MSI_ADDR_DEST_MODE_PHYSICAL ; 
 int /*<<< orphan*/  MSI_ADDR_EXT_DEST_ID (int /*<<< orphan*/ ) ; 
 int MSI_ADDR_REDIRECTION_CPU ; 
 int MSI_DATA_DELIVERY_FIXED ; 
 int MSI_DATA_LEVEL_ASSERT ; 
 int MSI_DATA_TRIGGER_EDGE ; 
 int MSI_DATA_VECTOR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X86_IRQ_ALLOC_CONTIGUOUS_VECTORS ; 
 void* X86_IRQ_ALLOC_TYPE_MSI ; 
 void* X86_IRQ_ALLOC_TYPE_MSIX ; 
 TYPE_2__* apic ; 
 struct msi_desc* first_pci_msi_entry (struct pci_dev*) ; 
 int /*<<< orphan*/  init_irq_alloc_info (struct irq_alloc_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_domain_free_irqs (unsigned int,int) ; 
 struct irq_domain* irq_remapping_get_irq_domain (struct irq_alloc_info*) ; 
 struct irq_cfg* irqd_cfg (struct irq_data*) ; 
 struct irq_domain* msi_default_domain ; 
 int msi_domain_alloc_irqs (struct irq_domain*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pci_msi_domain_calc_hwirq (struct pci_dev*,struct msi_desc*) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 
 scalar_t__ x2apic_enabled () ; 

__attribute__((used)) static void irq_msi_compose_msg(struct irq_data *data, struct msi_msg *msg)
{
	struct irq_cfg *cfg = irqd_cfg(data);

	msg->address_hi = MSI_ADDR_BASE_HI;

	if (x2apic_enabled())
		msg->address_hi |= MSI_ADDR_EXT_DEST_ID(cfg->dest_apicid);

	msg->address_lo =
		MSI_ADDR_BASE_LO |
		((apic->irq_dest_mode == 0) ?
			MSI_ADDR_DEST_MODE_PHYSICAL :
			MSI_ADDR_DEST_MODE_LOGICAL) |
		MSI_ADDR_REDIRECTION_CPU |
		MSI_ADDR_DEST_ID(cfg->dest_apicid);

	msg->data =
		MSI_DATA_TRIGGER_EDGE |
		MSI_DATA_LEVEL_ASSERT |
		MSI_DATA_DELIVERY_FIXED |
		MSI_DATA_VECTOR(cfg->vector);
}

int native_setup_msi_irqs(struct pci_dev *dev, int nvec, int type)
{
	struct irq_domain *domain;
	struct irq_alloc_info info;

	init_irq_alloc_info(&info, NULL);
	info.type = X86_IRQ_ALLOC_TYPE_MSI;
	info.msi_dev = dev;

	domain = irq_remapping_get_irq_domain(&info);
	if (domain == NULL)
		domain = msi_default_domain;
	if (domain == NULL)
		return -ENOSYS;

	return msi_domain_alloc_irqs(domain, &dev->dev, nvec);
}

void native_teardown_msi_irq(unsigned int irq)
{
	irq_domain_free_irqs(irq, 1);
}

__attribute__((used)) static irq_hw_number_t pci_msi_get_hwirq(struct msi_domain_info *info,
					 msi_alloc_info_t *arg)
{
	return arg->msi_hwirq;
}

int pci_msi_prepare(struct irq_domain *domain, struct device *dev, int nvec,
		    msi_alloc_info_t *arg)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	struct msi_desc *desc = first_pci_msi_entry(pdev);

	init_irq_alloc_info(arg, NULL);
	arg->msi_dev = pdev;
	if (desc->msi_attrib.is_msix) {
		arg->type = X86_IRQ_ALLOC_TYPE_MSIX;
	} else {
		arg->type = X86_IRQ_ALLOC_TYPE_MSI;
		arg->flags |= X86_IRQ_ALLOC_CONTIGUOUS_VECTORS;
	}

	return 0;
}

void pci_msi_set_desc(msi_alloc_info_t *arg, struct msi_desc *desc)
{
	arg->msi_hwirq = pci_msi_domain_calc_hwirq(arg->msi_dev, desc);
}

