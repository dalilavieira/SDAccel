#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int (* varsize_frob_t ) (struct map_info*,int /*<<< orphan*/ *,unsigned long,int,void*) ;
typedef  unsigned int uint32_t ;
typedef  unsigned long u_long ;
typedef  unsigned long u_char ;
struct mtd_info {int numeraseregions; struct mtd_erase_region_info* eraseregions; struct map_info* priv; } ;
struct mtd_erase_region_info {int offset; int erasesize; int numblocks; } ;
struct map_info {struct cfi_private* fldrv_priv; } ;
struct cfi_private {unsigned int device_type; scalar_t__ mfr; scalar_t__ id; int chipshift; int numchips; int /*<<< orphan*/ * chips; } ;
struct cfi_fixup {scalar_t__ mfr; scalar_t__ id; int /*<<< orphan*/  (* fixup ) (struct mtd_info*) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_9__ {unsigned long* x; TYPE_1__ member_0; } ;
typedef  TYPE_2__ map_word ;
typedef  int loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 scalar_t__ CFI_ID_ANY ; 
 scalar_t__ CFI_MFR_ANY ; 
 int EINVAL ; 
 unsigned long cfi16_to_cpu (struct map_info*,unsigned long) ; 
 unsigned long cfi32_to_cpu (struct map_info*,unsigned long) ; 
 int cfi_interleave (struct cfi_private*) ; 
 int /*<<< orphan*/  cond_resched () ; 
 unsigned long cpu_to_cfi16 (struct map_info*,unsigned long) ; 
 unsigned long cpu_to_cfi32 (struct map_info*,unsigned long) ; 
 int map_bankwidth (struct map_info*) ; 
 scalar_t__ map_bankwidth_is_large (struct map_info*) ; 
 TYPE_2__ map_read (struct map_info*,unsigned int) ; 
 int /*<<< orphan*/  map_write (struct map_info*,TYPE_2__,unsigned int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  stub1 (struct mtd_info*) ; 
 int stub2 (struct map_info*,int /*<<< orphan*/ *,unsigned long,int,void*) ; 
 int /*<<< orphan*/  udelay (int) ; 

void cfi_udelay(int us)
{
	if (us >= 1000) {
		msleep((us+999)/1000);
	} else {
		udelay(us);
		cond_resched();
	}
}

uint32_t cfi_build_cmd_addr(uint32_t cmd_ofs,
				struct map_info *map, struct cfi_private *cfi)
{
	unsigned bankwidth = map_bankwidth(map);
	unsigned interleave = cfi_interleave(cfi);
	unsigned type = cfi->device_type;
	uint32_t addr;

	addr = (cmd_ofs * type) * interleave;

	/* Modify the unlock address if we are in compatibility mode.
	 * For 16bit devices on 8 bit busses
	 * and 32bit devices on 16 bit busses
	 * set the low bit of the alternating bit sequence of the address.
	 */
	if (((type * interleave) > bankwidth) && ((cmd_ofs & 0xff) == 0xaa))
		addr |= (type >> 1)*interleave;

	return  addr;
}

map_word cfi_build_cmd(u_long cmd, struct map_info *map, struct cfi_private *cfi)
{
	map_word val = { {0} };
	int wordwidth, words_per_bus, chip_mode, chips_per_word;
	unsigned long onecmd;
	int i;

	/* We do it this way to give the compiler a fighting chance
	   of optimising away all the crap for 'bankwidth' larger than
	   an unsigned long, in the common case where that support is
	   disabled */
	if (map_bankwidth_is_large(map)) {
		wordwidth = sizeof(unsigned long);
		words_per_bus = (map_bankwidth(map)) / wordwidth; // i.e. normally 1
	} else {
		wordwidth = map_bankwidth(map);
		words_per_bus = 1;
	}

	chip_mode = map_bankwidth(map) / cfi_interleave(cfi);
	chips_per_word = wordwidth * cfi_interleave(cfi) / map_bankwidth(map);

	/* First, determine what the bit-pattern should be for a single
	   device, according to chip mode and endianness... */
	switch (chip_mode) {
	default: BUG();
	case 1:
		onecmd = cmd;
		break;
	case 2:
		onecmd = cpu_to_cfi16(map, cmd);
		break;
	case 4:
		onecmd = cpu_to_cfi32(map, cmd);
		break;
	}

	/* Now replicate it across the size of an unsigned long, or
	   just to the bus width as appropriate */
	switch (chips_per_word) {
	default: BUG();
#if BITS_PER_LONG >= 64
	case 8:
		onecmd |= (onecmd << (chip_mode * 32));
#endif
	case 4:
		onecmd |= (onecmd << (chip_mode * 16));
	case 2:
		onecmd |= (onecmd << (chip_mode * 8));
	case 1:
		;
	}

	/* And finally, for the multi-word case, replicate it
	   in all words in the structure */
	for (i=0; i < words_per_bus; i++) {
		val.x[i] = onecmd;
	}

	return val;
}

unsigned long cfi_merge_status(map_word val, struct map_info *map,
					   struct cfi_private *cfi)
{
	int wordwidth, words_per_bus, chip_mode, chips_per_word;
	unsigned long onestat, res = 0;
	int i;

	/* We do it this way to give the compiler a fighting chance
	   of optimising away all the crap for 'bankwidth' larger than
	   an unsigned long, in the common case where that support is
	   disabled */
	if (map_bankwidth_is_large(map)) {
		wordwidth = sizeof(unsigned long);
		words_per_bus = (map_bankwidth(map)) / wordwidth; // i.e. normally 1
	} else {
		wordwidth = map_bankwidth(map);
		words_per_bus = 1;
	}

	chip_mode = map_bankwidth(map) / cfi_interleave(cfi);
	chips_per_word = wordwidth * cfi_interleave(cfi) / map_bankwidth(map);

	onestat = val.x[0];
	/* Or all status words together */
	for (i=1; i < words_per_bus; i++) {
		onestat |= val.x[i];
	}

	res = onestat;
	switch(chips_per_word) {
	default: BUG();
#if BITS_PER_LONG >= 64
	case 8:
		res |= (onestat >> (chip_mode * 32));
#endif
	case 4:
		res |= (onestat >> (chip_mode * 16));
	case 2:
		res |= (onestat >> (chip_mode * 8));
	case 1:
		;
	}

	/* Last, determine what the bit-pattern should be for a single
	   device, according to chip mode and endianness... */
	switch (chip_mode) {
	case 1:
		break;
	case 2:
		res = cfi16_to_cpu(map, res);
		break;
	case 4:
		res = cfi32_to_cpu(map, res);
		break;
	default: BUG();
	}
	return res;
}

uint32_t cfi_send_gen_cmd(u_char cmd, uint32_t cmd_addr, uint32_t base,
				struct map_info *map, struct cfi_private *cfi,
				int type, map_word *prev_val)
{
	map_word val;
	uint32_t addr = base + cfi_build_cmd_addr(cmd_addr, map, cfi);
	val = cfi_build_cmd(cmd, map, cfi);

	if (prev_val)
		*prev_val = map_read(map, addr);

	map_write(map, val, addr);

	return addr - base;
}

void cfi_fixup(struct mtd_info *mtd, struct cfi_fixup *fixups)
{
	struct map_info *map = mtd->priv;
	struct cfi_private *cfi = map->fldrv_priv;
	struct cfi_fixup *f;

	for (f=fixups; f->fixup; f++) {
		if (((f->mfr == CFI_MFR_ANY) || (f->mfr == cfi->mfr)) &&
		    ((f->id  == CFI_ID_ANY)  || (f->id  == cfi->id))) {
			f->fixup(mtd);
		}
	}
}

int cfi_varsize_frob(struct mtd_info *mtd, varsize_frob_t frob,
				     loff_t ofs, size_t len, void *thunk)
{
	struct map_info *map = mtd->priv;
	struct cfi_private *cfi = map->fldrv_priv;
	unsigned long adr;
	int chipnum, ret = 0;
	int i, first;
	struct mtd_erase_region_info *regions = mtd->eraseregions;

	/* Check that both start and end of the requested erase are
	 * aligned with the erasesize at the appropriate addresses.
	 */

	i = 0;

	/* Skip all erase regions which are ended before the start of
	   the requested erase. Actually, to save on the calculations,
	   we skip to the first erase region which starts after the
	   start of the requested erase, and then go back one.
	*/

	while (i < mtd->numeraseregions && ofs >= regions[i].offset)
	       i++;
	i--;

	/* OK, now i is pointing at the erase region in which this
	   erase request starts. Check the start of the requested
	   erase range is aligned with the erase size which is in
	   effect here.
	*/

	if (ofs & (regions[i].erasesize-1))
		return -EINVAL;

	/* Remember the erase region we start on */
	first = i;

	/* Next, check that the end of the requested erase is aligned
	 * with the erase region at that address.
	 */

	while (i<mtd->numeraseregions && (ofs + len) >= regions[i].offset)
		i++;

	/* As before, drop back one to point at the region in which
	   the address actually falls
	*/
	i--;

	if ((ofs + len) & (regions[i].erasesize-1))
		return -EINVAL;

	chipnum = ofs >> cfi->chipshift;
	adr = ofs - (chipnum << cfi->chipshift);

	i=first;

	while(len) {
		int size = regions[i].erasesize;

		ret = (*frob)(map, &cfi->chips[chipnum], adr, size, thunk);

		if (ret)
			return ret;

		adr += size;
		ofs += size;
		len -= size;

		if (ofs == regions[i].offset + size * regions[i].numblocks)
			i++;

		if (adr >> cfi->chipshift) {
			adr = 0;
			chipnum++;

			if (chipnum >= cfi->numchips)
				break;
		}
	}

	return 0;
}

