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
typedef  unsigned long long u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct resource {int dummy; } ;
struct pcie_port_service_driver {int /*<<< orphan*/  (* error_resume ) (int /*<<< orphan*/ ) ;} ;
struct pcie_device {void* priv_data; int /*<<< orphan*/  port; } ;
struct pci_device_id {scalar_t__ vendor; scalar_t__ device; scalar_t__ subvendor; scalar_t__ subdevice; int class; int class_mask; } ;
struct pci_dev {scalar_t__ vendor; scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; int class; int __aer_firmware_first; int /*<<< orphan*/  dev; scalar_t__ __aer_firmware_first_valid; int /*<<< orphan*/  priv_flags; scalar_t__ no_d1d2; TYPE_2__* bus; scalar_t__ msix_cap; scalar_t__ msi_cap; scalar_t__ bridge_d3; int /*<<< orphan*/  subordinate; } ;
struct pci_bus {int dummy; } ;
struct list_head {int dummy; } ;
struct device_node {int dummy; } ;
struct device {scalar_t__ driver; int /*<<< orphan*/ * bus; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
typedef  int /*<<< orphan*/  pci_ers_result_t ;
typedef  enum pci_channel_state { ____Placeholder_pci_channel_state } pci_channel_state ;
struct TYPE_4__ {TYPE_1__* self; } ;
struct TYPE_3__ {unsigned int no_d1d2; } ;

/* Variables and functions */
 int DPM_FLAG_LEAVE_SUSPENDED ; 
 int DPM_FLAG_SMART_SUSPEND ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOTTY ; 
 scalar_t__ PCI_ANY_ID ; 
 int PCI_CLASS_BRIDGE_CARDBUS ; 
 int /*<<< orphan*/  PCI_DEV_ADDED ; 
 int /*<<< orphan*/  PCI_DEV_DISCONNECTED ; 
 int /*<<< orphan*/  PCI_ERS_RESULT_CAN_RECOVER ; 
 int /*<<< orphan*/  PCI_ERS_RESULT_RECOVERED ; 
 scalar_t__ PCI_EXP_TYPE_DOWNSTREAM ; 
 scalar_t__ PCI_EXP_TYPE_ROOT_PORT ; 
 scalar_t__ PCI_EXP_TYPE_UPSTREAM ; 
 scalar_t__ PCI_MSIX_FLAGS ; 
 scalar_t__ PCI_MSI_FLAGS ; 
 int /*<<< orphan*/  PCI_MSI_FLAGS_ENABLE ; 
 int /*<<< orphan*/  assign_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_pm_set_driver_flags (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  device_for_each_child (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int (*) (struct device*,void*)) ; 
 scalar_t__ pci_bridge_d3_possible (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_cardbus_resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  pci_is_pcie (struct pci_dev*) ; 
 scalar_t__ pci_pcie_type (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_save_state (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcie_port_bus_type ; 
 int pcie_port_device_register (struct pci_dev*) ; 
 int /*<<< orphan*/  pcie_port_device_remove (struct pci_dev*) ; 
 int /*<<< orphan*/  pm_runtime_allow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_dont_use_autosuspend (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_forbid (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct pcie_device* to_pcie_device (struct device*) ; 
 struct pcie_port_service_driver* to_service_driver (scalar_t__) ; 

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

__attribute__((used)) static inline void set_service_data(struct pcie_device *dev, void *data)
{
	dev->priv_data = data;
}

__attribute__((used)) static inline void *get_service_data(struct pcie_device *dev)
{
	return dev->priv_data;
}

__attribute__((used)) static inline void pcie_pme_disable_msi(void) {}

__attribute__((used)) static inline bool pcie_pme_no_msi(void) { return false; }

__attribute__((used)) static inline void pcie_pme_interrupt_enable(struct pci_dev *dev, bool en) {}

__attribute__((used)) static inline int pcie_aer_get_firmware_first(struct pci_dev *pci_dev)
{
	if (pci_dev->__aer_firmware_first_valid)
		return pci_dev->__aer_firmware_first;
	return 0;
}

__attribute__((used)) static int pcie_portdrv_probe(struct pci_dev *dev,
					const struct pci_device_id *id)
{
	int status;

	if (!pci_is_pcie(dev) ||
	    ((pci_pcie_type(dev) != PCI_EXP_TYPE_ROOT_PORT) &&
	     (pci_pcie_type(dev) != PCI_EXP_TYPE_UPSTREAM) &&
	     (pci_pcie_type(dev) != PCI_EXP_TYPE_DOWNSTREAM)))
		return -ENODEV;

	status = pcie_port_device_register(dev);
	if (status)
		return status;

	pci_save_state(dev);

	dev_pm_set_driver_flags(&dev->dev, DPM_FLAG_SMART_SUSPEND |
					   DPM_FLAG_LEAVE_SUSPENDED);

	if (pci_bridge_d3_possible(dev)) {
		/*
		 * Keep the port resumed 100ms to make sure things like
		 * config space accesses from userspace (lspci) will not
		 * cause the port to repeatedly suspend and resume.
		 */
		pm_runtime_set_autosuspend_delay(&dev->dev, 100);
		pm_runtime_use_autosuspend(&dev->dev);
		pm_runtime_mark_last_busy(&dev->dev);
		pm_runtime_put_autosuspend(&dev->dev);
		pm_runtime_allow(&dev->dev);
	}

	return 0;
}

__attribute__((used)) static void pcie_portdrv_remove(struct pci_dev *dev)
{
	if (pci_bridge_d3_possible(dev)) {
		pm_runtime_forbid(&dev->dev);
		pm_runtime_get_noresume(&dev->dev);
		pm_runtime_dont_use_autosuspend(&dev->dev);
	}

	pcie_port_device_remove(dev);
}

__attribute__((used)) static pci_ers_result_t pcie_portdrv_error_detected(struct pci_dev *dev,
					enum pci_channel_state error)
{
	/* Root Port has no impact. Always recovers. */
	return PCI_ERS_RESULT_CAN_RECOVER;
}

__attribute__((used)) static pci_ers_result_t pcie_portdrv_mmio_enabled(struct pci_dev *dev)
{
	return PCI_ERS_RESULT_RECOVERED;
}

__attribute__((used)) static int resume_iter(struct device *device, void *data)
{
	struct pcie_device *pcie_device;
	struct pcie_port_service_driver *driver;

	if (device->bus == &pcie_port_bus_type && device->driver) {
		driver = to_service_driver(device->driver);
		if (driver && driver->error_resume) {
			pcie_device = to_pcie_device(device);

			/* Forward error message to service drivers */
			driver->error_resume(pcie_device->port);
		}
	}

	return 0;
}

__attribute__((used)) static void pcie_portdrv_err_resume(struct pci_dev *dev)
{
	device_for_each_child(&dev->dev, NULL, resume_iter);
}

