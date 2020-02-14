#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct super_block {int dummy; } ;
struct buffer_head {int dummy; } ;
typedef  int /*<<< orphan*/  sector_t ;

/* Variables and functions */
 int /*<<< orphan*/  bforget (struct buffer_head*) ; 
 int /*<<< orphan*/  brelse (struct buffer_head*) ; 
 int /*<<< orphan*/  clear_buffer_uptodate (struct buffer_head*) ; 
 struct buffer_head* sb_getblk (struct super_block*,int /*<<< orphan*/ ) ; 
 struct buffer_head* sb_getblk_zero (struct super_block*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_buffer_dirty (struct buffer_head*) ; 

struct buffer_head *
extents_bread(struct super_block *sb, sector_t block)
{
    return sb_getblk(sb, block);
}

struct buffer_head *
extents_bwrite(struct super_block *sb, sector_t block)
{
    return sb_getblk_zero(sb, block);

}

void extents_mark_buffer_dirty(struct buffer_head *bh)
{
    set_buffer_dirty(bh);
}

void extents_brelse(struct buffer_head *bh)
{
    brelse(bh);
}

void extents_bforget(struct buffer_head *bh)
{
    clear_buffer_uptodate(bh);
    bforget(bh);
}

