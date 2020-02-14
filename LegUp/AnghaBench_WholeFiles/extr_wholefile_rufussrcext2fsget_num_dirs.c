#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct ext2_inode_large {int dummy; } ;
struct ext2_inode {int dummy; } ;
typedef  int /*<<< orphan*/  mode_t ;
typedef  int ext2_ino_t ;
typedef  TYPE_1__* ext2_filsys ;
typedef  int /*<<< orphan*/  errcode_t ;
typedef  scalar_t__ dgrp_t ;
struct TYPE_11__ {int s_inodes_per_group; int s_inodes_count; } ;
struct TYPE_10__ {scalar_t__ group_desc_count; TYPE_3__* super; } ;

/* Variables and functions */
 int /*<<< orphan*/  EXT2_CHECK_MAGIC (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_EXT2FS_FILSYS ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 int S_ISBLK (int /*<<< orphan*/ ) ; 
 int ext2fs_bg_used_dirs_count (TYPE_1__*,scalar_t__) ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (TYPE_3__*) ; 
 scalar_t__ ext2fs_has_feature_largedir (TYPE_3__*) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (TYPE_3__*) ; 

__attribute__((used)) static inline
struct ext2_inode *EXT2_INODE(struct ext2_inode_large *large_inode)
{
	return (struct ext2_inode *) large_inode;
}

__attribute__((used)) static inline int ext2fs_has_group_desc_csum(ext2_filsys fs)
{
	return ext2fs_has_feature_metadata_csum(fs->super) ||
	       ext2fs_has_feature_gdt_csum(fs->super);
}

__attribute__((used)) static inline int ext2fs_needs_large_file_feature(unsigned long long file_size)
{
	return file_size >= 0x80000000ULL;
}

__attribute__((used)) static inline unsigned int ext2_dir_htree_level(ext2_filsys fs)
{
	if (ext2fs_has_feature_largedir(fs->super))
		return EXT4_HTREE_LEVEL;

	return EXT4_HTREE_LEVEL_COMPAT;
}

__attribute__((used)) static inline int ext2fsP_is_disk_device(mode_t mode)
{
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	return S_ISBLK(mode) || S_ISCHR(mode);
#else
	return S_ISBLK(mode);
#endif
}

errcode_t ext2fs_get_num_dirs(ext2_filsys fs, ext2_ino_t *ret_num_dirs)
{
	dgrp_t	i;
	ext2_ino_t	num_dirs, max_dirs;

	EXT2_CHECK_MAGIC(fs, EXT2_ET_MAGIC_EXT2FS_FILSYS);

	num_dirs = 0;
	max_dirs = fs->super->s_inodes_per_group;
	for (i = 0; i < fs->group_desc_count; i++) {
		if (ext2fs_bg_used_dirs_count(fs, i) > max_dirs)
			num_dirs += max_dirs / 8;
		else
			num_dirs += ext2fs_bg_used_dirs_count(fs, i);
	}
	if (num_dirs > fs->super->s_inodes_count)
		num_dirs = fs->super->s_inodes_count;

	*ret_num_dirs = num_dirs;

	return 0;
}

