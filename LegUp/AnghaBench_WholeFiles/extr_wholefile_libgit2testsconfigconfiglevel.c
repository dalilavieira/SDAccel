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
typedef  int /*<<< orphan*/  git_config ;
struct TYPE_4__ {int /*<<< orphan*/  ptr; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_GLOBAL ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_LOCAL ; 
 int /*<<< orphan*/  GIT_EEXISTS ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int git_config_add_file_ondisk (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int git_config_get_string_buf (TYPE_1__*,int /*<<< orphan*/ *,char*) ; 
 int git_config_new (int /*<<< orphan*/ **) ; 
 int git_config_open_level (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void test_config_configlevel__adding_the_same_level_twice_returns_EEXISTS(void)
{
	int error;
	git_config *cfg;

	cl_git_pass(git_config_new(&cfg));
	cl_git_pass(git_config_add_file_ondisk(cfg, cl_fixture("config/config9"),
		GIT_CONFIG_LEVEL_LOCAL, NULL, 0));
	cl_git_pass(git_config_add_file_ondisk(cfg, cl_fixture("config/config15"),
		GIT_CONFIG_LEVEL_GLOBAL, NULL, 0));
	error = git_config_add_file_ondisk(cfg, cl_fixture("config/config16"),
		GIT_CONFIG_LEVEL_GLOBAL, NULL, 0);

	cl_git_fail(error);
	cl_assert_equal_i(GIT_EEXISTS, error);

	git_config_free(cfg);
}

void test_config_configlevel__can_replace_a_config_file_at_an_existing_level(void)
{
	git_config *cfg;
	git_buf buf = {0};

	cl_git_pass(git_config_new(&cfg));
	cl_git_pass(git_config_add_file_ondisk(cfg, cl_fixture("config/config18"),
		GIT_CONFIG_LEVEL_LOCAL, NULL, 1));
	cl_git_pass(git_config_add_file_ondisk(cfg, cl_fixture("config/config19"),
		GIT_CONFIG_LEVEL_LOCAL, NULL, 1));

	cl_git_pass(git_config_get_string_buf(&buf, cfg, "core.stringglobal"));
	cl_assert_equal_s("don't find me!", buf.ptr);

	git_buf_dispose(&buf);
	git_config_free(cfg);
}

void test_config_configlevel__can_read_from_a_single_level_focused_file_after_parent_config_has_been_freed(void)
{
	git_config *cfg;
	git_config *single_level_cfg;
	git_buf buf = {0};

	cl_git_pass(git_config_new(&cfg));
	cl_git_pass(git_config_add_file_ondisk(cfg, cl_fixture("config/config18"),
		GIT_CONFIG_LEVEL_GLOBAL, NULL, 0));
	cl_git_pass(git_config_add_file_ondisk(cfg, cl_fixture("config/config19"),
		GIT_CONFIG_LEVEL_LOCAL, NULL, 0));

	cl_git_pass(git_config_open_level(&single_level_cfg, cfg, GIT_CONFIG_LEVEL_LOCAL));

	git_config_free(cfg);

	cl_git_pass(git_config_get_string_buf(&buf, single_level_cfg, "core.stringglobal"));
	cl_assert_equal_s("don't find me!", buf.ptr);

	git_buf_dispose(&buf);
	git_config_free(single_level_cfg);
}

void test_config_configlevel__fetching_a_level_from_an_empty_compound_config_returns_ENOTFOUND(void)
{
	git_config *cfg;
	git_config *local_cfg;

	cl_git_pass(git_config_new(&cfg));

	cl_assert_equal_i(GIT_ENOTFOUND, git_config_open_level(&local_cfg, cfg, GIT_CONFIG_LEVEL_LOCAL));

	git_config_free(cfg);
}

