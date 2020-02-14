#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_46__   TYPE_9__ ;
typedef  struct TYPE_45__   TYPE_8__ ;
typedef  struct TYPE_44__   TYPE_7__ ;
typedef  struct TYPE_43__   TYPE_6__ ;
typedef  struct TYPE_42__   TYPE_5__ ;
typedef  struct TYPE_41__   TYPE_4__ ;
typedef  struct TYPE_40__   TYPE_3__ ;
typedef  struct TYPE_39__   TYPE_2__ ;
typedef  struct TYPE_38__   TYPE_1__ ;
typedef  struct TYPE_37__   TYPE_18__ ;
typedef  struct TYPE_36__   TYPE_17__ ;
typedef  struct TYPE_35__   TYPE_16__ ;
typedef  struct TYPE_34__   TYPE_15__ ;
typedef  struct TYPE_33__   TYPE_14__ ;
typedef  struct TYPE_32__   TYPE_13__ ;
typedef  struct TYPE_31__   TYPE_12__ ;
typedef  struct TYPE_30__   TYPE_11__ ;
typedef  struct TYPE_29__   TYPE_10__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  u_char ;
typedef  scalar_t__ ngx_uint_t ;
struct TYPE_41__ {int len; int /*<<< orphan*/ * data; } ;
struct TYPE_29__ {size_t size; int /*<<< orphan*/ * addr; int /*<<< orphan*/  log; TYPE_4__ name; } ;
typedef  TYPE_10__ ngx_shm_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_37__ {scalar_t__ spin; } ;
struct TYPE_30__ {TYPE_18__ ngx_http_tfs_kp_mutex; int /*<<< orphan*/ * ngx_http_tfs_kp_mutex_ptr; } ;
typedef  TYPE_11__ ngx_http_tfs_timers_lock_t ;
struct TYPE_31__ {TYPE_8__* lock; int /*<<< orphan*/  main_conf; TYPE_7__* upstream; } ;
typedef  TYPE_12__ ngx_http_tfs_timers_data_t ;
struct TYPE_38__ {int /*<<< orphan*/  code; } ;
struct TYPE_39__ {int version; TYPE_1__ action; } ;
struct TYPE_32__ {scalar_t__ (* finalize_request ) (TYPE_13__*) ;int /*<<< orphan*/  main_conf; TYPE_3__* loc_conf; TYPE_2__ r_ctx; TYPE_15__* finalize_data; int /*<<< orphan*/  log; TYPE_14__* data; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_13__ ngx_http_tfs_t ;
typedef  int /*<<< orphan*/  ngx_http_tfs_loc_conf_t ;
struct TYPE_33__ {TYPE_9__* connection; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_14__ ngx_http_request_t ;
struct TYPE_34__ {void (* handler ) (TYPE_15__*) ;int /*<<< orphan*/  log; TYPE_17__* data; scalar_t__ timer_set; } ;
typedef  TYPE_15__ ngx_event_t ;
struct TYPE_35__ {int /*<<< orphan*/  log; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_16__ ngx_cycle_t ;
struct TYPE_36__ {TYPE_12__* data; } ;
typedef  TYPE_17__ ngx_connection_t ;
typedef  int /*<<< orphan*/  ngx_atomic_t ;
struct TYPE_46__ {int destroyed; int /*<<< orphan*/  log; } ;
struct TYPE_45__ {int /*<<< orphan*/  ngx_http_tfs_kp_mutex; } ;
struct TYPE_44__ {int /*<<< orphan*/  rcs_interval; TYPE_6__* rc_ctx; } ;
struct TYPE_43__ {TYPE_5__* sh; } ;
struct TYPE_42__ {int /*<<< orphan*/  kp_queue; } ;
struct TYPE_40__ {TYPE_7__* upstream; } ;

/* Variables and functions */
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_ACTION_KEEPALIVE ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_EVENT ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  ngx_add_timer (TYPE_15__*,int /*<<< orphan*/ ) ; 
 int* ngx_crc32_table256 ; 
 int /*<<< orphan*/ * ngx_create_pool (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_destroy_pool (int /*<<< orphan*/ *) ; 
 scalar_t__ ngx_http_tfs_init (TYPE_13__*) ; 
static  void ngx_http_tfs_timeout_handler (TYPE_15__*) ; 
 int /*<<< orphan*/  ngx_log_debug0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 TYPE_11__* ngx_palloc (int /*<<< orphan*/ *,int) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 scalar_t__ ngx_queue_empty (int /*<<< orphan*/ *) ; 
 scalar_t__ ngx_shm_alloc (TYPE_10__*) ; 
 scalar_t__ ngx_shmtx_create (TYPE_18__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ ngx_shmtx_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_shmtx_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline uint32_t
ngx_http_tfs_crc(uint32_t crc, const char *data, size_t len)
{
    size_t i;

    for (i = 0; i < len; ++i) {
        crc = (crc >> 8) ^ ngx_crc32_table256[(crc ^ *data++) & 0xff];
    }

    return crc;
}

ngx_http_tfs_timers_lock_t *
ngx_http_tfs_timers_init(ngx_cycle_t *cycle,
    u_char *lock_file)
{
    u_char                     *shared;
    size_t                      size;
    ngx_shm_t                   shm;
    ngx_http_tfs_timers_lock_t *lock;

    /* cl should be equal or bigger than cache line size */

    size = 128; /* ngx_http_tfs_kp_mutex */

    shm.size = size;
    shm.name.len = sizeof("nginx_tfs_keepalive_zone");
    shm.name.data = (u_char *) "nginx_tfs_keepalive_zone";
    shm.log = cycle->log;

    if (ngx_shm_alloc(&shm) != NGX_OK) {
        return NULL;
    }

    shared = shm.addr;

    lock = ngx_palloc(cycle->pool, sizeof(ngx_http_tfs_timers_lock_t));
    if (lock == NULL) {
        return NULL;
    }

    lock->ngx_http_tfs_kp_mutex_ptr = (ngx_atomic_t *) shared;
    lock->ngx_http_tfs_kp_mutex.spin = (ngx_uint_t) -1;

#if defined(nginx_version) && (nginx_version > 1001008)

    if (ngx_shmtx_create(&lock->ngx_http_tfs_kp_mutex,
                         (ngx_shmtx_sh_t *) shared, lock_file)
        != NGX_OK)
    {
        return NULL;
    }

#else

    if (ngx_shmtx_create(&lock->ngx_http_tfs_kp_mutex, shared, lock_file)
        != NGX_OK)
    {
        return NULL;
    }
#endif

    return lock;
}

ngx_int_t
ngx_http_tfs_add_rcs_timers(ngx_cycle_t *cycle,
    ngx_http_tfs_timers_data_t *data)
{
    ngx_event_t         *ev;
    ngx_connection_t    *dummy;

    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cycle->log, 0,
                   "http check tfs rc servers");

    ev = ngx_pcalloc(cycle->pool, sizeof(ngx_event_t));
    if (ev == NULL) {
        return NGX_ERROR;
    }

    dummy = ngx_pcalloc(cycle->pool, sizeof(ngx_connection_t));
    if (dummy == NULL) {
        return NGX_ERROR;
    }

    dummy->data = data;
    ev->handler = ngx_http_tfs_timeout_handler;
    ev->log = cycle->log;
    ev->data = dummy;
    ev->timer_set = 0;

    ngx_add_timer(ev, data->upstream->rcs_interval);

    return NGX_OK;
}

ngx_int_t
ngx_http_tfs_timers_finalize_request_handler(ngx_http_tfs_t *t)
{
    ngx_event_t                 *event;
    ngx_connection_t            *dummy;
    ngx_http_tfs_timers_data_t  *data;

    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, t->log, 0, "http tfs timers finalize");

    event = t->finalize_data;
    dummy = event->data;
    data = dummy->data;

    ngx_destroy_pool(t->pool);
    ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
    ngx_add_timer(event, data->upstream->rcs_interval);
    return NGX_OK;
}

__attribute__((used)) static void
ngx_http_tfs_timeout_handler(ngx_event_t *event)
{
    ngx_int_t                   rc;
    ngx_pool_t                  *pool;
    ngx_http_tfs_t              *t;
    ngx_connection_t            *dummy;
    ngx_http_request_t          *r;
    ngx_http_tfs_timers_data_t  *data;

    dummy = event->data;
    data = dummy->data;
    if (ngx_shmtx_trylock(&data->lock->ngx_http_tfs_kp_mutex)) {

        if (ngx_queue_empty(&data->upstream->rc_ctx->sh->kp_queue)) {
            ngx_log_debug0(NGX_LOG_DEBUG_EVENT, event->log, 0,
                           "empty rc keepalive queue");
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            ngx_add_timer(event, data->upstream->rcs_interval);
            return;
        }

        pool = ngx_create_pool(8192, event->log);
        if (pool == NULL) {
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            return;
        }

        /* fake ngx_http_request_t */
        r = ngx_pcalloc(pool, sizeof(ngx_http_request_t));
        if (r == NULL) {
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            return;
        }

        r->pool = pool;
        r->connection = ngx_pcalloc(pool, sizeof(ngx_connection_t));
        if (r->connection == NULL) {
            ngx_destroy_pool(pool);
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            return;
        }
        r->connection->log = event->log;
        /* in order to return from ngx_http_run_posted_requests()  */
        r->connection->destroyed = 1;

        t = ngx_pcalloc(pool, sizeof(ngx_http_tfs_t));
        if (t == NULL) {
            ngx_destroy_pool(pool);
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            return;
        }

        t->pool = pool;
        t->data = r;
        t->log = event->log;
        t->finalize_request = ngx_http_tfs_timers_finalize_request_handler;
        t->finalize_data = event;

        t->r_ctx.action.code = NGX_HTTP_TFS_ACTION_KEEPALIVE;
        t->r_ctx.version = 1;
        t->loc_conf = ngx_pcalloc(pool, sizeof(ngx_http_tfs_loc_conf_t));
        if (t->loc_conf == NULL) {
            ngx_destroy_pool(pool);
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            return;
        }
        t->loc_conf->upstream = data->upstream;
        t->main_conf = data->main_conf;

        rc = ngx_http_tfs_init(t);
        if (rc == NGX_ERROR) {
            ngx_destroy_pool(pool);
            ngx_shmtx_unlock(&data->lock->ngx_http_tfs_kp_mutex);
            return;
        }

    } else {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, event->log, 0,
                       "tfs kp mutex lock failed");
    }
}

