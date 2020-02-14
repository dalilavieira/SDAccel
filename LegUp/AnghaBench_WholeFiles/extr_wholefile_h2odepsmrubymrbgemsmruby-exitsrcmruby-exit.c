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
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_8__ {int /*<<< orphan*/  kernel_module; } ;
typedef  TYPE_1__ mrb_state ;
typedef  scalar_t__ mrb_int ;

/* Variables and functions */
 scalar_t__ EXIT_SUCCESS ; 
 int /*<<< orphan*/  MRB_ARGS_OPT (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,scalar_t__*) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 

__attribute__((used)) static mrb_value
f_exit(mrb_state *mrb, mrb_value self)
{
  mrb_int i = EXIT_SUCCESS;

  mrb_get_args(mrb, "|i", &i);
  exit((int)i);
  /* not reached */
  return mrb_nil_value();
}

void
mrb_mruby_exit_gem_init(mrb_state* mrb)
{
  mrb_define_method(mrb, mrb->kernel_module, "exit", f_exit, MRB_ARGS_OPT(1));
}

void
mrb_mruby_exit_gem_final(mrb_state* mrb)
{
}

