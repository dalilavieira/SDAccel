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
 int /*<<< orphan*/  _buf ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_init (int /*<<< orphan*/ *,int) ; 
 int git_buf_len (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_sets (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_buf_splice (int /*<<< orphan*/ *,int,int,char*,int) ; 
 int strlen (char*) ; 

void test_buf_splice__initialize(void) {
   git_buf_init(&_buf, 16);
}

void test_buf_splice__cleanup(void) {
   git_buf_dispose(&_buf);
}

void test_buf_splice__preprend(void)
{
	git_buf_sets(&_buf, "world!");

	cl_git_pass(git_buf_splice(&_buf, 0, 0, "Hello Dolly", strlen("Hello ")));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__append(void)
{
	git_buf_sets(&_buf, "Hello");

	cl_git_pass(git_buf_splice(&_buf, git_buf_len(&_buf), 0, " world!", strlen(" world!")));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__insert_at(void)
{
	git_buf_sets(&_buf, "Hell world!");

	cl_git_pass(git_buf_splice(&_buf, strlen("Hell"), 0, "o", strlen("o")));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__remove_at(void)
{
	git_buf_sets(&_buf, "Hello world of warcraft!");

	cl_git_pass(git_buf_splice(&_buf, strlen("Hello world"), strlen(" of warcraft"), "", 0));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__replace(void)
{
	git_buf_sets(&_buf, "Hell0 w0rld!");

	cl_git_pass(git_buf_splice(&_buf, strlen("Hell"), strlen("0 w0"), "o wo", strlen("o wo")));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__replace_with_longer(void)
{
	git_buf_sets(&_buf, "Hello you!");

	cl_git_pass(git_buf_splice(&_buf, strlen("Hello "), strlen("you"), "world", strlen("world")));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__replace_with_shorter(void)
{
	git_buf_sets(&_buf, "Brave new world!");

	cl_git_pass(git_buf_splice(&_buf, 0, strlen("Brave new"), "Hello", strlen("Hello")));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__truncate(void)
{
	git_buf_sets(&_buf, "Hello world!!");

	cl_git_pass(git_buf_splice(&_buf, strlen("Hello world!"), strlen("!"), "", 0));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

void test_buf_splice__dont_do_anything(void)
{
	git_buf_sets(&_buf, "Hello world!");

	cl_git_pass(git_buf_splice(&_buf, 3, 0, "Hello", 0));

	cl_assert_equal_s("Hello world!", git_buf_cstr(&_buf));
}

