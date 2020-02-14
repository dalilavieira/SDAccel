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
typedef  int /*<<< orphan*/  u_char ;
struct mtd_info {TYPE_1__* priv; } ;
struct erase_info {int addr; int /*<<< orphan*/  len; } ;
struct TYPE_8__ {int start; int end; } ;
typedef  TYPE_1__ slram_priv_t ;
struct TYPE_9__ {char* name; unsigned long size; int (* _erase ) (struct mtd_info*,struct erase_info*) ;int (* _point ) (struct mtd_info*,int,size_t,size_t*,void**,int /*<<< orphan*/ *) ;int (* _unpoint ) (struct mtd_info*,int,size_t) ;int (* _read ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/ *) ;int (* _write ) (struct mtd_info*,int,size_t,size_t*,int /*<<< orphan*/  const*) ;unsigned long erasesize; int writesize; struct TYPE_9__* mtdinfo; struct TYPE_9__* priv; struct TYPE_9__* next; int /*<<< orphan*/  type; int /*<<< orphan*/  owner; int /*<<< orphan*/  flags; } ;
typedef  TYPE_2__ slram_mtd_list_t ;
typedef  int /*<<< orphan*/  resource_size_t ;
typedef  int loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  E (char*) ; 
 int EAGAIN ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MEMREMAP_WB ; 
 int MEMREMAP_WC ; 
 int MEMREMAP_WT ; 
 int /*<<< orphan*/  MTD_CAP_RAM ; 
 int /*<<< orphan*/  MTD_RAM ; 
 unsigned long SLRAM_BLK_SZ ; 
 int /*<<< orphan*/  T (char*,...) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  kfree (TYPE_2__*) ; 
 TYPE_2__* kmalloc (int,int /*<<< orphan*/ ) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int,int,size_t) ; 
 int memremap (unsigned long,unsigned long,int) ; 
 int /*<<< orphan*/  memset (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memunmap (int) ; 
 scalar_t__ mtd_device_register (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtd_device_unregister (TYPE_2__*) ; 
 unsigned long simple_strtoul (char*,char**,int /*<<< orphan*/ ) ; 
 TYPE_2__* slram_mtdlist ; 

__attribute__((used)) static int slram_erase(struct mtd_info *mtd, struct erase_info *instr)
{
	slram_priv_t *priv = mtd->priv;

	memset(priv->start + instr->addr, 0xff, instr->len);

	return(0);
}

__attribute__((used)) static int slram_point(struct mtd_info *mtd, loff_t from, size_t len,
		size_t *retlen, void **virt, resource_size_t *phys)
{
	slram_priv_t *priv = mtd->priv;

	*virt = priv->start + from;
	*retlen = len;
	return(0);
}

__attribute__((used)) static int slram_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
	return 0;
}

__attribute__((used)) static int slram_read(struct mtd_info *mtd, loff_t from, size_t len,
		size_t *retlen, u_char *buf)
{
	slram_priv_t *priv = mtd->priv;

	memcpy(buf, priv->start + from, len);
	*retlen = len;
	return(0);
}

__attribute__((used)) static int slram_write(struct mtd_info *mtd, loff_t to, size_t len,
		size_t *retlen, const u_char *buf)
{
	slram_priv_t *priv = mtd->priv;

	memcpy(priv->start + to, buf, len);
	*retlen = len;
	return(0);
}

__attribute__((used)) static int register_device(char *name, unsigned long start, unsigned long length)
{
	slram_mtd_list_t **curmtd;

	curmtd = &slram_mtdlist;
	while (*curmtd) {
		curmtd = &(*curmtd)->next;
	}

	*curmtd = kmalloc(sizeof(slram_mtd_list_t), GFP_KERNEL);
	if (!(*curmtd)) {
		E("slram: Cannot allocate new MTD device.\n");
		return(-ENOMEM);
	}
	(*curmtd)->mtdinfo = kzalloc(sizeof(struct mtd_info), GFP_KERNEL);
	(*curmtd)->next = NULL;

	if ((*curmtd)->mtdinfo)	{
		(*curmtd)->mtdinfo->priv =
			kzalloc(sizeof(slram_priv_t), GFP_KERNEL);

		if (!(*curmtd)->mtdinfo->priv) {
			kfree((*curmtd)->mtdinfo);
			(*curmtd)->mtdinfo = NULL;
		}
	}

	if (!(*curmtd)->mtdinfo) {
		E("slram: Cannot allocate new MTD device.\n");
		return(-ENOMEM);
	}

	if (!(((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start =
		memremap(start, length,
			 MEMREMAP_WB | MEMREMAP_WT | MEMREMAP_WC))) {
		E("slram: memremap failed\n");
		return -EIO;
	}
	((slram_priv_t *)(*curmtd)->mtdinfo->priv)->end =
		((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start + length;


	(*curmtd)->mtdinfo->name = name;
	(*curmtd)->mtdinfo->size = length;
	(*curmtd)->mtdinfo->flags = MTD_CAP_RAM;
	(*curmtd)->mtdinfo->_erase = slram_erase;
	(*curmtd)->mtdinfo->_point = slram_point;
	(*curmtd)->mtdinfo->_unpoint = slram_unpoint;
	(*curmtd)->mtdinfo->_read = slram_read;
	(*curmtd)->mtdinfo->_write = slram_write;
	(*curmtd)->mtdinfo->owner = THIS_MODULE;
	(*curmtd)->mtdinfo->type = MTD_RAM;
	(*curmtd)->mtdinfo->erasesize = SLRAM_BLK_SZ;
	(*curmtd)->mtdinfo->writesize = 1;

	if (mtd_device_register((*curmtd)->mtdinfo, NULL, 0))	{
		E("slram: Failed to register new device\n");
		memunmap(((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start);
		kfree((*curmtd)->mtdinfo->priv);
		kfree((*curmtd)->mtdinfo);
		return(-EAGAIN);
	}
	T("slram: Registered device %s from %luKiB to %luKiB\n", name,
			(start / 1024), ((start + length) / 1024));
	T("slram: Mapped from 0x%p to 0x%p\n",
			((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start,
			((slram_priv_t *)(*curmtd)->mtdinfo->priv)->end);
	return(0);
}

__attribute__((used)) static void unregister_devices(void)
{
	slram_mtd_list_t *nextitem;

	while (slram_mtdlist) {
		nextitem = slram_mtdlist->next;
		mtd_device_unregister(slram_mtdlist->mtdinfo);
		memunmap(((slram_priv_t *)slram_mtdlist->mtdinfo->priv)->start);
		kfree(slram_mtdlist->mtdinfo->priv);
		kfree(slram_mtdlist->mtdinfo);
		kfree(slram_mtdlist);
		slram_mtdlist = nextitem;
	}
}

__attribute__((used)) static unsigned long handle_unit(unsigned long value, char *unit)
{
	if ((*unit == 'M') || (*unit == 'm')) {
		return(value * 1024 * 1024);
	} else if ((*unit == 'K') || (*unit == 'k')) {
		return(value * 1024);
	}
	return(value);
}

__attribute__((used)) static int parse_cmdline(char *devname, char *szstart, char *szlength)
{
	char *buffer;
	unsigned long devstart;
	unsigned long devlength;

	if ((!devname) || (!szstart) || (!szlength)) {
		unregister_devices();
		return(-EINVAL);
	}

	devstart = simple_strtoul(szstart, &buffer, 0);
	devstart = handle_unit(devstart, buffer);

	if (*(szlength) != '+') {
		devlength = simple_strtoul(szlength, &buffer, 0);
		devlength = handle_unit(devlength, buffer);
		if (devlength < devstart)
			goto err_out;

		devlength -= devstart;
	} else {
		devlength = simple_strtoul(szlength + 1, &buffer, 0);
		devlength = handle_unit(devlength, buffer);
	}
	T("slram: devname=%s, devstart=0x%lx, devlength=0x%lx\n",
			devname, devstart, devlength);
	if (devlength % SLRAM_BLK_SZ != 0)
		goto err_out;

	if ((devstart = register_device(devname, devstart, devlength))){
		unregister_devices();
		return((int)devstart);
	}
	return(0);

err_out:
	E("slram: Illegal length parameter.\n");
	return(-EINVAL);
}

