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
typedef  int /*<<< orphan*/  u_char ;
struct mtd_info {int size; int (* _erase ) (struct mtd_info*,struct erase_info*) ;int (* _read ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/ *) ;int (* _write ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/  const*) ;int (* _panic_write ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/  const*) ;int (* _point ) (struct mtd_info*,int,size_t,size_t*,void**,int*) ;void (* _sync ) (struct mtd_info*) ;int (* _unpoint ) (struct mtd_info*,int,size_t) ;int writesize; int erasesize; struct map_info* priv; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; int /*<<< orphan*/  name; } ;
struct map_info {int size; int phys; void* virt; int /*<<< orphan*/  name; int /*<<< orphan*/ * fldrv; } ;
struct erase_info {unsigned long len; scalar_t__ addr; } ;
typedef  int resource_size_t ;
typedef  int /*<<< orphan*/  map_word ;
typedef  int loff_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MTD_CAP_RAM ; 
 int /*<<< orphan*/  MTD_RAM ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __module_get (int /*<<< orphan*/ ) ; 
 struct mtd_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ map_bankwidth (struct map_info*) ; 
 int /*<<< orphan*/  map_copy_from (struct map_info*,int /*<<< orphan*/ *,int,size_t) ; 
 int /*<<< orphan*/  map_copy_to (struct map_info*,int,int /*<<< orphan*/  const*,size_t) ; 
 int /*<<< orphan*/  map_word_ff (struct map_info*) ; 
 int /*<<< orphan*/  map_write (struct map_info*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  mapram_chipdrv ; 
static  int mapram_erase (struct mtd_info*,struct erase_info*) ; 
static  void mapram_nop (struct mtd_info*) ; 
static  int mapram_point (struct mtd_info*,int,size_t,size_t*,void**,int*) ; 
static  int mapram_read (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/ *) ; 
static  int mapram_unpoint (struct mtd_info*,int,size_t) ; 
static  int mapram_write (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static struct mtd_info *map_ram_probe(struct map_info *map)
{
	struct mtd_info *mtd;

	/* Check the first byte is RAM */
#if 0
	map_write8(map, 0x55, 0);
	if (map_read8(map, 0) != 0x55)
		return NULL;

	map_write8(map, 0xAA, 0);
	if (map_read8(map, 0) != 0xAA)
		return NULL;

	/* Check the last byte is RAM */
	map_write8(map, 0x55, map->size-1);
	if (map_read8(map, map->size-1) != 0x55)
		return NULL;

	map_write8(map, 0xAA, map->size-1);
	if (map_read8(map, map->size-1) != 0xAA)
		return NULL;
#endif
	/* OK. It seems to be RAM. */

	mtd = kzalloc(sizeof(*mtd), GFP_KERNEL);
	if (!mtd)
		return NULL;

	map->fldrv = &mapram_chipdrv;
	mtd->priv = map;
	mtd->name = map->name;
	mtd->type = MTD_RAM;
	mtd->size = map->size;
	mtd->_erase = mapram_erase;
	mtd->_read = mapram_read;
	mtd->_write = mapram_write;
	mtd->_panic_write = mapram_write;
	mtd->_point = mapram_point;
	mtd->_sync = mapram_nop;
	mtd->_unpoint = mapram_unpoint;
	mtd->flags = MTD_CAP_RAM;
	mtd->writesize = 1;

	mtd->erasesize = PAGE_SIZE;
 	while(mtd->size & (mtd->erasesize - 1))
		mtd->erasesize >>= 1;

	__module_get(THIS_MODULE);
	return mtd;
}

__attribute__((used)) static int mapram_point(struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, void **virt, resource_size_t *phys)
{
	struct map_info *map = mtd->priv;

	if (!map->virt)
		return -EINVAL;
	*virt = map->virt + from;
	if (phys)
		*phys = map->phys + from;
	*retlen = len;
	return 0;
}

__attribute__((used)) static int mapram_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
	return 0;
}

__attribute__((used)) static int mapram_read (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf)
{
	struct map_info *map = mtd->priv;

	map_copy_from(map, buf, from, len);
	*retlen = len;
	return 0;
}

__attribute__((used)) static int mapram_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
	struct map_info *map = mtd->priv;

	map_copy_to(map, to, buf, len);
	*retlen = len;
	return 0;
}

__attribute__((used)) static int mapram_erase (struct mtd_info *mtd, struct erase_info *instr)
{
	/* Yeah, it's inefficient. Who cares? It's faster than a _real_
	   flash erase. */
	struct map_info *map = mtd->priv;
	map_word allff;
	unsigned long i;

	allff = map_word_ff(map);
	for (i=0; i<instr->len; i += map_bankwidth(map))
		map_write(map, allff, instr->addr + i);
	return 0;
}

__attribute__((used)) static void mapram_nop(struct mtd_info *mtd)
{
	/* Nothing to see here */
}

