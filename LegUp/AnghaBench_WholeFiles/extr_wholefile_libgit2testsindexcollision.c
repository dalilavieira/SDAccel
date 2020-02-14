#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_tree_entry ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_8__ {int seconds; } ;
struct TYPE_7__ {int seconds; } ;
struct TYPE_9__ {int mode; char* path; int /*<<< orphan*/  id; scalar_t__ file_size; TYPE_2__ mtime; TYPE_1__ ctime; scalar_t__ flags; } ;
typedef  TYPE_3__ git_index_entry ;
typedef  int /*<<< orphan*/  entry ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_INDEX_ENTRY_STAGE_SET (TYPE_3__*,int) ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  g_empty_id ; 
 int /*<<< orphan*/  g_index ; 
 int /*<<< orphan*/  g_odb ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_index_add (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_index_write_tree (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_odb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_tree_entry_bypath (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_tree_entry_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 

void test_index_collision__initialize(void)
{
	g_repo = cl_git_sandbox_init("empty_standard_repo");
	cl_git_pass(git_repository_odb(&g_odb, g_repo));
	cl_git_pass(git_repository_index(&g_index, g_repo));

	cl_git_pass(git_odb_write(&g_empty_id, g_odb, "", 0, GIT_OBJECT_BLOB));
}

void test_index_collision__cleanup(void)
{
	git_index_free(g_index);
	git_odb_free(g_odb);
	cl_git_sandbox_cleanup();
}

void test_index_collision__add_blob_with_conflicting_file(void)
{
	git_index_entry entry;
	git_tree_entry *tentry;
	git_oid tree_id;
	git_tree *tree;

	memset(&entry, 0, sizeof(entry));
	entry.ctime.seconds = 12346789;
	entry.mtime.seconds = 12346789;
	entry.mode  = 0100644;
	entry.file_size = 0;
	git_oid_cpy(&entry.id, &g_empty_id);

	entry.path = "a/b";
	cl_git_pass(git_index_add(g_index, &entry));

	/* Check a/b exists here */
	cl_git_pass(git_index_write_tree(&tree_id, g_index));
	cl_git_pass(git_tree_lookup(&tree, g_repo, &tree_id));
	cl_git_pass(git_tree_entry_bypath(&tentry, tree, "a/b"));
	git_tree_entry_free(tentry);
	git_tree_free(tree);

	/* create a tree/blob collision */
	entry.path = "a/b/c";
	cl_git_pass(git_index_add(g_index, &entry));

	/* a/b should now be a tree and a/b/c a blob */
	cl_git_pass(git_index_write_tree(&tree_id, g_index));
	cl_git_pass(git_tree_lookup(&tree, g_repo, &tree_id));
	cl_git_pass(git_tree_entry_bypath(&tentry, tree, "a/b/c"));
	git_tree_entry_free(tentry);
	git_tree_free(tree);
}

void test_index_collision__add_blob_with_conflicting_dir(void)
{
	git_index_entry entry;
	git_tree_entry *tentry;
	git_oid tree_id;
	git_tree *tree;

	memset(&entry, 0, sizeof(entry));
	entry.ctime.seconds = 12346789;
	entry.mtime.seconds = 12346789;
	entry.mode  = 0100644;
	entry.file_size = 0;
	git_oid_cpy(&entry.id, &g_empty_id);

	entry.path = "a/b/c";
	cl_git_pass(git_index_add(g_index, &entry));

	/* Check a/b/c exists here */
	cl_git_pass(git_index_write_tree(&tree_id, g_index));
	cl_git_pass(git_tree_lookup(&tree, g_repo, &tree_id));
	cl_git_pass(git_tree_entry_bypath(&tentry, tree, "a/b/c"));
	git_tree_entry_free(tentry);
	git_tree_free(tree);

	/* create a blob/tree collision */
	entry.path = "a/b";
	cl_git_pass(git_index_add(g_index, &entry));

	/* a/b should now be a tree and a/b/c a blob */
	cl_git_pass(git_index_write_tree(&tree_id, g_index));
	cl_git_pass(git_tree_lookup(&tree, g_repo, &tree_id));
	cl_git_pass(git_tree_entry_bypath(&tentry, tree, "a/b"));
	cl_git_fail(git_tree_entry_bypath(&tentry, tree, "a/b/c"));
	git_tree_entry_free(tentry);
	git_tree_free(tree);
}

void test_index_collision__add_with_highstage_1(void)
{
	git_index_entry entry;

	memset(&entry, 0, sizeof(entry));
	entry.ctime.seconds = 12346789;
	entry.mtime.seconds = 12346789;
	entry.mode  = 0100644;
	entry.file_size = 0;
	git_oid_cpy(&entry.id, &g_empty_id);

	entry.path = "a/b";
	GIT_INDEX_ENTRY_STAGE_SET(&entry, 2);
	cl_git_pass(git_index_add(g_index, &entry));

	/* create a blob beneath the previous tree entry */
	entry.path = "a/b/c";
	entry.flags = 0;
	cl_git_pass(git_index_add(g_index, &entry));

	/* create another tree entry above the blob */
	entry.path = "a/b";
	GIT_INDEX_ENTRY_STAGE_SET(&entry, 1);
	cl_git_pass(git_index_add(g_index, &entry));
}

void test_index_collision__add_with_highstage_2(void)
{
	git_index_entry entry;

	memset(&entry, 0, sizeof(entry));
	entry.ctime.seconds = 12346789;
	entry.mtime.seconds = 12346789;
	entry.mode  = 0100644;
	entry.file_size = 0;
	git_oid_cpy(&entry.id, &g_empty_id);

	entry.path = "a/b/c";
	GIT_INDEX_ENTRY_STAGE_SET(&entry, 1);
	cl_git_pass(git_index_add(g_index, &entry));

	/* create a blob beneath the previous tree entry */
	entry.path = "a/b/c";
	GIT_INDEX_ENTRY_STAGE_SET(&entry, 2);
	cl_git_pass(git_index_add(g_index, &entry));

	/* create another tree entry above the blob */
	entry.path = "a/b";
	GIT_INDEX_ENTRY_STAGE_SET(&entry, 3);
	cl_git_pass(git_index_add(g_index, &entry));
}

