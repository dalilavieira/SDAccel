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
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ERROR ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ git_index_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_new (int /*<<< orphan*/ **) ; 

void test_index_inmemory__can_create_an_inmemory_index(void)
{
	git_index *index;

	cl_git_pass(git_index_new(&index));
	cl_assert_equal_i(0, (int)git_index_entrycount(index));

	git_index_free(index);
}

void test_index_inmemory__cannot_add_bypath_to_an_inmemory_index(void)
{
	git_index *index;

	cl_git_pass(git_index_new(&index));

	cl_assert_equal_i(GIT_ERROR, git_index_add_bypath(index, "test.txt"));

	git_index_free(index);
}

