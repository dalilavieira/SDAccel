#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_17__ {struct RClass* hash_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  size_t mrb_int ;

/* Variables and functions */
 int /*<<< orphan*/  MRB_ARGS_ANY () ; 
 int /*<<< orphan*/  mrb_ary_new_capa (TYPE_1__*,size_t) ; 
 int /*<<< orphan*/  mrb_ary_push (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_gc_arena_restore (TYPE_1__*,int) ; 
 int mrb_gc_arena_save (TYPE_1__*) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,int /*<<< orphan*/ **,size_t*) ; 
 int /*<<< orphan*/  mrb_hash_fetch (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_hash_get (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_hash_new_capa (TYPE_1__*,size_t) ; 
 int /*<<< orphan*/  mrb_hash_set (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_undef_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_undef_value () ; 

__attribute__((used)) static mrb_value
hash_values_at(mrb_state *mrb, mrb_value hash)
{
  mrb_value *argv, result;
  mrb_int argc, i;
  int ai;

  mrb_get_args(mrb, "*", &argv, &argc);
  result = mrb_ary_new_capa(mrb, argc);
  ai = mrb_gc_arena_save(mrb);
  for (i = 0; i < argc; i++) {
    mrb_ary_push(mrb, result, mrb_hash_get(mrb, hash, argv[i]));
    mrb_gc_arena_restore(mrb, ai);
  }
  return result;
}

__attribute__((used)) static mrb_value
hash_slice(mrb_state *mrb, mrb_value hash)
{
  mrb_value *argv, result;
  mrb_int argc, i;

  mrb_get_args(mrb, "*", &argv, &argc);
  if (argc == 0) {
    return mrb_hash_new_capa(mrb, argc);
  }
  result = mrb_hash_new_capa(mrb, argc);
  for (i = 0; i < argc; i++) {
    mrb_value key = argv[i];
    mrb_value val;

    val = mrb_hash_fetch(mrb, hash, key, mrb_undef_value());
    if (!mrb_undef_p(val)) {
      mrb_hash_set(mrb, result, key, val);
    }
  }
  return result;
}

void
mrb_mruby_hash_ext_gem_init(mrb_state *mrb)
{
  struct RClass *h;

  h = mrb->hash_class;
  mrb_define_method(mrb, h, "values_at", hash_values_at, MRB_ARGS_ANY());
  mrb_define_method(mrb, h, "slice",     hash_slice, MRB_ARGS_ANY());
}

void
mrb_mruby_hash_ext_gem_final(mrb_state *mrb)
{
}

