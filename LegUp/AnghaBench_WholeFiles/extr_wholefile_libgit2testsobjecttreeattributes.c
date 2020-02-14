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
typedef  int /*<<< orphan*/  git_treebuilder ;
typedef  int /*<<< orphan*/  git_tree_entry ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_filemode_t ;

/* Variables and functions */
 int GIT_FILEMODE_BLOB ; 
 int /*<<< orphan*/  GIT_FILEMODE_BLOB_GROUP_WRITABLE ; 
 char* blob_oid ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * git_tree_entry_byname (int /*<<< orphan*/ *,char*) ; 
 int git_tree_entry_filemode (int /*<<< orphan*/  const*) ; 
 int git_tree_entry_filemode_raw (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_treebuilder_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_treebuilder_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_treebuilder_insert (int /*<<< orphan*/  const**,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_treebuilder_new (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_treebuilder_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  repo ; 
 char* tree_oid ; 

void test_object_tree_attributes__initialize(void)
{
	repo = cl_git_sandbox_init("deprecated-mode.git");
}

void test_object_tree_attributes__cleanup(void)
{
   cl_git_sandbox_cleanup();
}

void test_object_tree_attributes__ensure_correctness_of_attributes_on_insertion(void)
{
	git_treebuilder *builder;
	git_oid oid;

	cl_git_pass(git_oid_fromstr(&oid, blob_oid));

	cl_git_pass(git_treebuilder_new(&builder, repo, NULL));

	cl_git_fail(git_treebuilder_insert(NULL, builder, "one.txt", &oid, (git_filemode_t)0777777));
	cl_git_fail(git_treebuilder_insert(NULL, builder, "one.txt", &oid, (git_filemode_t)0100666));
	cl_git_fail(git_treebuilder_insert(NULL, builder, "one.txt", &oid, (git_filemode_t)0000001));

	git_treebuilder_free(builder);
}

void test_object_tree_attributes__group_writable_tree_entries_created_with_an_antique_git_version_can_still_be_accessed(void)
{
	git_oid tid;
	git_tree *tree;
	const git_tree_entry *entry;


	cl_git_pass(git_oid_fromstr(&tid, tree_oid));
	cl_git_pass(git_tree_lookup(&tree, repo, &tid));

	entry = git_tree_entry_byname(tree, "old_mode.txt");
	cl_assert_equal_i(
		GIT_FILEMODE_BLOB,
		git_tree_entry_filemode(entry));

	git_tree_free(tree);
}

void test_object_tree_attributes__treebuilder_reject_invalid_filemode(void)
{
	git_treebuilder *builder;
	git_oid bid;
	const git_tree_entry *entry;

	cl_git_pass(git_oid_fromstr(&bid, blob_oid));
	cl_git_pass(git_treebuilder_new(&builder, repo, NULL));

	cl_git_fail(git_treebuilder_insert(
		&entry,
		builder,
		"normalized.txt",
		&bid,
		GIT_FILEMODE_BLOB_GROUP_WRITABLE));

	git_treebuilder_free(builder);
}

void test_object_tree_attributes__normalize_attributes_when_creating_a_tree_from_an_existing_one(void)
{
	git_treebuilder *builder;
	git_oid tid, tid2;
	git_tree *tree;
	const git_tree_entry *entry;

	cl_git_pass(git_oid_fromstr(&tid, tree_oid));
	cl_git_pass(git_tree_lookup(&tree, repo, &tid));

	cl_git_pass(git_treebuilder_new(&builder, repo, tree));
	
	entry = git_treebuilder_get(builder, "old_mode.txt");
	cl_assert(entry != NULL);
	cl_assert_equal_i(
		GIT_FILEMODE_BLOB,
		git_tree_entry_filemode(entry));

	cl_git_pass(git_treebuilder_write(&tid2, builder));
	git_treebuilder_free(builder);
	git_tree_free(tree);

	cl_git_pass(git_tree_lookup(&tree, repo, &tid2));
	entry = git_tree_entry_byname(tree, "old_mode.txt");
	cl_assert(entry != NULL);
	cl_assert_equal_i(
		GIT_FILEMODE_BLOB,
		git_tree_entry_filemode(entry));

	git_tree_free(tree);
}

void test_object_tree_attributes__normalize_600(void)
{
	git_oid id;
	git_tree *tree;
	const git_tree_entry *entry;

	git_oid_fromstr(&id, "0810fb7818088ff5ac41ee49199b51473b1bd6c7");
	cl_git_pass(git_tree_lookup(&tree, repo, &id));

	entry = git_tree_entry_byname(tree, "ListaTeste.xml");
	cl_assert_equal_i(git_tree_entry_filemode(entry), GIT_FILEMODE_BLOB);
	cl_assert_equal_i(git_tree_entry_filemode_raw(entry), 0100600);

	git_tree_free(tree);
}

