#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_tree ;
typedef  void git_submodule ;
struct TYPE_6__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_7__ {char* path; int /*<<< orphan*/  id; void* mode; TYPE_1__ member_0; } ;
typedef  TYPE_2__ git_index_entry ;
typedef  int /*<<< orphan*/  git_index ;
struct TYPE_8__ {size_t status; } ;
typedef  TYPE_3__ git_diff_delta ;
typedef  int /*<<< orphan*/  git_diff ;
typedef  int /*<<< orphan*/  git_blame ;

/* Variables and functions */
 int GIT_DELTA_DELETED ; 
 void* GIT_FILEMODE_BLOB ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int O_CREAT ; 
 int O_RDWR ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,size_t) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_write2file (char*,char*,int,int,int) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_blame_file (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_blame_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_free (int /*<<< orphan*/ *) ; 
 TYPE_3__* git_diff_get_delta (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  git_diff_index_to_workdir (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 size_t git_diff_num_deltas (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_tree_to_index (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_tree_to_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_add (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 size_t git_index_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_head_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_submodule_foreach (int /*<<< orphan*/ ,int (*) (void*,char const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  p_unlink (char*) ; 
 int /*<<< orphan*/  repo ; 
 int /*<<< orphan*/  repo_name ; 

void test_win32_forbidden__initialize(void)
{
	repo = cl_git_sandbox_init(repo_name);
}

void test_win32_forbidden__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_win32_forbidden__can_open_index(void)
{
	git_index *index;
	cl_git_pass(git_repository_index(&index, repo));
	cl_assert_equal_i(7, git_index_entrycount(index));

	/* ensure we can even write the unmodified index */
	cl_git_pass(git_index_write(index));

	git_index_free(index);
}

void test_win32_forbidden__can_add_forbidden_filename_with_entry(void)
{
	git_index *index;
	git_index_entry entry = {{0}};

	cl_git_pass(git_repository_index(&index, repo));

	entry.path = "aux";
	entry.mode = GIT_FILEMODE_BLOB;
	git_oid_fromstr(&entry.id, "da623abd956bb2fd8052c708c7ed43f05d192d37");

	cl_git_pass(git_index_add(index, &entry));

	git_index_free(index);
}

void test_win32_forbidden__cannot_add_dot_git_even_with_entry(void)
{
	git_index *index;
	git_index_entry entry = {{0}};

	cl_git_pass(git_repository_index(&index, repo));

	entry.path = "foo/.git";
	entry.mode = GIT_FILEMODE_BLOB;
	git_oid_fromstr(&entry.id, "da623abd956bb2fd8052c708c7ed43f05d192d37");

	cl_git_fail(git_index_add(index, &entry));

	git_index_free(index);
}

void test_win32_forbidden__cannot_add_forbidden_filename_from_filesystem(void)
{
	git_index *index;

	/* since our function calls are very low-level, we can create `aux.`,
	 * but we should not be able to add it to the index
	 */
	cl_git_pass(git_repository_index(&index, repo));
	cl_git_write2file("win32-forbidden/aux.", "foo\n", 4, O_RDWR | O_CREAT, 0666);

#ifdef GIT_WIN32
	cl_git_fail(git_index_add_bypath(index, "aux."));
#else
	cl_git_pass(git_index_add_bypath(index, "aux."));
#endif

	cl_must_pass(p_unlink("win32-forbidden/aux."));
	git_index_free(index);
}

__attribute__((used)) static int dummy_submodule_cb(
	git_submodule *sm, const char *name, void *payload)
{
	GIT_UNUSED(sm);
	GIT_UNUSED(name);
	GIT_UNUSED(payload);
	return 0;
}

void test_win32_forbidden__can_diff_tree_to_index(void)
{
	git_diff *diff;
	git_tree *tree;

	cl_git_pass(git_repository_head_tree(&tree, repo));
	cl_git_pass(git_diff_tree_to_index(&diff, repo, tree, NULL, NULL));
	cl_assert_equal_i(0, git_diff_num_deltas(diff));
	git_diff_free(diff);
	git_tree_free(tree);
}

void test_win32_forbidden__can_diff_tree_to_tree(void)
{
	git_diff *diff;
	git_tree *tree;

	cl_git_pass(git_repository_head_tree(&tree, repo));
	cl_git_pass(git_diff_tree_to_tree(&diff, repo, tree, tree, NULL));
	cl_assert_equal_i(0, git_diff_num_deltas(diff));
	git_diff_free(diff);
	git_tree_free(tree);
}

void test_win32_forbidden__can_diff_index_to_workdir(void)
{
	git_index *index;
	git_diff *diff;
	const git_diff_delta *delta;
	git_tree *tree;
	size_t i;

	cl_git_pass(git_repository_index(&index, repo));
	cl_git_pass(git_repository_head_tree(&tree, repo));
	cl_git_pass(git_diff_index_to_workdir(&diff, repo, index, NULL));

	for (i = 0; i < git_diff_num_deltas(diff); i++) {
		delta = git_diff_get_delta(diff, i);
		cl_assert_equal_i(GIT_DELTA_DELETED, delta->status);
	}

	git_diff_free(diff);
	git_tree_free(tree);
	git_index_free(index);
}

void test_win32_forbidden__checking_out_forbidden_index_fails(void)
{
#ifdef GIT_WIN32
	git_index *index;
	git_checkout_options opts = GIT_CHECKOUT_OPTIONS_INIT;
	git_diff *diff;
	const git_diff_delta *delta;
	git_tree *tree;
	size_t num_deltas, i;

	opts.checkout_strategy = GIT_CHECKOUT_FORCE;

	cl_git_pass(git_repository_index(&index, repo));
	cl_git_fail(git_checkout_index(repo, index, &opts));

	cl_git_pass(git_repository_head_tree(&tree, repo));
	cl_git_pass(git_diff_index_to_workdir(&diff, repo, index, NULL));

	num_deltas = git_diff_num_deltas(diff);

	cl_assert(num_deltas > 0);

	for (i = 0; i < num_deltas; i++) {
		delta = git_diff_get_delta(diff, i);
		cl_assert_equal_i(GIT_DELTA_DELETED, delta->status);
	}

	git_diff_free(diff);
	git_tree_free(tree);
	git_index_free(index);
#endif
}

void test_win32_forbidden__can_query_submodules(void)
{
	cl_git_pass(git_submodule_foreach(repo, dummy_submodule_cb, NULL));
}

void test_win32_forbidden__can_blame_file(void)
{
	git_blame *blame;

	cl_git_pass(git_blame_file(&blame, repo, "aux", NULL));
	git_blame_free(blame);
}

