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
typedef  unsigned char uint8_t ;
typedef  unsigned int uint32_t ;
typedef  unsigned short uint16_t ;
struct libfat_filesystem {int dummy; } ;
struct libfat_direntry {int offset; scalar_t__ sector; int /*<<< orphan*/  entry; } ;
struct fat_dirent {scalar_t__* name; int /*<<< orphan*/  clusthi; int /*<<< orphan*/  clustlo; int /*<<< orphan*/  size; } ;
typedef  scalar_t__ libfat_sector_t ;
typedef  unsigned char le8_t ;
typedef  int /*<<< orphan*/  le32_t ;
typedef  int /*<<< orphan*/  le16_t ;
typedef  int int32_t ;

/* Variables and functions */
 int LIBFAT_SECTOR_SIZE ; 
 scalar_t__ libfat_clustertosector (struct libfat_filesystem*,int) ; 
 struct fat_dirent* libfat_get_sector (struct libfat_filesystem*,scalar_t__) ; 
 scalar_t__ libfat_nextsector (struct libfat_filesystem*,scalar_t__) ; 
 int /*<<< orphan*/  memcmp (scalar_t__*,void const*,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,struct fat_dirent*,int) ; 

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

int32_t libfat_searchdir(struct libfat_filesystem *fs, int32_t dirclust,
			 const void *name, struct libfat_direntry *direntry)
{
    struct fat_dirent *dep;
    int nent;
    libfat_sector_t s = libfat_clustertosector(fs, dirclust);

    while (1) {
	if (s == 0)
	    return -2;		/* Not found */
	else if (s == (libfat_sector_t) - 1)
	    return -1;		/* Error */

	dep = libfat_get_sector(fs, s);
	if (!dep)
	    return -1;		/* Read error */

	for (nent = 0; nent < LIBFAT_SECTOR_SIZE;
	     nent += sizeof(struct fat_dirent)) {
	    if (!memcmp(dep->name, name, 11)) {
		if (direntry) {
		    memcpy(direntry->entry, dep, sizeof(*dep));
		    direntry->sector = s;
		    direntry->offset = nent;
		}
		if (read32(&dep->size) == 0)
		    return 0;	/* An empty file has no clusters */
		else
		    return read16(&dep->clustlo) +
			(read16(&dep->clusthi) << 16);
	    }

	    if (dep->name[0] == 0)
		return -2;	/* Hit high water mark */

	    dep++;
	}

	s = libfat_nextsector(fs, s);
    }
}

