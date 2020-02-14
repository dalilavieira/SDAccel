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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  size_t uint ;
typedef  int /*<<< orphan*/  pyb_uart_obj_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;
typedef  int /*<<< orphan*/  mp_obj_t ;
typedef  int byte ;
typedef  int /*<<< orphan*/  GPIO_TypeDef ;

/* Variables and functions */
 int /*<<< orphan*/ * MP_STATE_PORT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __WFI () ; 
 int /*<<< orphan*/  delay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  millis () ; 
 void mp_hal_stdout_tx_strn (char const*,size_t) ; 
 int /*<<< orphan*/  mp_raise_NotImplementedError (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pyb_stdio_uart ; 
 size_t strlen (char const*) ; 
 scalar_t__ uart_rx_any (int /*<<< orphan*/ *) ; 
 int uart_rx_char (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uart_tx_strn (int /*<<< orphan*/ *,char const*,size_t) ; 
 scalar_t__ usb_vcp_is_enabled () ; 
 scalar_t__ usb_vcp_recv_byte (int*) ; 
 int /*<<< orphan*/  usb_vcp_send_strn (char const*,size_t) ; 
 int /*<<< orphan*/  usb_vcp_send_strn_cooked (char const*,size_t) ; 

mp_uint_t mp_hal_ticks_ms(void) {
  return millis();
}

void mp_hal_delay_ms(mp_uint_t ms) {
  delay(ms);
}

void mp_hal_set_interrupt_char(int c) {
  // The teensy 3.1 usb stack doesn't currently have the notion of generating
  // an exception when a certain character is received. That just means that
  // you can't press Control-C and get your python script to stop.
}

int mp_hal_stdin_rx_chr(void) {
    for (;;) {
        byte c;
        if (usb_vcp_recv_byte(&c) != 0) {
            return c;
        } else if (MP_STATE_PORT(pyb_stdio_uart) != NULL && uart_rx_any(MP_STATE_PORT(pyb_stdio_uart))) {
            return uart_rx_char(MP_STATE_PORT(pyb_stdio_uart));
        }
        __WFI();
    }
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
    if (MP_STATE_PORT(pyb_stdio_uart) != NULL) {
        uart_tx_strn(MP_STATE_PORT(pyb_stdio_uart), str, len);
    }
    if (usb_vcp_is_enabled()) {
        usb_vcp_send_strn(str, len);
    }
}

void mp_hal_stdout_tx_strn_cooked(const char *str, size_t len) {
    // send stdout to UART and USB CDC VCP
    if (MP_STATE_PORT(pyb_stdio_uart) != NULL) {
        void uart_tx_strn_cooked(pyb_uart_obj_t *uart_obj, const char *str, uint len);
        uart_tx_strn_cooked(MP_STATE_PORT(pyb_stdio_uart), str, len);
    }
    if (usb_vcp_is_enabled()) {
        usb_vcp_send_strn_cooked(str, len);
    }
}

void mp_hal_gpio_clock_enable(GPIO_TypeDef *gpio) {
}

void extint_register_pin(const void *pin, uint32_t mode, int hard_irq, mp_obj_t callback_obj) {
    mp_raise_NotImplementedError(NULL);
}

