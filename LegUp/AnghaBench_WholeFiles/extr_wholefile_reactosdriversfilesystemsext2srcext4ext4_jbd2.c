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
struct inode {int dummy; } ;
struct buffer_head {int dummy; } ;
typedef  int /*<<< orphan*/  handle_t ;
typedef  int /*<<< orphan*/  ext4_fsblk_t ;

/* Variables and functions */
 int /*<<< orphan*/  extents_mark_buffer_dirty (struct buffer_head*) ; 
 int /*<<< orphan*/  no_journal ; 

handle_t *__ext4_journal_start_sb(void *icb, struct super_block *sb, unsigned int line,
				  int type, int blocks, int rsv_blocks)
{
	return &no_journal;
}

int __ext4_journal_stop(const char *where, unsigned int line, void *icb, handle_t *handle)
{
	return 0;
}

void ext4_journal_abort_handle(const char *caller, unsigned int line,
			       const char *err_fn, struct buffer_head *bh,
			       handle_t *handle, int err)
{
}

int __ext4_journal_get_write_access(const char *where, unsigned int line,
				    void *icb, handle_t *handle, struct buffer_head *bh)
{
	int err = 0;
	return err;
}

int __ext4_forget(const char *where, unsigned int line, void *icb, handle_t *handle,
		  int is_metadata, struct inode *inode,
		  struct buffer_head *bh, ext4_fsblk_t blocknr)
{
	int err = 0;
	return err;
}

int __ext4_journal_get_create_access(const char *where, unsigned int line,
				void *icb, handle_t *handle, struct buffer_head *bh)
{
	int err = 0;
	return err;
}

int __ext4_handle_dirty_metadata(const char *where, unsigned int line,
				 void *icb, handle_t *handle, struct inode *inode,
				 struct buffer_head *bh)
{
	int err = 0;

	extents_mark_buffer_dirty(bh);
	return err;
}

int __ext4_handle_dirty_super(const char *where, unsigned int line,
			      handle_t *handle, struct super_block *sb)
{
    return 0;
}

