#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int mp_uint_t ;
typedef  int /*<<< orphan*/  mp_obj_t ;
struct TYPE_4__ {scalar_t__ buf; } ;
typedef  TYPE_1__ mp_buffer_info_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  byte ;
struct TYPE_5__ {int /*<<< orphan*/ * read; int /*<<< orphan*/  stream_o; int /*<<< orphan*/ * write; } ;
typedef  int /*<<< orphan*/  HWREG ;

/* Variables and functions */
 int /*<<< orphan*/  FAULT_SYSTICK ; 
 int HAL_FCPU_HZ ; 
 int HAL_NVIC_INT_CTRL_REG ; 
 int HAL_SYSTICK_PERIOD_US ; 
 int HAL_VECTACTIVE_MASK ; 
 int HAL_tickCount ; 
 scalar_t__ IRQ_STATE_ENABLED ; 
 int /*<<< orphan*/  MAP_IntEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAP_IntVTableBaseSet (unsigned long) ; 
 int /*<<< orphan*/  MAP_SysTickEnable () ; 
 int /*<<< orphan*/  MAP_SysTickIntEnable () ; 
 int /*<<< orphan*/  MAP_SysTickIntRegister (void (*) ()) ; 
 int /*<<< orphan*/  MAP_SysTickPeriodSet (int) ; 
 int /*<<< orphan*/  MP_BUFFER_READ ; 
 TYPE_3__* MP_STATE_PORT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MP_THREAD_GIL_ENTER () ; 
 int /*<<< orphan*/  MP_THREAD_GIL_EXIT () ; 
 int SysTickPeriodGet () ; 
 int SysTickValueGet () ; 
 int /*<<< orphan*/  UTILS_DELAY_US_TO_COUNT (int) ; 
 int /*<<< orphan*/  UtilsDelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __WFI () ; 
 int disable_irq () ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 int /*<<< orphan*/ * g_pfnVectors ; 
static  void hal_TickInit () ; 
 int /*<<< orphan*/  mp_call_method_n_kw (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_get_buffer_raise (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 void mp_hal_stdout_tx_strn (char const*,size_t) ; 
 scalar_t__ mp_obj_is_true (int /*<<< orphan*/ ) ; 
 scalar_t__ mp_obj_is_type (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_obj_new_int (int) ; 
 int /*<<< orphan*/  mp_obj_new_str_of_type (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,size_t) ; 
 int /*<<< orphan*/  mp_type_str ; 
 int /*<<< orphan*/  os_term_dup_obj ; 
 int /*<<< orphan*/  pyb_uart_type ; 
 scalar_t__ query_irq () ; 
 size_t strlen (char const*) ; 
 scalar_t__ telnet_rx_any () ; 
 int telnet_rx_char () ; 
 int /*<<< orphan*/  telnet_tx_strn (char const*,size_t) ; 
 scalar_t__ uart_rx_any (int /*<<< orphan*/ ) ; 
 int uart_rx_char (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uart_tx_strn (int /*<<< orphan*/ ,char const*,size_t) ; 

__attribute__ ((section (".boot")))
void HAL_SystemInit (void) {
    MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);

    // in the case of a release image, these steps are already performed by
    // the bootloader so we can skip it and gain some code space
#ifdef DEBUG
    MAP_IntMasterEnable();
    PRCMCC3200MCUInit();
#endif

#ifndef USE_FREERTOS
    hal_TickInit();
#endif
}

void HAL_SystemDeInit (void) {
}

void HAL_IncrementTick(void) {
    HAL_tickCount++;
}

mp_uint_t mp_hal_ticks_ms(void) {
    return HAL_tickCount;
}

mp_uint_t mp_hal_ticks_us(void) {
    mp_uint_t irq_state = disable_irq();
    uint32_t counter = SysTickValueGet();
    uint32_t milliseconds = mp_hal_ticks_ms();
    enable_irq(irq_state);

    uint32_t load = SysTickPeriodGet();
    counter = load - counter; // Convert from decrementing to incrementing
    return (milliseconds * 1000) + ((counter * 1000) / load);
}

void mp_hal_delay_ms(mp_uint_t delay) {
    // only if we are not within interrupt context and interrupts are enabled
    if ((HAL_NVIC_INT_CTRL_REG & HAL_VECTACTIVE_MASK) == 0 && query_irq() == IRQ_STATE_ENABLED) {
        MP_THREAD_GIL_EXIT();
        #ifdef USE_FREERTOS
            vTaskDelay (delay / portTICK_PERIOD_MS);
        #else
            uint32_t start = HAL_tickCount;
            // wraparound of tick is taken care of by 2's complement arithmetic.
            while (HAL_tickCount - start < delay) {
                // enter sleep mode, waiting for (at least) the SysTick interrupt.
                __WFI();
            }
        #endif
        MP_THREAD_GIL_ENTER();
    } else {
        for (int ms = 0; ms < delay; ms++) {
            UtilsDelay(UTILS_DELAY_US_TO_COUNT(1000));
        }
    }
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
    if (MP_STATE_PORT(os_term_dup_obj)) {
        if (mp_obj_is_type(MP_STATE_PORT(os_term_dup_obj)->stream_o, &pyb_uart_type)) {
            uart_tx_strn(MP_STATE_PORT(os_term_dup_obj)->stream_o, str, len);
        } else {
            MP_STATE_PORT(os_term_dup_obj)->write[2] = mp_obj_new_str_of_type(&mp_type_str, (const byte *)str, len);
            mp_call_method_n_kw(1, 0, MP_STATE_PORT(os_term_dup_obj)->write);
        }
    }
    // and also to telnet
    telnet_tx_strn(str, len);
}

void mp_hal_stdout_tx_strn_cooked (const char *str, size_t len) {
    int32_t nslen = 0;
    const char *_str = str;

    for (int i = 0; i < len; i++) {
        if (str[i] == '\n') {
            mp_hal_stdout_tx_strn(_str, nslen);
            mp_hal_stdout_tx_strn("\r\n", 2);
            _str += nslen + 1;
            nslen = 0;
        } else {
            nslen++;
        }
    }
    if (_str < str + len) {
        mp_hal_stdout_tx_strn(_str, nslen);
    }
}

int mp_hal_stdin_rx_chr(void) {
    for ( ;; ) {
        // read telnet first
        if (telnet_rx_any()) {
            return telnet_rx_char();
        } else if (MP_STATE_PORT(os_term_dup_obj)) { // then the stdio_dup
            if (mp_obj_is_type(MP_STATE_PORT(os_term_dup_obj)->stream_o, &pyb_uart_type)) {
                if (uart_rx_any(MP_STATE_PORT(os_term_dup_obj)->stream_o)) {
                    return uart_rx_char(MP_STATE_PORT(os_term_dup_obj)->stream_o);
                }
            } else {
                MP_STATE_PORT(os_term_dup_obj)->read[2] = mp_obj_new_int(1);
                mp_obj_t data = mp_call_method_n_kw(1, 0, MP_STATE_PORT(os_term_dup_obj)->read);
                // data len is > 0
                if (mp_obj_is_true(data)) {
                    mp_buffer_info_t bufinfo;
                    mp_get_buffer_raise(data, &bufinfo, MP_BUFFER_READ);
                    return ((int *)(bufinfo.buf))[0];
                }
            }
        }
        mp_hal_delay_ms(1);
    }
}

__attribute__((used)) static void hal_TickInit (void) {
    HAL_tickCount = 0;
    MAP_SysTickIntRegister(HAL_IncrementTick);
    MAP_IntEnable(FAULT_SYSTICK);
    MAP_SysTickIntEnable();
    MAP_SysTickPeriodSet(HAL_FCPU_HZ / HAL_SYSTICK_PERIOD_US);
    // Force a reload of the SysTick counter register
    HWREG(NVIC_ST_CURRENT) = 0;
    MAP_SysTickEnable();
}

