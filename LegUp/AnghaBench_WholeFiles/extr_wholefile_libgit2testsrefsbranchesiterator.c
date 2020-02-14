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
struct expectations {int encounters; char* member_0; int /*<<< orphan*/  member_1; scalar_t__ branch_name; } ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_branch_t ;
typedef  int /*<<< orphan*/  git_branch_iterator ;

/* Variables and functions */
 unsigned int GIT_BRANCH_ALL ; 
 unsigned int GIT_BRANCH_LOCAL ; 
 unsigned int GIT_BRANCH_REMOTE ; 
 int GIT_ITEROVER ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_fail (char*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/ * fake_remote ; 
 int /*<<< orphan*/  git_branch_iterator_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_branch_iterator_new (int /*<<< orphan*/ **,int /*<<< orphan*/ *,unsigned int) ; 
 int git_branch_next (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_reference_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 char const* git_reference_shorthand (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/ * repo ; 
 scalar_t__ strcmp (char const*,scalar_t__) ; 

void test_refs_branches_iterator__initialize(void)
{
	git_oid id;

	cl_fixture_sandbox("testrepo.git");
	cl_git_pass(git_repository_open(&repo, "testrepo.git"));

	cl_git_pass(git_oid_fromstr(&id, "be3563ae3f795b2b4353bcce3a527ad0a4f7f644"));
	cl_git_pass(git_reference_create(&fake_remote, repo, "refs/remotes/nulltoken/master", &id, 0, NULL));
}

void test_refs_branches_iterator__cleanup(void)
{
	git_reference_free(fake_remote);
	fake_remote = NULL;

	git_repository_free(repo);
	repo = NULL;

	cl_fixture_cleanup("testrepo.git");

	cl_git_sandbox_cleanup();
}

__attribute__((used)) static void assert_retrieval(unsigned int flags, unsigned int expected_count)
{
	git_branch_iterator *iter;
	git_reference *ref;
	int count = 0, error;
	git_branch_t type;

	cl_git_pass(git_branch_iterator_new(&iter, repo, flags));
	while ((error = git_branch_next(&ref, &type, iter)) == 0) {
		count++;
		git_reference_free(ref);
	}

	git_branch_iterator_free(iter);
	cl_assert_equal_i(error, GIT_ITEROVER);
	cl_assert_equal_i(expected_count, count);
}

void test_refs_branches_iterator__retrieve_all_branches(void)
{
	assert_retrieval(GIT_BRANCH_ALL, 14);
}

void test_refs_branches_iterator__retrieve_remote_branches(void)
{
	assert_retrieval(GIT_BRANCH_REMOTE, 2);
}

void test_refs_branches_iterator__retrieve_local_branches(void)
{
	assert_retrieval(GIT_BRANCH_LOCAL, 12);
}

__attribute__((used)) static void assert_branch_has_been_found(struct expectations *findings, const char* expected_branch_name)
{
	int pos = 0;

	for (pos = 0; findings[pos].branch_name; ++pos) {
		if (strcmp(expected_branch_name, findings[pos].branch_name) == 0) {
			cl_assert_equal_i(1, findings[pos].encounters);
			return;
		}
	}

	cl_fail("expected branch not found in list.");
}

__attribute__((used)) static void contains_branches(struct expectations exp[], git_branch_iterator *iter)
{
	git_reference *ref;
	git_branch_t type;
	int error, pos = 0;

	while ((error = git_branch_next(&ref, &type, iter)) == 0) {
		for (pos = 0; exp[pos].branch_name; ++pos) {
			if (strcmp(git_reference_shorthand(ref), exp[pos].branch_name) == 0)
				exp[pos].encounters++;
		}

		git_reference_free(ref);
	}

	cl_assert_equal_i(error, GIT_ITEROVER);
}

void test_refs_branches_iterator__retrieve_remote_symbolic_HEAD_when_present(void)
{
	git_branch_iterator *iter;
	struct expectations exp[] = {
		{ "nulltoken/HEAD", 0 },
		{ "nulltoken/master", 0 },
		{ NULL, 0 }
	};

	git_reference_free(fake_remote);
	cl_git_pass(git_reference_symbolic_create(&fake_remote, repo, "refs/remotes/nulltoken/HEAD", "refs/remotes/nulltoken/master", 0, NULL));

	assert_retrieval(GIT_BRANCH_REMOTE, 3);

	cl_git_pass(git_branch_iterator_new(&iter, repo, GIT_BRANCH_REMOTE));
	contains_branches(exp, iter);
	git_branch_iterator_free(iter);

	assert_branch_has_been_found(exp, "nulltoken/HEAD");
	assert_branch_has_been_found(exp, "nulltoken/master");
}

void test_refs_branches_iterator__mix_of_packed_and_loose(void)
{
	git_branch_iterator *iter;
	struct expectations exp[] = {
		{ "master", 0 },
		{ "origin/HEAD", 0 },
		{ "origin/master", 0 },
		{ "origin/packed", 0 },
		{ NULL, 0 }
	};
	git_repository *r2;

	r2 = cl_git_sandbox_init("testrepo2");

	cl_git_pass(git_branch_iterator_new(&iter, r2, GIT_BRANCH_ALL));
	contains_branches(exp, iter);

	git_branch_iterator_free(iter);

	assert_branch_has_been_found(exp, "master");
	assert_branch_has_been_found(exp, "origin/HEAD");
	assert_branch_has_been_found(exp, "origin/master");
	assert_branch_has_been_found(exp, "origin/packed");
}

