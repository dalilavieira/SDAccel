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
typedef  int uint32_t ;
typedef  int u32 ;
struct pci_bus {int number; int /*<<< orphan*/ * parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  EMMA2RH_PCI_CONFIG_BASE ; 
 int /*<<< orphan*/  EMMA2RH_PCI_INT ; 
 int /*<<< orphan*/  EMMA2RH_PCI_IWIN0_CTR ; 
 int KSEG1ADDR (int /*<<< orphan*/ ) ; 
 int PCIBIOS_DEVICE_NOT_FOUND ; 
 int PCIBIOS_FUNC_NOT_SUPPORTED ; 
 int PCIBIOS_SUCCESSFUL ; 
 int PCI_FUNC (unsigned int) ; 
 int PCI_SLOT (unsigned int) ; 
 int RMABORT ; 
 int emma2rh_in32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emma2rh_out32 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int check_args(struct pci_bus *bus, u32 devfn, u32 * bus_num)
{
	/* check if the bus is top-level */
	if (bus->parent != NULL)
		*bus_num = bus->number;
	else
		*bus_num = 0;

	if (*bus_num == 0) {
		/* Type 0 */
		if (PCI_SLOT(devfn) >= 10)
			return PCIBIOS_DEVICE_NOT_FOUND;
	} else {
		/* Type 1 */
		if ((*bus_num >= 64) || (PCI_SLOT(devfn) >= 16))
			return PCIBIOS_DEVICE_NOT_FOUND;
	}
	return 0;
}

__attribute__((used)) static inline int set_pci_configuration_address(unsigned char bus_num,
						unsigned int devfn, int where)
{
	u32 config_win0;

	emma2rh_out32(EMMA2RH_PCI_INT, ~RMABORT);
	if (bus_num == 0)
		/*
		 * Type 0 configuration
		 */
		config_win0 = (1 << (22 + PCI_SLOT(devfn))) | (5 << 9);
	else
		/*
		 * Type 1 configuration
		 */
		config_win0 = (bus_num << 26) | (PCI_SLOT(devfn) << 22) |
		    (1 << 15) | (5 << 9);

	emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, config_win0);

	return 0;
}

__attribute__((used)) static int pci_config_read(struct pci_bus *bus, unsigned int devfn, int where,
			   int size, uint32_t * val)
{
	u32 bus_num;
	u32 base = KSEG1ADDR(EMMA2RH_PCI_CONFIG_BASE);
	u32 backup_win0;
	u32 data;

	*val = 0xffffffffU;

	if (check_args(bus, devfn, &bus_num) == PCIBIOS_DEVICE_NOT_FOUND)
		return PCIBIOS_DEVICE_NOT_FOUND;

	backup_win0 = emma2rh_in32(EMMA2RH_PCI_IWIN0_CTR);

	if (set_pci_configuration_address(bus_num, devfn, where) < 0)
		return PCIBIOS_DEVICE_NOT_FOUND;

	data =
	    *(volatile u32 *)(base + (PCI_FUNC(devfn) << 8) +
			      (where & 0xfffffffc));

	switch (size) {
	case 1:
		*val = (data >> ((where & 3) << 3)) & 0xffU;
		break;
	case 2:
		*val = (data >> ((where & 2) << 3)) & 0xffffU;
		break;
	case 4:
		*val = data;
		break;
	default:
		emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
		return PCIBIOS_FUNC_NOT_SUPPORTED;
	}

	emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);

	if (emma2rh_in32(EMMA2RH_PCI_INT) & RMABORT)
		return PCIBIOS_DEVICE_NOT_FOUND;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int pci_config_write(struct pci_bus *bus, unsigned int devfn, int where,
			    int size, u32 val)
{
	u32 bus_num;
	u32 base = KSEG1ADDR(EMMA2RH_PCI_CONFIG_BASE);
	u32 backup_win0;
	u32 data;
	int shift;

	if (check_args(bus, devfn, &bus_num) == PCIBIOS_DEVICE_NOT_FOUND)
		return PCIBIOS_DEVICE_NOT_FOUND;

	backup_win0 = emma2rh_in32(EMMA2RH_PCI_IWIN0_CTR);

	if (set_pci_configuration_address(bus_num, devfn, where) < 0)
		return PCIBIOS_DEVICE_NOT_FOUND;

	/* read modify write */
	data =
	    *(volatile u32 *)(base + (PCI_FUNC(devfn) << 8) +
			      (where & 0xfffffffc));

	switch (size) {
	case 1:
		shift = (where & 3) << 3;
		data &= ~(0xffU << shift);
		data |= ((val & 0xffU) << shift);
		break;
	case 2:
		shift = (where & 2) << 3;
		data &= ~(0xffffU << shift);
		data |= ((val & 0xffffU) << shift);
		break;
	case 4:
		data = val;
		break;
	default:
		emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
		return PCIBIOS_FUNC_NOT_SUPPORTED;
	}
	*(volatile u32 *)(base + (PCI_FUNC(devfn) << 8) +
			  (where & 0xfffffffc)) = data;

	emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
	if (emma2rh_in32(EMMA2RH_PCI_INT) & RMABORT)
		return PCIBIOS_DEVICE_NOT_FOUND;

	return PCIBIOS_SUCCESSFUL;
}

