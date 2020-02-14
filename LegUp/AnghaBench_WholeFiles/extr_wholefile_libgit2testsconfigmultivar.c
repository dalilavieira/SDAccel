#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_config_iterator ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ git_config_entry ;
typedef  int /*<<< orphan*/  git_config ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_APP ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_GLOBAL ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_LOCAL ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_SYSTEM ; 
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_UNUSED (TYPE_1__ const*) ; 
 char* _name ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 char* cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_fail_with (int,int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int git_config_add_file_ondisk (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int git_config_delete_multivar (int /*<<< orphan*/ *,char*,char*) ; 
 int git_config_foreach (int /*<<< orphan*/ *,int (*) (TYPE_1__ const*,void*),int*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int git_config_get_multivar_foreach (int /*<<< orphan*/ *,char const*,char*,int (*) (TYPE_1__ const*,void*),int*) ; 
 int /*<<< orphan*/  git_config_iterator_free (int /*<<< orphan*/ *) ; 
 int git_config_multivar_iterator_new (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ git_config_next (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int git_config_open_ondisk (int /*<<< orphan*/ **,char*) ; 
 int git_config_set_multivar (int /*<<< orphan*/ *,char const*,char*,char*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 

void test_config_multivar__initialize(void)
{
	cl_fixture_sandbox("config");
}

void test_config_multivar__cleanup(void)
{
	cl_fixture_cleanup("config");
}

__attribute__((used)) static int mv_read_cb(const git_config_entry *entry, void *data)
{
	int *n = (int *) data;

	if (!strcmp(entry->name, _name))
		(*n)++;

	return 0;
}

void test_config_multivar__foreach(void)
{
	git_config *cfg;
	int n = 0;

	cl_git_pass(git_config_open_ondisk(&cfg, cl_fixture("config/config11")));

	cl_git_pass(git_config_foreach(cfg, mv_read_cb, &n));
	cl_assert(n == 2);

	git_config_free(cfg);
}

__attribute__((used)) static int cb(const git_config_entry *entry, void *data)
{
	int *n = (int *) data;

	GIT_UNUSED(entry);

	(*n)++;

	return 0;
}

__attribute__((used)) static void check_get_multivar_foreach(
	git_config *cfg, int expected, int expected_patterned)
{
	int n = 0;

	if (expected > 0) {
		cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
		cl_assert_equal_i(expected, n);
	} else {
		cl_assert_equal_i(GIT_ENOTFOUND,
			git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	}

	n = 0;

	if (expected_patterned > 0) {
		cl_git_pass(git_config_get_multivar_foreach(cfg, _name, "example", cb, &n));
		cl_assert_equal_i(expected_patterned, n);
	} else {
		cl_assert_equal_i(GIT_ENOTFOUND,
			git_config_get_multivar_foreach(cfg, _name, "example", cb, &n));
	}
}

__attribute__((used)) static void check_get_multivar(git_config *cfg, int expected)
{
	git_config_iterator *iter;
	git_config_entry *entry;
	int n = 0;

	cl_git_pass(git_config_multivar_iterator_new(&iter, cfg, _name, NULL));

	while (git_config_next(&entry, iter) == 0)
		n++;

	cl_assert_equal_i(expected, n);
	git_config_iterator_free(iter);

}

void test_config_multivar__get(void)
{
	git_config *cfg;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));
	check_get_multivar_foreach(cfg, 2, 1);

	/* add another that has the _name entry */
	cl_git_pass(git_config_add_file_ondisk(cfg, "config/config9", GIT_CONFIG_LEVEL_SYSTEM, NULL, 1));
	check_get_multivar_foreach(cfg, 3, 2);

	/* add another that does not have the _name entry */
	cl_git_pass(git_config_add_file_ondisk(cfg, "config/config0", GIT_CONFIG_LEVEL_GLOBAL, NULL, 1));
	check_get_multivar_foreach(cfg, 3, 2);

	/* add another that does not have the _name entry at the end */
	cl_git_pass(git_config_add_file_ondisk(cfg, "config/config1", GIT_CONFIG_LEVEL_APP, NULL, 1));
	check_get_multivar_foreach(cfg, 3, 2);

	/* drop original file */
	cl_git_pass(git_config_add_file_ondisk(cfg, "config/config2", GIT_CONFIG_LEVEL_LOCAL, NULL, 1));
	check_get_multivar_foreach(cfg, 1, 1);

	/* drop other file with match */
	cl_git_pass(git_config_add_file_ondisk(cfg, "config/config3", GIT_CONFIG_LEVEL_SYSTEM, NULL, 1));
	check_get_multivar_foreach(cfg, 0, 0);

	/* reload original file (add different place in order) */
	cl_git_pass(git_config_add_file_ondisk(cfg, "config/config11", GIT_CONFIG_LEVEL_SYSTEM, NULL, 1));
	check_get_multivar_foreach(cfg, 2, 1);

	check_get_multivar(cfg, 2);

	git_config_free(cfg);
}

void test_config_multivar__add(void)
{
	git_config *cfg;
	int n;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));
	cl_git_pass(git_config_set_multivar(cfg, _name, "nonexistant", "git://git.otherplace.org/libgit2"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert_equal_i(n, 3);

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, "otherplace", cb, &n));
	cl_assert_equal_i(n, 1);

	git_config_free(cfg);

	/* We know it works in memory, let's see if the file is written correctly */

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert_equal_i(n, 3);

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, "otherplace", cb, &n));
	cl_assert_equal_i(n, 1);

	git_config_free(cfg);
}

void test_config_multivar__add_new(void)
{
	const char *var = "a.brand.new";
	git_config *cfg;
	int n;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	cl_git_pass(git_config_set_multivar(cfg, var, "$^", "variable"));
	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, var, NULL, cb, &n));
	cl_assert_equal_i(n, 1);

	git_config_free(cfg);
}

void test_config_multivar__replace(void)
{
	git_config *cfg;
	int n;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert(n == 2);

	cl_git_pass(git_config_set_multivar(cfg, _name, "github", "git://git.otherplace.org/libgit2"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert(n == 2);

	git_config_free(cfg);

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert(n == 2);

	git_config_free(cfg);
}

void test_config_multivar__replace_multiple(void)
{
	git_config *cfg;
	int n;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));
	cl_git_pass(git_config_set_multivar(cfg, _name, "git://", "git://git.otherplace.org/libgit2"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, "otherplace", cb, &n));
	cl_assert_equal_i(n, 2);

	git_config_free(cfg);

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, "otherplace", cb, &n));
	cl_assert_equal_i(n, 2);

	git_config_free(cfg);
}

void test_config_multivar__delete(void)
{
	git_config *cfg;
	int n;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert_equal_i(2, n);

	cl_git_pass(git_config_delete_multivar(cfg, _name, "github"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert_equal_i(1, n);

	git_config_free(cfg);

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert_equal_i(1, n);

	git_config_free(cfg);
}

void test_config_multivar__delete_multiple(void)
{
	git_config *cfg;
	int n;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_pass(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n));
	cl_assert(n == 2);

	cl_git_pass(git_config_delete_multivar(cfg, _name, "git"));

	n = 0;
	cl_git_fail_with(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n), GIT_ENOTFOUND);

	git_config_free(cfg);

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	n = 0;
	cl_git_fail_with(git_config_get_multivar_foreach(cfg, _name, NULL, cb, &n), GIT_ENOTFOUND);

	git_config_free(cfg);
}

void test_config_multivar__delete_notfound(void)
{
	git_config *cfg;

	cl_git_pass(git_config_open_ondisk(&cfg, "config/config11"));

	cl_git_fail_with(git_config_delete_multivar(cfg, "remote.ab.noturl", "git"), GIT_ENOTFOUND);

	git_config_free(cfg);
}

