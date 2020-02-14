#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct ext2_inode_large {int dummy; } ;
struct ext2_inode {int dummy; } ;
typedef  int /*<<< orphan*/  mode_t ;
typedef  TYPE_2__* ext2_u32_list ;
typedef  TYPE_2__* ext2_filsys ;
typedef  TYPE_2__* ext2_dblist ;
typedef  scalar_t__ ext2_badblocks_list ;
struct TYPE_15__ {scalar_t__ magic; scalar_t__ image_io; scalar_t__ io; TYPE_1__* fs; struct TYPE_15__* list; scalar_t__ block_sha_map; struct TYPE_15__* mmp_cmp; struct TYPE_15__* mmp_buf; scalar_t__ icache; struct TYPE_15__* dblist; scalar_t__ badblocks; struct TYPE_15__* image_header; scalar_t__ inode_map; scalar_t__ block_map; struct TYPE_15__* group_desc; struct TYPE_15__* orig_super; struct TYPE_15__* super; struct TYPE_15__* device_name; } ;
struct TYPE_14__ {TYPE_2__* dblist; } ;

/* Variables and functions */
 scalar_t__ EXT2_ET_MAGIC_BADBLOCKS_LIST ; 
 scalar_t__ EXT2_ET_MAGIC_DBLIST ; 
 scalar_t__ EXT2_ET_MAGIC_EXT2FS_FILSYS ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 int S_ISBLK (int /*<<< orphan*/ ) ; 
 void ext2fs_badblocks_list_free (scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_free_block_bitmap (scalar_t__) ; 
 void ext2fs_free_dblist (TYPE_2__*) ; 
 int /*<<< orphan*/  ext2fs_free_inode_bitmap (scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_free_inode_cache (scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_free_mem (TYPE_2__**) ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (TYPE_2__*) ; 
 scalar_t__ ext2fs_has_feature_largedir (TYPE_2__*) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (TYPE_2__*) ; 
 int /*<<< orphan*/  ext2fs_hashmap_free (scalar_t__) ; 
 int /*<<< orphan*/  ext2fs_zero_blocks2 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  io_channel_close (scalar_t__) ; 

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

void ext2fs_free(ext2_filsys fs)
{
	if (!fs || (fs->magic != EXT2_ET_MAGIC_EXT2FS_FILSYS))
		return;
	if (fs->image_io != fs->io) {
		if (fs->image_io)
			io_channel_close(fs->image_io);
	}
	if (fs->io) {
		io_channel_close(fs->io);
	}
	if (fs->device_name)
		ext2fs_free_mem(&fs->device_name);
	if (fs->super)
		ext2fs_free_mem(&fs->super);
	if (fs->orig_super)
		ext2fs_free_mem(&fs->orig_super);
	if (fs->group_desc)
		ext2fs_free_mem(&fs->group_desc);
	if (fs->block_map)
		ext2fs_free_block_bitmap(fs->block_map);
	if (fs->inode_map)
		ext2fs_free_inode_bitmap(fs->inode_map);
	if (fs->image_header)
		ext2fs_free_mem(&fs->image_header);

	if (fs->badblocks)
		ext2fs_badblocks_list_free(fs->badblocks);
	fs->badblocks = 0;

	if (fs->dblist)
		ext2fs_free_dblist(fs->dblist);

	if (fs->icache)
		ext2fs_free_inode_cache(fs->icache);

	if (fs->mmp_buf)
		ext2fs_free_mem(&fs->mmp_buf);
	if (fs->mmp_cmp)
		ext2fs_free_mem(&fs->mmp_cmp);

	if (fs->block_sha_map)
		ext2fs_hashmap_free(fs->block_sha_map);

	fs->magic = 0;

	// coverity[check_return]
	ext2fs_zero_blocks2(NULL, 0, 0, NULL, NULL);
	ext2fs_free_mem(&fs);
}

void ext2fs_u32_list_free(ext2_u32_list bb)
{
	if (bb->magic != EXT2_ET_MAGIC_BADBLOCKS_LIST)
		return;

	if (bb->list)
		ext2fs_free_mem(&bb->list);
	bb->list = 0;
	ext2fs_free_mem(&bb);
}

void ext2fs_badblocks_list_free(ext2_badblocks_list bb)
{
	ext2fs_u32_list_free((ext2_u32_list) bb);
}

void ext2fs_free_dblist(ext2_dblist dblist)
{
	if (!dblist || (dblist->magic != EXT2_ET_MAGIC_DBLIST))
		return;

	if (dblist->list)
		ext2fs_free_mem(&dblist->list);
	dblist->list = 0;
	if (dblist->fs && dblist->fs->dblist == dblist)
		dblist->fs->dblist = 0;
	dblist->magic = 0;
	ext2fs_free_mem(&dblist);
}

