#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_44__   TYPE_3__ ;
typedef  struct TYPE_43__   TYPE_2__ ;
typedef  struct TYPE_42__   TYPE_1__ ;

/* Type definitions */
struct opaque_ext2_group_desc {int dummy; } ;
struct ext4_group_desc {int bg_block_bitmap_csum_lo; int bg_block_bitmap; int bg_block_bitmap_hi; int bg_inode_bitmap_csum_lo; int bg_inode_bitmap; int bg_inode_bitmap_hi; int bg_inode_table; int bg_inode_table_hi; int bg_free_blocks_count; int bg_free_blocks_count_hi; int bg_free_inodes_count; int bg_free_inodes_count_hi; int bg_used_dirs_count; int bg_used_dirs_count_hi; int bg_itable_unused; int bg_itable_unused_hi; int bg_flags; int bg_checksum; scalar_t__ bg_inode_bitmap_csum_hi; scalar_t__ bg_block_bitmap_csum_hi; } ;
struct ext2_super_block {int s_first_data_block; int s_blocks_per_group; int s_blocks_count; int s_blocks_count_hi; int s_r_blocks_count; int s_r_blocks_count_hi; int s_free_blocks_count; int s_free_blocks_hi; scalar_t__ s_rev_level; } ;
struct TYPE_42__ {int l_i_file_acl_high; scalar_t__ l_i_blocks_hi; } ;
struct TYPE_43__ {TYPE_1__ linux2; } ;
struct ext2_inode {int i_blocks; int i_file_acl; int i_size; int i_size_high; int /*<<< orphan*/  i_mode; TYPE_2__ osd2; } ;
struct ext2_group_desc {int dummy; } ;
typedef  int ext2_off64_t ;
typedef  TYPE_3__* ext2_filsys ;
typedef  int /*<<< orphan*/  errcode_t ;
typedef  int dgrp_t ;
typedef  int blk64_t ;
typedef  int __u64 ;
typedef  int __u32 ;
typedef  int __u16 ;
struct TYPE_44__ {int group_desc_count; struct ext2_super_block* super; struct opaque_ext2_group_desc* group_desc; } ;

/* Variables and functions */
 int EXT2_CLUSTER_SIZE (struct ext2_super_block*) ; 
 scalar_t__ EXT2_DESC_SIZE (struct ext2_super_block*) ; 
 int /*<<< orphan*/  EXT2_ET_FILE_TOO_BIG ; 
 scalar_t__ EXT2_GOOD_OLD_REV ; 
 int EXT2_GROUPS_TO_BLOCKS (struct ext2_super_block*,int) ; 
 scalar_t__ EXT4_BG_BLOCK_BITMAP_CSUM_HI_LOCATION ; 
 scalar_t__ EXT4_BG_INODE_BITMAP_CSUM_HI_END ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 scalar_t__ LINUX_S_ISREG (int /*<<< orphan*/ ) ; 
 int ext2fs_blocks_count (struct ext2_super_block*) ; 
 scalar_t__ ext2fs_has_feature_64bit (struct ext2_super_block*) ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (struct ext2_super_block*) ; 
 scalar_t__ ext2fs_has_feature_huge_file (struct ext2_super_block*) ; 
 int /*<<< orphan*/  ext2fs_has_feature_large_file (struct ext2_super_block*) ; 
 scalar_t__ ext2fs_has_feature_largedir (struct ext2_super_block*) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (struct ext2_super_block*) ; 
 int /*<<< orphan*/  ext2fs_mark_super_dirty (TYPE_3__*) ; 
 int /*<<< orphan*/  ext2fs_set_feature_large_file (struct ext2_super_block*) ; 
 int /*<<< orphan*/  ext2fs_update_dynamic_rev (TYPE_3__*) ; 

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

dgrp_t ext2fs_group_of_blk2(ext2_filsys fs, blk64_t blk)
{
	return (blk - fs->super->s_first_data_block) /
		fs->super->s_blocks_per_group;
}

blk64_t ext2fs_group_first_block2(ext2_filsys fs, dgrp_t group)
{
	return fs->super->s_first_data_block +
		EXT2_GROUPS_TO_BLOCKS(fs->super, group);
}

blk64_t ext2fs_group_last_block2(ext2_filsys fs, dgrp_t group)
{
	return (group == fs->group_desc_count - 1 ?
		ext2fs_blocks_count(fs->super) - 1 :
		ext2fs_group_first_block2(fs, group) +
			(fs->super->s_blocks_per_group - 1));
}

int ext2fs_group_blocks_count(ext2_filsys fs, dgrp_t group)
{
	int num_blocks;

	if (group == fs->group_desc_count - 1) {
		num_blocks = (ext2fs_blocks_count(fs->super) -
				fs->super->s_first_data_block) %
			      fs->super->s_blocks_per_group;
		if (!num_blocks)
			num_blocks = fs->super->s_blocks_per_group;
	} else
		num_blocks = fs->super->s_blocks_per_group;

	return num_blocks;
}

blk64_t ext2fs_inode_data_blocks2(ext2_filsys fs,
					struct ext2_inode *inode)
{
	return (inode->i_blocks |
		(ext2fs_has_feature_huge_file(fs->super) ?
		 (__u64) inode->osd2.linux2.l_i_blocks_hi << 32 : 0)) -
		(inode->i_file_acl ? EXT2_CLUSTER_SIZE(fs->super) >> 9 : 0);
}

blk64_t ext2fs_inode_i_blocks(ext2_filsys fs,
					struct ext2_inode *inode)
{
	return (inode->i_blocks |
		(ext2fs_has_feature_huge_file(fs->super) ?
		 (__u64)inode->osd2.linux2.l_i_blocks_hi << 32 : 0));
}

blk64_t ext2fs_blocks_count(struct ext2_super_block *super)
{
	return super->s_blocks_count |
		(ext2fs_has_feature_64bit(super) ?
		(__u64) super->s_blocks_count_hi << 32 : 0);
}

void ext2fs_blocks_count_set(struct ext2_super_block *super, blk64_t blk)
{
	super->s_blocks_count = blk;
	if (ext2fs_has_feature_64bit(super))
		super->s_blocks_count_hi = (__u64) blk >> 32;
}

void ext2fs_blocks_count_add(struct ext2_super_block *super, blk64_t blk)
{
	blk64_t tmp;
	tmp = ext2fs_blocks_count(super) + blk;
	ext2fs_blocks_count_set(super, tmp);
}

blk64_t ext2fs_r_blocks_count(struct ext2_super_block *super)
{
	return super->s_r_blocks_count |
		(ext2fs_has_feature_64bit(super) ?
		(__u64) super->s_r_blocks_count_hi << 32 : 0);
}

void ext2fs_r_blocks_count_set(struct ext2_super_block *super, blk64_t blk)
{
	super->s_r_blocks_count = blk;
	if (ext2fs_has_feature_64bit(super))
		super->s_r_blocks_count_hi = (__u64) blk >> 32;
}

void ext2fs_r_blocks_count_add(struct ext2_super_block *super, blk64_t blk)
{
	blk64_t tmp;
	tmp = ext2fs_r_blocks_count(super) + blk;
	ext2fs_r_blocks_count_set(super, tmp);
}

blk64_t ext2fs_free_blocks_count(struct ext2_super_block *super)
{
	return super->s_free_blocks_count |
		(ext2fs_has_feature_64bit(super) ?
		(__u64) super->s_free_blocks_hi << 32 : 0);
}

void ext2fs_free_blocks_count_set(struct ext2_super_block *super, blk64_t blk)
{
	super->s_free_blocks_count = blk;
	if (ext2fs_has_feature_64bit(super))
		super->s_free_blocks_hi = (__u64) blk >> 32;
}

void ext2fs_free_blocks_count_add(struct ext2_super_block *super, blk64_t blk)
{
	blk64_t tmp;
	tmp = ext2fs_free_blocks_count(super) + blk;
	ext2fs_free_blocks_count_set(super, tmp);
}

struct ext2_group_desc *ext2fs_group_desc(ext2_filsys fs,
					  struct opaque_ext2_group_desc *gdp,
					  dgrp_t group)
{
	int desc_size = EXT2_DESC_SIZE(fs->super) & ~7;

	return (struct ext2_group_desc *)((char *)gdp + group * desc_size);
}

__attribute__((used)) static struct ext4_group_desc *ext4fs_group_desc(ext2_filsys fs,
					  struct opaque_ext2_group_desc *gdp,
					  dgrp_t group)
{
	return (struct ext4_group_desc *)ext2fs_group_desc(fs, gdp, group);
}

__u32 ext2fs_block_bitmap_checksum(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;
	__u32 csum;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	csum = gdp->bg_block_bitmap_csum_lo;
	if (EXT2_DESC_SIZE(fs->super) >= EXT4_BG_BLOCK_BITMAP_CSUM_HI_LOCATION)
		csum |= ((__u32)gdp->bg_block_bitmap_csum_hi << 16);
	return csum;
}

blk64_t ext2fs_block_bitmap_loc(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_block_bitmap |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u64)gdp->bg_block_bitmap_hi << 32 : 0);
}

void ext2fs_block_bitmap_loc_set(ext2_filsys fs, dgrp_t group, blk64_t blk)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_block_bitmap = blk;
	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_block_bitmap_hi = (__u64) blk >> 32;
}

__u32 ext2fs_inode_bitmap_checksum(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;
	__u32 csum;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	csum = gdp->bg_inode_bitmap_csum_lo;
	if (EXT2_DESC_SIZE(fs->super) >= EXT4_BG_INODE_BITMAP_CSUM_HI_END)
		csum |= ((__u32)gdp->bg_inode_bitmap_csum_hi << 16);
	return csum;
}

blk64_t ext2fs_inode_bitmap_loc(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_inode_bitmap |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u64) gdp->bg_inode_bitmap_hi << 32 : 0);
}

void ext2fs_inode_bitmap_loc_set(ext2_filsys fs, dgrp_t group, blk64_t blk)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_inode_bitmap = blk;
	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_inode_bitmap_hi = (__u64) blk >> 32;
}

blk64_t ext2fs_inode_table_loc(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_inode_table |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u64) gdp->bg_inode_table_hi << 32 : 0);
}

void ext2fs_inode_table_loc_set(ext2_filsys fs, dgrp_t group, blk64_t blk)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_inode_table = blk;
	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_inode_table_hi = (__u64) blk >> 32;
}

__u32 ext2fs_bg_free_blocks_count(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_free_blocks_count |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u32) gdp->bg_free_blocks_count_hi << 16 : 0);
}

void ext2fs_bg_free_blocks_count_set(ext2_filsys fs, dgrp_t group, __u32 n)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_free_blocks_count = n;

	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_free_blocks_count_hi = (__u32) n >> 16;
}

__u32 ext2fs_bg_free_inodes_count(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_free_inodes_count |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u32) gdp->bg_free_inodes_count_hi << 16 : 0);
}

void ext2fs_bg_free_inodes_count_set(ext2_filsys fs, dgrp_t group, __u32 n)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_free_inodes_count = n;
	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_free_inodes_count_hi = (__u32) n >> 16;
}

__u32 ext2fs_bg_used_dirs_count(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_used_dirs_count |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u32) gdp->bg_used_dirs_count_hi << 16 : 0);
}

void ext2fs_bg_used_dirs_count_set(ext2_filsys fs, dgrp_t group, __u32 n)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_used_dirs_count = n;
	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_used_dirs_count_hi = (__u32) n >> 16;
}

__u32 ext2fs_bg_itable_unused(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_itable_unused |
		(ext2fs_has_feature_64bit(fs->super) ?
		 (__u32) gdp->bg_itable_unused_hi << 16 : 0);
}

void ext2fs_bg_itable_unused_set(ext2_filsys fs, dgrp_t group, __u32 n)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_itable_unused = n;
	if (ext2fs_has_feature_64bit(fs->super))
		gdp->bg_itable_unused_hi = (__u32) n >> 16;
}

__u16 ext2fs_bg_flags(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_flags;
}

void ext2fs_bg_flags_zap(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_flags = 0;
	return;
}

int ext2fs_bg_flags_test(ext2_filsys fs, dgrp_t group, __u16 bg_flag)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_flags & bg_flag;
}

void ext2fs_bg_flags_set(ext2_filsys fs, dgrp_t group, __u16 bg_flags)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_flags |= bg_flags;
	return;
}

void ext2fs_bg_flags_clear(ext2_filsys fs, dgrp_t group, __u16 bg_flags)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_flags &= ~bg_flags;
	return;
}

__u16 ext2fs_bg_checksum(ext2_filsys fs, dgrp_t group)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	return gdp->bg_checksum;
}

void ext2fs_bg_checksum_set(ext2_filsys fs, dgrp_t group, __u16 checksum)
{
	struct ext4_group_desc *gdp;

	gdp = ext4fs_group_desc(fs, fs->group_desc, group);
	gdp->bg_checksum = checksum;
	return;
}

blk64_t ext2fs_file_acl_block(ext2_filsys fs, const struct ext2_inode *inode)
{
	blk64_t	blk = inode->i_file_acl;

	if (fs && ext2fs_has_feature_64bit(fs->super))
		blk |= ((__u64) inode->osd2.linux2.l_i_file_acl_high) << 32;
	return blk;
}

void ext2fs_file_acl_block_set(ext2_filsys fs, struct ext2_inode *inode,
			       blk64_t blk)
{
	inode->i_file_acl = blk;
	if (fs && ext2fs_has_feature_64bit(fs->super))
		inode->osd2.linux2.l_i_file_acl_high = (__u64) blk >> 32;
}

errcode_t ext2fs_inode_size_set(ext2_filsys fs, struct ext2_inode *inode,
				ext2_off64_t size)
{
	/* Only regular files get to be larger than 4GB */
	if (!LINUX_S_ISREG(inode->i_mode) && (size >> 32))
		return EXT2_ET_FILE_TOO_BIG;

	/* If we're writing a large file, set the large_file flag */
	if (LINUX_S_ISREG(inode->i_mode) &&
	    ext2fs_needs_large_file_feature(size) &&
	    (!ext2fs_has_feature_large_file(fs->super) ||
	     fs->super->s_rev_level == EXT2_GOOD_OLD_REV)) {
		ext2fs_set_feature_large_file(fs->super);
		ext2fs_update_dynamic_rev(fs);
		ext2fs_mark_super_dirty(fs);
	}

	inode->i_size = size & 0xffffffff;
	inode->i_size_high = (size >> 32);

	return 0;
}

