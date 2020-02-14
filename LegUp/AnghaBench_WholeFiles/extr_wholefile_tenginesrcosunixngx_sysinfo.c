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
typedef  int /*<<< orphan*/  ngx_str_t ;
typedef  int /*<<< orphan*/  ngx_meminfo_t ;
typedef  int /*<<< orphan*/  ngx_log_t ;
typedef  int /*<<< orphan*/  ngx_int_t ;
typedef  int /*<<< orphan*/  ngx_cpuinfo_t ;

/* Variables and functions */
 int /*<<< orphan*/  NGX_ERROR ; 
 int /*<<< orphan*/  NGX_LOG_EMERG ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 

ngx_int_t
ngx_getloadavg(ngx_int_t avg[], ngx_int_t nelem, ngx_log_t *log)
{
#if (NGX_HAVE_GETLOADAVG)
    double      loadavg[3];
    ngx_int_t   i;

    if (getloadavg(loadavg, nelem) == -1) {
        return NGX_ERROR;
    }

    for (i = 0; i < nelem; i ++) {
        avg[i] = loadavg[i] * 1000;
    }

    return NGX_OK;

#elif (NGX_HAVE_SYSINFO)

    struct sysinfo s;
    ngx_int_t   i;

    if (sysinfo(&s)) {
        return NGX_ERROR;
    }

    for (i = 0; i < nelem; i ++) {
        avg[i] = s.loads[i] * 1000 / 65536;
    }

    return NGX_OK;

#else

    ngx_log_error(NGX_LOG_EMERG, log, 0,
                  "getloadavg is unsupported under current os");

    return NGX_ERROR;
#endif
}

ngx_int_t
ngx_getmeminfo(ngx_meminfo_t *meminfo, ngx_log_t *log)
{
    ngx_log_error(NGX_LOG_EMERG, log, 0,
                  "getmeminfo is unsupported under current os");

    return NGX_ERROR;
}

ngx_int_t
ngx_getcpuinfo(ngx_str_t *cpunumber, ngx_cpuinfo_t *cpuinfo, ngx_log_t *log)
{
    ngx_log_error(NGX_LOG_EMERG, log, 0,
                  "ngx_getcpuinfo is unsupported under current os");

    return NGX_ERROR;
}

