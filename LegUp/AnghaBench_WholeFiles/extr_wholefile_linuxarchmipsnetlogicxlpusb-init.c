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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/  coherent_dma_mask; int /*<<< orphan*/ * dma_mask; } ;
struct pci_dev {int devfn; int /*<<< orphan*/  irq; TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  PIC_EHCI_0_IRQ ; 
 int /*<<< orphan*/  PIC_EHCI_1_IRQ ; 
 int /*<<< orphan*/  PIC_OHCI_0_IRQ ; 
 int /*<<< orphan*/  PIC_OHCI_1_IRQ ; 
 int /*<<< orphan*/  PIC_OHCI_2_IRQ ; 
 int /*<<< orphan*/  PIC_OHCI_3_IRQ ; 
 int USB_CONTROLLER_RESET ; 
 int /*<<< orphan*/  USB_CTL_0 ; 
 int USB_CTRL_INTERRUPT_EN ; 
 int /*<<< orphan*/  USB_INT_EN ; 
 int USB_OHCI_INTERRUPT1_EN ; 
 int USB_OHCI_INTERRUPT2_EN ; 
 int USB_OHCI_INTERRUPT_EN ; 
 int /*<<< orphan*/  USB_PHY_0 ; 
 int USB_PHY_PORT_RESET_0 ; 
 int USB_PHY_PORT_RESET_1 ; 
 int USB_PHY_RESET ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  nlm_get_usb_regbase (int,int) ; 
 int nlm_read_usb_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlm_write_usb_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  xlp_usb_dmamask ; 

__attribute__((used)) static void nlm_usb_intr_en(int node, int port)
{
	uint32_t val;
	uint64_t port_addr;

	port_addr = nlm_get_usb_regbase(node, port);
	val = nlm_read_usb_reg(port_addr, USB_INT_EN);
	val = USB_CTRL_INTERRUPT_EN  | USB_OHCI_INTERRUPT_EN |
		USB_OHCI_INTERRUPT1_EN | USB_OHCI_INTERRUPT2_EN;
	nlm_write_usb_reg(port_addr, USB_INT_EN, val);
}

__attribute__((used)) static void nlm_usb_hw_reset(int node, int port)
{
	uint64_t port_addr;
	uint32_t val;

	/* reset USB phy */
	port_addr = nlm_get_usb_regbase(node, port);
	val = nlm_read_usb_reg(port_addr, USB_PHY_0);
	val &= ~(USB_PHY_RESET | USB_PHY_PORT_RESET_0 | USB_PHY_PORT_RESET_1);
	nlm_write_usb_reg(port_addr, USB_PHY_0, val);

	mdelay(100);
	val = nlm_read_usb_reg(port_addr, USB_CTL_0);
	val &= ~(USB_CONTROLLER_RESET);
	val |= 0x4;
	nlm_write_usb_reg(port_addr, USB_CTL_0, val);
}

__attribute__((used)) static void nlm_usb_fixup_final(struct pci_dev *dev)
{
	dev->dev.dma_mask		= &xlp_usb_dmamask;
	dev->dev.coherent_dma_mask	= DMA_BIT_MASK(32);
	switch (dev->devfn) {
	case 0x10:
		dev->irq = PIC_EHCI_0_IRQ;
		break;
	case 0x11:
		dev->irq = PIC_OHCI_0_IRQ;
		break;
	case 0x12:
		dev->irq = PIC_OHCI_1_IRQ;
		break;
	case 0x13:
		dev->irq = PIC_EHCI_1_IRQ;
		break;
	case 0x14:
		dev->irq = PIC_OHCI_2_IRQ;
		break;
	case 0x15:
		dev->irq = PIC_OHCI_3_IRQ;
		break;
	}
}

