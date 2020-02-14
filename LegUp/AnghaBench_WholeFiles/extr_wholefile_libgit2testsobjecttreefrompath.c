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
typedef  int /*<<< orphan*/  git_tree_entry ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_must_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_tree_entry_bypath (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_tree_entry_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_entry_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * repo ; 
 int /*<<< orphan*/ * tree ; 

void test_object_tree_frompath__initialize(void)
{
	git_oid id;
	const char *tree_with_subtrees_oid = "ae90f12eea699729ed24555e40b9fd669da12a12";

	cl_git_pass(git_repository_open(&repo, cl_fixture("testrepo.git")));
	cl_assert(repo != NULL);

	cl_git_pass(git_oid_fromstr(&id, tree_with_subtrees_oid));
	cl_git_pass(git_tree_lookup(&tree, repo, &id));
	cl_assert(tree != NULL);
}

void test_object_tree_frompath__cleanup(void)
{
	git_tree_free(tree);
	tree = NULL;

	git_repository_free(repo);
	repo = NULL;
}

__attribute__((used)) static void assert_tree_from_path(
	git_tree *root,
	const char *path,
	const char *expected_entry_name)
{
	git_tree_entry *entry;

	cl_git_pass(git_tree_entry_bypath(&entry, root, path));
	cl_assert_equal_s(git_tree_entry_name(entry), expected_entry_name);
	git_tree_entry_free(entry);
}

void test_object_tree_frompath__retrieve_tree_from_path_to_treeentry(void)
{
	git_tree_entry *e;

	assert_tree_from_path(tree, "README", "README");
	assert_tree_from_path(tree, "ab/de/fgh/1.txt", "1.txt");
	assert_tree_from_path(tree, "ab/de/fgh", "fgh");
	assert_tree_from_path(tree, "ab/de/fgh/", "fgh");
	assert_tree_from_path(tree, "ab/de", "de");
	assert_tree_from_path(tree, "ab/", "ab");
	assert_tree_from_path(tree, "ab/de/", "de");

	cl_assert_equal_i(GIT_ENOTFOUND, git_tree_entry_bypath(&e, tree, "i-do-not-exist.txt"));
	cl_assert_equal_i(GIT_ENOTFOUND, git_tree_entry_bypath(&e, tree, "README/"));
	cl_assert_equal_i(GIT_ENOTFOUND, git_tree_entry_bypath(&e, tree, "ab/de/fgh/i-do-not-exist.txt"));
	cl_assert_equal_i(GIT_ENOTFOUND, git_tree_entry_bypath(&e, tree, "nope/de/fgh/1.txt"));
	cl_assert_equal_i(GIT_ENOTFOUND, git_tree_entry_bypath(&e, tree, "ab/me-neither/fgh/2.txt"));
	cl_assert_equal_i(GIT_ENOTFOUND, git_tree_entry_bypath(&e, tree, "ab/me-neither/fgh/2.txt/"));
}

void test_object_tree_frompath__fail_when_processing_an_invalid_path(void)
{
	git_tree_entry *e;

	cl_must_fail(git_tree_entry_bypath(&e, tree, "/"));
	cl_must_fail(git_tree_entry_bypath(&e, tree, "/ab"));
	cl_must_fail(git_tree_entry_bypath(&e, tree, "/ab/de"));
	cl_must_fail(git_tree_entry_bypath(&e, tree, "ab//de"));
}

