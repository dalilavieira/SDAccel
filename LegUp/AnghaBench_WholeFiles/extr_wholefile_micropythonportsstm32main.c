#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/ * systick_dispatch_t ;
struct TYPE_7__ {TYPE_1__* uartx; } ;
typedef  TYPE_2__ pyb_uart_obj_t ;
struct TYPE_9__ {int /*<<< orphan*/  ICSR; } ;
struct TYPE_8__ {struct TYPE_8__* run_next; scalar_t__ local_state; } ;
struct TYPE_6__ {int ISR; } ;

/* Variables and functions */
 int /*<<< orphan*/  PYB_LED_GREEN ; 
 int /*<<< orphan*/  PYB_LED_RED ; 
 TYPE_5__* SCB ; 
 int /*<<< orphan*/  SCB_ICSR_PENDSVSET_Msk ; 
 int USART_ISR_TXE ; 
 int /*<<< orphan*/  __WFI () ; 
 int /*<<< orphan*/  led_state (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mp_hal_delay_ms (int) ; 
 TYPE_4__* pyb_thread_cur ; 
 int /*<<< orphan*/ ** systick_dispatch_table ; 

__attribute__((used)) static inline void systick_enable_dispatch(size_t slot, systick_dispatch_t f) {
    systick_dispatch_table[slot] = f;
}

__attribute__((used)) static inline void systick_disable_dispatch(size_t slot) {
    systick_dispatch_table[slot] = NULL;
}

__attribute__((used)) static inline uint32_t pyb_thread_get_id(void) {
    return (uint32_t)pyb_thread_cur;
}

__attribute__((used)) static inline void pyb_thread_set_local(void *value) {
    pyb_thread_cur->local_state = (uint32_t)value;
}

__attribute__((used)) static inline void *pyb_thread_get_local(void) {
    return (void*)pyb_thread_cur->local_state;
}

__attribute__((used)) static inline void pyb_thread_yield(void) {
    if (pyb_thread_cur->run_next == pyb_thread_cur) {
        __WFI();
    } else {
        SCB->ICSR = SCB_ICSR_PENDSVSET_Msk;
    }
}

__attribute__((used)) static inline bool uart_tx_avail(pyb_uart_obj_t *self) {
    #if defined(STM32F4)
    return self->uartx->SR & USART_SR_TXE;
    #else
    return self->uartx->ISR & USART_ISR_TXE;
    #endif
}

void flash_error(int n) {
    for (int i = 0; i < n; i++) {
        led_state(PYB_LED_RED, 1);
        led_state(PYB_LED_GREEN, 0);
        mp_hal_delay_ms(250);
        led_state(PYB_LED_RED, 0);
        led_state(PYB_LED_GREEN, 1);
        mp_hal_delay_ms(250);
    }
    led_state(PYB_LED_GREEN, 0);
}

