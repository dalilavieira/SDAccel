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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  size_t uint32_t ;
typedef  int /*<<< orphan*/  os_param_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  scalar_t__ int32_t ;

/* Variables and functions */
 scalar_t__ LUA_NOREF ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ LUA_TFUNCTION ; 
 scalar_t__ LUA_TLIGHTFUNCTION ; 
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  PLATFORM_GPIO_OUTPUT ; 
 int /*<<< orphan*/  PLATFORM_GPIO_PULLUP ; 
 unsigned int SWITEC_CHANNEL_COUNT ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,char*) ; 
 void* luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 
 int* pin_num ; 
 int /*<<< orphan*/  platform_gpio_exists (size_t) ; 
 int /*<<< orphan*/  platform_gpio_mode (size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__* stopped_callback ; 
 int /*<<< orphan*/  switec ; 
 scalar_t__ switec_close (unsigned int) ; 
 scalar_t__ switec_getpos (int,scalar_t__*,scalar_t__*,scalar_t__*) ; 
 scalar_t__ switec_moveto (unsigned int,int) ; 
 scalar_t__ switec_reset (unsigned int) ; 
 scalar_t__ switec_setup (unsigned int,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  task_get_id (void (*) (int /*<<< orphan*/ ,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  tasknumber ; 

__attribute__((used)) static void callback_free(lua_State* L, unsigned int id)
{
  luaL_unref(L, LUA_REGISTRYINDEX, stopped_callback[id]);
  stopped_callback[id] = LUA_NOREF;
}

__attribute__((used)) static void callback_set(lua_State* L, unsigned int id, int argNumber)
{
  if (lua_type(L, argNumber) == LUA_TFUNCTION || lua_type(L, argNumber) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, argNumber);  // copy argument (func) to the top of stack
    callback_free(L, id);
    stopped_callback[id] = luaL_ref(L, LUA_REGISTRYINDEX);
  }
}

__attribute__((used)) static void callback_execute(lua_State* L, unsigned int id)
{
  if (stopped_callback[id] != LUA_NOREF) {
    int callback = stopped_callback[id];
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback);
    callback_free(L, id);

    lua_call(L, 0, 0);
  }
}

int platform_switec_exists( unsigned int id )
{
  return (id < SWITEC_CHANNEL_COUNT);
}

__attribute__((used)) static int lswitec_setup( lua_State* L )
{
  unsigned int id;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( switec, id );
  int pin[4];

  if (switec_close(id)) {
    return luaL_error( L, "Unable to setup stepper." );
  }

  int i;
  for (i = 0; i < 4; i++) {
    uint32_t gpio = luaL_checkinteger(L, 2 + i);

    luaL_argcheck(L, platform_gpio_exists(gpio), 2 + i, "Invalid pin");

    pin[i] = pin_num[gpio];

    platform_gpio_mode(gpio, PLATFORM_GPIO_OUTPUT, PLATFORM_GPIO_PULLUP);
  }

  int deg_per_sec = 0;
  if (lua_gettop(L) >= 6) {
    deg_per_sec = luaL_checkinteger(L, 6);
  }

  if (switec_setup(id, pin, deg_per_sec, tasknumber)) {
    return luaL_error(L, "Unable to setup stepper.");
  }
  return 0;
}

__attribute__((used)) static int lswitec_close( lua_State* L )
{
  unsigned int id;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( switec, id );
  callback_free(L, id);
  if (switec_close( id )) {
    return luaL_error( L, "Unable to close stepper." );
  }
  return 0;
}

__attribute__((used)) static int lswitec_reset( lua_State* L )
{
  unsigned int id;
  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( switec, id );
  if (switec_reset( id )) {
    return luaL_error( L, "Unable to reset stepper." );
  }
  return 0;
}

__attribute__((used)) static int lswitec_moveto( lua_State* L )
{
  unsigned int id;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( switec, id );
  int pos;
  pos = luaL_checkinteger( L, 2 );

  if (lua_gettop(L) >= 3) {
    callback_set(L, id, 3);
  } else {
    callback_free(L, id);
  }

  if (switec_moveto( id, pos )) {
    return luaL_error( L, "Unable to move stepper." );
  }
  return 0;
}

__attribute__((used)) static int lswitec_getpos( lua_State* L )
{
  unsigned int id;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( switec, id );
  int32_t pos;
  int32_t dir;
  int32_t target;
  if (switec_getpos( id, &pos, &dir, &target )) {
    return luaL_error( L, "Unable to get position." );
  }
  lua_pushnumber(L, pos);
  lua_pushnumber(L, dir);
  return 2;
}

__attribute__((used)) static int lswitec_dequeue(lua_State* L)
{
  int id;

  for (id = 0; id < SWITEC_CHANNEL_COUNT; id++) {
    if (stopped_callback[id] != LUA_NOREF) {
      int32_t pos;
      int32_t dir;
      int32_t target;
      if (!switec_getpos( id, &pos, &dir, &target )) {
	if (dir == 0 && pos == target) {
	  callback_execute(L, id);
	}
      }
    }
  }

  return 0;
}

__attribute__((used)) static void lswitec_task(os_param_t param, uint8_t prio)
{
  (void) param;
  (void) prio;

  lswitec_dequeue(lua_getstate());
}

__attribute__((used)) static int switec_open(lua_State *L)
{
  (void) L;

  tasknumber = task_get_id(lswitec_task);

  return 0;
}

