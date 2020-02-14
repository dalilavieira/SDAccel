#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct timeval {double tv_sec; double tv_usec; } ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  double lua_Number ;
struct TYPE_9__ {int size; } ;
typedef  TYPE_1__ THLongStorage ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  LUA_FILEHANDLE ; 
 int /*<<< orphan*/  LUA_GCCOLLECT ; 
 int LUA_REGISTRYINDEX ; 
 int /*<<< orphan*/  THGetNumCores () ; 
 int /*<<< orphan*/  THGetNumThreads () ; 
 int /*<<< orphan*/  THLongStorage_copy (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  THLongStorage_free (TYPE_1__*) ; 
 TYPE_1__* THLongStorage_newWithSize (int) ; 
 int /*<<< orphan*/  THLongStorage_set (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THSetArgErrorHandler (void (*) (int,char const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THSetErrorHandler (void (*) (char const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THSetGCHandler (void (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  THSetNumThreads (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fileno (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 int isatty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,char const*) ; 
 int /*<<< orphan*/  luaL_argerror (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaL_checkint (int /*<<< orphan*/ *,int) ; 
 double luaL_checknumber (int /*<<< orphan*/ *,int) ; 
 scalar_t__ luaL_checkudata (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_error (int /*<<< orphan*/ *,char const*) ; 
 int luaT_checkboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* luaT_toudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_gc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_getfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_getglobal (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ lua_getmetatable (int /*<<< orphan*/ *,int) ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_isnumber (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_isstring (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_istable (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,double) ; 
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  lua_rawget (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_tonumber (int /*<<< orphan*/ *,int) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 char const* torch_getdefaulttensortype (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  torch_utils__ ; 

THLongStorage* torch_checklongargs(lua_State *L, int index)
{
  THLongStorage *storage;
  int i;
  int narg = lua_gettop(L)-index+1;

  if(narg == 1 && luaT_toudata(L, index, "torch.LongStorage"))
  {
    THLongStorage *storagesrc = luaT_toudata(L, index, "torch.LongStorage");
    storage = THLongStorage_newWithSize(storagesrc->size);
    THLongStorage_copy(storage, storagesrc);
  }
  else
  {
    storage = THLongStorage_newWithSize(narg);
    for(i = index; i < index+narg; i++)
    {
      if(!lua_isnumber(L, i))
      {
        THLongStorage_free(storage);
        luaL_argerror(L, i, "number expected");
      }
      THLongStorage_set(storage, i-index, lua_tonumber(L, i));
    }
  }
  return storage;
}

int torch_islongargs(lua_State *L, int index)
{
  int narg = lua_gettop(L)-index+1;

  if(narg == 1 && luaT_toudata(L, index, "torch.LongStorage"))
  {
    return 1;
  }
  else
  {
    int i;

    for(i = index; i < index+narg; i++)
    {
      if(!lua_isnumber(L, i))
        return 0;
    }
    return 1;
  }
  return 0;
}

__attribute__((used)) static int torch_isatty(lua_State *L)
{
  FILE **fp = (FILE **) luaL_checkudata(L, -1, LUA_FILEHANDLE);
#ifdef _WIN32
  lua_pushboolean(L, _isatty(_fileno(*fp)));
#else
  lua_pushboolean(L, isatty(fileno(*fp)));
#endif
  return 1;
}

__attribute__((used)) static double real_time()
{
#ifdef _WIN32
  if (ticksPerSecond.QuadPart == 0)
  {
    QueryPerformanceFrequency(&ticksPerSecond);
  }
  LARGE_INTEGER current;
  QueryPerformanceCounter(&current);
  return (double)(current.QuadPart) / ticksPerSecond.QuadPart;
#else
  struct timeval current;
  gettimeofday(&current, NULL);
  return (current.tv_sec + current.tv_usec/1000000.0);
#endif
}

__attribute__((used)) static int torch_lua_tic(lua_State* L)
{
  double ttime = real_time();
  lua_pushnumber(L,ttime);
  return 1;
}

__attribute__((used)) static int torch_lua_toc(lua_State* L)
{
  double toctime = real_time();
  lua_Number tictime = luaL_checknumber(L,1);
  lua_pushnumber(L,toctime-tictime);
  return 1;
}

__attribute__((used)) static int torch_lua_getdefaulttensortype(lua_State *L)
{
  const char* tname = torch_getdefaulttensortype(L);
  if(tname)
  {
    lua_pushstring(L, tname);
    return 1;
  }
  return 0;
}

const char* torch_getdefaulttensortype(lua_State *L)
{
  lua_getglobal(L, "torch");
  if(lua_istable(L, -1))
  {
    lua_getfield(L, -1, "Tensor");
    if(lua_istable(L, -1))
    {
      if(lua_getmetatable(L, -1))
      {
        lua_pushstring(L, "__index");
        lua_rawget(L, -2);
        if(lua_istable(L, -1))
        {
          lua_rawget(L, LUA_REGISTRYINDEX);
          if(lua_isstring(L, -1))
          {
            const char *tname = lua_tostring(L, -1);
            lua_pop(L, 4);
            return tname;
          }
        }
        else
        {
          lua_pop(L, 4);
          return NULL;
        }
      }
      else
      {
        lua_pop(L, 2);
        return NULL;
      }
    }
    else
    {
      lua_pop(L, 2);
      return NULL;
    }
  }
  else
  {
    lua_pop(L, 1);
    return NULL;
  }
  return NULL;
}

__attribute__((used)) static int torch_getnumthreads(lua_State *L)
{
  lua_pushinteger(L, THGetNumThreads());
  return 1;
}

__attribute__((used)) static int torch_setnumthreads(lua_State *L)
{
  THSetNumThreads(luaL_checkint(L, 1));
  return 0;
}

__attribute__((used)) static int torch_getnumcores(lua_State *L)
{
  lua_pushinteger(L, THGetNumCores());
  return 1;
}

__attribute__((used)) static void luaTorchGCFunction(void *data)
{
  lua_State *L = data;
  lua_gc(L, LUA_GCCOLLECT, 0);
}

__attribute__((used)) static int torch_setheaptracking(lua_State *L)
{
  int enabled = luaT_checkboolean(L,1);
  lua_getglobal(L, "torch");
  lua_pushboolean(L, enabled);
  lua_setfield(L, -2, "_heaptracking");
  if(enabled) {
    THSetGCHandler(luaTorchGCFunction, L);
  } else {
    THSetGCHandler(NULL, NULL);
  }
  return 0;
}

__attribute__((used)) static void luaTorchErrorHandlerFunction(const char *msg, void *data)
{
  lua_State *L = data;
  luaL_error(L, msg);
}

__attribute__((used)) static void luaTorchArgErrorHandlerFunction(int argNumber, const char *msg, void *data)
{
  lua_State *L = data;
  luaL_argcheck(L, 0, argNumber, msg);
}

__attribute__((used)) static int torch_updateerrorhandlers(lua_State *L)
{
  THSetErrorHandler(luaTorchErrorHandlerFunction, L);
  THSetArgErrorHandler(luaTorchArgErrorHandlerFunction, L);
  return 0;
}

void torch_utils_init(lua_State *L)
{
  torch_updateerrorhandlers(L);
  luaT_setfuncs(L, torch_utils__, 0);
}

