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

/* Variables and functions */
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  path ; 

void test_win32_longpath__initialize(void)
{
#ifdef GIT_WIN32
	const char *base = clar_sandbox_path();
	size_t base_len = strlen(base);
	size_t remain = MAX_PATH - base_len;
	size_t i;

	git_buf_clear(&path);
	git_buf_puts(&path, base);
	git_buf_putc(&path, '/');

	cl_assert(remain < (MAX_PATH - 5));

	for (i = 0; i < (remain - 5); i++)
		git_buf_putc(&path, 'a');
#endif
}

void test_win32_longpath__cleanup(void)
{
	git_buf_dispose(&path);
}

void test_win32_longpath__errmsg_on_checkout(void)
{
#ifdef GIT_WIN32
	git_repository *repo;

	cl_git_fail(git_clone(&repo, cl_fixture("testrepo.git"), path.ptr, NULL));
	assert_name_too_long();
#endif
}

