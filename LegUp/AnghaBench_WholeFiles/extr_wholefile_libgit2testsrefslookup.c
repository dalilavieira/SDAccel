#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_2__ {int /*<<< orphan*/  message; } ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  g_repo ; 
 TYPE_1__* git_error_last () ; 
 int git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ git_reference_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_dwim (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int git_reference_lookup_resolved (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,int) ; 
 int git_reference_name_to_id (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int git_reference_resolve (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

void test_refs_lookup__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo.git");
}

void test_refs_lookup__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_refs_lookup__with_resolve(void)
{
	git_reference *a, *b, *temp;

	cl_git_pass(git_reference_lookup(&temp, g_repo, "HEAD"));
	cl_git_pass(git_reference_resolve(&a, temp));
	git_reference_free(temp);

	cl_git_pass(git_reference_lookup_resolved(&b, g_repo, "HEAD", 5));
	cl_assert(git_reference_cmp(a, b) == 0);
	git_reference_free(b);

	cl_git_pass(git_reference_lookup_resolved(&b, g_repo, "HEAD_TRACKER", 5));
	cl_assert(git_reference_cmp(a, b) == 0);
	git_reference_free(b);

	git_reference_free(a);
}

void test_refs_lookup__invalid_name(void)
{
	git_oid oid;
	cl_git_fail(git_reference_name_to_id(&oid, g_repo, "/refs/tags/point_to_blob"));
}

void test_refs_lookup__oid(void)
{
	git_oid tag, expected;

	cl_git_pass(git_reference_name_to_id(&tag, g_repo, "refs/tags/point_to_blob"));
	cl_git_pass(git_oid_fromstr(&expected, "1385f264afb75a56a5bec74243be9b367ba4ca08"));
	cl_assert_equal_oid(&expected, &tag);
}

void test_refs_lookup__namespace(void)
{
	int error;
	git_reference *ref;

	error = git_reference_lookup(&ref, g_repo, "refs/heads");
	cl_assert_equal_i(error, GIT_ENOTFOUND);

	error = git_reference_lookup(&ref, g_repo, "refs/heads/");
	cl_assert_equal_i(error, GIT_EINVALIDSPEC);
}

void test_refs_lookup__dwim_notfound(void)
{
	git_reference *ref;

	cl_git_fail_with(GIT_ENOTFOUND, git_reference_dwim(&ref, g_repo, "idontexist"));
	cl_assert_equal_s("no reference found for shorthand 'idontexist'", git_error_last()->message);
}

