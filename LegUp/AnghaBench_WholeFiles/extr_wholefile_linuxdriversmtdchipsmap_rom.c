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
struct mtd_info {unsigned int size; int (* _point ) (struct mtd_info*,int,size_t,size_t*,void**,int*) ;int (* _unpoint ) (struct mtd_info*,int,size_t) ;int (* _read ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/ *) ;int (* _write ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/  const*) ;void (* _sync ) (struct mtd_info*) ;int (* _erase ) (struct mtd_info*,struct erase_info*) ;unsigned int erasesize; int writesize; int writebufsize; struct map_info* priv; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; int /*<<< orphan*/  name; } ;
struct map_info {unsigned int size; int phys; void* virt; int /*<<< orphan*/  name; int /*<<< orphan*/ * fldrv; int /*<<< orphan*/  device_node; } ;
struct erase_info {int dummy; } ;
typedef  int resource_size_t ;
typedef  int loff_t ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int EINVAL ; 
 int EROFS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MTD_CAP_ROM ; 
 int /*<<< orphan*/  MTD_ROM ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __module_get (int /*<<< orphan*/ ) ; 
 unsigned int be32_to_cpu (int /*<<< orphan*/  const) ; 
 struct mtd_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  map_copy_from (struct map_info*,int /*<<< orphan*/ *,int,size_t) ; 
 int /*<<< orphan*/  maprom_chipdrv ; 
static  int maprom_erase (struct mtd_info*,struct erase_info*) ; 
static  void maprom_nop (struct mtd_info*) ; 
static  int maprom_point (struct mtd_info*,int,size_t,size_t*,void**,int*) ; 
static  int maprom_read (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/ *) ; 
static  int maprom_unpoint (struct mtd_info*,int,size_t) ; 
static  int maprom_write (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * of_get_property (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static unsigned int default_erasesize(struct map_info *map)
{
	const __be32 *erase_size = NULL;

	erase_size = of_get_property(map->device_node, "erase-size", NULL);

	return !erase_size ? map->size : be32_to_cpu(*erase_size);
}

__attribute__((used)) static struct mtd_info *map_rom_probe(struct map_info *map)
{
	struct mtd_info *mtd;

	mtd = kzalloc(sizeof(*mtd), GFP_KERNEL);
	if (!mtd)
		return NULL;

	map->fldrv = &maprom_chipdrv;
	mtd->priv = map;
	mtd->name = map->name;
	mtd->type = MTD_ROM;
	mtd->size = map->size;
	mtd->_point = maprom_point;
	mtd->_unpoint = maprom_unpoint;
	mtd->_read = maprom_read;
	mtd->_write = maprom_write;
	mtd->_sync = maprom_nop;
	mtd->_erase = maprom_erase;
	mtd->flags = MTD_CAP_ROM;
	mtd->erasesize = default_erasesize(map);
	mtd->writesize = 1;
	mtd->writebufsize = 1;

	__module_get(THIS_MODULE);
	return mtd;
}

__attribute__((used)) static int maprom_point(struct mtd_info *mtd, loff_t from, size_t len,
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

__attribute__((used)) static int maprom_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
	return 0;
}

__attribute__((used)) static int maprom_read (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf)
{
	struct map_info *map = mtd->priv;

	map_copy_from(map, buf, from, len);
	*retlen = len;
	return 0;
}

__attribute__((used)) static void maprom_nop(struct mtd_info *mtd)
{
	/* Nothing to see here */
}

__attribute__((used)) static int maprom_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
	return -EROFS;
}

__attribute__((used)) static int maprom_erase (struct mtd_info *mtd, struct erase_info *info)
{
	/* We do our best 8) */
	return -EROFS;
}

