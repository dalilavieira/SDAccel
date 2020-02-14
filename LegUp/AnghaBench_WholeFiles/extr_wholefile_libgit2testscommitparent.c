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
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_commit ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/ * _repo ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * commit ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_commit_nth_gen_ancestor (int /*<<< orphan*/ **,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int git_oid_streq (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

void test_commit_parent__initialize(void)
{
	git_oid oid;

	cl_git_pass(git_repository_open(&_repo, cl_fixture("testrepo.git")));

	git_oid_fromstr(&oid, "be3563ae3f795b2b4353bcce3a527ad0a4f7f644");
	cl_git_pass(git_commit_lookup(&commit, _repo, &oid));
}

void test_commit_parent__cleanup(void)
{
	git_commit_free(commit);
	commit = NULL;

	git_repository_free(_repo);
	_repo = NULL;
}

__attribute__((used)) static void assert_nth_gen_parent(unsigned int gen, const char *expected_oid)
{
	git_commit *parent = NULL;
	int error;
	
	error = git_commit_nth_gen_ancestor(&parent, commit, gen);

	if (expected_oid != NULL) {
		cl_assert_equal_i(0, error);
		cl_assert_equal_i(0, git_oid_streq(git_commit_id(parent), expected_oid));
	} else
		cl_assert_equal_i(GIT_ENOTFOUND, error);

	git_commit_free(parent);
}

void test_commit_parent__can_retrieve_nth_generation_parent(void)
{
	assert_nth_gen_parent(0, "be3563ae3f795b2b4353bcce3a527ad0a4f7f644");
	assert_nth_gen_parent(1, "9fd738e8f7967c078dceed8190330fc8648ee56a");
	assert_nth_gen_parent(3, "5b5b025afb0b4c913b4c338a42934a3863bf3644");
	assert_nth_gen_parent(42, NULL);
}

