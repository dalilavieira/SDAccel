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
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_4__ {int /*<<< orphan*/  value; } ;
typedef  TYPE_1__ git_config_entry ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/ * g_config ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_config_entry_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_get_entry (TYPE_1__**,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_rename_section (int /*<<< orphan*/ *,char*,char const*) ; 
 int /*<<< orphan*/  git_config_set_string (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

void test_config_rename__initialize(void)
{
    g_repo = cl_git_sandbox_init("testrepo.git");
	cl_git_pass(git_repository_config(&g_config, g_repo));
}

void test_config_rename__cleanup(void)
{
	git_config_free(g_config);
	g_config = NULL;

	cl_git_sandbox_cleanup();
	g_repo = NULL;
}

void test_config_rename__can_rename(void)
{
	git_config_entry *ce;

	cl_git_pass(git_config_get_entry(
		&ce, g_config, "branch.track-local.remote"));
	cl_assert_equal_s(".", ce->value);
	git_config_entry_free(ce);

	cl_git_fail(git_config_get_entry(
		&ce, g_config, "branch.local-track.remote"));

	cl_git_pass(git_config_rename_section(
		g_repo, "branch.track-local", "branch.local-track"));

	cl_git_pass(git_config_get_entry(
		&ce, g_config, "branch.local-track.remote"));
	cl_assert_equal_s(".", ce->value);
	git_config_entry_free(ce);

	cl_git_fail(git_config_get_entry(
		&ce, g_config, "branch.track-local.remote"));
}

void test_config_rename__prevent_overwrite(void)
{
	git_config_entry *ce;

	cl_git_pass(git_config_set_string(
		g_config, "branch.local-track.remote", "yellow"));

	cl_git_pass(git_config_get_entry(
		&ce, g_config, "branch.local-track.remote"));
	cl_assert_equal_s("yellow", ce->value);
	git_config_entry_free(ce);

	cl_git_pass(git_config_rename_section(
		g_repo, "branch.track-local", "branch.local-track"));

	cl_git_pass(git_config_get_entry(
		&ce, g_config, "branch.local-track.remote"));
	cl_assert_equal_s(".", ce->value);
	git_config_entry_free(ce);

	/* so, we don't currently prevent overwrite... */
	/* {
		const git_error *err;
		cl_assert((err = git_error_last()) != NULL);
		cl_assert(err->message != NULL);
	} */
}

__attribute__((used)) static void assert_invalid_config_section_name(
	git_repository *repo, const char *name)
{
	cl_git_fail_with(
		git_config_rename_section(repo, "branch.remoteless", name),
		GIT_EINVALIDSPEC);
}

void test_config_rename__require_a_valid_new_name(void)
{
	assert_invalid_config_section_name(g_repo, "");
	assert_invalid_config_section_name(g_repo, "bra\nch");
	assert_invalid_config_section_name(g_repo, "branc#");
	assert_invalid_config_section_name(g_repo, "bra\nch.duh");
	assert_invalid_config_section_name(g_repo, "branc#.duh");
}

