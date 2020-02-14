#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int len; int type; int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ git_rawobj ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_hash_ctx ;
struct TYPE_15__ {int len; void* data; } ;
typedef  TYPE_2__ git_buf_vec ;

/* Variables and functions */
 int GIT_OBJECT_BLOB ; 
 int GIT_OBJECT_OFS_DELTA ; 
 int GIT_OBJECT_REF_DELTA ; 
 int /*<<< orphan*/  bye_id ; 
 void* bye_text ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  commit_id ; 
 TYPE_1__ commit_obj ; 
 int /*<<< orphan*/  git_hash_buf (int /*<<< orphan*/ *,void*,int) ; 
 int /*<<< orphan*/  git_hash_ctx_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_ctx_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_final (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_update (int /*<<< orphan*/ *,void*,int) ; 
 int /*<<< orphan*/  git_hash_vec (int /*<<< orphan*/ *,TYPE_2__*,int) ; 
 int /*<<< orphan*/  git_odb_hash (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ git_oid_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hello_id ; 
 void* hello_text ; 
 TYPE_1__ junk_obj ; 
 int /*<<< orphan*/  one_id ; 
 TYPE_1__ one_obj ; 
 int /*<<< orphan*/ * some_data ; 
 int /*<<< orphan*/  some_id ; 
 TYPE_1__ some_obj ; 
 int strlen (void*) ; 
 int /*<<< orphan*/  tag_id ; 
 TYPE_1__ tag_obj ; 
 int /*<<< orphan*/  tree_id ; 
 TYPE_1__ tree_obj ; 
 int /*<<< orphan*/  two_id ; 
 TYPE_1__ two_obj ; 
 int /*<<< orphan*/  zero_id ; 
 TYPE_1__ zero_obj ; 

__attribute__((used)) static void hash_object_pass(git_oid *oid, git_rawobj *obj)
{
	cl_git_pass(git_odb_hash(oid, obj->data, obj->len, obj->type));
}

__attribute__((used)) static void hash_object_fail(git_oid *oid, git_rawobj *obj)
{
	cl_git_fail(git_odb_hash(oid, obj->data, obj->len, obj->type));
}

void test_object_raw_hash__hash_by_blocks(void)
{
	git_hash_ctx ctx;
	git_oid id1, id2;

	cl_git_pass(git_hash_ctx_init(&ctx));

	/* should already be init'd */
	cl_git_pass(git_hash_update(&ctx, hello_text, strlen(hello_text)));
	cl_git_pass(git_hash_final(&id2, &ctx));
	cl_git_pass(git_oid_fromstr(&id1, hello_id));
	cl_assert(git_oid_cmp(&id1, &id2) == 0);

	/* reinit should permit reuse */
	cl_git_pass(git_hash_init(&ctx));
	cl_git_pass(git_hash_update(&ctx, bye_text, strlen(bye_text)));
	cl_git_pass(git_hash_final(&id2, &ctx));
	cl_git_pass(git_oid_fromstr(&id1, bye_id));
	cl_assert(git_oid_cmp(&id1, &id2) == 0);

	git_hash_ctx_cleanup(&ctx);
}

void test_object_raw_hash__hash_buffer_in_single_call(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, hello_id));
	git_hash_buf(&id2, hello_text, strlen(hello_text));
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_vector(void)
{
	git_oid id1, id2;
	git_buf_vec vec[2];

	cl_git_pass(git_oid_fromstr(&id1, hello_id));

	vec[0].data = hello_text;
	vec[0].len  = 4;
	vec[1].data = hello_text+4;
	vec[1].len  = strlen(hello_text)-4;

	git_hash_vec(&id2, vec, 2);

	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_junk_data(void)
{
	git_oid id, id_zero;

	cl_git_pass(git_oid_fromstr(&id_zero, zero_id));

	/* invalid types: */
	junk_obj.data = some_data;
	hash_object_fail(&id, &junk_obj);

	junk_obj.type = 0; /* EXT1 */
	hash_object_fail(&id, &junk_obj);

	junk_obj.type = 5; /* EXT2 */
	hash_object_fail(&id, &junk_obj);

	junk_obj.type = GIT_OBJECT_OFS_DELTA;
	hash_object_fail(&id, &junk_obj);

	junk_obj.type = GIT_OBJECT_REF_DELTA;
	hash_object_fail(&id, &junk_obj);

	junk_obj.type = 42;
	hash_object_fail(&id, &junk_obj);

	/* data can be NULL only if len is zero: */
	junk_obj.type = GIT_OBJECT_BLOB;
	junk_obj.data = NULL;
	hash_object_pass(&id, &junk_obj);
	cl_assert(git_oid_cmp(&id, &id_zero) == 0);

	junk_obj.len = 1;
	hash_object_fail(&id, &junk_obj);
}

void test_object_raw_hash__hash_commit_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, commit_id));
	hash_object_pass(&id2, &commit_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_tree_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, tree_id));
	hash_object_pass(&id2, &tree_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_tag_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, tag_id));
	hash_object_pass(&id2, &tag_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_zero_length_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, zero_id));
	hash_object_pass(&id2, &zero_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_one_byte_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, one_id));
	hash_object_pass(&id2, &one_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_two_byte_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, two_id));
	hash_object_pass(&id2, &two_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

void test_object_raw_hash__hash_multi_byte_object(void)
{
	git_oid id1, id2;

	cl_git_pass(git_oid_fromstr(&id1, some_id));
	hash_object_pass(&id2, &some_obj);
	cl_assert(git_oid_cmp(&id1, &id2) == 0);
}

