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
typedef  int int32_t ;
typedef  int /*<<< orphan*/  git_config_entry ;
typedef  int /*<<< orphan*/  git_config ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_git_mkfile (char const*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_get_int32 (int*,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_get_multivar_foreach (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/  const*,void*),int*) ; 
 int /*<<< orphan*/  git_config_open_ondisk (int /*<<< orphan*/ **,char const*) ; 
 int /*<<< orphan*/  git_config_snapshot (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

void test_config_snapshot__create_snapshot(void)
{
	int32_t tmp;
	git_config *cfg, *snapshot, *new_snapshot;
	const char *filename = "config-ext-change";

	cl_git_mkfile(filename, "[old]\nvalue = 5\n");

	cl_git_pass(git_config_open_ondisk(&cfg, filename));

	cl_git_pass(git_config_get_int32(&tmp, cfg, "old.value"));
	cl_assert_equal_i(5, tmp);

	cl_git_pass(git_config_snapshot(&snapshot, cfg));

	/* Change the value on the file itself (simulate external process) */
	cl_git_mkfile(filename, "[old]\nvalue = 56\n");

	cl_git_pass(git_config_get_int32(&tmp, cfg, "old.value"));
	cl_assert_equal_i(56, tmp);

	cl_git_pass(git_config_get_int32(&tmp, snapshot, "old.value"));
	cl_assert_equal_i(5, tmp);

	/* Change the value on the file itself (simulate external process) */
	cl_git_mkfile(filename, "[old]\nvalue = 999\n");

	cl_git_pass(git_config_snapshot(&new_snapshot, cfg));

	/* New snapshot should see new value */
	cl_git_pass(git_config_get_int32(&tmp, new_snapshot, "old.value"));
	cl_assert_equal_i(999, tmp);

	/* Old snapshot should still have the old value */
	cl_git_pass(git_config_get_int32(&tmp, snapshot, "old.value"));
	cl_assert_equal_i(5, tmp);
	
	git_config_free(new_snapshot);
	git_config_free(snapshot);
	git_config_free(cfg);
}

__attribute__((used)) static int count_me(const git_config_entry *entry, void *payload)
{
	int *n = (int *) payload;

	GIT_UNUSED(entry);

	(*n)++;

	return 0;
}

void test_config_snapshot__multivar(void)
{
	int count = 0;
	git_config *cfg, *snapshot;
	const char *filename = "config-file";

	cl_git_mkfile(filename, "[old]\nvalue = 5\nvalue = 6\n");

	cl_git_pass(git_config_open_ondisk(&cfg, filename));
	cl_git_pass(git_config_get_multivar_foreach(cfg, "old.value", NULL, count_me, &count));

	cl_assert_equal_i(2, count);

	cl_git_pass(git_config_snapshot(&snapshot, cfg));
	git_config_free(cfg);

	count = 0;
	cl_git_pass(git_config_get_multivar_foreach(snapshot, "old.value", NULL, count_me, &count));

	cl_assert_equal_i(2, count);

	git_config_free(snapshot);
}

