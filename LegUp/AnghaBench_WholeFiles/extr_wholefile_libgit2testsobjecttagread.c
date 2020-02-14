#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/ * tagger; int /*<<< orphan*/ * message; } ;
typedef  TYPE_1__ git_tag ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_odb ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_commit ;

/* Variables and functions */
 scalar_t__ GIT_OBJECT_COMMIT ; 
 scalar_t__ GIT_OBJECT_TAG ; 
 int /*<<< orphan*/  bad_tag_id ; 
 int /*<<< orphan*/  badly_tagged_commit ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,char*) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ git_oid_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_odb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_tag_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_tag_id (TYPE_1__*) ; 
 int /*<<< orphan*/  git_tag_lookup (TYPE_1__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* git_tag_message (TYPE_1__*) ; 
 char* git_tag_name (TYPE_1__*) ; 
 int /*<<< orphan*/  git_tag_target (int /*<<< orphan*/ **,TYPE_1__*) ; 
 scalar_t__ git_tag_target_type (TYPE_1__*) ; 
 int /*<<< orphan*/  short_tag_id ; 
 int /*<<< orphan*/  short_tagged_commit ; 
 int /*<<< orphan*/  silly_tag ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tag1_id ; 
 int /*<<< orphan*/  tag2_id ; 
 int /*<<< orphan*/  tagged_commit ; 
 int /*<<< orphan*/  taggerless ; 

void test_object_tag_read__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo");
}

void test_object_tag_read__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_object_tag_read__parse(void)
{
	/* read and parse a tag from the repository */
	git_tag *tag1, *tag2;
	git_commit *commit;
	git_oid id1, id2, id_commit;

	git_oid_fromstr(&id1, tag1_id);
	git_oid_fromstr(&id2, tag2_id);
	git_oid_fromstr(&id_commit, tagged_commit);

	cl_git_pass(git_tag_lookup(&tag1, g_repo, &id1));

	cl_assert_equal_s(git_tag_name(tag1), "test");
	cl_assert(git_tag_target_type(tag1) == GIT_OBJECT_TAG);

	cl_git_pass(git_tag_target((git_object **)&tag2, tag1));
	cl_assert(tag2 != NULL);

	cl_assert(git_oid_cmp(&id2, git_tag_id(tag2)) == 0);

	cl_git_pass(git_tag_target((git_object **)&commit, tag2));
	cl_assert(commit != NULL);

	cl_assert(git_oid_cmp(&id_commit, git_commit_id(commit)) == 0);

	git_tag_free(tag1);
	git_tag_free(tag2);
	git_commit_free(commit);
}

void test_object_tag_read__parse_without_tagger(void)
{
	/* read and parse a tag without a tagger field */
	git_repository *bad_tag_repo;
	git_tag *bad_tag;
	git_commit *commit;
	git_oid id, id_commit;

	/* TODO: This is a little messy */
	cl_git_pass(git_repository_open(&bad_tag_repo, cl_fixture("bad_tag.git")));

	git_oid_fromstr(&id, bad_tag_id);
	git_oid_fromstr(&id_commit, badly_tagged_commit);

	cl_git_pass(git_tag_lookup(&bad_tag, bad_tag_repo, &id));
	cl_assert(bad_tag != NULL);

	cl_assert_equal_s(git_tag_name(bad_tag), "e90810b");
	cl_assert(git_oid_cmp(&id, git_tag_id(bad_tag)) == 0);
	cl_assert(bad_tag->tagger == NULL);

	cl_git_pass(git_tag_target((git_object **)&commit, bad_tag));
	cl_assert(commit != NULL);

	cl_assert(git_oid_cmp(&id_commit, git_commit_id(commit)) == 0);


	git_tag_free(bad_tag);
	git_commit_free(commit);
	git_repository_free(bad_tag_repo);
}

void test_object_tag_read__parse_without_message(void)
{
	/* read and parse a tag without a message field */
	git_repository *short_tag_repo;
	git_tag *short_tag;
	git_commit *commit;
	git_oid id, id_commit;

	/* TODO: This is a little messy */
	cl_git_pass(git_repository_open(&short_tag_repo, cl_fixture("short_tag.git")));

	git_oid_fromstr(&id, short_tag_id);
	git_oid_fromstr(&id_commit, short_tagged_commit);

	cl_git_pass(git_tag_lookup(&short_tag, short_tag_repo, &id));
	cl_assert(short_tag != NULL);

	cl_assert_equal_s(git_tag_name(short_tag), "no_description");
	cl_assert(git_oid_cmp(&id, git_tag_id(short_tag)) == 0);
	cl_assert(short_tag->message == NULL);

	cl_git_pass(git_tag_target((git_object **)&commit, short_tag));
	cl_assert(commit != NULL);

	cl_assert(git_oid_cmp(&id_commit, git_commit_id(commit)) == 0);

	git_tag_free(short_tag);
	git_commit_free(commit);
	git_repository_free(short_tag_repo);
}

void test_object_tag_read__without_tagger_nor_message(void)
{
	git_tag *tag;
	git_oid id;
	git_repository *repo;

	cl_git_pass(git_repository_open(&repo, cl_fixture("testrepo.git")));

	cl_git_pass(git_oid_fromstr(&id, taggerless));

	cl_git_pass(git_tag_lookup(&tag, repo, &id));

	cl_assert_equal_s(git_tag_name(tag), "taggerless");
	cl_assert(git_tag_target_type(tag) == GIT_OBJECT_COMMIT);

	cl_assert(tag->message == NULL);
	cl_assert(tag->tagger == NULL);

	git_tag_free(tag);
	git_repository_free(repo);
}

void test_object_tag_read__extra_header_fields(void)
{
	git_tag *tag;
	git_odb *odb;
	git_oid id;

	cl_git_pass(git_repository_odb__weakptr(&odb, g_repo));

	cl_git_pass(git_odb_write(&id, odb, silly_tag, strlen(silly_tag), GIT_OBJECT_TAG));
	cl_git_pass(git_tag_lookup(&tag, g_repo, &id));

	cl_assert_equal_s("v1_0_1 release\n", git_tag_message(tag));

	git_tag_free(tag);
}

