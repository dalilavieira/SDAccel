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
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_object ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_OBJECT_ANY ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  GIT_OBJECT_TREE ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * g_actualobject ; 
 int /*<<< orphan*/ * g_expectedobject ; 
 scalar_t__ g_head_commit ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/ * g_root_tree ; 
 int /*<<< orphan*/  git_commit_free (scalar_t__) ; 
 int /*<<< orphan*/  git_commit_tree (int /*<<< orphan*/ **,scalar_t__) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_object_lookup_bypath (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_tree_entry_bypath (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_tree_entry_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_entry_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void test_object_lookupbypath__initialize(void)
{
	git_reference *head;
	git_tree_entry *tree_entry;

	cl_git_pass(git_repository_open(&g_repo, cl_fixture("attr/.gitted")));

	cl_git_pass(git_repository_head(&head, g_repo));
	cl_git_pass(git_reference_peel((git_object**)&g_head_commit, head, GIT_OBJECT_COMMIT));
	cl_git_pass(git_commit_tree(&g_root_tree, g_head_commit));
	cl_git_pass(git_tree_entry_bypath(&tree_entry, g_root_tree, "subdir/subdir_test2.txt"));
	cl_git_pass(git_object_lookup(&g_expectedobject, g_repo, git_tree_entry_id(tree_entry),
				GIT_OBJECT_ANY));

	git_tree_entry_free(tree_entry);
	git_reference_free(head);

	g_actualobject = NULL;
}

void test_object_lookupbypath__cleanup(void)
{
	git_object_free(g_actualobject);
	git_object_free(g_expectedobject);
	git_tree_free(g_root_tree);
	git_commit_free(g_head_commit);
	g_expectedobject = NULL;
	git_repository_free(g_repo);
	g_repo = NULL;
}

void test_object_lookupbypath__errors(void)
{
	cl_assert_equal_i(GIT_EINVALIDSPEC,
			git_object_lookup_bypath(&g_actualobject, (git_object*)g_root_tree,
				"subdir/subdir_test2.txt", GIT_OBJECT_TREE)); /* It's not a tree */
	cl_assert_equal_i(GIT_ENOTFOUND,
			git_object_lookup_bypath(&g_actualobject, (git_object*)g_root_tree,
				"file/doesnt/exist", GIT_OBJECT_ANY));
}

void test_object_lookupbypath__from_root_tree(void)
{
	cl_git_pass(git_object_lookup_bypath(&g_actualobject, (git_object*)g_root_tree,
				"subdir/subdir_test2.txt", GIT_OBJECT_BLOB));
	cl_assert_equal_oid(git_object_id(g_expectedobject),
		git_object_id(g_actualobject));
}

void test_object_lookupbypath__from_head_commit(void)
{
	cl_git_pass(git_object_lookup_bypath(&g_actualobject, (git_object*)g_head_commit,
				"subdir/subdir_test2.txt", GIT_OBJECT_BLOB));
	cl_assert_equal_oid(git_object_id(g_expectedobject),
				git_object_id(g_actualobject));
}

void test_object_lookupbypath__from_subdir_tree(void)
{
	git_tree_entry *entry = NULL;
	git_tree *tree = NULL;

	cl_git_pass(git_tree_entry_bypath(&entry, g_root_tree, "subdir"));
	cl_git_pass(git_tree_lookup(&tree, g_repo, git_tree_entry_id(entry)));

	cl_git_pass(git_object_lookup_bypath(&g_actualobject, (git_object*)tree,
				"subdir_test2.txt", GIT_OBJECT_BLOB));
	cl_assert_equal_oid(git_object_id(g_expectedobject),
				git_object_id(g_actualobject));

	git_tree_entry_free(entry);
	git_tree_free(tree);
}

