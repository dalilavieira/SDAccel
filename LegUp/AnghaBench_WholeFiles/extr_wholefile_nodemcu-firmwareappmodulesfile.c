#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/ * vol; } ;
typedef  TYPE_2__ volume_type ;
struct TYPE_11__ {void* sec; void* min; void* hour; void* day; void* mon; void* year; } ;
typedef  TYPE_3__ vfs_time ;
typedef  int /*<<< orphan*/  vfs_dir ;
typedef  int uint32_t ;
typedef  int u32_t ;
struct TYPE_9__ {int year; int mon; int day; int hour; int min; int sec; } ;
struct vfs_stat {char* name; int size; int is_dir; int is_rdonly; int is_hidden; int is_sys; int is_arch; TYPE_1__ tm; scalar_t__ tm_valid; } ;
typedef  int sint32_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int int16_t ;
struct TYPE_12__ {int fd; } ;
typedef  TYPE_4__ file_fd_ud ;

/* Variables and functions */
 int EOF ; 
 int FALSE ; 
 void* FILE_READ_CHUNK ; 
 int FILE_TIMEDEF_DAY ; 
 int FILE_TIMEDEF_HOUR ; 
 int FILE_TIMEDEF_MIN ; 
 int FILE_TIMEDEF_MON ; 
 int FILE_TIMEDEF_SEC ; 
 int FILE_TIMEDEF_YEAR ; 
 size_t FS_OBJ_NAME_LEN ; 
 int /*<<< orphan*/  GET_FILE_OBJ ; 
 int LUAL_BUFFERSIZE ; 
 scalar_t__ LUA_NOREF ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ LUA_TFUNCTION ; 
 scalar_t__ LUA_TLIGHTFUNCTION ; 
 scalar_t__ LUA_TNUMBER ; 
 scalar_t__ LUA_TTABLE ; 
 scalar_t__ LUA_TUSERDATA ; 
 int /*<<< orphan*/  NODE_DBG (char*,int,int) ; 
 int /*<<< orphan*/  NODE_ERR (char*) ; 
 int VFS_RES_ERR ; 
 scalar_t__ VFS_RES_OK ; 
#define  VFS_SEEK_CUR 130 
#define  VFS_SEEK_END 129 
#define  VFS_SEEK_SET 128 
 char* alloca (int) ; 
 int argpos ; 
 size_t c_strlen (char const*) ; 
 int fd ; 
 int file_fd ; 
 scalar_t__ file_fd_ref ; 
 scalar_t__ file_obj_map ; 
 scalar_t__ file_vol_map ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,...) ; 
 scalar_t__ luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int luaL_checkoption (int /*<<< orphan*/ *,int,char*,char const* const*) ; 
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 TYPE_2__* luaL_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaL_getmetafield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaL_getmetatable (int /*<<< orphan*/ *,char*) ; 
 void* luaL_optint (int /*<<< orphan*/ *,int,int) ; 
 long luaL_optlong (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 char* luaL_optstring (int /*<<< orphan*/ *,int,char*) ; 
 scalar_t__ luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_rometatable (int /*<<< orphan*/ *,char*,void*) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  luaM_free (int /*<<< orphan*/ *,char*) ; 
 char* luaM_malloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_createtable (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_error (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_getfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_isnil (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_isstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_newtable (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_newuserdata (int /*<<< orphan*/ *,int) ; 
 int lua_pcall (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  lua_pushnil (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_setmetatable (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_settop (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 
 scalar_t__ rtc_cb_ref ; 
 char* vfs_basename (char const*) ; 
 scalar_t__ vfs_chdir (char const*) ; 
 int /*<<< orphan*/  vfs_close (int) ; 
 int /*<<< orphan*/  vfs_closedir (int /*<<< orphan*/ *) ; 
 scalar_t__ vfs_flush (int) ; 
 int /*<<< orphan*/  vfs_format () ; 
 int /*<<< orphan*/  vfs_fscfg (char*,int*,int*) ; 
 scalar_t__ vfs_fsinfo (char*,int*,int*) ; 
 int vfs_lseek (int,int,int const) ; 
 int /*<<< orphan*/ * vfs_mount (char const*,int) ; 
 int vfs_open (char const*,char const*) ; 
 int /*<<< orphan*/ * vfs_opendir (char*) ; 
 int vfs_read (int,char*,int) ; 
 scalar_t__ vfs_readdir (int /*<<< orphan*/ *,struct vfs_stat*) ; 
 int /*<<< orphan*/  vfs_register_rtc_cb (int (*) (TYPE_3__*)) ; 
 int /*<<< orphan*/  vfs_remove (char*) ; 
 scalar_t__ vfs_rename (char const*,char const*) ; 
 scalar_t__ vfs_stat (char*,struct vfs_stat*) ; 
 int vfs_tell (int) ; 
 scalar_t__ vfs_umount (int /*<<< orphan*/ *) ; 
 size_t vfs_write (int,char const*,int) ; 

__attribute__((used)) static void table2tm( lua_State *L, vfs_time *tm )
{
  int idx = lua_gettop( L );

  // extract items from table
  lua_getfield( L, idx, "year" );
  lua_getfield( L, idx, "mon" );
  lua_getfield( L, idx, "day" );
  lua_getfield( L, idx, "hour" );
  lua_getfield( L, idx, "min" );
  lua_getfield( L, idx, "sec" );

  tm->year = luaL_optint( L, ++idx, FILE_TIMEDEF_YEAR );
  tm->mon  = luaL_optint( L, ++idx, FILE_TIMEDEF_MON );
  tm->day  = luaL_optint( L, ++idx, FILE_TIMEDEF_DAY );
  tm->hour = luaL_optint( L, ++idx, FILE_TIMEDEF_HOUR );
  tm->min  = luaL_optint( L, ++idx, FILE_TIMEDEF_MIN );
  tm->sec  = luaL_optint( L, ++idx, FILE_TIMEDEF_SEC );

  // remove items from stack
  lua_pop( L, 6 );
}

__attribute__((used)) static sint32_t file_rtc_cb( vfs_time *tm )
{
  sint32_t res = VFS_RES_ERR;

  if (rtc_cb_ref != LUA_NOREF) {
    lua_State *L = lua_getstate();

    lua_rawgeti( L, LUA_REGISTRYINDEX, rtc_cb_ref );
    lua_call( L, 0, 1 );

    if (lua_type( L, lua_gettop( L ) ) == LUA_TTABLE) {
      table2tm( L, tm );
      res = VFS_RES_OK;
    }

    // pop item returned by callback
    lua_pop( L, 1 );
  }

  return res;
}

__attribute__((used)) static int file_on(lua_State *L)
{
  enum events{
    ON_RTC = 0
  };
  const char *const eventnames[] = {"rtc", NULL};

  int event = luaL_checkoption(L, 1, "rtc", eventnames);

  switch (event) {
  case ON_RTC:
    luaL_unref(L, LUA_REGISTRYINDEX, rtc_cb_ref);

    if ((lua_type(L, 2) == LUA_TFUNCTION) ||
        (lua_type(L, 2) == LUA_TLIGHTFUNCTION)) {
      lua_pushvalue(L, 2);  // copy argument (func) to the top of stack
      rtc_cb_ref = luaL_ref(L, LUA_REGISTRYINDEX);
      vfs_register_rtc_cb(file_rtc_cb);
    } else {
      rtc_cb_ref = LUA_NOREF;
      vfs_register_rtc_cb(NULL);
    }
    break;
  default:
    break;
  }

  return 0;
}

__attribute__((used)) static int file_close( lua_State* L )
{
  int need_pop = FALSE;
  file_fd_ud *ud;

  if (lua_type( L, 1 ) != LUA_TUSERDATA) {
    // fall back to last opened file
    if (file_fd_ref != LUA_NOREF) {
      lua_rawgeti( L, LUA_REGISTRYINDEX, file_fd_ref );
      // top of stack is now default file descriptor
      ud = (file_fd_ud *)luaL_checkudata(L, -1, "file.obj");
      lua_pop( L, 1 );
    } else {
      // no default file currently opened
      return 0;
    }
  } else {
    ud = (file_fd_ud *)luaL_checkudata(L, 1, "file.obj");
  }

  // unref default file descriptor
  luaL_unref( L, LUA_REGISTRYINDEX, file_fd_ref );
  file_fd_ref = LUA_NOREF;

  if(ud->fd){
      vfs_close(ud->fd);
      // mark as closed
      ud->fd = 0;
  }
  return 0;
}

__attribute__((used)) static int file_obj_free( lua_State *L )
{
  file_fd_ud *ud = (file_fd_ud *)luaL_checkudata(L, 1, "file.obj");
  if (ud->fd) {
    // close file if it's still open
    vfs_close(ud->fd);
    ud->fd = 0;
  }

  return 0;
}

__attribute__((used)) static int file_format( lua_State* L )
{
  size_t len;
  file_close(L);
  if( !vfs_format() )
  {
    NODE_ERR( "\n*** ERROR ***: unable to format. FS might be compromised.\n" );
    NODE_ERR( "It is advised to re-flash the NodeMCU image.\n" );
    luaL_error(L, "Failed to format file system");
  }
  else{
    NODE_ERR( "format done.\n" );
  }
  return 0;
}

__attribute__((used)) static int file_fscfg (lua_State *L)
{
  uint32_t phys_addr, phys_size;

  vfs_fscfg("/FLASH", &phys_addr, &phys_size);

  lua_pushinteger (L, phys_addr);
  lua_pushinteger (L, phys_size);
  return 2;
}

__attribute__((used)) static int file_open( lua_State* L )
{
  size_t len;

  // unref last file descriptor to allow gc'ing if not kept by user script
  luaL_unref( L, LUA_REGISTRYINDEX, file_fd_ref );
  file_fd_ref = LUA_NOREF;

  const char *fname = luaL_checklstring( L, 1, &len );
  const char *basename = vfs_basename( fname );
  luaL_argcheck(L, c_strlen(basename) <= FS_OBJ_NAME_LEN && c_strlen(fname) == len, 1, "filename invalid");

  const char *mode = luaL_optstring(L, 2, "r");

  file_fd = vfs_open(fname, mode);

  if(!file_fd){
    lua_pushnil(L);
  } else {
    file_fd_ud *ud = (file_fd_ud *) lua_newuserdata( L, sizeof( file_fd_ud ) );
    ud->fd = file_fd;
    luaL_getmetatable( L, "file.obj" );
    lua_setmetatable( L, -2 );

    // store reference to opened file
    lua_pushvalue( L, -1 );
    file_fd_ref = luaL_ref( L, LUA_REGISTRYINDEX );
  }
  return 1;
}

__attribute__((used)) static int file_list( lua_State* L )
{
  vfs_dir  *dir;
  const char *pattern;
  struct vfs_stat stat;
  int pcres;

  lua_settop(L, 1);
  pattern = luaL_optstring(L, 1, NULL);   /* Pattern (arg) or nil (not) at 1 */

  dir = vfs_opendir("");
  if (dir == NULL) {
    return 0;
  }

  lua_newtable( L );                      /* Table at 2 */

  if (pattern) {
    /*
     * We know that pattern is a string, and so the "match" method will always
     * exist.  No need to check return value here
     */
    luaL_getmetafield( L, 1, "match" );  /* Function at 3 */
  }

  while (vfs_readdir(dir, &stat) == VFS_RES_OK) {
    if (pattern) {
      lua_settop( L, 3 );                 /* Ensure nothing else on stack */

      /* Construct and pcall(string.match,name,pattern) */
      lua_pushvalue( L, 3 );
      lua_pushstring( L, stat.name );
      lua_pushvalue( L, 1 );
      pcres = lua_pcall( L, 2, 1, 0 );
      if (pcres != 0) {
        vfs_closedir(dir);
        lua_error( L );
      }
      if (lua_isnil( L, -1 )) {
        continue;
      }
    }
    lua_pushinteger( L, stat.size );
    lua_setfield( L, 2, stat.name );
  }

  /* Shed everything back to Table */
  lua_settop( L, 2 );
  vfs_closedir(dir);
  return 1;
}

__attribute__((used)) static int get_file_obj( lua_State *L, int *argpos )
{
  if (lua_type( L, 1 ) == LUA_TUSERDATA) {
    file_fd_ud *ud = (file_fd_ud *)luaL_checkudata(L, 1, "file.obj");
    *argpos = 2;
    return ud->fd;
  } else {
    *argpos = 1;
    return file_fd;
  }
}

__attribute__((used)) static int file_seek (lua_State *L)
{
  GET_FILE_OBJ;

  static const int mode[] = {VFS_SEEK_SET, VFS_SEEK_CUR, VFS_SEEK_END};
  static const char *const modenames[] = {"set", "cur", "end", NULL};
  if(!fd)
    return luaL_error(L, "open a file first");
  int op = luaL_checkoption(L, argpos, "cur", modenames);
  long offset = luaL_optlong(L, ++argpos, 0);
  op = vfs_lseek(fd, offset, mode[op]);
  if (op < 0)
    lua_pushnil(L);  /* error */
  else
    lua_pushinteger(L, vfs_tell(fd));
  return 1;
}

__attribute__((used)) static int file_exists( lua_State* L )
{
  size_t len;
  const char *fname = luaL_checklstring( L, 1, &len );
  const char *basename = vfs_basename( fname );
  luaL_argcheck(L, c_strlen(basename) <= FS_OBJ_NAME_LEN && c_strlen(fname) == len, 1, "filename invalid");

  struct vfs_stat stat;
  lua_pushboolean(L, vfs_stat((char *)fname, &stat) == VFS_RES_OK ? 1 : 0);

  return 1;
}

__attribute__((used)) static int file_remove( lua_State* L )
{
  size_t len;
  const char *fname = luaL_checklstring( L, 1, &len );
  const char *basename = vfs_basename( fname );
  luaL_argcheck(L, c_strlen(basename) <= FS_OBJ_NAME_LEN && c_strlen(fname) == len, 1, "filename invalid");
  vfs_remove((char *)fname);
  return 0;
}

__attribute__((used)) static int file_flush( lua_State* L )
{
  GET_FILE_OBJ;

  if(!fd)
    return luaL_error(L, "open a file first");
  if(vfs_flush(fd) == 0)
    lua_pushboolean(L, 1);
  else
    lua_pushnil(L);
  return 1;
}

__attribute__((used)) static int file_rename( lua_State* L )
{
  size_t len;

  const char *oldname = luaL_checklstring( L, 1, &len );
  const char *basename = vfs_basename( oldname );
  luaL_argcheck(L, c_strlen(basename) <= FS_OBJ_NAME_LEN && c_strlen(oldname) == len, 1, "filename invalid");

  const char *newname = luaL_checklstring( L, 2, &len );
  basename = vfs_basename( newname );
  luaL_argcheck(L, c_strlen(basename) <= FS_OBJ_NAME_LEN && c_strlen(newname) == len, 2, "filename invalid");

  if(0 <= vfs_rename( oldname, newname )){
    lua_pushboolean(L, 1);
  } else {
    lua_pushboolean(L, 0);
  }
  return 1;
}

__attribute__((used)) static int file_stat( lua_State* L )
{
  size_t len;
  const char *fname = luaL_checklstring( L, 1, &len );
  luaL_argcheck( L, c_strlen(fname) <= FS_OBJ_NAME_LEN && c_strlen(fname) == len, 1, "filename invalid" );

  struct vfs_stat stat;
  if (vfs_stat( (char *)fname, &stat ) != VFS_RES_OK) {
    lua_pushnil( L );
    return 1;
  }

  lua_createtable( L, 0, 7 );

  lua_pushinteger( L, stat.size );
  lua_setfield( L, -2, "size" );

  lua_pushstring( L, stat.name );
  lua_setfield( L, -2, "name" );

  lua_pushboolean( L, stat.is_dir );
  lua_setfield( L, -2, "is_dir" );

  lua_pushboolean( L, stat.is_rdonly );
  lua_setfield( L, -2, "is_rdonly" );

  lua_pushboolean( L, stat.is_hidden );
  lua_setfield( L, -2, "is_hidden" );

  lua_pushboolean( L, stat.is_sys );
  lua_setfield( L, -2, "is_sys" );

  lua_pushboolean( L, stat.is_arch );
  lua_setfield( L, -2, "is_arch" );

  // time stamp as sub-table
  lua_createtable( L, 0, 6 );

  lua_pushinteger( L, stat.tm_valid ? stat.tm.year : FILE_TIMEDEF_YEAR );
  lua_setfield( L, -2, "year" );

  lua_pushinteger( L, stat.tm_valid ? stat.tm.mon : FILE_TIMEDEF_MON );
  lua_setfield( L, -2, "mon" );

  lua_pushinteger( L, stat.tm_valid ? stat.tm.day : FILE_TIMEDEF_DAY );
  lua_setfield( L, -2, "day" );

  lua_pushinteger( L, stat.tm_valid ? stat.tm.hour : FILE_TIMEDEF_HOUR );
  lua_setfield( L, -2, "hour" );

  lua_pushinteger( L, stat.tm_valid ? stat.tm.min : FILE_TIMEDEF_MIN );
  lua_setfield( L, -2, "min" );

  lua_pushinteger( L, stat.tm_valid ? stat.tm.sec : FILE_TIMEDEF_SEC );
  lua_setfield( L, -2, "sec" );

  lua_setfield( L, -2, "time" );

  return 1;
}

__attribute__((used)) static int file_g_read( lua_State* L, int n, int16_t end_char, int fd )
{
  static char *heap_mem = NULL;
  // free leftover memory
  if (heap_mem) {
    luaM_free(L, heap_mem);
    heap_mem = NULL;
  }

  if(n <= 0)
    n = FILE_READ_CHUNK;

  if(end_char < 0 || end_char >255)
    end_char = EOF;


  if(!fd)
    return luaL_error(L, "open a file first");

  char *p;
  int i;

  if (n > LUAL_BUFFERSIZE) {
    // get buffer from heap
    p = heap_mem = luaM_malloc(L, n);
  } else {
    // small chunks go onto the stack
    p = alloca(n);
  }

  n = vfs_read(fd, p, n);
  // bypass search if no end character provided
  if (n > 0 && end_char != EOF) {
    for (i = 0; i < n; ++i)
      if (p[i] == end_char)
      {
        ++i;
        break;
      }
  } else {
    i = n;
  }

  if (i == 0 || n == VFS_RES_ERR) {
    if (heap_mem) {
      luaM_free(L, heap_mem);
      heap_mem = NULL;
    }
    lua_pushnil(L);
    return 1;
  }

  vfs_lseek(fd, -(n - i), VFS_SEEK_CUR);
  lua_pushlstring(L, p, i);
  if (heap_mem) {
    luaM_free(L, heap_mem);
    heap_mem = NULL;
  }
  return 1;
}

__attribute__((used)) static int file_read( lua_State* L )
{
  unsigned need_len = FILE_READ_CHUNK;
  int16_t end_char = EOF;
  size_t el;

  GET_FILE_OBJ;

  if( lua_type( L, argpos ) == LUA_TNUMBER )
  {
    need_len = ( unsigned )luaL_checkinteger( L, argpos );
  }
  else if(lua_isstring(L, argpos))
  {
    const char *end = luaL_checklstring( L, argpos, &el );
    if(el!=1){
      return luaL_error( L, "wrong arg range" );
    }
    end_char = (int16_t)end[0];
  }

  return file_g_read(L, need_len, end_char, fd);
}

__attribute__((used)) static int file_readline( lua_State* L )
{
  GET_FILE_OBJ;

  return file_g_read(L, FILE_READ_CHUNK, '\n', fd);
}

__attribute__((used)) static int file_write( lua_State* L )
{
  GET_FILE_OBJ;

  if(!fd)
    return luaL_error(L, "open a file first");
  size_t l, rl;
  const char *s = luaL_checklstring(L, argpos, &l);
  rl = vfs_write(fd, s, l);
  if(rl==l)
    lua_pushboolean(L, 1);
  else
    lua_pushnil(L);
  return 1;
}

__attribute__((used)) static int file_writeline( lua_State* L )
{
  GET_FILE_OBJ;

  if(!fd)
    return luaL_error(L, "open a file first");
  size_t l, rl;
  const char *s = luaL_checklstring(L, argpos, &l);
  rl = vfs_write(fd, s, l);
  if(rl==l){
    rl = vfs_write(fd, "\n", 1);
    if(rl==1)
      lua_pushboolean(L, 1);
    else
      lua_pushnil(L);
  }
  else{
    lua_pushnil(L);
  }
  return 1;
}

__attribute__((used)) static int file_fsinfo( lua_State* L )
{
  u32_t total, used;
  if (vfs_fsinfo("", &total, &used)) {
    return luaL_error(L, "file system failed");
  }
  NODE_DBG("total: %d, used:%d\n", total, used);
  if(total>0x7FFFFFFF || used>0x7FFFFFFF || used > total)
  {
    return luaL_error(L, "file system error");
  }
  lua_pushinteger(L, total-used);
  lua_pushinteger(L, used);
  lua_pushinteger(L, total);
  return 3;
}

__attribute__((used)) static int file_mount( lua_State *L )
{
  const char *ldrv = luaL_checkstring( L, 1 );
  int num = luaL_optint( L, 2, -1 );
  volume_type *vol = (volume_type *)lua_newuserdata( L, sizeof( volume_type ) );

  if (vol->vol = vfs_mount( ldrv, num )) {
    /* set its metatable */
    luaL_getmetatable(L, "file.vol");
    lua_setmetatable(L, -2);
    return 1;
  } else {
    // remove created userdata
    lua_pop( L, 1 );
    return 0;
  }
}

__attribute__((used)) static int file_chdir( lua_State *L )
{
  const char *path = luaL_checkstring( L, 1 );

  lua_pushboolean( L, 0 <= vfs_chdir( path ) );
  return 1;
}

__attribute__((used)) static int file_vol_umount( lua_State *L )
{
  volume_type *vol = luaL_checkudata( L, 1, "file.vol" );
  luaL_argcheck( L, vol, 1, "volume expected" );

  lua_pushboolean( L, 0 <= vfs_umount( vol->vol ) );

  // invalidate vfs descriptor, it has been free'd anyway
  vol->vol = NULL;
  return 1;
}

int luaopen_file( lua_State *L ) {
  luaL_rometatable( L, "file.vol",  (void *)file_vol_map );
  luaL_rometatable( L, "file.obj",  (void *)file_obj_map );
  return 0;
}

