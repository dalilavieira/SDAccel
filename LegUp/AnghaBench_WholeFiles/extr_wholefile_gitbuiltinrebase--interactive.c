#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  buf; } ;
struct todo_list {TYPE_1__ buf; } ;
struct string_list {int dummy; } ;
struct replay_opts {unsigned int allow_ff; unsigned int allow_empty_message; unsigned int signoff; char const* strategy; unsigned int reschedule_failed_exec; int allow_empty; int /*<<< orphan*/  gpg_sign; int /*<<< orphan*/  action; int /*<<< orphan*/  allow_rerere_auto; int /*<<< orphan*/  verbose; } ;
struct option {char member_1; char* member_2; intptr_t member_8; int /*<<< orphan*/ * member_7; int /*<<< orphan*/  member_6; int /*<<< orphan*/  member_5; int /*<<< orphan*/  member_4; int /*<<< orphan*/ * member_3; int /*<<< orphan*/  member_0; } ;
struct object_id {int dummy; } ;
struct child_process {int git_cmd; int /*<<< orphan*/  args; } ;
struct argv_array {int /*<<< orphan*/  argv; int /*<<< orphan*/  argc; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 struct argv_array ARGV_ARRAY_INIT ; 
 int /*<<< orphan*/  BUG (char*,...) ; 
 struct child_process CHILD_PROCESS_INIT ; 
 int /*<<< orphan*/  DEFAULT_ABBREV ; 
 int /*<<< orphan*/  GIT_MAX_HEXSZ ; 
 int /*<<< orphan*/  N_ (char*) ; 
 int /*<<< orphan*/  OPTION_STRING ; 
 struct option OPT_BOOL (int /*<<< orphan*/ ,char*,...) ; 
 struct option OPT_CMDMODE (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ,int) ; 
 struct option OPT_END () ; 
 struct option OPT_RERERE_AUTOUPDATE (int /*<<< orphan*/ *) ; 
 struct option OPT_STRING (int /*<<< orphan*/ ,char*,char const**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct option OPT__VERBOSE (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PARSE_OPT_KEEP_ARGV0 ; 
 int /*<<< orphan*/  PARSE_OPT_OPTARG ; 
 int /*<<< orphan*/  REPLAY_INTERACTIVE_REBASE ; 
 struct replay_opts REPLAY_OPTS_INIT ; 
 struct string_list STRING_LIST_INIT_DUP ; 
 unsigned int TODO_LIST_ABBREVIATE_CMDS ; 
 struct todo_list TODO_LIST_INIT ; 
 unsigned int TODO_LIST_KEEP_EMPTY ; 
 unsigned int TODO_LIST_REBASE_COUSINS ; 
 unsigned int TODO_LIST_REBASE_MERGES ; 
 unsigned int TODO_LIST_SHORTEN_IDS ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  argv_array_clear (struct argv_array*) ; 
 int /*<<< orphan*/  argv_array_push (struct argv_array*,char const*) ; 
 int /*<<< orphan*/  argv_array_pushl (struct argv_array*,char*,char*,char*,...) ; 
 int /*<<< orphan*/  builtin_rebase_interactive_usage ; 
 int check_todo_list_from_file (int /*<<< orphan*/ ) ; 
 int complete_action (int /*<<< orphan*/ ,struct replay_opts*,unsigned int,char*,char const*,char const*,char const*,struct string_list*,unsigned int,struct todo_list*) ; 
 int /*<<< orphan*/  delete_reflog (char*) ; 
 int /*<<< orphan*/  die (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  discard_cache () ; 
 int edit_todo_list (int /*<<< orphan*/ ,struct todo_list*,struct todo_list*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int error (int /*<<< orphan*/ ,...) ; 
 int error_errno (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 char* find_unique_abbrev (struct object_id*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * fopen (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ get_oid (char const*,struct object_id*) ; 
 int /*<<< orphan*/  git_config_get_bool (char*,int*) ; 
 int /*<<< orphan*/  is_directory (int /*<<< orphan*/ ) ; 
 scalar_t__ mkdir_in_gitdir (int /*<<< orphan*/ ) ; 
 int parse_options (int,char const**,int /*<<< orphan*/ *,struct option*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  parse_strategy_opts (struct replay_opts*,char*) ; 
 int /*<<< orphan*/  path_interactive () ; 
 int /*<<< orphan*/  path_squash_onto () ; 
 int /*<<< orphan*/  path_state_dir () ; 
 scalar_t__ prepare_branch_to_be_rebased (struct replay_opts*,char const*) ; 
 char* rebase_path_todo () ; 
 int /*<<< orphan*/  rerere_clear (int /*<<< orphan*/ ,struct string_list*) ; 
 int run_command (struct child_process*) ; 
 int sequencer_continue (int /*<<< orphan*/ ,struct replay_opts*) ; 
 int /*<<< orphan*/  sequencer_init_config (struct replay_opts*) ; 
 int sequencer_make_script (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ strbuf_read_file (TYPE_1__*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strbuf_stripspace (TYPE_1__*,int) ; 
 int /*<<< orphan*/  string_list_clear (struct string_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_list_remove_empty_items (struct string_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_list_split (struct string_list*,char const*,char,int) ; 
 int /*<<< orphan*/  the_repository ; 
 int /*<<< orphan*/  todo_list_add_exec_commands (struct todo_list*,struct string_list*) ; 
 scalar_t__ todo_list_parse_insn_buffer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct todo_list*) ; 
 int todo_list_rearrange_squash (struct todo_list*) ; 
 int /*<<< orphan*/  todo_list_release (struct todo_list*) ; 
 int todo_list_write_to_file (int /*<<< orphan*/ ,struct todo_list*,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,unsigned int) ; 
 int /*<<< orphan*/  usage_with_options (int /*<<< orphan*/ ,struct option*) ; 
 int /*<<< orphan*/  warning (int /*<<< orphan*/ ) ; 
 int write_basic_state (struct replay_opts*,char const*,char const*,char const*) ; 
 int /*<<< orphan*/  write_file (int /*<<< orphan*/ ,char*,char const*) ; 
 char* xstrdup (char const*) ; 
 int /*<<< orphan*/  xstrdup_or_null (int /*<<< orphan*/ ) ; 
 char* xstrfmt (char*,char const*,char const*) ; 

__attribute__((used)) static int add_exec_commands(struct string_list *commands)
{
	const char *todo_file = rebase_path_todo();
	struct todo_list todo_list = TODO_LIST_INIT;
	int res;

	if (strbuf_read_file(&todo_list.buf, todo_file, 0) < 0)
		return error_errno(_("could not read '%s'."), todo_file);

	if (todo_list_parse_insn_buffer(the_repository, todo_list.buf.buf,
					&todo_list)) {
		todo_list_release(&todo_list);
		return error(_("unusable todo list: '%s'"), todo_file);
	}

	todo_list_add_exec_commands(&todo_list, commands);
	res = todo_list_write_to_file(the_repository, &todo_list,
				      todo_file, NULL, NULL, -1, 0);
	todo_list_release(&todo_list);

	if (res)
		return error_errno(_("could not write '%s'."), todo_file);
	return 0;
}

__attribute__((used)) static int rearrange_squash_in_todo_file(void)
{
	const char *todo_file = rebase_path_todo();
	struct todo_list todo_list = TODO_LIST_INIT;
	int res = 0;

	if (strbuf_read_file(&todo_list.buf, todo_file, 0) < 0)
		return error_errno(_("could not read '%s'."), todo_file);
	if (todo_list_parse_insn_buffer(the_repository, todo_list.buf.buf,
					&todo_list)) {
		todo_list_release(&todo_list);
		return error(_("unusable todo list: '%s'"), todo_file);
	}

	res = todo_list_rearrange_squash(&todo_list);
	if (!res)
		res = todo_list_write_to_file(the_repository, &todo_list,
					      todo_file, NULL, NULL, -1, 0);

	todo_list_release(&todo_list);

	if (res)
		return error_errno(_("could not write '%s'."), todo_file);
	return 0;
}

__attribute__((used)) static int transform_todo_file(unsigned flags)
{
	const char *todo_file = rebase_path_todo();
	struct todo_list todo_list = TODO_LIST_INIT;
	int res;

	if (strbuf_read_file(&todo_list.buf, todo_file, 0) < 0)
		return error_errno(_("could not read '%s'."), todo_file);

	if (todo_list_parse_insn_buffer(the_repository, todo_list.buf.buf,
					&todo_list)) {
		todo_list_release(&todo_list);
		return error(_("unusable todo list: '%s'"), todo_file);
	}

	res = todo_list_write_to_file(the_repository, &todo_list, todo_file,
				      NULL, NULL, -1, flags);
	todo_list_release(&todo_list);

	if (res)
		return error_errno(_("could not write '%s'."), todo_file);
	return 0;
}

__attribute__((used)) static int edit_todo_file(unsigned flags)
{
	const char *todo_file = rebase_path_todo();
	struct todo_list todo_list = TODO_LIST_INIT,
		new_todo = TODO_LIST_INIT;
	int res = 0;

	if (strbuf_read_file(&todo_list.buf, todo_file, 0) < 0)
		return error_errno(_("could not read '%s'."), todo_file);

	strbuf_stripspace(&todo_list.buf, 1);
	res = edit_todo_list(the_repository, &todo_list, &new_todo, NULL, NULL, flags);
	if (!res && todo_list_write_to_file(the_repository, &new_todo, todo_file,
					    NULL, NULL, -1, flags & ~(TODO_LIST_SHORTEN_IDS)))
		res = error_errno(_("could not write '%s'"), todo_file);

	todo_list_release(&todo_list);
	todo_list_release(&new_todo);

	return res;
}

__attribute__((used)) static int get_revision_ranges(const char *upstream, const char *onto,
			       const char **head_hash,
			       char **revisions, char **shortrevisions)
{
	const char *base_rev = upstream ? upstream : onto, *shorthead;
	struct object_id orig_head;

	if (get_oid("HEAD", &orig_head))
		return error(_("no HEAD?"));

	*head_hash = find_unique_abbrev(&orig_head, GIT_MAX_HEXSZ);
	*revisions = xstrfmt("%s...%s", base_rev, *head_hash);

	shorthead = find_unique_abbrev(&orig_head, DEFAULT_ABBREV);

	if (upstream) {
		const char *shortrev;
		struct object_id rev_oid;

		get_oid(base_rev, &rev_oid);
		shortrev = find_unique_abbrev(&rev_oid, DEFAULT_ABBREV);

		*shortrevisions = xstrfmt("%s..%s", shortrev, shorthead);
	} else
		*shortrevisions = xstrdup(shorthead);

	return 0;
}

__attribute__((used)) static int init_basic_state(struct replay_opts *opts, const char *head_name,
			    const char *onto, const char *orig_head)
{
	FILE *interactive;

	if (!is_directory(path_state_dir()) && mkdir_in_gitdir(path_state_dir()))
		return error_errno(_("could not create temporary %s"), path_state_dir());

	delete_reflog("REBASE_HEAD");

	interactive = fopen(path_interactive(), "w");
	if (!interactive)
		return error_errno(_("could not mark as interactive"));
	fclose(interactive);

	return write_basic_state(opts, head_name, onto, orig_head);
}

__attribute__((used)) static int do_interactive_rebase(struct replay_opts *opts, unsigned flags,
				 const char *switch_to, const char *upstream,
				 const char *onto, const char *onto_name,
				 const char *squash_onto, const char *head_name,
				 const char *restrict_revision, char *raw_strategies,
				 struct string_list *commands, unsigned autosquash)
{
	int ret;
	const char *head_hash = NULL;
	char *revisions = NULL, *shortrevisions = NULL;
	struct argv_array make_script_args = ARGV_ARRAY_INIT;
	struct todo_list todo_list = TODO_LIST_INIT;

	if (prepare_branch_to_be_rebased(opts, switch_to))
		return -1;

	if (get_revision_ranges(upstream, onto, &head_hash,
				&revisions, &shortrevisions))
		return -1;

	if (raw_strategies)
		parse_strategy_opts(opts, raw_strategies);

	if (init_basic_state(opts, head_name, onto, head_hash)) {
		free(revisions);
		free(shortrevisions);

		return -1;
	}

	if (!upstream && squash_onto)
		write_file(path_squash_onto(), "%s\n", squash_onto);

	argv_array_pushl(&make_script_args, "", revisions, NULL);
	if (restrict_revision)
		argv_array_push(&make_script_args, restrict_revision);

	ret = sequencer_make_script(the_repository, &todo_list.buf,
				    make_script_args.argc, make_script_args.argv,
				    flags);

	if (ret)
		error(_("could not generate todo list"));
	else {
		discard_cache();
		if (todo_list_parse_insn_buffer(the_repository, todo_list.buf.buf,
						&todo_list))
			BUG("unusable todo list");

		ret = complete_action(the_repository, opts, flags, shortrevisions, onto_name,
				      onto, head_hash, commands, autosquash, &todo_list);
	}

	free(revisions);
	free(shortrevisions);
	todo_list_release(&todo_list);
	argv_array_clear(&make_script_args);

	return ret;
}

int cmd_rebase__interactive(int argc, const char **argv, const char *prefix)
{
	struct replay_opts opts = REPLAY_OPTS_INIT;
	unsigned flags = 0, keep_empty = 0, rebase_merges = 0, autosquash = 0;
	int abbreviate_commands = 0, rebase_cousins = -1, ret = 0;
	const char *onto = NULL, *onto_name = NULL, *restrict_revision = NULL,
		*squash_onto = NULL, *upstream = NULL, *head_name = NULL,
		*switch_to = NULL, *cmd = NULL;
	struct string_list commands = STRING_LIST_INIT_DUP;
	char *raw_strategies = NULL;
	enum {
		NONE = 0, CONTINUE, SKIP, EDIT_TODO, SHOW_CURRENT_PATCH,
		SHORTEN_OIDS, EXPAND_OIDS, CHECK_TODO_LIST, REARRANGE_SQUASH, ADD_EXEC
	} command = 0;
	struct option options[] = {
		OPT_BOOL(0, "ff", &opts.allow_ff, N_("allow fast-forward")),
		OPT_BOOL(0, "keep-empty", &keep_empty, N_("keep empty commits")),
		OPT_BOOL(0, "allow-empty-message", &opts.allow_empty_message,
			 N_("allow commits with empty messages")),
		OPT_BOOL(0, "rebase-merges", &rebase_merges, N_("rebase merge commits")),
		OPT_BOOL(0, "rebase-cousins", &rebase_cousins,
			 N_("keep original branch points of cousins")),
		OPT_BOOL(0, "autosquash", &autosquash,
			 N_("move commits that begin with squash!/fixup!")),
		OPT_BOOL(0, "signoff", &opts.signoff, N_("sign commits")),
		OPT__VERBOSE(&opts.verbose, N_("be verbose")),
		OPT_CMDMODE(0, "continue", &command, N_("continue rebase"),
			    CONTINUE),
		OPT_CMDMODE(0, "skip", &command, N_("skip commit"), SKIP),
		OPT_CMDMODE(0, "edit-todo", &command, N_("edit the todo list"),
			    EDIT_TODO),
		OPT_CMDMODE(0, "show-current-patch", &command, N_("show the current patch"),
			    SHOW_CURRENT_PATCH),
		OPT_CMDMODE(0, "shorten-ids", &command,
			N_("shorten commit ids in the todo list"), SHORTEN_OIDS),
		OPT_CMDMODE(0, "expand-ids", &command,
			N_("expand commit ids in the todo list"), EXPAND_OIDS),
		OPT_CMDMODE(0, "check-todo-list", &command,
			N_("check the todo list"), CHECK_TODO_LIST),
		OPT_CMDMODE(0, "rearrange-squash", &command,
			N_("rearrange fixup/squash lines"), REARRANGE_SQUASH),
		OPT_CMDMODE(0, "add-exec-commands", &command,
			N_("insert exec commands in todo list"), ADD_EXEC),
		OPT_STRING(0, "onto", &onto, N_("onto"), N_("onto")),
		OPT_STRING(0, "restrict-revision", &restrict_revision,
			   N_("restrict-revision"), N_("restrict revision")),
		OPT_STRING(0, "squash-onto", &squash_onto, N_("squash-onto"),
			   N_("squash onto")),
		OPT_STRING(0, "upstream", &upstream, N_("upstream"),
			   N_("the upstream commit")),
		OPT_STRING(0, "head-name", &head_name, N_("head-name"), N_("head name")),
		{ OPTION_STRING, 'S', "gpg-sign", &opts.gpg_sign, N_("key-id"),
			N_("GPG-sign commits"),
			PARSE_OPT_OPTARG, NULL, (intptr_t) "" },
		OPT_STRING(0, "strategy", &opts.strategy, N_("strategy"),
			   N_("rebase strategy")),
		OPT_STRING(0, "strategy-opts", &raw_strategies, N_("strategy-opts"),
			   N_("strategy options")),
		OPT_STRING(0, "switch-to", &switch_to, N_("switch-to"),
			   N_("the branch or commit to checkout")),
		OPT_STRING(0, "onto-name", &onto_name, N_("onto-name"), N_("onto name")),
		OPT_STRING(0, "cmd", &cmd, N_("cmd"), N_("the command to run")),
		OPT_RERERE_AUTOUPDATE(&opts.allow_rerere_auto),
		OPT_BOOL(0, "reschedule-failed-exec", &opts.reschedule_failed_exec,
			 N_("automatically re-schedule any `exec` that fails")),
		OPT_END()
	};

	sequencer_init_config(&opts);
	git_config_get_bool("rebase.abbreviatecommands", &abbreviate_commands);

	opts.action = REPLAY_INTERACTIVE_REBASE;
	opts.allow_ff = 1;
	opts.allow_empty = 1;

	if (argc == 1)
		usage_with_options(builtin_rebase_interactive_usage, options);

	argc = parse_options(argc, argv, NULL, options,
			builtin_rebase_interactive_usage, PARSE_OPT_KEEP_ARGV0);

	opts.gpg_sign = xstrdup_or_null(opts.gpg_sign);

	flags |= keep_empty ? TODO_LIST_KEEP_EMPTY : 0;
	flags |= abbreviate_commands ? TODO_LIST_ABBREVIATE_CMDS : 0;
	flags |= rebase_merges ? TODO_LIST_REBASE_MERGES : 0;
	flags |= rebase_cousins > 0 ? TODO_LIST_REBASE_COUSINS : 0;
	flags |= command == SHORTEN_OIDS ? TODO_LIST_SHORTEN_IDS : 0;

	if (rebase_cousins >= 0 && !rebase_merges)
		warning(_("--[no-]rebase-cousins has no effect without "
			  "--rebase-merges"));

	if (cmd && *cmd) {
		string_list_split(&commands, cmd, '\n', -1);

		/* rebase.c adds a new line to cmd after every command,
		 * so here the last command is always empty */
		string_list_remove_empty_items(&commands, 0);
	}

	switch (command) {
	case NONE:
		if (!onto && !upstream)
			die(_("a base commit must be provided with --upstream or --onto"));

		ret = do_interactive_rebase(&opts, flags, switch_to, upstream, onto,
					    onto_name, squash_onto, head_name, restrict_revision,
					    raw_strategies, &commands, autosquash);
		break;
	case SKIP: {
		struct string_list merge_rr = STRING_LIST_INIT_DUP;

		rerere_clear(the_repository, &merge_rr);
		/* fallthrough */
	case CONTINUE:
		ret = sequencer_continue(the_repository, &opts);
		break;
	}
	case EDIT_TODO:
		ret = edit_todo_file(flags);
		break;
	case SHOW_CURRENT_PATCH: {
		struct child_process cmd = CHILD_PROCESS_INIT;

		cmd.git_cmd = 1;
		argv_array_pushl(&cmd.args, "show", "REBASE_HEAD", "--", NULL);
		ret = run_command(&cmd);

		break;
	}
	case SHORTEN_OIDS:
	case EXPAND_OIDS:
		ret = transform_todo_file(flags);
		break;
	case CHECK_TODO_LIST:
		ret = check_todo_list_from_file(the_repository);
		break;
	case REARRANGE_SQUASH:
		ret = rearrange_squash_in_todo_file();
		break;
	case ADD_EXEC:
		ret = add_exec_commands(&commands);
		break;
	default:
		BUG("invalid command '%d'", command);
	}

	string_list_clear(&commands, 0);
	return !!ret;
}

