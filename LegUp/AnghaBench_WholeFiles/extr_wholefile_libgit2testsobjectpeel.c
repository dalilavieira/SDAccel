#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  git_oid ;
typedef  int git_object_t ;
typedef  int /*<<< orphan*/  git_object ;

/* Variables and functions */
 int GIT_EINVALIDSPEC ; 
 int GIT_EPEEL ; 
 int GIT_OBJECT_ANY ; 
 int GIT_OBJECT_BLOB ; 
 int GIT_OBJECT_COMMIT ; 
 int GIT_OBJECT_TAG ; 
 int GIT_OBJECT_TREE ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_object_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_object_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

void test_object_peel__initialize(void)
{
	cl_git_pass(git_repository_open(&g_repo, cl_fixture("testrepo.git")));
}

void test_object_peel__cleanup(void)
{
	git_repository_free(g_repo);
	g_repo = NULL;
}

__attribute__((used)) static void assert_peel(
	const char *sha,
	git_object_t requested_type,
	const char* expected_sha,
	git_object_t expected_type)
{
	git_oid oid, expected_oid;
	git_object *obj;
	git_object *peeled;

	cl_git_pass(git_oid_fromstr(&oid, sha));
	cl_git_pass(git_object_lookup(&obj, g_repo, &oid, GIT_OBJECT_ANY));

	cl_git_pass(git_object_peel(&peeled, obj, requested_type));

	cl_git_pass(git_oid_fromstr(&expected_oid, expected_sha));
	cl_assert_equal_oid(&expected_oid, git_object_id(peeled));

	cl_assert_equal_i(expected_type, git_object_type(peeled));

	git_object_free(peeled);
	git_object_free(obj);
}

__attribute__((used)) static void assert_peel_error(int error, const char *sha, git_object_t requested_type)
{
	git_oid oid;
	git_object *obj;
	git_object *peeled;

	cl_git_pass(git_oid_fromstr(&oid, sha));
	cl_git_pass(git_object_lookup(&obj, g_repo, &oid, GIT_OBJECT_ANY));

	cl_assert_equal_i(error, git_object_peel(&peeled, obj, requested_type));

	git_object_free(obj);
}

void test_object_peel__peeling_an_object_into_its_own_type_returns_another_instance_of_it(void)
{
	assert_peel("e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT,
		"e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT);
	assert_peel("7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_TAG,
		"7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_TAG);
	assert_peel("53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE,
		"53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE);
	assert_peel("0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_BLOB,
		"0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_BLOB);
}

void test_object_peel__tag(void)
{
	assert_peel("7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_COMMIT,
		"e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT);
	assert_peel("7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_TREE,
		"53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE);
	assert_peel_error(GIT_EPEEL, "7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_BLOB);
	assert_peel("7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_ANY,
		    "e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT);
}

void test_object_peel__commit(void)
{
	assert_peel_error(GIT_EINVALIDSPEC, "e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_BLOB);
	assert_peel("e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_TREE,
		    "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE);
	assert_peel("e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT,
		    "e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT);
	assert_peel_error(GIT_EINVALIDSPEC, "e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_TAG);
	assert_peel("e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_ANY,
		    "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE);
}

void test_object_peel__tree(void)
{
	assert_peel_error(GIT_EINVALIDSPEC, "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_BLOB);
	assert_peel("53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE,
		    "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE);
	assert_peel_error(GIT_EINVALIDSPEC, "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_COMMIT);
	assert_peel_error(GIT_EINVALIDSPEC, "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TAG);
	assert_peel_error(GIT_EINVALIDSPEC, "53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_ANY);
}

void test_object_peel__blob(void)
{
	assert_peel("0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_BLOB,
		    "0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_BLOB);
	assert_peel_error(GIT_EINVALIDSPEC, "0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_TREE);
	assert_peel_error(GIT_EINVALIDSPEC, "0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_COMMIT);
	assert_peel_error(GIT_EINVALIDSPEC, "0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_TAG);
	assert_peel_error(GIT_EINVALIDSPEC, "0266163a49e280c4f5ed1e08facd36a2bd716bcf", GIT_OBJECT_ANY);
}

void test_object_peel__target_any_object_for_type_change(void)
{
	/* tag to commit */
	assert_peel("7b4384978d2493e851f9cca7858815fac9b10980", GIT_OBJECT_ANY,
		"e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_COMMIT);

	/* commit to tree */
	assert_peel("e90810b8df3e80c413d903f631643c716887138d", GIT_OBJECT_ANY,
		"53fc32d17276939fc79ed05badaef2db09990016", GIT_OBJECT_TREE);
}

