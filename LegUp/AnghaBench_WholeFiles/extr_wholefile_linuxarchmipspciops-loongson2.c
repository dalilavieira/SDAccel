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
struct pci_bus {int number; } ;

/* Variables and functions */
 void* CFG_SPACE_REG (int) ; 
 int ID_SEL_BEGIN ; 
 int LOONGSON_PCICMD ; 
 int LOONGSON_PCICMD_MABORT_CLR ; 
 int LOONGSON_PCICMD_MTABORT_CLR ; 
 int LOONGSON_PCIMAP_CFG ; 
 int MAX_DEV_NUM ; 
 int PCIBIOS_BAD_REGISTER_NUMBER ; 
 int PCIBIOS_SUCCESSFUL ; 
 unsigned char PCI_ACCESS_READ ; 
 unsigned char PCI_ACCESS_WRITE ; 
 int PCI_FUNC (unsigned int) ; 
 int PCI_SLOT (unsigned int) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmiowb () ; 
 int /*<<< orphan*/  readl (void*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static int loongson_pcibios_config_access(unsigned char access_type,
				      struct pci_bus *bus,
				      unsigned int devfn, int where,
				      u32 *data)
{
	u32 busnum = bus->number;
	u32 addr, type;
	u32 dummy;
	void *addrp;
	int device = PCI_SLOT(devfn);
	int function = PCI_FUNC(devfn);
	int reg = where & ~3;

	if (busnum == 0) {
		/* board-specific part,currently,only fuloong2f,yeeloong2f
		 * use CS5536, fuloong2e use via686b, gdium has no
		 * south bridge
		 */
#ifdef CONFIG_CS5536
		/* cs5536_pci_conf_read4/write4() will call _rdmsr/_wrmsr() to
		 * access the regsters PCI_MSR_ADDR, PCI_MSR_DATA_LO,
		 * PCI_MSR_DATA_HI, which is bigger than PCI_MSR_CTRL, so, it
		 * will not go this branch, but the others. so, no calling dead
		 * loop here.
		 */
		if ((PCI_IDSEL_CS5536 == device) && (reg < PCI_MSR_CTRL)) {
			switch (access_type) {
			case PCI_ACCESS_READ:
				*data = cs5536_pci_conf_read4(function, reg);
				break;
			case PCI_ACCESS_WRITE:
				cs5536_pci_conf_write4(function, reg, *data);
				break;
			}
			return 0;
		}
#endif
		/* Type 0 configuration for onboard PCI bus */
		if (device > MAX_DEV_NUM)
			return -1;

		addr = (1 << (device + ID_SEL_BEGIN)) | (function << 8) | reg;
		type = 0;
	} else {
		/* Type 1 configuration for offboard PCI bus */
		addr = (busnum << 16) | (device << 11) | (function << 8) | reg;
		type = 0x10000;
	}

	/* Clear aborts */
	LOONGSON_PCICMD |= LOONGSON_PCICMD_MABORT_CLR | \
				LOONGSON_PCICMD_MTABORT_CLR;

	LOONGSON_PCIMAP_CFG = (addr >> 16) | type;

	/* Flush Bonito register block */
	dummy = LOONGSON_PCIMAP_CFG;
	mmiowb();

	addrp = CFG_SPACE_REG(addr & 0xffff);
	if (access_type == PCI_ACCESS_WRITE)
		writel(cpu_to_le32(*data), addrp);
	else
		*data = le32_to_cpu(readl(addrp));

	/* Detect Master/Target abort */
	if (LOONGSON_PCICMD & (LOONGSON_PCICMD_MABORT_CLR |
			     LOONGSON_PCICMD_MTABORT_CLR)) {
		/* Error occurred */

		/* Clear bits */
		LOONGSON_PCICMD |= (LOONGSON_PCICMD_MABORT_CLR |
				  LOONGSON_PCICMD_MTABORT_CLR);

		return -1;
	}

	return 0;

}

__attribute__((used)) static int loongson_pcibios_read(struct pci_bus *bus, unsigned int devfn,
			     int where, int size, u32 *val)
{
	u32 data = 0;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	if (loongson_pcibios_config_access(PCI_ACCESS_READ, bus, devfn, where,
				       &data))
		return -1;

	if (size == 1)
		*val = (data >> ((where & 3) << 3)) & 0xff;
	else if (size == 2)
		*val = (data >> ((where & 3) << 3)) & 0xffff;
	else
		*val = data;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int loongson_pcibios_write(struct pci_bus *bus, unsigned int devfn,
			      int where, int size, u32 val)
{
	u32 data = 0;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	if (size == 4)
		data = val;
	else {
		if (loongson_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
					where, &data))
			return -1;

		if (size == 1)
			data = (data & ~(0xff << ((where & 3) << 3))) |
				(val << ((where & 3) << 3));
		else if (size == 2)
			data = (data & ~(0xffff << ((where & 3) << 3))) |
				(val << ((where & 3) << 3));
	}

	if (loongson_pcibios_config_access(PCI_ACCESS_WRITE, bus, devfn, where,
				       &data))
		return -1;

	return PCIBIOS_SUCCESSFUL;
}

