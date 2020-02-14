#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_patch ;
struct TYPE_5__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 char* PATCH_ADD_ORIGINAL ; 
 char* PATCH_BINARY_ADD ; 
 char* PATCH_BINARY_DELETE ; 
 char* PATCH_BINARY_DELTA ; 
 char* PATCH_BINARY_LITERAL ; 
 char* PATCH_BINARY_NOT_PRINTED ; 
 char* PATCH_BINARY_NOT_REVERSIBLE ; 
 char* PATCH_DELETE_ORIGINAL ; 
 char* PATCH_EMPTY_FILE_TO_ORIGINAL ; 
 char* PATCH_MODECHANGE_MODIFIED ; 
 char* PATCH_MODECHANGE_UNCHANGED ; 
 char* PATCH_ORIGINAL_TO_APPEND ; 
 char* PATCH_ORIGINAL_TO_APPEND_NOCONTEXT ; 
 char* PATCH_ORIGINAL_TO_CHANGE_FIRSTLINE ; 
 char* PATCH_ORIGINAL_TO_CHANGE_LASTLINE ; 
 char* PATCH_ORIGINAL_TO_CHANGE_MIDDLE ; 
 char* PATCH_ORIGINAL_TO_CHANGE_MIDDLE_NOCONTEXT ; 
 char* PATCH_ORIGINAL_TO_EMPTY_FILE ; 
 char* PATCH_ORIGINAL_TO_PREPEND ; 
 char* PATCH_ORIGINAL_TO_PREPEND_AND_APPEND ; 
 char* PATCH_ORIGINAL_TO_PREPEND_NOCONTEXT ; 
 char* PATCH_RENAME_EXACT ; 
 char* PATCH_RENAME_EXACT_QUOTEDNAME ; 
 char* PATCH_RENAME_SIMILAR ; 
 char* PATCH_RENAME_SIMILAR_QUOTEDNAME ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_patch_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_patch_from_buffer (int /*<<< orphan*/ **,char const*,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_patch_to_buf (TYPE_1__*,int /*<<< orphan*/ *) ; 
 size_t strlen (char*) ; 

void patch_print_from_patchfile(const char *data, size_t len)
{
	git_patch *patch;
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_patch_from_buffer(&patch, data, len, NULL));
	cl_git_pass(git_patch_to_buf(&buf, patch));

	cl_assert_equal_s(data, buf.ptr);

	git_patch_free(patch);
	git_buf_dispose(&buf);
}

void test_patch_print__change_middle(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_CHANGE_MIDDLE,
		strlen(PATCH_ORIGINAL_TO_CHANGE_MIDDLE));
}

void test_patch_print__change_middle_nocontext(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_CHANGE_MIDDLE_NOCONTEXT,
		strlen(PATCH_ORIGINAL_TO_CHANGE_MIDDLE_NOCONTEXT));
}

void test_patch_print__change_firstline(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_CHANGE_FIRSTLINE,
		strlen(PATCH_ORIGINAL_TO_CHANGE_FIRSTLINE));
}

void test_patch_print__change_lastline(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_CHANGE_LASTLINE,
		strlen(PATCH_ORIGINAL_TO_CHANGE_LASTLINE));
}

void test_patch_print__prepend(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_PREPEND,
		strlen(PATCH_ORIGINAL_TO_PREPEND));
}

void test_patch_print__prepend_nocontext(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_PREPEND_NOCONTEXT,
		strlen(PATCH_ORIGINAL_TO_PREPEND_NOCONTEXT));
}

void test_patch_print__append(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_APPEND,
		strlen(PATCH_ORIGINAL_TO_APPEND));
}

void test_patch_print__append_nocontext(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_APPEND_NOCONTEXT,
		strlen(PATCH_ORIGINAL_TO_APPEND_NOCONTEXT));
}

void test_patch_print__prepend_and_append(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_PREPEND_AND_APPEND,
		strlen(PATCH_ORIGINAL_TO_PREPEND_AND_APPEND));
}

void test_patch_print__to_empty_file(void)
{
	patch_print_from_patchfile(PATCH_ORIGINAL_TO_EMPTY_FILE,
		strlen(PATCH_ORIGINAL_TO_EMPTY_FILE));
}

void test_patch_print__from_empty_file(void)
{
	patch_print_from_patchfile(PATCH_EMPTY_FILE_TO_ORIGINAL,
		strlen(PATCH_EMPTY_FILE_TO_ORIGINAL));
}

void test_patch_print__add(void)
{
	patch_print_from_patchfile(PATCH_ADD_ORIGINAL,
		strlen(PATCH_ADD_ORIGINAL));
}

void test_patch_print__delete(void)
{
	patch_print_from_patchfile(PATCH_DELETE_ORIGINAL,
		strlen(PATCH_DELETE_ORIGINAL));
}

void test_patch_print__rename_exact(void)
{
	patch_print_from_patchfile(PATCH_RENAME_EXACT,
		strlen(PATCH_RENAME_EXACT));
}

void test_patch_print__rename_similar(void)
{
	patch_print_from_patchfile(PATCH_RENAME_SIMILAR,
		strlen(PATCH_RENAME_SIMILAR));
}

void test_patch_print__rename_exact_quotedname(void)
{
	patch_print_from_patchfile(PATCH_RENAME_EXACT_QUOTEDNAME,
		strlen(PATCH_RENAME_EXACT_QUOTEDNAME));
}

void test_patch_print__rename_similar_quotedname(void)
{
	patch_print_from_patchfile(PATCH_RENAME_SIMILAR_QUOTEDNAME,
		strlen(PATCH_RENAME_SIMILAR_QUOTEDNAME));
}

void test_patch_print__modechange_unchanged(void)
{
	patch_print_from_patchfile(PATCH_MODECHANGE_UNCHANGED,
		strlen(PATCH_MODECHANGE_UNCHANGED));
}

void test_patch_print__modechange_modified(void)
{
	patch_print_from_patchfile(PATCH_MODECHANGE_MODIFIED,
		strlen(PATCH_MODECHANGE_MODIFIED));
}

void test_patch_print__binary_literal(void)
{
	patch_print_from_patchfile(PATCH_BINARY_LITERAL,
		strlen(PATCH_BINARY_LITERAL));
}

void test_patch_print__binary_delta(void)
{
	patch_print_from_patchfile(PATCH_BINARY_DELTA,
		strlen(PATCH_BINARY_DELTA));
}

void test_patch_print__binary_add(void)
{
	patch_print_from_patchfile(PATCH_BINARY_ADD,
		strlen(PATCH_BINARY_ADD));
}

void test_patch_print__binary_delete(void)
{
	patch_print_from_patchfile(PATCH_BINARY_DELETE,
		strlen(PATCH_BINARY_DELETE));
}

void test_patch_print__not_reversible(void)
{
	patch_print_from_patchfile(PATCH_BINARY_NOT_REVERSIBLE,
		strlen(PATCH_BINARY_NOT_REVERSIBLE));
}

void test_patch_print__binary_not_shown(void)
{
	patch_print_from_patchfile(PATCH_BINARY_NOT_PRINTED,
		strlen(PATCH_BINARY_NOT_PRINTED));
}

