#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;
struct TYPE_16__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;
typedef  int /*<<< orphan*/  git_annotated_commit ;
struct TYPE_18__ {int /*<<< orphan*/  workdir; int /*<<< orphan*/  gitdir; } ;
struct TYPE_17__ {TYPE_3__* worktree; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CONFLICT_BRANCH ; 
 int /*<<< orphan*/  CONFLICT_BRANCH_FILE_TXT ; 
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_MERGE_HEAD_FILE ; 
 int /*<<< orphan*/  MASTER_BRANCH ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (size_t,int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cleanup_fixture_worktree (TYPE_2__*) ; 
 TYPE_2__ fixture ; 
 int /*<<< orphan*/  git_annotated_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_annotated_commit_from_ref (int /*<<< orphan*/ **,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_clear (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_buf_printf (TYPE_1__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_futils_readbuffer (TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ git_index_entry_is_conflict (int /*<<< orphan*/  const*) ; 
 size_t git_index_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_index_get_byindex (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  git_merge (TYPE_3__*,int /*<<< orphan*/  const**,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_merge__setup (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/  const**,int) ; 
 int /*<<< orphan*/  const* git_path_exists (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,TYPE_3__*) ; 
 int /*<<< orphan*/ * merge_files ; 
 int /*<<< orphan*/  setup_fixture_worktree (TYPE_2__*) ; 

void test_worktree_merge__initialize(void)
{
	setup_fixture_worktree(&fixture);
}

void test_worktree_merge__cleanup(void)
{
	cleanup_fixture_worktree(&fixture);
}

void test_worktree_merge__merge_head(void)
{
	git_reference *theirs_ref, *ref;
	git_annotated_commit *theirs;

	cl_git_pass(git_reference_lookup(&theirs_ref, fixture.worktree, CONFLICT_BRANCH));
	cl_git_pass(git_annotated_commit_from_ref(&theirs, fixture.worktree, theirs_ref));
	cl_git_pass(git_merge(fixture.worktree, (const git_annotated_commit **)&theirs, 1, NULL, NULL));

	cl_git_pass(git_reference_lookup(&ref, fixture.worktree, GIT_MERGE_HEAD_FILE));

	git_reference_free(ref);
	git_reference_free(theirs_ref);
	git_annotated_commit_free(theirs);
}

void test_worktree_merge__merge_setup(void)
{
	git_reference *ours_ref, *theirs_ref;
	git_annotated_commit *ours, *theirs;
	git_buf path = GIT_BUF_INIT;
	unsigned i;

	cl_git_pass(git_reference_lookup(&ours_ref, fixture.worktree, MASTER_BRANCH));
	cl_git_pass(git_annotated_commit_from_ref(&ours, fixture.worktree, ours_ref));

	cl_git_pass(git_reference_lookup(&theirs_ref, fixture.worktree, CONFLICT_BRANCH));
	cl_git_pass(git_annotated_commit_from_ref(&theirs, fixture.worktree, theirs_ref));

	cl_git_pass(git_merge__setup(fixture.worktree,
		    ours, (const git_annotated_commit **)&theirs, 1));

	for (i = 0; i < ARRAY_SIZE(merge_files); i++) {
		git_buf_clear(&path);
		cl_git_pass(git_buf_printf(&path, "%s/%s",
			    fixture.worktree->gitdir, merge_files[i]));
		cl_assert(git_path_exists(path.ptr));
	}

	git_buf_dispose(&path);
	git_reference_free(ours_ref);
	git_reference_free(theirs_ref);
	git_annotated_commit_free(ours);
	git_annotated_commit_free(theirs);
}

void test_worktree_merge__merge_conflict(void)
{
	git_buf path = GIT_BUF_INIT, buf = GIT_BUF_INIT;
	git_reference *theirs_ref;
	git_annotated_commit *theirs;
	git_index *index;
	const git_index_entry *entry;
	size_t i, conflicts = 0;

	cl_git_pass(git_reference_lookup(&theirs_ref, fixture.worktree, CONFLICT_BRANCH));
	cl_git_pass(git_annotated_commit_from_ref(&theirs, fixture.worktree, theirs_ref));

	cl_git_pass(git_merge(fixture.worktree,
		    (const git_annotated_commit **)&theirs, 1, NULL, NULL));

	cl_git_pass(git_repository_index(&index, fixture.worktree));
	for (i = 0; i < git_index_entrycount(index); i++) {
		cl_assert(entry = git_index_get_byindex(index, i));

		if (git_index_entry_is_conflict(entry))
			conflicts++;
	}
	cl_assert_equal_sz(conflicts, 3);

	git_reference_free(theirs_ref);
	git_annotated_commit_free(theirs);
	git_index_free(index);

	cl_git_pass(git_buf_joinpath(&path, fixture.worktree->workdir, "branch_file.txt"));
	cl_git_pass(git_futils_readbuffer(&buf, path.ptr));
	cl_assert_equal_s(buf.ptr, CONFLICT_BRANCH_FILE_TXT);

	git_buf_dispose(&path);
	git_buf_dispose(&buf);
}

