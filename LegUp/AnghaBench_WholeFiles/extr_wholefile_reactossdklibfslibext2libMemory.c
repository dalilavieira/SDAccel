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
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int ULONG ;
struct TYPE_11__ {TYPE_2__* ext2_sb; TYPE_1__* group_desc; int /*<<< orphan*/  block_map; int /*<<< orphan*/  inode_map; } ;
struct TYPE_10__ {int s_inodes_per_group; int s_first_data_block; int s_blocks_per_group; int s_free_inodes_count; int s_free_blocks_count; } ;
struct TYPE_9__ {int bg_free_inodes_count; int bg_used_dirs_count; int bg_free_blocks_count; } ;
typedef  TYPE_3__* PEXT2_FILESYS ;

/* Variables and functions */
 int /*<<< orphan*/  ext2_mark_block_bitmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ext2_mark_inode_bitmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ext2_unmark_block_bitmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ext2_unmark_inode_bitmap (int /*<<< orphan*/ ,int) ; 

int ext2_group_of_ino(PEXT2_FILESYS fs, ULONG ino)
{
    return (ino - 1) / fs->ext2_sb->s_inodes_per_group;
}

int ext2_group_of_blk(PEXT2_FILESYS fs, ULONG blk)
{
    return (blk - fs->ext2_sb->s_first_data_block) /
        fs->ext2_sb->s_blocks_per_group;
}

void ext2_inode_alloc_stats2(PEXT2_FILESYS fs, ULONG ino,
                   int inuse, int isdir)
{
    int group = ext2_group_of_ino(fs, ino);

    if (inuse > 0)
        ext2_mark_inode_bitmap(fs->inode_map, ino);
    else
        ext2_unmark_inode_bitmap(fs->inode_map, ino);

    fs->group_desc[group].bg_free_inodes_count -= inuse;

    if (isdir)
        fs->group_desc[group].bg_used_dirs_count += inuse;

    fs->ext2_sb->s_free_inodes_count -= inuse;
}

void ext2_inode_alloc_stats(PEXT2_FILESYS fs, ULONG ino, int inuse)
{
    ext2_inode_alloc_stats2(fs, ino, inuse, 0);
}

void ext2_block_alloc_stats(PEXT2_FILESYS fs, ULONG blk, int inuse)
{
    int group = ext2_group_of_blk(fs, blk);

    if (inuse > 0)
        ext2_mark_block_bitmap(fs->block_map, blk);
    else
        ext2_unmark_block_bitmap(fs->block_map, blk);

    fs->group_desc[group].bg_free_blocks_count -= inuse;
    fs->ext2_sb->s_free_blocks_count -= inuse;
}

