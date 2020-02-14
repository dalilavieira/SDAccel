#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct ext2_inode_large {int dummy; } ;
struct ext2_inode {int dummy; } ;
typedef  int /*<<< orphan*/  mode_t ;
typedef  scalar_t__ ext2fs_inode_bitmap ;
typedef  TYPE_1__* ext2fs_generic_bitmap_64 ;
typedef  scalar_t__ ext2fs_generic_bitmap ;
typedef  scalar_t__ ext2fs_block_bitmap ;
typedef  unsigned int ext2_ino_t ;
typedef  TYPE_2__* ext2_filsys ;
typedef  int errcode_t ;
typedef  unsigned int blk_t ;
typedef  unsigned int blk64_t ;
typedef  unsigned int __u64 ;
typedef  int /*<<< orphan*/  __u32 ;
struct TYPE_22__ {unsigned int s_inodes_count; unsigned int s_first_data_block; } ;
struct TYPE_21__ {unsigned int group_desc_count; int flags; int /*<<< orphan*/  default_bitmap_type; TYPE_5__* super; int /*<<< orphan*/  cluster_ratio_bits; void* write_bitmaps; } ;
struct TYPE_20__ {int cluster_bits; } ;

/* Variables and functions */
 unsigned int EXT2FS_B2C (TYPE_2__*,unsigned int) ; 
 int /*<<< orphan*/  EXT2FS_IS_64_BITMAP (TYPE_1__*) ; 
 scalar_t__ EXT2_BLOCKS_PER_GROUP (TYPE_5__*) ; 
 int /*<<< orphan*/  EXT2_CHECK_MAGIC (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ EXT2_CLUSTERS_PER_GROUP (TYPE_5__*) ; 
 int EXT2_ET_CANT_USE_LEGACY_BITMAPS ; 
 int /*<<< orphan*/  EXT2_ET_FUDGE_BLOCK_BITMAP_END ; 
 int /*<<< orphan*/  EXT2_ET_FUDGE_INODE_BITMAP_END ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_BLOCK_BITMAP ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_BLOCK_BITMAP64 ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_EXT2FS_FILSYS ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_INODE_BITMAP ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_INODE_BITMAP64 ; 
 int /*<<< orphan*/  EXT2_ET_NEQ_BLOCK_BITMAP ; 
 int /*<<< orphan*/  EXT2_ET_NEQ_INODE_BITMAP ; 
 int EXT2_FLAG_64BITS ; 
 unsigned int EXT2_INODES_PER_GROUP (TYPE_5__*) ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 int S_ISBLK (int /*<<< orphan*/ ) ; 
 int ext2fs_alloc_generic_bmap (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int,char const*,scalar_t__*) ; 
 unsigned int ext2fs_blocks_count (TYPE_5__*) ; 
 int /*<<< orphan*/  ext2fs_clear_generic_bmap (scalar_t__) ; 
 int ext2fs_compare_generic_bmap (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int ext2fs_copy_generic_bmap (scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  ext2fs_free_generic_bmap (scalar_t__) ; 
 int ext2fs_fudge_generic_bitmap_end (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int ext2fs_fudge_generic_bmap_end (scalar_t__,int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int ext2fs_get_generic_bitmap_range (scalar_t__,int /*<<< orphan*/ ,unsigned int,unsigned int,void*) ; 
 int ext2fs_get_generic_bmap_range (scalar_t__,unsigned int,size_t,void*) ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (TYPE_5__*) ; 
 scalar_t__ ext2fs_has_feature_largedir (TYPE_5__*) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (TYPE_5__*) ; 
 int ext2fs_make_generic_bitmap (int /*<<< orphan*/ ,TYPE_2__*,unsigned int,unsigned int,unsigned int,char const*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int ext2fs_resize_generic_bitmap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int ext2fs_resize_generic_bmap (scalar_t__,unsigned int,unsigned int) ; 
 int ext2fs_set_generic_bitmap_range (scalar_t__,int /*<<< orphan*/ ,unsigned int,unsigned int,void*) ; 
 int /*<<< orphan*/  ext2fs_set_generic_bmap_padding (scalar_t__) ; 
 int ext2fs_set_generic_bmap_range (scalar_t__,unsigned int,size_t,void*) ; 
 void* ext2fs_write_bitmaps ; 

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

void ext2fs_free_inode_bitmap(ext2fs_inode_bitmap bitmap)
{
	ext2fs_free_generic_bmap(bitmap);
}

void ext2fs_free_block_bitmap(ext2fs_block_bitmap bitmap)
{
	ext2fs_free_generic_bmap(bitmap);
}

errcode_t ext2fs_copy_bitmap(ext2fs_generic_bitmap src,
			     ext2fs_generic_bitmap *dest)
{
	return (ext2fs_copy_generic_bmap(src, dest));
}

void ext2fs_set_bitmap_padding(ext2fs_generic_bitmap map)
{
	ext2fs_set_generic_bmap_padding(map);
}

errcode_t ext2fs_allocate_inode_bitmap(ext2_filsys fs,
				       const char *descr,
				       ext2fs_inode_bitmap *ret)
{
	__u64		start, end, real_end;

	EXT2_CHECK_MAGIC(fs, EXT2_ET_MAGIC_EXT2FS_FILSYS);

	fs->write_bitmaps = ext2fs_write_bitmaps;

	start = 1;
	end = fs->super->s_inodes_count;
	real_end = (EXT2_INODES_PER_GROUP(fs->super) * fs->group_desc_count);

	/* Are we permitted to use new-style bitmaps? */
	if (fs->flags & EXT2_FLAG_64BITS)
		return (ext2fs_alloc_generic_bmap(fs,
				EXT2_ET_MAGIC_INODE_BITMAP64,
				fs->default_bitmap_type,
				start, end, real_end, descr, ret));

	/* Otherwise, check to see if the file system is small enough
	 * to use old-style 32-bit bitmaps */
	if ((end > ~0U) || (real_end > ~0U))
		return EXT2_ET_CANT_USE_LEGACY_BITMAPS;

	return (ext2fs_make_generic_bitmap(EXT2_ET_MAGIC_INODE_BITMAP, fs,
					 start, end, real_end,
					 descr, 0,
					 (ext2fs_generic_bitmap *) ret));
}

errcode_t ext2fs_allocate_block_bitmap(ext2_filsys fs,
				       const char *descr,
				       ext2fs_block_bitmap *ret)
{
	__u64		start, end, real_end;

	EXT2_CHECK_MAGIC(fs, EXT2_ET_MAGIC_EXT2FS_FILSYS);

	fs->write_bitmaps = ext2fs_write_bitmaps;

	start = EXT2FS_B2C(fs, fs->super->s_first_data_block);
	end = EXT2FS_B2C(fs, ext2fs_blocks_count(fs->super)-1);
	real_end = ((__u64) EXT2_CLUSTERS_PER_GROUP(fs->super)
		    * (__u64) fs->group_desc_count)-1 + start;

	if (fs->flags & EXT2_FLAG_64BITS)
		return (ext2fs_alloc_generic_bmap(fs,
				EXT2_ET_MAGIC_BLOCK_BITMAP64,
				fs->default_bitmap_type,
				start, end, real_end, descr, ret));

	if ((end > ~0U) || (real_end > ~0U))
		return EXT2_ET_CANT_USE_LEGACY_BITMAPS;

	return (ext2fs_make_generic_bitmap(EXT2_ET_MAGIC_BLOCK_BITMAP, fs,
					   start, end, real_end,
					   descr, 0,
					   (ext2fs_generic_bitmap *) ret));
}

errcode_t ext2fs_allocate_subcluster_bitmap(ext2_filsys fs,
					    const char *descr,
					    ext2fs_block_bitmap *ret)
{
	__u64			start, end, real_end;
	ext2fs_generic_bitmap	bmap;
	ext2fs_generic_bitmap_64 bmap64;
	errcode_t		retval;

	EXT2_CHECK_MAGIC(fs, EXT2_ET_MAGIC_EXT2FS_FILSYS);

	fs->write_bitmaps = ext2fs_write_bitmaps;

	if (!fs->cluster_ratio_bits)
		return ext2fs_allocate_block_bitmap(fs, descr, ret);

	if ((fs->flags & EXT2_FLAG_64BITS) == 0)
		return EXT2_ET_CANT_USE_LEGACY_BITMAPS;

	start = fs->super->s_first_data_block;
	end = ext2fs_blocks_count(fs->super)-1;
	real_end = ((__u64) EXT2_BLOCKS_PER_GROUP(fs->super)
		    * (__u64) fs->group_desc_count)-1 + start;

	retval = ext2fs_alloc_generic_bmap(fs, EXT2_ET_MAGIC_BLOCK_BITMAP64,
					   fs->default_bitmap_type, start,
					   end, real_end, descr, &bmap);
	if (retval)
		return retval;
	bmap64 = (ext2fs_generic_bitmap_64) bmap;
	bmap64->cluster_bits = 0;
	*ret = bmap;
	return 0;
}

int ext2fs_get_bitmap_granularity(ext2fs_block_bitmap bitmap)
{
	ext2fs_generic_bitmap_64 bmap = (ext2fs_generic_bitmap_64) bitmap;

	if (!EXT2FS_IS_64_BITMAP(bmap))
		return 0;

	return bmap->cluster_bits;
}

errcode_t ext2fs_fudge_inode_bitmap_end(ext2fs_inode_bitmap bitmap,
					ext2_ino_t end, ext2_ino_t *oend)
{
	__u64 tmp_oend;
	int retval;

	retval = ext2fs_fudge_generic_bmap_end((ext2fs_generic_bitmap) bitmap,
					       EXT2_ET_FUDGE_INODE_BITMAP_END,
					       end, &tmp_oend);
	if (oend)
		*oend = tmp_oend;
	return retval;
}

errcode_t ext2fs_fudge_block_bitmap_end(ext2fs_block_bitmap bitmap,
					blk_t end, blk_t *oend)
{
	return (ext2fs_fudge_generic_bitmap_end(bitmap,
						EXT2_ET_MAGIC_BLOCK_BITMAP,
						EXT2_ET_FUDGE_BLOCK_BITMAP_END,
						end, oend));
}

errcode_t ext2fs_fudge_block_bitmap_end2(ext2fs_block_bitmap bitmap,
					 blk64_t end, blk64_t *oend)
{
	return (ext2fs_fudge_generic_bmap_end(bitmap,
					      EXT2_ET_FUDGE_BLOCK_BITMAP_END,
					      end, oend));
}

void ext2fs_clear_inode_bitmap(ext2fs_inode_bitmap bitmap)
{
	ext2fs_clear_generic_bmap(bitmap);
}

void ext2fs_clear_block_bitmap(ext2fs_block_bitmap bitmap)
{
	ext2fs_clear_generic_bmap(bitmap);
}

errcode_t ext2fs_resize_inode_bitmap(__u32 new_end, __u32 new_real_end,
				     ext2fs_inode_bitmap bmap)
{
	return (ext2fs_resize_generic_bitmap(EXT2_ET_MAGIC_INODE_BITMAP,
					     new_end, new_real_end, bmap));
}

errcode_t ext2fs_resize_inode_bitmap2(__u64 new_end, __u64 new_real_end,
				      ext2fs_inode_bitmap bmap)
{
	return (ext2fs_resize_generic_bmap(bmap, new_end, new_real_end));
}

errcode_t ext2fs_resize_block_bitmap(__u32 new_end, __u32 new_real_end,
				     ext2fs_block_bitmap bmap)
{
	return (ext2fs_resize_generic_bitmap(EXT2_ET_MAGIC_BLOCK_BITMAP,
					     new_end, new_real_end, bmap));
}

errcode_t ext2fs_resize_block_bitmap2(__u64 new_end, __u64 new_real_end,
				      ext2fs_block_bitmap bmap)
{
	return (ext2fs_resize_generic_bmap(bmap, new_end, new_real_end));
}

errcode_t ext2fs_compare_block_bitmap(ext2fs_block_bitmap bm1,
				      ext2fs_block_bitmap bm2)
{
	return (ext2fs_compare_generic_bmap(EXT2_ET_NEQ_BLOCK_BITMAP,
					    bm1, bm2));
}

errcode_t ext2fs_compare_inode_bitmap(ext2fs_inode_bitmap bm1,
				      ext2fs_inode_bitmap bm2)
{
	return (ext2fs_compare_generic_bmap(EXT2_ET_NEQ_INODE_BITMAP,
					    bm1, bm2));
}

errcode_t ext2fs_set_inode_bitmap_range(ext2fs_inode_bitmap bmap,
					ext2_ino_t start, unsigned int num,
					void *in)
{
	return (ext2fs_set_generic_bitmap_range(bmap,
						EXT2_ET_MAGIC_INODE_BITMAP,
						start, num, in));
}

errcode_t ext2fs_set_inode_bitmap_range2(ext2fs_inode_bitmap bmap,
					 __u64 start, size_t num,
					 void *in)
{
	return (ext2fs_set_generic_bmap_range(bmap, start, num, in));
}

errcode_t ext2fs_get_inode_bitmap_range(ext2fs_inode_bitmap bmap,
					ext2_ino_t start, unsigned int num,
					void *out)
{
	return (ext2fs_get_generic_bitmap_range(bmap,
						EXT2_ET_MAGIC_INODE_BITMAP,
						start, num, out));
}

errcode_t ext2fs_get_inode_bitmap_range2(ext2fs_inode_bitmap bmap,
					 __u64 start, size_t num,
					 void *out)
{
	return (ext2fs_get_generic_bmap_range(bmap, start, num, out));
}

errcode_t ext2fs_set_block_bitmap_range(ext2fs_block_bitmap bmap,
					blk_t start, unsigned int num,
					void *in)
{
	return (ext2fs_set_generic_bitmap_range(bmap,
						EXT2_ET_MAGIC_BLOCK_BITMAP,
						start, num, in));
}

errcode_t ext2fs_set_block_bitmap_range2(ext2fs_block_bitmap bmap,
					 blk64_t start, size_t num,
					 void *in)
{
	return (ext2fs_set_generic_bmap_range(bmap, start, num, in));
}

errcode_t ext2fs_get_block_bitmap_range(ext2fs_block_bitmap bmap,
					blk_t start, unsigned int num,
					void *out)
{
	return (ext2fs_get_generic_bitmap_range(bmap,
						EXT2_ET_MAGIC_BLOCK_BITMAP,
						start, num, out));
}

errcode_t ext2fs_get_block_bitmap_range2(ext2fs_block_bitmap bmap,
					 blk64_t start, size_t num,
					 void *out)
{
	return (ext2fs_get_generic_bmap_range(bmap, start, num, out));
}

