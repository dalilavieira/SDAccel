#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct opts {int cmd; int argc; char** argv; int /*<<< orphan*/  member_0; } ;
struct TYPE_7__ {char const** strings; scalar_t__ count; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ git_strarray ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_remote ;
typedef  enum subcmd { ____Placeholder_subcmd } subcmd ;
struct TYPE_6__ {int /*<<< orphan*/  member_0; } ;

/* Variables and functions */
 int /*<<< orphan*/  check_lg2 (int,char*,char const*) ; 
static  int cmd_add (int /*<<< orphan*/ *,struct opts*) ; 
static  int cmd_remove (int /*<<< orphan*/ *,struct opts*) ; 
static  int cmd_rename (int /*<<< orphan*/ *,struct opts*) ; 
static  int cmd_seturl (int /*<<< orphan*/ *,struct opts*) ; 
static  int cmd_show (int /*<<< orphan*/ *,struct opts*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 int git_remote_create (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,char*) ; 
 int git_remote_delete (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ *) ; 
 int git_remote_list (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int git_remote_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 char* git_remote_pushurl (int /*<<< orphan*/ *) ; 
 int git_remote_rename (TYPE_2__*,int /*<<< orphan*/ *,char*,char*) ; 
 int git_remote_set_pushurl (int /*<<< orphan*/ *,char*,char*) ; 
 int git_remote_set_url (int /*<<< orphan*/ *,char*,char*) ; 
 char* git_remote_url (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_strarray_free (TYPE_2__*) ; 
static  void parse_subcmd (struct opts*,int,char**) ; 
 int /*<<< orphan*/  printf (char*,char const*,char const*) ; 
 int /*<<< orphan*/  puts (char const*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
#define  subcmd_add 132 
#define  subcmd_remove 131 
#define  subcmd_rename 130 
#define  subcmd_seturl 129 
#define  subcmd_show 128 
static  void usage (char const*,char const*) ; 

int lg2_remote(git_repository *repo, int argc, char *argv[])
{
	int retval = 0;
	struct opts opt = {0};

	parse_subcmd(&opt, argc, argv);

	switch (opt.cmd)
	{
	case subcmd_add:
		retval = cmd_add(repo, &opt);
		break;
	case subcmd_remove:
		retval = cmd_remove(repo, &opt);
		break;
	case subcmd_rename:
		retval = cmd_rename(repo, &opt);
		break;
	case subcmd_seturl:
		retval = cmd_seturl(repo, &opt);
		break;
	case subcmd_show:
		retval = cmd_show(repo, &opt);
		break;
	}

	return retval;
}

__attribute__((used)) static int cmd_add(git_repository *repo, struct opts *o)
{
	char *name, *url;
	git_remote *remote = {0};

	if (o->argc != 2)
		usage("you need to specify a name and URL", NULL);

	name = o->argv[0];
	url = o->argv[1];

	check_lg2(git_remote_create(&remote, repo, name, url),
			"could not create remote", NULL);

	return 0;
}

__attribute__((used)) static int cmd_remove(git_repository *repo, struct opts *o)
{
	char *name;

	if (o->argc != 1)
		usage("you need to specify a name", NULL);

	name = o->argv[0];

	check_lg2(git_remote_delete(repo, name),
			"could not delete remote", name);

	return 0;
}

__attribute__((used)) static int cmd_rename(git_repository *repo, struct opts *o)
{
	int i, retval;
	char *old, *new;
	git_strarray problems = {0};

	if (o->argc != 2)
		usage("you need to specify old and new remote name", NULL);

	old = o->argv[0];
	new = o->argv[1];

	retval = git_remote_rename(&problems, repo, old, new);
	if (!retval)
		return 0;

	for (i = 0; i < (int) problems.count; i++) {
		puts(problems.strings[0]);
	}

	git_strarray_free(&problems);

	return retval;
}

__attribute__((used)) static int cmd_seturl(git_repository *repo, struct opts *o)
{
	int i, retval, push = 0;
	char *name = NULL, *url = NULL;

	for (i = 0; i < o->argc; i++) {
		char *arg = o->argv[i];

		if (!strcmp(arg, "--push")) {
			push = 1;
		} else if (arg[0] != '-' && name == NULL) {
			name = arg;
		} else if (arg[0] != '-' && url == NULL) {
			url = arg;
		} else {
			usage("invalid argument to set-url", arg);
		}
	}

	if (name == NULL || url == NULL)
		usage("you need to specify remote and the new URL", NULL);

	if (push)
		retval = git_remote_set_pushurl(repo, name, url);
	else
		retval = git_remote_set_url(repo, name, url);

	check_lg2(retval, "could not set URL", url);

	return 0;
}

__attribute__((used)) static int cmd_show(git_repository *repo, struct opts *o)
{
	int i;
	const char *arg, *name, *fetch, *push;
	int verbose = 0;
	git_strarray remotes = {0};
	git_remote *remote = {0};

	for (i = 0; i < o->argc; i++) {
		arg = o->argv[i];

		if (!strcmp(arg, "-v") || !strcmp(arg, "--verbose")) {
			verbose = 1;
		}
	}

	check_lg2(git_remote_list(&remotes, repo),
		"could not retrieve remotes", NULL);

	for (i = 0; i < (int) remotes.count; i++) {
		name = remotes.strings[i];
		if (!verbose) {
			puts(name);
			continue;
		}

		check_lg2(git_remote_lookup(&remote, repo, name),
			"could not look up remote", name);

		fetch = git_remote_url(remote);
		if (fetch)
			printf("%s\t%s (fetch)\n", name, fetch);
		push = git_remote_pushurl(remote);
		/* use fetch URL if no distinct push URL has been set */
		push = push ? push : fetch;
		if (push)
			printf("%s\t%s (push)\n", name, push);

		git_remote_free(remote);
	}

	git_strarray_free(&remotes);

	return 0;
}

__attribute__((used)) static void parse_subcmd(
	struct opts *opt, int argc, char **argv)
{
	char *arg = argv[1];
	enum subcmd cmd = 0;

	if (argc < 2)
		usage("no command specified", NULL);

	if (!strcmp(arg, "add")) {
		cmd = subcmd_add;
	} else if (!strcmp(arg, "remove")) {
		cmd = subcmd_remove;
	} else if (!strcmp(arg, "rename")) {
		cmd = subcmd_rename;
	} else if (!strcmp(arg, "set-url")) {
		cmd = subcmd_seturl;
	} else if (!strcmp(arg, "show")) {
		cmd = subcmd_show;
	} else {
		usage("command is not valid", arg);
	}
	opt->cmd = cmd;

	opt->argc = argc - 2; /* executable and subcommand are removed */
	opt->argv = argv + 2;
}

__attribute__((used)) static void usage(const char *msg, const char *arg)
{
	fputs("usage: remote add <name> <url>\n", stderr);
	fputs("       remote remove <name>\n", stderr);
	fputs("       remote rename <old> <new>\n", stderr);
	fputs("       remote set-url [--push] <name> <newurl>\n", stderr);
	fputs("       remote show [-v|--verbose]\n", stderr);

	if (msg && !arg)
		fprintf(stderr, "\n%s\n", msg);
	else if (msg && arg)
		fprintf(stderr, "\n%s: %s\n", msg, arg);
	exit(1);
}

