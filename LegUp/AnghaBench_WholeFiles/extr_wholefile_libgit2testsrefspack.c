#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  name ;
struct TYPE_12__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ git_reference ;
typedef  int /*<<< orphan*/  git_refdb ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_13__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_2__ git_buf ;

/* Variables and functions */
 TYPE_2__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_PACKEDREFS_FILE ; 
 int /*<<< orphan*/  GIT_REFS_DIR_MODE ; 
 int /*<<< orphan*/  GIT_REFS_HEADS_DIR ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_2__*) ; 
 int /*<<< orphan*/  git_buf_join_n (TYPE_2__*,char,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_futils_mkdir_r (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int git_path_exists (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_refdb_compress (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_refdb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_create (TYPE_1__**,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_reference_lookup (TYPE_1__**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_name_to_id (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_reference_symbolic_create (TYPE_1__**,int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_refdb (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  loose_tag_ref_name ; 
 int /*<<< orphan*/  p_snprintf (char*,int,char*,int) ; 
 int reference_is_packed (TYPE_1__*) ; 

void test_refs_pack__initialize(void)
{
   g_repo = cl_git_sandbox_init("testrepo");
}

void test_refs_pack__cleanup(void)
{
   cl_git_sandbox_cleanup();
}

__attribute__((used)) static void packall(void)
{
	git_refdb *refdb;

	cl_git_pass(git_repository_refdb(&refdb, g_repo));
	cl_git_pass(git_refdb_compress(refdb));
	git_refdb_free(refdb);
}

void test_refs_pack__empty(void)
{
	/* create a packfile for an empty folder */
	git_buf temp_path = GIT_BUF_INIT;

	cl_git_pass(git_buf_join_n(&temp_path, '/', 3, git_repository_path(g_repo), GIT_REFS_HEADS_DIR, "empty_dir"));
	cl_git_pass(git_futils_mkdir_r(temp_path.ptr, GIT_REFS_DIR_MODE));
	git_buf_dispose(&temp_path);

	packall();
}

void test_refs_pack__loose(void)
{
	/* create a packfile from all the loose refs in a repo */
	git_reference *reference;
	git_buf temp_path = GIT_BUF_INIT;

	/* Ensure a known loose ref can be looked up */
	cl_git_pass(git_reference_lookup(&reference, g_repo, loose_tag_ref_name));
	cl_assert(reference_is_packed(reference) == 0);
	cl_assert_equal_s(reference->name, loose_tag_ref_name);
	git_reference_free(reference);

	/*
	 * We are now trying to pack also a loose reference
	 * called `points_to_blob`, to make sure we can properly
	 * pack weak tags
	 */
	packall();

	/* Ensure the packed-refs file exists */
	cl_git_pass(git_buf_joinpath(&temp_path, git_repository_path(g_repo), GIT_PACKEDREFS_FILE));
	cl_assert(git_path_exists(temp_path.ptr));

	/* Ensure the known ref can still be looked up but is now packed */
	cl_git_pass(git_reference_lookup(&reference, g_repo, loose_tag_ref_name));
	cl_assert(reference_is_packed(reference));
	cl_assert_equal_s(reference->name, loose_tag_ref_name);

	/* Ensure the known ref has been removed from the loose folder structure */
	cl_git_pass(git_buf_joinpath(&temp_path, git_repository_path(g_repo), loose_tag_ref_name));
	cl_assert(!git_path_exists(temp_path.ptr));

	git_reference_free(reference);
	git_buf_dispose(&temp_path);
}

void test_refs_pack__symbolic(void)
{
	/* create a packfile from loose refs skipping symbolic refs */
	int i;
	git_oid head;
	git_reference *ref;
	char name[128];

	cl_git_pass(git_reference_name_to_id(&head, g_repo, "HEAD"));

	/* make a bunch of references */

	for (i = 0; i < 100; ++i) {
		p_snprintf(name, sizeof(name), "refs/heads/symbolic-%03d", i);
		cl_git_pass(git_reference_symbolic_create(
			&ref, g_repo, name, "refs/heads/master", 0, NULL));
		git_reference_free(ref);

		p_snprintf(name, sizeof(name), "refs/heads/direct-%03d", i);
		cl_git_pass(git_reference_create(&ref, g_repo, name, &head, 0, NULL));
		git_reference_free(ref);
	}

	packall();
}

