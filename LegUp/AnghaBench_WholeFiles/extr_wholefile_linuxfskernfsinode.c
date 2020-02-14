#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  void* umode_t ;
typedef  size_t u32 ;
struct xattr_handler {int dummy; } ;
struct super_block {int /*<<< orphan*/  s_time_gran; } ;
struct path {struct dentry* dentry; } ;
struct kstat {int dummy; } ;
struct kernfs_root {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  ino; int /*<<< orphan*/  generation; } ;
struct TYPE_6__ {int /*<<< orphan*/  size; } ;
struct TYPE_8__ {scalar_t__ subdirs; struct kernfs_root* root; } ;
struct kernfs_node {int flags; TYPE_3__ id; TYPE_2__ attr; void* mode; TYPE_4__ dir; struct kernfs_iattrs* iattr; struct kernfs_node* parent; } ;
struct iattr {unsigned int ia_valid; int /*<<< orphan*/  ia_ctime; int /*<<< orphan*/  ia_mtime; int /*<<< orphan*/  ia_atime; int /*<<< orphan*/  ia_gid; int /*<<< orphan*/  ia_uid; void* ia_mode; } ;
struct kernfs_iattrs {size_t ia_secdata_len; int /*<<< orphan*/  xattrs; void* ia_secdata; struct iattr ia_iattr; } ;
struct inode {int i_state; struct kernfs_node* i_private; int /*<<< orphan*/  i_data; int /*<<< orphan*/ * i_op; int /*<<< orphan*/ * i_fop; int /*<<< orphan*/  i_size; int /*<<< orphan*/  i_generation; TYPE_1__* i_mapping; void* i_mode; void* i_ctime; void* i_mtime; void* i_atime; int /*<<< orphan*/  i_gid; int /*<<< orphan*/  i_uid; struct super_block* i_sb; } ;
struct dentry {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_5__ {int /*<<< orphan*/ * a_ops; } ;
typedef  int /*<<< orphan*/  DEFINE_MUTEX ;

/* Variables and functions */
 unsigned int ATTR_ATIME ; 
 unsigned int ATTR_CTIME ; 
 unsigned int ATTR_GID ; 
 unsigned int ATTR_MODE ; 
 unsigned int ATTR_MTIME ; 
 unsigned int ATTR_UID ; 
 int /*<<< orphan*/  BUG () ; 
 int ECHILD ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GLOBAL_ROOT_GID ; 
 int /*<<< orphan*/  GLOBAL_ROOT_UID ; 
 int I_NEW ; 
#define  KERNFS_DIR 130 
 int KERNFS_EMPTY_DIR ; 
#define  KERNFS_FILE 129 
#define  KERNFS_LINK 128 
 int MAY_NOT_BLOCK ; 
 int /*<<< orphan*/  clear_inode (struct inode*) ; 
 void* current_time (struct inode*) ; 
 struct inode* d_inode (struct dentry*) ; 
 scalar_t__ d_really_is_negative (struct dentry*) ; 
 int /*<<< orphan*/  generic_fillattr (struct inode*,struct kstat*) ; 
 int generic_permission (struct inode*,int) ; 
 struct inode* iget_locked (struct super_block*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kernfs_aops ; 
 int /*<<< orphan*/  kernfs_dir_fops ; 
 int /*<<< orphan*/  kernfs_dir_iops ; 
 int /*<<< orphan*/  kernfs_file_fops ; 
 int /*<<< orphan*/  kernfs_get (struct kernfs_node*) ; 
 int /*<<< orphan*/  kernfs_iops ; 
 int /*<<< orphan*/  kernfs_mutex ; 
 int /*<<< orphan*/  kernfs_put (struct kernfs_node*) ; 
 int /*<<< orphan*/  kernfs_symlink_iops ; 
 int kernfs_type (struct kernfs_node*) ; 
 int /*<<< orphan*/  ktime_get_real_ts64 (int /*<<< orphan*/ *) ; 
 struct kernfs_iattrs* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  make_empty_dir_inode (struct inode*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int security_inode_getsecctx (struct inode*,void**,size_t*) ; 
 int /*<<< orphan*/  security_inode_notifysecctx (struct inode*,void*,size_t) ; 
 int security_inode_setsecurity (struct inode*,char const*,void const*,size_t,int) ; 
 int /*<<< orphan*/  security_release_secctx (void*,size_t) ; 
 int /*<<< orphan*/  set_nlink (struct inode*,scalar_t__) ; 
 int /*<<< orphan*/  setattr_copy (struct inode*,struct iattr*) ; 
 int setattr_prepare (struct dentry*,struct iattr*) ; 
 int simple_xattr_get (int /*<<< orphan*/ *,char const*,void*,size_t) ; 
 int simple_xattr_list (struct inode*,int /*<<< orphan*/ *,char*,size_t) ; 
 int simple_xattr_set (int /*<<< orphan*/ *,char const*,void const*,size_t,int) ; 
 int /*<<< orphan*/  simple_xattrs_init (int /*<<< orphan*/ *) ; 
 void* timespec64_trunc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  truncate_inode_pages_final (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unlock_new_inode (struct inode*) ; 
 char* xattr_full_name (struct xattr_handler const*,char const*) ; 

__attribute__((used)) static inline struct kernfs_root *kernfs_root(struct kernfs_node *kn)
{
	/* if parent exists, it's always a dir; otherwise, @sd is a dir */
	if (kn->parent)
		kn = kn->parent;
	return kn->dir.root;
}

__attribute__((used)) static inline struct kernfs_node *kernfs_dentry_node(struct dentry *dentry)
{
	if (d_really_is_negative(dentry))
		return NULL;
	return d_inode(dentry)->i_private;
}

__attribute__((used)) static struct kernfs_iattrs *kernfs_iattrs(struct kernfs_node *kn)
{
	static DEFINE_MUTEX(iattr_mutex);
	struct kernfs_iattrs *ret;
	struct iattr *iattrs;

	mutex_lock(&iattr_mutex);

	if (kn->iattr)
		goto out_unlock;

	kn->iattr = kzalloc(sizeof(struct kernfs_iattrs), GFP_KERNEL);
	if (!kn->iattr)
		goto out_unlock;
	iattrs = &kn->iattr->ia_iattr;

	/* assign default attributes */
	iattrs->ia_mode = kn->mode;
	iattrs->ia_uid = GLOBAL_ROOT_UID;
	iattrs->ia_gid = GLOBAL_ROOT_GID;

	ktime_get_real_ts64(&iattrs->ia_atime);
	iattrs->ia_mtime = iattrs->ia_atime;
	iattrs->ia_ctime = iattrs->ia_atime;

	simple_xattrs_init(&kn->iattr->xattrs);
out_unlock:
	ret = kn->iattr;
	mutex_unlock(&iattr_mutex);
	return ret;
}

int __kernfs_setattr(struct kernfs_node *kn, const struct iattr *iattr)
{
	struct kernfs_iattrs *attrs;
	struct iattr *iattrs;
	unsigned int ia_valid = iattr->ia_valid;

	attrs = kernfs_iattrs(kn);
	if (!attrs)
		return -ENOMEM;

	iattrs = &attrs->ia_iattr;

	if (ia_valid & ATTR_UID)
		iattrs->ia_uid = iattr->ia_uid;
	if (ia_valid & ATTR_GID)
		iattrs->ia_gid = iattr->ia_gid;
	if (ia_valid & ATTR_ATIME)
		iattrs->ia_atime = iattr->ia_atime;
	if (ia_valid & ATTR_MTIME)
		iattrs->ia_mtime = iattr->ia_mtime;
	if (ia_valid & ATTR_CTIME)
		iattrs->ia_ctime = iattr->ia_ctime;
	if (ia_valid & ATTR_MODE) {
		umode_t mode = iattr->ia_mode;
		iattrs->ia_mode = kn->mode = mode;
	}
	return 0;
}

int kernfs_setattr(struct kernfs_node *kn, const struct iattr *iattr)
{
	int ret;

	mutex_lock(&kernfs_mutex);
	ret = __kernfs_setattr(kn, iattr);
	mutex_unlock(&kernfs_mutex);
	return ret;
}

int kernfs_iop_setattr(struct dentry *dentry, struct iattr *iattr)
{
	struct inode *inode = d_inode(dentry);
	struct kernfs_node *kn = inode->i_private;
	int error;

	if (!kn)
		return -EINVAL;

	mutex_lock(&kernfs_mutex);
	error = setattr_prepare(dentry, iattr);
	if (error)
		goto out;

	error = __kernfs_setattr(kn, iattr);
	if (error)
		goto out;

	/* this ignores size changes */
	setattr_copy(inode, iattr);

out:
	mutex_unlock(&kernfs_mutex);
	return error;
}

__attribute__((used)) static int kernfs_node_setsecdata(struct kernfs_iattrs *attrs, void **secdata,
				  u32 *secdata_len)
{
	void *old_secdata;
	size_t old_secdata_len;

	old_secdata = attrs->ia_secdata;
	old_secdata_len = attrs->ia_secdata_len;

	attrs->ia_secdata = *secdata;
	attrs->ia_secdata_len = *secdata_len;

	*secdata = old_secdata;
	*secdata_len = old_secdata_len;
	return 0;
}

ssize_t kernfs_iop_listxattr(struct dentry *dentry, char *buf, size_t size)
{
	struct kernfs_node *kn = kernfs_dentry_node(dentry);
	struct kernfs_iattrs *attrs;

	attrs = kernfs_iattrs(kn);
	if (!attrs)
		return -ENOMEM;

	return simple_xattr_list(d_inode(dentry), &attrs->xattrs, buf, size);
}

__attribute__((used)) static inline void set_default_inode_attr(struct inode *inode, umode_t mode)
{
	inode->i_mode = mode;
	inode->i_atime = inode->i_mtime =
		inode->i_ctime = current_time(inode);
}

__attribute__((used)) static inline void set_inode_attr(struct inode *inode, struct iattr *iattr)
{
	struct super_block *sb = inode->i_sb;
	inode->i_uid = iattr->ia_uid;
	inode->i_gid = iattr->ia_gid;
	inode->i_atime = timespec64_trunc(iattr->ia_atime, sb->s_time_gran);
	inode->i_mtime = timespec64_trunc(iattr->ia_mtime, sb->s_time_gran);
	inode->i_ctime = timespec64_trunc(iattr->ia_ctime, sb->s_time_gran);
}

__attribute__((used)) static void kernfs_refresh_inode(struct kernfs_node *kn, struct inode *inode)
{
	struct kernfs_iattrs *attrs = kn->iattr;

	inode->i_mode = kn->mode;
	if (attrs) {
		/*
		 * kernfs_node has non-default attributes get them from
		 * persistent copy in kernfs_node.
		 */
		set_inode_attr(inode, &attrs->ia_iattr);
		security_inode_notifysecctx(inode, attrs->ia_secdata,
					    attrs->ia_secdata_len);
	}

	if (kernfs_type(kn) == KERNFS_DIR)
		set_nlink(inode, kn->dir.subdirs + 2);
}

int kernfs_iop_getattr(const struct path *path, struct kstat *stat,
		       u32 request_mask, unsigned int query_flags)
{
	struct inode *inode = d_inode(path->dentry);
	struct kernfs_node *kn = inode->i_private;

	mutex_lock(&kernfs_mutex);
	kernfs_refresh_inode(kn, inode);
	mutex_unlock(&kernfs_mutex);

	generic_fillattr(inode, stat);
	return 0;
}

__attribute__((used)) static void kernfs_init_inode(struct kernfs_node *kn, struct inode *inode)
{
	kernfs_get(kn);
	inode->i_private = kn;
	inode->i_mapping->a_ops = &kernfs_aops;
	inode->i_op = &kernfs_iops;
	inode->i_generation = kn->id.generation;

	set_default_inode_attr(inode, kn->mode);
	kernfs_refresh_inode(kn, inode);

	/* initialize inode according to type */
	switch (kernfs_type(kn)) {
	case KERNFS_DIR:
		inode->i_op = &kernfs_dir_iops;
		inode->i_fop = &kernfs_dir_fops;
		if (kn->flags & KERNFS_EMPTY_DIR)
			make_empty_dir_inode(inode);
		break;
	case KERNFS_FILE:
		inode->i_size = kn->attr.size;
		inode->i_fop = &kernfs_file_fops;
		break;
	case KERNFS_LINK:
		inode->i_op = &kernfs_symlink_iops;
		break;
	default:
		BUG();
	}

	unlock_new_inode(inode);
}

struct inode *kernfs_get_inode(struct super_block *sb, struct kernfs_node *kn)
{
	struct inode *inode;

	inode = iget_locked(sb, kn->id.ino);
	if (inode && (inode->i_state & I_NEW))
		kernfs_init_inode(kn, inode);

	return inode;
}

void kernfs_evict_inode(struct inode *inode)
{
	struct kernfs_node *kn = inode->i_private;

	truncate_inode_pages_final(&inode->i_data);
	clear_inode(inode);
	kernfs_put(kn);
}

int kernfs_iop_permission(struct inode *inode, int mask)
{
	struct kernfs_node *kn;

	if (mask & MAY_NOT_BLOCK)
		return -ECHILD;

	kn = inode->i_private;

	mutex_lock(&kernfs_mutex);
	kernfs_refresh_inode(kn, inode);
	mutex_unlock(&kernfs_mutex);

	return generic_permission(inode, mask);
}

__attribute__((used)) static int kernfs_xattr_get(const struct xattr_handler *handler,
			    struct dentry *unused, struct inode *inode,
			    const char *suffix, void *value, size_t size)
{
	const char *name = xattr_full_name(handler, suffix);
	struct kernfs_node *kn = inode->i_private;
	struct kernfs_iattrs *attrs;

	attrs = kernfs_iattrs(kn);
	if (!attrs)
		return -ENOMEM;

	return simple_xattr_get(&attrs->xattrs, name, value, size);
}

__attribute__((used)) static int kernfs_xattr_set(const struct xattr_handler *handler,
			    struct dentry *unused, struct inode *inode,
			    const char *suffix, const void *value,
			    size_t size, int flags)
{
	const char *name = xattr_full_name(handler, suffix);
	struct kernfs_node *kn = inode->i_private;
	struct kernfs_iattrs *attrs;

	attrs = kernfs_iattrs(kn);
	if (!attrs)
		return -ENOMEM;

	return simple_xattr_set(&attrs->xattrs, name, value, size, flags);
}

__attribute__((used)) static int kernfs_security_xattr_set(const struct xattr_handler *handler,
				     struct dentry *unused, struct inode *inode,
				     const char *suffix, const void *value,
				     size_t size, int flags)
{
	struct kernfs_node *kn = inode->i_private;
	struct kernfs_iattrs *attrs;
	void *secdata;
	u32 secdata_len = 0;
	int error;

	attrs = kernfs_iattrs(kn);
	if (!attrs)
		return -ENOMEM;

	error = security_inode_setsecurity(inode, suffix, value, size, flags);
	if (error)
		return error;
	error = security_inode_getsecctx(inode, &secdata, &secdata_len);
	if (error)
		return error;

	mutex_lock(&kernfs_mutex);
	error = kernfs_node_setsecdata(attrs, &secdata, &secdata_len);
	mutex_unlock(&kernfs_mutex);

	if (secdata)
		security_release_secctx(secdata, secdata_len);
	return error;
}

