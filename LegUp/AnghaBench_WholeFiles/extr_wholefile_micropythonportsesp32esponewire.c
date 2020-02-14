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
typedef  int /*<<< orphan*/  mp_hal_pin_obj_t ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY_US (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MICROPY_BEGIN_ATOMIC_SECTION () ; 
 int /*<<< orphan*/  MICROPY_END_ATOMIC_SECTION (int /*<<< orphan*/ ) ; 
 size_t TIMING_READ1 ; 
 size_t TIMING_READ2 ; 
 size_t TIMING_READ3 ; 
 size_t TIMING_RESET1 ; 
 size_t TIMING_RESET2 ; 
 size_t TIMING_RESET3 ; 
 size_t TIMING_WRITE1 ; 
 size_t TIMING_WRITE2 ; 
 size_t TIMING_WRITE3 ; 
 int /*<<< orphan*/ * esp_onewire_timings ; 
 int mp_hal_pin_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_hal_pin_write (int /*<<< orphan*/ ,int) ; 

int esp_onewire_reset(mp_hal_pin_obj_t pin) {
    mp_hal_pin_write(pin, 0);
    DELAY_US(esp_onewire_timings[TIMING_RESET1]);
    uint32_t i = MICROPY_BEGIN_ATOMIC_SECTION();
    mp_hal_pin_write(pin, 1);
    DELAY_US(esp_onewire_timings[TIMING_RESET2]);
    int status = !mp_hal_pin_read(pin);
    MICROPY_END_ATOMIC_SECTION(i);
    DELAY_US(esp_onewire_timings[TIMING_RESET3]);
    return status;
}

int esp_onewire_readbit(mp_hal_pin_obj_t pin) {
    mp_hal_pin_write(pin, 1);
    uint32_t i = MICROPY_BEGIN_ATOMIC_SECTION();
    mp_hal_pin_write(pin, 0);
    DELAY_US(esp_onewire_timings[TIMING_READ1]);
    mp_hal_pin_write(pin, 1);
    DELAY_US(esp_onewire_timings[TIMING_READ2]);
    int value = mp_hal_pin_read(pin);
    MICROPY_END_ATOMIC_SECTION(i);
    DELAY_US(esp_onewire_timings[TIMING_READ3]);
    return value;
}

void esp_onewire_writebit(mp_hal_pin_obj_t pin, int value) {
    uint32_t i = MICROPY_BEGIN_ATOMIC_SECTION();
    mp_hal_pin_write(pin, 0);
    DELAY_US(esp_onewire_timings[TIMING_WRITE1]);
    if (value) {
        mp_hal_pin_write(pin, 1);
    }
    DELAY_US(esp_onewire_timings[TIMING_WRITE2]);
    mp_hal_pin_write(pin, 1);
    DELAY_US(esp_onewire_timings[TIMING_WRITE3]);
    MICROPY_END_ATOMIC_SECTION(i);
}

