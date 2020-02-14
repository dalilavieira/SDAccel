#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_3__ {int /*<<< orphan*/  len; scalar_t__ data; } ;
struct TYPE_4__ {TYPE_1__ prefix; } ;

/* Variables and functions */
 char* NGX_CONFIGURE ; 
 int /*<<< orphan*/  lua_createtable (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pushcfunction (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pushliteral (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  nginx_version ; 
 TYPE_2__* ngx_cycle ; 
static  int ngx_http_lua_config_configure (int /*<<< orphan*/ *) ; 
static  int ngx_http_lua_config_prefix (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_http_lua_version ; 

void
ngx_http_lua_inject_config_api(lua_State *L)
{
    /* ngx.config */

    lua_createtable(L, 0, 6 /* nrec */);    /* .config */

#if (NGX_DEBUG)
    lua_pushboolean(L, 1);
#else
    lua_pushboolean(L, 0);
#endif
    lua_setfield(L, -2, "debug");

    lua_pushcfunction(L, ngx_http_lua_config_prefix);
    lua_setfield(L, -2, "prefix");

    lua_pushinteger(L, nginx_version);
    lua_setfield(L, -2, "nginx_version");

    lua_pushinteger(L, ngx_http_lua_version);
    lua_setfield(L, -2, "ngx_lua_version");

    lua_pushcfunction(L, ngx_http_lua_config_configure);
    lua_setfield(L, -2, "nginx_configure");

    lua_pushliteral(L, "http");
    lua_setfield(L, -2, "subsystem");

    lua_setfield(L, -2, "config");
}

__attribute__((used)) static int
ngx_http_lua_config_prefix(lua_State *L)
{
    lua_pushlstring(L, (char *) ngx_cycle->prefix.data,
                    ngx_cycle->prefix.len);
    return 1;
}

__attribute__((used)) static int
ngx_http_lua_config_configure(lua_State *L)
{
    lua_pushliteral(L, NGX_CONFIGURE);
    return 1;
}

