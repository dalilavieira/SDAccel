#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_11__ ;
typedef  struct TYPE_12__   TYPE_10__ ;

/* Type definitions */
typedef  int u8 ;
typedef  long long u32 ;
typedef  scalar_t__ u16 ;
struct super_block {char const* s_id; long long s_blocksize; int s_blocksize_bits; } ;
struct page {int dummy; } ;
struct inode {long long i_ino; long long i_size; struct address_space* i_mapping; struct super_block* i_sb; } ;
struct hfs_find_data {int entrylength; TYPE_4__* key; int /*<<< orphan*/  entryoffset; int /*<<< orphan*/  bnode; TYPE_5__* search_key; } ;
struct hfs_extent {scalar_t__ count; scalar_t__ block; } ;
struct hfs_cat_file {scalar_t__ FlNum; scalar_t__ PyLen; scalar_t__ RPyLen; struct hfs_extent* RExtRec; struct hfs_extent* ExtRec; } ;
struct buffer_head {int dummy; } ;
struct address_space {int dummy; } ;
typedef  scalar_t__ sector_t ;
typedef  int /*<<< orphan*/  hfs_extent_rec ;
struct TYPE_15__ {int FkType; scalar_t__ FNum; void* FABN; } ;
struct TYPE_18__ {int key_len; TYPE_2__ ext; } ;
typedef  TYPE_5__ hfs_btree_key ;
struct TYPE_14__ {scalar_t__ FNum; scalar_t__ FkType; scalar_t__ FABN; } ;
struct TYPE_19__ {TYPE_1__ ext; } ;
typedef  TYPE_6__ btree_key ;
typedef  scalar_t__ __be32 ;
typedef  scalar_t__ __be16 ;
struct TYPE_16__ {scalar_t__ FNum; scalar_t__ FkType; scalar_t__ FABN; } ;
struct TYPE_17__ {TYPE_3__ ext; } ;
struct TYPE_13__ {scalar_t__ cached_start; int flags; int cached_blocks; scalar_t__ fs_blocks; scalar_t__ alloc_blocks; scalar_t__ first_blocks; long long phys_size; long long clump_blocks; int /*<<< orphan*/  extents_lock; struct hfs_extent* cached_extents; struct hfs_extent* first_extents; } ;
struct TYPE_12__ {long long alloc_blksz; long long fs_div; int /*<<< orphan*/  ext_tree; int /*<<< orphan*/  flags; scalar_t__ fs_start; } ;

/* Variables and functions */
 int EIO ; 
 int ENOENT ; 
 int ENOSPC ; 
 int /*<<< orphan*/  EXTENT ; 
 scalar_t__ HFS_FIRSTUSER_CNID ; 
 int HFS_FK_DATA ; 
 int HFS_FK_RSRC ; 
 int /*<<< orphan*/  HFS_FLG_ALT_MDB_DIRTY ; 
 int /*<<< orphan*/  HFS_FLG_BITMAP_DIRTY ; 
 int HFS_FLG_EXT_DIRTY ; 
 int HFS_FLG_EXT_NEW ; 
 int /*<<< orphan*/  HFS_FLG_MDB_DIRTY ; 
 TYPE_11__* HFS_I (struct inode*) ; 
 scalar_t__ HFS_IS_RSRC (struct inode*) ; 
 TYPE_10__* HFS_SB (struct super_block*) ; 
 int /*<<< orphan*/  INODE ; 
 scalar_t__ be16_to_cpu (scalar_t__) ; 
 scalar_t__ be32_to_cpu (scalar_t__) ; 
 void* cpu_to_be16 (long long) ; 
 scalar_t__ cpu_to_be32 (long long) ; 
 int /*<<< orphan*/  hfs_bnode_read (int /*<<< orphan*/ ,struct hfs_extent*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  hfs_bnode_write (int /*<<< orphan*/ ,struct hfs_extent*,int /*<<< orphan*/ ,int) ; 
 int hfs_brec_find (struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfs_brec_insert (struct hfs_find_data*,struct hfs_extent*,int) ; 
 int /*<<< orphan*/  hfs_brec_remove (struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfs_clear_vbm_bits (struct super_block*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  hfs_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  hfs_dbg_cont (int /*<<< orphan*/ ,char*,...) ; 
 int hfs_extend_file (struct inode*) ; 
 int /*<<< orphan*/  hfs_find_exit (struct hfs_find_data*) ; 
 int hfs_find_init (int /*<<< orphan*/ ,struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfs_mark_mdb_dirty (struct super_block*) ; 
 long long hfs_vbm_search_free (struct super_block*,long long,long long*) ; 
 int /*<<< orphan*/  inode_add_bytes (struct inode*,long long) ; 
 int /*<<< orphan*/  inode_set_bytes (struct inode*,int) ; 
 int /*<<< orphan*/  map_bh (struct buffer_head*,struct super_block*,scalar_t__) ; 
 int /*<<< orphan*/  mark_inode_dirty (struct inode*) ; 
 int /*<<< orphan*/  memset (struct hfs_extent*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int pagecache_write_begin (int /*<<< orphan*/ *,struct address_space*,long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct page**,void**) ; 
 int pagecache_write_end (int /*<<< orphan*/ *,struct address_space*,long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct page*,void*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_buffer_new (struct buffer_head*) ; 

__attribute__((used)) static inline const char *hfs_mdb_name(struct super_block *sb)
{
	return sb->s_id;
}

__attribute__((used)) static inline void hfs_bitmap_dirty(struct super_block *sb)
{
	set_bit(HFS_FLG_BITMAP_DIRTY, &HFS_SB(sb)->flags);
	hfs_mark_mdb_dirty(sb);
}

__attribute__((used)) static void hfs_ext_build_key(hfs_btree_key *key, u32 cnid, u16 block, u8 type)
{
	key->key_len = 7;
	key->ext.FkType = type;
	key->ext.FNum = cpu_to_be32(cnid);
	key->ext.FABN = cpu_to_be16(block);
}

int hfs_ext_keycmp(const btree_key *key1, const btree_key *key2)
{
	__be32 fnum1, fnum2;
	__be16 block1, block2;

	fnum1 = key1->ext.FNum;
	fnum2 = key2->ext.FNum;
	if (fnum1 != fnum2)
		return be32_to_cpu(fnum1) < be32_to_cpu(fnum2) ? -1 : 1;
	if (key1->ext.FkType != key2->ext.FkType)
		return key1->ext.FkType < key2->ext.FkType ? -1 : 1;

	block1 = key1->ext.FABN;
	block2 = key2->ext.FABN;
	if (block1 == block2)
		return 0;
	return be16_to_cpu(block1) < be16_to_cpu(block2) ? -1 : 1;
}

__attribute__((used)) static u16 hfs_ext_find_block(struct hfs_extent *ext, u16 off)
{
	int i;
	u16 count;

	for (i = 0; i < 3; ext++, i++) {
		count = be16_to_cpu(ext->count);
		if (off < count)
			return be16_to_cpu(ext->block) + off;
		off -= count;
	}
	/* panic? */
	return 0;
}

__attribute__((used)) static int hfs_ext_block_count(struct hfs_extent *ext)
{
	int i;
	u16 count = 0;

	for (i = 0; i < 3; ext++, i++)
		count += be16_to_cpu(ext->count);
	return count;
}

__attribute__((used)) static u16 hfs_ext_lastblock(struct hfs_extent *ext)
{
	int i;

	ext += 2;
	for (i = 0; i < 2; ext--, i++)
		if (ext->count)
			break;
	return be16_to_cpu(ext->block) + be16_to_cpu(ext->count);
}

__attribute__((used)) static int __hfs_ext_write_extent(struct inode *inode, struct hfs_find_data *fd)
{
	int res;

	hfs_ext_build_key(fd->search_key, inode->i_ino, HFS_I(inode)->cached_start,
			  HFS_IS_RSRC(inode) ?  HFS_FK_RSRC : HFS_FK_DATA);
	res = hfs_brec_find(fd);
	if (HFS_I(inode)->flags & HFS_FLG_EXT_NEW) {
		if (res != -ENOENT)
			return res;
		hfs_brec_insert(fd, HFS_I(inode)->cached_extents, sizeof(hfs_extent_rec));
		HFS_I(inode)->flags &= ~(HFS_FLG_EXT_DIRTY|HFS_FLG_EXT_NEW);
	} else {
		if (res)
			return res;
		hfs_bnode_write(fd->bnode, HFS_I(inode)->cached_extents, fd->entryoffset, fd->entrylength);
		HFS_I(inode)->flags &= ~HFS_FLG_EXT_DIRTY;
	}
	return 0;
}

int hfs_ext_write_extent(struct inode *inode)
{
	struct hfs_find_data fd;
	int res = 0;

	if (HFS_I(inode)->flags & HFS_FLG_EXT_DIRTY) {
		res = hfs_find_init(HFS_SB(inode->i_sb)->ext_tree, &fd);
		if (res)
			return res;
		res = __hfs_ext_write_extent(inode, &fd);
		hfs_find_exit(&fd);
	}
	return res;
}

__attribute__((used)) static inline int __hfs_ext_read_extent(struct hfs_find_data *fd, struct hfs_extent *extent,
					u32 cnid, u32 block, u8 type)
{
	int res;

	hfs_ext_build_key(fd->search_key, cnid, block, type);
	fd->key->ext.FNum = 0;
	res = hfs_brec_find(fd);
	if (res && res != -ENOENT)
		return res;
	if (fd->key->ext.FNum != fd->search_key->ext.FNum ||
	    fd->key->ext.FkType != fd->search_key->ext.FkType)
		return -ENOENT;
	if (fd->entrylength != sizeof(hfs_extent_rec))
		return -EIO;
	hfs_bnode_read(fd->bnode, extent, fd->entryoffset, sizeof(hfs_extent_rec));
	return 0;
}

__attribute__((used)) static inline int __hfs_ext_cache_extent(struct hfs_find_data *fd, struct inode *inode, u32 block)
{
	int res;

	if (HFS_I(inode)->flags & HFS_FLG_EXT_DIRTY) {
		res = __hfs_ext_write_extent(inode, fd);
		if (res)
			return res;
	}

	res = __hfs_ext_read_extent(fd, HFS_I(inode)->cached_extents, inode->i_ino,
				    block, HFS_IS_RSRC(inode) ? HFS_FK_RSRC : HFS_FK_DATA);
	if (!res) {
		HFS_I(inode)->cached_start = be16_to_cpu(fd->key->ext.FABN);
		HFS_I(inode)->cached_blocks = hfs_ext_block_count(HFS_I(inode)->cached_extents);
	} else {
		HFS_I(inode)->cached_start = HFS_I(inode)->cached_blocks = 0;
		HFS_I(inode)->flags &= ~(HFS_FLG_EXT_DIRTY|HFS_FLG_EXT_NEW);
	}
	return res;
}

__attribute__((used)) static int hfs_ext_read_extent(struct inode *inode, u16 block)
{
	struct hfs_find_data fd;
	int res;

	if (block >= HFS_I(inode)->cached_start &&
	    block < HFS_I(inode)->cached_start + HFS_I(inode)->cached_blocks)
		return 0;

	res = hfs_find_init(HFS_SB(inode->i_sb)->ext_tree, &fd);
	if (!res) {
		res = __hfs_ext_cache_extent(&fd, inode, block);
		hfs_find_exit(&fd);
	}
	return res;
}

__attribute__((used)) static void hfs_dump_extent(struct hfs_extent *extent)
{
	int i;

	hfs_dbg(EXTENT, "   ");
	for (i = 0; i < 3; i++)
		hfs_dbg_cont(EXTENT, " %u:%u",
			     be16_to_cpu(extent[i].block),
			     be16_to_cpu(extent[i].count));
	hfs_dbg_cont(EXTENT, "\n");
}

__attribute__((used)) static int hfs_add_extent(struct hfs_extent *extent, u16 offset,
			  u16 alloc_block, u16 block_count)
{
	u16 count, start;
	int i;

	hfs_dump_extent(extent);
	for (i = 0; i < 3; extent++, i++) {
		count = be16_to_cpu(extent->count);
		if (offset == count) {
			start = be16_to_cpu(extent->block);
			if (alloc_block != start + count) {
				if (++i >= 3)
					return -ENOSPC;
				extent++;
				extent->block = cpu_to_be16(alloc_block);
			} else
				block_count += count;
			extent->count = cpu_to_be16(block_count);
			return 0;
		} else if (offset < count)
			break;
		offset -= count;
	}
	/* panic? */
	return -EIO;
}

__attribute__((used)) static int hfs_free_extents(struct super_block *sb, struct hfs_extent *extent,
			    u16 offset, u16 block_nr)
{
	u16 count, start;
	int i;

	hfs_dump_extent(extent);
	for (i = 0; i < 3; extent++, i++) {
		count = be16_to_cpu(extent->count);
		if (offset == count)
			goto found;
		else if (offset < count)
			break;
		offset -= count;
	}
	/* panic? */
	return -EIO;
found:
	for (;;) {
		start = be16_to_cpu(extent->block);
		if (count <= block_nr) {
			hfs_clear_vbm_bits(sb, start, count);
			extent->block = 0;
			extent->count = 0;
			block_nr -= count;
		} else {
			count -= block_nr;
			hfs_clear_vbm_bits(sb, start + count, block_nr);
			extent->count = cpu_to_be16(count);
			block_nr = 0;
		}
		if (!block_nr || !i)
			return 0;
		i--;
		extent--;
		count = be16_to_cpu(extent->count);
	}
}

int hfs_free_fork(struct super_block *sb, struct hfs_cat_file *file, int type)
{
	struct hfs_find_data fd;
	u32 total_blocks, blocks, start;
	u32 cnid = be32_to_cpu(file->FlNum);
	struct hfs_extent *extent;
	int res, i;

	if (type == HFS_FK_DATA) {
		total_blocks = be32_to_cpu(file->PyLen);
		extent = file->ExtRec;
	} else {
		total_blocks = be32_to_cpu(file->RPyLen);
		extent = file->RExtRec;
	}
	total_blocks /= HFS_SB(sb)->alloc_blksz;
	if (!total_blocks)
		return 0;

	blocks = 0;
	for (i = 0; i < 3; extent++, i++)
		blocks += be16_to_cpu(extent[i].count);

	res = hfs_free_extents(sb, extent, blocks, blocks);
	if (res)
		return res;
	if (total_blocks == blocks)
		return 0;

	res = hfs_find_init(HFS_SB(sb)->ext_tree, &fd);
	if (res)
		return res;
	do {
		res = __hfs_ext_read_extent(&fd, extent, cnid, total_blocks, type);
		if (res)
			break;
		start = be16_to_cpu(fd.key->ext.FABN);
		hfs_free_extents(sb, extent, total_blocks - start, total_blocks);
		hfs_brec_remove(&fd);
		total_blocks = start;
	} while (total_blocks > blocks);
	hfs_find_exit(&fd);

	return res;
}

int hfs_get_block(struct inode *inode, sector_t block,
		  struct buffer_head *bh_result, int create)
{
	struct super_block *sb;
	u16 dblock, ablock;
	int res;

	sb = inode->i_sb;
	/* Convert inode block to disk allocation block */
	ablock = (u32)block / HFS_SB(sb)->fs_div;

	if (block >= HFS_I(inode)->fs_blocks) {
		if (block > HFS_I(inode)->fs_blocks || !create)
			return -EIO;
		if (ablock >= HFS_I(inode)->alloc_blocks) {
			res = hfs_extend_file(inode);
			if (res)
				return res;
		}
	} else
		create = 0;

	if (ablock < HFS_I(inode)->first_blocks) {
		dblock = hfs_ext_find_block(HFS_I(inode)->first_extents, ablock);
		goto done;
	}

	mutex_lock(&HFS_I(inode)->extents_lock);
	res = hfs_ext_read_extent(inode, ablock);
	if (!res)
		dblock = hfs_ext_find_block(HFS_I(inode)->cached_extents,
					    ablock - HFS_I(inode)->cached_start);
	else {
		mutex_unlock(&HFS_I(inode)->extents_lock);
		return -EIO;
	}
	mutex_unlock(&HFS_I(inode)->extents_lock);

done:
	map_bh(bh_result, sb, HFS_SB(sb)->fs_start +
	       dblock * HFS_SB(sb)->fs_div +
	       (u32)block % HFS_SB(sb)->fs_div);

	if (create) {
		set_buffer_new(bh_result);
		HFS_I(inode)->phys_size += sb->s_blocksize;
		HFS_I(inode)->fs_blocks++;
		inode_add_bytes(inode, sb->s_blocksize);
		mark_inode_dirty(inode);
	}
	return 0;
}

int hfs_extend_file(struct inode *inode)
{
	struct super_block *sb = inode->i_sb;
	u32 start, len, goal;
	int res;

	mutex_lock(&HFS_I(inode)->extents_lock);
	if (HFS_I(inode)->alloc_blocks == HFS_I(inode)->first_blocks)
		goal = hfs_ext_lastblock(HFS_I(inode)->first_extents);
	else {
		res = hfs_ext_read_extent(inode, HFS_I(inode)->alloc_blocks);
		if (res)
			goto out;
		goal = hfs_ext_lastblock(HFS_I(inode)->cached_extents);
	}

	len = HFS_I(inode)->clump_blocks;
	start = hfs_vbm_search_free(sb, goal, &len);
	if (!len) {
		res = -ENOSPC;
		goto out;
	}

	hfs_dbg(EXTENT, "extend %lu: %u,%u\n", inode->i_ino, start, len);
	if (HFS_I(inode)->alloc_blocks == HFS_I(inode)->first_blocks) {
		if (!HFS_I(inode)->first_blocks) {
			hfs_dbg(EXTENT, "first extents\n");
			/* no extents yet */
			HFS_I(inode)->first_extents[0].block = cpu_to_be16(start);
			HFS_I(inode)->first_extents[0].count = cpu_to_be16(len);
			res = 0;
		} else {
			/* try to append to extents in inode */
			res = hfs_add_extent(HFS_I(inode)->first_extents,
					     HFS_I(inode)->alloc_blocks,
					     start, len);
			if (res == -ENOSPC)
				goto insert_extent;
		}
		if (!res) {
			hfs_dump_extent(HFS_I(inode)->first_extents);
			HFS_I(inode)->first_blocks += len;
		}
	} else {
		res = hfs_add_extent(HFS_I(inode)->cached_extents,
				     HFS_I(inode)->alloc_blocks -
				     HFS_I(inode)->cached_start,
				     start, len);
		if (!res) {
			hfs_dump_extent(HFS_I(inode)->cached_extents);
			HFS_I(inode)->flags |= HFS_FLG_EXT_DIRTY;
			HFS_I(inode)->cached_blocks += len;
		} else if (res == -ENOSPC)
			goto insert_extent;
	}
out:
	mutex_unlock(&HFS_I(inode)->extents_lock);
	if (!res) {
		HFS_I(inode)->alloc_blocks += len;
		mark_inode_dirty(inode);
		if (inode->i_ino < HFS_FIRSTUSER_CNID)
			set_bit(HFS_FLG_ALT_MDB_DIRTY, &HFS_SB(sb)->flags);
		set_bit(HFS_FLG_MDB_DIRTY, &HFS_SB(sb)->flags);
		hfs_mark_mdb_dirty(sb);
	}
	return res;

insert_extent:
	hfs_dbg(EXTENT, "insert new extent\n");
	res = hfs_ext_write_extent(inode);
	if (res)
		goto out;

	memset(HFS_I(inode)->cached_extents, 0, sizeof(hfs_extent_rec));
	HFS_I(inode)->cached_extents[0].block = cpu_to_be16(start);
	HFS_I(inode)->cached_extents[0].count = cpu_to_be16(len);
	hfs_dump_extent(HFS_I(inode)->cached_extents);
	HFS_I(inode)->flags |= HFS_FLG_EXT_DIRTY|HFS_FLG_EXT_NEW;
	HFS_I(inode)->cached_start = HFS_I(inode)->alloc_blocks;
	HFS_I(inode)->cached_blocks = len;

	res = 0;
	goto out;
}

void hfs_file_truncate(struct inode *inode)
{
	struct super_block *sb = inode->i_sb;
	struct hfs_find_data fd;
	u16 blk_cnt, alloc_cnt, start;
	u32 size;
	int res;

	hfs_dbg(INODE, "truncate: %lu, %Lu -> %Lu\n",
		inode->i_ino, (long long)HFS_I(inode)->phys_size,
		inode->i_size);
	if (inode->i_size > HFS_I(inode)->phys_size) {
		struct address_space *mapping = inode->i_mapping;
		void *fsdata;
		struct page *page;

		/* XXX: Can use generic_cont_expand? */
		size = inode->i_size - 1;
		res = pagecache_write_begin(NULL, mapping, size+1, 0, 0,
					    &page, &fsdata);
		if (!res) {
			res = pagecache_write_end(NULL, mapping, size+1, 0, 0,
					page, fsdata);
		}
		if (res)
			inode->i_size = HFS_I(inode)->phys_size;
		return;
	} else if (inode->i_size == HFS_I(inode)->phys_size)
		return;
	size = inode->i_size + HFS_SB(sb)->alloc_blksz - 1;
	blk_cnt = size / HFS_SB(sb)->alloc_blksz;
	alloc_cnt = HFS_I(inode)->alloc_blocks;
	if (blk_cnt == alloc_cnt)
		goto out;

	mutex_lock(&HFS_I(inode)->extents_lock);
	res = hfs_find_init(HFS_SB(sb)->ext_tree, &fd);
	if (res) {
		mutex_unlock(&HFS_I(inode)->extents_lock);
		/* XXX: We lack error handling of hfs_file_truncate() */
		return;
	}
	while (1) {
		if (alloc_cnt == HFS_I(inode)->first_blocks) {
			hfs_free_extents(sb, HFS_I(inode)->first_extents,
					 alloc_cnt, alloc_cnt - blk_cnt);
			hfs_dump_extent(HFS_I(inode)->first_extents);
			HFS_I(inode)->first_blocks = blk_cnt;
			break;
		}
		res = __hfs_ext_cache_extent(&fd, inode, alloc_cnt);
		if (res)
			break;
		start = HFS_I(inode)->cached_start;
		hfs_free_extents(sb, HFS_I(inode)->cached_extents,
				 alloc_cnt - start, alloc_cnt - blk_cnt);
		hfs_dump_extent(HFS_I(inode)->cached_extents);
		if (blk_cnt > start) {
			HFS_I(inode)->flags |= HFS_FLG_EXT_DIRTY;
			break;
		}
		alloc_cnt = start;
		HFS_I(inode)->cached_start = HFS_I(inode)->cached_blocks = 0;
		HFS_I(inode)->flags &= ~(HFS_FLG_EXT_DIRTY|HFS_FLG_EXT_NEW);
		hfs_brec_remove(&fd);
	}
	hfs_find_exit(&fd);
	mutex_unlock(&HFS_I(inode)->extents_lock);

	HFS_I(inode)->alloc_blocks = blk_cnt;
out:
	HFS_I(inode)->phys_size = inode->i_size;
	HFS_I(inode)->fs_blocks = (inode->i_size + sb->s_blocksize - 1) >> sb->s_blocksize_bits;
	inode_set_bytes(inode, HFS_I(inode)->fs_blocks << sb->s_blocksize_bits);
	mark_inode_dirty(inode);
}

