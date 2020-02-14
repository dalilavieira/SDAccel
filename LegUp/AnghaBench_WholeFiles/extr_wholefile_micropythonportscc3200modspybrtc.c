#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_4__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  scalar_t__ uint16_t ;
struct TYPE_5__ {int alarm_time_s; int alarm_time_ms; scalar_t__ alarm_ms; scalar_t__ repeat; } ;
typedef  TYPE_1__ pyb_rtc_obj_t ;
typedef  scalar_t__ int32_t ;
struct TYPE_6__ {int alarmset; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAP_PRCMRTCGet (int*,scalar_t__*) ; 
 int /*<<< orphan*/  MAP_PRCMRTCInUseSet () ; 
 scalar_t__ MAP_PRCMSysResetCauseGet () ; 
 scalar_t__ PRCM_POWER_ON ; 
 scalar_t__ PYB_RTC_MIN_ALARM_TIME_MS ; 
 scalar_t__ RTC_CYCLES_U16MS (scalar_t__) ; 
 int /*<<< orphan*/  pyb_rtc_disable_interupt () ; 
 TYPE_4__ pyb_rtc_obj ; 
 int /*<<< orphan*/  pyb_rtc_reset () ; 
 int /*<<< orphan*/  pyb_rtc_set_alarm (TYPE_1__*,int,scalar_t__) ; 
 int /*<<< orphan*/  rtc_msec_add (scalar_t__,int*,scalar_t__*) ; 

__attribute__ ((section (".boot")))
void pyb_rtc_pre_init(void) {
    // only if comming out of a power-on reset
    if (MAP_PRCMSysResetCauseGet() == PRCM_POWER_ON) {
        // Mark the RTC in use first
        MAP_PRCMRTCInUseSet();
        // reset the time and date
        pyb_rtc_reset();
    }
}

void pyb_rtc_get_time (uint32_t *secs, uint16_t *msecs) {
    uint16_t cycles;
    MAP_PRCMRTCGet (secs, &cycles);
    *msecs = RTC_CYCLES_U16MS(cycles);
}

uint32_t pyb_rtc_get_seconds (void) {
    uint32_t seconds;
    uint16_t mseconds;
    pyb_rtc_get_time(&seconds, &mseconds);
    return seconds;
}

void pyb_rtc_calc_future_time (uint32_t a_mseconds, uint32_t *f_seconds, uint16_t *f_mseconds) {
    uint32_t c_seconds;
    uint16_t c_mseconds;
    // get the current time
    pyb_rtc_get_time(&c_seconds, &c_mseconds);
    // calculate the future seconds
    *f_seconds = c_seconds + (a_mseconds / 1000);
    // calculate the "remaining" future mseconds
    *f_mseconds = a_mseconds % 1000;
    // add the current milliseconds
    rtc_msec_add (c_mseconds, f_seconds, f_mseconds);
}

void pyb_rtc_repeat_alarm (pyb_rtc_obj_t *self) {
    if (self->repeat) {
        uint32_t f_seconds, c_seconds;
        uint16_t f_mseconds, c_mseconds;

        pyb_rtc_get_time(&c_seconds, &c_mseconds);

        // substract the time elapsed between waking up and setting up the alarm again
        int32_t wake_ms = ((c_seconds * 1000) + c_mseconds) - ((self->alarm_time_s * 1000) + self->alarm_time_ms);
        int32_t next_alarm = self->alarm_ms - wake_ms;
        next_alarm = next_alarm > 0 ? next_alarm : PYB_RTC_MIN_ALARM_TIME_MS;
        pyb_rtc_calc_future_time (next_alarm, &f_seconds, &f_mseconds);

        // now configure the alarm
        pyb_rtc_set_alarm (self, f_seconds, f_mseconds);
    }
}

void pyb_rtc_disable_alarm (void) {
    pyb_rtc_obj.alarmset = false;
    pyb_rtc_disable_interupt();
}

