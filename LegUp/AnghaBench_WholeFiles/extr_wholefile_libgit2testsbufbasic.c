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
struct TYPE_9__ {int size; int asize; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 char* git_buf_cstr (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_grow_by (TYPE_1__*,int) ; 
 scalar_t__ git_buf_oom (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_printf (TYPE_1__*,char*,char*,...) ; 
 int /*<<< orphan*/  git_buf_puts (TYPE_1__*,char*) ; 
 int strlen (char*) ; 
 char* test_string ; 

void test_buf_basic__resize(void)
{
	git_buf buf1 = GIT_BUF_INIT;
	git_buf_puts(&buf1, test_string);
	cl_assert(git_buf_oom(&buf1) == 0);
	cl_assert_equal_s(git_buf_cstr(&buf1), test_string);

	git_buf_puts(&buf1, test_string);
	cl_assert(strlen(git_buf_cstr(&buf1)) == strlen(test_string) * 2);
	git_buf_dispose(&buf1);
}

void test_buf_basic__resize_incremental(void)
{
	git_buf buf1 = GIT_BUF_INIT;

	/* Presently, asking for 6 bytes will round up to 8. */
	cl_git_pass(git_buf_puts(&buf1, "Hello"));
	cl_assert_equal_i(5, buf1.size);
	cl_assert_equal_i(8, buf1.asize);

	/* Ensure an additional byte does not realloc. */
	cl_git_pass(git_buf_grow_by(&buf1, 1));
	cl_assert_equal_i(5, buf1.size);
	cl_assert_equal_i(8, buf1.asize);

	/* But requesting many does. */
	cl_git_pass(git_buf_grow_by(&buf1, 16));
	cl_assert_equal_i(5, buf1.size);
	cl_assert(buf1.asize > 8);

	git_buf_dispose(&buf1);
}

void test_buf_basic__printf(void)
{
	git_buf buf2 = GIT_BUF_INIT;
	git_buf_printf(&buf2, "%s %s %d ", "shoop", "da", 23);
	cl_assert(git_buf_oom(&buf2) == 0);
	cl_assert_equal_s(git_buf_cstr(&buf2), "shoop da 23 ");

	git_buf_printf(&buf2, "%s %d", "woop", 42);
	cl_assert(git_buf_oom(&buf2) == 0);
	cl_assert_equal_s(git_buf_cstr(&buf2), "shoop da 23 woop 42");
	git_buf_dispose(&buf2);
}

