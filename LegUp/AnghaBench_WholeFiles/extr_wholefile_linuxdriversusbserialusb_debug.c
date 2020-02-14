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
struct usb_serial_port {int dummy; } ;
struct urb {scalar_t__ actual_length; int /*<<< orphan*/  transfer_buffer; struct usb_serial_port* context; } ;
struct tty_struct {struct usb_serial_port* driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  USB_DEBUG_BRK ; 
 scalar_t__ USB_DEBUG_BRK_SIZE ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  usb_serial_generic_process_read_urb (struct urb*) ; 
 int /*<<< orphan*/  usb_serial_generic_write (struct tty_struct*,struct usb_serial_port*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  usb_serial_handle_break (struct usb_serial_port*) ; 

__attribute__((used)) static void usb_debug_break_ctl(struct tty_struct *tty, int break_state)
{
	struct usb_serial_port *port = tty->driver_data;
	if (!break_state)
		return;
	usb_serial_generic_write(tty, port, USB_DEBUG_BRK, USB_DEBUG_BRK_SIZE);
}

__attribute__((used)) static void usb_debug_process_read_urb(struct urb *urb)
{
	struct usb_serial_port *port = urb->context;

	if (urb->actual_length == USB_DEBUG_BRK_SIZE &&
		memcmp(urb->transfer_buffer, USB_DEBUG_BRK,
						USB_DEBUG_BRK_SIZE) == 0) {
		usb_serial_handle_break(port);
		return;
	}

	usb_serial_generic_process_read_urb(urb);
}

