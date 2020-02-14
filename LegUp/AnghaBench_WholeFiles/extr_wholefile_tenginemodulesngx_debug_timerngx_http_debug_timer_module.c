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

/* Type definitions */
typedef  char u_char ;
typedef  int ngx_uint_t ;
struct TYPE_30__ {scalar_t__ key; struct TYPE_30__* right; struct TYPE_30__* left; } ;
typedef  TYPE_3__ ngx_rbtree_node_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  scalar_t__ ngx_msec_int_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_27__ {char* content_length_n; int /*<<< orphan*/  status; } ;
struct TYPE_31__ {scalar_t__ method; scalar_t__ header_only; TYPE_1__ headers_out; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_4__ ngx_http_request_t ;
struct TYPE_32__ {scalar_t__ (* handler ) (TYPE_4__*) ;} ;
typedef  TYPE_5__ ngx_http_core_loc_conf_t ;
struct TYPE_33__ {TYPE_2__* log; int /*<<< orphan*/  handler; int /*<<< orphan*/  data; int /*<<< orphan*/  timer; } ;
typedef  TYPE_6__ ngx_event_t ;
typedef  int /*<<< orphan*/  ngx_conf_t ;
typedef  int /*<<< orphan*/  ngx_command_t ;
struct TYPE_34__ {int /*<<< orphan*/ * next; TYPE_8__* buf; } ;
typedef  TYPE_7__ ngx_chain_t ;
struct TYPE_35__ {char* last; char* pos; int memory; int last_buf; } ;
typedef  TYPE_8__ ngx_buf_t ;
struct TYPE_36__ {int nelts; scalar_t__ elts; } ;
typedef  TYPE_9__ ngx_array_t ;
struct TYPE_29__ {char* action; } ;
struct TYPE_28__ {TYPE_3__* root; TYPE_3__* sentinel; } ;

/* Variables and functions */
 char* NGX_CONF_OK ; 
 scalar_t__ NGX_ERROR ; 
 scalar_t__ NGX_HTTP_GET ; 
 scalar_t__ NGX_HTTP_INTERNAL_SERVER_ERROR ; 
 scalar_t__ NGX_HTTP_NOT_ALLOWED ; 
 int /*<<< orphan*/  NGX_HTTP_OK ; 
 int NGX_INT_T_LEN ; 
 scalar_t__ NGX_OK ; 
 int NGX_PTR_SIZE ; 
 int NGX_TIME_T_LEN ; 
 TYPE_9__* ngx_array_create (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  ngx_array_destroy (TYPE_9__*) ; 
 TYPE_3__** ngx_array_push (TYPE_9__*) ; 
 scalar_t__ ngx_current_msec ; 
 TYPE_22__ ngx_event_timer_rbtree ; 
 TYPE_5__* ngx_http_conf_get_module_loc_conf (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_core_module ; 
static  scalar_t__ ngx_http_debug_timer_buf (int /*<<< orphan*/ *,TYPE_8__*) ; 
 scalar_t__ ngx_http_discard_request_body (TYPE_4__*) ; 
 scalar_t__ ngx_http_output_filter (TYPE_4__*,TYPE_7__*) ; 
 scalar_t__ ngx_http_send_header (TYPE_4__*) ; 
 char* ngx_palloc (int /*<<< orphan*/ *,size_t) ; 
 TYPE_8__* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_pid ; 
 char* ngx_snprintf (char*,int,char*,int,TYPE_3__*,scalar_t__,TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 char* ngx_sprintf (char*,char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static ngx_int_t
ngx_http_debug_timer_handler(ngx_http_request_t *r)
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

    if (ngx_http_debug_timer_buf(r->pool, b) == NGX_ERROR) {
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

__attribute__((used)) static void
ngx_http_debug_timer_traversal(ngx_array_t *array, ngx_rbtree_node_t *root)
{
    ngx_rbtree_node_t              **node;

    if (array != NULL && root != NULL
        && root != ngx_event_timer_rbtree.sentinel)
    {
        ngx_http_debug_timer_traversal(array, root->left);
        node = ngx_array_push(array);
        if (node == NULL) {
            return;
        }
        *node = (ngx_rbtree_node_t *) root;
        ngx_http_debug_timer_traversal(array, root->right);
    }
}

__attribute__((used)) static ngx_int_t
ngx_http_debug_timer_buf(ngx_pool_t *pool, ngx_buf_t *b)
{
    u_char              *p;
    size_t               size;
    ngx_uint_t           i, n;
    ngx_event_t         *ev;
    ngx_array_t         *array;
    ngx_msec_int_t       timer;
    ngx_rbtree_node_t   *root;
    ngx_rbtree_node_t  **nodes, *node;

#define NGX_TIMER_TITLE_SIZE     (sizeof(NGX_TIMER_TITLE_FORMAT) - 1 + NGX_TIME_T_LEN + NGX_INT_T_LEN)     /* sizeof pid_t equals time_t */
#define NGX_TIMER_TITLE_FORMAT   "pid:%P\n"                  \
                                 "timer:%ui\n"

#define NGX_TIMER_ENTRY_SIZE     (sizeof(NGX_TIMER_ENTRY_FORMAT) - 1 + \
                                  NGX_INT_T_LEN * 2 + NGX_PTR_SIZE * 4 + 256 /* func name */)
#define NGX_TIMER_ENTRY_FORMAT  "--------- [%ui] --------\n"\
                                "timers[i]: %p\n"          \
                                "    timer: %ui\n"          \
                                "       ev: %p\n"           \
                                "     data: %p\n"           \
                                "  handler: %p\n"           \
                                "   action: %s\n"

    root = ngx_event_timer_rbtree.root;

    array = ngx_array_create(pool, 10, sizeof(ngx_rbtree_node_t **));
    if (array == NULL) {
        return NGX_ERROR;
    }

    ngx_http_debug_timer_traversal(array, root);

    n = array->nelts;

    size = NGX_TIMER_TITLE_SIZE + n * NGX_TIMER_ENTRY_SIZE;
    p = ngx_palloc(pool, size);
    if (p == NULL) {
        ngx_array_destroy(array);
        return NGX_ERROR;
    }

    b->pos = p;

    p = ngx_sprintf(p, NGX_TIMER_TITLE_FORMAT, ngx_pid, n);

    nodes = (ngx_rbtree_node_t **) array->elts;

    for (i = 0; i < n; i++) {
        node = nodes[i]; /* node: timer */
        ev = (ngx_event_t *) ((char *) node - (intptr_t)&((ngx_event_t *) 0x0)->timer);

         /* entry format of timer and ev */

        timer = (ngx_msec_int_t) (node->key - ngx_current_msec);

        p = ngx_snprintf(p, NGX_TIMER_ENTRY_SIZE, NGX_TIMER_ENTRY_FORMAT,
                         i, node, timer, ev, ev->data, ev->handler,
                         (ev->log->action != NULL) ? ev->log->action : "");
    }

    ngx_array_destroy(array);

    p[-1] = '\n';  /* make sure last char is newline */

    b->last = p;
    b->memory = 1;
    b->last_buf = 1;

    return NGX_OK;
}

__attribute__((used)) static char *
ngx_http_debug_timer(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t *clcf;

    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_debug_timer_handler;

    return NGX_CONF_OK;
}

