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
typedef  int /*<<< orphan*/  ngx_thread_mutex_t ;
typedef  int /*<<< orphan*/  ngx_thread_cond_t ;
typedef  int /*<<< orphan*/  ngx_log_t ;
typedef  int /*<<< orphan*/  ngx_int_t ;
typedef  scalar_t__ ngx_err_t ;

/* Variables and functions */
 int /*<<< orphan*/  NGX_ERROR ; 
 int /*<<< orphan*/  NGX_LOG_ALERT ; 
 int /*<<< orphan*/  NGX_LOG_EMERG ; 
 int /*<<< orphan*/  NGX_OK ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__,char*) ; 
 scalar_t__ pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_cond_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_cond_signal (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

ngx_int_t
ngx_thread_cond_create(ngx_thread_cond_t *cond, ngx_log_t *log)
{
    ngx_err_t  err;

    err = pthread_cond_init(cond, NULL);
    if (err == 0) {
        return NGX_OK;
    }

    ngx_log_error(NGX_LOG_EMERG, log, err, "pthread_cond_init() failed");
    return NGX_ERROR;
}

ngx_int_t
ngx_thread_cond_destroy(ngx_thread_cond_t *cond, ngx_log_t *log)
{
    ngx_err_t  err;

    err = pthread_cond_destroy(cond);
    if (err == 0) {
        return NGX_OK;
    }

    ngx_log_error(NGX_LOG_EMERG, log, err, "pthread_cond_destroy() failed");
    return NGX_ERROR;
}

ngx_int_t
ngx_thread_cond_signal(ngx_thread_cond_t *cond, ngx_log_t *log)
{
    ngx_err_t  err;

    err = pthread_cond_signal(cond);
    if (err == 0) {
        return NGX_OK;
    }

    ngx_log_error(NGX_LOG_EMERG, log, err, "pthread_cond_signal() failed");
    return NGX_ERROR;
}

ngx_int_t
ngx_thread_cond_wait(ngx_thread_cond_t *cond, ngx_thread_mutex_t *mtx,
    ngx_log_t *log)
{
    ngx_err_t  err;

    err = pthread_cond_wait(cond, mtx);

#if 0
    ngx_time_update();
#endif

    if (err == 0) {
        return NGX_OK;
    }

    ngx_log_error(NGX_LOG_ALERT, log, err, "pthread_cond_wait() failed");

    return NGX_ERROR;
}

