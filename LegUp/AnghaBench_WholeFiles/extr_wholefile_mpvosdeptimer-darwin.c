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
struct mach_timebase_info {scalar_t__ denom; scalar_t__ numer; } ;
typedef  int int64_t ;

/* Variables and functions */
 int mach_absolute_time () ; 
 int /*<<< orphan*/  mach_timebase_info (struct mach_timebase_info*) ; 
 int /*<<< orphan*/  mach_wait_until (int) ; 
 int timebase_ratio ; 

void mp_sleep_us(int64_t us)
{
    uint64_t deadline = us / 1e6 / timebase_ratio + mach_absolute_time();

    mach_wait_until(deadline);
}

uint64_t mp_raw_time_us(void)
{
    return mach_absolute_time() * timebase_ratio * 1e6;
}

void mp_raw_time_init(void)
{
    struct mach_timebase_info timebase;

    mach_timebase_info(&timebase);
    timebase_ratio = (double)timebase.numer / (double)timebase.denom * 1e-9;
}

