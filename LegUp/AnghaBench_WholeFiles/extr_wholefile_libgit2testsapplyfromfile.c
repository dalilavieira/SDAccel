#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_patch ;
struct TYPE_10__ {scalar_t__ context_lines; } ;
typedef  TYPE_1__ git_diff_options ;
struct TYPE_11__ {unsigned int size; char* ptr; } ;
typedef  TYPE_2__ git_buf ;

/* Variables and functions */
 char* FILE_APPEND ; 
 char* FILE_APPEND_NO_NL ; 
 char* FILE_BINARY_DELTA_MODIFIED ; 
 size_t FILE_BINARY_DELTA_MODIFIED_LEN ; 
 char* FILE_BINARY_DELTA_ORIGINAL ; 
 size_t FILE_BINARY_DELTA_ORIGINAL_LEN ; 
 char* FILE_BINARY_LITERAL_MODIFIED ; 
 size_t FILE_BINARY_LITERAL_MODIFIED_LEN ; 
 char* FILE_BINARY_LITERAL_ORIGINAL ; 
 size_t FILE_BINARY_LITERAL_ORIGINAL_LEN ; 
 char* FILE_CHANGE_FIRSTLINE ; 
 char* FILE_CHANGE_LASTLINE ; 
 char* FILE_CHANGE_MIDDLE ; 
 char* FILE_CHANGE_MIDDLE_GROW ; 
 char* FILE_CHANGE_MIDDLE_SHRINK ; 
 char* FILE_EMPTY_CONTEXT_MODIFIED ; 
 char* FILE_EMPTY_CONTEXT_ORIGINAL ; 
 char* FILE_ORIGINAL ; 
 char* FILE_PREPEND ; 
 char* FILE_PREPEND_AND_APPEND ; 
 TYPE_2__ GIT_BUF_INIT ; 
 TYPE_1__ GIT_DIFF_OPTIONS_INIT ; 
 char* PATCH_ADD_ORIGINAL ; 
 char* PATCH_APPEND_NO_NL ; 
 char* PATCH_BINARY_ADD ; 
 char* PATCH_BINARY_DELETE ; 
 char* PATCH_BINARY_DELTA ; 
 char* PATCH_BINARY_LITERAL ; 
 char* PATCH_BINARY_NOT_REVERSIBLE ; 
 char* PATCH_CORRUPT_GIT_HEADER ; 
 char* PATCH_CORRUPT_MISSING_HUNK_HEADER ; 
 char* PATCH_CORRUPT_MISSING_NEW_FILE ; 
 char* PATCH_CORRUPT_MISSING_OLD_FILE ; 
 char* PATCH_CORRUPT_NO_CHANGES ; 
 char* PATCH_DELETE_ORIGINAL ; 
 char* PATCH_EMPTY_CONTEXT ; 
 char* PATCH_EMPTY_FILE_TO_ORIGINAL ; 
 char* PATCH_MODECHANGE_MODIFIED ; 
 char* PATCH_MODECHANGE_UNCHANGED ; 
 char* PATCH_NOISY ; 
 char* PATCH_NOISY_NOCONTEXT ; 
 char* PATCH_NOT_A_PATCH ; 
 char* PATCH_ORIGINAL_TO_APPEND ; 
 char* PATCH_ORIGINAL_TO_APPEND_NOCONTEXT ; 
 char* PATCH_ORIGINAL_TO_CHANGE_FIRSTLINE ; 
 char* PATCH_ORIGINAL_TO_CHANGE_LASTLINE ; 
 char* PATCH_ORIGINAL_TO_CHANGE_MIDDLE ; 
 char* PATCH_ORIGINAL_TO_CHANGE_MIDDLE_GROW ; 
 char* PATCH_ORIGINAL_TO_CHANGE_MIDDLE_NOCONTEXT ; 
 char* PATCH_ORIGINAL_TO_CHANGE_MIDDLE_SHRINK ; 
 char* PATCH_ORIGINAL_TO_EMPTY_FILE ; 
 char* PATCH_ORIGINAL_TO_MIDDLE_GROW_NOCONTEXT ; 
 char* PATCH_ORIGINAL_TO_MIDDLE_SHRINK_NOCONTEXT ; 
 char* PATCH_ORIGINAL_TO_PREPEND ; 
 char* PATCH_ORIGINAL_TO_PREPEND_AND_APPEND ; 
 char* PATCH_ORIGINAL_TO_PREPEND_NOCONTEXT ; 
 char* PATCH_RENAME_EXACT ; 
 char* PATCH_RENAME_SIMILAR ; 
 char* PATCH_RENAME_SIMILAR_QUOTEDNAME ; 
 char* PATCH_TRUNCATED_1 ; 
 char* PATCH_TRUNCATED_2 ; 
 char* PATCH_TRUNCATED_3 ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char*) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  git__free (char*) ; 
 int git_apply__patch (TYPE_2__*,char**,unsigned int*,char const*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_2__*) ; 
 int /*<<< orphan*/  git_patch_free (int /*<<< orphan*/ *) ; 
 int git_patch_from_buffer (int /*<<< orphan*/ **,char const*,size_t,int /*<<< orphan*/ *) ; 
 int git_patch_from_buffers (int /*<<< orphan*/ **,char const*,size_t,char*,char const*,size_t,char*,TYPE_1__ const*) ; 
 int git_patch_to_buf (TYPE_2__*,int /*<<< orphan*/ *) ; 
 scalar_t__ memcmp (char const*,char*,size_t) ; 
 int /*<<< orphan*/  repo ; 
 size_t strlen (char const*) ; 

void test_apply_fromfile__initialize(void)
{
	repo = cl_git_sandbox_init("renames");
}

void test_apply_fromfile__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static int apply_patchfile(
	const char *old,
	size_t old_len,
	const char *new,
	size_t new_len,
	const char *patchfile,
	const char *filename_expected,
	unsigned int mode_expected)
{
	git_patch *patch;
	git_buf result = GIT_BUF_INIT;
	git_buf patchbuf = GIT_BUF_INIT;
	char *filename;
	unsigned int mode;
	int error;

	cl_git_pass(git_patch_from_buffer(&patch, patchfile, strlen(patchfile), NULL));

	error = git_apply__patch(&result, &filename, &mode, old, old_len, patch, NULL);

	if (error == 0) {
		cl_assert_equal_i(new_len, result.size);
		if (new_len)
			cl_assert(memcmp(new, result.ptr, new_len) == 0);

		cl_assert_equal_s(filename_expected, filename);
		cl_assert_equal_i(mode_expected, mode);
	}

	git__free(filename);
	git_buf_dispose(&result);
	git_buf_dispose(&patchbuf);
	git_patch_free(patch);

	return error;
}

__attribute__((used)) static int validate_and_apply_patchfile(
	const char *old,
	size_t old_len,
	const char *new,
	size_t new_len,
	const char *patchfile,
	const git_diff_options *diff_opts,
	const char *filename_expected,
	unsigned int mode_expected)
{
	git_patch *patch_fromdiff;
	git_buf validated = GIT_BUF_INIT;
	int error;

	cl_git_pass(git_patch_from_buffers(&patch_fromdiff,
		old, old_len, "file.txt",
		new, new_len, "file.txt",
		diff_opts));
	cl_git_pass(git_patch_to_buf(&validated, patch_fromdiff));

	cl_assert_equal_s(patchfile, validated.ptr);

	error = apply_patchfile(old, old_len, new, new_len, patchfile, filename_expected, mode_expected);

	git_buf_dispose(&validated);
	git_patch_free(patch_fromdiff);

	return error;
}

void test_apply_fromfile__change_middle(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_ORIGINAL_TO_CHANGE_MIDDLE, NULL,
		"file.txt", 0100644));
}

void test_apply_fromfile__change_middle_nocontext(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_ORIGINAL_TO_CHANGE_MIDDLE_NOCONTEXT,
		&diff_opts, "file.txt", 0100644));
}

void test_apply_fromfile__change_firstline(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_FIRSTLINE, strlen(FILE_CHANGE_FIRSTLINE),
		PATCH_ORIGINAL_TO_CHANGE_FIRSTLINE, NULL,
		"file.txt", 0100644));
}

void test_apply_fromfile__lastline(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_LASTLINE, strlen(FILE_CHANGE_LASTLINE),
		PATCH_ORIGINAL_TO_CHANGE_LASTLINE, NULL,
		"file.txt", 0100644));
}

void test_apply_fromfile__change_middle_shrink(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE_SHRINK, strlen(FILE_CHANGE_MIDDLE_SHRINK),
		PATCH_ORIGINAL_TO_CHANGE_MIDDLE_SHRINK, NULL,
		"file.txt", 0100644));
}

void test_apply_fromfile__change_middle_shrink_nocontext(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE_SHRINK, strlen(FILE_CHANGE_MIDDLE_SHRINK),
		PATCH_ORIGINAL_TO_MIDDLE_SHRINK_NOCONTEXT, &diff_opts,
		"file.txt", 0100644));
}

void test_apply_fromfile__change_middle_grow(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE_GROW, strlen(FILE_CHANGE_MIDDLE_GROW),
		PATCH_ORIGINAL_TO_CHANGE_MIDDLE_GROW, NULL,
		"file.txt", 0100644));
}

void test_apply_fromfile__change_middle_grow_nocontext(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE_GROW, strlen(FILE_CHANGE_MIDDLE_GROW),
		PATCH_ORIGINAL_TO_MIDDLE_GROW_NOCONTEXT, &diff_opts,
		"file.txt", 0100644));
}

void test_apply_fromfile__prepend(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_PREPEND, strlen(FILE_PREPEND),
		PATCH_ORIGINAL_TO_PREPEND, NULL, "file.txt", 0100644));
}

void test_apply_fromfile__prepend_nocontext(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_PREPEND, strlen(FILE_PREPEND),
		PATCH_ORIGINAL_TO_PREPEND_NOCONTEXT, &diff_opts,
		"file.txt", 0100644));
}

void test_apply_fromfile__append(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_APPEND, strlen(FILE_APPEND),
		PATCH_ORIGINAL_TO_APPEND, NULL, "file.txt", 0100644));
}

void test_apply_fromfile__append_nocontext(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_APPEND, strlen(FILE_APPEND),
		PATCH_ORIGINAL_TO_APPEND_NOCONTEXT, &diff_opts,
		"file.txt", 0100644));
}

void test_apply_fromfile__prepend_and_append(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_PREPEND_AND_APPEND, strlen(FILE_PREPEND_AND_APPEND),
		PATCH_ORIGINAL_TO_PREPEND_AND_APPEND, NULL,
		"file.txt", 0100644));
}

void test_apply_fromfile__to_empty_file(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		"", 0,
		PATCH_ORIGINAL_TO_EMPTY_FILE, NULL, "file.txt", 0100644));
}

void test_apply_fromfile__from_empty_file(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		"", 0,
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		PATCH_EMPTY_FILE_TO_ORIGINAL, NULL, "file.txt", 0100644));
}

void test_apply_fromfile__add(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		NULL, 0,
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		PATCH_ADD_ORIGINAL, NULL, "file.txt", 0100644));
}

void test_apply_fromfile__delete(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		NULL, 0,
		PATCH_DELETE_ORIGINAL, NULL, NULL, 0));
}

void test_apply_fromfile__rename_exact(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		PATCH_RENAME_EXACT, "newfile.txt", 0100644));
}

void test_apply_fromfile__rename_similar(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_RENAME_SIMILAR, "newfile.txt", 0100644));
}

void test_apply_fromfile__rename_similar_quotedname(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_RENAME_SIMILAR_QUOTEDNAME, "foo\"bar.txt", 0100644));
}

void test_apply_fromfile__modechange(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		PATCH_MODECHANGE_UNCHANGED, "file.txt", 0100755));
}

void test_apply_fromfile__modechange_with_modification(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_MODECHANGE_MODIFIED, "file.txt", 0100755));
}

void test_apply_fromfile__noisy(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_NOISY, "file.txt", 0100644));
}

void test_apply_fromfile__noisy_nocontext(void)
{
	cl_git_pass(apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_CHANGE_MIDDLE, strlen(FILE_CHANGE_MIDDLE),
		PATCH_NOISY_NOCONTEXT, "file.txt", 0100644));
}

void test_apply_fromfile__fail_truncated_1(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch, PATCH_TRUNCATED_1,
		strlen(PATCH_TRUNCATED_1), NULL));
}

void test_apply_fromfile__fail_truncated_2(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch, PATCH_TRUNCATED_2,
		strlen(PATCH_TRUNCATED_2), NULL));
}

void test_apply_fromfile__fail_truncated_3(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch, PATCH_TRUNCATED_3,
		strlen(PATCH_TRUNCATED_3), NULL));
}

void test_apply_fromfile__fail_corrupt_githeader(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch, PATCH_CORRUPT_GIT_HEADER,
		strlen(PATCH_CORRUPT_GIT_HEADER), NULL));
}

void test_apply_fromfile__empty_context(void)
{
	cl_git_pass(apply_patchfile(
		FILE_EMPTY_CONTEXT_ORIGINAL, strlen(FILE_EMPTY_CONTEXT_ORIGINAL),
		FILE_EMPTY_CONTEXT_MODIFIED, strlen(FILE_EMPTY_CONTEXT_MODIFIED),
		PATCH_EMPTY_CONTEXT,
		"file.txt", 0100644));
}

void test_apply_fromfile__append_no_nl(void)
{
	cl_git_pass(validate_and_apply_patchfile(
		FILE_ORIGINAL, strlen(FILE_ORIGINAL),
		FILE_APPEND_NO_NL, strlen(FILE_APPEND_NO_NL),
		PATCH_APPEND_NO_NL, NULL, "file.txt", 0100644));
}

void test_apply_fromfile__fail_missing_new_file(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch,
		PATCH_CORRUPT_MISSING_NEW_FILE,
		strlen(PATCH_CORRUPT_MISSING_NEW_FILE), NULL));
}

void test_apply_fromfile__fail_missing_old_file(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch,
		PATCH_CORRUPT_MISSING_OLD_FILE,
		strlen(PATCH_CORRUPT_MISSING_OLD_FILE), NULL));
}

void test_apply_fromfile__fail_no_changes(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch,
		PATCH_CORRUPT_NO_CHANGES,
		strlen(PATCH_CORRUPT_NO_CHANGES), NULL));
}

void test_apply_fromfile__fail_missing_hunk_header(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch,
		PATCH_CORRUPT_MISSING_HUNK_HEADER,
		strlen(PATCH_CORRUPT_MISSING_HUNK_HEADER), NULL));
}

void test_apply_fromfile__fail_not_a_patch(void)
{
	git_patch *patch;
	cl_git_fail(git_patch_from_buffer(&patch, PATCH_NOT_A_PATCH,
		strlen(PATCH_NOT_A_PATCH), NULL));
}

void test_apply_fromfile__binary_add(void)
{
	cl_git_pass(apply_patchfile(
		NULL, 0,
		FILE_BINARY_DELTA_MODIFIED, FILE_BINARY_DELTA_MODIFIED_LEN,
		PATCH_BINARY_ADD, "binary.bin", 0100644));
}

void test_apply_fromfile__binary_change_delta(void)
{
	cl_git_pass(apply_patchfile(
		FILE_BINARY_DELTA_ORIGINAL, FILE_BINARY_DELTA_ORIGINAL_LEN,
		FILE_BINARY_DELTA_MODIFIED, FILE_BINARY_DELTA_MODIFIED_LEN,
		PATCH_BINARY_DELTA, "binary.bin", 0100644));
}

void test_apply_fromfile__binary_change_literal(void)
{
	cl_git_pass(apply_patchfile(
		FILE_BINARY_LITERAL_ORIGINAL, FILE_BINARY_LITERAL_ORIGINAL_LEN,
		FILE_BINARY_LITERAL_MODIFIED, FILE_BINARY_LITERAL_MODIFIED_LEN,
		PATCH_BINARY_LITERAL, "binary.bin", 0100644));
}

void test_apply_fromfile__binary_delete(void)
{
	cl_git_pass(apply_patchfile(
		FILE_BINARY_DELTA_MODIFIED, FILE_BINARY_DELTA_MODIFIED_LEN,
		NULL, 0,
		PATCH_BINARY_DELETE, NULL, 0));
}

void test_apply_fromfile__binary_change_does_not_apply(void)
{
	/* try to apply patch backwards, ensure it does not apply */
	cl_git_fail(apply_patchfile(
		FILE_BINARY_DELTA_MODIFIED, FILE_BINARY_DELTA_MODIFIED_LEN,
		FILE_BINARY_DELTA_ORIGINAL, FILE_BINARY_DELTA_ORIGINAL_LEN,
		PATCH_BINARY_DELTA, "binary.bin", 0100644));
}

void test_apply_fromfile__binary_change_must_be_reversible(void)
{
	cl_git_fail(apply_patchfile(
		FILE_BINARY_DELTA_MODIFIED, FILE_BINARY_DELTA_MODIFIED_LEN,
		NULL, 0,
		PATCH_BINARY_NOT_REVERSIBLE, NULL, 0));
}

void test_apply_fromfile__empty_file_not_allowed(void)
{
	git_patch *patch;

	cl_git_fail(git_patch_from_buffer(&patch, "", 0, NULL));
	cl_git_fail(git_patch_from_buffer(&patch, NULL, 0, NULL));
}

