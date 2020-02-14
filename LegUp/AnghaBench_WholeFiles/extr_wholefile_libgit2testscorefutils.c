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
struct TYPE_8__ {int /*<<< orphan*/  size; int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int O_APPEND ; 
 int O_CREAT ; 
 int O_RDWR ; 
 int /*<<< orphan*/  cl_assert_equal_file (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_skip () ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_printf (TYPE_1__*,char*,char*) ; 
 int /*<<< orphan*/  git_buf_put (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_puts (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  git_futils_writebuffer (TYPE_1__*,char*,int,int) ; 
 int /*<<< orphan*/  p_mkdir (char*,int) ; 

void test_core_futils__initialize(void)
{
	cl_must_pass(p_mkdir("futils", 0777));
}

void test_core_futils__cleanup(void)
{
	cl_fixture_cleanup("futils");
}

void test_core_futils__writebuffer(void)
{
	git_buf out = GIT_BUF_INIT,
		append = GIT_BUF_INIT;

	/* create a new file */
	git_buf_puts(&out, "hello!\n");
	git_buf_printf(&out, "this is a %s\n", "test");

	cl_git_pass(git_futils_writebuffer(&out, "futils/test-file", O_RDWR|O_CREAT, 0666));

	cl_assert_equal_file(out.ptr, out.size, "futils/test-file");

	/* append some more data */
	git_buf_puts(&append, "And some more!\n");
	git_buf_put(&out, append.ptr, append.size);

	cl_git_pass(git_futils_writebuffer(&append, "futils/test-file", O_RDWR|O_APPEND, 0666));

	cl_assert_equal_file(out.ptr, out.size, "futils/test-file");

	git_buf_dispose(&out);
	git_buf_dispose(&append);
}

void test_core_futils__write_hidden_file(void)
{
#ifndef GIT_WIN32
	cl_skip();
#else
	git_buf out = GIT_BUF_INIT, append = GIT_BUF_INIT;
	bool hidden;

	git_buf_puts(&out, "hidden file.\n");
	git_futils_writebuffer(&out, "futils/test-file", O_RDWR | O_CREAT, 0666);

	cl_git_pass(git_win32__set_hidden("futils/test-file", true));

	/* append some more data */
	git_buf_puts(&append, "And some more!\n");
	git_buf_put(&out, append.ptr, append.size);

	cl_git_pass(git_futils_writebuffer(&append, "futils/test-file", O_RDWR | O_APPEND, 0666));

	cl_assert_equal_file(out.ptr, out.size, "futils/test-file");

	cl_git_pass(git_win32__hidden(&hidden, "futils/test-file"));
	cl_assert(hidden);

	git_buf_dispose(&out);
	git_buf_dispose(&append);
#endif
}

