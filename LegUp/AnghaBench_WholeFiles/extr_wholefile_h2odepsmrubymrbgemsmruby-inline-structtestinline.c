#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  char* mrb_value ;
struct TYPE_19__ {int /*<<< orphan*/  object_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  int mrb_int ;

/* Variables and functions */
 int /*<<< orphan*/  E_TYPE_ERROR ; 
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int /*<<< orphan*/  MRB_ARGS_REQ (int) ; 
 int /*<<< orphan*/  MRB_SET_INSTANCE_TT (struct RClass*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MRB_TT_ISTRUCT ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 char* mrb_bool_value (int) ; 
 scalar_t__ mrb_class_get (TYPE_1__*,char*) ; 
 struct RClass* mrb_define_class (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_class_method (TYPE_1__*,struct RClass*,char*,char* (*) (TYPE_1__*,char*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,struct RClass*,char*,char* (*) (TYPE_1__*,char*),int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_fixnum_p (char*) ; 
 char* mrb_fixnum_value (int) ; 
 scalar_t__ mrb_float_p (char*) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,char**) ; 
 scalar_t__ mrb_istruct_ptr (char*) ; 
 int mrb_istruct_size () ; 
 char* mrb_nil_value () ; 
 scalar_t__ mrb_obj_class (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 char* mrb_str_new_cstr (TYPE_1__*,char const*) ; 
 scalar_t__ mrb_string_p (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 

__attribute__((used)) static mrb_value
istruct_test_initialize(mrb_state *mrb, mrb_value self)
{
  char *string = (char*)mrb_istruct_ptr(self);
  mrb_int size = mrb_istruct_size();
  mrb_value object;
  mrb_get_args(mrb, "o", &object);

  if (mrb_fixnum_p(object)) {
    strncpy(string, "fixnum", size-1);
  }
#ifndef MRB_WITHOUT_FLOAT
  else if (mrb_float_p(object)) {
    strncpy(string, "float", size-1);
  }
#endif
  else if (mrb_string_p(object)) {
    strncpy(string, "string", size-1);
  }
  else {
    strncpy(string, "anything", size-1);
  }

  string[size - 1] = 0; // force NULL at the end
  return self;
}

__attribute__((used)) static mrb_value
istruct_test_to_s(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, (const char*)mrb_istruct_ptr(self));
}

__attribute__((used)) static mrb_value
istruct_test_length(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_istruct_size());
}

__attribute__((used)) static mrb_value
istruct_test_test_receive(mrb_state *mrb, mrb_value self)
{
  mrb_value object;
  mrb_get_args(mrb, "o", &object);
  if (mrb_obj_class(mrb, object) != mrb_class_get(mrb, "InlineStructTest"))
  {
    mrb_raise(mrb, E_TYPE_ERROR, "Expected InlineStructTest");
  }
  return mrb_bool_value(((char*)mrb_istruct_ptr(object))[0] == 's');
}

__attribute__((used)) static mrb_value
istruct_test_test_receive_direct(mrb_state *mrb, mrb_value self)
{
  char *ptr;
  mrb_get_args(mrb, "I", &ptr);
  return mrb_bool_value(ptr[0] == 's');
}

__attribute__((used)) static mrb_value
istruct_test_mutate(mrb_state *mrb, mrb_value self)
{
  char *ptr = (char*)mrb_istruct_ptr(self);
  memcpy(ptr, "mutate", 6);
  return mrb_nil_value();
}

void mrb_mruby_inline_struct_gem_test(mrb_state *mrb)
{
  struct RClass *cls;

  cls = mrb_define_class(mrb, "InlineStructTest", mrb->object_class);
  MRB_SET_INSTANCE_TT(cls, MRB_TT_ISTRUCT);
  mrb_define_method(mrb, cls, "initialize", istruct_test_initialize, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "to_s", istruct_test_to_s, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "mutate", istruct_test_mutate, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, cls, "length", istruct_test_length, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, cls, "test_receive", istruct_test_test_receive, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, cls, "test_receive_direct", istruct_test_test_receive_direct, MRB_ARGS_REQ(1));
}

