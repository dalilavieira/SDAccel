#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_odb_backend ;
typedef  int /*<<< orphan*/  git_odb ;
typedef  int /*<<< orphan*/  git_object_t ;
typedef  int /*<<< orphan*/  git_object ;
struct TYPE_3__ {int /*<<< orphan*/  read_calls; int /*<<< orphan*/  read_header_calls; int /*<<< orphan*/  read_prefix_calls; int /*<<< orphan*/  exists_calls; } ;
typedef  TYPE_1__ fake_backend ;

/* Variables and functions */
 int /*<<< orphan*/  EXISTING_HASH ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_OBJECT_ANY ; 
 int /*<<< orphan*/  NONEXISTING_HASH ; 
 int /*<<< orphan*/  _existing_oid ; 
 TYPE_1__* _fake ; 
 int /*<<< orphan*/  _nonexisting_oid ; 
 int /*<<< orphan*/  _objects ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  build_fake_backend (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_b (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_object_lookup_prefix (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_odb_exists (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read_header (size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_odb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void setup_repository_and_backend(void)
{
	git_odb *odb = NULL;
	git_odb_backend *backend = NULL;

	_repo = cl_git_sandbox_init("testrepo.git");

	cl_git_pass(build_fake_backend(&backend, _objects));

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_git_pass(git_odb_add_backend(odb, backend, 10));

	_fake = (fake_backend *)backend;
}

void test_odb_backend_nonrefreshing__initialize(void)
{
	git_oid_fromstr(&_nonexisting_oid, NONEXISTING_HASH);
	git_oid_fromstr(&_existing_oid, EXISTING_HASH);
	setup_repository_and_backend();
}

void test_odb_backend_nonrefreshing__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_odb_backend_nonrefreshing__exists_is_invoked_once_on_failure(void)
{
	git_odb *odb;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_assert_equal_b(false, git_odb_exists(odb, &_nonexisting_oid));

	cl_assert_equal_i(1, _fake->exists_calls);
}

void test_odb_backend_nonrefreshing__read_is_invoked_once_on_failure(void)
{
	git_object *obj;

	cl_git_fail_with(
		git_object_lookup(&obj, _repo, &_nonexisting_oid, GIT_OBJECT_ANY),
		GIT_ENOTFOUND);

	cl_assert_equal_i(1, _fake->read_calls);
}

void test_odb_backend_nonrefreshing__readprefix_is_invoked_once_on_failure(void)
{
	git_object *obj;

	cl_git_fail_with(
		git_object_lookup_prefix(&obj, _repo, &_nonexisting_oid, 7, GIT_OBJECT_ANY),
		GIT_ENOTFOUND);

	cl_assert_equal_i(1, _fake->read_prefix_calls);
}

void test_odb_backend_nonrefreshing__readheader_is_invoked_once_on_failure(void)
{
	git_odb *odb;
	size_t len;
	git_object_t type;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));

	cl_git_fail_with(
		git_odb_read_header(&len, &type, odb, &_nonexisting_oid),
		GIT_ENOTFOUND);

	cl_assert_equal_i(1, _fake->read_header_calls);
}

void test_odb_backend_nonrefreshing__exists_is_invoked_once_on_success(void)
{
	git_odb *odb;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_assert_equal_b(true, git_odb_exists(odb, &_existing_oid));

	cl_assert_equal_i(1, _fake->exists_calls);
}

void test_odb_backend_nonrefreshing__read_is_invoked_once_on_success(void)
{
	git_object *obj;

	cl_git_pass(git_object_lookup(&obj, _repo, &_existing_oid, GIT_OBJECT_ANY));

	cl_assert_equal_i(1, _fake->read_calls);

	git_object_free(obj);
}

void test_odb_backend_nonrefreshing__readprefix_is_invoked_once_on_success(void)
{
	git_object *obj;

	cl_git_pass(git_object_lookup_prefix(&obj, _repo, &_existing_oid, 7, GIT_OBJECT_ANY));

	cl_assert_equal_i(1, _fake->read_prefix_calls);

	git_object_free(obj);
}

void test_odb_backend_nonrefreshing__readheader_is_invoked_once_on_success(void)
{
	git_odb *odb;
	size_t len;
	git_object_t type;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));

	cl_git_pass(git_odb_read_header(&len, &type, odb, &_existing_oid));

	cl_assert_equal_i(1, _fake->read_header_calls);
}

void test_odb_backend_nonrefreshing__read_is_invoked_once_when_revparsing_a_full_oid(void)
{
	git_object *obj;

	cl_git_fail_with(
		git_revparse_single(&obj, _repo, "deadbeefdeadbeefdeadbeefdeadbeefdeadbeef"),
		GIT_ENOTFOUND);

	cl_assert_equal_i(1, _fake->read_calls);
}

