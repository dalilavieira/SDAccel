#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  int u32 ;
struct xgene_msi_group {int msi_grp; int gic_irq; struct xgene_msi* msi; } ;
struct xgene_msi {unsigned long num_cpus; struct xgene_msi_group* msi_groups; int /*<<< orphan*/  node; scalar_t__ msi_addr; scalar_t__ msi_regs; struct xgene_msi_group* bitmap; scalar_t__ inner_domain; int /*<<< orphan*/  bitmap_lock; scalar_t__ msi_domain; } ;
struct resource {scalar_t__ start; } ;
struct TYPE_4__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct msi_msg {int data; int /*<<< orphan*/  address_lo; int /*<<< orphan*/  address_hi; } ;
struct irq_domain {struct xgene_msi* host_data; } ;
struct irq_desc {int dummy; } ;
struct irq_data {unsigned long hwirq; } ;
struct irq_chip {int dummy; } ;
struct cpumask {int dummy; } ;
typedef  int /*<<< orphan*/  cpumask_var_t ;

/* Variables and functions */
 int BITS_TO_LONGS (int) ; 
 int CPUHP_AP_ONLINE_DYN ; 
 int CPUHP_PCI_XGENE_DEAD ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IDX_PER_GROUP ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 unsigned long IRQS_PER_IDX ; 
 int IRQ_SET_MASK_OK ; 
 int IRQ_SET_MASK_OK_DONE ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ MSI_INT0 ; 
 scalar_t__ MSI_IR0 ; 
 unsigned long NR_HW_IRQS ; 
 int NR_MSI_VEC ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 scalar_t__ alloc_cpumask_var (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_clear (struct xgene_msi_group*,int,unsigned long) ; 
 int bitmap_find_next_zero_area (struct xgene_msi_group*,int,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_set (struct xgene_msi_group*,int,unsigned long) ; 
 int /*<<< orphan*/  chained_irq_enter (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  chained_irq_exit (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  cpuhp_remove_state (int) ; 
 int cpuhp_setup_state (int,char*,int (*) (unsigned int),...) ; 
 int /*<<< orphan*/  cpumask_clear (int /*<<< orphan*/ ) ; 
 int cpumask_first (struct cpumask const*) ; 
 int /*<<< orphan*/  cpumask_set_cpu (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 int ffs (int) ; 
 int /*<<< orphan*/  free_cpumask_var (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int /*<<< orphan*/  handle_simple_irq ; 
 struct xgene_msi* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 struct xgene_msi_group* irq_desc_get_handler_data (struct irq_desc*) ; 
 scalar_t__ irq_domain_add_linear (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,struct xgene_msi*) ; 
 int /*<<< orphan*/  irq_domain_free_irqs_parent (struct irq_domain*,unsigned int,unsigned int) ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_domain_remove (scalar_t__) ; 
 int /*<<< orphan*/  irq_domain_set_info (struct irq_domain*,unsigned int,int,int /*<<< orphan*/ *,struct xgene_msi*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned int irq_find_mapping (scalar_t__,int) ; 
 int irq_set_affinity (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chained_handler (int,void (*) (struct irq_desc*)) ; 
 int /*<<< orphan*/  irq_set_chained_handler_and_data (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int irq_set_handler_data (int,struct xgene_msi_group*) ; 
 struct xgene_msi_group* kcalloc (unsigned long,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct xgene_msi_group*) ; 
 struct xgene_msi_group* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lower_32_bits (scalar_t__) ; 
 int /*<<< orphan*/  msi_domain_ops ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned long num_possible_cpus () ; 
 int /*<<< orphan*/  of_node_to_fwnode (int /*<<< orphan*/ ) ; 
 scalar_t__ pci_msi_create_irq_domain (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__) ; 
 int pci_xgene_online ; 
 struct xgene_msi* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xgene_msi*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  upper_32_bits (scalar_t__) ; 
 int /*<<< orphan*/  xgene_msi_bottom_irq_chip ; 
 struct xgene_msi xgene_msi_ctrl ; 
 int /*<<< orphan*/  xgene_msi_domain_info ; 

__attribute__((used)) static u32 xgene_msi_ir_read(struct xgene_msi *msi,
				    u32 msi_grp, u32 msir_idx)
{
	return readl_relaxed(msi->msi_regs + MSI_IR0 +
			      (msi_grp << 19) + (msir_idx << 16));
}

__attribute__((used)) static u32 xgene_msi_int_read(struct xgene_msi *msi, u32 msi_grp)
{
	return readl_relaxed(msi->msi_regs + MSI_INT0 + (msi_grp << 16));
}

__attribute__((used)) static u32 hwirq_to_reg_set(unsigned long hwirq)
{
	return (hwirq / (NR_HW_IRQS * IRQS_PER_IDX));
}

__attribute__((used)) static u32 hwirq_to_group(unsigned long hwirq)
{
	return (hwirq % NR_HW_IRQS);
}

__attribute__((used)) static u32 hwirq_to_msi_data(unsigned long hwirq)
{
	return ((hwirq / NR_HW_IRQS) % IRQS_PER_IDX);
}

__attribute__((used)) static void xgene_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
	struct xgene_msi *msi = irq_data_get_irq_chip_data(data);
	u32 reg_set = hwirq_to_reg_set(data->hwirq);
	u32 group = hwirq_to_group(data->hwirq);
	u64 target_addr = msi->msi_addr + (((8 * group) + reg_set) << 16);

	msg->address_hi = upper_32_bits(target_addr);
	msg->address_lo = lower_32_bits(target_addr);
	msg->data = hwirq_to_msi_data(data->hwirq);
}

__attribute__((used)) static int hwirq_to_cpu(unsigned long hwirq)
{
	return (hwirq % xgene_msi_ctrl.num_cpus);
}

__attribute__((used)) static unsigned long hwirq_to_canonical_hwirq(unsigned long hwirq)
{
	return (hwirq - hwirq_to_cpu(hwirq));
}

__attribute__((used)) static int xgene_msi_set_affinity(struct irq_data *irqdata,
				  const struct cpumask *mask, bool force)
{
	int target_cpu = cpumask_first(mask);
	int curr_cpu;

	curr_cpu = hwirq_to_cpu(irqdata->hwirq);
	if (curr_cpu == target_cpu)
		return IRQ_SET_MASK_OK_DONE;

	/* Update MSI number to target the new CPU */
	irqdata->hwirq = hwirq_to_canonical_hwirq(irqdata->hwirq) + target_cpu;

	return IRQ_SET_MASK_OK;
}

__attribute__((used)) static int xgene_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
				  unsigned int nr_irqs, void *args)
{
	struct xgene_msi *msi = domain->host_data;
	int msi_irq;

	mutex_lock(&msi->bitmap_lock);

	msi_irq = bitmap_find_next_zero_area(msi->bitmap, NR_MSI_VEC, 0,
					     msi->num_cpus, 0);
	if (msi_irq < NR_MSI_VEC)
		bitmap_set(msi->bitmap, msi_irq, msi->num_cpus);
	else
		msi_irq = -ENOSPC;

	mutex_unlock(&msi->bitmap_lock);

	if (msi_irq < 0)
		return msi_irq;

	irq_domain_set_info(domain, virq, msi_irq,
			    &xgene_msi_bottom_irq_chip, domain->host_data,
			    handle_simple_irq, NULL, NULL);

	return 0;
}

__attribute__((used)) static void xgene_irq_domain_free(struct irq_domain *domain,
				  unsigned int virq, unsigned int nr_irqs)
{
	struct irq_data *d = irq_domain_get_irq_data(domain, virq);
	struct xgene_msi *msi = irq_data_get_irq_chip_data(d);
	u32 hwirq;

	mutex_lock(&msi->bitmap_lock);

	hwirq = hwirq_to_canonical_hwirq(d->hwirq);
	bitmap_clear(msi->bitmap, hwirq, msi->num_cpus);

	mutex_unlock(&msi->bitmap_lock);

	irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}

__attribute__((used)) static int xgene_allocate_domains(struct xgene_msi *msi)
{
	msi->inner_domain = irq_domain_add_linear(NULL, NR_MSI_VEC,
						  &msi_domain_ops, msi);
	if (!msi->inner_domain)
		return -ENOMEM;

	msi->msi_domain = pci_msi_create_irq_domain(of_node_to_fwnode(msi->node),
						    &xgene_msi_domain_info,
						    msi->inner_domain);

	if (!msi->msi_domain) {
		irq_domain_remove(msi->inner_domain);
		return -ENOMEM;
	}

	return 0;
}

__attribute__((used)) static void xgene_free_domains(struct xgene_msi *msi)
{
	if (msi->msi_domain)
		irq_domain_remove(msi->msi_domain);
	if (msi->inner_domain)
		irq_domain_remove(msi->inner_domain);
}

__attribute__((used)) static int xgene_msi_init_allocator(struct xgene_msi *xgene_msi)
{
	int size = BITS_TO_LONGS(NR_MSI_VEC) * sizeof(long);

	xgene_msi->bitmap = kzalloc(size, GFP_KERNEL);
	if (!xgene_msi->bitmap)
		return -ENOMEM;

	mutex_init(&xgene_msi->bitmap_lock);

	xgene_msi->msi_groups = kcalloc(NR_HW_IRQS,
					sizeof(struct xgene_msi_group),
					GFP_KERNEL);
	if (!xgene_msi->msi_groups)
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static void xgene_msi_isr(struct irq_desc *desc)
{
	struct irq_chip *chip = irq_desc_get_chip(desc);
	struct xgene_msi_group *msi_groups;
	struct xgene_msi *xgene_msi;
	unsigned int virq;
	int msir_index, msir_val, hw_irq;
	u32 intr_index, grp_select, msi_grp;

	chained_irq_enter(chip, desc);

	msi_groups = irq_desc_get_handler_data(desc);
	xgene_msi = msi_groups->msi;
	msi_grp = msi_groups->msi_grp;

	/*
	 * MSIINTn (n is 0..F) indicates if there is a pending MSI interrupt
	 * If bit x of this register is set (x is 0..7), one or more interupts
	 * corresponding to MSInIRx is set.
	 */
	grp_select = xgene_msi_int_read(xgene_msi, msi_grp);
	while (grp_select) {
		msir_index = ffs(grp_select) - 1;
		/*
		 * Calculate MSInIRx address to read to check for interrupts
		 * (refer to termination address and data assignment
		 * described in xgene_compose_msi_msg() )
		 */
		msir_val = xgene_msi_ir_read(xgene_msi, msi_grp, msir_index);
		while (msir_val) {
			intr_index = ffs(msir_val) - 1;
			/*
			 * Calculate MSI vector number (refer to the termination
			 * address and data assignment described in
			 * xgene_compose_msi_msg function)
			 */
			hw_irq = (((msir_index * IRQS_PER_IDX) + intr_index) *
				 NR_HW_IRQS) + msi_grp;
			/*
			 * As we have multiple hw_irq that maps to single MSI,
			 * always look up the virq using the hw_irq as seen from
			 * CPU0
			 */
			hw_irq = hwirq_to_canonical_hwirq(hw_irq);
			virq = irq_find_mapping(xgene_msi->inner_domain, hw_irq);
			WARN_ON(!virq);
			if (virq != 0)
				generic_handle_irq(virq);
			msir_val &= ~(1 << intr_index);
		}
		grp_select &= ~(1 << msir_index);

		if (!grp_select) {
			/*
			 * We handled all interrupts happened in this group,
			 * resample this group MSI_INTx register in case
			 * something else has been made pending in the meantime
			 */
			grp_select = xgene_msi_int_read(xgene_msi, msi_grp);
		}
	}

	chained_irq_exit(chip, desc);
}

__attribute__((used)) static int xgene_msi_remove(struct platform_device *pdev)
{
	struct xgene_msi *msi = platform_get_drvdata(pdev);

	if (pci_xgene_online)
		cpuhp_remove_state(pci_xgene_online);
	cpuhp_remove_state(CPUHP_PCI_XGENE_DEAD);

	kfree(msi->msi_groups);

	kfree(msi->bitmap);
	msi->bitmap = NULL;

	xgene_free_domains(msi);

	return 0;
}

__attribute__((used)) static int xgene_msi_hwirq_alloc(unsigned int cpu)
{
	struct xgene_msi *msi = &xgene_msi_ctrl;
	struct xgene_msi_group *msi_group;
	cpumask_var_t mask;
	int i;
	int err;

	for (i = cpu; i < NR_HW_IRQS; i += msi->num_cpus) {
		msi_group = &msi->msi_groups[i];
		if (!msi_group->gic_irq)
			continue;

		irq_set_chained_handler(msi_group->gic_irq,
					xgene_msi_isr);
		err = irq_set_handler_data(msi_group->gic_irq, msi_group);
		if (err) {
			pr_err("failed to register GIC IRQ handler\n");
			return -EINVAL;
		}
		/*
		 * Statically allocate MSI GIC IRQs to each CPU core.
		 * With 8-core X-Gene v1, 2 MSI GIC IRQs are allocated
		 * to each core.
		 */
		if (alloc_cpumask_var(&mask, GFP_KERNEL)) {
			cpumask_clear(mask);
			cpumask_set_cpu(cpu, mask);
			err = irq_set_affinity(msi_group->gic_irq, mask);
			if (err)
				pr_err("failed to set affinity for GIC IRQ");
			free_cpumask_var(mask);
		} else {
			pr_err("failed to alloc CPU mask for affinity\n");
			err = -EINVAL;
		}

		if (err) {
			irq_set_chained_handler_and_data(msi_group->gic_irq,
							 NULL, NULL);
			return err;
		}
	}

	return 0;
}

__attribute__((used)) static int xgene_msi_hwirq_free(unsigned int cpu)
{
	struct xgene_msi *msi = &xgene_msi_ctrl;
	struct xgene_msi_group *msi_group;
	int i;

	for (i = cpu; i < NR_HW_IRQS; i += msi->num_cpus) {
		msi_group = &msi->msi_groups[i];
		if (!msi_group->gic_irq)
			continue;

		irq_set_chained_handler_and_data(msi_group->gic_irq, NULL,
						 NULL);
	}
	return 0;
}

__attribute__((used)) static int xgene_msi_probe(struct platform_device *pdev)
{
	struct resource *res;
	int rc, irq_index;
	struct xgene_msi *xgene_msi;
	int virt_msir;
	u32 msi_val, msi_idx;

	xgene_msi = &xgene_msi_ctrl;

	platform_set_drvdata(pdev, xgene_msi);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	xgene_msi->msi_regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(xgene_msi->msi_regs)) {
		dev_err(&pdev->dev, "no reg space\n");
		rc = PTR_ERR(xgene_msi->msi_regs);
		goto error;
	}
	xgene_msi->msi_addr = res->start;
	xgene_msi->node = pdev->dev.of_node;
	xgene_msi->num_cpus = num_possible_cpus();

	rc = xgene_msi_init_allocator(xgene_msi);
	if (rc) {
		dev_err(&pdev->dev, "Error allocating MSI bitmap\n");
		goto error;
	}

	rc = xgene_allocate_domains(xgene_msi);
	if (rc) {
		dev_err(&pdev->dev, "Failed to allocate MSI domain\n");
		goto error;
	}

	for (irq_index = 0; irq_index < NR_HW_IRQS; irq_index++) {
		virt_msir = platform_get_irq(pdev, irq_index);
		if (virt_msir < 0) {
			dev_err(&pdev->dev, "Cannot translate IRQ index %d\n",
				irq_index);
			rc = virt_msir;
			goto error;
		}
		xgene_msi->msi_groups[irq_index].gic_irq = virt_msir;
		xgene_msi->msi_groups[irq_index].msi_grp = irq_index;
		xgene_msi->msi_groups[irq_index].msi = xgene_msi;
	}

	/*
	 * MSInIRx registers are read-to-clear; before registering
	 * interrupt handlers, read all of them to clear spurious
	 * interrupts that may occur before the driver is probed.
	 */
	for (irq_index = 0; irq_index < NR_HW_IRQS; irq_index++) {
		for (msi_idx = 0; msi_idx < IDX_PER_GROUP; msi_idx++)
			msi_val = xgene_msi_ir_read(xgene_msi, irq_index,
						    msi_idx);
		/* Read MSIINTn to confirm */
		msi_val = xgene_msi_int_read(xgene_msi, irq_index);
		if (msi_val) {
			dev_err(&pdev->dev, "Failed to clear spurious IRQ\n");
			rc = -EINVAL;
			goto error;
		}
	}

	rc = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "pci/xgene:online",
			       xgene_msi_hwirq_alloc, NULL);
	if (rc < 0)
		goto err_cpuhp;
	pci_xgene_online = rc;
	rc = cpuhp_setup_state(CPUHP_PCI_XGENE_DEAD, "pci/xgene:dead", NULL,
			       xgene_msi_hwirq_free);
	if (rc)
		goto err_cpuhp;

	dev_info(&pdev->dev, "APM X-Gene PCIe MSI driver loaded\n");

	return 0;

err_cpuhp:
	dev_err(&pdev->dev, "failed to add CPU MSI notifier\n");
error:
	xgene_msi_remove(pdev);
	return rc;
}

