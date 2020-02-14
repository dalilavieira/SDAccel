#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_fetch_options ;
typedef  int /*<<< orphan*/  git_clone_options ;
struct TYPE_9__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;
struct TYPE_10__ {int bare; int /*<<< orphan*/  fetch_opts; int /*<<< orphan*/  version; } ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_CLONE_OPTIONS_VERSION ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_FETCH_OPTIONS_INIT ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char const*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_remove_placeholders (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_set_cleanup (void (*) (void*),char*) ; 
 TYPE_2__ g_options ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/ * g_repo_cloned ; 
 int /*<<< orphan*/  git_branch_remote_name (TYPE_1__*,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_branch_upstream_name (TYPE_1__*,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_clone (int /*<<< orphan*/ **,char*,char*,TYPE_2__*) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

void test_clone_empty__initialize(void)
{
	git_repository *sandbox = cl_git_sandbox_init("empty_bare.git");
	git_fetch_options dummy_options = GIT_FETCH_OPTIONS_INIT;
	cl_git_remove_placeholders(git_repository_path(sandbox), "dummy-marker.txt");

	g_repo = NULL;

	memset(&g_options, 0, sizeof(git_clone_options));
	g_options.version = GIT_CLONE_OPTIONS_VERSION;
	g_options.fetch_opts = dummy_options;
}

void test_clone_empty__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static void cleanup_repository(void *path)
{
	cl_fixture_cleanup((const char *)path);

	git_repository_free(g_repo_cloned);
	g_repo_cloned = NULL;
}

void test_clone_empty__can_clone_an_empty_local_repo_barely(void)
{
	char *local_name = "refs/heads/master";
	const char *expected_tracked_branch_name = "refs/remotes/origin/master";
	const char *expected_remote_name = "origin";
	git_buf buf = GIT_BUF_INIT;
	git_reference *ref;

	cl_set_cleanup(&cleanup_repository, "./empty");

	g_options.bare = true;
	cl_git_pass(git_clone(&g_repo_cloned, "./empty_bare.git", "./empty", &g_options));

	/* Although the HEAD is unborn... */
	cl_assert_equal_i(GIT_ENOTFOUND, git_reference_lookup(&ref, g_repo_cloned, local_name));

	/* ...one can still retrieve the name of the remote tracking reference */
	cl_git_pass(git_branch_upstream_name(&buf, g_repo_cloned, local_name));

	cl_assert_equal_s(expected_tracked_branch_name, buf.ptr);
	git_buf_dispose(&buf);

	/* ...and the name of the remote... */
	cl_git_pass(git_branch_remote_name(&buf, g_repo_cloned, expected_tracked_branch_name));

	cl_assert_equal_s(expected_remote_name, buf.ptr);
	git_buf_dispose(&buf);

	/* ...even when the remote HEAD is unborn as well */
	cl_assert_equal_i(GIT_ENOTFOUND, git_reference_lookup(&ref, g_repo_cloned,
		expected_tracked_branch_name));
}

void test_clone_empty__can_clone_an_empty_local_repo(void)
{
	cl_set_cleanup(&cleanup_repository, "./empty");

	cl_git_pass(git_clone(&g_repo_cloned, "./empty_bare.git", "./empty", &g_options));
}

void test_clone_empty__can_clone_an_empty_standard_repo(void)
{
	cl_git_sandbox_cleanup();
	g_repo = cl_git_sandbox_init("empty_standard_repo");
	cl_git_remove_placeholders(git_repository_path(g_repo), "dummy-marker.txt");

	cl_set_cleanup(&cleanup_repository, "./empty");

	cl_git_pass(git_clone(&g_repo_cloned, "./empty_standard_repo", "./empty", &g_options));
}

