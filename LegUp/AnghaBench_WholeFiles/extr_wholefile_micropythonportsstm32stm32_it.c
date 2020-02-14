#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_10__ {TYPE_1__* uartx; } ;
typedef  TYPE_2__ pyb_uart_obj_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;
struct TYPE_14__ {int /*<<< orphan*/  ISR; } ;
struct TYPE_13__ {int /*<<< orphan*/  ICSR; } ;
struct TYPE_12__ {struct TYPE_12__* run_next; scalar_t__ local_state; } ;
struct TYPE_11__ {scalar_t__ xpsr; scalar_t__ pc; scalar_t__ lr; scalar_t__ r12; scalar_t__ r3; scalar_t__ r2; scalar_t__ r1; scalar_t__ r0; } ;
struct TYPE_9__ {int ISR; } ;
typedef  TYPE_3__ ExceptionRegisters_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXTI0_IRQn ; 
 int /*<<< orphan*/  EXTI15_10_IRQn ; 
 int /*<<< orphan*/  EXTI1_IRQn ; 
 int /*<<< orphan*/  EXTI2_IRQn ; 
 int /*<<< orphan*/  EXTI3_IRQn ; 
 int /*<<< orphan*/  EXTI4_IRQn ; 
 int /*<<< orphan*/  EXTI9_5_IRQn ; 
 int EXTI_PVD_OUTPUT ; 
 int EXTI_RTC_ALARM ; 
 int EXTI_RTC_TIMESTAMP ; 
 int EXTI_RTC_WAKEUP ; 
 int /*<<< orphan*/  HAL_TIM_IRQHandler (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Handle_EXTI_Irq (int) ; 
 int /*<<< orphan*/  IRQ_ENTER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQ_EXIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NVIC_SystemReset () ; 
 int /*<<< orphan*/  PVD_IRQn ; 
 TYPE_7__* RTC ; 
 int /*<<< orphan*/  RTC_Alarm_IRQn ; 
 int /*<<< orphan*/  RTC_ISR_WUTF ; 
 int /*<<< orphan*/  RTC_WKUP_IRQn ; 
 TYPE_6__* SCB ; 
 int /*<<< orphan*/  SCB_ICSR_PENDSVSET_Msk ; 
 int /*<<< orphan*/  TAMP_STAMP_IRQn ; 
 int /*<<< orphan*/  TIM1_BRK_TIM9_IRQn ; 
 int /*<<< orphan*/  TIM1_CC_IRQn ; 
 int /*<<< orphan*/  TIM1_TRG_COM_TIM11_IRQn ; 
 int /*<<< orphan*/  TIM1_UP_TIM10_IRQn ; 
 int /*<<< orphan*/  TIM2_IRQn ; 
 int /*<<< orphan*/  TIM3_IRQn ; 
 int /*<<< orphan*/  TIM4_IRQn ; 
 int /*<<< orphan*/  TIM5_Handle ; 
 int /*<<< orphan*/  TIM5_IRQn ; 
 int /*<<< orphan*/  UART4_IRQn ; 
 int /*<<< orphan*/  UART5_IRQn ; 
 int /*<<< orphan*/  USART1_IRQn ; 
 int /*<<< orphan*/  USART2_IRQn ; 
 int /*<<< orphan*/  USART3_IRQn ; 
 int /*<<< orphan*/  USART6_IRQn ; 
 int USART_ISR_TXE ; 
 int /*<<< orphan*/  __WFI () ; 
 int /*<<< orphan*/  __fatal_error (char*) ; 
 int /*<<< orphan*/  __get_PRIMASK () ; 
 scalar_t__ _estack ; 
 int /*<<< orphan*/  _heap_end ; 
 int /*<<< orphan*/  _ram_end ; 
 int /*<<< orphan*/  _ram_start ; 
 int /*<<< orphan*/  mp_hal_stdout_tx_str (char*) ; 
 int /*<<< orphan*/  print_hex_hex (char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  print_reg (char*,scalar_t__) ; 
 int /*<<< orphan*/  pyb_hard_fault_debug ; 
 TYPE_5__* pyb_thread_cur ; 
 int /*<<< orphan*/  timer_irq_handler (int) ; 
 int /*<<< orphan*/  uart_irq_handler (int) ; 

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

void HardFault_C_Handler(ExceptionRegisters_t *regs) {
    if (!pyb_hard_fault_debug) {
        NVIC_SystemReset();
    }

    #if MICROPY_HW_ENABLE_USB
    // We need to disable the USB so it doesn't try to write data out on
    // the VCP and then block indefinitely waiting for the buffer to drain.
    pyb_usb_flags = 0;
    #endif

    mp_hal_stdout_tx_str("HardFault\r\n");

    print_reg("R0    ", regs->r0);
    print_reg("R1    ", regs->r1);
    print_reg("R2    ", regs->r2);
    print_reg("R3    ", regs->r3);
    print_reg("R12   ", regs->r12);
    print_reg("SP    ", (uint32_t)regs);
    print_reg("LR    ", regs->lr);
    print_reg("PC    ", regs->pc);
    print_reg("XPSR  ", regs->xpsr);

    #if __CORTEX_M >= 3
    uint32_t cfsr = SCB->CFSR;

    print_reg("HFSR  ", SCB->HFSR);
    print_reg("CFSR  ", cfsr);
    if (cfsr & 0x80) {
        print_reg("MMFAR ", SCB->MMFAR);
    }
    if (cfsr & 0x8000) {
        print_reg("BFAR  ", SCB->BFAR);
    }
    #endif

    if ((void*)&_ram_start <= (void*)regs && (void*)regs < (void*)&_ram_end) {
        mp_hal_stdout_tx_str("Stack:\r\n");
        uint32_t *stack_top = &_estack;
        if ((void*)regs < (void*)&_heap_end) {
            // stack not in static stack area so limit the amount we print
            stack_top = (uint32_t*)regs + 32;
        }
        for (uint32_t *sp = (uint32_t*)regs; sp < stack_top; ++sp) {
            print_hex_hex("  ", (uint32_t)sp, *sp);
        }
    }

    /* Go to infinite loop when Hard Fault exception occurs */
    while (1) {
        __fatal_error("HardFault");
    }
}

__attribute__((naked))
void HardFault_Handler(void) {

    // From the ARMv7M Architecture Reference Manual, section B.1.5.6
    // on entry to the Exception, the LR register contains, amongst other
    // things, the value of CONTROL.SPSEL. This can be found in bit 3.
    //
    // If CONTROL.SPSEL is 0, then the exception was stacked up using the
    // main stack pointer (aka MSP). If CONTROL.SPSEL is 1, then the exception
    // was stacked up using the process stack pointer (aka PSP).

    #if __CORTEX_M == 0
    __asm volatile(
    " mov r0, lr    \n"
    " lsr r0, r0, #3 \n"        // Shift Bit 3 into carry to see which stack pointer we should use.
    " mrs r0, msp   \n"         // Make R0 point to main stack pointer
    " bcc .use_msp  \n"         // Keep MSP in R0 if SPSEL (carry) is 0
    " mrs r0, psp   \n"         // Make R0 point to process stack pointer
    " .use_msp:     \n"
    " b HardFault_C_Handler \n" // Off to C land
    );
    #else
    __asm volatile(
    " tst lr, #4    \n"         // Test Bit 3 to see which stack pointer we should use.
    " ite eq        \n"         // Tell the assembler that the nest 2 instructions are if-then-else
    " mrseq r0, msp \n"         // Make R0 point to main stack pointer
    " mrsne r0, psp \n"         // Make R0 point to process stack pointer
    " b HardFault_C_Handler \n" // Off to C land
    );
    #endif
}

void NMI_Handler(void) {
}

void MemManage_Handler(void) {
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1) {
        __fatal_error("MemManage");
    }
}

void BusFault_Handler(void) {
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1) {
        __fatal_error("BusFault");
    }
}

void UsageFault_Handler(void) {
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1) {
        __fatal_error("UsageFault");
    }
}

void SVC_Handler(void) {
}

void DebugMon_Handler(void) {
}

void EXTI0_IRQHandler(void) {
    IRQ_ENTER(EXTI0_IRQn);
    Handle_EXTI_Irq(0);
    IRQ_EXIT(EXTI0_IRQn);
}

void EXTI1_IRQHandler(void) {
    IRQ_ENTER(EXTI1_IRQn);
    Handle_EXTI_Irq(1);
    IRQ_EXIT(EXTI1_IRQn);
}

void EXTI2_IRQHandler(void) {
    IRQ_ENTER(EXTI2_IRQn);
    Handle_EXTI_Irq(2);
    IRQ_EXIT(EXTI2_IRQn);
}

void EXTI3_IRQHandler(void) {
    IRQ_ENTER(EXTI3_IRQn);
    Handle_EXTI_Irq(3);
    IRQ_EXIT(EXTI3_IRQn);
}

void EXTI4_IRQHandler(void) {
    IRQ_ENTER(EXTI4_IRQn);
    Handle_EXTI_Irq(4);
    IRQ_EXIT(EXTI4_IRQn);
}

void EXTI9_5_IRQHandler(void) {
    IRQ_ENTER(EXTI9_5_IRQn);
    Handle_EXTI_Irq(5);
    Handle_EXTI_Irq(6);
    Handle_EXTI_Irq(7);
    Handle_EXTI_Irq(8);
    Handle_EXTI_Irq(9);
    IRQ_EXIT(EXTI9_5_IRQn);
}

void EXTI15_10_IRQHandler(void) {
    IRQ_ENTER(EXTI15_10_IRQn);
    Handle_EXTI_Irq(10);
    Handle_EXTI_Irq(11);
    Handle_EXTI_Irq(12);
    Handle_EXTI_Irq(13);
    Handle_EXTI_Irq(14);
    Handle_EXTI_Irq(15);
    IRQ_EXIT(EXTI15_10_IRQn);
}

void PVD_IRQHandler(void) {
    IRQ_ENTER(PVD_IRQn);
    Handle_EXTI_Irq(EXTI_PVD_OUTPUT);
    IRQ_EXIT(PVD_IRQn);
}

void RTC_Alarm_IRQHandler(void) {
    IRQ_ENTER(RTC_Alarm_IRQn);
    Handle_EXTI_Irq(EXTI_RTC_ALARM);
    IRQ_EXIT(RTC_Alarm_IRQn);
}

void TAMP_STAMP_IRQHandler(void) {
    IRQ_ENTER(TAMP_STAMP_IRQn);
    Handle_EXTI_Irq(EXTI_RTC_TIMESTAMP);
    IRQ_EXIT(TAMP_STAMP_IRQn);
}

void RTC_WKUP_IRQHandler(void) {
    IRQ_ENTER(RTC_WKUP_IRQn);
    RTC->ISR &= ~RTC_ISR_WUTF; // clear wakeup interrupt flag
    Handle_EXTI_Irq(EXTI_RTC_WAKEUP); // clear EXTI flag and execute optional callback
    IRQ_EXIT(RTC_WKUP_IRQn);
}

void TIM1_BRK_TIM9_IRQHandler(void) {
    IRQ_ENTER(TIM1_BRK_TIM9_IRQn);
    timer_irq_handler(9);
    IRQ_EXIT(TIM1_BRK_TIM9_IRQn);
}

void TIM1_UP_TIM10_IRQHandler(void) {
    IRQ_ENTER(TIM1_UP_TIM10_IRQn);
    timer_irq_handler(1);
    timer_irq_handler(10);
    IRQ_EXIT(TIM1_UP_TIM10_IRQn);
}

void TIM1_TRG_COM_TIM11_IRQHandler(void) {
    IRQ_ENTER(TIM1_TRG_COM_TIM11_IRQn);
    timer_irq_handler(11);
    IRQ_EXIT(TIM1_TRG_COM_TIM11_IRQn);
}

void TIM1_CC_IRQHandler(void) {
    IRQ_ENTER(TIM1_CC_IRQn);
    timer_irq_handler(1);
    IRQ_EXIT(TIM1_CC_IRQn);
}

void TIM2_IRQHandler(void) {
    IRQ_ENTER(TIM2_IRQn);
    timer_irq_handler(2);
    IRQ_EXIT(TIM2_IRQn);
}

void TIM3_IRQHandler(void) {
    IRQ_ENTER(TIM3_IRQn);
    timer_irq_handler(3);
    IRQ_EXIT(TIM3_IRQn);
}

void TIM4_IRQHandler(void) {
    IRQ_ENTER(TIM4_IRQn);
    timer_irq_handler(4);
    IRQ_EXIT(TIM4_IRQn);
}

void TIM5_IRQHandler(void) {
    IRQ_ENTER(TIM5_IRQn);
    timer_irq_handler(5);
    HAL_TIM_IRQHandler(&TIM5_Handle);
    IRQ_EXIT(TIM5_IRQn);
}

void USART1_IRQHandler(void) {
    IRQ_ENTER(USART1_IRQn);
    uart_irq_handler(1);
    IRQ_EXIT(USART1_IRQn);
}

void USART2_IRQHandler(void) {
    IRQ_ENTER(USART2_IRQn);
    uart_irq_handler(2);
    IRQ_EXIT(USART2_IRQn);
}

void USART3_IRQHandler(void) {
    IRQ_ENTER(USART3_IRQn);
    uart_irq_handler(3);
    IRQ_EXIT(USART3_IRQn);
}

void UART4_IRQHandler(void) {
    IRQ_ENTER(UART4_IRQn);
    uart_irq_handler(4);
    IRQ_EXIT(UART4_IRQn);
}

void UART5_IRQHandler(void) {
    IRQ_ENTER(UART5_IRQn);
    uart_irq_handler(5);
    IRQ_EXIT(UART5_IRQn);
}

void USART6_IRQHandler(void) {
    IRQ_ENTER(USART6_IRQn);
    uart_irq_handler(6);
    IRQ_EXIT(USART6_IRQn);
}

