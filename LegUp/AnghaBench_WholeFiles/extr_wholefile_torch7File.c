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
typedef  int ptrdiff_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  THFile ;

/* Variables and functions */
 int /*<<< orphan*/  LUA_TSTRING ; 
 int /*<<< orphan*/  THArgCheck (int,int,char*) ; 
 scalar_t__ THFile_position (int /*<<< orphan*/ *) ; 
 int THFile_readStringRaw (int /*<<< orphan*/ *,char const*,char**) ; 
 int /*<<< orphan*/  THFile_seek (int /*<<< orphan*/ *,size_t) ; 
 scalar_t__ THFile_writeStringRaw (int /*<<< orphan*/ *,char const*,size_t) ; 
 int /*<<< orphan*/  THFree (char*) ; 
 int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaL_checktype (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * luaT_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaT_newmetatable (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  lua_settop (int /*<<< orphan*/ *,int) ; 
 char* lua_tolstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int /*<<< orphan*/  torch_File__ ; 

__attribute__((used)) static int torch_File_seek(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.File");
  ptrdiff_t position = luaL_checkinteger(L, 2)-1;
  // >= 0 because it has 1 already subtracted
  THArgCheck(position >= 0, 2, "position has to be greater than 0!");
  THFile_seek(self, (size_t)position);
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_File_position(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.File");
  lua_pushnumber(L, THFile_position(self)+1);
  return 1;
}

__attribute__((used)) static int torch_File_readString(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.File");
  const char *format = luaL_checkstring(L, 2);
  char *str;
  ptrdiff_t size;

  size = THFile_readStringRaw(self, format, &str);
  lua_pushlstring(L, str, size);
  THFree(str);

  return 1;
}

__attribute__((used)) static int torch_File_writeString(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.File");
  const char *str = NULL;
  size_t size;

  luaL_checktype(L, 2, LUA_TSTRING);
  str = lua_tolstring(L, 2, &size);
  lua_pushnumber(L, THFile_writeStringRaw(self, str, size));
  return 1;
}

void torch_File_init(lua_State *L)
{
  luaT_newmetatable(L, "torch.File", NULL, NULL, NULL, NULL);
  luaT_setfuncs(L, torch_File__, 0);
  lua_pop(L, 1);
}

