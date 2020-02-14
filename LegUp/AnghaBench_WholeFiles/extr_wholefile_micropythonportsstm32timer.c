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
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  size_t uint ;
struct TYPE_13__ {TYPE_1__* Instance; } ;
struct TYPE_11__ {TYPE_5__ tim; TYPE_3__* channel; int /*<<< orphan*/  callback; } ;
typedef  TYPE_2__ pyb_timer_obj_t ;
struct TYPE_12__ {struct TYPE_12__* next; int /*<<< orphan*/  channel; int /*<<< orphan*/  callback; } ;
typedef  TYPE_3__ pyb_timer_channel_obj_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;
struct TYPE_14__ {int CFGR; } ;
struct TYPE_10__ {int DIER; } ;
typedef  int /*<<< orphan*/  TIM_HandleTypeDef ;

/* Variables and functions */
 int HAL_RCC_GetPCLK1Freq () ; 
 int HAL_RCC_GetPCLK2Freq () ; 
 int /*<<< orphan*/  MP_OBJ_FROM_PTR (TYPE_2__*) ; 
 TYPE_2__** MP_STATE_PORT (int /*<<< orphan*/ ) ; 
 size_t PYB_TIMER_OBJ_ALL_NUM ; 
 TYPE_7__* RCC ; 
 int RCC_CFGR_PPRE1 ; 
 int RCC_CFGR_PPRE2 ; 
 int TIMER_IRQ_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __HAL_TIM_CLEAR_IT (TYPE_5__*,int) ; 
 int /*<<< orphan*/  __HAL_TIM_DISABLE_IT (TYPE_5__*,int) ; 
 int /*<<< orphan*/  __get_PRIMASK () ; 
 int /*<<< orphan*/  printf (char*,unsigned int) ; 
 int /*<<< orphan*/  pyb_timer_deinit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pyb_timer_obj_all ; 
 int /*<<< orphan*/  timer_handle_irq_channel (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline mp_uint_t query_irq(void) {
    return __get_PRIMASK();
}

void timer_init0(void) {
    for (uint i = 0; i < PYB_TIMER_OBJ_ALL_NUM; i++) {
        MP_STATE_PORT(pyb_timer_obj_all)[i] = NULL;
    }
}

void timer_deinit(void) {
    for (uint i = 0; i < PYB_TIMER_OBJ_ALL_NUM; i++) {
        pyb_timer_obj_t *tim = MP_STATE_PORT(pyb_timer_obj_all)[i];
        if (tim != NULL) {
            pyb_timer_deinit(MP_OBJ_FROM_PTR(tim));
        }
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    #if MICROPY_HW_ENABLE_SERVO
    if (htim == &TIM5_Handle) {
        servo_timer_irq_callback();
    }
    #endif
}

uint32_t timer_get_source_freq(uint32_t tim_id) {
    uint32_t source, clk_div;
    if (tim_id == 1 || (8 <= tim_id && tim_id <= 11)) {
        // TIM{1,8,9,10,11} are on APB2
        #if defined(STM32F0)
        source = HAL_RCC_GetPCLK1Freq();
        clk_div = RCC->CFGR & RCC_CFGR_PPRE;
        #elif defined(STM32H7)
        source = HAL_RCC_GetPCLK2Freq();
        clk_div = RCC->D2CFGR & RCC_D2CFGR_D2PPRE2;
        #else
        source = HAL_RCC_GetPCLK2Freq();
        clk_div = RCC->CFGR & RCC_CFGR_PPRE2;
        #endif
    } else {
        // TIM{2,3,4,5,6,7,12,13,14} are on APB1
        source = HAL_RCC_GetPCLK1Freq();
        #if defined(STM32F0)
        clk_div = RCC->CFGR & RCC_CFGR_PPRE;
        #elif defined(STM32H7)
        clk_div = RCC->D2CFGR & RCC_D2CFGR_D2PPRE1;
        #else
        clk_div = RCC->CFGR & RCC_CFGR_PPRE1;
        #endif
    }
    if (clk_div != 0) {
        // APB prescaler for this timer is > 1
        source *= 2;
    }
    return source;
}

void timer_irq_handler(uint tim_id) {
    if (tim_id - 1 < PYB_TIMER_OBJ_ALL_NUM) {
        // get the timer object
        pyb_timer_obj_t *tim = MP_STATE_PORT(pyb_timer_obj_all)[tim_id - 1];

        if (tim == NULL) {
            // Timer object has not been set, so we can't do anything.
            // This can happen under normal circumstances for timers like
            // 1 & 10 which use the same IRQ.
            return;
        }

        // Check for timer (versus timer channel) interrupt.
        timer_handle_irq_channel(tim, 0, tim->callback);
        uint32_t handled = TIMER_IRQ_MASK(0);

        // Check to see if a timer channel interrupt was pending
        pyb_timer_channel_obj_t *chan = tim->channel;
        while (chan != NULL) {
            timer_handle_irq_channel(tim, chan->channel, chan->callback);
            handled |= TIMER_IRQ_MASK(chan->channel);
            chan = chan->next;
        }

        // Finally, clear any remaining interrupt sources. Otherwise we'll
        // just get called continuously.
        uint32_t unhandled = tim->tim.Instance->DIER & 0xff & ~handled;
        if (unhandled != 0) {
            __HAL_TIM_DISABLE_IT(&tim->tim, unhandled);
            __HAL_TIM_CLEAR_IT(&tim->tim, unhandled);
            printf("Unhandled interrupt SR=0x%02x (now disabled)\n", (unsigned int)unhandled);
        }
    }
}

