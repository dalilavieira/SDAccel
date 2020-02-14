#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_65__   TYPE_9__ ;
typedef  struct TYPE_64__   TYPE_8__ ;
typedef  struct TYPE_63__   TYPE_7__ ;
typedef  struct TYPE_62__   TYPE_6__ ;
typedef  struct TYPE_61__   TYPE_5__ ;
typedef  struct TYPE_60__   TYPE_4__ ;
typedef  struct TYPE_59__   TYPE_41__ ;
typedef  struct TYPE_58__   TYPE_3__ ;
typedef  struct TYPE_57__   TYPE_31__ ;
typedef  struct TYPE_56__   TYPE_2__ ;
typedef  struct TYPE_55__   TYPE_20__ ;
typedef  struct TYPE_54__   TYPE_1__ ;
typedef  struct TYPE_53__   TYPE_19__ ;
typedef  struct TYPE_52__   TYPE_18__ ;
typedef  struct TYPE_51__   TYPE_16__ ;
typedef  struct TYPE_50__   TYPE_15__ ;
typedef  struct TYPE_49__   TYPE_14__ ;
typedef  struct TYPE_48__   TYPE_13__ ;
typedef  struct TYPE_47__   TYPE_12__ ;
typedef  struct TYPE_46__   TYPE_11__ ;
typedef  struct TYPE_45__   TYPE_10__ ;

/* Type definitions */
struct TYPE_62__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {TYPE_6__ sin_addr; } ;
struct sockaddr {scalar_t__ sa_family; } ;
typedef  size_t ngx_uint_t ;
struct TYPE_65__ {size_t naddrs; TYPE_12__* addrs; } ;
typedef  TYPE_9__ ngx_mail_port_t ;
struct TYPE_45__ {char* (* init_main_conf ) (TYPE_19__*,TYPE_14__*) ;char* (* merge_srv_conf ) (TYPE_19__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* create_srv_conf ) (TYPE_19__*) ;TYPE_14__* (* create_main_conf ) (TYPE_19__*) ;} ;
typedef  TYPE_10__ ngx_mail_module_t ;
struct TYPE_46__ {int bind; scalar_t__ wildcard; int /*<<< orphan*/  addr_text; TYPE_7__* ctx; struct sockaddr* sockaddr; int /*<<< orphan*/  so_keepalive; int /*<<< orphan*/  sndbuf; int /*<<< orphan*/  rcvbuf; int /*<<< orphan*/  backlog; int /*<<< orphan*/  socklen; } ;
typedef  TYPE_11__ ngx_mail_listen_t ;
struct TYPE_64__ {int /*<<< orphan*/  addr_text; TYPE_7__* ctx; } ;
struct TYPE_47__ {TYPE_8__ conf; int /*<<< orphan*/  addr; } ;
typedef  TYPE_12__ ngx_mail_in_addr_t ;
struct TYPE_48__ {int /*<<< orphan*/  error_log; TYPE_16__* ctx; } ;
typedef  TYPE_13__ ngx_mail_core_srv_conf_t ;
struct TYPE_58__ {size_t nelts; TYPE_11__* elts; } ;
struct TYPE_56__ {size_t nelts; TYPE_13__** elts; } ;
struct TYPE_49__ {TYPE_3__ listen; TYPE_2__ servers; } ;
typedef  TYPE_14__ ngx_mail_core_main_conf_t ;
struct TYPE_55__ {size_t nelts; TYPE_15__* elts; } ;
struct TYPE_50__ {scalar_t__ family; TYPE_11__ opt; TYPE_20__ addrs; int /*<<< orphan*/  port; } ;
typedef  TYPE_15__ ngx_mail_conf_port_t ;
struct TYPE_51__ {int /*<<< orphan*/ ** srv_conf; TYPE_14__** main_conf; } ;
typedef  TYPE_16__ ngx_mail_conf_ctx_t ;
typedef  TYPE_15__ ngx_mail_conf_addr_t ;
struct TYPE_60__ {int /*<<< orphan*/  handler; int /*<<< orphan*/ * data; } ;
struct TYPE_52__ {int addr_ntop; int pool_size; TYPE_5__* sockaddr; TYPE_9__* servers; int /*<<< orphan*/  keepalive; int /*<<< orphan*/  sndbuf; int /*<<< orphan*/  rcvbuf; int /*<<< orphan*/  backlog; TYPE_4__ log; int /*<<< orphan*/  addr_text; int /*<<< orphan*/  logp; int /*<<< orphan*/  handler; } ;
typedef  TYPE_18__ ngx_listening_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_53__ {int /*<<< orphan*/  pool; int /*<<< orphan*/  temp_pool; TYPE_16__* ctx; TYPE_41__* cycle; int /*<<< orphan*/  cmd_type; scalar_t__ module_type; } ;
typedef  TYPE_19__ ngx_conf_t ;
typedef  int /*<<< orphan*/  ngx_command_t ;
typedef  TYPE_20__ ngx_array_t ;
typedef  int /*<<< orphan*/  in_port_t ;
struct TYPE_63__ {TYPE_13__** srv_conf; } ;
struct TYPE_61__ {int sa_family; } ;
struct TYPE_59__ {TYPE_1__** modules; } ;
struct TYPE_57__ {size_t ctx_index; } ;
struct TYPE_54__ {scalar_t__ type; size_t ctx_index; TYPE_10__* ctx; } ;

/* Variables and functions */
 char* NGX_CONF_ERROR ; 
 char* NGX_CONF_OK ; 
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_MAIL_MAIN_CONF ; 
 scalar_t__ NGX_MAIL_MODULE ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  ngx_accept_log_error ; 
 scalar_t__ ngx_array_init (TYPE_20__*,int /*<<< orphan*/ ,int,int) ; 
 void* ngx_array_push (TYPE_20__*) ; 
 char* ngx_conf_parse (TYPE_19__*,int /*<<< orphan*/ *) ; 
 int ngx_count_modules (TYPE_41__*,scalar_t__) ; 
 TYPE_18__* ngx_create_listening (TYPE_19__*,struct sockaddr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_inet_get_port (struct sockaddr*) ; 
static  scalar_t__ ngx_mail_add_addrs (TYPE_19__*,TYPE_9__*,TYPE_15__*) ; 
static  scalar_t__ ngx_mail_add_ports (TYPE_19__*,TYPE_20__*,TYPE_11__*) ; 
static  scalar_t__ ngx_mail_cmp_conf_addrs (void const*,void const*) ; 
 TYPE_31__ ngx_mail_core_module ; 
 int /*<<< orphan*/  ngx_mail_init_connection ; 
 int ngx_mail_max_module ; 
static  char* ngx_mail_optimize_servers (TYPE_19__*,TYPE_20__*) ; 
 TYPE_9__* ngx_palloc (int /*<<< orphan*/ ,int) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_sort (TYPE_15__*,size_t,int,scalar_t__ (*) (void const*,void const*)) ; 
 TYPE_14__* stub1 (TYPE_19__*) ; 
 int /*<<< orphan*/ * stub2 (TYPE_19__*) ; 
 char* stub3 (TYPE_19__*,TYPE_14__*) ; 
 char* stub4 (TYPE_19__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static char *
ngx_mail_block(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char                        *rv;
    ngx_uint_t                   i, m, mi, s;
    ngx_conf_t                   pcf;
    ngx_array_t                  ports;
    ngx_mail_listen_t           *listen;
    ngx_mail_module_t           *module;
    ngx_mail_conf_ctx_t         *ctx;
    ngx_mail_core_srv_conf_t   **cscfp;
    ngx_mail_core_main_conf_t   *cmcf;

    if (*(ngx_mail_conf_ctx_t **) conf) {
        return "is duplicate";
    }

    /* the main mail context */

    ctx = ngx_pcalloc(cf->pool, sizeof(ngx_mail_conf_ctx_t));
    if (ctx == NULL) {
        return NGX_CONF_ERROR;
    }

    *(ngx_mail_conf_ctx_t **) conf = ctx;

    /* count the number of the mail modules and set up their indices */

    ngx_mail_max_module = ngx_count_modules(cf->cycle, NGX_MAIL_MODULE);


    /* the mail main_conf context, it is the same in the all mail contexts */

    ctx->main_conf = ngx_pcalloc(cf->pool,
                                 sizeof(void *) * ngx_mail_max_module);
    if (ctx->main_conf == NULL) {
        return NGX_CONF_ERROR;
    }


    /*
     * the mail null srv_conf context, it is used to merge
     * the server{}s' srv_conf's
     */

    ctx->srv_conf = ngx_pcalloc(cf->pool, sizeof(void *) * ngx_mail_max_module);
    if (ctx->srv_conf == NULL) {
        return NGX_CONF_ERROR;
    }


    /*
     * create the main_conf's and the null srv_conf's of the all mail modules
     */

    for (m = 0; cf->cycle->modules[m]; m++) {
        if (cf->cycle->modules[m]->type != NGX_MAIL_MODULE) {
            continue;
        }

        module = cf->cycle->modules[m]->ctx;
        mi = cf->cycle->modules[m]->ctx_index;

        if (module->create_main_conf) {
            ctx->main_conf[mi] = module->create_main_conf(cf);
            if (ctx->main_conf[mi] == NULL) {
                return NGX_CONF_ERROR;
            }
        }

        if (module->create_srv_conf) {
            ctx->srv_conf[mi] = module->create_srv_conf(cf);
            if (ctx->srv_conf[mi] == NULL) {
                return NGX_CONF_ERROR;
            }
        }
    }


    /* parse inside the mail{} block */

    pcf = *cf;
    cf->ctx = ctx;

    cf->module_type = NGX_MAIL_MODULE;
    cf->cmd_type = NGX_MAIL_MAIN_CONF;
    rv = ngx_conf_parse(cf, NULL);

    if (rv != NGX_CONF_OK) {
        *cf = pcf;
        return rv;
    }


    /* init mail{} main_conf's, merge the server{}s' srv_conf's */

    cmcf = ctx->main_conf[ngx_mail_core_module.ctx_index];
    cscfp = cmcf->servers.elts;

    for (m = 0; cf->cycle->modules[m]; m++) {
        if (cf->cycle->modules[m]->type != NGX_MAIL_MODULE) {
            continue;
        }

        module = cf->cycle->modules[m]->ctx;
        mi = cf->cycle->modules[m]->ctx_index;

        /* init mail{} main_conf's */

        cf->ctx = ctx;

        if (module->init_main_conf) {
            rv = module->init_main_conf(cf, ctx->main_conf[mi]);
            if (rv != NGX_CONF_OK) {
                *cf = pcf;
                return rv;
            }
        }

        for (s = 0; s < cmcf->servers.nelts; s++) {

            /* merge the server{}s' srv_conf's */

            cf->ctx = cscfp[s]->ctx;

            if (module->merge_srv_conf) {
                rv = module->merge_srv_conf(cf,
                                            ctx->srv_conf[mi],
                                            cscfp[s]->ctx->srv_conf[mi]);
                if (rv != NGX_CONF_OK) {
                    *cf = pcf;
                    return rv;
                }
            }
        }
    }

    *cf = pcf;


    if (ngx_array_init(&ports, cf->temp_pool, 4, sizeof(ngx_mail_conf_port_t))
        != NGX_OK)
    {
        return NGX_CONF_ERROR;
    }

    listen = cmcf->listen.elts;

    for (i = 0; i < cmcf->listen.nelts; i++) {
        if (ngx_mail_add_ports(cf, &ports, &listen[i]) != NGX_OK) {
            return NGX_CONF_ERROR;
        }
    }

    return ngx_mail_optimize_servers(cf, &ports);
}

__attribute__((used)) static ngx_int_t
ngx_mail_add_ports(ngx_conf_t *cf, ngx_array_t *ports,
    ngx_mail_listen_t *listen)
{
    in_port_t              p;
    ngx_uint_t             i;
    struct sockaddr       *sa;
    ngx_mail_conf_port_t  *port;
    ngx_mail_conf_addr_t  *addr;

    sa = listen->sockaddr;
    p = ngx_inet_get_port(sa);

    port = ports->elts;
    for (i = 0; i < ports->nelts; i++) {
        if (p == port[i].port && sa->sa_family == port[i].family) {

            /* a port is already in the port list */

            port = &port[i];
            goto found;
        }
    }

    /* add a port to the port list */

    port = ngx_array_push(ports);
    if (port == NULL) {
        return NGX_ERROR;
    }

    port->family = sa->sa_family;
    port->port = p;

    if (ngx_array_init(&port->addrs, cf->temp_pool, 2,
                       sizeof(ngx_mail_conf_addr_t))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

found:

    addr = ngx_array_push(&port->addrs);
    if (addr == NULL) {
        return NGX_ERROR;
    }

    addr->opt = *listen;

    return NGX_OK;
}

__attribute__((used)) static char *
ngx_mail_optimize_servers(ngx_conf_t *cf, ngx_array_t *ports)
{
    ngx_uint_t                 i, p, last, bind_wildcard;
    ngx_listening_t           *ls;
    ngx_mail_port_t           *mport;
    ngx_mail_conf_port_t      *port;
    ngx_mail_conf_addr_t      *addr;
    ngx_mail_core_srv_conf_t  *cscf;

    port = ports->elts;
    for (p = 0; p < ports->nelts; p++) {

        ngx_sort(port[p].addrs.elts, (size_t) port[p].addrs.nelts,
                 sizeof(ngx_mail_conf_addr_t), ngx_mail_cmp_conf_addrs);

        addr = port[p].addrs.elts;
        last = port[p].addrs.nelts;

        /*
         * if there is the binding to the "*:port" then we need to bind()
         * to the "*:port" only and ignore the other bindings
         */

        if (addr[last - 1].opt.wildcard) {
            addr[last - 1].opt.bind = 1;
            bind_wildcard = 1;

        } else {
            bind_wildcard = 0;
        }

        i = 0;

        while (i < last) {

            if (bind_wildcard && !addr[i].opt.bind) {
                i++;
                continue;
            }

            ls = ngx_create_listening(cf, addr[i].opt.sockaddr,
                                      addr[i].opt.socklen);
            if (ls == NULL) {
                return NGX_CONF_ERROR;
            }

            ls->addr_ntop = 1;
            ls->handler = ngx_mail_init_connection;
            ls->pool_size = 256;

            cscf = addr->opt.ctx->srv_conf[ngx_mail_core_module.ctx_index];

            ls->logp = cscf->error_log;
            ls->log.data = &ls->addr_text;
            ls->log.handler = ngx_accept_log_error;

            ls->backlog = addr[i].opt.backlog;
            ls->rcvbuf = addr[i].opt.rcvbuf;
            ls->sndbuf = addr[i].opt.sndbuf;

            ls->keepalive = addr[i].opt.so_keepalive;
#if (NGX_HAVE_KEEPALIVE_TUNABLE)
            ls->keepidle = addr[i].opt.tcp_keepidle;
            ls->keepintvl = addr[i].opt.tcp_keepintvl;
            ls->keepcnt = addr[i].opt.tcp_keepcnt;
#endif

#if (NGX_HAVE_INET6)
            ls->ipv6only = addr[i].opt.ipv6only;
#endif

            mport = ngx_palloc(cf->pool, sizeof(ngx_mail_port_t));
            if (mport == NULL) {
                return NGX_CONF_ERROR;
            }

            ls->servers = mport;

            mport->naddrs = i + 1;

            switch (ls->sockaddr->sa_family) {
#if (NGX_HAVE_INET6)
            case AF_INET6:
                if (ngx_mail_add_addrs6(cf, mport, addr) != NGX_OK) {
                    return NGX_CONF_ERROR;
                }
                break;
#endif
            default: /* AF_INET */
                if (ngx_mail_add_addrs(cf, mport, addr) != NGX_OK) {
                    return NGX_CONF_ERROR;
                }
                break;
            }

            addr++;
            last--;
        }
    }

    return NGX_CONF_OK;
}

__attribute__((used)) static ngx_int_t
ngx_mail_add_addrs(ngx_conf_t *cf, ngx_mail_port_t *mport,
    ngx_mail_conf_addr_t *addr)
{
    ngx_uint_t           i;
    ngx_mail_in_addr_t  *addrs;
    struct sockaddr_in  *sin;

    mport->addrs = ngx_pcalloc(cf->pool,
                               mport->naddrs * sizeof(ngx_mail_in_addr_t));
    if (mport->addrs == NULL) {
        return NGX_ERROR;
    }

    addrs = mport->addrs;

    for (i = 0; i < mport->naddrs; i++) {

        sin = (struct sockaddr_in *) addr[i].opt.sockaddr;
        addrs[i].addr = sin->sin_addr.s_addr;

        addrs[i].conf.ctx = addr[i].opt.ctx;
#if (NGX_MAIL_SSL)
        addrs[i].conf.ssl = addr[i].opt.ssl;
#endif
        addrs[i].conf.addr_text = addr[i].opt.addr_text;
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_mail_cmp_conf_addrs(const void *one, const void *two)
{
    ngx_mail_conf_addr_t  *first, *second;

    first = (ngx_mail_conf_addr_t *) one;
    second = (ngx_mail_conf_addr_t *) two;

    if (first->opt.wildcard) {
        /* a wildcard must be the last resort, shift it to the end */
        return 1;
    }

    if (second->opt.wildcard) {
        /* a wildcard must be the last resort, shift it to the end */
        return -1;
    }

    if (first->opt.bind && !second->opt.bind) {
        /* shift explicit bind()ed addresses to the start */
        return -1;
    }

    if (!first->opt.bind && second->opt.bind) {
        /* shift explicit bind()ed addresses to the start */
        return 1;
    }

    /* do not sort by default */

    return 0;
}

