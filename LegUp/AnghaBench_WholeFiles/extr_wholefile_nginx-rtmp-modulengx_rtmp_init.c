#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_52__   TYPE_9__ ;
typedef  struct TYPE_51__   TYPE_8__ ;
typedef  struct TYPE_50__   TYPE_7__ ;
typedef  struct TYPE_49__   TYPE_6__ ;
typedef  struct TYPE_48__   TYPE_5__ ;
typedef  struct TYPE_47__   TYPE_4__ ;
typedef  struct TYPE_46__   TYPE_3__ ;
typedef  struct TYPE_45__   TYPE_35__ ;
typedef  struct TYPE_44__   TYPE_33__ ;
typedef  struct TYPE_43__   TYPE_2__ ;
typedef  struct TYPE_42__   TYPE_23__ ;
typedef  struct TYPE_41__   TYPE_1__ ;
typedef  struct TYPE_40__   TYPE_12__ ;
typedef  struct TYPE_39__   TYPE_11__ ;
typedef  struct TYPE_38__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
struct TYPE_43__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {TYPE_2__ sin_addr; } ;
struct sockaddr {int sa_family; } ;
typedef  int ngx_uint_t ;
typedef  int /*<<< orphan*/  ngx_rtmp_stream_t ;
struct TYPE_39__ {void (* handler ) (TYPE_11__*) ;TYPE_33__* log; TYPE_4__* data; } ;
struct TYPE_45__ {scalar_t__ timer_set; } ;
struct TYPE_47__ {int auto_pushed; int out_queue; int out_pos; int out_last; TYPE_11__ close; TYPE_12__* connection; int /*<<< orphan*/ * out; int /*<<< orphan*/ * in_pool; int /*<<< orphan*/ * in_old_pool; TYPE_35__ ping_evt; int /*<<< orphan*/ * addr_text; int /*<<< orphan*/  buflen; int /*<<< orphan*/  timeout; int /*<<< orphan*/  epoch; int /*<<< orphan*/ * in_streams; int /*<<< orphan*/  out_cork; int /*<<< orphan*/ * ctx; scalar_t__* srv_conf; int /*<<< orphan*/  main_conf; } ;
typedef  TYPE_4__ ngx_rtmp_session_t ;
struct TYPE_48__ {int naddrs; TYPE_6__* addrs; } ;
typedef  TYPE_5__ ngx_rtmp_port_t ;
struct TYPE_52__ {int /*<<< orphan*/  addr_text; TYPE_3__* ctx; scalar_t__ proxy_protocol; } ;
struct TYPE_49__ {TYPE_9__ conf; int /*<<< orphan*/  addr; } ;
typedef  TYPE_6__ ngx_rtmp_in_addr_t ;
struct TYPE_50__ {TYPE_4__* session; int /*<<< orphan*/ * client; } ;
typedef  TYPE_7__ ngx_rtmp_error_log_ctx_t ;
struct TYPE_51__ {int out_queue; int max_streams; int /*<<< orphan*/  buflen; int /*<<< orphan*/  timeout; int /*<<< orphan*/  out_cork; } ;
typedef  TYPE_8__ ngx_rtmp_core_srv_conf_t ;
typedef  TYPE_9__ ngx_rtmp_addr_conf_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
struct TYPE_38__ {TYPE_7__* data; int /*<<< orphan*/ * action; } ;
typedef  TYPE_10__ ngx_log_t ;
typedef  int ngx_int_t ;
typedef  TYPE_11__ ngx_event_t ;
struct TYPE_40__ {int destroyed; TYPE_33__* log; int /*<<< orphan*/ * pool; int /*<<< orphan*/  log_error; int /*<<< orphan*/  number; int /*<<< orphan*/  addr_text; TYPE_4__* data; struct sockaddr* local_sockaddr; TYPE_1__* listening; } ;
typedef  TYPE_12__ ngx_connection_t ;
typedef  int /*<<< orphan*/  ngx_chain_t ;
struct TYPE_46__ {scalar_t__* srv_conf; int /*<<< orphan*/  main_conf; } ;
struct TYPE_44__ {int /*<<< orphan*/ * action; TYPE_7__* data; int /*<<< orphan*/ * (* handler ) (TYPE_10__*,int /*<<< orphan*/ *,size_t) ;int /*<<< orphan*/  connection; } ;
struct TYPE_42__ {size_t ctx_index; } ;
struct TYPE_41__ {TYPE_5__* servers; } ;

/* Variables and functions */
#define  AF_UNIX 128 
 int /*<<< orphan*/  NGX_ERROR_INFO ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_RTMP ; 
 int /*<<< orphan*/  NGX_LOG_INFO ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  NGX_RTMP_CONNECT ; 
 int /*<<< orphan*/  NGX_RTMP_DEFAULT_CHUNK_SIZE ; 
 int /*<<< orphan*/  NGX_RTMP_DISCONNECT ; 
 int /*<<< orphan*/  ngx_close_connection (TYPE_12__*) ; 
 scalar_t__ ngx_connection_local_sockaddr (TYPE_12__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_current_msec ; 
 int /*<<< orphan*/  ngx_del_timer (TYPE_35__*) ; 
 int /*<<< orphan*/  ngx_destroy_pool (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_log_debug0 (int /*<<< orphan*/ ,TYPE_33__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,TYPE_33__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_7__* ngx_palloc (int /*<<< orphan*/ *,int) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_post_event (TYPE_11__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_posted_events ; 
static  void ngx_rtmp_close_connection (TYPE_12__*) ; 
 TYPE_23__ ngx_rtmp_core_module ; 
 void ngx_rtmp_finalize_session (TYPE_4__*) ; 
 scalar_t__ ngx_rtmp_fire_event (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_rtmp_free_handshake_buffers (TYPE_4__*) ; 
 int /*<<< orphan*/  ngx_rtmp_free_shared_chain (TYPE_8__*,int /*<<< orphan*/ ) ; 
 TYPE_8__* ngx_rtmp_get_module_srv_conf (TYPE_4__*,TYPE_23__) ; 
 int /*<<< orphan*/  ngx_rtmp_handshake (TYPE_4__*) ; 
 TYPE_4__* ngx_rtmp_init_session (TYPE_12__*,TYPE_9__*) ; 
static  int /*<<< orphan*/ * ngx_rtmp_log_error (TYPE_10__*,int /*<<< orphan*/ *,size_t) ; 
 int ngx_rtmp_max_module ; 
 int /*<<< orphan*/  ngx_rtmp_naccepted ; 
 int /*<<< orphan*/  ngx_rtmp_proxy_protocol (TYPE_4__*) ; 
 int /*<<< orphan*/  ngx_rtmp_set_chunk_size (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ngx_snprintf (int /*<<< orphan*/ *,size_t,char*,int /*<<< orphan*/ *) ; 

void
ngx_rtmp_init_connection(ngx_connection_t *c)
{
    ngx_uint_t             i;
    ngx_rtmp_port_t       *port;
    struct sockaddr       *sa;
    struct sockaddr_in    *sin;
    ngx_rtmp_in_addr_t    *addr;
    ngx_rtmp_session_t    *s;
    ngx_rtmp_addr_conf_t  *addr_conf;
    ngx_int_t              unix_socket;
#if (NGX_HAVE_INET6)
    struct sockaddr_in6   *sin6;
    ngx_rtmp_in6_addr_t   *addr6;
#endif

    ++ngx_rtmp_naccepted;

    /* find the server configuration for the address:port */

    /* AF_INET only */

    port = c->listening->servers;
    unix_socket = 0;

    if (port->naddrs > 1) {

        /*
         * There are several addresses on this port and one of them
         * is the "*:port" wildcard so getsockname() is needed to determine
         * the server address.
         *
         * AcceptEx() already gave this address.
         */

        if (ngx_connection_local_sockaddr(c, NULL, 0) != NGX_OK) {
            ngx_rtmp_close_connection(c);
            return;
        }

        sa = c->local_sockaddr;

        switch (sa->sa_family) {

#if (NGX_HAVE_INET6)
        case AF_INET6:
            sin6 = (struct sockaddr_in6 *) sa;

            addr6 = port->addrs;

            /* the last address is "*" */

            for (i = 0; i < port->naddrs - 1; i++) {
                if (ngx_memcmp(&addr6[i].addr6, &sin6->sin6_addr, 16) == 0) {
                    break;
                }
            }

            addr_conf = &addr6[i].conf;

            break;
#endif

        case AF_UNIX:
            unix_socket = 1;
            /* fall through */

        default: /* AF_INET */
            sin = (struct sockaddr_in *) sa;

            addr = port->addrs;

            /* the last address is "*" */

            for (i = 0; i < port->naddrs - 1; i++) {
                if (addr[i].addr == sin->sin_addr.s_addr) {
                    break;
                }
            }

            addr_conf = &addr[i].conf;

            break;
        }

    } else {
        switch (c->local_sockaddr->sa_family) {

#if (NGX_HAVE_INET6)
        case AF_INET6:
            addr6 = port->addrs;
            addr_conf = &addr6[0].conf;
            break;
#endif

        case AF_UNIX:
            unix_socket = 1;
            /* fall through */

        default: /* AF_INET */
            addr = port->addrs;
            addr_conf = &addr[0].conf;
            break;
        }
    }

    ngx_log_error(NGX_LOG_INFO, c->log, 0, "*%ui client connected '%V'",
                  c->number, &c->addr_text);

    s = ngx_rtmp_init_session(c, addr_conf);
    if (s == NULL) {
        return;
    }

    /* only auto-pushed connections are
     * done through unix socket */

    s->auto_pushed = unix_socket;

    if (addr_conf->proxy_protocol) {
        ngx_rtmp_proxy_protocol(s);

    } else {
        ngx_rtmp_handshake(s);
    }
}

ngx_rtmp_session_t *
ngx_rtmp_init_session(ngx_connection_t *c, ngx_rtmp_addr_conf_t *addr_conf)
{
    ngx_rtmp_session_t             *s;
    ngx_rtmp_core_srv_conf_t       *cscf;
    ngx_rtmp_error_log_ctx_t       *ctx;

    s = ngx_pcalloc(c->pool, sizeof(ngx_rtmp_session_t) +
            sizeof(ngx_chain_t *) * ((ngx_rtmp_core_srv_conf_t *)
                addr_conf->ctx-> srv_conf[ngx_rtmp_core_module
                    .ctx_index])->out_queue);
    if (s == NULL) {
        ngx_rtmp_close_connection(c);
        return NULL;
    }

    s->main_conf = addr_conf->ctx->main_conf;
    s->srv_conf = addr_conf->ctx->srv_conf;

    s->addr_text = &addr_conf->addr_text;

    c->data = s;
    s->connection = c;

    ctx = ngx_palloc(c->pool, sizeof(ngx_rtmp_error_log_ctx_t));
    if (ctx == NULL) {
        ngx_rtmp_close_connection(c);
        return NULL;
    }

    ctx->client = &c->addr_text;
    ctx->session = s;

    c->log->connection = c->number;
    c->log->handler = ngx_rtmp_log_error;
    c->log->data = ctx;
    c->log->action = NULL;

    c->log_error = NGX_ERROR_INFO;

    s->ctx = ngx_pcalloc(c->pool, sizeof(void *) * ngx_rtmp_max_module);
    if (s->ctx == NULL) {
        ngx_rtmp_close_connection(c);
        return NULL;
    }

    cscf = ngx_rtmp_get_module_srv_conf(s, ngx_rtmp_core_module);

    s->out_queue = cscf->out_queue;
    s->out_cork = cscf->out_cork;
    s->in_streams = ngx_pcalloc(c->pool, sizeof(ngx_rtmp_stream_t)
            * cscf->max_streams);
    if (s->in_streams == NULL) {
        ngx_rtmp_close_connection(c);
        return NULL;
    }

#if (nginx_version >= 1007005)
    ngx_queue_init(&s->posted_dry_events);
#endif

    s->epoch = ngx_current_msec;
    s->timeout = cscf->timeout;
    s->buflen = cscf->buflen;
    ngx_rtmp_set_chunk_size(s, NGX_RTMP_DEFAULT_CHUNK_SIZE);


    if (ngx_rtmp_fire_event(s, NGX_RTMP_CONNECT, NULL, NULL) != NGX_OK) {
        ngx_rtmp_finalize_session(s);
        return NULL;
    }

    return s;
}

__attribute__((used)) static u_char *
ngx_rtmp_log_error(ngx_log_t *log, u_char *buf, size_t len)
{
    u_char                     *p;
    ngx_rtmp_session_t         *s;
    ngx_rtmp_error_log_ctx_t   *ctx;

    if (log->action) {
        p = ngx_snprintf(buf, len, " while %s", log->action);
        len -= p - buf;
        buf = p;
    }

    ctx = log->data;

    p = ngx_snprintf(buf, len, ", client: %V", ctx->client);
    len -= p - buf;
    buf = p;

    s = ctx->session;

    if (s == NULL) {
        return p;
    }

    p = ngx_snprintf(buf, len, ", server: %V", s->addr_text);
    len -= p - buf;
    buf = p;

    return p;
}

__attribute__((used)) static void
ngx_rtmp_close_connection(ngx_connection_t *c)
{
    ngx_pool_t                         *pool;

    ngx_log_debug0(NGX_LOG_DEBUG_RTMP, c->log, 0, "close connection");

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_active, -1);
#endif

    pool = c->pool;
    ngx_close_connection(c);
    ngx_destroy_pool(pool);
}

__attribute__((used)) static void
ngx_rtmp_close_session_handler(ngx_event_t *e)
{
    ngx_rtmp_session_t                 *s;
    ngx_connection_t                   *c;
    ngx_rtmp_core_srv_conf_t           *cscf;

    s = e->data;
    c = s->connection;

    cscf = ngx_rtmp_get_module_srv_conf(s, ngx_rtmp_core_module);

    ngx_log_debug0(NGX_LOG_DEBUG_RTMP, c->log, 0, "close session");

    ngx_rtmp_fire_event(s, NGX_RTMP_DISCONNECT, NULL, NULL);

    if (s->ping_evt.timer_set) {
        ngx_del_timer(&s->ping_evt);
    }

    if (s->in_old_pool) {
        ngx_destroy_pool(s->in_old_pool);
    }

    if (s->in_pool) {
        ngx_destroy_pool(s->in_pool);
    }

    ngx_rtmp_free_handshake_buffers(s);

    while (s->out_pos != s->out_last) {
        ngx_rtmp_free_shared_chain(cscf, s->out[s->out_pos++]);
        s->out_pos %= s->out_queue;
    }

    ngx_rtmp_close_connection(c);
}

void
ngx_rtmp_finalize_session(ngx_rtmp_session_t *s)
{
    ngx_event_t        *e;
    ngx_connection_t   *c;

    c = s->connection;
    if (c->destroyed) {
        return;
    }

    ngx_log_debug0(NGX_LOG_DEBUG_RTMP, c->log, 0, "finalize session");

    c->destroyed = 1;
    e = &s->close;
    e->data = s;
    e->handler = ngx_rtmp_close_session_handler;
    e->log = c->log;

    ngx_post_event(e, &ngx_posted_events);
}

