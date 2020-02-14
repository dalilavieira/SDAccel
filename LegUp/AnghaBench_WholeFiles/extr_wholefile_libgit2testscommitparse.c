#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_9__ ;
typedef  struct TYPE_44__   TYPE_8__ ;
typedef  struct TYPE_43__   TYPE_6__ ;
typedef  struct TYPE_42__   TYPE_5__ ;
typedef  struct TYPE_41__   TYPE_4__ ;
typedef  struct TYPE_40__   TYPE_3__ ;
typedef  struct TYPE_39__   TYPE_2__ ;
typedef  struct TYPE_38__   TYPE_1__ ;
typedef  struct TYPE_37__   TYPE_14__ ;

/* Type definitions */
struct TYPE_38__ {int offset; scalar_t__ time; } ;
struct git_signature {char* name; char* email; int /*<<< orphan*/  member_0; TYPE_1__ when; } ;
struct TYPE_41__ {char* string; char const* name; char const* email; int offset; scalar_t__ time; int /*<<< orphan*/  header; } ;
typedef  TYPE_4__ passing_signature_test_case ;
struct TYPE_42__ {char* line; int /*<<< orphan*/  header; } ;
typedef  TYPE_5__ parse_test_case ;
typedef  scalar_t__ git_time_t ;
typedef  struct git_signature git_signature ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_40__ {int size; } ;
struct TYPE_39__ {int /*<<< orphan*/  repo; } ;
struct TYPE_43__ {char* buffer; TYPE_3__ cached; TYPE_2__ object; } ;
typedef  TYPE_6__ git_odb_object ;
typedef  int /*<<< orphan*/  git_odb ;
typedef  TYPE_6__ git_commit ;
struct TYPE_44__ {char* ptr; } ;
typedef  TYPE_8__ git_buf ;
struct TYPE_45__ {char* string; int /*<<< orphan*/  header; } ;
typedef  TYPE_9__ failing_signature_test_case ;
typedef  int /*<<< orphan*/  commit_ids ;
struct TYPE_37__ {int klass; } ;

/* Variables and functions */
 int ARRAY_SIZE (char const**) ; 
 TYPE_8__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int GIT_ERROR_INVALID ; 
 int GIT_ERROR_OBJECT ; 
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char*) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 char const** failing_commit_cases ; 
 TYPE_5__* failing_header_cases ; 
 TYPE_9__* failing_signature_cases ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git__free (char*) ; 
 scalar_t__ git__malloc (int) ; 
 scalar_t__ git__prefixcmp (char*,char*) ; 
 int /*<<< orphan*/  git_buf_clear (TYPE_8__*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_8__*) ; 
 int /*<<< orphan*/  git_commit__free (TYPE_6__*) ; 
 int git_commit__parse (TYPE_6__*,TYPE_6__*) ; 
 struct git_signature* git_commit_author (TYPE_6__*) ; 
 struct git_signature* git_commit_committer (TYPE_6__*) ; 
 int git_commit_extract_signature (TYPE_8__*,TYPE_8__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_commit_free (TYPE_6__*) ; 
 int git_commit_header_field (TYPE_8__*,TYPE_6__*,char*) ; 
 int git_commit_lookup (TYPE_6__**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 char* git_commit_message (TYPE_6__*) ; 
 char* git_commit_message_raw (TYPE_6__*) ; 
 int git_commit_parent (TYPE_6__**,TYPE_6__*,unsigned int) ; 
 unsigned int git_commit_parentcount (TYPE_6__*) ; 
 scalar_t__ git_commit_time (TYPE_6__*) ; 
 TYPE_14__* git_error_last () ; 
 int git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int,int /*<<< orphan*/ ) ; 
 int git_oid__parse (int /*<<< orphan*/ *,char const**,char const*,int /*<<< orphan*/ ) ; 
 int git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int git_repository_odb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int git_signature__parse (struct git_signature*,char const**,char const*,int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  memset (TYPE_6__*,int,int) ; 
 char const** passing_commit_cases ; 
 TYPE_5__* passing_header_cases ; 
 TYPE_4__* passing_signature_cases ; 
 int strlen (char const*) ; 

void test_commit_parse__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo");
}

void test_commit_parse__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_commit_parse__header(void)
{
	git_oid oid;

	parse_test_case *testcase;
	for (testcase = passing_header_cases; testcase->line != NULL; testcase++)
	{
		const char *line = testcase->line;
		const char *line_end = line + strlen(line);

		cl_git_pass(git_oid__parse(&oid, &line, line_end, testcase->header));
		cl_assert(line == line_end);
	}

	for (testcase = failing_header_cases; testcase->line != NULL; testcase++)
	{
		const char *line = testcase->line;
		const char *line_end = line + strlen(line);

		cl_git_fail(git_oid__parse(&oid, &line, line_end, testcase->header));
	}
}

void test_commit_parse__signature(void)
{
	passing_signature_test_case *passcase;
	failing_signature_test_case *failcase;

	for (passcase = passing_signature_cases; passcase->string != NULL; passcase++)
	{
		const char *str = passcase->string;
		size_t len = strlen(passcase->string);
		struct git_signature person = {0};

		cl_git_pass(git_signature__parse(&person, &str, str + len, passcase->header, '\n'));
		cl_assert_equal_s(passcase->name, person.name);
		cl_assert_equal_s(passcase->email, person.email);
		cl_assert_equal_i((int)passcase->time, (int)person.when.time);
		cl_assert_equal_i(passcase->offset, person.when.offset);
		git__free(person.name); git__free(person.email);
	}

	for (failcase = failing_signature_cases; failcase->string != NULL; failcase++)
	{
		const char *str = failcase->string;
		size_t len = strlen(failcase->string);
		git_signature person = {0};
		cl_git_fail(git_signature__parse(&person, &str, str + len, failcase->header, '\n'));
		git__free(person.name); git__free(person.email);
	}
}

__attribute__((used)) static int parse_commit(git_commit **out, const char *buffer)
{
	git_commit *commit;
	git_odb_object fake_odb_object;
	int error;

	commit = (git_commit*)git__malloc(sizeof(git_commit));
	memset(commit, 0x0, sizeof(git_commit));
	commit->object.repo = g_repo;

	memset(&fake_odb_object, 0x0, sizeof(git_odb_object));
	fake_odb_object.buffer = (char *)buffer;
	fake_odb_object.cached.size = strlen(fake_odb_object.buffer);

	error = git_commit__parse(commit, &fake_odb_object);

	*out = commit;
	return error;
}

void test_commit_parse__entire_commit(void)
{
	const int failing_commit_count = ARRAY_SIZE(failing_commit_cases);
	const int passing_commit_count = ARRAY_SIZE(passing_commit_cases);
	int i;
	git_commit *commit;

	for (i = 0; i < failing_commit_count; ++i) {
		cl_git_fail(parse_commit(&commit, failing_commit_cases[i]));
		git_commit__free(commit);
	}

	for (i = 0; i < passing_commit_count; ++i) {
		cl_git_pass(parse_commit(&commit, passing_commit_cases[i]));

		if (!i)
			cl_assert_equal_s("", git_commit_message(commit));
		else
			cl_assert(git__prefixcmp(
				git_commit_message(commit), "a simple commit which works") == 0);

		git_commit__free(commit);
	}
}

void test_commit_parse__details0(void) {
	static const char *commit_ids[] = {
		"a4a7dce85cf63874e984719f4fdd239f5145052f", /* 0 */
		"9fd738e8f7967c078dceed8190330fc8648ee56a", /* 1 */
		"4a202b346bb0fb0db7eff3cffeb3c70babbd2045", /* 2 */
		"c47800c7266a2be04c571c04d5a6614691ea99bd", /* 3 */
		"8496071c1b46c854b31185ea97743be6a8774479", /* 4 */
		"5b5b025afb0b4c913b4c338a42934a3863bf3644", /* 5 */
		"a65fedf39aefe402d3bb6e24df4d4f5fe4547750", /* 6 */
	};
	const size_t commit_count = sizeof(commit_ids) / sizeof(const char *);
	unsigned int i;

	for (i = 0; i < commit_count; ++i) {
		git_oid id;
		git_commit *commit;

		const git_signature *author, *committer;
		const char *message;
		git_time_t commit_time;
		unsigned int parents, p;
		git_commit *parent = NULL, *old_parent = NULL;

		git_oid_fromstr(&id, commit_ids[i]);

		cl_git_pass(git_commit_lookup(&commit, g_repo, &id));

		message = git_commit_message(commit);
		author = git_commit_author(commit);
		committer = git_commit_committer(commit);
		commit_time = git_commit_time(commit);
		parents = git_commit_parentcount(commit);

		cl_assert_equal_s("Scott Chacon", author->name);
		cl_assert_equal_s("schacon@gmail.com", author->email);
		cl_assert_equal_s("Scott Chacon", committer->name);
		cl_assert_equal_s("schacon@gmail.com", committer->email);
		cl_assert(message != NULL);
		cl_assert(commit_time > 0);
		cl_assert(parents <= 2);
		for (p = 0;p < parents;p++) {
			if (old_parent != NULL)
				git_commit_free(old_parent);

			old_parent = parent;
			cl_git_pass(git_commit_parent(&parent, commit, p));
			cl_assert(parent != NULL);
			cl_assert(git_commit_author(parent) != NULL); /* is it really a commit? */
		}
		git_commit_free(old_parent);
		git_commit_free(parent);

		cl_git_fail(git_commit_parent(&parent, commit, parents));
		git_commit_free(commit);
	}
}

void test_commit_parse__leading_lf(void)
{
	git_commit *commit;
	const char *buffer =
"tree 1810dff58d8a660512d4832e740f692884338ccd\n\
parent e90810b8df3e80c413d903f631643c716887138d\n\
author Vicent Marti <tanoku@gmail.com> 1273848544 +0200\n\
committer Vicent Marti <tanoku@gmail.com> 1273848544 +0200\n\
\n\
\n\
\n\
This commit has a few LF at the start of the commit message";
	const char *message =
"This commit has a few LF at the start of the commit message";
	const char *raw_message =
"\n\
\n\
This commit has a few LF at the start of the commit message";
	cl_git_pass(parse_commit(&commit, buffer));
	cl_assert_equal_s(message, git_commit_message(commit));
	cl_assert_equal_s(raw_message, git_commit_message_raw(commit));
	git_commit__free(commit);
}

void test_commit_parse__only_lf(void)
{
	git_commit *commit;
	const char *buffer =
"tree 1810dff58d8a660512d4832e740f692884338ccd\n\
parent e90810b8df3e80c413d903f631643c716887138d\n\
author Vicent Marti <tanoku@gmail.com> 1273848544 +0200\n\
committer Vicent Marti <tanoku@gmail.com> 1273848544 +0200\n\
\n\
\n\
\n";
	const char *message = "";
	const char *raw_message = "\n\n";

	cl_git_pass(parse_commit(&commit, buffer));
	cl_assert_equal_s(message, git_commit_message(commit));
	cl_assert_equal_s(raw_message, git_commit_message_raw(commit));
	git_commit__free(commit);
}

void test_commit_parse__arbitrary_field(void)
{
	git_commit *commit;
	git_buf buf = GIT_BUF_INIT;
	const char *gpgsig = "-----BEGIN PGP SIGNATURE-----\n\
Version: GnuPG v1.4.12 (Darwin)\n\
\n\
iQIcBAABAgAGBQJQ+FMIAAoJEH+LfPdZDSs1e3EQAJMjhqjWF+WkGLHju7pTw2al\n\
o6IoMAhv0Z/LHlWhzBd9e7JeCnanRt12bAU7yvYp9+Z+z+dbwqLwDoFp8LVuigl8\n\
JGLcnwiUW3rSvhjdCp9irdb4+bhKUnKUzSdsR2CK4/hC0N2i/HOvMYX+BRsvqweq\n\
AsAkA6dAWh+gAfedrBUkCTGhlNYoetjdakWqlGL1TiKAefEZrtA1TpPkGn92vbLq\n\
SphFRUY9hVn1ZBWrT3hEpvAIcZag3rTOiRVT1X1flj8B2vGCEr3RrcwOIZikpdaW\n\
who/X3xh/DGbI2RbuxmmJpxxP/8dsVchRJJzBwG+yhwU/iN3MlV2c5D69tls/Dok\n\
6VbyU4lm/ae0y3yR83D9dUlkycOnmmlBAHKIZ9qUts9X7mWJf0+yy2QxJVpjaTGG\n\
cmnQKKPeNIhGJk2ENnnnzjEve7L7YJQF6itbx5VCOcsGh3Ocb3YR7DMdWjt7f8pu\n\
c6j+q1rP7EpE2afUN/geSlp5i3x8aXZPDj67jImbVCE/Q1X9voCtyzGJH7MXR0N9\n\
ZpRF8yzveRfMH8bwAJjSOGAFF5XkcR/RNY95o+J+QcgBLdX48h+ZdNmUf6jqlu3J\n\
7KmTXXQcOVpN6dD3CmRFsbjq+x6RHwa8u1iGn+oIkX908r97ckfB/kHKH7ZdXIJc\n\
cpxtDQQMGYFpXK/71stq\n\
=ozeK\n\
-----END PGP SIGNATURE-----";

	cl_git_pass(parse_commit(&commit, passing_commit_cases[4]));

	cl_git_pass(git_commit_header_field(&buf, commit, "tree"));
	cl_assert_equal_s("6b79e22d69bf46e289df0345a14ca059dfc9bdf6", buf.ptr);
	git_buf_clear(&buf);

	cl_git_pass(git_commit_header_field(&buf, commit, "parent"));
	cl_assert_equal_s("34734e478d6cf50c27c9d69026d93974d052c454", buf.ptr);
	git_buf_clear(&buf);

	cl_git_pass(git_commit_header_field(&buf, commit, "gpgsig"));
	cl_assert_equal_s(gpgsig, buf.ptr);
	git_buf_clear(&buf);

	cl_git_fail_with(GIT_ENOTFOUND, git_commit_header_field(&buf, commit, "awesomeness"));
	cl_git_fail_with(GIT_ENOTFOUND, git_commit_header_field(&buf, commit, "par"));

	git_commit__free(commit);
	cl_git_pass(parse_commit(&commit, passing_commit_cases[0]));

	cl_git_pass(git_commit_header_field(&buf, commit, "committer"));
	cl_assert_equal_s("Vicent Marti <tanoku@gmail.com> 1273848544 +0200", buf.ptr);

	git_buf_dispose(&buf);
	git_commit__free(commit);
}

void test_commit_parse__extract_signature(void)
{
	git_odb *odb;
	git_oid commit_id;
	git_buf signature = GIT_BUF_INIT, signed_data = GIT_BUF_INIT;
	const char *gpgsig = "-----BEGIN PGP SIGNATURE-----\n\
Version: GnuPG v1.4.12 (Darwin)\n\
\n\
iQIcBAABAgAGBQJQ+FMIAAoJEH+LfPdZDSs1e3EQAJMjhqjWF+WkGLHju7pTw2al\n\
o6IoMAhv0Z/LHlWhzBd9e7JeCnanRt12bAU7yvYp9+Z+z+dbwqLwDoFp8LVuigl8\n\
JGLcnwiUW3rSvhjdCp9irdb4+bhKUnKUzSdsR2CK4/hC0N2i/HOvMYX+BRsvqweq\n\
AsAkA6dAWh+gAfedrBUkCTGhlNYoetjdakWqlGL1TiKAefEZrtA1TpPkGn92vbLq\n\
SphFRUY9hVn1ZBWrT3hEpvAIcZag3rTOiRVT1X1flj8B2vGCEr3RrcwOIZikpdaW\n\
who/X3xh/DGbI2RbuxmmJpxxP/8dsVchRJJzBwG+yhwU/iN3MlV2c5D69tls/Dok\n\
6VbyU4lm/ae0y3yR83D9dUlkycOnmmlBAHKIZ9qUts9X7mWJf0+yy2QxJVpjaTGG\n\
cmnQKKPeNIhGJk2ENnnnzjEve7L7YJQF6itbx5VCOcsGh3Ocb3YR7DMdWjt7f8pu\n\
c6j+q1rP7EpE2afUN/geSlp5i3x8aXZPDj67jImbVCE/Q1X9voCtyzGJH7MXR0N9\n\
ZpRF8yzveRfMH8bwAJjSOGAFF5XkcR/RNY95o+J+QcgBLdX48h+ZdNmUf6jqlu3J\n\
7KmTXXQcOVpN6dD3CmRFsbjq+x6RHwa8u1iGn+oIkX908r97ckfB/kHKH7ZdXIJc\n\
cpxtDQQMGYFpXK/71stq\n\
=ozeK\n\
-----END PGP SIGNATURE-----";

	const char *data =  "tree 6b79e22d69bf46e289df0345a14ca059dfc9bdf6\n\
parent 34734e478d6cf50c27c9d69026d93974d052c454\n\
author Ben Burkert <ben@benburkert.com> 1358451456 -0800\n\
committer Ben Burkert <ben@benburkert.com> 1358451456 -0800\n\
\n\
a simple commit which works\n";

	const char *oneline_signature = "tree 51832e6397b30309c8bcad9c55fa6ae67778f378\n\
parent a1b6decaaac768b5e01e1b5dbf5b2cc081bed1eb\n\
author Some User <someuser@gmail.com> 1454537944 -0700\n\
committer Some User <someuser@gmail.com> 1454537944 -0700\n\
gpgsig bad\n\
\n\
corrupt signature\n";

	const char *oneline_data = "tree 51832e6397b30309c8bcad9c55fa6ae67778f378\n\
parent a1b6decaaac768b5e01e1b5dbf5b2cc081bed1eb\n\
author Some User <someuser@gmail.com> 1454537944 -0700\n\
committer Some User <someuser@gmail.com> 1454537944 -0700\n\
\n\
corrupt signature\n";


	cl_git_pass(git_repository_odb__weakptr(&odb, g_repo));
	cl_git_pass(git_odb_write(&commit_id, odb, passing_commit_cases[4], strlen(passing_commit_cases[4]), GIT_OBJECT_COMMIT));

	cl_git_pass(git_commit_extract_signature(&signature, &signed_data, g_repo, &commit_id, NULL));
	cl_assert_equal_s(gpgsig, signature.ptr);
	cl_assert_equal_s(data, signed_data.ptr);

	git_buf_clear(&signature);
	git_buf_clear(&signed_data);

	cl_git_pass(git_commit_extract_signature(&signature, &signed_data, g_repo, &commit_id, "gpgsig"));
	cl_assert_equal_s(gpgsig, signature.ptr);
	cl_assert_equal_s(data, signed_data.ptr);

	/* Try to parse a tree */
	cl_git_pass(git_oid_fromstr(&commit_id, "45dd856fdd4d89b884c340ba0e047752d9b085d6"));
	cl_git_fail_with(GIT_ENOTFOUND, git_commit_extract_signature(&signature, &signed_data, g_repo, &commit_id, NULL));
	cl_assert_equal_i(GIT_ERROR_INVALID, git_error_last()->klass);

	/* Try to parse an unsigned commit */
	cl_git_pass(git_odb_write(&commit_id, odb, passing_commit_cases[1], strlen(passing_commit_cases[1]), GIT_OBJECT_COMMIT));
	cl_git_fail_with(GIT_ENOTFOUND, git_commit_extract_signature(&signature, &signed_data, g_repo, &commit_id, NULL));
	cl_assert_equal_i(GIT_ERROR_OBJECT, git_error_last()->klass);

	/* Parse the commit with a single-line signature */
	git_buf_clear(&signature);
	git_buf_clear(&signed_data);
	cl_git_pass(git_odb_write(&commit_id, odb, oneline_signature, strlen(oneline_signature), GIT_OBJECT_COMMIT));
	cl_git_pass(git_commit_extract_signature(&signature, &signed_data, g_repo, &commit_id, NULL));
	cl_assert_equal_s("bad", signature.ptr);
	cl_assert_equal_s(oneline_data, signed_data.ptr);


	git_buf_dispose(&signature);
	git_buf_dispose(&signed_data);

}

