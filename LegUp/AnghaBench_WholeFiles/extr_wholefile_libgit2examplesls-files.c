#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int file_count; char** files; int error_unmatch; } ;
typedef  TYPE_1__ ls_options ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_9__ {char const* path; } ;
typedef  TYPE_2__ git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_INDEX_STAGE_NORMAL ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 size_t git_index_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 TYPE_2__* git_index_get_byindex (int /*<<< orphan*/ *,size_t) ; 
 TYPE_2__* git_index_get_bypath (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  puts (char const*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

__attribute__((used)) static void usage(const char *message, const char *arg)
{
	if (message && arg)
		fprintf(stderr, "%s: %s\n", message, arg);
	else if (message)
		fprintf(stderr, "%s\n", message);
	fprintf(stderr, "usage: ls-files [--error-unmatch] [--] [<file>...]\n");
	exit(1);
}

__attribute__((used)) static int parse_options(ls_options *opts, int argc, char *argv[])
{
	int parsing_files = 0;
	int i;

	memset(opts, 0, sizeof(ls_options));

	if (argc < 2)
		return 0;

	for (i = 1; i < argc; ++i) {
		char *a = argv[i];

		/* if it doesn't start with a '-' or is after the '--' then it is a file */
		if (a[0] != '-' || parsing_files) {
			parsing_files = 1;

			/* watch for overflows (just in case) */
			if (opts->file_count == 1024) {
				fprintf(stderr, "ls-files can only support 1024 files at this time.\n");
				return -1;
			}

			opts->files[opts->file_count++] = a;
		} else if (!strcmp(a, "--")) {
			parsing_files = 1;
		} else if (!strcmp(a, "--error-unmatch")) {
			opts->error_unmatch = 1;
		} else {
			usage("Unsupported argument", a);
			return -1;
		}
	}

	return 0;
}

__attribute__((used)) static int print_paths(ls_options *opts, git_index *index)
{
	size_t i;
	const git_index_entry *entry;

	/* if there are no files explicitly listed by the user print all entries in the index */
	if (opts->file_count == 0) {
		size_t entry_count = git_index_entrycount(index);

		for (i = 0; i < entry_count; i++) {
			entry = git_index_get_byindex(index, i);
			puts(entry->path);
		}
		return 0;
	}

	/* loop through the files found in the args and print them if they exist */
	for (i = 0; i < opts->file_count; ++i) {
		const char *path = opts->files[i];

		if ((entry = git_index_get_bypath(index, path, GIT_INDEX_STAGE_NORMAL)) != NULL) {
			puts(path);
		} else if (opts->error_unmatch) {
			fprintf(stderr, "error: pathspec '%s' did not match any file(s) known to git.\n", path);
			fprintf(stderr, "Did you forget to 'git add'?\n");
			return -1;
		}
	}

	return 0;
}

int lg2_ls_files(git_repository *repo, int argc, char *argv[])
{
	git_index *index = NULL;
	ls_options opts;
	int error;

	if ((error = parse_options(&opts, argc, argv)) < 0)
		return error;

	if ((error = git_repository_index(&index, repo)) < 0)
		goto cleanup;

	error = print_paths(&opts, index);

cleanup:
	git_index_free(index);

	return error;
}

