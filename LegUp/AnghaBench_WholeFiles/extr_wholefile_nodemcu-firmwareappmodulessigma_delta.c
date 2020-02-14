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

/* Variables and functions */
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,int) ; 
 int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  platform_sigma_delta_close (int) ; 
 int /*<<< orphan*/  platform_sigma_delta_set_prescale (int) ; 
 int /*<<< orphan*/  platform_sigma_delta_set_pwmduty (int) ; 
 int /*<<< orphan*/  platform_sigma_delta_set_target (int) ; 
 int /*<<< orphan*/  platform_sigma_delta_setup (int) ; 
 int /*<<< orphan*/  sigma_delta ; 

__attribute__((used)) static int sigma_delta_setup( lua_State *L )
{
    int pin = luaL_checkinteger( L, 1 );

    MOD_CHECK_ID(sigma_delta, pin);

    platform_sigma_delta_setup( pin );

    return 0;
}

__attribute__((used)) static int sigma_delta_close( lua_State *L )
{
    int pin = luaL_checkinteger( L, 1 );

    MOD_CHECK_ID(sigma_delta, pin);

    platform_sigma_delta_close( pin );

    return 0;
}

__attribute__((used)) static int sigma_delta_setpwmduty( lua_State *L )
{
    int duty = luaL_checkinteger( L, 1 );

    if (duty < 0 || duty > 255) {
        return luaL_error( L, "wrong arg range" );
    }

    platform_sigma_delta_set_pwmduty( duty );

    return 0;
}

__attribute__((used)) static int sigma_delta_setprescale( lua_State *L )
{
    int prescale = luaL_checkinteger( L, 1 );

    if (prescale < 0 || prescale > 255) {
        return luaL_error( L, "wrong arg range" );
    }

    platform_sigma_delta_set_prescale( prescale );

    return 0;
}

__attribute__((used)) static int sigma_delta_settarget( lua_State *L )
{
    int target = luaL_checkinteger( L, 1 );

    if (target < 0 || target > 255) {
        return luaL_error( L, "wrong arg range" );
    }

    platform_sigma_delta_set_target( target );

    return 0;
}

