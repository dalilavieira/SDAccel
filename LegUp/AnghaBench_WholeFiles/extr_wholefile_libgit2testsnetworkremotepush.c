#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {char** member_0; int member_1; } ;
typedef  TYPE_2__ git_strarray ;
typedef  int /*<<< orphan*/  git_signature ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reference ;
struct TYPE_11__ {char* src_refname; char* dst_refname; int /*<<< orphan*/  src; int /*<<< orphan*/  dst; } ;
typedef  TYPE_3__ git_push_update ;
struct TYPE_9__ {int (* push_negotiation ) (TYPE_3__ const**,size_t,void*) ;TYPE_3__* payload; } ;
struct TYPE_12__ {TYPE_1__ callbacks; } ;
typedef  TYPE_4__ git_push_options ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 TYPE_4__ GIT_PUSH_OPTIONS_INIT ; 
 int /*<<< orphan*/ * _dummy ; 
 int /*<<< orphan*/ * _remote ; 
 int /*<<< orphan*/ * _repo ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,size_t) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,char*) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_fixture_sandbox (char*) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_path_url (char*) ; 
 int /*<<< orphan*/  git_commit_create_from_ids (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_write_tree (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_reference_target (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_remote_push (int /*<<< orphan*/ *,TYPE_2__ const*,TYPE_4__*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_init (int /*<<< orphan*/ **,char*,int) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,char*) ; 
 int /*<<< orphan*/  git_signature_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_signature_now (int /*<<< orphan*/ **,char*,char*) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

void test_network_remote_push__initialize(void)
{
	cl_fixture_sandbox("testrepo.git");
	git_repository_open(&_repo, "testrepo.git");

	/* We need a repository to have a remote */
	cl_git_pass(git_repository_init(&_dummy, "dummy.git", true));
	cl_git_pass(git_remote_create(&_remote, _dummy, "origin", cl_git_path_url("testrepo.git")));
}

void test_network_remote_push__cleanup(void)
{
	git_remote_free(_remote);
	_remote = NULL;

	git_repository_free(_repo);
	_repo = NULL;

	git_repository_free(_dummy);
	_dummy = NULL;

	cl_fixture_cleanup("testrepo.git");
	cl_fixture_cleanup("dummy.git");
}

int negotiation_cb(const git_push_update **updates, size_t len, void *payload)
{
	const git_push_update *expected = payload;

	cl_assert_equal_i(1, len);
	cl_assert_equal_s(expected->src_refname, updates[0]->src_refname);
	cl_assert_equal_s(expected->dst_refname, updates[0]->dst_refname);
	cl_assert_equal_oid(&expected->src, &updates[0]->src);
	cl_assert_equal_oid(&expected->dst, &updates[0]->dst);

	return 0;
}

void test_network_remote_push__delete_notification(void)
{
	git_push_options opts = GIT_PUSH_OPTIONS_INIT;
	git_reference *ref;
	git_push_update expected;
	char *refspec = ":refs/heads/master";
	const git_strarray refspecs = {
		&refspec,
		1,
	};

	cl_git_pass(git_reference_lookup(&ref, _repo, "refs/heads/master"));

	expected.src_refname = "";
	expected.dst_refname = "refs/heads/master";
	memset(&expected.dst, 0, sizeof(git_oid));
	git_oid_cpy(&expected.src, git_reference_target(ref));

	opts.callbacks.push_negotiation = negotiation_cb;
	opts.callbacks.payload = &expected;
	cl_git_pass(git_remote_push(_remote, &refspecs, &opts));

	git_reference_free(ref);
	cl_git_fail_with(GIT_ENOTFOUND, git_reference_lookup(&ref, _repo, "refs/heads/master"));

}

void create_dummy_commit(git_reference **out, git_repository *repo)
{
	git_index *index;
	git_oid tree_id, commit_id;
	git_signature *sig;

	cl_git_pass(git_repository_index(&index, repo));
	cl_git_pass(git_index_write_tree(&tree_id, index));
	git_index_free(index);

	cl_git_pass(git_signature_now(&sig, "Pusher Joe", "pjoe"));
	cl_git_pass(git_commit_create_from_ids(&commit_id, repo, NULL, sig, sig,
					       NULL, "Empty tree\n", &tree_id, 0, NULL));
	cl_git_pass(git_reference_create(out, repo, "refs/heads/empty-tree", &commit_id, true, "commit yo"));
	git_signature_free(sig);
}

void test_network_remote_push__create_notification(void)
{
	git_push_options opts = GIT_PUSH_OPTIONS_INIT;
	git_reference *ref;
	git_push_update expected;
	char *refspec = "refs/heads/empty-tree";
	const git_strarray refspecs = {
		&refspec,
		1,
	};

	create_dummy_commit(&ref, _dummy);

	expected.src_refname = "refs/heads/empty-tree";
	expected.dst_refname = "refs/heads/empty-tree";
	git_oid_cpy(&expected.dst, git_reference_target(ref));
	memset(&expected.src, 0, sizeof(git_oid));

	opts.callbacks.push_negotiation = negotiation_cb;
	opts.callbacks.payload = &expected;
	cl_git_pass(git_remote_push(_remote, &refspecs, &opts));

	git_reference_free(ref);
	cl_git_pass(git_reference_lookup(&ref, _repo, "refs/heads/empty-tree"));
	git_reference_free(ref);
}

