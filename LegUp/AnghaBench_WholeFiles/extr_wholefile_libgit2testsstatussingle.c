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
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_mkfile (char const*,char const*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_set_cleanup (void (*) (void*),void*) ; 
 int /*<<< orphan*/  git_odb_hashfile (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  p_unlink (char*) ; 

__attribute__((used)) static void
cleanup__remove_file(void *_file)
{
	cl_must_pass(p_unlink((char *)_file));
}

void test_status_single__hash_single_file(void)
{
	static const char file_name[] = "new_file";
	static const char file_contents[] = "new_file\n";
	static const char file_hash[] = "d4fa8600b4f37d7516bef4816ae2c64dbf029e3a";

	git_oid expected_id, actual_id;

	/* initialization */
	git_oid_fromstr(&expected_id, file_hash);
	cl_git_mkfile(file_name, file_contents);
	cl_set_cleanup(&cleanup__remove_file, (void *)file_name);

	cl_git_pass(git_odb_hashfile(&actual_id, file_name, GIT_OBJECT_BLOB));
	cl_assert_equal_oid(&expected_id, &actual_id);
}

void test_status_single__hash_single_empty_file(void)
{
	static const char file_name[] = "new_empty_file";
	static const char file_contents[] = "";
	static const char file_hash[] = "e69de29bb2d1d6434b8b29ae775ad8c2e48c5391";

	git_oid expected_id, actual_id;

	/* initialization */
	git_oid_fromstr(&expected_id, file_hash);
	cl_git_mkfile(file_name, file_contents);
	cl_set_cleanup(&cleanup__remove_file, (void *)file_name);

	cl_git_pass(git_odb_hashfile(&actual_id, file_name, GIT_OBJECT_BLOB));
	cl_assert_equal_oid(&expected_id, &actual_id);
}

