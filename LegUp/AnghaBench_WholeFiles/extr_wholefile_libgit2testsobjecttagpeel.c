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
typedef  int /*<<< orphan*/  git_tag ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 scalar_t__ GIT_OBJECT_BLOB ; 
 scalar_t__ GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/ *) ; 
 scalar_t__ git_object_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_oid_streq (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/  git_tag_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tag_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tag_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * repo ; 
 int /*<<< orphan*/ * tag ; 
 int /*<<< orphan*/ * target ; 

void test_object_tag_peel__initialize(void)
{
	cl_fixture_sandbox("testrepo.git");
	cl_git_pass(git_repository_open(&repo, "testrepo.git"));
}

void test_object_tag_peel__cleanup(void)
{
	git_tag_free(tag);
	tag = NULL;

	git_object_free(target);
	target = NULL;

	git_repository_free(repo);
	repo = NULL;

	cl_fixture_cleanup("testrepo.git");
}

__attribute__((used)) static void retrieve_tag_from_oid(git_tag **tag_out, git_repository *repo, const char *sha)
{
	git_oid oid;

	cl_git_pass(git_oid_fromstr(&oid, sha));
	cl_git_pass(git_tag_lookup(tag_out, repo, &oid));
}

void test_object_tag_peel__can_peel_to_a_commit(void)
{
	retrieve_tag_from_oid(&tag, repo, "7b4384978d2493e851f9cca7858815fac9b10980");

	cl_git_pass(git_tag_peel(&target, tag));
	cl_assert(git_object_type(target) == GIT_OBJECT_COMMIT);
	cl_git_pass(git_oid_streq(git_object_id(target), "e90810b8df3e80c413d903f631643c716887138d"));
}

void test_object_tag_peel__can_peel_several_nested_tags_to_a_commit(void)
{
	retrieve_tag_from_oid(&tag, repo, "b25fa35b38051e4ae45d4222e795f9df2e43f1d1");

	cl_git_pass(git_tag_peel(&target, tag));
	cl_assert(git_object_type(target) == GIT_OBJECT_COMMIT);
	cl_git_pass(git_oid_streq(git_object_id(target), "e90810b8df3e80c413d903f631643c716887138d"));
}

void test_object_tag_peel__can_peel_to_a_non_commit(void)
{
	retrieve_tag_from_oid(&tag, repo, "521d87c1ec3aef9824daf6d96cc0ae3710766d91");

	cl_git_pass(git_tag_peel(&target, tag));
	cl_assert(git_object_type(target) == GIT_OBJECT_BLOB);
	cl_git_pass(git_oid_streq(git_object_id(target), "1385f264afb75a56a5bec74243be9b367ba4ca08"));
}

