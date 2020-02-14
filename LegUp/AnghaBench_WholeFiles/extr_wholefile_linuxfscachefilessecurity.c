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
struct dentry {int dummy; } ;
struct cred {int dummy; } ;
struct cachefiles_cache {struct cred* cache_cred; int /*<<< orphan*/  secctx; int /*<<< orphan*/  daemon_pollwq; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  CACHEFILES_STATE_CHANGED ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  _enter (char*,...) ; 
 int /*<<< orphan*/  _leave (char*,int) ; 
 int /*<<< orphan*/  abort_creds (struct cred*) ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  d_backing_inode (struct dentry*) ; 
 struct cred* override_creds (struct cred*) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 struct cred* prepare_creds () ; 
 struct cred* prepare_kernel_cred (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_cred (struct cred*) ; 
 int /*<<< orphan*/  revert_creds (struct cred const*) ; 
 int security_inode_create (int /*<<< orphan*/ ,struct dentry*,int /*<<< orphan*/ ) ; 
 int security_inode_mkdir (int /*<<< orphan*/ ,struct dentry*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int set_create_files_as (struct cred*,int /*<<< orphan*/ ) ; 
 int set_security_override_from_ctx (struct cred*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up_all (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void cachefiles_state_changed(struct cachefiles_cache *cache)
{
	set_bit(CACHEFILES_STATE_CHANGED, &cache->flags);
	wake_up_all(&cache->daemon_pollwq);
}

__attribute__((used)) static inline void cachefiles_begin_secure(struct cachefiles_cache *cache,
					   const struct cred **_saved_cred)
{
	*_saved_cred = override_creds(cache->cache_cred);
}

__attribute__((used)) static inline void cachefiles_end_secure(struct cachefiles_cache *cache,
					 const struct cred *saved_cred)
{
	revert_creds(saved_cred);
}

int cachefiles_get_security_ID(struct cachefiles_cache *cache)
{
	struct cred *new;
	int ret;

	_enter("{%s}", cache->secctx);

	new = prepare_kernel_cred(current);
	if (!new) {
		ret = -ENOMEM;
		goto error;
	}

	if (cache->secctx) {
		ret = set_security_override_from_ctx(new, cache->secctx);
		if (ret < 0) {
			put_cred(new);
			pr_err("Security denies permission to nominate security context: error %d\n",
			       ret);
			goto error;
		}
	}

	cache->cache_cred = new;
	ret = 0;
error:
	_leave(" = %d", ret);
	return ret;
}

__attribute__((used)) static int cachefiles_check_cache_dir(struct cachefiles_cache *cache,
				      struct dentry *root)
{
	int ret;

	ret = security_inode_mkdir(d_backing_inode(root), root, 0);
	if (ret < 0) {
		pr_err("Security denies permission to make dirs: error %d",
		       ret);
		return ret;
	}

	ret = security_inode_create(d_backing_inode(root), root, 0);
	if (ret < 0)
		pr_err("Security denies permission to create files: error %d",
		       ret);

	return ret;
}

int cachefiles_determine_cache_security(struct cachefiles_cache *cache,
					struct dentry *root,
					const struct cred **_saved_cred)
{
	struct cred *new;
	int ret;

	_enter("");

	/* duplicate the cache creds for COW (the override is currently in
	 * force, so we can use prepare_creds() to do this) */
	new = prepare_creds();
	if (!new)
		return -ENOMEM;

	cachefiles_end_secure(cache, *_saved_cred);

	/* use the cache root dir's security context as the basis with
	 * which create files */
	ret = set_create_files_as(new, d_backing_inode(root));
	if (ret < 0) {
		abort_creds(new);
		cachefiles_begin_secure(cache, _saved_cred);
		_leave(" = %d [cfa]", ret);
		return ret;
	}

	put_cred(cache->cache_cred);
	cache->cache_cred = new;

	cachefiles_begin_secure(cache, _saved_cred);
	ret = cachefiles_check_cache_dir(cache, root);

	if (ret == -EOPNOTSUPP)
		ret = 0;
	_leave(" = %d", ret);
	return ret;
}

