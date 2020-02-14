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
typedef  scalar_t__ uint32_t ;
typedef  scalar_t__ mp_uint_t ;

/* Variables and functions */
 scalar_t__ mp_hal_ticks_ms () ; 
 scalar_t__ mp_hal_ticks_us () ; 
 int mp_interrupt_char ; 
 scalar_t__ mp_js_ticks_ms () ; 
 int /*<<< orphan*/  mp_js_write (char const*,size_t) ; 

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
    mp_js_write(str, len);
}

void mp_hal_delay_ms(mp_uint_t ms) {
    uint32_t start = mp_hal_ticks_ms();
    while (mp_hal_ticks_ms() - start < ms) {
    }
}

void mp_hal_delay_us(mp_uint_t us) {
    uint32_t start = mp_hal_ticks_us();
    while (mp_hal_ticks_us() - start < us) {
    }
}

mp_uint_t mp_hal_ticks_us(void) {
    return mp_js_ticks_ms() * 1000;
}

mp_uint_t mp_hal_ticks_ms(void) {
    return mp_js_ticks_ms();
}

mp_uint_t mp_hal_ticks_cpu(void) {
    return 0;
}

int mp_hal_get_interrupt_char(void) {
    return mp_interrupt_char;
}

