#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
struct RArray {int dummy; } ;
typedef  size_t mrb_value ;
struct TYPE_23__ {struct RClass* array_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  size_t mrb_int ;

/* Variables and functions */
 size_t ARY_LEN (struct RArray*) ; 
 size_t* ARY_PTR (struct RArray*) ; 
 int /*<<< orphan*/  MRB_ARGS_ANY () ; 
 int /*<<< orphan*/  MRB_ARGS_REQ (int) ; 
 scalar_t__ MRB_TT_ARRAY ; 
#define  MRB_TT_FIXNUM 129 
#define  MRB_TT_RANGE 128 
 int RARRAY_LEN (size_t) ; 
 size_t* RARRAY_PTR (size_t) ; 
 int /*<<< orphan*/  TRUE ; 
 size_t mrb_ary_entry (size_t,size_t) ; 
 int /*<<< orphan*/  mrb_ary_modify (TYPE_1__*,struct RArray*) ; 
 size_t mrb_ary_new (TYPE_1__*) ; 
 size_t mrb_ary_new_capa (TYPE_1__*,size_t) ; 
 struct RArray* mrb_ary_ptr (size_t) ; 
 int /*<<< orphan*/  mrb_ary_push (TYPE_1__*,size_t,size_t) ; 
 int /*<<< orphan*/  mrb_ary_ref ; 
 int /*<<< orphan*/  mrb_ary_resize (TYPE_1__*,size_t,size_t) ; 
 size_t mrb_check_array_type (TYPE_1__*,size_t) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,struct RClass*,char*,size_t (*) (TYPE_1__*,size_t),int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_equal (TYPE_1__*,size_t,size_t) ; 
 size_t mrb_funcall (TYPE_1__*,size_t,char*,int,size_t) ; 
 int mrb_get_argc (TYPE_1__*) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,...) ; 
 size_t mrb_get_values_at (TYPE_1__*,size_t,int,size_t,size_t*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_nil_p (size_t) ; 
 size_t mrb_nil_value () ; 
 int mrb_range_beg_len (TYPE_1__*,size_t,size_t*,size_t*,size_t,int /*<<< orphan*/ ) ; 
 int mrb_type (size_t) ; 

__attribute__((used)) static mrb_value
mrb_ary_assoc(mrb_state *mrb, mrb_value ary)
{
  mrb_int i;
  mrb_value v, k;

  mrb_get_args(mrb, "o", &k);

  for (i = 0; i < RARRAY_LEN(ary); ++i) {
    v = mrb_check_array_type(mrb, RARRAY_PTR(ary)[i]);
    if (!mrb_nil_p(v) && RARRAY_LEN(v) > 0 &&
        mrb_equal(mrb, RARRAY_PTR(v)[0], k))
      return v;
  }
  return mrb_nil_value();
}

__attribute__((used)) static mrb_value
mrb_ary_rassoc(mrb_state *mrb, mrb_value ary)
{
  mrb_int i;
  mrb_value v, value;

  mrb_get_args(mrb, "o", &value);

  for (i = 0; i < RARRAY_LEN(ary); ++i) {
    v = RARRAY_PTR(ary)[i];
    if (mrb_type(v) == MRB_TT_ARRAY &&
        RARRAY_LEN(v) > 1 &&
        mrb_equal(mrb, RARRAY_PTR(v)[1], value))
      return v;
  }
  return mrb_nil_value();
}

__attribute__((used)) static mrb_value
mrb_ary_at(mrb_state *mrb, mrb_value ary)
{
  mrb_int pos;
  mrb_get_args(mrb, "i", &pos);

  return mrb_ary_entry(ary, pos);
}

__attribute__((used)) static mrb_value
mrb_ary_values_at(mrb_state *mrb, mrb_value self)
{
  mrb_int argc;
  mrb_value *argv;

  mrb_get_args(mrb, "*", &argv, &argc);

  return mrb_get_values_at(mrb, self, RARRAY_LEN(self), argc, argv, mrb_ary_ref);
}

__attribute__((used)) static mrb_value
mrb_ary_slice_bang(mrb_state *mrb, mrb_value self)
{
  struct RArray *a = mrb_ary_ptr(self);
  mrb_int i, j, k, len, alen;
  mrb_value val;
  mrb_value *ptr;
  mrb_value ary;

  mrb_ary_modify(mrb, a);

  if (mrb_get_argc(mrb) == 1) {
    mrb_value index;

    mrb_get_args(mrb, "o|i", &index, &len);
    switch (mrb_type(index)) {
    case MRB_TT_RANGE:
      if (mrb_range_beg_len(mrb, index, &i, &len, ARY_LEN(a), TRUE) == 1) {
        goto delete_pos_len;
      }
      else {
        return mrb_nil_value();
      }
    case MRB_TT_FIXNUM:
      val = mrb_funcall(mrb, self, "delete_at", 1, index);
      return val;
    default:
      val = mrb_funcall(mrb, self, "delete_at", 1, index);
      return val;
    }
  }

  mrb_get_args(mrb, "ii", &i, &len);
 delete_pos_len:
  alen = ARY_LEN(a);
  if (i < 0) i += alen;
  if (i < 0 || alen < i) return mrb_nil_value();
  if (len < 0) return mrb_nil_value();
  if (alen == i) return mrb_ary_new(mrb);
  if (len > alen - i) len = alen - i;

  ary = mrb_ary_new_capa(mrb, len);
  ptr = ARY_PTR(a);
  for (j = i, k = 0; k < len; ++j, ++k) {
    mrb_ary_push(mrb, ary, ptr[j]);
  }

  ptr += i;
  for (j = i; j < alen - len; ++j) {
    *ptr = *(ptr+len);
    ++ptr;
  }

  mrb_ary_resize(mrb, self, alen - len);
  return ary;
}

void
mrb_mruby_array_ext_gem_init(mrb_state* mrb)
{
  struct RClass * a = mrb->array_class;

  mrb_define_method(mrb, a, "assoc",  mrb_ary_assoc,  MRB_ARGS_REQ(1));
  mrb_define_method(mrb, a, "at",     mrb_ary_at,     MRB_ARGS_REQ(1));
  mrb_define_method(mrb, a, "rassoc", mrb_ary_rassoc, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, a, "values_at", mrb_ary_values_at, MRB_ARGS_ANY());
  mrb_define_method(mrb, a, "slice!", mrb_ary_slice_bang,   MRB_ARGS_ANY());
}

void
mrb_mruby_array_ext_gem_final(mrb_state* mrb)
{
}

