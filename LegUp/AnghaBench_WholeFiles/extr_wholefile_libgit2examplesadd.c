#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct print_payload {int options; int /*<<< orphan*/ * repo; int /*<<< orphan*/  member_0; } ;
struct TYPE_5__ {int count; char** strings; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_strarray ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int (* git_index_matched_path_cb ) (char const*,char const*,void*) ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 unsigned int GIT_STATUS_WT_MODIFIED ; 
 unsigned int GIT_STATUS_WT_NEW ; 
 int SKIP ; 
 int UPDATE ; 
 int VERBOSE ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 char** calloc (int,int) ; 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  git_index_add_all (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ,int (*) (char const*,char const*,void*),struct print_payload*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_update_all (int /*<<< orphan*/ *,TYPE_1__*,int (*) (char const*,char const*,void*),struct print_payload*) ; 
 int /*<<< orphan*/  git_index_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 scalar_t__ git_status_file (unsigned int*,int /*<<< orphan*/ *,char const*) ; 
 void init_array (TYPE_1__*,int,char**) ; 
static  void parse_opts (int*,int*,int,char**) ; 
 int print_matched_cb (char const*,char const*,void*) ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

int lg2_add(git_repository *repo, int argc, char** argv)
{
	git_index_matched_path_cb matched_cb = NULL;
	git_index *index;
	git_strarray array = {0};
	int options = 0, count = 0;
	struct print_payload payload = {0};

	parse_opts(&options, &count, argc, argv);
	init_array(&array, argc-count, argv+count);

	check_lg2(git_repository_index(&index, repo), "Could not open repository index", NULL);

	/* Setup a callback if the requested options need it */
	if ((options & VERBOSE) || (options & SKIP)) {
		matched_cb = &print_matched_cb;
	}

	/* Perform the requested action with the index and files */
	payload.options = options;
	payload.repo = repo;

	if (options & UPDATE) {
		git_index_update_all(index, &array, matched_cb, &payload);
	} else {
		git_index_add_all(index, &array, 0, matched_cb, &payload);
	}

	/* Cleanup memory */
	git_index_write(index);
	git_index_free(index);

	return 0;
}

int print_matched_cb(const char *path, const char *matched_pathspec, void *payload)
{
	struct print_payload p = *(struct print_payload*)(payload);
	int ret;
	unsigned status;
	(void)matched_pathspec;

	/* Get the file status */
	if (git_status_file(&status, p.repo, path)) {
		return -1;
	}

	if ((status & GIT_STATUS_WT_MODIFIED) || (status & GIT_STATUS_WT_NEW)) {
		printf("add '%s'\n", path);
		ret = 0;
	} else {
		ret = 1;
	}

	if ((p.options & SKIP)) {
		ret = 1;
	}

	return ret;
}

void init_array(git_strarray *array, int argc, char **argv)
{
	unsigned int i;

	array->count = argc;
	array->strings = calloc(array->count, sizeof(char *));
	assert(array->strings != NULL);

	for (i = 0; i < array->count; i++) {
		array->strings[i] = argv[i];
	}

	return;
}

void print_usage(void)
{
	fprintf(stderr, "usage: add [options] [--] file-spec [file-spec] [...]\n\n");
	fprintf(stderr, "\t-n, --dry-run    dry run\n");
	fprintf(stderr, "\t-v, --verbose    be verbose\n");
	fprintf(stderr, "\t-u, --update     update tracked files\n");
	exit(1);
}

__attribute__((used)) static void parse_opts(int *options, int *count, int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; ++i) {
		if (argv[i][0] != '-')
			break;
		else if (!strcmp(argv[i], "--verbose") || !strcmp(argv[i], "-v"))
			*options |= VERBOSE;
		else if (!strcmp(argv[i], "--dry-run") || !strcmp(argv[i], "-n"))
			*options |= SKIP;
		else if (!strcmp(argv[i], "--update") || !strcmp(argv[i], "-u"))
			*options |= UPDATE;
		else if (!strcmp(argv[i], "-h")) {
			print_usage();
			break;
		} else if (!strcmp(argv[i], "--")) {
			i++;
			break;
		} else {
			fprintf(stderr, "Unsupported option %s.\n", argv[i]);
			print_usage();
		}
	}

	if (argc <= i)
		print_usage();

	*count = i;
}

