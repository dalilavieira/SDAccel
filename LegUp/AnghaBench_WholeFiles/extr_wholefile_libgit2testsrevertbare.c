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
struct merge_index_entry {int member_0; char* member_1; int member_2; char* member_3; } ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_index ;
typedef  int /*<<< orphan*/  git_commit ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  TEST_REPO_PATH ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_has_conflicts (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_revert_commit (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  merge_test_index (int /*<<< orphan*/ *,struct merge_index_entry*,int) ; 
 int /*<<< orphan*/  repo ; 

void test_revert_bare__initialize(void)
{
	repo = cl_git_sandbox_init(TEST_REPO_PATH);
}

void test_revert_bare__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_revert_bare__automerge(void)
{
	git_commit *head_commit, *revert_commit;
	git_oid head_oid, revert_oid;
	git_index *index;

	struct merge_index_entry merge_index_entries[] = {
		{ 0100644, "caf99de3a49827117bb66721010eac461b06a80c", 0, "file1.txt" },
		{ 0100644, "0ab09ea6d4c3634bdf6c221626d8b6f7dd890767", 0, "file2.txt" },
		{ 0100644, "f4e107c230d08a60fb419d19869f1f282b272d9c", 0, "file3.txt" },
		{ 0100644, "0f5bfcf58c558d865da6be0281d7795993646cee", 0, "file6.txt" },
	};

	git_oid_fromstr(&head_oid, "72333f47d4e83616630ff3b0ffe4c0faebcc3c45");
	cl_git_pass(git_commit_lookup(&head_commit, repo, &head_oid));

	git_oid_fromstr(&revert_oid, "d1d403d22cbe24592d725f442835cf46fe60c8ac");
	cl_git_pass(git_commit_lookup(&revert_commit, repo, &revert_oid));

	cl_git_pass(git_revert_commit(&index, repo, revert_commit, head_commit, 0, NULL));
	cl_assert(merge_test_index(index, merge_index_entries, 4));

	git_commit_free(revert_commit);
	git_commit_free(head_commit);
	git_index_free(index);
}

void test_revert_bare__conflicts(void)
{
	git_reference *head_ref;
	git_commit *head_commit, *revert_commit;
	git_oid revert_oid;
	git_index *index;

	struct merge_index_entry merge_index_entries[] = {
		{ 0100644, "7731926a337c4eaba1e2187d90ebfa0a93659382", 1, "file1.txt" },
		{ 0100644, "4b8fcff56437e60f58e9a6bc630dd242ebf6ea2c", 2, "file1.txt" },
		{ 0100644, "3a3ef367eaf3fe79effbfb0a56b269c04c2b59fe", 3, "file1.txt" },
		{ 0100644, "0ab09ea6d4c3634bdf6c221626d8b6f7dd890767", 0, "file2.txt" },
		{ 0100644, "f4e107c230d08a60fb419d19869f1f282b272d9c", 0, "file3.txt" },
		{ 0100644, "0f5bfcf58c558d865da6be0281d7795993646cee", 0, "file6.txt" },
	};

	git_oid_fromstr(&revert_oid, "72333f47d4e83616630ff3b0ffe4c0faebcc3c45");

	cl_git_pass(git_repository_head(&head_ref, repo));
	cl_git_pass(git_reference_peel((git_object **)&head_commit, head_ref, GIT_OBJECT_COMMIT));

	cl_git_pass(git_commit_lookup(&revert_commit, repo, &revert_oid));
	cl_git_pass(git_revert_commit(&index, repo, revert_commit, head_commit, 0, NULL));

	cl_assert(git_index_has_conflicts(index));
	cl_assert(merge_test_index(index, merge_index_entries, 6));

	git_commit_free(revert_commit);
	git_commit_free(head_commit);
	git_reference_free(head_ref);
	git_index_free(index);
}

void test_revert_bare__orphan(void)
{
	git_commit *head_commit, *revert_commit;
	git_oid head_oid, revert_oid;
	git_index *index;

	struct merge_index_entry merge_index_entries[] = {
		{ 0100644, "296a6d3be1dff05c5d1f631d2459389fa7b619eb", 0, "file-mainline.txt" },
	};

	git_oid_fromstr(&head_oid, "39467716290f6df775a91cdb9a4eb39295018145");
	cl_git_pass(git_commit_lookup(&head_commit, repo, &head_oid));

	git_oid_fromstr(&revert_oid, "ebb03002cee5d66c7732dd06241119fe72ab96a5");
	cl_git_pass(git_commit_lookup(&revert_commit, repo, &revert_oid));

	cl_git_pass(git_revert_commit(&index, repo, revert_commit, head_commit, 0, NULL));
	cl_assert(merge_test_index(index, merge_index_entries, 1));

	git_commit_free(revert_commit);
	git_commit_free(head_commit);
	git_index_free(index);
}

