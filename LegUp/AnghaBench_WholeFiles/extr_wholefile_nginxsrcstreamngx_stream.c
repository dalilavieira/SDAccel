#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_79__   TYPE_9__ ;
typedef  struct TYPE_78__   TYPE_8__ ;
typedef  struct TYPE_77__   TYPE_7__ ;
typedef  struct TYPE_76__   TYPE_6__ ;
typedef  struct TYPE_75__   TYPE_5__ ;
typedef  struct TYPE_74__   TYPE_52__ ;
typedef  struct TYPE_73__   TYPE_4__ ;
typedef  struct TYPE_72__   TYPE_40__ ;
typedef  struct TYPE_71__   TYPE_3__ ;
typedef  struct TYPE_70__   TYPE_2__ ;
typedef  struct TYPE_69__   TYPE_24__ ;
typedef  struct TYPE_68__   TYPE_23__ ;
typedef  struct TYPE_67__   TYPE_22__ ;
typedef  struct TYPE_66__   TYPE_20__ ;
typedef  struct TYPE_65__   TYPE_1__ ;
typedef  struct TYPE_64__   TYPE_18__ ;
typedef  struct TYPE_63__   TYPE_17__ ;
typedef  struct TYPE_62__   TYPE_16__ ;
typedef  struct TYPE_61__   TYPE_15__ ;
typedef  struct TYPE_60__   TYPE_14__ ;
typedef  struct TYPE_59__   TYPE_13__ ;
typedef  struct TYPE_58__   TYPE_12__ ;
typedef  struct TYPE_57__   TYPE_11__ ;
typedef  struct TYPE_56__   TYPE_10__ ;

/* Type definitions */
struct TYPE_78__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {TYPE_8__ sin_addr; } ;
struct sockaddr {scalar_t__ sa_family; } ;
typedef  size_t ngx_uint_t ;
struct TYPE_57__ {size_t naddrs; TYPE_15__* addrs; } ;
typedef  TYPE_11__ ngx_stream_port_t ;
struct TYPE_60__ {scalar_t__ type; int bind; scalar_t__ wildcard; int /*<<< orphan*/  addr_text; int /*<<< orphan*/  proxy_protocol; TYPE_9__* ctx; struct sockaddr* sockaddr; int /*<<< orphan*/  so_keepalive; int /*<<< orphan*/  sndbuf; int /*<<< orphan*/  rcvbuf; int /*<<< orphan*/  backlog; int /*<<< orphan*/  socklen; } ;
struct TYPE_69__ {scalar_t__ nelts; TYPE_16__* elts; } ;
struct TYPE_62__ {scalar_t__ type; scalar_t__ family; TYPE_14__ opt; TYPE_24__ addrs; int /*<<< orphan*/  port; } ;
struct TYPE_58__ {size_t next; TYPE_16__ handler; int /*<<< orphan*/  checker; } ;
typedef  TYPE_12__ ngx_stream_phase_handler_t ;
typedef  int /*<<< orphan*/  ngx_stream_phase_handler_pt ;
struct TYPE_59__ {scalar_t__ (* preconfiguration ) (TYPE_23__*) ;char* (* init_main_conf ) (TYPE_23__*,TYPE_18__*) ;char* (* merge_srv_conf ) (TYPE_23__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;scalar_t__ (* postconfiguration ) (TYPE_23__*) ;int /*<<< orphan*/ * (* create_srv_conf ) (TYPE_23__*) ;TYPE_18__* (* create_main_conf ) (TYPE_23__*) ;} ;
typedef  TYPE_13__ ngx_stream_module_t ;
typedef  TYPE_14__ ngx_stream_listen_t ;
struct TYPE_56__ {int /*<<< orphan*/  addr_text; int /*<<< orphan*/  proxy_protocol; TYPE_9__* ctx; } ;
struct TYPE_61__ {TYPE_10__ conf; int /*<<< orphan*/  addr; } ;
typedef  TYPE_15__ ngx_stream_in_addr_t ;
typedef  TYPE_16__ ngx_stream_handler_pt ;
struct TYPE_63__ {int /*<<< orphan*/  error_log; TYPE_20__* ctx; } ;
typedef  TYPE_17__ ngx_stream_core_srv_conf_t ;
struct TYPE_73__ {TYPE_12__* handlers; } ;
struct TYPE_71__ {size_t nelts; TYPE_14__* elts; } ;
struct TYPE_65__ {size_t nelts; TYPE_17__** elts; } ;
struct TYPE_64__ {TYPE_5__* phases; TYPE_4__ phase_engine; TYPE_3__ listen; TYPE_1__ servers; } ;
typedef  TYPE_18__ ngx_stream_core_main_conf_t ;
typedef  TYPE_16__ ngx_stream_conf_port_t ;
struct TYPE_66__ {int /*<<< orphan*/ ** srv_conf; TYPE_18__** main_conf; } ;
typedef  TYPE_20__ ngx_stream_conf_ctx_t ;
typedef  TYPE_16__ ngx_stream_conf_addr_t ;
struct TYPE_76__ {int /*<<< orphan*/  handler; int /*<<< orphan*/ * data; } ;
struct TYPE_67__ {int addr_ntop; int pool_size; scalar_t__ type; TYPE_7__* sockaddr; TYPE_11__* servers; int /*<<< orphan*/  keepalive; scalar_t__ wildcard; int /*<<< orphan*/  sndbuf; int /*<<< orphan*/  rcvbuf; int /*<<< orphan*/  backlog; TYPE_6__ log; int /*<<< orphan*/  addr_text; int /*<<< orphan*/  logp; int /*<<< orphan*/  handler; } ;
typedef  TYPE_22__ ngx_listening_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_68__ {int /*<<< orphan*/  pool; int /*<<< orphan*/  temp_pool; TYPE_52__* cycle; TYPE_20__* ctx; int /*<<< orphan*/  cmd_type; scalar_t__ module_type; } ;
typedef  TYPE_23__ ngx_conf_t ;
typedef  int /*<<< orphan*/  ngx_command_t ;
typedef  TYPE_24__ ngx_array_t ;
typedef  int /*<<< orphan*/  in_port_t ;
struct TYPE_79__ {TYPE_17__** srv_conf; } ;
struct TYPE_77__ {int sa_family; } ;
struct TYPE_75__ {TYPE_24__ handlers; } ;
struct TYPE_74__ {TYPE_2__** modules; } ;
struct TYPE_72__ {size_t ctx_index; } ;
struct TYPE_70__ {scalar_t__ type; size_t ctx_index; TYPE_13__* ctx; } ;

/* Variables and functions */
 char* NGX_CONF_ERROR ; 
 char* NGX_CONF_OK ; 
 scalar_t__ NGX_ERROR ; 
 scalar_t__ NGX_OK ; 
 size_t NGX_STREAM_ACCESS_PHASE ; 
#define  NGX_STREAM_CONTENT_PHASE 129 
 size_t NGX_STREAM_LOG_PHASE ; 
 int /*<<< orphan*/  NGX_STREAM_MAIN_CONF ; 
 scalar_t__ NGX_STREAM_MODULE ; 
 size_t NGX_STREAM_POST_ACCEPT_PHASE ; 
 size_t NGX_STREAM_PREACCESS_PHASE ; 
#define  NGX_STREAM_PREREAD_PHASE 128 
 size_t NGX_STREAM_SSL_PHASE ; 
 int /*<<< orphan*/  ngx_accept_log_error ; 
 scalar_t__ ngx_array_init (TYPE_24__*,int /*<<< orphan*/ ,int,int) ; 
 void* ngx_array_push (TYPE_24__*) ; 
 char* ngx_conf_parse (TYPE_23__*,int /*<<< orphan*/ *) ; 
 int ngx_count_modules (TYPE_52__*,scalar_t__) ; 
 TYPE_22__* ngx_create_listening (TYPE_23__*,struct sockaddr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_inet_get_port (struct sockaddr*) ; 
 TYPE_11__* ngx_palloc (int /*<<< orphan*/ ,int) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_sort (TYPE_16__*,size_t,int,scalar_t__ (*) (void const*,void const*)) ; 
static  scalar_t__ ngx_stream_add_addrs (TYPE_23__*,TYPE_11__*,TYPE_16__*) ; 
static  scalar_t__ ngx_stream_add_ports (TYPE_23__*,TYPE_24__*,TYPE_14__*) ; 
static  scalar_t__ ngx_stream_cmp_conf_addrs (void const*,void const*) ; 
 int /*<<< orphan*/  ngx_stream_core_content_phase ; 
 int /*<<< orphan*/  ngx_stream_core_generic_phase ; 
 TYPE_40__ ngx_stream_core_module ; 
 int /*<<< orphan*/  ngx_stream_core_preread_phase ; 
 int /*<<< orphan*/  ngx_stream_init_connection ; 
static  scalar_t__ ngx_stream_init_phase_handlers (TYPE_23__*,TYPE_18__*) ; 
static  scalar_t__ ngx_stream_init_phases (TYPE_23__*,TYPE_18__*) ; 
 int ngx_stream_max_module ; 
static  char* ngx_stream_optimize_servers (TYPE_23__*,TYPE_24__*) ; 
 scalar_t__ ngx_stream_variables_init_vars (TYPE_23__*) ; 
 TYPE_18__* stub1 (TYPE_23__*) ; 
 int /*<<< orphan*/ * stub2 (TYPE_23__*) ; 
 scalar_t__ stub3 (TYPE_23__*) ; 
 char* stub4 (TYPE_23__*,TYPE_18__*) ; 
 char* stub5 (TYPE_23__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ stub6 (TYPE_23__*) ; 

__attribute__((used)) static char *
ngx_stream_block(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char                          *rv;
    ngx_uint_t                     i, m, mi, s;
    ngx_conf_t                     pcf;
    ngx_array_t                    ports;
    ngx_stream_listen_t           *listen;
    ngx_stream_module_t           *module;
    ngx_stream_conf_ctx_t         *ctx;
    ngx_stream_core_srv_conf_t   **cscfp;
    ngx_stream_core_main_conf_t   *cmcf;

    if (*(ngx_stream_conf_ctx_t **) conf) {
        return "is duplicate";
    }

    /* the main stream context */

    ctx = ngx_pcalloc(cf->pool, sizeof(ngx_stream_conf_ctx_t));
    if (ctx == NULL) {
        return NGX_CONF_ERROR;
    }

    *(ngx_stream_conf_ctx_t **) conf = ctx;

    /* count the number of the stream modules and set up their indices */

    ngx_stream_max_module = ngx_count_modules(cf->cycle, NGX_STREAM_MODULE);


    /* the stream main_conf context, it's the same in the all stream contexts */

    ctx->main_conf = ngx_pcalloc(cf->pool,
                                 sizeof(void *) * ngx_stream_max_module);
    if (ctx->main_conf == NULL) {
        return NGX_CONF_ERROR;
    }


    /*
     * the stream null srv_conf context, it is used to merge
     * the server{}s' srv_conf's
     */

    ctx->srv_conf = ngx_pcalloc(cf->pool,
                                sizeof(void *) * ngx_stream_max_module);
    if (ctx->srv_conf == NULL) {
        return NGX_CONF_ERROR;
    }


    /*
     * create the main_conf's and the null srv_conf's of the all stream modules
     */

    for (m = 0; cf->cycle->modules[m]; m++) {
        if (cf->cycle->modules[m]->type != NGX_STREAM_MODULE) {
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


    pcf = *cf;
    cf->ctx = ctx;

    for (m = 0; cf->cycle->modules[m]; m++) {
        if (cf->cycle->modules[m]->type != NGX_STREAM_MODULE) {
            continue;
        }

        module = cf->cycle->modules[m]->ctx;

        if (module->preconfiguration) {
            if (module->preconfiguration(cf) != NGX_OK) {
                return NGX_CONF_ERROR;
            }
        }
    }


    /* parse inside the stream{} block */

    cf->module_type = NGX_STREAM_MODULE;
    cf->cmd_type = NGX_STREAM_MAIN_CONF;
    rv = ngx_conf_parse(cf, NULL);

    if (rv != NGX_CONF_OK) {
        *cf = pcf;
        return rv;
    }


    /* init stream{} main_conf's, merge the server{}s' srv_conf's */

    cmcf = ctx->main_conf[ngx_stream_core_module.ctx_index];
    cscfp = cmcf->servers.elts;

    for (m = 0; cf->cycle->modules[m]; m++) {
        if (cf->cycle->modules[m]->type != NGX_STREAM_MODULE) {
            continue;
        }

        module = cf->cycle->modules[m]->ctx;
        mi = cf->cycle->modules[m]->ctx_index;

        /* init stream{} main_conf's */

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

    if (ngx_stream_init_phases(cf, cmcf) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    for (m = 0; cf->cycle->modules[m]; m++) {
        if (cf->cycle->modules[m]->type != NGX_STREAM_MODULE) {
            continue;
        }

        module = cf->cycle->modules[m]->ctx;

        if (module->postconfiguration) {
            if (module->postconfiguration(cf) != NGX_OK) {
                return NGX_CONF_ERROR;
            }
        }
    }

    if (ngx_stream_variables_init_vars(cf) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    *cf = pcf;

    if (ngx_stream_init_phase_handlers(cf, cmcf) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    if (ngx_array_init(&ports, cf->temp_pool, 4, sizeof(ngx_stream_conf_port_t))
        != NGX_OK)
    {
        return NGX_CONF_ERROR;
    }

    listen = cmcf->listen.elts;

    for (i = 0; i < cmcf->listen.nelts; i++) {
        if (ngx_stream_add_ports(cf, &ports, &listen[i]) != NGX_OK) {
            return NGX_CONF_ERROR;
        }
    }

    return ngx_stream_optimize_servers(cf, &ports);
}

__attribute__((used)) static ngx_int_t
ngx_stream_init_phases(ngx_conf_t *cf, ngx_stream_core_main_conf_t *cmcf)
{
    if (ngx_array_init(&cmcf->phases[NGX_STREAM_POST_ACCEPT_PHASE].handlers,
                       cf->pool, 1, sizeof(ngx_stream_handler_pt))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

    if (ngx_array_init(&cmcf->phases[NGX_STREAM_PREACCESS_PHASE].handlers,
                       cf->pool, 1, sizeof(ngx_stream_handler_pt))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

    if (ngx_array_init(&cmcf->phases[NGX_STREAM_ACCESS_PHASE].handlers,
                       cf->pool, 1, sizeof(ngx_stream_handler_pt))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

    if (ngx_array_init(&cmcf->phases[NGX_STREAM_SSL_PHASE].handlers,
                       cf->pool, 1, sizeof(ngx_stream_handler_pt))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

    if (ngx_array_init(&cmcf->phases[NGX_STREAM_PREREAD_PHASE].handlers,
                       cf->pool, 1, sizeof(ngx_stream_handler_pt))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

    if (ngx_array_init(&cmcf->phases[NGX_STREAM_LOG_PHASE].handlers,
                       cf->pool, 1, sizeof(ngx_stream_handler_pt))
        != NGX_OK)
    {
        return NGX_ERROR;
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_stream_init_phase_handlers(ngx_conf_t *cf,
    ngx_stream_core_main_conf_t *cmcf)
{
    ngx_int_t                     j;
    ngx_uint_t                    i, n;
    ngx_stream_handler_pt        *h;
    ngx_stream_phase_handler_t   *ph;
    ngx_stream_phase_handler_pt   checker;

    n = 1 /* content phase */;

    for (i = 0; i < NGX_STREAM_LOG_PHASE; i++) {
        n += cmcf->phases[i].handlers.nelts;
    }

    ph = ngx_pcalloc(cf->pool,
                     n * sizeof(ngx_stream_phase_handler_t) + sizeof(void *));
    if (ph == NULL) {
        return NGX_ERROR;
    }

    cmcf->phase_engine.handlers = ph;
    n = 0;

    for (i = 0; i < NGX_STREAM_LOG_PHASE; i++) {
        h = cmcf->phases[i].handlers.elts;

        switch (i) {

        case NGX_STREAM_PREREAD_PHASE:
            checker = ngx_stream_core_preread_phase;
            break;

        case NGX_STREAM_CONTENT_PHASE:
            ph->checker = ngx_stream_core_content_phase;
            n++;
            ph++;

            continue;

        default:
            checker = ngx_stream_core_generic_phase;
        }

        n += cmcf->phases[i].handlers.nelts;

        for (j = cmcf->phases[i].handlers.nelts - 1; j >= 0; j--) {
            ph->checker = checker;
            ph->handler = h[j];
            ph->next = n;
            ph++;
        }
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_stream_add_ports(ngx_conf_t *cf, ngx_array_t *ports,
    ngx_stream_listen_t *listen)
{
    in_port_t                p;
    ngx_uint_t               i;
    struct sockaddr         *sa;
    ngx_stream_conf_port_t  *port;
    ngx_stream_conf_addr_t  *addr;

    sa = listen->sockaddr;
    p = ngx_inet_get_port(sa);

    port = ports->elts;
    for (i = 0; i < ports->nelts; i++) {

        if (p == port[i].port
            && listen->type == port[i].type
            && sa->sa_family == port[i].family)
        {
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
    port->type = listen->type;
    port->port = p;

    if (ngx_array_init(&port->addrs, cf->temp_pool, 2,
                       sizeof(ngx_stream_conf_addr_t))
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
ngx_stream_optimize_servers(ngx_conf_t *cf, ngx_array_t *ports)
{
    ngx_uint_t                   i, p, last, bind_wildcard;
    ngx_listening_t             *ls;
    ngx_stream_port_t           *stport;
    ngx_stream_conf_port_t      *port;
    ngx_stream_conf_addr_t      *addr;
    ngx_stream_core_srv_conf_t  *cscf;

    port = ports->elts;
    for (p = 0; p < ports->nelts; p++) {

        ngx_sort(port[p].addrs.elts, (size_t) port[p].addrs.nelts,
                 sizeof(ngx_stream_conf_addr_t), ngx_stream_cmp_conf_addrs);

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
            ls->handler = ngx_stream_init_connection;
            ls->pool_size = 256;
            ls->type = addr[i].opt.type;

            cscf = addr->opt.ctx->srv_conf[ngx_stream_core_module.ctx_index];

            ls->logp = cscf->error_log;
            ls->log.data = &ls->addr_text;
            ls->log.handler = ngx_accept_log_error;

            ls->backlog = addr[i].opt.backlog;
            ls->rcvbuf = addr[i].opt.rcvbuf;
            ls->sndbuf = addr[i].opt.sndbuf;

            ls->wildcard = addr[i].opt.wildcard;

            ls->keepalive = addr[i].opt.so_keepalive;
#if (NGX_HAVE_KEEPALIVE_TUNABLE)
            ls->keepidle = addr[i].opt.tcp_keepidle;
            ls->keepintvl = addr[i].opt.tcp_keepintvl;
            ls->keepcnt = addr[i].opt.tcp_keepcnt;
#endif

#if (NGX_HAVE_INET6)
            ls->ipv6only = addr[i].opt.ipv6only;
#endif

#if (NGX_HAVE_REUSEPORT)
            ls->reuseport = addr[i].opt.reuseport;
#endif

            stport = ngx_palloc(cf->pool, sizeof(ngx_stream_port_t));
            if (stport == NULL) {
                return NGX_CONF_ERROR;
            }

            ls->servers = stport;

            stport->naddrs = i + 1;

            switch (ls->sockaddr->sa_family) {
#if (NGX_HAVE_INET6)
            case AF_INET6:
                if (ngx_stream_add_addrs6(cf, stport, addr) != NGX_OK) {
                    return NGX_CONF_ERROR;
                }
                break;
#endif
            default: /* AF_INET */
                if (ngx_stream_add_addrs(cf, stport, addr) != NGX_OK) {
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
ngx_stream_add_addrs(ngx_conf_t *cf, ngx_stream_port_t *stport,
    ngx_stream_conf_addr_t *addr)
{
    ngx_uint_t             i;
    struct sockaddr_in    *sin;
    ngx_stream_in_addr_t  *addrs;

    stport->addrs = ngx_pcalloc(cf->pool,
                                stport->naddrs * sizeof(ngx_stream_in_addr_t));
    if (stport->addrs == NULL) {
        return NGX_ERROR;
    }

    addrs = stport->addrs;

    for (i = 0; i < stport->naddrs; i++) {

        sin = (struct sockaddr_in *) addr[i].opt.sockaddr;
        addrs[i].addr = sin->sin_addr.s_addr;

        addrs[i].conf.ctx = addr[i].opt.ctx;
#if (NGX_STREAM_SSL)
        addrs[i].conf.ssl = addr[i].opt.ssl;
#endif
        addrs[i].conf.proxy_protocol = addr[i].opt.proxy_protocol;
        addrs[i].conf.addr_text = addr[i].opt.addr_text;
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_stream_cmp_conf_addrs(const void *one, const void *two)
{
    ngx_stream_conf_addr_t  *first, *second;

    first = (ngx_stream_conf_addr_t *) one;
    second = (ngx_stream_conf_addr_t *) two;

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

