#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
typedef  size_t ngx_uint_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
struct TYPE_17__ {size_t size; size_t cnum; size_t lnum; size_t func; int /*<<< orphan*/ * num; struct TYPE_17__* next; } ;
typedef  TYPE_2__ ngx_pool_stat_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_16__ {int /*<<< orphan*/ * content_length_n; int /*<<< orphan*/  status; } ;
struct TYPE_18__ {scalar_t__ method; scalar_t__ header_only; TYPE_1__ headers_out; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_3__ ngx_http_request_t ;
struct TYPE_19__ {scalar_t__ (* handler ) (TYPE_3__*) ;} ;
typedef  TYPE_4__ ngx_http_core_loc_conf_t ;
typedef  int /*<<< orphan*/  ngx_conf_t ;
typedef  int /*<<< orphan*/  ngx_command_t ;
struct TYPE_20__ {int /*<<< orphan*/ * next; TYPE_6__* buf; } ;
typedef  TYPE_5__ ngx_chain_t ;
struct TYPE_21__ {int memory; int last_buf; int /*<<< orphan*/ * last; int /*<<< orphan*/ * pos; } ;
typedef  TYPE_6__ ngx_buf_t ;

/* Variables and functions */
 char* NGX_CONF_OK ; 
 scalar_t__ NGX_ERROR ; 
 scalar_t__ NGX_HTTP_GET ; 
 scalar_t__ NGX_HTTP_INTERNAL_SERVER_ERROR ; 
 scalar_t__ NGX_HTTP_NOT_ALLOWED ; 
 int /*<<< orphan*/  NGX_HTTP_OK ; 
 scalar_t__ NGX_OK ; 
 size_t NGX_POOL_STATS_MAX ; 
 int NGX_TIME_T_LEN ; 
 TYPE_4__* ngx_http_conf_get_module_loc_conf (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_core_module ; 
static  scalar_t__ ngx_http_debug_pool_buf (int /*<<< orphan*/ *,TYPE_6__*) ; 
 scalar_t__ ngx_http_discard_request_body (TYPE_3__*) ; 
 scalar_t__ ngx_http_output_filter (TYPE_3__*,TYPE_5__*) ; 
 scalar_t__ ngx_http_send_header (TYPE_3__*) ; 
 int /*<<< orphan*/ * ngx_palloc (int /*<<< orphan*/ *,size_t) ; 
 TYPE_6__* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_pid ; 
 TYPE_2__** ngx_pool_stats ; 
 int ngx_pool_stats_num ; 
 int /*<<< orphan*/ * ngx_snprintf (int /*<<< orphan*/ *,int,char*,size_t,int /*<<< orphan*/ *,size_t,size_t,size_t) ; 
 int /*<<< orphan*/ * ngx_sprintf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ngx_int_t
ngx_http_debug_pool_handler(ngx_http_request_t *r)
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

    if (ngx_http_debug_pool_buf(r->pool, b) == NGX_ERROR) {
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
ngx_http_debug_pool_buf(ngx_pool_t *pool, ngx_buf_t *b)
{
    u_char              *p, *unit;
    size_t               size, s, n, cn, ln;
    ngx_uint_t           i;
    ngx_pool_stat_t     *stat;

#define NGX_POOL_PID_SIZE       (NGX_TIME_T_LEN + sizeof("pid:\n") - 1)     /* sizeof pid_t equals time_t */
#define NGX_POOL_PID_FORMAT     "pid:%P\n"
#define NGX_POOL_ENTRY_SIZE     (48 /* func */ + 12 * 4 + sizeof("size: num: cnum: lnum: \n") - 1)
#define NGX_POOL_ENTRY_FORMAT   "size:%12z num:%12z cnum:%12z lnum:%12z %s\n"
#define NGX_POOL_SUMMARY_SIZE   (12 * 4 + sizeof("size: num: cnum: lnum: [SUMMARY]\n") - 1)
#define NGX_POOL_SUMMARY_FORMAT "size:%10z%2s num:%12z cnum:%12z lnum:%12z [SUMMARY]\n"

    size = NGX_POOL_PID_SIZE + ngx_pool_stats_num * NGX_POOL_ENTRY_SIZE
           + NGX_POOL_SUMMARY_SIZE;
    p = ngx_palloc(pool, size);
    if (p == NULL) {
        return NGX_ERROR;
    }

    b->pos = p;

    p = ngx_sprintf(p, NGX_POOL_PID_FORMAT, ngx_pid);

    /* lines of entry */

    s = n = cn = ln = 0;

    for (i = 0; i < NGX_POOL_STATS_MAX; i++) {
        for (stat = ngx_pool_stats[i]; stat != NULL; stat = stat->next) {
            p = ngx_snprintf(p, NGX_POOL_ENTRY_SIZE, NGX_POOL_ENTRY_FORMAT,
                             stat->size, stat->num, stat->cnum, stat->lnum,
                             stat->func);
            s += stat->size;
            n += stat->num;
            cn += stat->cnum;
            ln += stat->lnum;
        }
    }

    /* summary line */

    unit = (u_char *) " B";

    if (s > 1024 * 1024) {
        s = s / (1024 * 1024);
        unit = (u_char *) "MB";
    } else if (s > 1024) {
        s = s / 1024;
        unit = (u_char *) "KB";
    }

    p = ngx_snprintf(p, NGX_POOL_SUMMARY_SIZE, NGX_POOL_SUMMARY_FORMAT,
                     s, unit, n, cn, ln);

    b->last = p;
    b->memory = 1;
    b->last_buf = 1;

    return NGX_OK;
}

__attribute__((used)) static char *
ngx_http_debug_pool(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t *clcf;

    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_debug_pool_handler;

    return NGX_CONF_OK;
}

