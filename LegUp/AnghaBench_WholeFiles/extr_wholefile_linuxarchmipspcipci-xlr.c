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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct pci_dev {int /*<<< orphan*/  devfn; struct pci_bus* bus; } ;
struct pci_bus {scalar_t__ number; struct pci_dev* self; struct pci_bus* parent; } ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  NETLOGIC_IO_PCIE_1_OFFSET ; 
 int /*<<< orphan*/  NETLOGIC_IO_PCIX_OFFSET ; 
 int PCIBIOS_BAD_REGISTER_NUMBER ; 
 int PCIBIOS_SUCCESSFUL ; 
 int PCI_SLOT (int /*<<< orphan*/ ) ; 
#define  PIC_PCIE_LINK0_IRQ 133 
#define  PIC_PCIE_LINK1_IRQ 132 
#define  PIC_PCIE_LINK2_IRQ 131 
#define  PIC_PCIE_LINK3_IRQ 130 
#define  PIC_PCIE_XLSB0_LINK2_IRQ 129 
#define  PIC_PCIE_XLSB0_LINK3_IRQ 128 
 int PIC_PCIX_IRQ ; 
 int /*<<< orphan*/  WARN (int,char*,int) ; 
 int cpu_to_le32 (int) ; 
 int /*<<< orphan*/  nlm_chip_is_xls () ; 
 int /*<<< orphan*/  nlm_chip_is_xls_b () ; 
 int /*<<< orphan*/  nlm_mmio_base (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlm_read_reg (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nlm_write_reg (int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ pci_cfg_addr (scalar_t__,unsigned int,int) ; 
 scalar_t__ pci_config_base ; 

__attribute__((used)) static inline u32 pci_cfg_read_32bit(struct pci_bus *bus, unsigned int devfn,
	int where)
{
	u32 data;
	u32 *cfgaddr;

	cfgaddr = (u32 *)(pci_config_base +
			pci_cfg_addr(bus->number, devfn, where & ~3));
	data = *cfgaddr;
	return cpu_to_le32(data);
}

__attribute__((used)) static inline void pci_cfg_write_32bit(struct pci_bus *bus, unsigned int devfn,
	int where, u32 data)
{
	u32 *cfgaddr;

	cfgaddr = (u32 *)(pci_config_base +
			pci_cfg_addr(bus->number, devfn, where & ~3));
	*cfgaddr = cpu_to_le32(data);
}

__attribute__((used)) static int nlm_pcibios_read(struct pci_bus *bus, unsigned int devfn,
	int where, int size, u32 *val)
{
	u32 data;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	data = pci_cfg_read_32bit(bus, devfn, where);

	if (size == 1)
		*val = (data >> ((where & 3) << 3)) & 0xff;
	else if (size == 2)
		*val = (data >> ((where & 3) << 3)) & 0xffff;
	else
		*val = data;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int nlm_pcibios_write(struct pci_bus *bus, unsigned int devfn,
		int where, int size, u32 val)
{
	u32 data;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	data = pci_cfg_read_32bit(bus, devfn, where);

	if (size == 1)
		data = (data & ~(0xff << ((where & 3) << 3))) |
			(val << ((where & 3) << 3));
	else if (size == 2)
		data = (data & ~(0xffff << ((where & 3) << 3))) |
			(val << ((where & 3) << 3));
	else
		data = val;

	pci_cfg_write_32bit(bus, devfn, where, data);

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static struct pci_dev *xls_get_pcie_link(const struct pci_dev *dev)
{
	struct pci_bus *bus, *p;

	/* Find the bridge on bus 0 */
	bus = dev->bus;
	for (p = bus->parent; p && p->number != 0; p = p->parent)
		bus = p;

	return p ? bus->self : NULL;
}

__attribute__((used)) static int nlm_pci_link_to_irq(int link)
{
	switch	(link) {
	case 0:
		return PIC_PCIE_LINK0_IRQ;
	case 1:
		return PIC_PCIE_LINK1_IRQ;
	case 2:
		if (nlm_chip_is_xls_b())
			return PIC_PCIE_XLSB0_LINK2_IRQ;
		else
			return PIC_PCIE_LINK2_IRQ;
	case 3:
		if (nlm_chip_is_xls_b())
			return PIC_PCIE_XLSB0_LINK3_IRQ;
		else
			return PIC_PCIE_LINK3_IRQ;
	}
	WARN(1, "Unexpected link %d\n", link);
	return 0;
}

__attribute__((used)) static int get_irq_vector(const struct pci_dev *dev)
{
	struct pci_dev *lnk;
	int link;

	if (!nlm_chip_is_xls())
		return	PIC_PCIX_IRQ;	/* for XLR just one IRQ */

	lnk = xls_get_pcie_link(dev);
	if (lnk == NULL)
		return 0;

	link = PCI_SLOT(lnk->devfn);
	return nlm_pci_link_to_irq(link);
}

__attribute__((used)) static void xlr_pci_ack(struct irq_data *d)
{
	uint64_t pcibase = nlm_mmio_base(NETLOGIC_IO_PCIX_OFFSET);

	nlm_read_reg(pcibase, (0x140 >> 2));
}

__attribute__((used)) static void xls_pcie_ack(struct irq_data *d)
{
	uint64_t pciebase_le = nlm_mmio_base(NETLOGIC_IO_PCIE_1_OFFSET);

	switch (d->irq) {
	case PIC_PCIE_LINK0_IRQ:
		nlm_write_reg(pciebase_le, (0x90 >> 2), 0xffffffff);
		break;
	case PIC_PCIE_LINK1_IRQ:
		nlm_write_reg(pciebase_le, (0x94 >> 2), 0xffffffff);
		break;
	case PIC_PCIE_LINK2_IRQ:
		nlm_write_reg(pciebase_le, (0x190 >> 2), 0xffffffff);
		break;
	case PIC_PCIE_LINK3_IRQ:
		nlm_write_reg(pciebase_le, (0x194 >> 2), 0xffffffff);
		break;
	}
}

__attribute__((used)) static void xls_pcie_ack_b(struct irq_data *d)
{
	uint64_t pciebase_le = nlm_mmio_base(NETLOGIC_IO_PCIE_1_OFFSET);

	switch (d->irq) {
	case PIC_PCIE_LINK0_IRQ:
		nlm_write_reg(pciebase_le, (0x90 >> 2), 0xffffffff);
		break;
	case PIC_PCIE_LINK1_IRQ:
		nlm_write_reg(pciebase_le, (0x94 >> 2), 0xffffffff);
		break;
	case PIC_PCIE_XLSB0_LINK2_IRQ:
		nlm_write_reg(pciebase_le, (0x190 >> 2), 0xffffffff);
		break;
	case PIC_PCIE_XLSB0_LINK3_IRQ:
		nlm_write_reg(pciebase_le, (0x194 >> 2), 0xffffffff);
		break;
	}
}

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	return get_irq_vector(dev);
}

int pcibios_plat_dev_init(struct pci_dev *dev)
{
	return 0;
}

