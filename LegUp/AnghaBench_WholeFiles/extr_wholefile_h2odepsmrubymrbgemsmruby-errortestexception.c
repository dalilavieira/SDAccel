#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_25__ {int /*<<< orphan*/  object_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  int /*<<< orphan*/  mrb_bool ;

/* Variables and functions */
 struct RClass* E_TYPE_ERROR ; 
 int MRB_ARGS_BLOCK () ; 
 int MRB_ARGS_NONE () ; 
 int MRB_ARGS_REQ (int) ; 
 int /*<<< orphan*/  mrb_ary_new_from_values (TYPE_1__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_bool_value (int /*<<< orphan*/ ) ; 
 struct RClass* mrb_define_class (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_module_function (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int) ; 
 int /*<<< orphan*/  mrb_ensure (TYPE_1__*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  mrb_protect (TYPE_1__*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_rescue (TYPE_1__*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_rescue_exceptions (TYPE_1__*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ,int,struct RClass**) ; 
 int /*<<< orphan*/  mrb_yield_argv (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static mrb_value
protect_cb(mrb_state *mrb, mrb_value b)
{
  return mrb_yield_argv(mrb, b, 0, NULL);
}

__attribute__((used)) static mrb_value
run_protect(mrb_state *mrb, mrb_value self)
{
  mrb_value b;
  mrb_value ret[2];
  mrb_bool state;
  mrb_get_args(mrb, "&", &b);
  ret[0] = mrb_protect(mrb, protect_cb, b, &state);
  ret[1] = mrb_bool_value(state);
  return mrb_ary_new_from_values(mrb, 2, ret);
}

__attribute__((used)) static mrb_value
run_ensure(mrb_state *mrb, mrb_value self)
{
  mrb_value b, e;
  mrb_get_args(mrb, "oo", &b, &e);
  return mrb_ensure(mrb, protect_cb, b, protect_cb, e);
}

__attribute__((used)) static mrb_value
run_rescue(mrb_state *mrb, mrb_value self)
{
  mrb_value b, r;
  mrb_get_args(mrb, "oo", &b, &r);
  return mrb_rescue(mrb, protect_cb, b, protect_cb, r);
}

__attribute__((used)) static mrb_value
run_rescue_exceptions(mrb_state *mrb, mrb_value self)
{
  mrb_value b, r;
  struct RClass *cls[1];
  mrb_get_args(mrb, "oo", &b, &r);
  cls[0] = E_TYPE_ERROR;
  return mrb_rescue_exceptions(mrb, protect_cb, b, protect_cb, r, 1, cls);
}

void
mrb_mruby_error_gem_test(mrb_state *mrb)
{
  struct RClass *cls;

  cls = mrb_define_class(mrb, "ExceptionTest", mrb->object_class);
  mrb_define_module_function(mrb, cls, "mrb_protect", run_protect, MRB_ARGS_NONE() | MRB_ARGS_BLOCK());
  mrb_define_module_function(mrb, cls, "mrb_ensure", run_ensure, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, cls, "mrb_rescue", run_rescue, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, cls, "mrb_rescue_exceptions", run_rescue_exceptions, MRB_ARGS_REQ(2));
}

