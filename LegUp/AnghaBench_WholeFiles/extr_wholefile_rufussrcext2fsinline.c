#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct ext2_inode_large {int dummy; } ;
struct ext2_inode {int dummy; } ;
typedef  TYPE_1__* ext2_filsys ;
typedef  int /*<<< orphan*/  errcode_t ;
struct TYPE_4__ {int /*<<< orphan*/  super; } ;

/* Variables and functions */
 int /*<<< orphan*/  EXT2_ET_NO_MEMORY ; 
 unsigned int EXT4_HTREE_LEVEL ; 
 unsigned int EXT4_HTREE_LEVEL_COMPAT ; 
 scalar_t__ ext2fs_has_feature_gdt_csum (int /*<<< orphan*/ ) ; 
 scalar_t__ ext2fs_has_feature_largedir (int /*<<< orphan*/ ) ; 
 scalar_t__ ext2fs_has_feature_metadata_csum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (void*) ; 
 void* malloc (unsigned long) ; 

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

errcode_t ext2fs_get_memalign(unsigned long size,
			      unsigned long align, void *ptr)
{
	errcode_t retval = 0;
	void **p = ptr;

	if (align < 8)
		align = 8;
#ifdef HAVE_POSIX_MEMALIGN
	retval = posix_memalign(p, align, size);
	if (retval == ENOMEM)
		return EXT2_ET_NO_MEMORY;
#else  /* !HAVE_POSIX_MEMALIGN */
#ifdef HAVE_MEMALIGN
	*p = memalign(align, size);
	if (*p == NULL) {
		if (errno)
			return errno;
		else
			return EXT2_ET_NO_MEMORY;
	}
#else  /* !HAVE_MEMALIGN */
#ifdef HAVE_VALLOC
	if (align > sizeof(long long))
		*p = valloc(size);
	else
#endif
		*p = malloc(size);
	if ((uintptr_t) *p & (align - 1)) {
		free(*p);
		*p = 0;
	}
	if (*p == 0)
		return EXT2_ET_NO_MEMORY;
#endif	/* HAVE_MEMALIGN */
#endif	/* HAVE_POSIX_MEMALIGN */
	return retval;
}

