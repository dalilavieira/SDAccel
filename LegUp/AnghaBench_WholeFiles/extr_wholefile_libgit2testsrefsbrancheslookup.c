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
 int /*<<< orphan*/  GIT_BRANCH_ALL ; 
 int /*<<< orphan*/  GIT_BRANCH_LOCAL ; 
 int /*<<< orphan*/  GIT_BRANCH_REMOTE ; 
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/ * branch ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_branch_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * repo ; 

void test_refs_branches_lookup__initialize(void)
{
	cl_git_pass(git_repository_open(&repo, cl_fixture("testrepo.git")));

	branch = NULL;
}

void test_refs_branches_lookup__cleanup(void)
{
	git_reference_free(branch);
	branch = NULL;

	git_repository_free(repo);
	repo = NULL;
}

void test_refs_branches_lookup__can_retrieve_a_local_branch_local(void)
{
	cl_git_pass(git_branch_lookup(&branch, repo, "br2", GIT_BRANCH_LOCAL));
}

void test_refs_branches_lookup__can_retrieve_a_local_branch_all(void)
{
	cl_git_pass(git_branch_lookup(&branch, repo, "br2", GIT_BRANCH_ALL));
}

void test_refs_branches_lookup__trying_to_retrieve_a_local_branch_remote(void)
{
	cl_git_fail(git_branch_lookup(&branch, repo, "br2", GIT_BRANCH_REMOTE));
}

void test_refs_branches_lookup__can_retrieve_a_remote_tracking_branch_remote(void)
{
	cl_git_pass(git_branch_lookup(&branch, repo, "test/master", GIT_BRANCH_REMOTE));
}

void test_refs_branches_lookup__can_retrieve_a_remote_tracking_branch_all(void)
{
	cl_git_pass(git_branch_lookup(&branch, repo, "test/master", GIT_BRANCH_ALL));
}

void test_refs_branches_lookup__trying_to_retrieve_a_remote_tracking_branch_local(void)
{
	cl_git_fail(git_branch_lookup(&branch, repo, "test/master", GIT_BRANCH_LOCAL));
}

void test_refs_branches_lookup__trying_to_retrieve_an_unknown_branch_returns_ENOTFOUND(void)
{
	cl_assert_equal_i(GIT_ENOTFOUND, git_branch_lookup(&branch, repo, "where/are/you", GIT_BRANCH_LOCAL));
	cl_assert_equal_i(GIT_ENOTFOUND, git_branch_lookup(&branch, repo, "over/here", GIT_BRANCH_REMOTE));
	cl_assert_equal_i(GIT_ENOTFOUND, git_branch_lookup(&branch, repo, "maybe/here", GIT_BRANCH_ALL));
}

void test_refs_branches_lookup__trying_to_retrieve_a_branch_with_an_invalid_name_returns_EINVALIDSPEC(void)
{
	cl_assert_equal_i(GIT_EINVALIDSPEC,
		git_branch_lookup(&branch, repo, "are/you/inv@{id", GIT_BRANCH_LOCAL));
	cl_assert_equal_i(GIT_EINVALIDSPEC,
		git_branch_lookup(&branch, repo, "yes/i am", GIT_BRANCH_REMOTE));
	cl_assert_equal_i(GIT_EINVALIDSPEC,
		git_branch_lookup(&branch, repo, "inv al/id", GIT_BRANCH_ALL));
}

