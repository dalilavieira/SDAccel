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
struct mtd_oob_ops {int ooblen; int oobretlen; int ooboffs; void* oobbuf; int /*<<< orphan*/ * datbuf; scalar_t__ retlen; scalar_t__ len; void* mode; } ;
typedef  int loff_t ;
struct TYPE_4__ {int erasesize; int writesize; int oobavail; } ;

/* Variables and functions */
 int EINTR ; 
 void* MTD_OPS_AUTO_OOB ; 
 scalar_t__* bbt ; 
 size_t bitflip_limit ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 unsigned int ebcnt ; 
 int errcnt ; 
 scalar_t__ hweight8 (int) ; 
 size_t memcmpshow (int,void*,void*,size_t) ; 
 TYPE_1__* mtd ; 
 scalar_t__ mtd_is_bitflip (int) ; 
 int mtd_read_oob (TYPE_1__*,int,struct mtd_oob_ops*) ; 
 int mtd_write_oob (TYPE_1__*,int,struct mtd_oob_ops*) ; 
 int pgcnt ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  prandom_bytes_state (int /*<<< orphan*/ *,void*,size_t) ; 
 void* readbuf ; 
 int /*<<< orphan*/  rnd_state ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 int use_len ; 
 int use_len_max ; 
 int use_offset ; 
 scalar_t__ vary_offset ; 
 void* writebuf ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

__attribute__((used)) static void do_vary_offset(void)
{
	use_len -= 1;
	if (use_len < 1) {
		use_offset += 1;
		if (use_offset >= use_len_max)
			use_offset = 0;
		use_len = use_len_max - use_offset;
	}
}

__attribute__((used)) static int write_eraseblock(int ebnum)
{
	int i;
	struct mtd_oob_ops ops;
	int err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	prandom_bytes_state(&rnd_state, writebuf, use_len_max * pgcnt);
	for (i = 0; i < pgcnt; ++i, addr += mtd->writesize) {
		ops.mode      = MTD_OPS_AUTO_OOB;
		ops.len       = 0;
		ops.retlen    = 0;
		ops.ooblen    = use_len;
		ops.oobretlen = 0;
		ops.ooboffs   = use_offset;
		ops.datbuf    = NULL;
		ops.oobbuf    = writebuf + (use_len_max * i) + use_offset;
		err = mtd_write_oob(mtd, addr, &ops);
		if (err || ops.oobretlen != use_len) {
			pr_err("error: writeoob failed at %#llx\n",
			       (long long)addr);
			pr_err("error: use_len %d, use_offset %d\n",
			       use_len, use_offset);
			errcnt += 1;
			return err ? err : -1;
		}
		if (vary_offset)
			do_vary_offset();
	}

	return err;
}

__attribute__((used)) static int write_whole_device(void)
{
	int err;
	unsigned int i;

	pr_info("writing OOBs of whole device\n");
	for (i = 0; i < ebcnt; ++i) {
		if (bbt[i])
			continue;
		err = write_eraseblock(i);
		if (err)
			return err;
		if (i % 256 == 0)
			pr_info("written up to eraseblock %u\n", i);

		err = mtdtest_relax();
		if (err)
			return err;
	}
	pr_info("written %u eraseblocks\n", i);
	return 0;
}

__attribute__((used)) static size_t memcmpshowoffset(loff_t addr, loff_t offset, const void *cs,
			       const void *ct, size_t count)
{
	const unsigned char *su1, *su2;
	int res;
	size_t i = 0;
	size_t bitflips = 0;

	for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--, i++) {
		res = *su1 ^ *su2;
		if (res) {
			pr_info("error @addr[0x%lx:0x%lx] 0x%x -> 0x%x diff 0x%x\n",
				(unsigned long)addr, (unsigned long)offset + i,
				*su1, *su2, res);
			bitflips += hweight8(res);
		}
	}

	return bitflips;
}

__attribute__((used)) static size_t memffshow(loff_t addr, loff_t offset, const void *cs,
			size_t count)
{
	const unsigned char *su1;
	int res;
	size_t i = 0;
	size_t bitflips = 0;

	for (su1 = cs; 0 < count; ++su1, count--, i++) {
		res = *su1 ^ 0xff;
		if (res) {
			pr_info("error @addr[0x%lx:0x%lx] 0x%x -> 0xff diff 0x%x\n",
				(unsigned long)addr, (unsigned long)offset + i,
				*su1, res);
			bitflips += hweight8(res);
		}
	}

	return bitflips;
}

__attribute__((used)) static int verify_eraseblock(int ebnum)
{
	int i;
	struct mtd_oob_ops ops;
	int err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;
	size_t bitflips;

	prandom_bytes_state(&rnd_state, writebuf, use_len_max * pgcnt);
	for (i = 0; i < pgcnt; ++i, addr += mtd->writesize) {
		ops.mode      = MTD_OPS_AUTO_OOB;
		ops.len       = 0;
		ops.retlen    = 0;
		ops.ooblen    = use_len;
		ops.oobretlen = 0;
		ops.ooboffs   = use_offset;
		ops.datbuf    = NULL;
		ops.oobbuf    = readbuf;
		err = mtd_read_oob(mtd, addr, &ops);
		if (mtd_is_bitflip(err))
			err = 0;

		if (err || ops.oobretlen != use_len) {
			pr_err("error: readoob failed at %#llx\n",
			       (long long)addr);
			errcnt += 1;
			return err ? err : -1;
		}

		bitflips = memcmpshow(addr, readbuf,
				      writebuf + (use_len_max * i) + use_offset,
				      use_len);
		if (bitflips > bitflip_limit) {
			pr_err("error: verify failed at %#llx\n",
			       (long long)addr);
			errcnt += 1;
			if (errcnt > 1000) {
				pr_err("error: too many errors\n");
				return -1;
			}
		} else if (bitflips) {
			pr_info("ignoring error as within bitflip_limit\n");
		}

		if (use_offset != 0 || use_len < mtd->oobavail) {
			int k;

			ops.mode      = MTD_OPS_AUTO_OOB;
			ops.len       = 0;
			ops.retlen    = 0;
			ops.ooblen    = mtd->oobavail;
			ops.oobretlen = 0;
			ops.ooboffs   = 0;
			ops.datbuf    = NULL;
			ops.oobbuf    = readbuf;
			err = mtd_read_oob(mtd, addr, &ops);
			if (mtd_is_bitflip(err))
				err = 0;

			if (err || ops.oobretlen != mtd->oobavail) {
				pr_err("error: readoob failed at %#llx\n",
						(long long)addr);
				errcnt += 1;
				return err ? err : -1;
			}
			bitflips = memcmpshowoffset(addr, use_offset,
						    readbuf + use_offset,
						    writebuf + (use_len_max * i) + use_offset,
						    use_len);

			/* verify pre-offset area for 0xff */
			bitflips += memffshow(addr, 0, readbuf, use_offset);

			/* verify post-(use_offset + use_len) area for 0xff */
			k = use_offset + use_len;
			bitflips += memffshow(addr, k, readbuf + k,
					      mtd->oobavail - k);

			if (bitflips > bitflip_limit) {
				pr_err("error: verify failed at %#llx\n",
						(long long)addr);
				errcnt += 1;
				if (errcnt > 1000) {
					pr_err("error: too many errors\n");
					return -1;
				}
			} else if (bitflips) {
				pr_info("ignoring errors as within bitflip limit\n");
			}
		}
		if (vary_offset)
			do_vary_offset();
	}
	return err;
}

__attribute__((used)) static int verify_eraseblock_in_one_go(int ebnum)
{
	struct mtd_oob_ops ops;
	int err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;
	size_t len = mtd->oobavail * pgcnt;
	size_t oobavail = mtd->oobavail;
	size_t bitflips;
	int i;

	prandom_bytes_state(&rnd_state, writebuf, len);
	ops.mode      = MTD_OPS_AUTO_OOB;
	ops.len       = 0;
	ops.retlen    = 0;
	ops.ooblen    = len;
	ops.oobretlen = 0;
	ops.ooboffs   = 0;
	ops.datbuf    = NULL;
	ops.oobbuf    = readbuf;

	/* read entire block's OOB at one go */
	err = mtd_read_oob(mtd, addr, &ops);
	if (mtd_is_bitflip(err))
		err = 0;

	if (err || ops.oobretlen != len) {
		pr_err("error: readoob failed at %#llx\n",
		       (long long)addr);
		errcnt += 1;
		return err ? err : -1;
	}

	/* verify one page OOB at a time for bitflip per page limit check */
	for (i = 0; i < pgcnt; ++i, addr += mtd->writesize) {
		bitflips = memcmpshow(addr, readbuf + (i * oobavail),
				      writebuf + (i * oobavail), oobavail);
		if (bitflips > bitflip_limit) {
			pr_err("error: verify failed at %#llx\n",
			       (long long)addr);
			errcnt += 1;
			if (errcnt > 1000) {
				pr_err("error: too many errors\n");
				return -1;
			}
		} else if (bitflips) {
			pr_info("ignoring error as within bitflip_limit\n");
		}
	}

	return err;
}

__attribute__((used)) static int verify_all_eraseblocks(void)
{
	int err;
	unsigned int i;

	pr_info("verifying all eraseblocks\n");
	for (i = 0; i < ebcnt; ++i) {
		if (bbt[i])
			continue;
		err = verify_eraseblock(i);
		if (err)
			return err;
		if (i % 256 == 0)
			pr_info("verified up to eraseblock %u\n", i);

		err = mtdtest_relax();
		if (err)
			return err;
	}
	pr_info("verified %u eraseblocks\n", i);
	return 0;
}

