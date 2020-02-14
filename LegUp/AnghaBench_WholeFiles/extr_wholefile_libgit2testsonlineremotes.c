#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {size_t count; int /*<<< orphan*/ * strings; } ;
typedef  TYPE_1__ git_strarray ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_11__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_2__ git_remote_head ;
typedef  int /*<<< orphan*/  git_remote ;
struct TYPE_12__ {int (* remote_cb ) (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*,char const*,void*) ;char* checkout_branch; } ;
typedef  TYPE_3__ git_clone_options ;

/* Variables and functions */
 size_t ARRAY_SIZE (char const**) ; 
 TYPE_3__ GIT_CLONE_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_DIRECTION_FETCH ; 
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int /*<<< orphan*/  REFSPEC ; 
 int /*<<< orphan*/  URL ; 
 int /*<<< orphan*/  cl_assert_ (char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,size_t) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (size_t,int) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git__prefixcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_clone (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,TYPE_3__*) ; 
 int /*<<< orphan*/  git_reference_list (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_connect (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_create_detached (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_remote_create_with_fetchspec (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_remote_download (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_get_fetch_refspecs (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_remote_ls (TYPE_2__ const***,size_t*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_push (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_upload (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_1__*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static int remote_single_branch(git_remote **out, git_repository *repo, const char *name, const char *url, void *payload)
{
	GIT_UNUSED(payload);

	cl_git_pass(git_remote_create_with_fetchspec(out, repo, name, url, REFSPEC));

	return 0;
}

void test_online_remotes__single_branch(void)
{
	git_clone_options opts = GIT_CLONE_OPTIONS_INIT;
	git_repository *repo;
	git_remote *remote;
	git_strarray refs;
	size_t i, count = 0;

	opts.remote_cb = remote_single_branch;
	opts.checkout_branch = "first-merge";

	cl_git_pass(git_clone(&repo, URL, "./single-branch", &opts));
	cl_git_pass(git_reference_list(&refs, repo));

	for (i = 0; i < refs.count; i++) {
		if (!git__prefixcmp(refs.strings[i], "refs/heads/"))
			count++;
	}
	cl_assert_equal_i(1, count);

	git_strarray_free(&refs);

	cl_git_pass(git_remote_lookup(&remote, repo, "origin"));
	cl_git_pass(git_remote_get_fetch_refspecs(&refs, remote));

	cl_assert_equal_i(1, refs.count);
	cl_assert_equal_s(REFSPEC, refs.strings[0]);

	git_strarray_free(&refs);
	git_remote_free(remote);
	git_repository_free(repo);
}

void test_online_remotes__restricted_refspecs(void)
{
	git_clone_options opts = GIT_CLONE_OPTIONS_INIT;
	git_repository *repo;

	opts.remote_cb = remote_single_branch;

	cl_git_fail_with(GIT_EINVALIDSPEC, git_clone(&repo, URL, "./restrict-refspec", &opts));
}

void test_online_remotes__detached_remote_fails_downloading(void)
{
	git_remote *remote;

	cl_git_pass(git_remote_create_detached(&remote, URL));
	cl_git_pass(git_remote_connect(remote, GIT_DIRECTION_FETCH, NULL, NULL, NULL));
	cl_git_fail(git_remote_download(remote, NULL, NULL));

	git_remote_free(remote);
}

void test_online_remotes__detached_remote_fails_uploading(void)
{
	git_remote *remote;

	cl_git_pass(git_remote_create_detached(&remote, URL));
	cl_git_pass(git_remote_connect(remote, GIT_DIRECTION_FETCH, NULL, NULL, NULL));
	cl_git_fail(git_remote_upload(remote, NULL, NULL));

	git_remote_free(remote);
}

void test_online_remotes__detached_remote_fails_pushing(void)
{
	git_remote *remote;

	cl_git_pass(git_remote_create_detached(&remote, URL));
	cl_git_pass(git_remote_connect(remote, GIT_DIRECTION_FETCH, NULL, NULL, NULL));
	cl_git_fail(git_remote_push(remote, NULL, NULL));

	git_remote_free(remote);
}

void test_online_remotes__detached_remote_succeeds_ls(void)
{
	const char *refs[] = {
	    "HEAD",
	    "refs/heads/first-merge",
	    "refs/heads/master",
	    "refs/heads/no-parent",
	    "refs/tags/annotated_tag",
	    "refs/tags/annotated_tag^{}",
	    "refs/tags/blob",
	    "refs/tags/commit_tree",
	    "refs/tags/nearly-dangling",
	};
	const git_remote_head **heads;
	git_remote *remote;
	size_t i, j, n;

	cl_git_pass(git_remote_create_detached(&remote, URL));
	cl_git_pass(git_remote_connect(remote, GIT_DIRECTION_FETCH, NULL, NULL, NULL));
	cl_git_pass(git_remote_ls(&heads, &n, remote));

	cl_assert_equal_sz(n, 9);
	for (i = 0; i < n; i++) {
		char found = false;

		for (j = 0; j < ARRAY_SIZE(refs); j++) {
			if (!strcmp(heads[i]->name, refs[j])) {
				found = true;
				break;
			}
		}

		cl_assert_(found, heads[i]->name);
	}

	git_remote_free(remote);
}

