#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_8__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_blame_options ;
struct TYPE_20__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_19__ {TYPE_4__ member_0; } ;
struct TYPE_18__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_17__ {TYPE_2__ member_0; } ;
struct TYPE_21__ {int member_0; int member_2; char* member_5; int /*<<< orphan*/  orig_path; int /*<<< orphan*/  lines_in_hunk; int /*<<< orphan*/  final_start_line_number; int /*<<< orphan*/  member_6; TYPE_3__ member_4; int /*<<< orphan*/ * member_3; TYPE_1__ member_1; } ;
typedef  TYPE_5__ git_blame_hunk ;
struct TYPE_22__ {int /*<<< orphan*/  hunks; } ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BLAME_OPTIONS_INIT ; 
 int /*<<< orphan*/  cl_assert (TYPE_5__ const*) ; 
 int /*<<< orphan*/  cl_assert_equal_p (TYPE_5__ const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char*) ; 
 TYPE_8__* g_blame ; 
 TYPE_5__* git__calloc (int,int) ; 
 int /*<<< orphan*/  git__strdup (int /*<<< orphan*/ ) ; 
 TYPE_8__* git_blame__alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_blame_free (TYPE_8__*) ; 
 TYPE_5__* git_blame_get_hunk_byindex (TYPE_8__*,int) ; 
 TYPE_5__* git_blame_get_hunk_byline (TYPE_8__*,int) ; 
 int /*<<< orphan*/  git_vector_insert (int /*<<< orphan*/ *,TYPE_5__*) ; 

void test_blame_getters__initialize(void)
{
	size_t i;
	git_blame_options opts = GIT_BLAME_OPTIONS_INIT;

	git_blame_hunk hunks[] = {
		{ 3, {{0}},  1, NULL, {{0}}, "a", 0},
		{ 3, {{0}},  4, NULL, {{0}}, "b", 0},
		{ 3, {{0}},  7, NULL, {{0}}, "c", 0},
		{ 3, {{0}}, 10, NULL, {{0}}, "d", 0},
		{ 3, {{0}}, 13, NULL, {{0}}, "e", 0},
	};

	g_blame = git_blame__alloc(NULL, opts, "");

	for (i=0; i<5; i++) {
		git_blame_hunk *h = git__calloc(1, sizeof(git_blame_hunk));
		h->final_start_line_number = hunks[i].final_start_line_number;
		h->orig_path = git__strdup(hunks[i].orig_path);
		h->lines_in_hunk = hunks[i].lines_in_hunk;

		git_vector_insert(&g_blame->hunks, h);
	}
}

void test_blame_getters__cleanup(void)
{
	git_blame_free(g_blame);
}

void test_blame_getters__byindex(void)
{
	const git_blame_hunk *h = git_blame_get_hunk_byindex(g_blame, 2);
	cl_assert(h);
	cl_assert_equal_s(h->orig_path, "c");

	h = git_blame_get_hunk_byindex(g_blame, 95);
	cl_assert_equal_p(h, NULL);
}

void test_blame_getters__byline(void)
{
	const git_blame_hunk *h = git_blame_get_hunk_byline(g_blame, 5);
	cl_assert(h);
	cl_assert_equal_s(h->orig_path, "b");

	h = git_blame_get_hunk_byline(g_blame, 95);
	cl_assert_equal_p(h, NULL);
}

