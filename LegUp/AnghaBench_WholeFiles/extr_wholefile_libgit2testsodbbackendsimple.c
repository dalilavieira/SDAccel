#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;
typedef  struct TYPE_17__   TYPE_14__ ;

/* Type definitions */
struct TYPE_18__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_19__ {TYPE_1__ member_0; } ;
typedef  TYPE_2__ git_oid ;
typedef  int /*<<< orphan*/  git_odb_object ;
typedef  int /*<<< orphan*/  git_odb_backend ;
struct TYPE_20__ {char* member_0; char* member_1; char* oid; char* content; } ;
typedef  TYPE_3__ fake_object ;
struct TYPE_17__ {int /*<<< orphan*/  message; } ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_EAMBIGUOUS ; 
 int /*<<< orphan*/  GIT_EMISMATCH ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION ; 
 int /*<<< orphan*/ * _obj ; 
 int /*<<< orphan*/ * _odb ; 
 TYPE_2__ _oid ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  build_fake_backend (int /*<<< orphan*/ **,TYPE_3__ const*) ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char const*) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 TYPE_14__* git_error_last () ; 
 int /*<<< orphan*/  git_libgit2_opts (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ git_odb_exists (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  git_odb_exists_prefix (TYPE_2__*,int /*<<< orphan*/ *,TYPE_2__*,int) ; 
 scalar_t__ git_odb_object_data (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read (int /*<<< orphan*/ **,int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  git_odb_read_prefix (int /*<<< orphan*/ **,int /*<<< orphan*/ *,TYPE_2__*,int) ; 
 int git_oid_equal (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  git_oid_fromstr (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  git_oid_fromstrn (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_odb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 scalar_t__ strstr (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void setup_backend(const fake_object *objs)
{
	git_odb_backend *backend;

	cl_git_pass(build_fake_backend(&backend, objs));

	cl_git_pass(git_repository_odb__weakptr(&_odb, _repo));
	cl_git_pass(git_odb_add_backend(_odb, backend, 10));
}

__attribute__((used)) static void assert_object_contains(git_odb_object *obj, const char *expected)
{
	const char *actual = (const char *) git_odb_object_data(obj);

	cl_assert_equal_s(actual, expected);
}

void test_odb_backend_simple__initialize(void)
{
	_repo = cl_git_sandbox_init("testrepo.git");
	_odb = NULL;
	_obj = NULL;
}

void test_odb_backend_simple__cleanup(void)
{
	git_odb_object_free(_obj);
	cl_git_sandbox_cleanup();
	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 1));
}

void test_odb_backend_simple__read_of_object_succeeds(void)
{
	const fake_object objs[] = {
		{ "f6ea0495187600e7b2288c8ac19c5886383a4632", "foobar" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_pass(git_odb_read(&_obj, _odb, &_oid));

	assert_object_contains(_obj, objs[0].content);
}

void test_odb_backend_simple__read_of_nonexisting_object_fails(void)
{
	const fake_object objs[] = {
		{ "f6ea0495187600e7b2288c8ac19c5886383a4632", "foobar" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, "f6ea0495187600e7b2288c8ac19c5886383a4633"));
	cl_git_fail_with(GIT_ENOTFOUND, git_odb_read(&_obj, _odb, &_oid));
}

void test_odb_backend_simple__read_with_hash_mismatch_fails(void)
{
	const fake_object objs[] = {
		{ "1234567890123456789012345678901234567890", "nonmatching content" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_fail_with(GIT_EMISMATCH, git_odb_read(&_obj, _odb, &_oid));
}

void test_odb_backend_simple__read_with_hash_mismatch_succeeds_without_verification(void)
{
	const fake_object objs[] = {
		{ "1234567890123456789012345678901234567890", "nonmatching content" },
		{ NULL, NULL }
	};

	setup_backend(objs);
	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));

	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 0));
	cl_git_pass(git_odb_read(&_obj, _odb, &_oid));

	assert_object_contains(_obj, objs[0].content);
}

void test_odb_backend_simple__read_prefix_succeeds(void)
{
	const fake_object objs[] = {
		{ "f6ea0495187600e7b2288c8ac19c5886383a4632", "foobar" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, "f6ea0495187600e7b2288c8ac19c5886383a4632"));
	cl_git_pass(git_odb_read(&_obj, _odb, &_oid));

	assert_object_contains(_obj, objs[0].content);
}

void test_odb_backend_simple__read_prefix_of_nonexisting_object_fails(void)
{
	const fake_object objs[] = {
		{ "f6ea0495187600e7b2288c8ac19c5886383a4632", "foobar" },
		{ NULL, NULL }
	};
	char *hash = "f6ea0495187600e8";

	setup_backend(objs);

	cl_git_pass(git_oid_fromstrn(&_oid, hash, strlen(hash)));
	cl_git_fail_with(GIT_ENOTFOUND, git_odb_read(&_obj, _odb, &_oid));
}

void test_odb_backend_simple__read_with_ambiguous_prefix_fails(void)
{
	const fake_object objs[] = {
		{ "1234567890111111111111111111111111111111", "first content" },
		{ "1234567890222222222222222222222222222222", "second content" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_fail_with(GIT_EAMBIGUOUS, git_odb_read_prefix(&_obj, _odb, &_oid, 7));
}

void test_odb_backend_simple__read_with_highly_ambiguous_prefix(void)
{
	const fake_object objs[] = {
		{ "1234567890111111111111111111111111111111", "first content" },
		{ "1234567890111111111111111111111111111112", "second content" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 0));
	cl_git_fail_with(GIT_EAMBIGUOUS, git_odb_read_prefix(&_obj, _odb, &_oid, 39));
	cl_git_pass(git_odb_read_prefix(&_obj, _odb, &_oid, 40));
	assert_object_contains(_obj, objs[0].content);
}

void test_odb_backend_simple__exists_succeeds(void)
{
	const fake_object objs[] = {
		{ "f6ea0495187600e7b2288c8ac19c5886383a4632", "foobar" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_assert(git_odb_exists(_odb, &_oid));
}

void test_odb_backend_simple__exists_fails_for_nonexisting_object(void)
{
	const fake_object objs[] = {
		{ "f6ea0495187600e7b2288c8ac19c5886383a4632", "foobar" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, "f6ea0495187600e7b2288c8ac19c5886383a4633"));
	cl_assert(git_odb_exists(_odb, &_oid) == 0);
}

void test_odb_backend_simple__exists_prefix_succeeds(void)
{
	const fake_object objs[] = {
		{ "1234567890111111111111111111111111111111", "first content" },
		{ "1234567890222222222222222222222222222222", "second content" },
		{ NULL, NULL }
	};
	git_oid found;

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_pass(git_odb_exists_prefix(&found, _odb, &_oid, 12));
	cl_assert(git_oid_equal(&found, &_oid));
}

void test_odb_backend_simple__exists_with_ambiguous_prefix_fails(void)
{
	const fake_object objs[] = {
		{ "1234567890111111111111111111111111111111", "first content" },
		{ "1234567890222222222222222222222222222222", "second content" },
		{ NULL, NULL }
	};

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_fail_with(GIT_EAMBIGUOUS, git_odb_exists_prefix(NULL, _odb, &_oid, 7));
}

void test_odb_backend_simple__exists_with_highly_ambiguous_prefix(void)
{
	const fake_object objs[] = {
		{ "1234567890111111111111111111111111111111", "first content" },
		{ "1234567890111111111111111111111111111112", "second content" },
		{ NULL, NULL }
	};
	git_oid found;

	setup_backend(objs);

	cl_git_pass(git_oid_fromstr(&_oid, objs[0].oid));
	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 0));
	cl_git_fail_with(GIT_EAMBIGUOUS, git_odb_exists_prefix(&found, _odb, &_oid, 39));
	cl_git_pass(git_odb_exists_prefix(&found, _odb, &_oid, 40));
	cl_assert(git_oid_equal(&found, &_oid));
}

void test_odb_backend_simple__null_oid_is_ignored(void)
{
	const fake_object objs[] = {
		{ "0000000000000000000000000000000000000000", "null oid content" },
		{ NULL, NULL }
	};
	git_oid null_oid = {{0}};
	git_odb_object *obj;

	setup_backend(objs);

	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, 0));
	cl_assert(!git_odb_exists(_odb, &null_oid));

	cl_git_fail_with(GIT_ENOTFOUND, git_odb_read(&obj, _odb, &null_oid));
	cl_assert(git_error_last() && strstr(git_error_last()->message, "null OID"));
}

