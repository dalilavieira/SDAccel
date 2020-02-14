#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_revwalk ;
struct TYPE_3__ {int flags; int /*<<< orphan*/ * to; int /*<<< orphan*/ * from; } ;
typedef  TYPE_1__ git_revspec ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;

/* Variables and functions */
 int GIT_EINVALIDSPEC ; 
 int GIT_OID_HEXSZ ; 
 int GIT_REVPARSE_MERGE_BASE ; 
 unsigned int GIT_SORT_NONE ; 
 unsigned int GIT_SORT_REVERSE ; 
 unsigned int GIT_SORT_TIME ; 
 unsigned int GIT_SORT_TOPOLOGICAL ; 
 int /*<<< orphan*/  check_lg2 (int,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_object_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fmt (char*,int /*<<< orphan*/ *) ; 
 int git_revparse (TYPE_1__*,int /*<<< orphan*/ *,char const*) ; 
 int git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int git_revwalk_hide (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int git_revwalk_new (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revwalk_next (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_revwalk_push (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_revwalk_sorting (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
static  int revwalk_parseopts (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,char**) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 scalar_t__ strstr (char*,char*) ; 

int lg2_rev_list(git_repository *repo, int argc, char **argv)
{
	git_revwalk *walk;
	git_oid oid;
	char buf[GIT_OID_HEXSZ+1];

	check_lg2(git_revwalk_new(&walk, repo), "allocating revwalk", NULL);
	check_lg2(revwalk_parseopts(repo, walk, argc-1, argv+1), "parsing options", NULL);

	while (!git_revwalk_next(&oid, walk)) {
		git_oid_fmt(buf, &oid);
		buf[GIT_OID_HEXSZ] = '\0';
		printf("%s\n", buf);
	}

	return 0;
}

__attribute__((used)) static int push_commit(git_revwalk *walk, const git_oid *oid, int hide)
{
	if (hide)
		return git_revwalk_hide(walk, oid);
	else
		return git_revwalk_push(walk, oid);
}

__attribute__((used)) static int push_spec(git_repository *repo, git_revwalk *walk, const char *spec, int hide)
{
	int error;
	git_object *obj;

	if ((error = git_revparse_single(&obj, repo, spec)) < 0)
		return error;

	error = push_commit(walk, git_object_id(obj), hide);
	git_object_free(obj);
	return error;
}

__attribute__((used)) static int push_range(git_repository *repo, git_revwalk *walk, const char *range, int hide)
{
	git_revspec revspec;
	int error = 0;

	if ((error = git_revparse(&revspec, repo, range)))
		return error;

	if (revspec.flags & GIT_REVPARSE_MERGE_BASE) {
		/* TODO: support "<commit>...<commit>" */
		return GIT_EINVALIDSPEC;
	}

	if ((error = push_commit(walk, git_object_id(revspec.from), !hide)))
		goto out;

	error = push_commit(walk, git_object_id(revspec.to), hide);

out:
	git_object_free(revspec.from);
	git_object_free(revspec.to);
	return error;
}

__attribute__((used)) static int revwalk_parseopts(git_repository *repo, git_revwalk *walk, int nopts, char **opts)
{
	int hide, i, error;
	unsigned int sorting = GIT_SORT_NONE;

	hide = 0;
	for (i = 0; i < nopts; i++) {
		if (!strcmp(opts[i], "--topo-order")) {
			sorting = GIT_SORT_TOPOLOGICAL | (sorting & GIT_SORT_REVERSE);
			git_revwalk_sorting(walk, sorting);
		} else if (!strcmp(opts[i], "--date-order")) {
			sorting = GIT_SORT_TIME | (sorting & GIT_SORT_REVERSE);
			git_revwalk_sorting(walk, sorting);
		} else if (!strcmp(opts[i], "--reverse")) {
			sorting = (sorting & ~GIT_SORT_REVERSE)
			    | ((sorting & GIT_SORT_REVERSE) ? 0 : GIT_SORT_REVERSE);
			git_revwalk_sorting(walk, sorting);
		} else if (!strcmp(opts[i], "--not")) {
			hide = !hide;
		} else if (opts[i][0] == '^') {
			if ((error = push_spec(repo, walk, opts[i] + 1, !hide)))
				return error;
		} else if (strstr(opts[i], "..")) {
			if ((error = push_range(repo, walk, opts[i], hide)))
				return error;
		} else {
			if ((error = push_spec(repo, walk, opts[i], hide)))
				return error;
		}
	}

	return 0;
}

