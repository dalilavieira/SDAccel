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
typedef  int /*<<< orphan*/  time_t ;
struct tm {int tm_mon; int tm_year; int tm_mday; scalar_t__ tm_sec; scalar_t__ tm_min; scalar_t__ tm_hour; } ;
typedef  int __time64_t ;
typedef  int /*<<< orphan*/  __time32_t ;
struct TYPE_3__ {int Bias; } ;
typedef  TYPE_1__ TIME_ZONE_INFORMATION ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 scalar_t__ GetTimeZoneInformation (TYPE_1__*) ; 
 int MAX_32BIT_TIME ; 
 scalar_t__ TIME_ZONE_ID_INVALID ; 
 struct tm* _gmtime64 (int*) ; 
 scalar_t__* g_monthdays ; 

__time64_t
mktime_worker(struct tm * ptm, int utc)
{
    struct tm *ptm2;
    __time64_t time;
    int mons, years, leapyears;
    TIME_ZONE_INFORMATION tzi;
    DWORD ret;

    /* Normalize year and month */
    if (ptm->tm_mon < 0)
    {
        mons = -ptm->tm_mon - 1;
        ptm->tm_year -= 1 + mons / 12;
        ptm->tm_mon = 11 - (mons % 12);
    }
    else if (ptm->tm_mon > 11)
    {
        mons = ptm->tm_mon;
        ptm->tm_year += (mons / 12);
        ptm->tm_mon = mons % 12;
    }

    /* Is it inside margins */
    if (ptm->tm_year < 70 || ptm->tm_year > 139) // FIXME: max year for 64 bits
    {
        return -1;
    }

    years = ptm->tm_year - 70;

    /* Number of leapyears passed since 1970 */
    leapyears = (years + 1) / 4;

    /* Calculate days up to 1st of Jan */
    time = years * 365 + leapyears;

    /* Calculate days up to 1st of month */
    time += g_monthdays[ptm->tm_mon];

    /* Check if we need to add a leap day */
    if (((years + 2) % 4) == 0)
    {
        if (ptm->tm_mon > 2)
        {
            time++;
        }
    }

    time += ptm->tm_mday - 1;

    time *= 24;
    time += ptm->tm_hour;

    time *= 60;
    time += ptm->tm_min;

    time *= 60;
    time += ptm->tm_sec;

    if (time < 0)
    {
        return -1;
    }

    /* Finally get normalized tm struct */
    ptm2 = _gmtime64(&time);
    if (!ptm2)
    {
        return -1;
    }
    *ptm = *ptm2;

    /* Finally adjust by the difference to GMT in seconds */
    ret = GetTimeZoneInformation(&tzi);
    if (ret != TIME_ZONE_ID_INVALID)
    {
        time += tzi.Bias * 60;
    }

    return time;
}

time_t
_mkgmtime(struct tm *ptm)
{
    __time64_t time = mktime_worker(ptm, 1);
    return (time_t)((time > MAX_32BIT_TIME) ? -1 : time);
}

time_t
mktime(struct tm *ptm)
{
    __time64_t time = mktime_worker(ptm, 0);
    return (time_t)((time > MAX_32BIT_TIME) ? -1 : time);
}

__time32_t
_mkgmtime32(struct tm *ptm)
{
    __time64_t time = mktime_worker(ptm, 1);
    return (__time32_t)((time > MAX_32BIT_TIME) ? -1 : time);
}

__time32_t
_mktime32(struct tm *ptm)
{
    __time64_t time = mktime_worker(ptm, 0);
    return (__time32_t)((time > MAX_32BIT_TIME) ? -1 : time);
}

__time64_t
_mkgmtime64(struct tm *ptm)
{
    return mktime_worker(ptm, 1);
}

__time64_t
_mktime64(struct tm *ptm)
{
    return mktime_worker(ptm, 0);
}

