#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_odb_backend ;
typedef  int /*<<< orphan*/  git_odb ;
struct TYPE_5__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * _odb ; 
 int /*<<< orphan*/ * _repo ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 char* cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_mkfile (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int git_buf_printf (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int git_odb_backend_one_pack (int /*<<< orphan*/ **,char*) ; 
 int git_odb_foreach (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/  const*,void*),int*) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int git_odb_new (int /*<<< orphan*/ **) ; 
 int git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int git_repository_init (int /*<<< orphan*/ **,char*,int) ; 
 int git_repository_odb (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int git_repository_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ *) ; 

void test_odb_foreach__cleanup(void)
{
	git_odb_free(_odb);
	git_repository_free(_repo);

	_odb = NULL;
	_repo = NULL;
}

__attribute__((used)) static int foreach_cb(const git_oid *oid, void *data)
{
	int *nobj = data;
	(*nobj)++;

	GIT_UNUSED(oid);

	return 0;
}

void test_odb_foreach__foreach(void)
{
	int nobj = 0;

	cl_git_pass(git_repository_open(&_repo, cl_fixture("testrepo.git")));
	git_repository_odb(&_odb, _repo);

	cl_git_pass(git_odb_foreach(_odb, foreach_cb, &nobj));
	cl_assert_equal_i(60 + 1640, nobj); /* count + in-pack */
}

void test_odb_foreach__one_pack(void)
{
	git_odb_backend *backend = NULL;
	int nobj = 0;

	cl_git_pass(git_odb_new(&_odb));
	cl_git_pass(git_odb_backend_one_pack(&backend, cl_fixture("testrepo.git/objects/pack/pack-a81e489679b7d3418f9ab594bda8ceb37dd4c695.idx")));
	cl_git_pass(git_odb_add_backend(_odb, backend, 1));
	_repo = NULL;

	cl_git_pass(git_odb_foreach(_odb, foreach_cb, &nobj));
	cl_assert(nobj == 1628);
}

__attribute__((used)) static int foreach_stop_cb(const git_oid *oid, void *data)
{
	int *nobj = data;
	(*nobj)++;

	GIT_UNUSED(oid);

	return (*nobj == 1000) ? -321 : 0;
}

__attribute__((used)) static int foreach_stop_first_cb(const git_oid *oid, void *data)
{
	int *nobj = data;
	(*nobj)++;

	GIT_UNUSED(oid);

	return -123;
}

__attribute__((used)) static int foreach_stop_cb_positive_ret(const git_oid *oid, void *data)
{
	int *nobj = data;
	(*nobj)++;

	GIT_UNUSED(oid);

	return (*nobj == 1000) ? 321 : 0;
}

void test_odb_foreach__interrupt_foreach(void)
{
	int nobj = 0;
	git_oid id;

	cl_git_pass(git_repository_open(&_repo, cl_fixture("testrepo.git")));
	git_repository_odb(&_odb, _repo);

	cl_assert_equal_i(-321, git_odb_foreach(_odb, foreach_stop_cb, &nobj));
	cl_assert(nobj == 1000);

	nobj = 0;

	cl_assert_equal_i(321, git_odb_foreach(_odb, foreach_stop_cb_positive_ret, &nobj));
	cl_assert(nobj == 1000);

	git_odb_free(_odb);
	git_repository_free(_repo);

	cl_git_pass(git_repository_init(&_repo, "onlyloose.git", true));
	git_repository_odb(&_odb, _repo);

	cl_git_pass(git_odb_write(&id, _odb, "", 0, GIT_OBJECT_BLOB));
	cl_assert_equal_i(-123, git_odb_foreach(_odb, foreach_stop_first_cb, &nobj));
}

void test_odb_foreach__files_in_objects_dir(void)
{
	git_repository *repo;
	git_odb *odb;
	git_buf buf = GIT_BUF_INIT;
	int nobj = 0;

	cl_fixture_sandbox("testrepo.git");
	cl_git_pass(git_repository_open(&repo, "testrepo.git"));

	cl_git_pass(git_buf_printf(&buf, "%s/objects/somefile", git_repository_path(repo)));
	cl_git_mkfile(buf.ptr, "");
	git_buf_dispose(&buf);

	cl_git_pass(git_repository_odb(&odb, repo));
	cl_git_pass(git_odb_foreach(odb, foreach_cb, &nobj));
	cl_assert_equal_i(60 + 1640, nobj); /* count + in-pack */

	git_odb_free(odb);
	git_repository_free(repo);
	cl_fixture_cleanup("testrepo.git");
}

