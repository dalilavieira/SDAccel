#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_index ;
typedef  int /*<<< orphan*/  git_filter_list ;
struct TYPE_14__ {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_filter ;
struct TYPE_15__ {int /*<<< orphan*/  ptr; int /*<<< orphan*/  member_0; int /*<<< orphan*/  size; } ;
typedef  TYPE_2__ git_buf ;
typedef  int /*<<< orphan*/  git_blob ;
struct TYPE_16__ {int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BITFLIPPED_AND_REVERSED_DATA_LEN ; 
 int /*<<< orphan*/  BITFLIP_FILTER_PRIORITY ; 
 TYPE_2__ GIT_BUF_INIT ; 
 TYPE_2__ GIT_BUF_INIT_CONST (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GIT_EEXISTS ; 
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 char* GIT_FILTER_CRLF ; 
 int /*<<< orphan*/  GIT_FILTER_DRIVER_PRIORITY ; 
 char* GIT_FILTER_IDENT ; 
 int /*<<< orphan*/  GIT_FILTER_TO_ODB ; 
 int /*<<< orphan*/  GIT_FILTER_TO_WORKTREE ; 
 int /*<<< orphan*/  GIT_FILTER_VERSION ; 
 int /*<<< orphan*/  REVERSE_FILTER_PRIORITY ; 
 int /*<<< orphan*/  bitflipped_and_reversed_data ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (int,size_t) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_repo_commit_from_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 TYPE_1__* create_bitflip_filter () ; 
 TYPE_1__* create_erroneous_filter (char*) ; 
 TYPE_1__* create_reverse_filter (char*) ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_blob_filtered_content (TYPE_2__*,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_blob_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_rawcontent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_2__*) ; 
 int /*<<< orphan*/  git_filter_list_apply_to_data (TYPE_2__*,int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  git_filter_list_free (int /*<<< orphan*/ *) ; 
 size_t git_filter_list_length (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_load (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_filter_register (char*,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_filter_unregister (char*) ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 TYPE_3__* git_index_get_bypath (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
static  void register_custom_filters () ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  workdir_data ; 

void test_filter_custom__initialize(void)
{
	register_custom_filters();

	g_repo = cl_git_sandbox_init("empty_standard_repo");

	cl_git_mkfile(
		"empty_standard_repo/.gitattributes",
		"hero* bitflip reverse\n"
		"herofile text\n"
		"heroflip -reverse binary\n"
		"villain erroneous\n"
		"*.bin binary\n");
}

void test_filter_custom__cleanup(void)
{
	cl_git_sandbox_cleanup();
	g_repo = NULL;
}

__attribute__((used)) static void register_custom_filters(void)
{
	static int filters_registered = 0;

	if (!filters_registered) {
		cl_git_pass(git_filter_register(
			"bitflip", create_bitflip_filter(), BITFLIP_FILTER_PRIORITY));

		cl_git_pass(git_filter_register(
			"reverse", create_reverse_filter("+reverse"),
			REVERSE_FILTER_PRIORITY));

		/* re-register reverse filter with standard filter=xyz priority */
		cl_git_pass(git_filter_register(
			"pre-reverse",
			create_reverse_filter("+prereverse"),
			GIT_FILTER_DRIVER_PRIORITY));

		cl_git_pass(git_filter_register(
			"erroneous",
			create_erroneous_filter("+erroneous"),
			GIT_FILTER_DRIVER_PRIORITY));

		filters_registered = 1;
	}
}

void test_filter_custom__to_odb(void)
{
	git_filter_list *fl;
	git_buf out = { 0 };
	git_buf in = GIT_BUF_INIT_CONST(workdir_data, strlen(workdir_data));

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "herofile", GIT_FILTER_TO_ODB, 0));

	cl_git_pass(git_filter_list_apply_to_data(&out, fl, &in));

	cl_assert_equal_i(BITFLIPPED_AND_REVERSED_DATA_LEN, out.size);

	cl_assert_equal_i(
		0, memcmp(bitflipped_and_reversed_data, out.ptr, out.size));

	git_filter_list_free(fl);
	git_buf_dispose(&out);
}

void test_filter_custom__to_workdir(void)
{
	git_filter_list *fl;
	git_buf out = { 0 };
	git_buf in = GIT_BUF_INIT_CONST(
		bitflipped_and_reversed_data, BITFLIPPED_AND_REVERSED_DATA_LEN);

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "herofile", GIT_FILTER_TO_WORKTREE, 0));

	cl_git_pass(git_filter_list_apply_to_data(&out, fl, &in));

	cl_assert_equal_i(strlen(workdir_data), out.size);

	cl_assert_equal_i(
		0, memcmp(workdir_data, out.ptr, out.size));

	git_filter_list_free(fl);
	git_buf_dispose(&out);
}

void test_filter_custom__can_register_a_custom_filter_in_the_repository(void)
{
	git_filter_list *fl;

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "herofile", GIT_FILTER_TO_WORKTREE, 0));
	/* expect: bitflip, reverse, crlf */
	cl_assert_equal_sz(3, git_filter_list_length(fl));
	git_filter_list_free(fl);

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "herocorp", GIT_FILTER_TO_WORKTREE, 0));
	/* expect: bitflip, reverse - possibly crlf depending on global config */
	{
		size_t flen = git_filter_list_length(fl);
		cl_assert(flen == 2 || flen == 3);
	}
	git_filter_list_free(fl);

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "hero.bin", GIT_FILTER_TO_WORKTREE, 0));
	/* expect: bitflip, reverse */
	cl_assert_equal_sz(2, git_filter_list_length(fl));
	git_filter_list_free(fl);

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "heroflip", GIT_FILTER_TO_WORKTREE, 0));
	/* expect: bitflip (because of -reverse) */
	cl_assert_equal_sz(1, git_filter_list_length(fl));
	git_filter_list_free(fl);

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "doesntapplytome.bin",
		GIT_FILTER_TO_WORKTREE, 0));
	/* expect: none */
	cl_assert_equal_sz(0, git_filter_list_length(fl));
	git_filter_list_free(fl);
}

void test_filter_custom__order_dependency(void)
{
	git_index *index;
	git_blob *blob;
	git_buf buf = { 0 };

	/* so if ident and reverse are used together, an interesting thing
	 * happens - a reversed "$Id$" string is no longer going to trigger
	 * ident correctly.  When checking out, the filters should be applied
	 * in order CLRF, then ident, then reverse, so ident expansion should
	 * work correctly.  On check in, the content should be reversed, then
	 * ident, then CRLF filtered.  Let's make sure that works...
	 */

	cl_git_mkfile(
		"empty_standard_repo/.gitattributes",
		"hero.*.rev-ident text ident prereverse eol=lf\n");

	cl_git_mkfile(
		"empty_standard_repo/hero.1.rev-ident",
		"This is a test\n$Id$\nHave fun!\n");

	cl_git_mkfile(
		"empty_standard_repo/hero.2.rev-ident",
		"Another test\n$dI$\nCrazy!\n");

	cl_git_pass(git_repository_index(&index, g_repo));
	cl_git_pass(git_index_add_bypath(index, "hero.1.rev-ident"));
	cl_git_pass(git_index_add_bypath(index, "hero.2.rev-ident"));
	cl_repo_commit_from_index(NULL, g_repo, NULL, 0, "Filter chains\n");
	git_index_free(index);

	cl_git_pass(git_blob_lookup(&blob, g_repo,
		& git_index_get_bypath(index, "hero.1.rev-ident", 0)->id));
	cl_assert_equal_s(
		"\n!nuf evaH\n$dI$\ntset a si sihT", git_blob_rawcontent(blob));
	cl_git_pass(git_blob_filtered_content(&buf, blob, "hero.1.rev-ident", 0));
	/* no expansion because id was reversed at checkin and now at ident
	 * time, reverse is not applied yet */
	cl_assert_equal_s(
		"This is a test\n$Id$\nHave fun!\n", buf.ptr);
	git_blob_free(blob);

	cl_git_pass(git_blob_lookup(&blob, g_repo,
		& git_index_get_bypath(index, "hero.2.rev-ident", 0)->id));
	cl_assert_equal_s(
		"\n!yzarC\n$Id$\ntset rehtonA", git_blob_rawcontent(blob));
	cl_git_pass(git_blob_filtered_content(&buf, blob, "hero.2.rev-ident", 0));
	/* expansion because reverse was applied at checkin and at ident time,
	 * reverse is not applied yet */
	cl_assert_equal_s(
		"Another test\n$ 59001fe193103b1016b27027c0c827d036fd0ac8 :dI$\nCrazy!\n", buf.ptr);
	cl_assert_equal_i(0, git_oid_strcmp(
		git_blob_id(blob), "8ca0df630d728c0c72072b6101b301391ef10095"));
	git_blob_free(blob);

	git_buf_dispose(&buf);
}

void test_filter_custom__filter_registry_failure_cases(void)
{
	git_filter fake = { GIT_FILTER_VERSION, 0 };

	cl_assert_equal_i(GIT_EEXISTS, git_filter_register("bitflip", &fake, 0));

	cl_git_fail(git_filter_unregister(GIT_FILTER_CRLF));
	cl_git_fail(git_filter_unregister(GIT_FILTER_IDENT));
	cl_assert_equal_i(GIT_ENOTFOUND, git_filter_unregister("not-a-filter"));
}

void test_filter_custom__erroneous_filter_fails(void)
{
	git_filter_list *filters;
	git_buf out = GIT_BUF_INIT;
	git_buf in = GIT_BUF_INIT_CONST(workdir_data, strlen(workdir_data));

	cl_git_pass(git_filter_list_load(
		&filters, g_repo, NULL, "villain", GIT_FILTER_TO_WORKTREE, 0));

	cl_git_fail(git_filter_list_apply_to_data(&out, filters, &in));

	git_filter_list_free(filters);
	git_buf_dispose(&out);
}

