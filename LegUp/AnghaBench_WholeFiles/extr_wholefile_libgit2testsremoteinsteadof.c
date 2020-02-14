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
 int /*<<< orphan*/  REMOTE_INSTEADOF ; 
 int /*<<< orphan*/  REMOTE_ORIGIN ; 
 int /*<<< orphan*/  REPO_PATH ; 
 int /*<<< orphan*/  cl_assert_equal_p (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_fixture (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * g_remote ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_remote_create_anonymous (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_remote_pushurl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_url (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

void test_remote_insteadof__initialize(void)
{
	g_repo = NULL;
	g_remote = NULL;
}

void test_remote_insteadof__cleanup(void)
{
	git_repository_free(g_repo);
	git_remote_free(g_remote);
}

void test_remote_insteadof__url_insteadof_not_applicable(void)
{
	cl_git_pass(git_repository_open(&g_repo, cl_fixture(REPO_PATH)));
	cl_git_pass(git_remote_lookup(&g_remote, g_repo, REMOTE_ORIGIN));

	cl_assert_equal_s(
		git_remote_url(g_remote),
		"https://github.com/libgit2/false.git");
}

void test_remote_insteadof__url_insteadof_applicable(void)
{
	cl_git_pass(git_repository_open(&g_repo, cl_fixture(REPO_PATH)));
	cl_git_pass(git_remote_lookup(&g_remote, g_repo, REMOTE_INSTEADOF));

	cl_assert_equal_s(
	    git_remote_url(g_remote),
	    "http://github.com/libgit2/libgit2");
}

void test_remote_insteadof__pushurl_insteadof_not_applicable(void)
{
	cl_git_pass(git_repository_open(&g_repo, cl_fixture(REPO_PATH)));
	cl_git_pass(git_remote_lookup(&g_remote, g_repo, REMOTE_ORIGIN));

	cl_assert_equal_p(git_remote_pushurl(g_remote), NULL);
}

void test_remote_insteadof__pushurl_insteadof_applicable(void)
{
	cl_git_pass(git_repository_open(&g_repo, cl_fixture(REPO_PATH)));
	cl_git_pass(git_remote_lookup(&g_remote, g_repo, REMOTE_INSTEADOF));

	cl_assert_equal_s(
	    git_remote_pushurl(g_remote),
	    "git@github.com:libgit2/libgit2");
}

void test_remote_insteadof__anonymous_remote(void)
{
	cl_git_pass(git_repository_open(&g_repo, cl_fixture(REPO_PATH)));
	cl_git_pass(git_remote_create_anonymous(&g_remote, g_repo,
	    "http://example.com/libgit2/libgit2"));

	cl_assert_equal_s(
	    git_remote_url(g_remote),
	    "http://github.com/libgit2/libgit2");
	cl_assert_equal_p(git_remote_pushurl(g_remote), NULL);
}

