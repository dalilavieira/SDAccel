#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  line ;
typedef  int /*<<< orphan*/  git_submodule ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_9__ {char const* ptr; } ;
typedef  TYPE_1__ git_buf ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  F_OK ; 
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_SUBMODULE_IGNORE_UNSPECIFIED ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_at_line (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (void*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_report_failure (int,int /*<<< orphan*/ ,char const*,int,char const*) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_set_cleanup (void (*) (void*),char*) ; 
 int /*<<< orphan*/  clar__assert_equal (char const*,int,char const*,int,char*,int,int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,char*,unsigned int) ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fwrite (char*,int,int,int /*<<< orphan*/ *) ; 
 scalar_t__ git__prefixcmp (char*,char*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_1__*,char const*,char*) ; 
 int /*<<< orphan*/  git_buf_oom (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_putc (TYPE_1__*,char) ; 
 int /*<<< orphan*/  git_buf_rtrim (TYPE_1__*) ; 
 int /*<<< orphan*/  git_path_prettify (TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_reinit_filesystem (int /*<<< orphan*/ *,int) ; 
 char* git_repository_workdir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_foreach (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,char const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_location (unsigned int*,int /*<<< orphan*/ *) ; 
 int git_submodule_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 char* git_submodule_path (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_submodule_status (unsigned int*,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ p_access (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p_mkdir (char*,int) ; 
 int /*<<< orphan*/  p_rename (char*,char*) ; 
 int /*<<< orphan*/  p_unlink (char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strlen (char*) ; 

void rewrite_gitmodules(const char *workdir)
{
	git_buf in_f = GIT_BUF_INIT, out_f = GIT_BUF_INIT, path = GIT_BUF_INIT;
	FILE *in, *out;
	char line[256];

	cl_git_pass(git_buf_joinpath(&in_f, workdir, "gitmodules"));
	cl_git_pass(git_buf_joinpath(&out_f, workdir, ".gitmodules"));

	cl_assert((in  = fopen(in_f.ptr, "rb")) != NULL);
	cl_assert((out = fopen(out_f.ptr, "wb")) != NULL);

	while (fgets(line, sizeof(line), in) != NULL) {
		char *scan = line;

		while (*scan == ' ' || *scan == '\t') scan++;

		/* rename .gitted -> .git in submodule directories */
		if (git__prefixcmp(scan, "path =") == 0) {
			scan += strlen("path =");
			while (*scan == ' ') scan++;

			git_buf_joinpath(&path, workdir, scan);
			git_buf_rtrim(&path);
			git_buf_joinpath(&path, path.ptr, ".gitted");

			if (!git_buf_oom(&path) && p_access(path.ptr, F_OK) == 0) {
				git_buf_joinpath(&out_f, workdir, scan);
				git_buf_rtrim(&out_f);
				git_buf_joinpath(&out_f, out_f.ptr, ".git");

				if (!git_buf_oom(&out_f))
					p_rename(path.ptr, out_f.ptr);
			}
		}

		/* copy non-"url =" lines verbatim */
		if (git__prefixcmp(scan, "url =") != 0) {
			fputs(line, out);
			continue;
		}

		/* convert relative URLs in "url =" lines */
		scan += strlen("url =");
		while (*scan == ' ') scan++;

		if (*scan == '.') {
			git_buf_joinpath(&path, workdir, scan);
			git_buf_rtrim(&path);
		} else if (!*scan || *scan == '\n') {
			git_buf_joinpath(&path, workdir, "../testrepo.git");
		} else {
			fputs(line, out);
			continue;
		}

		git_path_prettify(&path, path.ptr, NULL);
		git_buf_putc(&path, '\n');
		cl_assert(!git_buf_oom(&path));

		fwrite(line, scan - line, sizeof(char), out);
		fputs(path.ptr, out);
	}

	fclose(in);
	fclose(out);

	cl_must_pass(p_unlink(in_f.ptr));

	git_buf_dispose(&in_f);
	git_buf_dispose(&out_f);
	git_buf_dispose(&path);
}

__attribute__((used)) static void cleanup_fixture_submodules(void *payload)
{
	cl_git_sandbox_cleanup(); /* either "submodules" or "submod2" */

	if (payload)
		cl_fixture_cleanup(payload);
}

git_repository *setup_fixture_submodules(void)
{
	git_repository *repo = cl_git_sandbox_init("submodules");

	cl_fixture_sandbox("testrepo.git");

	rewrite_gitmodules(git_repository_workdir(repo));
	p_rename("submodules/testrepo/.gitted", "submodules/testrepo/.git");

	cl_set_cleanup(cleanup_fixture_submodules, "testrepo.git");

	cl_git_pass(git_repository_reinit_filesystem(repo, 1));

	return repo;
}

git_repository *setup_fixture_submod2(void)
{
	git_repository *repo = cl_git_sandbox_init("submod2");

	cl_fixture_sandbox("submod2_target");
	p_rename("submod2_target/.gitted", "submod2_target/.git");

	rewrite_gitmodules(git_repository_workdir(repo));
	p_rename("submod2/not-submodule/.gitted", "submod2/not-submodule/.git");
	p_rename("submod2/not/.gitted", "submod2/not/.git");

	cl_set_cleanup(cleanup_fixture_submodules, "submod2_target");

	cl_git_pass(git_repository_reinit_filesystem(repo, 1));

	return repo;
}

git_repository *setup_fixture_submod3(void)
{
	git_repository *repo = cl_git_sandbox_init("submod3");

	cl_fixture_sandbox("submod2_target");
	p_rename("submod2_target/.gitted", "submod2_target/.git");

	rewrite_gitmodules(git_repository_workdir(repo));
	p_rename("submod3/One/.gitted", "submod3/One/.git");
	p_rename("submod3/TWO/.gitted", "submod3/TWO/.git");
	p_rename("submod3/three/.gitted", "submod3/three/.git");
	p_rename("submod3/FoUr/.gitted", "submod3/FoUr/.git");
	p_rename("submod3/Five/.gitted", "submod3/Five/.git");
	p_rename("submod3/six/.gitted", "submod3/six/.git");
	p_rename("submod3/sEvEn/.gitted", "submod3/sEvEn/.git");
	p_rename("submod3/EIGHT/.gitted", "submod3/EIGHT/.git");
	p_rename("submod3/nine/.gitted", "submod3/nine/.git");
	p_rename("submod3/TEN/.gitted", "submod3/TEN/.git");

	cl_set_cleanup(cleanup_fixture_submodules, "submod2_target");

	cl_git_pass(git_repository_reinit_filesystem(repo, 1));

	return repo;
}

git_repository *setup_fixture_super(void)
{
	git_repository *repo = cl_git_sandbox_init("super");

	cl_fixture_sandbox("sub.git");
	p_mkdir("super/sub", 0777);

	rewrite_gitmodules(git_repository_workdir(repo));

	cl_set_cleanup(cleanup_fixture_submodules, "sub.git");

	cl_git_pass(git_repository_reinit_filesystem(repo, 1));

	return repo;
}

git_repository *setup_fixture_submodule_simple(void)
{
	git_repository *repo = cl_git_sandbox_init("submodule_simple");

	cl_fixture_sandbox("testrepo.git");
	p_mkdir("submodule_simple/testrepo", 0777);

	cl_set_cleanup(cleanup_fixture_submodules, "testrepo.git");

	cl_git_pass(git_repository_reinit_filesystem(repo, 1));

	return repo;
}

git_repository *setup_fixture_submodule_with_path(void)
{
	git_repository *repo = cl_git_sandbox_init("submodule_with_path");

	cl_fixture_sandbox("testrepo.git");
	p_mkdir("submodule_with_path/lib", 0777);
	p_mkdir("submodule_with_path/lib/testrepo", 0777);

	cl_set_cleanup(cleanup_fixture_submodules, "testrepo.git");

	cl_git_pass(git_repository_reinit_filesystem(repo, 1));

	return repo;
}

void assert__submodule_exists(
	git_repository *repo, const char *name,
	const char *msg, const char *file, int line)
{
	git_submodule *sm;
	int error = git_submodule_lookup(&sm, repo, name);
	if (error)
		cl_git_report_failure(error, 0, file, line, msg);
	cl_assert_at_line(sm != NULL, file, line);
	git_submodule_free(sm);
}

void refute__submodule_exists(
	git_repository *repo, const char *name, int expected_error,
	const char *msg, const char *file, int line)
{
	clar__assert_equal(
		file, line, msg, 1, "%i",
		expected_error, (int)(git_submodule_lookup(NULL, repo, name)));
}

unsigned int get_submodule_status(git_repository *repo, const char *name)
{
	unsigned int status = 0;

	assert(repo && name);

	cl_git_pass(git_submodule_status(&status, repo, name, GIT_SUBMODULE_IGNORE_UNSPECIFIED));

	return status;
}

__attribute__((used)) static int print_submodules(git_submodule *sm, const char *name, void *p)
{
	unsigned int loc = 0;
	GIT_UNUSED(p);
	git_submodule_location(&loc, sm);
	fprintf(stderr, "# submodule %s (at %s) flags %x\n",
		name, git_submodule_path(sm), loc);
	return 0;
}

void dump_submodules(git_repository *repo)
{
	git_submodule_foreach(repo, print_submodules, NULL);
}

