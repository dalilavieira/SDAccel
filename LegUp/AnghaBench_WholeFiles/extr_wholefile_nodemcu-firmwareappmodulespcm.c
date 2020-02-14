#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_9__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_13__ ;
typedef  struct TYPE_15__   TYPE_12__ ;

/* Type definitions */
typedef  void* uint8_t ;
typedef  int /*<<< orphan*/  uint8 ;
typedef  scalar_t__ task_param_t ;
struct TYPE_21__ {int isr_throttled; int self_ref; int cb_data_ref; int cb_drained_ref; int cb_paused_ref; int cb_stopped_ref; int cb_vu_ref; int vu_freq; void* pin; TYPE_1__* bufs; scalar_t__ fbuf_idx; scalar_t__ rbuf_idx; } ;
struct TYPE_20__ {TYPE_13__* drv; TYPE_5__ cfg; } ;
typedef  TYPE_4__ pud_t ;
typedef  int /*<<< orphan*/  os_param_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  TYPE_5__ cfg_t ;
struct TYPE_22__ {int cb_data_ref; int cb_drained_ref; int cb_paused_ref; int cb_stopped_ref; int cb_vu_ref; int self_ref; int isr_throttled; scalar_t__ rate; void* vu_freq; TYPE_2__* bufs; } ;
struct TYPE_19__ {int /*<<< orphan*/  (* stop ) (TYPE_9__*) ;int /*<<< orphan*/  (* close ) (TYPE_9__*) ;} ;
struct TYPE_18__ {void* empty; int /*<<< orphan*/ * data; } ;
struct TYPE_17__ {void* empty; scalar_t__ rpos; scalar_t__ len; int /*<<< orphan*/ * data; scalar_t__ buf_size; } ;
struct TYPE_16__ {int /*<<< orphan*/  (* init ) (TYPE_5__*) ;int /*<<< orphan*/  (* play ) (TYPE_5__*) ;int /*<<< orphan*/  (* stop ) (TYPE_5__*) ;} ;
struct TYPE_15__ {TYPE_3__* drv; } ;

/* Variables and functions */
 void* COND_REF (void*) ; 
 void* FALSE ; 
 int /*<<< orphan*/  GET_PUD () ; 
 int LUA_NOREF ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ LUA_TFUNCTION ; 
 scalar_t__ LUA_TLIGHTFUNCTION ; 
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,void*) ; 
 int PCM_DRIVER_END ; 
 int PCM_DRIVER_SD ; 
 scalar_t__ PCM_RATE_16K ; 
 scalar_t__ PCM_RATE_1K ; 
 int PCM_RATE_8K ; 
 void* TRUE ; 
 int /*<<< orphan*/  UNREF_CB (int) ; 
 int /*<<< orphan*/  c_free (int /*<<< orphan*/ *) ; 
 scalar_t__ c_strcmp (char const*,char*) ; 
 TYPE_9__* cfg ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int,int,char*) ; 
 void* luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaL_getmetatable (int /*<<< orphan*/ *,char*) ; 
 void* luaL_optinteger (int /*<<< orphan*/ *,int,int) ; 
 int luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_rometatable (int /*<<< orphan*/ *,char*,void*) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 scalar_t__ lua_newuserdata (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_setmetatable (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 
 void pcm_data_play (scalar_t__,int /*<<< orphan*/ ) ; 
 void* pcm_data_play_task ; 
 void pcm_data_vu (scalar_t__,int /*<<< orphan*/ ) ; 
 void* pcm_data_vu_task ; 
 scalar_t__ pcm_driver_map ; 
 TYPE_13__ pcm_drv_sd ; 
 void* pcm_start_play_task ; 
 TYPE_12__* pud ; 
 int /*<<< orphan*/  sigma_delta ; 
 int /*<<< orphan*/  stub1 (TYPE_9__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_9__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_9__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_5__*) ; 
 void* task_get_id (void (*) (scalar_t__,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  task_post_low (void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dispatch_callback( lua_State *L, int self_ref, int cb_ref, int returns )
{
  if (cb_ref != LUA_NOREF) {
    lua_rawgeti( L, LUA_REGISTRYINDEX, cb_ref );
    lua_rawgeti( L, LUA_REGISTRYINDEX, self_ref );
    lua_call( L, 1, returns );
  }
}

__attribute__((used)) static int pcm_drv_free( lua_State *L )
{
  GET_PUD();

  UNREF_CB( cfg->cb_data_ref );
  UNREF_CB( cfg->cb_drained_ref );
  UNREF_CB( cfg->cb_paused_ref );
  UNREF_CB( cfg->cb_stopped_ref );
  UNREF_CB( cfg->cb_vu_ref );
  UNREF_CB( cfg->self_ref );

  if (cfg->bufs[0].data) {
    c_free( cfg->bufs[0].data );
    cfg->bufs[0].data = NULL;
  }
  if (cfg->bufs[1].data) {
    c_free( cfg->bufs[1].data );
    cfg->bufs[1].data = NULL;
  }

  return 0;
}

__attribute__((used)) static int pcm_drv_close( lua_State *L )
{
  GET_PUD();

  pud->drv->close( cfg );

  return pcm_drv_free( L );
}

__attribute__((used)) static int pcm_drv_stop( lua_State *L )
{
  GET_PUD();

  // throttle ISR and reader
  cfg->isr_throttled = -1;

  pud->drv->stop( cfg );

  // invalidate the buffers
  cfg->bufs[0].empty = cfg->bufs[1].empty = TRUE;

  dispatch_callback( L, cfg->self_ref, cfg->cb_stopped_ref, 0 );

  return 0;
}

__attribute__((used)) static int pcm_drv_pause( lua_State *L )
{
  GET_PUD();

  // throttle ISR and reader
  cfg->isr_throttled = -1;

  pud->drv->stop( cfg );

  dispatch_callback( L, cfg->self_ref, cfg->cb_paused_ref, 0 );

  return 0;
}

__attribute__((used)) static void pcm_start_play( task_param_t param, uint8 prio )
{
  lua_State *L = lua_getstate();
  pud_t *pud = (pud_t *)param;
  cfg_t *cfg = &(pud->cfg);

  // stop driver before starting it in case it hasn't been stopped from Lua
  pud->drv->stop( cfg );

  if (!pud->drv->play( cfg )) {
      luaL_error( L, "pcm driver start" );
  }

  // unthrottle ISR and reader
  pud->cfg.isr_throttled = 0;
}

__attribute__((used)) static int pcm_drv_play( lua_State *L )
{
  GET_PUD();

  cfg->rate = luaL_optinteger( L, 2, PCM_RATE_8K );

  luaL_argcheck( L, (cfg->rate >= PCM_RATE_1K) && (cfg->rate <= PCM_RATE_16K), 2, "invalid bit rate" );

  if (cfg->self_ref == LUA_NOREF) {
    lua_pushvalue( L, 1 );  // copy self userdata to the top of stack
    cfg->self_ref = luaL_ref( L, LUA_REGISTRYINDEX );
  }

  // schedule actions for play in separate task since drv:play() might have been called
  // in the callback fn of pcm_data_play() which in turn gets called when starting play...
  task_post_low( pcm_start_play_task, (os_param_t)pud );

  return 0;
}

__attribute__((used)) static int pcm_drv_on( lua_State *L )
{
  size_t len;
  const char *event;
  uint8_t is_func = FALSE;

  GET_PUD();

  event = luaL_checklstring( L, 2, &len );

  if ((lua_type( L, 3 ) == LUA_TFUNCTION) ||
      (lua_type( L, 3 ) == LUA_TLIGHTFUNCTION)) {
    lua_pushvalue( L, 3 );  // copy argument (func) to the top of stack
    is_func = TRUE;
  }

  if ((len == 4) && (c_strcmp( event, "data" ) == 0)) {
    luaL_unref( L, LUA_REGISTRYINDEX, cfg->cb_data_ref);
    cfg->cb_data_ref = COND_REF( is_func );
  } else if ((len == 7) && (c_strcmp( event, "drained" ) == 0)) {
    luaL_unref( L, LUA_REGISTRYINDEX, cfg->cb_drained_ref);
    cfg->cb_drained_ref = COND_REF( is_func );
  } else if ((len == 6) && (c_strcmp( event, "paused" ) == 0)) {
    luaL_unref( L, LUA_REGISTRYINDEX, cfg->cb_paused_ref);
    cfg->cb_paused_ref = COND_REF( is_func );
  } else if ((len == 7) && (c_strcmp( event, "stopped" ) == 0)) {
    luaL_unref( L, LUA_REGISTRYINDEX, cfg->cb_stopped_ref);
    cfg->cb_stopped_ref = COND_REF( is_func );
  } else if ((len == 2) && (c_strcmp( event, "vu" ) == 0)) {
    luaL_unref( L, LUA_REGISTRYINDEX, cfg->cb_vu_ref);
    cfg->cb_vu_ref = COND_REF( is_func );

    int freq = luaL_optinteger( L, 4, 10 );
    luaL_argcheck( L, (freq > 0) && (freq <= 200), 4, "invalid range" );
    cfg->vu_freq = (uint8_t)freq;
  } else {
    if (is_func) {
      // need to pop pushed function arg
      lua_pop( L, 1 );
    }
    return luaL_error( L, "method not supported" );
  }

  return 0;
}

__attribute__((used)) static int pcm_new( lua_State *L )
{
  pud_t *pud = (pud_t *) lua_newuserdata( L, sizeof( pud_t ) );
  cfg_t *cfg = &(pud->cfg);
  int driver;

  cfg->rbuf_idx = cfg->fbuf_idx = 0;
  cfg->isr_throttled = -1;  // start ISR and reader in throttled mode

  driver = luaL_checkinteger( L, 1 );
  luaL_argcheck( L, (driver >= 0) && (driver < PCM_DRIVER_END), 1, "invalid driver" );

  cfg->self_ref      = LUA_NOREF;
  cfg->cb_data_ref   = cfg->cb_drained_ref = LUA_NOREF;
  cfg->cb_paused_ref = cfg->cb_stopped_ref = LUA_NOREF;
  cfg->cb_vu_ref     = LUA_NOREF;

  cfg->bufs[0].buf_size = cfg->bufs[1].buf_size = 0;
  cfg->bufs[0].data     = cfg->bufs[1].data     = NULL;
  cfg->bufs[0].len      = cfg->bufs[1].len      = 0;
  cfg->bufs[0].rpos     = cfg->bufs[1].rpos     = 0;
  cfg->bufs[0].empty    = cfg->bufs[1].empty    = TRUE;

  cfg->vu_freq         = 10;

  if (driver == PCM_DRIVER_SD) {
    cfg->pin = luaL_checkinteger( L, 2 );
    MOD_CHECK_ID(sigma_delta, cfg->pin);

    pud->drv = &pcm_drv_sd;

    pud->drv->init( cfg );

    /* set its metatable */
    lua_pushvalue( L, -1 );  // copy self userdata to the top of stack
    luaL_getmetatable( L, "pcm.driver" );
    lua_setmetatable( L, -2 );

    return 1;
  } else {
    pud->drv = NULL;
    return 0;
  }
}

int luaopen_pcm( lua_State *L ) {
  luaL_rometatable( L, "pcm.driver", (void *)pcm_driver_map );  // create metatable

  pcm_data_vu_task    = task_get_id( pcm_data_vu );
  pcm_data_play_task  = task_get_id( pcm_data_play );
  pcm_start_play_task = task_get_id( pcm_start_play );
  return 0;
}

