#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_5__ {size_t size; scalar_t__ type; } ;
struct TYPE_6__ {TYPE_1__ cached; } ;
typedef  TYPE_2__ git_odb_object ;
typedef  int /*<<< orphan*/  git_odb_backend ;
typedef  scalar_t__ git_object_t ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * _odb ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_odb_backend_one_pack (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int git_odb_exists (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_new (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  git_odb_object_free (TYPE_2__*) ; 
 int /*<<< orphan*/  git_odb_read (TYPE_2__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read_header (size_t*,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * packed_objects_one ; 

void test_odb_packed_one__initialize(void)
{
	git_odb_backend *backend = NULL;

	cl_git_pass(git_odb_new(&_odb));
	cl_git_pass(git_odb_backend_one_pack(&backend, cl_fixture("testrepo.git/objects/pack/pack-a81e489679b7d3418f9ab594bda8ceb37dd4c695.idx")));
	cl_git_pass(git_odb_add_backend(_odb, backend, 1));
}

void test_odb_packed_one__cleanup(void)
{
	git_odb_free(_odb);
	_odb = NULL;
}

void test_odb_packed_one__mass_read(void)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(packed_objects_one); ++i) {
		git_oid id;
		git_odb_object *obj;

		cl_git_pass(git_oid_fromstr(&id, packed_objects_one[i]));
		cl_assert(git_odb_exists(_odb, &id) == 1);
		cl_git_pass(git_odb_read(&obj, _odb, &id));

		git_odb_object_free(obj);
	}
}

void test_odb_packed_one__read_header_0(void)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(packed_objects_one); ++i) {
		git_oid id;
		git_odb_object *obj;
		size_t len;
		git_object_t type;

		cl_git_pass(git_oid_fromstr(&id, packed_objects_one[i]));

		cl_git_pass(git_odb_read(&obj, _odb, &id));
		cl_git_pass(git_odb_read_header(&len, &type, _odb, &id));

		cl_assert(obj->cached.size == len);
		cl_assert(obj->cached.type == type);

		git_odb_object_free(obj);
	}
}

