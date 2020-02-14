#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;
typedef  struct TYPE_18__   TYPE_13__ ;
typedef  struct TYPE_17__   TYPE_12__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_18__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_13__ dev; } ;
struct map_info {scalar_t__ map_priv_1; scalar_t__ virt; } ;
struct ltq_mtd {TYPE_5__* mtd; TYPE_12__* map; TYPE_3__* res; } ;
struct cfi_private {int addr_unlock1; int addr_unlock2; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_20__ {int /*<<< orphan*/ * x; } ;
typedef  TYPE_2__ map_word ;
struct TYPE_19__ {TYPE_13__* parent; } ;
struct TYPE_22__ {TYPE_1__ dev; } ;
struct TYPE_21__ {int /*<<< orphan*/  start; } ;
struct TYPE_17__ {int bankwidth; void (* write ) (struct map_info*,TYPE_2__,unsigned long) ;void (* copy_from ) (struct map_info*,void*,unsigned long,int /*<<< orphan*/ ) ;void (* copy_to ) (struct map_info*,unsigned long,void const*,int /*<<< orphan*/ ) ;struct cfi_private* fldrv_priv; scalar_t__ map_priv_1; TYPE_2__ (* read ) (struct map_info*,unsigned long) ;int /*<<< orphan*/  name; int /*<<< orphan*/  virt; int /*<<< orphan*/  size; int /*<<< orphan*/  phys; } ;

/* Variables and functions */
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ LTQ_NOR_NORMAL ; 
 scalar_t__ LTQ_NOR_PROBING ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_13__*,char*) ; 
 int /*<<< orphan*/  devm_ioremap_resource (TYPE_13__*,TYPE_3__*) ; 
 void* devm_kzalloc (TYPE_13__*,int,int /*<<< orphan*/ ) ; 
 TYPE_5__* do_map_probe (char*,TYPE_12__*) ; 
 int /*<<< orphan*/  ebu_lock ; 
 int /*<<< orphan*/  ltq_map_name ; 
 int /*<<< orphan*/  map_destroy (TYPE_5__*) ; 
 int mtd_device_register (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtd_device_unregister (TYPE_5__*) ; 
 int /*<<< orphan*/  mtd_set_of_node (TYPE_5__*,int /*<<< orphan*/ ) ; 
 struct ltq_mtd* platform_get_drvdata (struct platform_device*) ; 
 TYPE_3__* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ltq_mtd*) ; 
 int /*<<< orphan*/  resource_size (TYPE_3__*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static map_word
ltq_read16(struct map_info *map, unsigned long adr)
{
	unsigned long flags;
	map_word temp;

	if (map->map_priv_1 == LTQ_NOR_PROBING)
		adr ^= 2;
	spin_lock_irqsave(&ebu_lock, flags);
	temp.x[0] = *(u16 *)(map->virt + adr);
	spin_unlock_irqrestore(&ebu_lock, flags);
	return temp;
}

__attribute__((used)) static void
ltq_write16(struct map_info *map, map_word d, unsigned long adr)
{
	unsigned long flags;

	if (map->map_priv_1 == LTQ_NOR_PROBING)
		adr ^= 2;
	spin_lock_irqsave(&ebu_lock, flags);
	*(u16 *)(map->virt + adr) = d.x[0];
	spin_unlock_irqrestore(&ebu_lock, flags);
}

__attribute__((used)) static void
ltq_copy_from(struct map_info *map, void *to,
	unsigned long from, ssize_t len)
{
	unsigned char *f = (unsigned char *)map->virt + from;
	unsigned char *t = (unsigned char *)to;
	unsigned long flags;

	spin_lock_irqsave(&ebu_lock, flags);
	while (len--)
		*t++ = *f++;
	spin_unlock_irqrestore(&ebu_lock, flags);
}

__attribute__((used)) static void
ltq_copy_to(struct map_info *map, unsigned long to,
	const void *from, ssize_t len)
{
	unsigned char *f = (unsigned char *)from;
	unsigned char *t = (unsigned char *)map->virt + to;
	unsigned long flags;

	spin_lock_irqsave(&ebu_lock, flags);
	while (len--)
		*t++ = *f++;
	spin_unlock_irqrestore(&ebu_lock, flags);
}

__attribute__((used)) static int
ltq_mtd_probe(struct platform_device *pdev)
{
	struct ltq_mtd *ltq_mtd;
	struct cfi_private *cfi;
	int err;

	ltq_mtd = devm_kzalloc(&pdev->dev, sizeof(struct ltq_mtd), GFP_KERNEL);
	if (!ltq_mtd)
		return -ENOMEM;

	platform_set_drvdata(pdev, ltq_mtd);

	ltq_mtd->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!ltq_mtd->res) {
		dev_err(&pdev->dev, "failed to get memory resource\n");
		return -ENOENT;
	}

	ltq_mtd->map = devm_kzalloc(&pdev->dev, sizeof(struct map_info),
				    GFP_KERNEL);
	if (!ltq_mtd->map)
		return -ENOMEM;

	ltq_mtd->map->phys = ltq_mtd->res->start;
	ltq_mtd->map->size = resource_size(ltq_mtd->res);
	ltq_mtd->map->virt = devm_ioremap_resource(&pdev->dev, ltq_mtd->res);
	if (IS_ERR(ltq_mtd->map->virt))
		return PTR_ERR(ltq_mtd->map->virt);

	ltq_mtd->map->name = ltq_map_name;
	ltq_mtd->map->bankwidth = 2;
	ltq_mtd->map->read = ltq_read16;
	ltq_mtd->map->write = ltq_write16;
	ltq_mtd->map->copy_from = ltq_copy_from;
	ltq_mtd->map->copy_to = ltq_copy_to;

	ltq_mtd->map->map_priv_1 = LTQ_NOR_PROBING;
	ltq_mtd->mtd = do_map_probe("cfi_probe", ltq_mtd->map);
	ltq_mtd->map->map_priv_1 = LTQ_NOR_NORMAL;

	if (!ltq_mtd->mtd) {
		dev_err(&pdev->dev, "probing failed\n");
		return -ENXIO;
	}

	ltq_mtd->mtd->dev.parent = &pdev->dev;
	mtd_set_of_node(ltq_mtd->mtd, pdev->dev.of_node);

	cfi = ltq_mtd->map->fldrv_priv;
	cfi->addr_unlock1 ^= 1;
	cfi->addr_unlock2 ^= 1;

	err = mtd_device_register(ltq_mtd->mtd, NULL, 0);
	if (err) {
		dev_err(&pdev->dev, "failed to add partitions\n");
		goto err_destroy;
	}

	return 0;

err_destroy:
	map_destroy(ltq_mtd->mtd);
	return err;
}

__attribute__((used)) static int
ltq_mtd_remove(struct platform_device *pdev)
{
	struct ltq_mtd *ltq_mtd = platform_get_drvdata(pdev);

	if (ltq_mtd && ltq_mtd->mtd) {
		mtd_device_unregister(ltq_mtd->mtd);
		map_destroy(ltq_mtd->mtd);
	}
	return 0;
}

