#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_odb_backend ;
typedef  int /*<<< orphan*/  git_odb ;
struct TYPE_4__ {int /*<<< orphan*/  read_prefix_calls; int /*<<< orphan*/  read_calls; } ;
typedef  TYPE_1__ fake_backend ;

/* Variables and functions */
 int /*<<< orphan*/  EXISTING_HASH ; 
 int /*<<< orphan*/  GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION ; 
 int /*<<< orphan*/  _existing_oid ; 
 TYPE_1__* _fake_empty ; 
 TYPE_1__* _fake_filled ; 
 int /*<<< orphan*/ * _obj ; 
 int /*<<< orphan*/  _objects_empty ; 
 int /*<<< orphan*/  _objects_filled ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  build_fake_backend (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  git_libgit2_opts (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_odb_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read_prefix (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_odb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

void test_odb_backend_multiple__initialize(void)
{
	git_odb_backend *backend;

	git_oid_fromstr(&_existing_oid, EXISTING_HASH);

	_obj = NULL;
	_repo = cl_git_sandbox_init("testrepo.git");

	cl_git_pass(build_fake_backend(&backend, _objects_filled));
	_fake_filled = (fake_backend *)backend;

	cl_git_pass(build_fake_backend(&backend, _objects_empty));
	_fake_empty = (fake_backend *)backend;
}

void test_odb_backend_multiple__cleanup(void)
{
	git_odb_object_free(_obj);
	cl_git_sandbox_cleanup();
}

void test_odb_backend_multiple__read_with_empty_first_succeeds(void)
{
	git_odb *odb;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_filled, 10));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_empty, 50));

	cl_git_pass(git_odb_read(&_obj, odb, &_existing_oid));

	cl_assert_equal_i(1, _fake_filled->read_calls);
	cl_assert_equal_i(1, _fake_empty->read_calls);
}

void test_odb_backend_multiple__read_with_first_matching_stops(void)
{
	git_odb *odb;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_empty, 10));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_filled, 50));

	cl_git_pass(git_odb_read(&_obj, odb, &_existing_oid));

	cl_assert_equal_i(1, _fake_filled->read_calls);
	cl_assert_equal_i(0, _fake_empty->read_calls);
}

void test_odb_backend_multiple__read_prefix_with_first_empty_succeeds(void)
{
	git_odb *odb;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_filled, 10));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_empty, 50));

	cl_git_pass(git_odb_read_prefix(&_obj, odb, &_existing_oid, 7));

	cl_assert_equal_i(1, _fake_filled->read_prefix_calls);
	cl_assert_equal_i(1, _fake_empty->read_prefix_calls);
}

void test_odb_backend_multiple__read_prefix_with_first_matching_reads_both(void)
{
	git_odb *odb;

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_empty, -10));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_filled, 50));

	cl_git_pass(git_odb_read_prefix(&_obj, odb, &_existing_oid, 7));

	cl_assert_equal_i(1, _fake_filled->read_prefix_calls);
	cl_assert_equal_i(1, _fake_empty->read_prefix_calls);
}

void test_odb_backend_multiple__read_prefix_with_first_matching_succeeds_without_hash_verification(void)
{
	git_odb *odb;

	git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 0);

	cl_git_pass(git_repository_odb__weakptr(&odb, _repo));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_empty, -10));
	cl_git_pass(git_odb_add_backend(odb, (git_odb_backend *)_fake_filled, 50));

	cl_git_pass(git_odb_read_prefix(&_obj, odb, &_existing_oid, 7));

	/*
	 * Both backends should be checked as we have to check
	 * for collisions
	 */
	cl_assert_equal_i(1, _fake_filled->read_prefix_calls);
	cl_assert_equal_i(1, _fake_empty->read_prefix_calls);

	git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 1);
}

