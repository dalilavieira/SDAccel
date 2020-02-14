#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char* attributes; int (* check ) (int /*<<< orphan*/ *,void**,int /*<<< orphan*/  const*,char const**) ;int (* apply ) (int /*<<< orphan*/ *,void**,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;void (* cleanup ) (int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  shutdown; int /*<<< orphan*/ * initialize; int /*<<< orphan*/  version; } ;
struct crlf_filter {TYPE_1__ f; } ;
struct crlf_attrs {scalar_t__ auto_crlf; scalar_t__ core_eol; int crlf_action; scalar_t__ safe_crlf; int attr_action; } ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  size_t git_off_t ;
struct TYPE_8__ {int /*<<< orphan*/  id; int /*<<< orphan*/  mode; } ;
typedef  TYPE_2__ git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;
typedef  int /*<<< orphan*/  git_filter_source ;
typedef  int /*<<< orphan*/  git_filter ;
typedef  scalar_t__ git_cvar_value ;
typedef  int git_crlf_t ;
struct TYPE_9__ {scalar_t__ crlf; scalar_t__ lf; scalar_t__ cr; } ;
typedef  TYPE_3__ git_buf_text_stats ;
typedef  int /*<<< orphan*/  git_buf ;
typedef  int /*<<< orphan*/  git_blob ;
typedef  int /*<<< orphan*/  ca ;

/* Variables and functions */
 scalar_t__ GIT_ATTR_FALSE (char const*) ; 
 scalar_t__ GIT_ATTR_TRUE (char const*) ; 
 scalar_t__ GIT_ATTR_UNSPECIFIED (char const*) ; 
 scalar_t__ GIT_AUTO_CRLF_FALSE ; 
 scalar_t__ GIT_AUTO_CRLF_INPUT ; 
 scalar_t__ GIT_AUTO_CRLF_TRUE ; 
#define  GIT_CRLF_AUTO 135 
#define  GIT_CRLF_AUTO_CRLF 134 
#define  GIT_CRLF_AUTO_INPUT 133 
#define  GIT_CRLF_BINARY 132 
#define  GIT_CRLF_TEXT 131 
#define  GIT_CRLF_TEXT_CRLF 130 
#define  GIT_CRLF_TEXT_INPUT 129 
#define  GIT_CRLF_UNDEFINED 128 
 int /*<<< orphan*/  GIT_CVAR_AUTO_CRLF ; 
 int /*<<< orphan*/  GIT_CVAR_EOL ; 
 int /*<<< orphan*/  GIT_CVAR_SAFE_CRLF ; 
 scalar_t__ GIT_EOL_CRLF ; 
 scalar_t__ GIT_EOL_LF ; 
 scalar_t__ GIT_EOL_NATIVE ; 
 scalar_t__ GIT_EOL_UNSET ; 
 int /*<<< orphan*/  GIT_ERROR_CHECK_ALLOC (void*) ; 
 int GIT_FILTER_ALLOW_UNSAFE ; 
 scalar_t__ GIT_FILTER_SMUDGE ; 
 int /*<<< orphan*/  GIT_FILTER_VERSION ; 
 int GIT_PASSTHROUGH ; 
 scalar_t__ GIT_SAFE_CRLF_FAIL ; 
 scalar_t__ GIT_SAFE_CRLF_WARN ; 
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 int check_safecrlf (struct crlf_attrs*,int /*<<< orphan*/  const*,TYPE_3__*) ; 
 struct crlf_filter* git__calloc (int,int) ; 
 int /*<<< orphan*/  git__free (void*) ; 
 int /*<<< orphan*/  git__is_sizet (size_t) ; 
 void* git__malloc (int) ; 
 int /*<<< orphan*/  git_blob_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_blob_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* git_blob_rawcontent (int /*<<< orphan*/ *) ; 
 size_t git_blob_rawsize (int /*<<< orphan*/ *) ; 
 scalar_t__ git_buf_len (int /*<<< orphan*/  const*) ; 
 int git_buf_text_crlf_to_lf (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int git_buf_text_gather_stats (TYPE_3__*,int /*<<< orphan*/  const*,int) ; 
 int git_buf_text_lf_to_crlf (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_error_clear () ; 
 int /*<<< orphan*/  git_filter_free ; 
 int git_filter_source_flags (int /*<<< orphan*/  const*) ; 
 scalar_t__ git_filter_source_mode (int /*<<< orphan*/  const*) ; 
 char* git_filter_source_path (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * git_filter_source_repo (int /*<<< orphan*/  const*) ; 
 TYPE_2__* git_index_get_bypath (int /*<<< orphan*/ *,char const*,int) ; 
 int git_repository__cvar (scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ git_repository_index__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * memchr (void const*,char,size_t) ; 
 int /*<<< orphan*/  memcpy (void*,struct crlf_attrs*,int) ; 
 int /*<<< orphan*/  memset (struct crlf_attrs*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static git_crlf_t check_crlf(const char *value)
{
	if (GIT_ATTR_TRUE(value))
		return GIT_CRLF_TEXT;
	else if (GIT_ATTR_FALSE(value))
		return GIT_CRLF_BINARY;
	else if (GIT_ATTR_UNSPECIFIED(value))
		;
	else if (strcmp(value, "input") == 0)
		return GIT_CRLF_TEXT_INPUT;
	else if (strcmp(value, "auto") == 0)
		return GIT_CRLF_AUTO;

	return GIT_CRLF_UNDEFINED;
}

__attribute__((used)) static git_cvar_value check_eol(const char *value)
{
	if (GIT_ATTR_UNSPECIFIED(value))
		;
	else if (strcmp(value, "lf") == 0)
		return GIT_EOL_LF;
	else if (strcmp(value, "crlf") == 0)
		return GIT_EOL_CRLF;

	return GIT_EOL_UNSET;
}

__attribute__((used)) static int has_cr_in_index(const git_filter_source *src)
{
	git_repository *repo = git_filter_source_repo(src);
	const char *path = git_filter_source_path(src);
	git_index *index;
	const git_index_entry *entry;
	git_blob *blob;
	const void *blobcontent;
	git_off_t blobsize;
	bool found_cr;

	if (!path)
		return false;

	if (git_repository_index__weakptr(&index, repo) < 0) {
		git_error_clear();
		return false;
	}

	if (!(entry = git_index_get_bypath(index, path, 0)) &&
		!(entry = git_index_get_bypath(index, path, 1)))
		return false;

	if (!S_ISREG(entry->mode)) /* don't crlf filter non-blobs */
		return true;

	if (git_blob_lookup(&blob, repo, &entry->id) < 0)
		return false;

	blobcontent = git_blob_rawcontent(blob);
	blobsize    = git_blob_rawsize(blob);
	if (!git__is_sizet(blobsize))
		blobsize = (size_t)-1;

	found_cr = (blobcontent != NULL &&
		blobsize > 0 &&
		memchr(blobcontent, '\r', (size_t)blobsize) != NULL);

	git_blob_free(blob);
	return found_cr;
}

__attribute__((used)) static int text_eol_is_crlf(struct crlf_attrs *ca)
{
	if (ca->auto_crlf == GIT_AUTO_CRLF_TRUE)
		return 1;
	else if (ca->auto_crlf == GIT_AUTO_CRLF_INPUT)
		return 0;

	if (ca->core_eol == GIT_EOL_CRLF)
		return 1;
	if (ca->core_eol == GIT_EOL_UNSET && GIT_EOL_NATIVE == GIT_EOL_CRLF)
		return 1;

	return 0;
}

__attribute__((used)) static git_cvar_value output_eol(struct crlf_attrs *ca)
{
	switch (ca->crlf_action) {
	case GIT_CRLF_BINARY:
		return GIT_EOL_UNSET;
	case GIT_CRLF_TEXT_CRLF:
		return GIT_EOL_CRLF;
	case GIT_CRLF_TEXT_INPUT:
		return GIT_EOL_LF;
	case GIT_CRLF_UNDEFINED:
	case GIT_CRLF_AUTO_CRLF:
		return GIT_EOL_CRLF;
	case GIT_CRLF_AUTO_INPUT:
		return GIT_EOL_LF;
	case GIT_CRLF_TEXT:
	case GIT_CRLF_AUTO:
		return text_eol_is_crlf(ca) ? GIT_EOL_CRLF : GIT_EOL_LF;
	}

	/* TODO: warn when available */
	return ca->core_eol;
}

__attribute__((used)) static int crlf_apply_to_odb(
	struct crlf_attrs *ca,
	git_buf *to,
	const git_buf *from,
	const git_filter_source *src)
{
	git_buf_text_stats stats;
	bool is_binary;
	int error;

	/* Binary attribute? Empty file? Nothing to do */
	if (ca->crlf_action == GIT_CRLF_BINARY || !git_buf_len(from))
		return GIT_PASSTHROUGH;

	is_binary = git_buf_text_gather_stats(&stats, from, false);

	/* Heuristics to see if we can skip the conversion.
	 * Straight from Core Git.
	 */
	if (ca->crlf_action == GIT_CRLF_AUTO ||
		ca->crlf_action == GIT_CRLF_AUTO_INPUT ||
		ca->crlf_action == GIT_CRLF_AUTO_CRLF) {

		if (is_binary)
			return GIT_PASSTHROUGH;

		/*
		 * If the file in the index has any CR in it, do not convert.
		 * This is the new safer autocrlf handling.
		 */
		if (has_cr_in_index(src))
			return GIT_PASSTHROUGH;
	}

	if ((error = check_safecrlf(ca, src, &stats)) < 0)
		return error;

	/* If there are no CR characters to filter out, then just pass */
	if (!stats.crlf)
		return GIT_PASSTHROUGH;

	/* Actually drop the carriage returns */
	return git_buf_text_crlf_to_lf(to, from);
}

__attribute__((used)) static int crlf_apply_to_workdir(
	struct crlf_attrs *ca,
	git_buf *to,
	const git_buf *from)
{
	git_buf_text_stats stats;
	bool is_binary;

	/* Empty file? Nothing to do. */
	if (git_buf_len(from) == 0 || output_eol(ca) != GIT_EOL_CRLF)
		return GIT_PASSTHROUGH;

	is_binary = git_buf_text_gather_stats(&stats, from, false);

	/* If there are no LFs, or all LFs are part of a CRLF, nothing to do */
	if (stats.lf == 0 || stats.lf == stats.crlf)
		return GIT_PASSTHROUGH;

	if (ca->crlf_action == GIT_CRLF_AUTO ||
		ca->crlf_action == GIT_CRLF_AUTO_INPUT ||
		ca->crlf_action == GIT_CRLF_AUTO_CRLF) {

		/* If we have any existing CR or CRLF line endings, do nothing */
		if (stats.cr > 0)
			return GIT_PASSTHROUGH;

		/* Don't filter binary files */
		if (is_binary)
			return GIT_PASSTHROUGH;
	}

	return git_buf_text_lf_to_crlf(to, from);
}

__attribute__((used)) static int convert_attrs(
	struct crlf_attrs *ca,
	const char **attr_values,
	const git_filter_source *src)
{
	int error;

	memset(ca, 0, sizeof(struct crlf_attrs));

	if ((error = git_repository__cvar(&ca->auto_crlf,
		 git_filter_source_repo(src), GIT_CVAR_AUTO_CRLF)) < 0 ||
		(error = git_repository__cvar(&ca->safe_crlf,
		 git_filter_source_repo(src), GIT_CVAR_SAFE_CRLF)) < 0 ||
		(error = git_repository__cvar(&ca->core_eol,
		 git_filter_source_repo(src), GIT_CVAR_EOL)) < 0)
		return error;

	/* downgrade FAIL to WARN if ALLOW_UNSAFE option is used */
	if ((git_filter_source_flags(src) & GIT_FILTER_ALLOW_UNSAFE) &&
		ca->safe_crlf == GIT_SAFE_CRLF_FAIL)
		ca->safe_crlf = GIT_SAFE_CRLF_WARN;

	if (attr_values) {
		/* load the text attribute */
		ca->crlf_action = check_crlf(attr_values[2]); /* text */

		if (ca->crlf_action == GIT_CRLF_UNDEFINED)
			ca->crlf_action = check_crlf(attr_values[0]); /* crlf */

		if (ca->crlf_action != GIT_CRLF_BINARY) {
			/* load the eol attribute */
			int eol_attr = check_eol(attr_values[1]);

			if (ca->crlf_action == GIT_CRLF_AUTO && eol_attr == GIT_EOL_LF)
				ca->crlf_action = GIT_CRLF_AUTO_INPUT;
			else if (ca->crlf_action == GIT_CRLF_AUTO && eol_attr == GIT_EOL_CRLF)
				ca->crlf_action = GIT_CRLF_AUTO_CRLF;
			else if (eol_attr == GIT_EOL_LF)
				ca->crlf_action = GIT_CRLF_TEXT_INPUT;
			else if (eol_attr == GIT_EOL_CRLF)
				ca->crlf_action = GIT_CRLF_TEXT_CRLF;
		}

		ca->attr_action = ca->crlf_action;
	} else {
		ca->crlf_action = GIT_CRLF_UNDEFINED;
	}

	if (ca->crlf_action == GIT_CRLF_TEXT)
		ca->crlf_action = text_eol_is_crlf(ca) ? GIT_CRLF_TEXT_CRLF : GIT_CRLF_TEXT_INPUT;
	if (ca->crlf_action == GIT_CRLF_UNDEFINED && ca->auto_crlf == GIT_AUTO_CRLF_FALSE)
		ca->crlf_action = GIT_CRLF_BINARY;
	if (ca->crlf_action == GIT_CRLF_UNDEFINED && ca->auto_crlf == GIT_AUTO_CRLF_TRUE)
		ca->crlf_action = GIT_CRLF_AUTO_CRLF;
	if (ca->crlf_action == GIT_CRLF_UNDEFINED && ca->auto_crlf == GIT_AUTO_CRLF_INPUT)
		ca->crlf_action = GIT_CRLF_AUTO_INPUT;

	return 0;
}

__attribute__((used)) static int crlf_check(
	git_filter *self,
	void **payload, /* points to NULL ptr on entry, may be set */
	const git_filter_source *src,
	const char **attr_values)
{
	struct crlf_attrs ca;

	GIT_UNUSED(self);

	convert_attrs(&ca, attr_values, src);

	if (ca.crlf_action == GIT_CRLF_BINARY)
		return GIT_PASSTHROUGH;

	*payload = git__malloc(sizeof(ca));
	GIT_ERROR_CHECK_ALLOC(*payload);
	memcpy(*payload, &ca, sizeof(ca));

	return 0;
}

__attribute__((used)) static int crlf_apply(
	git_filter *self,
	void **payload, /* may be read and/or set */
	git_buf *to,
	const git_buf *from,
	const git_filter_source *src)
{
	/* initialize payload in case `check` was bypassed */
	if (!*payload) {
		int error = crlf_check(self, payload, src, NULL);

		if (error < 0)
			return error;
	}

	if (git_filter_source_mode(src) == GIT_FILTER_SMUDGE)
		return crlf_apply_to_workdir(*payload, to, from);
	else
		return crlf_apply_to_odb(*payload, to, from, src);
}

__attribute__((used)) static void crlf_cleanup(
	git_filter *self,
	void       *payload)
{
	GIT_UNUSED(self);
	git__free(payload);
}

git_filter *git_crlf_filter_new(void)
{
	struct crlf_filter *f = git__calloc(1, sizeof(struct crlf_filter));
	if (f == NULL)
		return NULL;

	f->f.version = GIT_FILTER_VERSION;
	f->f.attributes = "crlf eol text";
	f->f.initialize = NULL;
	f->f.shutdown = git_filter_free;
	f->f.check    = crlf_check;
	f->f.apply    = crlf_apply;
	f->f.cleanup  = crlf_cleanup;

	return (git_filter *)f;
}

