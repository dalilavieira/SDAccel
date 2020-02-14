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
typedef  int /*<<< orphan*/  git_remote ;
struct TYPE_5__ {int /*<<< orphan*/  ptr; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_EAMBIGUOUS ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_ERROR ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  expected_remote_name ; 
 int expected_remote_name_length ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_branch_remote_name (TYPE_1__*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_error_clear () ; 
 int /*<<< orphan*/ * git_error_last () ; 
 int /*<<< orphan*/  git_remote_create_with_fetchspec (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,char*,char*) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 char const* remote_tracking_branch_name ; 
 scalar_t__ strlen (int /*<<< orphan*/ ) ; 

void test_refs_branches_remote__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo");

	expected_remote_name_length = (int)strlen(expected_remote_name) + 1;
}

void test_refs_branches_remote__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_refs_branches_remote__can_get_remote_for_branch(void)
{
	git_buf remotename = {0};

	cl_git_pass(git_branch_remote_name(&remotename, g_repo, remote_tracking_branch_name));

	cl_assert_equal_s("test", remotename.ptr);
	git_buf_dispose(&remotename);
}

void test_refs_branches_remote__no_matching_remote_returns_error(void)
{
	const char *unknown = "refs/remotes/nonexistent/master";
	git_buf buf;

	git_error_clear();
	memset(&buf, 0, sizeof(git_buf));
	cl_git_fail_with(git_branch_remote_name(&buf, g_repo, unknown), GIT_ENOTFOUND);
	cl_assert(git_error_last() != NULL);
}

void test_refs_branches_remote__local_remote_returns_error(void)
{
	const char *local = "refs/heads/master";
	git_buf buf;

	git_error_clear();
	memset(&buf, 0, sizeof(git_buf));
	cl_git_fail_with(git_branch_remote_name(&buf, g_repo, local), GIT_ERROR);
	cl_assert(git_error_last() != NULL);
}

void test_refs_branches_remote__ambiguous_remote_returns_error(void)
{
	git_remote *remote;
	git_buf buf;

	/* Create the remote */
	cl_git_pass(git_remote_create_with_fetchspec(&remote, g_repo, "addtest", "http://github.com/libgit2/libgit2", "refs/heads/*:refs/remotes/test/*"));

	git_remote_free(remote);

	git_error_clear();
	memset(&buf, 0, sizeof(git_buf));
	cl_git_fail_with(git_branch_remote_name(&buf, g_repo, remote_tracking_branch_name), GIT_EAMBIGUOUS);
	cl_assert(git_error_last() != NULL);
}

