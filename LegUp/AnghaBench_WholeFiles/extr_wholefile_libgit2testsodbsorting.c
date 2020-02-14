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
typedef  int /*<<< orphan*/  git_odb_backend ;
typedef  int /*<<< orphan*/  git_odb ;
struct TYPE_4__ {void (* free ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  version; } ;
struct TYPE_5__ {size_t position; TYPE_1__ base; } ;
typedef  TYPE_2__ fake_backend ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ODB_BACKEND_VERSION ; 
 int /*<<< orphan*/ * _odb ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (size_t,size_t) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 TYPE_2__* git__calloc (int,int) ; 
 scalar_t__ git__free ; 
 int /*<<< orphan*/  git_odb_add_alternate (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_get_backend (int /*<<< orphan*/ **,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  git_odb_new (int /*<<< orphan*/ **) ; 
 size_t git_odb_num_backends (int /*<<< orphan*/ *) ; 

__attribute__((used)) static git_odb_backend *new_backend(size_t position)
{
	fake_backend *b;

	b = git__calloc(1, sizeof(fake_backend));
	if (b == NULL)
		return NULL;

	b->base.free = (void (*)(git_odb_backend *)) git__free;
	b->base.version = GIT_ODB_BACKEND_VERSION;
	b->position = position;
	return (git_odb_backend *)b;
}

__attribute__((used)) static void check_backend_sorting(git_odb *odb)
{
	size_t i, max_i = git_odb_num_backends(odb);
	fake_backend *internal;

	for (i = 0; i < max_i; ++i) {
		cl_git_pass(git_odb_get_backend((git_odb_backend **)&internal, odb, i));
		cl_assert(internal != NULL);
		cl_assert_equal_sz(i, internal->position);
	}
}

void test_odb_sorting__initialize(void)
{
	cl_git_pass(git_odb_new(&_odb));
}

void test_odb_sorting__cleanup(void)
{
	git_odb_free(_odb);
	_odb = NULL;
}

void test_odb_sorting__basic_backends_sorting(void)
{
	cl_git_pass(git_odb_add_backend(_odb, new_backend(0), 5));
	cl_git_pass(git_odb_add_backend(_odb, new_backend(2), 3));
	cl_git_pass(git_odb_add_backend(_odb, new_backend(1), 4));
	cl_git_pass(git_odb_add_backend(_odb, new_backend(3), 1));

	check_backend_sorting(_odb);
}

void test_odb_sorting__alternate_backends_sorting(void)
{
	cl_git_pass(git_odb_add_backend(_odb, new_backend(1), 5));
	cl_git_pass(git_odb_add_backend(_odb, new_backend(5), 3));
	cl_git_pass(git_odb_add_backend(_odb, new_backend(3), 4));
	cl_git_pass(git_odb_add_backend(_odb, new_backend(7), 1));
	cl_git_pass(git_odb_add_alternate(_odb, new_backend(0), 5));
	cl_git_pass(git_odb_add_alternate(_odb, new_backend(4), 3));
	cl_git_pass(git_odb_add_alternate(_odb, new_backend(2), 4));
	cl_git_pass(git_odb_add_alternate(_odb, new_backend(6), 1));

	check_backend_sorting(_odb);
}

