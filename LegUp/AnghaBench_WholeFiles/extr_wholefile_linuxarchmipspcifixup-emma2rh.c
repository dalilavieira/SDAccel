#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
struct pci_dev {int class; TYPE_1__* resource; int /*<<< orphan*/  devfn; } ;
struct TYPE_2__ {scalar_t__ flags; scalar_t__ end; scalar_t__ start; } ;

/* Variables and functions */
 scalar_t__ EMMA2RH_PCI_HOST_SLOT ; 
 scalar_t__ EMMA2RH_USB_SLOT ; 
 int PCI_CLASS_BRIDGE_HOST ; 
 int PCI_NUM_RESOURCES ; 
 scalar_t__ PCI_SLOT (int /*<<< orphan*/ ) ; 
 int** irq_map ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 

__attribute__((used)) static void nec_usb_controller_fixup(struct pci_dev *dev)
{
	if (PCI_SLOT(dev->devfn) == EMMA2RH_USB_SLOT)
		/* on board USB controller configuration */
		pci_write_config_dword(dev, 0xe4, 1 << 5);
}

__attribute__((used)) static void emma2rh_pci_host_fixup(struct pci_dev *dev)
{
	int i;

	if (PCI_SLOT(dev->devfn) == EMMA2RH_PCI_HOST_SLOT) {
		dev->class &= 0xff;
		dev->class |= PCI_CLASS_BRIDGE_HOST << 8;
		for (i = 0; i < PCI_NUM_RESOURCES; i++) {
			dev->resource[i].start = 0;
			dev->resource[i].end = 0;
			dev->resource[i].flags = 0;
		}
	}
}

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	return irq_map[slot][pin];
}

int pcibios_plat_dev_init(struct pci_dev *dev)
{
	return 0;
}

