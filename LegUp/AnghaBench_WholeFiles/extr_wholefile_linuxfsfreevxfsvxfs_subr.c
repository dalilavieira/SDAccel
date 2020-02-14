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
typedef  int /*<<< orphan*/  u_long ;
struct page {int dummy; } ;
struct inode {int /*<<< orphan*/  i_sb; } ;
struct file {int dummy; } ;
struct buffer_head {int dummy; } ;
struct address_space {int dummy; } ;
typedef  int sector_t ;
typedef  scalar_t__ daddr_t ;

/* Variables and functions */
 int EIO ; 
 struct page* ERR_PTR (int) ; 
 int /*<<< orphan*/  IS_ERR (struct page*) ; 
 scalar_t__ PageError (struct page*) ; 
 int block_read_full_page (struct page*,int (*) (struct inode*,int,struct buffer_head*,int)) ; 
 int generic_block_bmap (struct address_space*,int,int (*) (struct inode*,int,struct buffer_head*,int)) ; 
 int /*<<< orphan*/  kmap (struct page*) ; 
 int /*<<< orphan*/  kunmap (struct page*) ; 
 int /*<<< orphan*/  map_bh (struct buffer_head*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 struct page* read_mapping_page (struct address_space*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct buffer_head* sb_bread (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ vxfs_bmap1 (struct inode*,int) ; 

inline void
vxfs_put_page(struct page *pp)
{
	kunmap(pp);
	put_page(pp);
}

struct page *
vxfs_get_page(struct address_space *mapping, u_long n)
{
	struct page *			pp;

	pp = read_mapping_page(mapping, n, NULL);

	if (!IS_ERR(pp)) {
		kmap(pp);
		/** if (!PageChecked(pp)) **/
			/** vxfs_check_page(pp); **/
		if (PageError(pp))
			goto fail;
	}
	
	return (pp);
		 
fail:
	vxfs_put_page(pp);
	return ERR_PTR(-EIO);
}

struct buffer_head *
vxfs_bread(struct inode *ip, int block)
{
	struct buffer_head	*bp;
	daddr_t			pblock;

	pblock = vxfs_bmap1(ip, block);
	bp = sb_bread(ip->i_sb, pblock);

	return (bp);
}

__attribute__((used)) static int
vxfs_getblk(struct inode *ip, sector_t iblock,
	    struct buffer_head *bp, int create)
{
	daddr_t			pblock;

	pblock = vxfs_bmap1(ip, iblock);
	if (pblock != 0) {
		map_bh(bp, ip->i_sb, pblock);
		return 0;
	}

	return -EIO;
}

__attribute__((used)) static int
vxfs_readpage(struct file *file, struct page *page)
{
	return block_read_full_page(page, vxfs_getblk);
}

__attribute__((used)) static sector_t
vxfs_bmap(struct address_space *mapping, sector_t block)
{
	return generic_block_bmap(mapping, block, vxfs_getblk);
}

