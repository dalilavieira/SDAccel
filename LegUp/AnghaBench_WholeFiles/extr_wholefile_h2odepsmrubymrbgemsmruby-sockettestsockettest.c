#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;

/* Variables and functions */
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int close (int) ; 
 int mkstemp (char*) ; 
 int /*<<< orphan*/  mrb_define_class_method (int /*<<< orphan*/ *,struct RClass*,char*,int /*<<< orphan*/  (*) (int /*<<< orphan*/ *,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 struct RClass* mrb_define_module (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  mrb_false_value () ; 
 int /*<<< orphan*/  mrb_str_new_cstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  mrb_sys_fail (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int unlink (char*) ; 

mrb_value
mrb_sockettest_tmppath(mrb_state *mrb, mrb_value klass)
{
  char name[] = "mruby-socket.XXXXXXXX";
  int fd = mkstemp(name);
  if (fd == -1) {
    mrb_sys_fail(mrb, 0);
  }
  if (close(fd) == -1) {
    mrb_sys_fail(mrb, 0);
  }
  if (unlink(name) == -1) {
    mrb_sys_fail(mrb, 0);
  }
  return mrb_str_new_cstr(mrb, name);
}

mrb_value
mrb_sockettest_win_p(mrb_state *mrb, mrb_value klass)
{
#ifdef _WIN32
  return mrb_true_value();
#else
  return mrb_false_value();
#endif
}

mrb_value
mrb_sockettest_cygwin_p(mrb_state *mrb, mrb_value klass)
{
#if defined(__CYGWIN__) || defined(__CYGWIN32__)
  return mrb_true_value();
#else
  return mrb_false_value();
#endif
}

void
mrb_mruby_socket_gem_test(mrb_state* mrb)
{
  struct RClass *c = mrb_define_module(mrb, "SocketTest");
  mrb_define_class_method(mrb, c, "tmppath", mrb_sockettest_tmppath, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, c, "win?", mrb_sockettest_win_p, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, c, "cygwin?", mrb_sockettest_cygwin_p, MRB_ARGS_NONE());
}

