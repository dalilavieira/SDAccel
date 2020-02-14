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
struct map_info {int dummy; } ;
typedef  long ssize_t ;
struct TYPE_4__ {int /*<<< orphan*/ * x; } ;
typedef  TYPE_1__ map_word ;

/* Variables and functions */
 unsigned long DEVICE_ENABLE ; 
 int /*<<< orphan*/  PAGE_IO ; 
 int /*<<< orphan*/  PAGE_IO_SIZE ; 
 unsigned long WINDOW_LENGTH ; 
 unsigned long WINDOW_MASK ; 
 unsigned long WINDOW_SHIFT ; 
 scalar_t__ all_mtd ; 
 scalar_t__ iomapadr ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  map_destroy (scalar_t__) ; 
 int /*<<< orphan*/  memcpy_fromio (void*,scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  memcpy_toio (scalar_t__,void const*,unsigned long) ; 
 int /*<<< orphan*/  mtd_device_unregister (scalar_t__) ; 
 int /*<<< orphan*/  outw (unsigned long,int /*<<< orphan*/ ) ; 
 unsigned long page_in_window ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int /*<<< orphan*/  release_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sbc_gxx_spin ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void sbc_gxx_page(struct map_info *map, unsigned long ofs)
{
	unsigned long page = ofs >> WINDOW_SHIFT;

	if( page!=page_in_window ) {
		outw( page | DEVICE_ENABLE, PAGE_IO );
		page_in_window = page;
	}
}

__attribute__((used)) static map_word sbc_gxx_read8(struct map_info *map, unsigned long ofs)
{
	map_word ret;
	spin_lock(&sbc_gxx_spin);
	sbc_gxx_page(map, ofs);
	ret.x[0] = readb(iomapadr + (ofs & WINDOW_MASK));
	spin_unlock(&sbc_gxx_spin);
	return ret;
}

__attribute__((used)) static void sbc_gxx_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
	while(len) {
		unsigned long thislen = len;
		if (len > (WINDOW_LENGTH - (from & WINDOW_MASK)))
			thislen = WINDOW_LENGTH-(from & WINDOW_MASK);

		spin_lock(&sbc_gxx_spin);
		sbc_gxx_page(map, from);
		memcpy_fromio(to, iomapadr + (from & WINDOW_MASK), thislen);
		spin_unlock(&sbc_gxx_spin);
		to += thislen;
		from += thislen;
		len -= thislen;
	}
}

__attribute__((used)) static void sbc_gxx_write8(struct map_info *map, map_word d, unsigned long adr)
{
	spin_lock(&sbc_gxx_spin);
	sbc_gxx_page(map, adr);
	writeb(d.x[0], iomapadr + (adr & WINDOW_MASK));
	spin_unlock(&sbc_gxx_spin);
}

__attribute__((used)) static void sbc_gxx_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	while(len) {
		unsigned long thislen = len;
		if (len > (WINDOW_LENGTH - (to & WINDOW_MASK)))
			thislen = WINDOW_LENGTH-(to & WINDOW_MASK);

		spin_lock(&sbc_gxx_spin);
		sbc_gxx_page(map, to);
		memcpy_toio(iomapadr + (to & WINDOW_MASK), from, thislen);
		spin_unlock(&sbc_gxx_spin);
		to += thislen;
		from += thislen;
		len -= thislen;
	}
}

__attribute__((used)) static void cleanup_sbc_gxx(void)
{
	if( all_mtd ) {
		mtd_device_unregister(all_mtd);
		map_destroy( all_mtd );
	}

	iounmap(iomapadr);
	release_region(PAGE_IO,PAGE_IO_SIZE);
}

