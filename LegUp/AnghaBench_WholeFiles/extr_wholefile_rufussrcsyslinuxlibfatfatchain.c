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
typedef  int uint8_t ;
typedef  unsigned int uint32_t ;
typedef  unsigned short uint16_t ;
struct libfat_filesystem {int rootcluster; int rootdir; int endcluster; int data; int clustshift; unsigned int clustsize; int fat_type; unsigned int fat; } ;
typedef  int libfat_sector_t ;
typedef  unsigned char le8_t ;
typedef  int /*<<< orphan*/  le32_t ;
typedef  int /*<<< orphan*/  le16_t ;
typedef  int int32_t ;

/* Variables and functions */
#define  FAT12 130 
#define  FAT16 129 
#define  FAT28 128 
 unsigned int LIBFAT_SECTOR_MASK ; 
 unsigned int LIBFAT_SECTOR_SHIFT ; 
 int* libfat_get_sector (struct libfat_filesystem*,int) ; 

__attribute__((used)) static inline unsigned char read8(le8_t * _p)
{
    return *_p;
}

__attribute__((used)) static inline void write8(le8_t * _p, uint8_t _v)
{
    *_p = _v;
}

__attribute__((used)) static inline unsigned short read16(le16_t * _p)
{
    return *((const uint16_t *)_p);
}

__attribute__((used)) static inline void write16(le16_t * _p, unsigned short _v)
{
    *((uint16_t *) _p) = _v;
}

__attribute__((used)) static inline unsigned int read32(le32_t * _p)
{
    return *((const uint32_t *)_p);
}

__attribute__((used)) static inline void write32(le32_t * _p, uint32_t _v)
{
    *((uint32_t *) _p) = _v;
}

libfat_sector_t libfat_clustertosector(const struct libfat_filesystem *fs,
				       int32_t cluster)
{
    if (cluster == 0)
	cluster = fs->rootcluster;

    if (cluster == 0)
	return fs->rootdir;
    else if (cluster < 2 || cluster >= fs->endcluster)
	return -1;
    else
	return fs->data + ((libfat_sector_t) (cluster - 2) << fs->clustshift);
}

libfat_sector_t libfat_nextsector(struct libfat_filesystem * fs,
				  libfat_sector_t s)
{
    int32_t cluster, nextcluster;
    uint32_t fatoffset;
    libfat_sector_t fatsect;
    uint8_t *fsdata;
    uint32_t clustmask = fs->clustsize - 1;
    libfat_sector_t rs;

    if (s < fs->data) {
	if (s < fs->rootdir)
	    return -1;

	/* Root directory */
	s++;
	return (s < fs->data) ? s : 0;
    }

    rs = s - fs->data;

    if (~rs & clustmask)
	return s + 1;		/* Next sector in cluster */

    cluster = 2 + (rs >> fs->clustshift);

    if (cluster >= fs->endcluster)
	return -1;

    switch (fs->fat_type) {
    case FAT12:
	/* Get first byte */
	fatoffset = cluster + (cluster >> 1);
	fatsect = fs->fat + (fatoffset >> LIBFAT_SECTOR_SHIFT);
	fsdata = libfat_get_sector(fs, fatsect);
	if (!fsdata)
	    return -1;
	nextcluster = fsdata[fatoffset & LIBFAT_SECTOR_MASK];

	/* Get second byte */
	fatoffset++;
	fatsect = fs->fat + (fatoffset >> LIBFAT_SECTOR_SHIFT);
	fsdata = libfat_get_sector(fs, fatsect);
	if (!fsdata)
	    return -1;
	nextcluster |= fsdata[fatoffset & LIBFAT_SECTOR_MASK] << 8;

	/* Extract the FAT entry */
	if (cluster & 1)
	    nextcluster >>= 4;
	else
	    nextcluster &= 0x0FFF;

	if (nextcluster >= 0x0FF8)
	    return 0;
	break;

    case FAT16:
	fatoffset = cluster << 1;
	fatsect = fs->fat + (fatoffset >> LIBFAT_SECTOR_SHIFT);
	fsdata = libfat_get_sector(fs, fatsect);
	if (!fsdata)
	    return -1;
	nextcluster =
	    read16((le16_t *) & fsdata[fatoffset & LIBFAT_SECTOR_MASK]);

	if (nextcluster >= 0x0FFF8)
	    return 0;
	break;

    case FAT28:
	fatoffset = cluster << 2;
	fatsect = fs->fat + (fatoffset >> LIBFAT_SECTOR_SHIFT);
	fsdata = libfat_get_sector(fs, fatsect);
	if (!fsdata)
	    return -1;
	nextcluster =
	    read32((le32_t *) & fsdata[fatoffset & LIBFAT_SECTOR_MASK]);
	nextcluster &= 0x0FFFFFFF;

	if (nextcluster >= 0x0FFFFFF8)
	    return 0;
	break;

    default:
	return -1;		/* WTF? */
    }

    return libfat_clustertosector(fs, nextcluster);
}

