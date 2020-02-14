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
typedef  int u32 ;
typedef  int u16 ;
struct resource {int flags; unsigned long long end; unsigned long long start; int /*<<< orphan*/  parent; int /*<<< orphan*/  name; } ;
struct pci_device_id {scalar_t__ vendor; scalar_t__ device; scalar_t__ subvendor; scalar_t__ subdevice; int class; int class_mask; } ;
struct pci_dev {scalar_t__ vendor; scalar_t__ device; scalar_t__ subsystem_vendor; scalar_t__ subsystem_device; int class; int rom_base_reg; struct resource* resource; TYPE_1__* bus; int /*<<< orphan*/  mmio_always_on; scalar_t__ is_virtfn; int /*<<< orphan*/  priv_flags; scalar_t__ no_d1d2; scalar_t__ msix_cap; scalar_t__ msi_cap; scalar_t__ bridge_d3; int /*<<< orphan*/  subordinate; int /*<<< orphan*/  dev; } ;
struct pci_bus_region {int start; } ;
struct pci_bus {int dummy; } ;
struct list_head {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  unsigned long long resource_size_t ;
struct TYPE_4__ {unsigned int no_d1d2; } ;
struct TYPE_3__ {TYPE_2__* self; } ;

/* Variables and functions */
 int BIT (int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOTSUPP ; 
 int ENOTTY ; 
 int IORESOURCE_IO ; 
 int IORESOURCE_MEM ; 
 int IORESOURCE_MEM_64 ; 
 int IORESOURCE_PCI_FIXED ; 
 int IORESOURCE_ROM_ENABLE ; 
 int IORESOURCE_ROM_SHADOW ; 
 int IORESOURCE_STARTALIGN ; 
 int IORESOURCE_UNSET ; 
 scalar_t__ PCI_ANY_ID ; 
 int PCI_BASE_ADDRESS_0 ; 
 int PCI_BASE_ADDRESS_IO_MASK ; 
 int PCI_BASE_ADDRESS_MEM_MASK ; 
 int PCI_BRIDGE_RESOURCES ; 
 int PCI_CLASS_BRIDGE_CARDBUS ; 
 scalar_t__ PCI_COMMAND ; 
 int PCI_COMMAND_IO ; 
 int PCI_COMMAND_MEMORY ; 
 int /*<<< orphan*/  PCI_DEV_ADDED ; 
 int /*<<< orphan*/  PCI_DEV_DISCONNECTED ; 
 int PCI_MEMORY_BASE ; 
 scalar_t__ PCI_MSIX_FLAGS ; 
 scalar_t__ PCI_MSI_FLAGS ; 
 int PCI_MSI_FLAGS_ENABLE ; 
 int PCI_NUM_RESOURCES ; 
 int PCI_PREF_BASE_UPPER32 ; 
 int PCI_PREF_LIMIT_UPPER32 ; 
 int PCI_PREF_MEMORY_BASE ; 
 int PCI_ROM_ADDRESS_ENABLE ; 
 int PCI_ROM_ADDRESS_MASK ; 
 int PCI_ROM_RESOURCE ; 
 int _pci_assign_resource (struct pci_dev*,int,unsigned long long,unsigned long long) ; 
 int /*<<< orphan*/  assign_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 unsigned long long pci_cardbus_resource_alignment (struct resource*) ; 
 int /*<<< orphan*/  pci_err (struct pci_dev*,char*,int,...) ; 
 struct resource* pci_find_parent_resource (struct pci_dev*,struct resource*) ; 
 int /*<<< orphan*/  pci_info (struct pci_dev*,char*,int,...) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,scalar_t__,int*) ; 
 int pci_reassign_bridge_resources (TYPE_2__*,int) ; 
 int pci_rebar_get_current_size (struct pci_dev*,int) ; 
 int pci_rebar_get_possible_sizes (struct pci_dev*,int) ; 
 int pci_rebar_set_size (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,scalar_t__,int) ; 
 int /*<<< orphan*/  pcibios_resource_to_bus (TYPE_1__*,struct pci_bus_region*,struct resource*) ; 
 int /*<<< orphan*/  pm_wakeup_event (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  release_resource (struct resource*) ; 
 struct resource* request_resource_conflict (struct resource*,struct resource*) ; 
 unsigned long long resource_alignment (struct resource*) ; 
 unsigned long long resource_size (struct resource*) ; 
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

__attribute__((used)) static void pci_std_update_resource(struct pci_dev *dev, int resno)
{
	struct pci_bus_region region;
	bool disable;
	u16 cmd;
	u32 new, check, mask;
	int reg;
	struct resource *res = dev->resource + resno;

	/* Per SR-IOV spec 3.4.1.11, VF BARs are RO zero */
	if (dev->is_virtfn)
		return;

	/*
	 * Ignore resources for unimplemented BARs and unused resource slots
	 * for 64 bit BARs.
	 */
	if (!res->flags)
		return;

	if (res->flags & IORESOURCE_UNSET)
		return;

	/*
	 * Ignore non-moveable resources.  This might be legacy resources for
	 * which no functional BAR register exists or another important
	 * system resource we shouldn't move around.
	 */
	if (res->flags & IORESOURCE_PCI_FIXED)
		return;

	pcibios_resource_to_bus(dev->bus, &region, res);
	new = region.start;

	if (res->flags & IORESOURCE_IO) {
		mask = (u32)PCI_BASE_ADDRESS_IO_MASK;
		new |= res->flags & ~PCI_BASE_ADDRESS_IO_MASK;
	} else if (resno == PCI_ROM_RESOURCE) {
		mask = PCI_ROM_ADDRESS_MASK;
	} else {
		mask = (u32)PCI_BASE_ADDRESS_MEM_MASK;
		new |= res->flags & ~PCI_BASE_ADDRESS_MEM_MASK;
	}

	if (resno < PCI_ROM_RESOURCE) {
		reg = PCI_BASE_ADDRESS_0 + 4 * resno;
	} else if (resno == PCI_ROM_RESOURCE) {

		/*
		 * Apparently some Matrox devices have ROM BARs that read
		 * as zero when disabled, so don't update ROM BARs unless
		 * they're enabled.  See https://lkml.org/lkml/2005/8/30/138.
		 */
		if (!(res->flags & IORESOURCE_ROM_ENABLE))
			return;

		reg = dev->rom_base_reg;
		new |= PCI_ROM_ADDRESS_ENABLE;
	} else
		return;

	/*
	 * We can't update a 64-bit BAR atomically, so when possible,
	 * disable decoding so that a half-updated BAR won't conflict
	 * with another device.
	 */
	disable = (res->flags & IORESOURCE_MEM_64) && !dev->mmio_always_on;
	if (disable) {
		pci_read_config_word(dev, PCI_COMMAND, &cmd);
		pci_write_config_word(dev, PCI_COMMAND,
				      cmd & ~PCI_COMMAND_MEMORY);
	}

	pci_write_config_dword(dev, reg, new);
	pci_read_config_dword(dev, reg, &check);

	if ((new ^ check) & mask) {
		pci_err(dev, "BAR %d: error updating (%#08x != %#08x)\n",
			resno, new, check);
	}

	if (res->flags & IORESOURCE_MEM_64) {
		new = region.start >> 16 >> 16;
		pci_write_config_dword(dev, reg + 4, new);
		pci_read_config_dword(dev, reg + 4, &check);
		if (check != new) {
			pci_err(dev, "BAR %d: error updating (high %#08x != %#08x)\n",
				resno, new, check);
		}
	}

	if (disable)
		pci_write_config_word(dev, PCI_COMMAND, cmd);
}

void pci_update_resource(struct pci_dev *dev, int resno)
{
	if (resno <= PCI_ROM_RESOURCE)
		pci_std_update_resource(dev, resno);
#ifdef CONFIG_PCI_IOV
	else if (resno >= PCI_IOV_RESOURCES && resno <= PCI_IOV_RESOURCE_END)
		pci_iov_update_resource(dev, resno);
#endif
}

int pci_claim_resource(struct pci_dev *dev, int resource)
{
	struct resource *res = &dev->resource[resource];
	struct resource *root, *conflict;

	if (res->flags & IORESOURCE_UNSET) {
		pci_info(dev, "can't claim BAR %d %pR: no address assigned\n",
			 resource, res);
		return -EINVAL;
	}

	/*
	 * If we have a shadow copy in RAM, the PCI device doesn't respond
	 * to the shadow range, so we don't need to claim it, and upstream
	 * bridges don't need to route the range to the device.
	 */
	if (res->flags & IORESOURCE_ROM_SHADOW)
		return 0;

	root = pci_find_parent_resource(dev, res);
	if (!root) {
		pci_info(dev, "can't claim BAR %d %pR: no compatible bridge window\n",
			 resource, res);
		res->flags |= IORESOURCE_UNSET;
		return -EINVAL;
	}

	conflict = request_resource_conflict(root, res);
	if (conflict) {
		pci_info(dev, "can't claim BAR %d %pR: address conflict with %s %pR\n",
			 resource, res, conflict->name, conflict);
		res->flags |= IORESOURCE_UNSET;
		return -EBUSY;
	}

	return 0;
}

void pci_disable_bridge_window(struct pci_dev *dev)
{
	/* MMIO Base/Limit */
	pci_write_config_dword(dev, PCI_MEMORY_BASE, 0x0000fff0);

	/* Prefetchable MMIO Base/Limit */
	pci_write_config_dword(dev, PCI_PREF_LIMIT_UPPER32, 0);
	pci_write_config_dword(dev, PCI_PREF_MEMORY_BASE, 0x0000fff0);
	pci_write_config_dword(dev, PCI_PREF_BASE_UPPER32, 0xffffffff);
}

int pci_reassign_resource(struct pci_dev *dev, int resno, resource_size_t addsize,
			resource_size_t min_align)
{
	struct resource *res = dev->resource + resno;
	unsigned long flags;
	resource_size_t new_size;
	int ret;

	if (res->flags & IORESOURCE_PCI_FIXED)
		return 0;

	flags = res->flags;
	res->flags |= IORESOURCE_UNSET;
	if (!res->parent) {
		pci_info(dev, "BAR %d: can't reassign an unassigned resource %pR\n",
			 resno, res);
		return -EINVAL;
	}

	/* already aligned with min_align */
	new_size = resource_size(res) + addsize;
	ret = _pci_assign_resource(dev, resno, new_size, min_align);
	if (ret) {
		res->flags = flags;
		pci_info(dev, "BAR %d: %pR (failed to expand by %#llx)\n",
			 resno, res, (unsigned long long) addsize);
		return ret;
	}

	res->flags &= ~IORESOURCE_UNSET;
	res->flags &= ~IORESOURCE_STARTALIGN;
	pci_info(dev, "BAR %d: reassigned %pR (expanded by %#llx)\n",
		 resno, res, (unsigned long long) addsize);
	if (resno < PCI_BRIDGE_RESOURCES)
		pci_update_resource(dev, resno);

	return 0;
}

void pci_release_resource(struct pci_dev *dev, int resno)
{
	struct resource *res = dev->resource + resno;

	pci_info(dev, "BAR %d: releasing %pR\n", resno, res);

	if (!res->parent)
		return;

	release_resource(res);
	res->end = resource_size(res) - 1;
	res->start = 0;
	res->flags |= IORESOURCE_UNSET;
}

int pci_resize_resource(struct pci_dev *dev, int resno, int size)
{
	struct resource *res = dev->resource + resno;
	int old, ret;
	u32 sizes;
	u16 cmd;

	/* Make sure the resource isn't assigned before resizing it. */
	if (!(res->flags & IORESOURCE_UNSET))
		return -EBUSY;

	pci_read_config_word(dev, PCI_COMMAND, &cmd);
	if (cmd & PCI_COMMAND_MEMORY)
		return -EBUSY;

	sizes = pci_rebar_get_possible_sizes(dev, resno);
	if (!sizes)
		return -ENOTSUPP;

	if (!(sizes & BIT(size)))
		return -EINVAL;

	old = pci_rebar_get_current_size(dev, resno);
	if (old < 0)
		return old;

	ret = pci_rebar_set_size(dev, resno, size);
	if (ret)
		return ret;

	res->end = res->start + pci_rebar_size_to_bytes(size) - 1;

	/* Check if the new config works by trying to assign everything. */
	ret = pci_reassign_bridge_resources(dev->bus->self, res->flags);
	if (ret)
		goto error_resize;

	return 0;

error_resize:
	pci_rebar_set_size(dev, resno, old);
	res->end = res->start + pci_rebar_size_to_bytes(old) - 1;
	return ret;
}

int pci_enable_resources(struct pci_dev *dev, int mask)
{
	u16 cmd, old_cmd;
	int i;
	struct resource *r;

	pci_read_config_word(dev, PCI_COMMAND, &cmd);
	old_cmd = cmd;

	for (i = 0; i < PCI_NUM_RESOURCES; i++) {
		if (!(mask & (1 << i)))
			continue;

		r = &dev->resource[i];

		if (!(r->flags & (IORESOURCE_IO | IORESOURCE_MEM)))
			continue;
		if ((i == PCI_ROM_RESOURCE) &&
				(!(r->flags & IORESOURCE_ROM_ENABLE)))
			continue;

		if (r->flags & IORESOURCE_UNSET) {
			pci_err(dev, "can't enable device: BAR %d %pR not assigned\n",
				i, r);
			return -EINVAL;
		}

		if (!r->parent) {
			pci_err(dev, "can't enable device: BAR %d %pR not claimed\n",
				i, r);
			return -EINVAL;
		}

		if (r->flags & IORESOURCE_IO)
			cmd |= PCI_COMMAND_IO;
		if (r->flags & IORESOURCE_MEM)
			cmd |= PCI_COMMAND_MEMORY;
	}

	if (cmd != old_cmd) {
		pci_info(dev, "enabling device (%04x -> %04x)\n", old_cmd, cmd);
		pci_write_config_word(dev, PCI_COMMAND, cmd);
	}
	return 0;
}

