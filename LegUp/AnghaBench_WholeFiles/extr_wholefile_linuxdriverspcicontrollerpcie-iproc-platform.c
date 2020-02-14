#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long long u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct pci_host_bridge {int dummy; } ;
struct pci_device_id {scalar_t__ vendor; scalar_t__ device; scalar_t__ subvendor; scalar_t__ subdevice; int class; int class_mask; } ;
struct pci_dev {scalar_t__ vendor; scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; int class; int /*<<< orphan*/  priv_flags; scalar_t__ no_d1d2; TYPE_3__* bus; scalar_t__ msix_cap; scalar_t__ msi_cap; scalar_t__ bridge_d3; int /*<<< orphan*/  subordinate; int /*<<< orphan*/  dev; } ;
struct pci_bus {int dummy; } ;
struct list_head {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  axi_offset; } ;
struct iproc_pcie {int type; int need_ob_cfg; int /*<<< orphan*/  map_irq; int /*<<< orphan*/ * phy; scalar_t__ need_ib_cfg; TYPE_1__ ob; int /*<<< orphan*/  base_addr; int /*<<< orphan*/  base; struct device* dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
typedef  enum iproc_pcie_type { ____Placeholder_iproc_pcie_type } iproc_pcie_type ;
struct TYPE_6__ {TYPE_2__* self; } ;
struct TYPE_5__ {unsigned int no_d1d2; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTTY ; 
 int EPROBE_DEFER ; 
#define  IPROC_PCIE_PAXC 129 
#define  IPROC_PCIE_PAXC_V2 128 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LIST_HEAD (struct list_head) ; 
 scalar_t__ PCI_ANY_ID ; 
 int PCI_CLASS_BRIDGE_CARDBUS ; 
 int /*<<< orphan*/  PCI_DEV_ADDED ; 
 int /*<<< orphan*/  PCI_DEV_DISCONNECTED ; 
 scalar_t__ PCI_MSIX_FLAGS ; 
 scalar_t__ PCI_MSI_FLAGS ; 
 int /*<<< orphan*/  PCI_MSI_FLAGS_ENABLE ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assign_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct pci_host_bridge* devm_pci_alloc_host_bridge (struct device*,int) ; 
 int /*<<< orphan*/  devm_pci_remap_cfgspace (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * devm_phy_get (struct device*,char*) ; 
 int iproc_pcie_remove (struct iproc_pcie*) ; 
 int iproc_pcie_setup (struct iproc_pcie*,struct list_head*) ; 
 int /*<<< orphan*/  iproc_pcie_shutdown (struct iproc_pcie*) ; 
 int of_address_to_resource (struct device_node*,int /*<<< orphan*/ ,struct resource*) ; 
 scalar_t__ of_device_get_match_data (struct device*) ; 
 int /*<<< orphan*/  of_irq_parse_and_map_pci ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_cardbus_resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  pci_free_resource_list (struct list_head*) ; 
 struct iproc_pcie* pci_host_bridge_priv (struct pci_host_bridge*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 struct iproc_pcie* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iproc_pcie*) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 struct list_head resources ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void pci_create_firmware_label_files(struct pci_dev *pdev)
{ return; }

__attribute__((used)) static inline void pci_remove_firmware_label_files(struct pci_dev *pdev)
{ return; }

__attribute__((used)) static inline void pci_wakeup_event(struct pci_dev *dev)
{
	/* Wait 100 ms before the system can be put into a sleep state. */
	pm_wakeup_event(&dev->dev, 100);
}

__attribute__((used)) static inline bool pci_has_subordinate(struct pci_dev *pci_dev)
{
	return !!(pci_dev->subordinate);
}

__attribute__((used)) static inline bool pci_power_manageable(struct pci_dev *pci_dev)
{
	/*
	 * Currently we allow normal PCI devices and PCI bridges transition
	 * into D3 if their bridge_d3 is set.
	 */
	return !pci_has_subordinate(pci_dev) || pci_dev->bridge_d3;
}

__attribute__((used)) static inline int pci_proc_attach_device(struct pci_dev *dev) { return 0; }

__attribute__((used)) static inline int pci_proc_detach_device(struct pci_dev *dev) { return 0; }

__attribute__((used)) static inline int pci_proc_detach_bus(struct pci_bus *bus) { return 0; }

__attribute__((used)) static inline void pci_create_legacy_files(struct pci_bus *bus) { return; }

__attribute__((used)) static inline void pci_remove_legacy_files(struct pci_bus *bus) { return; }

__attribute__((used)) static inline void pci_no_msi(void) { }

__attribute__((used)) static inline void pci_msi_set_enable(struct pci_dev *dev, int enable)
{
	u16 control;

	pci_read_config_word(dev, dev->msi_cap + PCI_MSI_FLAGS, &control);
	control &= ~PCI_MSI_FLAGS_ENABLE;
	if (enable)
		control |= PCI_MSI_FLAGS_ENABLE;
	pci_write_config_word(dev, dev->msi_cap + PCI_MSI_FLAGS, control);
}

__attribute__((used)) static inline void pci_msix_clear_and_set_ctrl(struct pci_dev *dev, u16 clear, u16 set)
{
	u16 ctrl;

	pci_read_config_word(dev, dev->msix_cap + PCI_MSIX_FLAGS, &ctrl);
	ctrl &= ~clear;
	ctrl |= set;
	pci_write_config_word(dev, dev->msix_cap + PCI_MSIX_FLAGS, ctrl);
}

__attribute__((used)) static inline int pci_no_d1d2(struct pci_dev *dev)
{
	unsigned int parent_dstates = 0;

	if (dev->bus->self)
		parent_dstates = dev->bus->self->no_d1d2;
	return (dev->no_d1d2 || parent_dstates);

}

__attribute__((used)) static inline const struct pci_device_id *
pci_match_one_device(const struct pci_device_id *id, const struct pci_dev *dev)
{
	if ((id->vendor == PCI_ANY_ID || id->vendor == dev->vendor) &&
	    (id->device == PCI_ANY_ID || id->device == dev->device) &&
	    (id->subvendor == PCI_ANY_ID || id->subvendor == dev->subsystem_vendor) &&
	    (id->subdevice == PCI_ANY_ID || id->subdevice == dev->subsystem_device) &&
	    !((id->class ^ dev->class) & id->class_mask))
		return id;
	return NULL;
}

__attribute__((used)) static inline int pci_dev_set_disconnected(struct pci_dev *dev, void *unused)
{
	set_bit(PCI_DEV_DISCONNECTED, &dev->priv_flags);
	return 0;
}

__attribute__((used)) static inline bool pci_dev_is_disconnected(const struct pci_dev *dev)
{
	return test_bit(PCI_DEV_DISCONNECTED, &dev->priv_flags);
}

__attribute__((used)) static inline void pci_dev_assign_added(struct pci_dev *dev, bool added)
{
	assign_bit(PCI_DEV_ADDED, &dev->priv_flags, added);
}

__attribute__((used)) static inline bool pci_dev_is_added(const struct pci_dev *dev)
{
	return test_bit(PCI_DEV_ADDED, &dev->priv_flags);
}

__attribute__((used)) static inline void pci_restore_ats_state(struct pci_dev *dev)
{
}

__attribute__((used)) static inline int pci_iov_init(struct pci_dev *dev)
{
	return -ENODEV;
}

__attribute__((used)) static inline void pci_iov_release(struct pci_dev *dev)

{
}

__attribute__((used)) static inline void pci_iov_remove(struct pci_dev *dev)
{
}

__attribute__((used)) static inline void pci_restore_iov_state(struct pci_dev *dev)
{
}

__attribute__((used)) static inline int pci_iov_bus_range(struct pci_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline resource_size_t pci_resource_alignment(struct pci_dev *dev,
						     struct resource *res)
{
#ifdef CONFIG_PCI_IOV
	int resno = res - dev->resource;

	if (resno >= PCI_IOV_RESOURCES && resno <= PCI_IOV_RESOURCE_END)
		return pci_sriov_resource_alignment(dev, resno);
#endif
	if (dev->class >> 8 == PCI_CLASS_BRIDGE_CARDBUS)
		return pci_cardbus_resource_alignment(res);
	return resource_alignment(res);
}

__attribute__((used)) static inline int pci_dev_specific_acs_enabled(struct pci_dev *dev,
					       u16 acs_flags)
{
	return -ENOTTY;
}

__attribute__((used)) static inline int pci_dev_specific_enable_acs(struct pci_dev *dev)
{
	return -ENOTTY;
}

__attribute__((used)) static inline int pci_dev_specific_disable_acs_redir(struct pci_dev *dev)
{
	return -ENOTTY;
}

__attribute__((used)) static inline void pcie_aspm_init_link_state(struct pci_dev *pdev) { }

__attribute__((used)) static inline void pcie_aspm_exit_link_state(struct pci_dev *pdev) { }

__attribute__((used)) static inline void pcie_aspm_pm_state_change(struct pci_dev *pdev) { }

__attribute__((used)) static inline void pcie_aspm_powersave_config_link(struct pci_dev *pdev) { }

__attribute__((used)) static inline void pcie_aspm_create_sysfs_dev_files(struct pci_dev *pdev) { }

__attribute__((used)) static inline void pcie_aspm_remove_sysfs_dev_files(struct pci_dev *pdev) { }

__attribute__((used)) static inline void pci_ptm_init(struct pci_dev *dev) { }

__attribute__((used)) static inline int pci_dev_specific_reset(struct pci_dev *dev, int probe)
{
	return -ENOTTY;
}

__attribute__((used)) static inline u64 pci_rebar_size_to_bytes(int size)
{
	return 1ULL << (size + 20);
}

__attribute__((used)) static inline int
of_pci_parse_bus_range(struct device_node *node, struct resource *res)
{
	return -EINVAL;
}

__attribute__((used)) static inline int
of_get_pci_domain_nr(struct device_node *node)
{
	return -1;
}

__attribute__((used)) static inline int
of_pci_get_max_link_speed(struct device_node *node)
{
	return -EINVAL;
}

__attribute__((used)) static inline int devm_of_pci_get_host_bridge_resources(struct device *dev,
			unsigned char busno, unsigned char bus_max,
			struct list_head *resources, resource_size_t *io_base)
{
	return -EINVAL;
}

__attribute__((used)) static inline void pci_no_aer(void) { }

__attribute__((used)) static inline int pci_aer_init(struct pci_dev *d) { return -ENODEV; }

__attribute__((used)) static inline void pci_aer_exit(struct pci_dev *d) { }

__attribute__((used)) static inline void pci_aer_clear_fatal_status(struct pci_dev *dev) { }

__attribute__((used)) static inline void pci_aer_clear_device_status(struct pci_dev *dev) { }

__attribute__((used)) static inline int iproc_msi_init(struct iproc_pcie *pcie,
				 struct device_node *node)
{
	return -ENODEV;
}

__attribute__((used)) static inline void iproc_msi_exit(struct iproc_pcie *pcie)
{
}

__attribute__((used)) static int iproc_pcie_pltfm_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct iproc_pcie *pcie;
	struct device_node *np = dev->of_node;
	struct resource reg;
	resource_size_t iobase = 0;
	LIST_HEAD(resources);
	struct pci_host_bridge *bridge;
	int ret;

	bridge = devm_pci_alloc_host_bridge(dev, sizeof(*pcie));
	if (!bridge)
		return -ENOMEM;

	pcie = pci_host_bridge_priv(bridge);

	pcie->dev = dev;
	pcie->type = (enum iproc_pcie_type) of_device_get_match_data(dev);

	ret = of_address_to_resource(np, 0, &reg);
	if (ret < 0) {
		dev_err(dev, "unable to obtain controller resources\n");
		return ret;
	}

	pcie->base = devm_pci_remap_cfgspace(dev, reg.start,
					     resource_size(&reg));
	if (!pcie->base) {
		dev_err(dev, "unable to map controller registers\n");
		return -ENOMEM;
	}
	pcie->base_addr = reg.start;

	if (of_property_read_bool(np, "brcm,pcie-ob")) {
		u32 val;

		ret = of_property_read_u32(np, "brcm,pcie-ob-axi-offset",
					   &val);
		if (ret) {
			dev_err(dev,
				"missing brcm,pcie-ob-axi-offset property\n");
			return ret;
		}
		pcie->ob.axi_offset = val;
		pcie->need_ob_cfg = true;
	}

	/*
	 * DT nodes are not used by all platforms that use the iProc PCIe
	 * core driver. For platforms that require explict inbound mapping
	 * configuration, "dma-ranges" would have been present in DT
	 */
	pcie->need_ib_cfg = of_property_read_bool(np, "dma-ranges");

	/* PHY use is optional */
	pcie->phy = devm_phy_get(dev, "pcie-phy");
	if (IS_ERR(pcie->phy)) {
		if (PTR_ERR(pcie->phy) == -EPROBE_DEFER)
			return -EPROBE_DEFER;
		pcie->phy = NULL;
	}

	ret = devm_of_pci_get_host_bridge_resources(dev, 0, 0xff, &resources,
						    &iobase);
	if (ret) {
		dev_err(dev, "unable to get PCI host bridge resources\n");
		return ret;
	}

	/* PAXC doesn't support legacy IRQs, skip mapping */
	switch (pcie->type) {
	case IPROC_PCIE_PAXC:
	case IPROC_PCIE_PAXC_V2:
		break;
	default:
		pcie->map_irq = of_irq_parse_and_map_pci;
	}

	ret = iproc_pcie_setup(pcie, &resources);
	if (ret) {
		dev_err(dev, "PCIe controller setup failed\n");
		pci_free_resource_list(&resources);
		return ret;
	}

	platform_set_drvdata(pdev, pcie);
	return 0;
}

__attribute__((used)) static int iproc_pcie_pltfm_remove(struct platform_device *pdev)
{
	struct iproc_pcie *pcie = platform_get_drvdata(pdev);

	return iproc_pcie_remove(pcie);
}

__attribute__((used)) static void iproc_pcie_pltfm_shutdown(struct platform_device *pdev)
{
	struct iproc_pcie *pcie = platform_get_drvdata(pdev);

	iproc_pcie_shutdown(pcie);
}

