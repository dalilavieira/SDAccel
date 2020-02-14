#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_22__ ;
typedef  struct TYPE_27__   TYPE_1__ ;
typedef  struct TYPE_26__   TYPE_13__ ;
typedef  struct TYPE_25__   TYPE_12__ ;
typedef  struct TYPE_24__   TYPE_11__ ;
typedef  struct TYPE_23__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
typedef  size_t ngx_uint_t ;
struct TYPE_32__ {int /*<<< orphan*/  fails; int /*<<< orphan*/  reqs; int /*<<< orphan*/  used; int /*<<< orphan*/  total; } ;
typedef  TYPE_5__ ngx_slab_stat_t ;
struct TYPE_34__ {size_t slab; struct TYPE_34__* next; } ;
struct TYPE_33__ {int min_shift; size_t pfree; int /*<<< orphan*/  mutex; TYPE_5__* stats; int /*<<< orphan*/  end; int /*<<< orphan*/  start; TYPE_7__ free; } ;
typedef  TYPE_6__ ngx_slab_pool_t ;
typedef  TYPE_7__ ngx_slab_page_t ;
struct TYPE_30__ {scalar_t__ len; } ;
struct TYPE_31__ {int size; TYPE_3__ name; scalar_t__ addr; } ;
struct TYPE_35__ {TYPE_4__ shm; } ;
typedef  TYPE_8__ ngx_shm_zone_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
struct TYPE_36__ {size_t nelts; TYPE_8__* elts; struct TYPE_36__* next; } ;
typedef  TYPE_9__ ngx_list_part_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_27__ {int /*<<< orphan*/ * content_length_n; int /*<<< orphan*/  status; } ;
struct TYPE_23__ {scalar_t__ method; scalar_t__ header_only; TYPE_1__ headers_out; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_10__ ngx_http_request_t ;
struct TYPE_24__ {scalar_t__ (* handler ) (TYPE_10__*) ;} ;
typedef  TYPE_11__ ngx_http_core_loc_conf_t ;
typedef  int /*<<< orphan*/  ngx_conf_t ;
typedef  int /*<<< orphan*/  ngx_command_t ;
struct TYPE_25__ {int /*<<< orphan*/ * next; TYPE_13__* buf; } ;
typedef  TYPE_12__ ngx_chain_t ;
struct TYPE_26__ {int memory; int last_buf; int /*<<< orphan*/ * last; int /*<<< orphan*/ * pos; } ;
typedef  TYPE_13__ ngx_buf_t ;
struct TYPE_29__ {TYPE_9__ part; } ;
struct TYPE_28__ {TYPE_2__ shared_memory; } ;

/* Variables and functions */
 char* NGX_CONF_OK ; 
 scalar_t__ NGX_ERROR ; 
 scalar_t__ NGX_HTTP_GET ; 
 scalar_t__ NGX_HTTP_INTERNAL_SERVER_ERROR ; 
 scalar_t__ NGX_HTTP_NOT_ALLOWED ; 
 int /*<<< orphan*/  NGX_HTTP_OK ; 
 scalar_t__ NGX_OK ; 
 TYPE_22__* ngx_cycle ; 
 TYPE_11__* ngx_http_conf_get_module_loc_conf (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_core_module ; 
 scalar_t__ ngx_http_discard_request_body (TYPE_10__*) ; 
 scalar_t__ ngx_http_output_filter (TYPE_10__*,TYPE_12__*) ; 
 scalar_t__ ngx_http_send_header (TYPE_10__*) ; 
static  scalar_t__ ngx_http_slab_stat_buf (int /*<<< orphan*/ *,TYPE_13__*) ; 
 int ngx_pagesize_shift ; 
 int /*<<< orphan*/ * ngx_palloc (int /*<<< orphan*/ *,size_t) ; 
 TYPE_13__* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_shmtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_shmtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ngx_snprintf (int /*<<< orphan*/ *,int,char*,...) ; 

__attribute__((used)) static ngx_int_t
ngx_http_slab_stat_handler(ngx_http_request_t *r)
{
    ngx_int_t    rc;
    ngx_buf_t   *b;
    ngx_chain_t  out;

    if (r->method != NGX_HTTP_GET) {
        return NGX_HTTP_NOT_ALLOWED;
    }

    rc = ngx_http_discard_request_body(r);
    if (rc != NGX_OK) {
        return rc;
    }

    b = ngx_pcalloc(r->pool, sizeof(ngx_buf_t));
    if (b == NULL) {
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }

    if (ngx_http_slab_stat_buf(r->pool, b) == NGX_ERROR) {
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }

    r->headers_out.status = NGX_HTTP_OK;
    r->headers_out.content_length_n = b->last - b->pos;

    rc = ngx_http_send_header(r);

    if (rc == NGX_ERROR || rc > NGX_OK || r->header_only) {
        return rc;
    }

    out.buf = b;
    out.next = NULL;

    return ngx_http_output_filter(r, &out);
}

__attribute__((used)) static ngx_int_t
ngx_http_slab_stat_buf(ngx_pool_t *pool, ngx_buf_t *b)
{
    u_char                       *p;
    size_t                        pz, size;
    ngx_uint_t                    i, k, n;
    ngx_shm_zone_t               *shm_zone;
    ngx_slab_pool_t              *shpool;
    ngx_slab_page_t              *page;
    ngx_slab_stat_t              *stats;
    volatile ngx_list_part_t     *part;

#define NGX_SLAB_SHM_SIZE               (sizeof("* shared memory: \n") - 1)
#define NGX_SLAB_SHM_FORMAT             "* shared memory: %V\n"
#define NGX_SLAB_SUMMARY_SIZE           \
    (3 * 12 + sizeof("total:(KB) free:(KB) size:(KB)\n") - 1)
#define NGX_SLAB_SUMMARY_FORMAT         \
    "total:%12z(KB) free:%12z(KB) size:%12z(KB)\n"
#define NGX_SLAB_PAGE_ENTRY_SIZE        \
    (12 + 2 * 16 + sizeof("pages:(KB) start: end:\n") - 1)
#define NGX_SLAB_PAGE_ENTRY_FORMAT      \
    "pages:%12z(KB) start:%p end:%p\n"
#define NGX_SLAB_SLOT_ENTRY_SIZE        \
    (12 * 5 + sizeof("slot:(Bytes) total: used: reqs: fails:\n") - 1)
#define NGX_SLAB_SLOT_ENTRY_FORMAT      \
    "slot:%12z(Bytes) total:%12z used:%12z reqs:%12z fails:%12z\n"

    pz = 0;

    /* query shared memory */

    part = &ngx_cycle->shared_memory.part;
    shm_zone = part->elts;

    for (i = 0; /* void */ ; i++) {

        if (i >= part->nelts) {
            if (part->next == NULL) {
                break;
            }
            part = part->next;
            shm_zone = part->elts;
            i = 0;
        }

        pz += NGX_SLAB_SHM_SIZE + (size_t)shm_zone[i].shm.name.len;
        pz += NGX_SLAB_SUMMARY_SIZE;

        shpool = (ngx_slab_pool_t *) shm_zone[i].shm.addr;

        ngx_shmtx_lock(&shpool->mutex);

        for (page = shpool->free.next; page != &shpool->free; page = page->next) {
            pz += NGX_SLAB_PAGE_ENTRY_SIZE;
        }

        n = ngx_pagesize_shift - shpool->min_shift;

        ngx_shmtx_unlock(&shpool->mutex);

        for (k = 0; k < n; k++) {
            pz += NGX_SLAB_SLOT_ENTRY_SIZE;
        }

    }

    /* preallocate pz * 2 to make sure memory enough */
    p = ngx_palloc(pool, pz * 2);
    if (p == NULL) {
        return NGX_ERROR;
    }

    b->pos = p;

    size = 1 << ngx_pagesize_shift;

    part = &ngx_cycle->shared_memory.part;
    shm_zone = part->elts;

    for (i = 0; /* void */ ; i++) {

        if (i >= part->nelts) {
            if (part->next == NULL) {
                break;
            }
            part = part->next;
            shm_zone = part->elts;
            i = 0;
        }

        shpool = (ngx_slab_pool_t *) shm_zone[i].shm.addr;

        p = ngx_snprintf(p, NGX_SLAB_SHM_SIZE + shm_zone[i].shm.name.len,
            NGX_SLAB_SHM_FORMAT, &shm_zone[i].shm.name);

        ngx_shmtx_lock(&shpool->mutex);

        p = ngx_snprintf(p, NGX_SLAB_SUMMARY_SIZE, NGX_SLAB_SUMMARY_FORMAT,
            shm_zone[i].shm.size / 1024, shpool->pfree * size / 1024,
            size / 1024, shpool->pfree);

        for (page = shpool->free.next; page != &shpool->free; page = page->next) {
            p = ngx_snprintf(p, NGX_SLAB_PAGE_ENTRY_SIZE,
                NGX_SLAB_PAGE_ENTRY_FORMAT, page->slab * size / 1024,
                shpool->start, shpool->end);
        }

        stats = shpool->stats;

        n = ngx_pagesize_shift - shpool->min_shift;

        for (k = 0; k < n; k++) {
            p = ngx_snprintf(p, NGX_SLAB_SLOT_ENTRY_SIZE, NGX_SLAB_SLOT_ENTRY_FORMAT,
                1 << (k + shpool->min_shift),
                stats[k].total, stats[k].used, stats[k].reqs, stats[k].fails);
        }

        ngx_shmtx_unlock(&shpool->mutex);
    }

    b->last = p;
    b->memory = 1;
    b->last_buf = 1;

    return NGX_OK;
}

__attribute__((used)) static char *
ngx_http_slab_stat(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t *clcf;

    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_slab_stat_handler;

    return NGX_CONF_OK;
}

