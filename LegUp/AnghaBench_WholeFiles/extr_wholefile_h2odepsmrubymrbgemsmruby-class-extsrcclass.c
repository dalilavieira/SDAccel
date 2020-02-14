#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_18__ {struct RClass* module_class; TYPE_2__* c; } ;
typedef  TYPE_3__ mrb_state ;
typedef  int /*<<< orphan*/  mrb_int ;
struct TYPE_17__ {TYPE_1__* ci; } ;
struct TYPE_16__ {int /*<<< orphan*/  target_class; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int MRB_ARGS_ANY () ; 
 int MRB_ARGS_BLOCK () ; 
 int MRB_ARGS_NONE () ; 
 scalar_t__ MRB_TT_SCLASS ; 
 int /*<<< orphan*/  mrb_bool_value (int) ; 
 int /*<<< orphan*/  mrb_class_path (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_class_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_3__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_3__*,int /*<<< orphan*/ ),int) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_3__*,char*,int /*<<< orphan*/  const**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ mrb_nil_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_str_dup (TYPE_3__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_yield_cont (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static mrb_value
mrb_mod_name(mrb_state *mrb, mrb_value self)
{
  mrb_value name = mrb_class_path(mrb, mrb_class_ptr(self));
  return mrb_nil_p(name)? name : mrb_str_dup(mrb, name);
}

__attribute__((used)) static mrb_value
mrb_mod_singleton_class_p(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(mrb_type(self) == MRB_TT_SCLASS);
}

__attribute__((used)) static mrb_value
mrb_mod_module_exec(mrb_state *mrb, mrb_value self)
{
  const mrb_value *argv;
  mrb_int argc;
  mrb_value blk;

  mrb_get_args(mrb, "*&", &argv, &argc, &blk);

  if (mrb_nil_p(blk)) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "no block given");
  }

  mrb->c->ci->target_class = mrb_class_ptr(self);
  return mrb_yield_cont(mrb, blk, self, argc, argv);
}

void
mrb_mruby_class_ext_gem_init(mrb_state *mrb)
{
  struct RClass *mod = mrb->module_class;

  mrb_define_method(mrb, mod, "name", mrb_mod_name, MRB_ARGS_NONE());
  mrb_define_method(mrb, mod, "singleton_class?", mrb_mod_singleton_class_p, MRB_ARGS_NONE());
  mrb_define_method(mrb, mod, "module_exec", mrb_mod_module_exec, MRB_ARGS_ANY()|MRB_ARGS_BLOCK());
  mrb_define_method(mrb, mod, "class_exec", mrb_mod_module_exec, MRB_ARGS_ANY()|MRB_ARGS_BLOCK());
}

void
mrb_mruby_class_ext_gem_final(mrb_state *mrb)
{
}

