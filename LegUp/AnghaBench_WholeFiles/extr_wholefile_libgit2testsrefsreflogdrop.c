#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  oid_old; int /*<<< orphan*/  oid_cur; } ;
typedef  TYPE_1__ git_reflog_entry ;
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_OID_HEX_ZERO ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (int,int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int entrycount ; 
 int /*<<< orphan*/ * g_reflog ; 
 int /*<<< orphan*/  g_repo ; 
 scalar_t__ git_oid_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ git_oid_streq (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_reflog_drop (int /*<<< orphan*/ *,int,int) ; 
 TYPE_1__* git_reflog_entry_byindex (int /*<<< orphan*/ *,int) ; 
 int git_reflog_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reflog_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reflog_read (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int git_reflog_write (int /*<<< orphan*/ *) ; 

void test_refs_reflog_drop__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo.git");

	git_reflog_read(&g_reflog, g_repo, "HEAD");
	entrycount = git_reflog_entrycount(g_reflog);
}

void test_refs_reflog_drop__cleanup(void)
{
	git_reflog_free(g_reflog);
	g_reflog = NULL;

	cl_git_sandbox_cleanup();
}

void test_refs_reflog_drop__dropping_a_non_exisiting_entry_from_the_log_returns_ENOTFOUND(void)
{
	cl_assert_equal_i(GIT_ENOTFOUND, git_reflog_drop(g_reflog, entrycount, 0));

	cl_assert_equal_sz(entrycount, git_reflog_entrycount(g_reflog));
}

void test_refs_reflog_drop__can_drop_an_entry(void)
{
	cl_assert(entrycount > 4);

	cl_git_pass(git_reflog_drop(g_reflog, 2, 0));
	cl_assert_equal_sz(entrycount - 1, git_reflog_entrycount(g_reflog));
}

void test_refs_reflog_drop__can_drop_an_entry_and_rewrite_the_log_history(void)
{
	const git_reflog_entry *before_current;
	const git_reflog_entry *after_current;
	git_oid before_current_old_oid, before_current_cur_oid;

	cl_assert(entrycount > 4);

	before_current = git_reflog_entry_byindex(g_reflog, 1);

	git_oid_cpy(&before_current_old_oid, &before_current->oid_old);
	git_oid_cpy(&before_current_cur_oid, &before_current->oid_cur);

	cl_git_pass(git_reflog_drop(g_reflog, 1, 1));

	cl_assert_equal_sz(entrycount - 1, git_reflog_entrycount(g_reflog));

	after_current = git_reflog_entry_byindex(g_reflog, 0);

	cl_assert_equal_i(0, git_oid_cmp(&before_current_old_oid, &after_current->oid_old));
	cl_assert(0 != git_oid_cmp(&before_current_cur_oid, &after_current->oid_cur));
}

void test_refs_reflog_drop__can_drop_the_oldest_entry(void)
{
	const git_reflog_entry *entry;

	cl_assert(entrycount > 2);

	cl_git_pass(git_reflog_drop(g_reflog, entrycount - 1, 0));
	cl_assert_equal_sz(entrycount - 1, git_reflog_entrycount(g_reflog));

	entry = git_reflog_entry_byindex(g_reflog, entrycount - 2);
	cl_assert(git_oid_streq(&entry->oid_old, GIT_OID_HEX_ZERO) != 0);
}

void test_refs_reflog_drop__can_drop_the_oldest_entry_and_rewrite_the_log_history(void)
{
	const git_reflog_entry *entry;

	cl_assert(entrycount > 2);

	cl_git_pass(git_reflog_drop(g_reflog, entrycount - 1, 1));
	cl_assert_equal_sz(entrycount - 1, git_reflog_entrycount(g_reflog));

	entry = git_reflog_entry_byindex(g_reflog, entrycount - 2);
	cl_assert(git_oid_streq(&entry->oid_old, GIT_OID_HEX_ZERO) == 0);
}

void test_refs_reflog_drop__can_drop_all_the_entries(void)
{
	cl_assert(--entrycount > 0);

	do 	{
		cl_git_pass(git_reflog_drop(g_reflog, 0, 1));
	} while (--entrycount > 0);

	cl_git_pass(git_reflog_drop(g_reflog, 0, 1));

	cl_assert_equal_i(0, (int)git_reflog_entrycount(g_reflog));
}

void test_refs_reflog_drop__can_persist_deletion_on_disk(void)
{
	cl_assert(entrycount > 2);

	cl_git_pass(git_reflog_drop(g_reflog, 0, 1));
	cl_assert_equal_sz(entrycount - 1, git_reflog_entrycount(g_reflog));
	cl_git_pass(git_reflog_write(g_reflog));

	git_reflog_free(g_reflog);

	git_reflog_read(&g_reflog, g_repo, "HEAD");

	cl_assert_equal_sz(entrycount - 1, git_reflog_entrycount(g_reflog));
}

