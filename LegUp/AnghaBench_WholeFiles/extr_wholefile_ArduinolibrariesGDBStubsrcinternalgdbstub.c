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

/* Variables and functions */

bool gdbstub_has_putc1_control() {
#if GDBSTUB_REDIRECT_CONSOLE_OUTPUT
	return true;
#else
	return false;
#endif
}

bool gdbstub_has_uart_isr_control() {
#if GDBSTUB_CTRLC_BREAK
	return true;
#else
	return false;
#endif
}

