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
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  lua_Integer ;

/* Variables and functions */
 int /*<<< orphan*/  dump_c_mem () ; 
 int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaS_expandshr (int) ; 
 scalar_t__ lua_isnone (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ lua_toboolean (int /*<<< orphan*/ *,int) ; 
 int mallctl_bool (char*,int*) ; 
 int /*<<< orphan*/  mallctl_cmd (char*) ; 
 int /*<<< orphan*/  malloc_current_memory () ; 
 size_t malloc_memory_block () ; 
 size_t malloc_used_memory () ; 
 int /*<<< orphan*/  memory_info_dump () ; 

__attribute__((used)) static int
ltotal(lua_State *L) {
	size_t t = malloc_used_memory();
	lua_pushinteger(L, (lua_Integer)t);

	return 1;
}

__attribute__((used)) static int
lblock(lua_State *L) {
	size_t t = malloc_memory_block();
	lua_pushinteger(L, (lua_Integer)t);

	return 1;
}

__attribute__((used)) static int
ldumpinfo(lua_State *L) {
	memory_info_dump();

	return 0;
}

__attribute__((used)) static int
ldump(lua_State *L) {
	dump_c_mem();

	return 0;
}

__attribute__((used)) static int
lexpandshrtbl(lua_State *L) {
	int n = luaL_checkinteger(L, 1);
	luaS_expandshr(n);
	return 0;
}

__attribute__((used)) static int
lcurrent(lua_State *L) {
	lua_pushinteger(L, malloc_current_memory());
	return 1;
}

__attribute__((used)) static int
ldumpheap(lua_State *L) {
	mallctl_cmd("prof.dump");
	return 0;
}

__attribute__((used)) static int
lprofactive(lua_State *L) {
	bool *pval, active;
	if (lua_isnone(L, 1)) {
		pval = NULL;
	} else {
		active = lua_toboolean(L, 1) ? true : false;
		pval = &active;
	}
	bool ret = mallctl_bool("prof.active", pval);
	lua_pushboolean(L, ret);
	return 1;
}

