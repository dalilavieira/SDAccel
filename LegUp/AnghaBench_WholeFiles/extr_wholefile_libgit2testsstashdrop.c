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
typedef  int /*<<< orphan*/  git_reflog_entry ;
typedef  int /*<<< orphan*/  git_reflog ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_REFS_STASH_FILE ; 
 int /*<<< orphan*/  GIT_RMDIR_REMOVE_FILES ; 
 int /*<<< orphan*/  GIT_STASH_INCLUDE_UNTRACKED ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (size_t,size_t) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_repo_commit_from_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_futils_rmdir_r (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/ *) ; 
 int git_oid_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_path_exists (char*) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_name_to_id (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * git_reflog_entry_byindex (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_reflog_entry_id_old (int /*<<< orphan*/  const*) ; 
 size_t git_reflog_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reflog_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reflog_read (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_init (int /*<<< orphan*/ **,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_signature_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_signature_new (int /*<<< orphan*/ **,char*,char*,int,int) ; 
 int /*<<< orphan*/  git_stash_drop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_stash_save (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * repo ; 
 int /*<<< orphan*/ * signature ; 

void test_stash_drop__initialize(void)
{
	cl_git_pass(git_repository_init(&repo, "stash", 0));
	cl_git_pass(git_signature_new(&signature, "nulltoken", "emeric.fermas@gmail.com", 1323847743, 60)); /* Wed Dec 14 08:29:03 2011 +0100 */
}

void test_stash_drop__cleanup(void)
{
	git_signature_free(signature);
	signature = NULL;

	git_repository_free(repo);
	repo = NULL;

	cl_git_pass(git_futils_rmdir_r("stash", NULL, GIT_RMDIR_REMOVE_FILES));
}

void test_stash_drop__cannot_drop_from_an_empty_stash(void)
{
	cl_git_fail_with(git_stash_drop(repo, 0), GIT_ENOTFOUND);
}

__attribute__((used)) static void push_three_states(void)
{
	git_oid oid;
	git_index *index;

	cl_git_mkfile("stash/zero.txt", "content\n");
	cl_git_pass(git_repository_index(&index, repo));
	cl_git_pass(git_index_add_bypath(index, "zero.txt"));
	cl_repo_commit_from_index(NULL, repo, signature, 0, "Initial commit");
	cl_assert(git_path_exists("stash/zero.txt"));
	git_index_free(index);

	cl_git_mkfile("stash/one.txt", "content\n");
	cl_git_pass(git_stash_save(
		&oid, repo, signature, "First", GIT_STASH_INCLUDE_UNTRACKED));
	cl_assert(!git_path_exists("stash/one.txt"));
	cl_assert(git_path_exists("stash/zero.txt"));

	cl_git_mkfile("stash/two.txt", "content\n");
	cl_git_pass(git_stash_save(
		&oid, repo, signature, "Second", GIT_STASH_INCLUDE_UNTRACKED));
	cl_assert(!git_path_exists("stash/two.txt"));
	cl_assert(git_path_exists("stash/zero.txt"));

	cl_git_mkfile("stash/three.txt", "content\n");
	cl_git_pass(git_stash_save(
		&oid, repo, signature, "Third", GIT_STASH_INCLUDE_UNTRACKED));
	cl_assert(!git_path_exists("stash/three.txt"));
	cl_assert(git_path_exists("stash/zero.txt"));
}

void test_stash_drop__cannot_drop_a_non_existing_stashed_state(void)
{
	push_three_states();

	cl_git_fail_with(git_stash_drop(repo, 666), GIT_ENOTFOUND);
	cl_git_fail_with(git_stash_drop(repo, 42), GIT_ENOTFOUND);
	cl_git_fail_with(git_stash_drop(repo, 3), GIT_ENOTFOUND);
}

void test_stash_drop__can_purge_the_stash_from_the_top(void)
{
	push_three_states();

	cl_git_pass(git_stash_drop(repo, 0));
	cl_git_pass(git_stash_drop(repo, 0));
	cl_git_pass(git_stash_drop(repo, 0));

	cl_git_fail_with(git_stash_drop(repo, 0), GIT_ENOTFOUND);
}

void test_stash_drop__can_purge_the_stash_from_the_bottom(void)
{
	push_three_states();

	cl_git_pass(git_stash_drop(repo, 2));
	cl_git_pass(git_stash_drop(repo, 1));
	cl_git_pass(git_stash_drop(repo, 0));

	cl_git_fail_with(git_stash_drop(repo, 0), GIT_ENOTFOUND);
}

void test_stash_drop__dropping_an_entry_rewrites_reflog_history(void)
{
	git_reference *stash;
	git_reflog *reflog;
	const git_reflog_entry *entry;
	git_oid oid;
	size_t count;

	push_three_states();

	cl_git_pass(git_reference_lookup(&stash, repo, GIT_REFS_STASH_FILE));

	cl_git_pass(git_reflog_read(&reflog, repo, GIT_REFS_STASH_FILE));
	entry = git_reflog_entry_byindex(reflog, 1);

	git_oid_cpy(&oid, git_reflog_entry_id_old(entry));
	count = git_reflog_entrycount(reflog);

	git_reflog_free(reflog);

	cl_git_pass(git_stash_drop(repo, 1));

	cl_git_pass(git_reflog_read(&reflog, repo, GIT_REFS_STASH_FILE));
	entry = git_reflog_entry_byindex(reflog, 0);

	cl_assert_equal_oid(&oid, git_reflog_entry_id_old(entry));
	cl_assert_equal_sz(count - 1, git_reflog_entrycount(reflog));

	git_reflog_free(reflog);

	git_reference_free(stash);
}

void test_stash_drop__dropping_the_last_entry_removes_the_stash(void)
{
	git_reference *stash;

	push_three_states();

	cl_git_pass(git_reference_lookup(&stash, repo, GIT_REFS_STASH_FILE));
	git_reference_free(stash);

	cl_git_pass(git_stash_drop(repo, 0));
	cl_git_pass(git_stash_drop(repo, 0));
	cl_git_pass(git_stash_drop(repo, 0));

	cl_git_fail_with(
		git_reference_lookup(&stash, repo, GIT_REFS_STASH_FILE), GIT_ENOTFOUND);
}

void retrieve_top_stash_id(git_oid *out)
{
	git_object *top_stash;

	cl_git_pass(git_revparse_single(&top_stash, repo, "stash@{0}"));
	cl_git_pass(git_reference_name_to_id(out, repo, GIT_REFS_STASH_FILE));

	cl_assert_equal_oid(out, git_object_id(top_stash));

	git_object_free(top_stash);
}

void test_stash_drop__dropping_the_top_stash_updates_the_stash_reference(void)
{
	git_object *next_top_stash;
	git_oid oid;

	push_three_states();

	retrieve_top_stash_id(&oid);

	cl_git_pass(git_revparse_single(&next_top_stash, repo, "stash@{1}"));
	cl_assert(git_oid_cmp(&oid, git_object_id(next_top_stash)));

	cl_git_pass(git_stash_drop(repo, 0));

	retrieve_top_stash_id(&oid);

	cl_assert_equal_oid(&oid, git_object_id(next_top_stash));

	git_object_free(next_top_stash);
}

