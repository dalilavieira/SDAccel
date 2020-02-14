#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
struct TYPE_30__ {int /*<<< orphan*/  real_email; int /*<<< orphan*/  real_name; int /*<<< orphan*/  replace_email; int /*<<< orphan*/  replace_name; } ;
typedef  TYPE_1__ mailmap_entry ;
struct TYPE_31__ {char const* real_name; char const* real_email; char const* replace_name; char const* replace_email; } ;
typedef  TYPE_2__ git_mailmap_entry ;
struct TYPE_32__ {int /*<<< orphan*/  entries; } ;
typedef  TYPE_3__ git_mailmap ;
struct TYPE_33__ {int /*<<< orphan*/  size; int /*<<< orphan*/  ptr; } ;
typedef  TYPE_4__ git_buf ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_4__ GIT_BUF_INIT ; 
 TYPE_1__* bare_resolved_with_blob_override ; 
 int /*<<< orphan*/  cl_assert (TYPE_2__ const*) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (size_t,int) ; 
 int /*<<< orphan*/  cl_check (int) ; 
 char* cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 TYPE_1__* entries ; 
 int /*<<< orphan*/ * g_config ; 
 TYPE_3__* g_mailmap ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_buf_attach_notowned (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_4__*) ; 
 int /*<<< orphan*/  git_buf_text_lf_to_crlf (TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_set_string (int /*<<< orphan*/ *,char*,char*) ; 
 TYPE_2__* git_mailmap_entry_lookup (TYPE_3__ const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_mailmap_free (TYPE_3__*) ; 
 int /*<<< orphan*/  git_mailmap_from_buffer (TYPE_3__**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_mailmap_from_repository (TYPE_3__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_mailmap_resolve (char const**,char const**,TYPE_3__ const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int git_repository_is_bare (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_set_bare (int /*<<< orphan*/ *) ; 
 size_t git_vector_length (int /*<<< orphan*/ *) ; 
 TYPE_1__* resolved ; 
 TYPE_1__* resolved_bare ; 
 TYPE_1__* resolved_untracked ; 
 TYPE_1__* resolved_with_blob_override ; 
 TYPE_1__* resolved_with_file_override ; 
 int /*<<< orphan*/  string_mailmap ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 

void test_mailmap_parsing__initialize(void)
{
	g_repo = NULL;
	g_mailmap = NULL;
	g_config = NULL;
}

void test_mailmap_parsing__cleanup(void)
{
	git_mailmap_free(g_mailmap);
	git_config_free(g_config);
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static void check_mailmap_entries(
	const git_mailmap *mailmap, const mailmap_entry *entries, size_t entries_size)
{
	const git_mailmap_entry *parsed;
	size_t idx;

	/* Check the correct # of entries were parsed */
	cl_assert_equal_sz(entries_size, git_vector_length(&mailmap->entries));

	/* Make sure looking up each entry succeeds */
	for (idx = 0; idx < entries_size; ++idx) {
		parsed = git_mailmap_entry_lookup(
			mailmap, entries[idx].replace_name, entries[idx].replace_email);

		cl_assert(parsed);
		cl_assert_equal_s(parsed->real_name, entries[idx].real_name);
		cl_assert_equal_s(parsed->real_email, entries[idx].real_email);
		cl_assert_equal_s(parsed->replace_name, entries[idx].replace_name);
		cl_assert_equal_s(parsed->replace_email, entries[idx].replace_email);
	}
}

__attribute__((used)) static void check_mailmap_resolve(
	const git_mailmap *mailmap, const mailmap_entry *resolved, size_t resolved_size)
{
	const char *resolved_name = NULL;
	const char *resolved_email = NULL;
	size_t idx;

	/* Check that the resolver behaves correctly */
	for (idx = 0; idx < resolved_size; ++idx) {
		cl_git_pass(git_mailmap_resolve(
			&resolved_name, &resolved_email, mailmap,
			resolved[idx].replace_name, resolved[idx].replace_email));
		cl_assert_equal_s(resolved_name, resolved[idx].real_name);
		cl_assert_equal_s(resolved_email, resolved[idx].real_email);
	}
}

void test_mailmap_parsing__string(void)
{
	cl_git_pass(git_mailmap_from_buffer(
		&g_mailmap, string_mailmap, strlen(string_mailmap)));

	/* We should have parsed all of the entries */
	check_mailmap_entries(g_mailmap, entries, ARRAY_SIZE(entries));

	/* Check that resolving the entries works */
	check_mailmap_resolve(g_mailmap, resolved, ARRAY_SIZE(resolved));
	check_mailmap_resolve(
		g_mailmap, resolved_untracked, ARRAY_SIZE(resolved_untracked));
}

void test_mailmap_parsing__windows_string(void)
{
	git_buf unixbuf = GIT_BUF_INIT;
	git_buf winbuf = GIT_BUF_INIT;

	/* Parse with windows-style line endings */
	git_buf_attach_notowned(&unixbuf, string_mailmap, strlen(string_mailmap));
	cl_git_pass(git_buf_text_lf_to_crlf(&winbuf, &unixbuf));

	cl_git_pass(git_mailmap_from_buffer(&g_mailmap, winbuf.ptr, winbuf.size));
	git_buf_dispose(&winbuf);

	/* We should have parsed all of the entries */
	check_mailmap_entries(g_mailmap, entries, ARRAY_SIZE(entries));

	/* Check that resolving the entries works */
	check_mailmap_resolve(g_mailmap, resolved, ARRAY_SIZE(resolved));
	check_mailmap_resolve(
		g_mailmap, resolved_untracked, ARRAY_SIZE(resolved_untracked));
}

void test_mailmap_parsing__fromrepo(void)
{
	g_repo = cl_git_sandbox_init("mailmap");
	cl_check(!git_repository_is_bare(g_repo));

	cl_git_pass(git_mailmap_from_repository(&g_mailmap, g_repo));

	/* We should have parsed all of the entries */
	check_mailmap_entries(g_mailmap, entries, ARRAY_SIZE(entries));

	/* Check that resolving the entries works */
	check_mailmap_resolve(g_mailmap, resolved, ARRAY_SIZE(resolved));
	check_mailmap_resolve(
		g_mailmap, resolved_untracked, ARRAY_SIZE(resolved_untracked));
}

void test_mailmap_parsing__frombare(void)
{
	g_repo = cl_git_sandbox_init("mailmap/.gitted");
	cl_git_pass(git_repository_set_bare(g_repo));
	cl_check(git_repository_is_bare(g_repo));

	cl_git_pass(git_mailmap_from_repository(&g_mailmap, g_repo));

	/* We should have parsed all of the entries, except for the untracked one */
	check_mailmap_entries(g_mailmap, entries, ARRAY_SIZE(entries) - 1);

	/* Check that resolving the entries works */
	check_mailmap_resolve(g_mailmap, resolved, ARRAY_SIZE(resolved));
	check_mailmap_resolve(
		g_mailmap, resolved_bare, ARRAY_SIZE(resolved_bare));
}

void test_mailmap_parsing__file_config(void)
{
	g_repo = cl_git_sandbox_init("mailmap");
	cl_git_pass(git_repository_config(&g_config, g_repo));

	cl_git_pass(git_config_set_string(
		g_config, "mailmap.file", cl_fixture("mailmap/file_override")));

	cl_git_pass(git_mailmap_from_repository(&g_mailmap, g_repo));

	/* Check we don't have duplicate entries */
	cl_assert_equal_sz(git_vector_length(&g_mailmap->entries), 9);

	/* Check that resolving the entries works */
	check_mailmap_resolve(
		g_mailmap, resolved_with_file_override,
		ARRAY_SIZE(resolved_with_file_override));
}

void test_mailmap_parsing__blob_config(void)
{
	g_repo = cl_git_sandbox_init("mailmap");
	cl_git_pass(git_repository_config(&g_config, g_repo));

	cl_git_pass(git_config_set_string(
		g_config, "mailmap.blob", "HEAD:blob_override"));

	cl_git_pass(git_mailmap_from_repository(&g_mailmap, g_repo));

	/* Check we don't have duplicate entries */
	cl_assert_equal_sz(git_vector_length(&g_mailmap->entries), 9);

	/* Check that resolving the entries works */
	check_mailmap_resolve(
		g_mailmap, resolved_with_blob_override,
		ARRAY_SIZE(resolved_with_blob_override));
}

void test_mailmap_parsing__bare_blob_config(void)
{
	g_repo = cl_git_sandbox_init("mailmap/.gitted");
	cl_git_pass(git_repository_set_bare(g_repo));
	cl_check(git_repository_is_bare(g_repo));

	cl_git_pass(git_repository_config(&g_config, g_repo));

	cl_git_pass(git_config_set_string(
		g_config, "mailmap.blob", "HEAD:blob_override"));

	cl_git_pass(git_mailmap_from_repository(&g_mailmap, g_repo));

	/* Check that we only have the 2 entries */
	cl_assert_equal_sz(git_vector_length(&g_mailmap->entries), 2);

	/* Check that resolving the entries works */
	check_mailmap_resolve(
		g_mailmap, bare_resolved_with_blob_override,
		ARRAY_SIZE(bare_resolved_with_blob_override));
}

