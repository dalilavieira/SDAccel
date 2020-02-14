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
typedef  int mp_uint_t ;
typedef  int /*<<< orphan*/  MP_STATE_PORT ;

/* Variables and functions */
 int interrupt_char ; 
 void mp_hal_stdout_tx_strn (char const*,size_t) ; 
 int /*<<< orphan*/  mp_obj_new_exception (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_type_KeyboardInterrupt ; 
 size_t strlen (char const*) ; 
 scalar_t__ uart_rx_any () ; 
 int uart_rx_char () ; 
 int /*<<< orphan*/  uart_tx_char (char) ; 

void mp_hal_init(void) {
    MP_STATE_PORT(keyboard_interrupt_obj) = mp_obj_new_exception(&mp_type_KeyboardInterrupt);
}

mp_uint_t mp_hal_ticks_ms(void) {
    // TODO
    return 0;
}

void mp_hal_delay_ms(mp_uint_t ms) {
    // tuned for fixed CPU frequency
    for (int i = ms; i > 0; i--) {
        for (volatile int j = 0; j < 5000; j++) {
        }
    }
}

void mp_hal_set_interrupt_char(int c) {
    interrupt_char = c;
}

int mp_hal_stdin_rx_chr(void) {
    for (;;) {
        if (uart_rx_any()) {
            return uart_rx_char();
        }
    }
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
    for (; len > 0; --len) {
        uart_tx_char(*str++);
    }
}

void mp_hal_stdout_tx_strn_cooked(const char *str, size_t len) {
    for (; len > 0; --len) {
        if (*str == '\n') {
            uart_tx_char('\r');
        }
        uart_tx_char(*str++);
    }
}

