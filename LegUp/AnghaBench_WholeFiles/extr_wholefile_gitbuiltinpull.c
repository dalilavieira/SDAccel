#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct strbuf {int /*<<< orphan*/  buf; } ;
struct remote {char* name; } ;
struct option {int* value; } ;
struct oid_array {int dummy; } ;
struct object_id {int dummy; } ;
struct branch {int /*<<< orphan*/  name; } ;
struct argv_array {int dummy; } ;
typedef  enum rebase_type { ____Placeholder_rebase_type } rebase_type ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ EOF ; 
 int REBASE_FALSE ; 
 int REBASE_INTERACTIVE ; 
 int REBASE_INVALID ; 
 int REBASE_MERGES ; 
 int REBASE_PRESERVE ; 
 int REBASE_TRUE ; 
 int /*<<< orphan*/  RECURSE_SUBMODULES_OFF ; 
 int /*<<< orphan*/  RECURSE_SUBMODULES_ON ; 
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  argv_array_push (struct argv_array*,char*) ; 
 struct branch* branch_get (char*) ; 
 scalar_t__ config_autostash ; 
 int /*<<< orphan*/  die (int /*<<< orphan*/ ,char const*,...) ; 
 int /*<<< orphan*/  error (int /*<<< orphan*/ ,char const*,char const*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ git_config_bool (char const*,char const*) ; 
 scalar_t__ git_config_get_value (char*,char const**) ; 
 int git_default_config (char const*,char const*,void*) ; 
 int git_parse_maybe_bool (char const*) ; 
 char* git_path_fetch_head (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oid_array_append (struct oid_array*,struct object_id*) ; 
 int opt_force ; 
 int opt_verbosity ; 
 scalar_t__ parse_oid_hex (int /*<<< orphan*/ ,struct object_id*,char const**) ; 
 int /*<<< orphan*/  recurse_submodules ; 
 int /*<<< orphan*/  setenv (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ starts_with (char const*,char*) ; 
 int /*<<< orphan*/  strbuf_addch (struct strbuf*,char) ; 
 int /*<<< orphan*/  strbuf_addstr (struct strbuf*,char const*) ; 
 scalar_t__ strbuf_getline_lf (struct strbuf*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  the_repository ; 
 int /*<<< orphan*/ * xfopen (char const*,char*) ; 
 char* xstrfmt (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum rebase_type parse_config_rebase(const char *key, const char *value,
		int fatal)
{
	int v = git_parse_maybe_bool(value);

	if (!v)
		return REBASE_FALSE;
	else if (v > 0)
		return REBASE_TRUE;
	else if (!strcmp(value, "preserve") || !strcmp(value, "p"))
		return REBASE_PRESERVE;
	else if (!strcmp(value, "merges") || !strcmp(value, "m"))
		return REBASE_MERGES;
	else if (!strcmp(value, "interactive") || !strcmp(value, "i"))
		return REBASE_INTERACTIVE;
	/*
	 * Please update _git_config() in git-completion.bash when you
	 * add new rebase modes.
	 */

	if (fatal)
		die(_("Invalid value for %s: %s"), key, value);
	else
		error(_("Invalid value for %s: %s"), key, value);

	return REBASE_INVALID;
}

__attribute__((used)) static int parse_opt_rebase(const struct option *opt, const char *arg, int unset)
{
	enum rebase_type *value = opt->value;

	if (arg)
		*value = parse_config_rebase("--rebase", arg, 0);
	else
		*value = unset ? REBASE_FALSE : REBASE_TRUE;
	return *value == REBASE_INVALID ? -1 : 0;
}

__attribute__((used)) static void argv_push_verbosity(struct argv_array *arr)
{
	int verbosity;

	for (verbosity = opt_verbosity; verbosity > 0; verbosity--)
		argv_array_push(arr, "-v");

	for (verbosity = opt_verbosity; verbosity < 0; verbosity++)
		argv_array_push(arr, "-q");
}

__attribute__((used)) static void argv_push_force(struct argv_array *arr)
{
	int force = opt_force;
	while (force-- > 0)
		argv_array_push(arr, "-f");
}

__attribute__((used)) static void set_reflog_message(int argc, const char **argv)
{
	int i;
	struct strbuf msg = STRBUF_INIT;

	for (i = 0; i < argc; i++) {
		if (i)
			strbuf_addch(&msg, ' ');
		strbuf_addstr(&msg, argv[i]);
	}

	setenv("GIT_REFLOG_ACTION", msg.buf, 0);

	strbuf_release(&msg);
}

__attribute__((used)) static const char *config_get_ff(void)
{
	const char *value;

	if (git_config_get_value("pull.ff", &value))
		return NULL;

	switch (git_parse_maybe_bool(value)) {
	case 0:
		return "--no-ff";
	case 1:
		return "--ff";
	}

	if (!strcmp(value, "only"))
		return "--ff-only";

	die(_("Invalid value for pull.ff: %s"), value);
}

__attribute__((used)) static enum rebase_type config_get_rebase(void)
{
	struct branch *curr_branch = branch_get("HEAD");
	const char *value;

	if (curr_branch) {
		char *key = xstrfmt("branch.%s.rebase", curr_branch->name);

		if (!git_config_get_value(key, &value)) {
			enum rebase_type ret = parse_config_rebase(key, value, 1);
			free(key);
			return ret;
		}

		free(key);
	}

	if (!git_config_get_value("pull.rebase", &value))
		return parse_config_rebase("pull.rebase", value, 1);

	return REBASE_FALSE;
}

__attribute__((used)) static int git_pull_config(const char *var, const char *value, void *cb)
{
	if (!strcmp(var, "rebase.autostash")) {
		config_autostash = git_config_bool(var, value);
		return 0;
	} else if (!strcmp(var, "submodule.recurse")) {
		recurse_submodules = git_config_bool(var, value) ?
			RECURSE_SUBMODULES_ON : RECURSE_SUBMODULES_OFF;
		return 0;
	}
	return git_default_config(var, value, cb);
}

__attribute__((used)) static void get_merge_heads(struct oid_array *merge_heads)
{
	const char *filename = git_path_fetch_head(the_repository);
	FILE *fp;
	struct strbuf sb = STRBUF_INIT;
	struct object_id oid;

	fp = xfopen(filename, "r");
	while (strbuf_getline_lf(&sb, fp) != EOF) {
		const char *p;
		if (parse_oid_hex(sb.buf, &oid, &p))
			continue;  /* invalid line: does not start with object ID */
		if (starts_with(p, "\tnot-for-merge\t"))
			continue;  /* ref is not-for-merge */
		oid_array_append(merge_heads, &oid);
	}
	fclose(fp);
	strbuf_release(&sb);
}

__attribute__((used)) static int get_only_remote(struct remote *remote, void *cb_data)
{
	const char **remote_name = cb_data;

	if (*remote_name)
		return -1;

	*remote_name = remote->name;
	return 0;
}

