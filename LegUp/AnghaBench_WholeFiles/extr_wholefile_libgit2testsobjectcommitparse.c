#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
struct TYPE_14__ {int /*<<< orphan*/  sign; int /*<<< orphan*/  offset; int /*<<< orphan*/  time; } ;
struct TYPE_18__ {TYPE_2__ when; int /*<<< orphan*/  email; int /*<<< orphan*/  name; } ;
typedef  TYPE_6__ git_signature ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
struct TYPE_17__ {int /*<<< orphan*/  size; } ;
struct TYPE_19__ {int /*<<< orphan*/  object; TYPE_5__ parent_ids; int /*<<< orphan*/  tree_id; int /*<<< orphan*/  message_encoding; int /*<<< orphan*/  raw_message; TYPE_4__* committer; TYPE_11__* author; } ;
typedef  TYPE_7__ git_commit ;
struct TYPE_15__ {size_t time; size_t offset; size_t sign; } ;
struct TYPE_16__ {char const* name; char const* email; TYPE_3__ when; } ;
struct TYPE_13__ {size_t time; size_t offset; size_t sign; } ;
struct TYPE_12__ {char const* name; char const* email; TYPE_1__ when; } ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_p (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_object__free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object__from_raw (int /*<<< orphan*/ **,char const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_signature__equal (TYPE_6__*,TYPE_11__*) ; 
 int /*<<< orphan*/  git_signature_free (TYPE_6__*) ; 
 int /*<<< orphan*/  git_signature_from_buffer (TYPE_6__**,char const*) ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static void assert_commit_parses(const char *data, size_t datalen,
	const char *expected_treeid,
	const char *expected_author,
	const char *expected_committer,
	const char *expected_encoding,
	const char *expected_message,
	size_t expected_parents)
{
	git_commit *commit;
	if (!datalen)
		datalen = strlen(data);
	cl_git_pass(git_object__from_raw((git_object **) &commit, data, datalen, GIT_OBJECT_COMMIT));

	if (expected_author) {
		git_signature *author;
		cl_git_pass(git_signature_from_buffer(&author, expected_author));
		cl_assert(git_signature__equal(author, commit->author));
		cl_assert_equal_s(author->name, commit->author->name);
		cl_assert_equal_s(author->email, commit->author->email);
		cl_assert_equal_i(author->when.time, commit->author->when.time);
		cl_assert_equal_i(author->when.offset, commit->author->when.offset);
		cl_assert_equal_i(author->when.sign, commit->author->when.sign);
		git_signature_free(author);
	}

	if (expected_committer) {
		git_signature *committer;
		cl_git_pass(git_signature_from_buffer(&committer, expected_committer));
		cl_assert_equal_s(committer->name, commit->committer->name);
		cl_assert_equal_s(committer->email, commit->committer->email);
		cl_assert_equal_i(committer->when.time, commit->committer->when.time);
		cl_assert_equal_i(committer->when.offset, commit->committer->when.offset);
		cl_assert_equal_i(committer->when.sign, commit->committer->when.sign);
		git_signature_free(committer);
	}

	if (expected_encoding)
		cl_assert_equal_s(commit->message_encoding, expected_encoding);
	else
		cl_assert_equal_p(commit->message_encoding, NULL);

	if (expected_message)
		cl_assert_equal_s(commit->raw_message, expected_message);
	else
		cl_assert_equal_p(commit->message_encoding, NULL);

	if (expected_treeid) {
		git_oid tree_oid;
		cl_git_pass(git_oid_fromstr(&tree_oid, expected_treeid));
		cl_assert_equal_oid(&tree_oid, &commit->tree_id);
	}

	cl_assert_equal_i(commit->parent_ids.size, expected_parents);

	git_object__free(&commit->object);
}

__attribute__((used)) static void assert_commit_fails(const char *data, size_t datalen)
{
	git_object *object;
	if (!datalen)
		datalen = strlen(data);
	cl_git_fail(git_object__from_raw(&object, data, datalen, GIT_OBJECT_COMMIT));
}

void test_object_commit_parse__parsing_commit_succeeds(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"encoding Encoding\n"
		"\n"
		"Message";
	assert_commit_parses(commit, 0,
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"Author <author@example.com>",
		"Committer <committer@example.com>",
		"Encoding",
		"Message", 0);
}

void test_object_commit_parse__parsing_commit_without_encoding_succeeds(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_parses(commit, 0,
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"Author <author@example.com>",
		"Committer <committer@example.com>",
		NULL,
		"Message", 0);
}

void test_object_commit_parse__parsing_commit_with_multiple_authors_succeeds(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author1 <author@example.com>\n"
		"author Author2 <author@example.com>\n"
		"author Author3 <author@example.com>\n"
		"author Author4 <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_parses(commit, 0,
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"Author1 <author@example.com>",
		"Committer <committer@example.com>",
		NULL,
		"Message", 0);
}

void test_object_commit_parse__parsing_commit_with_multiple_committers_succeeds(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"committer Committer1 <committer@example.com>\n"
		"committer Committer2 <committer@example.com>\n"
		"committer Committer3 <committer@example.com>\n"
		"committer Committer4 <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_parses(commit, 0,
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"Author <author@example.com>",
		"Committer1 <committer@example.com>",
		NULL,
		"Message", 0);
}

void test_object_commit_parse__parsing_commit_without_message_succeeds(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n";
	assert_commit_parses(commit, 0,
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"Author <author@example.com>",
		"Committer <committer@example.com>",
		NULL,
		"", 0);
}

void test_object_commit_parse__parsing_commit_with_unknown_fields_succeeds(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"foo bar\n"
		"more garbage\n"
		"\n"
		"Message";
	assert_commit_parses(commit, 0,
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"Author <author@example.com>",
		"Committer <committer@example.com>",
		NULL,
		"Message", 0);
}

void test_object_commit_parse__parsing_commit_with_invalid_tree_fails(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1xxx5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_fails(commit, 0);
}

void test_object_commit_parse__parsing_commit_without_tree_fails(void)
{
	const char *commit =
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_fails(commit, 0);
}

void test_object_commit_parse__parsing_commit_without_author_fails(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"committer Committer <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_fails(commit, 0);
}

void test_object_commit_parse__parsing_commit_without_committer_fails(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author Author <author@example.com>\n"
		"\n"
		"Message";
	assert_commit_fails(commit, 0);
}

void test_object_commit_parse__parsing_encoding_will_not_cause_oob_read(void)
{
	const char *commit =
		"tree 3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8\n"
		"author <>\n"
		"committer <>\n"
		"encoding foo\n";
	/*
	 * As we ignore unknown fields, the cut-off encoding field will be
	 * parsed just fine.
	 */
	assert_commit_parses(commit, strlen(commit) - strlen("ncoding foo\n"),
		"3e7ac388cadacccdf1c6c5f3445895b71d9cb0f8",
		"<>",
		"<>",
		NULL,
		"", 0);
}

