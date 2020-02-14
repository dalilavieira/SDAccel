#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int tm_year; scalar_t__ tm_sec; scalar_t__ tm_min; scalar_t__ tm_hour; scalar_t__ tm_mday; scalar_t__ tm_mon; } ;
typedef  TYPE_1__ timeutils_struct_time_t ;
struct timeval {int /*<<< orphan*/  tv_sec; } ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timeutils_seconds_since_2000_to_struct_time (int /*<<< orphan*/ ,TYPE_1__*) ; 

DWORD get_fattime(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    timeutils_struct_time_t tm;
    timeutils_seconds_since_2000_to_struct_time(tv.tv_sec, &tm);

    return (((DWORD)(tm.tm_year - 1980) << 25) | ((DWORD)tm.tm_mon << 21) | ((DWORD)tm.tm_mday << 16) |
           ((DWORD)tm.tm_hour << 11) | ((DWORD)tm.tm_min << 5) | ((DWORD)tm.tm_sec >> 1));
}

