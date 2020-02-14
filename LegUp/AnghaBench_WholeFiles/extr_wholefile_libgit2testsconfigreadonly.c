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
struct TYPE_4__ {int readonly; } ;
typedef  TYPE_1__ git_config_backend ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_GLOBAL ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_LOCAL ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/ * cfg ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_add_backend (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_backend_from_file (TYPE_1__**,char*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_new (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  git_config_set_string (int /*<<< orphan*/ *,char*,char*) ; 
 int git_path_exists (char*) ; 
 int /*<<< orphan*/  p_unlink (char*) ; 

void test_config_readonly__initialize(void)
{
	cl_git_pass(git_config_new(&cfg));
}

void test_config_readonly__cleanup(void)
{
	git_config_free(cfg);
	cfg = NULL;
}

void test_config_readonly__writing_to_readonly_fails(void)
{
	git_config_backend *backend;

	cl_git_pass(git_config_backend_from_file(&backend, "global"));
	backend->readonly = 1;
	cl_git_pass(git_config_add_backend(cfg, backend, GIT_CONFIG_LEVEL_GLOBAL, NULL, 0));

	cl_git_fail_with(GIT_ENOTFOUND, git_config_set_string(cfg, "foo.bar", "baz"));
	cl_assert(!git_path_exists("global"));
}

void test_config_readonly__writing_to_cfg_with_rw_precedence_succeeds(void)
{
	git_config_backend *backend;

	cl_git_pass(git_config_backend_from_file(&backend, "global"));
	backend->readonly = 1;
	cl_git_pass(git_config_add_backend(cfg, backend, GIT_CONFIG_LEVEL_GLOBAL, NULL, 0));

	cl_git_pass(git_config_backend_from_file(&backend, "local"));
	cl_git_pass(git_config_add_backend(cfg, backend, GIT_CONFIG_LEVEL_LOCAL, NULL, 0));

	cl_git_pass(git_config_set_string(cfg, "foo.bar", "baz"));

	cl_assert(git_path_exists("local"));
	cl_assert(!git_path_exists("global"));
	cl_git_pass(p_unlink("local"));
}

void test_config_readonly__writing_to_cfg_with_ro_precedence_succeeds(void)
{
	git_config_backend *backend;

	cl_git_pass(git_config_backend_from_file(&backend, "local"));
	backend->readonly = 1;
	cl_git_pass(git_config_add_backend(cfg, backend, GIT_CONFIG_LEVEL_LOCAL, NULL, 0));

	cl_git_pass(git_config_backend_from_file(&backend, "global"));
	cl_git_pass(git_config_add_backend(cfg, backend, GIT_CONFIG_LEVEL_GLOBAL, NULL, 0));

	cl_git_pass(git_config_set_string(cfg, "foo.bar", "baz"));

	cl_assert(!git_path_exists("local"));
	cl_assert(git_path_exists("global"));
	cl_git_pass(p_unlink("global"));
}

