#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct stat {int /*<<< orphan*/  st_mode; } ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_config ;
struct TYPE_6__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_CONFIG_LEVEL_GLOBAL ; 
 char* GIT_HEAD_FILE ; 
 int /*<<< orphan*/  GIT_OPT_SET_SEARCH_PATH ; 
 scalar_t__ S_ISLNK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 char const* git_buf_cstr (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_1__*,char const*,char*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_open_ondisk (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_set_string (int /*<<< orphan*/ *,char const*,char const*) ; 
 int /*<<< orphan*/  git_libgit2_opts (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_symbolic_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,char const*,int,int /*<<< orphan*/ *) ; 
 char const* git_repository_path (int /*<<< orphan*/ *) ; 
 scalar_t__ p_lstat (char const*,struct stat*) ; 
 int /*<<< orphan*/  p_mkdir (char const*,int) ; 
 scalar_t__ p_symlink (char*,char const*) ; 
 int /*<<< orphan*/  p_unlink (char const*) ; 

void make_head_unborn(git_repository* repo, const char *target)
{
	git_reference *head;

	cl_git_pass(git_reference_symbolic_create(&head, repo, GIT_HEAD_FILE, target, 1, NULL));
	git_reference_free(head);
}

void delete_head(git_repository* repo)
{
	git_buf head_path = GIT_BUF_INIT;

	cl_git_pass(git_buf_joinpath(&head_path, git_repository_path(repo), GIT_HEAD_FILE));
	cl_git_pass(p_unlink(git_buf_cstr(&head_path)));

	git_buf_dispose(&head_path);
}

int filesystem_supports_symlinks(const char *path)
{
	struct stat st;
	bool support = 0;

	if (p_symlink("target", path) == 0) {
		if (p_lstat(path, &st) == 0 && S_ISLNK(st.st_mode))
			support = 1;

		p_unlink(path);
	}

	return support;
}

void create_tmp_global_config(const char *dirname, const char *key, const char *val)
{
	git_buf path = GIT_BUF_INIT;
	git_config *config;

	cl_git_pass(git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH,
		GIT_CONFIG_LEVEL_GLOBAL, dirname));
	cl_must_pass(p_mkdir(dirname, 0777));
	cl_git_pass(git_buf_joinpath(&path, dirname, ".gitconfig"));
	cl_git_pass(git_config_open_ondisk(&config, path.ptr));
	cl_git_pass(git_config_set_string(config, key, val));
	git_config_free(config);
	git_buf_dispose(&path);
}

