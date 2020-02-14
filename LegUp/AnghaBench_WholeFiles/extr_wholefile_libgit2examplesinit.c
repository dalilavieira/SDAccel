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
typedef  void* uint32_t ;
struct opts {int member_0; void* member_4; char* dir; int bare; char const* template; char* gitdir; scalar_t__ shared; int quiet; int initial_commit; scalar_t__ no_options; int /*<<< orphan*/  member_7; int /*<<< orphan*/  member_6; int /*<<< orphan*/  member_5; int /*<<< orphan*/  member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; } ;
struct args_info {int pos; } ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_signature ;
struct TYPE_4__ {char const* template_path; char* workdir_path; scalar_t__ mode; int /*<<< orphan*/  flags; } ;
typedef  TYPE_1__ git_repository_init_options ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 struct args_info ARGS_INFO_INIT ; 
 int /*<<< orphan*/  GIT_REPOSITORY_INIT_BARE ; 
 int /*<<< orphan*/  GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE ; 
 int /*<<< orphan*/  GIT_REPOSITORY_INIT_MKPATH ; 
 TYPE_1__ GIT_REPOSITORY_INIT_OPTIONS_INIT ; 
 void* GIT_REPOSITORY_INIT_SHARED_ALL ; 
 void* GIT_REPOSITORY_INIT_SHARED_GROUP ; 
 void* GIT_REPOSITORY_INIT_SHARED_UMASK ; 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
static  void create_initial_commit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fatal (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ git_commit_create_v (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_index_write_tree (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_init (int /*<<< orphan*/ **,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_init_ext (int /*<<< orphan*/ **,char*,TYPE_1__*) ; 
 char* git_repository_path (int /*<<< orphan*/ *) ; 
 char* git_repository_workdir (int /*<<< orphan*/ *) ; 
 scalar_t__ git_signature_default (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_signature_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_tree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ match_str_arg (char const**,struct args_info*,char*) ; 
static  void parse_opts (struct opts*,int,char**) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 long strtol (char const*,char**,int) ; 

int lg2_init(git_repository *repo, int argc, char *argv[])
{
	struct opts o = { 1, 0, 0, 0, GIT_REPOSITORY_INIT_SHARED_UMASK, 0, 0, 0 };

	parse_opts(&o, argc, argv);

	/* Initialize repository. */

	if (o.no_options) {
		/**
		 * No options were specified, so let's demonstrate the default
		 * simple case of git_repository_init() API usage...
		 */
		check_lg2(git_repository_init(&repo, o.dir, 0),
			"Could not initialize repository", NULL);
	}
	else {
		/**
		 * Some command line options were specified, so we'll use the
		 * extended init API to handle them
		 */
		git_repository_init_options initopts = GIT_REPOSITORY_INIT_OPTIONS_INIT;
		initopts.flags = GIT_REPOSITORY_INIT_MKPATH;

		if (o.bare)
			initopts.flags |= GIT_REPOSITORY_INIT_BARE;

		if (o.template) {
			initopts.flags |= GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE;
			initopts.template_path = o.template;
		}

		if (o.gitdir) {
			/**
			 * If you specified a separate git directory, then initialize
			 * the repository at that path and use the second path as the
			 * working directory of the repository (with a git-link file)
			 */
			initopts.workdir_path = o.dir;
			o.dir = o.gitdir;
		}

		if (o.shared != 0)
			initopts.mode = o.shared;

		check_lg2(git_repository_init_ext(&repo, o.dir, &initopts),
				"Could not initialize repository", NULL);
	}

	/** Print a message to stdout like "git init" does. */

	if (!o.quiet) {
		if (o.bare || o.gitdir)
			o.dir = git_repository_path(repo);
		else
			o.dir = git_repository_workdir(repo);

		printf("Initialized empty Git repository in %s\n", o.dir);
	}

	/**
	 * As an extension to the basic "git init" command, this example
	 * gives the option to create an empty initial commit.  This is
	 * mostly to demonstrate what it takes to do that, but also some
	 * people like to have that empty base commit in their repo.
	 */
	if (o.initial_commit) {
		create_initial_commit(repo);
		printf("Created empty initial commit\n");
	}

	git_repository_free(repo);

	return 0;
}

__attribute__((used)) static void create_initial_commit(git_repository *repo)
{
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;

	/** First use the config to initialize a commit signature for the user. */

	if (git_signature_default(&sig, repo) < 0)
		fatal("Unable to create a commit signature.",
		      "Perhaps 'user.name' and 'user.email' are not set");

	/* Now let's create an empty tree for this commit */

	if (git_repository_index(&index, repo) < 0)
		fatal("Could not open repository index", NULL);

	/**
	 * Outside of this example, you could call git_index_add_bypath()
	 * here to put actual files into the index.  For our purposes, we'll
	 * leave it empty for now.
	 */

	if (git_index_write_tree(&tree_id, index) < 0)
		fatal("Unable to write initial tree from index", NULL);

	git_index_free(index);

	if (git_tree_lookup(&tree, repo, &tree_id) < 0)
		fatal("Could not look up initial tree", NULL);

	/**
	 * Ready to create the initial commit.
	 *
	 * Normally creating a commit would involve looking up the current
	 * HEAD commit and making that be the parent of the initial commit,
	 * but here this is the first commit so there will be no parent.
	 */

	if (git_commit_create_v(
			&commit_id, repo, "HEAD", sig, sig,
			NULL, "Initial commit", tree, 0) < 0)
		fatal("Could not create the initial commit", NULL);

	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
}

__attribute__((used)) static void usage(const char *error, const char *arg)
{
	fprintf(stderr, "error: %s '%s'\n", error, arg);
	fprintf(stderr,
			"usage: init [-q | --quiet] [--bare] [--template=<dir>]\n"
			"            [--shared[=perms]] [--initial-commit]\n"
			"            [--separate-git-dir] <directory>\n");
	exit(1);
}

__attribute__((used)) static uint32_t parse_shared(const char *shared)
{
	if (!strcmp(shared, "false") || !strcmp(shared, "umask"))
		return GIT_REPOSITORY_INIT_SHARED_UMASK;

	else if (!strcmp(shared, "true") || !strcmp(shared, "group"))
		return GIT_REPOSITORY_INIT_SHARED_GROUP;

	else if (!strcmp(shared, "all") || !strcmp(shared, "world") ||
			 !strcmp(shared, "everybody"))
		return GIT_REPOSITORY_INIT_SHARED_ALL;

	else if (shared[0] == '0') {
		long val;
		char *end = NULL;
		val = strtol(shared + 1, &end, 8);
		if (end == shared + 1 || *end != 0)
			usage("invalid octal value for --shared", shared);
		return (uint32_t)val;
	}

	else
		usage("unknown value for --shared", shared);

	return 0;
}

__attribute__((used)) static void parse_opts(struct opts *o, int argc, char *argv[])
{
	struct args_info args = ARGS_INFO_INIT;
	const char *sharedarg;

	/** Process arguments. */

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		char *a = argv[args.pos];

		if (a[0] == '-')
			o->no_options = 0;

		if (a[0] != '-') {
			if (o->dir != NULL)
				usage("extra argument", a);
			o->dir = a;
		}
		else if (!strcmp(a, "-q") || !strcmp(a, "--quiet"))
			o->quiet = 1;
		else if (!strcmp(a, "--bare"))
			o->bare = 1;
		else if (!strcmp(a, "--shared"))
			o->shared = GIT_REPOSITORY_INIT_SHARED_GROUP;
		else if (!strcmp(a, "--initial-commit"))
			o->initial_commit = 1;
		else if (match_str_arg(&sharedarg, &args, "--shared"))
			o->shared = parse_shared(sharedarg);
		else if (!match_str_arg(&o->template, &args, "--template") ||
		         !match_str_arg(&o->gitdir, &args, "--separate-git-dir"))
			usage("unknown option", a);
	}

	if (!o->dir)
		usage("must specify directory to init", NULL);
}

