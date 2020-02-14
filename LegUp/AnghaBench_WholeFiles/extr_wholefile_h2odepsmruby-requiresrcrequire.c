#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_1__ ;
typedef  struct TYPE_36__   TYPE_19__ ;

/* Type definitions */
struct RProc {int dummy; } ;
struct RClass {int dummy; } ;
struct TYPE_38__ {int no_exec; } ;
typedef  TYPE_2__ mrbc_context ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_39__ {struct RClass* kernel_module; scalar_t__ jmp; scalar_t__ exc; int /*<<< orphan*/  object_class; } ;
typedef  TYPE_3__ mrb_state ;
typedef  int /*<<< orphan*/  mrb_irep ;
typedef  int mode_t ;
typedef  int /*<<< orphan*/  jmp_buf ;
struct TYPE_37__ {int /*<<< orphan*/ * irep; } ;
struct TYPE_36__ {TYPE_1__ body; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  E_LOAD_ERROR ; 
 int /*<<< orphan*/  MRB_ARGS_ANY () ; 
 int /*<<< orphan*/  MRB_ARGS_REQ (int) ; 
 int MRB_DUMP_GENERAL_FAILURE ; 
 int MRB_DUMP_OK ; 
 int /*<<< orphan*/  MRB_PROC_SET_TARGET_CLASS (struct RProc*,int /*<<< orphan*/ ) ; 
 int RSTRING_LEN (int /*<<< orphan*/ ) ; 
 char* RSTRING_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fdopen (int,char*) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int mkstemp (char*) ; 
 int /*<<< orphan*/  mrb_close (TYPE_3__*) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_3__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_3__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int mrb_dump_irep_binary (TYPE_3__*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_gc_arena_restore (TYPE_3__*,int) ; 
 int mrb_gc_arena_save (TYPE_3__*) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_3__*,char*,int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  mrb_irep_decref (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_load_nstring_cxt (TYPE_3__*,char const*,int,TYPE_2__*) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 
 int /*<<< orphan*/  mrb_obj_value (struct RProc*) ; 
 TYPE_3__* mrb_open () ; 
 struct RProc* mrb_proc_new (TYPE_3__*,int /*<<< orphan*/ *) ; 
 TYPE_19__* mrb_proc_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_raisef (TYPE_3__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * mrb_read_irep_file (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_str_new_cstr (TYPE_3__*,char*) ; 
 char* mrb_str_to_cstr (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_string_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_sys_fail (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  mrb_top_self (TYPE_3__*) ; 
 int /*<<< orphan*/  mrb_true_value () ; 
 scalar_t__ mrb_undef_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_yield_with_class (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrbc_context_free (TYPE_3__*,TYPE_2__*) ; 
 TYPE_2__* mrbc_context_new (TYPE_3__*) ; 
 int /*<<< orphan*/  mrbc_filename (TYPE_3__*,TYPE_2__*,char const*) ; 
 int /*<<< orphan*/  remove (char*) ; 
 int /*<<< orphan*/  rewind (int /*<<< orphan*/ *) ; 
 int umask (int) ; 

__attribute__((used)) static int
compile_rb2mrb(mrb_state *mrb0, const char *code, int code_len, const char *path, FILE* tmpfp)
{
  mrb_state *mrb = mrb_open();
  mrb_value result;
  mrbc_context *c;
  int ret = -1;
  int debuginfo = 1;
  mrb_irep *irep;

  c = mrbc_context_new(mrb);
  c->no_exec = 1;
  if (path != NULL) {
    mrbc_filename(mrb, c, path);
  }

  result = mrb_load_nstring_cxt(mrb, code, code_len, c);
  if (mrb_undef_p(result)) {
    mrbc_context_free(mrb, c);
    mrb_close(mrb);
    return MRB_DUMP_GENERAL_FAILURE;
  }

  irep = mrb_proc_ptr(result)->body.irep;
  ret = mrb_dump_irep_binary(mrb, irep, debuginfo, tmpfp);

  mrbc_context_free(mrb, c);
  mrb_close(mrb);

  return ret;
}

__attribute__((used)) static void
eval_load_irep(mrb_state *mrb, mrb_irep *irep)
{
  int ai;
  struct RProc *proc;

#ifdef USE_MRUBY_OLD_BYTE_CODE
  replace_stop_with_return(mrb, irep);
#endif
  proc = mrb_proc_new(mrb, irep);
  mrb_irep_decref(mrb, irep);
  MRB_PROC_SET_TARGET_CLASS(proc, mrb->object_class);

  ai = mrb_gc_arena_save(mrb);
  mrb_yield_with_class(mrb, mrb_obj_value(proc), 0, NULL, mrb_top_self(mrb), mrb->object_class);
  mrb_gc_arena_restore(mrb, ai);
}

__attribute__((used)) static mrb_value
mrb_require_load_rb_str(mrb_state *mrb, mrb_value self)
{
  char *path_ptr = NULL;
#if defined(_WIN32) || defined(_WIN64)
  char tmpname[MAX_PATH] = "tmp.XXXXXXXX";
#else
  char tmpname[] = "tmp.XXXXXXXX";
#endif
  mode_t mask;
  FILE *tmpfp = NULL;
  int fd = -1, ret;
  mrb_irep *irep;
  mrb_value code, path = mrb_nil_value();

  mrb_get_args(mrb, "S|S", &code, &path);
  if (!mrb_string_p(path)) {
    path = mrb_str_new_cstr(mrb, "-");
  }
  path_ptr = mrb_str_to_cstr(mrb, path);

  mask = umask(077);
  fd = mkstemp(tmpname);
  if (fd == -1) {
    mrb_sys_fail(mrb, "can't create mkstemp() at mrb_require_load_rb_str");
  }
  umask(mask);

  tmpfp = fdopen(fd, "r+");
  if (tmpfp == NULL) {
    close(fd);
    mrb_sys_fail(mrb, "can't open temporay file at mrb_require_load_rb_str");
  }

  ret = compile_rb2mrb(mrb, RSTRING_PTR(code), RSTRING_LEN(code), path_ptr, tmpfp);
  if (ret != MRB_DUMP_OK) {
    fclose(tmpfp);
    remove(tmpname);
    mrb_raisef(mrb, E_LOAD_ERROR, "can't load file -- %S", path);
    return mrb_nil_value();
  }

  rewind(tmpfp);
  irep = mrb_read_irep_file(mrb, tmpfp);
  fclose(tmpfp);
  remove(tmpname);

  if (irep) {
    eval_load_irep(mrb, irep);
  } else if (mrb->exc) {
    // fail to load
    longjmp(*(jmp_buf*)mrb->jmp, 1);
  } else {
    mrb_raisef(mrb, E_LOAD_ERROR, "can't load file -- %S", path);
    return mrb_nil_value();
  }

  return mrb_true_value();
}

__attribute__((used)) static mrb_value
mrb_require_load_mrb_file(mrb_state *mrb, mrb_value self)
{
  char *path_ptr = NULL;
  FILE *fp = NULL;
  mrb_irep *irep;
  mrb_value path;

  mrb_get_args(mrb, "S", &path);
  path_ptr = mrb_str_to_cstr(mrb, path);

  fp = fopen(path_ptr, "rb");
  if (fp == NULL) {
    mrb_raisef(mrb, E_LOAD_ERROR, "can't open file -- %S", path);
  }

  irep = mrb_read_irep_file(mrb, fp);
  fclose(fp);

  if (irep) {
    eval_load_irep(mrb, irep);
  } else if (mrb->exc) {
    // fail to load
    longjmp(*(jmp_buf*)mrb->jmp, 1);
  } else {
    mrb_raisef(mrb, E_LOAD_ERROR, "can't load file -- %S", path);
    return mrb_nil_value();
  }

  return mrb_true_value();
}

void
mrb_mruby_require_gem_init(mrb_state *mrb)
{
  struct RClass *krn;
  krn = mrb->kernel_module;

  mrb_define_method(mrb, krn, "_load_rb_str",   mrb_require_load_rb_str,   MRB_ARGS_ANY());
  mrb_define_method(mrb, krn, "_load_mrb_file", mrb_require_load_mrb_file, MRB_ARGS_REQ(1));
}

void
mrb_mruby_require_gem_final(mrb_state *mrb)
{
}

