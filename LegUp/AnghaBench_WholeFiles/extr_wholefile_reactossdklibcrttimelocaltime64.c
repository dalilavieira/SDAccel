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
typedef  scalar_t__ time_t ;
struct tm {int dummy; } ;
typedef  int /*<<< orphan*/  errno_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  _CRT_WIDE (char*) ; 
 scalar_t__ const _MAX__TIME64_T ; 
 int /*<<< orphan*/  _invalid_parameter (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _set_errno (int /*<<< orphan*/ ) ; 
 scalar_t__ _timezone ; 
 int /*<<< orphan*/  _tz_is_set ; 
 int /*<<< orphan*/  _tzset () ; 
 struct tm* gmtime (scalar_t__*) ; 
 struct tm* localtime (scalar_t__ const*) ; 
 int /*<<< orphan*/  memset (struct tm*,int,int) ; 

errno_t
localtime_s(struct tm* _tm, const time_t *ptime)
{
    /* check for NULL */
    if (!_tm || !ptime )
    {
        if(_tm) memset(_tm, 0xFF, sizeof(struct tm));
        _invalid_parameter(NULL,
                           0,//__FUNCTION__, 
                           _CRT_WIDE(__FILE__), 
                           __LINE__, 
                           0);
        _set_errno(EINVAL);
        return EINVAL;
    }

    /* Validate input */
    if (*ptime < 0 || *ptime > _MAX__TIME64_T)
    {
        memset(_tm, 0xFF, sizeof(struct tm));
        _set_errno(EINVAL);
        return EINVAL;
    }

    _tm = localtime(ptime);
    return 0;
}

struct tm *
localtime(const time_t *ptime)
{
    time_t time = *ptime;
    struct tm * ptm;

    /* Check for invalid time value */
    if (time < 0)
    {
        return 0;
    }

    /* Never without */
    if (!_tz_is_set)
        _tzset();

    /* Check for overflow */

    /* Correct for timezone */
    time -= _timezone;
#if 0
    /* Correct for daylight saving */
    if (_isdstime(time))
    {
        ptm->tm_isdst = 1;
        time -= _dstbias;
    }
#endif
    ptm = gmtime(&time);

    return ptm;
}

