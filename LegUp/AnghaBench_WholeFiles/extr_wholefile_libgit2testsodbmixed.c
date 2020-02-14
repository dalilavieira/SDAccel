#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;
typedef  struct TYPE_21__   TYPE_14__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  short_hex ;
typedef  int /*<<< orphan*/  hex ;
struct TYPE_22__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_23__ {TYPE_1__ member_0; } ;
typedef  TYPE_2__ git_oid ;
typedef  int /*<<< orphan*/  git_odb_object ;
struct TYPE_24__ {unsigned short length; size_t type; TYPE_2__ id; } ;
typedef  TYPE_3__ git_odb_expand_id ;
typedef  size_t git_object_t ;
struct TYPE_21__ {char* lookup_id; size_t expected_type; char const* expected_id; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (TYPE_14__*) ; 
 size_t GIT_EAMBIGUOUS ; 
 scalar_t__ GIT_OBJECT_ANY ; 
 scalar_t__ GIT_OBJECT_BLOB ; 
 scalar_t__ GIT_OBJECT_TREE ; 
 size_t GIT_OID_HEXSZ ; 
 int /*<<< orphan*/ * _odb ; 
 int /*<<< orphan*/  cl_assert (TYPE_3__*) ; 
 int /*<<< orphan*/  cl_assert_equal_i (size_t,unsigned short) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (unsigned short) ; 
 TYPE_14__* expand_id_test_data ; 
 TYPE_3__* git__calloc (size_t,int) ; 
 int /*<<< orphan*/  git__free (TYPE_3__*) ; 
 unsigned short git_odb_exists_prefix (TYPE_2__*,int /*<<< orphan*/ *,TYPE_2__*,size_t) ; 
 unsigned short git_odb_expand_ids (int /*<<< orphan*/ *,TYPE_3__*,size_t) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_object_free (int /*<<< orphan*/ *) ; 
 TYPE_2__* git_odb_object_id (int /*<<< orphan*/ *) ; 
 unsigned short git_odb_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 unsigned short git_odb_read_prefix (int /*<<< orphan*/ **,int /*<<< orphan*/ *,TYPE_2__*,size_t) ; 
 unsigned short git_oid_fromstr (TYPE_2__*,char const*) ; 
 unsigned short git_oid_fromstrn (TYPE_2__*,char const*,size_t) ; 
 size_t strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 

void test_odb_mixed__initialize(void)
{
	cl_git_pass(git_odb_open(&_odb, cl_fixture("duplicate.git/objects")));
}

void test_odb_mixed__cleanup(void)
{
	git_odb_free(_odb);
	_odb = NULL;
}

void test_odb_mixed__dup_oid(void) {
	const char hex[] = "ce013625030ba8dba906f756967f9e9ca394464a";
	const char short_hex[] = "ce01362";
	git_oid oid;
	git_odb_object *obj;

	cl_git_pass(git_oid_fromstr(&oid, hex));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, GIT_OID_HEXSZ));
	git_odb_object_free(obj);

	cl_git_pass(git_odb_exists_prefix(NULL, _odb, &oid, GIT_OID_HEXSZ));

	cl_git_pass(git_oid_fromstrn(&oid, short_hex, sizeof(short_hex) - 1));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, sizeof(short_hex) - 1));
	git_odb_object_free(obj);

	cl_git_pass(git_odb_exists_prefix(NULL, _odb, &oid, sizeof(short_hex) - 1));
}

void test_odb_mixed__dup_oid_prefix_0(void) {
	char hex[10];
	git_oid oid, found;
	git_odb_object *obj;

	/* ambiguous in the same pack file */

	strncpy(hex, "dea509d0", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_assert_equal_i(
		GIT_EAMBIGUOUS, git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	cl_assert_equal_i(
		GIT_EAMBIGUOUS, git_odb_exists_prefix(&found, _odb, &oid, strlen(hex)));

	strncpy(hex, "dea509d09", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	cl_git_pass(git_odb_exists_prefix(&found, _odb, &oid, strlen(hex)));
	cl_assert_equal_oid(&found, git_odb_object_id(obj));
	git_odb_object_free(obj);

	strncpy(hex, "dea509d0b", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	git_odb_object_free(obj);

	/* ambiguous in different pack files */

	strncpy(hex, "81b5bff5", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_assert_equal_i(
		GIT_EAMBIGUOUS, git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	cl_assert_equal_i(
		GIT_EAMBIGUOUS, git_odb_exists_prefix(&found, _odb, &oid, strlen(hex)));

	strncpy(hex, "81b5bff5b", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	cl_git_pass(git_odb_exists_prefix(&found, _odb, &oid, strlen(hex)));
	cl_assert_equal_oid(&found, git_odb_object_id(obj));
	git_odb_object_free(obj);

	strncpy(hex, "81b5bff5f", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	git_odb_object_free(obj);

	/* ambiguous in pack file and loose */

	strncpy(hex, "0ddeaded", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_assert_equal_i(
		GIT_EAMBIGUOUS, git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	cl_assert_equal_i(
		GIT_EAMBIGUOUS, git_odb_exists_prefix(&found, _odb, &oid, strlen(hex)));

	strncpy(hex, "0ddeaded9", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	cl_git_pass(git_odb_exists_prefix(&found, _odb, &oid, strlen(hex)));
	cl_assert_equal_oid(&found, git_odb_object_id(obj));
	git_odb_object_free(obj);

	strncpy(hex, "0ddeadede", sizeof(hex));
	cl_git_pass(git_oid_fromstrn(&oid, hex, strlen(hex)));
	cl_git_pass(git_odb_read_prefix(&obj, _odb, &oid, strlen(hex)));
	git_odb_object_free(obj);
}

__attribute__((used)) static void setup_prefix_query(
	git_odb_expand_id **out_ids,
	size_t *out_num)
{
	git_odb_expand_id *ids;
	size_t num, i;

	num = ARRAY_SIZE(expand_id_test_data);

	cl_assert((ids = git__calloc(num, sizeof(git_odb_expand_id))));

	for (i = 0; i < num; i++) {
		git_odb_expand_id *id = &ids[i];

		size_t len = strlen(expand_id_test_data[i].lookup_id);

		git_oid_fromstrn(&id->id, expand_id_test_data[i].lookup_id, len);
		id->length = (unsigned short)len;
		id->type = expand_id_test_data[i].expected_type;
	}

	*out_ids = ids;
	*out_num = num;
}

__attribute__((used)) static void assert_found_objects(git_odb_expand_id *ids)
{
	size_t num, i;

	num = ARRAY_SIZE(expand_id_test_data);

	for (i = 0; i < num; i++) {
		git_oid expected_id = {{0}};
		size_t expected_len = 0;
		git_object_t expected_type = 0;

		if (expand_id_test_data[i].expected_id) {
			git_oid_fromstr(&expected_id, expand_id_test_data[i].expected_id);
			expected_len = GIT_OID_HEXSZ;
			expected_type = expand_id_test_data[i].expected_type;
		}

		cl_assert_equal_oid(&expected_id, &ids[i].id);
		cl_assert_equal_i(expected_len, ids[i].length);
		cl_assert_equal_i(expected_type, ids[i].type);
	}
}

__attribute__((used)) static void assert_notfound_objects(git_odb_expand_id *ids)
{
	git_oid expected_id = {{0}};
	size_t num, i;

	num = ARRAY_SIZE(expand_id_test_data);

	for (i = 0; i < num; i++) {
		cl_assert_equal_oid(&expected_id, &ids[i].id);
		cl_assert_equal_i(0, ids[i].length);
		cl_assert_equal_i(0, ids[i].type);
	}
}

void test_odb_mixed__expand_ids(void)
{
	git_odb_expand_id *ids;
	size_t i, num;

	/* test looking for the actual (correct) types */

	setup_prefix_query(&ids, &num);
	cl_git_pass(git_odb_expand_ids(_odb, ids, num));
	assert_found_objects(ids);
	git__free(ids);

	/* test looking for an explicit `type == 0` */

	setup_prefix_query(&ids, &num);

	for (i = 0; i < num; i++)
		ids[i].type = 0;

	cl_git_pass(git_odb_expand_ids(_odb, ids, num));
	assert_found_objects(ids);
	git__free(ids);

	/* test looking for an explicit GIT_OBJECT_ANY */

	setup_prefix_query(&ids, &num);

	for (i = 0; i < num; i++)
		ids[i].type = GIT_OBJECT_ANY;

	cl_git_pass(git_odb_expand_ids(_odb, ids, num));
	assert_found_objects(ids);
	git__free(ids);

	/* test looking for the completely wrong type */

	setup_prefix_query(&ids, &num);

	for (i = 0; i < num; i++)
		ids[i].type = (ids[i].type == GIT_OBJECT_BLOB) ?
			GIT_OBJECT_TREE : GIT_OBJECT_BLOB;

	cl_git_pass(git_odb_expand_ids(_odb, ids, num));
	assert_notfound_objects(ids);
	git__free(ids);
}

void test_odb_mixed__expand_ids_cached(void)
{
	git_odb_expand_id *ids;
	size_t i, num;

	/* test looking for the actual (correct) types after accessing the object */

	setup_prefix_query(&ids, &num);

	for (i = 0; i < num; i++) {
		git_odb_object *obj;
		if (ids[i].type == GIT_OBJECT_ANY)
			continue;
		cl_git_pass(git_odb_read_prefix(&obj, _odb, &ids[i].id, ids[i].length));
		git_odb_object_free(obj);
	}

	cl_git_pass(git_odb_expand_ids(_odb, ids, num));
	assert_found_objects(ids);
	git__free(ids);
}

