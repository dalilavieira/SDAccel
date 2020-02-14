#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;
typedef  struct TYPE_21__   TYPE_12__ ;
typedef  struct TYPE_20__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_describe_result ;
struct TYPE_22__ {char* ptr; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_buf ;
struct TYPE_21__ {int always_use_long_format; int /*<<< orphan*/ * dirty_suffix; int /*<<< orphan*/  abbreviated_size; } ;
struct TYPE_20__ {int show_commit_oid_as_fallback; int only_follow_first_parent; int /*<<< orphan*/  pattern; scalar_t__ max_candidates_tags; int /*<<< orphan*/  describe_strategy; } ;
struct TYPE_23__ {int commit_count; char const** commits; TYPE_12__ format_options; TYPE_10__ describe_options; } ;
typedef  TYPE_2__ describe_options ;
struct TYPE_24__ {int pos; } ;
typedef  TYPE_3__ args_info ;

/* Variables and functions */
 TYPE_3__ ARGS_INFO_INIT ; 
 int /*<<< orphan*/  GIT_DESCRIBE_ALL ; 
 int /*<<< orphan*/  GIT_DESCRIBE_FORMAT_OPTIONS_VERSION ; 
 int /*<<< orphan*/  GIT_DESCRIBE_OPTIONS_VERSION ; 
 int /*<<< orphan*/  GIT_DESCRIBE_TAGS ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fatal (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_describe_commit (int /*<<< orphan*/ **,int /*<<< orphan*/ *,TYPE_10__*) ; 
 int /*<<< orphan*/  git_describe_format (TYPE_1__*,int /*<<< orphan*/ *,TYPE_12__*) ; 
 int /*<<< orphan*/  git_describe_init_format_options (TYPE_12__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_describe_init_options (TYPE_10__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_describe_workdir (int /*<<< orphan*/ **,int /*<<< orphan*/ *,TYPE_10__*) ; 
 int /*<<< orphan*/  git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ match_int_arg (int*,TYPE_3__*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ match_str_arg (int /*<<< orphan*/ *,TYPE_3__*,char*) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ optional_str_arg (int /*<<< orphan*/ **,TYPE_3__*,char*,char*) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 char const** xrealloc (char const**,size_t) ; 

__attribute__((used)) static void opts_add_commit(describe_options *opts, const char *commit)
{
	size_t sz;

	assert(opts != NULL);

	sz = ++opts->commit_count * sizeof(opts->commits[0]);
	opts->commits = xrealloc(opts->commits, sz);
	opts->commits[opts->commit_count - 1] = commit;
}

__attribute__((used)) static void do_describe_single(git_repository *repo, describe_options *opts, const char *rev)
{
	git_object *commit;
	git_describe_result *describe_result;
	git_buf buf = { 0 };
	
	if (rev) {
		check_lg2(git_revparse_single(&commit, repo, rev),
			"Failed to lookup rev", rev);

		check_lg2(git_describe_commit(&describe_result, commit, &opts->describe_options),
			"Failed to describe rev", rev);
	}
	else
		check_lg2(git_describe_workdir(&describe_result, repo, &opts->describe_options),
			"Failed to describe workdir", NULL);

	check_lg2(git_describe_format(&buf, describe_result, &opts->format_options),
			"Failed to format describe rev", rev);

	printf("%s\n", buf.ptr);
}

__attribute__((used)) static void do_describe(git_repository *repo, describe_options *opts)
{
	if (opts->commit_count == 0)
		do_describe_single(repo, opts, NULL);
	else
	{
		size_t i;
		for (i = 0; i < opts->commit_count; i++)
			do_describe_single(repo, opts, opts->commits[i]);
	}
}

__attribute__((used)) static void print_usage(void)
{
	fprintf(stderr, "usage: see `git help describe`\n");
	exit(1);
}

__attribute__((used)) static void parse_options(describe_options *opts, int argc, char **argv)
{
	args_info args = ARGS_INFO_INIT;

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		const char *curr = argv[args.pos];

		if (curr[0] != '-') {
			opts_add_commit(opts, curr);
		} else if (!strcmp(curr, "--all")) {
			opts->describe_options.describe_strategy = GIT_DESCRIBE_ALL;
		} else if (!strcmp(curr, "--tags")) {
			opts->describe_options.describe_strategy = GIT_DESCRIBE_TAGS;
		} else if (!strcmp(curr, "--exact-match")) {
			opts->describe_options.max_candidates_tags = 0;
		} else if (!strcmp(curr, "--long")) {
			opts->format_options.always_use_long_format = 1;
		} else if (!strcmp(curr, "--always")) {
			opts->describe_options.show_commit_oid_as_fallback = 1;
		} else if (!strcmp(curr, "--first-parent")) {
			opts->describe_options.only_follow_first_parent = 1;
		} else if (optional_str_arg(&opts->format_options.dirty_suffix, &args, "--dirty", "-dirty")) {
		} else if (match_int_arg((int *)&opts->format_options.abbreviated_size, &args, "--abbrev", 0)) {
		} else if (match_int_arg((int *)&opts->describe_options.max_candidates_tags, &args, "--candidates", 0)) {
		} else if (match_str_arg(&opts->describe_options.pattern, &args, "--match")) {
		} else {
			print_usage();
		}
	}

	if (opts->commit_count > 0) {
		if (opts->format_options.dirty_suffix)
			fatal("--dirty is incompatible with commit-ishes", NULL);
	}
	else {
		if (!opts->format_options.dirty_suffix || !opts->format_options.dirty_suffix[0]) {
			opts_add_commit(opts, "HEAD");
		}
	}
}

__attribute__((used)) static void describe_options_init(describe_options *opts)
{
	memset(opts, 0, sizeof(*opts));

	opts->commits = NULL;
	opts->commit_count = 0;
	git_describe_init_options(&opts->describe_options, GIT_DESCRIBE_OPTIONS_VERSION);
	git_describe_init_format_options(&opts->format_options, GIT_DESCRIBE_FORMAT_OPTIONS_VERSION);
}

int lg2_describe(git_repository *repo, int argc, char **argv)
{
	describe_options opts;

	describe_options_init(&opts);
	parse_options(&opts, argc, argv);

	do_describe(repo, &opts);

	return 0;
}

