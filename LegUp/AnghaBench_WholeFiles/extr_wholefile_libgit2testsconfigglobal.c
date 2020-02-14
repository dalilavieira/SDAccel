#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  int32_t ;
typedef  int /*<<< orphan*/  git_transaction ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_15__ {TYPE_2__* value; } ;
typedef  TYPE_1__ git_config_entry ;
typedef  int /*<<< orphan*/  git_config ;
struct TYPE_16__ {struct TYPE_16__* ptr; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ git_buf ;

/* Variables and functions */
 TYPE_2__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_GLOBAL ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_PROGRAMDATA ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_SYSTEM ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_XDG ; 
 int /*<<< orphan*/  GIT_OPT_GET_SEARCH_PATH ; 
 int /*<<< orphan*/  GIT_OPT_SET_SEARCH_PATH ; 
 int /*<<< orphan*/  GIT_RMDIR_REMOVE_FILES ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,TYPE_2__*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 scalar_t__ cl_is_env_set (char*) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_sandbox_set_search_path_defaults () ; 
 int /*<<< orphan*/  cl_skip () ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_2__*) ; 
 int /*<<< orphan*/  git_buf_puts (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  git_config_entry_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_get_entry (TYPE_1__**,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_get_int32 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_get_string_buf (TYPE_2__*,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_config_lock (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_open_default (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  git_config_open_global (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_open_level (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_open_ondisk (int /*<<< orphan*/ **,TYPE_2__*) ; 
 int /*<<< orphan*/  git_config_set_string (int /*<<< orphan*/ *,char const*,char const*) ; 
 int /*<<< orphan*/  git_futils_mkdir_r (char*,int) ; 
 int /*<<< orphan*/  git_futils_rmdir_r (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_libgit2_opts (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  git_path_isdir (TYPE_2__*) ; 
 int /*<<< orphan*/  git_path_prettify (TYPE_2__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_init (int /*<<< orphan*/ **,char*,int) ; 
 int /*<<< orphan*/  git_transaction_commit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_transaction_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  p_mkdir (TYPE_2__*,int) ; 
 int /*<<< orphan*/  p_unlink (char*) ; 
 int /*<<< orphan*/  symlink (char*,char*) ; 

void test_config_global__initialize(void)
{
	git_buf path = GIT_BUF_INIT;

	cl_git_pass(git_futils_mkdir_r("home", 0777));
	cl_git_pass(git_path_prettify(&path, "home", NULL));
	cl_git_pass(git_libgit2_opts(
		GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_GLOBAL, path.ptr));

	cl_git_pass(git_futils_mkdir_r("xdg/git", 0777));
	cl_git_pass(git_path_prettify(&path, "xdg/git", NULL));
	cl_git_pass(git_libgit2_opts(
		GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_XDG, path.ptr));

	cl_git_pass(git_futils_mkdir_r("etc", 0777));
	cl_git_pass(git_path_prettify(&path, "etc", NULL));
	cl_git_pass(git_libgit2_opts(
		GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_SYSTEM, path.ptr));

	git_buf_dispose(&path);
}

void test_config_global__cleanup(void)
{
	cl_sandbox_set_search_path_defaults();
	cl_git_pass(git_futils_rmdir_r("home", NULL, GIT_RMDIR_REMOVE_FILES));
	cl_git_pass(git_futils_rmdir_r("xdg", NULL, GIT_RMDIR_REMOVE_FILES));
	cl_git_pass(git_futils_rmdir_r("etc", NULL, GIT_RMDIR_REMOVE_FILES));
}

void test_config_global__open_global(void)
{
	git_config *cfg, *global, *selected, *dummy;
	int32_t value;

	cl_git_mkfile("home/.gitconfig", "[global]\n  test = 4567\n");

	cl_git_pass(git_config_open_default(&cfg));
	cl_git_pass(git_config_get_int32(&value, cfg, "global.test"));
	cl_assert_equal_i(4567, value);

	cl_git_pass(git_config_open_level(&global, cfg, GIT_CONFIG_LEVEL_GLOBAL));
	cl_git_pass(git_config_get_int32(&value, global, "global.test"));
	cl_assert_equal_i(4567, value);

	cl_git_fail(git_config_open_level(&dummy, cfg, GIT_CONFIG_LEVEL_XDG));

	cl_git_pass(git_config_open_global(&selected, cfg));
	cl_git_pass(git_config_get_int32(&value, selected, "global.test"));
	cl_assert_equal_i(4567, value);

	git_config_free(selected);
	git_config_free(global);
	git_config_free(cfg);
}

void test_config_global__open_symlinked_global(void)
{
#ifndef GIT_WIN32
	git_config *cfg;
	int32_t value;

	cl_git_mkfile("home/.gitconfig.linked", "[global]\n  test = 4567\n");
	cl_must_pass(symlink(".gitconfig.linked", "home/.gitconfig"));

	cl_git_pass(git_config_open_default(&cfg));
	cl_git_pass(git_config_get_int32(&value, cfg, "global.test"));
	cl_assert_equal_i(4567, value);

	git_config_free(cfg);
#endif
}

void test_config_global__lock_missing_global_config(void)
{
	git_config *cfg;
	git_config_entry *entry;
	git_transaction *transaction;

	p_unlink("home/.gitconfig"); /* No global config */

	cl_git_pass(git_config_open_default(&cfg));
	cl_git_pass(git_config_lock(&transaction, cfg));
	cl_git_pass(git_config_set_string(cfg, "assertion.fail", "boom"));
	cl_git_pass(git_transaction_commit(transaction));
	git_transaction_free(transaction);

	/* cfg is updated */
	cl_git_pass(git_config_get_entry(&entry, cfg, "assertion.fail"));
	cl_assert_equal_s("boom", entry->value);

	git_config_entry_free(entry);
	git_config_free(cfg);

	/* We can reread the new value from the global config */
	cl_git_pass(git_config_open_default(&cfg));
	cl_git_pass(git_config_get_entry(&entry, cfg, "assertion.fail"));
	cl_assert_equal_s("boom", entry->value);

	git_config_entry_free(entry);
	git_config_free(cfg);
}

void test_config_global__open_xdg(void)
{
	git_config *cfg, *xdg, *selected;
	const char *str = "teststring";
	const char *key = "this.variable";
	git_buf buf = {0};

	cl_git_mkfile("xdg/git/config", "# XDG config\n[core]\n  test = 1\n");

	cl_git_pass(git_config_open_default(&cfg));
	cl_git_pass(git_config_open_level(&xdg, cfg, GIT_CONFIG_LEVEL_XDG));
	cl_git_pass(git_config_open_global(&selected, cfg));

	cl_git_pass(git_config_set_string(xdg, key, str));
	cl_git_pass(git_config_get_string_buf(&buf, selected, key));
	cl_assert_equal_s(str, buf.ptr);

	git_buf_dispose(&buf);
	git_config_free(selected);
	git_config_free(xdg);
	git_config_free(cfg);
}

void test_config_global__open_programdata(void)
{
	git_config *cfg;
	git_repository *repo;
	git_buf config_path = GIT_BUF_INIT;
	git_buf var_contents = GIT_BUF_INIT;

	if (cl_is_env_set("GITTEST_INVASIVE_FS_STRUCTURE"))
		cl_skip();

	cl_git_pass(git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH,
		GIT_CONFIG_LEVEL_PROGRAMDATA, &config_path));

	if (!git_path_isdir(config_path.ptr))
		cl_git_pass(p_mkdir(config_path.ptr, 0777));

	cl_git_pass(git_buf_puts(&config_path, "/config"));

	cl_git_pass(git_config_open_ondisk(&cfg, config_path.ptr));
	cl_git_pass(git_config_set_string(cfg, "programdata.var", "even higher level"));

	git_buf_dispose(&config_path);
	git_config_free(cfg);

	git_config_open_default(&cfg);
	cl_git_pass(git_config_get_string_buf(&var_contents, cfg, "programdata.var"));
	cl_assert_equal_s("even higher level", var_contents.ptr);

	git_config_free(cfg);
	git_buf_dispose(&var_contents);

	cl_git_pass(git_repository_init(&repo, "./foo.git", true));
	cl_git_pass(git_repository_config(&cfg, repo));
	cl_git_pass(git_config_get_string_buf(&var_contents, cfg, "programdata.var"));
	cl_assert_equal_s("even higher level", var_contents.ptr);

	git_config_free(cfg);
	git_buf_dispose(&var_contents);
	git_repository_free(repo);
	cl_fixture_cleanup("./foo.git");
}

