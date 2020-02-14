#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct RObject {int dummy; } ;
struct RClass {scalar_t__ tt; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_10__ {struct RClass* class_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  enum mrb_vtype { ____Placeholder_mrb_vtype } mrb_vtype ;

/* Variables and functions */
 int /*<<< orphan*/  E_TYPE_ERROR ; 
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int MRB_INSTANCE_TT (struct RClass*) ; 
 int MRB_TT_CPTR ; 
 int MRB_TT_OBJECT ; 
 scalar_t__ MRB_TT_SCLASS ; 
 struct RClass* mrb_class_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_obj_alloc (TYPE_1__*,int,struct RClass*) ; 
 int /*<<< orphan*/  mrb_obj_value (struct RObject*) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_raisef (TYPE_1__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static mrb_value class_allocate(mrb_state *mrb, mrb_value cv)
{
  struct RClass *c = mrb_class_ptr(cv);
  struct RObject *o;
  enum mrb_vtype ttype = MRB_INSTANCE_TT(c);

  if (c->tt == MRB_TT_SCLASS)
    mrb_raise(mrb, E_TYPE_ERROR, "can't create instance of singleton class");

  if (ttype == 0) ttype = MRB_TT_OBJECT;
  if (ttype <= MRB_TT_CPTR) {
    mrb_raisef(mrb, E_TYPE_ERROR, "can't create instance of %S", cv);
  }
  o = (struct RObject*)mrb_obj_alloc(mrb, ttype, c);
  return mrb_obj_value(o);
}

void mrb_mruby_class_new_fiber_safe_gem_init(mrb_state* mrb)
{
    struct RClass *cls = mrb->class_class;
    mrb_define_method(mrb, cls, "allocate", class_allocate, MRB_ARGS_NONE());
}

void mrb_mruby_class_new_fiber_safe_gem_final(mrb_state* mrb)
{
}

