#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct string_list {int nr; TYPE_2__* items; } ;
struct strbuf {int /*<<< orphan*/  buf; } ;
struct stat {int /*<<< orphan*/  st_mode; } ;
struct pathspec {int nr; TYPE_1__* items; } ;
struct object_id {int dummy; } ;
struct lock_file {int dummy; } ;
struct cache_entry {scalar_t__ ce_mode; int /*<<< orphan*/  name; int /*<<< orphan*/  oid; } ;
struct TYPE_8__ {char* name; scalar_t__ is_submodule; } ;
struct TYPE_7__ {int nr; TYPE_4__* entry; int /*<<< orphan*/  alloc; } ;
struct TYPE_6__ {int /*<<< orphan*/  string; } ;
struct TYPE_5__ {char* original; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABSORB_GITDIR_RECURSE_SUBMODULES ; 
 int /*<<< orphan*/  ALLOC_GROW (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int COMMIT_LOCK ; 
 int /*<<< orphan*/  LOCK_DIE_ON_ERROR ; 
 struct lock_file LOCK_INIT ; 
 char MATCHED_RECURSIVELY ; 
 int /*<<< orphan*/  PATHSPEC_PREFER_CWD ; 
 char* Q_ (char*,char*,int) ; 
 int /*<<< orphan*/  REFRESH_QUIET ; 
 int SKIP_IF_UNCHANGED ; 
 struct strbuf STRBUF_INIT ; 
 struct string_list STRING_LIST_INIT_NODUP ; 
 int SUBMODULE_REMOVAL_DIE_ON_ERROR ; 
 int SUBMODULE_REMOVAL_IGNORE_IGNORED_UNTRACKED ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 scalar_t__ S_ISGITLINK (scalar_t__) ; 
 char* _ (char*) ; 
 int /*<<< orphan*/  absorb_git_dir_into_superproject (char const*,char const*,int /*<<< orphan*/ ) ; 
 struct cache_entry** active_cache ; 
 int active_nr ; 
 scalar_t__ advice_rm_hints ; 
 scalar_t__ bad_to_remove_submodule (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  builtin_rm_options ; 
 int /*<<< orphan*/  builtin_rm_usage ; 
 int cache_name_pos (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ce_intent_to_add (struct cache_entry const*) ; 
 scalar_t__ ce_match_stat (struct cache_entry const*,struct stat*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ce_path_match (int /*<<< orphan*/ *,struct cache_entry const*,struct pathspec*,char*) ; 
 int ce_stage (struct cache_entry*) ; 
 scalar_t__ create_ce_mode (unsigned int) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int /*<<< orphan*/  die_errno (char*,char const*) ; 
 int /*<<< orphan*/  errno ; 
 int error (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  file_exists (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  force ; 
 scalar_t__ get_oid (char*,struct object_id*) ; 
 scalar_t__ get_tree_entry (struct object_id*,char const*,struct object_id*,unsigned int*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_default_config ; 
 int /*<<< orphan*/  hold_locked_index (struct lock_file*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ignore_unmatch ; 
 int index_only ; 
 scalar_t__ is_empty_dir (char const*) ; 
 int /*<<< orphan*/  is_missing_file_error (int /*<<< orphan*/ ) ; 
 int is_null_oid (struct object_id*) ; 
 int /*<<< orphan*/  is_staging_gitmodules_ok (int /*<<< orphan*/ *) ; 
 TYPE_3__ list ; 
 scalar_t__ lstat (int /*<<< orphan*/ ,struct stat*) ; 
 int /*<<< orphan*/  oidclr (struct object_id*) ; 
 int /*<<< orphan*/  oideq (int /*<<< orphan*/ *,struct object_id*) ; 
 int parse_options (int,char const**,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  parse_pathspec (struct pathspec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,char const**) ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 
 int /*<<< orphan*/  quiet ; 
 scalar_t__ read_cache () ; 
 int /*<<< orphan*/  recursive ; 
 int /*<<< orphan*/  refresh_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct pathspec*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ remove_dir_recursively (struct strbuf*,int /*<<< orphan*/ ) ; 
 scalar_t__ remove_file_from_cache (char const*) ; 
 int /*<<< orphan*/  remove_path (char const*) ; 
 int /*<<< orphan*/  remove_path_from_gitmodules (char const*) ; 
 int /*<<< orphan*/  setup_work_tree () ; 
 scalar_t__ show_only ; 
 int /*<<< orphan*/  stage_updated_gitmodules (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strbuf_addf (struct strbuf*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strbuf_addstr (struct strbuf*,char const*) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_reset (struct strbuf*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  string_list_append (struct string_list*,char const*) ; 
 int /*<<< orphan*/  string_list_clear (struct string_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  submodule_uses_gitfile (char const*) ; 
 int /*<<< orphan*/  the_index ; 
 int /*<<< orphan*/  usage_with_options (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warning_errno (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ write_locked_index (int /*<<< orphan*/ *,struct lock_file*,int) ; 
 char* xcalloc (int,int) ; 
 char* xstrdup (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int get_ours_cache_pos(const char *path, int pos)
{
	int i = -pos - 1;

	while ((i < active_nr) && !strcmp(active_cache[i]->name, path)) {
		if (ce_stage(active_cache[i]) == 2)
			return i;
		i++;
	}
	return -1;
}

__attribute__((used)) static void print_error_files(struct string_list *files_list,
			      const char *main_msg,
			      const char *hints_msg,
			      int *errs)
{
	if (files_list->nr) {
		int i;
		struct strbuf err_msg = STRBUF_INIT;

		strbuf_addstr(&err_msg, main_msg);
		for (i = 0; i < files_list->nr; i++)
			strbuf_addf(&err_msg,
				    "\n    %s",
				    files_list->items[i].string);
		if (advice_rm_hints)
			strbuf_addstr(&err_msg, hints_msg);
		*errs = error("%s", err_msg.buf);
		strbuf_release(&err_msg);
	}
}

__attribute__((used)) static void submodules_absorb_gitdir_if_needed(const char *prefix)
{
	int i;
	for (i = 0; i < list.nr; i++) {
		const char *name = list.entry[i].name;
		int pos;
		const struct cache_entry *ce;

		pos = cache_name_pos(name, strlen(name));
		if (pos < 0) {
			pos = get_ours_cache_pos(name, pos);
			if (pos < 0)
				continue;
		}
		ce = active_cache[pos];

		if (!S_ISGITLINK(ce->ce_mode) ||
		    !file_exists(ce->name) ||
		    is_empty_dir(name))
			continue;

		if (!submodule_uses_gitfile(name))
			absorb_git_dir_into_superproject(prefix, name,
				ABSORB_GITDIR_RECURSE_SUBMODULES);
	}
}

__attribute__((used)) static int check_local_mod(struct object_id *head, int index_only)
{
	/*
	 * Items in list are already sorted in the cache order,
	 * so we could do this a lot more efficiently by using
	 * tree_desc based traversal if we wanted to, but I am
	 * lazy, and who cares if removal of files is a tad
	 * slower than the theoretical maximum speed?
	 */
	int i, no_head;
	int errs = 0;
	struct string_list files_staged = STRING_LIST_INIT_NODUP;
	struct string_list files_cached = STRING_LIST_INIT_NODUP;
	struct string_list files_local = STRING_LIST_INIT_NODUP;

	no_head = is_null_oid(head);
	for (i = 0; i < list.nr; i++) {
		struct stat st;
		int pos;
		const struct cache_entry *ce;
		const char *name = list.entry[i].name;
		struct object_id oid;
		unsigned mode;
		int local_changes = 0;
		int staged_changes = 0;

		pos = cache_name_pos(name, strlen(name));
		if (pos < 0) {
			/*
			 * Skip unmerged entries except for populated submodules
			 * that could lose history when removed.
			 */
			pos = get_ours_cache_pos(name, pos);
			if (pos < 0)
				continue;

			if (!S_ISGITLINK(active_cache[pos]->ce_mode) ||
			    is_empty_dir(name))
				continue;
		}
		ce = active_cache[pos];

		if (lstat(ce->name, &st) < 0) {
			if (!is_missing_file_error(errno))
				warning_errno(_("failed to stat '%s'"), ce->name);
			/* It already vanished from the working tree */
			continue;
		}
		else if (S_ISDIR(st.st_mode)) {
			/* if a file was removed and it is now a
			 * directory, that is the same as ENOENT as
			 * far as git is concerned; we do not track
			 * directories unless they are submodules.
			 */
			if (!S_ISGITLINK(ce->ce_mode))
				continue;
		}

		/*
		 * "rm" of a path that has changes need to be treated
		 * carefully not to allow losing local changes
		 * accidentally.  A local change could be (1) file in
		 * work tree is different since the index; and/or (2)
		 * the user staged a content that is different from
		 * the current commit in the index.
		 *
		 * In such a case, you would need to --force the
		 * removal.  However, "rm --cached" (remove only from
		 * the index) is safe if the index matches the file in
		 * the work tree or the HEAD commit, as it means that
		 * the content being removed is available elsewhere.
		 */

		/*
		 * Is the index different from the file in the work tree?
		 * If it's a submodule, is its work tree modified?
		 */
		if (ce_match_stat(ce, &st, 0) ||
		    (S_ISGITLINK(ce->ce_mode) &&
		     bad_to_remove_submodule(ce->name,
				SUBMODULE_REMOVAL_DIE_ON_ERROR |
				SUBMODULE_REMOVAL_IGNORE_IGNORED_UNTRACKED)))
			local_changes = 1;

		/*
		 * Is the index different from the HEAD commit?  By
		 * definition, before the very initial commit,
		 * anything staged in the index is treated by the same
		 * way as changed from the HEAD.
		 */
		if (no_head
		     || get_tree_entry(head, name, &oid, &mode)
		     || ce->ce_mode != create_ce_mode(mode)
		     || !oideq(&ce->oid, &oid))
			staged_changes = 1;

		/*
		 * If the index does not match the file in the work
		 * tree and if it does not match the HEAD commit
		 * either, (1) "git rm" without --cached definitely
		 * will lose information; (2) "git rm --cached" will
		 * lose information unless it is about removing an
		 * "intent to add" entry.
		 */
		if (local_changes && staged_changes) {
			if (!index_only || !ce_intent_to_add(ce))
				string_list_append(&files_staged, name);
		}
		else if (!index_only) {
			if (staged_changes)
				string_list_append(&files_cached, name);
			if (local_changes)
				string_list_append(&files_local, name);
		}
	}
	print_error_files(&files_staged,
			  Q_("the following file has staged content different "
			     "from both the\nfile and the HEAD:",
			     "the following files have staged content different"
			     " from both the\nfile and the HEAD:",
			     files_staged.nr),
			  _("\n(use -f to force removal)"),
			  &errs);
	string_list_clear(&files_staged, 0);
	print_error_files(&files_cached,
			  Q_("the following file has changes "
			     "staged in the index:",
			     "the following files have changes "
			     "staged in the index:", files_cached.nr),
			  _("\n(use --cached to keep the file,"
			    " or -f to force removal)"),
			  &errs);
	string_list_clear(&files_cached, 0);

	print_error_files(&files_local,
			  Q_("the following file has local modifications:",
			     "the following files have local modifications:",
			     files_local.nr),
			  _("\n(use --cached to keep the file,"
			    " or -f to force removal)"),
			  &errs);
	string_list_clear(&files_local, 0);

	return errs;
}

int cmd_rm(int argc, const char **argv, const char *prefix)
{
	struct lock_file lock_file = LOCK_INIT;
	int i;
	struct pathspec pathspec;
	char *seen;

	git_config(git_default_config, NULL);

	argc = parse_options(argc, argv, prefix, builtin_rm_options,
			     builtin_rm_usage, 0);
	if (!argc)
		usage_with_options(builtin_rm_usage, builtin_rm_options);

	if (!index_only)
		setup_work_tree();

	hold_locked_index(&lock_file, LOCK_DIE_ON_ERROR);

	if (read_cache() < 0)
		die(_("index file corrupt"));

	parse_pathspec(&pathspec, 0,
		       PATHSPEC_PREFER_CWD,
		       prefix, argv);
	refresh_index(&the_index, REFRESH_QUIET, &pathspec, NULL, NULL);

	seen = xcalloc(pathspec.nr, 1);

	for (i = 0; i < active_nr; i++) {
		const struct cache_entry *ce = active_cache[i];
		if (!ce_path_match(&the_index, ce, &pathspec, seen))
			continue;
		ALLOC_GROW(list.entry, list.nr + 1, list.alloc);
		list.entry[list.nr].name = xstrdup(ce->name);
		list.entry[list.nr].is_submodule = S_ISGITLINK(ce->ce_mode);
		if (list.entry[list.nr++].is_submodule &&
		    !is_staging_gitmodules_ok(&the_index))
			die(_("please stage your changes to .gitmodules or stash them to proceed"));
	}

	if (pathspec.nr) {
		const char *original;
		int seen_any = 0;
		for (i = 0; i < pathspec.nr; i++) {
			original = pathspec.items[i].original;
			if (!seen[i]) {
				if (!ignore_unmatch) {
					die(_("pathspec '%s' did not match any files"),
					    original);
				}
			}
			else {
				seen_any = 1;
			}
			if (!recursive && seen[i] == MATCHED_RECURSIVELY)
				die(_("not removing '%s' recursively without -r"),
				    *original ? original : ".");
		}

		if (!seen_any)
			exit(0);
	}

	if (!index_only)
		submodules_absorb_gitdir_if_needed(prefix);

	/*
	 * If not forced, the file, the index and the HEAD (if exists)
	 * must match; but the file can already been removed, since
	 * this sequence is a natural "novice" way:
	 *
	 *	rm F; git rm F
	 *
	 * Further, if HEAD commit exists, "diff-index --cached" must
	 * report no changes unless forced.
	 */
	if (!force) {
		struct object_id oid;
		if (get_oid("HEAD", &oid))
			oidclr(&oid);
		if (check_local_mod(&oid, index_only))
			exit(1);
	}

	/*
	 * First remove the names from the index: we won't commit
	 * the index unless all of them succeed.
	 */
	for (i = 0; i < list.nr; i++) {
		const char *path = list.entry[i].name;
		if (!quiet)
			printf("rm '%s'\n", path);

		if (remove_file_from_cache(path))
			die(_("git rm: unable to remove %s"), path);
	}

	if (show_only)
		return 0;

	/*
	 * Then, unless we used "--cached", remove the filenames from
	 * the workspace. If we fail to remove the first one, we
	 * abort the "git rm" (but once we've successfully removed
	 * any file at all, we'll go ahead and commit to it all:
	 * by then we've already committed ourselves and can't fail
	 * in the middle)
	 */
	if (!index_only) {
		int removed = 0, gitmodules_modified = 0;
		struct strbuf buf = STRBUF_INIT;
		for (i = 0; i < list.nr; i++) {
			const char *path = list.entry[i].name;
			if (list.entry[i].is_submodule) {
				strbuf_reset(&buf);
				strbuf_addstr(&buf, path);
				if (remove_dir_recursively(&buf, 0))
					die(_("could not remove '%s'"), path);

				removed = 1;
				if (!remove_path_from_gitmodules(path))
					gitmodules_modified = 1;
				continue;
			}
			if (!remove_path(path)) {
				removed = 1;
				continue;
			}
			if (!removed)
				die_errno("git rm: '%s'", path);
		}
		strbuf_release(&buf);
		if (gitmodules_modified)
			stage_updated_gitmodules(&the_index);
	}

	if (write_locked_index(&the_index, &lock_file,
			       COMMIT_LOCK | SKIP_IF_UNCHANGED))
		die(_("Unable to write new index file"));

	return 0;
}

