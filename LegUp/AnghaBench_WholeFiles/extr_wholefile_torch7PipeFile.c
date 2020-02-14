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
 int /*<<< orphan*/  THDiskFile_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THFile_free (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isOpened (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isReadable (int /*<<< orphan*/ *) ; 
 scalar_t__ THFile_isWritable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * THPipeFile_new (char const*,char const*,int) ; 
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 char* luaL_optstring (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/ * luaT_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaT_newmetatable (int /*<<< orphan*/ *,char*,char*,int (*) (int /*<<< orphan*/ *),int (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ *) ; 
 int luaT_optboolean (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaT_pushudata (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushfstring (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,char*,char,char) ; 
 int /*<<< orphan*/  torch_PipeFile__ ; 

__attribute__((used)) static int torch_PipeFile_new(lua_State *L)
{
  const char *name = luaL_checkstring(L, 1);
  const char *mode = luaL_optstring(L, 2, "r");
  int isQuiet = luaT_optboolean(L, 3, 0);
  THFile *self = THPipeFile_new(name, mode, isQuiet);

  luaT_pushudata(L, self, "torch.PipeFile");
  return 1;
}

__attribute__((used)) static int torch_PipeFile_free(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.PipeFile");
  THFile_free(self);
  return 0;
}

__attribute__((used)) static int torch_PipeFile___tostring__(lua_State *L)
{
  THFile *self = luaT_checkudata(L, 1, "torch.PipeFile");
  lua_pushfstring(L, "torch.PipeFile on <%s> [status: %s -- mode: %c%c]",
                  THDiskFile_name(self),
                  (THFile_isOpened(self) ? "open" : "closed"),
                  (THFile_isReadable(self) ? 'r' : ' '),
                  (THFile_isWritable(self) ? 'w' : ' '));
  return 1;
}

void torch_PipeFile_init(lua_State *L)
{
  luaT_newmetatable(L, "torch.PipeFile", "torch.DiskFile",
                    torch_PipeFile_new, torch_PipeFile_free, NULL);
  luaT_setfuncs(L, torch_PipeFile__, 0);
  lua_pop(L, 1);
}

