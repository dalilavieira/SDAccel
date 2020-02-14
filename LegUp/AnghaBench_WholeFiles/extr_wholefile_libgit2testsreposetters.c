#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int val; } ;
struct TYPE_4__ {TYPE_1__ refcount; } ;
typedef  TYPE_2__ git_refcount ;
typedef  int /*<<< orphan*/  git_odb ;
typedef  int /*<<< orphan*/  git_index ;
typedef  int /*<<< orphan*/  git_config ;
typedef  int /*<<< orphan*/  git_buf ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 scalar_t__ git__prefixcmp (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ git__suffixcmp (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_get_string_buf (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_futils_readbuffer (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_open (int /*<<< orphan*/ **,char*) ; 
 int git_path_isfile (char*) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int git_repository_is_bare (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/  git_repository_set_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_set_odb (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_set_workdir (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/ * git_repository_workdir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  p_mkdir (char*,int) ; 
 int /*<<< orphan*/ * repo ; 

void test_repo_setters__initialize(void)
{
	cl_fixture_sandbox("testrepo.git");
	cl_git_pass(git_repository_open(&repo, "testrepo.git"));
	cl_must_pass(p_mkdir("new_workdir", 0777));
}

void test_repo_setters__cleanup(void)
{
	git_repository_free(repo);
	repo = NULL;

	cl_fixture_cleanup("testrepo.git");
	cl_fixture_cleanup("new_workdir");
}

void test_repo_setters__setting_a_workdir_turns_a_bare_repository_into_a_standard_one(void)
{
	cl_assert(git_repository_is_bare(repo) == 1);

	cl_assert(git_repository_workdir(repo) == NULL);
	cl_git_pass(git_repository_set_workdir(repo, "./new_workdir", false));

	cl_assert(git_repository_workdir(repo) != NULL);
	cl_assert(git_repository_is_bare(repo) == 0);
}

void test_repo_setters__setting_a_workdir_prettifies_its_path(void)
{
	cl_git_pass(git_repository_set_workdir(repo, "./new_workdir", false));

	cl_assert(git__suffixcmp(git_repository_workdir(repo), "new_workdir/") == 0);
}

void test_repo_setters__setting_a_workdir_creates_a_gitlink(void)
{
	git_config *cfg;
	git_buf buf = GIT_BUF_INIT;
	git_buf content = GIT_BUF_INIT;

	cl_git_pass(git_repository_set_workdir(repo, "./new_workdir", true));

	cl_assert(git_path_isfile("./new_workdir/.git"));

	cl_git_pass(git_futils_readbuffer(&content, "./new_workdir/.git"));
	cl_assert(git__prefixcmp(git_buf_cstr(&content), "gitdir: ") == 0);
	cl_assert(git__suffixcmp(git_buf_cstr(&content), "testrepo.git/") == 0);
	git_buf_dispose(&content);

	cl_git_pass(git_repository_config(&cfg, repo));
	cl_git_pass(git_config_get_string_buf(&buf, cfg, "core.worktree"));
	cl_assert(git__suffixcmp(git_buf_cstr(&buf), "new_workdir/") == 0);

	git_buf_dispose(&buf);
	git_config_free(cfg);
}

void test_repo_setters__setting_a_new_index_on_a_repo_which_has_already_loaded_one_properly_honors_the_refcount(void)
{
	git_index *new_index;

	cl_git_pass(git_index_open(&new_index, "./my-index"));
	cl_assert(((git_refcount *)new_index)->refcount.val == 1);

	git_repository_set_index(repo, new_index);
	cl_assert(((git_refcount *)new_index)->refcount.val == 2);

	git_repository_free(repo);
	cl_assert(((git_refcount *)new_index)->refcount.val == 1);

	git_index_free(new_index);

	/* 
	 * Ensure the cleanup method won't try to free the repo as it's already been taken care of
	 */
	repo = NULL;
}

void test_repo_setters__setting_a_new_odb_on_a_repo_which_already_loaded_one_properly_honors_the_refcount(void)
{
	git_odb *new_odb;

	cl_git_pass(git_odb_open(&new_odb, "./testrepo.git/objects"));
	cl_assert(((git_refcount *)new_odb)->refcount.val == 1);

	git_repository_set_odb(repo, new_odb);
	cl_assert(((git_refcount *)new_odb)->refcount.val == 2);

	git_repository_free(repo);
	cl_assert(((git_refcount *)new_odb)->refcount.val == 1);

	git_odb_free(new_odb);

	/* 
	 * Ensure the cleanup method won't try to free the repo as it's already been taken care of
	 */
	repo = NULL;
}

