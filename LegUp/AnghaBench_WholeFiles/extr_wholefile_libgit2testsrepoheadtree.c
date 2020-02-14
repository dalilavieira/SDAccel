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
 int GIT_ENOTFOUND ; 
 int GIT_EUNBORNBRANCH ; 
 int /*<<< orphan*/  NON_EXISTING_HEAD ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  delete_head (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_streq (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_repository_detach_head (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_head_detached (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_head_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_head_unborn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  make_head_unborn (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  repo ; 
 int /*<<< orphan*/ * tree ; 

void test_repo_headtree__initialize(void)
{
	repo = cl_git_sandbox_init("testrepo.git");
	tree = NULL;
}

void test_repo_headtree__cleanup(void)
{
	git_tree_free(tree);
	cl_git_sandbox_cleanup();
}

void test_repo_headtree__can_retrieve_the_root_tree_from_a_detached_head(void)
{
	cl_git_pass(git_repository_detach_head(repo));

	cl_git_pass(git_repository_head_tree(&tree, repo));

	cl_assert(git_oid_streq(git_tree_id(tree), "az"));
}

void test_repo_headtree__can_retrieve_the_root_tree_from_a_non_detached_head(void)
{
	cl_assert_equal_i(false, git_repository_head_detached(repo));

	cl_git_pass(git_repository_head_tree(&tree, repo));

	cl_assert(git_oid_streq(git_tree_id(tree), "az"));
}

void test_repo_headtree__when_head_is_unborn_returns_EUNBORNBRANCH(void)
{
	make_head_unborn(repo, NON_EXISTING_HEAD);

	cl_assert_equal_i(true, git_repository_head_unborn(repo));

	cl_assert_equal_i(GIT_EUNBORNBRANCH, git_repository_head_tree(&tree, repo));
}

void test_repo_headtree__when_head_is_missing_returns_ENOTFOUND(void)
{
	delete_head(repo);

	cl_assert_equal_i(GIT_ENOTFOUND, git_repository_head_tree(&tree, repo));
}

