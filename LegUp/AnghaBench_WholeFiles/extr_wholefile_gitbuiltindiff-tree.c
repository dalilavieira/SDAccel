#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct object_id {int dummy; } ;
struct TYPE_8__ {struct object_id oid; } ;
struct tree {TYPE_1__ object; } ;
struct setup_revision_opt {void (* tweak ) (struct rev_info*,struct setup_revision_opt*) ;} ;
struct TYPE_12__ {int needed_rename_limit; int degraded_cc_to_c; int /*<<< orphan*/  setup; scalar_t__ detect_rename; scalar_t__ output_format; } ;
struct TYPE_9__ {int nr; TYPE_3__* objects; } ;
struct rev_info {int diff; int disable_stdin; TYPE_5__ diffopt; TYPE_2__ pending; scalar_t__ abbrev; scalar_t__ dense_combined_merges; } ;
struct object {scalar_t__ type; int flags; struct object_id oid; } ;
struct commit_list {int dummy; } ;
struct commit {struct commit_list* parents; } ;
typedef  int /*<<< orphan*/  s_r_opt ;
typedef  int /*<<< orphan*/  line ;
struct TYPE_13__ {struct commit_list* next; } ;
struct TYPE_11__ {int /*<<< orphan*/  cache; } ;
struct TYPE_10__ {struct object* item; } ;

/* Variables and functions */
 scalar_t__ DIFF_FORMAT_PATCH ; 
 scalar_t__ DIFF_FORMAT_RAW ; 
 int /*<<< orphan*/  DIFF_SETUP_USE_SIZE_CACHE ; 
 scalar_t__ OBJ_COMMIT ; 
 scalar_t__ OBJ_TREE ; 
 int /*<<< orphan*/  SWAP (struct object*,struct object*) ; 
 int UNINTERESTING ; 
 int /*<<< orphan*/  _ (char*) ; 
 TYPE_7__* commit_list_insert (struct commit*,struct commit_list**) ; 
 int /*<<< orphan*/  die (int /*<<< orphan*/ ) ; 
 int diff_result_code (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  diff_tree_oid (struct object_id*,struct object_id*,char*,TYPE_5__*) ; 
 int /*<<< orphan*/  diff_tree_usage ; 
 int error (char*,...) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 scalar_t__ fgets (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_commit_list (struct commit_list*) ; 
 scalar_t__ get_oid_hex (char*,struct object_id*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_basic_config ; 
 scalar_t__ isspace (int /*<<< orphan*/ ) ; 
 int log_tree_commit (struct rev_info*,struct commit*) ; 
 int /*<<< orphan*/  log_tree_diff_flush (struct rev_info*) ; 
 struct rev_info log_tree_opt ; 
 struct commit* lookup_commit (int /*<<< orphan*/ ,struct object_id*) ; 
 struct commit* lookup_commit_reference (int /*<<< orphan*/ ,struct object_id const*) ; 
 struct tree* lookup_tree (int /*<<< orphan*/ ,struct object_id*) ; 
 int /*<<< orphan*/  memset (struct setup_revision_opt*,int /*<<< orphan*/ ,int) ; 
 char* oid_to_hex (struct object_id*) ; 
 struct object* parse_object (int /*<<< orphan*/ ,struct object_id*) ; 
 scalar_t__ parse_oid_hex (char const*,struct object_id*,char const**) ; 
 scalar_t__ parse_tree (struct tree*) ; 
 int /*<<< orphan*/  precompose_argv (int,char const**) ; 
 int /*<<< orphan*/  printf (char*,char*,char*) ; 
 scalar_t__ read_cache () ; 
 int /*<<< orphan*/  repo_init_revisions (int /*<<< orphan*/ ,struct rev_info*,char const*) ; 
 int /*<<< orphan*/  repo_read_index (int /*<<< orphan*/ ) ; 
 int setup_revisions (int,char const**,struct rev_info*,struct setup_revision_opt*) ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int strlen (char*) ; 
 TYPE_4__ the_index ; 
 int /*<<< orphan*/  the_repository ; 
 char* type_name (scalar_t__) ; 
 int /*<<< orphan*/  usage (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int diff_tree_commit_oid(const struct object_id *oid)
{
	struct commit *commit = lookup_commit_reference(the_repository, oid);
	if (!commit)
		return -1;
	return log_tree_commit(&log_tree_opt, commit);
}

__attribute__((used)) static int stdin_diff_commit(struct commit *commit, const char *p)
{
	struct object_id oid;
	struct commit_list **pptr = NULL;

	/* Graft the fake parents locally to the commit */
	while (isspace(*p++) && !parse_oid_hex(p, &oid, &p)) {
		struct commit *parent = lookup_commit(the_repository, &oid);
		if (!pptr) {
			/* Free the real parent list */
			free_commit_list(commit->parents);
			commit->parents = NULL;
			pptr = &(commit->parents);
		}
		if (parent) {
			pptr = &commit_list_insert(parent, pptr)->next;
		}
	}
	return log_tree_commit(&log_tree_opt, commit);
}

__attribute__((used)) static int stdin_diff_trees(struct tree *tree1, const char *p)
{
	struct object_id oid;
	struct tree *tree2;
	if (!isspace(*p++) || parse_oid_hex(p, &oid, &p) || *p)
		return error("Need exactly two trees, separated by a space");
	tree2 = lookup_tree(the_repository, &oid);
	if (!tree2 || parse_tree(tree2))
		return -1;
	printf("%s %s\n", oid_to_hex(&tree1->object.oid),
			  oid_to_hex(&tree2->object.oid));
	diff_tree_oid(&tree1->object.oid, &tree2->object.oid,
		      "", &log_tree_opt.diffopt);
	log_tree_diff_flush(&log_tree_opt);
	return 0;
}

__attribute__((used)) static int diff_tree_stdin(char *line)
{
	int len = strlen(line);
	struct object_id oid;
	struct object *obj;
	const char *p;

	if (!len || line[len-1] != '\n')
		return -1;
	line[len-1] = 0;
	if (parse_oid_hex(line, &oid, &p))
		return -1;
	obj = parse_object(the_repository, &oid);
	if (!obj)
		return -1;
	if (obj->type == OBJ_COMMIT)
		return stdin_diff_commit((struct commit *)obj, p);
	if (obj->type == OBJ_TREE)
		return stdin_diff_trees((struct tree *)obj, p);
	error("Object %s is a %s, not a commit or tree",
	      oid_to_hex(&oid), type_name(obj->type));
	return -1;
}

__attribute__((used)) static void diff_tree_tweak_rev(struct rev_info *rev, struct setup_revision_opt *opt)
{
	if (!rev->diffopt.output_format) {
		if (rev->dense_combined_merges)
			rev->diffopt.output_format = DIFF_FORMAT_PATCH;
		else
			rev->diffopt.output_format = DIFF_FORMAT_RAW;
	}
}

int cmd_diff_tree(int argc, const char **argv, const char *prefix)
{
	char line[1000];
	struct object *tree1, *tree2;
	static struct rev_info *opt = &log_tree_opt;
	struct setup_revision_opt s_r_opt;
	int read_stdin = 0;

	if (argc == 2 && !strcmp(argv[1], "-h"))
		usage(diff_tree_usage);

	git_config(git_diff_basic_config, NULL); /* no "diff" UI options */
	repo_init_revisions(the_repository, opt, prefix);
	if (read_cache() < 0)
		die(_("index file corrupt"));
	opt->abbrev = 0;
	opt->diff = 1;
	opt->disable_stdin = 1;
	memset(&s_r_opt, 0, sizeof(s_r_opt));
	s_r_opt.tweak = diff_tree_tweak_rev;

	precompose_argv(argc, argv);
	argc = setup_revisions(argc, argv, opt, &s_r_opt);

	while (--argc > 0) {
		const char *arg = *++argv;

		if (!strcmp(arg, "--stdin")) {
			read_stdin = 1;
			continue;
		}
		usage(diff_tree_usage);
	}

	/*
	 * NOTE!  We expect "a..b" to expand to "^a b" but it is
	 * perfectly valid for revision range parser to yield "b ^a",
	 * which means the same thing. If we get the latter, i.e. the
	 * second one is marked UNINTERESTING, we recover the original
	 * order the user gave, i.e. "a..b", by swapping the trees.
	 */
	switch (opt->pending.nr) {
	case 0:
		if (!read_stdin)
			usage(diff_tree_usage);
		break;
	case 1:
		tree1 = opt->pending.objects[0].item;
		diff_tree_commit_oid(&tree1->oid);
		break;
	case 2:
		tree1 = opt->pending.objects[0].item;
		tree2 = opt->pending.objects[1].item;
		if (tree2->flags & UNINTERESTING) {
			SWAP(tree2, tree1);
		}
		diff_tree_oid(&tree1->oid, &tree2->oid, "", &opt->diffopt);
		log_tree_diff_flush(opt);
		break;
	}

	if (read_stdin) {
		int saved_nrl = 0;
		int saved_dcctc = 0;

		if (opt->diffopt.detect_rename) {
			if (!the_index.cache)
				repo_read_index(the_repository);
			opt->diffopt.setup |= DIFF_SETUP_USE_SIZE_CACHE;
		}
		while (fgets(line, sizeof(line), stdin)) {
			struct object_id oid;

			if (get_oid_hex(line, &oid)) {
				fputs(line, stdout);
				fflush(stdout);
			}
			else {
				diff_tree_stdin(line);
				if (saved_nrl < opt->diffopt.needed_rename_limit)
					saved_nrl = opt->diffopt.needed_rename_limit;
				if (opt->diffopt.degraded_cc_to_c)
					saved_dcctc = 1;
			}
		}
		opt->diffopt.degraded_cc_to_c = saved_dcctc;
		opt->diffopt.needed_rename_limit = saved_nrl;
	}

	return diff_result_code(&opt->diffopt, 0);
}

