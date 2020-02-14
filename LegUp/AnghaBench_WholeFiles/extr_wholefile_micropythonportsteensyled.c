#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int pyb_led_t ;
struct TYPE_12__ {int /*<<< orphan*/  led_id; } ;
typedef  TYPE_1__ pyb_led_obj_t ;
struct TYPE_13__ {int pin_mask; TYPE_4__* gpio; } ;
typedef  TYPE_2__ pin_obj_t ;
typedef  int /*<<< orphan*/  mp_print_t ;
typedef  int /*<<< orphan*/  mp_print_kind_t ;
typedef  TYPE_1__* mp_obj_t ;
struct TYPE_16__ {TYPE_2__* led_pin; } ;
struct TYPE_15__ {int Pin; int /*<<< orphan*/  Pull; int /*<<< orphan*/  Mode; int /*<<< orphan*/  Speed; } ;
struct TYPE_14__ {int PDOR; int PCOR; int PSOR; } ;
typedef  TYPE_4__ GPIO_TypeDef ;
typedef  TYPE_5__ GPIO_InitTypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_NOPULL ; 
 int /*<<< orphan*/  GPIO_SPEED_FREQ_LOW ; 
 int /*<<< orphan*/  HAL_GPIO_Init (TYPE_4__*,TYPE_5__*) ; 
 int /*<<< orphan*/  MICROPY_HW_LED_OFF (TYPE_2__ const*) ; 
 int /*<<< orphan*/  MICROPY_HW_LED_ON (TYPE_2__ const*) ; 
 int /*<<< orphan*/  MICROPY_HW_LED_OTYPE ; 
 int NUM_LEDS ; 
 int /*<<< orphan*/  mp_printf (int /*<<< orphan*/  const*,char*,int /*<<< orphan*/ ) ; 
 TYPE_6__* pyb_led_obj ; 

void led_init(void) {
    /* GPIO structure */
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Configure I/O speed, mode, output type and pull */
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.Mode = MICROPY_HW_LED_OTYPE;
    GPIO_InitStructure.Pull = GPIO_NOPULL;

    /* Turn off LEDs and initialize */
    for (int led = 0; led < NUM_LEDS; led++) {
        const pin_obj_t *led_pin = pyb_led_obj[led].led_pin;
        MICROPY_HW_LED_OFF(led_pin);
        GPIO_InitStructure.Pin = led_pin->pin_mask;
        HAL_GPIO_Init(led_pin->gpio, &GPIO_InitStructure);
    }
}

void led_state(pyb_led_t led, int state) {
    if (led < 1 || led > NUM_LEDS) {
        return;
    }
    const pin_obj_t *led_pin = pyb_led_obj[led - 1].led_pin;
    //printf("led_state(%d,%d)\n", led, state);
    if (state == 0) {
        // turn LED off
        MICROPY_HW_LED_OFF(led_pin);
    } else {
        // turn LED on
        MICROPY_HW_LED_ON(led_pin);
    }
}

void led_toggle(pyb_led_t led) {
    if (led < 1 || led > NUM_LEDS) {
        return;
    }
    const pin_obj_t *led_pin = pyb_led_obj[led - 1].led_pin;
    GPIO_TypeDef *gpio = led_pin->gpio;

    // We don't know if we're turning the LED on or off, but we don't really
    // care. Just invert the state.
    if (gpio->PDOR & led_pin->pin_mask) {
        // pin is high, make it low
        gpio->PCOR = led_pin->pin_mask;
    } else {
        // pin is low, make it high
        gpio->PSOR = led_pin->pin_mask;
    }
}

void led_obj_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    pyb_led_obj_t *self = self_in;
    (void)kind;
    mp_printf(print, "<LED %lu>", self->led_id);
}

