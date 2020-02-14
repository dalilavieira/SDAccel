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
typedef  int /*<<< orphan*/  THGenerator ;
typedef  int /*<<< orphan*/  THFile ;

/* Variables and functions */
 int /*<<< orphan*/  THFile_readByteRaw (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  THFile_writeByteRaw (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  THGenerator_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * THGenerator_new () ; 
 void* luaT_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaT_newmetatable (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *),int (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaT_pushudata (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 char* torch_Generator ; 
 int /*<<< orphan*/  torch_Generator_factory ; 
 int /*<<< orphan*/  torch_Generator_table_ ; 

int torch_Generator_new(lua_State *L)
{
  THGenerator *gen = THGenerator_new();
  luaT_pushudata(L, gen, torch_Generator);
  return 1;
}

int torch_Generator_free(lua_State *L)
{
  THGenerator *gen= luaT_checkudata(L, 1, torch_Generator);
  THGenerator_free(gen);
  return 0;
}

__attribute__((used)) static int torch_Generator_write(lua_State *L)
{
  THGenerator *gen = luaT_checkudata(L, 1, torch_Generator);
  THFile *file = luaT_checkudata(L, 2, "torch.File");

  THFile_writeByteRaw(file, (unsigned char *)gen, sizeof(THGenerator));
  return 0;
}

__attribute__((used)) static int torch_Generator_read(lua_State *L)
{
  THGenerator *gen = luaT_checkudata(L, 1, torch_Generator);
  THFile *file = luaT_checkudata(L, 2, "torch.File");

  THFile_readByteRaw(file, (unsigned char *)gen, sizeof(THGenerator));
  return 0;
}

void torch_Generator_init(lua_State *L)
{
  luaT_newmetatable(L, torch_Generator, NULL,
                    torch_Generator_new, torch_Generator_free, torch_Generator_factory);
  luaT_setfuncs(L, torch_Generator_table_, 0);
  lua_pop(L, 1);
}

