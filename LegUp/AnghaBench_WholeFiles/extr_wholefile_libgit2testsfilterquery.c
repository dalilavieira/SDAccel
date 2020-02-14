#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_filter_list ;
struct TYPE_3__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_filter ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_FILTER_TO_WORKTREE ; 
 int /*<<< orphan*/  GIT_FILTER_VERSION ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  g_repo ; 
 int git_filter_list_contains (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_filter_list_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_load (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_filter_register (char*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  git_filter_unregister (char*) ; 

void test_filter_query__initialize(void)
{
	g_repo = cl_git_sandbox_init("crlf");

	cl_git_mkfile("crlf/.gitattributes",
		"*.txt text\n"
		"*.bin binary\n"
		"*.crlf text eol=crlf\n"
		"*.lf text eol=lf\n"
		"*.binident binary ident\n"
		"*.ident text ident\n"
		"*.identcrlf ident text eol=crlf\n"
		"*.identlf ident text eol=lf\n"
		"*.custom custom ident text\n");
}

void test_filter_query__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static int filter_for(const char *filename, const char *filter)
{
	git_filter_list *fl;
	int filtered;

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, filename, GIT_FILTER_TO_WORKTREE, 0));
	filtered = git_filter_list_contains(fl, filter);
	git_filter_list_free(fl);

	return filtered;
}

void test_filter_query__filters(void)
{
	cl_assert_equal_i(1, filter_for("text.txt", "crlf"));
	cl_assert_equal_i(0, filter_for("binary.bin", "crlf"));

	cl_assert_equal_i(1, filter_for("foo.lf", "crlf"));
	cl_assert_equal_i(0, filter_for("foo.lf", "ident"));

	cl_assert_equal_i(1, filter_for("id.ident", "crlf"));
	cl_assert_equal_i(1, filter_for("id.ident", "ident"));

	cl_assert_equal_i(0, filter_for("id.binident", "crlf"));
	cl_assert_equal_i(1, filter_for("id.binident", "ident"));
}

void test_filter_query__autocrlf_true_implies_crlf(void)
{
	cl_repo_set_bool(g_repo, "core.autocrlf", true);
	cl_assert_equal_i(1, filter_for("not_in_gitattributes", "crlf"));
	cl_assert_equal_i(1, filter_for("foo.txt", "crlf"));
	cl_assert_equal_i(0, filter_for("foo.bin", "crlf"));
	cl_assert_equal_i(1, filter_for("foo.lf", "crlf"));

	cl_repo_set_bool(g_repo, "core.autocrlf", false);
	cl_assert_equal_i(0, filter_for("not_in_gitattributes", "crlf"));
	cl_assert_equal_i(1, filter_for("foo.txt", "crlf"));
	cl_assert_equal_i(0, filter_for("foo.bin", "crlf"));
	cl_assert_equal_i(1, filter_for("foo.lf", "crlf"));
}

void test_filter_query__unknown(void)
{
	cl_assert_equal_i(1, filter_for("foo.custom", "crlf"));
	cl_assert_equal_i(1, filter_for("foo.custom", "ident"));
	cl_assert_equal_i(0, filter_for("foo.custom", "custom"));
}

void test_filter_query__custom(void)
{
	git_filter custom = { GIT_FILTER_VERSION };

	cl_git_pass(git_filter_register(
		"custom", &custom, 42));

	cl_assert_equal_i(1, filter_for("foo.custom", "crlf"));
	cl_assert_equal_i(1, filter_for("foo.custom", "ident"));
	cl_assert_equal_i(1, filter_for("foo.custom", "custom"));

	git_filter_unregister("custom");
}

