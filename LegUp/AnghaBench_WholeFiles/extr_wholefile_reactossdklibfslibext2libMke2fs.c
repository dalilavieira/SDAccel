#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct mke2fs_defaults {int size; int inode_ratio; int blocksize; scalar_t__ type; } ;
typedef  int ULONG ;
struct TYPE_9__ {TYPE_1__* ext2_sb; } ;
struct TYPE_8__ {int s_blocks_count; int s_log_frag_size; int s_log_block_size; scalar_t__ s_rev_level; int /*<<< orphan*/  s_inode_size; int /*<<< orphan*/  s_first_ino; } ;
typedef  TYPE_1__* PEXT2_SUPER_BLOCK ;
typedef  TYPE_2__* PEXT2_FILESYS ;

/* Variables and functions */
 int BLOCK_BITS ; 
 int EXT2_BLOCK_SIZE (TYPE_1__*) ; 
 scalar_t__ EXT2_DYNAMIC_REV ; 
 int /*<<< orphan*/  EXT2_GOOD_OLD_FIRST_INO ; 
 int /*<<< orphan*/  EXT2_GOOD_OLD_INODE_SIZE ; 
 scalar_t__ EXT2_GOOD_OLD_REV ; 
 int EXT2_MIN_BLOCK_LOG_SIZE ; 
 int EXT2_NDIR_BLOCKS ; 
 char const* default_str ; 
 struct mke2fs_defaults* settings ; 
 scalar_t__ strcmp (scalar_t__,char const*) ; 

int int_log2(int arg)
{
    int l = 0;

    arg >>= 1;

    while (arg)
    {
        l++;
        arg >>= 1;
    }

    return l;
}

int int_log10(unsigned int arg)
{
    int l;

    for (l=0; arg ; l++)
        arg = arg / 10;

    return l;
}

void set_fs_defaults(const char *fs_type,
                PEXT2_SUPER_BLOCK super,
                int blocksize, int *inode_ratio)
{
    int megs;
    int ratio = 0;
    struct mke2fs_defaults *p;

    megs = (super->s_blocks_count * (EXT2_BLOCK_SIZE(super) / 1024) / 1024);

    if (inode_ratio)
        ratio = *inode_ratio;

    if (!fs_type)
        fs_type = default_str;

    for (p = settings; p->type; p++)
    {
        if ((strcmp(p->type, fs_type) != 0) &&
            (strcmp(p->type, default_str) != 0))
            continue;

        if ((p->size != 0) &&
            (megs > p->size))
            continue;

        if (ratio == 0)
            *inode_ratio = p->inode_ratio;

        if (blocksize == 0)
        {
            super->s_log_frag_size = super->s_log_block_size =
                int_log2(p->blocksize >> EXT2_MIN_BLOCK_LOG_SIZE);
        }
    }

    if (blocksize == 0)
    {
        super->s_blocks_count /= EXT2_BLOCK_SIZE(super) / 1024;
    }
}

void ext2_update_dynamic_rev(PEXT2_FILESYS fs)
{
    PEXT2_SUPER_BLOCK sb = fs->ext2_sb;

    if (sb->s_rev_level > EXT2_GOOD_OLD_REV)
        return;

    sb->s_rev_level = EXT2_DYNAMIC_REV;
    sb->s_first_ino = EXT2_GOOD_OLD_FIRST_INO;
    sb->s_inode_size = EXT2_GOOD_OLD_INODE_SIZE;
    /* s_uuid is handled by e2fsck already */
    /* other fields should be left alone */
}

ULONG
Ext2DataBlocks(PEXT2_FILESYS Ext2Sys, ULONG TotalBlocks)
{
    ULONG   dwData[4] = {1, 1, 1, 1};
    ULONG   dwMeta[4] = {0, 0, 0, 0};
    ULONG   DataBlocks = 0;
    ULONG   i, j;

    if (TotalBlocks <= EXT2_NDIR_BLOCKS)
    {
        return TotalBlocks;
    }

    TotalBlocks -= EXT2_NDIR_BLOCKS;

    for (i = 0; i < 4; i++)
    {
        dwData[i] = dwData[i] << ((BLOCK_BITS - 2) * i);

        if (i > 0)
        {
            dwMeta[i] = 1 + (dwMeta[i - 1] << (BLOCK_BITS - 2));
        }
    }

    for( i=1; (i < 4) && (TotalBlocks > 0); i++)
    {
        if (TotalBlocks >= (dwData[i] + dwMeta[i]))
        {
            TotalBlocks -= (dwData[i] + dwMeta[i]);
            DataBlocks  += dwData[i];
        }
        else
        {
            ULONG   dwDivide = 0;
            ULONG   dwRemain = 0;

            for (j=i; (j > 0) && (TotalBlocks > 0); j--)
            {
                dwDivide = (TotalBlocks - 1) / (dwData[j-1] + dwMeta[j-1]);
                dwRemain = (TotalBlocks - 1) % (dwData[j-1] + dwMeta[j-1]);

                DataBlocks += (dwDivide * dwData[j-1]);
                TotalBlocks = dwRemain;
            }
        }
    }

    return (DataBlocks + EXT2_NDIR_BLOCKS);
}

ULONG
Ext2TotalBlocks(PEXT2_FILESYS Ext2Sys, ULONG DataBlocks)
{
    ULONG   dwData[4] = {1, 1, 1, 1};
    ULONG   dwMeta[4] = {0, 0, 0, 0};
    ULONG   TotalBlocks = 0;
    ULONG   i, j;

    if (DataBlocks <= EXT2_NDIR_BLOCKS)
    {
        return DataBlocks;
    }

    DataBlocks -= EXT2_NDIR_BLOCKS;

    for (i = 0; i < 4; i++)
    {
        dwData[i] = dwData[i] << ((BLOCK_BITS - 2) * i);

        if (i > 0)
        {
            dwMeta[i] = 1 + (dwMeta[i - 1] << (BLOCK_BITS - 2));
        }
    }

    for( i=1; (i < 4) && (DataBlocks > 0); i++)
    {
        if (DataBlocks >= dwData[i])
        {
            DataBlocks  -= dwData[i];
            TotalBlocks += (dwData[i] + dwMeta[i]);
        }
        else
        {
            ULONG   dwDivide = 0;
            ULONG   dwRemain = 0;

            for (j=i; (j > 0) && (DataBlocks > 0); j--)
            {
                dwDivide = (DataBlocks) / (dwData[j-1]);
                dwRemain = (DataBlocks) % (dwData[j-1]);

                TotalBlocks += (dwDivide * (dwData[j-1] + dwMeta[j-1]) + 1);
                DataBlocks = dwRemain;
            }
        }
    }

    return (TotalBlocks + EXT2_NDIR_BLOCKS);
}

