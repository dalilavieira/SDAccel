#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int count; char** strings; } ;
typedef  TYPE_1__ git_strarray ;
typedef  int /*<<< orphan*/  git_remote ;
typedef  int /*<<< orphan*/  git_reference ;
struct TYPE_16__ {int /*<<< orphan*/  download_tags; } ;
typedef  TYPE_2__ git_fetch_options ;
typedef  int /*<<< orphan*/  git_config ;
typedef  int /*<<< orphan*/  git_clone_options ;
struct TYPE_17__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_3__ git_buf ;
struct TYPE_18__ {TYPE_2__ fetch_opts; int /*<<< orphan*/  version; } ;

/* Variables and functions */
 char* FETCH_HEAD_EXPLICIT_DATA ; 
 char* FETCH_HEAD_NO_MERGE_DATA ; 
 char* FETCH_HEAD_NO_MERGE_DATA2 ; 
 char* FETCH_HEAD_NO_MERGE_DATA3 ; 
 char* FETCH_HEAD_WILDCARD_DATA ; 
 char* FETCH_HEAD_WILDCARD_DATA2 ; 
 int /*<<< orphan*/  GIT_BRANCH_ALL ; 
 TYPE_3__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_CLONE_OPTIONS_VERSION ; 
 TYPE_2__ GIT_FETCH_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_REMOTE_DOWNLOAD_TAGS_AUTO ; 
 int /*<<< orphan*/  LIVE_REPO_URL ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 TYPE_4__ g_options ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_branch_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_3__*) ; 
 int /*<<< orphan*/  git_clone (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,TYPE_4__*) ; 
 int /*<<< orphan*/  git_config_delete_entry (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_futils_readbuffer (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_list (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_fetch (int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_tag_delete (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 

void test_online_fetchhead__initialize(void)
{
	git_fetch_options dummy_fetch = GIT_FETCH_OPTIONS_INIT;
	g_repo = NULL;

	memset(&g_options, 0, sizeof(git_clone_options));
	g_options.version = GIT_CLONE_OPTIONS_VERSION;
	g_options.fetch_opts = dummy_fetch;
}

void test_online_fetchhead__cleanup(void)
{
	if (g_repo) {
		git_repository_free(g_repo);
		g_repo = NULL;
	}

	cl_fixture_cleanup("./foo");
}

__attribute__((used)) static void fetchhead_test_clone(void)
{
	cl_git_pass(git_clone(&g_repo, LIVE_REPO_URL, "./foo", &g_options));
}

__attribute__((used)) static int count_references(void)
{
	git_strarray array;
	int refs;

	cl_git_pass(git_reference_list(&array, g_repo));
	refs = array.count;

	git_strarray_free(&array);

	return refs;
}

__attribute__((used)) static void fetchhead_test_fetch(const char *fetchspec, const char *expected_fetchhead)
{
	git_remote *remote;
	git_fetch_options fetch_opts = GIT_FETCH_OPTIONS_INIT;
	git_buf fetchhead_buf = GIT_BUF_INIT;
	int equals = 0;
	git_strarray array, *active_refs = NULL;

	cl_git_pass(git_remote_lookup(&remote, g_repo, "origin"));
	fetch_opts.download_tags = GIT_REMOTE_DOWNLOAD_TAGS_AUTO;

	if(fetchspec != NULL) {
		array.count = 1;
		array.strings = (char **) &fetchspec;
		active_refs = &array;
	}

	cl_git_pass(git_remote_fetch(remote, active_refs, &fetch_opts, NULL));
	git_remote_free(remote);

	cl_git_pass(git_futils_readbuffer(&fetchhead_buf, "./foo/.git/FETCH_HEAD"));

	equals = (strcmp(fetchhead_buf.ptr, expected_fetchhead) == 0);

	git_buf_dispose(&fetchhead_buf);

	cl_assert(equals);
}

void test_online_fetchhead__wildcard_spec(void)
{
	fetchhead_test_clone();
	fetchhead_test_fetch(NULL, FETCH_HEAD_WILDCARD_DATA2);
	cl_git_pass(git_tag_delete(g_repo, "annotated_tag"));
	cl_git_pass(git_tag_delete(g_repo, "blob"));
	cl_git_pass(git_tag_delete(g_repo, "commit_tree"));
	cl_git_pass(git_tag_delete(g_repo, "nearly-dangling"));
	fetchhead_test_fetch(NULL, FETCH_HEAD_WILDCARD_DATA);
}

void test_online_fetchhead__explicit_spec(void)
{
	fetchhead_test_clone();
	fetchhead_test_fetch("refs/heads/first-merge:refs/remotes/origin/first-merge", FETCH_HEAD_EXPLICIT_DATA);
}

void test_online_fetchhead__no_merges(void)
{
	git_config *config;

	fetchhead_test_clone();

	cl_git_pass(git_repository_config(&config, g_repo));
	cl_git_pass(git_config_delete_entry(config, "branch.master.remote"));
	cl_git_pass(git_config_delete_entry(config, "branch.master.merge"));
	git_config_free(config);

	fetchhead_test_fetch(NULL, FETCH_HEAD_NO_MERGE_DATA2);
	cl_git_pass(git_tag_delete(g_repo, "annotated_tag"));
	cl_git_pass(git_tag_delete(g_repo, "blob"));
	cl_git_pass(git_tag_delete(g_repo, "commit_tree"));
	cl_git_pass(git_tag_delete(g_repo, "nearly-dangling"));
	fetchhead_test_fetch(NULL, FETCH_HEAD_NO_MERGE_DATA);
	cl_git_pass(git_tag_delete(g_repo, "commit_tree"));
	fetchhead_test_fetch(NULL, FETCH_HEAD_NO_MERGE_DATA3);
}

void test_online_fetchhead__explicit_dst_refspec_creates_branch(void)
{
	git_reference *ref;
	int refs;

	fetchhead_test_clone();
	refs = count_references();
	fetchhead_test_fetch("refs/heads/first-merge:refs/heads/explicit-refspec", FETCH_HEAD_EXPLICIT_DATA);

	cl_git_pass(git_branch_lookup(&ref, g_repo, "explicit-refspec", GIT_BRANCH_ALL));
	cl_assert_equal_i(refs + 1, count_references());

	git_reference_free(ref);
}

void test_online_fetchhead__empty_dst_refspec_creates_no_branch(void)
{
	git_reference *ref;
	int refs;

	fetchhead_test_clone();
	refs = count_references();

	fetchhead_test_fetch("refs/heads/first-merge", FETCH_HEAD_EXPLICIT_DATA);
	cl_git_fail(git_branch_lookup(&ref, g_repo, "first-merge", GIT_BRANCH_ALL));

	cl_assert_equal_i(refs, count_references());
}

void test_online_fetchhead__colon_only_dst_refspec_creates_no_branch(void)
{
	int refs;

	fetchhead_test_clone();
	refs = count_references();
	fetchhead_test_fetch("refs/heads/first-merge:", FETCH_HEAD_EXPLICIT_DATA);

	cl_assert_equal_i(refs, count_references());
}

