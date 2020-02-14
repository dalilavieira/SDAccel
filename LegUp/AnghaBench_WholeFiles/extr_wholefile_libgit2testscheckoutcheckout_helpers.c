#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct timespec {int tv_nsec; scalar_t__ tv_sec; } ;
struct p_timeval {int tv_usec; scalar_t__ tv_sec; } ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_object ;
struct TYPE_20__ {struct timespec mtime; } ;
struct TYPE_21__ {TYPE_1__ stamp; int /*<<< orphan*/  on_disk; } ;
typedef  TYPE_2__ git_index ;
struct TYPE_22__ {char* path; } ;
typedef  TYPE_3__ git_diff_file ;
typedef  int git_checkout_notify_t ;
struct TYPE_23__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_4__ git_buf ;
struct TYPE_24__ {scalar_t__ debug; int /*<<< orphan*/  n_ignored; int /*<<< orphan*/  n_untracked; int /*<<< orphan*/  n_updates; int /*<<< orphan*/  n_dirty; int /*<<< orphan*/  n_conflicts; } ;
typedef  TYPE_5__ checkout_counts ;

/* Variables and functions */
 TYPE_4__ GIT_BUF_INIT ; 
 int GIT_CHECKOUT_NOTIFY_CONFLICT ; 
 int GIT_CHECKOUT_NOTIFY_DIRTY ; 
 int GIT_CHECKOUT_NOTIFY_IGNORED ; 
 int GIT_CHECKOUT_NOTIFY_UNTRACKED ; 
 int GIT_CHECKOUT_NOTIFY_UPDATED ; 
 int /*<<< orphan*/  GIT_HEAD_FILE ; 
 int /*<<< orphan*/  GIT_OBJECT_TREE ; 
 scalar_t__ GIT_REFERENCE_SYMBOLIC ; 
 int /*<<< orphan*/  GIT_UNUSED (TYPE_3__ const*) ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_ (int,char const*) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_4__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_4__*,char*,char const*) ; 
 int /*<<< orphan*/  git_index_free (TYPE_2__*) ; 
 int /*<<< orphan*/  git_index_path (TYPE_2__*) ; 
 int /*<<< orphan*/  git_index_read (TYPE_2__*,int) ; 
 int /*<<< orphan*/  git_index_read_tree (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_write (TYPE_2__*) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_object_owner (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_symbolic_target (int /*<<< orphan*/ *) ; 
 scalar_t__ git_reference_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (TYPE_2__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  p_utimes (int /*<<< orphan*/ ,struct p_timeval*) ; 
 int /*<<< orphan*/  stderr ; 

void assert_on_branch(git_repository *repo, const char *branch)
{
	git_reference *head;
	git_buf bname = GIT_BUF_INIT;

	cl_git_pass(git_reference_lookup(&head, repo, GIT_HEAD_FILE));
	cl_assert_(git_reference_type(head) == GIT_REFERENCE_SYMBOLIC, branch);

	cl_git_pass(git_buf_joinpath(&bname, "refs/heads", branch));
	cl_assert_equal_s(bname.ptr, git_reference_symbolic_target(head));

	git_reference_free(head);
	git_buf_dispose(&bname);
}

void reset_index_to_treeish(git_object *treeish)
{
	git_object *tree;
	git_index *index;
	git_repository *repo = git_object_owner(treeish);

	cl_git_pass(git_object_peel(&tree, treeish, GIT_OBJECT_TREE));

	cl_git_pass(git_repository_index(&index, repo));
	cl_git_pass(git_index_read_tree(index, (git_tree *)tree));
	cl_git_pass(git_index_write(index));

	git_object_free(tree);
	git_index_free(index);
}

int checkout_count_callback(
	git_checkout_notify_t why,
	const char *path,
	const git_diff_file *baseline,
	const git_diff_file *target,
	const git_diff_file *workdir,
	void *payload)
{
	checkout_counts *ct = payload;

	GIT_UNUSED(baseline); GIT_UNUSED(target); GIT_UNUSED(workdir);

	if (why & GIT_CHECKOUT_NOTIFY_CONFLICT) {
		ct->n_conflicts++;

		if (ct->debug) {
			if (workdir) {
				if (baseline) {
					if (target)
						fprintf(stderr, "M %s (conflicts with M %s)\n",
							workdir->path, target->path);
					else
						fprintf(stderr, "M %s (conflicts with D %s)\n",
							workdir->path, baseline->path);
				} else {
					if (target)
						fprintf(stderr, "Existing %s (conflicts with A %s)\n",
							workdir->path, target->path);
					else
						fprintf(stderr, "How can an untracked file be a conflict (%s)\n", workdir->path);
				}
			} else {
				if (baseline) {
					if (target)
						fprintf(stderr, "D %s (conflicts with M %s)\n",
							target->path, baseline->path);
					else
						fprintf(stderr, "D %s (conflicts with D %s)\n",
							baseline->path, baseline->path);
				} else {
					if (target)
						fprintf(stderr, "How can an added file with no workdir be a conflict (%s)\n", target->path);
					else
						fprintf(stderr, "How can a nonexistent file be a conflict (%s)\n", path);
				}
			}
		}
	}

	if (why & GIT_CHECKOUT_NOTIFY_DIRTY) {
		ct->n_dirty++;

		if (ct->debug) {
			if (workdir)
				fprintf(stderr, "M %s\n", workdir->path);
			else
				fprintf(stderr, "D %s\n", baseline->path);
		}
	}

	if (why & GIT_CHECKOUT_NOTIFY_UPDATED) {
		ct->n_updates++;

		if (ct->debug) {
			if (baseline) {
				if (target)
					fprintf(stderr, "update: M %s\n", path);
				else
					fprintf(stderr, "update: D %s\n", path);
			} else {
				if (target)
					fprintf(stderr, "update: A %s\n", path);
				else
					fprintf(stderr, "update: this makes no sense %s\n", path);
			}
		}
	}

	if (why & GIT_CHECKOUT_NOTIFY_UNTRACKED) {
		ct->n_untracked++;

		if (ct->debug)
			fprintf(stderr, "? %s\n", path);
	}

	if (why & GIT_CHECKOUT_NOTIFY_IGNORED) {
		ct->n_ignored++;

		if (ct->debug)
			fprintf(stderr, "I %s\n", path);
	}

	return 0;
}

void tick_index(git_index *index)
{
	struct timespec ts;
	struct p_timeval times[2];

	cl_assert(index->on_disk);
	cl_assert(git_index_path(index));

	cl_git_pass(git_index_read(index, true));
	ts = index->stamp.mtime;

	times[0].tv_sec = ts.tv_sec;
	times[0].tv_usec = ts.tv_nsec / 1000;
	times[1].tv_sec = ts.tv_sec + 5;
	times[1].tv_usec = ts.tv_nsec / 1000;

	cl_git_pass(p_utimes(git_index_path(index), times));
	cl_git_pass(git_index_read(index, true));
}

