#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char** strings; size_t count; } ;
typedef  TYPE_1__ git_strarray ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_8__ {char* name; char* fetchspec; int /*<<< orphan*/ * repository; int /*<<< orphan*/  flags; } ;
typedef  TYPE_2__ git_remote_create_options ;
typedef  int /*<<< orphan*/  git_remote ;
typedef  int /*<<< orphan*/  git_config ;

/* Variables and functions */
 size_t ARRAY_SIZE (char const**) ; 
 int /*<<< orphan*/  GIT_EEXISTS ; 
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 int /*<<< orphan*/  GIT_ERROR ; 
 TYPE_2__ GIT_REMOTE_CREATE_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_REMOTE_CREATE_SKIP_DEFAULT_FETCHSPEC ; 
 int /*<<< orphan*/  GIT_REMOTE_CREATE_SKIP_INSTEADOF ; 
 char* TEST_URL ; 
 int /*<<< orphan*/ * _config ; 
 int /*<<< orphan*/ * _repo ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,size_t) ; 
 int /*<<< orphan*/  cl_assert_equal_p (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 size_t count_config_entries_match (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int git_config_get_string (char const**,int /*<<< orphan*/ *,char*) ; 
 int git_config_set_string (int /*<<< orphan*/ *,char*,char*) ; 
 int git_remote_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*,char*) ; 
 int git_remote_create_anonymous (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int git_remote_create_detached (int /*<<< orphan*/ **,char*) ; 
 int git_remote_create_with_fetchspec (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,char*,char*) ; 
 int git_remote_create_with_opts (int /*<<< orphan*/ **,char const*,TYPE_2__*) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int git_remote_get_fetch_refspecs (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int git_remote_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 char* git_remote_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_remote_owner (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_remote_pushurl (int /*<<< orphan*/ *) ; 
 char* git_remote_url (int /*<<< orphan*/ *) ; 
 int git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int git_repository_config_snapshot (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int git_repository_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_1__*) ; 

void test_remote_create__initialize(void)
{
	cl_fixture_sandbox("testrepo.git");

	cl_git_pass(git_repository_open(&_repo, "testrepo.git"));

	cl_git_pass(git_repository_config(&_config, _repo));
}

void test_remote_create__cleanup(void)
{
	git_config_free(_config);

	git_repository_free(_repo);

	cl_fixture_cleanup("testrepo.git");
}

void test_remote_create__manual(void)
{
	git_remote *remote;
	cl_git_pass(git_config_set_string(_config, "remote.origin.fetch", "+refs/heads/*:refs/remotes/origin/*"));
	cl_git_pass(git_config_set_string(_config, "remote.origin.url", TEST_URL));

	cl_git_pass(git_remote_lookup(&remote, _repo, "origin"));
	cl_assert_equal_s(git_remote_name(remote), "origin");
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);

	git_remote_free(remote);
}

void test_remote_create__named(void)
{
	git_remote *remote;
	git_config *cfg;
	const char *cfg_val;

	size_t section_count = count_config_entries_match(_repo, "remote\\.");

	cl_git_pass(git_remote_create(&remote, _repo, "valid-name", TEST_URL));

	cl_assert_equal_s(git_remote_name(remote), "valid-name");
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_repository_config_snapshot(&cfg, _repo));

	cl_git_pass(git_config_get_string(&cfg_val, cfg, "remote.valid-name.fetch"));
	cl_assert_equal_s(cfg_val, "+refs/heads/*:refs/remotes/valid-name/*");

	cl_git_pass(git_config_get_string(&cfg_val, cfg, "remote.valid-name.url"));
	cl_assert_equal_s(cfg_val, TEST_URL);

	cl_assert_equal_i(section_count + 2, count_config_entries_match(_repo, "remote\\."));

	git_config_free(cfg);
	git_remote_free(remote);
}

void test_remote_create__named_fail_on_invalid_name(void)
{
	const char *names[] = {
		NULL,
		"Inv@{id",
		"",
		"/",
		"//",
		".lock",
		"a.lock",
	};
	size_t i;

	for (i = 0; i < ARRAY_SIZE(names); i++) {
		git_remote *remote = NULL;
		cl_git_fail_with(GIT_EINVALIDSPEC, git_remote_create(&remote, _repo, names[i], TEST_URL));
		cl_assert_equal_p(remote, NULL);
	}
}

void test_remote_create__named_fail_on_invalid_url(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_ERROR, git_remote_create(&remote, _repo, "bad-url", ""));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__named_fail_on_conflicting_name(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EEXISTS, git_remote_create(&remote, _repo, "test", TEST_URL));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__with_fetchspec(void)
{
	git_remote *remote;
	git_strarray array;
	size_t section_count = count_config_entries_match(_repo, "remote\\.");

	cl_git_pass(git_remote_create_with_fetchspec(&remote, _repo, "test-new", "git://github.com/libgit2/libgit2", "+refs/*:refs/*"));
	cl_assert_equal_s(git_remote_name(remote), "test-new");
	cl_assert_equal_s(git_remote_url(remote), "git://github.com/libgit2/libgit2");
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_s("+refs/*:refs/*", array.strings[0]);
	cl_assert_equal_i(1, array.count);
	cl_assert_equal_i(section_count + 2, count_config_entries_match(_repo, "remote\\."));

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__with_empty_fetchspec(void)
{
	git_remote *remote;
	git_strarray array;
	size_t section_count = count_config_entries_match(_repo, "remote\\.");

	cl_git_pass(git_remote_create_with_fetchspec(&remote, _repo, "test-new", "git://github.com/libgit2/libgit2", NULL));
	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);
	cl_assert_equal_i(section_count + 1, count_config_entries_match(_repo, "remote\\."));

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__with_fetchspec_invalid_name(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EINVALIDSPEC, git_remote_create_with_fetchspec(&remote, _repo, NULL, TEST_URL, NULL));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__with_fetchspec_invalid_url(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EINVALIDSPEC, git_remote_create_with_fetchspec(&remote, _repo, NULL, "", NULL));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__anonymous(void)
{
	git_remote *remote;
	git_strarray array;
	size_t section_count = count_config_entries_match(_repo, "remote\\.");

	cl_git_pass(git_remote_create_anonymous(&remote, _repo, TEST_URL));
	cl_assert_equal_s(git_remote_name(remote), NULL);
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);
	cl_assert_equal_i(section_count, count_config_entries_match(_repo, "remote\\."));

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__anonymous_invalid_url(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EINVALIDSPEC, git_remote_create_anonymous(&remote, _repo, ""));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__detached(void)
{
	git_remote *remote;
	git_strarray array;

	size_t section_count = count_config_entries_match(_repo, "remote\\.");

	cl_git_pass(git_remote_create_detached(&remote, TEST_URL));
	cl_assert_equal_s(git_remote_name(remote), NULL);
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), NULL);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);
	cl_assert_equal_i(section_count, count_config_entries_match(_repo, "remote\\."));

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__detached_invalid_url(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EINVALIDSPEC, git_remote_create_detached(&remote, ""));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__with_opts_named(void)
{
	git_remote *remote;
	git_strarray array;
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	opts.name = "test-new";
	opts.repository = _repo;

	cl_git_pass(git_remote_create_with_opts(&remote, TEST_URL, &opts));
	cl_assert_equal_s(git_remote_name(remote), "test-new");
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(1, array.count);
	cl_assert_equal_s("+refs/heads/*:refs/remotes/test-new/*", array.strings[0]);

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__with_opts_named_and_fetchspec(void)
{
	git_remote *remote;
	git_strarray array;
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	opts.name = "test-new";
	opts.repository = _repo;
	opts.fetchspec = "+refs/*:refs/*";

	cl_git_pass(git_remote_create_with_opts(&remote, TEST_URL, &opts));
	cl_assert_equal_s(git_remote_name(remote), "test-new");
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(1, array.count);
	cl_assert_equal_s("+refs/*:refs/*", array.strings[0]);

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__with_opts_named_no_fetchspec(void)
{
	git_remote *remote;
	git_strarray array;
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	opts.name = "test-new";
	opts.repository = _repo;
	opts.flags = GIT_REMOTE_CREATE_SKIP_DEFAULT_FETCHSPEC;

	cl_git_pass(git_remote_create_with_opts(&remote, TEST_URL, &opts));
	cl_assert_equal_s(git_remote_name(remote), "test-new");
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__with_opts_anonymous(void)
{
	git_remote *remote;
	git_strarray array;
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	opts.repository = _repo;

	cl_git_pass(git_remote_create_with_opts(&remote, TEST_URL, &opts));
	cl_assert_equal_s(git_remote_name(remote), NULL);
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), _repo);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);

	git_strarray_free(&array);
	git_remote_free(remote);
}

void test_remote_create__with_opts_detached(void)
{
	git_remote *remote;
	git_strarray array;
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	cl_git_pass(git_remote_create_with_opts(&remote, TEST_URL, &opts));
	cl_assert_equal_s(git_remote_name(remote), NULL);
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), NULL);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);

	git_strarray_free(&array);

	git_remote_free(remote);

	cl_git_pass(git_remote_create_with_opts(&remote, TEST_URL, NULL));
	cl_assert_equal_s(git_remote_name(remote), NULL);
	cl_assert_equal_s(git_remote_url(remote), TEST_URL);
	cl_assert_equal_p(git_remote_owner(remote), NULL);

	cl_git_pass(git_remote_get_fetch_refspecs(&array, remote));
	cl_assert_equal_i(0, array.count);

	git_strarray_free(&array);

	git_remote_free(remote);
}

void test_remote_create__with_opts_insteadof_disabled(void)
{
	git_remote *remote;
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	opts.repository = _repo;
	opts.flags = GIT_REMOTE_CREATE_SKIP_INSTEADOF;

	cl_git_pass(git_remote_create_with_opts(&remote, "http://example.com/libgit2/libgit2", &opts));

	cl_assert_equal_s(git_remote_url(remote), "http://example.com/libgit2/libgit2");
	cl_assert_equal_p(git_remote_pushurl(remote), NULL);

	git_remote_free(remote);
}

__attribute__((used)) static int create_with_name(git_remote **remote, git_repository *repo, const char *name, const char *url)
{
	git_remote_create_options opts = GIT_REMOTE_CREATE_OPTIONS_INIT;

	opts.repository = repo;
	opts.name = name;

	return git_remote_create_with_opts(remote, url, &opts);
}

void test_remote_create__with_opts_invalid_name(void)
{
	const char *names[] = {
		"Inv@{id",
		"",
		"/",
		"//",
		".lock",
		"a.lock",
	};
	size_t i;

	for (i = 0; i < ARRAY_SIZE(names); i++) {
		git_remote *remote = NULL;
		cl_git_fail_with(GIT_EINVALIDSPEC, create_with_name(&remote, _repo, names[i], TEST_URL));
		cl_assert_equal_p(remote, NULL);
	}
}

void test_remote_create__with_opts_conflicting_name(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EEXISTS, create_with_name(&remote, _repo, "test", TEST_URL));
	cl_assert_equal_p(remote, NULL);
}

void test_remote_create__with_opts_invalid_url(void)
{
	git_remote *remote = NULL;

	cl_git_fail_with(GIT_EINVALIDSPEC, create_with_name(&remote, _repo, "test-new", ""));
	cl_assert_equal_p(remote, NULL);
}

