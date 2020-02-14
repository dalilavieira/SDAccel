#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  TYPE_1__* timer_t ;
typedef  int /*<<< orphan*/  timer_struct_t ;
typedef  int sint32_t ;
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_4__ {scalar_t__ lua_ref; scalar_t__ self_ref; int mode; int interval; int /*<<< orphan*/  os; } ;

/* Variables and functions */
 scalar_t__ LUA_NOREF ; 
 scalar_t__ LUA_REFNIL ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ LUA_TFUNCTION ; 
 scalar_t__ LUA_TLIGHTFUNCTION ; 
 scalar_t__ MAX_TIMEOUT ; 
 char* MAX_TIMEOUT_ERR_STR ; 
 int /*<<< orphan*/  SWTIMER_REG_CB (void (*) (void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SWTIMER_RESUME ; 
 int TIMER_IDLE_FLAG ; 
 int TIMER_MODE_AUTO ; 
 void* TIMER_MODE_OFF ; 
 int TIMER_MODE_SEMI ; 
 int TIMER_MODE_SINGLE ; 
 scalar_t__ last_rtc_time ; 
 int last_rtc_time_us ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int,int,char*) ; 
 scalar_t__ luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaL_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaL_getmetatable (int /*<<< orphan*/ *,char*) ; 
 void* luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_rometatable (int /*<<< orphan*/ *,char*,void*) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 int /*<<< orphan*/  lua_newuserdata (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushnil (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  lua_setmetatable (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  os_delay_us (int) ; 
 int /*<<< orphan*/  os_timer_arm (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  os_timer_disarm (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_timer_setfn (int /*<<< orphan*/ *,void (*) (void*),TYPE_1__*) ; 
 int rtc_time_cali ; 
 int /*<<< orphan*/  rtc_timer ; 
 scalar_t__ soft_watchdog ; 
 scalar_t__ system_get_rtc_time () ; 
 int system_get_time () ; 
 int /*<<< orphan*/  system_restart () ; 
 int system_rtc_clock_cali_proc () ; 
 int /*<<< orphan*/  system_soft_wdt_feed () ; 
 scalar_t__ tmr_dyn_map ; 

__attribute__((used)) static void alarm_timer_common(void* arg){
	timer_t tmr = (timer_t)arg;
	lua_State* L = lua_getstate();
	if(tmr->lua_ref == LUA_NOREF)
		return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, tmr->lua_ref);
	lua_rawgeti(L, LUA_REGISTRYINDEX, tmr->self_ref);
	//if the timer was set to single run we clean up after it
	if(tmr->mode == TIMER_MODE_SINGLE){
		luaL_unref(L, LUA_REGISTRYINDEX, tmr->lua_ref);
		tmr->lua_ref = LUA_NOREF;
		tmr->mode = TIMER_MODE_OFF;
	}else if(tmr->mode == TIMER_MODE_SEMI){
		tmr->mode |= TIMER_IDLE_FLAG;
	}
	if (tmr->mode != TIMER_MODE_AUTO && tmr->self_ref != LUA_REFNIL) {
		luaL_unref(L, LUA_REGISTRYINDEX, tmr->self_ref);
		tmr->self_ref = LUA_NOREF;
	}
	lua_call(L, 1, 0);
}

__attribute__((used)) static int tmr_delay( lua_State* L ){
	sint32_t us = luaL_checkinteger(L, 1);
	if(us <= 0)
		return luaL_error(L, "wrong arg range");
	while(us >= 1000000){
		us -= 1000000;
		os_delay_us(1000000);
		system_soft_wdt_feed ();
	}
	if(us>0){
		os_delay_us(us);
		system_soft_wdt_feed ();
	}
	return 0;
}

__attribute__((used)) static int tmr_now(lua_State* L){
	uint32_t now = 0x7FFFFFFF & system_get_time();
	lua_pushinteger(L, now);
	return 1;
}

__attribute__((used)) static timer_t tmr_get( lua_State *L, int stack ) {
	timer_t t = (timer_t)luaL_checkudata(L, stack, "tmr.timer");
	if (t == NULL)
		return (timer_t)luaL_error(L, "timer object expected");
	return t;
}

__attribute__((used)) static int tmr_register(lua_State* L){
	timer_t tmr = tmr_get(L, 1);

	uint32_t interval = luaL_checkinteger(L, 2);
	uint8_t mode = luaL_checkinteger(L, 3);

	luaL_argcheck(L, (interval > 0 && interval <= MAX_TIMEOUT), 2, MAX_TIMEOUT_ERR_STR);
	luaL_argcheck(L, (mode == TIMER_MODE_SINGLE || mode == TIMER_MODE_SEMI || mode == TIMER_MODE_AUTO), 3, "Invalid mode");
	luaL_argcheck(L, (lua_type(L, 4) == LUA_TFUNCTION || lua_type(L, 4) == LUA_TLIGHTFUNCTION), 4, "Must be function");
	//get the lua function reference
	lua_pushvalue(L, 4);
	sint32_t ref = luaL_ref(L, LUA_REGISTRYINDEX);
	if(!(tmr->mode & TIMER_IDLE_FLAG) && tmr->mode != TIMER_MODE_OFF)
		os_timer_disarm(&tmr->os);
	//there was a bug in this part, the second part of the following condition was missing
	if(tmr->lua_ref != LUA_NOREF && tmr->lua_ref != ref)
		luaL_unref(L, LUA_REGISTRYINDEX, tmr->lua_ref);
	tmr->lua_ref = ref;
	tmr->mode = mode|TIMER_IDLE_FLAG;
	tmr->interval = interval;
	os_timer_setfn(&tmr->os, alarm_timer_common, tmr);
	return 0;
}

__attribute__((used)) static int tmr_start(lua_State* L){
	timer_t tmr = tmr_get(L, 1);

	if (tmr->self_ref == LUA_NOREF) {
		lua_pushvalue(L, 1);
		tmr->self_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}

	//we return false if the timer is not idle
	if(!(tmr->mode&TIMER_IDLE_FLAG)){
		lua_pushboolean(L, 0);
	}else{
		tmr->mode &= ~TIMER_IDLE_FLAG;
		os_timer_arm(&tmr->os, tmr->interval, tmr->mode==TIMER_MODE_AUTO);
		lua_pushboolean(L, 1);
	}
	return 1;
}

__attribute__((used)) static int tmr_alarm(lua_State* L){
	tmr_register(L);
	return tmr_start(L);
}

__attribute__((used)) static int tmr_stop(lua_State* L){
	timer_t tmr = tmr_get(L, 1);

	if (tmr->self_ref != LUA_REFNIL) {
		luaL_unref(L, LUA_REGISTRYINDEX, tmr->self_ref);
		tmr->self_ref = LUA_NOREF;
	}

	//we return false if the timer is idle (of not registered)
	if(!(tmr->mode & TIMER_IDLE_FLAG) && tmr->mode != TIMER_MODE_OFF){
		tmr->mode |= TIMER_IDLE_FLAG;
		os_timer_disarm(&tmr->os);
		lua_pushboolean(L, 1);
	}else{
		lua_pushboolean(L, 0);
	}
	return 1;
}

__attribute__((used)) static int tmr_unregister(lua_State* L){
	timer_t tmr = tmr_get(L, 1);

	if (tmr->self_ref != LUA_REFNIL) {
		luaL_unref(L, LUA_REGISTRYINDEX, tmr->self_ref);
		tmr->self_ref = LUA_NOREF;
	}

	if(!(tmr->mode & TIMER_IDLE_FLAG) && tmr->mode != TIMER_MODE_OFF)
		os_timer_disarm(&tmr->os);
	if(tmr->lua_ref != LUA_NOREF)
		luaL_unref(L, LUA_REGISTRYINDEX, tmr->lua_ref);
	tmr->lua_ref = LUA_NOREF;
	tmr->mode = TIMER_MODE_OFF;
	return 0;
}

__attribute__((used)) static int tmr_interval(lua_State* L){
	timer_t tmr = tmr_get(L, 1);

	uint32_t interval = luaL_checkinteger(L, 2);
	luaL_argcheck(L, (interval > 0 && interval <= MAX_TIMEOUT), 2, MAX_TIMEOUT_ERR_STR);
	if(tmr->mode != TIMER_MODE_OFF){
		tmr->interval = interval;
		if(!(tmr->mode&TIMER_IDLE_FLAG)){
			os_timer_disarm(&tmr->os);
			os_timer_arm(&tmr->os, tmr->interval, tmr->mode==TIMER_MODE_AUTO);
		}
	}
	return 0;
}

__attribute__((used)) static int tmr_state(lua_State* L){
	timer_t tmr = tmr_get(L, 1);

	if(tmr->mode == TIMER_MODE_OFF){
		lua_pushnil(L);
		return 1;
	}

  lua_pushboolean(L, (tmr->mode & TIMER_IDLE_FLAG) == 0);
  lua_pushinteger(L, tmr->mode & (~TIMER_IDLE_FLAG));
	return 2;
}

__attribute__((used)) static int tmr_wdclr( lua_State* L ){
	system_soft_wdt_feed ();
	// update_key_led();
	return 0;
}

__attribute__((used)) static uint32_t rtc2usec(uint64_t rtc){
	return (rtc*rtc_time_cali)>>12;
}

__attribute__((used)) inline static uint64_t rtc_timer_update(bool do_calibration){
	if (do_calibration || rtc_time_cali==0)
		rtc_time_cali=system_rtc_clock_cali_proc();

	uint32_t current = system_get_rtc_time();
	uint32_t since_last=current-last_rtc_time; // This will transparently deal with wraparound
	uint32_t us_since_last=rtc2usec(since_last);
	uint64_t now=last_rtc_time_us+us_since_last;

	// Only update if at least 100ms has passed since we last updated.
	// This prevents the rounding errors in rtc2usec from accumulating
	if (us_since_last>=100000)
	{
		last_rtc_time=current;
		last_rtc_time_us=now;
	}
	return now;
}

void rtc_callback(void *arg){
	rtc_timer_update(true);
	if(soft_watchdog > 0){
		soft_watchdog--;
		if(soft_watchdog == 0)
			system_restart();
	}
}

__attribute__((used)) static int tmr_time( lua_State* L ){
	uint64_t us=rtc_timer_update(false);
	lua_pushinteger(L, us/1000000);
	return 1;
}

__attribute__((used)) static int tmr_softwd( lua_State* L ){
	soft_watchdog = luaL_checkinteger(L, 1);
	return 0;
}

__attribute__((used)) static int tmr_create( lua_State *L ) {
	timer_t ud = (timer_t)lua_newuserdata(L, sizeof(timer_struct_t));
	if (!ud) return luaL_error(L, "not enough memory");
	luaL_getmetatable(L, "tmr.timer");
	lua_setmetatable(L, -2);
	ud->lua_ref = LUA_NOREF;
	ud->self_ref = LUA_NOREF;
	ud->mode = TIMER_MODE_OFF;
	os_timer_disarm(&ud->os);
	return 1;
}

int luaopen_tmr( lua_State *L ){
	luaL_rometatable(L, "tmr.timer", (void *)tmr_dyn_map);

	last_rtc_time=system_get_rtc_time(); // Right now is time 0
	last_rtc_time_us=0;

	os_timer_disarm(&rtc_timer);
	os_timer_setfn(&rtc_timer, rtc_callback, NULL);
	os_timer_arm(&rtc_timer, 1000, 1);

  SWTIMER_REG_CB(rtc_callback, SWTIMER_RESUME);
  //The function rtc_callback calls the a function that calibrates the SoftRTC for drift in the esp8266's clock.
  //My guess: after the duration of light_sleep there's bound to be some drift in the clock, so a calibration is due.
  SWTIMER_REG_CB(alarm_timer_common, SWTIMER_RESUME);
  //The function alarm_timer_common handles timers created by the developer via tmr.create().
  //No reason not to resume the timers, so resume em'.


	return 0;
}

