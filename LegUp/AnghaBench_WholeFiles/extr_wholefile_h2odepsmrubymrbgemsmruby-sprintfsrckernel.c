#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
struct TYPE_6__ {struct RClass* kernel_module; } ;
typedef  TYPE_1__ mrb_state ;

/* Variables and functions */
 int /*<<< orphan*/  MRB_ARGS_ANY () ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct RClass* mrb_define_module (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  mrb_f_sprintf ; 

void
mrb_mruby_sprintf_gem_init(mrb_state* mrb)
{
  struct RClass *krn;

  if (mrb->kernel_module == NULL) {
    mrb->kernel_module = mrb_define_module(mrb, "Kernel"); /* Might be PARANOID. */
  }
  krn = mrb->kernel_module;

  mrb_define_method(mrb, krn, "sprintf", mrb_f_sprintf, MRB_ARGS_ANY());
  mrb_define_method(mrb, krn, "format",  mrb_f_sprintf, MRB_ARGS_ANY());
}

void
mrb_mruby_sprintf_gem_final(mrb_state* mrb)
{
  /* nothing to do. */
}

