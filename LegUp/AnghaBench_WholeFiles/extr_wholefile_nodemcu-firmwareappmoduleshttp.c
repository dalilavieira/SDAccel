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
typedef  int /*<<< orphan*/  luaL_Buffer ;

/* Variables and functions */
 int HTTP_STATUS_GENERIC_ERROR ; 
 scalar_t__ LUA_NOREF ; 
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ LUA_TFUNCTION ; 
 scalar_t__ LUA_TLIGHTFUNCTION ; 
 int /*<<< orphan*/  c_free (char*) ; 
 scalar_t__ http_callback_registry ; 
 int /*<<< orphan*/  http_delete (char const*,char const*,char const*,void (*) (char*,int,char**)) ; 
 int /*<<< orphan*/  http_get (char const*,char const*,void (*) (char*,int,char**)) ; 
 int /*<<< orphan*/  http_post (char const*,char const*,char const*,void (*) (char*,int,char**)) ; 
 int /*<<< orphan*/  http_put (char const*,char const*,char const*,void (*) (char*,int,char**)) ; 
 int /*<<< orphan*/  http_request (char const*,char const*,char const*,char const*,void (*) (char*,int,char**),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_addchar (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_buffinit (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,int*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  luaL_pushresult (int /*<<< orphan*/ *) ; 
 scalar_t__ luaL_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_unref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 scalar_t__ lua_isstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_newtable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  lua_pushnil (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushnumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  lua_settable (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  tolower (unsigned char) ; 

__attribute__((used)) static void http_callback( char * response, int http_status, char ** full_response_p )
{
  const char *full_response = full_response_p ? *full_response_p : NULL;

#if defined(HTTPCLIENT_DEBUG_ON)
  dbg_printf( "http_status=%d\n", http_status );
  if ( http_status != HTTP_STATUS_GENERIC_ERROR )
  {
    if (full_response != NULL) {
      dbg_printf( "strlen(full_response)=%d\n", strlen( full_response ) );
    }
    dbg_printf( "response=%s<EOF>\n", response );
  }
#endif
  if (http_callback_registry != LUA_NOREF)
  {
    lua_State *L = lua_getstate();

    lua_rawgeti(L, LUA_REGISTRYINDEX, http_callback_registry);

    lua_pushnumber(L, http_status);
    if ( http_status != HTTP_STATUS_GENERIC_ERROR && response)
    {
      lua_pushstring(L, response);
      lua_newtable(L);

      const char *p = full_response;

      // Need to skip the HTTP/1.1 header line
      while (*p && *p != '\n') {
        p++;
      }
      if (*p == '\n') {
        p++;
      }

      while (*p && *p != '\r' && *p != '\n') {
        const char *eol = p;
        while (*eol && *eol != '\r') {
          eol++;
        }

        const char *colon = p;
        while (*colon != ':' && colon < eol) {
          colon++;
        }

        if (*colon != ':') {
          break;
        }

        const char *value = colon + 1;
        while (*value == ' ') {
          value++;
        }

        luaL_Buffer b;
        luaL_buffinit(L, &b);
        while (p < colon) {
          luaL_addchar(&b, tolower((unsigned char) *p));
          p++;
        }
        luaL_pushresult(&b);

        lua_pushlstring(L, value, eol - value);
        lua_settable(L, -3);

        p = eol + 1;
        if (*p == '\n') {
          p++;
        }
      }
    }
    else
    {
      lua_pushnil(L);
      lua_pushnil(L);
    }

    if (full_response_p && *full_response_p) {
      c_free(*full_response_p);
      *full_response_p = NULL;
    }

    luaL_unref(L, LUA_REGISTRYINDEX, http_callback_registry);
    http_callback_registry = LUA_NOREF;

    lua_call(L, 3, 0); // With 3 arguments and 0 result
  }
}

__attribute__((used)) static int http_lapi_request( lua_State *L )
{
  int length;
  const char * url     = luaL_checklstring(L, 1, &length);
  const char * method  = luaL_checklstring(L, 2, &length);
  const char * headers = NULL;
  const char * body    = NULL;

  // Check parameter
  if ((url == NULL) || (method == NULL))
  {
    return luaL_error( L, "wrong arg type" );
  }

  if (lua_isstring(L, 3))
  {
    headers = luaL_checklstring(L, 3, &length);
  }
  if (lua_isstring(L, 4))
  {
    body = luaL_checklstring(L, 4, &length);
  }

  if (lua_type(L, 5) == LUA_TFUNCTION || lua_type(L, 5) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, 5);  // copy argument (func) to the top of stack
    luaL_unref(L, LUA_REGISTRYINDEX, http_callback_registry);
    http_callback_registry = luaL_ref(L, LUA_REGISTRYINDEX);
  }

  http_request(url, method, headers, body, http_callback, 0);
  return 0;
}

__attribute__((used)) static int http_lapi_post( lua_State *L )
{
  int length;
  const char * url     = luaL_checklstring(L, 1, &length);
  const char * headers = NULL;
  const char * body    = NULL;

  // Check parameter
  if ((url == NULL))
  {
    return luaL_error( L, "wrong arg type" );
  }

  if (lua_isstring(L, 2))
  {
    headers = luaL_checklstring(L, 2, &length);
  }
  if (lua_isstring(L, 3))
  {
    body = luaL_checklstring(L, 3, &length);
  }

  if (lua_type(L, 4) == LUA_TFUNCTION || lua_type(L, 4) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, 4);  // copy argument (func) to the top of stack
    if (http_callback_registry != LUA_NOREF)
      luaL_unref(L, LUA_REGISTRYINDEX, http_callback_registry);
    http_callback_registry = luaL_ref(L, LUA_REGISTRYINDEX);
  }

  http_post(url, headers, body, http_callback);
  return 0;
}

__attribute__((used)) static int http_lapi_put( lua_State *L )
{
  int length;
  const char * url     = luaL_checklstring(L, 1, &length);
  const char * headers = NULL;
  const char * body    = NULL;

  // Check parameter
  if ((url == NULL))
  {
    return luaL_error( L, "wrong arg type" );
  }

  if (lua_isstring(L, 2))
  {
    headers = luaL_checklstring(L, 2, &length);
  }
  if (lua_isstring(L, 3))
  {
    body = luaL_checklstring(L, 3, &length);
  }

  if (lua_type(L, 4) == LUA_TFUNCTION || lua_type(L, 4) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, 4);  // copy argument (func) to the top of stack
    if (http_callback_registry != LUA_NOREF)
      luaL_unref(L, LUA_REGISTRYINDEX, http_callback_registry);
    http_callback_registry = luaL_ref(L, LUA_REGISTRYINDEX);
  }

  http_put(url, headers, body, http_callback);
  return 0;
}

__attribute__((used)) static int http_lapi_delete( lua_State *L )
{
  int length;
  const char * url     = luaL_checklstring(L, 1, &length);
  const char * headers = NULL;
  const char * body    = NULL;

  // Check parameter
  if ((url == NULL))
  {
    return luaL_error( L, "wrong arg type" );
  }

  if (lua_isstring(L, 2))
  {
    headers = luaL_checklstring(L, 2, &length);
  }
  if (lua_isstring(L, 3))
  {
    body = luaL_checklstring(L, 3, &length);
  }

  if (lua_type(L, 4) == LUA_TFUNCTION || lua_type(L, 4) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, 4);  // copy argument (func) to the top of stack
    if (http_callback_registry != LUA_NOREF)
      luaL_unref(L, LUA_REGISTRYINDEX, http_callback_registry);
    http_callback_registry = luaL_ref(L, LUA_REGISTRYINDEX);
  }

  http_delete(url, headers, body, http_callback);
  return 0;
}

__attribute__((used)) static int http_lapi_get( lua_State *L )
{
  int length;
  const char * url     = luaL_checklstring(L, 1, &length);
  const char * headers = NULL;

  // Check parameter
  if ((url == NULL))
  {
    return luaL_error( L, "wrong arg type" );
  }

  if (lua_isstring(L, 2))
  {
    headers = luaL_checklstring(L, 2, &length);
  }

  if (lua_type(L, 3) == LUA_TFUNCTION || lua_type(L, 3) == LUA_TLIGHTFUNCTION) {
    lua_pushvalue(L, 3);  // copy argument (func) to the top of stack
    if (http_callback_registry != LUA_NOREF)
      luaL_unref(L, LUA_REGISTRYINDEX, http_callback_registry);
    http_callback_registry = luaL_ref(L, LUA_REGISTRYINDEX);
  }

  http_get(url, headers, http_callback);
  return 0;
}

