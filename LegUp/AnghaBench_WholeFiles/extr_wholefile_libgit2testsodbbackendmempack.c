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
typedef  int /*<<< orphan*/  git_odb_backend ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  _obj ; 
 int /*<<< orphan*/  _odb ; 
 int /*<<< orphan*/  _oid ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_blob_create_frombuffer (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,scalar_t__) ; 
 int /*<<< orphan*/  git_mempack_new (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  git_odb_add_backend (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int git_odb_exists (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_object_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_wrap_odb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ strlen (char const*) ; 

void test_odb_backend_mempack__initialize(void)
{
	git_odb_backend *backend;

	cl_git_pass(git_mempack_new(&backend));
	cl_git_pass(git_odb_new(&_odb));
	cl_git_pass(git_odb_add_backend(_odb, backend, 10));
	cl_git_pass(git_repository_wrap_odb(&_repo, _odb));
}

void test_odb_backend_mempack__cleanup(void)
{
	git_odb_object_free(_obj);
	git_odb_free(_odb);
	git_repository_free(_repo);
}

void test_odb_backend_mempack__write_succeeds(void)
{
	const char *data = "data";
	cl_git_pass(git_odb_write(&_oid, _odb, data, strlen(data) + 1, GIT_OBJECT_BLOB));
	cl_git_pass(git_odb_read(&_obj, _odb, &_oid));
}

void test_odb_backend_mempack__read_of_missing_object_fails(void)
{
	cl_git_pass(git_oid_fromstr(&_oid, "f6ea0495187600e7b2288c8ac19c5886383a4633"));
	cl_git_fail_with(GIT_ENOTFOUND, git_odb_read(&_obj, _odb, &_oid));
}

void test_odb_backend_mempack__exists_of_missing_object_fails(void)
{
	cl_git_pass(git_oid_fromstr(&_oid, "f6ea0495187600e7b2288c8ac19c5886383a4633"));
	cl_assert(git_odb_exists(_odb, &_oid) == 0);
}

void test_odb_backend_mempack__exists_with_existing_objects_succeeds(void)
{
	const char *data = "data";
	cl_git_pass(git_odb_write(&_oid, _odb, data, strlen(data) + 1, GIT_OBJECT_BLOB));
	cl_assert(git_odb_exists(_odb, &_oid) == 1);
}

void test_odb_backend_mempack__blob_create_frombuffer_succeeds(void)
{
	const char *data = "data";

	cl_git_pass(git_blob_create_frombuffer(&_oid, _repo, data, strlen(data) + 1));
	cl_assert(git_odb_exists(_odb, &_oid) == 1);
}

