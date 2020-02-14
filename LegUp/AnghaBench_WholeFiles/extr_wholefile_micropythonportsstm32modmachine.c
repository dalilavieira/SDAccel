#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_8__ {TYPE_1__* uartx; } ;
typedef  TYPE_2__ pyb_uart_obj_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;
struct TYPE_11__ {int RCC_SR; } ;
struct TYPE_10__ {int /*<<< orphan*/  ICSR; } ;
struct TYPE_9__ {int local_state; struct TYPE_9__* run_next; } ;
struct TYPE_7__ {int ISR; } ;

/* Variables and functions */
 int /*<<< orphan*/  PYB_RESET_HARD ; 
 int /*<<< orphan*/  PYB_RESET_POWER_ON ; 
 int /*<<< orphan*/  PYB_RESET_SOFT ; 
 int /*<<< orphan*/  PYB_RESET_WDT ; 
 TYPE_6__* RCC ; 
 int RCC_SR_BORRSTF ; 
 int RCC_SR_IWDGRSTF ; 
 int RCC_SR_PINRSTF ; 
 int RCC_SR_PORRSTF ; 
 int RCC_SR_RMVF ; 
 int RCC_SR_WWDGRSTF ; 
 TYPE_5__* SCB ; 
 int /*<<< orphan*/  SCB_ICSR_PENDSVSET_Msk ; 
 int USART_ISR_TXE ; 
 int /*<<< orphan*/  __WFI () ; 
 int /*<<< orphan*/  __get_PRIMASK () ; 
 TYPE_4__* pyb_thread_cur ; 
 int /*<<< orphan*/  reset_cause ; 

__attribute__((used)) static inline mp_uint_t query_irq(void) {
    return __get_PRIMASK();
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

void machine_init(void) {
    #if defined(STM32F4)
    if (PWR->CSR & PWR_CSR_SBF) {
        // came out of standby
        reset_cause = PYB_RESET_DEEPSLEEP;
        PWR->CR |= PWR_CR_CSBF;
    } else
    #elif defined(STM32F7)
    if (PWR->CSR1 & PWR_CSR1_SBF) {
        // came out of standby
        reset_cause = PYB_RESET_DEEPSLEEP;
        PWR->CR1 |= PWR_CR1_CSBF;
    } else
    #elif defined(STM32H7)
    if (PWR->CPUCR & PWR_CPUCR_SBF || PWR->CPUCR & PWR_CPUCR_STOPF) {
        // came out of standby or stop mode
        reset_cause = PYB_RESET_DEEPSLEEP;
        PWR->CPUCR |= PWR_CPUCR_CSSF;
    } else
    #elif defined(STM32L4)
    if (PWR->SR1 & PWR_SR1_SBF) {
        // came out of standby
        reset_cause = PYB_RESET_DEEPSLEEP;
        PWR->SCR |= PWR_SCR_CSBF;
    } else
    #endif
    {
        // get reset cause from RCC flags
        uint32_t state = RCC->RCC_SR;
        if (state & RCC_SR_IWDGRSTF || state & RCC_SR_WWDGRSTF) {
            reset_cause = PYB_RESET_WDT;
        } else if (state & RCC_SR_PORRSTF
            #if !defined(STM32F0)
            || state & RCC_SR_BORRSTF
            #endif
            ) {
            reset_cause = PYB_RESET_POWER_ON;
        } else if (state & RCC_SR_PINRSTF) {
            reset_cause = PYB_RESET_HARD;
        } else {
            // default is soft reset
            reset_cause = PYB_RESET_SOFT;
        }
    }
    // clear RCC reset flags
    RCC->RCC_SR |= RCC_SR_RMVF;
}

void machine_deinit(void) {
    // we are doing a soft-reset so change the reset_cause
    reset_cause = PYB_RESET_SOFT;
}

