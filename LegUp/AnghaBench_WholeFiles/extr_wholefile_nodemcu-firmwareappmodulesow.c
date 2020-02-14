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
typedef  char uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  luaL_Buffer ;

/* Variables and functions */
 scalar_t__ LUAL_BUFFERSIZE ; 
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  luaL_addsize (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  luaL_argcheck (int /*<<< orphan*/ *,int,int,char*) ; 
 int /*<<< orphan*/  luaL_buffinit (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 void* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 char* luaL_prepbuffer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_pushresult (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_isnumber (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_istable (int /*<<< orphan*/ *,int) ; 
 size_t lua_objlen (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int,int) ; 
 int lua_tointeger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  onewire_depower (unsigned int) ; 
 int /*<<< orphan*/  onewire_init (unsigned int) ; 
 int /*<<< orphan*/  onewire_read (unsigned int) ; 
 int /*<<< orphan*/  onewire_read_bytes (unsigned int,char*,scalar_t__) ; 
 int /*<<< orphan*/  onewire_reset (unsigned int) ; 
 int /*<<< orphan*/  onewire_select (unsigned int,char*) ; 
 int /*<<< orphan*/  onewire_skip (unsigned int) ; 
 int /*<<< orphan*/  onewire_write (char,char,char) ; 
 int /*<<< orphan*/  onewire_write_bytes (char,char const*,int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  ow ; 

__attribute__((used)) static int ow_setup( lua_State *L )
{
  unsigned id = luaL_checkinteger( L, 1 );

  if(id==0)
    return luaL_error( L, "no 1-wire for D0" );

  MOD_CHECK_ID( ow, id );

  onewire_init( id );
  return 0;
}

__attribute__((used)) static int ow_reset( lua_State *L )
{
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );
  lua_pushinteger( L, onewire_reset(id) );
  return 1;
}

__attribute__((used)) static int ow_skip( lua_State *L )
{
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );
  onewire_skip(id);
  return 0;
}

__attribute__((used)) static int ow_select( lua_State *L )
{
  uint8_t rom[8];
  size_t datalen;
  int numdata, i;
  unsigned id = luaL_checkinteger( L, 1 );
  const char *pdata;
  MOD_CHECK_ID( ow, id );

  if( lua_istable( L, 2 ) )
  {
    datalen = lua_objlen( L, 2 );
    if (datalen!=8)
      return luaL_error( L, "wrong arg range" );
    for( i = 0; i < datalen; i ++ )
    {
      lua_rawgeti( L, 2, i + 1 );
      numdata = ( int )luaL_checkinteger( L, -1 );
      lua_pop( L, 1 );
      if( numdata > 255 )
        return luaL_error( L, "wrong arg range" );
      rom[i] = (uint8_t)numdata;
    }
  }
  else
  {
    pdata = luaL_checklstring( L, 2, &datalen );
    if (datalen!=8)
      return luaL_error( L, "wrong arg range" );
    for( i = 0; i < datalen; i ++ ){
      rom[i] = pdata[i];
    }
  }

  onewire_select(id, rom);
  return 0;
}

__attribute__((used)) static int ow_write( lua_State *L )
{
  int power = 0;
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );

  int v = (int)luaL_checkinteger( L, 2 );
  if( v > 255 )
    return luaL_error( L, "wrong arg range" );
  if(lua_isnumber(L, 3))
    power = lua_tointeger(L, 3);
  if(power!=0)
    power = 1;

  onewire_write((uint8_t)id, (uint8_t)v, (uint8_t)power);

  return 0;
}

__attribute__((used)) static int ow_write_bytes( lua_State *L )
{
  int power = 0;
  size_t datalen;
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );

  const uint8_t *pdata = luaL_checklstring( L, 2, &datalen );

  if(lua_isnumber(L, 3))
    power = lua_tointeger(L, 3);
  if(power!=0)
    power = 1;

  onewire_write_bytes((uint8_t)id, pdata, (uint16_t)datalen, (uint8_t)power);

  return 0;
}

__attribute__((used)) static int ow_read( lua_State *L )
{
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );
  lua_pushinteger( L, onewire_read(id) );
  return 1;
}

__attribute__((used)) static int ow_read_bytes( lua_State *L )
{
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );
  u32 size = ( u32 )luaL_checkinteger( L, 2 );
  if( size == 0 )
    return 0;

  luaL_argcheck(L, size <= LUAL_BUFFERSIZE, 2, "Attempt to read too many characters");

  luaL_Buffer b;
  luaL_buffinit( L, &b );
  char *p = luaL_prepbuffer(&b);

  onewire_read_bytes(id, (uint8_t *)p, size);

  luaL_addsize(&b, size);
  luaL_pushresult( &b );
  return 1;
}

__attribute__((used)) static int ow_depower( lua_State *L )
{
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );
  onewire_depower(id);
  return 0;
}

