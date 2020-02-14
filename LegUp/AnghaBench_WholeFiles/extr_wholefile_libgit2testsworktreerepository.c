#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  oid; } ;
struct TYPE_13__ {TYPE_1__ target; } ;
typedef  TYPE_2__ git_reference ;
struct TYPE_14__ {scalar_t__ repo; int /*<<< orphan*/  worktree; } ;

/* Variables and functions */
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail (int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cleanup_fixture_worktree (TYPE_3__*) ; 
 TYPE_3__ fixture ; 
 scalar_t__ git_reference_cmp (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  git_reference_free (TYPE_2__*) ; 
 int git_reference_lookup (TYPE_2__**,scalar_t__,char*) ; 
 scalar_t__ git_reference_owner (TYPE_2__*) ; 
 int git_repository_head_detached (int /*<<< orphan*/ ) ; 
 int git_repository_head_detached_for_worktree (scalar_t__,char*) ; 
 int git_repository_head_for_worktree (TYPE_2__**,scalar_t__,char*) ; 
 int git_repository_set_head_detached (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setup_fixture_worktree (TYPE_3__*) ; 

void test_worktree_repository__initialize(void)
{
	setup_fixture_worktree(&fixture);
}

void test_worktree_repository__cleanup(void)
{
	cleanup_fixture_worktree(&fixture);
}

void test_worktree_repository__head(void)
{
	git_reference *ref, *head;

	cl_git_pass(git_reference_lookup(&ref, fixture.repo, "refs/heads/testrepo-worktree"));
	cl_git_pass(git_repository_head_for_worktree(&head, fixture.repo, "testrepo-worktree"));
	cl_assert(git_reference_cmp(ref, head) == 0);
	cl_assert(git_reference_owner(ref) == fixture.repo);

	git_reference_free(ref);
	git_reference_free(head);
}

void test_worktree_repository__head_fails_for_invalid_worktree(void)
{
	git_reference *head = NULL;

	cl_git_fail(git_repository_head_for_worktree(&head, fixture.repo, "invalid"));
	cl_assert(head == NULL);
}

void test_worktree_repository__head_detached(void)
{
	git_reference *ref, *head;

	cl_git_pass(git_reference_lookup(&ref, fixture.repo, "refs/heads/testrepo-worktree"));
	cl_git_pass(git_repository_set_head_detached(fixture.worktree, &ref->target.oid));

	cl_assert(git_repository_head_detached(fixture.worktree));
	cl_assert(git_repository_head_detached_for_worktree(fixture.repo, "testrepo-worktree"));
	cl_git_fail(git_repository_head_for_worktree(&head, fixture.repo, "testrepo-worktree"));

	git_reference_free(ref);
}

void test_worktree_repository__head_detached_fails_for_invalid_worktree(void)
{
	git_reference *head = NULL;

	cl_git_fail(git_repository_head_detached_for_worktree(fixture.repo, "invalid"));
	cl_assert(head == NULL);
}

