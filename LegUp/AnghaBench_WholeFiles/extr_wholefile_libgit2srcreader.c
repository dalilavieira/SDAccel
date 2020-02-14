#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_7__ ;
typedef  struct TYPE_34__   TYPE_6__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct TYPE_32__ {int (* read ) (TYPE_7__*,int /*<<< orphan*/ *,scalar_t__*,TYPE_2__*,char const*) ;} ;
struct TYPE_33__ {int (* read ) (TYPE_7__*,int /*<<< orphan*/ *,scalar_t__*,TYPE_2__*,char const*) ;int /*<<< orphan*/ * index; int /*<<< orphan*/ * repo; TYPE_1__ reader; int /*<<< orphan*/ * tree; } ;
typedef  TYPE_2__ workdir_reader ;
typedef  TYPE_2__ tree_reader ;
struct stat {int /*<<< orphan*/  st_mode; } ;
typedef  TYPE_2__ index_reader ;
typedef  int /*<<< orphan*/  git_tree_entry ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  TYPE_2__ git_reader ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  scalar_t__ git_off_t ;
struct TYPE_34__ {scalar_t__ mode; int /*<<< orphan*/  id; } ;
typedef  TYPE_6__ git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;
typedef  int /*<<< orphan*/  git_filter_list ;
typedef  scalar_t__ git_filemode_t ;
struct TYPE_35__ {int /*<<< orphan*/  size; int /*<<< orphan*/  ptr; } ;
typedef  TYPE_7__ git_buf ;
typedef  int /*<<< orphan*/  git_blob ;

/* Variables and functions */
 scalar_t__ ENOENT ; 
 TYPE_7__ GIT_BUF_INIT ; 
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_ERROR_CHECK_ALLOC (TYPE_2__*) ; 
 int /*<<< orphan*/  GIT_ERROR_CHECK_BLOBSIZE (scalar_t__) ; 
 int /*<<< orphan*/  GIT_ERROR_OS ; 
 int /*<<< orphan*/  GIT_FILTER_DEFAULT ; 
 int /*<<< orphan*/  GIT_FILTER_TO_ODB ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int GIT_READER_MISMATCH ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ errno ; 
 TYPE_2__* git__calloc (int,int) ; 
 int /*<<< orphan*/  git__free (TYPE_2__*) ; 
 int git_blob__getbuf (TYPE_7__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_free (int /*<<< orphan*/ *) ; 
 int git_blob_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_rawcontent (int /*<<< orphan*/ *) ; 
 scalar_t__ git_blob_rawsize (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_7__*) ; 
 int git_buf_joinpath (TYPE_7__*,int /*<<< orphan*/ ,char const*) ; 
 int git_buf_set (TYPE_7__*,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int git_filter_list_apply_to_file (TYPE_7__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_filter_list_free (int /*<<< orphan*/ *) ; 
 int git_filter_list_load (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ git_futils_canonical_mode (int /*<<< orphan*/ ) ; 
 TYPE_6__* git_index_get_bypath (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int git_odb_hash (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_equal (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_repository_index__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_workdir (int /*<<< orphan*/ *) ; 
 int git_tree_entry_bypath (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ git_tree_entry_filemode (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_entry_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_tree_entry_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_tree_owner (int /*<<< orphan*/ *) ; 
 int p_lstat (int /*<<< orphan*/ ,struct stat*) ; 
 int stub1 (TYPE_7__*,int /*<<< orphan*/ *,scalar_t__*,TYPE_2__*,char const*) ; 

__attribute__((used)) static int tree_reader_read(
	git_buf *out,
	git_oid *out_id,
	git_filemode_t *out_filemode,
	git_reader *_reader,
	const char *filename)
{
	tree_reader *reader = (tree_reader *)_reader;
	git_tree_entry *tree_entry = NULL;
	git_blob *blob = NULL;
	git_off_t blobsize;
	int error;

	if ((error = git_tree_entry_bypath(&tree_entry, reader->tree, filename)) < 0 ||
	    (error = git_blob_lookup(&blob, git_tree_owner(reader->tree), git_tree_entry_id(tree_entry))) < 0)
		goto done;

	blobsize = git_blob_rawsize(blob);
	GIT_ERROR_CHECK_BLOBSIZE(blobsize);

	if ((error = git_buf_set(out, git_blob_rawcontent(blob), (size_t)blobsize)) < 0)
		goto done;

	if (out_id)
		git_oid_cpy(out_id, git_tree_entry_id(tree_entry));

	if (out_filemode)
		*out_filemode = git_tree_entry_filemode(tree_entry);

done:
	git_blob_free(blob);
	git_tree_entry_free(tree_entry);
	return error;
}

int git_reader_for_tree(git_reader **out, git_tree *tree)
{
	tree_reader *reader;

	assert(out && tree);

	reader = git__calloc(1, sizeof(tree_reader));
	GIT_ERROR_CHECK_ALLOC(reader);

	reader->reader.read = tree_reader_read;
	reader->tree = tree;

	*out = (git_reader *)reader;
	return 0;
}

__attribute__((used)) static int workdir_reader_read(
	git_buf *out,
	git_oid *out_id,
	git_filemode_t *out_filemode,
	git_reader *_reader,
	const char *filename)
{
	workdir_reader *reader = (workdir_reader *)_reader;
	git_buf path = GIT_BUF_INIT;
	struct stat st;
	git_filemode_t filemode;
	git_filter_list *filters = NULL;
	const git_index_entry *idx_entry;
	git_oid id;
	int error;

	if ((error = git_buf_joinpath(&path,
		git_repository_workdir(reader->repo), filename)) < 0)
		goto done;

	if ((error = p_lstat(path.ptr, &st)) < 0) {
		if (error == -1 && errno == ENOENT)
			error = GIT_ENOTFOUND;

		git_error_set(GIT_ERROR_OS, "could not stat '%s'", path.ptr);
		goto done;
	}

	filemode = git_futils_canonical_mode(st.st_mode);

	/*
	 * Patch application - for example - uses the filtered version of
	 * the working directory data to match git.  So we will run the
	 * workdir -> ODB filter on the contents in this workdir reader.
	 */
	if ((error = git_filter_list_load(&filters, reader->repo, NULL, filename,
		GIT_FILTER_TO_ODB, GIT_FILTER_DEFAULT)) < 0)
		goto done;

	if ((error = git_filter_list_apply_to_file(out,
	    filters, reader->repo, path.ptr)) < 0)
		goto done;

	if (out_id || reader->index) {
		if ((error = git_odb_hash(&id, out->ptr, out->size, GIT_OBJECT_BLOB)) < 0)
			goto done;
	}

	if (reader->index) {
		if (!(idx_entry = git_index_get_bypath(reader->index, filename, 0)) ||
		    filemode != idx_entry->mode ||
		    !git_oid_equal(&id, &idx_entry->id)) {
			error = GIT_READER_MISMATCH;
			goto done;
		}
	}

	if (out_id)
		git_oid_cpy(out_id, &id);

	if (out_filemode)
		*out_filemode = filemode;

done:
	git_filter_list_free(filters);
	git_buf_dispose(&path);
	return error;
}

int git_reader_for_workdir(
	git_reader **out,
	git_repository *repo,
	bool validate_index)
{
	workdir_reader *reader;
	int error;

	assert(out && repo);

	reader = git__calloc(1, sizeof(workdir_reader));
	GIT_ERROR_CHECK_ALLOC(reader);

	reader->reader.read = workdir_reader_read;
	reader->repo = repo;

	if (validate_index &&
	    (error = git_repository_index__weakptr(&reader->index, repo)) < 0) {
		git__free(reader);
		return error;
	}

	*out = (git_reader *)reader;
	return 0;
}

__attribute__((used)) static int index_reader_read(
	git_buf *out,
	git_oid *out_id,
	git_filemode_t *out_filemode,
	git_reader *_reader,
	const char *filename)
{
	index_reader *reader = (index_reader *)_reader;
	const git_index_entry *entry;
	git_blob *blob;
	int error;

	if ((entry = git_index_get_bypath(reader->index, filename, 0)) == NULL)
		return GIT_ENOTFOUND;

	if ((error = git_blob_lookup(&blob, reader->repo, &entry->id)) < 0)
		goto done;

	if (out_id)
		git_oid_cpy(out_id, &entry->id);

	if (out_filemode)
		*out_filemode = entry->mode;

	error = git_blob__getbuf(out, blob);

done:
	git_blob_free(blob);
	return error;
}

int git_reader_for_index(
	git_reader **out,
	git_repository *repo,
	git_index *index)
{
	index_reader *reader;
	int error;

	assert(out && repo);

	reader = git__calloc(1, sizeof(index_reader));
	GIT_ERROR_CHECK_ALLOC(reader);

	reader->reader.read = index_reader_read;
	reader->repo = repo;

	if (index) {
		reader->index = index;
	} else if ((error = git_repository_index__weakptr(&reader->index, repo)) < 0) {
		git__free(reader);
		return error;
	}

	*out = (git_reader *)reader;
	return 0;
}

int git_reader_read(
	git_buf *out,
	git_oid *out_id,
	git_filemode_t *out_filemode,
	git_reader *reader,
	const char *filename)
{
	assert(out && reader && filename);

	return reader->read(out, out_id, out_filemode, reader, filename);
}

void git_reader_free(git_reader *reader)
{
	if (!reader)
		return;

	git__free(reader);
}

