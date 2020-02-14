#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint8 ;
typedef  int uint64_t ;
typedef  scalar_t__ uint64 ;
typedef  unsigned int uint32_t ;
typedef  scalar_t__ task_param_t ;
struct rst_info {unsigned int reason; unsigned int exccause; unsigned int epc1; unsigned int epc2; unsigned int epc3; unsigned int excvaddr; unsigned int depc; } ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int lua_Number ;
struct TYPE_3__ {unsigned int totalbytes; unsigned int estimate; } ;
typedef  TYPE_1__ global_State ;
typedef  int /*<<< orphan*/  Proto ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 unsigned int CPU160MHZ ; 
 unsigned int CPU80MHZ ; 
 unsigned int EGC_ALWAYS ; 
 unsigned int EGC_ON_ALLOC_FAILURE ; 
 unsigned int EGC_ON_MEM_LIMIT ; 
 int FS_OBJ_NAME_LEN ; 
 TYPE_1__* G (int /*<<< orphan*/ *) ; 
 int LUA_ERR_CC_INTOVERFLOW ; 
 int LUA_ERR_CC_NOTINTEGER ; 
 scalar_t__ LUA_NOREF ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 int LUA_TFUNCTION ; 
 int LUA_TLIGHTFUNCTION ; 
 int LUA_TNUMBER ; 
 int /*<<< orphan*/  NODE_DBG (char*,...) ; 
 unsigned int NODE_VERSION_MAJOR ; 
 unsigned int NODE_VERSION_MINOR ; 
 unsigned int NODE_VERSION_REVISION ; 
 scalar_t__ REASON_EXCEPTION_RST ; 
 int /*<<< orphan*/  REG_CLR_BIT (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET_BIT (int,int /*<<< orphan*/ ) ; 
 unsigned int TASK_PRIORITY_HIGH ; 
 unsigned int TASK_PRIORITY_MEDIUM ; 
 int /*<<< orphan*/  UNUSED (int /*<<< orphan*/ *) ; 
 scalar_t__ VFS_RES_OK ; 
 scalar_t__ c_strcmp (char*,char*) ; 
 int /*<<< orphan*/  c_strcpy (char*,char const*) ; 
 int c_strlen (char const*) ; 
 int /*<<< orphan*/  dbg_printf (char*) ; 
 scalar_t__ do_node_task_handle ; 
 unsigned int ets_get_cpu_frequency () ; 
 int /*<<< orphan*/  ets_update_cpu_frequency (unsigned int) ; 
 unsigned int flash_rom_get_mode () ; 
 int flash_rom_get_size_byte () ; 
 unsigned int flash_rom_get_speed () ; 
 int /*<<< orphan*/  flash_rom_set_size_byte (unsigned int) ; 
 int /*<<< orphan*/  legc_set_mode (int /*<<< orphan*/ *,unsigned int,int) ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int,int,char*) ; 
 int luaL_checkint (int /*<<< orphan*/ *,int) ; 
 unsigned int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 scalar_t__ luaL_checknumber (int /*<<< orphan*/ *,int) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ luaL_loadfsfile (int /*<<< orphan*/ *,char const*) ; 
 int luaL_optinteger (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  luaM_free (int /*<<< orphan*/ *,char*) ; 
 char* luaM_malloc (int /*<<< orphan*/ *,size_t) ; 
 int luaU_dump (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,void const*,size_t,void*),int*,int) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_isnumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_put_line (char const*,size_t) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ lua_toboolean (int /*<<< orphan*/ *,int) ; 
 void* lua_tointeger (int /*<<< orphan*/ *,int) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 int lua_type (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_unlock (int /*<<< orphan*/ *) ; 
 int os_random () ; 
 scalar_t__ output_redir_ref ; 
 unsigned int rtc_get_reset_reason () ; 
 int serial_debug ; 
 unsigned int spi_flash_get_id () ; 
 int /*<<< orphan*/  system_deep_sleep (scalar_t__) ; 
 int /*<<< orphan*/  system_deep_sleep_instant (scalar_t__) ; 
 int /*<<< orphan*/  system_deep_sleep_set_option (int) ; 
 unsigned int system_get_chip_id () ; 
 unsigned int system_get_cpu_freq () ; 
 unsigned int system_get_free_heap_size () ; 
 struct rst_info* system_get_rst_info () ; 
 int /*<<< orphan*/  system_restart () ; 
 int /*<<< orphan*/  system_restore () ; 
 scalar_t__ system_rtc_clock_cali_proc () ; 
 int /*<<< orphan*/  system_set_os_print (int) ; 
 scalar_t__ task_get_id (void (*) (scalar_t__,unsigned int)) ; 
 int /*<<< orphan*/  task_post (unsigned int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/ * toproto (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uart0_sendStr (char const*) ; 
 int /*<<< orphan*/  user_process_input (int) ; 
 char* vfs_basename (char const*) ; 
 int /*<<< orphan*/  vfs_close (int) ; 
 scalar_t__ vfs_flush (int) ; 
 int vfs_open (char*,char*) ; 
 size_t vfs_write (int,char const*,size_t) ; 

__attribute__((used)) static int node_restart( lua_State* L )
{
  system_restart();
  return 0;
}

__attribute__((used)) static int dsleepMax( lua_State *L ) {
  lua_pushnumber(L, (uint64_t)system_rtc_clock_cali_proc()*(0x80000000-1)/(0x1000));
  return 1;
}

__attribute__((used)) static int node_deepsleep( lua_State* L )
{
  uint64 us;
  uint8 option;
  //us = luaL_checkinteger( L, 1 );
  // Set deleep option, skip if nil
  if ( lua_isnumber(L, 2) )
  {
    option = lua_tointeger(L, 2);
    if ( option < 0 || option > 4)
      return luaL_error( L, "wrong arg range" );
    else
      system_deep_sleep_set_option( option );
  }
  bool instant = false;
  if (lua_isnumber(L, 3))
    instant = lua_tointeger(L, 3);
  // Set deleep time, skip if nil
  if ( lua_isnumber(L, 1) )
  {
    us = luaL_checknumber(L, 1);
    // if ( us <= 0 )
    if ( us < 0 )
      return luaL_error( L, "wrong arg range" );
    else
    {
      if (instant)
        system_deep_sleep_instant(us);
      else
        system_deep_sleep( us );
    }
  }
  return 0;
}

__attribute__((used)) static int node_sleep( lua_State* L )
{
  dbg_printf("\n The options \"TIMER_SUSPEND_ENABLE\" and \"PMSLEEP_ENABLE\" in \"app/include/user_config.h\" were disabled during FW build!\n");
  return luaL_error(L, "node.sleep() is unavailable");
}

__attribute__((used)) static int node_info( lua_State* L )
{
  lua_pushinteger(L, NODE_VERSION_MAJOR);
  lua_pushinteger(L, NODE_VERSION_MINOR);
  lua_pushinteger(L, NODE_VERSION_REVISION);
  lua_pushinteger(L, system_get_chip_id());   // chip id
  lua_pushinteger(L, spi_flash_get_id());     // flash id
  lua_pushinteger(L, flash_rom_get_size_byte() / 1024);  // flash size in KB
  lua_pushinteger(L, flash_rom_get_mode());
  lua_pushinteger(L, flash_rom_get_speed());
  return 8;
}

__attribute__((used)) static int node_chipid( lua_State* L )
{
  uint32_t id = system_get_chip_id();
  lua_pushinteger(L, id);
  return 1;
}

__attribute__((used)) static int node_flashid( lua_State* L )
{
  uint32_t id = spi_flash_get_id();
  lua_pushinteger( L, id );
  return 1;
}

__attribute__((used)) static int node_flashsize( lua_State* L )
{
  if (lua_type(L, 1) == LUA_TNUMBER)
  {
    flash_rom_set_size_byte(luaL_checkinteger(L, 1));
  }
  uint32_t sz = flash_rom_get_size_byte();
  lua_pushinteger( L, sz );
  return 1;
}

__attribute__((used)) static int node_heap( lua_State* L )
{
  uint32_t sz = system_get_free_heap_size();
  lua_pushinteger(L, sz);
  return 1;
}

__attribute__((used)) static int node_input( lua_State* L ) {
  size_t l = 0;
  const char *s = luaL_checklstring(L, 1, &l);
  if (lua_put_line(s, l)) {
    NODE_DBG("Result (if any):\n");
    user_process_input(true);
  }
  return 0;
}

void output_redirect(const char *str) {
  lua_State *L = lua_getstate();
  // if(c_strlen(str)>=TX_BUFF_SIZE){
  //   NODE_ERR("output too long.\n");
  //   return;
  // }

  if (output_redir_ref == LUA_NOREF) {
    uart0_sendStr(str);
    return;
  }

  if (serial_debug != 0) {
    uart0_sendStr(str);
  }

  lua_rawgeti(L, LUA_REGISTRYINDEX, output_redir_ref);
  lua_pushstring(L, str);
  lua_call(L, 1, 0);   // this call back function should never user output.
}

__attribute__((used)) static int node_output( lua_State* L )
{
  // luaL_checkanyfunction(L, 1);
  if (lua_type(L, 1) == LUA_TFUNCTION || lua_type(L, 1) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, 1);  // copy argument (func) to the top of stack
    if (output_redir_ref != LUA_NOREF)
      luaL_unref(L, LUA_REGISTRYINDEX, output_redir_ref);
    output_redir_ref = luaL_ref(L, LUA_REGISTRYINDEX);
  } else {    // unref the key press function
    if (output_redir_ref != LUA_NOREF)
      luaL_unref(L, LUA_REGISTRYINDEX, output_redir_ref);
    output_redir_ref = LUA_NOREF;
    serial_debug = 1;
    return 0;
  }

  if ( lua_isnumber(L, 2) )
  {
    serial_debug = lua_tointeger(L, 2);
    if (serial_debug != 0)
      serial_debug = 1;
  } else {
    serial_debug = 1; // default to 1
  }

  return 0;
}

__attribute__((used)) static int writer(lua_State* L, const void* p, size_t size, void* u)
{
  UNUSED(L);
  int file_fd = *( (int *)u );
  if (!file_fd)
    return 1;
  NODE_DBG("get fd:%d,size:%d\n", file_fd, size);

  if (size != 0 && (size != vfs_write(file_fd, (const char *)p, size)) )
    return 1;
  NODE_DBG("write fd:%d,size:%d\n", file_fd, size);
  return 0;
}

__attribute__((used)) static int node_compile( lua_State* L )
{
  Proto* f;
  int file_fd = 0;
  size_t len;
  const char *fname = luaL_checklstring( L, 1, &len );
  const char *basename = vfs_basename( fname );
  luaL_argcheck(L, c_strlen(basename) <= FS_OBJ_NAME_LEN && c_strlen(fname) == len, 1, "filename invalid");

  char *output = luaM_malloc( L, len+1 );
  c_strcpy(output, fname);
  // check here that filename end with ".lua".
  if (len < 4 || (c_strcmp( output + len - 4, ".lua") != 0) ) {
    luaM_free( L, output );
    return luaL_error(L, "not a .lua file");
  }

  output[c_strlen(output) - 2] = 'c';
  output[c_strlen(output) - 1] = '\0';
  NODE_DBG(output);
  NODE_DBG("\n");
  if (luaL_loadfsfile(L, fname) != 0) {
    luaM_free( L, output );
    return luaL_error(L, lua_tostring(L, -1));
  }

  f = toproto(L, -1);

  int stripping = 1;      /* strip debug information? */

  file_fd = vfs_open(output, "w+");
  if (!file_fd)
  {
    luaM_free( L, output );
    return luaL_error(L, "cannot open/write to file");
  }

  lua_lock(L);
  int result = luaU_dump(L, f, writer, &file_fd, stripping);
  lua_unlock(L);

  if (vfs_flush(file_fd) != VFS_RES_OK) {
    // overwrite Lua error, like writer() does in case of a file io error
    result = 1;
  }
  vfs_close(file_fd);
  file_fd = 0;
  luaM_free( L, output );

  if (result == LUA_ERR_CC_INTOVERFLOW) {
    return luaL_error(L, "value too big or small for target integer type");
  }
  if (result == LUA_ERR_CC_NOTINTEGER) {
    return luaL_error(L, "target lua_Number is integral but fractional value found");
  }
  if (result == 1) {    // result status generated by writer() or fs_flush() fail
    return luaL_error(L, "writing to file failed");
  }

  return 0;
}

__attribute__((used)) static void do_node_task (task_param_t task_fn_ref, uint8_t prio)
{
  lua_State* L = lua_getstate();
  lua_rawgeti(L, LUA_REGISTRYINDEX, (int)task_fn_ref);
  luaL_unref(L, LUA_REGISTRYINDEX, (int)task_fn_ref);
  lua_pushinteger(L, prio);
  lua_call(L, 1, 0);
}

__attribute__((used)) static int node_task_post( lua_State* L )
{
  int n = 1, Ltype = lua_type(L, 1);
  unsigned priority = TASK_PRIORITY_MEDIUM;
  if (Ltype == LUA_TNUMBER) {
    priority = (unsigned) luaL_checkint(L, 1);
    luaL_argcheck(L, priority <= TASK_PRIORITY_HIGH, 1, "invalid  priority");
    Ltype = lua_type(L, ++n);
  }
  luaL_argcheck(L, Ltype == LUA_TFUNCTION || Ltype == LUA_TLIGHTFUNCTION, n, "invalid function");
  lua_pushvalue(L, n);

  int task_fn_ref = luaL_ref(L, LUA_REGISTRYINDEX);

  if (!do_node_task_handle)  // bind the task handle to do_node_task on 1st call
    do_node_task_handle = task_get_id(do_node_task);

  if(!task_post(priority, do_node_task_handle, (task_param_t)task_fn_ref)) {
    luaL_unref(L, LUA_REGISTRYINDEX, task_fn_ref);
    luaL_error(L, "Task queue overflow. Task not posted");
  }
  return 0;
}

__attribute__((used)) static int node_setcpufreq(lua_State* L)
{
  // http://www.esp8266.com/viewtopic.php?f=21&t=1369
  uint32_t new_freq = luaL_checkinteger(L, 1);
  if (new_freq == CPU160MHZ){
    REG_SET_BIT(0x3ff00014, BIT(0));
    ets_update_cpu_frequency(CPU160MHZ);
  } else {
    REG_CLR_BIT(0x3ff00014,  BIT(0));
    ets_update_cpu_frequency(CPU80MHZ);
  }
  new_freq = ets_get_cpu_frequency();
  lua_pushinteger(L, new_freq);
  return 1;
}

__attribute__((used)) static int node_getcpufreq(lua_State* L)
{
  lua_pushinteger(L, system_get_cpu_freq());
  return 1;
}

__attribute__((used)) static int node_bootreason (lua_State *L)
{
  const struct rst_info *ri = system_get_rst_info ();
  uint32_t arr[8] = {
    rtc_get_reset_reason(),
    ri->reason,
    ri->exccause, ri->epc1, ri->epc2, ri->epc3, ri->excvaddr, ri->depc
  };
  int i, n = ((ri->reason != REASON_EXCEPTION_RST) ? 2 : 8);
  for (i = 0; i < n; ++i)
    lua_pushinteger (L, arr[i]);
  return n;
}

__attribute__((used)) static int node_restore (lua_State *L)
{
  system_restore();
  return 0;
}

__attribute__((used)) static int node_egc_setmode(lua_State* L) {
  unsigned mode  = luaL_checkinteger(L, 1);
  int limit = luaL_optinteger (L, 2, 0);

  luaL_argcheck(L, mode <= (EGC_ON_ALLOC_FAILURE | EGC_ON_MEM_LIMIT | EGC_ALWAYS), 1, "invalid mode");
  luaL_argcheck(L, !(mode & EGC_ON_MEM_LIMIT) || limit!=0, 1, "limit must be non-zero");

  legc_set_mode( L, mode, limit );
  return 0;
}

__attribute__((used)) static int node_egc_meminfo(lua_State *L) {
  global_State *g = G(L);
  lua_pushinteger(L, g->totalbytes);
  lua_pushinteger(L, g->estimate);
  return 2;
}

__attribute__((used)) static int node_osprint( lua_State* L )
{
  if (lua_toboolean(L, 1)) {
    system_set_os_print(1);
  } else {
    system_set_os_print(0);
  }

  return 0;
}

int node_random_range(int l, int u) {
  // The range is the number of different values to return
  unsigned int range = u + 1 - l;

  // If this is very large then use simpler code
  if (range >= 0x7fffffff) {
    unsigned int v;

    // This cannot loop more than half the time
    while ((v = os_random()) >= range) {
    }

    // Now v is in the range [0, range)
    return v + l;
  }

  // Easy case, with only one value, we know the result
  if (range == 1) {
    return l;
  }

  // Another easy case -- uniform 32-bit
  if (range == 0) {
    return os_random();
  }

  // Now we have to figure out what a large multiple of range is
  // that just fits into 32 bits.
  // The limit will be less than 1 << 32 by some amount (not much)
  uint32_t limit = ((0x80000000 / ((range + 1) >> 1)) - 1) * range;

  uint32_t v;

  while ((v = os_random()) >= limit) {
  }

  // Now v is uniformly distributed in [0, limit) and limit is a multiple of range

  return (v % range) + l;
}

__attribute__((used)) static int node_random (lua_State *L) {
  int u;
  int l;

  switch (lua_gettop(L)) {  /* check number of arguments */
    case 0: {  /* no arguments */
#ifdef LUA_NUMBER_INTEGRAL
      lua_pushnumber(L, 0);  /* Number between 0 and 1 - always 0 with ints */
#else
      lua_pushnumber(L, (lua_Number)os_random() / (lua_Number)(1LL << 32));
#endif
      return 1;
    }
    case 1: {  /* only upper limit */
      l = 1;
      u = luaL_checkint(L, 1);
      break;
    }
    case 2: {  /* lower and upper limits */
      l = luaL_checkint(L, 1);
      u = luaL_checkint(L, 2);
      break;
    }
    default:
      return luaL_error(L, "wrong number of arguments");
  }
  luaL_argcheck(L, l<=u, 2, "interval is empty");
  lua_pushnumber(L, node_random_range(l, u));  /* int between `l' and `u' */
  return 1;
}

