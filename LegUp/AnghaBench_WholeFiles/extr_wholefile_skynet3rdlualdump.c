#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_5__ ;
typedef  struct TYPE_32__   TYPE_4__ ;
typedef  struct TYPE_31__   TYPE_3__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ (* lua_Writer ) (int /*<<< orphan*/ *,void const*,size_t,void*) ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  size_t lua_Number ;
typedef  size_t lua_Integer ;
typedef  size_t lu_byte ;
struct TYPE_33__ {scalar_t__ status; scalar_t__ (* writer ) (int /*<<< orphan*/ *,void const*,size_t,void*) ;int strip; void* data; int /*<<< orphan*/ * L; } ;
struct TYPE_32__ {TYPE_3__* sp; struct TYPE_32__ const** p; int /*<<< orphan*/ * k; } ;
struct TYPE_31__ {int sizecode; char const* code; int sizek; int sizep; int sizeupvalues; int sizelineinfo; char const* lineinfo; int sizelocvars; int linedefined; int lastlinedefined; int numparams; int is_vararg; int maxstacksize; int /*<<< orphan*/ * source; TYPE_2__* upvalues; TYPE_1__* locvars; } ;
struct TYPE_30__ {int instack; int idx; int /*<<< orphan*/ * name; } ;
struct TYPE_29__ {int startpc; int endpc; int /*<<< orphan*/ * varname; } ;
typedef  int /*<<< orphan*/  TValue ;
typedef  int /*<<< orphan*/  TString ;
typedef  TYPE_3__ SharedProto ;
typedef  TYPE_4__ Proto ;
typedef  int /*<<< orphan*/  Instruction ;
typedef  TYPE_5__ DumpState ;

/* Variables and functions */
static  void DumpFunction (TYPE_4__ const*,int /*<<< orphan*/ *,TYPE_5__*) ; 
 int /*<<< orphan*/  DumpLiteral (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  DumpVar (size_t,TYPE_5__*) ; 
 int /*<<< orphan*/  DumpVector (char const*,int,TYPE_5__*) ; 
 int /*<<< orphan*/  LUAC_DATA ; 
 int LUAC_FORMAT ; 
 size_t LUAC_INT ; 
 size_t LUAC_NUM ; 
 int LUAC_VERSION ; 
 int /*<<< orphan*/  LUA_SIGNATURE ; 
#define  LUA_TBOOLEAN 133 
#define  LUA_TLNGSTR 132 
#define  LUA_TNIL 131 
#define  LUA_TNUMFLT 130 
#define  LUA_TNUMINT 129 
#define  LUA_TSHRSTR 128 
 int bvalue (int /*<<< orphan*/  const*) ; 
 int cast_int (size_t) ; 
 size_t fltvalue (int /*<<< orphan*/  const*) ; 
 char* getstr (int /*<<< orphan*/  const*) ; 
 size_t ivalue (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  lua_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ *,void const*,size_t,void*) ; 
 int tsslen (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * tsvalue (int /*<<< orphan*/  const*) ; 
 int ttype (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void DumpBlock (const void *b, size_t size, DumpState *D) {
  if (D->status == 0 && size > 0) {
    lua_unlock(D->L);
    D->status = (*D->writer)(D->L, b, size, D->data);
    lua_lock(D->L);
  }
}

__attribute__((used)) static void DumpByte (int y, DumpState *D) {
  lu_byte x = (lu_byte)y;
  DumpVar(x, D);
}

__attribute__((used)) static void DumpInt (int x, DumpState *D) {
  DumpVar(x, D);
}

__attribute__((used)) static void DumpNumber (lua_Number x, DumpState *D) {
  DumpVar(x, D);
}

__attribute__((used)) static void DumpInteger (lua_Integer x, DumpState *D) {
  DumpVar(x, D);
}

__attribute__((used)) static void DumpString (const TString *s, DumpState *D) {
  if (s == NULL)
    DumpByte(0, D);
  else {
    size_t size = tsslen(s) + 1;  /* include trailing '\0' */
    const char *str = getstr(s);
    if (size < 0xFF)
      DumpByte(cast_int(size), D);
    else {
      DumpByte(0xFF, D);
      DumpVar(size, D);
    }
    DumpVector(str, size - 1, D);  /* no need to save '\0' */
  }
}

__attribute__((used)) static void DumpCode (const SharedProto *f, DumpState *D) {
  DumpInt(f->sizecode, D);
  DumpVector(f->code, f->sizecode, D);
}

__attribute__((used)) static void DumpConstants (const Proto *f, DumpState *D) {
  int i;
  int n = f->sp->sizek;
  DumpInt(n, D);
  for (i = 0; i < n; i++) {
    const TValue *o = &f->k[i];
    DumpByte(ttype(o), D);
    switch (ttype(o)) {
    case LUA_TNIL:
      break;
    case LUA_TBOOLEAN:
      DumpByte(bvalue(o), D);
      break;
    case LUA_TNUMFLT:
      DumpNumber(fltvalue(o), D);
      break;
    case LUA_TNUMINT:
      DumpInteger(ivalue(o), D);
      break;
    case LUA_TSHRSTR:
    case LUA_TLNGSTR:
      DumpString(tsvalue(o), D);
      break;
    default:
      lua_assert(0);
    }
  }
}

__attribute__((used)) static void DumpProtos (const Proto *f, DumpState *D) {
  int i;
  int n = f->sp->sizep;
  DumpInt(n, D);
  for (i = 0; i < n; i++)
    DumpFunction(f->p[i], f->sp->source, D);
}

__attribute__((used)) static void DumpUpvalues (const SharedProto *f, DumpState *D) {
  int i, n = f->sizeupvalues;
  DumpInt(n, D);
  for (i = 0; i < n; i++) {
    DumpByte(f->upvalues[i].instack, D);
    DumpByte(f->upvalues[i].idx, D);
  }
}

__attribute__((used)) static void DumpDebug (const SharedProto *f, DumpState *D) {
  int i, n;
  n = (D->strip) ? 0 : f->sizelineinfo;
  DumpInt(n, D);
  DumpVector(f->lineinfo, n, D);
  n = (D->strip) ? 0 : f->sizelocvars;
  DumpInt(n, D);
  for (i = 0; i < n; i++) {
    DumpString(f->locvars[i].varname, D);
    DumpInt(f->locvars[i].startpc, D);
    DumpInt(f->locvars[i].endpc, D);
  }
  n = (D->strip) ? 0 : f->sizeupvalues;
  DumpInt(n, D);
  for (i = 0; i < n; i++)
    DumpString(f->upvalues[i].name, D);
}

__attribute__((used)) static void DumpFunction (const Proto *fp, TString *psource, DumpState *D) {
  const SharedProto *f = fp->sp;
  if (D->strip || f->source == psource)
    DumpString(NULL, D);  /* no debug info or same source as its parent */
  else
    DumpString(f->source, D);
  DumpInt(f->linedefined, D);
  DumpInt(f->lastlinedefined, D);
  DumpByte(f->numparams, D);
  DumpByte(f->is_vararg, D);
  DumpByte(f->maxstacksize, D);
  DumpCode(f, D);
  DumpConstants(fp, D);
  DumpUpvalues(f, D);
  DumpProtos(fp, D);
  DumpDebug(f, D);
}

__attribute__((used)) static void DumpHeader (DumpState *D) {
  DumpLiteral(LUA_SIGNATURE, D);
  DumpByte(LUAC_VERSION, D);
  DumpByte(LUAC_FORMAT, D);
  DumpLiteral(LUAC_DATA, D);
  DumpByte(sizeof(int), D);
  DumpByte(sizeof(size_t), D);
  DumpByte(sizeof(Instruction), D);
  DumpByte(sizeof(lua_Integer), D);
  DumpByte(sizeof(lua_Number), D);
  DumpInteger(LUAC_INT, D);
  DumpNumber(LUAC_NUM, D);
}

int luaU_dump(lua_State *L, const Proto *f, lua_Writer w, void *data,
              int strip) {
  DumpState D;
  D.L = L;
  D.writer = w;
  D.data = data;
  D.strip = strip;
  D.status = 0;
  DumpHeader(&D);
  DumpByte(f->sp->sizeupvalues, &D);
  DumpFunction(f, NULL, &D);
  return D.status;
}

