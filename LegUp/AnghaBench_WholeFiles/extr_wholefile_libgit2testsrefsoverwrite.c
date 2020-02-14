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
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 int GIT_REFERENCE_DIRECT ; 
 int GIT_REFERENCE_SYMBOLIC ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_create (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_symbolic_create (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_target (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_target (int /*<<< orphan*/ *) ; 
 int git_reference_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ref_branch_name ; 
 int /*<<< orphan*/  ref_master_name ; 
 int /*<<< orphan*/  ref_name ; 
 int /*<<< orphan*/  ref_test_name ; 

void test_refs_overwrite__initialize(void)
{
   g_repo = cl_git_sandbox_init("testrepo");
}

void test_refs_overwrite__cleanup(void)
{
   cl_git_sandbox_cleanup();
}

void test_refs_overwrite__symbolic(void)
{
	/* Overwrite an existing symbolic reference */
	git_reference *ref, *branch_ref;

	/* The target needds to exist and we need to check the name has changed */
	cl_git_pass(git_reference_symbolic_create(&branch_ref, g_repo, ref_branch_name, ref_master_name, 0, NULL));
	cl_git_pass(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_branch_name, 0, NULL));
	git_reference_free(ref);

	/* Ensure it points to the right place*/
	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_SYMBOLIC);
	cl_assert_equal_s(git_reference_symbolic_target(ref), ref_branch_name);
	git_reference_free(ref);

	/* Ensure we can't create it unless we force it to */
	cl_git_fail(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_master_name, 0, NULL));
	cl_git_pass(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_master_name, 1, NULL));
	git_reference_free(ref);

	/* Ensure it points to the right place */
	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_SYMBOLIC);
	cl_assert_equal_s(git_reference_symbolic_target(ref), ref_master_name);

	git_reference_free(ref);
	git_reference_free(branch_ref);
}

void test_refs_overwrite__object_id(void)
{
	/* Overwrite an existing object id reference */
	git_reference *ref;
	git_oid id;

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_master_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));
	git_reference_free(ref);

	/* Create it */
	cl_git_pass(git_reference_create(&ref, g_repo, ref_name, &id, 0, NULL));
	git_reference_free(ref);

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_test_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));
	git_reference_free(ref);

	/* Ensure we can't overwrite unless we force it */
	cl_git_fail(git_reference_create(&ref, g_repo, ref_name, &id, 0, NULL));
	cl_git_pass(git_reference_create(&ref, g_repo, ref_name, &id, 1, NULL));
	git_reference_free(ref);

	/* Ensure it has been overwritten */
	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_name));
	cl_assert_equal_oid(&id, git_reference_target(ref));

	git_reference_free(ref);
}

void test_refs_overwrite__object_id_with_symbolic(void)
{
	/* Overwrite an existing object id reference with a symbolic one */
	git_reference *ref;
	git_oid id;

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_master_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));
	git_reference_free(ref);

	cl_git_pass(git_reference_create(&ref, g_repo, ref_name, &id, 0, NULL));
	git_reference_free(ref);
	cl_git_fail(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_master_name, 0, NULL));
	cl_git_pass(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_master_name, 1, NULL));
	git_reference_free(ref);

	/* Ensure it points to the right place */
	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_SYMBOLIC);
	cl_assert_equal_s(git_reference_symbolic_target(ref), ref_master_name);

	git_reference_free(ref);
}

void test_refs_overwrite__symbolic_with_object_id(void)
{
	/* Overwrite an existing symbolic reference with an object id one */
	git_reference *ref;
	git_oid id;

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_master_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));
	git_reference_free(ref);

	/* Create the symbolic ref */
	cl_git_pass(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_master_name, 0, NULL));
	git_reference_free(ref);
	/* It shouldn't overwrite unless we tell it to */
	cl_git_fail(git_reference_create(&ref, g_repo, ref_name, &id, 0, NULL));
	cl_git_pass(git_reference_create(&ref, g_repo, ref_name, &id, 1, NULL));
	git_reference_free(ref);

	/* Ensure it points to the right place */
	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_name));
	cl_assert(git_reference_type(ref) & GIT_REFERENCE_DIRECT);
	cl_assert_equal_oid(&id, git_reference_target(ref));

	git_reference_free(ref);
}

