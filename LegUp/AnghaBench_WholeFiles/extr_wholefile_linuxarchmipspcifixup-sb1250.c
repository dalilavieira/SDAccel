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
struct pci_dev {int class; } ;

/* Variables and functions */
 int PCI_CLASS_BRIDGE_PCI ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,int) ; 

__attribute__((used)) static void quirk_sb1250_pci(struct pci_dev *dev)
{
	pci_write_config_byte(dev, 0x40, 0xff);
}

__attribute__((used)) static void quirk_sb1250_ht(struct pci_dev *dev)
{
	dev->class = PCI_CLASS_BRIDGE_PCI << 8;
}

__attribute__((used)) static void quirk_sp1011(struct pci_dev *dev)
{
	pci_write_config_byte(dev, 0x64, 0xff);
}

