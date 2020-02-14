#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct opts {char* member_0; char* rev; int verbose; int action; int /*<<< orphan*/  dir; int /*<<< orphan*/  member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/ * member_1; } ;
struct args_info {int pos; } ;
typedef  int /*<<< orphan*/  oidstr ;
typedef  int /*<<< orphan*/  git_tree_entry ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_tag ;
struct TYPE_7__ {int offset; scalar_t__ time; } ;
struct TYPE_8__ {char* name; char* email; TYPE_1__ when; } ;
typedef  TYPE_2__ git_signature ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_odb_object ;
typedef  int /*<<< orphan*/  git_odb ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_commit ;
typedef  int /*<<< orphan*/  git_blob ;

/* Variables and functions */
 struct args_info ARGS_INFO_INIT ; 
#define  GIT_OBJECT_BLOB 135 
#define  GIT_OBJECT_COMMIT 134 
#define  GIT_OBJECT_TAG 133 
#define  GIT_OBJECT_TREE 132 
 int /*<<< orphan*/  GIT_OID_HEXSZ ; 
#define  SHOW_NONE 131 
#define  SHOW_PRETTY 130 
#define  SHOW_SIZE 129 
#define  SHOW_TYPE 128 
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fwrite (int /*<<< orphan*/ ,size_t,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_blob_rawcontent (int /*<<< orphan*/  const*) ; 
 scalar_t__ git_blob_rawsize (int /*<<< orphan*/  const*) ; 
 TYPE_2__* git_commit_author (int /*<<< orphan*/  const*) ; 
 TYPE_2__* git_commit_committer (int /*<<< orphan*/  const*) ; 
 char* git_commit_message (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_commit_parent_id (int /*<<< orphan*/  const*,unsigned int) ; 
 scalar_t__ git_commit_parentcount (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_commit_tree_id (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_type (int /*<<< orphan*/ *) ; 
 char* git_object_type2string (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_object_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_odb_object_size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_tostr (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_odb (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*) ; 
 char* git_tag_message (int /*<<< orphan*/  const*) ; 
 char* git_tag_name (int /*<<< orphan*/  const*) ; 
 TYPE_2__* git_tag_tagger (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_tag_target_id (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_tag_target_type (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * git_tree_entry_byindex (int /*<<< orphan*/  const*,size_t) ; 
 int git_tree_entry_filemode (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_tree_entry_id (int /*<<< orphan*/  const*) ; 
 char* git_tree_entry_name (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_tree_entry_type (int /*<<< orphan*/  const*) ; 
 scalar_t__ git_tree_entrycount (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  match_str_arg (int /*<<< orphan*/ *,struct args_info*,char*) ; 
static  void parse_opts (struct opts*,int,char**) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

__attribute__((used)) static void print_signature(const char *header, const git_signature *sig)
{
	char sign;
	int offset, hours, minutes;

	if (!sig)
		return;

	offset = sig->when.offset;
	if (offset < 0) {
		sign = '-';
		offset = -offset;
	} else {
		sign = '+';
	}

	hours   = offset / 60;
	minutes = offset % 60;

	printf("%s %s <%s> %ld %c%02d%02d\n",
		   header, sig->name, sig->email, (long)sig->when.time,
		   sign, hours, minutes);
}

__attribute__((used)) static void show_blob(const git_blob *blob)
{
	/* ? Does this need crlf filtering? */
	fwrite(git_blob_rawcontent(blob), (size_t)git_blob_rawsize(blob), 1, stdout);
}

__attribute__((used)) static void show_tree(const git_tree *tree)
{
	size_t i, max_i = (int)git_tree_entrycount(tree);
	char oidstr[GIT_OID_HEXSZ + 1];
	const git_tree_entry *te;

	for (i = 0; i < max_i; ++i) {
		te = git_tree_entry_byindex(tree, i);

		git_oid_tostr(oidstr, sizeof(oidstr), git_tree_entry_id(te));

		printf("%06o %s %s\t%s\n",
			git_tree_entry_filemode(te),
			git_object_type2string(git_tree_entry_type(te)),
			oidstr, git_tree_entry_name(te));
	}
}

__attribute__((used)) static void show_commit(const git_commit *commit)
{
	unsigned int i, max_i;
	char oidstr[GIT_OID_HEXSZ + 1];

	git_oid_tostr(oidstr, sizeof(oidstr), git_commit_tree_id(commit));
	printf("tree %s\n", oidstr);

	max_i = (unsigned int)git_commit_parentcount(commit);
	for (i = 0; i < max_i; ++i) {
		git_oid_tostr(oidstr, sizeof(oidstr), git_commit_parent_id(commit, i));
		printf("parent %s\n", oidstr);
	}

	print_signature("author", git_commit_author(commit));
	print_signature("committer", git_commit_committer(commit));

	if (git_commit_message(commit))
		printf("\n%s\n", git_commit_message(commit));
}

__attribute__((used)) static void show_tag(const git_tag *tag)
{
	char oidstr[GIT_OID_HEXSZ + 1];

	git_oid_tostr(oidstr, sizeof(oidstr), git_tag_target_id(tag));;
	printf("object %s\n", oidstr);
	printf("type %s\n", git_object_type2string(git_tag_target_type(tag)));
	printf("tag %s\n", git_tag_name(tag));
	print_signature("tagger", git_tag_tagger(tag));

	if (git_tag_message(tag))
		printf("\n%s\n", git_tag_message(tag));
}

int lg2_cat_file(git_repository *repo, int argc, char *argv[])
{
	struct opts o = { ".", NULL, 0, 0 };
	git_object *obj = NULL;
	char oidstr[GIT_OID_HEXSZ + 1];

	parse_opts(&o, argc, argv);

	check_lg2(git_revparse_single(&obj, repo, o.rev),
			"Could not resolve", o.rev);

	if (o.verbose) {
		char oidstr[GIT_OID_HEXSZ + 1];
		git_oid_tostr(oidstr, sizeof(oidstr), git_object_id(obj));

		printf("%s %s\n--\n",
			git_object_type2string(git_object_type(obj)), oidstr);
	}

	switch (o.action) {
	case SHOW_TYPE:
		printf("%s\n", git_object_type2string(git_object_type(obj)));
		break;
	case SHOW_SIZE: {
		git_odb *odb;
		git_odb_object *odbobj;

		check_lg2(git_repository_odb(&odb, repo), "Could not open ODB", NULL);
		check_lg2(git_odb_read(&odbobj, odb, git_object_id(obj)),
			"Could not find obj", NULL);

		printf("%ld\n", (long)git_odb_object_size(odbobj));

		git_odb_object_free(odbobj);
		git_odb_free(odb);
		}
		break;
	case SHOW_NONE:
		/* just want return result */
		break;
	case SHOW_PRETTY:

		switch (git_object_type(obj)) {
		case GIT_OBJECT_BLOB:
			show_blob((const git_blob *)obj);
			break;
		case GIT_OBJECT_COMMIT:
			show_commit((const git_commit *)obj);
			break;
		case GIT_OBJECT_TREE:
			show_tree((const git_tree *)obj);
			break;
		case GIT_OBJECT_TAG:
			show_tag((const git_tag *)obj);
			break;
		default:
			printf("unknown %s\n", oidstr);
			break;
		}
		break;
	}

	git_object_free(obj);

	return 0;
}

__attribute__((used)) static void usage(const char *message, const char *arg)
{
	if (message && arg)
		fprintf(stderr, "%s: %s\n", message, arg);
	else if (message)
		fprintf(stderr, "%s\n", message);
	fprintf(stderr,
			"usage: cat-file (-t | -s | -e | -p) [-v] [-q] "
			"[-h|--help] [--git-dir=<dir>] <object>\n");
	exit(1);
}

__attribute__((used)) static void parse_opts(struct opts *o, int argc, char *argv[])
{
	struct args_info args = ARGS_INFO_INIT;

	for (args.pos = 1; args.pos < argc; ++args.pos) {
		char *a = argv[args.pos];

		if (a[0] != '-') {
			if (o->rev != NULL)
				usage("Only one rev should be provided", NULL);
			else
				o->rev = a;
		}
		else if (!strcmp(a, "-t"))
			o->action = SHOW_TYPE;
		else if (!strcmp(a, "-s"))
			o->action = SHOW_SIZE;
		else if (!strcmp(a, "-e"))
			o->action = SHOW_NONE;
		else if (!strcmp(a, "-p"))
			o->action = SHOW_PRETTY;
		else if (!strcmp(a, "-q"))
			o->verbose = 0;
		else if (!strcmp(a, "-v"))
			o->verbose = 1;
		else if (!strcmp(a, "--help") || !strcmp(a, "-h"))
			usage(NULL, NULL);
		else if (!match_str_arg(&o->dir, &args, "--git-dir"))
			usage("Unknown option", a);
	}

	if (!o->action || !o->rev)
		usage(NULL, NULL);

}

