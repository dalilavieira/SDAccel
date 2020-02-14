#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reflog_entry ;
typedef  int /*<<< orphan*/  git_reflog ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_buf ;
struct TYPE_2__ {char const* email; } ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int GIT_OID_HEXSZ ; 
 scalar_t__ GIT_OK ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clar__fail (char const*,int,char*,char*,int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/ * git__calloc (int,int) ; 
 int /*<<< orphan*/  git__free (int /*<<< orphan*/ *) ; 
 char* git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 scalar_t__ git_buf_len (int /*<<< orphan*/ *) ; 
 int git_buf_printf (int /*<<< orphan*/ *,char*,char const*,char const*,...) ; 
 int /*<<< orphan*/  git_buf_putc (int /*<<< orphan*/ *,char) ; 
 int /*<<< orphan*/  git_buf_puts (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_object_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid__writebuf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ git_oid_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_oid_tostr (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_reflog_entry_byindex (int /*<<< orphan*/ *,size_t) ; 
 TYPE_1__* git_reflog_entry_committer (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * git_reflog_entry_id_new (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * git_reflog_entry_id_old (int /*<<< orphan*/  const*) ; 
 char* git_reflog_entry_message (int /*<<< orphan*/  const*) ; 
 size_t git_reflog_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reflog_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reflog_read (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ git_revparse_single (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char const*,char const*) ; 

__attribute__((used)) static int reflog_entry_tostr(git_buf *out, const git_reflog_entry *entry)
{
	char old_oid[GIT_OID_HEXSZ], new_oid[GIT_OID_HEXSZ];

	assert(out && entry);

	git_oid_tostr((char *)&old_oid, GIT_OID_HEXSZ, git_reflog_entry_id_old(entry));
	git_oid_tostr((char *)&new_oid, GIT_OID_HEXSZ, git_reflog_entry_id_new(entry));

	return git_buf_printf(out, "%s %s %s %s", old_oid, new_oid, "somesig", git_reflog_entry_message(entry));
}

size_t reflog_entrycount(git_repository *repo, const char *name)
{
	git_reflog *log;
	size_t ret;

	cl_git_pass(git_reflog_read(&log, repo, name));
	ret = git_reflog_entrycount(log);
	git_reflog_free(log);

	return ret;
}

void cl_reflog_check_entry_(git_repository *repo, const char *reflog, size_t idx,
	const char *old_spec, const char *new_spec,
	const char *email, const char *message, const char *file, int line)
{
	git_reflog *log;
	const git_reflog_entry *entry;
	git_buf result = GIT_BUF_INIT;

	cl_git_pass(git_reflog_read(&log, repo, reflog));
	entry = git_reflog_entry_byindex(log, idx);
	if (entry == NULL)
		clar__fail(file, line, "Reflog has no such entry", NULL, 1);

	if (old_spec) {
		git_object *obj = NULL;
		if (git_revparse_single(&obj, repo, old_spec) == GIT_OK) {
			if (git_oid_cmp(git_object_id(obj), git_reflog_entry_id_old(entry)) != 0) {
				git_oid__writebuf(&result, "\tOld OID: \"", git_object_id(obj));
				git_oid__writebuf(&result, "\" != \"", git_reflog_entry_id_old(entry));
				git_buf_puts(&result, "\"\n");
			}
			git_object_free(obj);
		} else {
			git_oid *oid = git__calloc(1, sizeof(*oid));
			git_oid_fromstr(oid, old_spec);
			if (git_oid_cmp(oid, git_reflog_entry_id_old(entry)) != 0) {
				git_oid__writebuf(&result, "\tOld OID: \"", oid);
				git_oid__writebuf(&result, "\" != \"", git_reflog_entry_id_old(entry));
				git_buf_puts(&result, "\"\n");
			}
			git__free(oid);
		}
	}
	if (new_spec) {
		git_object *obj = NULL;
		if (git_revparse_single(&obj, repo, new_spec) == GIT_OK) {
			if (git_oid_cmp(git_object_id(obj), git_reflog_entry_id_new(entry)) != 0) {
				git_oid__writebuf(&result, "\tNew OID: \"", git_object_id(obj));
				git_oid__writebuf(&result, "\" != \"", git_reflog_entry_id_new(entry));
				git_buf_puts(&result, "\"\n");
			}
			git_object_free(obj);
		} else {
			git_oid *oid = git__calloc(1, sizeof(*oid));
			git_oid_fromstr(oid, new_spec);
			if (git_oid_cmp(oid, git_reflog_entry_id_new(entry)) != 0) {
				git_oid__writebuf(&result, "\tNew OID: \"", oid);
				git_oid__writebuf(&result, "\" != \"", git_reflog_entry_id_new(entry));
				git_buf_puts(&result, "\"\n");
			}
			git__free(oid);
		}
	}

	if (email && strcmp(email, git_reflog_entry_committer(entry)->email) != 0)
		git_buf_printf(&result, "\tEmail: \"%s\" != \"%s\"\n", email, git_reflog_entry_committer(entry)->email);

	if (message) {
		const char *entry_msg = git_reflog_entry_message(entry);
		if (entry_msg == NULL) entry_msg = "";

		if (entry_msg && strcmp(message, entry_msg) != 0)
			git_buf_printf(&result, "\tMessage: \"%s\" != \"%s\"\n", message, entry_msg);
	}
	if (git_buf_len(&result) != 0)
		clar__fail(file, line, "Reflog entry mismatch", git_buf_cstr(&result), 1);

	git_buf_dispose(&result);
	git_reflog_free(log);
}

void reflog_print(git_repository *repo, const char *reflog_name)
{
	git_reflog *reflog;
	size_t idx;
	git_buf out = GIT_BUF_INIT;

	git_reflog_read(&reflog, repo, reflog_name);

	for (idx = 0; idx < git_reflog_entrycount(reflog); idx++) {
		const git_reflog_entry *entry = git_reflog_entry_byindex(reflog, idx);
		reflog_entry_tostr(&out, entry);
		git_buf_putc(&out, '\n');
	}

	fprintf(stderr, "%s", git_buf_cstr(&out));
	git_buf_dispose(&out);
	git_reflog_free(reflog);
}

