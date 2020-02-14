#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint8_t ;
typedef  int /*<<< orphan*/  uint8 ;
typedef  scalar_t__ task_param_t ;
struct TYPE_3__ {size_t buf_size; size_t* data; size_t len; void* empty; scalar_t__ rpos; } ;
typedef  TYPE_1__ pcm_buf_t ;
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_4__ {int cb_vu_ref; int self_ref; size_t fbuf_idx; int isr_throttled; int cb_data_ref; int cb_drained_ref; TYPE_1__* bufs; scalar_t__ vu_peak; } ;
typedef  TYPE_2__ cfg_t ;
typedef  int /*<<< orphan*/  LUA_NUMBER ;

/* Variables and functions */
 void* FALSE ; 
 int LUA_NOREF ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ LUA_TSTRING ; 
 int /*<<< orphan*/  PLATFORM_GPIO_HIGH ; 
 int /*<<< orphan*/  PLATFORM_GPIO_LOW ; 
 size_t TRUE ; 
 int /*<<< orphan*/  c_free (size_t*) ; 
 scalar_t__ c_malloc (size_t) ; 
 int /*<<< orphan*/  c_memcpy (size_t*,char const*,size_t) ; 
 int /*<<< orphan*/  dbg_platform_gpio_write (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 char* lua_tolstring (int /*<<< orphan*/ *,int,size_t*) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void dispatch_callback( lua_State *L, int self_ref, int cb_ref, int returns )
{
  if (cb_ref != LUA_NOREF) {
    lua_rawgeti( L, LUA_REGISTRYINDEX, cb_ref );
    lua_rawgeti( L, LUA_REGISTRYINDEX, self_ref );
    lua_call( L, 1, returns );
  }
}

void pcm_data_vu( task_param_t param, uint8 prio )
{
  cfg_t *cfg = (cfg_t *)param;
  lua_State *L = lua_getstate();

  if (cfg->cb_vu_ref != LUA_NOREF) {
    lua_rawgeti( L, LUA_REGISTRYINDEX, cfg->cb_vu_ref );
    lua_rawgeti( L, LUA_REGISTRYINDEX, cfg->self_ref );
    lua_pushnumber( L, (LUA_NUMBER)(cfg->vu_peak) );
    lua_call( L, 2, 0 );
  }
}

void pcm_data_play( task_param_t param, uint8 prio )
{
  cfg_t *cfg = (cfg_t *)param;
  pcm_buf_t *buf = &(cfg->bufs[cfg->fbuf_idx]);
  size_t string_len;
  const char *data = NULL;
  uint8_t need_pop = FALSE;
  lua_State *L = lua_getstate();

  // retrieve new data from callback
  if ((cfg->isr_throttled >= 0) &&
      (cfg->cb_data_ref != LUA_NOREF)) {
    dispatch_callback( L, cfg->self_ref, cfg->cb_data_ref, 1 );
    need_pop = TRUE;

    if (lua_type( L, -1 ) == LUA_TSTRING) {
      data = lua_tolstring( L, -1, &string_len );
      if (string_len > buf->buf_size) {
        uint8_t *new_data = (uint8_t *) c_malloc( string_len );
        if (new_data) {
          if (buf->data) c_free( buf->data );
          buf->buf_size = string_len;
          buf->data = new_data;
        }
      }
    }
  }

  if (data) {
    size_t to_copy = string_len > buf->buf_size ? buf->buf_size : string_len;
    c_memcpy( buf->data, data, to_copy );

    buf->rpos  = 0;
    buf->len   = to_copy;
    buf->empty = FALSE;
    dbg_platform_gpio_write( PLATFORM_GPIO_HIGH );
    lua_pop( L, 1 );

    if (cfg->isr_throttled > 0) {
      uint8_t other_buf = cfg->fbuf_idx ^ 1;

      if (cfg->bufs[other_buf].empty) {
        // rerun data callback to get next buffer chunk
        dbg_platform_gpio_write( PLATFORM_GPIO_LOW );
        cfg->fbuf_idx = other_buf;
        pcm_data_play( param, 0 );
      }
      // unthrottle ISR
      cfg->isr_throttled = 0;
    }
  } else {
    dbg_platform_gpio_write( PLATFORM_GPIO_HIGH );
    if (need_pop) lua_pop( L, 1 );

    if (cfg->isr_throttled > 0) {
      // ISR found no further data
      // this was the last invocation of the reader task, fire drained cb

      cfg->isr_throttled = -1;

      dispatch_callback( L, cfg->self_ref, cfg->cb_drained_ref, 0 );
    }
  }

}

