#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_refdb ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_5__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  current_master_tip ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_1__*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_path_exists (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_refdb_compress (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_refdb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_create (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_delete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_reference_remove (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_refdb (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 char const* packed_test_head_name ; 
 int reference_is_packed (int /*<<< orphan*/ *) ; 

void test_refs_delete__initialize(void)
{
   g_repo = cl_git_sandbox_init("testrepo");
}

void test_refs_delete__cleanup(void)
{
   cl_git_sandbox_cleanup();
}

void test_refs_delete__packed_loose(void)
{
	/* deleting a ref which is both packed and loose should remove both tracks in the filesystem */
	git_reference *looked_up_ref, *another_looked_up_ref;
	git_buf temp_path = GIT_BUF_INIT;

	/* Ensure the loose reference exists on the file system */
	cl_git_pass(git_buf_joinpath(&temp_path, git_repository_path(g_repo), packed_test_head_name));
	cl_assert(git_path_exists(temp_path.ptr));

	/* Lookup the reference */
	cl_git_pass(git_reference_lookup(&looked_up_ref, g_repo, packed_test_head_name));

	/* Ensure it's the loose version that has been found */
	cl_assert(reference_is_packed(looked_up_ref) == 0);

	/* Now that the reference is deleted... */
	cl_git_pass(git_reference_delete(looked_up_ref));
	git_reference_free(looked_up_ref);

	/* Looking up the reference once again should not retrieve it */
	cl_git_fail(git_reference_lookup(&another_looked_up_ref, g_repo, packed_test_head_name));

	/* Ensure the loose reference doesn't exist any longer on the file system */
	cl_assert(!git_path_exists(temp_path.ptr));

	git_reference_free(another_looked_up_ref);
	git_buf_dispose(&temp_path);
}

void test_refs_delete__packed_only(void)
{
	/* can delete a just packed reference */
	git_reference *ref;
	git_refdb *refdb;
	git_oid id;
	const char *new_ref = "refs/heads/new_ref";

	git_oid_fromstr(&id, current_master_tip);

	/* Create and write the new object id reference */
	cl_git_pass(git_reference_create(&ref, g_repo, new_ref, &id, 0, NULL));
	git_reference_free(ref);

	/* Lookup the reference */
	cl_git_pass(git_reference_lookup(&ref, g_repo, new_ref));

	/* Ensure it's a loose reference */
	cl_assert(reference_is_packed(ref) == 0);

	/* Pack all existing references */
	cl_git_pass(git_repository_refdb(&refdb, g_repo));
	cl_git_pass(git_refdb_compress(refdb));

	/* Reload the reference from disk */
	git_reference_free(ref);
	cl_git_pass(git_reference_lookup(&ref, g_repo, new_ref));

	/* Ensure it's a packed reference */
	cl_assert(reference_is_packed(ref) == 1);

	/* This should pass */
	cl_git_pass(git_reference_delete(ref));
	git_reference_free(ref);
	git_refdb_free(refdb);
}

void test_refs_delete__remove(void)
{
	git_reference *ref;

	/* Check that passing no old values lets us delete */

	cl_git_pass(git_reference_lookup(&ref, g_repo, packed_test_head_name));
	git_reference_free(ref);

	cl_git_pass(git_reference_remove(g_repo, packed_test_head_name));

	cl_git_fail(git_reference_lookup(&ref, g_repo, packed_test_head_name));
}

