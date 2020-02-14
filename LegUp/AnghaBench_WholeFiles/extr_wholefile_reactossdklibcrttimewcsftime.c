#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct tm {int /*<<< orphan*/  tm_sec; int /*<<< orphan*/  tm_min; int /*<<< orphan*/  tm_hour; int /*<<< orphan*/  tm_mday; int /*<<< orphan*/  tm_wday; scalar_t__ tm_mon; scalar_t__ tm_year; } ;
struct TYPE_9__ {char* date; char* short_date; int /*<<< orphan*/  time; } ;
struct TYPE_10__ {TYPE_1__ names; } ;
struct TYPE_12__ {TYPE_2__ str; int /*<<< orphan*/  lcid; } ;
struct TYPE_11__ {scalar_t__ wMilliseconds; int /*<<< orphan*/  wSecond; int /*<<< orphan*/  wMinute; int /*<<< orphan*/  wHour; int /*<<< orphan*/  wDay; int /*<<< orphan*/  wDayOfWeek; scalar_t__ wMonth; scalar_t__ wYear; } ;
typedef  TYPE_3__ SYSTEMTIME ;
typedef  TYPE_4__ MSVCRT___lc_time_data ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ERANGE ; 
 scalar_t__ FALSE ; 
 size_t GetDateFormatA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*,char*,char*,size_t) ; 
 size_t GetTimeFormatA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,char*,size_t) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/ * _errno () ; 
 size_t _snprintf (char*,size_t,char*,int,int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,size_t) ; 
 size_t strlen (char*) ; 

__attribute__((used)) static inline BOOL strftime_date(char *str, size_t *pos, size_t max,
        BOOL alternate, const struct tm *mstm, MSVCRT___lc_time_data *time_data)
{
    char *format;
    SYSTEMTIME st;
    size_t ret;

    st.wYear = mstm->tm_year + 1900;
    st.wMonth = mstm->tm_mon + 1;
    st.wDayOfWeek = mstm->tm_wday;
    st.wDay = mstm->tm_mday;
    st.wHour = mstm->tm_hour;
    st.wMinute = mstm->tm_min;
    st.wSecond = mstm->tm_sec;
    st.wMilliseconds = 0;

    format = alternate ? time_data->str.names.date : time_data->str.names.short_date;
    ret = GetDateFormatA(time_data->lcid, 0, &st, format, NULL, 0);
    if(ret && ret<max-*pos)
        ret = GetDateFormatA(time_data->lcid, 0, &st, format, str+*pos, max-*pos);
    if(!ret) {
        *str = 0;
        *_errno() = EINVAL;
        return FALSE;
    }else if(ret > max-*pos) {
        *str = 0;
        *_errno() = ERANGE;
        return FALSE;
    }
    *pos += ret-1;
    return TRUE;
}

__attribute__((used)) static inline BOOL strftime_time(char *str, size_t *pos, size_t max,
        const struct tm *mstm, MSVCRT___lc_time_data *time_data)
{
    SYSTEMTIME st;
    size_t ret;

    st.wYear = mstm->tm_year + 1900;
    st.wMonth = mstm->tm_mon + 1;
    st.wDayOfWeek = mstm->tm_wday;
    st.wDay = mstm->tm_mday;
    st.wHour = mstm->tm_hour;
    st.wMinute = mstm->tm_min;
    st.wSecond = mstm->tm_sec;
    st.wMilliseconds = 0;

    ret = GetTimeFormatA(time_data->lcid, 0, &st, time_data->str.names.time, NULL, 0);
    if(ret && ret<max-*pos)
        ret = GetTimeFormatA(time_data->lcid, 0, &st, time_data->str.names.time,
                str+*pos, max-*pos);
    if(!ret) {
        *str = 0;
        *_errno() = EINVAL;
        return FALSE;
    }else if(ret > max-*pos) {
        *str = 0;
        *_errno() = ERANGE;
        return FALSE;
    }
    *pos += ret-1;
    return TRUE;
}

__attribute__((used)) static inline BOOL strftime_str(char *str, size_t *pos, size_t max, char *src)
{
    size_t len = strlen(src);
    if(len > max-*pos) {
        *str = 0;
        *_errno() = ERANGE;
        return FALSE;
    }

    memcpy(str+*pos, src, len);
    *pos += len;
    return TRUE;
}

__attribute__((used)) static inline BOOL strftime_int(char *str, size_t *pos, size_t max,
        int src, int prec, int l, int h)
{
    size_t len;

    if(src<l || src>h) {
        *str = 0;
        *_errno() = EINVAL;
        return FALSE;
    }

    len = _snprintf(str+*pos, max-*pos, "%0*d", prec, src);
    if(len == -1) {
        *str = 0;
        *_errno() = ERANGE;
        return FALSE;
    }

    *pos += len;
    return TRUE;
}

