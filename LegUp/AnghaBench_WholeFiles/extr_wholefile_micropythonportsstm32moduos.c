#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* uartx; } ;
typedef  TYPE_2__ pyb_uart_obj_t ;
typedef  int /*<<< orphan*/  mp_obj_type_t ;
typedef  int /*<<< orphan*/  mp_const_obj_t ;
struct TYPE_4__ {int ISR; } ;

/* Variables and functions */
 int USART_ISR_TXE ; 
 int /*<<< orphan*/ * mp_obj_get_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pyb_uart_type ; 

__attribute__((used)) static inline bool uart_tx_avail(pyb_uart_obj_t *self) {
    #if defined(STM32F4)
    return self->uartx->SR & USART_SR_TXE;
    #else
    return self->uartx->ISR & USART_ISR_TXE;
    #endif
}

bool mp_uos_dupterm_is_builtin_stream(mp_const_obj_t stream) {
    mp_obj_type_t *type = mp_obj_get_type(stream);
    return type == &pyb_uart_type
        #if MICROPY_HW_ENABLE_USB
        || type == &pyb_usb_vcp_type
        #endif
        ;
}

