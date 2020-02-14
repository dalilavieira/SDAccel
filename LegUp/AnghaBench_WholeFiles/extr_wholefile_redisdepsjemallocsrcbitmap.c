#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t bitmap_t ;
struct TYPE_6__ {size_t ngroups; size_t nbits; } ;
typedef  TYPE_1__ bitmap_info_t ;

/* Variables and functions */
 size_t BITMAP_BITS2GROUPS (size_t) ; 
 size_t BITMAP_GROUP_NBITS ; 
 size_t BITMAP_GROUP_NBITS_MASK ; 
 size_t LG_BITMAP_MAXBITS ; 
 size_t LG_SIZEOF_BITMAP ; 
 size_t ZU (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 size_t bitmap_size (TYPE_1__ const*) ; 
 int /*<<< orphan*/  memset (size_t*,int,size_t) ; 

void
bitmap_info_init(bitmap_info_t *binfo, size_t nbits) {
	assert(nbits > 0);
	assert(nbits <= (ZU(1) << LG_BITMAP_MAXBITS));

	binfo->ngroups = BITMAP_BITS2GROUPS(nbits);
	binfo->nbits = nbits;
}

__attribute__((used)) static size_t
bitmap_info_ngroups(const bitmap_info_t *binfo) {
	return binfo->ngroups;
}

void
bitmap_init(bitmap_t *bitmap, const bitmap_info_t *binfo, bool fill) {
	size_t extra;

	if (fill) {
		memset(bitmap, 0, bitmap_size(binfo));
		return;
	}

	memset(bitmap, 0xffU, bitmap_size(binfo));
	extra = (BITMAP_GROUP_NBITS - (binfo->nbits & BITMAP_GROUP_NBITS_MASK))
	    & BITMAP_GROUP_NBITS_MASK;
	if (extra != 0) {
		bitmap[binfo->ngroups - 1] >>= extra;
	}
}

size_t
bitmap_size(const bitmap_info_t *binfo) {
	return (bitmap_info_ngroups(binfo) << LG_SIZEOF_BITMAP);
}

