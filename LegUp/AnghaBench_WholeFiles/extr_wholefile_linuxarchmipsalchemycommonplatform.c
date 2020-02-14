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
struct uart_port {int dummy; } ;
struct platform_device {int id; } ;

/* Variables and functions */
 int ALCHEMY_USB_EHCI0 ; 
 int ALCHEMY_USB_OHCI0 ; 
 int ALCHEMY_USB_OHCI1 ; 
 int alchemy_usb_control (int,int) ; 

__attribute__((used)) static void alchemy_8250_pm(struct uart_port *port, unsigned int state,
			    unsigned int old_state)
{
#ifdef CONFIG_SERIAL_8250
	switch (state) {
	case 0:
		alchemy_uart_enable(CPHYSADDR(port->membase));
		serial8250_do_pm(port, state, old_state);
		break;
	case 3:		/* power off */
		serial8250_do_pm(port, state, old_state);
		alchemy_uart_disable(CPHYSADDR(port->membase));
		break;
	default:
		serial8250_do_pm(port, state, old_state);
		break;
	}
#endif
}

__attribute__((used)) static int alchemy_ehci_power_on(struct platform_device *pdev)
{
	return alchemy_usb_control(ALCHEMY_USB_EHCI0, 1);
}

__attribute__((used)) static void alchemy_ehci_power_off(struct platform_device *pdev)
{
	alchemy_usb_control(ALCHEMY_USB_EHCI0, 0);
}

__attribute__((used)) static int alchemy_ohci_power_on(struct platform_device *pdev)
{
	int unit;

	unit = (pdev->id == 1) ?
		ALCHEMY_USB_OHCI1 : ALCHEMY_USB_OHCI0;

	return alchemy_usb_control(unit, 1);
}

__attribute__((used)) static void alchemy_ohci_power_off(struct platform_device *pdev)
{
	int unit;

	unit = (pdev->id == 1) ?
		ALCHEMY_USB_OHCI1 : ALCHEMY_USB_OHCI0;

	alchemy_usb_control(unit, 0);
}

