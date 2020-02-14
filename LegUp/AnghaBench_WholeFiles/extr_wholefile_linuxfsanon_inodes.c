#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct file_system_type {int dummy; } ;
struct file_operations {scalar_t__ owner; } ;
struct file {void* private_data; int /*<<< orphan*/  i_mapping; int /*<<< orphan*/  f_mapping; } ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;
struct dentry {TYPE_1__ d_name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ANON_INODE_FS_MAGIC ; 
 int /*<<< orphan*/  ENODEV ; 
 int /*<<< orphan*/  ENOENT ; 
 struct file* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct file*) ; 
 int O_ACCMODE ; 
 int O_NONBLOCK ; 
 int PTR_ERR (struct file*) ; 
 struct file* alloc_file_pseudo (struct file*,int /*<<< orphan*/ ,char const*,int,struct file_operations const*) ; 
 struct file* anon_inode_inode ; 
 int /*<<< orphan*/  anon_inode_mnt ; 
 int /*<<< orphan*/  anon_inodefs_dentry_operations ; 
 char* dynamic_dname (struct dentry*,char*,int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fd_install (int,struct file*) ; 
 int get_unused_fd_flags (int) ; 
 int /*<<< orphan*/  ihold (struct file*) ; 
 int /*<<< orphan*/  iput (struct file*) ; 
 int /*<<< orphan*/  module_put (scalar_t__) ; 
 struct dentry* mount_pseudo (struct file_system_type*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_unused_fd (int) ; 
 int /*<<< orphan*/  try_module_get (scalar_t__) ; 

__attribute__((used)) static char *anon_inodefs_dname(struct dentry *dentry, char *buffer, int buflen)
{
	return dynamic_dname(dentry, buffer, buflen, "anon_inode:%s",
				dentry->d_name.name);
}

__attribute__((used)) static struct dentry *anon_inodefs_mount(struct file_system_type *fs_type,
				int flags, const char *dev_name, void *data)
{
	return mount_pseudo(fs_type, "anon_inode:", NULL,
			&anon_inodefs_dentry_operations, ANON_INODE_FS_MAGIC);
}

struct file *anon_inode_getfile(const char *name,
				const struct file_operations *fops,
				void *priv, int flags)
{
	struct file *file;

	if (IS_ERR(anon_inode_inode))
		return ERR_PTR(-ENODEV);

	if (fops->owner && !try_module_get(fops->owner))
		return ERR_PTR(-ENOENT);

	/*
	 * We know the anon_inode inode count is always greater than zero,
	 * so ihold() is safe.
	 */
	ihold(anon_inode_inode);
	file = alloc_file_pseudo(anon_inode_inode, anon_inode_mnt, name,
				 flags & (O_ACCMODE | O_NONBLOCK), fops);
	if (IS_ERR(file))
		goto err;

	file->f_mapping = anon_inode_inode->i_mapping;

	file->private_data = priv;

	return file;

err:
	iput(anon_inode_inode);
	module_put(fops->owner);
	return file;
}

int anon_inode_getfd(const char *name, const struct file_operations *fops,
		     void *priv, int flags)
{
	int error, fd;
	struct file *file;

	error = get_unused_fd_flags(flags);
	if (error < 0)
		return error;
	fd = error;

	file = anon_inode_getfile(name, fops, priv, flags);
	if (IS_ERR(file)) {
		error = PTR_ERR(file);
		goto err_put_unused_fd;
	}
	fd_install(fd, file);

	return fd;

err_put_unused_fd:
	put_unused_fd(fd);
	return error;
}

