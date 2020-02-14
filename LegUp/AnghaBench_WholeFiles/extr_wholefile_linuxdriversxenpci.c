#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  unsigned long long u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct resource {int dummy; } ;
struct physdev_pci_device_add {int is_extfn; int /*<<< orphan*/  devfn; int /*<<< orphan*/  bus; scalar_t__ seg; int /*<<< orphan*/  flags; } ;
struct physdev_pci_device {int is_extfn; int /*<<< orphan*/  devfn; int /*<<< orphan*/  bus; scalar_t__ seg; int /*<<< orphan*/  flags; } ;
struct physdev_manage_pci_ext {int is_extfn; int /*<<< orphan*/  devfn; int /*<<< orphan*/  bus; scalar_t__ seg; int /*<<< orphan*/  flags; } ;
struct physdev_manage_pci {int is_extfn; int /*<<< orphan*/  devfn; int /*<<< orphan*/  bus; scalar_t__ seg; int /*<<< orphan*/  flags; } ;
struct pci_device_id {scalar_t__ vendor; scalar_t__ device; scalar_t__ subvendor; scalar_t__ subdevice; int class; int class_mask; } ;
struct pci_dev {scalar_t__ vendor; scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; int class; int /*<<< orphan*/  devfn; TYPE_2__* bus; int /*<<< orphan*/  priv_flags; scalar_t__ no_d1d2; scalar_t__ msix_cap; scalar_t__ msi_cap; scalar_t__ bridge_d3; int /*<<< orphan*/  subordinate; int /*<<< orphan*/  dev; } ;
struct pci_bus {int dummy; } ;
struct notifier_block {int dummy; } ;
struct list_head {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
struct TYPE_5__ {int /*<<< orphan*/  number; TYPE_1__* self; } ;
struct TYPE_4__ {unsigned int no_d1d2; } ;

/* Variables and functions */
#define  BUS_NOTIFY_ADD_DEVICE 129 
#define  BUS_NOTIFY_DEL_DEVICE 128 
 int EINVAL ; 
 int ENODEV ; 
 int ENOSYS ; 
 int ENOTTY ; 
 int HYPERVISOR_physdev_op (int /*<<< orphan*/ ,struct physdev_pci_device_add*) ; 
 int NOTIFY_DONE ; 
 int NOTIFY_OK ; 
 scalar_t__ PCI_ANY_ID ; 
 int PCI_CLASS_BRIDGE_CARDBUS ; 
 int /*<<< orphan*/  PCI_DEV_ADDED ; 
 int /*<<< orphan*/  PCI_DEV_DISCONNECTED ; 
 scalar_t__ PCI_MSIX_FLAGS ; 
 scalar_t__ PCI_MSI_FLAGS ; 
 int /*<<< orphan*/  PCI_MSI_FLAGS_ENABLE ; 
 scalar_t__ PCI_SLOT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PHYSDEVOP_manage_pci_add ; 
 int /*<<< orphan*/  PHYSDEVOP_manage_pci_add_ext ; 
 int /*<<< orphan*/  PHYSDEVOP_manage_pci_remove ; 
 int /*<<< orphan*/  PHYSDEVOP_pci_device_add ; 
 int /*<<< orphan*/  PHYSDEVOP_pci_device_remove ; 
 int /*<<< orphan*/  XEN_PCI_DEV_EXTFN ; 
 int /*<<< orphan*/  assign_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,char*) ; 
 scalar_t__ pci_ari_enabled (TYPE_2__*) ; 
 int /*<<< orphan*/  pci_cardbus_resource_alignment (struct resource*) ; 
 scalar_t__ pci_domain_nr (TYPE_2__*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,scalar_t__,int /*<<< orphan*/ *) ; 
 int pci_seg_supported ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 

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

__attribute__((used)) static int xen_add_device(struct device *dev)
{
	int r;
	struct pci_dev *pci_dev = to_pci_dev(dev);
#ifdef CONFIG_PCI_IOV
	struct pci_dev *physfn = pci_dev->physfn;
#endif

	if (pci_seg_supported) {
		struct {
			struct physdev_pci_device_add add;
			uint32_t pxm;
		} add_ext = {
			.add.seg = pci_domain_nr(pci_dev->bus),
			.add.bus = pci_dev->bus->number,
			.add.devfn = pci_dev->devfn
		};
		struct physdev_pci_device_add *add = &add_ext.add;

#ifdef CONFIG_ACPI
		acpi_handle handle;
#endif

#ifdef CONFIG_PCI_IOV
		if (pci_dev->is_virtfn) {
			add->flags = XEN_PCI_DEV_VIRTFN;
			add->physfn.bus = physfn->bus->number;
			add->physfn.devfn = physfn->devfn;
		} else
#endif
		if (pci_ari_enabled(pci_dev->bus) && PCI_SLOT(pci_dev->devfn))
			add->flags = XEN_PCI_DEV_EXTFN;

#ifdef CONFIG_ACPI
		handle = ACPI_HANDLE(&pci_dev->dev);
#ifdef CONFIG_PCI_IOV
		if (!handle && pci_dev->is_virtfn)
			handle = ACPI_HANDLE(physfn->bus->bridge);
#endif
		if (!handle) {
			/*
			 * This device was not listed in the ACPI name space at
			 * all. Try to get acpi handle of parent pci bus.
			 */
			struct pci_bus *pbus;
			for (pbus = pci_dev->bus; pbus; pbus = pbus->parent) {
				handle = acpi_pci_get_bridge_handle(pbus);
				if (handle)
					break;
			}
		}
		if (handle) {
			acpi_status status;

			do {
				unsigned long long pxm;

				status = acpi_evaluate_integer(handle, "_PXM",
							       NULL, &pxm);
				if (ACPI_SUCCESS(status)) {
					add->optarr[0] = pxm;
					add->flags |= XEN_PCI_DEV_PXM;
					break;
				}
				status = acpi_get_parent(handle, &handle);
			} while (ACPI_SUCCESS(status));
		}
#endif /* CONFIG_ACPI */

		r = HYPERVISOR_physdev_op(PHYSDEVOP_pci_device_add, add);
		if (r != -ENOSYS)
			return r;
		pci_seg_supported = false;
	}

	if (pci_domain_nr(pci_dev->bus))
		r = -ENOSYS;
#ifdef CONFIG_PCI_IOV
	else if (pci_dev->is_virtfn) {
		struct physdev_manage_pci_ext manage_pci_ext = {
			.bus		= pci_dev->bus->number,
			.devfn		= pci_dev->devfn,
			.is_virtfn 	= 1,
			.physfn.bus	= physfn->bus->number,
			.physfn.devfn	= physfn->devfn,
		};

		r = HYPERVISOR_physdev_op(PHYSDEVOP_manage_pci_add_ext,
			&manage_pci_ext);
	}
#endif
	else if (pci_ari_enabled(pci_dev->bus) && PCI_SLOT(pci_dev->devfn)) {
		struct physdev_manage_pci_ext manage_pci_ext = {
			.bus		= pci_dev->bus->number,
			.devfn		= pci_dev->devfn,
			.is_extfn	= 1,
		};

		r = HYPERVISOR_physdev_op(PHYSDEVOP_manage_pci_add_ext,
			&manage_pci_ext);
	} else {
		struct physdev_manage_pci manage_pci = {
			.bus	= pci_dev->bus->number,
			.devfn	= pci_dev->devfn,
		};

		r = HYPERVISOR_physdev_op(PHYSDEVOP_manage_pci_add,
			&manage_pci);
	}

	return r;
}

__attribute__((used)) static int xen_remove_device(struct device *dev)
{
	int r;
	struct pci_dev *pci_dev = to_pci_dev(dev);

	if (pci_seg_supported) {
		struct physdev_pci_device device = {
			.seg = pci_domain_nr(pci_dev->bus),
			.bus = pci_dev->bus->number,
			.devfn = pci_dev->devfn
		};

		r = HYPERVISOR_physdev_op(PHYSDEVOP_pci_device_remove,
					  &device);
	} else if (pci_domain_nr(pci_dev->bus))
		r = -ENOSYS;
	else {
		struct physdev_manage_pci manage_pci = {
			.bus = pci_dev->bus->number,
			.devfn = pci_dev->devfn
		};

		r = HYPERVISOR_physdev_op(PHYSDEVOP_manage_pci_remove,
					  &manage_pci);
	}

	return r;
}

__attribute__((used)) static int xen_pci_notifier(struct notifier_block *nb,
			    unsigned long action, void *data)
{
	struct device *dev = data;
	int r = 0;

	switch (action) {
	case BUS_NOTIFY_ADD_DEVICE:
		r = xen_add_device(dev);
		break;
	case BUS_NOTIFY_DEL_DEVICE:
		r = xen_remove_device(dev);
		break;
	default:
		return NOTIFY_DONE;
	}
	if (r)
		dev_err(dev, "Failed to %s - passthrough or MSI/MSI-X might fail!\n",
			action == BUS_NOTIFY_ADD_DEVICE ? "add" :
			(action == BUS_NOTIFY_DEL_DEVICE ? "delete" : "?"));
	return NOTIFY_OK;
}

