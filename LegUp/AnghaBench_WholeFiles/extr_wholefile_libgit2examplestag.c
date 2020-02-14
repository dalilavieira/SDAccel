#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
struct TYPE_26__ {TYPE_2__* opts; int /*<<< orphan*/ * repo; } ;
typedef  TYPE_1__ tag_state ;
struct TYPE_27__ {int num_lines; char* pattern; char const* tag_name; char* target; int force; char const* message; } ;
typedef  TYPE_2__ tag_options ;
typedef  void (* tag_action ) (TYPE_1__*) ;
typedef  int /*<<< orphan*/  git_tag ;
struct TYPE_28__ {size_t count; char** strings; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_4__ git_strarray ;
typedef  int /*<<< orphan*/  git_signature ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_commit ;
struct TYPE_29__ {char* ptr; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_5__ git_buf ;
struct TYPE_30__ {int pos; } ;
typedef  TYPE_6__ args_info ;

/* Variables and functions */
 TYPE_6__ ARGS_INFO_INIT ; 
#define  GIT_OBJECT_COMMIT 129 
#define  GIT_OBJECT_TAG 128 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fatal (char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_5__*) ; 
 char* git_commit_message (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_short_id (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int git_object_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_signature_default (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_signature_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_4__*) ; 
 int /*<<< orphan*/  git_tag_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  git_tag_create_lightweight (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_tag_delete (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_tag_list_match (TYPE_4__*,char const*,int /*<<< orphan*/ *) ; 
 char* git_tag_message (int /*<<< orphan*/ *) ; 
 char* git_tag_name (int /*<<< orphan*/ *) ; 
 scalar_t__ match_int_arg (int*,TYPE_6__*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ match_str_arg (char const**,TYPE_6__*,char*) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static void check(int result, const char *message)
{
	if (result) fatal(message, NULL);
}

__attribute__((used)) static void print_list_lines(const char *message, const tag_state *state)
{
	const char *msg = message;
	int num = state->opts->num_lines - 1;

	if (!msg) return;

	/** first line - headline */
	while(*msg && *msg != '\n') printf("%c", *msg++);

	/** skip over new lines */
	while(*msg && *msg == '\n') msg++;

	printf("\n");

	/** print just headline? */
	if (num == 0) return;
	if (*msg && msg[1]) printf("\n");

	/** print individual commit/tag lines */
	while (*msg && num-- >= 2) {
		printf("    ");

		while (*msg && *msg != '\n') printf("%c", *msg++);

		/** handle consecutive new lines */
		if (*msg && *msg == '\n' && msg[1] == '\n') {
			num--;
			printf("\n");
		}
		while(*msg && *msg == '\n') msg++;

		printf("\n");
	}
}

__attribute__((used)) static void print_tag(git_tag *tag, const tag_state *state)
{
	printf("%-16s", git_tag_name(tag));

	if (state->opts->num_lines) {
		const char *msg = git_tag_message(tag);
		print_list_lines(msg, state);
	} else {
		printf("\n");
	}
}

__attribute__((used)) static void print_commit(git_commit *commit, const char *name,
		const tag_state *state)
{
	printf("%-16s", name);

	if (state->opts->num_lines) {
		const char *msg = git_commit_message(commit);
		print_list_lines(msg, state);
	} else {
		printf("\n");
	}
}

__attribute__((used)) static void print_name(const char *name)
{
	printf("%s\n", name);
}

__attribute__((used)) static int each_tag(const char *name, tag_state *state)
{
	git_repository *repo = state->repo;
	git_object *obj;

	check_lg2(git_revparse_single(&obj, repo, name),
			"Failed to lookup rev", name);

	switch (git_object_type(obj)) {
		case GIT_OBJECT_TAG:
			print_tag((git_tag *) obj, state);
			break;
		case GIT_OBJECT_COMMIT:
			print_commit((git_commit *) obj, name, state);
			break;
		default:
			print_name(name);
	}

	git_object_free(obj);
	return 0;
}

__attribute__((used)) static void action_list_tags(tag_state *state)
{
	const char *pattern = state->opts->pattern;
	git_strarray tag_names = {0};
	size_t i;

	check_lg2(git_tag_list_match(&tag_names, pattern ? pattern : "*", state->repo),
			"Unable to get list of tags", NULL);

	for(i = 0; i < tag_names.count; i++) {
		each_tag(tag_names.strings[i], state);
	}

	git_strarray_free(&tag_names);
}

__attribute__((used)) static void action_delete_tag(tag_state *state)
{
	tag_options *opts = state->opts;
	git_object *obj;
	git_buf abbrev_oid = {0};

	check(!opts->tag_name, "Name required");

	check_lg2(git_revparse_single(&obj, state->repo, opts->tag_name),
			"Failed to lookup rev", opts->tag_name);

	check_lg2(git_object_short_id(&abbrev_oid, obj),
			"Unable to get abbreviated OID", opts->tag_name);

	check_lg2(git_tag_delete(state->repo, opts->tag_name),
			"Unable to delete tag", opts->tag_name);

	printf("Deleted tag '%s' (was %s)\n", opts->tag_name, abbrev_oid.ptr);

	git_buf_dispose(&abbrev_oid);
	git_object_free(obj);
}

__attribute__((used)) static void action_create_lighweight_tag(tag_state *state)
{
	git_repository *repo = state->repo;
	tag_options *opts = state->opts;
	git_oid oid;
	git_object *target;

	check(!opts->tag_name, "Name required");

	if (!opts->target) opts->target = "HEAD";

	check(!opts->target, "Target required");

	check_lg2(git_revparse_single(&target, repo, opts->target),
			"Unable to resolve spec", opts->target);

	check_lg2(git_tag_create_lightweight(&oid, repo, opts->tag_name,
				target, opts->force), "Unable to create tag", NULL);

	git_object_free(target);
}

__attribute__((used)) static void action_create_tag(tag_state *state)
{
	git_repository *repo = state->repo;
	tag_options *opts = state->opts;
	git_signature *tagger;
	git_oid oid;
	git_object *target;

	check(!opts->tag_name, "Name required");
	check(!opts->message, "Message required");

	if (!opts->target) opts->target = "HEAD";

	check_lg2(git_revparse_single(&target, repo, opts->target),
			"Unable to resolve spec", opts->target);

	check_lg2(git_signature_default(&tagger, repo),
			"Unable to create signature", NULL);

	check_lg2(git_tag_create(&oid, repo, opts->tag_name,
				target, tagger, opts->message, opts->force), "Unable to create tag", NULL);

	git_object_free(target);
	git_signature_free(tagger);
}

__attribute__((used)) static void print_usage(void)
{
	fprintf(stderr, "usage: see `git help tag`\n");
	exit(1);
}

__attribute__((used)) static void parse_options(tag_action *action, tag_options *opts, int argc, char **argv)
{
	args_info args = ARGS_INFO_INIT;
	*action = &action_list_tags;

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		const char *curr = argv[args.pos];

		if (curr[0] != '-') {
			if (!opts->tag_name)
				opts->tag_name = curr;
			else if (!opts->target)
				opts->target = curr;
			else
				print_usage();

			if (*action != &action_create_tag)
				*action = &action_create_lighweight_tag;
		} else if (!strcmp(curr, "-n")) {
			opts->num_lines = 1;
			*action = &action_list_tags;
		} else if (!strcmp(curr, "-a")) {
			*action = &action_create_tag;
		} else if (!strcmp(curr, "-f")) {
			opts->force = 1;
		} else if (match_int_arg(&opts->num_lines, &args, "-n", 0)) {
			*action = &action_list_tags;
		} else if (match_str_arg(&opts->pattern, &args, "-l")) {
			*action = &action_list_tags;
		} else if (match_str_arg(&opts->tag_name, &args, "-d")) {
			*action = &action_delete_tag;
		} else if (match_str_arg(&opts->message, &args, "-m")) {
			*action = &action_create_tag;
		}
	}
}

__attribute__((used)) static void tag_options_init(tag_options *opts)
{
	memset(opts, 0, sizeof(*opts));

	opts->message   = NULL;
	opts->pattern   = NULL;
	opts->tag_name  = NULL;
	opts->target    = NULL;
	opts->num_lines = 0;
	opts->force     = 0;
}

int lg2_tag(git_repository *repo, int argc, char **argv)
{
	tag_options opts;
	tag_action action;
	tag_state state;

	tag_options_init(&opts);
	parse_options(&action, &opts, argc, argv);

	state.repo = repo;
	state.opts = &opts;
	action(&state);

	return 0;
}

