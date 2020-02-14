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
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_tag ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_commit ;
typedef  int /*<<< orphan*/  git_blob ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  GIT_OBJECT_TAG ; 
 int /*<<< orphan*/  GIT_OBJECT_TREE ; 
 int git_object_dup (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* git_object_id (int /*<<< orphan*/  const*) ; 
 int git_object_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int git_object_lookup_prefix (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * git_object_owner (int /*<<< orphan*/  const*) ; 

int git_commit_lookup(git_commit **out, git_repository *repo, const git_oid *id)
{
	return git_object_lookup((git_object **)out, repo, id, GIT_OBJECT_COMMIT);
}

int git_commit_lookup_prefix(git_commit **out, git_repository *repo, const git_oid *id, size_t len)
{
	return git_object_lookup_prefix((git_object **)out, repo, id, len, GIT_OBJECT_COMMIT);
}

void git_commit_free(git_commit *obj)
{
	git_object_free((git_object *)obj);
}

const git_oid *git_commit_id(const git_commit *obj)
{
	return git_object_id((const git_object *)obj);
}

git_repository *git_commit_owner(const git_commit *obj)
{
	return git_object_owner((const git_object *)obj);
}

int git_commit_dup(git_commit **out, git_commit *obj)
{
	return git_object_dup((git_object **)out, (git_object *)obj);
}

int git_tree_lookup(git_tree **out, git_repository *repo, const git_oid *id)
{
	return git_object_lookup((git_object **)out, repo, id, GIT_OBJECT_TREE);
}

int git_tree_lookup_prefix(git_tree **out, git_repository *repo, const git_oid *id, size_t len)
{
	return git_object_lookup_prefix((git_object **)out, repo, id, len, GIT_OBJECT_TREE);
}

void git_tree_free(git_tree *obj)
{
	git_object_free((git_object *)obj);
}

const git_oid *git_tree_id(const git_tree *obj)
{
	return git_object_id((const git_object *)obj);
}

git_repository *git_tree_owner(const git_tree *obj)
{
	return git_object_owner((const git_object *)obj);
}

int git_tree_dup(git_tree **out, git_tree *obj)
{
	return git_object_dup((git_object **)out, (git_object *)obj);
}

int git_tag_lookup(git_tag **out, git_repository *repo, const git_oid *id)
{
	return git_object_lookup((git_object **)out, repo, id, GIT_OBJECT_TAG);
}

int git_tag_lookup_prefix(git_tag **out, git_repository *repo, const git_oid *id, size_t len)
{
	return git_object_lookup_prefix((git_object **)out, repo, id, len, GIT_OBJECT_TAG);
}

void git_tag_free(git_tag *obj)
{
	git_object_free((git_object *)obj);
}

const git_oid *git_tag_id(const git_tag *obj)
{
	return git_object_id((const git_object *)obj);
}

git_repository *git_tag_owner(const git_tag *obj)
{
	return git_object_owner((const git_object *)obj);
}

int git_tag_dup(git_tag **out, git_tag *obj)
{
	return git_object_dup((git_object **)out, (git_object *)obj);
}

int git_blob_lookup(git_blob **out, git_repository *repo, const git_oid *id)
{
	return git_object_lookup((git_object **)out, repo, id, GIT_OBJECT_BLOB);
}

int git_blob_lookup_prefix(git_blob **out, git_repository *repo, const git_oid *id, size_t len)
{
	return git_object_lookup_prefix((git_object **)out, repo, id, len, GIT_OBJECT_BLOB);
}

void git_blob_free(git_blob *obj)
{
	git_object_free((git_object *)obj);
}

const git_oid *git_blob_id(const git_blob *obj)
{
	return git_object_id((const git_object *)obj);
}

git_repository *git_blob_owner(const git_blob *obj)
{
	return git_object_owner((const git_object *)obj);
}

int git_blob_dup(git_blob **out, git_blob *obj)
{
	return git_object_dup((git_object **)out, (git_object *)obj);
}

