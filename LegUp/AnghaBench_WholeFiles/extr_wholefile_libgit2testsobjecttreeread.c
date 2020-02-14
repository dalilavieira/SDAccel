#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_tree_entry ;
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_index ;
typedef  int /*<<< orphan*/  git_commit ;
struct TYPE_7__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 char* BIGFILE ; 
 int /*<<< orphan*/  BIGFILE_SIZE ; 
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  GIT_OBJECT_TREE ; 
 int O_CREAT ; 
 int O_RDWR ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_ (int,char*) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_fail (scalar_t__) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_is_env_set (char*) ; 
 int /*<<< orphan*/  cl_must_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_repo_commit_from_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_skip () ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_buf_cstr (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_joinpath (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_buf_puts (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_tree (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_object_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_workdir (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * git_tree_entry_byindex (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/ * git_tree_entry_byname (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_tree_entry_name (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  git_tree_entry_to_object (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int git_tree_entrycount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_tree_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  p_close (int) ; 
 int /*<<< orphan*/  p_fallocate (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int p_open (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  tree_oid ; 

void test_object_tree_read__initialize(void)
{
   g_repo = cl_git_sandbox_init("testrepo");
}

void test_object_tree_read__cleanup(void)
{
   cl_git_sandbox_cleanup();
}

void test_object_tree_read__loaded(void)
{
	/* acces randomly the entries on a loaded tree */
	git_oid id;
	git_tree *tree;

	git_oid_fromstr(&id, tree_oid);

	cl_git_pass(git_tree_lookup(&tree, g_repo, &id));

	cl_assert(git_tree_entry_byname(tree, "README") != NULL);
	cl_assert(git_tree_entry_byname(tree, "NOTEXISTS") == NULL);
	cl_assert(git_tree_entry_byname(tree, "") == NULL);
	cl_assert(git_tree_entry_byindex(tree, 0) != NULL);
	cl_assert(git_tree_entry_byindex(tree, 2) != NULL);
	cl_assert(git_tree_entry_byindex(tree, 3) == NULL);
	cl_assert(git_tree_entry_byindex(tree, (unsigned int)-1) == NULL);

	git_tree_free(tree);
}

void test_object_tree_read__two(void)
{
	/* read a tree from the repository */
	git_oid id;
	git_tree *tree;
	const git_tree_entry *entry;
	git_object *obj;

	git_oid_fromstr(&id, tree_oid);

	cl_git_pass(git_tree_lookup(&tree, g_repo, &id));

	cl_assert(git_tree_entrycount(tree) == 3);

	/* GH-86: git_object_lookup() should also check the type if the object comes from the cache */
	cl_assert(git_object_lookup(&obj, g_repo, &id, GIT_OBJECT_TREE) == 0);
	cl_assert(obj != NULL);
	git_object_free(obj);
	obj = NULL;
	cl_git_fail(git_object_lookup(&obj, g_repo, &id, GIT_OBJECT_BLOB));
	cl_assert(obj == NULL);

	entry = git_tree_entry_byname(tree, "README");
	cl_assert(entry != NULL);

	cl_assert_equal_s(git_tree_entry_name(entry), "README");

	cl_git_pass(git_tree_entry_to_object(&obj, g_repo, entry));
	cl_assert(obj != NULL);

	git_object_free(obj);
	git_tree_free(tree);
}

void test_object_tree_read__largefile(void)
{
	git_reference *ref;
	git_commit *commit;
	git_tree *tree;
	git_oid oid;
	const git_tree_entry *entry;
	git_object *object;
	git_buf file = GIT_BUF_INIT;
	int fd;
	git_index *idx;

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE"))
		cl_skip();

	cl_git_pass(git_reference_lookup(&ref, g_repo, "refs/heads/master"));
	cl_git_pass(git_repository_index(&idx, g_repo));

	cl_git_pass(git_buf_puts(&file, git_repository_workdir(g_repo)));
	cl_git_pass(git_buf_joinpath(&file, file.ptr, BIGFILE));

	fd = p_open(git_buf_cstr(&file), O_CREAT|O_RDWR, 0644);
	cl_assert_(fd >= 0, "invalid file descriptor");

	cl_must_pass(p_fallocate(fd, 0, BIGFILE_SIZE));
	cl_must_pass(p_close(fd));

	cl_git_pass(git_index_add_bypath(idx, BIGFILE));
	cl_repo_commit_from_index(&oid, g_repo, NULL, 0, "bigfile");

	cl_git_pass(git_commit_lookup(&commit, g_repo, &oid));
	cl_git_pass(git_commit_tree(&tree, commit));

	entry = git_tree_entry_byname(tree, BIGFILE);
	cl_assert_(entry, "entry was NULL");

	cl_git_pass(git_tree_entry_to_object(&object, g_repo, entry));

	git_buf_dispose(&file);
	git_object_free(object);
	git_tree_free(tree);
	git_index_free(idx);
	git_commit_free(commit);
	git_reference_free(ref);
}

