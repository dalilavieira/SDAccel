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
typedef  int git_merge_preference_t ;
typedef  int git_merge_analysis_t ;
typedef  int /*<<< orphan*/  git_config ;
typedef  int /*<<< orphan*/  git_buf ;
typedef  int /*<<< orphan*/  git_annotated_commit ;

/* Variables and functions */
 char* FASTFORWARD_BRANCH ; 
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_HEAD_FILE ; 
 int GIT_MERGE_ANALYSIS_FASTFORWARD ; 
 int GIT_MERGE_ANALYSIS_NORMAL ; 
 int GIT_MERGE_ANALYSIS_UNBORN ; 
 int GIT_MERGE_ANALYSIS_UP_TO_DATE ; 
 int GIT_MERGE_PREFERENCE_FASTFORWARD_ONLY ; 
 int GIT_MERGE_PREFERENCE_NO_FASTFORWARD ; 
 int /*<<< orphan*/  GIT_REFS_HEADS_DIR ; 
 char* NOFASTFORWARD_BRANCH ; 
 char* PREVIOUS_BRANCH ; 
 int /*<<< orphan*/  TEST_REPO_PATH ; 
 char* UPTODATE_BRANCH ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_annotated_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_annotated_commit_from_ref (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_joinpath (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_buf_printf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_config_set_string (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_merge_analysis_for_ref (int*,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  const**,int) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p_unlink (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  repo ; 
 int /*<<< orphan*/  repo_index ; 

void test_merge_workdir_analysis__initialize(void)
{
	repo = cl_git_sandbox_init(TEST_REPO_PATH);
	git_repository_index(&repo_index, repo);
}

void test_merge_workdir_analysis__cleanup(void)
{
	git_index_free(repo_index);
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static void analysis_from_branch(
	git_merge_analysis_t *merge_analysis,
	git_merge_preference_t *merge_pref,
	const char *our_branchname,
	const char *their_branchname)
{
	git_buf our_refname = GIT_BUF_INIT;
	git_buf their_refname = GIT_BUF_INIT;
	git_reference *our_ref;
	git_reference *their_ref;
	git_annotated_commit *their_head;

	if (our_branchname != NULL) {
		cl_git_pass(git_buf_printf(&our_refname, "%s%s", GIT_REFS_HEADS_DIR, our_branchname));
		cl_git_pass(git_reference_lookup(&our_ref, repo, git_buf_cstr(&our_refname)));
	} else {
		cl_git_pass(git_reference_lookup(&our_ref, repo, GIT_HEAD_FILE));
	}

	cl_git_pass(git_buf_printf(&their_refname, "%s%s", GIT_REFS_HEADS_DIR, their_branchname));

	cl_git_pass(git_reference_lookup(&their_ref, repo, git_buf_cstr(&their_refname)));
	cl_git_pass(git_annotated_commit_from_ref(&their_head, repo, their_ref));

	cl_git_pass(git_merge_analysis_for_ref(merge_analysis, merge_pref, repo, our_ref, (const git_annotated_commit **)&their_head, 1));

	git_buf_dispose(&our_refname);
	git_buf_dispose(&their_refname);
	git_annotated_commit_free(their_head);
	git_reference_free(our_ref);
	git_reference_free(their_ref);
}

void test_merge_workdir_analysis__fastforward(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, FASTFORWARD_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_NORMAL|GIT_MERGE_ANALYSIS_FASTFORWARD, merge_analysis);
}

void test_merge_workdir_analysis__no_fastforward(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, NOFASTFORWARD_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_NORMAL, merge_analysis);
}

void test_merge_workdir_analysis__uptodate(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, UPTODATE_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_UP_TO_DATE, merge_analysis);
}

void test_merge_workdir_analysis__uptodate_merging_prev_commit(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, PREVIOUS_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_UP_TO_DATE, merge_analysis);
}

void test_merge_workdir_analysis__unborn(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;
	git_buf master = GIT_BUF_INIT;

	git_buf_joinpath(&master, git_repository_path(repo), "refs/heads/master");
	p_unlink(git_buf_cstr(&master));

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, NOFASTFORWARD_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_FASTFORWARD|GIT_MERGE_ANALYSIS_UNBORN, merge_analysis);

	git_buf_dispose(&master);
}

void test_merge_workdir_analysis__fastforward_with_config_noff(void)
{
	git_config *config;
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	git_repository_config(&config, repo);
	git_config_set_string(config, "merge.ff", "false");

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, FASTFORWARD_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_NORMAL|GIT_MERGE_ANALYSIS_FASTFORWARD, merge_analysis);

	cl_assert_equal_i(GIT_MERGE_PREFERENCE_NO_FASTFORWARD, (merge_pref & GIT_MERGE_PREFERENCE_NO_FASTFORWARD));
}

void test_merge_workdir_analysis__no_fastforward_with_config_ffonly(void)
{
	git_config *config;
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	git_repository_config(&config, repo);
	git_config_set_string(config, "merge.ff", "only");

	analysis_from_branch(&merge_analysis, &merge_pref, NULL, NOFASTFORWARD_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_NORMAL, merge_analysis);

	cl_assert_equal_i(GIT_MERGE_PREFERENCE_FASTFORWARD_ONLY, (merge_pref & GIT_MERGE_PREFERENCE_FASTFORWARD_ONLY));
}

void test_merge_workdir_analysis__between_uptodate_refs(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	analysis_from_branch(&merge_analysis, &merge_pref, NOFASTFORWARD_BRANCH, PREVIOUS_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_UP_TO_DATE, merge_analysis);
}

void test_merge_workdir_analysis__between_noff_refs(void)
{
	git_merge_analysis_t merge_analysis;
	git_merge_preference_t merge_pref;

	analysis_from_branch(&merge_analysis, &merge_pref, "branch", FASTFORWARD_BRANCH);
	cl_assert_equal_i(GIT_MERGE_ANALYSIS_NORMAL, merge_analysis);
}

