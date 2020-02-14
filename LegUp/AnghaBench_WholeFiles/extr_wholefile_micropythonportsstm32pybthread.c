#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;
struct TYPE_4__ {int /*<<< orphan*/  ICSR; } ;
struct TYPE_3__ {struct TYPE_3__* run_next; scalar_t__ local_state; } ;

/* Variables and functions */
 TYPE_2__* SCB ; 
 int /*<<< orphan*/  SCB_ICSR_PENDSVSET_Msk ; 
 int /*<<< orphan*/  __WFI () ; 
 int /*<<< orphan*/  __get_PRIMASK () ; 
 TYPE_1__* pyb_thread_cur ; 

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

