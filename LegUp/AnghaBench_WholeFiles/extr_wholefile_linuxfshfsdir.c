#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_9__ ;
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/  FlNum; } ;
struct TYPE_10__ {int /*<<< orphan*/  DirID; } ;
struct TYPE_12__ {int /*<<< orphan*/  ParID; } ;
union hfs_cat_rec {scalar_t__ type; TYPE_2__ file; TYPE_1__ dir; TYPE_3__ thread; } ;
typedef  int umode_t ;
typedef  scalar_t__ u16 ;
struct super_block {char const* s_id; } ;
struct inode {scalar_t__ i_ino; scalar_t__ i_size; int /*<<< orphan*/  d_name; struct super_block* i_sb; int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mode; } ;
struct hfs_readdir_data {int /*<<< orphan*/  list; int /*<<< orphan*/  key; struct file* file; } ;
struct hfs_find_data {int entrylength; TYPE_4__* key; int /*<<< orphan*/  entryoffset; int /*<<< orphan*/  bnode; TYPE_5__* search_key; } ;
struct hfs_cat_key {int dummy; } ;
struct hfs_cat_file {int dummy; } ;
struct hfs_cat_dir {int dummy; } ;
struct file {struct hfs_readdir_data* private_data; } ;
struct dir_context {scalar_t__ pos; } ;
struct dentry {scalar_t__ i_ino; scalar_t__ i_size; int /*<<< orphan*/  d_name; struct super_block* i_sb; int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mode; } ;
typedef  int /*<<< orphan*/  rec ;
typedef  int /*<<< orphan*/  hfs_cat_rec ;
typedef  int /*<<< orphan*/  entry ;
struct TYPE_14__ {int /*<<< orphan*/  cat; } ;
typedef  TYPE_5__ btree_key ;
struct TYPE_17__ {int /*<<< orphan*/  cat_key; int /*<<< orphan*/  open_dir_lock; int /*<<< orphan*/  open_dir_list; } ;
struct TYPE_16__ {int /*<<< orphan*/  cat_tree; int /*<<< orphan*/  flags; } ;
struct TYPE_15__ {int /*<<< orphan*/  CName; int /*<<< orphan*/  ParID; } ;
struct TYPE_13__ {TYPE_6__ cat; } ;

/* Variables and functions */
 int /*<<< orphan*/  DT_DIR ; 
 int /*<<< orphan*/  DT_REG ; 
 int EACCES ; 
 int EINVAL ; 
 int EIO ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOTEMPTY ; 
 struct inode* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HFS_CDR_DIR ; 
 scalar_t__ HFS_CDR_FIL ; 
 scalar_t__ HFS_CDR_THD ; 
 int /*<<< orphan*/  HFS_FLG_BITMAP_DIRTY ; 
 TYPE_9__* HFS_I (struct inode*) ; 
 int HFS_MAX_NAMELEN ; 
 TYPE_8__* HFS_SB (struct super_block*) ; 
 unsigned int RENAME_NOREPLACE ; 
 int S_IFDIR ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_nlink (struct inode*) ; 
 int /*<<< orphan*/  current_time (struct inode*) ; 
 struct inode* d_inode (struct inode*) ; 
 int /*<<< orphan*/  d_instantiate (struct inode*,struct inode*) ; 
 scalar_t__ d_really_is_positive (struct inode*) ; 
 struct inode* d_splice_alias (struct inode*,struct inode*) ; 
 int /*<<< orphan*/  dir_emit (struct dir_context*,char*,int,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dir_emit_dot (struct file*,struct dir_context*) ; 
 struct inode* file_inode (struct file*) ; 
 int /*<<< orphan*/  hfs_bnode_read (int /*<<< orphan*/ ,union hfs_cat_rec*,int /*<<< orphan*/ ,int) ; 
 int hfs_brec_find (struct hfs_find_data*) ; 
 int hfs_brec_goto (struct hfs_find_data*,int) ; 
 int hfs_brec_read (struct hfs_find_data*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  hfs_cat_build_key (struct super_block*,TYPE_5__*,scalar_t__,int /*<<< orphan*/ *) ; 
 int hfs_cat_create (scalar_t__,struct inode*,int /*<<< orphan*/ *,struct inode*) ; 
 int hfs_cat_delete (scalar_t__,struct inode*,int /*<<< orphan*/ *) ; 
 int hfs_cat_move (scalar_t__,struct inode*,int /*<<< orphan*/ *,struct inode*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hfs_delete_inode (struct inode*) ; 
 int /*<<< orphan*/  hfs_find_exit (struct hfs_find_data*) ; 
 int hfs_find_init (int /*<<< orphan*/ ,struct hfs_find_data*) ; 
 struct inode* hfs_iget (struct super_block*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int hfs_mac2asc (struct super_block*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hfs_mark_mdb_dirty (struct super_block*) ; 
 struct inode* hfs_new_inode (struct inode*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 
 int /*<<< orphan*/  kfree (struct hfs_readdir_data*) ; 
 struct hfs_readdir_data* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mark_inode_dirty (struct inode*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,TYPE_6__*,int) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline const char *hfs_mdb_name(struct super_block *sb)
{
	return sb->s_id;
}

__attribute__((used)) static inline void hfs_bitmap_dirty(struct super_block *sb)
{
	set_bit(HFS_FLG_BITMAP_DIRTY, &HFS_SB(sb)->flags);
	hfs_mark_mdb_dirty(sb);
}

__attribute__((used)) static struct dentry *hfs_lookup(struct inode *dir, struct dentry *dentry,
				 unsigned int flags)
{
	hfs_cat_rec rec;
	struct hfs_find_data fd;
	struct inode *inode = NULL;
	int res;

	res = hfs_find_init(HFS_SB(dir->i_sb)->cat_tree, &fd);
	if (res)
		return ERR_PTR(res);
	hfs_cat_build_key(dir->i_sb, fd.search_key, dir->i_ino, &dentry->d_name);
	res = hfs_brec_read(&fd, &rec, sizeof(rec));
	if (res) {
		if (res != -ENOENT)
			inode = ERR_PTR(res);
	} else {
		inode = hfs_iget(dir->i_sb, &fd.search_key->cat, &rec);
		if (!inode)
			inode = ERR_PTR(-EACCES);
	}
	hfs_find_exit(&fd);
	return d_splice_alias(inode, dentry);
}

__attribute__((used)) static int hfs_readdir(struct file *file, struct dir_context *ctx)
{
	struct inode *inode = file_inode(file);
	struct super_block *sb = inode->i_sb;
	int len, err;
	char strbuf[HFS_MAX_NAMELEN];
	union hfs_cat_rec entry;
	struct hfs_find_data fd;
	struct hfs_readdir_data *rd;
	u16 type;

	if (ctx->pos >= inode->i_size)
		return 0;

	err = hfs_find_init(HFS_SB(sb)->cat_tree, &fd);
	if (err)
		return err;
	hfs_cat_build_key(sb, fd.search_key, inode->i_ino, NULL);
	err = hfs_brec_find(&fd);
	if (err)
		goto out;

	if (ctx->pos == 0) {
		/* This is completely artificial... */
		if (!dir_emit_dot(file, ctx))
			goto out;
		ctx->pos = 1;
	}
	if (ctx->pos == 1) {
		if (fd.entrylength > sizeof(entry) || fd.entrylength < 0) {
			err = -EIO;
			goto out;
		}

		hfs_bnode_read(fd.bnode, &entry, fd.entryoffset, fd.entrylength);
		if (entry.type != HFS_CDR_THD) {
			pr_err("bad catalog folder thread\n");
			err = -EIO;
			goto out;
		}
		//if (fd.entrylength < HFS_MIN_THREAD_SZ) {
		//	pr_err("truncated catalog thread\n");
		//	err = -EIO;
		//	goto out;
		//}
		if (!dir_emit(ctx, "..", 2,
			    be32_to_cpu(entry.thread.ParID), DT_DIR))
			goto out;
		ctx->pos = 2;
	}
	if (ctx->pos >= inode->i_size)
		goto out;
	err = hfs_brec_goto(&fd, ctx->pos - 1);
	if (err)
		goto out;

	for (;;) {
		if (be32_to_cpu(fd.key->cat.ParID) != inode->i_ino) {
			pr_err("walked past end of dir\n");
			err = -EIO;
			goto out;
		}

		if (fd.entrylength > sizeof(entry) || fd.entrylength < 0) {
			err = -EIO;
			goto out;
		}

		hfs_bnode_read(fd.bnode, &entry, fd.entryoffset, fd.entrylength);
		type = entry.type;
		len = hfs_mac2asc(sb, strbuf, &fd.key->cat.CName);
		if (type == HFS_CDR_DIR) {
			if (fd.entrylength < sizeof(struct hfs_cat_dir)) {
				pr_err("small dir entry\n");
				err = -EIO;
				goto out;
			}
			if (!dir_emit(ctx, strbuf, len,
				    be32_to_cpu(entry.dir.DirID), DT_DIR))
				break;
		} else if (type == HFS_CDR_FIL) {
			if (fd.entrylength < sizeof(struct hfs_cat_file)) {
				pr_err("small file entry\n");
				err = -EIO;
				goto out;
			}
			if (!dir_emit(ctx, strbuf, len,
				    be32_to_cpu(entry.file.FlNum), DT_REG))
				break;
		} else {
			pr_err("bad catalog entry type %d\n", type);
			err = -EIO;
			goto out;
		}
		ctx->pos++;
		if (ctx->pos >= inode->i_size)
			goto out;
		err = hfs_brec_goto(&fd, 1);
		if (err)
			goto out;
	}
	rd = file->private_data;
	if (!rd) {
		rd = kmalloc(sizeof(struct hfs_readdir_data), GFP_KERNEL);
		if (!rd) {
			err = -ENOMEM;
			goto out;
		}
		file->private_data = rd;
		rd->file = file;
		spin_lock(&HFS_I(inode)->open_dir_lock);
		list_add(&rd->list, &HFS_I(inode)->open_dir_list);
		spin_unlock(&HFS_I(inode)->open_dir_lock);
	}
	/*
	 * Can be done after the list insertion; exclusion with
	 * hfs_delete_cat() is provided by directory lock.
	 */
	memcpy(&rd->key, &fd.key->cat, sizeof(struct hfs_cat_key));
out:
	hfs_find_exit(&fd);
	return err;
}

__attribute__((used)) static int hfs_dir_release(struct inode *inode, struct file *file)
{
	struct hfs_readdir_data *rd = file->private_data;
	if (rd) {
		spin_lock(&HFS_I(inode)->open_dir_lock);
		list_del(&rd->list);
		spin_unlock(&HFS_I(inode)->open_dir_lock);
		kfree(rd);
	}
	return 0;
}

__attribute__((used)) static int hfs_create(struct inode *dir, struct dentry *dentry, umode_t mode,
		      bool excl)
{
	struct inode *inode;
	int res;

	inode = hfs_new_inode(dir, &dentry->d_name, mode);
	if (!inode)
		return -ENOMEM;

	res = hfs_cat_create(inode->i_ino, dir, &dentry->d_name, inode);
	if (res) {
		clear_nlink(inode);
		hfs_delete_inode(inode);
		iput(inode);
		return res;
	}
	d_instantiate(dentry, inode);
	mark_inode_dirty(inode);
	return 0;
}

__attribute__((used)) static int hfs_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode)
{
	struct inode *inode;
	int res;

	inode = hfs_new_inode(dir, &dentry->d_name, S_IFDIR | mode);
	if (!inode)
		return -ENOMEM;

	res = hfs_cat_create(inode->i_ino, dir, &dentry->d_name, inode);
	if (res) {
		clear_nlink(inode);
		hfs_delete_inode(inode);
		iput(inode);
		return res;
	}
	d_instantiate(dentry, inode);
	mark_inode_dirty(inode);
	return 0;
}

__attribute__((used)) static int hfs_remove(struct inode *dir, struct dentry *dentry)
{
	struct inode *inode = d_inode(dentry);
	int res;

	if (S_ISDIR(inode->i_mode) && inode->i_size != 2)
		return -ENOTEMPTY;
	res = hfs_cat_delete(inode->i_ino, dir, &dentry->d_name);
	if (res)
		return res;
	clear_nlink(inode);
	inode->i_ctime = current_time(inode);
	hfs_delete_inode(inode);
	mark_inode_dirty(inode);
	return 0;
}

__attribute__((used)) static int hfs_rename(struct inode *old_dir, struct dentry *old_dentry,
		      struct inode *new_dir, struct dentry *new_dentry,
		      unsigned int flags)
{
	int res;

	if (flags & ~RENAME_NOREPLACE)
		return -EINVAL;

	/* Unlink destination if it already exists */
	if (d_really_is_positive(new_dentry)) {
		res = hfs_remove(new_dir, new_dentry);
		if (res)
			return res;
	}

	res = hfs_cat_move(d_inode(old_dentry)->i_ino,
			   old_dir, &old_dentry->d_name,
			   new_dir, &new_dentry->d_name);
	if (!res)
		hfs_cat_build_key(old_dir->i_sb,
				  (btree_key *)&HFS_I(d_inode(old_dentry))->cat_key,
				  new_dir->i_ino, &new_dentry->d_name);
	return res;
}

