#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_3__ {int val; } ;
struct TYPE_4__ {TYPE_1__ refcount; } ;
typedef  TYPE_2__ git_refcount ;
typedef  int /*<<< orphan*/  git_odb ;

/* Variables and functions */
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_fixture (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_remove_placeholders (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_is_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_odb (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_open (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_path (int /*<<< orphan*/ *) ; 

void test_repo_getters__is_empty_correctly_deals_with_pristine_looking_repos(void)
{
	git_repository *repo;

	repo = cl_git_sandbox_init("empty_bare.git");
	cl_git_remove_placeholders(git_repository_path(repo), "dummy-marker.txt");

	cl_assert_equal_i(true, git_repository_is_empty(repo));

	cl_git_sandbox_cleanup();
}

void test_repo_getters__is_empty_can_detect_used_repositories(void)
{
	git_repository *repo;

	cl_git_pass(git_repository_open(&repo, cl_fixture("testrepo.git")));

	cl_assert_equal_i(false, git_repository_is_empty(repo));

	git_repository_free(repo);
}

void test_repo_getters__retrieving_the_odb_honors_the_refcount(void)
{
	git_odb *odb;
	git_repository *repo;

	cl_git_pass(git_repository_open(&repo, cl_fixture("testrepo.git")));

	cl_git_pass(git_repository_odb(&odb, repo));
	cl_assert(((git_refcount *)odb)->refcount.val == 2);

	git_repository_free(repo);
	cl_assert(((git_refcount *)odb)->refcount.val == 1);

	git_odb_free(odb);
}

