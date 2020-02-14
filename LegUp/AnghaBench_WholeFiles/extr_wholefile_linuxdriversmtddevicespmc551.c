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
typedef  int /*<<< orphan*/  const u_char ;
typedef  int u32 ;
struct mypriv {int asize; int base_map0; int curr_map0; void* start; int /*<<< orphan*/  dev; } ;
struct mtd_info {int size; struct mypriv* priv; } ;
struct erase_info {int addr; int len; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
typedef  int loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  PMC551_PCI_MEM_MAP0 ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/  const*,int,int) ; 
 int /*<<< orphan*/  pci_write_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
static  int pmc551_point (struct mtd_info*,int,size_t,size_t*,void**,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pmc551_erase(struct mtd_info *mtd, struct erase_info *instr)
{
	struct mypriv *priv = mtd->priv;
	u32 soff_hi, soff_lo;	/* start address offset hi/lo */
	u32 eoff_hi, eoff_lo;	/* end address offset hi/lo */
	unsigned long end;
	u_char *ptr;
	size_t retlen;

#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_erase(pos:%ld, len:%ld)\n", (long)instr->addr,
		(long)instr->len);
#endif

	end = instr->addr + instr->len - 1;
	eoff_hi = end & ~(priv->asize - 1);
	soff_hi = instr->addr & ~(priv->asize - 1);
	eoff_lo = end & (priv->asize - 1);
	soff_lo = instr->addr & (priv->asize - 1);

	pmc551_point(mtd, instr->addr, instr->len, &retlen,
		     (void **)&ptr, NULL);

	if (soff_hi == eoff_hi || mtd->size == priv->asize) {
		/* The whole thing fits within one access, so just one shot
		   will do it. */
		memset(ptr, 0xff, instr->len);
	} else {
		/* We have to do multiple writes to get all the data
		   written. */
		while (soff_hi != eoff_hi) {
#ifdef CONFIG_MTD_PMC551_DEBUG
			printk(KERN_DEBUG "pmc551_erase() soff_hi: %ld, "
				"eoff_hi: %ld\n", (long)soff_hi, (long)eoff_hi);
#endif
			memset(ptr, 0xff, priv->asize);
			if (soff_hi + priv->asize >= mtd->size) {
				goto out;
			}
			soff_hi += priv->asize;
			pmc551_point(mtd, (priv->base_map0 | soff_hi),
				     priv->asize, &retlen,
				     (void **)&ptr, NULL);
		}
		memset(ptr, 0xff, eoff_lo);
	}

      out:
#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_erase() done\n");
#endif

	return 0;
}

__attribute__((used)) static int pmc551_point(struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, void **virt, resource_size_t *phys)
{
	struct mypriv *priv = mtd->priv;
	u32 soff_hi;
	u32 soff_lo;

#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_point(%ld, %ld)\n", (long)from, (long)len);
#endif

	soff_hi = from & ~(priv->asize - 1);
	soff_lo = from & (priv->asize - 1);

	/* Cheap hack optimization */
	if (priv->curr_map0 != from) {
		pci_write_config_dword(priv->dev, PMC551_PCI_MEM_MAP0,
					(priv->base_map0 | soff_hi));
		priv->curr_map0 = soff_hi;
	}

	*virt = priv->start + soff_lo;
	*retlen = len;
	return 0;
}

__attribute__((used)) static int pmc551_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_unpoint()\n");
#endif
	return 0;
}

__attribute__((used)) static int pmc551_read(struct mtd_info *mtd, loff_t from, size_t len,
			size_t * retlen, u_char * buf)
{
	struct mypriv *priv = mtd->priv;
	u32 soff_hi, soff_lo;	/* start address offset hi/lo */
	u32 eoff_hi, eoff_lo;	/* end address offset hi/lo */
	unsigned long end;
	u_char *ptr;
	u_char *copyto = buf;

#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_read(pos:%ld, len:%ld) asize: %ld\n",
		(long)from, (long)len, (long)priv->asize);
#endif

	end = from + len - 1;
	soff_hi = from & ~(priv->asize - 1);
	eoff_hi = end & ~(priv->asize - 1);
	soff_lo = from & (priv->asize - 1);
	eoff_lo = end & (priv->asize - 1);

	pmc551_point(mtd, from, len, retlen, (void **)&ptr, NULL);

	if (soff_hi == eoff_hi) {
		/* The whole thing fits within one access, so just one shot
		   will do it. */
		memcpy(copyto, ptr, len);
		copyto += len;
	} else {
		/* We have to do multiple writes to get all the data
		   written. */
		while (soff_hi != eoff_hi) {
#ifdef CONFIG_MTD_PMC551_DEBUG
			printk(KERN_DEBUG "pmc551_read() soff_hi: %ld, "
				"eoff_hi: %ld\n", (long)soff_hi, (long)eoff_hi);
#endif
			memcpy(copyto, ptr, priv->asize);
			copyto += priv->asize;
			if (soff_hi + priv->asize >= mtd->size) {
				goto out;
			}
			soff_hi += priv->asize;
			pmc551_point(mtd, soff_hi, priv->asize, retlen,
				     (void **)&ptr, NULL);
		}
		memcpy(copyto, ptr, eoff_lo);
		copyto += eoff_lo;
	}

      out:
#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_read() done\n");
#endif
	*retlen = copyto - buf;
	return 0;
}

__attribute__((used)) static int pmc551_write(struct mtd_info *mtd, loff_t to, size_t len,
			size_t * retlen, const u_char * buf)
{
	struct mypriv *priv = mtd->priv;
	u32 soff_hi, soff_lo;	/* start address offset hi/lo */
	u32 eoff_hi, eoff_lo;	/* end address offset hi/lo */
	unsigned long end;
	u_char *ptr;
	const u_char *copyfrom = buf;

#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_write(pos:%ld, len:%ld) asize:%ld\n",
		(long)to, (long)len, (long)priv->asize);
#endif

	end = to + len - 1;
	soff_hi = to & ~(priv->asize - 1);
	eoff_hi = end & ~(priv->asize - 1);
	soff_lo = to & (priv->asize - 1);
	eoff_lo = end & (priv->asize - 1);

	pmc551_point(mtd, to, len, retlen, (void **)&ptr, NULL);

	if (soff_hi == eoff_hi) {
		/* The whole thing fits within one access, so just one shot
		   will do it. */
		memcpy(ptr, copyfrom, len);
		copyfrom += len;
	} else {
		/* We have to do multiple writes to get all the data
		   written. */
		while (soff_hi != eoff_hi) {
#ifdef CONFIG_MTD_PMC551_DEBUG
			printk(KERN_DEBUG "pmc551_write() soff_hi: %ld, "
				"eoff_hi: %ld\n", (long)soff_hi, (long)eoff_hi);
#endif
			memcpy(ptr, copyfrom, priv->asize);
			copyfrom += priv->asize;
			if (soff_hi >= mtd->size) {
				goto out;
			}
			soff_hi += priv->asize;
			pmc551_point(mtd, soff_hi, priv->asize, retlen,
				     (void **)&ptr, NULL);
		}
		memcpy(ptr, copyfrom, eoff_lo);
		copyfrom += eoff_lo;
	}

      out:
#ifdef CONFIG_MTD_PMC551_DEBUG
	printk(KERN_DEBUG "pmc551_write() done\n");
#endif
	*retlen = copyfrom - buf;
	return 0;
}

