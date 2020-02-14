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
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  magic ;
typedef  int /*<<< orphan*/  len ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  delta ;
typedef  int /*<<< orphan*/  cal ;

/* Variables and functions */
 int /*<<< orphan*/  MEM_CAL_ADDR ; 
 int /*<<< orphan*/  MEM_DELTA_ADDR ; 
 scalar_t__ MEM_MAGIC ; 
 int /*<<< orphan*/  MEM_USER_LEN_ADDR ; 
 int /*<<< orphan*/  MEM_USER_MAGIC_ADDR ; 
 scalar_t__ pyb_rtc_alarm0_expiry ; 
 scalar_t__ pyb_rtc_alarm0_wake ; 
 scalar_t__ rtc_last_ticks ; 
 scalar_t__ system_get_rtc_time () ; 
 scalar_t__ system_rtc_clock_cali_proc () ; 
 int /*<<< orphan*/  system_rtc_mem_read (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  system_rtc_mem_write (int /*<<< orphan*/ ,...) ; 

void mp_hal_rtc_init(void) {
    uint32_t magic;

    system_rtc_mem_read(MEM_USER_MAGIC_ADDR, &magic, sizeof(magic));
    if (magic != MEM_MAGIC) {
        magic = MEM_MAGIC;
        system_rtc_mem_write(MEM_USER_MAGIC_ADDR, &magic, sizeof(magic));
        uint32_t cal = system_rtc_clock_cali_proc();
        int64_t delta = 0;
        system_rtc_mem_write(MEM_CAL_ADDR, &cal, sizeof(cal));
        system_rtc_mem_write(MEM_DELTA_ADDR, &delta, sizeof(delta));
        uint32_t len = 0;
        system_rtc_mem_write(MEM_USER_LEN_ADDR, &len, sizeof(len));
    }
    // system_get_rtc_time() is always 0 after reset/deepsleep
    rtc_last_ticks = system_get_rtc_time();

    // reset ALARM0 state
    pyb_rtc_alarm0_wake = 0;
    pyb_rtc_alarm0_expiry = 0;
}

uint64_t pyb_rtc_get_us_since_2000() {
    uint32_t cal;
    int64_t delta;
    uint32_t rtc_ticks;

    system_rtc_mem_read(MEM_CAL_ADDR, &cal, sizeof(cal));
    system_rtc_mem_read(MEM_DELTA_ADDR, &delta, sizeof(delta));

    // ESP-SDK system_get_rtc_time() only returns uint32 and therefore
    // overflow about every 7:45h.  Thus, we have to check for
    // overflow and handle it.
    rtc_ticks = system_get_rtc_time();
    if (rtc_ticks < rtc_last_ticks) {
        // Adjust delta because of RTC overflow.
        delta += (uint64_t)cal << 20;
        system_rtc_mem_write(MEM_DELTA_ADDR, &delta, sizeof(delta));
    }
    rtc_last_ticks = rtc_ticks;

    return (((uint64_t)rtc_ticks * cal) >> 12) + delta;
}

void rtc_prepare_deepsleep(uint64_t sleep_us) {
    // RTC time will reset at wake up. Let's be preared for this.
    int64_t delta = pyb_rtc_get_us_since_2000() + sleep_us;
    system_rtc_mem_write(MEM_DELTA_ADDR, &delta, sizeof(delta));
}

