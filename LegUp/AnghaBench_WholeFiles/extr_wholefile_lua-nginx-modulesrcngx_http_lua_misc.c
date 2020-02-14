#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_8__ ;
typedef  struct TYPE_25__   TYPE_7__ ;
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;
typedef  struct TYPE_18__   TYPE_17__ ;

/* Type definitions */
typedef  char u_char ;
typedef  size_t ngx_uint_t ;
struct TYPE_22__ {char* data; size_t len; } ;
typedef  TYPE_4__ ngx_str_t ;
typedef  scalar_t__ ngx_socket_t ;
struct TYPE_26__ {scalar_t__ len; } ;
struct TYPE_21__ {int status; TYPE_8__ status_line; } ;
struct TYPE_23__ {int internal; int err_status; scalar_t__ http_version; scalar_t__ header_sent; TYPE_2__* connection; struct TYPE_23__* main; TYPE_3__ headers_out; } ;
typedef  TYPE_5__ ngx_http_request_t ;
struct TYPE_24__ {scalar_t__ header_sent; } ;
typedef  TYPE_6__ ngx_http_lua_ctx_t ;
struct TYPE_19__ {size_t nelts; TYPE_4__* elts; } ;
struct TYPE_25__ {TYPE_1__ env; } ;
typedef  TYPE_7__ ngx_core_conf_t ;
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_20__ {scalar_t__ fd; int /*<<< orphan*/  log; } ;
struct TYPE_18__ {int /*<<< orphan*/  conf_ctx; } ;

/* Variables and functions */
 int NGX_DECLINED ; 
 int NGX_HTTP_LUA_FFI_BAD_CONTEXT ; 
 int NGX_HTTP_LUA_FFI_NO_REQ_CTX ; 
 scalar_t__ NGX_HTTP_VERSION_9 ; 
 int /*<<< orphan*/  NGX_LOG_ERR ; 
 int NGX_OK ; 
 int /*<<< orphan*/  dd (char*,...) ; 
 scalar_t__ luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 scalar_t__ luaL_checknumber (int /*<<< orphan*/ *,int) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_createtable (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushcfunction (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushnil (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_rawset (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_setmetatable (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_core_module ; 
 TYPE_17__* ngx_cycle ; 
 scalar_t__ ngx_get_conf (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_6__* ngx_http_get_module_ctx (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_lua_check_fake_request (int /*<<< orphan*/ *,TYPE_5__*) ; 
 TYPE_5__* ngx_http_lua_get_req (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_http_lua_module ; 
static  int ngx_http_lua_ngx_get (int /*<<< orphan*/ *) ; 
 int ngx_http_lua_ngx_get_ctx (int /*<<< orphan*/ *) ; 
static  int ngx_http_lua_ngx_req_is_internal (int /*<<< orphan*/ *) ; 
static  int ngx_http_lua_ngx_set (int /*<<< orphan*/ *) ; 
 int ngx_http_lua_ngx_set_ctx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_str_set (TYPE_8__*,char*) ; 
 scalar_t__ ngx_strncmp (char*,char*,int) ; 

void
ngx_http_lua_inject_misc_api(lua_State *L)
{
    /* ngx. getter and setter */
    lua_createtable(L, 0, 2); /* metatable for .ngx */
    lua_pushcfunction(L, ngx_http_lua_ngx_get);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, ngx_http_lua_ngx_set);
    lua_setfield(L, -2, "__newindex");
    lua_setmetatable(L, -2);
}

void
ngx_http_lua_inject_req_misc_api(lua_State *L)
{
    lua_pushcfunction(L, ngx_http_lua_ngx_req_is_internal);
    lua_setfield(L, -2, "is_internal");
}

__attribute__((used)) static int
ngx_http_lua_ngx_req_is_internal(lua_State *L)
{
    ngx_http_request_t  *r;

    r = ngx_http_lua_get_req(L);
    if (r == NULL) {
        return luaL_error(L, "no request object found");
    }

    lua_pushboolean(L, r->internal == 1);
    return 1;
}

__attribute__((used)) static int
ngx_http_lua_ngx_get(lua_State *L)
{
    int                          status;
    ngx_http_request_t          *r;
    u_char                      *p;
    size_t                       len;
    ngx_http_lua_ctx_t          *ctx;

    r = ngx_http_lua_get_req(L);
    if (r == NULL) {
        lua_pushnil(L);
        return 1;
    }

    ctx = ngx_http_get_module_ctx(r, ngx_http_lua_module);
    if (ctx == NULL) {
        lua_pushnil(L);
        return 1;
    }

    p = (u_char *) luaL_checklstring(L, -1, &len);

    dd("ngx get %s", p);

    if (len == sizeof("status") - 1
        && ngx_strncmp(p, "status", sizeof("status") - 1) == 0)
    {
        ngx_http_lua_check_fake_request(L, r);

        if (r->err_status) {
            status = r->err_status;

        } else if (r->headers_out.status) {
            status = r->headers_out.status;

        } else if (r->http_version == NGX_HTTP_VERSION_9) {
            status = 9;

        } else {
            status = 0;
        }

        lua_pushinteger(L, status);
        return 1;
    }

    if (len == sizeof("ctx") - 1
        && ngx_strncmp(p, "ctx", sizeof("ctx") - 1) == 0)
    {
        return ngx_http_lua_ngx_get_ctx(L);
    }

    if (len == sizeof("is_subrequest") - 1
        && ngx_strncmp(p, "is_subrequest", sizeof("is_subrequest") - 1) == 0)
    {
        lua_pushboolean(L, r != r->main);
        return 1;
    }

    if (len == sizeof("headers_sent") - 1
        && ngx_strncmp(p, "headers_sent", sizeof("headers_sent") - 1) == 0)
    {
        ngx_http_lua_check_fake_request(L, r);

        dd("headers sent: %d", r->header_sent || ctx->header_sent);

        lua_pushboolean(L, r->header_sent || ctx->header_sent);
        return 1;
    }

    dd("key %s not matched", p);

    lua_pushnil(L);
    return 1;
}

__attribute__((used)) static int
ngx_http_lua_ngx_set(lua_State *L)
{
    ngx_http_request_t          *r;
    u_char                      *p;
    size_t                       len;

    /* we skip the first argument that is the table */
    p = (u_char *) luaL_checklstring(L, 2, &len);

    if (len == sizeof("status") - 1
        && ngx_strncmp(p, "status", sizeof("status") - 1) == 0)
    {
        r = ngx_http_lua_get_req(L);
        if (r == NULL) {
            return luaL_error(L, "no request object found");
        }

        if (r->header_sent) {
            ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
                          "attempt to set ngx.status after sending out "
                          "response headers");
            return 0;
        }

        if (r->err_status) {
            r->err_status = 0;
        }

        ngx_http_lua_check_fake_request(L, r);

        /* get the value */
        r->headers_out.status = (ngx_uint_t) luaL_checknumber(L, 3);

        if (r->headers_out.status == 101) {
            /*
             * XXX work-around a bug in the Nginx core that 101 does
             * not have a default status line
             */

            ngx_str_set(&r->headers_out.status_line, "101 Switching Protocols");

        } else {
            r->headers_out.status_line.len = 0;
        }

        return 0;
    }

    if (len == sizeof("ctx") - 1
        && ngx_strncmp(p, "ctx", sizeof("ctx") - 1) == 0)
    {
        r = ngx_http_lua_get_req(L);
        if (r == NULL) {
            return luaL_error(L, "no request object found");
        }

        return ngx_http_lua_ngx_set_ctx(L);
    }

    lua_rawset(L, -3);
    return 0;
}

int
ngx_http_lua_ffi_get_resp_status(ngx_http_request_t *r)
{
    if (r->connection->fd == (ngx_socket_t) -1) {
        return NGX_HTTP_LUA_FFI_BAD_CONTEXT;
    }

    if (r->err_status) {
        return r->err_status;

    } else if (r->headers_out.status) {
        return r->headers_out.status;

    } else if (r->http_version == NGX_HTTP_VERSION_9) {
        return 9;

    } else {
        return 0;
    }
}

int
ngx_http_lua_ffi_set_resp_status(ngx_http_request_t *r, int status)
{
    if (r->connection->fd == (ngx_socket_t) -1) {
        return NGX_HTTP_LUA_FFI_BAD_CONTEXT;
    }

    if (r->header_sent) {
        ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
                      "attempt to set ngx.status after sending out "
                      "response headers");
        return NGX_DECLINED;
    }

    r->headers_out.status = status;

    if (r->err_status) {
        r->err_status = 0;
    }

    if (status == 101) {
        /*
         * XXX work-around a bug in the Nginx core older than 1.5.5
         * that 101 does not have a default status line
         */

        ngx_str_set(&r->headers_out.status_line, "101 Switching Protocols");

    } else {
        r->headers_out.status_line.len = 0;
    }

    return NGX_OK;
}

int
ngx_http_lua_ffi_is_subrequest(ngx_http_request_t *r)
{
    if (r->connection->fd == (ngx_socket_t) -1) {
        return NGX_HTTP_LUA_FFI_BAD_CONTEXT;
    }

    return r != r->main;
}

int
ngx_http_lua_ffi_headers_sent(ngx_http_request_t *r)
{
    ngx_http_lua_ctx_t          *ctx;

    ctx = ngx_http_get_module_ctx(r, ngx_http_lua_module);
    if (ctx == NULL) {
        return NGX_HTTP_LUA_FFI_NO_REQ_CTX;
    }

    if (r->connection->fd == (ngx_socket_t) -1) {
        return NGX_HTTP_LUA_FFI_BAD_CONTEXT;
    }

    return r->header_sent ? 1 : 0;
}

int
ngx_http_lua_ffi_get_conf_env(u_char *name, u_char **env_buf, size_t *name_len)
{
    ngx_uint_t            i;
    ngx_str_t            *var;
    ngx_core_conf_t      *ccf;

    ccf = (ngx_core_conf_t *) ngx_get_conf(ngx_cycle->conf_ctx,
                                           ngx_core_module);

    var = ccf->env.elts;

    for (i = 0; i < ccf->env.nelts; i++) {
        if (var[i].data[var[i].len] == '='
            && ngx_strncmp(name, var[i].data, var[i].len) == 0)
        {
            *env_buf = var[i].data;
            *name_len = var[i].len;

            return NGX_OK;
        }
    }

    return NGX_DECLINED;
}

