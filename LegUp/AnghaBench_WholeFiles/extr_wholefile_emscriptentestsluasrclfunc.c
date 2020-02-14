#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_51__   TYPE_9__ ;
typedef  struct TYPE_50__   TYPE_6__ ;
typedef  struct TYPE_49__   TYPE_5__ ;
typedef  struct TYPE_48__   TYPE_4__ ;
typedef  struct TYPE_47__   TYPE_3__ ;
typedef  struct TYPE_46__   TYPE_39__ ;
typedef  struct TYPE_45__   TYPE_33__ ;
typedef  struct TYPE_44__   TYPE_2__ ;
typedef  struct TYPE_43__   TYPE_1__ ;
typedef  struct TYPE_42__   TYPE_14__ ;

/* Type definitions */
struct TYPE_43__ {TYPE_5__* next; TYPE_5__* prev; } ;
struct TYPE_48__ {int /*<<< orphan*/  value; TYPE_1__ l; } ;
struct TYPE_49__ {scalar_t__ v; int sizek; int sizep; int sizecode; int sizelineinfo; int sizeupvalues; int sizelocvars; TYPE_14__* locvars; TYPE_14__* upvalues; TYPE_14__* lineinfo; TYPE_14__* k; TYPE_14__* p; TYPE_14__* code; int /*<<< orphan*/ * source; scalar_t__ lastlinedefined; scalar_t__ linedefined; scalar_t__ maxstacksize; scalar_t__ is_vararg; scalar_t__ numparams; int /*<<< orphan*/ * cache; TYPE_4__ u; int /*<<< orphan*/ * next; int /*<<< orphan*/ * openupval; } ;
typedef  TYPE_5__ lua_State ;
struct TYPE_50__ {int /*<<< orphan*/ * allgc; TYPE_5__ uvhead; } ;
typedef  TYPE_6__ global_State ;
typedef  TYPE_5__ UpVal ;
struct TYPE_47__ {int /*<<< orphan*/ ** upvals; void* nupvalues; int /*<<< orphan*/ * p; } ;
struct TYPE_44__ {void* nupvalues; } ;
struct TYPE_51__ {TYPE_3__ l; TYPE_2__ c; } ;
struct TYPE_46__ {int /*<<< orphan*/ * next; } ;
struct TYPE_45__ {TYPE_5__ p; TYPE_5__ uv; TYPE_9__ cl; } ;
struct TYPE_42__ {int startpc; int endpc; int /*<<< orphan*/  varname; } ;
typedef  scalar_t__ StkId ;
typedef  TYPE_5__ Proto ;
typedef  int /*<<< orphan*/  GCObject ;
typedef  TYPE_9__ Closure ;

/* Variables and functions */
 TYPE_6__* G (TYPE_5__*) ; 
 int /*<<< orphan*/  LUA_TCCL ; 
 int /*<<< orphan*/  LUA_TLCL ; 
 int /*<<< orphan*/  LUA_TPROTO ; 
 int /*<<< orphan*/  LUA_TUPVAL ; 
 void* cast_byte (int) ; 
 int /*<<< orphan*/  changewhite (int /*<<< orphan*/ *) ; 
 TYPE_39__* gch (int /*<<< orphan*/ *) ; 
 TYPE_5__* gco2uv (int /*<<< orphan*/ *) ; 
 char const* getstr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isblack (int /*<<< orphan*/ *) ; 
 scalar_t__ isdead (TYPE_6__*,int /*<<< orphan*/ *) ; 
 scalar_t__ isold (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaC_checkupvalcolor (TYPE_6__*,TYPE_5__*) ; 
 TYPE_33__* luaC_newobj (TYPE_5__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaM_free (TYPE_5__*,TYPE_5__*) ; 
 int /*<<< orphan*/  luaM_freearray (TYPE_5__*,TYPE_14__*,int) ; 
 int /*<<< orphan*/  lua_assert (int) ; 
 int /*<<< orphan*/ * obj2gco (TYPE_5__*) ; 
 int /*<<< orphan*/  setnilvalue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setobj (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int sizeCclosure (int) ; 
 int sizeLclosure (int) ; 

Closure *luaF_newCclosure (lua_State *L, int n) {
  Closure *c = &luaC_newobj(L, LUA_TCCL, sizeCclosure(n), NULL, 0)->cl;
  c->c.nupvalues = cast_byte(n);
  return c;
}

Closure *luaF_newLclosure (lua_State *L, int n) {
  Closure *c = &luaC_newobj(L, LUA_TLCL, sizeLclosure(n), NULL, 0)->cl;
  c->l.p = NULL;
  c->l.nupvalues = cast_byte(n);
  while (n--) c->l.upvals[n] = NULL;
  return c;
}

UpVal *luaF_newupval (lua_State *L) {
  UpVal *uv = &luaC_newobj(L, LUA_TUPVAL, sizeof(UpVal), NULL, 0)->uv;
  uv->v = &uv->u.value;
  setnilvalue(uv->v);
  return uv;
}

UpVal *luaF_findupval (lua_State *L, StkId level) {
  global_State *g = G(L);
  GCObject **pp = &L->openupval;
  UpVal *p;
  UpVal *uv;
  while (*pp != NULL && (p = gco2uv(*pp))->v >= level) {
    GCObject *o = obj2gco(p);
    lua_assert(p->v != &p->u.value);
    lua_assert(!isold(o) || isold(obj2gco(L)));
    if (p->v == level) {  /* found a corresponding upvalue? */
      if (isdead(g, o))  /* is it dead? */
        changewhite(o);  /* resurrect it */
      return p;
    }
    pp = &p->next;
  }
  /* not found: create a new one */
  uv = &luaC_newobj(L, LUA_TUPVAL, sizeof(UpVal), pp, 0)->uv;
  uv->v = level;  /* current value lives in the stack */
  uv->u.l.prev = &g->uvhead;  /* double link it in `uvhead' list */
  uv->u.l.next = g->uvhead.u.l.next;
  uv->u.l.next->u.l.prev = uv;
  g->uvhead.u.l.next = uv;
  lua_assert(uv->u.l.next->u.l.prev == uv && uv->u.l.prev->u.l.next == uv);
  return uv;
}

__attribute__((used)) static void unlinkupval (UpVal *uv) {
  lua_assert(uv->u.l.next->u.l.prev == uv && uv->u.l.prev->u.l.next == uv);
  uv->u.l.next->u.l.prev = uv->u.l.prev;  /* remove from `uvhead' list */
  uv->u.l.prev->u.l.next = uv->u.l.next;
}

void luaF_freeupval (lua_State *L, UpVal *uv) {
  if (uv->v != &uv->u.value)  /* is it open? */
    unlinkupval(uv);  /* remove from open list */
  luaM_free(L, uv);  /* free upvalue */
}

void luaF_close (lua_State *L, StkId level) {
  UpVal *uv;
  global_State *g = G(L);
  while (L->openupval != NULL && (uv = gco2uv(L->openupval))->v >= level) {
    GCObject *o = obj2gco(uv);
    lua_assert(!isblack(o) && uv->v != &uv->u.value);
    L->openupval = uv->next;  /* remove from `open' list */
    if (isdead(g, o))
      luaF_freeupval(L, uv);  /* free upvalue */
    else {
      unlinkupval(uv);  /* remove upvalue from 'uvhead' list */
      setobj(L, &uv->u.value, uv->v);  /* move value to upvalue slot */
      uv->v = &uv->u.value;  /* now current value lives here */
      gch(o)->next = g->allgc;  /* link upvalue into 'allgc' list */
      g->allgc = o;
      luaC_checkupvalcolor(g, uv);
    }
  }
}

Proto *luaF_newproto (lua_State *L) {
  Proto *f = &luaC_newobj(L, LUA_TPROTO, sizeof(Proto), NULL, 0)->p;
  f->k = NULL;
  f->sizek = 0;
  f->p = NULL;
  f->sizep = 0;
  f->code = NULL;
  f->cache = NULL;
  f->sizecode = 0;
  f->lineinfo = NULL;
  f->sizelineinfo = 0;
  f->upvalues = NULL;
  f->sizeupvalues = 0;
  f->numparams = 0;
  f->is_vararg = 0;
  f->maxstacksize = 0;
  f->locvars = NULL;
  f->sizelocvars = 0;
  f->linedefined = 0;
  f->lastlinedefined = 0;
  f->source = NULL;
  return f;
}

void luaF_freeproto (lua_State *L, Proto *f) {
  luaM_freearray(L, f->code, f->sizecode);
  luaM_freearray(L, f->p, f->sizep);
  luaM_freearray(L, f->k, f->sizek);
  luaM_freearray(L, f->lineinfo, f->sizelineinfo);
  luaM_freearray(L, f->locvars, f->sizelocvars);
  luaM_freearray(L, f->upvalues, f->sizeupvalues);
  luaM_free(L, f);
}

const char *luaF_getlocalname (const Proto *f, int local_number, int pc) {
  int i;
  for (i = 0; i<f->sizelocvars && f->locvars[i].startpc <= pc; i++) {
    if (pc < f->locvars[i].endpc) {  /* is variable active? */
      local_number--;
      if (local_number == 0)
        return getstr(f->locvars[i].varname);
    }
  }
  return NULL;  /* not found */
}

