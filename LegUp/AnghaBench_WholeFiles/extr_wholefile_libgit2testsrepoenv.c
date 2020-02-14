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

/* Variables and functions */
 int /*<<< orphan*/  GIT_RMDIR_REMOVE_FILES ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_setenv (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_futils_rmdir_r (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ git_path_isdir (char*) ; 

__attribute__((used)) static void clear_git_env(void)
{
	cl_setenv("GIT_DIR", NULL);
	cl_setenv("GIT_CEILING_DIRECTORIES", NULL);
	cl_setenv("GIT_INDEX_FILE", NULL);
	cl_setenv("GIT_NAMESPACE", NULL);
	cl_setenv("GIT_OBJECT_DIRECTORY", NULL);
	cl_setenv("GIT_ALTERNATE_OBJECT_DIRECTORIES", NULL);
	cl_setenv("GIT_WORK_TREE", NULL);
	cl_setenv("GIT_COMMON_DIR", NULL);
}

void test_repo_env__initialize(void)
{
	clear_git_env();
}

void test_repo_env__cleanup(void)
{
	cl_git_sandbox_cleanup();

	if (git_path_isdir("attr"))
		git_futils_rmdir_r("attr", NULL, GIT_RMDIR_REMOVE_FILES);
	if (git_path_isdir("testrepo.git"))
		git_futils_rmdir_r("testrepo.git", NULL, GIT_RMDIR_REMOVE_FILES);
	if (git_path_isdir("peeled.git"))
		git_futils_rmdir_r("peeled.git", NULL, GIT_RMDIR_REMOVE_FILES);

	clear_git_env();
}

