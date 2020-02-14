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
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  mp_uint_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_UART_CONSOLE_ON_DEV_NAME ; 
 struct device* device_get_binding (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uart_poll_out (struct device*,int /*<<< orphan*/ ) ; 
 int zephyr_getchar () ; 

int mp_hal_stdin_rx_chr(void) {
#ifdef CONFIG_CONSOLE_SUBSYS
    return console_getchar();
#else
    return zephyr_getchar();
#endif
}

void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
#ifdef CONFIG_CONSOLE_SUBSYS
    while (len--) {
        char c = *str++;
        while (console_putchar(c) == -1) {
            k_sleep(1);
        }
    }
#else
    static struct device *uart_console_dev;
    if (uart_console_dev == NULL) {
        uart_console_dev = device_get_binding(CONFIG_UART_CONSOLE_ON_DEV_NAME);
    }

    while (len--) {
        uart_poll_out(uart_console_dev, *str++);
    }
#endif
}

