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
typedef  size_t uint32_t ;
typedef  size_t loff_t ;
struct TYPE_4__ {size_t erasesize; } ;

/* Variables and functions */
 int EINTR ; 
 scalar_t__* bbt ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 unsigned int ebcnt ; 
 int errcnt ; 
 int memcmp (unsigned char*,unsigned char*,size_t) ; 
 int /*<<< orphan*/  memset (unsigned char*,int,size_t) ; 
 TYPE_1__* mtd ; 
 scalar_t__ mtd_is_bitflip (int) ; 
 int mtd_read (TYPE_1__*,size_t,size_t,size_t*,unsigned char*) ; 
 int mtd_write (TYPE_1__*,size_t,size_t,size_t*,unsigned char*) ; 
 int /*<<< orphan*/  pr_err (char*,long long) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  prandom_bytes_state (int /*<<< orphan*/ *,unsigned char*,size_t) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 unsigned char* readbuf ; 
 int /*<<< orphan*/  rnd_state ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 size_t subpgsize ; 
 scalar_t__ unlikely (int) ; 
 unsigned char* writebuf ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

__attribute__((used)) static inline void clear_data(unsigned char *buf, size_t len)
{
	memset(buf, 0, len);
}

__attribute__((used)) static int write_eraseblock(int ebnum)
{
	size_t written;
	int err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	prandom_bytes_state(&rnd_state, writebuf, subpgsize);
	err = mtd_write(mtd, addr, subpgsize, &written, writebuf);
	if (unlikely(err || written != subpgsize)) {
		pr_err("error: write failed at %#llx\n",
		       (long long)addr);
		if (written != subpgsize) {
			pr_err("  write size: %#x\n", subpgsize);
			pr_err("  written: %#zx\n", written);
		}
		return err ? err : -1;
	}

	addr += subpgsize;

	prandom_bytes_state(&rnd_state, writebuf, subpgsize);
	err = mtd_write(mtd, addr, subpgsize, &written, writebuf);
	if (unlikely(err || written != subpgsize)) {
		pr_err("error: write failed at %#llx\n",
		       (long long)addr);
		if (written != subpgsize) {
			pr_err("  write size: %#x\n", subpgsize);
			pr_err("  written: %#zx\n", written);
		}
		return err ? err : -1;
	}

	return err;
}

__attribute__((used)) static int write_eraseblock2(int ebnum)
{
	size_t written;
	int err = 0, k;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	for (k = 1; k < 33; ++k) {
		if (addr + (subpgsize * k) > (loff_t)(ebnum + 1) * mtd->erasesize)
			break;
		prandom_bytes_state(&rnd_state, writebuf, subpgsize * k);
		err = mtd_write(mtd, addr, subpgsize * k, &written, writebuf);
		if (unlikely(err || written != subpgsize * k)) {
			pr_err("error: write failed at %#llx\n",
			       (long long)addr);
			if (written != subpgsize * k) {
				pr_err("  write size: %#x\n",
				       subpgsize * k);
				pr_err("  written: %#08zx\n",
				       written);
			}
			return err ? err : -1;
		}
		addr += subpgsize * k;
	}

	return err;
}

__attribute__((used)) static void print_subpage(unsigned char *p)
{
	int i, j;

	for (i = 0; i < subpgsize; ) {
		for (j = 0; i < subpgsize && j < 32; ++i, ++j)
			printk("%02x", *p++);
		printk("\n");
	}
}

__attribute__((used)) static int verify_eraseblock(int ebnum)
{
	size_t read;
	int err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	prandom_bytes_state(&rnd_state, writebuf, subpgsize);
	clear_data(readbuf, subpgsize);
	err = mtd_read(mtd, addr, subpgsize, &read, readbuf);
	if (unlikely(err || read != subpgsize)) {
		if (mtd_is_bitflip(err) && read == subpgsize) {
			pr_info("ECC correction at %#llx\n",
			       (long long)addr);
			err = 0;
		} else {
			pr_err("error: read failed at %#llx\n",
			       (long long)addr);
			return err ? err : -1;
		}
	}
	if (unlikely(memcmp(readbuf, writebuf, subpgsize))) {
		pr_err("error: verify failed at %#llx\n",
		       (long long)addr);
		pr_info("------------- written----------------\n");
		print_subpage(writebuf);
		pr_info("------------- read ------------------\n");
		print_subpage(readbuf);
		pr_info("-------------------------------------\n");
		errcnt += 1;
	}

	addr += subpgsize;

	prandom_bytes_state(&rnd_state, writebuf, subpgsize);
	clear_data(readbuf, subpgsize);
	err = mtd_read(mtd, addr, subpgsize, &read, readbuf);
	if (unlikely(err || read != subpgsize)) {
		if (mtd_is_bitflip(err) && read == subpgsize) {
			pr_info("ECC correction at %#llx\n",
			       (long long)addr);
			err = 0;
		} else {
			pr_err("error: read failed at %#llx\n",
			       (long long)addr);
			return err ? err : -1;
		}
	}
	if (unlikely(memcmp(readbuf, writebuf, subpgsize))) {
		pr_info("error: verify failed at %#llx\n",
		       (long long)addr);
		pr_info("------------- written----------------\n");
		print_subpage(writebuf);
		pr_info("------------- read ------------------\n");
		print_subpage(readbuf);
		pr_info("-------------------------------------\n");
		errcnt += 1;
	}

	return err;
}

__attribute__((used)) static int verify_eraseblock2(int ebnum)
{
	size_t read;
	int err = 0, k;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	for (k = 1; k < 33; ++k) {
		if (addr + (subpgsize * k) > (loff_t)(ebnum + 1) * mtd->erasesize)
			break;
		prandom_bytes_state(&rnd_state, writebuf, subpgsize * k);
		clear_data(readbuf, subpgsize * k);
		err = mtd_read(mtd, addr, subpgsize * k, &read, readbuf);
		if (unlikely(err || read != subpgsize * k)) {
			if (mtd_is_bitflip(err) && read == subpgsize * k) {
				pr_info("ECC correction at %#llx\n",
				       (long long)addr);
				err = 0;
			} else {
				pr_err("error: read failed at "
				       "%#llx\n", (long long)addr);
				return err ? err : -1;
			}
		}
		if (unlikely(memcmp(readbuf, writebuf, subpgsize * k))) {
			pr_err("error: verify failed at %#llx\n",
			       (long long)addr);
			errcnt += 1;
		}
		addr += subpgsize * k;
	}

	return err;
}

__attribute__((used)) static int verify_eraseblock_ff(int ebnum)
{
	uint32_t j;
	size_t read;
	int err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	memset(writebuf, 0xff, subpgsize);
	for (j = 0; j < mtd->erasesize / subpgsize; ++j) {
		clear_data(readbuf, subpgsize);
		err = mtd_read(mtd, addr, subpgsize, &read, readbuf);
		if (unlikely(err || read != subpgsize)) {
			if (mtd_is_bitflip(err) && read == subpgsize) {
				pr_info("ECC correction at %#llx\n",
				       (long long)addr);
				err = 0;
			} else {
				pr_err("error: read failed at "
				       "%#llx\n", (long long)addr);
				return err ? err : -1;
			}
		}
		if (unlikely(memcmp(readbuf, writebuf, subpgsize))) {
			pr_err("error: verify 0xff failed at "
			       "%#llx\n", (long long)addr);
			errcnt += 1;
		}
		addr += subpgsize;
	}

	return err;
}

__attribute__((used)) static int verify_all_eraseblocks_ff(void)
{
	int err;
	unsigned int i;

	pr_info("verifying all eraseblocks for 0xff\n");
	for (i = 0; i < ebcnt; ++i) {
		if (bbt[i])
			continue;
		err = verify_eraseblock_ff(i);
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

