#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_20__ {struct RClass* kernel_module; struct RClass* nil_class; TYPE_2__* c; } ;
typedef  TYPE_3__ mrb_state ;
typedef  int /*<<< orphan*/  mrb_int ;
struct TYPE_19__ {TYPE_1__* ci; } ;
struct TYPE_18__ {struct RClass* target_class; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int MRB_ARGS_ANY () ; 
 int MRB_ARGS_BLOCK () ; 
 int MRB_ARGS_NONE () ; 
#define  MRB_TT_FIXNUM 130 
#define  MRB_TT_FLOAT 129 
#define  MRB_TT_SYMBOL 128 
 int /*<<< orphan*/  mrb_ary_new (TYPE_3__*) ; 
 struct RClass* mrb_class_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_3__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_3__*,int /*<<< orphan*/ ),int) ; 
 int /*<<< orphan*/  mrb_fixnum_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_float_value (TYPE_3__*,double) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_3__*,char*,int /*<<< orphan*/  const**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ mrb_nil_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_singleton_class (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int mrb_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_yield_cont (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static mrb_value
nil_to_a(mrb_state *mrb, mrb_value obj)
{
  return mrb_ary_new(mrb);
}

__attribute__((used)) static mrb_value
nil_to_f(mrb_state *mrb, mrb_value obj)
{
  return mrb_float_value(mrb, 0.0);
}

__attribute__((used)) static mrb_value
nil_to_i(mrb_state *mrb, mrb_value obj)
{
  return mrb_fixnum_value(0);
}

__attribute__((used)) static mrb_value
mrb_obj_instance_exec(mrb_state *mrb, mrb_value self)
{
  const mrb_value *argv;
  mrb_int argc;
  mrb_value blk;
  struct RClass *c;

  mrb_get_args(mrb, "*&", &argv, &argc, &blk);

  if (mrb_nil_p(blk)) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "no block given");
  }

  switch (mrb_type(self)) {
  case MRB_TT_SYMBOL:
  case MRB_TT_FIXNUM:
#ifndef MRB_WITHOUT_FLOAT
  case MRB_TT_FLOAT:
#endif
    c = NULL;
    break;
  default:
    c = mrb_class_ptr(mrb_singleton_class(mrb, self));
    break;
  }
  mrb->c->ci->target_class = c;
  return mrb_yield_cont(mrb, blk, self, argc, argv);
}

void
mrb_mruby_object_ext_gem_init(mrb_state* mrb)
{
  struct RClass * n = mrb->nil_class;

  mrb_define_method(mrb, n, "to_a", nil_to_a,       MRB_ARGS_NONE());
#ifndef MRB_WITHOUT_FLOAT
  mrb_define_method(mrb, n, "to_f", nil_to_f,       MRB_ARGS_NONE());
#endif
  mrb_define_method(mrb, n, "to_i", nil_to_i,       MRB_ARGS_NONE());

  mrb_define_method(mrb, mrb->kernel_module, "instance_exec", mrb_obj_instance_exec, MRB_ARGS_ANY() | MRB_ARGS_BLOCK());
}

void
mrb_mruby_object_ext_gem_final(mrb_state* mrb)
{
}

