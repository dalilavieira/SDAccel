#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ u32 ;
struct pci_mmcfg_region {scalar_t__ address; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  FIX_PCIE_MCFG ; 
 unsigned int PCI_MMCFG_BUS_OFFSET (int) ; 
 int mmcfg_last_accessed_cpu ; 
 scalar_t__ mmcfg_last_accessed_device ; 
 int /*<<< orphan*/  mmcfg_virt_addr ; 
 scalar_t__ mmio_config_readb (int /*<<< orphan*/ ) ; 
 scalar_t__ mmio_config_readl (int /*<<< orphan*/ ) ; 
 scalar_t__ mmio_config_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmio_config_writeb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  mmio_config_writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  mmio_config_writew (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  pci_config_lock ; 
 struct pci_mmcfg_region* pci_mmconfig_lookup (unsigned int,int) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  set_fixmap_nocache (int /*<<< orphan*/ ,scalar_t__) ; 
 int smp_processor_id () ; 

__attribute__((used)) static u32 get_base_addr(unsigned int seg, int bus, unsigned devfn)
{
	struct pci_mmcfg_region *cfg = pci_mmconfig_lookup(seg, bus);

	if (cfg)
		return cfg->address;
	return 0;
}

__attribute__((used)) static void pci_exp_set_dev_base(unsigned int base, int bus, int devfn)
{
	u32 dev_base = base | PCI_MMCFG_BUS_OFFSET(bus) | (devfn << 12);
	int cpu = smp_processor_id();
	if (dev_base != mmcfg_last_accessed_device ||
	    cpu != mmcfg_last_accessed_cpu) {
		mmcfg_last_accessed_device = dev_base;
		mmcfg_last_accessed_cpu = cpu;
		set_fixmap_nocache(FIX_PCIE_MCFG, dev_base);
	}
}

__attribute__((used)) static int pci_mmcfg_read(unsigned int seg, unsigned int bus,
			  unsigned int devfn, int reg, int len, u32 *value)
{
	unsigned long flags;
	u32 base;

	if ((bus > 255) || (devfn > 255) || (reg > 4095)) {
err:		*value = -1;
		return -EINVAL;
	}

	rcu_read_lock();
	base = get_base_addr(seg, bus, devfn);
	if (!base) {
		rcu_read_unlock();
		goto err;
	}

	raw_spin_lock_irqsave(&pci_config_lock, flags);

	pci_exp_set_dev_base(base, bus, devfn);

	switch (len) {
	case 1:
		*value = mmio_config_readb(mmcfg_virt_addr + reg);
		break;
	case 2:
		*value = mmio_config_readw(mmcfg_virt_addr + reg);
		break;
	case 4:
		*value = mmio_config_readl(mmcfg_virt_addr + reg);
		break;
	}
	raw_spin_unlock_irqrestore(&pci_config_lock, flags);
	rcu_read_unlock();

	return 0;
}

__attribute__((used)) static int pci_mmcfg_write(unsigned int seg, unsigned int bus,
			   unsigned int devfn, int reg, int len, u32 value)
{
	unsigned long flags;
	u32 base;

	if ((bus > 255) || (devfn > 255) || (reg > 4095))
		return -EINVAL;

	rcu_read_lock();
	base = get_base_addr(seg, bus, devfn);
	if (!base) {
		rcu_read_unlock();
		return -EINVAL;
	}

	raw_spin_lock_irqsave(&pci_config_lock, flags);

	pci_exp_set_dev_base(base, bus, devfn);

	switch (len) {
	case 1:
		mmio_config_writeb(mmcfg_virt_addr + reg, value);
		break;
	case 2:
		mmio_config_writew(mmcfg_virt_addr + reg, value);
		break;
	case 4:
		mmio_config_writel(mmcfg_virt_addr + reg, value);
		break;
	}
	raw_spin_unlock_irqrestore(&pci_config_lock, flags);
	rcu_read_unlock();

	return 0;
}

