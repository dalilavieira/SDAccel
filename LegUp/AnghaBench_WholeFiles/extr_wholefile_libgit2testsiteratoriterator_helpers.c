#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t git_iterator_status_t ;
typedef  int /*<<< orphan*/  git_iterator ;
struct TYPE_6__ {char* path; size_t mode; } ;
typedef  TYPE_1__ git_index_entry ;

/* Variables and functions */
 int GIT_ENOTFOUND ; 
 size_t GIT_FILEMODE_TREE ; 
 int GIT_ITERATOR_INCLUDE_TREES ; 
 int GIT_ITEROVER ; 
 scalar_t__ S_ISDIR (size_t) ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (size_t,size_t) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char*) ; 
 int /*<<< orphan*/  cl_git_fail_with (int,int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,...) ; 
 int git_iterator_advance (TYPE_1__ const**,int /*<<< orphan*/ *) ; 
 int git_iterator_advance_into (TYPE_1__ const**,int /*<<< orphan*/ *) ; 
 int git_iterator_advance_over (TYPE_1__ const**,size_t*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_iterator_current (TYPE_1__ const**,int /*<<< orphan*/ *) ; 
 int git_iterator_flags (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_iterator_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static void assert_at_end(git_iterator *i, bool verbose)
{
	const git_index_entry *end;
	int error = git_iterator_advance(&end, i);

	if (verbose && error != GIT_ITEROVER)
		fprintf(stderr, "Expected end of iterator, got '%s'\n", end->path);

	cl_git_fail_with(GIT_ITEROVER, error);
}

void expect_iterator_items(
	git_iterator *i,
	size_t expected_flat,
	const char **expected_flat_paths,
	size_t expected_total,
	const char **expected_total_paths)
{
	const git_index_entry *entry;
	size_t count;
	int no_trees = !(git_iterator_flags(i) & GIT_ITERATOR_INCLUDE_TREES);
	bool v = false;
	int error;

	if (v) fprintf(stderr, "== %s ==\n", no_trees ? "notrees" : "trees");

	count = 0;

	while (!git_iterator_advance(&entry, i)) {
		if (v) fprintf(stderr, "  %s %07o\n", entry->path, (int)entry->mode);

		if (no_trees)
			cl_assert(entry->mode != GIT_FILEMODE_TREE);

		if (expected_flat_paths) {
			const char *expect_path = expected_flat_paths[count];
			size_t expect_len = strlen(expect_path);

			cl_assert_equal_s(expect_path, entry->path);

			if (expect_path[expect_len - 1] == '/')
				cl_assert_equal_i(GIT_FILEMODE_TREE, entry->mode);
			else
				cl_assert(entry->mode != GIT_FILEMODE_TREE);
		}

		cl_assert(++count <= expected_flat);
	}

	assert_at_end(i, v);
	cl_assert_equal_i(expected_flat, count);

	cl_git_pass(git_iterator_reset(i));

	count = 0;
	cl_git_pass(git_iterator_current(&entry, i));

	if (v) fprintf(stderr, "-- %s --\n", no_trees ? "notrees" : "trees");

	while (entry != NULL) {
		if (v) fprintf(stderr, "  %s %07o\n", entry->path, (int)entry->mode);

		if (no_trees)
			cl_assert(entry->mode != GIT_FILEMODE_TREE);

		if (expected_total_paths) {
			const char *expect_path = expected_total_paths[count];
			size_t expect_len = strlen(expect_path);

			cl_assert_equal_s(expect_path, entry->path);

			if (expect_path[expect_len - 1] == '/')
				cl_assert_equal_i(GIT_FILEMODE_TREE, entry->mode);
			else
				cl_assert(entry->mode != GIT_FILEMODE_TREE);
		}

		if (entry->mode == GIT_FILEMODE_TREE) {
			error = git_iterator_advance_into(&entry, i);

			/* could return NOTFOUND if directory is empty */
			cl_assert(!error || error == GIT_ENOTFOUND);

			if (error == GIT_ENOTFOUND) {
				error = git_iterator_advance(&entry, i);
				cl_assert(!error || error == GIT_ITEROVER);
			}
		} else {
			error = git_iterator_advance(&entry, i);
			cl_assert(!error || error == GIT_ITEROVER);
		}

		if (++count >= expected_total)
			break;
	}

	assert_at_end(i, v);
	cl_assert_equal_i(expected_total, count);
}

void expect_advance_over(
	git_iterator *i,
	const char *expected_path,
	git_iterator_status_t expected_status)
{
	const git_index_entry *entry;
	git_iterator_status_t status;
	int error;

	cl_git_pass(git_iterator_current(&entry, i));
	cl_assert_equal_s(expected_path, entry->path);

	error = git_iterator_advance_over(&entry, &status, i);
	cl_assert(!error || error == GIT_ITEROVER);
	cl_assert_equal_i(expected_status, status);
}

void expect_advance_into(
	git_iterator *i,
	const char *expected_path)
{
	const git_index_entry *entry;
	int error;

	cl_git_pass(git_iterator_current(&entry, i));
	cl_assert_equal_s(expected_path, entry->path);

	if (S_ISDIR(entry->mode))
		error = git_iterator_advance_into(&entry, i);
	else
		error = git_iterator_advance(&entry, i);

	cl_assert(!error || error == GIT_ITEROVER);
}

