#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  ngx_int_t ;
typedef  int /*<<< orphan*/  ngx_conf_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  NGX_OK ; 
 int /*<<< orphan*/  lua_createtable (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_pushcfunction (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  ngx_http_lua_add_package_preload (int /*<<< orphan*/ *,char*,int (*) (int /*<<< orphan*/ *)) ; 
static  int ngx_http_lua_fake_delayed_load_function (int /*<<< orphan*/ *) ; 
static  int ngx_http_lua_fake_delayed_load_preload (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ngx_int_t
ngx_http_lua_fake_delayed_load_init(ngx_conf_t *cf)
{
    ngx_http_lua_add_package_preload(cf, "ngx.delayed_load",
                                     ngx_http_lua_fake_delayed_load_preload);
    return NGX_OK;
}

__attribute__((used)) static int
ngx_http_lua_fake_delayed_load_preload(lua_State *L)
{
    lua_createtable(L, 0, 1);

    lua_pushcfunction(L, ngx_http_lua_fake_delayed_load_function);
    lua_setfield(L, -2, "get_function");

    return 1;
}

__attribute__((used)) static int
ngx_http_lua_fake_delayed_load_function(lua_State * L)
{
    return 0;
}

