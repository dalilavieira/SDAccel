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
typedef  int /*<<< orphan*/  git_config_entry ;
typedef  int /*<<< orphan*/  git_config ;
typedef  int /*<<< orphan*/  git_buf ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_entry_free (int /*<<< orphan*/ *) ; 
 int git_config_foreach_match (int /*<<< orphan*/ *,char const*,int (*) (int /*<<< orphan*/  const*,void*),int*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int git_config_get_entry (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int git_config_get_string_buf (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*) ; 
 int git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int git_repository_config__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

void assert_config_entry_existence(
	git_repository *repo,
	const char *name,
	bool is_supposed_to_exist)
{
	git_config *config;
	git_config_entry *entry = NULL;
	int result;

	cl_git_pass(git_repository_config__weakptr(&config, repo));
	
	result = git_config_get_entry(&entry, config, name);
	git_config_entry_free(entry);

	if (is_supposed_to_exist)
		cl_git_pass(result);
	else
		cl_assert_equal_i(GIT_ENOTFOUND, result);
}

void assert_config_entry_value(
	git_repository *repo,
	const char *name,
	const char *expected_value)
{
	git_config *config;
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_repository_config__weakptr(&config, repo));

	cl_git_pass(git_config_get_string_buf(&buf, config, name));

	cl_assert_equal_s(expected_value, git_buf_cstr(&buf));
	git_buf_dispose(&buf);
}

__attribute__((used)) static int count_config_entries_cb(
	const git_config_entry *entry,
	void *payload)
{
	int *how_many = (int *)payload;

	GIT_UNUSED(entry);

	(*how_many)++;

	return 0;
}

int count_config_entries_match(git_repository *repo, const char *pattern)
{
	git_config *config;
	int how_many = 0;

	cl_git_pass(git_repository_config(&config, repo));

	cl_assert_equal_i(0, git_config_foreach_match(
		config,	pattern, count_config_entries_cb, &how_many));

	git_config_free(config);

	return how_many;
}

