#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct strbuf {char* buf; } ;
struct git_attr {int dummy; } ;
struct attr_check {int nr; TYPE_1__* items; } ;
typedef  scalar_t__ (* strbuf_getline_fn ) (struct strbuf*,int /*<<< orphan*/ ) ;
struct TYPE_2__ {char* value; int /*<<< orphan*/  attr; } ;

/* Variables and functions */
 scalar_t__ ATTR_FALSE (char const*) ; 
 scalar_t__ ATTR_TRUE (char const*) ; 
 scalar_t__ ATTR_UNSET (char const*) ; 
 scalar_t__ EOF ; 
 int /*<<< orphan*/  GIT_ATTR_INDEX ; 
 int /*<<< orphan*/  PARSE_OPT_KEEP_DASHDASH ; 
 struct strbuf STRBUF_INIT ; 
 int all_attrs ; 
 struct attr_check* attr_check_alloc () ; 
 int /*<<< orphan*/  attr_check_append (struct attr_check*,struct git_attr const*) ; 
 int /*<<< orphan*/  attr_check_free (struct attr_check*) ; 
 scalar_t__ cached_attrs ; 
 int /*<<< orphan*/  check_attr_options ; 
 int /*<<< orphan*/  check_attr_usage ; 
 int /*<<< orphan*/  die (char*) ; 
 int error (char*,char const*) ; 
 int /*<<< orphan*/  error_with_usage (char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  git_all_attrs (int /*<<< orphan*/ *,char*,struct attr_check*) ; 
 struct git_attr* git_attr (char const*) ; 
 char* git_attr_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_attr_set_direction (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_check_attr (int /*<<< orphan*/ *,char*,struct attr_check*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_default_config ; 
 int /*<<< orphan*/  is_bare_repository () ; 
 int /*<<< orphan*/  maybe_flush_or_die (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ nul_term_line ; 
 int parse_options (int,char const**,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* prefix_path (char const*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  printf (char*,char const*,char const*,...) ; 
 int /*<<< orphan*/  quote_c_style (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ read_cache () ; 
 int /*<<< orphan*/  setup_work_tree () ; 
 int /*<<< orphan*/  stdin ; 
 scalar_t__ stdin_paths ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strbuf_getline_lf (struct strbuf*,int /*<<< orphan*/ ) ; 
 scalar_t__ strbuf_getline_nul (struct strbuf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_reset (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_swap (struct strbuf*,struct strbuf*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  the_index ; 
 scalar_t__ unquote_c_style (struct strbuf*,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void output_attr(struct attr_check *check, const char *file)
{
	int j;
	int cnt = check->nr;

	for (j = 0; j < cnt; j++) {
		const char *value = check->items[j].value;

		if (ATTR_TRUE(value))
			value = "set";
		else if (ATTR_FALSE(value))
			value = "unset";
		else if (ATTR_UNSET(value))
			value = "unspecified";

		if (nul_term_line) {
			printf("%s%c" /* path */
			       "%s%c" /* attrname */
			       "%s%c" /* attrvalue */,
			       file, 0,
			       git_attr_name(check->items[j].attr), 0, value, 0);
		} else {
			quote_c_style(file, NULL, stdout, 0);
			printf(": %s: %s\n",
			       git_attr_name(check->items[j].attr), value);
		}
	}
}

__attribute__((used)) static void check_attr(const char *prefix,
		       struct attr_check *check,
		       int collect_all,
		       const char *file)
{
	char *full_path =
		prefix_path(prefix, prefix ? strlen(prefix) : 0, file);

	if (collect_all) {
		git_all_attrs(&the_index, full_path, check);
	} else {
		git_check_attr(&the_index, full_path, check);
	}
	output_attr(check, file);

	free(full_path);
}

__attribute__((used)) static void check_attr_stdin_paths(const char *prefix,
				   struct attr_check *check,
				   int collect_all)
{
	struct strbuf buf = STRBUF_INIT;
	struct strbuf unquoted = STRBUF_INIT;
	strbuf_getline_fn getline_fn;

	getline_fn = nul_term_line ? strbuf_getline_nul : strbuf_getline_lf;
	while (getline_fn(&buf, stdin) != EOF) {
		if (!nul_term_line && buf.buf[0] == '"') {
			strbuf_reset(&unquoted);
			if (unquote_c_style(&unquoted, buf.buf, NULL))
				die("line is badly quoted");
			strbuf_swap(&buf, &unquoted);
		}
		check_attr(prefix, check, collect_all, buf.buf);
		maybe_flush_or_die(stdout, "attribute to stdout");
	}
	strbuf_release(&buf);
	strbuf_release(&unquoted);
}

int cmd_check_attr(int argc, const char **argv, const char *prefix)
{
	struct attr_check *check;
	int cnt, i, doubledash, filei;

	if (!is_bare_repository())
		setup_work_tree();

	git_config(git_default_config, NULL);

	argc = parse_options(argc, argv, prefix, check_attr_options,
			     check_attr_usage, PARSE_OPT_KEEP_DASHDASH);

	if (read_cache() < 0) {
		die("invalid cache");
	}

	if (cached_attrs)
		git_attr_set_direction(GIT_ATTR_INDEX);

	doubledash = -1;
	for (i = 0; doubledash < 0 && i < argc; i++) {
		if (!strcmp(argv[i], "--"))
			doubledash = i;
	}

	/* Process --all and/or attribute arguments: */
	if (all_attrs) {
		if (doubledash >= 1)
			error_with_usage("Attributes and --all both specified");

		cnt = 0;
		filei = doubledash + 1;
	} else if (doubledash == 0) {
		error_with_usage("No attribute specified");
	} else if (doubledash < 0) {
		if (!argc)
			error_with_usage("No attribute specified");

		if (stdin_paths) {
			/* Treat all arguments as attribute names. */
			cnt = argc;
			filei = argc;
		} else {
			/* Treat exactly one argument as an attribute name. */
			cnt = 1;
			filei = 1;
		}
	} else {
		cnt = doubledash;
		filei = doubledash + 1;
	}

	/* Check file argument(s): */
	if (stdin_paths) {
		if (filei < argc)
			error_with_usage("Can't specify files with --stdin");
	} else {
		if (filei >= argc)
			error_with_usage("No file specified");
	}

	check = attr_check_alloc();
	if (!all_attrs) {
		for (i = 0; i < cnt; i++) {
			const struct git_attr *a = git_attr(argv[i]);

			if (!a)
				return error("%s: not a valid attribute name",
					     argv[i]);
			attr_check_append(check, a);
		}
	}

	if (stdin_paths)
		check_attr_stdin_paths(prefix, check, all_attrs);
	else {
		for (i = filei; i < argc; i++)
			check_attr(prefix, check, all_attrs, argv[i]);
		maybe_flush_or_die(stdout, "attribute to stdout");
	}

	attr_check_free(check);
	return 0;
}

