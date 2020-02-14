#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_8__ {struct RClass* symbol_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  int /*<<< orphan*/  mrb_int ;

/* Variables and functions */
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_fixnum_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_sym2name_len (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_symbol (int /*<<< orphan*/ ) ; 

__attribute__((used)) static mrb_value
mrb_sym_length(mrb_state *mrb, mrb_value self)
{
  mrb_int len;
#ifdef MRB_UTF8_STRING
  mrb_int byte_len;
  const char *name = mrb_sym2name_len(mrb, mrb_symbol(self), &byte_len);
  len = mrb_utf8_len(name, byte_len);
#else
  mrb_sym2name_len(mrb, mrb_symbol(self), &len);
#endif
  return mrb_fixnum_value(len);
}

void
mrb_mruby_symbol_ext_gem_init(mrb_state* mrb)
{
  struct RClass *s = mrb->symbol_class;
#ifdef MRB_ENABLE_ALL_SYMBOLS
  mrb_define_class_method(mrb, s, "all_symbols", mrb_sym_all_symbols, MRB_ARGS_NONE());
#endif
  mrb_define_method(mrb, s, "length", mrb_sym_length, MRB_ARGS_NONE());
  mrb_define_method(mrb, s, "size", mrb_sym_length, MRB_ARGS_NONE());
}

void
mrb_mruby_symbol_ext_gem_final(mrb_state* mrb)
{
}

