#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
struct ext2_inode_large {int dummy; } ;
struct ext2_inode {int dummy; } ;
typedef  TYPE_2__* io_channel ;
typedef  TYPE_3__* ext2_filsys ;
typedef  scalar_t__ errcode_t ;
struct TYPE_26__ {int /*<<< orphan*/  super; } ;
struct TYPE_25__ {size_t block_size; TYPE_1__* manager; int /*<<< orphan*/  align; } ;
struct TYPE_24__ {scalar_t__ (* cache_readahead ) (TYPE_2__*,unsigned long long,unsigned long long) ;scalar_t__ (* zeroout ) (TYPE_2__*,unsigned long long,unsigned long long) ;scalar_t__ (* discard ) (TYPE_2__*,unsigned long long,unsigned long long) ;scalar_t__ (* write_blk ) (TYPE_2__*,unsigned long,int,void const*) ;scalar_t__ (* write_blk64 ) (TYPE_2__*,unsigned long long,int,void const*) ;scalar_t__ (* read_blk ) (TYPE_2__*,unsigned long,int,void*) ;scalar_t__ (* read_blk64 ) (TYPE_2__*,unsigned long long,int,void*) ;scalar_t__ (* write_byte ) (TYPE_2__*,unsigned long,int,void const*) ;scalar_t__ (* set_option ) (TYPE_2__*,char*,char*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  EXT2_CHECK_MAGIC (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ EXT2_ET_INVALID_ARGUMENT ; 
 scalar_t__ EXT2_ET_IO_CHANNEL_NO_SUPPORT_64 ; 
 int /*<<< orphan*/  EXT2_ET_MAGIC_IO_CHANNEL ; 
 scalar_t__ EXT2_ET_NO_MEMORY ; 
 scalar_t__ EXT2_ET_OP_NOT_SUPPORTED ; 
 scalar_t__ EXT2_ET_UNIMPLEMENTED ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 scalar_t__ ext2fs_get_mem (size_t,void*) ; 
 scalar_t__ ext2fs_get_memalign (size_t,int /*<<< orphan*/ ,void*) ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (int /*<<< orphan*/ ) ; 
 scalar_t__ ext2fs_has_feature_largedir (int /*<<< orphan*/ ) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (scalar_t__) ; 
 char* strchr (char*,char) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 scalar_t__ strlen (char const*) ; 
 scalar_t__ stub1 (TYPE_2__*,char*,char*) ; 
 scalar_t__ stub2 (TYPE_2__*,unsigned long,int,void const*) ; 
 scalar_t__ stub3 (TYPE_2__*,unsigned long long,int,void*) ; 
 scalar_t__ stub4 (TYPE_2__*,unsigned long,int,void*) ; 
 scalar_t__ stub5 (TYPE_2__*,unsigned long long,int,void const*) ; 
 scalar_t__ stub6 (TYPE_2__*,unsigned long,int,void const*) ; 
 scalar_t__ stub7 (TYPE_2__*,unsigned long long,unsigned long long) ; 
 scalar_t__ stub8 (TYPE_2__*,unsigned long long,unsigned long long) ; 
 scalar_t__ stub9 (TYPE_2__*,unsigned long long,unsigned long long) ; 

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

errcode_t io_channel_set_options(io_channel channel, const char *opts)
{
	errcode_t retval = 0;
	char *next, *ptr, *options, *arg;

	EXT2_CHECK_MAGIC(channel, EXT2_ET_MAGIC_IO_CHANNEL);

	if (!opts)
		return 0;

	if (!channel->manager->set_option)
		return EXT2_ET_INVALID_ARGUMENT;

	options = malloc(strlen(opts)+1);
	if (!options)
		return EXT2_ET_NO_MEMORY;
	strcpy(options, opts);
	ptr = options;

	while (ptr && *ptr) {
		next = strchr(ptr, '&');
		if (next)
			*next++ = 0;

		arg = strchr(ptr, '=');
		if (arg)
			*arg++ = 0;

		retval = (channel->manager->set_option)(channel, ptr, arg);
		if (retval)
			break;
		ptr = next;
	}
	free(options);
	return retval;
}

errcode_t io_channel_write_byte(io_channel channel, unsigned long offset,
				int count, const void *data)
{
	EXT2_CHECK_MAGIC(channel, EXT2_ET_MAGIC_IO_CHANNEL);

	if (channel->manager->write_byte)
		return channel->manager->write_byte(channel, offset,
						    count, data);

	return EXT2_ET_UNIMPLEMENTED;
}

errcode_t io_channel_read_blk64(io_channel channel, unsigned long long block,
				 int count, void *data)
{
	EXT2_CHECK_MAGIC(channel, EXT2_ET_MAGIC_IO_CHANNEL);

	if (channel->manager->read_blk64)
		return (channel->manager->read_blk64)(channel, block,
						      count, data);

	if ((block >> 32) != 0)
		return EXT2_ET_IO_CHANNEL_NO_SUPPORT_64;

	return (channel->manager->read_blk)(channel, (unsigned long) block,
					     count, data);
}

errcode_t io_channel_write_blk64(io_channel channel, unsigned long long block,
				 int count, const void *data)
{
	EXT2_CHECK_MAGIC(channel, EXT2_ET_MAGIC_IO_CHANNEL);

	if (channel->manager->write_blk64)
		return (channel->manager->write_blk64)(channel, block,
						       count, data);

	if ((block >> 32) != 0)
		return EXT2_ET_IO_CHANNEL_NO_SUPPORT_64;

	return (channel->manager->write_blk)(channel, (unsigned long) block,
					     count, data);
}

errcode_t io_channel_discard(io_channel channel, unsigned long long block,
			     unsigned long long count)
{
	EXT2_CHECK_MAGIC(channel, EXT2_ET_MAGIC_IO_CHANNEL);

	if (channel->manager->discard)
		return (channel->manager->discard)(channel, block, count);

	return EXT2_ET_UNIMPLEMENTED;
}

errcode_t io_channel_zeroout(io_channel channel, unsigned long long block,
			     unsigned long long count)
{
	EXT2_CHECK_MAGIC(channel, EXT2_ET_MAGIC_IO_CHANNEL);

	if (channel->manager->zeroout)
		return (channel->manager->zeroout)(channel, block, count);

	return EXT2_ET_UNIMPLEMENTED;
}

errcode_t io_channel_alloc_buf(io_channel io, int count, void *ptr)
{
	size_t	size;

	if (count == 0)
		size = io->block_size;
	else if (count > 0)
		size = io->block_size * count;
	else
		size = -count;

	if (io->align)
		return ext2fs_get_memalign(size, io->align, ptr);
	else
		return ext2fs_get_mem(size, ptr);
}

errcode_t io_channel_cache_readahead(io_channel io, unsigned long long block,
				     unsigned long long count)
{
	if (!io->manager->cache_readahead)
		return EXT2_ET_OP_NOT_SUPPORTED;

	return io->manager->cache_readahead(io, block, count);
}

