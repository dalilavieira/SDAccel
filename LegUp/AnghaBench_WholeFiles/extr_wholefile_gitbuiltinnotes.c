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
struct worktree {int /*<<< orphan*/  path; } ;
struct strbuf {char* buf; unsigned long len; } ;
struct pretty_print_context {int dummy; } ;
struct option {char member_1; char* member_2; int (* member_7 ) (struct option const*,char const*,int) ;int /*<<< orphan*/  member_6; int /*<<< orphan*/  member_5; int /*<<< orphan*/  member_4; struct note_data* member_3; int /*<<< orphan*/  member_0; struct note_data* value; } ;
typedef  struct object_id {int /*<<< orphan*/  hash; } const object_id ;
struct notes_tree {char* update_ref; char* ref; } ;
struct notes_rewrite_cfg {int dummy; } ;
struct notes_merge_options {char* local_ref; int verbosity; char* remote_ref; int strategy; struct strbuf commit_msg; } ;
struct note_data {char* edit_path; int use_editor; int given; struct strbuf buf; struct strbuf member_3; int /*<<< orphan*/ * member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct commit {TYPE_3__* parents; } ;
struct child_process {char const** argv; int no_stdin; int out; int git_cmd; scalar_t__ err; } ;
typedef  int /*<<< orphan*/  pretty_ctx ;
typedef  enum object_type { ____Placeholder_object_type } object_type ;
typedef  enum notes_merge_strategy { ____Placeholder_notes_merge_strategy } notes_merge_strategy ;
struct TYPE_6__ {TYPE_2__* item; } ;
struct TYPE_4__ {int /*<<< orphan*/  oid; } ;
struct TYPE_5__ {TYPE_1__ object; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG (char*,...) ; 
 int /*<<< orphan*/  BUG_ON_OPT_NEG (int) ; 
 struct child_process CHILD_PROCESS_INIT ; 
 scalar_t__ EOF ; 
 unsigned int IGNORE_MISSING ; 
 int NOTES_INIT_WRITABLE ; 
 int NOTES_MERGE_VERBOSITY_DEFAULT ; 
 int /*<<< orphan*/  NOTES_MERGE_WORKTREE ; 
 int NOTES_PRUNE_DRYRUN ; 
 int NOTES_PRUNE_VERBOSE ; 
 int /*<<< orphan*/  N_ (char*) ; 
 int OBJ_BLOB ; 
 int /*<<< orphan*/  OPTION_CALLBACK ; 
 struct option OPT_BIT (int /*<<< orphan*/ ,char*,unsigned int*,int /*<<< orphan*/ ,unsigned int) ; 
 struct option OPT_BOOL (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ) ; 
 struct option OPT_END () ; 
 struct option OPT_GROUP (int /*<<< orphan*/ ) ; 
 struct option OPT_SET_INT_F (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct option OPT_STRING (char,char*,char const**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct option OPT__DRY_RUN (int*,int /*<<< orphan*/ ) ; 
 struct option OPT__FORCE (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct option OPT__VERBOSE (int*,int /*<<< orphan*/ ) ; 
 struct option OPT__VERBOSITY (int*) ; 
 int O_CREAT ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  PARSE_OPT_KEEP_ARGV0 ; 
 int /*<<< orphan*/  PARSE_OPT_NOCOMPLETE ; 
 int /*<<< orphan*/  PARSE_OPT_NONEG ; 
 int /*<<< orphan*/  PARSE_OPT_STOP_AT_NON_OPTION ; 
 int /*<<< orphan*/  REF_NO_DEREF ; 
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  UPDATE_REFS_DIE_ON_ERR ; 
 char* _ (char*) ; 
 scalar_t__ add_note (struct notes_tree*,struct object_id const*,struct object_id const*,int /*<<< orphan*/ *) ; 
static  int append_edit (int,char const**,char const*) ; 
 int /*<<< orphan*/  blob_type ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/ * combine_notes_overwrite ; 
 int /*<<< orphan*/  commit_notes (int /*<<< orphan*/ ,struct notes_tree*,char const*) ; 
 int copy_note (struct notes_tree*,struct object_id const*,struct object_id const*,int,int /*<<< orphan*/ *) ; 
 int copy_note_for_rewrite (struct notes_rewrite_cfg*,struct object_id const*,struct object_id const*) ; 
 scalar_t__ create_symref (char*,char*,int /*<<< orphan*/ *) ; 
 char* default_notes_ref () ; 
 struct notes_tree default_notes_tree ; 
 scalar_t__ delete_ref (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int /*<<< orphan*/  die_errno (char*,...) ; 
 int error (char*,...) ; 
 int execv_git_cmd (char const**) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  expand_loose_notes_ref (struct strbuf*) ; 
 int /*<<< orphan*/  expand_notes_ref (struct strbuf*) ; 
 struct worktree* find_shared_symref (char*,char*) ; 
 scalar_t__ finish_command (struct child_process*) ; 
 int /*<<< orphan*/  finish_copy_notes_for_rewrite (int /*<<< orphan*/ ,struct notes_rewrite_cfg*,char const*) ; 
 int for_each_note (struct notes_tree*,int /*<<< orphan*/ ,int (*) (struct object_id const*,struct object_id const*,char*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  format_commit_message (struct commit*,char*,struct strbuf*,struct pretty_print_context*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  free_notes (struct notes_tree*) ; 
 struct object_id const* get_note (struct notes_tree*,struct object_id const*) ; 
 scalar_t__ get_oid (char const*,struct object_id const*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ git_config_get_string (char const*,char**) ; 
 int /*<<< orphan*/  git_default_config ; 
 int /*<<< orphan*/  git_die_config (char const*,char*,char*) ; 
 char const* const* git_notes_add_usage ; 
 char** git_notes_append_usage ; 
 char const* const* git_notes_copy_usage ; 
 char** git_notes_edit_usage ; 
 char const* const* git_notes_get_ref_usage ; 
 char const* const* git_notes_list_usage ; 
 char const* const* git_notes_merge_usage ; 
 char const* const* git_notes_prune_usage ; 
 char const* const* git_notes_remove_usage ; 
 char const* const* git_notes_show_usage ; 
 char const* const* git_notes_usage ; 
 char* git_path (int /*<<< orphan*/ ) ; 
 char* git_pathdup (char*) ; 
 struct notes_rewrite_cfg* init_copy_notes_for_rewrite (char const*) ; 
 int /*<<< orphan*/  init_notes (struct notes_tree*,char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  init_notes_merge_options (int /*<<< orphan*/ ,struct notes_merge_options*) ; 
 scalar_t__ is_null_oid (struct object_id const*) ; 
 scalar_t__ launch_editor (char const*,struct strbuf*,int /*<<< orphan*/ *) ; 
 struct commit* lookup_commit_reference (int /*<<< orphan*/ ,struct object_id const*) ; 
 int /*<<< orphan*/  memset (struct pretty_print_context*,int /*<<< orphan*/ ,int) ; 
 char* note_template ; 
 int notes_merge (struct notes_merge_options*,struct notes_tree*,struct object_id const*) ; 
 scalar_t__ notes_merge_abort (struct notes_merge_options*) ; 
 scalar_t__ notes_merge_commit (struct notes_merge_options*,struct notes_tree*,struct commit*,struct object_id const*) ; 
 char* oid_to_hex (struct object_id const*) ; 
 int /*<<< orphan*/  oidclr (struct object_id const*) ; 
 int /*<<< orphan*/  oidcpy (struct object_id const*,int /*<<< orphan*/ *) ; 
 int open (char*,int,int) ; 
 scalar_t__ parse_commit (struct commit*) ; 
 scalar_t__ parse_notes_merge_strategy (char const*,int*) ; 
 int parse_options (int,char const**,char const*,struct option*,char const* const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char*,char*) ; 
 int /*<<< orphan*/  prune_notes (struct notes_tree*,int) ; 
 int /*<<< orphan*/  puts (char*) ; 
 char* read_object_file (struct object_id const*,int*,unsigned long*) ; 
 int remove_note (struct notes_tree*,int /*<<< orphan*/ ) ; 
 void* resolve_refdup (char*,int /*<<< orphan*/ ,struct object_id const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setenv (char*,char*,int) ; 
 int /*<<< orphan*/  skip_prefix (char*,char*,char const**) ; 
 scalar_t__ start_command (struct child_process*) ; 
 int /*<<< orphan*/  starts_with (char const*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/  strbuf_add (struct strbuf*,char*,int) ; 
 int /*<<< orphan*/  strbuf_add_commented_lines (struct strbuf*,char*,unsigned long) ; 
 int /*<<< orphan*/  strbuf_addch (struct strbuf*,char) ; 
 int /*<<< orphan*/  strbuf_addf (struct strbuf*,char*,char const*,...) ; 
 int /*<<< orphan*/  strbuf_addstr (struct strbuf*,char const*) ; 
 scalar_t__ strbuf_getline_lf (struct strbuf*,int /*<<< orphan*/ ) ; 
 scalar_t__ strbuf_getwholeline (struct strbuf*,int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  strbuf_grow (struct strbuf*,unsigned long) ; 
 int /*<<< orphan*/  strbuf_insert (struct strbuf*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  strbuf_list_free (struct strbuf**) ; 
 scalar_t__ strbuf_read (struct strbuf*,int,int) ; 
 scalar_t__ strbuf_read_file (struct strbuf*,char const*,int) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_reset (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_rtrim (struct strbuf*) ; 
 struct strbuf** strbuf_split (struct strbuf*,char) ; 
 int /*<<< orphan*/  strbuf_stripspace (struct strbuf*,int) ; 
 int /*<<< orphan*/  strbuf_trim (struct strbuf*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 unsigned long strlen (char const*) ; 
 int /*<<< orphan*/  the_repository ; 
 int /*<<< orphan*/  unlink_or_warn (char*) ; 
 int /*<<< orphan*/  update_ref (char*,char*,struct object_id const*,struct object_id const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usage_with_options (char const* const*,struct option*) ; 
 scalar_t__ write_object_file (char*,unsigned long,int /*<<< orphan*/ ,struct object_id const*) ; 
 int /*<<< orphan*/  write_or_die (int,char*,unsigned long) ; 
 struct notes_tree* xcalloc (int,int) ; 
 char* xstrfmt (char*,char const*) ; 

__attribute__((used)) static void free_note_data(struct note_data *d)
{
	if (d->edit_path) {
		unlink_or_warn(d->edit_path);
		free(d->edit_path);
	}
	strbuf_release(&d->buf);
}

__attribute__((used)) static int list_each_note(const struct object_id *object_oid,
		const struct object_id *note_oid, char *note_path,
		void *cb_data)
{
	printf("%s %s\n", oid_to_hex(note_oid), oid_to_hex(object_oid));
	return 0;
}

__attribute__((used)) static void copy_obj_to_fd(int fd, const struct object_id *oid)
{
	unsigned long size;
	enum object_type type;
	char *buf = read_object_file(oid, &type, &size);
	if (buf) {
		if (size)
			write_or_die(fd, buf, size);
		free(buf);
	}
}

__attribute__((used)) static void write_commented_object(int fd, const struct object_id *object)
{
	const char *show_args[5] =
		{"show", "--stat", "--no-notes", oid_to_hex(object), NULL};
	struct child_process show = CHILD_PROCESS_INIT;
	struct strbuf buf = STRBUF_INIT;
	struct strbuf cbuf = STRBUF_INIT;

	/* Invoke "git show --stat --no-notes $object" */
	show.argv = show_args;
	show.no_stdin = 1;
	show.out = -1;
	show.err = 0;
	show.git_cmd = 1;
	if (start_command(&show))
		die(_("unable to start 'show' for object '%s'"),
		    oid_to_hex(object));

	if (strbuf_read(&buf, show.out, 0) < 0)
		die_errno(_("could not read 'show' output"));
	strbuf_add_commented_lines(&cbuf, buf.buf, buf.len);
	write_or_die(fd, cbuf.buf, cbuf.len);

	strbuf_release(&cbuf);
	strbuf_release(&buf);

	if (finish_command(&show))
		die(_("failed to finish 'show' for object '%s'"),
		    oid_to_hex(object));
}

__attribute__((used)) static void prepare_note_data(const struct object_id *object, struct note_data *d,
		const struct object_id *old_note)
{
	if (d->use_editor || !d->given) {
		int fd;
		struct strbuf buf = STRBUF_INIT;

		/* write the template message before editing: */
		d->edit_path = git_pathdup("NOTES_EDITMSG");
		fd = open(d->edit_path, O_CREAT | O_TRUNC | O_WRONLY, 0600);
		if (fd < 0)
			die_errno(_("could not create file '%s'"), d->edit_path);

		if (d->given)
			write_or_die(fd, d->buf.buf, d->buf.len);
		else if (old_note)
			copy_obj_to_fd(fd, old_note);

		strbuf_addch(&buf, '\n');
		strbuf_add_commented_lines(&buf, "\n", strlen("\n"));
		strbuf_add_commented_lines(&buf, _(note_template), strlen(_(note_template)));
		strbuf_addch(&buf, '\n');
		write_or_die(fd, buf.buf, buf.len);

		write_commented_object(fd, object);

		close(fd);
		strbuf_release(&buf);
		strbuf_reset(&d->buf);

		if (launch_editor(d->edit_path, &d->buf, NULL)) {
			die(_("please supply the note contents using either -m or -F option"));
		}
		strbuf_stripspace(&d->buf, 1);
	}
}

__attribute__((used)) static void write_note_data(struct note_data *d, struct object_id *oid)
{
	if (write_object_file(d->buf.buf, d->buf.len, blob_type, oid)) {
		error(_("unable to write note object"));
		if (d->edit_path)
			error(_("the note contents have been left in %s"),
				d->edit_path);
		exit(128);
	}
}

__attribute__((used)) static int parse_msg_arg(const struct option *opt, const char *arg, int unset)
{
	struct note_data *d = opt->value;

	BUG_ON_OPT_NEG(unset);

	strbuf_grow(&d->buf, strlen(arg) + 2);
	if (d->buf.len)
		strbuf_addch(&d->buf, '\n');
	strbuf_addstr(&d->buf, arg);
	strbuf_stripspace(&d->buf, 0);

	d->given = 1;
	return 0;
}

__attribute__((used)) static int parse_file_arg(const struct option *opt, const char *arg, int unset)
{
	struct note_data *d = opt->value;

	BUG_ON_OPT_NEG(unset);

	if (d->buf.len)
		strbuf_addch(&d->buf, '\n');
	if (!strcmp(arg, "-")) {
		if (strbuf_read(&d->buf, 0, 1024) < 0)
			die_errno(_("cannot read '%s'"), arg);
	} else if (strbuf_read_file(&d->buf, arg, 1024) < 0)
		die_errno(_("could not open or read '%s'"), arg);
	strbuf_stripspace(&d->buf, 0);

	d->given = 1;
	return 0;
}

__attribute__((used)) static int parse_reuse_arg(const struct option *opt, const char *arg, int unset)
{
	struct note_data *d = opt->value;
	char *buf;
	struct object_id object;
	enum object_type type;
	unsigned long len;

	BUG_ON_OPT_NEG(unset);

	if (d->buf.len)
		strbuf_addch(&d->buf, '\n');

	if (get_oid(arg, &object))
		die(_("failed to resolve '%s' as a valid ref."), arg);
	if (!(buf = read_object_file(&object, &type, &len)))
		die(_("failed to read object '%s'."), arg);
	if (type != OBJ_BLOB) {
		free(buf);
		die(_("cannot read note data from non-blob object '%s'."), arg);
	}
	strbuf_add(&d->buf, buf, len);
	free(buf);

	d->given = 1;
	return 0;
}

__attribute__((used)) static int parse_reedit_arg(const struct option *opt, const char *arg, int unset)
{
	struct note_data *d = opt->value;
	BUG_ON_OPT_NEG(unset);
	d->use_editor = 1;
	return parse_reuse_arg(opt, arg, unset);
}

__attribute__((used)) static int notes_copy_from_stdin(int force, const char *rewrite_cmd)
{
	struct strbuf buf = STRBUF_INIT;
	struct notes_rewrite_cfg *c = NULL;
	struct notes_tree *t = NULL;
	int ret = 0;
	const char *msg = "Notes added by 'git notes copy'";

	if (rewrite_cmd) {
		c = init_copy_notes_for_rewrite(rewrite_cmd);
		if (!c)
			return 0;
	} else {
		init_notes(NULL, NULL, NULL, NOTES_INIT_WRITABLE);
		t = &default_notes_tree;
	}

	while (strbuf_getline_lf(&buf, stdin) != EOF) {
		struct object_id from_obj, to_obj;
		struct strbuf **split;
		int err;

		split = strbuf_split(&buf, ' ');
		if (!split[0] || !split[1])
			die(_("malformed input line: '%s'."), buf.buf);
		strbuf_rtrim(split[0]);
		strbuf_rtrim(split[1]);
		if (get_oid(split[0]->buf, &from_obj))
			die(_("failed to resolve '%s' as a valid ref."), split[0]->buf);
		if (get_oid(split[1]->buf, &to_obj))
			die(_("failed to resolve '%s' as a valid ref."), split[1]->buf);

		if (rewrite_cmd)
			err = copy_note_for_rewrite(c, &from_obj, &to_obj);
		else
			err = copy_note(t, &from_obj, &to_obj, force,
					combine_notes_overwrite);

		if (err) {
			error(_("failed to copy notes from '%s' to '%s'"),
			      split[0]->buf, split[1]->buf);
			ret = 1;
		}

		strbuf_list_free(split);
	}

	if (!rewrite_cmd) {
		commit_notes(the_repository, t, msg);
		free_notes(t);
	} else {
		finish_copy_notes_for_rewrite(the_repository, c, msg);
	}
	strbuf_release(&buf);
	return ret;
}

__attribute__((used)) static struct notes_tree *init_notes_check(const char *subcommand,
					   int flags)
{
	struct notes_tree *t;
	const char *ref;
	init_notes(NULL, NULL, NULL, flags);
	t = &default_notes_tree;

	ref = (flags & NOTES_INIT_WRITABLE) ? t->update_ref : t->ref;
	if (!starts_with(ref, "refs/notes/"))
		/*
		 * TRANSLATORS: the first %s will be replaced by a git
		 * notes command: 'add', 'merge', 'remove', etc.
		 */
		die(_("refusing to %s notes in %s (outside of refs/notes/)"),
		    subcommand, ref);
	return t;
}

__attribute__((used)) static int list(int argc, const char **argv, const char *prefix)
{
	struct notes_tree *t;
	struct object_id object;
	const struct object_id *note;
	int retval = -1;
	struct option options[] = {
		OPT_END()
	};

	if (argc)
		argc = parse_options(argc, argv, prefix, options,
				     git_notes_list_usage, 0);

	if (1 < argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_list_usage, options);
	}

	t = init_notes_check("list", 0);
	if (argc) {
		if (get_oid(argv[0], &object))
			die(_("failed to resolve '%s' as a valid ref."), argv[0]);
		note = get_note(t, &object);
		if (note) {
			puts(oid_to_hex(note));
			retval = 0;
		} else
			retval = error(_("no note found for object %s."),
				       oid_to_hex(&object));
	} else
		retval = for_each_note(t, 0, list_each_note, NULL);

	free_notes(t);
	return retval;
}

__attribute__((used)) static int add(int argc, const char **argv, const char *prefix)
{
	int force = 0, allow_empty = 0;
	const char *object_ref;
	struct notes_tree *t;
	struct object_id object, new_note;
	const struct object_id *note;
	struct note_data d = { 0, 0, NULL, STRBUF_INIT };
	struct option options[] = {
		{ OPTION_CALLBACK, 'm', "message", &d, N_("message"),
			N_("note contents as a string"), PARSE_OPT_NONEG,
			parse_msg_arg},
		{ OPTION_CALLBACK, 'F', "file", &d, N_("file"),
			N_("note contents in a file"), PARSE_OPT_NONEG,
			parse_file_arg},
		{ OPTION_CALLBACK, 'c', "reedit-message", &d, N_("object"),
			N_("reuse and edit specified note object"), PARSE_OPT_NONEG,
			parse_reedit_arg},
		{ OPTION_CALLBACK, 'C', "reuse-message", &d, N_("object"),
			N_("reuse specified note object"), PARSE_OPT_NONEG,
			parse_reuse_arg},
		OPT_BOOL(0, "allow-empty", &allow_empty,
			N_("allow storing empty note")),
		OPT__FORCE(&force, N_("replace existing notes"), PARSE_OPT_NOCOMPLETE),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_add_usage,
			     PARSE_OPT_KEEP_ARGV0);

	if (2 < argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_add_usage, options);
	}

	object_ref = argc > 1 ? argv[1] : "HEAD";

	if (get_oid(object_ref, &object))
		die(_("failed to resolve '%s' as a valid ref."), object_ref);

	t = init_notes_check("add", NOTES_INIT_WRITABLE);
	note = get_note(t, &object);

	if (note) {
		if (!force) {
			free_notes(t);
			if (d.given) {
				free_note_data(&d);
				return error(_("Cannot add notes. "
					"Found existing notes for object %s. "
					"Use '-f' to overwrite existing notes"),
					oid_to_hex(&object));
			}
			/*
			 * Redirect to "edit" subcommand.
			 *
			 * We only end up here if none of -m/-F/-c/-C or -f are
			 * given. The original args are therefore still in
			 * argv[0-1].
			 */
			argv[0] = "edit";
			return append_edit(argc, argv, prefix);
		}
		fprintf(stderr, _("Overwriting existing notes for object %s\n"),
			oid_to_hex(&object));
	}

	prepare_note_data(&object, &d, note);
	if (d.buf.len || allow_empty) {
		write_note_data(&d, &new_note);
		if (add_note(t, &object, &new_note, combine_notes_overwrite))
			BUG("combine_notes_overwrite failed");
		commit_notes(the_repository, t,
			     "Notes added by 'git notes add'");
	} else {
		fprintf(stderr, _("Removing note for object %s\n"),
			oid_to_hex(&object));
		remove_note(t, object.hash);
		commit_notes(the_repository, t,
			     "Notes removed by 'git notes add'");
	}

	free_note_data(&d);
	free_notes(t);
	return 0;
}

__attribute__((used)) static int copy(int argc, const char **argv, const char *prefix)
{
	int retval = 0, force = 0, from_stdin = 0;
	const struct object_id *from_note, *note;
	const char *object_ref;
	struct object_id object, from_obj;
	struct notes_tree *t;
	const char *rewrite_cmd = NULL;
	struct option options[] = {
		OPT__FORCE(&force, N_("replace existing notes"), PARSE_OPT_NOCOMPLETE),
		OPT_BOOL(0, "stdin", &from_stdin, N_("read objects from stdin")),
		OPT_STRING(0, "for-rewrite", &rewrite_cmd, N_("command"),
			   N_("load rewriting config for <command> (implies "
			      "--stdin)")),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_copy_usage,
			     0);

	if (from_stdin || rewrite_cmd) {
		if (argc) {
			error(_("too many parameters"));
			usage_with_options(git_notes_copy_usage, options);
		} else {
			return notes_copy_from_stdin(force, rewrite_cmd);
		}
	}

	if (argc < 2) {
		error(_("too few parameters"));
		usage_with_options(git_notes_copy_usage, options);
	}
	if (2 < argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_copy_usage, options);
	}

	if (get_oid(argv[0], &from_obj))
		die(_("failed to resolve '%s' as a valid ref."), argv[0]);

	object_ref = 1 < argc ? argv[1] : "HEAD";

	if (get_oid(object_ref, &object))
		die(_("failed to resolve '%s' as a valid ref."), object_ref);

	t = init_notes_check("copy", NOTES_INIT_WRITABLE);
	note = get_note(t, &object);

	if (note) {
		if (!force) {
			retval = error(_("Cannot copy notes. Found existing "
				       "notes for object %s. Use '-f' to "
				       "overwrite existing notes"),
				       oid_to_hex(&object));
			goto out;
		}
		fprintf(stderr, _("Overwriting existing notes for object %s\n"),
			oid_to_hex(&object));
	}

	from_note = get_note(t, &from_obj);
	if (!from_note) {
		retval = error(_("missing notes on source object %s. Cannot "
			       "copy."), oid_to_hex(&from_obj));
		goto out;
	}

	if (add_note(t, &object, from_note, combine_notes_overwrite))
		BUG("combine_notes_overwrite failed");
	commit_notes(the_repository, t,
		     "Notes added by 'git notes copy'");
out:
	free_notes(t);
	return retval;
}

__attribute__((used)) static int append_edit(int argc, const char **argv, const char *prefix)
{
	int allow_empty = 0;
	const char *object_ref;
	struct notes_tree *t;
	struct object_id object, new_note;
	const struct object_id *note;
	char *logmsg;
	const char * const *usage;
	struct note_data d = { 0, 0, NULL, STRBUF_INIT };
	struct option options[] = {
		{ OPTION_CALLBACK, 'm', "message", &d, N_("message"),
			N_("note contents as a string"), PARSE_OPT_NONEG,
			parse_msg_arg},
		{ OPTION_CALLBACK, 'F', "file", &d, N_("file"),
			N_("note contents in a file"), PARSE_OPT_NONEG,
			parse_file_arg},
		{ OPTION_CALLBACK, 'c', "reedit-message", &d, N_("object"),
			N_("reuse and edit specified note object"), PARSE_OPT_NONEG,
			parse_reedit_arg},
		{ OPTION_CALLBACK, 'C', "reuse-message", &d, N_("object"),
			N_("reuse specified note object"), PARSE_OPT_NONEG,
			parse_reuse_arg},
		OPT_BOOL(0, "allow-empty", &allow_empty,
			N_("allow storing empty note")),
		OPT_END()
	};
	int edit = !strcmp(argv[0], "edit");

	usage = edit ? git_notes_edit_usage : git_notes_append_usage;
	argc = parse_options(argc, argv, prefix, options, usage,
			     PARSE_OPT_KEEP_ARGV0);

	if (2 < argc) {
		error(_("too many parameters"));
		usage_with_options(usage, options);
	}

	if (d.given && edit)
		fprintf(stderr, _("The -m/-F/-c/-C options have been deprecated "
			"for the 'edit' subcommand.\n"
			"Please use 'git notes add -f -m/-F/-c/-C' instead.\n"));

	object_ref = 1 < argc ? argv[1] : "HEAD";

	if (get_oid(object_ref, &object))
		die(_("failed to resolve '%s' as a valid ref."), object_ref);

	t = init_notes_check(argv[0], NOTES_INIT_WRITABLE);
	note = get_note(t, &object);

	prepare_note_data(&object, &d, edit && note ? note : NULL);

	if (note && !edit) {
		/* Append buf to previous note contents */
		unsigned long size;
		enum object_type type;
		char *prev_buf = read_object_file(note, &type, &size);

		strbuf_grow(&d.buf, size + 1);
		if (d.buf.len && prev_buf && size)
			strbuf_insert(&d.buf, 0, "\n", 1);
		if (prev_buf && size)
			strbuf_insert(&d.buf, 0, prev_buf, size);
		free(prev_buf);
	}

	if (d.buf.len || allow_empty) {
		write_note_data(&d, &new_note);
		if (add_note(t, &object, &new_note, combine_notes_overwrite))
			BUG("combine_notes_overwrite failed");
		logmsg = xstrfmt("Notes added by 'git notes %s'", argv[0]);
	} else {
		fprintf(stderr, _("Removing note for object %s\n"),
			oid_to_hex(&object));
		remove_note(t, object.hash);
		logmsg = xstrfmt("Notes removed by 'git notes %s'", argv[0]);
	}
	commit_notes(the_repository, t, logmsg);

	free(logmsg);
	free_note_data(&d);
	free_notes(t);
	return 0;
}

__attribute__((used)) static int show(int argc, const char **argv, const char *prefix)
{
	const char *object_ref;
	struct notes_tree *t;
	struct object_id object;
	const struct object_id *note;
	int retval;
	struct option options[] = {
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_show_usage,
			     0);

	if (1 < argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_show_usage, options);
	}

	object_ref = argc ? argv[0] : "HEAD";

	if (get_oid(object_ref, &object))
		die(_("failed to resolve '%s' as a valid ref."), object_ref);

	t = init_notes_check("show", 0);
	note = get_note(t, &object);

	if (!note)
		retval = error(_("no note found for object %s."),
			       oid_to_hex(&object));
	else {
		const char *show_args[3] = {"show", oid_to_hex(note), NULL};
		retval = execv_git_cmd(show_args);
	}
	free_notes(t);
	return retval;
}

__attribute__((used)) static int merge_abort(struct notes_merge_options *o)
{
	int ret = 0;

	/*
	 * Remove .git/NOTES_MERGE_PARTIAL and .git/NOTES_MERGE_REF, and call
	 * notes_merge_abort() to remove .git/NOTES_MERGE_WORKTREE.
	 */

	if (delete_ref(NULL, "NOTES_MERGE_PARTIAL", NULL, 0))
		ret += error(_("failed to delete ref NOTES_MERGE_PARTIAL"));
	if (delete_ref(NULL, "NOTES_MERGE_REF", NULL, REF_NO_DEREF))
		ret += error(_("failed to delete ref NOTES_MERGE_REF"));
	if (notes_merge_abort(o))
		ret += error(_("failed to remove 'git notes merge' worktree"));
	return ret;
}

__attribute__((used)) static int merge_commit(struct notes_merge_options *o)
{
	struct strbuf msg = STRBUF_INIT;
	struct object_id oid, parent_oid;
	struct notes_tree *t;
	struct commit *partial;
	struct pretty_print_context pretty_ctx;
	void *local_ref_to_free;
	int ret;

	/*
	 * Read partial merge result from .git/NOTES_MERGE_PARTIAL,
	 * and target notes ref from .git/NOTES_MERGE_REF.
	 */

	if (get_oid("NOTES_MERGE_PARTIAL", &oid))
		die(_("failed to read ref NOTES_MERGE_PARTIAL"));
	else if (!(partial = lookup_commit_reference(the_repository, &oid)))
		die(_("could not find commit from NOTES_MERGE_PARTIAL."));
	else if (parse_commit(partial))
		die(_("could not parse commit from NOTES_MERGE_PARTIAL."));

	if (partial->parents)
		oidcpy(&parent_oid, &partial->parents->item->object.oid);
	else
		oidclr(&parent_oid);

	t = xcalloc(1, sizeof(struct notes_tree));
	init_notes(t, "NOTES_MERGE_PARTIAL", combine_notes_overwrite, 0);

	o->local_ref = local_ref_to_free =
		resolve_refdup("NOTES_MERGE_REF", 0, &oid, NULL);
	if (!o->local_ref)
		die(_("failed to resolve NOTES_MERGE_REF"));

	if (notes_merge_commit(o, t, partial, &oid))
		die(_("failed to finalize notes merge"));

	/* Reuse existing commit message in reflog message */
	memset(&pretty_ctx, 0, sizeof(pretty_ctx));
	format_commit_message(partial, "%s", &msg, &pretty_ctx);
	strbuf_trim(&msg);
	strbuf_insert(&msg, 0, "notes: ", 7);
	update_ref(msg.buf, o->local_ref, &oid,
		   is_null_oid(&parent_oid) ? NULL : &parent_oid,
		   0, UPDATE_REFS_DIE_ON_ERR);

	free_notes(t);
	strbuf_release(&msg);
	ret = merge_abort(o);
	free(local_ref_to_free);
	return ret;
}

__attribute__((used)) static int git_config_get_notes_strategy(const char *key,
					 enum notes_merge_strategy *strategy)
{
	char *value;

	if (git_config_get_string(key, &value))
		return 1;
	if (parse_notes_merge_strategy(value, strategy))
		git_die_config(key, _("unknown notes merge strategy %s"), value);

	free(value);
	return 0;
}

__attribute__((used)) static int merge(int argc, const char **argv, const char *prefix)
{
	struct strbuf remote_ref = STRBUF_INIT, msg = STRBUF_INIT;
	struct object_id result_oid;
	struct notes_tree *t;
	struct notes_merge_options o;
	int do_merge = 0, do_commit = 0, do_abort = 0;
	int verbosity = 0, result;
	const char *strategy = NULL;
	struct option options[] = {
		OPT_GROUP(N_("General options")),
		OPT__VERBOSITY(&verbosity),
		OPT_GROUP(N_("Merge options")),
		OPT_STRING('s', "strategy", &strategy, N_("strategy"),
			   N_("resolve notes conflicts using the given strategy "
			      "(manual/ours/theirs/union/cat_sort_uniq)")),
		OPT_GROUP(N_("Committing unmerged notes")),
		OPT_SET_INT_F(0, "commit", &do_commit,
			      N_("finalize notes merge by committing unmerged notes"),
			      1, PARSE_OPT_NONEG),
		OPT_GROUP(N_("Aborting notes merge resolution")),
		OPT_SET_INT_F(0, "abort", &do_abort,
			      N_("abort notes merge"),
			      1, PARSE_OPT_NONEG),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options,
			     git_notes_merge_usage, 0);

	if (strategy || do_commit + do_abort == 0)
		do_merge = 1;
	if (do_merge + do_commit + do_abort != 1) {
		error(_("cannot mix --commit, --abort or -s/--strategy"));
		usage_with_options(git_notes_merge_usage, options);
	}

	if (do_merge && argc != 1) {
		error(_("must specify a notes ref to merge"));
		usage_with_options(git_notes_merge_usage, options);
	} else if (!do_merge && argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_merge_usage, options);
	}

	init_notes_merge_options(the_repository, &o);
	o.verbosity = verbosity + NOTES_MERGE_VERBOSITY_DEFAULT;

	if (do_abort)
		return merge_abort(&o);
	if (do_commit)
		return merge_commit(&o);

	o.local_ref = default_notes_ref();
	strbuf_addstr(&remote_ref, argv[0]);
	expand_loose_notes_ref(&remote_ref);
	o.remote_ref = remote_ref.buf;

	t = init_notes_check("merge", NOTES_INIT_WRITABLE);

	if (strategy) {
		if (parse_notes_merge_strategy(strategy, &o.strategy)) {
			error(_("unknown -s/--strategy: %s"), strategy);
			usage_with_options(git_notes_merge_usage, options);
		}
	} else {
		struct strbuf merge_key = STRBUF_INIT;
		const char *short_ref = NULL;

		if (!skip_prefix(o.local_ref, "refs/notes/", &short_ref))
			BUG("local ref %s is outside of refs/notes/",
			    o.local_ref);

		strbuf_addf(&merge_key, "notes.%s.mergeStrategy", short_ref);

		if (git_config_get_notes_strategy(merge_key.buf, &o.strategy))
			git_config_get_notes_strategy("notes.mergeStrategy", &o.strategy);

		strbuf_release(&merge_key);
	}

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
		    remote_ref.buf, default_notes_ref());
	strbuf_add(&(o.commit_msg), msg.buf + 7, msg.len - 7); /* skip "notes: " */

	result = notes_merge(&o, t, &result_oid);

	if (result >= 0) /* Merge resulted (trivially) in result_oid */
		/* Update default notes ref with new commit */
		update_ref(msg.buf, default_notes_ref(), &result_oid, NULL, 0,
			   UPDATE_REFS_DIE_ON_ERR);
	else { /* Merge has unresolved conflicts */
		const struct worktree *wt;
		/* Update .git/NOTES_MERGE_PARTIAL with partial merge result */
		update_ref(msg.buf, "NOTES_MERGE_PARTIAL", &result_oid, NULL,
			   0, UPDATE_REFS_DIE_ON_ERR);
		/* Store ref-to-be-updated into .git/NOTES_MERGE_REF */
		wt = find_shared_symref("NOTES_MERGE_REF", default_notes_ref());
		if (wt)
			die(_("a notes merge into %s is already in-progress at %s"),
			    default_notes_ref(), wt->path);
		if (create_symref("NOTES_MERGE_REF", default_notes_ref(), NULL))
			die(_("failed to store link to current notes ref (%s)"),
			    default_notes_ref());
		fprintf(stderr, _("Automatic notes merge failed. Fix conflicts in %s "
				  "and commit the result with 'git notes merge --commit', "
				  "or abort the merge with 'git notes merge --abort'.\n"),
			git_path(NOTES_MERGE_WORKTREE));
	}

	free_notes(t);
	strbuf_release(&remote_ref);
	strbuf_release(&msg);
	return result < 0; /* return non-zero on conflicts */
}

__attribute__((used)) static int remove_one_note(struct notes_tree *t, const char *name, unsigned flag)
{
	int status;
	struct object_id oid;
	if (get_oid(name, &oid))
		return error(_("Failed to resolve '%s' as a valid ref."), name);
	status = remove_note(t, oid.hash);
	if (status)
		fprintf(stderr, _("Object %s has no note\n"), name);
	else
		fprintf(stderr, _("Removing note for object %s\n"), name);
	return (flag & IGNORE_MISSING) ? 0 : status;
}

__attribute__((used)) static int remove_cmd(int argc, const char **argv, const char *prefix)
{
	unsigned flag = 0;
	int from_stdin = 0;
	struct option options[] = {
		OPT_BIT(0, "ignore-missing", &flag,
			N_("attempt to remove non-existent note is not an error"),
			IGNORE_MISSING),
		OPT_BOOL(0, "stdin", &from_stdin,
			    N_("read object names from the standard input")),
		OPT_END()
	};
	struct notes_tree *t;
	int retval = 0;

	argc = parse_options(argc, argv, prefix, options,
			     git_notes_remove_usage, 0);

	t = init_notes_check("remove", NOTES_INIT_WRITABLE);

	if (!argc && !from_stdin) {
		retval = remove_one_note(t, "HEAD", flag);
	} else {
		while (*argv) {
			retval |= remove_one_note(t, *argv, flag);
			argv++;
		}
	}
	if (from_stdin) {
		struct strbuf sb = STRBUF_INIT;
		while (strbuf_getwholeline(&sb, stdin, '\n') != EOF) {
			strbuf_rtrim(&sb);
			retval |= remove_one_note(t, sb.buf, flag);
		}
		strbuf_release(&sb);
	}
	if (!retval)
		commit_notes(the_repository, t,
			     "Notes removed by 'git notes remove'");
	free_notes(t);
	return retval;
}

__attribute__((used)) static int prune(int argc, const char **argv, const char *prefix)
{
	struct notes_tree *t;
	int show_only = 0, verbose = 0;
	struct option options[] = {
		OPT__DRY_RUN(&show_only, N_("do not remove, show only")),
		OPT__VERBOSE(&verbose, N_("report pruned notes")),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, git_notes_prune_usage,
			     0);

	if (argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_prune_usage, options);
	}

	t = init_notes_check("prune", NOTES_INIT_WRITABLE);

	prune_notes(t, (verbose ? NOTES_PRUNE_VERBOSE : 0) |
		(show_only ? NOTES_PRUNE_VERBOSE|NOTES_PRUNE_DRYRUN : 0) );
	if (!show_only)
		commit_notes(the_repository, t,
			     "Notes removed by 'git notes prune'");
	free_notes(t);
	return 0;
}

__attribute__((used)) static int get_ref(int argc, const char **argv, const char *prefix)
{
	struct option options[] = { OPT_END() };
	argc = parse_options(argc, argv, prefix, options,
			     git_notes_get_ref_usage, 0);

	if (argc) {
		error(_("too many parameters"));
		usage_with_options(git_notes_get_ref_usage, options);
	}

	puts(default_notes_ref());
	return 0;
}

int cmd_notes(int argc, const char **argv, const char *prefix)
{
	int result;
	const char *override_notes_ref = NULL;
	struct option options[] = {
		OPT_STRING(0, "ref", &override_notes_ref, N_("notes-ref"),
			   N_("use notes from <notes-ref>")),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	argc = parse_options(argc, argv, prefix, options, git_notes_usage,
			     PARSE_OPT_STOP_AT_NON_OPTION);

	if (override_notes_ref) {
		struct strbuf sb = STRBUF_INIT;
		strbuf_addstr(&sb, override_notes_ref);
		expand_notes_ref(&sb);
		setenv("GIT_NOTES_REF", sb.buf, 1);
		strbuf_release(&sb);
	}

	if (argc < 1 || !strcmp(argv[0], "list"))
		result = list(argc, argv, prefix);
	else if (!strcmp(argv[0], "add"))
		result = add(argc, argv, prefix);
	else if (!strcmp(argv[0], "copy"))
		result = copy(argc, argv, prefix);
	else if (!strcmp(argv[0], "append") || !strcmp(argv[0], "edit"))
		result = append_edit(argc, argv, prefix);
	else if (!strcmp(argv[0], "show"))
		result = show(argc, argv, prefix);
	else if (!strcmp(argv[0], "merge"))
		result = merge(argc, argv, prefix);
	else if (!strcmp(argv[0], "remove"))
		result = remove_cmd(argc, argv, prefix);
	else if (!strcmp(argv[0], "prune"))
		result = prune(argc, argv, prefix);
	else if (!strcmp(argv[0], "get-ref"))
		result = get_ref(argc, argv, prefix);
	else {
		result = error(_("unknown subcommand: %s"), argv[0]);
		usage_with_options(git_notes_usage, options);
	}

	return result ? 1 : 0;
}

