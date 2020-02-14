#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct super_block {scalar_t__ s_magic; scalar_t__ s_fs_info; } ;
struct inode {int dummy; } ;
struct file {int f_mode; int /*<<< orphan*/  f_flags; } ;
struct dentry {int d_flags; struct super_block* d_sb; int /*<<< orphan*/  d_lock; scalar_t__ d_fsdata; } ;
struct delayed_call {int dummy; } ;
struct autofs_sb_info {scalar_t__ oz_pgrp; int /*<<< orphan*/  lookup_lock; int /*<<< orphan*/  expiring_list; TYPE_1__* sb; scalar_t__ catatonic; } ;
struct autofs_info {int /*<<< orphan*/  last_used; int /*<<< orphan*/  expiring; } ;
struct TYPE_6__ {char const* i_private; int /*<<< orphan*/  i_ino; } ;
struct TYPE_5__ {int /*<<< orphan*/  i_mode; } ;
struct TYPE_4__ {struct dentry* s_root; int /*<<< orphan*/  s_dev; } ;

/* Variables and functions */
 scalar_t__ AUTOFS_SUPER_MAGIC ; 
 int DCACHE_MANAGE_TRANSIT ; 
 int DCACHE_NEED_AUTOMOUNT ; 
 int /*<<< orphan*/  ECHILD ; 
 int EINVAL ; 
 char const* ERR_PTR (int /*<<< orphan*/ ) ; 
 int FMODE_CAN_WRITE ; 
 int /*<<< orphan*/  O_DIRECT ; 
 int /*<<< orphan*/  S_ISFIFO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  current ; 
 TYPE_3__* d_inode (struct dentry*) ; 
 TYPE_2__* file_inode (struct file*) ; 
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 scalar_t__ list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  new_encode_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ task_pgrp (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct autofs_sb_info *autofs_sbi(struct super_block *sb)
{
	return sb->s_magic != AUTOFS_SUPER_MAGIC ?
		NULL : (struct autofs_sb_info *)(sb->s_fs_info);
}

__attribute__((used)) static inline struct autofs_info *autofs_dentry_ino(struct dentry *dentry)
{
	return (struct autofs_info *)(dentry->d_fsdata);
}

__attribute__((used)) static inline int autofs_oz_mode(struct autofs_sb_info *sbi)
{
	return sbi->catatonic || task_pgrp(current) == sbi->oz_pgrp;
}

__attribute__((used)) static inline void __managed_dentry_set_managed(struct dentry *dentry)
{
	dentry->d_flags |= (DCACHE_NEED_AUTOMOUNT|DCACHE_MANAGE_TRANSIT);
}

__attribute__((used)) static inline void managed_dentry_set_managed(struct dentry *dentry)
{
	spin_lock(&dentry->d_lock);
	__managed_dentry_set_managed(dentry);
	spin_unlock(&dentry->d_lock);
}

__attribute__((used)) static inline void __managed_dentry_clear_managed(struct dentry *dentry)
{
	dentry->d_flags &= ~(DCACHE_NEED_AUTOMOUNT|DCACHE_MANAGE_TRANSIT);
}

__attribute__((used)) static inline void managed_dentry_clear_managed(struct dentry *dentry)
{
	spin_lock(&dentry->d_lock);
	__managed_dentry_clear_managed(dentry);
	spin_unlock(&dentry->d_lock);
}

__attribute__((used)) static inline int autofs_prepare_pipe(struct file *pipe)
{
	if (!(pipe->f_mode & FMODE_CAN_WRITE))
		return -EINVAL;
	if (!S_ISFIFO(file_inode(pipe)->i_mode))
		return -EINVAL;
	/* We want a packet pipe */
	pipe->f_flags |= O_DIRECT;
	return 0;
}

__attribute__((used)) static inline u32 autofs_get_dev(struct autofs_sb_info *sbi)
{
	return new_encode_dev(sbi->sb->s_dev);
}

__attribute__((used)) static inline u64 autofs_get_ino(struct autofs_sb_info *sbi)
{
	return d_inode(sbi->sb->s_root)->i_ino;
}

__attribute__((used)) static inline void __autofs_add_expiring(struct dentry *dentry)
{
	struct autofs_sb_info *sbi = autofs_sbi(dentry->d_sb);
	struct autofs_info *ino = autofs_dentry_ino(dentry);

	if (ino) {
		if (list_empty(&ino->expiring))
			list_add(&ino->expiring, &sbi->expiring_list);
	}
}

__attribute__((used)) static inline void autofs_add_expiring(struct dentry *dentry)
{
	struct autofs_sb_info *sbi = autofs_sbi(dentry->d_sb);
	struct autofs_info *ino = autofs_dentry_ino(dentry);

	if (ino) {
		spin_lock(&sbi->lookup_lock);
		if (list_empty(&ino->expiring))
			list_add(&ino->expiring, &sbi->expiring_list);
		spin_unlock(&sbi->lookup_lock);
	}
}

__attribute__((used)) static inline void autofs_del_expiring(struct dentry *dentry)
{
	struct autofs_sb_info *sbi = autofs_sbi(dentry->d_sb);
	struct autofs_info *ino = autofs_dentry_ino(dentry);

	if (ino) {
		spin_lock(&sbi->lookup_lock);
		if (!list_empty(&ino->expiring))
			list_del_init(&ino->expiring);
		spin_unlock(&sbi->lookup_lock);
	}
}

__attribute__((used)) static const char *autofs_get_link(struct dentry *dentry,
				   struct inode *inode,
				   struct delayed_call *done)
{
	struct autofs_sb_info *sbi;
	struct autofs_info *ino;

	if (!dentry)
		return ERR_PTR(-ECHILD);
	sbi = autofs_sbi(dentry->d_sb);
	ino = autofs_dentry_ino(dentry);
	if (ino && !autofs_oz_mode(sbi))
		ino->last_used = jiffies;
	return d_inode(dentry)->i_private;
}

