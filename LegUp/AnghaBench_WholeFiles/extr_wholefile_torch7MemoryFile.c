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
typedef  int /*<<< orphan*/  THFile ;
typedef  int /*<<< orphan*/  THCharStorage ;

/* Variables and functions */
 int /*<<< orphan*/  THCharStorage_retain (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THFile_free (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isOpened (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isReadable (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isWritable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THMemoryFile_longSize (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * THMemoryFile_new (char const*) ; 
 int /*<<< orphan*/ * THMemoryFile_newWithStorage (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/ * THMemoryFile_storage (int /*<<< orphan*/ *) ; 
 char* luaL_optstring (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/ * luaT_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaT_newmetatable (int /*<<< orphan*/ *,char*,char*,int (*) (int /*<<< orphan*/ *),int (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaT_pushudata (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * luaT_toudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushfstring (int /*<<< orphan*/ *,char*,char*,char,char) ; 
 int /*<<< orphan*/  lua_settop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_tointeger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  torch_MemoryFile__ ; 

__attribute__((used)) static int torch_MemoryFile_new(lua_State *L)
{
  const char *mode;
  THCharStorage *storage = luaT_toudata(L, 1, "torch.CharStorage");
  THFile *self;

  if(storage)
  {
    mode = luaL_optstring(L, 2, "rw");
    self = THMemoryFile_newWithStorage(storage, mode);
  }
  else
  {
    mode = luaL_optstring(L, 1, "rw");
    self = THMemoryFile_new(mode);
  }

  luaT_pushudata(L, self, "torch.MemoryFile");
  return 1;
}

__attribute__((used)) static int torch_MemoryFile_storage(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.MemoryFile");
  THCharStorage_retain(THMemoryFile_storage(self));
  luaT_pushudata(L, THMemoryFile_storage(self), "torch.CharStorage");
  return 1;
}

__attribute__((used)) static int torch_longSize(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.MemoryFile");
  THMemoryFile_longSize(self, lua_tointeger(L, 2));
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_MemoryFile_free(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.MemoryFile");
  THFile_free(self);
  return 0;
}

__attribute__((used)) static int torch_MemoryFile___tostring__(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.MemoryFile");
  lua_pushfstring(L, "torch.MemoryFile [status: %s -- mode: %c%c]",
                  (THFile_isOpened(self) ? "open" : "closed"),
                  (THFile_isReadable(self) ? 'r' : ' '),
                  (THFile_isWritable(self) ? 'w' : ' '));
  return 1;
}

void torch_MemoryFile_init(lua_State *L)
{
  luaT_newmetatable(L, "torch.MemoryFile", "torch.File",
                    torch_MemoryFile_new, torch_MemoryFile_free, NULL);
  luaT_setfuncs(L, torch_MemoryFile__, 0);
  lua_pop(L, 1);
}

