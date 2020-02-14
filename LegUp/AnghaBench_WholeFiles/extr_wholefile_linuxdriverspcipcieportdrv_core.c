#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct resource {int dummy; } ;
struct portdrv_service_data {int service; struct device* dev; struct pcie_port_service_driver* drv; } ;
struct TYPE_7__ {int (* probe ) (struct device*) ;int (* remove ) (struct device*) ;void (* shutdown ) (struct device*) ;int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct pcie_port_service_driver {int service; int (* probe ) (struct pcie_device*) ;TYPE_3__ driver; int /*<<< orphan*/  name; int /*<<< orphan*/  (* remove ) (struct pcie_device*) ;} ;
struct device {void (* release ) (struct device*) ;scalar_t__ driver; int /*<<< orphan*/ * bus; int /*<<< orphan*/ * parent; } ;
struct pcie_device {void* priv_data; int irq; int service; struct device device; struct pci_dev* port; } ;
struct pci_host_bridge {scalar_t__ native_pme; scalar_t__ native_pcie_hotplug; } ;
struct pci_device_id {scalar_t__ vendor; scalar_t__ device; scalar_t__ subvendor; scalar_t__ subdevice; int class; int class_mask; } ;
struct pci_dev {int msi_cap; int msix_cap; scalar_t__ vendor; scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; int class; int __aer_firmware_first; int /*<<< orphan*/  dev; scalar_t__ is_hotplug_bridge; TYPE_2__* bus; scalar_t__ __aer_firmware_first_valid; int /*<<< orphan*/  priv_flags; scalar_t__ no_d1d2; scalar_t__ bridge_d3; int /*<<< orphan*/  subordinate; } ;
struct pci_bus {int dummy; } ;
struct list_head {int dummy; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
struct TYPE_6__ {TYPE_1__* self; } ;
struct TYPE_5__ {unsigned int no_d1d2; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTTY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PCIE_PORT_DEVICE_MAXSERVICES ; 
 int PCIE_PORT_MAX_MSI_ENTRIES ; 
 int PCIE_PORT_SERVICE_AER ; 
 size_t PCIE_PORT_SERVICE_AER_SHIFT ; 
 int PCIE_PORT_SERVICE_DPC ; 
 size_t PCIE_PORT_SERVICE_DPC_SHIFT ; 
 int PCIE_PORT_SERVICE_HP ; 
 size_t PCIE_PORT_SERVICE_HP_SHIFT ; 
 int PCIE_PORT_SERVICE_PME ; 
 size_t PCIE_PORT_SERVICE_PME_SHIFT ; 
 scalar_t__ PCI_ANY_ID ; 
 int PCI_CLASS_BRIDGE_CARDBUS ; 
 int /*<<< orphan*/  PCI_DEV_ADDED ; 
 int /*<<< orphan*/  PCI_DEV_DISCONNECTED ; 
 int PCI_EXP_DPC_CAP ; 
 int PCI_EXP_DPC_IRQ ; 
 int /*<<< orphan*/  PCI_EXP_FLAGS ; 
 int PCI_EXP_FLAGS_IRQ ; 
 int /*<<< orphan*/  PCI_EXP_SLTCTL ; 
 int PCI_EXP_SLTCTL_CCIE ; 
 int PCI_EXP_SLTCTL_HPIE ; 
 scalar_t__ PCI_EXP_TYPE_ROOT_PORT ; 
 int /*<<< orphan*/  PCI_EXT_CAP_ID_DPC ; 
 int PCI_IRQ_LEGACY ; 
 int PCI_IRQ_MSI ; 
 int PCI_IRQ_MSIX ; 
 int PCI_MSIX_FLAGS ; 
 int PCI_MSI_FLAGS ; 
 int PCI_MSI_FLAGS_ENABLE ; 
 int /*<<< orphan*/  assign_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_set_name (struct device*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_enable_async_suspend (struct device*) ; 
 int /*<<< orphan*/  device_for_each_child (int /*<<< orphan*/ *,struct portdrv_service_data*,int (*) (struct device*,void*)) ; 
 int device_register (struct device*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int driver_register (TYPE_3__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  get_descriptor_id (scalar_t__,int) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 int /*<<< orphan*/  kfree (struct pcie_device*) ; 
 struct pcie_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int max (int,int) ; 
 scalar_t__ pci_aer_available () ; 
 int pci_alloc_irq_vectors (struct pci_dev*,int,int,int) ; 
 int /*<<< orphan*/  pci_cardbus_resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 int pci_find_ext_capability (struct pci_dev*,int /*<<< orphan*/ ) ; 
 struct pci_host_bridge* pci_find_host_bridge (TYPE_2__*) ; 
 int /*<<< orphan*/  pci_free_irq_vectors (struct pci_dev*) ; 
 int pci_irq_vector (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pci_name (struct pci_dev*) ; 
 scalar_t__ pci_pcie_type (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pcie_capability_clear_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pcie_capability_read_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pcie_port_bus_type ; 
 scalar_t__ pcie_ports_disabled ; 
 scalar_t__ pcie_ports_native ; 
 int /*<<< orphan*/  pm_runtime_no_callbacks (struct device*) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int /*<<< orphan*/  resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub1 (struct pcie_device*) ; 
 int /*<<< orphan*/  stub2 (struct pcie_device*) ; 
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

__attribute__((used)) static void release_pcie_device(struct device *dev)
{
	kfree(to_pcie_device(dev));
}

__attribute__((used)) static int pcie_message_numbers(struct pci_dev *dev, int mask,
				u32 *pme, u32 *aer, u32 *dpc)
{
	u32 nvec = 0, pos;
	u16 reg16;

	/*
	 * The Interrupt Message Number indicates which vector is used, i.e.,
	 * the MSI-X table entry or the MSI offset between the base Message
	 * Data and the generated interrupt message.  See PCIe r3.1, sec
	 * 7.8.2, 7.10.10, 7.31.2.
	 */

	if (mask & (PCIE_PORT_SERVICE_PME | PCIE_PORT_SERVICE_HP)) {
		pcie_capability_read_word(dev, PCI_EXP_FLAGS, &reg16);
		*pme = (reg16 & PCI_EXP_FLAGS_IRQ) >> 9;
		nvec = *pme + 1;
	}

#ifdef CONFIG_PCIEAER
	if (mask & PCIE_PORT_SERVICE_AER) {
		u32 reg32;

		pos = dev->aer_cap;
		if (pos) {
			pci_read_config_dword(dev, pos + PCI_ERR_ROOT_STATUS,
					      &reg32);
			*aer = (reg32 & PCI_ERR_ROOT_AER_IRQ) >> 27;
			nvec = max(nvec, *aer + 1);
		}
	}
#endif

	if (mask & PCIE_PORT_SERVICE_DPC) {
		pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_DPC);
		if (pos) {
			pci_read_config_word(dev, pos + PCI_EXP_DPC_CAP,
					     &reg16);
			*dpc = reg16 & PCI_EXP_DPC_IRQ;
			nvec = max(nvec, *dpc + 1);
		}
	}

	return nvec;
}

__attribute__((used)) static int pcie_port_enable_irq_vec(struct pci_dev *dev, int *irqs, int mask)
{
	int nr_entries, nvec;
	u32 pme = 0, aer = 0, dpc = 0;

	/* Allocate the maximum possible number of MSI/MSI-X vectors */
	nr_entries = pci_alloc_irq_vectors(dev, 1, PCIE_PORT_MAX_MSI_ENTRIES,
			PCI_IRQ_MSIX | PCI_IRQ_MSI);
	if (nr_entries < 0)
		return nr_entries;

	/* See how many and which Interrupt Message Numbers we actually use */
	nvec = pcie_message_numbers(dev, mask, &pme, &aer, &dpc);
	if (nvec > nr_entries) {
		pci_free_irq_vectors(dev);
		return -EIO;
	}

	/*
	 * If we allocated more than we need, free them and reallocate fewer.
	 *
	 * Reallocating may change the specific vectors we get, so
	 * pci_irq_vector() must be done *after* the reallocation.
	 *
	 * If we're using MSI, hardware is *allowed* to change the Interrupt
	 * Message Numbers when we free and reallocate the vectors, but we
	 * assume it won't because we allocate enough vectors for the
	 * biggest Message Number we found.
	 */
	if (nvec != nr_entries) {
		pci_free_irq_vectors(dev);

		nr_entries = pci_alloc_irq_vectors(dev, nvec, nvec,
				PCI_IRQ_MSIX | PCI_IRQ_MSI);
		if (nr_entries < 0)
			return nr_entries;
	}

	/* PME and hotplug share an MSI/MSI-X vector */
	if (mask & (PCIE_PORT_SERVICE_PME | PCIE_PORT_SERVICE_HP)) {
		irqs[PCIE_PORT_SERVICE_PME_SHIFT] = pci_irq_vector(dev, pme);
		irqs[PCIE_PORT_SERVICE_HP_SHIFT] = pci_irq_vector(dev, pme);
	}

	if (mask & PCIE_PORT_SERVICE_AER)
		irqs[PCIE_PORT_SERVICE_AER_SHIFT] = pci_irq_vector(dev, aer);

	if (mask & PCIE_PORT_SERVICE_DPC)
		irqs[PCIE_PORT_SERVICE_DPC_SHIFT] = pci_irq_vector(dev, dpc);

	return 0;
}

__attribute__((used)) static int pcie_init_service_irqs(struct pci_dev *dev, int *irqs, int mask)
{
	int ret, i;

	for (i = 0; i < PCIE_PORT_DEVICE_MAXSERVICES; i++)
		irqs[i] = -1;

	/*
	 * If we support PME but can't use MSI/MSI-X for it, we have to
	 * fall back to INTx or other interrupts, e.g., a system shared
	 * interrupt.
	 */
	if ((mask & PCIE_PORT_SERVICE_PME) && pcie_pme_no_msi())
		goto legacy_irq;

	/* Try to use MSI-X or MSI if supported */
	if (pcie_port_enable_irq_vec(dev, irqs, mask) == 0)
		return 0;

legacy_irq:
	/* fall back to legacy IRQ */
	ret = pci_alloc_irq_vectors(dev, 1, 1, PCI_IRQ_LEGACY);
	if (ret < 0)
		return -ENODEV;

	for (i = 0; i < PCIE_PORT_DEVICE_MAXSERVICES; i++)
		irqs[i] = pci_irq_vector(dev, 0);

	return 0;
}

__attribute__((used)) static int get_port_device_capability(struct pci_dev *dev)
{
	struct pci_host_bridge *host = pci_find_host_bridge(dev->bus);
	int services = 0;

	if (dev->is_hotplug_bridge &&
	    (pcie_ports_native || host->native_pcie_hotplug)) {
		services |= PCIE_PORT_SERVICE_HP;

		/*
		 * Disable hot-plug interrupts in case they have been enabled
		 * by the BIOS and the hot-plug service driver is not loaded.
		 */
		pcie_capability_clear_word(dev, PCI_EXP_SLTCTL,
			  PCI_EXP_SLTCTL_CCIE | PCI_EXP_SLTCTL_HPIE);
	}

#ifdef CONFIG_PCIEAER
	if (dev->aer_cap && pci_aer_available() &&
	    (pcie_ports_native || host->native_aer)) {
		services |= PCIE_PORT_SERVICE_AER;

		/*
		 * Disable AER on this port in case it's been enabled by the
		 * BIOS (the AER service driver will enable it when necessary).
		 */
		pci_disable_pcie_error_reporting(dev);
	}
#endif

	/*
	 * Root ports are capable of generating PME too.  Root Complex
	 * Event Collectors can also generate PMEs, but we don't handle
	 * those yet.
	 */
	if (pci_pcie_type(dev) == PCI_EXP_TYPE_ROOT_PORT &&
	    (pcie_ports_native || host->native_pme)) {
		services |= PCIE_PORT_SERVICE_PME;

		/*
		 * Disable PME interrupt on this port in case it's been enabled
		 * by the BIOS (the PME service driver will enable it when
		 * necessary).
		 */
		pcie_pme_interrupt_enable(dev, false);
	}

	if (pci_find_ext_capability(dev, PCI_EXT_CAP_ID_DPC) &&
	    pci_aer_available() && services & PCIE_PORT_SERVICE_AER)
		services |= PCIE_PORT_SERVICE_DPC;

	return services;
}

__attribute__((used)) static int pcie_device_init(struct pci_dev *pdev, int service, int irq)
{
	int retval;
	struct pcie_device *pcie;
	struct device *device;

	pcie = kzalloc(sizeof(*pcie), GFP_KERNEL);
	if (!pcie)
		return -ENOMEM;
	pcie->port = pdev;
	pcie->irq = irq;
	pcie->service = service;

	/* Initialize generic device interface */
	device = &pcie->device;
	device->bus = &pcie_port_bus_type;
	device->release = release_pcie_device;	/* callback to free pcie dev */
	dev_set_name(device, "%s:pcie%03x",
		     pci_name(pdev),
		     get_descriptor_id(pci_pcie_type(pdev), service));
	device->parent = &pdev->dev;
	device_enable_async_suspend(device);

	retval = device_register(device);
	if (retval) {
		put_device(device);
		return retval;
	}

	pm_runtime_no_callbacks(device);

	return 0;
}

int pcie_port_device_register(struct pci_dev *dev)
{
	int status, capabilities, i, nr_service;
	int irqs[PCIE_PORT_DEVICE_MAXSERVICES];

	/* Enable PCI Express port device */
	status = pci_enable_device(dev);
	if (status)
		return status;

	/* Get and check PCI Express port services */
	capabilities = get_port_device_capability(dev);
	if (!capabilities)
		return 0;

	pci_set_master(dev);
	/*
	 * Initialize service irqs. Don't use service devices that
	 * require interrupts if there is no way to generate them.
	 * However, some drivers may have a polling mode (e.g. pciehp_poll_mode)
	 * that can be used in the absence of irqs.  Allow them to determine
	 * if that is to be used.
	 */
	status = pcie_init_service_irqs(dev, irqs, capabilities);
	if (status) {
		capabilities &= PCIE_PORT_SERVICE_HP;
		if (!capabilities)
			goto error_disable;
	}

	/* Allocate child services if any */
	status = -ENODEV;
	nr_service = 0;
	for (i = 0; i < PCIE_PORT_DEVICE_MAXSERVICES; i++) {
		int service = 1 << i;
		if (!(capabilities & service))
			continue;
		if (!pcie_device_init(dev, service, irqs[i]))
			nr_service++;
	}
	if (!nr_service)
		goto error_cleanup_irqs;

	return 0;

error_cleanup_irqs:
	pci_free_irq_vectors(dev);
error_disable:
	pci_disable_device(dev);
	return status;
}

__attribute__((used)) static int remove_iter(struct device *dev, void *data)
{
	if (dev->bus == &pcie_port_bus_type)
		device_unregister(dev);
	return 0;
}

__attribute__((used)) static int find_service_iter(struct device *device, void *data)
{
	struct pcie_port_service_driver *service_driver;
	struct portdrv_service_data *pdrvs;
	u32 service;

	pdrvs = (struct portdrv_service_data *) data;
	service = pdrvs->service;

	if (device->bus == &pcie_port_bus_type && device->driver) {
		service_driver = to_service_driver(device->driver);
		if (service_driver->service == service) {
			pdrvs->drv = service_driver;
			pdrvs->dev = device;
			return 1;
		}
	}

	return 0;
}

struct pcie_port_service_driver *pcie_port_find_service(struct pci_dev *dev,
							u32 service)
{
	struct pcie_port_service_driver *drv;
	struct portdrv_service_data pdrvs;

	pdrvs.drv = NULL;
	pdrvs.service = service;
	device_for_each_child(&dev->dev, &pdrvs, find_service_iter);

	drv = pdrvs.drv;
	return drv;
}

struct device *pcie_port_find_device(struct pci_dev *dev,
				      u32 service)
{
	struct device *device;
	struct portdrv_service_data pdrvs;

	pdrvs.dev = NULL;
	pdrvs.service = service;
	device_for_each_child(&dev->dev, &pdrvs, find_service_iter);

	device = pdrvs.dev;
	return device;
}

void pcie_port_device_remove(struct pci_dev *dev)
{
	device_for_each_child(&dev->dev, NULL, remove_iter);
	pci_free_irq_vectors(dev);
	pci_disable_device(dev);
}

__attribute__((used)) static int pcie_port_probe_service(struct device *dev)
{
	struct pcie_device *pciedev;
	struct pcie_port_service_driver *driver;
	int status;

	if (!dev || !dev->driver)
		return -ENODEV;

	driver = to_service_driver(dev->driver);
	if (!driver || !driver->probe)
		return -ENODEV;

	pciedev = to_pcie_device(dev);
	status = driver->probe(pciedev);
	if (status)
		return status;

	get_device(dev);
	return 0;
}

__attribute__((used)) static int pcie_port_remove_service(struct device *dev)
{
	struct pcie_device *pciedev;
	struct pcie_port_service_driver *driver;

	if (!dev || !dev->driver)
		return 0;

	pciedev = to_pcie_device(dev);
	driver = to_service_driver(dev->driver);
	if (driver && driver->remove) {
		driver->remove(pciedev);
		put_device(dev);
	}
	return 0;
}

__attribute__((used)) static void pcie_port_shutdown_service(struct device *dev) {}

int pcie_port_service_register(struct pcie_port_service_driver *new)
{
	if (pcie_ports_disabled)
		return -ENODEV;

	new->driver.name = new->name;
	new->driver.bus = &pcie_port_bus_type;
	new->driver.probe = pcie_port_probe_service;
	new->driver.remove = pcie_port_remove_service;
	new->driver.shutdown = pcie_port_shutdown_service;

	return driver_register(&new->driver);
}

void pcie_port_service_unregister(struct pcie_port_service_driver *drv)
{
	driver_unregister(&drv->driver);
}

