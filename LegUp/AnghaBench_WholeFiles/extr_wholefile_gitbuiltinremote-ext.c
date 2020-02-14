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
struct strbuf {int dummy; } ;
struct argv_array {int dummy; } ;
struct child_process {int in; int out; struct argv_array args; scalar_t__ err; } ;

/* Variables and functions */
 struct child_process CHILD_PROCESS_INIT ; 
 int MAXCOMMAND ; 
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  argv_array_push (struct argv_array*,char*) ; 
 int bidirectional_transfer_loop (int,int) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 scalar_t__ ferror (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fgets (char*,int,int /*<<< orphan*/ ) ; 
 int finish_command (struct child_process*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* git_req ; 
 char* git_req_vhost ; 
 scalar_t__ isspace (char) ; 
 int /*<<< orphan*/  packet_write_fmt (int,char*,char const*,char const*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  setenv (char*,char const*,int) ; 
 int /*<<< orphan*/  skip_prefix (char const*,char*,char const**) ; 
 scalar_t__ start_command (struct child_process*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strbuf_addch (struct strbuf*,char const) ; 
 int /*<<< orphan*/  strbuf_addstr (struct strbuf*,char const*) ; 
 char* strbuf_detach (struct strbuf*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 size_t strlen (char*) ; 
 int /*<<< orphan*/  strncmp (char*,char*,int) ; 
 int /*<<< orphan*/  usage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usage_msg ; 

__attribute__((used)) static char *strip_escapes(const char *str, const char *service,
	const char **next)
{
	size_t rpos = 0;
	int escape = 0;
	char special = 0;
	const char *service_noprefix = service;
	struct strbuf ret = STRBUF_INIT;

	skip_prefix(service_noprefix, "git-", &service_noprefix);

	/* Pass the service to command. */
	setenv("GIT_EXT_SERVICE", service, 1);
	setenv("GIT_EXT_SERVICE_NOPREFIX", service_noprefix, 1);

	/* Scan the length of argument. */
	while (str[rpos] && (escape || str[rpos] != ' ')) {
		if (escape) {
			switch (str[rpos]) {
			case ' ':
			case '%':
			case 's':
			case 'S':
				break;
			case 'G':
			case 'V':
				special = str[rpos];
				if (rpos == 1)
					break;
				/* fallthrough */
			default:
				die("Bad remote-ext placeholder '%%%c'.",
					str[rpos]);
			}
			escape = 0;
		} else
			escape = (str[rpos] == '%');
		rpos++;
	}
	if (escape && !str[rpos])
		die("remote-ext command has incomplete placeholder");
	*next = str + rpos;
	if (**next == ' ')
		++*next;	/* Skip over space */

	/*
	 * Do the actual placeholder substitution. The string will be short
	 * enough not to overflow integers.
	 */
	rpos = special ? 2 : 0;		/* Skip first 2 bytes in specials. */
	escape = 0;
	while (str[rpos] && (escape || str[rpos] != ' ')) {
		if (escape) {
			switch (str[rpos]) {
			case ' ':
			case '%':
				strbuf_addch(&ret, str[rpos]);
				break;
			case 's':
				strbuf_addstr(&ret, service_noprefix);
				break;
			case 'S':
				strbuf_addstr(&ret, service);
				break;
			}
			escape = 0;
		} else
			switch (str[rpos]) {
			case '%':
				escape = 1;
				break;
			default:
				strbuf_addch(&ret, str[rpos]);
				break;
			}
		rpos++;
	}
	switch (special) {
	case 'G':
		git_req = strbuf_detach(&ret, NULL);
		return NULL;
	case 'V':
		git_req_vhost = strbuf_detach(&ret, NULL);
		return NULL;
	default:
		return strbuf_detach(&ret, NULL);
	}
}

__attribute__((used)) static void parse_argv(struct argv_array *out, const char *arg, const char *service)
{
	while (*arg) {
		char *expanded = strip_escapes(arg, service, &arg);
		if (expanded)
			argv_array_push(out, expanded);
		free(expanded);
	}
}

__attribute__((used)) static void send_git_request(int stdin_fd, const char *serv, const char *repo,
	const char *vhost)
{
	if (!vhost)
		packet_write_fmt(stdin_fd, "%s %s%c", serv, repo, 0);
	else
		packet_write_fmt(stdin_fd, "%s %s%chost=%s%c", serv, repo, 0,
			     vhost, 0);
}

__attribute__((used)) static int run_child(const char *arg, const char *service)
{
	int r;
	struct child_process child = CHILD_PROCESS_INIT;

	child.in = -1;
	child.out = -1;
	child.err = 0;
	parse_argv(&child.args, arg, service);

	if (start_command(&child) < 0)
		die("Can't run specified command");

	if (git_req)
		send_git_request(child.in, service, git_req, git_req_vhost);

	r = bidirectional_transfer_loop(child.out, child.in);
	if (!r)
		r = finish_command(&child);
	else
		finish_command(&child);
	return r;
}

__attribute__((used)) static int command_loop(const char *child)
{
	char buffer[MAXCOMMAND];

	while (1) {
		size_t i;
		if (!fgets(buffer, MAXCOMMAND - 1, stdin)) {
			if (ferror(stdin))
				die("Command input error");
			exit(0);
		}
		/* Strip end of line characters. */
		i = strlen(buffer);
		while (i > 0 && isspace(buffer[i - 1]))
			buffer[--i] = 0;

		if (!strcmp(buffer, "capabilities")) {
			printf("*connect\n\n");
			fflush(stdout);
		} else if (!strncmp(buffer, "connect ", 8)) {
			printf("\n");
			fflush(stdout);
			return run_child(child, buffer + 8);
		} else {
			fprintf(stderr, "Bad command");
			return 1;
		}
	}
}

int cmd_remote_ext(int argc, const char **argv, const char *prefix)
{
	if (argc != 3)
		usage(usage_msg);

	return command_loop(argv[2]);
}

