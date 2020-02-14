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
typedef  int /*<<< orphan*/  clock_t ;
struct TYPE_3__ {int /*<<< orphan*/  QuadPart; } ;
typedef  TYPE_1__ ULARGE_INTEGER ;
struct TYPE_4__ {scalar_t__ QuadPart; } ;
typedef  int /*<<< orphan*/  FILETIME ;

/* Variables and functions */
 int /*<<< orphan*/  FileTimeToUnixTime (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetSystemTimeAsFileTime (int /*<<< orphan*/ *) ; 
 TYPE_2__ g_StartupTime ; 

void
initclock(void)
{
    GetSystemTimeAsFileTime((FILETIME*)&g_StartupTime);
}

clock_t
clock(void)
{
    ULARGE_INTEGER Time;

    GetSystemTimeAsFileTime((FILETIME*)&Time);
    Time.QuadPart -= g_StartupTime.QuadPart;
    return (clock_t)FileTimeToUnixTime((FILETIME*)&Time, NULL);
}

