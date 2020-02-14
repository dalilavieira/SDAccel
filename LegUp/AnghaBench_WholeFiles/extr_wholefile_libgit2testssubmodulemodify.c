#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_submodule_update_t ;
typedef  int /*<<< orphan*/  git_submodule_recurse_t ;
typedef  int /*<<< orphan*/  git_submodule_ignore_t ;
typedef  int /*<<< orphan*/  git_submodule ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ git_config_entry ;
typedef  int /*<<< orphan*/  git_config ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_SUBMODULE_IGNORE_ALL ; 
 int /*<<< orphan*/  GIT_SUBMODULE_IGNORE_NONE ; 
 int /*<<< orphan*/  GIT_SUBMODULE_IGNORE_UNTRACKED ; 
 int /*<<< orphan*/  GIT_SUBMODULE_RECURSE_NO ; 
 int /*<<< orphan*/  GIT_SUBMODULE_RECURSE_ONDEMAND ; 
 int /*<<< orphan*/  GIT_SUBMODULE_RECURSE_YES ; 
 int /*<<< orphan*/  GIT_SUBMODULE_UPDATE_CHECKOUT ; 
 int /*<<< orphan*/  GIT_SUBMODULE_UPDATE_NONE ; 
 int /*<<< orphan*/  GIT_SUBMODULE_UPDATE_REBASE ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int /*<<< orphan*/ * SM_LIBGIT2_BRANCH ; 
 int /*<<< orphan*/ * SM_LIBGIT2_URL ; 
 int /*<<< orphan*/  assert_config_entry_value (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * g_repo ; 
 scalar_t__ git__suffixcmp (char const*,char*) ; 
 int git_config_delete_entry (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_foreach_match (int /*<<< orphan*/ *,char*,int (*) (TYPE_1__ const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_get_string (char const**,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_config_snapshot (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_submodule_branch (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_fetch_recurse_submodules (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_foreach (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,char const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_ignore (int /*<<< orphan*/ *) ; 
 int git_submodule_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_submodule_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_submodule_open (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_set_branch (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_set_fetch_recurse_submodules (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_submodule_set_ignore (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_submodule_set_update (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_submodule_set_url (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int git_submodule_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_update_strategy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_submodule_url (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * setup_fixture_submod2 () ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char const*) ; 

void test_submodule_modify__initialize(void)
{
	g_repo = setup_fixture_submod2();
}

__attribute__((used)) static int delete_one_config(const git_config_entry *entry, void *payload)
{
	git_config *cfg = payload;
	return git_config_delete_entry(cfg, entry->name);
}

__attribute__((used)) static int init_one_submodule(
	git_submodule *sm, const char *name, void *payload)
{
	GIT_UNUSED(name);
	GIT_UNUSED(payload);
	return git_submodule_init(sm, false);
}

void test_submodule_modify__init(void)
{
	git_config *cfg;
	const char *str;

	/* erase submodule data from .git/config */
	cl_git_pass(git_repository_config(&cfg, g_repo));
	cl_git_pass(
		git_config_foreach_match(cfg, "submodule\\..*", delete_one_config, cfg));
	git_config_free(cfg);

	/* confirm no submodule data in config */
	cl_git_pass(git_repository_config_snapshot(&cfg, g_repo));
	cl_git_fail_with(GIT_ENOTFOUND, git_config_get_string(&str, cfg, "submodule.sm_unchanged.url"));
	cl_git_fail_with(GIT_ENOTFOUND, git_config_get_string(&str, cfg, "submodule.sm_changed_head.url"));
	cl_git_fail_with(GIT_ENOTFOUND, git_config_get_string(&str, cfg, "submodule.sm_added_and_uncommited.url"));
	git_config_free(cfg);

	/* call init and see that settings are copied */
	cl_git_pass(git_submodule_foreach(g_repo, init_one_submodule, NULL));

	/* confirm submodule data in config */
	cl_git_pass(git_repository_config_snapshot(&cfg, g_repo));
	cl_git_pass(git_config_get_string(&str, cfg, "submodule.sm_unchanged.url"));
	cl_assert(git__suffixcmp(str, "/submod2_target") == 0);
	cl_git_pass(git_config_get_string(&str, cfg, "submodule.sm_changed_head.url"));
	cl_assert(git__suffixcmp(str, "/submod2_target") == 0);
	cl_git_pass(git_config_get_string(&str, cfg, "submodule.sm_added_and_uncommited.url"));
	cl_assert(git__suffixcmp(str, "/submod2_target") == 0);
	git_config_free(cfg);
}

__attribute__((used)) static int sync_one_submodule(
	git_submodule *sm, const char *name, void *payload)
{
	GIT_UNUSED(name);
	GIT_UNUSED(payload);
	return git_submodule_sync(sm);
}

__attribute__((used)) static void assert_submodule_url_is_synced(
	git_submodule *sm, const char *parent_key, const char *child_key)
{
	git_repository *smrepo;

	assert_config_entry_value(g_repo, parent_key, git_submodule_url(sm));

	cl_git_pass(git_submodule_open(&smrepo, sm));
	assert_config_entry_value(smrepo, child_key,  git_submodule_url(sm));
	git_repository_free(smrepo);
}

void test_submodule_modify__sync(void)
{
	git_submodule *sm1, *sm2, *sm3;
	git_config *cfg;
	const char *str;

#define SM1 "sm_unchanged"
#define SM2 "sm_changed_head"
#define SM3 "sm_added_and_uncommited"

	/* look up some submodules */
	cl_git_pass(git_submodule_lookup(&sm1, g_repo, SM1));
	cl_git_pass(git_submodule_lookup(&sm2, g_repo, SM2));
	cl_git_pass(git_submodule_lookup(&sm3, g_repo, SM3));

	/* At this point, the .git/config URLs for the submodules have
	 * not be rewritten with the absolute paths (although the
	 * .gitmodules have.  Let's confirm that they DO NOT match
	 * yet, then we can do a sync to make them match...
	 */

	/* check submodule info does not match before sync */
	cl_git_pass(git_repository_config_snapshot(&cfg, g_repo));
	cl_git_pass(git_config_get_string(&str, cfg, "submodule."SM1".url"));
	cl_assert(strcmp(git_submodule_url(sm1), str) != 0);
	cl_git_pass(git_config_get_string(&str, cfg, "submodule."SM2".url"));
	cl_assert(strcmp(git_submodule_url(sm2), str) != 0);
	cl_git_pass(git_config_get_string(&str, cfg, "submodule."SM3".url"));
	cl_assert(strcmp(git_submodule_url(sm3), str) != 0);
	git_config_free(cfg);

	/* sync all the submodules */
	cl_git_pass(git_submodule_foreach(g_repo, sync_one_submodule, NULL));

	/* check that submodule config is updated */
	assert_submodule_url_is_synced(
		sm1, "submodule."SM1".url", "remote.origin.url");
	assert_submodule_url_is_synced(
		sm2, "submodule."SM2".url", "remote.origin.url");
	assert_submodule_url_is_synced(
		sm3, "submodule."SM3".url", "remote.origin.url");

	git_submodule_free(sm1);
	git_submodule_free(sm2);
	git_submodule_free(sm3);
}

void assert_ignore_change(git_submodule_ignore_t ignore)
{
	git_submodule *sm;

	cl_git_pass(git_submodule_set_ignore(g_repo, "sm_changed_head", ignore));

	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert_equal_i(ignore, git_submodule_ignore(sm));
	git_submodule_free(sm);
}

void test_submodule_modify__set_ignore(void)
{
	assert_ignore_change(GIT_SUBMODULE_IGNORE_UNTRACKED);
	assert_ignore_change(GIT_SUBMODULE_IGNORE_NONE);
	assert_ignore_change(GIT_SUBMODULE_IGNORE_ALL);
}

void assert_update_change(git_submodule_update_t update)
{
	git_submodule *sm;

	cl_git_pass(git_submodule_set_update(g_repo, "sm_changed_head", update));

	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert_equal_i(update, git_submodule_update_strategy(sm));
	git_submodule_free(sm);
}

void test_submodule_modify__set_update(void)
{
	assert_update_change(GIT_SUBMODULE_UPDATE_REBASE);
	assert_update_change(GIT_SUBMODULE_UPDATE_NONE);
	assert_update_change(GIT_SUBMODULE_UPDATE_CHECKOUT);
}

void assert_recurse_change(git_submodule_recurse_t recurse)
{
	git_submodule *sm;

	cl_git_pass(git_submodule_set_fetch_recurse_submodules(g_repo, "sm_changed_head", recurse));

	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert_equal_i(recurse, git_submodule_fetch_recurse_submodules(sm));
	git_submodule_free(sm);
}

void test_submodule_modify__set_fetch_recurse_submodules(void)
{
	assert_recurse_change(GIT_SUBMODULE_RECURSE_YES);
	assert_recurse_change(GIT_SUBMODULE_RECURSE_NO);
	assert_recurse_change(GIT_SUBMODULE_RECURSE_ONDEMAND);
}

void test_submodule_modify__set_branch(void)
{
	git_submodule *sm;

	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert(git_submodule_branch(sm) == NULL);
	git_submodule_free(sm);

	cl_git_pass(git_submodule_set_branch(g_repo, "sm_changed_head", SM_LIBGIT2_BRANCH));
	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert_equal_s(SM_LIBGIT2_BRANCH, git_submodule_branch(sm));
	git_submodule_free(sm);

	cl_git_pass(git_submodule_set_branch(g_repo, "sm_changed_head", NULL));
	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert(git_submodule_branch(sm) == NULL);
	git_submodule_free(sm);
}

void test_submodule_modify__set_url(void)
{
	git_submodule *sm;

	cl_git_pass(git_submodule_set_url(g_repo, "sm_changed_head", SM_LIBGIT2_URL));
	cl_git_pass(git_submodule_lookup(&sm, g_repo, "sm_changed_head"));
	cl_assert_equal_s(SM_LIBGIT2_URL, git_submodule_url(sm));
	git_submodule_free(sm);
}

