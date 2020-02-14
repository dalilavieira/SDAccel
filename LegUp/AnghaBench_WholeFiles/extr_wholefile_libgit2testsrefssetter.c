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
 scalar_t__ GIT_REFERENCE_DIRECT ; 
 scalar_t__ GIT_REFERENCE_SYMBOLIC ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_reference_set_target (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_create (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_set_target (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_target (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_target (int /*<<< orphan*/ *) ; 
 scalar_t__ git_reference_type (int /*<<< orphan*/ *) ; 
 char* ref_master_name ; 
 char* ref_name ; 
 char* ref_test_name ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 

void test_refs_setter__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo");
}

void test_refs_setter__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_refs_setter__update_direct(void)
{
	git_reference *ref, *test_ref, *new_ref;
	git_oid id;

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_master_name));
	cl_assert(git_reference_type(ref) == GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));
	git_reference_free(ref);

	cl_git_pass(git_reference_lookup(&test_ref, g_repo, ref_test_name));
	cl_assert(git_reference_type(test_ref) == GIT_REFERENCE_DIRECT);

	cl_git_pass(git_reference_set_target(&new_ref, test_ref, &id, NULL));

	git_reference_free(test_ref);
	git_reference_free(new_ref);

	cl_git_pass(git_reference_lookup(&test_ref, g_repo, ref_test_name));
	cl_assert(git_reference_type(test_ref) == GIT_REFERENCE_DIRECT);
	cl_assert_equal_oid(&id, git_reference_target(test_ref));
	git_reference_free(test_ref);
}

void test_refs_setter__update_symbolic(void)
{
	git_reference *head, *new_head;

	cl_git_pass(git_reference_lookup(&head, g_repo, "HEAD"));
	cl_assert(git_reference_type(head) == GIT_REFERENCE_SYMBOLIC);
	cl_assert(strcmp(git_reference_symbolic_target(head), ref_master_name) == 0);

	cl_git_pass(git_reference_symbolic_set_target(&new_head, head, ref_test_name, NULL));
	git_reference_free(new_head);
	git_reference_free(head);

	cl_git_pass(git_reference_lookup(&head, g_repo, "HEAD"));
	cl_assert(git_reference_type(head) == GIT_REFERENCE_SYMBOLIC);
	cl_assert(strcmp(git_reference_symbolic_target(head), ref_test_name) == 0);
	git_reference_free(head);
}

void test_refs_setter__cant_update_direct_with_symbolic(void)
{
	/* Overwrite an existing object id reference with a symbolic one */
	git_reference *ref, *new;
	git_oid id;

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_master_name));
	cl_assert(git_reference_type(ref) == GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));

	cl_git_fail(git_reference_symbolic_set_target(&new, ref, ref_name, NULL));

	git_reference_free(ref);
}

void test_refs_setter__cant_update_symbolic_with_direct(void)
{
	/* Overwrite an existing symbolic reference with an object id one */
	git_reference *ref, *new;
	git_oid id;

	cl_git_pass(git_reference_lookup(&ref, g_repo, ref_master_name));
	cl_assert(git_reference_type(ref) == GIT_REFERENCE_DIRECT);
	git_oid_cpy(&id, git_reference_target(ref));
	git_reference_free(ref);

	/* Create the symbolic ref */
	cl_git_pass(git_reference_symbolic_create(&ref, g_repo, ref_name, ref_master_name, 0, NULL));

	/* Can't set an OID on a direct ref */
	cl_git_fail(git_reference_set_target(&new, ref, &id, NULL));

	git_reference_free(ref);
}

