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
struct stat {scalar_t__ st_mtime; } ;
struct rev_info {int exclude_promisor_objects; } ;
struct progress {int dummy; } ;
struct option {int dummy; } ;
struct object_id {int /*<<< orphan*/  hash; } ;
struct object {int flags; } ;
struct dirent {char const* d_name; } ;
typedef  enum object_type { ____Placeholder_object_type } object_type ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  N_ (char*) ; 
 struct option const OPT_BOOL (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ) ; 
 struct option const OPT_END () ; 
 struct option const OPT_EXPIRY_DATE (int /*<<< orphan*/ ,char*,scalar_t__*,int /*<<< orphan*/ ) ; 
 struct option const OPT__DRY_RUN (scalar_t__*,int /*<<< orphan*/ ) ; 
 struct option const OPT__VERBOSE (scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PRUNE_PACKED_DRY_RUN ; 
 int /*<<< orphan*/  PRUNE_SHOW_ONLY ; 
 int SEEN ; 
 scalar_t__ TIME_MAX ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  add_pending_object (struct rev_info*,struct object*,char*) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int error (char*,char const*) ; 
 scalar_t__ expire ; 
 scalar_t__ fetch_if_missing ; 
 int /*<<< orphan*/  for_each_loose_file_in_objdir (char*,int (*) (struct object_id const*,char const*,void*),int (*) (char const*,char const*,void*),int (*) (unsigned int,char const*,void*),struct rev_info*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* get_object_directory () ; 
 int /*<<< orphan*/  get_oid (char const*,struct object_id*) ; 
 scalar_t__ is_repository_shallow (int /*<<< orphan*/ ) ; 
 int isatty (int) ; 
 struct object* lookup_object (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ lstat (char const*,struct stat*) ; 
 int /*<<< orphan*/  mark_reachable_objects (struct rev_info*,int,scalar_t__,struct progress*) ; 
 char* mkpath (char*,char const*,char const*) ; 
 char* mkpathdup (char*,char*) ; 
 int oid_object_info (int /*<<< orphan*/ ,struct object_id const*,int /*<<< orphan*/ *) ; 
 char* oid_to_hex (struct object_id const*) ; 
 int /*<<< orphan*/ * opendir (char const*) ; 
 struct object* parse_object_or_die (struct object_id*,char const*) ; 
 int parse_options (int,char const**,char const*,struct option const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char const*,...) ; 
 int /*<<< orphan*/  prune_packed_objects (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prune_shallow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prune_usage ; 
 scalar_t__ read_replace_refs ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 int ref_paranoia ; 
 int /*<<< orphan*/  repo_init_revisions (int /*<<< orphan*/ ,struct rev_info*,char const*) ; 
 scalar_t__ repository_format_precious_objects ; 
 int /*<<< orphan*/  rmdir (char const*) ; 
 scalar_t__ save_commit_buffer ; 
 scalar_t__ show_only ; 
 int show_progress ; 
 struct progress* start_delayed_progress (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ starts_with (char const*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stop_progress (struct progress**) ; 
 int /*<<< orphan*/  the_repository ; 
 char* type_name (int) ; 
 int /*<<< orphan*/  unlink_or_warn (char const*) ; 
 scalar_t__ verbose ; 

__attribute__((used)) static int prune_tmp_file(const char *fullpath)
{
	struct stat st;
	if (lstat(fullpath, &st))
		return error("Could not stat '%s'", fullpath);
	if (st.st_mtime > expire)
		return 0;
	if (show_only || verbose)
		printf("Removing stale temporary file %s\n", fullpath);
	if (!show_only)
		unlink_or_warn(fullpath);
	return 0;
}

__attribute__((used)) static void perform_reachability_traversal(struct rev_info *revs)
{
	static int initialized;
	struct progress *progress = NULL;

	if (initialized)
		return;

	if (show_progress)
		progress = start_delayed_progress(_("Checking connectivity"), 0);
	mark_reachable_objects(revs, 1, expire, progress);
	stop_progress(&progress);
	initialized = 1;
}

__attribute__((used)) static int is_object_reachable(const struct object_id *oid,
			       struct rev_info *revs)
{
	struct object *obj;

	perform_reachability_traversal(revs);

	obj = lookup_object(the_repository, oid->hash);
	return obj && (obj->flags & SEEN);
}

__attribute__((used)) static int prune_object(const struct object_id *oid, const char *fullpath,
			void *data)
{
	struct rev_info *revs = data;
	struct stat st;

	if (is_object_reachable(oid, revs))
		return 0;

	if (lstat(fullpath, &st)) {
		/* report errors, but do not stop pruning */
		error("Could not stat '%s'", fullpath);
		return 0;
	}
	if (st.st_mtime > expire)
		return 0;
	if (show_only || verbose) {
		enum object_type type = oid_object_info(the_repository, oid,
							NULL);
		printf("%s %s\n", oid_to_hex(oid),
		       (type > 0) ? type_name(type) : "unknown");
	}
	if (!show_only)
		unlink_or_warn(fullpath);
	return 0;
}

__attribute__((used)) static int prune_cruft(const char *basename, const char *path, void *data)
{
	if (starts_with(basename, "tmp_obj_"))
		prune_tmp_file(path);
	else
		fprintf(stderr, "bad sha1 file: %s\n", path);
	return 0;
}

__attribute__((used)) static int prune_subdir(unsigned int nr, const char *path, void *data)
{
	if (!show_only)
		rmdir(path);
	return 0;
}

__attribute__((used)) static void remove_temporary_files(const char *path)
{
	DIR *dir;
	struct dirent *de;

	dir = opendir(path);
	if (!dir) {
		fprintf(stderr, "Unable to open directory %s\n", path);
		return;
	}
	while ((de = readdir(dir)) != NULL)
		if (starts_with(de->d_name, "tmp_"))
			prune_tmp_file(mkpath("%s/%s", path, de->d_name));
	closedir(dir);
}

int cmd_prune(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
	int exclude_promisor_objects = 0;
	const struct option options[] = {
		OPT__DRY_RUN(&show_only, N_("do not remove, show only")),
		OPT__VERBOSE(&verbose, N_("report pruned objects")),
		OPT_BOOL(0, "progress", &show_progress, N_("show progress")),
		OPT_EXPIRY_DATE(0, "expire", &expire,
				N_("expire objects older than <time>")),
		OPT_BOOL(0, "exclude-promisor-objects", &exclude_promisor_objects,
			 N_("limit traversal to objects outside promisor packfiles")),
		OPT_END()
	};
	char *s;

	expire = TIME_MAX;
	save_commit_buffer = 0;
	read_replace_refs = 0;
	ref_paranoia = 1;
	repo_init_revisions(the_repository, &revs, prefix);

	argc = parse_options(argc, argv, prefix, options, prune_usage, 0);

	if (repository_format_precious_objects)
		die(_("cannot prune in a precious-objects repo"));

	while (argc--) {
		struct object_id oid;
		const char *name = *argv++;

		if (!get_oid(name, &oid)) {
			struct object *object = parse_object_or_die(&oid,
								    name);
			add_pending_object(&revs, object, "");
		}
		else
			die("unrecognized argument: %s", name);
	}

	if (show_progress == -1)
		show_progress = isatty(2);
	if (exclude_promisor_objects) {
		fetch_if_missing = 0;
		revs.exclude_promisor_objects = 1;
	}

	for_each_loose_file_in_objdir(get_object_directory(), prune_object,
				      prune_cruft, prune_subdir, &revs);

	prune_packed_objects(show_only ? PRUNE_PACKED_DRY_RUN : 0);
	remove_temporary_files(get_object_directory());
	s = mkpathdup("%s/pack", get_object_directory());
	remove_temporary_files(s);
	free(s);

	if (is_repository_shallow(the_repository)) {
		perform_reachability_traversal(&revs);
		prune_shallow(show_only ? PRUNE_SHOW_ONLY : 0);
	}

	return 0;
}

