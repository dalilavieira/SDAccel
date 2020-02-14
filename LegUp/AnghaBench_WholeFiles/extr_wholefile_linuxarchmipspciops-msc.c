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
struct pci_bus {unsigned char number; } ;

/* Variables and functions */
 int /*<<< orphan*/  MSC01_PCI_CFGADDR ; 
 unsigned char MSC01_PCI_CFGADDR_BNUM_SHF ; 
 unsigned char MSC01_PCI_CFGADDR_DNUM_SHF ; 
 unsigned char MSC01_PCI_CFGADDR_FNUM_SHF ; 
 int MSC01_PCI_CFGADDR_RNUM_SHF ; 
 int /*<<< orphan*/  MSC01_PCI_CFGDATA ; 
 int MSC01_PCI_INTCFG_MA_BIT ; 
 int MSC01_PCI_INTCFG_TA_BIT ; 
 int /*<<< orphan*/  MSC01_PCI_INTSTAT ; 
 int /*<<< orphan*/  MSC_READ (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MSC_WRITE (int /*<<< orphan*/ ,int) ; 
 int PCIBIOS_BAD_REGISTER_NUMBER ; 
 int PCIBIOS_SUCCESSFUL ; 
 unsigned char PCI_ACCESS_READ ; 
 unsigned char PCI_ACCESS_WRITE ; 
 unsigned char PCI_FUNC (unsigned int) ; 
 unsigned char PCI_SLOT (unsigned int) ; 

__attribute__((used)) static int msc_pcibios_config_access(unsigned char access_type,
	struct pci_bus *bus, unsigned int devfn, int where, u32 * data)
{
	unsigned char busnum = bus->number;
	u32 intr;

	/* Clear status register bits. */
	MSC_WRITE(MSC01_PCI_INTSTAT,
		  (MSC01_PCI_INTCFG_MA_BIT | MSC01_PCI_INTCFG_TA_BIT));

	MSC_WRITE(MSC01_PCI_CFGADDR,
		  ((busnum << MSC01_PCI_CFGADDR_BNUM_SHF) |
		   (PCI_SLOT(devfn) << MSC01_PCI_CFGADDR_DNUM_SHF) |
		   (PCI_FUNC(devfn) << MSC01_PCI_CFGADDR_FNUM_SHF) |
		   ((where / 4) << MSC01_PCI_CFGADDR_RNUM_SHF)));

	/* Perform access */
	if (access_type == PCI_ACCESS_WRITE)
		MSC_WRITE(MSC01_PCI_CFGDATA, *data);
	else
		MSC_READ(MSC01_PCI_CFGDATA, *data);

	/* Detect Master/Target abort */
	MSC_READ(MSC01_PCI_INTSTAT, intr);
	if (intr & (MSC01_PCI_INTCFG_MA_BIT | MSC01_PCI_INTCFG_TA_BIT)) {
		/* Error occurred */

		/* Clear bits */
		MSC_WRITE(MSC01_PCI_INTSTAT,
			  (MSC01_PCI_INTCFG_MA_BIT | MSC01_PCI_INTCFG_TA_BIT));

		return -1;
	}

	return 0;
}

__attribute__((used)) static int msc_pcibios_read(struct pci_bus *bus, unsigned int devfn,
			     int where, int size, u32 * val)
{
	u32 data = 0;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	if (msc_pcibios_config_access(PCI_ACCESS_READ, bus, devfn, where,
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

__attribute__((used)) static int msc_pcibios_write(struct pci_bus *bus, unsigned int devfn,
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
		if (msc_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
					      where, &data))
			return -1;

		if (size == 1)
			data = (data & ~(0xff << ((where & 3) << 3))) |
				(val << ((where & 3) << 3));
		else if (size == 2)
			data = (data & ~(0xffff << ((where & 3) << 3))) |
				(val << ((where & 3) << 3));
	}

	if (msc_pcibios_config_access(PCI_ACCESS_WRITE, bus, devfn, where,
				       &data))
		return -1;

	return PCIBIOS_SUCCESSFUL;
}

