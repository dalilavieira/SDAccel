#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_7__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_9__ {int /*<<< orphan*/  flags; } ;
typedef  TYPE_1__ Table ;
struct TYPE_12__ {int /*<<< orphan*/ ** tmname; TYPE_1__** mt; } ;
struct TYPE_11__ {TYPE_1__* metatable; } ;
struct TYPE_10__ {TYPE_1__* metatable; } ;
typedef  int /*<<< orphan*/  TValue ;
typedef  int /*<<< orphan*/  TString ;
typedef  unsigned int TMS ;

/* Variables and functions */
 TYPE_8__* G (int /*<<< orphan*/ *) ; 
#define  LUA_TROTABLE 130 
#define  LUA_TTABLE 129 
#define  LUA_TUSERDATA 128 
 unsigned int TM_EQ ; 
 int TM_N ; 
 int /*<<< orphan*/  cast_byte (unsigned int) ; 
 TYPE_7__* hvalue (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* luaH_getstr (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* luaH_getstr_ro (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* luaO_nilobject ; 
 scalar_t__ luaR_getmeta (int /*<<< orphan*/ ) ; 
 scalar_t__ luaR_isrotable (TYPE_1__*) ; 
 int /*<<< orphan*/ * luaS_new (int /*<<< orphan*/ *,char const* const) ; 
 int /*<<< orphan*/  lua_assert (int) ; 
 int /*<<< orphan*/  rvalue (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  stringfix (int /*<<< orphan*/ *) ; 
 scalar_t__ ttisnil (int /*<<< orphan*/  const*) ; 
 size_t ttype (int /*<<< orphan*/  const*) ; 
 TYPE_2__* uvalue (int /*<<< orphan*/  const*) ; 

void luaT_init (lua_State *L) {
  static const char *const luaT_eventname[] = {  /* ORDER TM */
    "__index", "__newindex",
    "__gc", "__mode", "__eq",
    "__add", "__sub", "__mul", "__div", "__mod",
    "__pow", "__unm", "__len", "__lt", "__le",
    "__concat", "__call"
  };
  int i;
  for (i=0; i<TM_N; i++) {
    G(L)->tmname[i] = luaS_new(L, luaT_eventname[i]);
    stringfix(G(L)->tmname[i]);  /* never collect these names */
  }
}

const TValue *luaT_gettm (Table *events, TMS event, TString *ename) {
  const TValue *tm;
  lua_assert(event <= TM_EQ);

  if (luaR_isrotable(events)) {
    tm =  luaH_getstr_ro(events, ename);
    if (ttisnil(tm)) {  /* no tag method? */
      return NULL;
    }
  } else {
    tm = luaH_getstr(events, ename);
    if (ttisnil(tm)) {  /* no tag method? */
      events->flags |= cast_byte(1u<<event);  /* cache this fact */
      return NULL;
    }
  }
  return tm;
}

const TValue *luaT_gettmbyobj (lua_State *L, const TValue *o, TMS event) {
  Table *mt;
  switch (ttype(o)) {
    case LUA_TTABLE:
      mt = hvalue(o)->metatable;
      break;
    case LUA_TROTABLE:
      mt = (Table*)luaR_getmeta(rvalue(o));
      break;
    case LUA_TUSERDATA:
      mt = uvalue(o)->metatable;
      break;
    default:
      mt = G(L)->mt[ttype(o)];
  }
  if (!mt)
    return luaO_nilobject;
  else if (luaR_isrotable(mt))
    return luaH_getstr_ro(mt, G(L)->tmname[event]);
  else
    return luaH_getstr(mt, G(L)->tmname[event]);
}

