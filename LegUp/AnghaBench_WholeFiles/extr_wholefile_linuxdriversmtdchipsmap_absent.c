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
struct mtd_info {int (* _erase ) (struct mtd_info*,struct erase_info*) ;int (* _read ) (struct mtd_info*,int /*<<< orphan*/ ,size_t,size_t*,int /*<<< orphan*/ *) ;int (* _write ) (struct mtd_info*,int /*<<< orphan*/ ,size_t,size_t*,int /*<<< orphan*/  const*) ;void (* _sync ) (struct mtd_info*) ;int writesize; int /*<<< orphan*/  erasesize; scalar_t__ flags; int /*<<< orphan*/  size; int /*<<< orphan*/  type; int /*<<< orphan*/  name; struct map_info* priv; } ;
struct map_info {int /*<<< orphan*/  size; int /*<<< orphan*/  name; int /*<<< orphan*/ * fldrv; } ;
struct erase_info {int dummy; } ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MTD_ABSENT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __module_get (int /*<<< orphan*/ ) ; 
 struct mtd_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  map_absent_chipdrv ; 
static  int map_absent_erase (struct mtd_info*,struct erase_info*) ; 
static  int map_absent_read (struct mtd_info*,int /*<<< orphan*/ ,size_t,size_t*,int /*<<< orphan*/ *) ; 
static  void map_absent_sync (struct mtd_info*) ; 
static  int map_absent_write (struct mtd_info*,int /*<<< orphan*/ ,size_t,size_t*,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static struct mtd_info *map_absent_probe(struct map_info *map)
{
	struct mtd_info *mtd;

	mtd = kzalloc(sizeof(*mtd), GFP_KERNEL);
	if (!mtd) {
		return NULL;
	}

	map->fldrv 	= &map_absent_chipdrv;
	mtd->priv 	= map;
	mtd->name 	= map->name;
	mtd->type 	= MTD_ABSENT;
	mtd->size 	= map->size;
	mtd->_erase 	= map_absent_erase;
	mtd->_read 	= map_absent_read;
	mtd->_write 	= map_absent_write;
	mtd->_sync 	= map_absent_sync;
	mtd->flags 	= 0;
	mtd->erasesize  = PAGE_SIZE;
	mtd->writesize  = 1;

	__module_get(THIS_MODULE);
	return mtd;
}

__attribute__((used)) static int map_absent_read(struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf)
{
	return -ENODEV;
}

__attribute__((used)) static int map_absent_write(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
	return -ENODEV;
}

__attribute__((used)) static int map_absent_erase(struct mtd_info *mtd, struct erase_info *instr)
{
	return -ENODEV;
}

__attribute__((used)) static void map_absent_sync(struct mtd_info *mtd)
{
	/* nop */
}

__attribute__((used)) static void map_absent_destroy(struct mtd_info *mtd)
{
	/* nop */
}

