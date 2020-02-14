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
struct stat {int /*<<< orphan*/  st_size; int /*<<< orphan*/  st_mode; } ;
typedef  int /*<<< orphan*/  git_buf ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_UNUSED (int) ; 
 int /*<<< orphan*/  S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S_ISLNK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,char*) ; 
 int /*<<< orphan*/  cl_git_rewritefile (char*,char*) ; 
 int /*<<< orphan*/  cl_must_fail (int) ; 
 int /*<<< orphan*/  cl_must_pass (int) ; 
 int /*<<< orphan*/  clar__skip () ; 
 int /*<<< orphan*/  clar_sandbox_path () ; 
 int /*<<< orphan*/  errno ; 
 char* git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_join (int /*<<< orphan*/ *,char,int /*<<< orphan*/ ,char*) ; 
 int git_buf_len (int /*<<< orphan*/ *) ; 
 int link (char const*,char const*) ; 
 int p_lstat (char*,struct stat*) ; 
 int /*<<< orphan*/  p_mkdir (char*,int) ; 
 int p_readlink (char*,char*,int) ; 
 int p_stat (char*,struct stat*) ; 
 int strlen (char*) ; 
 int symlink (char const*,char const*) ; 

void test_core_link__cleanup(void)
{
#ifdef GIT_WIN32
	RemoveDirectory("lstat_junction");
	RemoveDirectory("lstat_dangling");
	RemoveDirectory("lstat_dangling_dir");
	RemoveDirectory("lstat_dangling_junction");

	RemoveDirectory("stat_junction");
	RemoveDirectory("stat_dangling");
	RemoveDirectory("stat_dangling_dir");
	RemoveDirectory("stat_dangling_junction");
#endif
}

__attribute__((used)) static bool should_run(void)
{
	return true;
}

__attribute__((used)) static void do_symlink(const char *old, const char *new, int is_dir)
{
#ifndef GIT_WIN32
	GIT_UNUSED(is_dir);

	cl_must_pass(symlink(old, new));
#else
	typedef DWORD (WINAPI *create_symlink_func)(LPCTSTR, LPCTSTR, DWORD);
	HMODULE module;
	create_symlink_func pCreateSymbolicLink;

	cl_assert(module = GetModuleHandle("kernel32"));
	cl_assert(pCreateSymbolicLink = (create_symlink_func)GetProcAddress(module, "CreateSymbolicLinkA"));

	cl_win32_pass(pCreateSymbolicLink(new, old, is_dir));
#endif
}

__attribute__((used)) static void do_hardlink(const char *old, const char *new)
{
#ifndef GIT_WIN32
	cl_must_pass(link(old, new));
#else
	typedef DWORD (WINAPI *create_hardlink_func)(LPCTSTR, LPCTSTR, LPSECURITY_ATTRIBUTES);
	HMODULE module;
	create_hardlink_func pCreateHardLink;

	cl_assert(module = GetModuleHandle("kernel32"));
	cl_assert(pCreateHardLink = (create_hardlink_func)GetProcAddress(module, "CreateHardLinkA"));

	cl_win32_pass(pCreateHardLink(new, old, 0));
#endif
}

void test_core_link__stat_regular_file(void)
{
	struct stat st;

	cl_git_rewritefile("stat_regfile", "This is a regular file!\n");

	cl_must_pass(p_stat("stat_regfile", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(24, st.st_size);
}

void test_core_link__lstat_regular_file(void)
{
	struct stat st;

	cl_git_rewritefile("lstat_regfile", "This is a regular file!\n");

	cl_must_pass(p_stat("lstat_regfile", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(24, st.st_size);
}

void test_core_link__stat_symlink(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	cl_git_rewritefile("stat_target", "This is the target of a symbolic link.\n");
	do_symlink("stat_target", "stat_symlink", 0);

	cl_must_pass(p_stat("stat_target", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(39, st.st_size);

	cl_must_pass(p_stat("stat_symlink", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(39, st.st_size);
}

void test_core_link__stat_symlink_directory(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	p_mkdir("stat_dirtarget", 0777);
	do_symlink("stat_dirtarget", "stat_dirlink", 1);

	cl_must_pass(p_stat("stat_dirtarget", &st));
	cl_assert(S_ISDIR(st.st_mode));

	cl_must_pass(p_stat("stat_dirlink", &st));
	cl_assert(S_ISDIR(st.st_mode));
}

void test_core_link__stat_symlink_chain(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	cl_git_rewritefile("stat_final_target", "Final target of some symbolic links...\n");
	do_symlink("stat_final_target", "stat_chain_3", 0);
	do_symlink("stat_chain_3", "stat_chain_2", 0);
	do_symlink("stat_chain_2", "stat_chain_1", 0);

	cl_must_pass(p_stat("stat_chain_1", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(39, st.st_size);
}

void test_core_link__stat_dangling_symlink(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	do_symlink("stat_nonexistent", "stat_dangling", 0);

	cl_must_fail(p_stat("stat_nonexistent", &st));
	cl_must_fail(p_stat("stat_dangling", &st));
}

void test_core_link__stat_dangling_symlink_directory(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	do_symlink("stat_nonexistent", "stat_dangling_dir", 1);

	cl_must_fail(p_stat("stat_nonexistent_dir", &st));
	cl_must_fail(p_stat("stat_dangling", &st));
}

void test_core_link__lstat_symlink(void)
{
	git_buf target_path = GIT_BUF_INIT;
	struct stat st;

	if (!should_run())
		clar__skip();

	/* Windows always writes the canonical path as the link target, so
	 * write the full path on all platforms.
	 */
	git_buf_join(&target_path, '/', clar_sandbox_path(), "lstat_target");

	cl_git_rewritefile("lstat_target", "This is the target of a symbolic link.\n");
	do_symlink(git_buf_cstr(&target_path), "lstat_symlink", 0);

	cl_must_pass(p_lstat("lstat_target", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(39, st.st_size);

	cl_must_pass(p_lstat("lstat_symlink", &st));
	cl_assert(S_ISLNK(st.st_mode));
	cl_assert_equal_i(git_buf_len(&target_path), st.st_size);

	git_buf_dispose(&target_path);
}

void test_core_link__lstat_symlink_directory(void)
{
	git_buf target_path = GIT_BUF_INIT;
	struct stat st;

	if (!should_run())
		clar__skip();

	git_buf_join(&target_path, '/', clar_sandbox_path(), "lstat_dirtarget");

	p_mkdir("lstat_dirtarget", 0777);
	do_symlink(git_buf_cstr(&target_path), "lstat_dirlink", 1);

	cl_must_pass(p_lstat("lstat_dirtarget", &st));
	cl_assert(S_ISDIR(st.st_mode));

	cl_must_pass(p_lstat("lstat_dirlink", &st));
	cl_assert(S_ISLNK(st.st_mode));
	cl_assert_equal_i(git_buf_len(&target_path), st.st_size);

	git_buf_dispose(&target_path);
}

void test_core_link__lstat_dangling_symlink(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	do_symlink("lstat_nonexistent", "lstat_dangling", 0);

	cl_must_fail(p_lstat("lstat_nonexistent", &st));

	cl_must_pass(p_lstat("lstat_dangling", &st));
	cl_assert(S_ISLNK(st.st_mode));
	cl_assert_equal_i(strlen("lstat_nonexistent"), st.st_size);
}

void test_core_link__lstat_dangling_symlink_directory(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	do_symlink("lstat_nonexistent", "lstat_dangling_dir", 1);

	cl_must_fail(p_lstat("lstat_nonexistent", &st));

	cl_must_pass(p_lstat("lstat_dangling_dir", &st));
	cl_assert(S_ISLNK(st.st_mode));
	cl_assert_equal_i(strlen("lstat_nonexistent"), st.st_size);
}

void test_core_link__stat_junction(void)
{
#ifdef GIT_WIN32
	git_buf target_path = GIT_BUF_INIT;
	struct stat st;

	git_buf_join(&target_path, '/', clar_sandbox_path(), "stat_junctarget");

	p_mkdir("stat_junctarget", 0777);
	do_junction(git_buf_cstr(&target_path), "stat_junction");

	cl_must_pass(p_stat("stat_junctarget", &st));
	cl_assert(S_ISDIR(st.st_mode));

	cl_must_pass(p_stat("stat_junction", &st));
	cl_assert(S_ISDIR(st.st_mode));

	git_buf_dispose(&target_path);
#endif
}

void test_core_link__stat_dangling_junction(void)
{
#ifdef GIT_WIN32
	git_buf target_path = GIT_BUF_INIT;
	struct stat st;

	git_buf_join(&target_path, '/', clar_sandbox_path(), "stat_nonexistent_junctarget");

	p_mkdir("stat_nonexistent_junctarget", 0777);
	do_junction(git_buf_cstr(&target_path), "stat_dangling_junction");

	RemoveDirectory("stat_nonexistent_junctarget");

	cl_must_fail(p_stat("stat_nonexistent_junctarget", &st));
	cl_must_fail(p_stat("stat_dangling_junction", &st));

	git_buf_dispose(&target_path);
#endif
}

void test_core_link__lstat_junction(void)
{
#ifdef GIT_WIN32
	git_buf target_path = GIT_BUF_INIT;
	struct stat st;

	git_buf_join(&target_path, '/', clar_sandbox_path(), "lstat_junctarget");

	p_mkdir("lstat_junctarget", 0777);
	do_junction(git_buf_cstr(&target_path), "lstat_junction");

	cl_must_pass(p_lstat("lstat_junctarget", &st));
	cl_assert(S_ISDIR(st.st_mode));

	cl_must_pass(p_lstat("lstat_junction", &st));
	cl_assert(S_ISLNK(st.st_mode));

	git_buf_dispose(&target_path);
#endif
}

void test_core_link__lstat_dangling_junction(void)
{
#ifdef GIT_WIN32
	git_buf target_path = GIT_BUF_INIT;
	struct stat st;

	git_buf_join(&target_path, '/', clar_sandbox_path(), "lstat_nonexistent_junctarget");

	p_mkdir("lstat_nonexistent_junctarget", 0777);
	do_junction(git_buf_cstr(&target_path), "lstat_dangling_junction");

	RemoveDirectory("lstat_nonexistent_junctarget");

	cl_must_fail(p_lstat("lstat_nonexistent_junctarget", &st));

	cl_must_pass(p_lstat("lstat_dangling_junction", &st));
	cl_assert(S_ISLNK(st.st_mode));
	cl_assert_equal_i(git_buf_len(&target_path), st.st_size);

	git_buf_dispose(&target_path);
#endif
}

void test_core_link__stat_hardlink(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	cl_git_rewritefile("stat_hardlink1", "This file has many names!\n");
	do_hardlink("stat_hardlink1", "stat_hardlink2");

	cl_must_pass(p_stat("stat_hardlink1", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(26, st.st_size);

	cl_must_pass(p_stat("stat_hardlink2", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(26, st.st_size);
}

void test_core_link__lstat_hardlink(void)
{
	struct stat st;

	if (!should_run())
		clar__skip();

	cl_git_rewritefile("lstat_hardlink1", "This file has many names!\n");
	do_hardlink("lstat_hardlink1", "lstat_hardlink2");

	cl_must_pass(p_lstat("lstat_hardlink1", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(26, st.st_size);

	cl_must_pass(p_lstat("lstat_hardlink2", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(26, st.st_size);
}

void test_core_link__stat_reparse_point(void)
{
#ifdef GIT_WIN32
	struct stat st;

	/* Generic reparse points should be treated as regular files, only
	 * symlinks and junctions should be treated as links.
	 */

	cl_git_rewritefile("stat_reparse", "This is a reparse point!\n");
	do_custom_reparse("stat_reparse");

	cl_must_pass(p_lstat("stat_reparse", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(25, st.st_size);
#endif
}

void test_core_link__lstat_reparse_point(void)
{
#ifdef GIT_WIN32
	struct stat st;

	cl_git_rewritefile("lstat_reparse", "This is a reparse point!\n");
	do_custom_reparse("lstat_reparse");

	cl_must_pass(p_lstat("lstat_reparse", &st));
	cl_assert(S_ISREG(st.st_mode));
	cl_assert_equal_i(25, st.st_size);
#endif
}

void test_core_link__readlink_nonexistent_file(void)
{
	char buf[2048];

	cl_must_fail(p_readlink("readlink_nonexistent", buf, 2048));
	cl_assert_equal_i(ENOENT, errno);
}

void test_core_link__readlink_normal_file(void)
{
	char buf[2048];

	cl_git_rewritefile("readlink_regfile", "This is a regular file!\n");
	cl_must_fail(p_readlink("readlink_regfile", buf, 2048));
	cl_assert_equal_i(EINVAL, errno);
}

void test_core_link__readlink_symlink(void)
{
	git_buf target_path = GIT_BUF_INIT;
	int len;
	char buf[2048];

	if (!should_run())
		clar__skip();

	git_buf_join(&target_path, '/', clar_sandbox_path(), "readlink_target");

	cl_git_rewritefile("readlink_target", "This is the target of a symlink\n");
	do_symlink(git_buf_cstr(&target_path), "readlink_link", 0);

	len = p_readlink("readlink_link", buf, 2048);
	cl_must_pass(len);

	buf[len] = 0;

	cl_assert_equal_s(git_buf_cstr(&target_path), buf);

	git_buf_dispose(&target_path);
}

void test_core_link__readlink_dangling(void)
{
	git_buf target_path = GIT_BUF_INIT;
	int len;
	char buf[2048];

	if (!should_run())
		clar__skip();

	git_buf_join(&target_path, '/', clar_sandbox_path(), "readlink_nonexistent");

	do_symlink(git_buf_cstr(&target_path), "readlink_dangling", 0);

	len = p_readlink("readlink_dangling", buf, 2048);
	cl_must_pass(len);

	buf[len] = 0;

	cl_assert_equal_s(git_buf_cstr(&target_path), buf);

	git_buf_dispose(&target_path);
}

void test_core_link__readlink_multiple(void)
{
	git_buf target_path = GIT_BUF_INIT,
		path3 = GIT_BUF_INIT, path2 = GIT_BUF_INIT, path1 = GIT_BUF_INIT;
	int len;
	char buf[2048];

	if (!should_run())
		clar__skip();

	git_buf_join(&target_path, '/', clar_sandbox_path(), "readlink_final");
	git_buf_join(&path3, '/', clar_sandbox_path(), "readlink_3");
	git_buf_join(&path2, '/', clar_sandbox_path(), "readlink_2");
	git_buf_join(&path1, '/', clar_sandbox_path(), "readlink_1");

	do_symlink(git_buf_cstr(&target_path), git_buf_cstr(&path3), 0);
	do_symlink(git_buf_cstr(&path3), git_buf_cstr(&path2), 0);
	do_symlink(git_buf_cstr(&path2), git_buf_cstr(&path1), 0);

	len = p_readlink("readlink_1", buf, 2048);
	cl_must_pass(len);

	buf[len] = 0;

	cl_assert_equal_s(git_buf_cstr(&path2), buf);

	git_buf_dispose(&path1);
	git_buf_dispose(&path2);
	git_buf_dispose(&path3);
	git_buf_dispose(&target_path);
}

