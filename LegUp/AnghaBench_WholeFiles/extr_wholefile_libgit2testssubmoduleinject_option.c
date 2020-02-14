#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_submodule ;
struct TYPE_5__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_assert_equal_p (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_rewritefile (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git__strcmp (char*,char const*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_repository_workdir (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_submodule_foreach (int /*<<< orphan*/ ,int (*) (int /*<<< orphan*/ *,char const*,void*),int*) ; 
 int /*<<< orphan*/  git_submodule_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_submodule_path (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_url (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setup_fixture_submodule_simple () ; 

void test_submodule_inject_option__initialize(void)
{
	g_repo = setup_fixture_submodule_simple();
}

void test_submodule_inject_option__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static int find_naughty(git_submodule *sm, const char *name, void *payload)
{
	int *foundit = (int *) payload;

	GIT_UNUSED(sm);

	if (!git__strcmp("naughty", name))
		*foundit = true;

	return 0;
}

void test_submodule_inject_option__url(void)
{
	int foundit;
	git_submodule *sm;
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_buf_joinpath(&buf, git_repository_workdir(g_repo), ".gitmodules"));
	cl_git_rewritefile(buf.ptr,
			   "[submodule \"naughty\"]\n"
			   "    path = testrepo\n"
			   "    url = -u./payload\n");
	git_buf_dispose(&buf);

	/* We do want to find it, but with the appropriate field empty */
	foundit = 0;
	cl_git_pass(git_submodule_foreach(g_repo, find_naughty, &foundit));
	cl_assert_equal_i(1, foundit);

	cl_git_pass(git_submodule_lookup(&sm, g_repo, "naughty"));
	cl_assert_equal_s("testrepo", git_submodule_path(sm));
	cl_assert_equal_p(NULL, git_submodule_url(sm));

	git_submodule_free(sm);
}

void test_submodule_inject_option__path(void)
{
	int foundit;
	git_submodule *sm;
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_buf_joinpath(&buf, git_repository_workdir(g_repo), ".gitmodules"));
	cl_git_rewritefile(buf.ptr,
			   "[submodule \"naughty\"]\n"
			   "    path = --something\n"
			   "    url = blah.git\n");
	git_buf_dispose(&buf);

	/* We do want to find it, but with the appropriate field empty */
	foundit = 0;
	cl_git_pass(git_submodule_foreach(g_repo, find_naughty, &foundit));
	cl_assert_equal_i(1, foundit);

	cl_git_pass(git_submodule_lookup(&sm, g_repo, "naughty"));
	cl_assert_equal_s("naughty", git_submodule_path(sm));
	cl_assert_equal_s("blah.git", git_submodule_url(sm));

	git_submodule_free(sm);
}

