#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
struct stat {int st_mode; scalar_t__ st_size; } ;
struct mrb_io {scalar_t__ fd; } ;
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_25__ {int /*<<< orphan*/  object_class; } ;
typedef  TYPE_1__ mrb_state ;

/* Variables and functions */
 int /*<<< orphan*/  E_IO_ERROR ; 
 int LSTAT (char*,struct stat*) ; 
 int /*<<< orphan*/  MRB_ARGS_REQ (int) ; 
 int S_IFDIR ; 
 int S_IFMT ; 
 int S_IFREG ; 
 int fstat (scalar_t__,struct stat*) ; 
 int /*<<< orphan*/  mrb_class_get (TYPE_1__*,char*) ; 
 struct RClass* mrb_define_class (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_define_class_method (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_false_value () ; 
 int /*<<< orphan*/  mrb_fixnum_value (scalar_t__) ; 
 int /*<<< orphan*/  mrb_funcall (TYPE_1__*,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ mrb_get_datatype (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_io_type ; 
 int /*<<< orphan*/  mrb_locale_free (char*) ; 
 char* mrb_locale_from_utf8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 
 int /*<<< orphan*/  mrb_obj_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_str_to_cstr (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_sys_fail (TYPE_1__*,char*) ; 
 scalar_t__ mrb_test (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_true_value () ; 
 int stat (char*,struct stat*) ; 

__attribute__((used)) static int
mrb_stat0(mrb_state *mrb, mrb_value obj, struct stat *st, int do_lstat)
{
  mrb_value tmp;
  mrb_value io_klass, str_klass;

  io_klass  = mrb_obj_value(mrb_class_get(mrb, "IO"));
  str_klass = mrb_obj_value(mrb_class_get(mrb, "String"));

  tmp = mrb_funcall(mrb, obj, "is_a?", 1, io_klass);
  if (mrb_test(tmp)) {
    struct mrb_io *fptr;
    fptr = (struct mrb_io *)mrb_get_datatype(mrb, obj, &mrb_io_type);

    if (fptr && fptr->fd >= 0) {
      return fstat(fptr->fd, st);
    }

    mrb_raise(mrb, E_IO_ERROR, "closed stream");
    return -1;
  }

  tmp = mrb_funcall(mrb, obj, "is_a?", 1, str_klass);
  if (mrb_test(tmp)) {
    char *path = mrb_locale_from_utf8(mrb_str_to_cstr(mrb, obj), -1);
    int ret;
    if (do_lstat) {
      ret = LSTAT(path, st);
    } else {
      ret = stat(path, st);
    }
    mrb_locale_free(path);
    return ret;
  }

  return -1;
}

__attribute__((used)) static int
mrb_stat(mrb_state *mrb, mrb_value obj, struct stat *st)
{
  return mrb_stat0(mrb, obj, st, 0);
}

__attribute__((used)) static int
mrb_lstat(mrb_state *mrb, mrb_value obj, struct stat *st)
{
  return mrb_stat0(mrb, obj, st, 1);
}

mrb_value
mrb_filetest_s_directory_p(mrb_state *mrb, mrb_value klass)
{
#ifndef S_ISDIR
#   define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#endif

  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_false_value();
  if (S_ISDIR(st.st_mode))
    return mrb_true_value();

  return mrb_false_value();
}

mrb_value
mrb_filetest_s_pipe_p(mrb_state *mrb, mrb_value klass)
{
#if defined(_WIN32) || defined(_WIN64)
  mrb_raise(mrb, E_NOTIMP_ERROR, "pipe is not supported on this platform");
#else
#ifdef S_IFIFO
#  ifndef S_ISFIFO
#    define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#  endif

  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_false_value();
  if (S_ISFIFO(st.st_mode))
    return mrb_true_value();

#endif
  return mrb_false_value();
#endif
}

mrb_value
mrb_filetest_s_symlink_p(mrb_state *mrb, mrb_value klass)
{
#if defined(_WIN32) || defined(_WIN64)
  mrb_raise(mrb, E_NOTIMP_ERROR, "symlink is not supported on this platform");
#else
#ifndef S_ISLNK
#  ifdef _S_ISLNK
#    define S_ISLNK(m) _S_ISLNK(m)
#  else
#    ifdef _S_IFLNK
#      define S_ISLNK(m) (((m) & S_IFMT) == _S_IFLNK)
#    else
#      ifdef S_IFLNK
#        define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#      endif
#    endif
#  endif
#endif

#ifdef S_ISLNK
  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_lstat(mrb, obj, &st) == -1)
    return mrb_false_value();
  if (S_ISLNK(st.st_mode))
    return mrb_true_value();
#endif

  return mrb_false_value();
#endif
}

mrb_value
mrb_filetest_s_socket_p(mrb_state *mrb, mrb_value klass)
{
#if defined(_WIN32) || defined(_WIN64)
  mrb_raise(mrb, E_NOTIMP_ERROR, "socket is not supported on this platform");
#else
#ifndef S_ISSOCK
#  ifdef _S_ISSOCK
#    define S_ISSOCK(m) _S_ISSOCK(m)
#  else
#    ifdef _S_IFSOCK
#      define S_ISSOCK(m) (((m) & S_IFMT) == _S_IFSOCK)
#    else
#      ifdef S_IFSOCK
#        define S_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)
#      endif
#    endif
#  endif
#endif

#ifdef S_ISSOCK
  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_false_value();
  if (S_ISSOCK(st.st_mode))
    return mrb_true_value();
#endif

  return mrb_false_value();
#endif
}

mrb_value
mrb_filetest_s_exist_p(mrb_state *mrb, mrb_value klass)
{
  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);
  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_false_value();

  return mrb_true_value();
}

mrb_value
mrb_filetest_s_file_p(mrb_state *mrb, mrb_value klass)
{
#ifndef S_ISREG
#   define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif

  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_false_value();
  if (S_ISREG(st.st_mode))
    return mrb_true_value();

  return mrb_false_value();
}

mrb_value
mrb_filetest_s_zero_p(mrb_state *mrb, mrb_value klass)
{
  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_false_value();
  if (st.st_size == 0)
    return mrb_true_value();

  return mrb_false_value();
}

mrb_value
mrb_filetest_s_size(mrb_state *mrb, mrb_value klass)
{
  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    mrb_sys_fail(mrb, "mrb_stat");

  return mrb_fixnum_value(st.st_size);
}

mrb_value
mrb_filetest_s_size_p(mrb_state *mrb, mrb_value klass)
{
  struct stat st;
  mrb_value obj;

  mrb_get_args(mrb, "o", &obj);

  if (mrb_stat(mrb, obj, &st) < 0)
    return mrb_nil_value();
  if (st.st_size == 0)
    return mrb_nil_value();

  return mrb_fixnum_value(st.st_size);
}

void
mrb_init_file_test(mrb_state *mrb)
{
  struct RClass *f;

  f = mrb_define_class(mrb, "FileTest", mrb->object_class);

  mrb_define_class_method(mrb, f, "directory?", mrb_filetest_s_directory_p, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "exist?",     mrb_filetest_s_exist_p,     MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "exists?",    mrb_filetest_s_exist_p,     MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "file?",      mrb_filetest_s_file_p,      MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "pipe?",      mrb_filetest_s_pipe_p,      MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "size",       mrb_filetest_s_size,        MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "size?",      mrb_filetest_s_size_p,      MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "socket?",    mrb_filetest_s_socket_p,    MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "symlink?",   mrb_filetest_s_symlink_p,   MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, f, "zero?",      mrb_filetest_s_zero_p,      MRB_ARGS_REQ(1));
}

