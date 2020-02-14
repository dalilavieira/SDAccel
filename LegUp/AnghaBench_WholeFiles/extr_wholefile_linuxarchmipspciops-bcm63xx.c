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
typedef  int u32 ;
struct pci_bus {unsigned int number; scalar_t__ parent; } ;

/* Variables and functions */
 scalar_t__ CARDBUS_PCI_IDSEL ; 
 int DLSTATUS_PHYLINKUP ; 
 int MPI_L2PCFG_CFG_SEL_MASK ; 
 int MPI_L2PCFG_CFG_TYPE_SHIFT ; 
 int MPI_L2PCFG_CFG_USEREG_MASK ; 
 unsigned int MPI_L2PCFG_DEVNUM_MASK ; 
 unsigned int MPI_L2PCFG_DEVNUM_SHIFT ; 
 unsigned int MPI_L2PCFG_FUNC_MASK ; 
 unsigned int MPI_L2PCFG_FUNC_SHIFT ; 
 int /*<<< orphan*/  MPI_L2PCFG_REG ; 
 unsigned int MPI_L2PCFG_REG_MASK ; 
 unsigned int MPI_L2PCFG_REG_SHIFT ; 
 int PCIBIOS_DEVICE_NOT_FOUND ; 
 int PCIBIOS_SUCCESSFUL ; 
#define  PCIE_BUS_BRIDGE 129 
#define  PCIE_BUS_DEVICE 128 
 scalar_t__ PCIE_DEVICE_OFFSET ; 
 int PCIE_DLSTATUS_REG ; 
 unsigned int PCI_FUNC (unsigned int) ; 
 scalar_t__ PCI_SLOT (int) ; 
 int /*<<< orphan*/  __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm_mpi_writel (int,int /*<<< orphan*/ ) ; 
 int bcm_pcie_readl (int) ; 
 int /*<<< orphan*/  bcm_pcie_writel (int,int) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  iob () ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_iospace_start ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static int postprocess_read(u32 data, int where, unsigned int size)
{
	u32 ret;

	ret = 0;
	switch (size) {
	case 1:
		ret = (data >> ((where & 3) << 3)) & 0xff;
		break;
	case 2:
		ret = (data >> ((where & 3) << 3)) & 0xffff;
		break;
	case 4:
		ret = data;
		break;
	}
	return ret;
}

__attribute__((used)) static int preprocess_write(u32 orig_data, u32 val, int where,
			    unsigned int size)
{
	u32 ret;

	ret = 0;
	switch (size) {
	case 1:
		ret = (orig_data & ~(0xff << ((where & 3) << 3))) |
			(val << ((where & 3) << 3));
		break;
	case 2:
		ret = (orig_data & ~(0xffff << ((where & 3) << 3))) |
			(val << ((where & 3) << 3));
		break;
	case 4:
		ret = val;
		break;
	}
	return ret;
}

__attribute__((used)) static int bcm63xx_setup_cfg_access(int type, unsigned int busn,
				    unsigned int devfn, int where)
{
	unsigned int slot, func, reg;
	u32 val;

	slot = PCI_SLOT(devfn);
	func = PCI_FUNC(devfn);
	reg = where >> 2;

	/* sanity check */
	if (slot > (MPI_L2PCFG_DEVNUM_MASK >> MPI_L2PCFG_DEVNUM_SHIFT))
		return 1;

	if (func > (MPI_L2PCFG_FUNC_MASK >> MPI_L2PCFG_FUNC_SHIFT))
		return 1;

	if (reg > (MPI_L2PCFG_REG_MASK >> MPI_L2PCFG_REG_SHIFT))
		return 1;

	/* ok, setup config access */
	val = (reg << MPI_L2PCFG_REG_SHIFT);
	val |= (func << MPI_L2PCFG_FUNC_SHIFT);
	val |= (slot << MPI_L2PCFG_DEVNUM_SHIFT);
	val |= MPI_L2PCFG_CFG_USEREG_MASK;
	val |= MPI_L2PCFG_CFG_SEL_MASK;
	/* type 0 cycle for local bus, type 1 cycle for anything else */
	if (type != 0) {
		/* FIXME: how to specify bus ??? */
		val |= (1 << MPI_L2PCFG_CFG_TYPE_SHIFT);
	}
	bcm_mpi_writel(val, MPI_L2PCFG_REG);

	return 0;
}

__attribute__((used)) static int bcm63xx_do_cfg_read(int type, unsigned int busn,
				unsigned int devfn, int where, int size,
				u32 *val)
{
	u32 data;

	/* two phase cycle, first we write address, then read data at
	 * another location, caller already has a spinlock so no need
	 * to add one here  */
	if (bcm63xx_setup_cfg_access(type, busn, devfn, where))
		return PCIBIOS_DEVICE_NOT_FOUND;
	iob();
	data = le32_to_cpu(__raw_readl(pci_iospace_start));
	/* restore IO space normal behaviour */
	bcm_mpi_writel(0, MPI_L2PCFG_REG);

	*val = postprocess_read(data, where, size);

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int bcm63xx_do_cfg_write(int type, unsigned int busn,
				 unsigned int devfn, int where, int size,
				 u32 val)
{
	u32 data;

	/* two phase cycle, first we write address, then write data to
	 * another location, caller already has a spinlock so no need
	 * to add one here  */
	if (bcm63xx_setup_cfg_access(type, busn, devfn, where))
		return PCIBIOS_DEVICE_NOT_FOUND;
	iob();

	data = le32_to_cpu(__raw_readl(pci_iospace_start));
	data = preprocess_write(data, val, where, size);

	__raw_writel(cpu_to_le32(data), pci_iospace_start);
	wmb();
	/* no way to know the access is done, we have to wait */
	udelay(500);
	/* restore IO space normal behaviour */
	bcm_mpi_writel(0, MPI_L2PCFG_REG);

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int bcm63xx_pci_read(struct pci_bus *bus, unsigned int devfn,
			     int where, int size, u32 *val)
{
	int type;

	type = bus->parent ? 1 : 0;

	if (type == 0 && PCI_SLOT(devfn) == CARDBUS_PCI_IDSEL)
		return PCIBIOS_DEVICE_NOT_FOUND;

	return bcm63xx_do_cfg_read(type, bus->number, devfn,
				    where, size, val);
}

__attribute__((used)) static int bcm63xx_pci_write(struct pci_bus *bus, unsigned int devfn,
			      int where, int size, u32 val)
{
	int type;

	type = bus->parent ? 1 : 0;

	if (type == 0 && PCI_SLOT(devfn) == CARDBUS_PCI_IDSEL)
		return PCIBIOS_DEVICE_NOT_FOUND;

	return bcm63xx_do_cfg_write(type, bus->number, devfn,
				     where, size, val);
}

__attribute__((used)) static int bcm63xx_pcie_can_access(struct pci_bus *bus, int devfn)
{
	switch (bus->number) {
	case PCIE_BUS_BRIDGE:
		return PCI_SLOT(devfn) == 0;
	case PCIE_BUS_DEVICE:
		if (PCI_SLOT(devfn) == 0)
			return bcm_pcie_readl(PCIE_DLSTATUS_REG)
					& DLSTATUS_PHYLINKUP;
	default:
		return false;
	}
}

__attribute__((used)) static int bcm63xx_pcie_read(struct pci_bus *bus, unsigned int devfn,
			     int where, int size, u32 *val)
{
	u32 data;
	u32 reg = where & ~3;

	if (!bcm63xx_pcie_can_access(bus, devfn))
		return PCIBIOS_DEVICE_NOT_FOUND;

	if (bus->number == PCIE_BUS_DEVICE)
		reg += PCIE_DEVICE_OFFSET;

	data = bcm_pcie_readl(reg);

	*val = postprocess_read(data, where, size);

	return PCIBIOS_SUCCESSFUL;

}

__attribute__((used)) static int bcm63xx_pcie_write(struct pci_bus *bus, unsigned int devfn,
			      int where, int size, u32 val)
{
	u32 data;
	u32 reg = where & ~3;

	if (!bcm63xx_pcie_can_access(bus, devfn))
		return PCIBIOS_DEVICE_NOT_FOUND;

	if (bus->number == PCIE_BUS_DEVICE)
		reg += PCIE_DEVICE_OFFSET;


	data = bcm_pcie_readl(reg);

	data = preprocess_write(data, val, where, size);
	bcm_pcie_writel(data, reg);

	return PCIBIOS_SUCCESSFUL;
}

