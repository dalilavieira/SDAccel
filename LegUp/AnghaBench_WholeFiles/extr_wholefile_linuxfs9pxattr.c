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
typedef  size_t u64 ;
struct xattr_handler {int dummy; } ;
struct p9_fid {int dummy; } ;
struct kvec {void* iov_base; size_t iov_len; } ;
struct iov_iter {int dummy; } ;
struct inode {int dummy; } ;
struct dentry {struct dentry* d_parent; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ERANGE ; 
 scalar_t__ IS_ERR (struct p9_fid*) ; 
 int ITER_KVEC ; 
 int /*<<< orphan*/  P9_DEBUG_VFS ; 
 int PTR_ERR (struct p9_fid*) ; 
 int READ ; 
 int WRITE ; 
 int /*<<< orphan*/  iov_iter_kvec (struct iov_iter*,int,struct kvec*,int,size_t) ; 
 int /*<<< orphan*/  iov_iter_truncate (struct iov_iter*,size_t) ; 
 int p9_client_clunk (struct p9_fid*) ; 
 int p9_client_read (struct p9_fid*,int /*<<< orphan*/ ,struct iov_iter*,int*) ; 
 struct p9_fid* p9_client_walk (struct p9_fid*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  p9_client_write (struct p9_fid*,int /*<<< orphan*/ ,struct iov_iter*,int*) ; 
 int p9_client_xattrcreate (struct p9_fid*,char const*,size_t,int) ; 
 struct p9_fid* p9_client_xattrwalk (struct p9_fid*,char const*,size_t*) ; 
 int /*<<< orphan*/  p9_debug (int /*<<< orphan*/ ,char*,...) ; 
 struct p9_fid* v9fs_fid_lookup (struct dentry*) ; 
 int v9fs_fid_xattr_set (struct p9_fid*,char const*,void const*,size_t,int) ; 
 char* xattr_full_name (struct xattr_handler const*,char const*) ; 

__attribute__((used)) static inline struct p9_fid *v9fs_parent_fid(struct dentry *dentry)
{
	return v9fs_fid_lookup(dentry->d_parent);
}

__attribute__((used)) static inline struct p9_fid *clone_fid(struct p9_fid *fid)
{
	return IS_ERR(fid) ? fid :  p9_client_walk(fid, 0, NULL, 1);
}

__attribute__((used)) static inline struct p9_fid *v9fs_fid_clone(struct dentry *dentry)
{
	return clone_fid(v9fs_fid_lookup(dentry));
}

ssize_t v9fs_fid_xattr_get(struct p9_fid *fid, const char *name,
			   void *buffer, size_t buffer_size)
{
	ssize_t retval;
	u64 attr_size;
	struct p9_fid *attr_fid;
	struct kvec kvec = {.iov_base = buffer, .iov_len = buffer_size};
	struct iov_iter to;
	int err;

	iov_iter_kvec(&to, READ | ITER_KVEC, &kvec, 1, buffer_size);

	attr_fid = p9_client_xattrwalk(fid, name, &attr_size);
	if (IS_ERR(attr_fid)) {
		retval = PTR_ERR(attr_fid);
		p9_debug(P9_DEBUG_VFS, "p9_client_attrwalk failed %zd\n",
			 retval);
		return retval;
	}
	if (attr_size > buffer_size) {
		if (!buffer_size) /* request to get the attr_size */
			retval = attr_size;
		else
			retval = -ERANGE;
	} else {
		iov_iter_truncate(&to, attr_size);
		retval = p9_client_read(attr_fid, 0, &to, &err);
		if (err)
			retval = err;
	}
	p9_client_clunk(attr_fid);
	return retval;
}

ssize_t v9fs_xattr_get(struct dentry *dentry, const char *name,
		       void *buffer, size_t buffer_size)
{
	struct p9_fid *fid;

	p9_debug(P9_DEBUG_VFS, "name = %s value_len = %zu\n",
		 name, buffer_size);
	fid = v9fs_fid_lookup(dentry);
	if (IS_ERR(fid))
		return PTR_ERR(fid);

	return v9fs_fid_xattr_get(fid, name, buffer, buffer_size);
}

int v9fs_xattr_set(struct dentry *dentry, const char *name,
		   const void *value, size_t value_len, int flags)
{
	struct p9_fid *fid = v9fs_fid_lookup(dentry);
	return v9fs_fid_xattr_set(fid, name, value, value_len, flags);
}

int v9fs_fid_xattr_set(struct p9_fid *fid, const char *name,
		   const void *value, size_t value_len, int flags)
{
	struct kvec kvec = {.iov_base = (void *)value, .iov_len = value_len};
	struct iov_iter from;
	int retval, err;

	iov_iter_kvec(&from, WRITE | ITER_KVEC, &kvec, 1, value_len);

	p9_debug(P9_DEBUG_VFS, "name = %s value_len = %zu flags = %d\n",
		 name, value_len, flags);

	/* Clone it */
	fid = clone_fid(fid);
	if (IS_ERR(fid))
		return PTR_ERR(fid);

	/*
	 * On success fid points to xattr
	 */
	retval = p9_client_xattrcreate(fid, name, value_len, flags);
	if (retval < 0)
		p9_debug(P9_DEBUG_VFS, "p9_client_xattrcreate failed %d\n",
			 retval);
	else
		p9_client_write(fid, 0, &from, &retval);
	err = p9_client_clunk(fid);
	if (!retval && err)
		retval = err;
	return retval;
}

ssize_t v9fs_listxattr(struct dentry *dentry, char *buffer, size_t buffer_size)
{
	return v9fs_xattr_get(dentry, NULL, buffer, buffer_size);
}

__attribute__((used)) static int v9fs_xattr_handler_get(const struct xattr_handler *handler,
				  struct dentry *dentry, struct inode *inode,
				  const char *name, void *buffer, size_t size)
{
	const char *full_name = xattr_full_name(handler, name);

	return v9fs_xattr_get(dentry, full_name, buffer, size);
}

__attribute__((used)) static int v9fs_xattr_handler_set(const struct xattr_handler *handler,
				  struct dentry *dentry, struct inode *inode,
				  const char *name, const void *value,
				  size_t size, int flags)
{
	const char *full_name = xattr_full_name(handler, name);

	return v9fs_xattr_set(dentry, full_name, value, size, flags);
}

