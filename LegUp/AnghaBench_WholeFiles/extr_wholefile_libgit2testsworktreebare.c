#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_worktree ;
struct TYPE_4__ {int count; } ;
typedef  TYPE_1__ git_strarray ;
typedef  int /*<<< orphan*/  git_repository ;

/* Variables and functions */
 int /*<<< orphan*/  COMMON_REPO ; 
 int /*<<< orphan*/  WORKTREE_REPO ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_path (int,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_repository_commondir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int git_repository_is_bare (int /*<<< orphan*/ *) ; 
 int git_repository_is_worktree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_workdir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_worktree_add (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_worktree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_worktree_list (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_worktree_path (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_worktree_validate (int /*<<< orphan*/ *) ; 

void test_worktree_bare__initialize(void)
{
	g_repo = cl_git_sandbox_init(COMMON_REPO);

	cl_assert_equal_i(1, git_repository_is_bare(g_repo));
	cl_assert_equal_i(0, git_repository_is_worktree(g_repo));
}

void test_worktree_bare__cleanup(void)
{
	cl_fixture_cleanup(WORKTREE_REPO);
	cl_git_sandbox_cleanup();
}

void test_worktree_bare__list(void)
{
	git_strarray wts;

	cl_git_pass(git_worktree_list(&wts, g_repo));
	cl_assert_equal_i(wts.count, 0);

	git_strarray_free(&wts);
}

void test_worktree_bare__add(void)
{
	git_worktree *wt;
	git_repository *wtrepo;
	git_strarray wts;

	cl_git_pass(git_worktree_add(&wt, g_repo, "name", WORKTREE_REPO, NULL));

	cl_git_pass(git_worktree_list(&wts, g_repo));
	cl_assert_equal_i(wts.count, 1);

	cl_git_pass(git_worktree_validate(wt));

	cl_git_pass(git_repository_open(&wtrepo, WORKTREE_REPO));
	cl_assert_equal_i(0, git_repository_is_bare(wtrepo));
	cl_assert_equal_i(1, git_repository_is_worktree(wtrepo));

	git_strarray_free(&wts);
	git_worktree_free(wt);
	git_repository_free(wtrepo);
}

void test_worktree_bare__repository_path(void)
{
	git_worktree *wt;
	git_repository *wtrepo;

	cl_git_pass(git_worktree_add(&wt, g_repo, "name", WORKTREE_REPO, NULL));
	cl_assert_equal_s(git_worktree_path(wt), cl_git_sandbox_path(0, WORKTREE_REPO, NULL));

	cl_git_pass(git_repository_open(&wtrepo, WORKTREE_REPO));
	cl_assert_equal_s(git_repository_path(wtrepo), cl_git_sandbox_path(1, COMMON_REPO, "worktrees", "name", NULL));

	cl_assert_equal_s(git_repository_commondir(g_repo), git_repository_commondir(wtrepo));
	cl_assert_equal_s(git_repository_workdir(wtrepo), cl_git_sandbox_path(1, WORKTREE_REPO, NULL));

	git_repository_free(wtrepo);
	git_worktree_free(wt);
}

