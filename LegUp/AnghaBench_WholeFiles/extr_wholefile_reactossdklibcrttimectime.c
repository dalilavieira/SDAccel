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
typedef  int /*<<< orphan*/  time_t ;
struct tm {int dummy; } ;
typedef  scalar_t__ errno_t ;
typedef  int /*<<< orphan*/  _TCHAR ;

/* Variables and functions */
 scalar_t__ EINVAL ; 
 int /*<<< orphan*/ * _tasctime (struct tm*) ; 
 scalar_t__ _tasctime_s (int /*<<< orphan*/ *,size_t,struct tm*) ; 
 struct tm* localtime (int /*<<< orphan*/  const*) ; 
 scalar_t__ localtime_s (struct tm*,int /*<<< orphan*/  const*) ; 

errno_t
_tctime_s(_TCHAR *buffer, size_t numberOfElements, const time_t *time)
{
    struct tm _tm;

    if (localtime_s(&_tm, time) == EINVAL)
    {
        return EINVAL;
    }
    return _tasctime_s(buffer, numberOfElements, &_tm);
}

_TCHAR *
_tctime(const time_t *ptime)
{
    struct tm *ptm = localtime(ptime);
    if (!ptm)
    {
        return 0;
    }
    return _tasctime(ptm);
}

