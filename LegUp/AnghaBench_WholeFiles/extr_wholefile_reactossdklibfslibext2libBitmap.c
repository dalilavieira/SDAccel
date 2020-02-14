#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_1__* block_map; TYPE_1__* inode_map; } ;
struct TYPE_9__ {struct TYPE_9__* bitmap; } ;
typedef  TYPE_1__* PEXT2_INODE_BITMAP ;
typedef  TYPE_1__* PEXT2_GENERIC_BITMAP ;
typedef  TYPE_3__* PEXT2_FILESYS ;
typedef  TYPE_1__* PEXT2_BLOCK_BITMAP ;

/* Variables and functions */
 int /*<<< orphan*/  RtlFreeHeap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  RtlGetProcessHeap () ; 

void ext2_free_generic_bitmap(PEXT2_GENERIC_BITMAP bitmap)
{
    if (!bitmap)
        return;

    if (bitmap->bitmap)
    {
        RtlFreeHeap(RtlGetProcessHeap(), 0, bitmap->bitmap);
        bitmap->bitmap = 0;
    }

    RtlFreeHeap(RtlGetProcessHeap(), 0, bitmap);
}

void ext2_free_inode_bitmap(PEXT2_FILESYS Ext2Sys)
{
    PEXT2_INODE_BITMAP bitmap = Ext2Sys->inode_map;
    if (!bitmap)
        return;

    ext2_free_generic_bitmap(bitmap);

    Ext2Sys->inode_map = NULL;
}

void ext2_free_block_bitmap(PEXT2_FILESYS Ext2Sys)
{
    PEXT2_BLOCK_BITMAP bitmap = Ext2Sys->block_map;
    if (!bitmap)
        return;

    ext2_free_generic_bitmap(bitmap);

    Ext2Sys->block_map = NULL;
}

