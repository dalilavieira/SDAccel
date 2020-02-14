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
struct mtd_info {int erasesize; } ;
struct erase_info {int addr; int len; } ;
typedef  int loff_t ;

/* Variables and functions */
 int EINTR ; 
 int EIO ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  memset (struct erase_info*,int /*<<< orphan*/ ,int) ; 
 int mtd_block_isbad (struct mtd_info*,int) ; 
 int /*<<< orphan*/  mtd_can_have_bb (struct mtd_info*) ; 
 int mtd_erase (struct mtd_info*,struct erase_info*) ; 
 scalar_t__ mtd_is_bitflip (int) ; 
 int mtd_read (struct mtd_info*,int,size_t,size_t*,void*) ; 
 int mtd_write (struct mtd_info*,int,size_t,size_t*,void const*) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

int mtdtest_erase_eraseblock(struct mtd_info *mtd, unsigned int ebnum)
{
	int err;
	struct erase_info ei;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	memset(&ei, 0, sizeof(struct erase_info));
	ei.addr = addr;
	ei.len  = mtd->erasesize;

	err = mtd_erase(mtd, &ei);
	if (err) {
		pr_info("error %d while erasing EB %d\n", err, ebnum);
		return err;
	}

	return 0;
}

__attribute__((used)) static int is_block_bad(struct mtd_info *mtd, unsigned int ebnum)
{
	int ret;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	ret = mtd_block_isbad(mtd, addr);
	if (ret)
		pr_info("block %d is bad\n", ebnum);

	return ret;
}

int mtdtest_scan_for_bad_eraseblocks(struct mtd_info *mtd, unsigned char *bbt,
					unsigned int eb, int ebcnt)
{
	int i, bad = 0;

	if (!mtd_can_have_bb(mtd))
		return 0;

	pr_info("scanning for bad eraseblocks\n");
	for (i = 0; i < ebcnt; ++i) {
		bbt[i] = is_block_bad(mtd, eb + i) ? 1 : 0;
		if (bbt[i])
			bad += 1;
		cond_resched();
	}
	pr_info("scanned %d eraseblocks, %d are bad\n", i, bad);

	return 0;
}

int mtdtest_erase_good_eraseblocks(struct mtd_info *mtd, unsigned char *bbt,
				unsigned int eb, int ebcnt)
{
	int err;
	unsigned int i;

	for (i = 0; i < ebcnt; ++i) {
		if (bbt[i])
			continue;
		err = mtdtest_erase_eraseblock(mtd, eb + i);
		if (err)
			return err;
		cond_resched();
	}

	return 0;
}

int mtdtest_read(struct mtd_info *mtd, loff_t addr, size_t size, void *buf)
{
	size_t read;
	int err;

	err = mtd_read(mtd, addr, size, &read, buf);
	/* Ignore corrected ECC errors */
	if (mtd_is_bitflip(err))
		err = 0;
	if (!err && read != size)
		err = -EIO;
	if (err)
		pr_err("error: read failed at %#llx\n", addr);

	return err;
}

int mtdtest_write(struct mtd_info *mtd, loff_t addr, size_t size,
		const void *buf)
{
	size_t written;
	int err;

	err = mtd_write(mtd, addr, size, &written, buf);
	if (!err && written != size)
		err = -EIO;
	if (err)
		pr_err("error: write failed at %#llx\n", addr);

	return err;
}

