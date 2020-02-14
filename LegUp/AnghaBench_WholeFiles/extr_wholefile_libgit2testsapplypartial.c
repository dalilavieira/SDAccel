#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_patch ;
struct TYPE_21__ {scalar_t__ context_lines; } ;
typedef  TYPE_1__ git_diff_options ;
struct TYPE_22__ {scalar_t__ new_lines; scalar_t__ old_lines; } ;
typedef  TYPE_2__ git_diff_hunk ;
struct TYPE_23__ {char* ptr; } ;
typedef  TYPE_3__ git_buf ;
struct TYPE_24__ {int (* hunk_cb ) (TYPE_2__ const*,void*) ;void* payload; } ;
typedef  TYPE_4__ git_apply_options ;
typedef  int (* git_apply_hunk_cb ) (TYPE_2__ const*,void*) ;

/* Variables and functions */
 char* FILE_CHANGE_MIDDLE ; 
 char* FILE_DELETE_AND_CHANGE ; 
 char* FILE_DELETE_FIRSTLINE ; 
 char* FILE_ORIGINAL ; 
 char* FILE_PREPEND ; 
 char* FILE_PREPEND_AND_CHANGE ; 
 TYPE_4__ GIT_APPLY_OPTIONS_INIT ; 
 TYPE_3__ GIT_BUF_INIT ; 
 TYPE_1__ GIT_DIFF_OPTIONS_INIT ; 
 int GIT_EUSER ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,unsigned int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char*) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  git__free (char*) ; 
 int git_apply__patch (TYPE_3__*,char**,unsigned int*,char const*,size_t,int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_3__*) ; 
 int /*<<< orphan*/  git_patch_free (int /*<<< orphan*/ *) ; 
 int git_patch_from_buffers (int /*<<< orphan*/ **,char const*,size_t,char const*,char const*,size_t,char const*,TYPE_1__ const*) ; 
 int /*<<< orphan*/  repo ; 
 size_t strlen (char const*) ; 

void test_apply_partial__initialize(void)
{
	repo = cl_git_sandbox_init("renames");
}

void test_apply_partial__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static int skip_addition(
	const git_diff_hunk *hunk,
	void *payload)
{
	GIT_UNUSED(payload);

	return (hunk->new_lines > hunk->old_lines) ? 1 : 0;
}

__attribute__((used)) static int skip_deletion(
	const git_diff_hunk *hunk,
	void *payload)
{
	GIT_UNUSED(payload);

	return (hunk->new_lines < hunk->old_lines) ? 1 : 0;
}

__attribute__((used)) static int skip_change(
	const git_diff_hunk *hunk,
	void *payload)
{
	GIT_UNUSED(payload);

	return (hunk->new_lines == hunk->old_lines) ? 1 : 0;
}

__attribute__((used)) static int abort_addition(
	const git_diff_hunk *hunk,
	void *payload)
{
	GIT_UNUSED(payload);

	return (hunk->new_lines > hunk->old_lines) ? GIT_EUSER : 0;
}

__attribute__((used)) static int abort_deletion(
	const git_diff_hunk *hunk,
	void *payload)
{
	GIT_UNUSED(payload);

	return (hunk->new_lines < hunk->old_lines) ? GIT_EUSER : 0;
}

__attribute__((used)) static int abort_change(
	const git_diff_hunk *hunk,
	void *payload)
{
	GIT_UNUSED(payload);

	return (hunk->new_lines == hunk->old_lines) ? GIT_EUSER : 0;
}

__attribute__((used)) static int apply_buf(
	const char *old,
	const char *oldname,
	const char *new,
	const char *newname,
	const char *expected,
	const git_diff_options *diff_opts,
	git_apply_hunk_cb hunk_cb,
	void *payload)
{
	git_patch *patch;
	git_buf result = GIT_BUF_INIT;
	git_buf patchbuf = GIT_BUF_INIT;
	git_apply_options opts = GIT_APPLY_OPTIONS_INIT;
	char *filename;
	unsigned int mode;
	int error;
	size_t oldsize = strlen(old);
	size_t newsize = strlen(new);

	opts.hunk_cb = hunk_cb;
	opts.payload = payload;

	cl_git_pass(git_patch_from_buffers(&patch, old, oldsize, oldname, new, newsize, newname, diff_opts));
	if ((error = git_apply__patch(&result, &filename, &mode, old, oldsize, patch, &opts)) == 0) {
		cl_assert_equal_s(expected, result.ptr);
		cl_assert_equal_s(newname, filename);
		cl_assert_equal_i(0100644, mode);
	}

	git__free(filename);
	git_buf_dispose(&result);
	git_buf_dispose(&patchbuf);
	git_patch_free(patch);

	return error;
}

void test_apply_partial__prepend_and_change_skip_addition(void)
{
	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_PREPEND_AND_CHANGE, "file.txt",
		FILE_ORIGINAL, NULL, skip_addition, NULL));
}

void test_apply_partial__prepend_and_change_nocontext_skip_addition(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_PREPEND_AND_CHANGE, "file.txt",
		FILE_CHANGE_MIDDLE, &diff_opts, skip_addition, NULL));
}

void test_apply_partial__prepend_and_change_nocontext_abort_addition(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_fail(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_PREPEND_AND_CHANGE, "file.txt",
		FILE_ORIGINAL, &diff_opts, abort_addition, NULL));
}

void test_apply_partial__prepend_and_change_skip_change(void)
{
	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_PREPEND_AND_CHANGE, "file.txt",
		FILE_PREPEND_AND_CHANGE, NULL, skip_change, NULL));
}

void test_apply_partial__prepend_and_change_nocontext_skip_change(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_PREPEND_AND_CHANGE, "file.txt",
		FILE_PREPEND, &diff_opts, skip_change, NULL));
}

void test_apply_partial__prepend_and_change_nocontext_abort_change(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_fail(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_PREPEND_AND_CHANGE, "file.txt",
		FILE_PREPEND, &diff_opts, abort_change, NULL));
}

void test_apply_partial__delete_and_change_skip_deletion(void)
{
	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_ORIGINAL, NULL, skip_deletion, NULL));
}

void test_apply_partial__delete_and_change_nocontext_skip_deletion(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_CHANGE_MIDDLE, &diff_opts, skip_deletion, NULL));
}

void test_apply_partial__delete_and_change_nocontext_abort_deletion(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_fail(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_ORIGINAL, &diff_opts, abort_deletion, NULL));
}

void test_apply_partial__delete_and_change_skip_change(void)
{
	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_DELETE_AND_CHANGE, NULL, skip_change, NULL));
}

void test_apply_partial__delete_and_change_nocontext_skip_change(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_DELETE_FIRSTLINE, &diff_opts, skip_change, NULL));
}

void test_apply_partial__delete_and_change_nocontext_abort_change(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_fail(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_DELETE_FIRSTLINE, &diff_opts, abort_change, NULL));
}

