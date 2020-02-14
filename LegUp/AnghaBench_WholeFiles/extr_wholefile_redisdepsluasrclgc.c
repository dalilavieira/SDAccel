#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_146__   TYPE_9__ ;
typedef  struct TYPE_145__   TYPE_8__ ;
typedef  struct TYPE_144__   TYPE_7__ ;
typedef  struct TYPE_143__   TYPE_6__ ;
typedef  struct TYPE_142__   TYPE_5__ ;
typedef  struct TYPE_141__   TYPE_4__ ;
typedef  struct TYPE_140__   TYPE_3__ ;
typedef  struct TYPE_139__   TYPE_2__ ;
typedef  struct TYPE_138__   TYPE_1__ ;
typedef  struct TYPE_137__   TYPE_19__ ;
typedef  struct TYPE_136__   TYPE_18__ ;
typedef  struct TYPE_135__   TYPE_16__ ;
typedef  struct TYPE_134__   TYPE_15__ ;
typedef  struct TYPE_133__   TYPE_14__ ;
typedef  struct TYPE_132__   TYPE_13__ ;
typedef  struct TYPE_131__   TYPE_11__ ;

/* Type definitions */
struct TYPE_142__ {TYPE_8__* next; TYPE_8__* prev; } ;
struct TYPE_143__ {TYPE_5__ l; int /*<<< orphan*/  value; } ;
struct TYPE_145__ {scalar_t__ v; int marked; int sizearray; int nups; scalar_t__ ci; scalar_t__ base_ci; scalar_t__ stack; int size_ci; int stacksize; scalar_t__ top; scalar_t__ stack_last; TYPE_14__* gclist; TYPE_6__ u; void* allowhook; TYPE_14__* next; TYPE_14__* openupval; int /*<<< orphan*/ * array; struct TYPE_145__* metatable; } ;
typedef  TYPE_8__ lua_State ;
typedef  int lu_mem ;
typedef  void* lu_byte ;
typedef  int l_mem ;
struct TYPE_144__ {scalar_t__ nuse; int size; TYPE_14__** hash; } ;
struct TYPE_146__ {int GCthreshold; int totalbytes; int currentwhite; int gcstate; int sweepstrgc; int estimate; int gcdept; int gcstepmul; TYPE_14__* rootgc; TYPE_14__* grayagain; TYPE_14__* weak; TYPE_14__* gray; TYPE_14__** sweepgc; TYPE_14__* tmudata; TYPE_7__ strt; TYPE_8__* mainthread; TYPE_8__ uvhead; TYPE_8__** mt; int /*<<< orphan*/  buff; } ;
typedef  TYPE_9__ global_State ;
typedef  TYPE_8__ UpVal ;
struct TYPE_141__ {TYPE_8__* metatable; TYPE_14__* next; } ;
struct TYPE_131__ {TYPE_4__ uv; } ;
typedef  TYPE_11__ Udata ;
typedef  TYPE_8__ Table ;
struct TYPE_140__ {int nupvalues; TYPE_8__** upvals; TYPE_8__* p; } ;
struct TYPE_139__ {int nupvalues; scalar_t__ isC; TYPE_14__* gclist; int /*<<< orphan*/ * upvalue; TYPE_8__* env; } ;
struct TYPE_138__ {scalar_t__ varname; } ;
struct TYPE_137__ {int tt; int marked; TYPE_14__* next; } ;
struct TYPE_136__ {TYPE_8__* metatable; TYPE_8__* env; } ;
struct TYPE_135__ {scalar_t__ top; } ;
struct TYPE_134__ {TYPE_3__ l; TYPE_2__ c; } ;
struct TYPE_133__ {TYPE_19__ gch; } ;
struct TYPE_132__ {int sizek; int sizeupvalues; int sizep; int sizelocvars; int sizecode; int sizelineinfo; TYPE_14__* gclist; TYPE_1__* locvars; TYPE_8__** p; scalar_t__* upvalues; int /*<<< orphan*/ * k; scalar_t__ source; } ;
typedef  int /*<<< orphan*/  TValue ;
typedef  int /*<<< orphan*/  TString ;
typedef  scalar_t__ StkId ;
typedef  TYPE_13__ Proto ;
typedef  int /*<<< orphan*/  Node ;
typedef  int /*<<< orphan*/  LocVar ;
typedef  int /*<<< orphan*/  Instruction ;
typedef  TYPE_14__ GCObject ;
typedef  TYPE_15__ Closure ;
typedef  TYPE_16__ CallInfo ;

/* Variables and functions */
 int BASIC_CI_SIZE ; 
 int BASIC_STACK_SIZE ; 
 int EXTRA_STACK ; 
 int FIXEDBIT ; 
 TYPE_9__* G (TYPE_8__*) ; 
 int GCFINALIZECOST ; 
 int GCSTEPSIZE ; 
 int GCSWEEPCOST ; 
 int GCSWEEPMAX ; 
#define  GCSfinalize 139 
#define  GCSpause 138 
#define  GCSpropagate 137 
#define  GCSsweep 136 
#define  GCSsweepstring 135 
 int KEYWEAK ; 
 int KEYWEAKBIT ; 
 int LUAI_MAXCALLS ; 
 int LUA_MINBUFFER ; 
 scalar_t__ LUA_TDEADKEY ; 
#define  LUA_TFUNCTION 134 
#define  LUA_TPROTO 133 
#define  LUA_TSTRING 132 
#define  LUA_TTABLE 131 
#define  LUA_TTHREAD 130 
#define  LUA_TUPVAL 129 
#define  LUA_TUSERDATA 128 
 int MAX_LUMEM ; 
 int MINSTRTABSIZE ; 
 int NUM_TAGS ; 
 int /*<<< orphan*/  SFIXEDBIT ; 
 int /*<<< orphan*/  TM_GC ; 
 int /*<<< orphan*/  TM_MODE ; 
 int VALUEWEAK ; 
 int VALUEWEAKBIT ; 
 int WHITEBITS ; 
 int bitmask (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  black2gray (TYPE_14__*) ; 
 scalar_t__ cast (int /*<<< orphan*/ ,int) ; 
 int cast_byte (int) ; 
 int cast_int (scalar_t__) ; 
 int /*<<< orphan*/  condhardstacktests (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * fasttm (TYPE_8__*,TYPE_8__*,int /*<<< orphan*/ ) ; 
 TYPE_15__* gco2cl (TYPE_14__*) ; 
 TYPE_8__* gco2h (TYPE_14__*) ; 
 TYPE_13__* gco2p (TYPE_14__*) ; 
 TYPE_8__* gco2th (TYPE_14__*) ; 
 int /*<<< orphan*/  gco2ts (TYPE_14__*) ; 
 TYPE_18__* gco2u (TYPE_14__*) ; 
 TYPE_8__* gco2uv (TYPE_14__*) ; 
 TYPE_14__* gcvalue (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * gfasttm (TYPE_9__*,TYPE_8__*,int /*<<< orphan*/ ) ; 
 scalar_t__ gkey (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * gnode (TYPE_8__*,int) ; 
 int /*<<< orphan*/  gray2black (TYPE_14__*) ; 
 scalar_t__ gt (TYPE_8__*) ; 
 int /*<<< orphan*/ * gval (int /*<<< orphan*/ *) ; 
 scalar_t__ isblack (TYPE_14__*) ; 
 scalar_t__ iscollectable (int /*<<< orphan*/  const*) ; 
 scalar_t__ isdead (TYPE_9__*,TYPE_14__*) ; 
 scalar_t__ isfinalized (TYPE_18__*) ; 
 int isgray (TYPE_14__*) ; 
 scalar_t__ iswhite (TYPE_14__*) ; 
 int /*<<< orphan*/ * key2tval (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lu_int32 ; 
 int /*<<< orphan*/  luaC_barrier (TYPE_8__*,TYPE_8__*,scalar_t__) ; 
 int luaC_white (TYPE_9__*) ; 
 int /*<<< orphan*/  luaD_call (TYPE_8__*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaD_reallocCI (TYPE_8__*,int) ; 
 int /*<<< orphan*/  luaD_reallocstack (TYPE_8__*,int) ; 
 int /*<<< orphan*/  luaE_freethread (TYPE_8__*,TYPE_8__*) ; 
 int /*<<< orphan*/  luaF_freeclosure (TYPE_8__*,TYPE_15__*) ; 
 int /*<<< orphan*/  luaF_freeproto (TYPE_8__*,TYPE_13__*) ; 
 int /*<<< orphan*/  luaF_freeupval (TYPE_8__*,TYPE_8__*) ; 
 int /*<<< orphan*/  luaH_free (TYPE_8__*,TYPE_8__*) ; 
 int /*<<< orphan*/  luaM_freemem (TYPE_8__*,TYPE_14__*,scalar_t__) ; 
 int /*<<< orphan*/  luaS_resize (TYPE_8__*,int) ; 
 int /*<<< orphan*/  luaZ_resizebuffer (TYPE_8__*,int /*<<< orphan*/ *,size_t) ; 
 int luaZ_sizebuffer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_assert (int) ; 
 int /*<<< orphan*/  makewhite (TYPE_9__*,TYPE_14__*) ; 
 int /*<<< orphan*/  markfinalized (TYPE_18__*) ; 
 int /*<<< orphan*/  markobject (TYPE_9__*,TYPE_8__*) ; 
 int /*<<< orphan*/  markvalue (TYPE_9__*,scalar_t__) ; 
 TYPE_14__* obj2gco (TYPE_8__*) ; 
 int otherwhite (TYPE_9__*) ; 
 TYPE_11__* rawgco2u (TYPE_14__*) ; 
 scalar_t__ rawtsvalue (int /*<<< orphan*/  const*) ; 
 scalar_t__ registry (TYPE_8__*) ; 
 int /*<<< orphan*/  setnilvalue (scalar_t__) ; 
 int /*<<< orphan*/  setobj2s (TYPE_8__*,scalar_t__,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  setthreshold (TYPE_9__*) ; 
 int /*<<< orphan*/  setttype (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  setuvalue (TYPE_8__*,scalar_t__,TYPE_11__*) ; 
 int sizeCclosure (int) ; 
 int sizeLclosure (int) ; 
 int sizenode (TYPE_8__*) ; 
 scalar_t__ sizestring (int /*<<< orphan*/ ) ; 
 scalar_t__ sizeudata (TYPE_18__*) ; 
 int /*<<< orphan*/ * strchr (int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  stringmark (scalar_t__) ; 
 int /*<<< orphan*/  svalue (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  sweepwholelist (TYPE_8__*,TYPE_14__**) ; 
 scalar_t__ testbit (int,int) ; 
 int ttisnil (int /*<<< orphan*/ *) ; 
 scalar_t__ ttisstring (int /*<<< orphan*/  const*) ; 
 scalar_t__ ttisuserdata (int /*<<< orphan*/  const*) ; 
 int const ttype (TYPE_19__*) ; 
 TYPE_18__* uvalue (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  white2gray (TYPE_14__*) ; 

__attribute__((used)) static void removeentry (Node *n) {
  lua_assert(ttisnil(gval(n)));
  if (iscollectable(gkey(n)))
    setttype(gkey(n), LUA_TDEADKEY);  /* dead key; remove it */
}

__attribute__((used)) static void reallymarkobject (global_State *g, GCObject *o) {
  lua_assert(iswhite(o) && !isdead(g, o));
  white2gray(o);
  switch (o->gch.tt) {
    case LUA_TSTRING: {
      return;
    }
    case LUA_TUSERDATA: {
      Table *mt = gco2u(o)->metatable;
      gray2black(o);  /* udata are never gray */
      if (mt) markobject(g, mt);
      markobject(g, gco2u(o)->env);
      return;
    }
    case LUA_TUPVAL: {
      UpVal *uv = gco2uv(o);
      markvalue(g, uv->v);
      if (uv->v == &uv->u.value)  /* closed? */
        gray2black(o);  /* open upvalues are never black */
      return;
    }
    case LUA_TFUNCTION: {
      gco2cl(o)->c.gclist = g->gray;
      g->gray = o;
      break;
    }
    case LUA_TTABLE: {
      gco2h(o)->gclist = g->gray;
      g->gray = o;
      break;
    }
    case LUA_TTHREAD: {
      gco2th(o)->gclist = g->gray;
      g->gray = o;
      break;
    }
    case LUA_TPROTO: {
      gco2p(o)->gclist = g->gray;
      g->gray = o;
      break;
    }
    default: lua_assert(0);
  }
}

__attribute__((used)) static void marktmu (global_State *g) {
  GCObject *u = g->tmudata;
  if (u) {
    do {
      u = u->gch.next;
      makewhite(g, u);  /* may be marked, if left from previous GC */
      reallymarkobject(g, u);
    } while (u != g->tmudata);
  }
}

size_t luaC_separateudata (lua_State *L, int all) {
  global_State *g = G(L);
  size_t deadmem = 0;
  GCObject **p = &g->mainthread->next;
  GCObject *curr;
  while ((curr = *p) != NULL) {
    if (!(iswhite(curr) || all) || isfinalized(gco2u(curr)))
      p = &curr->gch.next;  /* don't bother with them */
    else if (fasttm(L, gco2u(curr)->metatable, TM_GC) == NULL) {
      markfinalized(gco2u(curr));  /* don't need finalization */
      p = &curr->gch.next;
    }
    else {  /* must call its gc method */
      deadmem += sizeudata(gco2u(curr));
      markfinalized(gco2u(curr));
      *p = curr->gch.next;
      /* link `curr' at the end of `tmudata' list */
      if (g->tmudata == NULL)  /* list is empty? */
        g->tmudata = curr->gch.next = curr;  /* creates a circular list */
      else {
        curr->gch.next = g->tmudata->gch.next;
        g->tmudata->gch.next = curr;
        g->tmudata = curr;
      }
    }
  }
  return deadmem;
}

__attribute__((used)) static int traversetable (global_State *g, Table *h) {
  int i;
  int weakkey = 0;
  int weakvalue = 0;
  const TValue *mode;
  if (h->metatable)
    markobject(g, h->metatable);
  mode = gfasttm(g, h->metatable, TM_MODE);
  if (mode && ttisstring(mode)) {  /* is there a weak mode? */
    weakkey = (strchr(svalue(mode), 'k') != NULL);
    weakvalue = (strchr(svalue(mode), 'v') != NULL);
    if (weakkey || weakvalue) {  /* is really weak? */
      h->marked &= ~(KEYWEAK | VALUEWEAK);  /* clear bits */
      h->marked |= cast_byte((weakkey << KEYWEAKBIT) |
                             (weakvalue << VALUEWEAKBIT));
      h->gclist = g->weak;  /* must be cleared after GC, ... */
      g->weak = obj2gco(h);  /* ... so put in the appropriate list */
    }
  }
  if (weakkey && weakvalue) return 1;
  if (!weakvalue) {
    i = h->sizearray;
    while (i--)
      markvalue(g, &h->array[i]);
  }
  i = sizenode(h);
  while (i--) {
    Node *n = gnode(h, i);
    lua_assert(ttype(gkey(n)) != LUA_TDEADKEY || ttisnil(gval(n)));
    if (ttisnil(gval(n)))
      removeentry(n);  /* remove empty entries */
    else {
      lua_assert(!ttisnil(gkey(n)));
      if (!weakkey) markvalue(g, gkey(n));
      if (!weakvalue) markvalue(g, gval(n));
    }
  }
  return weakkey || weakvalue;
}

__attribute__((used)) static void traverseproto (global_State *g, Proto *f) {
  int i;
  if (f->source) stringmark(f->source);
  for (i=0; i<f->sizek; i++)  /* mark literals */
    markvalue(g, &f->k[i]);
  for (i=0; i<f->sizeupvalues; i++) {  /* mark upvalue names */
    if (f->upvalues[i])
      stringmark(f->upvalues[i]);
  }
  for (i=0; i<f->sizep; i++) {  /* mark nested protos */
    if (f->p[i])
      markobject(g, f->p[i]);
  }
  for (i=0; i<f->sizelocvars; i++) {  /* mark local-variable names */
    if (f->locvars[i].varname)
      stringmark(f->locvars[i].varname);
  }
}

__attribute__((used)) static void traverseclosure (global_State *g, Closure *cl) {
  markobject(g, cl->c.env);
  if (cl->c.isC) {
    int i;
    for (i=0; i<cl->c.nupvalues; i++)  /* mark its upvalues */
      markvalue(g, &cl->c.upvalue[i]);
  }
  else {
    int i;
    lua_assert(cl->l.nupvalues == cl->l.p->nups);
    markobject(g, cl->l.p);
    for (i=0; i<cl->l.nupvalues; i++)  /* mark its upvalues */
      markobject(g, cl->l.upvals[i]);
  }
}

__attribute__((used)) static void checkstacksizes (lua_State *L, StkId max) {
  int ci_used = cast_int(L->ci - L->base_ci);  /* number of `ci' in use */
  int s_used = cast_int(max - L->stack);  /* part of stack in use */
  if (L->size_ci > LUAI_MAXCALLS)  /* handling overflow? */
    return;  /* do not touch the stacks */
  if (4*ci_used < L->size_ci && 2*BASIC_CI_SIZE < L->size_ci)
    luaD_reallocCI(L, L->size_ci/2);  /* still big enough... */
  condhardstacktests(luaD_reallocCI(L, ci_used + 1));
  if (4*s_used < L->stacksize &&
      2*(BASIC_STACK_SIZE+EXTRA_STACK) < L->stacksize)
    luaD_reallocstack(L, L->stacksize/2);  /* still big enough... */
  condhardstacktests(luaD_reallocstack(L, s_used));
}

__attribute__((used)) static void traversestack (global_State *g, lua_State *l) {
  StkId o, lim;
  CallInfo *ci;
  markvalue(g, gt(l));
  lim = l->top;
  for (ci = l->base_ci; ci <= l->ci; ci++) {
    lua_assert(ci->top <= l->stack_last);
    if (lim < ci->top) lim = ci->top;
  }
  for (o = l->stack; o < l->top; o++)
    markvalue(g, o);
  for (; o <= lim; o++)
    setnilvalue(o);
  checkstacksizes(l, lim);
}

__attribute__((used)) static l_mem propagatemark (global_State *g) {
  GCObject *o = g->gray;
  lua_assert(isgray(o));
  gray2black(o);
  switch (o->gch.tt) {
    case LUA_TTABLE: {
      Table *h = gco2h(o);
      g->gray = h->gclist;
      if (traversetable(g, h))  /* table is weak? */
        black2gray(o);  /* keep it gray */
      return sizeof(Table) + sizeof(TValue) * h->sizearray +
                             sizeof(Node) * sizenode(h);
    }
    case LUA_TFUNCTION: {
      Closure *cl = gco2cl(o);
      g->gray = cl->c.gclist;
      traverseclosure(g, cl);
      return (cl->c.isC) ? sizeCclosure(cl->c.nupvalues) :
                           sizeLclosure(cl->l.nupvalues);
    }
    case LUA_TTHREAD: {
      lua_State *th = gco2th(o);
      g->gray = th->gclist;
      th->gclist = g->grayagain;
      g->grayagain = o;
      black2gray(o);
      traversestack(g, th);
      return sizeof(lua_State) + sizeof(TValue) * th->stacksize +
                                 sizeof(CallInfo) * th->size_ci;
    }
    case LUA_TPROTO: {
      Proto *p = gco2p(o);
      g->gray = p->gclist;
      traverseproto(g, p);
      return sizeof(Proto) + sizeof(Instruction) * p->sizecode +
                             sizeof(Proto *) * p->sizep +
                             sizeof(TValue) * p->sizek + 
                             sizeof(int) * p->sizelineinfo +
                             sizeof(LocVar) * p->sizelocvars +
                             sizeof(TString *) * p->sizeupvalues;
    }
    default: lua_assert(0); return 0;
  }
}

__attribute__((used)) static size_t propagateall (global_State *g) {
  size_t m = 0;
  while (g->gray) m += propagatemark(g);
  return m;
}

__attribute__((used)) static int iscleared (const TValue *o, int iskey) {
  if (!iscollectable(o)) return 0;
  if (ttisstring(o)) {
    stringmark(rawtsvalue(o));  /* strings are `values', so are never weak */
    return 0;
  }
  return iswhite(gcvalue(o)) ||
    (ttisuserdata(o) && (!iskey && isfinalized(uvalue(o))));
}

__attribute__((used)) static void cleartable (GCObject *l) {
  while (l) {
    Table *h = gco2h(l);
    int i = h->sizearray;
    lua_assert(testbit(h->marked, VALUEWEAKBIT) ||
               testbit(h->marked, KEYWEAKBIT));
    if (testbit(h->marked, VALUEWEAKBIT)) {
      while (i--) {
        TValue *o = &h->array[i];
        if (iscleared(o, 0))  /* value was collected? */
          setnilvalue(o);  /* remove value */
      }
    }
    i = sizenode(h);
    while (i--) {
      Node *n = gnode(h, i);
      if (!ttisnil(gval(n)) &&  /* non-empty entry? */
          (iscleared(key2tval(n), 1) || iscleared(gval(n), 0))) {
        setnilvalue(gval(n));  /* remove value ... */
        removeentry(n);  /* remove entry from table */
      }
    }
    l = h->gclist;
  }
}

__attribute__((used)) static void freeobj (lua_State *L, GCObject *o) {
  switch (o->gch.tt) {
    case LUA_TPROTO: luaF_freeproto(L, gco2p(o)); break;
    case LUA_TFUNCTION: luaF_freeclosure(L, gco2cl(o)); break;
    case LUA_TUPVAL: luaF_freeupval(L, gco2uv(o)); break;
    case LUA_TTABLE: luaH_free(L, gco2h(o)); break;
    case LUA_TTHREAD: {
      lua_assert(gco2th(o) != L && gco2th(o) != G(L)->mainthread);
      luaE_freethread(L, gco2th(o));
      break;
    }
    case LUA_TSTRING: {
      G(L)->strt.nuse--;
      luaM_freemem(L, o, sizestring(gco2ts(o)));
      break;
    }
    case LUA_TUSERDATA: {
      luaM_freemem(L, o, sizeudata(gco2u(o)));
      break;
    }
    default: lua_assert(0);
  }
}

__attribute__((used)) static GCObject **sweeplist (lua_State *L, GCObject **p, lu_mem count) {
  GCObject *curr;
  global_State *g = G(L);
  int deadmask = otherwhite(g);
  while ((curr = *p) != NULL && count-- > 0) {
    if (curr->gch.tt == LUA_TTHREAD)  /* sweep open upvalues of each thread */
      sweepwholelist(L, &gco2th(curr)->openupval);
    if ((curr->gch.marked ^ WHITEBITS) & deadmask) {  /* not dead? */
      lua_assert(!isdead(g, curr) || testbit(curr->gch.marked, FIXEDBIT));
      makewhite(g, curr);  /* make it white (for next cycle) */
      p = &curr->gch.next;
    }
    else {  /* must erase `curr' */
      lua_assert(isdead(g, curr) || deadmask == bitmask(SFIXEDBIT));
      *p = curr->gch.next;
      if (curr == g->rootgc)  /* is the first element of the list? */
        g->rootgc = curr->gch.next;  /* adjust first */
      freeobj(L, curr);
    }
  }
  return p;
}

__attribute__((used)) static void checkSizes (lua_State *L) {
  global_State *g = G(L);
  /* check size of string hash */
  if (g->strt.nuse < cast(lu_int32, g->strt.size/4) &&
      g->strt.size > MINSTRTABSIZE*2)
    luaS_resize(L, g->strt.size/2);  /* table is too big */
  /* check size of buffer */
  if (luaZ_sizebuffer(&g->buff) > LUA_MINBUFFER*2) {  /* buffer too big? */
    size_t newsize = luaZ_sizebuffer(&g->buff) / 2;
    luaZ_resizebuffer(L, &g->buff, newsize);
  }
}

__attribute__((used)) static void GCTM (lua_State *L) {
  global_State *g = G(L);
  GCObject *o = g->tmudata->gch.next;  /* get first element */
  Udata *udata = rawgco2u(o);
  const TValue *tm;
  /* remove udata from `tmudata' */
  if (o == g->tmudata)  /* last element? */
    g->tmudata = NULL;
  else
    g->tmudata->gch.next = udata->uv.next;
  udata->uv.next = g->mainthread->next;  /* return it to `root' list */
  g->mainthread->next = o;
  makewhite(g, o);
  tm = fasttm(L, udata->uv.metatable, TM_GC);
  if (tm != NULL) {
    lu_byte oldah = L->allowhook;
    lu_mem oldt = g->GCthreshold;
    L->allowhook = 0;  /* stop debug hooks during GC tag method */
    g->GCthreshold = 2*g->totalbytes;  /* avoid GC steps */
    setobj2s(L, L->top, tm);
    setuvalue(L, L->top+1, udata);
    L->top += 2;
    luaD_call(L, L->top - 2, 0);
    L->allowhook = oldah;  /* restore hooks */
    g->GCthreshold = oldt;  /* restore threshold */
  }
}

void luaC_callGCTM (lua_State *L) {
  while (G(L)->tmudata)
    GCTM(L);
}

void luaC_freeall (lua_State *L) {
  global_State *g = G(L);
  int i;
  g->currentwhite = WHITEBITS | bitmask(SFIXEDBIT);  /* mask to collect all elements */
  sweepwholelist(L, &g->rootgc);
  for (i = 0; i < g->strt.size; i++)  /* free all string lists */
    sweepwholelist(L, &g->strt.hash[i]);
}

__attribute__((used)) static void markmt (global_State *g) {
  int i;
  for (i=0; i<NUM_TAGS; i++)
    if (g->mt[i]) markobject(g, g->mt[i]);
}

__attribute__((used)) static void markroot (lua_State *L) {
  global_State *g = G(L);
  g->gray = NULL;
  g->grayagain = NULL;
  g->weak = NULL;
  markobject(g, g->mainthread);
  /* make global table be traversed before main stack */
  markvalue(g, gt(g->mainthread));
  markvalue(g, registry(L));
  markmt(g);
  g->gcstate = GCSpropagate;
}

__attribute__((used)) static void remarkupvals (global_State *g) {
  UpVal *uv;
  for (uv = g->uvhead.u.l.next; uv != &g->uvhead; uv = uv->u.l.next) {
    lua_assert(uv->u.l.next->u.l.prev == uv && uv->u.l.prev->u.l.next == uv);
    if (isgray(obj2gco(uv)))
      markvalue(g, uv->v);
  }
}

__attribute__((used)) static void atomic (lua_State *L) {
  global_State *g = G(L);
  size_t udsize;  /* total size of userdata to be finalized */
  /* remark occasional upvalues of (maybe) dead threads */
  remarkupvals(g);
  /* traverse objects cautch by write barrier and by 'remarkupvals' */
  propagateall(g);
  /* remark weak tables */
  g->gray = g->weak;
  g->weak = NULL;
  lua_assert(!iswhite(obj2gco(g->mainthread)));
  markobject(g, L);  /* mark running thread */
  markmt(g);  /* mark basic metatables (again) */
  propagateall(g);
  /* remark gray again */
  g->gray = g->grayagain;
  g->grayagain = NULL;
  propagateall(g);
  udsize = luaC_separateudata(L, 0);  /* separate userdata to be finalized */
  marktmu(g);  /* mark `preserved' userdata */
  udsize += propagateall(g);  /* remark, to propagate `preserveness' */
  cleartable(g->weak);  /* remove collected objects from weak tables */
  /* flip current white */
  g->currentwhite = cast_byte(otherwhite(g));
  g->sweepstrgc = 0;
  g->sweepgc = &g->rootgc;
  g->gcstate = GCSsweepstring;
  g->estimate = g->totalbytes - udsize;  /* first estimate */
}

__attribute__((used)) static l_mem singlestep (lua_State *L) {
  global_State *g = G(L);
  /*lua_checkmemory(L);*/
  switch (g->gcstate) {
    case GCSpause: {
      markroot(L);  /* start a new collection */
      return 0;
    }
    case GCSpropagate: {
      if (g->gray)
        return propagatemark(g);
      else {  /* no more `gray' objects */
        atomic(L);  /* finish mark phase */
        return 0;
      }
    }
    case GCSsweepstring: {
      lu_mem old = g->totalbytes;
      sweepwholelist(L, &g->strt.hash[g->sweepstrgc++]);
      if (g->sweepstrgc >= g->strt.size)  /* nothing more to sweep? */
        g->gcstate = GCSsweep;  /* end sweep-string phase */
      lua_assert(old >= g->totalbytes);
      g->estimate -= old - g->totalbytes;
      return GCSWEEPCOST;
    }
    case GCSsweep: {
      lu_mem old = g->totalbytes;
      g->sweepgc = sweeplist(L, g->sweepgc, GCSWEEPMAX);
      if (*g->sweepgc == NULL) {  /* nothing more to sweep? */
        checkSizes(L);
        g->gcstate = GCSfinalize;  /* end sweep phase */
      }
      lua_assert(old >= g->totalbytes);
      g->estimate -= old - g->totalbytes;
      return GCSWEEPMAX*GCSWEEPCOST;
    }
    case GCSfinalize: {
      if (g->tmudata) {
        GCTM(L);
        if (g->estimate > GCFINALIZECOST)
          g->estimate -= GCFINALIZECOST;
        return GCFINALIZECOST;
      }
      else {
        g->gcstate = GCSpause;  /* end collection */
        g->gcdept = 0;
        return 0;
      }
    }
    default: lua_assert(0); return 0;
  }
}

void luaC_step (lua_State *L) {
  global_State *g = G(L);
  l_mem lim = (GCSTEPSIZE/100) * g->gcstepmul;
  if (lim == 0)
    lim = (MAX_LUMEM-1)/2;  /* no limit */
  g->gcdept += g->totalbytes - g->GCthreshold;
  do {
    lim -= singlestep(L);
    if (g->gcstate == GCSpause)
      break;
  } while (lim > 0);
  if (g->gcstate != GCSpause) {
    if (g->gcdept < GCSTEPSIZE)
      g->GCthreshold = g->totalbytes + GCSTEPSIZE;  /* - lim/g->gcstepmul;*/
    else {
      g->gcdept -= GCSTEPSIZE;
      g->GCthreshold = g->totalbytes;
    }
  }
  else {
    setthreshold(g);
  }
}

void luaC_fullgc (lua_State *L) {
  global_State *g = G(L);
  if (g->gcstate <= GCSpropagate) {
    /* reset sweep marks to sweep all elements (returning them to white) */
    g->sweepstrgc = 0;
    g->sweepgc = &g->rootgc;
    /* reset other collector lists */
    g->gray = NULL;
    g->grayagain = NULL;
    g->weak = NULL;
    g->gcstate = GCSsweepstring;
  }
  lua_assert(g->gcstate != GCSpause && g->gcstate != GCSpropagate);
  /* finish any pending sweep phase */
  while (g->gcstate != GCSfinalize) {
    lua_assert(g->gcstate == GCSsweepstring || g->gcstate == GCSsweep);
    singlestep(L);
  }
  markroot(L);
  while (g->gcstate != GCSpause) {
    singlestep(L);
  }
  setthreshold(g);
}

void luaC_barrierf (lua_State *L, GCObject *o, GCObject *v) {
  global_State *g = G(L);
  lua_assert(isblack(o) && iswhite(v) && !isdead(g, v) && !isdead(g, o));
  lua_assert(g->gcstate != GCSfinalize && g->gcstate != GCSpause);
  lua_assert(ttype(&o->gch) != LUA_TTABLE);
  /* must keep invariant? */
  if (g->gcstate == GCSpropagate)
    reallymarkobject(g, v);  /* restore invariant */
  else  /* don't mind */
    makewhite(g, o);  /* mark as white just to avoid other barriers */
}

void luaC_barrierback (lua_State *L, Table *t) {
  global_State *g = G(L);
  GCObject *o = obj2gco(t);
  lua_assert(isblack(o) && !isdead(g, o));
  lua_assert(g->gcstate != GCSfinalize && g->gcstate != GCSpause);
  black2gray(o);  /* make table gray (again) */
  t->gclist = g->grayagain;
  g->grayagain = o;
}

void luaC_link (lua_State *L, GCObject *o, lu_byte tt) {
  global_State *g = G(L);
  o->gch.next = g->rootgc;
  g->rootgc = o;
  o->gch.marked = luaC_white(g);
  o->gch.tt = tt;
}

void luaC_linkupval (lua_State *L, UpVal *uv) {
  global_State *g = G(L);
  GCObject *o = obj2gco(uv);
  o->gch.next = g->rootgc;  /* link upvalue into `rootgc' list */
  g->rootgc = o;
  if (isgray(o)) { 
    if (g->gcstate == GCSpropagate) {
      gray2black(o);  /* closed upvalues need barrier */
      luaC_barrier(L, uv, uv->v);
    }
    else {  /* sweep phase: sweep it (turning it into white) */
      makewhite(g, o);
      lua_assert(g->gcstate != GCSfinalize && g->gcstate != GCSpause);
    }
  }
}

