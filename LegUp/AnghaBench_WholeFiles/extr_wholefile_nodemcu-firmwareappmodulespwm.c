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
typedef  unsigned int u32 ;
typedef  unsigned int s32 ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int NORMAL_PWM_DEPTH ; 
 unsigned int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  platform_pwm_close (unsigned int) ; 
 unsigned int platform_pwm_get_clock (unsigned int) ; 
 unsigned int platform_pwm_get_duty (unsigned int) ; 
 int /*<<< orphan*/  platform_pwm_init () ; 
 unsigned int platform_pwm_set_clock (unsigned int,unsigned int) ; 
 unsigned int platform_pwm_set_duty (unsigned int,unsigned int) ; 
 unsigned int platform_pwm_setup (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  platform_pwm_start (unsigned int) ; 
 int /*<<< orphan*/  platform_pwm_stop (unsigned int) ; 
 int /*<<< orphan*/  pwm ; 

__attribute__((used)) static int lpwm_setup( lua_State* L )
{
  s32 freq;	  // signed, to error check for negative values
  unsigned duty;
  unsigned id;

  id = luaL_checkinteger( L, 1 );
  if(id==0)
    return luaL_error( L, "no pwm for D0" );
  MOD_CHECK_ID( pwm, id );
  freq = luaL_checkinteger( L, 2 );
  if ( freq <= 0 )
    return luaL_error( L, "wrong arg range" );
  duty = luaL_checkinteger( L, 3 );
  if ( duty > NORMAL_PWM_DEPTH )
    // Negative values will turn out > 100, so will also fail.
    return luaL_error( L, "wrong arg range" );
  freq = platform_pwm_setup( id, (u32)freq, duty );
  if(freq==0)
    return luaL_error( L, "too many pwms." );
  lua_pushinteger( L, freq );
  return 1;
}

__attribute__((used)) static int lpwm_close( lua_State* L )
{
  unsigned id;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  platform_pwm_close( id );
  return 0;
}

__attribute__((used)) static int lpwm_start( lua_State* L )
{
  unsigned id;
  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  if (!platform_pwm_start( id )) {
    return luaL_error(L, "Unable to start PWM output");
  }
  return 0;
}

__attribute__((used)) static int lpwm_stop( lua_State* L )
{
  unsigned id;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  platform_pwm_stop( id );
  return 0;
}

__attribute__((used)) static int lpwm_setclock( lua_State* L )
{
  unsigned id;
  s32 clk;	// signed to error-check for negative values

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  clk = luaL_checkinteger( L, 2 );
  if ( clk <= 0 )
    return luaL_error( L, "wrong arg range" );
  clk = platform_pwm_set_clock( id, (u32)clk );
  lua_pushinteger( L, clk );
  return 1;
}

__attribute__((used)) static int lpwm_getclock( lua_State* L )
{
  unsigned id;
  u32 clk;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  clk = platform_pwm_get_clock( id );
  lua_pushinteger( L, clk );
  return 1;
}

__attribute__((used)) static int lpwm_setduty( lua_State* L )
{
  unsigned id;
  s32 duty;  // signed to error-check for negative values

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  duty = luaL_checkinteger( L, 2 );
  if ( duty > NORMAL_PWM_DEPTH )
    return luaL_error( L, "wrong arg range" );
  duty = platform_pwm_set_duty( id, (u32)duty );
  lua_pushinteger( L, duty );
  return 1;
}

__attribute__((used)) static int lpwm_getduty( lua_State* L )
{
  unsigned id;
  u32 duty;

  id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( pwm, id );
  duty = platform_pwm_get_duty( id );
  lua_pushinteger( L, duty );
  return 1;
}

int lpwm_open( lua_State *L ) {
  platform_pwm_init();
  return 0;
}

