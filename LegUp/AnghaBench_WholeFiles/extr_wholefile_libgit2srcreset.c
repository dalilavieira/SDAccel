#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_tree ;
struct TYPE_23__ {scalar_t__ count; } ;
typedef  TYPE_3__ git_strarray ;
typedef  scalar_t__ git_reset_t ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  const git_object ;
struct TYPE_24__ {char* path; int /*<<< orphan*/  id; int /*<<< orphan*/  mode; } ;
typedef  TYPE_4__ git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;
struct TYPE_25__ {int /*<<< orphan*/  flags; TYPE_3__ pathspec; } ;
typedef  TYPE_5__ git_diff_options ;
struct TYPE_22__ {scalar_t__ path; int /*<<< orphan*/  id; int /*<<< orphan*/  mode; } ;
struct TYPE_21__ {int /*<<< orphan*/  path; } ;
struct TYPE_26__ {scalar_t__ status; TYPE_2__ new_file; TYPE_1__ old_file; } ;
typedef  TYPE_6__ git_diff_delta ;
typedef  int /*<<< orphan*/  git_diff ;
typedef  int /*<<< orphan*/  git_commit ;
struct TYPE_27__ {int /*<<< orphan*/  checkout_strategy; } ;
typedef  TYPE_7__ git_checkout_options ;
typedef  int /*<<< orphan*/  git_buf ;
struct TYPE_28__ {char* description; scalar_t__ commit; } ;
typedef  TYPE_8__ git_annotated_commit ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR_MSG ; 
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_CHECKOUT_FORCE ; 
 TYPE_7__ GIT_CHECKOUT_OPTIONS_INIT ; 
 scalar_t__ GIT_DELTA_ADDED ; 
 scalar_t__ GIT_DELTA_CONFLICTED ; 
 scalar_t__ GIT_DELTA_DELETED ; 
 scalar_t__ GIT_DELTA_MODIFIED ; 
 TYPE_5__ GIT_DIFF_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_DIFF_REVERSE ; 
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_ERROR_INDEX ; 
 int /*<<< orphan*/  GIT_ERROR_OBJECT ; 
 int GIT_EUNMERGED ; 
 int /*<<< orphan*/  GIT_HEAD_FILE ; 
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 scalar_t__ GIT_REPOSITORY_STATE_MERGE ; 
 scalar_t__ GIT_RESET_HARD ; 
 scalar_t__ GIT_RESET_MIXED ; 
 scalar_t__ GIT_RESET_SOFT ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int git_buf_printf (int /*<<< orphan*/ *,char*,char const*) ; 
 int git_checkout_tree (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,TYPE_7__*) ; 
 int git_commit_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_free (int /*<<< orphan*/ *) ; 
 TYPE_6__* git_diff_get_delta (int /*<<< orphan*/ *,size_t) ; 
 size_t git_diff_num_deltas (int /*<<< orphan*/ *) ; 
 int git_diff_tree_to_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*) ; 
 int /*<<< orphan*/  git_error_clear () ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int git_index_add (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int git_index_conflict_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_index_has_conflicts (int /*<<< orphan*/ *) ; 
 int git_index_read_tree (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_index_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int git_index_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * git_object_owner (int /*<<< orphan*/  const*) ; 
 int git_object_peel (int /*<<< orphan*/  const**,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* git_oid_tostr_s (int /*<<< orphan*/ ) ; 
 int git_reference__update_terminal (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_repository__ensure_not_bare (int /*<<< orphan*/ *,char*) ; 
 int git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 scalar_t__ git_repository_state (int /*<<< orphan*/ *) ; 
 int git_repository_state_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 

int git_reset_default(
	git_repository *repo,
	const git_object *target,
	const git_strarray* pathspecs)
{
	git_object *commit = NULL;
	git_tree *tree = NULL;
	git_diff *diff = NULL;
	git_diff_options opts = GIT_DIFF_OPTIONS_INIT;
	size_t i, max_i;
	git_index_entry entry;
	int error;
	git_index *index = NULL;

	assert(pathspecs != NULL && pathspecs->count > 0);

	memset(&entry, 0, sizeof(git_index_entry));

	if ((error = git_repository_index(&index, repo)) < 0)
		goto cleanup;

	if (target) {
		if (git_object_owner(target) != repo) {
			git_error_set(GIT_ERROR_OBJECT,
				"%s_default - The given target does not belong to this repository.", ERROR_MSG);
			return -1;
		}

		if ((error = git_object_peel(&commit, target, GIT_OBJECT_COMMIT)) < 0 ||
			(error = git_commit_tree(&tree, (git_commit *)commit)) < 0)
			goto cleanup;
	}

	opts.pathspec = *pathspecs;
	opts.flags = GIT_DIFF_REVERSE;

	if ((error = git_diff_tree_to_index(
		&diff, repo, tree, index, &opts)) < 0)
			goto cleanup;

	for (i = 0, max_i = git_diff_num_deltas(diff); i < max_i; ++i) {
		const git_diff_delta *delta = git_diff_get_delta(diff, i);

		assert(delta->status == GIT_DELTA_ADDED ||
			delta->status == GIT_DELTA_MODIFIED ||
			delta->status == GIT_DELTA_CONFLICTED ||
			delta->status == GIT_DELTA_DELETED);

		error = git_index_conflict_remove(index, delta->old_file.path);
		if (error < 0) {
			if (delta->status == GIT_DELTA_ADDED && error == GIT_ENOTFOUND)
				git_error_clear();
			else
				goto cleanup;
		}

		if (delta->status == GIT_DELTA_DELETED) {
			if ((error = git_index_remove(index, delta->old_file.path, 0)) < 0)
				goto cleanup;
		} else {
			entry.mode = delta->new_file.mode;
			git_oid_cpy(&entry.id, &delta->new_file.id);
			entry.path = (char *)delta->new_file.path;

			if ((error = git_index_add(index, &entry)) < 0)
				goto cleanup;
		}
	}

	error = git_index_write(index);

cleanup:
	git_object_free(commit);
	git_tree_free(tree);
	git_index_free(index);
	git_diff_free(diff);

	return error;
}

__attribute__((used)) static int reset(
	git_repository *repo,
	const git_object *target,
	const char *to,
	git_reset_t reset_type,
	const git_checkout_options *checkout_opts)
{
	git_object *commit = NULL;
	git_index *index = NULL;
	git_tree *tree = NULL;
	int error = 0;
	git_checkout_options opts = GIT_CHECKOUT_OPTIONS_INIT;
	git_buf log_message = GIT_BUF_INIT;

	assert(repo && target);

	if (checkout_opts)
		opts = *checkout_opts;

	if (git_object_owner(target) != repo) {
		git_error_set(GIT_ERROR_OBJECT,
			"%s - The given target does not belong to this repository.", ERROR_MSG);
		return -1;
	}

	if (reset_type != GIT_RESET_SOFT &&
		(error = git_repository__ensure_not_bare(repo,
			reset_type == GIT_RESET_MIXED ? "reset mixed" : "reset hard")) < 0)
		return error;

	if ((error = git_object_peel(&commit, target, GIT_OBJECT_COMMIT)) < 0 ||
		(error = git_repository_index(&index, repo)) < 0 ||
		(error = git_commit_tree(&tree, (git_commit *)commit)) < 0)
		goto cleanup;

	if (reset_type == GIT_RESET_SOFT &&
		(git_repository_state(repo) == GIT_REPOSITORY_STATE_MERGE ||
		 git_index_has_conflicts(index)))
	{
		git_error_set(GIT_ERROR_OBJECT, "%s (soft) in the middle of a merge", ERROR_MSG);
		error = GIT_EUNMERGED;
		goto cleanup;
	}

	if ((error = git_buf_printf(&log_message, "reset: moving to %s", to)) < 0)
		return error;

	if (reset_type == GIT_RESET_HARD) {
		/* overwrite working directory with the new tree */
		opts.checkout_strategy = GIT_CHECKOUT_FORCE;

		if ((error = git_checkout_tree(repo, (git_object *)tree, &opts)) < 0)
			goto cleanup;
	}

	/* move HEAD to the new target */
	if ((error = git_reference__update_terminal(repo, GIT_HEAD_FILE,
		git_object_id(commit), NULL, git_buf_cstr(&log_message))) < 0)
		goto cleanup;

	if (reset_type > GIT_RESET_SOFT) {
		/* reset index to the target content */

		if ((error = git_index_read_tree(index, tree)) < 0 ||
			(error = git_index_write(index)) < 0)
			goto cleanup;

		if ((error = git_repository_state_cleanup(repo)) < 0) {
			git_error_set(GIT_ERROR_INDEX, "%s - failed to clean up merge data", ERROR_MSG);
			goto cleanup;
		}
	}

cleanup:
	git_object_free(commit);
	git_index_free(index);
	git_tree_free(tree);
	git_buf_dispose(&log_message);

	return error;
}

int git_reset(
	git_repository *repo,
	const git_object *target,
	git_reset_t reset_type,
	const git_checkout_options *checkout_opts)
{
	return reset(repo, target, git_oid_tostr_s(git_object_id(target)), reset_type, checkout_opts);
}

int git_reset_from_annotated(
	git_repository *repo,
	const git_annotated_commit *commit,
	git_reset_t reset_type,
	const git_checkout_options *checkout_opts)
{
	return reset(repo, (git_object *) commit->commit, commit->description, reset_type, checkout_opts);
}

