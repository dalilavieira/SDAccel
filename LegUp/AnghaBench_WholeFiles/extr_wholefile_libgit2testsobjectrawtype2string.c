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

/* Variables and functions */
 int GIT_OBJECT_BLOB ; 
 int GIT_OBJECT_COMMIT ; 
 int GIT_OBJECT_INVALID ; 
 int GIT_OBJECT_OFS_DELTA ; 
 int GIT_OBJECT_REF_DELTA ; 
 int GIT_OBJECT_TAG ; 
 int GIT_OBJECT_TREE ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char*) ; 
 int git_object_string2type (char*) ; 
 int /*<<< orphan*/  git_object_type2string (int) ; 
 int git_object_typeisloose (int) ; 

void test_object_raw_type2string__convert_type_to_string(void)
{
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_INVALID), "");
	cl_assert_equal_s(git_object_type2string(0), ""); /* EXT1 */
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_COMMIT), "commit");
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_TREE), "tree");
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_BLOB), "blob");
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_TAG), "tag");
	cl_assert_equal_s(git_object_type2string(5), ""); /* EXT2 */
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_OFS_DELTA), "OFS_DELTA");
	cl_assert_equal_s(git_object_type2string(GIT_OBJECT_REF_DELTA), "REF_DELTA");

	cl_assert_equal_s(git_object_type2string(-2), "");
	cl_assert_equal_s(git_object_type2string(8), "");
	cl_assert_equal_s(git_object_type2string(1234), "");
}

void test_object_raw_type2string__convert_string_to_type(void)
{
	cl_assert(git_object_string2type(NULL) == GIT_OBJECT_INVALID);
	cl_assert(git_object_string2type("") == GIT_OBJECT_INVALID);
	cl_assert(git_object_string2type("commit") == GIT_OBJECT_COMMIT);
	cl_assert(git_object_string2type("tree") == GIT_OBJECT_TREE);
	cl_assert(git_object_string2type("blob") == GIT_OBJECT_BLOB);
	cl_assert(git_object_string2type("tag") == GIT_OBJECT_TAG);
	cl_assert(git_object_string2type("OFS_DELTA") == GIT_OBJECT_OFS_DELTA);
	cl_assert(git_object_string2type("REF_DELTA") == GIT_OBJECT_REF_DELTA);

	cl_assert(git_object_string2type("CoMmIt") == GIT_OBJECT_INVALID);
	cl_assert(git_object_string2type("hohoho") == GIT_OBJECT_INVALID);
}

void test_object_raw_type2string__check_type_is_loose(void)
{
	cl_assert(git_object_typeisloose(GIT_OBJECT_INVALID) == 0);
	cl_assert(git_object_typeisloose(0) == 0); /* EXT1 */
	cl_assert(git_object_typeisloose(GIT_OBJECT_COMMIT) == 1);
	cl_assert(git_object_typeisloose(GIT_OBJECT_TREE) == 1);
	cl_assert(git_object_typeisloose(GIT_OBJECT_BLOB) == 1);
	cl_assert(git_object_typeisloose(GIT_OBJECT_TAG) == 1);
	cl_assert(git_object_typeisloose(5) == 0); /* EXT2 */
	cl_assert(git_object_typeisloose(GIT_OBJECT_OFS_DELTA) == 0);
	cl_assert(git_object_typeisloose(GIT_OBJECT_REF_DELTA) == 0);

	cl_assert(git_object_typeisloose(-2) == 0);
	cl_assert(git_object_typeisloose(8) == 0);
	cl_assert(git_object_typeisloose(1234) == 0);
}

