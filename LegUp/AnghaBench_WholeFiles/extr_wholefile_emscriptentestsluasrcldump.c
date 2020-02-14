#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_6__ ;
typedef  struct TYPE_34__   TYPE_5__ ;
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ (* lua_Writer ) (int /*<<< orphan*/ *,void const*,size_t,void*) ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  size_t lua_Number ;
typedef  int /*<<< orphan*/  lu_byte ;
struct TYPE_35__ {scalar_t__ status; scalar_t__ (* writer ) (int /*<<< orphan*/ *,void const*,size_t,void*) ;int strip; void* data; int /*<<< orphan*/ * L; } ;
struct TYPE_34__ {int sizek; int sizep; int sizeupvalues; int sizelineinfo; void* lineinfo; int sizelocvars; int linedefined; int lastlinedefined; int numparams; int is_vararg; int maxstacksize; TYPE_3__* upvalues; TYPE_2__* locvars; TYPE_4__* source; struct TYPE_34__ const** p; int /*<<< orphan*/ * k; } ;
struct TYPE_30__ {int len; } ;
struct TYPE_33__ {TYPE_1__ tsv; } ;
struct TYPE_32__ {int instack; int idx; TYPE_4__* name; } ;
struct TYPE_31__ {int startpc; int endpc; TYPE_4__* varname; } ;
typedef  int /*<<< orphan*/  TValue ;
typedef  TYPE_4__ TString ;
typedef  TYPE_5__ Proto ;
typedef  TYPE_6__ DumpState ;

/* Variables and functions */
 int /*<<< orphan*/  DumpCode (TYPE_5__ const*,TYPE_6__*) ; 
static  void DumpFunction (TYPE_5__ const*,TYPE_6__*) ; 
 int /*<<< orphan*/  DumpMem (void const*,int,size_t,TYPE_6__*) ; 
 int /*<<< orphan*/  DumpVar (size_t,TYPE_6__*) ; 
 int LUAC_HEADERSIZE ; 
#define  LUA_TBOOLEAN 131 
#define  LUA_TNIL 130 
#define  LUA_TNUMBER 129 
#define  LUA_TSTRING 128 
 int bvalue (int /*<<< orphan*/  const*) ; 
 void* getstr (TYPE_4__ const*) ; 
 int /*<<< orphan*/  luaU_header (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_unlock (int /*<<< orphan*/ *) ; 
 size_t nvalue (int /*<<< orphan*/  const*) ; 
 TYPE_4__* rawtsvalue (int /*<<< orphan*/  const*) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ *,void const*,size_t,void*) ; 
 int ttypenv (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void DumpBlock(const void* b, size_t size, DumpState* D)
{
 if (D->status==0)
 {
  lua_unlock(D->L);
  D->status=(*D->writer)(D->L,b,size,D->data);
  lua_lock(D->L);
 }
}

__attribute__((used)) static void DumpChar(int y, DumpState* D)
{
 char x=(char)y;
 DumpVar(x,D);
}

__attribute__((used)) static void DumpInt(int x, DumpState* D)
{
 DumpVar(x,D);
}

__attribute__((used)) static void DumpNumber(lua_Number x, DumpState* D)
{
 DumpVar(x,D);
}

__attribute__((used)) static void DumpVector(const void* b, int n, size_t size, DumpState* D)
{
 DumpInt(n,D);
 DumpMem(b,n,size,D);
}

__attribute__((used)) static void DumpString(const TString* s, DumpState* D)
{
 if (s==NULL)
 {
  size_t size=0;
  DumpVar(size,D);
 }
 else
 {
  size_t size=s->tsv.len+1;		/* include trailing '\0' */
  DumpVar(size,D);
  DumpBlock(getstr(s),size*sizeof(char),D);
 }
}

__attribute__((used)) static void DumpConstants(const Proto* f, DumpState* D)
{
 int i,n=f->sizek;
 DumpInt(n,D);
 for (i=0; i<n; i++)
 {
  const TValue* o=&f->k[i];
  DumpChar(ttypenv(o),D);
  switch (ttypenv(o))
  {
   case LUA_TNIL:
	break;
   case LUA_TBOOLEAN:
	DumpChar(bvalue(o),D);
	break;
   case LUA_TNUMBER:
	DumpNumber(nvalue(o),D);
	break;
   case LUA_TSTRING:
	DumpString(rawtsvalue(o),D);
	break;
    default: lua_assert(0);
  }
 }
 n=f->sizep;
 DumpInt(n,D);
 for (i=0; i<n; i++) DumpFunction(f->p[i],D);
}

__attribute__((used)) static void DumpUpvalues(const Proto* f, DumpState* D)
{
 int i,n=f->sizeupvalues;
 DumpInt(n,D);
 for (i=0; i<n; i++)
 {
  DumpChar(f->upvalues[i].instack,D);
  DumpChar(f->upvalues[i].idx,D);
 }
}

__attribute__((used)) static void DumpDebug(const Proto* f, DumpState* D)
{
 int i,n;
 DumpString((D->strip) ? NULL : f->source,D);
 n= (D->strip) ? 0 : f->sizelineinfo;
 DumpVector(f->lineinfo,n,sizeof(int),D);
 n= (D->strip) ? 0 : f->sizelocvars;
 DumpInt(n,D);
 for (i=0; i<n; i++)
 {
  DumpString(f->locvars[i].varname,D);
  DumpInt(f->locvars[i].startpc,D);
  DumpInt(f->locvars[i].endpc,D);
 }
 n= (D->strip) ? 0 : f->sizeupvalues;
 DumpInt(n,D);
 for (i=0; i<n; i++) DumpString(f->upvalues[i].name,D);
}

__attribute__((used)) static void DumpFunction(const Proto* f, DumpState* D)
{
 DumpInt(f->linedefined,D);
 DumpInt(f->lastlinedefined,D);
 DumpChar(f->numparams,D);
 DumpChar(f->is_vararg,D);
 DumpChar(f->maxstacksize,D);
 DumpCode(f,D);
 DumpConstants(f,D);
 DumpUpvalues(f,D);
 DumpDebug(f,D);
}

__attribute__((used)) static void DumpHeader(DumpState* D)
{
 lu_byte h[LUAC_HEADERSIZE];
 luaU_header(h);
 DumpBlock(h,LUAC_HEADERSIZE,D);
}

int luaU_dump (lua_State* L, const Proto* f, lua_Writer w, void* data, int strip)
{
 DumpState D;
 D.L=L;
 D.writer=w;
 D.data=data;
 D.strip=strip;
 D.status=0;
 DumpHeader(&D);
 DumpFunction(f,&D);
 return D.status;
}

