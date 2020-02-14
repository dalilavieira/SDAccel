#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_6__ {int pin; int pin_mask; TYPE_2__* gpio; } ;
typedef  TYPE_1__ pin_obj_t ;
struct TYPE_7__ {int MODER; int OTYPER; int PUPDR; int* AFR; } ;
typedef  TYPE_2__ GPIO_TypeDef ;

/* Variables and functions */
 int GPIO_MODE_ANALOG ; 

uint32_t pin_get_mode(const pin_obj_t *pin) {
    GPIO_TypeDef *gpio = pin->gpio;
    uint32_t mode = (gpio->MODER >> (pin->pin * 2)) & 3;
    if (mode != GPIO_MODE_ANALOG) {
        if (gpio->OTYPER & pin->pin_mask) {
            mode |= 1 << 4;
        }
    }
    return mode;
}

uint32_t pin_get_pull(const pin_obj_t *pin) {
    return (pin->gpio->PUPDR >> (pin->pin * 2)) & 3;
}

uint32_t pin_get_af(const pin_obj_t *pin) {
    return (pin->gpio->AFR[pin->pin >> 3] >> ((pin->pin & 7) * 4)) & 0xf;
}

