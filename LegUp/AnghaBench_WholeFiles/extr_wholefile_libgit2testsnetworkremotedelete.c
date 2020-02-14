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
typedef  int /*<<< orphan*/  git_reference ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ENOTFOUND ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  assert_config_entry_existence (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 scalar_t__ count_config_entries_match (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_remote_delete (int /*<<< orphan*/ ,char*) ; 

void test_network_remote_delete__initialize(void)
{
	_repo = cl_git_sandbox_init("testrepo.git");
}

void test_network_remote_delete__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_network_remote_delete__remove_remote_tracking_branches(void)
{
	git_reference *ref;

	cl_git_pass(git_remote_delete(_repo, "test"));
	cl_git_fail_with(GIT_ENOTFOUND, git_reference_lookup(&ref, _repo, "refs/remotes/test/master"));
}

void test_network_remote_delete__remove_remote_configuration_settings(void)
{
	cl_assert(count_config_entries_match(_repo, "remote\\.test\\.+") > 0);

	cl_git_pass(git_remote_delete(_repo, "test"));

	cl_assert_equal_i(0, count_config_entries_match(_repo, "remote\\.test\\.+"));
}

void test_network_remote_delete__remove_branch_upstream_configuration_settings(void)
{
	assert_config_entry_existence(_repo, "branch.mergeless.remote", true);
	assert_config_entry_existence(_repo, "branch.master.remote", true);

	cl_git_pass(git_remote_delete(_repo, "test"));

	assert_config_entry_existence(_repo, "branch.mergeless.remote", false);
	assert_config_entry_existence(_repo, "branch.mergeless.merge", false);
	assert_config_entry_existence(_repo, "branch.master.remote", false);
	assert_config_entry_existence(_repo, "branch.master.merge", false);
}

