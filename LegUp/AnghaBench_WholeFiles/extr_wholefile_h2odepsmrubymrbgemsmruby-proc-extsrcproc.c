#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
struct mrb_irep {scalar_t__* iseq; int nlocals; TYPE_2__* lv; } ;
struct TYPE_30__ {struct mrb_irep* irep; } ;
typedef  struct RProc {TYPE_1__ body; } const RProc ;
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_sym ;
struct TYPE_32__ {struct RClass* kernel_module; struct RClass* proc_class; } ;
typedef  TYPE_3__ mrb_state ;
typedef  struct mrb_irep mrb_irep ;
typedef  int /*<<< orphan*/  mrb_aspec ;
typedef  int int32_t ;
struct TYPE_31__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int MRB_ASPEC_BLOCK (int /*<<< orphan*/ ) ; 
 int MRB_ASPEC_OPT (int /*<<< orphan*/ ) ; 
 int MRB_ASPEC_POST (int /*<<< orphan*/ ) ; 
 int MRB_ASPEC_REQ (int /*<<< orphan*/ ) ; 
 int MRB_ASPEC_REST (int /*<<< orphan*/ ) ; 
 scalar_t__ MRB_PROC_CFUNC_P (struct RProc const*) ; 
 scalar_t__ MRB_PROC_STRICT_P (struct RProc const*) ; 
 scalar_t__ OP_ENTER ; 
 int /*<<< orphan*/  PEEK_W (scalar_t__*) ; 
 int /*<<< orphan*/  mrb_ary_new (TYPE_3__*) ; 
 int /*<<< orphan*/  mrb_ary_new_capa (TYPE_3__*,int) ; 
 int /*<<< orphan*/  mrb_ary_push (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_assoc_new (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_bool_value (scalar_t__) ; 
 int /*<<< orphan*/  mrb_cptr (int /*<<< orphan*/ ) ; 
 char* mrb_debug_get_filename (struct mrb_irep*,int /*<<< orphan*/ ) ; 
 int mrb_debug_get_line (struct mrb_irep*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_class_method (TYPE_3__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_3__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_3__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_3__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_fixnum_value (int) ; 
 int /*<<< orphan*/  mrb_format (TYPE_3__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_3__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_intern_static (TYPE_3__*,char*,int) ; 
 scalar_t__ mrb_nil_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 
 struct RProc const* mrb_proc_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_ptr_to_str (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_str_cat_cstr (TYPE_3__*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  mrb_str_cat_lit (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_str_concat (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_str_new_cstr (TYPE_3__*,char const*) ; 
 int /*<<< orphan*/  mrb_str_new_lit (TYPE_3__*,char*) ; 
 char* mrb_sym2name (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_symbol_value (int /*<<< orphan*/ ) ; 

__attribute__((used)) static mrb_value
mrb_proc_lambda(mrb_state *mrb, mrb_value self)
{
  struct RProc *p = mrb_proc_ptr(self);
  return mrb_bool_value(MRB_PROC_STRICT_P(p));
}

__attribute__((used)) static mrb_value
mrb_proc_source_location(mrb_state *mrb, mrb_value self)
{
  struct RProc *p = mrb_proc_ptr(self);

  if (MRB_PROC_CFUNC_P(p)) {
    return mrb_nil_value();
  }
  else {
    mrb_irep *irep = p->body.irep;
    int32_t line;
    const char *filename;

    filename = mrb_debug_get_filename(irep, 0);
    line = mrb_debug_get_line(irep, 0);

    return (!filename && line == -1)? mrb_nil_value()
        : mrb_assoc_new(mrb, mrb_str_new_cstr(mrb, filename), mrb_fixnum_value(line));
  }
}

__attribute__((used)) static mrb_value
mrb_proc_inspect(mrb_state *mrb, mrb_value self)
{
  struct RProc *p = mrb_proc_ptr(self);
  mrb_value str = mrb_str_new_lit(mrb, "#<Proc:");
  mrb_str_concat(mrb, str, mrb_ptr_to_str(mrb, mrb_cptr(self)));

  if (!MRB_PROC_CFUNC_P(p)) {
    mrb_irep *irep = p->body.irep;
    const char *filename;
    int32_t line;
    mrb_str_cat_lit(mrb, str, "@");

    filename = mrb_debug_get_filename(irep, 0);
    mrb_str_cat_cstr(mrb, str, filename ? filename : "-");
    mrb_str_cat_lit(mrb, str, ":");

    line = mrb_debug_get_line(irep, 0);
    if (line != -1) {
      str = mrb_format(mrb, "%S:%S", str, mrb_fixnum_value(line));
    }
    else {
      mrb_str_cat_lit(mrb, str, "-");
    }
  }

  if (MRB_PROC_STRICT_P(p)) {
    mrb_str_cat_lit(mrb, str, " (lambda)");
  }

  mrb_str_cat_lit(mrb, str, ">");
  return str;
}

__attribute__((used)) static mrb_value
mrb_kernel_proc(mrb_state *mrb, mrb_value self)
{
  mrb_value blk;

  mrb_get_args(mrb, "&", &blk);
  if (mrb_nil_p(blk)) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "tried to create Proc object without a block");
  }

  return blk;
}

__attribute__((used)) static mrb_value
mrb_proc_parameters(mrb_state *mrb, mrb_value self)
{
  struct parameters_type {
    size_t len;
    const char *name;
    int size;
  } *p, parameters_list [] = {
    {sizeof("req")   - 1, "req",   0},
    {sizeof("opt")   - 1, "opt",   0},
    {sizeof("rest")  - 1, "rest",  0},
    {sizeof("req")   - 1, "req",   0},
    {sizeof("block") - 1, "block", 0},
    {0, NULL, 0}
  };
  const struct RProc *proc = mrb_proc_ptr(self);
  const struct mrb_irep *irep = proc->body.irep;
  mrb_aspec aspec;
  mrb_value parameters;
  int i, j;
  int max = -1;

  if (MRB_PROC_CFUNC_P(proc)) {
    // TODO cfunc aspec is not implemented yet
    return mrb_ary_new(mrb);
  }
  if (!irep) {
    return mrb_ary_new(mrb);
  }
  if (!irep->lv) {
    return mrb_ary_new(mrb);
  }
  if (*irep->iseq != OP_ENTER) {
    return mrb_ary_new(mrb);
  }

  if (!MRB_PROC_STRICT_P(proc)) {
    parameters_list[0].len = sizeof("opt") - 1;
    parameters_list[0].name = "opt";
    parameters_list[3].len = sizeof("opt") - 1;
    parameters_list[3].name = "opt";
  }

  aspec = PEEK_W(irep->iseq+1);
  parameters_list[0].size = MRB_ASPEC_REQ(aspec);
  parameters_list[1].size = MRB_ASPEC_OPT(aspec);
  parameters_list[2].size = MRB_ASPEC_REST(aspec);
  parameters_list[3].size = MRB_ASPEC_POST(aspec);
  parameters_list[4].size = MRB_ASPEC_BLOCK(aspec);

  parameters = mrb_ary_new_capa(mrb, irep->nlocals-1);

  max = irep->nlocals-1;
  for (i = 0, p = parameters_list; p->name; p++) {
    mrb_value sname = mrb_symbol_value(mrb_intern_static(mrb, p->name, p->len));

    for (j = 0; j < p->size; i++, j++) {
      mrb_value a;

      a = mrb_ary_new(mrb);
      mrb_ary_push(mrb, a, sname);
      if (i < max && irep->lv[i].name) {
        mrb_sym sym = irep->lv[i].name;
        const char *name = mrb_sym2name(mrb, sym);
        switch (name[0]) {
        case '*': case '&':
          break;
        default:
          mrb_ary_push(mrb, a, mrb_symbol_value(sym));
          break;
        }
      }
      mrb_ary_push(mrb, parameters, a);
    }
  }
  return parameters;
}

void
mrb_mruby_proc_ext_gem_init(mrb_state* mrb)
{
  struct RClass *p = mrb->proc_class;
  mrb_define_method(mrb, p, "lambda?",         mrb_proc_lambda,          MRB_ARGS_NONE());
  mrb_define_method(mrb, p, "source_location", mrb_proc_source_location, MRB_ARGS_NONE());
  mrb_define_method(mrb, p, "to_s",            mrb_proc_inspect,         MRB_ARGS_NONE());
  mrb_define_method(mrb, p, "inspect",         mrb_proc_inspect,         MRB_ARGS_NONE());
  mrb_define_method(mrb, p, "parameters",      mrb_proc_parameters,      MRB_ARGS_NONE());

  mrb_define_class_method(mrb, mrb->kernel_module, "proc", mrb_kernel_proc, MRB_ARGS_NONE());
  mrb_define_method(mrb, mrb->kernel_module,       "proc", mrb_kernel_proc, MRB_ARGS_NONE());
}

void
mrb_mruby_proc_ext_gem_final(mrb_state* mrb)
{
}

