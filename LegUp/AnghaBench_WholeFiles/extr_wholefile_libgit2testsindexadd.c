#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_5__ {char* path; scalar_t__ mode; int /*<<< orphan*/  id; TYPE_1__ member_0; } ;
typedef  TYPE_2__ git_index_entry ;
typedef  scalar_t__ git_filemode_t ;

/* Variables and functions */
 scalar_t__ GIT_FILEMODE_BLOB ; 
 scalar_t__ GIT_FILEMODE_BLOB_EXECUTABLE ; 
 scalar_t__ GIT_FILEMODE_LINK ; 
 scalar_t__ GIT_FILEMODE_TREE ; 
 int /*<<< orphan*/  GIT_OPT_ENABLE_STRICT_OBJECT_CREATION ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  g_index ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_index_add (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_libgit2_opts (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* invalid_id ; 
 char* valid_blob_id ; 
 char* valid_commit_id ; 
 char* valid_tree_id ; 

void test_index_add__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo");
	cl_git_pass(git_repository_index(&g_index, g_repo));
}

void test_index_add__cleanup(void)
{
	git_index_free(g_index);
	cl_git_sandbox_cleanup();
	g_repo = NULL;

	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_OBJECT_CREATION, 1));
}

__attribute__((used)) static void test_add_entry(
	bool should_succeed, const char *idstr, git_filemode_t mode)
{
	git_index_entry entry = {{0}};

	cl_git_pass(git_oid_fromstr(&entry.id, idstr));

	entry.path = mode == GIT_FILEMODE_TREE ? "test_folder" : "test_file";
	entry.mode = mode;

	if (should_succeed)
		cl_git_pass(git_index_add(g_index, &entry));
	else
		cl_git_fail(git_index_add(g_index, &entry));
}

void test_index_add__invalid_entries_succeeds_by_default(void)
{
	/*
	 * Ensure that there is validation on object ids by default
	 */

	/* ensure that we can add some actually good entries */
	test_add_entry(true, valid_blob_id, GIT_FILEMODE_BLOB);
	test_add_entry(true, valid_blob_id, GIT_FILEMODE_BLOB_EXECUTABLE);
	test_add_entry(true, valid_blob_id, GIT_FILEMODE_LINK);

	/* test that we fail to add some invalid (missing) blobs and trees */
	test_add_entry(false, invalid_id, GIT_FILEMODE_BLOB);
	test_add_entry(false, invalid_id, GIT_FILEMODE_BLOB_EXECUTABLE);
	test_add_entry(false, invalid_id, GIT_FILEMODE_LINK);

	/* test that we validate the types of objects */
	test_add_entry(false, valid_commit_id, GIT_FILEMODE_BLOB);
	test_add_entry(false, valid_tree_id, GIT_FILEMODE_BLOB_EXECUTABLE);
	test_add_entry(false, valid_commit_id, GIT_FILEMODE_LINK);

	/*
	 * Ensure that there we can disable validation
	 */

	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_OBJECT_CREATION, 0));

	/* ensure that we can add some actually good entries */
	test_add_entry(true, valid_blob_id, GIT_FILEMODE_BLOB);
	test_add_entry(true, valid_blob_id, GIT_FILEMODE_BLOB_EXECUTABLE);
	test_add_entry(true, valid_blob_id, GIT_FILEMODE_LINK);

	/* test that we can now add some invalid (missing) blobs and trees */
	test_add_entry(true, invalid_id, GIT_FILEMODE_BLOB);
	test_add_entry(true, invalid_id, GIT_FILEMODE_BLOB_EXECUTABLE);
	test_add_entry(true, invalid_id, GIT_FILEMODE_LINK);

	/* test that we do not validate the types of objects */
	test_add_entry(true, valid_commit_id, GIT_FILEMODE_BLOB);
	test_add_entry(true, valid_tree_id, GIT_FILEMODE_BLOB_EXECUTABLE);
	test_add_entry(true, valid_commit_id, GIT_FILEMODE_LINK);
}

