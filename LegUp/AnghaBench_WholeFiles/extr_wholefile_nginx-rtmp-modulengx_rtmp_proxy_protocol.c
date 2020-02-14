#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  char u_char ;
typedef  int ssize_t ;
struct TYPE_19__ {TYPE_4__* connection; int /*<<< orphan*/  timeout; } ;
typedef  TYPE_2__ ngx_rtmp_session_t ;
typedef  int ngx_int_t ;
struct TYPE_20__ {void (* handler ) (TYPE_3__*) ;scalar_t__ timer_set; scalar_t__ timedout; TYPE_4__* data; scalar_t__ ready; } ;
typedef  TYPE_3__ ngx_event_t ;
typedef  scalar_t__ ngx_err_t ;
struct TYPE_18__ {char* data; size_t len; } ;
struct TYPE_21__ {int timedout; int (* recv ) (TYPE_4__*,char*,int) ;int /*<<< orphan*/  log; TYPE_1__ addr_text; scalar_t__ socklen; int /*<<< orphan*/  sockaddr; int /*<<< orphan*/  pool; TYPE_3__* read; int /*<<< orphan*/  fd; scalar_t__ destroyed; TYPE_2__* data; } ;
typedef  TYPE_4__ ngx_connection_t ;
struct TYPE_22__ {scalar_t__ socklen; int /*<<< orphan*/  sockaddr; } ;
typedef  TYPE_5__ ngx_addr_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 char CR ; 
 char LF ; 
 int /*<<< orphan*/  MSG_PEEK ; 
 scalar_t__ NGX_EAGAIN ; 
 int /*<<< orphan*/  NGX_ETIMEDOUT ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_RTMP ; 
 int /*<<< orphan*/  NGX_LOG_INFO ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  NGX_SOCKADDR_STRLEN ; 
 int /*<<< orphan*/  ngx_add_timer (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_del_timer (TYPE_3__*) ; 
 scalar_t__ ngx_handle_read_event (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_log_debug0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_log_debug1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_memzero (TYPE_5__*,int) ; 
 char* ngx_palloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ngx_parse_addr (int /*<<< orphan*/ ,TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  ngx_post_event (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_posted_events ; 
 int /*<<< orphan*/  ngx_rtmp_finalize_session (TYPE_2__*) ; 
 int /*<<< orphan*/  ngx_rtmp_handshake (TYPE_2__*) ; 
static  void ngx_rtmp_proxy_protocol_recv (TYPE_3__*) ; 
 size_t ngx_sock_ntop (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ngx_socket_errno ; 
 char* ngx_strlchr (char*,char*,char) ; 
 scalar_t__ ngx_strncmp (char*,char*,int) ; 
 scalar_t__ ngx_use_accept_mutex ; 
 int recv (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 void stub1 (TYPE_3__*) ; 
 int stub2 (TYPE_4__*,char*,int) ; 

void
ngx_rtmp_proxy_protocol(ngx_rtmp_session_t *s)
{
    ngx_event_t       *rev;
    ngx_connection_t  *c;

    c = s->connection;
    rev = c->read;
    rev->handler =  ngx_rtmp_proxy_protocol_recv;

    ngx_log_debug0(NGX_LOG_DEBUG_RTMP, s->connection->log, 0,
                   "proxy_protocol: start");

    if (rev->ready) {
        /* the deferred accept(), rtsig, aio, iocp */

        if (ngx_use_accept_mutex) {
            ngx_post_event(rev, &ngx_posted_events);
            return;
        }

        rev->handler(rev);
        return;
    }

    ngx_add_timer(rev, s->timeout);

    if (ngx_handle_read_event(rev, 0) != NGX_OK) {
        ngx_rtmp_finalize_session(s);
        return;
    }
}

__attribute__((used)) static void
ngx_rtmp_proxy_protocol_recv(ngx_event_t *rev)
{
    u_char               buf[107], *p, *pp, *text;
    size_t               len;
    ssize_t              n;
    ngx_err_t            err;
    ngx_int_t            i;
    ngx_addr_t           addr;
    ngx_connection_t    *c;
    ngx_rtmp_session_t  *s;

    c = rev->data;
    s = c->data;

    if (c->destroyed) {
        return;
    }

    if (rev->timedout) {
        ngx_log_error(NGX_LOG_INFO, c->log, NGX_ETIMEDOUT,
                "proxy_protocol: recv: client timed out");
        c->timedout = 1;
        ngx_rtmp_finalize_session(s);
        return;
    }

    if (rev->timer_set) {
        ngx_del_timer(rev);
    }

    n = recv(c->fd, (char *) buf, sizeof(buf), MSG_PEEK);

    err = ngx_socket_errno;

    ngx_log_debug1(NGX_LOG_DEBUG_RTMP, c->log, 0, "recv(): %d", n);

    if (n == -1) {

        if (err == NGX_EAGAIN) {
            ngx_add_timer(rev, s->timeout);

            if (ngx_handle_read_event(c->read, 0) != NGX_OK) {
                ngx_rtmp_finalize_session(s);
            }

            return;
        }

        ngx_rtmp_finalize_session(s);

        return;
    }

    p = buf;

    if (n <= 8 && ngx_strncmp(p, "PROXY ", 6) != 0) {
        goto bad_header;
    }

    n -= 6;
    p += 6;

    ngx_memzero(&addr, sizeof(ngx_addr_t));

    if (n >= 7 && ngx_strncmp(p, "UNKNOWN", 7) == 0) {
        n -= 7;
        p += 7;
        goto skip;
    }

    if (n < 5 || ngx_strncmp(p, "TCP", 3) != 0
        || (p[3] != '4' && p[3] != '6') || p[4] != ' ')
    {
        goto bad_header;
    }

    n -= 5;
    p += 5;

    pp = ngx_strlchr(p, p + n, ' ');

    if (pp == NULL) {
        goto bad_header;
    }

    if (ngx_parse_addr(s->connection->pool, &addr, p, pp - p) != NGX_OK) {
        goto bad_header;
    }

    n -= pp - p;
    p = pp;

skip:

    for (i = 0; i + 1 < n; i++) {
        if (p[i] == CR && p[i + 1] == LF) {
            break;
        }
    }

    if (i + 1 >= n) {
        goto bad_header;
    }

    n = p - buf + i + 2;

    if (c->recv(c, buf, n) != n) {
        goto failed;
    }

    if (addr.socklen) {
        text = ngx_palloc(s->connection->pool, NGX_SOCKADDR_STRLEN);

        if (text == NULL) {
            goto failed;
        }

        len = ngx_sock_ntop(addr.sockaddr,
#if (nginx_version >= 1005003)
                            addr.socklen,
#endif
                            text, NGX_SOCKADDR_STRLEN, 0);
        if (len == 0) {
            goto failed;
        }

        c->sockaddr = addr.sockaddr;
        c->socklen = addr.socklen;
        c->addr_text.data = text;
        c->addr_text.len = len;

        ngx_log_debug1(NGX_LOG_DEBUG_RTMP, c->log, 0,
                       "proxy_protocol: remote_addr:'%V'", &c->addr_text);
    }

    ngx_rtmp_handshake(s);

    return;

bad_header:

    ngx_log_error(NGX_LOG_INFO, c->log, 0, "proxy_protocol: bad header");

failed:

    ngx_rtmp_finalize_session(s);
}

