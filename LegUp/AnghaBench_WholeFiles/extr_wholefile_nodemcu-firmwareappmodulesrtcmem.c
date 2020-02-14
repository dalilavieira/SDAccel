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
 int RTC_USER_MEM_NUM_DWORDS ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int,int,char*) ; 
 int luaL_checknumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_checkstack (int /*<<< orphan*/ *,int) ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_isnumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int lua_tonumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  rtc_mem_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_mem_write (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int rtcmem_read32 (lua_State *L)
{
  int idx = luaL_checknumber (L, 1);
  int n = 1;
  if (lua_isnumber (L, 2))
    n = lua_tonumber (L, 2);

  if (!lua_checkstack (L, n))
    return 0;

  int ret  = 0;
  while (n > 0 && idx >= 0 && idx < RTC_USER_MEM_NUM_DWORDS)
  {
    lua_pushinteger (L, rtc_mem_read (idx++));
    --n;
    ++ret;
  }
  return ret;
}

__attribute__((used)) static int rtcmem_write32 (lua_State *L)
{
  int idx = luaL_checknumber (L, 1);
  int n = lua_gettop (L) - 1;
  luaL_argcheck (
    L, idx + n <= RTC_USER_MEM_NUM_DWORDS, 1, "RTC mem would overrun");
  int src = 2;
  while (n-- > 0)
  {
    rtc_mem_write (idx++, lua_tonumber (L, src++));
  }
  return 0;
}

