#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_41__ {int /*<<< orphan*/  eStandardError_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  int mrb_int ;
typedef  double mrb_float ;

/* Variables and functions */
 int MRB_ARGS_OPT (int) ; 
 int MRB_ARGS_REQ (int) ; 
 double acos (double) ; 
 double acosh (double) ; 
 double asin (double) ; 
 double asinh (double) ; 
 double atan (double) ; 
 double atan2 (double,double) ; 
 double atanh (double) ; 
 double cbrt (double) ; 
 double cos (double) ; 
 double cosh (double) ; 
 double erf (double) ; 
 double erfc (double) ; 
 int exp (double) ; 
 double frexp (double,int*) ; 
 double hypot (double,double) ; 
 double ldexp (double,int) ; 
 double log (double) ; 
 double log10 (double) ; 
 double log2 (double) ; 
 int /*<<< orphan*/  mrb_assoc_new (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct RClass* mrb_class_get_under (TYPE_1__*,struct RClass*,char*) ; 
 int /*<<< orphan*/  mrb_define_class_under (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_const (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/ ) ; 
 struct RClass* mrb_define_module (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  mrb_define_module_function (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int) ; 
 int /*<<< orphan*/  mrb_fixnum_value (int) ; 
 int /*<<< orphan*/  mrb_float_value (TYPE_1__*,int) ; 
 int mrb_get_args (TYPE_1__*,char*,double*,...) ; 
 struct RClass* mrb_module_get (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  mrb_raisef (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_str_new_cstr (TYPE_1__*,char const*) ; 
 double sin (double) ; 
 double sinh (double) ; 
 double sqrt (double) ; 
 double tan (double) ; 
 double tanh (double) ; 

__attribute__((used)) static void
domain_error(mrb_state *mrb, const char *func)
{
  struct RClass *math = mrb_module_get(mrb, "Math");
  struct RClass *domainerror = mrb_class_get_under(mrb, math, "DomainError");
  mrb_value str = mrb_str_new_cstr(mrb, func);
  mrb_raisef(mrb, domainerror, "Numerical argument is out of domain - %S", str);
}

__attribute__((used)) static mrb_value
math_sin(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = sin(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_cos(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = cos(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_tan(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = tan(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_asin(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < -1.0 || x > 1.0) {
    domain_error(mrb, "asin");
  }
  x = asin(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_acos(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < -1.0 || x > 1.0) {
    domain_error(mrb, "acos");
  }
  x = acos(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_atan(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = atan(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_atan2(mrb_state *mrb, mrb_value obj)
{
  mrb_float x, y;

  mrb_get_args(mrb, "ff", &x, &y);
  x = atan2(x, y);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_sinh(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = sinh(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_cosh(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = cosh(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_tanh(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = tanh(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_asinh(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);

  x = asinh(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_acosh(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < 1.0) {
    domain_error(mrb, "acosh");
  }
  x = acosh(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_atanh(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < -1.0 || x > 1.0) {
    domain_error(mrb, "atanh");
  }
  x = atanh(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_exp(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = exp(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_log(mrb_state *mrb, mrb_value obj)
{
  mrb_float x, base;
  mrb_int argc;

  argc = mrb_get_args(mrb, "f|f", &x, &base);
  if (x < 0.0) {
    domain_error(mrb, "log");
  }
  x = log(x);
  if (argc == 2) {
    if (base < 0.0) {
      domain_error(mrb, "log");
    }
    x /= log(base);
  }
  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_log2(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < 0.0) {
    domain_error(mrb, "log2");
  }
  x = log2(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_log10(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < 0.0) {
    domain_error(mrb, "log10");
  }
  x = log10(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_sqrt(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  if (x < 0.0) {
    domain_error(mrb, "sqrt");
  }
  x = sqrt(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_cbrt(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = cbrt(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_frexp(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;
  int exp;

  mrb_get_args(mrb, "f", &x);
  x = frexp(x, &exp);

  return mrb_assoc_new(mrb, mrb_float_value(mrb, x), mrb_fixnum_value(exp));
}

__attribute__((used)) static mrb_value
math_ldexp(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;
  mrb_int   i;

  mrb_get_args(mrb, "fi", &x, &i);
  x = ldexp(x, (int)i);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_hypot(mrb_state *mrb, mrb_value obj)
{
  mrb_float x, y;

  mrb_get_args(mrb, "ff", &x, &y);
  x = hypot(x, y);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_erf(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = erf(x);

  return mrb_float_value(mrb, x);
}

__attribute__((used)) static mrb_value
math_erfc(mrb_state *mrb, mrb_value obj)
{
  mrb_float x;

  mrb_get_args(mrb, "f", &x);
  x = erfc(x);

  return mrb_float_value(mrb, x);
}

void
mrb_mruby_math_gem_init(mrb_state* mrb)
{
  struct RClass *mrb_math;
  mrb_math = mrb_define_module(mrb, "Math");

  mrb_define_class_under(mrb, mrb_math, "DomainError", mrb->eStandardError_class);

#ifdef M_PI
  mrb_define_const(mrb, mrb_math, "PI", mrb_float_value(mrb, M_PI));
#else
  mrb_define_const(mrb, mrb_math, "PI", mrb_float_value(mrb, atan(1.0)*4.0));
#endif

#ifdef M_E
  mrb_define_const(mrb, mrb_math, "E", mrb_float_value(mrb, M_E));
#else
  mrb_define_const(mrb, mrb_math, "E", mrb_float_value(mrb, exp(1.0)));
#endif

#ifdef MRB_USE_FLOAT
  mrb_define_const(mrb, mrb_math, "TOLERANCE", mrb_float_value(mrb, 1e-5));
#else
  mrb_define_const(mrb, mrb_math, "TOLERANCE", mrb_float_value(mrb, 1e-12));
#endif

  mrb_define_module_function(mrb, mrb_math, "sin", math_sin, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "cos", math_cos, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "tan", math_tan, MRB_ARGS_REQ(1));

  mrb_define_module_function(mrb, mrb_math, "asin", math_asin, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "acos", math_acos, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "atan", math_atan, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "atan2", math_atan2, MRB_ARGS_REQ(2));

  mrb_define_module_function(mrb, mrb_math, "sinh", math_sinh, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "cosh", math_cosh, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "tanh", math_tanh, MRB_ARGS_REQ(1));

  mrb_define_module_function(mrb, mrb_math, "asinh", math_asinh, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "acosh", math_acosh, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "atanh", math_atanh, MRB_ARGS_REQ(1));

  mrb_define_module_function(mrb, mrb_math, "exp", math_exp, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "log", math_log, MRB_ARGS_REQ(1)|MRB_ARGS_OPT(1));
  mrb_define_module_function(mrb, mrb_math, "log2", math_log2, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "log10", math_log10, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "sqrt", math_sqrt, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "cbrt", math_cbrt, MRB_ARGS_REQ(1));

  mrb_define_module_function(mrb, mrb_math, "frexp", math_frexp, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "ldexp", math_ldexp, MRB_ARGS_REQ(2));

  mrb_define_module_function(mrb, mrb_math, "hypot", math_hypot, MRB_ARGS_REQ(2));

  mrb_define_module_function(mrb, mrb_math, "erf",  math_erf,  MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_math, "erfc", math_erfc, MRB_ARGS_REQ(1));
}

void
mrb_mruby_math_gem_final(mrb_state* mrb)
{
}

