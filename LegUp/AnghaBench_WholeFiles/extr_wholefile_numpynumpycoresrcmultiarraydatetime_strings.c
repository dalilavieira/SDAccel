#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct tm {int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; } ;
typedef  int npy_int64 ;
struct TYPE_6__ {int year; int hour; int min; int day; int month; int as; int ps; int us; scalar_t__ sec; } ;
typedef  TYPE_1__ npy_datetimestruct ;
typedef  int NPY_TIME_T ;
typedef  int /*<<< orphan*/  NPY_DATETIMEUNIT ;

/* Variables and functions */
 int /*<<< orphan*/  NPY_FR_D ; 
 int /*<<< orphan*/  NPY_FR_M ; 
 int /*<<< orphan*/  NPY_FR_Y ; 
 int /*<<< orphan*/  NPY_FR_as ; 
 int /*<<< orphan*/  NPY_FR_fs ; 
 int /*<<< orphan*/  NPY_FR_h ; 
 int /*<<< orphan*/  NPY_FR_m ; 
 int /*<<< orphan*/  NPY_FR_ms ; 
 int /*<<< orphan*/  NPY_FR_ns ; 
 int /*<<< orphan*/  NPY_FR_ps ; 
 int /*<<< orphan*/  NPY_FR_s ; 
 int /*<<< orphan*/  NPY_FR_us ; 
 int /*<<< orphan*/  PyErr_Format (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  PyExc_OSError ; 
 scalar_t__ get_datetimestruct_days (TYPE_1__*) ; 
 scalar_t__ is_leapyear (int) ; 
 int /*<<< orphan*/ * localtime_r (int*,struct tm*) ; 

__attribute__((used)) static int
get_localtime(NPY_TIME_T *ts, struct tm *tms)
{
    char *func_name = "<unknown>";
#if defined(_WIN32)
 #if defined(_MSC_VER) && (_MSC_VER >= 1400)
    if (localtime_s(tms, ts) != 0) {
        func_name = "localtime_s";
        goto fail;
    }
 #elif defined(NPY_MINGW_USE_CUSTOM_MSVCR)
    if (_localtime64_s(tms, ts) != 0) {
        func_name = "_localtime64_s";
        goto fail;
    }
 #else
    struct tm *tms_tmp;
    tms_tmp = localtime(ts);
    if (tms_tmp == NULL) {
        func_name = "localtime";
        goto fail;
    }
    memcpy(tms, tms_tmp, sizeof(struct tm));
 #endif
#else
    if (localtime_r(ts, tms) == NULL) {
        func_name = "localtime_r";
        goto fail;
    }
#endif

    return 0;

fail:
    PyErr_Format(PyExc_OSError, "Failed to use '%s' to convert "
                                "to a local time", func_name);
    return -1;
}

__attribute__((used)) static int
convert_datetimestruct_utc_to_local(npy_datetimestruct *out_dts_local,
                const npy_datetimestruct *dts_utc, int *out_timezone_offset)
{
    NPY_TIME_T rawtime = 0, localrawtime;
    struct tm tm_;
    npy_int64 year_correction = 0;

    /* Make a copy of the input 'dts' to modify */
    *out_dts_local = *dts_utc;

    /*
     * For 32 bit NPY_TIME_T, the get_localtime() function does not work for
     * years later than 2038, see the comments above get_localtime(). So if the
     * year >= 2038, we instead call get_localtime() for the year 2036 or 2037
     * (depending on the leap year) which must work and at the end we add the
     * 'year_correction' back.
     */
    if (sizeof(NPY_TIME_T) == 4 && out_dts_local->year >= 2038) {
        if (is_leapyear(out_dts_local->year)) {
            /* 2036 is a leap year */
            year_correction = out_dts_local->year - 2036;
            out_dts_local->year -= year_correction; /* = 2036 */
        }
        else {
            /* 2037 is not a leap year */
            year_correction = out_dts_local->year - 2037;
            out_dts_local->year -= year_correction; /* = 2037 */
        }
    }

    /*
     * Convert everything in 'dts' to a time_t, to minutes precision.
     * This is POSIX time, which skips leap-seconds, but because
     * we drop the seconds value from the npy_datetimestruct, everything
     * is ok for this operation.
     */
    rawtime = (NPY_TIME_T)get_datetimestruct_days(out_dts_local) * 24 * 60 * 60;
    rawtime += dts_utc->hour * 60 * 60;
    rawtime += dts_utc->min * 60;

    /* localtime converts a 'time_t' into a local 'struct tm' */
    if (get_localtime(&rawtime, &tm_) < 0) {
        /* This should only fail if year < 1970 on some platforms. */
        return -1;
    }

    /* Copy back all the values except seconds */
    out_dts_local->min = tm_.tm_min;
    out_dts_local->hour = tm_.tm_hour;
    out_dts_local->day = tm_.tm_mday;
    out_dts_local->month = tm_.tm_mon + 1;
    out_dts_local->year = tm_.tm_year + 1900;

    /* Extract the timezone offset that was applied */
    rawtime /= 60;
    localrawtime = (NPY_TIME_T)get_datetimestruct_days(out_dts_local) * 24 * 60;
    localrawtime += out_dts_local->hour * 60;
    localrawtime += out_dts_local->min;

    *out_timezone_offset = localrawtime - rawtime;

    /* Reapply the year 2038 year correction */
    out_dts_local->year += year_correction;

    return 0;
}

__attribute__((used)) static NPY_DATETIMEUNIT
lossless_unit_from_datetimestruct(npy_datetimestruct *dts)
{
    if (dts->as % 1000 != 0) {
        return NPY_FR_as;
    }
    else if (dts->as != 0) {
        return NPY_FR_fs;
    }
    else if (dts->ps % 1000 != 0) {
        return NPY_FR_ps;
    }
    else if (dts->ps != 0) {
        return NPY_FR_ns;
    }
    else if (dts->us % 1000 != 0) {
        return NPY_FR_us;
    }
    else if (dts->us != 0) {
        return NPY_FR_ms;
    }
    else if (dts->sec != 0) {
        return NPY_FR_s;
    }
    else if (dts->min != 0) {
        return NPY_FR_m;
    }
    else if (dts->hour != 0) {
        return NPY_FR_h;
    }
    else if (dts->day != 1) {
        return NPY_FR_D;
    }
    else if (dts->month != 1) {
        return NPY_FR_M;
    }
    else {
        return NPY_FR_Y;
    }
}

