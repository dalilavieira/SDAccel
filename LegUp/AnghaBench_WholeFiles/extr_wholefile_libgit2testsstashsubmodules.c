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
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_STASH_DEFAULT ; 
 int /*<<< orphan*/  GIT_STATUS_CURRENT ; 
 int /*<<< orphan*/  GIT_STATUS_WT_MODIFIED ; 
 int /*<<< orphan*/  assert_status (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_rewritefile (char*,char*) ; 
 int /*<<< orphan*/  cl_repo_commit_from_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_signature_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_signature_new (int /*<<< orphan*/ **,char*,char*,int,int) ; 
 int /*<<< orphan*/  git_stash_save (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_submodule_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_submodule_open (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  repo ; 
 int /*<<< orphan*/  setup_fixture_submodules () ; 
 int /*<<< orphan*/ * signature ; 
 int /*<<< orphan*/ * sm ; 
 int /*<<< orphan*/  stash_tip_oid ; 

void test_stash_submodules__initialize(void)
{
	cl_git_pass(git_signature_new(&signature, "nulltoken", "emeric.fermas@gmail.com", 1323847743, 60)); /* Wed Dec 14 08:29:03 2011 +0100 */

	repo = setup_fixture_submodules();

	cl_git_pass(git_submodule_lookup(&sm, repo, "testrepo"));
}

void test_stash_submodules__cleanup(void)
{
	git_submodule_free(sm);
	sm = NULL;

	git_signature_free(signature);
	signature = NULL;
}

void test_stash_submodules__does_not_stash_modified_submodules(void)
{
	static git_index *smindex;
	static git_repository *smrepo;

	assert_status(repo, "modified", GIT_STATUS_WT_MODIFIED);

	/* modify file in submodule */
	cl_git_rewritefile("submodules/testrepo/README", "heyheyhey");
	assert_status(repo, "testrepo", GIT_STATUS_WT_MODIFIED);

	/* add file to index in submodule */
	cl_git_pass(git_submodule_open(&smrepo, sm));
	cl_git_pass(git_repository_index(&smindex, smrepo));
	cl_git_pass(git_index_add_bypath(smindex, "README"));

	/* commit changed index of submodule */
	cl_repo_commit_from_index(NULL, smrepo, NULL, 1372350000, "Modify it");
	assert_status(repo, "testrepo", GIT_STATUS_WT_MODIFIED);

	cl_git_pass(git_stash_save(&stash_tip_oid, repo, signature, NULL, GIT_STASH_DEFAULT));

	assert_status(repo, "testrepo", GIT_STATUS_WT_MODIFIED);
	assert_status(repo, "modified", GIT_STATUS_CURRENT);

	git_index_free(smindex);
	git_repository_free(smrepo);
}

void test_stash_submodules__stash_is_empty_with_modified_submodules(void)
{
	static git_index *smindex;
	static git_repository *smrepo;

	cl_git_pass(git_stash_save(&stash_tip_oid, repo, signature, NULL, GIT_STASH_DEFAULT));
	assert_status(repo, "modified", GIT_STATUS_CURRENT);

	/* modify file in submodule */
	cl_git_rewritefile("submodules/testrepo/README", "heyheyhey");
	assert_status(repo, "testrepo", GIT_STATUS_WT_MODIFIED);

	/* add file to index in submodule */
	cl_git_pass(git_submodule_open(&smrepo, sm));
	cl_git_pass(git_repository_index(&smindex, smrepo));
	cl_git_pass(git_index_add_bypath(smindex, "README"));

	/* commit changed index of submodule */
	cl_repo_commit_from_index(NULL, smrepo, NULL, 1372350000, "Modify it");
	assert_status(repo, "testrepo", GIT_STATUS_WT_MODIFIED);

	cl_git_fail_with(git_stash_save(&stash_tip_oid, repo, signature, NULL, GIT_STASH_DEFAULT), GIT_ENOTFOUND);

	git_index_free(smindex);
	git_repository_free(smrepo);
}

