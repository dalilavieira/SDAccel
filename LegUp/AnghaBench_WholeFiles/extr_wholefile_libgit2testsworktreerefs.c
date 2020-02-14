#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int /*<<< orphan*/  flags; } ;
typedef  TYPE_1__ git_worktree_prune_options ;
typedef  int /*<<< orphan*/  git_worktree ;
struct TYPE_15__ {unsigned int count; int /*<<< orphan*/ * strings; } ;
typedef  TYPE_2__ git_strarray ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_commit ;
struct TYPE_16__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_3__ git_buf ;
struct TYPE_17__ {int /*<<< orphan*/  worktree; int /*<<< orphan*/  repo; int /*<<< orphan*/  worktreename; } ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BRANCH_LOCAL ; 
 TYPE_3__ GIT_BUF_INIT ; 
 int GIT_ERROR ; 
 TYPE_1__ GIT_WORKTREE_PRUNE_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_WORKTREE_PRUNE_VALID ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cleanup_fixture_worktree (TYPE_4__*) ; 
 TYPE_4__ fixture ; 
 int git_branch_create (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_branch_delete (int /*<<< orphan*/ *) ; 
 int git_branch_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_3__*) ; 
 int git_buf_joinpath (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int git_commit_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int git_path_exists (int /*<<< orphan*/ ) ; 
 scalar_t__ git_reference_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int git_reference_list (TYPE_2__*,int /*<<< orphan*/ ) ; 
 char* git_reference_name (int /*<<< orphan*/ *) ; 
 int git_reference_rename (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_target (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_commondir (int /*<<< orphan*/ ) ; 
 int git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int git_repository_set_head (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_2__*) ; 
 int /*<<< orphan*/  git_worktree_free (int /*<<< orphan*/ *) ; 
 int git_worktree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int git_worktree_prune (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  setup_fixture_worktree (TYPE_4__*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void test_worktree_refs__initialize(void)
{
	setup_fixture_worktree(&fixture);
}

void test_worktree_refs__cleanup(void)
{
	cleanup_fixture_worktree(&fixture);
}

void test_worktree_refs__list(void)
{
	git_strarray refs, wtrefs;
	unsigned i, j;
	int error = 0;

	cl_git_pass(git_reference_list(&refs, fixture.repo));
	cl_git_pass(git_reference_list(&wtrefs, fixture.worktree));

	if (refs.count != wtrefs.count)
	{
		error = GIT_ERROR;
		goto exit;
	}

	for (i = 0; i < refs.count; i++)
	{
		int found = 0;

		for (j = 0; j < wtrefs.count; j++)
		{
			if (!strcmp(refs.strings[i], wtrefs.strings[j]))
			{
				found = 1;
				break;
			}
		}

		if (!found)
		{
			error = GIT_ERROR;
			goto exit;
		}
	}

exit:
	git_strarray_free(&refs);
	git_strarray_free(&wtrefs);
	cl_git_pass(error);
}

void test_worktree_refs__read_head(void)
{
	git_reference *head;

	cl_git_pass(git_repository_head(&head, fixture.worktree));

	git_reference_free(head);
}

void test_worktree_refs__set_head_fails_when_worktree_wants_linked_repos_HEAD(void)
{
	git_reference *head;

	cl_git_pass(git_repository_head(&head, fixture.repo));
	cl_git_fail(git_repository_set_head(fixture.worktree, git_reference_name(head)));

	git_reference_free(head);
}

void test_worktree_refs__set_head_fails_when_main_repo_wants_worktree_head(void)
{
	git_reference *head;

	cl_git_pass(git_repository_head(&head, fixture.worktree));
	cl_git_fail(git_repository_set_head(fixture.repo, git_reference_name(head)));

	git_reference_free(head);
}

void test_worktree_refs__set_head_works_for_current_HEAD(void)
{
	git_reference *head;

	cl_git_pass(git_repository_head(&head, fixture.repo));
	cl_git_pass(git_repository_set_head(fixture.repo, git_reference_name(head)));

	git_reference_free(head);
}

void test_worktree_refs__set_head_fails_when_already_checked_out(void)
{
	cl_git_fail(git_repository_set_head(fixture.repo, "refs/heads/testrepo-worktree"));
}

void test_worktree_refs__delete_fails_for_checked_out_branch(void)
{
	git_reference *branch;

	cl_git_pass(git_branch_lookup(&branch, fixture.repo,
		    "testrepo-worktree", GIT_BRANCH_LOCAL));
	cl_git_fail(git_branch_delete(branch));

	git_reference_free(branch);
}

void test_worktree_refs__delete_succeeds_after_pruning_worktree(void)
{
	git_worktree_prune_options opts = GIT_WORKTREE_PRUNE_OPTIONS_INIT;
	git_reference *branch;
	git_worktree *worktree;

	opts.flags = GIT_WORKTREE_PRUNE_VALID;

	cl_git_pass(git_worktree_lookup(&worktree, fixture.repo, fixture.worktreename));
	cl_git_pass(git_worktree_prune(worktree, &opts));
	git_worktree_free(worktree);

	cl_git_pass(git_branch_lookup(&branch, fixture.repo,
		    "testrepo-worktree", GIT_BRANCH_LOCAL));
	cl_git_pass(git_branch_delete(branch));
	git_reference_free(branch);
}

void test_worktree_refs__delete_unrelated_branch_on_worktree(void)
{
	git_reference *branch;

	cl_git_pass(git_branch_lookup(&branch, fixture.worktree,
		    "merge-conflict", GIT_BRANCH_LOCAL));
	cl_git_pass(git_branch_delete(branch));

	git_reference_free(branch);
}

void test_worktree_refs__delete_unrelated_branch_on_parent(void)
{
	git_reference *branch;

	cl_git_pass(git_branch_lookup(&branch, fixture.repo,
		    "merge-conflict", GIT_BRANCH_LOCAL));
	cl_git_pass(git_branch_delete(branch));

	git_reference_free(branch);
}

void test_worktree_refs__renaming_reference_updates_worktree_heads(void)
{
	git_reference *head, *branch, *renamed;

	cl_git_pass(git_branch_lookup(&branch, fixture.repo,
		    "testrepo-worktree", GIT_BRANCH_LOCAL));
	cl_git_pass(git_reference_rename(&renamed, branch, "refs/heads/renamed", 0, NULL));
	cl_git_pass(git_repository_head(&head, fixture.worktree));

	git_reference_free(head);
	git_reference_free(branch);
	git_reference_free(renamed);
}

void test_worktree_refs__creating_refs_uses_commondir(void)
{
	   git_reference *head, *branch, *lookup;
	   git_commit *commit;
	   git_buf refpath = GIT_BUF_INIT;

	   cl_git_pass(git_buf_joinpath(&refpath,
		       git_repository_commondir(fixture.worktree), "refs/heads/testbranch"));
	   cl_assert(!git_path_exists(refpath.ptr));

	   cl_git_pass(git_repository_head(&head, fixture.worktree));
	   cl_git_pass(git_commit_lookup(&commit, fixture.worktree, git_reference_target(head)));
	   cl_git_pass(git_branch_create(&branch, fixture.worktree, "testbranch", commit, 0));
	   cl_git_pass(git_branch_lookup(&lookup, fixture.worktree, "testbranch", GIT_BRANCH_LOCAL));
	   cl_assert(git_reference_cmp(branch, lookup) == 0);
	   cl_assert(git_path_exists(refpath.ptr));

	   git_reference_free(lookup);
	   git_reference_free(branch);
	   git_reference_free(head);
	   git_commit_free(commit);
	   git_buf_dispose(&refpath);
}

