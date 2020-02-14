#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_34__ {struct RClass* kernel_module; TYPE_1__* c; } ;
typedef  TYPE_2__ mrb_state ;
typedef  int mrb_int ;
struct TYPE_35__ {scalar_t__ mid; } ;
typedef  TYPE_3__ mrb_callinfo ;
struct TYPE_33__ {TYPE_3__* ci; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int /*<<< orphan*/  MRB_ARGS_ANY () ; 
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int /*<<< orphan*/  MRB_ARGS_OPT (int) ; 
 int /*<<< orphan*/  MRB_ARGS_REQ (int) ; 
 int /*<<< orphan*/  MRB_TT_ARRAY ; 
 int /*<<< orphan*/  MRB_TT_RANGE ; 
 int /*<<< orphan*/  MRB_TT_STRING ; 
 scalar_t__ RARRAY_LEN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  mrb_Float (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_array_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_ary_new (TYPE_2__*) ; 
 int /*<<< orphan*/  mrb_ary_new_from_values (TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_check_convert_type (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  mrb_convert_to_integer (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mrb_convert_type (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_2__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_2__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_module_function (TYPE_2__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_2__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_ensure_hash_type (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_f_raise (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int mrb_fixnum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_fixnum_value (int) ; 
 int /*<<< orphan*/  mrb_funcall (TYPE_2__*,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mrb_get_args (TYPE_2__*,char*,int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  mrb_get_backtrace (TYPE_2__*) ; 
 int /*<<< orphan*/  mrb_hash_new (TYPE_2__*) ; 
 scalar_t__ mrb_nil_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 
 int /*<<< orphan*/  mrb_raisef (TYPE_2__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int mrb_range_beg_len (TYPE_2__*,int /*<<< orphan*/ ,int*,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_symbol_value (scalar_t__) ; 
 int /*<<< orphan*/  mrb_to_int (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_type (int /*<<< orphan*/ ) ; 

__attribute__((used)) static mrb_value
mrb_f_caller(mrb_state *mrb, mrb_value self)
{
  mrb_value bt, v, length;
  mrb_int bt_len, argc, lev, n;

  bt = mrb_get_backtrace(mrb);
  bt_len = RARRAY_LEN(bt);
  argc = mrb_get_args(mrb, "|oo", &v, &length);

  switch (argc) {
    case 0:
      lev = 1;
      n = bt_len - lev;
      break;
    case 1:
      if (mrb_type(v) == MRB_TT_RANGE) {
        mrb_int beg, len;
        if (mrb_range_beg_len(mrb, v, &beg, &len, bt_len, TRUE) == 1) {
          lev = beg;
          n = len;
        }
        else {
          return mrb_nil_value();
        }
      }
      else {
        v = mrb_to_int(mrb, v);
        lev = mrb_fixnum(v);
        if (lev < 0) {
          mrb_raisef(mrb, E_ARGUMENT_ERROR, "negative level (%S)", v);
        }
        n = bt_len - lev;
      }
      break;
    case 2:
      lev = mrb_fixnum(mrb_to_int(mrb, v));
      n = mrb_fixnum(mrb_to_int(mrb, length));
      if (lev < 0) {
        mrb_raisef(mrb, E_ARGUMENT_ERROR, "negative level (%S)", v);
      }
      if (n < 0) {
        mrb_raisef(mrb, E_ARGUMENT_ERROR, "negative size (%S)", length);
      }
      break;
    default:
      lev = n = 0;
      break;
  }

  if (n == 0) {
    return mrb_ary_new(mrb);
  }

  return mrb_funcall(mrb, bt, "[]", 2, mrb_fixnum_value(lev), mrb_fixnum_value(n));
}

__attribute__((used)) static mrb_value
mrb_f_method(mrb_state *mrb, mrb_value self)
{
  mrb_callinfo *ci = mrb->c->ci;
  ci--;
  if (ci->mid)
    return mrb_symbol_value(ci->mid);
  else
    return mrb_nil_value();
}

__attribute__((used)) static mrb_value
mrb_f_integer(mrb_state *mrb, mrb_value self)
{
  mrb_value arg;
  mrb_int base = 0;

  mrb_get_args(mrb, "o|i", &arg, &base);
  return mrb_convert_to_integer(mrb, arg, base);
}

__attribute__((used)) static mrb_value
mrb_f_float(mrb_state *mrb, mrb_value self)
{
  mrb_value arg;

  mrb_get_args(mrb, "o", &arg);
  return mrb_Float(mrb, arg);
}

__attribute__((used)) static mrb_value
mrb_f_string(mrb_state *mrb, mrb_value self)
{
  mrb_value arg, tmp;

  mrb_get_args(mrb, "o", &arg);
  tmp = mrb_convert_type(mrb, arg, MRB_TT_STRING, "String", "to_s");
  return tmp;
}

__attribute__((used)) static mrb_value
mrb_f_array(mrb_state *mrb, mrb_value self)
{
  mrb_value arg, tmp;

  mrb_get_args(mrb, "o", &arg);
  tmp = mrb_check_convert_type(mrb, arg, MRB_TT_ARRAY, "Array", "to_a");
  if (mrb_nil_p(tmp)) {
    return mrb_ary_new_from_values(mrb, 1, &arg);
  }

  return tmp;
}

__attribute__((used)) static mrb_value
mrb_f_hash(mrb_state *mrb, mrb_value self)
{
  mrb_value arg;

  mrb_get_args(mrb, "o", &arg);
  if (mrb_nil_p(arg) || (mrb_array_p(arg) && RARRAY_LEN(arg) == 0)) {
    return mrb_hash_new(mrb);
  }
  return mrb_ensure_hash_type(mrb, arg);
}

__attribute__((used)) static mrb_value
mrb_f_itself(mrb_state *mrb, mrb_value self)
{
  return self;
}

void
mrb_mruby_kernel_ext_gem_init(mrb_state *mrb)
{
  struct RClass *krn = mrb->kernel_module;

  mrb_define_module_function(mrb, krn, "fail", mrb_f_raise, MRB_ARGS_OPT(2));
  mrb_define_module_function(mrb, krn, "caller", mrb_f_caller, MRB_ARGS_OPT(2));
  mrb_define_method(mrb, krn, "__method__", mrb_f_method, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, krn, "Integer", mrb_f_integer, MRB_ARGS_ANY());
#ifndef MRB_WITHOUT_FLOAT
  mrb_define_module_function(mrb, krn, "Float", mrb_f_float, MRB_ARGS_REQ(1));
#endif
  mrb_define_module_function(mrb, krn, "String", mrb_f_string, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, krn, "Array", mrb_f_array, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, krn, "Hash", mrb_f_hash, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, krn, "itself", mrb_f_itself, MRB_ARGS_NONE());
}

void
mrb_mruby_kernel_ext_gem_final(mrb_state *mrb)
{
}

