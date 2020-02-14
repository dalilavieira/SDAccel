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
typedef  int uint8_t ;

/* Variables and functions */
 int USB_SERIAL_DTR ; 
 int USB_SERIAL_RTS ; 
 int strlen (char const*) ; 
 int usb_cdc_line_rtsdtr ; 
 scalar_t__ usb_configuration ; 
 int usb_serial_available () ; 
 int usb_serial_getchar () ; 
 int /*<<< orphan*/  usb_serial_putchar (char const) ; 
 int /*<<< orphan*/  usb_serial_write (char const*,int) ; 
 void usb_vcp_send_strn (char const*,int) ; 

bool usb_vcp_is_connected(void)
{
  return usb_configuration && (usb_cdc_line_rtsdtr & (USB_SERIAL_DTR | USB_SERIAL_RTS));
}

bool usb_vcp_is_enabled(void)
{
  return true;
}

int usb_vcp_rx_num(void) {
  return usb_serial_available();
}

int usb_vcp_recv_byte(uint8_t *ptr)
{
  int ch = usb_serial_getchar();
  if (ch < 0) {
    return 0;
  }
  *ptr = ch;
  return 1;
}

void usb_vcp_send_str(const char* str)
{
  usb_vcp_send_strn(str, strlen(str));
}

void usb_vcp_send_strn(const char* str, int len)
{
  usb_serial_write(str, len);
}

void usb_vcp_send_strn_cooked(const char *str, int len)
{
  for (const char *top = str + len; str < top; str++) {
    if (*str == '\n') {
      usb_serial_putchar('\r');
    }
    usb_serial_putchar(*str);
  }
}

