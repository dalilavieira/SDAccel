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
typedef  int /*<<< orphan*/  git_reference ;

/* Variables and functions */
 char* GIT_HEAD_FILE ; 
 int /*<<< orphan*/  NON_EXISTING_HEAD ; 
 int /*<<< orphan*/ * branch ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  delete_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_branch_is_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_reference_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  make_head_unborn (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * repo ; 

void test_refs_branches_ishead__initialize(void)
{
	repo = cl_git_sandbox_init("testrepo.git");
	branch = NULL;
}

void test_refs_branches_ishead__cleanup(void)
{
	git_reference_free(branch);
	branch = NULL;

	cl_git_sandbox_cleanup();
	repo = NULL;
}

void test_refs_branches_ishead__can_tell_if_a_branch_is_pointed_at_by_HEAD(void)
{
	cl_git_pass(git_reference_lookup(&branch, repo, "refs/heads/master"));

	cl_assert_equal_i(true, git_branch_is_head(branch));
}

void test_refs_branches_ishead__can_properly_handle_unborn_HEAD(void)
{
	make_head_unborn(repo, NON_EXISTING_HEAD);

	cl_git_pass(git_reference_lookup(&branch, repo, "refs/heads/master"));

	cl_assert_equal_i(false, git_branch_is_head(branch));
}

void test_refs_branches_ishead__can_properly_handle_missing_HEAD(void)
{
	delete_head(repo);

	cl_git_pass(git_reference_lookup(&branch, repo, "refs/heads/master"));

	cl_assert_equal_i(false, git_branch_is_head(branch));
}

void test_refs_branches_ishead__can_tell_if_a_branch_is_not_pointed_at_by_HEAD(void)
{
	cl_git_pass(git_reference_lookup(&branch, repo, "refs/heads/br2"));

	cl_assert_equal_i(false, git_branch_is_head(branch));
}

void test_refs_branches_ishead__wont_be_fooled_by_a_non_branch(void)
{
	cl_git_pass(git_reference_lookup(&branch, repo, "refs/tags/e90810b"));

	cl_assert_equal_i(false, git_branch_is_head(branch));
}

void test_refs_branches_ishead__only_direct_references_are_considered(void)
{
	git_reference *linked, *super, *head;

	cl_git_pass(git_reference_symbolic_create(&linked, repo, "refs/heads/linked", "refs/heads/master", 0, NULL));
	cl_git_pass(git_reference_symbolic_create(&super, repo, "refs/heads/super", "refs/heads/linked", 0, NULL));
	cl_git_pass(git_reference_symbolic_create(&head, repo, GIT_HEAD_FILE, "refs/heads/super", 1, NULL));

	cl_assert_equal_i(false, git_branch_is_head(linked));
	cl_assert_equal_i(false, git_branch_is_head(super));

	cl_git_pass(git_repository_head(&branch, repo));
	cl_assert_equal_s("refs/heads/master", git_reference_name(branch));

	git_reference_free(linked);
	git_reference_free(super);
	git_reference_free(head);
}

