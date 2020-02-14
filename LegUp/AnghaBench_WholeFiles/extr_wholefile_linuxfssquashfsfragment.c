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
typedef  scalar_t__ u64 ;
typedef  int u32 ;
struct super_block {struct squashfs_sb_info* s_fs_info; } ;
struct squashfs_sb_info {unsigned int fragments; int /*<<< orphan*/ * fragment_index; } ;
struct squashfs_fragment_entry {int /*<<< orphan*/  size; int /*<<< orphan*/  start_block; } ;
typedef  int /*<<< orphan*/  fragment_entry ;
typedef  int /*<<< orphan*/  __le64 ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/ * ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ *) ; 
 int SQUASHFS_FRAGMENT_INDEX (unsigned int) ; 
 unsigned int SQUASHFS_FRAGMENT_INDEX_BYTES (unsigned int) ; 
 int SQUASHFS_FRAGMENT_INDEX_OFFSET (unsigned int) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ le64_to_cpu (int /*<<< orphan*/ ) ; 
 int squashfs_read_metadata (struct super_block*,struct squashfs_fragment_entry*,scalar_t__*,int*,int) ; 
 int /*<<< orphan*/ * squashfs_read_table (struct super_block*,scalar_t__,unsigned int) ; 

__attribute__((used)) static inline int squashfs_block_size(__le32 raw)
{
	u32 size = le32_to_cpu(raw);
	return (size >> 25) ? -EIO : size;
}

int squashfs_frag_lookup(struct super_block *sb, unsigned int fragment,
				u64 *fragment_block)
{
	struct squashfs_sb_info *msblk = sb->s_fs_info;
	int block, offset, size;
	struct squashfs_fragment_entry fragment_entry;
	u64 start_block;

	if (fragment >= msblk->fragments)
		return -EIO;
	block = SQUASHFS_FRAGMENT_INDEX(fragment);
	offset = SQUASHFS_FRAGMENT_INDEX_OFFSET(fragment);

	start_block = le64_to_cpu(msblk->fragment_index[block]);

	size = squashfs_read_metadata(sb, &fragment_entry, &start_block,
					&offset, sizeof(fragment_entry));
	if (size < 0)
		return size;

	*fragment_block = le64_to_cpu(fragment_entry.start_block);
	return squashfs_block_size(fragment_entry.size);
}

__le64 *squashfs_read_fragment_index_table(struct super_block *sb,
	u64 fragment_table_start, u64 next_table, unsigned int fragments)
{
	unsigned int length = SQUASHFS_FRAGMENT_INDEX_BYTES(fragments);
	__le64 *table;

	/*
	 * Sanity check, length bytes should not extend into the next table -
	 * this check also traps instances where fragment_table_start is
	 * incorrectly larger than the next table start
	 */
	if (fragment_table_start + length > next_table)
		return ERR_PTR(-EINVAL);

	table = squashfs_read_table(sb, fragment_table_start, length);

	/*
	 * table[0] points to the first fragment table metadata block, this
	 * should be less than fragment_table_start
	 */
	if (!IS_ERR(table) && le64_to_cpu(table[0]) >= fragment_table_start) {
		kfree(table);
		return ERR_PTR(-EINVAL);
	}

	return table;
}

