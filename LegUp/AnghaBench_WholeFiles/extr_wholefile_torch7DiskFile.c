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

/* Variables and functions */
 int /*<<< orphan*/  THDiskFile_bigEndianEncoding (int /*<<< orphan*/ *) ; 
 int THDiskFile_isLittleEndianCPU () ; 
 int /*<<< orphan*/  THDiskFile_littleEndianEncoding (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THDiskFile_longSize (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THDiskFile_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THDiskFile_nativeEndianEncoding (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * THDiskFile_new (char const*,char const*,int) ; 
 int /*<<< orphan*/  THDiskFile_noBuffer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THFile_free (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isOpened (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isReadable (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isWritable (int /*<<< orphan*/ *) ; 
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 char* luaL_optstring (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/ * luaT_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaT_newmetatable (int /*<<< orphan*/ *,char*,char*,int (*) (int /*<<< orphan*/ *),int (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ *) ; 
 int luaT_optboolean (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaT_pushudata (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushfstring (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,char*,char,char) ; 
 int /*<<< orphan*/  lua_settop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_tointeger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  torch_DiskFile__ ; 

__attribute__((used)) static int torch_DiskFile_new(lua_State *L)
{
  const char *name = luaL_checkstring(L, 1);
  const char *mode = luaL_optstring(L, 2, "r");
  int isQuiet = luaT_optboolean(L, 3, 0);
  THFile *self = THDiskFile_new(name, mode, isQuiet);

  luaT_pushudata(L, self, "torch.DiskFile");
  return 1;
}

__attribute__((used)) static int torch_DiskFile_free(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  THFile_free(self);
  return 0;
}

__attribute__((used)) static int torch_DiskFile_isLittleEndianCPU(lua_State *L)
{
  lua_pushboolean(L, THDiskFile_isLittleEndianCPU());
  return 1;
}

__attribute__((used)) static int torch_DiskFile_isBigEndianCPU(lua_State *L)
{
  lua_pushboolean(L, !THDiskFile_isLittleEndianCPU());
  return 1;
}

__attribute__((used)) static int torch_DiskFile_nativeEndianEncoding(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  THDiskFile_nativeEndianEncoding(self);
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_DiskFile_littleEndianEncoding(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  THDiskFile_littleEndianEncoding(self);
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_DiskFile_bigEndianEncoding(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  THDiskFile_bigEndianEncoding(self);
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_DiskFile_longSize(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  THDiskFile_longSize(self, lua_tointeger(L, 2));
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_DiskFile_noBuffer(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  THDiskFile_noBuffer(self);
  lua_settop(L, 1);
  return 1;
}

__attribute__((used)) static int torch_DiskFile___tostring__(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.DiskFile");
  lua_pushfstring(L, "torch.DiskFile on <%s> [status: %s -- mode %c%c]",
                  THDiskFile_name(self),
                  (THFile_isOpened(self) ? "open" : "closed"),
                  (THFile_isReadable(self) ? 'r' : ' '),
                  (THFile_isWritable(self) ? 'w' : ' '));

  return 1;
}

void torch_DiskFile_init(lua_State *L)
{
  luaT_newmetatable(L, "torch.DiskFile", "torch.File",
                    torch_DiskFile_new, torch_DiskFile_free, NULL);

  luaT_setfuncs(L, torch_DiskFile__, 0);
  lua_pop(L, 1);
}

