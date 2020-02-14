#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct args_info {int argc; size_t pos; char** argv; } ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int (* git_command_fn ) (int /*<<< orphan*/ *,int,char**) ;
struct TYPE_5__ {char* name; int (* fn ) (int /*<<< orphan*/ *,int,char**) ;scalar_t__ requires_repo; } ;
struct TYPE_4__ {char* message; } ;

/* Variables and functions */
 struct args_info ARGS_INFO_INIT ; 
 size_t ARRAY_SIZE (TYPE_2__*) ; 
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,char const*) ; 
 TYPE_2__* commands ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_1__* git_error_last () ; 
 int /*<<< orphan*/  git_libgit2_init () ; 
 int /*<<< orphan*/  git_libgit2_shutdown () ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open_ext (int /*<<< orphan*/ **,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ optional_str_arg (char const**,struct args_info*,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static int run_command(git_command_fn fn, git_repository *repo, struct args_info args)
{
	int error;

	/* Run the command. If something goes wrong, print the error message to stderr */
	error = fn(repo, args.argc - args.pos, &args.argv[args.pos]);
	if (error < 0) {
		if (git_error_last() == NULL)
			fprintf(stderr, "Error without message");
		else
			fprintf(stderr, "Bad news:\n %s\n", git_error_last()->message);
	}

	return !!error;
}

__attribute__((used)) static int usage(const char *prog)
{
	size_t i;

	fprintf(stderr, "usage: %s <cmd>...\n\nAvailable commands:\n\n", prog);
	for (i = 0; i < ARRAY_SIZE(commands); i++)
		fprintf(stderr, "\t%s\n", commands[i].name);

	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	struct args_info args = ARGS_INFO_INIT;
	git_repository *repo = NULL;
	const char *git_dir = NULL;
	int return_code = 1;
	size_t i;

	if (argc < 2)
		usage(argv[0]);

	git_libgit2_init();

	for (args.pos = 1; args.pos < args.argc; ++args.pos) {
		char *a = args.argv[args.pos];

		if (a[0] != '-') {
			/* non-arg */
			break;
		} else if (optional_str_arg(&git_dir, &args, "--git-dir", ".git")) {
			continue;
		} else if (!strcmp(a, "--")) {
			/* arg separator */
			break;
		}
	}

	if (args.pos == args.argc)
		usage(argv[0]);

	if (!git_dir)
		git_dir = ".";

	for (i = 0; i < ARRAY_SIZE(commands); ++i) {
		if (strcmp(args.argv[args.pos], commands[i].name))
			continue;

		/*
		 * Before running the actual command, create an instance
		 * of the local repository and pass it to the function.
		 * */
		if (commands[i].requires_repo) {
			check_lg2(git_repository_open_ext(&repo, git_dir, 0, NULL),
				  "Unable to open repository '%s'", git_dir);
		}

		return_code = run_command(commands[i].fn, repo, args);
		goto shutdown;
	}

	fprintf(stderr, "Command not found: %s\n", argv[1]);

shutdown:
	git_repository_free(repo);
	git_libgit2_shutdown();

	return return_code;
}

