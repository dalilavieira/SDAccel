#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_10__ ;

/* Type definitions */
struct TYPE_18__ {int id_abbrev; int /*<<< orphan*/  new_prefix; int /*<<< orphan*/  old_prefix; int /*<<< orphan*/  interhunk_lines; int /*<<< orphan*/  context_lines; int /*<<< orphan*/  flags; } ;
struct TYPE_15__ {int flags; int rename_threshold; int copy_threshold; } ;
struct opts {int member_2; char* member_8; char* treeish1; char* treeish2; scalar_t__ cache; int output; scalar_t__ color; int /*<<< orphan*/  dir; TYPE_3__ diffopts; TYPE_10__ findopts; void* format; int /*<<< orphan*/ * member_7; int /*<<< orphan*/ * member_6; void* member_5; int /*<<< orphan*/  member_4; int /*<<< orphan*/  member_3; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct args_info {int pos; } ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_diff_stats_format_t ;
typedef  int /*<<< orphan*/  git_diff_stats ;
struct TYPE_16__ {int origin; } ;
typedef  TYPE_1__ git_diff_line ;
typedef  int /*<<< orphan*/  git_diff_hunk ;
typedef  int /*<<< orphan*/  git_diff_delta ;
typedef  int /*<<< orphan*/  git_diff ;
struct TYPE_17__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_2__ git_buf ;

/* Variables and functions */
 struct args_info ARGS_INFO_INIT ; 
 scalar_t__ CACHE_NONE ; 
 scalar_t__ CACHE_NORMAL ; 
 scalar_t__ CACHE_ONLY ; 
 TYPE_2__ GIT_BUF_INIT_CONST (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int GIT_DIFF_FIND_ALL ; 
 int GIT_DIFF_FIND_COPIES ; 
 int GIT_DIFF_FIND_COPIES_FROM_UNMODIFIED ; 
 int /*<<< orphan*/  GIT_DIFF_FIND_OPTIONS_INIT ; 
 int GIT_DIFF_FIND_RENAMES ; 
 int GIT_DIFF_FIND_REWRITES ; 
 int /*<<< orphan*/  GIT_DIFF_FORCE_TEXT ; 
 void* GIT_DIFF_FORMAT_NAME_ONLY ; 
 void* GIT_DIFF_FORMAT_NAME_STATUS ; 
 void* GIT_DIFF_FORMAT_PATCH ; 
 void* GIT_DIFF_FORMAT_RAW ; 
 int /*<<< orphan*/  GIT_DIFF_IGNORE_WHITESPACE ; 
 int /*<<< orphan*/  GIT_DIFF_IGNORE_WHITESPACE_CHANGE ; 
 int /*<<< orphan*/  GIT_DIFF_IGNORE_WHITESPACE_EOL ; 
 int /*<<< orphan*/  GIT_DIFF_INCLUDE_IGNORED ; 
 int /*<<< orphan*/  GIT_DIFF_INCLUDE_UNTRACKED ; 
#define  GIT_DIFF_LINE_ADDITION 133 
#define  GIT_DIFF_LINE_ADD_EOFNL 132 
#define  GIT_DIFF_LINE_DELETION 131 
#define  GIT_DIFF_LINE_DEL_EOFNL 130 
#define  GIT_DIFF_LINE_FILE_HDR 129 
#define  GIT_DIFF_LINE_HUNK_HDR 128 
 int /*<<< orphan*/  GIT_DIFF_MINIMAL ; 
 int /*<<< orphan*/  GIT_DIFF_OPTIONS_INIT ; 
 int /*<<< orphan*/  GIT_DIFF_PATIENCE ; 
 int /*<<< orphan*/  GIT_DIFF_REVERSE ; 
 int /*<<< orphan*/  GIT_DIFF_STATS_FULL ; 
 int /*<<< orphan*/  GIT_DIFF_STATS_INCLUDE_SUMMARY ; 
 int /*<<< orphan*/  GIT_DIFF_STATS_NUMBER ; 
 int /*<<< orphan*/  GIT_DIFF_STATS_SHORT ; 
 int OUTPUT_DIFF ; 
 int OUTPUT_NUMSTAT ; 
 int OUTPUT_SHORTSTAT ; 
 int OUTPUT_STAT ; 
 int OUTPUT_SUMMARY ; 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
static  int color_printer (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_1__ const*,void*) ; 
 int /*<<< orphan*/ * colors ; 
 int diff_output (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_1__ const*,int /*<<< orphan*/ ) ; 
static  void diff_print_stats (int /*<<< orphan*/ *,struct opts*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fputs (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_2__*) ; 
 int /*<<< orphan*/  git_diff_find_similar (int /*<<< orphan*/ *,TYPE_10__*) ; 
 int /*<<< orphan*/  git_diff_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_get_stats (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_index_to_workdir (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  git_diff_print (int /*<<< orphan*/ *,void*,int (*) (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_1__ const*,void*),scalar_t__*) ; 
 int /*<<< orphan*/  git_diff_stats_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_stats_to_buf (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  git_diff_tree_to_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  git_diff_tree_to_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  git_diff_tree_to_workdir (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  git_diff_tree_to_workdir_with_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 scalar_t__ is_prefixed (char const*,char*) ; 
 int /*<<< orphan*/  match_str_arg (int /*<<< orphan*/ *,struct args_info*,char*) ; 
 scalar_t__ match_uint16_arg (int*,struct args_info*,char*) ; 
 int /*<<< orphan*/  match_uint32_arg (int /*<<< orphan*/ *,struct args_info*,char*) ; 
static  void parse_opts (struct opts*,int,char**) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  treeish_to_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 

int lg2_diff(git_repository *repo, int argc, char *argv[])
{
	git_tree *t1 = NULL, *t2 = NULL;
	git_diff *diff;
	struct opts o = {
		GIT_DIFF_OPTIONS_INIT, GIT_DIFF_FIND_OPTIONS_INIT,
		-1, 0, 0, GIT_DIFF_FORMAT_PATCH, NULL, NULL, "."
	};

	parse_opts(&o, argc, argv);

	/**
	 * Possible argument patterns:
	 *
	 *  * &lt;sha1&gt; &lt;sha2&gt;
	 *  * &lt;sha1&gt; --cached
	 *  * &lt;sha1&gt;
	 *  * --cached
	 *  * --nocache (don't use index data in diff at all)
	 *  * nothing
	 *
	 * Currently ranged arguments like &lt;sha1&gt;..&lt;sha2&gt; and &lt;sha1&gt;...&lt;sha2&gt;
	 * are not supported in this example
	 */

	if (o.treeish1)
		treeish_to_tree(&t1, repo, o.treeish1);
	if (o.treeish2)
		treeish_to_tree(&t2, repo, o.treeish2);

	if (t1 && t2)
		check_lg2(
			git_diff_tree_to_tree(&diff, repo, t1, t2, &o.diffopts),
			"diff trees", NULL);
	else if (o.cache != CACHE_NORMAL) {
		if (!t1)
			treeish_to_tree(&t1, repo, "HEAD");

		if (o.cache == CACHE_NONE)
			check_lg2(
				git_diff_tree_to_workdir(&diff, repo, t1, &o.diffopts),
				"diff tree to working directory", NULL);
		else
			check_lg2(
				git_diff_tree_to_index(&diff, repo, t1, NULL, &o.diffopts),
				"diff tree to index", NULL);
	}
	else if (t1)
		check_lg2(
			git_diff_tree_to_workdir_with_index(&diff, repo, t1, &o.diffopts),
			"diff tree to working directory", NULL);
	else
		check_lg2(
			git_diff_index_to_workdir(&diff, repo, NULL, &o.diffopts),
			"diff index to working directory", NULL);

	/** Apply rename and copy detection if requested. */

	if ((o.findopts.flags & GIT_DIFF_FIND_ALL) != 0)
		check_lg2(
			git_diff_find_similar(diff, &o.findopts),
			"finding renames and copies", NULL);

	/** Generate simple output using libgit2 display helper. */

	if (!o.output)
		o.output = OUTPUT_DIFF;

	if (o.output != OUTPUT_DIFF)
		diff_print_stats(diff, &o);

	if ((o.output & OUTPUT_DIFF) != 0) {
		if (o.color >= 0)
			fputs(colors[0], stdout);

		check_lg2(
			git_diff_print(diff, o.format, color_printer, &o.color),
			"displaying diff", NULL);

		if (o.color >= 0)
			fputs(colors[0], stdout);
	}

	/** Cleanup before exiting. */
	git_diff_free(diff);
	git_tree_free(t1);
	git_tree_free(t2);

	return 0;
}

__attribute__((used)) static void usage(const char *message, const char *arg)
{
	if (message && arg)
		fprintf(stderr, "%s: %s\n", message, arg);
	else if (message)
		fprintf(stderr, "%s\n", message);
	fprintf(stderr, "usage: diff [<tree-oid> [<tree-oid>]]\n");
	exit(1);
}

__attribute__((used)) static int color_printer(
	const git_diff_delta *delta,
	const git_diff_hunk *hunk,
	const git_diff_line *line,
	void *data)
{
	int *last_color = data, color = 0;

	(void)delta; (void)hunk;

	if (*last_color >= 0) {
		switch (line->origin) {
		case GIT_DIFF_LINE_ADDITION:  color = 3; break;
		case GIT_DIFF_LINE_DELETION:  color = 2; break;
		case GIT_DIFF_LINE_ADD_EOFNL: color = 3; break;
		case GIT_DIFF_LINE_DEL_EOFNL: color = 2; break;
		case GIT_DIFF_LINE_FILE_HDR:  color = 1; break;
		case GIT_DIFF_LINE_HUNK_HDR:  color = 4; break;
		default: break;
		}

		if (color != *last_color) {
			if (*last_color == 1 || color == 1)
				fputs(colors[0], stdout);
			fputs(colors[color], stdout);
			*last_color = color;
		}
	}

	return diff_output(delta, hunk, line, stdout);
}

__attribute__((used)) static void parse_opts(struct opts *o, int argc, char *argv[])
{
	struct args_info args = ARGS_INFO_INIT;


	for (args.pos = 1; args.pos < argc; ++args.pos) {
		const char *a = argv[args.pos];

		if (a[0] != '-') {
			if (o->treeish1 == NULL)
				o->treeish1 = a;
			else if (o->treeish2 == NULL)
				o->treeish2 = a;
			else
				usage("Only one or two tree identifiers can be provided", NULL);
		}
		else if (!strcmp(a, "-p") || !strcmp(a, "-u") ||
				 !strcmp(a, "--patch")) {
			o->output |= OUTPUT_DIFF;
			o->format = GIT_DIFF_FORMAT_PATCH;
		}
		else if (!strcmp(a, "--cached"))
			o->cache = CACHE_ONLY;
		else if (!strcmp(a, "--nocache"))
			o->cache = CACHE_NONE;
		else if (!strcmp(a, "--name-only") || !strcmp(a, "--format=name"))
			o->format = GIT_DIFF_FORMAT_NAME_ONLY;
		else if (!strcmp(a, "--name-status") ||
				!strcmp(a, "--format=name-status"))
			o->format = GIT_DIFF_FORMAT_NAME_STATUS;
		else if (!strcmp(a, "--raw") || !strcmp(a, "--format=raw"))
			o->format = GIT_DIFF_FORMAT_RAW;
		else if (!strcmp(a, "--format=diff-index")) {
			o->format = GIT_DIFF_FORMAT_RAW;
			o->diffopts.id_abbrev = 40;
		}
		else if (!strcmp(a, "--color"))
			o->color = 0;
		else if (!strcmp(a, "--no-color"))
			o->color = -1;
		else if (!strcmp(a, "-R"))
			o->diffopts.flags |= GIT_DIFF_REVERSE;
		else if (!strcmp(a, "-a") || !strcmp(a, "--text"))
			o->diffopts.flags |= GIT_DIFF_FORCE_TEXT;
		else if (!strcmp(a, "--ignore-space-at-eol"))
			o->diffopts.flags |= GIT_DIFF_IGNORE_WHITESPACE_EOL;
		else if (!strcmp(a, "-b") || !strcmp(a, "--ignore-space-change"))
			o->diffopts.flags |= GIT_DIFF_IGNORE_WHITESPACE_CHANGE;
		else if (!strcmp(a, "-w") || !strcmp(a, "--ignore-all-space"))
			o->diffopts.flags |= GIT_DIFF_IGNORE_WHITESPACE;
		else if (!strcmp(a, "--ignored"))
			o->diffopts.flags |= GIT_DIFF_INCLUDE_IGNORED;
		else if (!strcmp(a, "--untracked"))
			o->diffopts.flags |= GIT_DIFF_INCLUDE_UNTRACKED;
		else if (!strcmp(a, "--patience"))
			o->diffopts.flags |= GIT_DIFF_PATIENCE;
		else if (!strcmp(a, "--minimal"))
			o->diffopts.flags |= GIT_DIFF_MINIMAL;
		else if (!strcmp(a, "--stat"))
			o->output |= OUTPUT_STAT;
		else if (!strcmp(a, "--numstat"))
			o->output |= OUTPUT_NUMSTAT;
		else if (!strcmp(a, "--shortstat"))
			o->output |= OUTPUT_SHORTSTAT;
		else if (!strcmp(a, "--summary"))
			o->output |= OUTPUT_SUMMARY;
		else if (match_uint16_arg(
				&o->findopts.rename_threshold, &args, "-M") ||
			match_uint16_arg(
				&o->findopts.rename_threshold, &args, "--find-renames"))
			o->findopts.flags |= GIT_DIFF_FIND_RENAMES;
		else if (match_uint16_arg(
				&o->findopts.copy_threshold, &args, "-C") ||
			match_uint16_arg(
				&o->findopts.copy_threshold, &args, "--find-copies"))
			o->findopts.flags |= GIT_DIFF_FIND_COPIES;
		else if (!strcmp(a, "--find-copies-harder"))
			o->findopts.flags |= GIT_DIFF_FIND_COPIES_FROM_UNMODIFIED;
		else if (is_prefixed(a, "-B") || is_prefixed(a, "--break-rewrites"))
			/* TODO: parse thresholds */
			o->findopts.flags |= GIT_DIFF_FIND_REWRITES;
		else if (!match_uint32_arg(
				&o->diffopts.context_lines, &args, "-U") &&
			!match_uint32_arg(
				&o->diffopts.context_lines, &args, "--unified") &&
			!match_uint32_arg(
				&o->diffopts.interhunk_lines, &args, "--inter-hunk-context") &&
			!match_uint16_arg(
				&o->diffopts.id_abbrev, &args, "--abbrev") &&
			!match_str_arg(&o->diffopts.old_prefix, &args, "--src-prefix") &&
			!match_str_arg(&o->diffopts.new_prefix, &args, "--dst-prefix") &&
			!match_str_arg(&o->dir, &args, "--git-dir"))
			usage("Unknown command line argument", a);
	}
}

__attribute__((used)) static void diff_print_stats(git_diff *diff, struct opts *o)
{
	git_diff_stats *stats;
	git_buf b = GIT_BUF_INIT_CONST(NULL, 0);
	git_diff_stats_format_t format = 0;

	check_lg2(
		git_diff_get_stats(&stats, diff), "generating stats for diff", NULL);

	if (o->output & OUTPUT_STAT)
		format |= GIT_DIFF_STATS_FULL;
	if (o->output & OUTPUT_SHORTSTAT)
		format |= GIT_DIFF_STATS_SHORT;
	if (o->output & OUTPUT_NUMSTAT)
		format |= GIT_DIFF_STATS_NUMBER;
	if (o->output & OUTPUT_SUMMARY)
		format |= GIT_DIFF_STATS_INCLUDE_SUMMARY;

	check_lg2(
		git_diff_stats_to_buf(&b, stats, format, 80), "formatting stats", NULL);

	fputs(b.ptr, stdout);

	git_buf_dispose(&b);
	git_diff_stats_free(stats);
}

