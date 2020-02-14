#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_42__   TYPE_1__ ;
typedef  struct TYPE_41__   TYPE_18__ ;

/* Type definitions */
struct ext2_inode_large {int dummy; } ;
struct ext2_inode {int dummy; } ;
typedef  scalar_t__ ext2_ino_t ;
typedef  TYPE_1__* ext2_filsys ;
typedef  scalar_t__ blk_t ;
typedef  scalar_t__ blk64_t ;
struct TYPE_42__ {void (* block_alloc_stats ) (TYPE_1__*,scalar_t__,int) ;scalar_t__ magic; void (* block_alloc_stats_range ) (TYPE_1__*,scalar_t__,scalar_t__,int) ;TYPE_18__* super; int /*<<< orphan*/  block_map; int /*<<< orphan*/  inode_map; } ;
struct TYPE_41__ {scalar_t__ s_inodes_count; int s_inodes_per_group; int s_free_inodes_count; } ;

/* Variables and functions */
 int EXT2FS_CLUSTER_RATIO (TYPE_1__*) ; 
 int /*<<< orphan*/  EXT2_BG_BLOCK_UNINIT ; 
 int /*<<< orphan*/  EXT2_BG_INODE_UNINIT ; 
 scalar_t__ EXT2_ET_MAGIC_EXT2FS_FILSYS ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 int /*<<< orphan*/  com_err (char*,int /*<<< orphan*/ ,char*,unsigned long long,...) ; 
 int /*<<< orphan*/  ext2fs_bg_flags_clear (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ ext2fs_bg_free_blocks_count (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ext2fs_bg_free_blocks_count_set (TYPE_1__*,int,scalar_t__) ; 
 scalar_t__ ext2fs_bg_free_inodes_count (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ext2fs_bg_free_inodes_count_set (TYPE_1__*,int,scalar_t__) ; 
 scalar_t__ ext2fs_bg_itable_unused (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ext2fs_bg_itable_unused_set (TYPE_1__*,int,scalar_t__) ; 
 scalar_t__ ext2fs_bg_used_dirs_count (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ext2fs_bg_used_dirs_count_set (TYPE_1__*,int,scalar_t__) ; 
 scalar_t__ ext2fs_blocks_count (TYPE_18__*) ; 
 int /*<<< orphan*/  ext2fs_free_blocks_count_add (TYPE_18__*,int) ; 
 int /*<<< orphan*/  ext2fs_group_desc_csum_set (TYPE_1__*,int) ; 
 scalar_t__ ext2fs_group_last_block2 (TYPE_1__*,int) ; 
 int ext2fs_group_of_blk2 (TYPE_1__*,scalar_t__) ; 
 int ext2fs_group_of_ino (TYPE_1__*,scalar_t__) ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (TYPE_18__*) ; 
 scalar_t__ ext2fs_has_feature_largedir (TYPE_18__*) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (TYPE_18__*) ; 
 int /*<<< orphan*/  ext2fs_mark_bb_dirty (TYPE_1__*) ; 
 int /*<<< orphan*/  ext2fs_mark_block_bitmap2 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_mark_block_bitmap_range2 (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_mark_ib_dirty (TYPE_1__*) ; 
 int /*<<< orphan*/  ext2fs_mark_inode_bitmap2 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_mark_super_dirty (TYPE_1__*) ; 
 int /*<<< orphan*/  ext2fs_unmark_block_bitmap2 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_unmark_block_bitmap_range2 (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_unmark_inode_bitmap2 (int /*<<< orphan*/ ,scalar_t__) ; 
 void stub1 (TYPE_1__*,scalar_t__,int) ; 
 void stub2 (TYPE_1__*,scalar_t__,scalar_t__,int) ; 

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

void ext2fs_inode_alloc_stats2(ext2_filsys fs, ext2_ino_t ino,
			       int inuse, int isdir)
{
	int	group = ext2fs_group_of_ino(fs, ino);

	if (ino > fs->super->s_inodes_count) {
#ifndef OMIT_COM_ERR
		com_err("ext2fs_inode_alloc_stats2", 0,
			"Illegal inode number: %lu", (unsigned long) ino);
#endif
		return;
	}
	if (inuse > 0)
		ext2fs_mark_inode_bitmap2(fs->inode_map, ino);
	else
		ext2fs_unmark_inode_bitmap2(fs->inode_map, ino);
	ext2fs_bg_free_inodes_count_set(fs, group, ext2fs_bg_free_inodes_count(fs, group) - inuse);
	if (isdir)
		ext2fs_bg_used_dirs_count_set(fs, group, ext2fs_bg_used_dirs_count(fs, group) + inuse);

	/* We don't strictly need to be clearing the uninit flag if inuse < 0
	 * (i.e. freeing inodes) but it also means something is bad. */
	ext2fs_bg_flags_clear(fs, group, EXT2_BG_INODE_UNINIT);
	if (ext2fs_has_group_desc_csum(fs)) {
		ext2_ino_t first_unused_inode =	fs->super->s_inodes_per_group -
			ext2fs_bg_itable_unused(fs, group) +
			group * fs->super->s_inodes_per_group + 1;

		if (ino >= first_unused_inode)
			ext2fs_bg_itable_unused_set(fs, group, group * fs->super->s_inodes_per_group + fs->super->s_inodes_per_group - ino);
		ext2fs_group_desc_csum_set(fs, group);
	}

	fs->super->s_free_inodes_count -= inuse;
	ext2fs_mark_super_dirty(fs);
	ext2fs_mark_ib_dirty(fs);
}

void ext2fs_inode_alloc_stats(ext2_filsys fs, ext2_ino_t ino, int inuse)
{
	ext2fs_inode_alloc_stats2(fs, ino, inuse, 0);
}

void ext2fs_block_alloc_stats2(ext2_filsys fs, blk64_t blk, int inuse)
{
	int	group = ext2fs_group_of_blk2(fs, blk);

	if (blk >= ext2fs_blocks_count(fs->super)) {
#ifndef OMIT_COM_ERR
		com_err("ext2fs_block_alloc_stats", 0,
			"Illegal block number: %lu", (unsigned long) blk);
#endif
		return;
	}
	if (inuse > 0)
		ext2fs_mark_block_bitmap2(fs->block_map, blk);
	else
		ext2fs_unmark_block_bitmap2(fs->block_map, blk);
	ext2fs_bg_free_blocks_count_set(fs, group, ext2fs_bg_free_blocks_count(fs, group) - inuse);
	ext2fs_bg_flags_clear(fs, group, EXT2_BG_BLOCK_UNINIT);
	ext2fs_group_desc_csum_set(fs, group);

	ext2fs_free_blocks_count_add(fs->super,
			     -inuse * (blk64_t) EXT2FS_CLUSTER_RATIO(fs));
	ext2fs_mark_super_dirty(fs);
	ext2fs_mark_bb_dirty(fs);
	if (fs->block_alloc_stats)
		(fs->block_alloc_stats)(fs, (blk64_t) blk, inuse);
}

void ext2fs_block_alloc_stats(ext2_filsys fs, blk_t blk, int inuse)
{
	ext2fs_block_alloc_stats2(fs, blk, inuse);
}

void ext2fs_set_block_alloc_stats_callback(ext2_filsys fs,
					   void (*func)(ext2_filsys fs,
							blk64_t blk,
							int inuse),
					   void (**old)(ext2_filsys fs,
							blk64_t blk,
							int inuse))
{
	if (!fs || fs->magic != EXT2_ET_MAGIC_EXT2FS_FILSYS)
		return;
	if (old)
		*old = fs->block_alloc_stats;

	fs->block_alloc_stats = func;
}

void ext2fs_block_alloc_stats_range(ext2_filsys fs, blk64_t blk,
				    blk_t num, int inuse)
{
#ifndef OMIT_COM_ERR
	if (blk + num > ext2fs_blocks_count(fs->super)) {
		com_err("ext2fs_block_alloc_stats_range", 0,
			"Illegal block range: %llu (%u) ",
			(unsigned long long) blk, num);
		return;
	}
#endif
	if (inuse == 0)
		return;
	if (inuse > 0) {
		ext2fs_mark_block_bitmap_range2(fs->block_map, blk, num);
		inuse = 1;
	} else {
		ext2fs_unmark_block_bitmap_range2(fs->block_map, blk, num);
		inuse = -1;
	}
	while (num) {
		int group = ext2fs_group_of_blk2(fs, blk);
		blk64_t last_blk = ext2fs_group_last_block2(fs, group);
		blk64_t n = num;

		if (blk + num > last_blk)
			n = last_blk - blk + 1;

		ext2fs_bg_free_blocks_count_set(fs, group,
			ext2fs_bg_free_blocks_count(fs, group) -
			inuse*n/EXT2FS_CLUSTER_RATIO(fs));
		ext2fs_bg_flags_clear(fs, group, EXT2_BG_BLOCK_UNINIT);
		ext2fs_group_desc_csum_set(fs, group);
		ext2fs_free_blocks_count_add(fs->super, -inuse * (blk64_t) n);
		blk += n;
		num -= n;
	}
	ext2fs_mark_super_dirty(fs);
	ext2fs_mark_bb_dirty(fs);
	if (fs->block_alloc_stats_range)
		(fs->block_alloc_stats_range)(fs, blk, num, inuse);
}

void ext2fs_set_block_alloc_stats_range_callback(ext2_filsys fs,
	void (*func)(ext2_filsys fs, blk64_t blk,
				    blk_t num, int inuse),
	void (**old)(ext2_filsys fs, blk64_t blk,
				    blk_t num, int inuse))
{
	if (!fs || fs->magic != EXT2_ET_MAGIC_EXT2FS_FILSYS)
		return;
	if (old)
		*old = fs->block_alloc_stats_range;

	fs->block_alloc_stats_range = func;
}

