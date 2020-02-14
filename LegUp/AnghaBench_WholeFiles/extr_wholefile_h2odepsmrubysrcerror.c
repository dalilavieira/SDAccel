#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_25__ ;
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
struct RObject {int dummy; } ;
struct RClass {int dummy; } ;
struct RBasic {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_29__ {int arena_idx; int /*<<< orphan*/  out_of_memory; struct RBasic** arena; } ;
struct TYPE_30__ {int /*<<< orphan*/  jmp; int /*<<< orphan*/  eException_class; struct RObject* exc; TYPE_3__ gc; TYPE_1__* c; } ;
typedef  TYPE_4__ mrb_state ;
struct TYPE_31__ {int iseq; } ;
typedef  TYPE_5__ mrb_irep ;
typedef  int /*<<< orphan*/  mrb_code ;
struct TYPE_32__ {int /*<<< orphan*/ * pc; TYPE_25__* proc; int /*<<< orphan*/ * err; } ;
typedef  TYPE_6__ mrb_callinfo ;
typedef  int int32_t ;
struct TYPE_28__ {TYPE_5__* irep; } ;
struct TYPE_27__ {TYPE_2__ body; } ;
struct TYPE_26__ {TYPE_6__* cibase; TYPE_6__* ci; } ;

/* Variables and functions */
 struct RClass* E_TYPE_ERROR ; 
 int /*<<< orphan*/  MRB_FROZEN_P (struct RObject*) ; 
 int /*<<< orphan*/  MRB_PROC_CFUNC_P (TYPE_25__*) ; 
 int /*<<< orphan*/  MRB_THROW (int /*<<< orphan*/ ) ; 
 int RARRAY_LEN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * RARRAY_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  mrb_array_p (int /*<<< orphan*/ ) ; 
 char* mrb_debug_get_filename (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int mrb_debug_get_line (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_exc_new_str (TYPE_4__*,struct RClass*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_fixnum_value (int const) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_4__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_intern_lit (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  mrb_iv_set (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_keep_backtrace (TYPE_4__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_nil_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_obj_is_kind_of (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_obj_iv_defined (TYPE_4__*,struct RObject*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_obj_iv_set (TYPE_4__*,struct RObject*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct RObject* mrb_obj_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_p (TYPE_4__*,int /*<<< orphan*/ ) ; 
 void mrb_raise (TYPE_4__*,struct RClass*,char const*) ; 
 int /*<<< orphan*/  mrb_str_new_cstr (TYPE_4__*,char const*) ; 
 int /*<<< orphan*/  mrb_string_p (int /*<<< orphan*/  const) ; 

__attribute__((used)) static void
set_backtrace(mrb_state *mrb, mrb_value exc, mrb_value backtrace)
{
  if (!mrb_array_p(backtrace)) {
  type_err:
    mrb_raise(mrb, E_TYPE_ERROR, "backtrace must be Array of String");
  }
  else {
    const mrb_value *p = RARRAY_PTR(backtrace);
    const mrb_value *pend = p + RARRAY_LEN(backtrace);

    while (p < pend) {
      if (!mrb_string_p(*p)) goto type_err;
      p++;
    }
  }
  mrb_iv_set(mrb, exc, mrb_intern_lit(mrb, "backtrace"), backtrace);
}

__attribute__((used)) static mrb_value
exc_set_backtrace(mrb_state *mrb, mrb_value exc)
{
  mrb_value backtrace;

  mrb_get_args(mrb, "o", &backtrace);
  set_backtrace(mrb, exc, backtrace);
  return backtrace;
}

__attribute__((used)) static void
exc_debug_info(mrb_state *mrb, struct RObject *exc)
{
  mrb_callinfo *ci = mrb->c->ci;
  mrb_code *pc = ci->pc;

  if (mrb_obj_iv_defined(mrb, exc, mrb_intern_lit(mrb, "file"))) return;
  while (ci >= mrb->c->cibase) {
    mrb_code *err = ci->err;

    if (!err && pc) err = pc - 1;
    if (err && ci->proc && !MRB_PROC_CFUNC_P(ci->proc)) {
      mrb_irep *irep = ci->proc->body.irep;

      int32_t const line = mrb_debug_get_line(irep, err - irep->iseq);
      char const* file = mrb_debug_get_filename(irep, err - irep->iseq);
      if (line != -1 && file) {
        mrb_obj_iv_set(mrb, exc, mrb_intern_lit(mrb, "file"), mrb_str_new_cstr(mrb, file));
        mrb_obj_iv_set(mrb, exc, mrb_intern_lit(mrb, "line"), mrb_fixnum_value(line));
        return;
      }
    }
    pc = ci->pc;
    ci--;
  }
}

void
mrb_exc_set(mrb_state *mrb, mrb_value exc)
{
  if (mrb_nil_p(exc)) {
    mrb->exc = 0;
  }
  else {
    mrb->exc = mrb_obj_ptr(exc);
    if (mrb->gc.arena_idx > 0 &&
        (struct RBasic*)mrb->exc == mrb->gc.arena[mrb->gc.arena_idx-1]) {
      mrb->gc.arena_idx--;
    }
    if (!mrb->gc.out_of_memory && !MRB_FROZEN_P(mrb->exc)) {
      exc_debug_info(mrb, mrb->exc);
      mrb_keep_backtrace(mrb, exc);
    }
  }
}

void
mrb_exc_raise(mrb_state *mrb, mrb_value exc)
{
  if (!mrb_obj_is_kind_of(mrb, exc, mrb->eException_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "exception object expected");
  }
  mrb_exc_set(mrb, exc);
  if (!mrb->jmp) {
    mrb_p(mrb, exc);
    abort();
  }
  MRB_THROW(mrb->jmp);
}

void
mrb_raise(mrb_state *mrb, struct RClass *c, const char *msg)
{
  mrb_exc_raise(mrb, mrb_exc_new_str(mrb, c, mrb_str_new_cstr(mrb, msg)));
}

