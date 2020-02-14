#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_6__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct TYPE_19__ {struct REnv* env; struct RClass* target_class; } ;
struct TYPE_18__ {TYPE_5__* irep; } ;
struct RProc {int /*<<< orphan*/  flags; TYPE_3__ e; TYPE_2__ body; struct RProc* upper; } ;
struct REnv {struct RClass* c; TYPE_1__* cxt; int /*<<< orphan*/  stack; int /*<<< orphan*/  mid; } ;
struct RClass {int dummy; } ;
struct RBasic {int dummy; } ;
struct TYPE_20__ {TYPE_1__* c; int /*<<< orphan*/ * proc_class; } ;
typedef  TYPE_4__ mrb_state ;
struct TYPE_21__ {int /*<<< orphan*/  nlocals; } ;
typedef  TYPE_5__ mrb_irep ;
typedef  int /*<<< orphan*/  mrb_int ;
struct TYPE_22__ {int argc; struct REnv* env; int /*<<< orphan*/  mid; struct RProc* proc; struct RClass* target_class; } ;
typedef  TYPE_6__ mrb_callinfo ;
struct TYPE_17__ {TYPE_6__* ci; int /*<<< orphan*/  stack; } ;

/* Variables and functions */
 int /*<<< orphan*/  MRB_ENV_SET_BIDX (struct REnv*,int) ; 
 int /*<<< orphan*/  MRB_ENV_SET_STACK_LEN (struct REnv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MRB_PROC_ENVSET ; 
 struct RClass* MRB_PROC_TARGET_CLASS (struct RProc*) ; 
 int /*<<< orphan*/  MRB_TT_ENV ; 
 int /*<<< orphan*/  MRB_TT_PROC ; 
 int /*<<< orphan*/  mrb_field_write_barrier (TYPE_4__*,struct RBasic*,struct RBasic*) ; 
 int /*<<< orphan*/  mrb_irep_incref (TYPE_4__*,TYPE_5__*) ; 
 scalar_t__ mrb_obj_alloc (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

struct RProc*
mrb_proc_new(mrb_state *mrb, mrb_irep *irep)
{
  struct RProc *p;
  mrb_callinfo *ci = mrb->c->ci;

  p = (struct RProc*)mrb_obj_alloc(mrb, MRB_TT_PROC, mrb->proc_class);
  if (ci) {
    struct RClass *tc = NULL;

    if (ci->proc) {
      tc = MRB_PROC_TARGET_CLASS(ci->proc);
    }
    if (tc == NULL) {
      tc = ci->target_class;
    }
    p->upper = ci->proc;
    p->e.target_class = tc;
  }
  p->body.irep = irep;
  mrb_irep_incref(mrb, irep);

  return p;
}

__attribute__((used)) static struct REnv*
env_new(mrb_state *mrb, mrb_int nlocals)
{
  struct REnv *e;
  mrb_callinfo *ci = mrb->c->ci;
  int bidx;

  e = (struct REnv*)mrb_obj_alloc(mrb, MRB_TT_ENV, NULL);
  MRB_ENV_SET_STACK_LEN(e, nlocals);
  bidx = ci->argc;
  if (ci->argc < 0) bidx = 2;
  else bidx += 1;
  MRB_ENV_SET_BIDX(e, bidx);
  e->mid = ci->mid;
  e->stack = mrb->c->stack;
  e->cxt = mrb->c;

  return e;
}

__attribute__((used)) static void
closure_setup(mrb_state *mrb, struct RProc *p)
{
  mrb_callinfo *ci = mrb->c->ci;
  struct RProc *up = p->upper;
  struct REnv *e = NULL;

  if (ci && ci->env) {
    e = ci->env;
  }
  else if (up) {
    struct RClass *tc = MRB_PROC_TARGET_CLASS(p);

    e = env_new(mrb, up->body.irep->nlocals);
    ci->env = e;
    if (tc) {
      e->c = tc;
      mrb_field_write_barrier(mrb, (struct RBasic*)e, (struct RBasic*)tc);
    }
  }
  if (e) {
    p->e.env = e;
    p->flags |= MRB_PROC_ENVSET;
    mrb_field_write_barrier(mrb, (struct RBasic*)p, (struct RBasic*)e);
  }
}

struct RProc*
mrb_closure_new(mrb_state *mrb, mrb_irep *irep)
{
  struct RProc *p = mrb_proc_new(mrb, irep);

  closure_setup(mrb, p);
  return p;
}

