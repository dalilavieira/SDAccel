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
typedef  size_t uint ;
typedef  int /*<<< orphan*/  pyb_timer_obj_t ;
typedef  int mp_uint_t ;
typedef  int mp_int_t ;

/* Variables and functions */
 size_t PYB_TIMER_OBJ_ALL_NUM ; 
 int /*<<< orphan*/  mp_obj_new_exception_msg_varg (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  mp_type_TypeError ; 
 int /*<<< orphan*/  nlr_raise (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pyb_timer_deinit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ ** pyb_timer_obj_all ; 

void timer_init0(void) {
    for (uint i = 0; i < PYB_TIMER_OBJ_ALL_NUM; i++) {
        pyb_timer_obj_all[i] = NULL;
    }
}

void timer_deinit(void) {
    for (uint i = 0; i < PYB_TIMER_OBJ_ALL_NUM; i++) {
        pyb_timer_obj_t *tim = pyb_timer_obj_all[i];
        if (tim != NULL) {
            pyb_timer_deinit(tim);
        }
    }
}

mp_uint_t get_prescaler_shift(mp_int_t prescaler) {
    mp_uint_t prescaler_shift;
    for (prescaler_shift = 0; prescaler_shift < 8; prescaler_shift++) {
        if (prescaler == (1 << prescaler_shift)) {
            return prescaler_shift;
        }
    }
    nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_TypeError, "prescaler must be a power of 2 between 1 and 128, not %d", prescaler));
}

