#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_7__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zeroed ;
typedef  int /*<<< orphan*/  stats ;
typedef  int /*<<< orphan*/  git_filter_list ;
typedef  int /*<<< orphan*/  git_config ;
typedef  int /*<<< orphan*/  git_buf_text_stats ;
struct TYPE_9__ {size_t size; int /*<<< orphan*/ * ptr; } ;
typedef  TYPE_1__ git_buf ;
typedef  int /*<<< orphan*/  git_blob ;
struct TYPE_10__ {size_t size; int /*<<< orphan*/ * ptr; } ;

/* Variables and functions */
 int CRLF_NUM_TEST_OBJECTS ; 
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_FILTER_TO_ODB ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (size_t,size_t) ; 
 int /*<<< orphan*/  cl_git_append2file (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 TYPE_7__* g_crlf_filtered ; 
 int /*<<< orphan*/ * g_crlf_filtered_stats ; 
 int /*<<< orphan*/ * g_crlf_oids ; 
 int /*<<< orphan*/ ** g_crlf_raw ; 
 scalar_t__* g_crlf_raw_len ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_attr_cache_flush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_blob__getbuf (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_create_frombuffer (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  git_blob_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blob_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * git_blob_rawcontent (int /*<<< orphan*/ *) ; 
 scalar_t__ git_blob_rawsize (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_text_gather_stats (int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_apply_to_blob (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_load (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_config (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ strlen (int /*<<< orphan*/ *) ; 

void test_object_blob_filter__initialize(void)
{
	int i;

	g_repo = cl_git_sandbox_init("empty_standard_repo");

	for (i = 0; i < CRLF_NUM_TEST_OBJECTS; i++) {
		if (g_crlf_raw_len[i] < 0)
			g_crlf_raw_len[i] = strlen(g_crlf_raw[i]);

		cl_git_pass(git_blob_create_frombuffer(
			&g_crlf_oids[i], g_repo, g_crlf_raw[i], (size_t)g_crlf_raw_len[i]));
	}
}

void test_object_blob_filter__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_object_blob_filter__unfiltered(void)
{
	int i;
	git_blob *blob;

	for (i = 0; i < CRLF_NUM_TEST_OBJECTS; i++) {
		size_t raw_len = (size_t)g_crlf_raw_len[i];

		cl_git_pass(git_blob_lookup(&blob, g_repo, &g_crlf_oids[i]));

		cl_assert_equal_sz(raw_len, (size_t)git_blob_rawsize(blob));
		cl_assert_equal_i(
			0, memcmp(g_crlf_raw[i], git_blob_rawcontent(blob), raw_len));

		git_blob_free(blob);
	}
}

void test_object_blob_filter__stats(void)
{
	int i;
	git_blob *blob;
	git_buf buf = GIT_BUF_INIT;
	git_buf_text_stats stats;

	for (i = 0; i < CRLF_NUM_TEST_OBJECTS; i++) {
		cl_git_pass(git_blob_lookup(&blob, g_repo, &g_crlf_oids[i]));
		cl_git_pass(git_blob__getbuf(&buf, blob));
		git_buf_text_gather_stats(&stats, &buf, false);
		cl_assert_equal_i(
			0, memcmp(&g_crlf_filtered_stats[i], &stats, sizeof(stats)));
		git_blob_free(blob);
	}

	git_buf_dispose(&buf);
}

void test_object_blob_filter__to_odb(void)
{
	git_filter_list *fl = NULL;
	git_config *cfg;
	int i;
	git_blob *blob;
	git_buf out = GIT_BUF_INIT, zeroed;

	cl_git_pass(git_repository_config(&cfg, g_repo));
	cl_assert(cfg);

	git_attr_cache_flush(g_repo);
	cl_git_append2file("empty_standard_repo/.gitattributes", "*.txt text\n");

	cl_git_pass(git_filter_list_load(
		&fl, g_repo, NULL, "filename.txt", GIT_FILTER_TO_ODB, 0));
	cl_assert(fl != NULL);

	for (i = 0; i < CRLF_NUM_TEST_OBJECTS; i++) {
		cl_git_pass(git_blob_lookup(&blob, g_repo, &g_crlf_oids[i]));

		/* try once with allocated blob */
		cl_git_pass(git_filter_list_apply_to_blob(&out, fl, blob));
		cl_assert_equal_sz(g_crlf_filtered[i].size, out.size);
		cl_assert_equal_i(
			0, memcmp(out.ptr, g_crlf_filtered[i].ptr, out.size));

		/* try again with zeroed blob */
		memset(&zeroed, 0, sizeof(zeroed));
		cl_git_pass(git_filter_list_apply_to_blob(&zeroed, fl, blob));
		cl_assert_equal_sz(g_crlf_filtered[i].size, zeroed.size);
		cl_assert_equal_i(
			0, memcmp(zeroed.ptr, g_crlf_filtered[i].ptr, zeroed.size));
		git_buf_dispose(&zeroed);

		git_blob_free(blob);
	}

	git_filter_list_free(fl);
	git_buf_dispose(&out);
	git_config_free(cfg);
}

