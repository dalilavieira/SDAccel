#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct option {int dummy; } ;
struct object_id {int dummy; } ;
struct commit_list {TYPE_2__* item; struct commit_list* next; } ;
struct TYPE_6__ {int /*<<< orphan*/  oid; } ;
struct commit {TYPE_3__ object; } ;
struct TYPE_4__ {int /*<<< orphan*/  oid; } ;
struct TYPE_5__ {TYPE_1__ object; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALLOC_ARRAY (struct commit**,int) ; 
 int /*<<< orphan*/  N_ (char*) ; 
 struct option OPT_BOOL (char,char*,int*,int /*<<< orphan*/ ) ; 
 struct option OPT_CMDMODE (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ,float) ; 
 struct option OPT_END () ; 
 int /*<<< orphan*/  commit_list_insert (struct commit*,struct commit_list**) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int dwim_ref (char const*,int /*<<< orphan*/ ,struct object_id*,char**) ; 
 int /*<<< orphan*/  free_commit_list (struct commit_list*) ; 
 struct commit* get_fork_point (char*,struct commit*) ; 
 struct commit_list* get_merge_bases_many_dirty (struct commit*,int,struct commit**) ; 
 struct commit_list* get_octopus_merge_bases (struct commit_list*) ; 
 scalar_t__ get_oid (char const*,struct object_id*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_default_config ; 
 scalar_t__ in_merge_bases (struct commit*,struct commit*) ; 
 struct commit* lookup_commit_reference (int /*<<< orphan*/ ,struct object_id*) ; 
 int /*<<< orphan*/  merge_base_usage ; 
 char* oid_to_hex (int /*<<< orphan*/ *) ; 
 int parse_options (int,char const**,char const*,struct option*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  reduce_heads_replace (struct commit_list**) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  the_repository ; 
 int /*<<< orphan*/  usage_with_options (int /*<<< orphan*/ ,struct option*) ; 

__attribute__((used)) static int show_merge_base(struct commit **rev, int rev_nr, int show_all)
{
	struct commit_list *result, *r;

	result = get_merge_bases_many_dirty(rev[0], rev_nr - 1, rev + 1);

	if (!result)
		return 1;

	for (r = result; r; r = r->next) {
		printf("%s\n", oid_to_hex(&r->item->object.oid));
		if (!show_all)
			break;
	}

	free_commit_list(result);
	return 0;
}

__attribute__((used)) static struct commit *get_commit_reference(const char *arg)
{
	struct object_id revkey;
	struct commit *r;

	if (get_oid(arg, &revkey))
		die("Not a valid object name %s", arg);
	r = lookup_commit_reference(the_repository, &revkey);
	if (!r)
		die("Not a valid commit name %s", arg);

	return r;
}

__attribute__((used)) static int handle_independent(int count, const char **args)
{
	struct commit_list *revs = NULL, *rev;
	int i;

	for (i = count - 1; i >= 0; i--)
		commit_list_insert(get_commit_reference(args[i]), &revs);

	reduce_heads_replace(&revs);

	if (!revs)
		return 1;

	for (rev = revs; rev; rev = rev->next)
		printf("%s\n", oid_to_hex(&rev->item->object.oid));

	free_commit_list(revs);
	return 0;
}

__attribute__((used)) static int handle_octopus(int count, const char **args, int show_all)
{
	struct commit_list *revs = NULL;
	struct commit_list *result, *rev;
	int i;

	for (i = count - 1; i >= 0; i--)
		commit_list_insert(get_commit_reference(args[i]), &revs);

	result = get_octopus_merge_bases(revs);
	free_commit_list(revs);
	reduce_heads_replace(&result);

	if (!result)
		return 1;

	for (rev = result; rev; rev = rev->next) {
		printf("%s\n", oid_to_hex(&rev->item->object.oid));
		if (!show_all)
			break;
	}

	free_commit_list(result);
	return 0;
}

__attribute__((used)) static int handle_is_ancestor(int argc, const char **argv)
{
	struct commit *one, *two;

	if (argc != 2)
		die("--is-ancestor takes exactly two commits");
	one = get_commit_reference(argv[0]);
	two = get_commit_reference(argv[1]);
	if (in_merge_bases(one, two))
		return 0;
	else
		return 1;
}

__attribute__((used)) static int handle_fork_point(int argc, const char **argv)
{
	struct object_id oid;
	char *refname;
	struct commit *derived, *fork_point;
	const char *commitname;

	switch (dwim_ref(argv[0], strlen(argv[0]), &oid, &refname)) {
	case 0:
		die("No such ref: '%s'", argv[0]);
	case 1:
		break; /* good */
	default:
		die("Ambiguous refname: '%s'", argv[0]);
	}

	commitname = (argc == 2) ? argv[1] : "HEAD";
	if (get_oid(commitname, &oid))
		die("Not a valid object name: '%s'", commitname);

	derived = lookup_commit_reference(the_repository, &oid);

	fork_point = get_fork_point(refname, derived);

	if (!fork_point)
		return 1;

	printf("%s\n", oid_to_hex(&fork_point->object.oid));
	return 0;
}

int cmd_merge_base(int argc, const char **argv, const char *prefix)
{
	struct commit **rev;
	int rev_nr = 0;
	int show_all = 0;
	int cmdmode = 0;

	struct option options[] = {
		OPT_BOOL('a', "all", &show_all, N_("output all common ancestors")),
		OPT_CMDMODE(0, "octopus", &cmdmode,
			    N_("find ancestors for a single n-way merge"), 'o'),
		OPT_CMDMODE(0, "independent", &cmdmode,
			    N_("list revs not reachable from others"), 'r'),
		OPT_CMDMODE(0, "is-ancestor", &cmdmode,
			    N_("is the first one ancestor of the other?"), 'a'),
		OPT_CMDMODE(0, "fork-point", &cmdmode,
			    N_("find where <commit> forked from reflog of <ref>"), 'f'),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	argc = parse_options(argc, argv, prefix, options, merge_base_usage, 0);

	if (cmdmode == 'a') {
		if (argc < 2)
			usage_with_options(merge_base_usage, options);
		if (show_all)
			die("--is-ancestor cannot be used with --all");
		return handle_is_ancestor(argc, argv);
	}

	if (cmdmode == 'r' && show_all)
		die("--independent cannot be used with --all");

	if (cmdmode == 'o')
		return handle_octopus(argc, argv, show_all);

	if (cmdmode == 'r')
		return handle_independent(argc, argv);

	if (cmdmode == 'f') {
		if (argc < 1 || 2 < argc)
			usage_with_options(merge_base_usage, options);
		return handle_fork_point(argc, argv);
	}

	if (argc < 2)
		usage_with_options(merge_base_usage, options);

	ALLOC_ARRAY(rev, argc);
	while (argc-- > 0)
		rev[rev_nr++] = get_commit_reference(*argv++);
	return show_merge_base(rev, rev_nr, show_all);
}

