#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
struct aiocb {int dummy; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  off_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_23__ {struct TYPE_23__* data; } ;
struct TYPE_19__ {TYPE_8__ name; int /*<<< orphan*/  fd; int /*<<< orphan*/  log; TYPE_3__* aio; } ;
typedef  TYPE_1__ ngx_file_t ;
struct TYPE_20__ {int ready; void (* handler ) (TYPE_2__*) ;int active; int /*<<< orphan*/  log; TYPE_3__* data; scalar_t__ complete; } ;
typedef  TYPE_2__ ngx_event_t ;
struct TYPE_22__ {size_t aio_nbytes; int /*<<< orphan*/ * aio_buf; int /*<<< orphan*/  aio_offset; int /*<<< orphan*/  aio_fildes; } ;
struct TYPE_21__ {scalar_t__ err; scalar_t__ nbytes; int /*<<< orphan*/  (* handler ) (TYPE_2__*) ;TYPE_1__* file; int /*<<< orphan*/  fd; TYPE_7__ aiocb; TYPE_2__ event; } ;
typedef  TYPE_3__ ngx_event_aio_t ;
typedef  int ngx_err_t ;

/* Variables and functions */
 scalar_t__ NGX_AGAIN ; 
 int NGX_EAGAIN ; 
 int NGX_EINPROGRESS ; 
 int NGX_ENOSYS ; 
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_LOG_ALERT ; 
 int /*<<< orphan*/  NGX_LOG_CRIT ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_CORE ; 
 scalar_t__ NGX_OK ; 
 int aio_error (TYPE_7__*) ; 
 int aio_read (TYPE_7__*) ; 
 int aio_return (TYPE_7__*) ; 
 int ngx_errno ; 
 scalar_t__ ngx_file_aio ; 
static  void ngx_file_aio_event_handler (TYPE_2__*) ; 
static  scalar_t__ ngx_file_aio_result (TYPE_1__*,TYPE_3__*,TYPE_2__*) ; 
 int /*<<< orphan*/  ngx_log_debug2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  ngx_log_debug4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,scalar_t__,int /*<<< orphan*/ ,size_t,TYPE_8__*) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,TYPE_8__*) ; 
 int /*<<< orphan*/  ngx_memzero (TYPE_7__*,int) ; 
 TYPE_3__* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 scalar_t__ ngx_read_file (TYPE_1__*,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_set_errno (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 

ngx_int_t
ngx_file_aio_init(ngx_file_t *file, ngx_pool_t *pool)
{
    ngx_event_aio_t  *aio;

    aio = ngx_pcalloc(pool, sizeof(ngx_event_aio_t));
    if (aio == NULL) {
        return NGX_ERROR;
    }

    aio->file = file;
    aio->fd = file->fd;
    aio->event.data = aio;
    aio->event.ready = 1;
    aio->event.log = file->log;

    file->aio = aio;

    return NGX_OK;
}

ssize_t
ngx_file_aio_read(ngx_file_t *file, u_char *buf, size_t size, off_t offset,
    ngx_pool_t *pool)
{
    int               n;
    ngx_event_t      *ev;
    ngx_event_aio_t  *aio;

    if (!ngx_file_aio) {
        return ngx_read_file(file, buf, size, offset);
    }

    if (file->aio == NULL && ngx_file_aio_init(file, pool) != NGX_OK) {
        return NGX_ERROR;
    }

    aio = file->aio;
    ev = &aio->event;

    if (!ev->ready) {
        ngx_log_error(NGX_LOG_ALERT, file->log, 0,
                      "second aio post for \"%V\"", &file->name);
        return NGX_AGAIN;
    }

    ngx_log_debug4(NGX_LOG_DEBUG_CORE, file->log, 0,
                   "aio complete:%d @%O:%uz %V",
                   ev->complete, offset, size, &file->name);

    if (ev->complete) {
        ev->complete = 0;
        ngx_set_errno(aio->err);

        if (aio->err == 0) {
            return aio->nbytes;
        }

        ngx_log_error(NGX_LOG_CRIT, file->log, ngx_errno,
                      "aio read \"%s\" failed", file->name.data);

        return NGX_ERROR;
    }

    ngx_memzero(&aio->aiocb, sizeof(struct aiocb));

    aio->aiocb.aio_fildes = file->fd;
    aio->aiocb.aio_offset = offset;
    aio->aiocb.aio_buf = buf;
    aio->aiocb.aio_nbytes = size;
#if (NGX_HAVE_KQUEUE)
    aio->aiocb.aio_sigevent.sigev_notify_kqueue = ngx_kqueue;
    aio->aiocb.aio_sigevent.sigev_notify = SIGEV_KEVENT;
    aio->aiocb.aio_sigevent.sigev_value.sival_ptr = ev;
#endif
    ev->handler = ngx_file_aio_event_handler;

    n = aio_read(&aio->aiocb);

    if (n == -1) {
        n = ngx_errno;

        if (n == NGX_EAGAIN) {
            return ngx_read_file(file, buf, size, offset);
        }

        ngx_log_error(NGX_LOG_CRIT, file->log, n,
                      "aio_read(\"%V\") failed", &file->name);

        if (n == NGX_ENOSYS) {
            ngx_file_aio = 0;
            return ngx_read_file(file, buf, size, offset);
        }

        return NGX_ERROR;
    }

    ngx_log_debug2(NGX_LOG_DEBUG_CORE, file->log, 0,
                   "aio_read: fd:%d %d", file->fd, n);

    ev->active = 1;
    ev->ready = 0;
    ev->complete = 0;

    return ngx_file_aio_result(aio->file, aio, ev);
}

__attribute__((used)) static ssize_t
ngx_file_aio_result(ngx_file_t *file, ngx_event_aio_t *aio, ngx_event_t *ev)
{
    int        n;
    ngx_err_t  err;

    n = aio_error(&aio->aiocb);

    ngx_log_debug2(NGX_LOG_DEBUG_CORE, file->log, 0,
                   "aio_error: fd:%d %d", file->fd, n);

    if (n == -1) {
        err = ngx_errno;
        aio->err = err;

        ngx_log_error(NGX_LOG_ALERT, file->log, err,
                      "aio_error(\"%V\") failed", &file->name);
        return NGX_ERROR;
    }

    if (n == NGX_EINPROGRESS) {
        if (ev->ready) {
            ev->ready = 0;
            ngx_log_error(NGX_LOG_ALERT, file->log, n,
                          "aio_read(\"%V\") still in progress",
                          &file->name);
        }

        return NGX_AGAIN;
    }

    n = aio_return(&aio->aiocb);

    if (n == -1) {
        err = ngx_errno;
        aio->err = err;
        ev->ready = 1;

        ngx_log_error(NGX_LOG_CRIT, file->log, err,
                      "aio_return(\"%V\") failed", &file->name);
        return NGX_ERROR;
    }

    aio->err = 0;
    aio->nbytes = n;
    ev->ready = 1;
    ev->active = 0;

    ngx_log_debug2(NGX_LOG_DEBUG_CORE, file->log, 0,
                   "aio_return: fd:%d %d", file->fd, n);

    return n;
}

__attribute__((used)) static void
ngx_file_aio_event_handler(ngx_event_t *ev)
{
    ngx_event_aio_t  *aio;

    aio = ev->data;

    ngx_log_debug2(NGX_LOG_DEBUG_CORE, ev->log, 0,
                   "aio event handler fd:%d %V", aio->fd, &aio->file->name);

    if (ngx_file_aio_result(aio->file, aio, ev) != NGX_AGAIN) {
        aio->handler(ev);
    }
}

