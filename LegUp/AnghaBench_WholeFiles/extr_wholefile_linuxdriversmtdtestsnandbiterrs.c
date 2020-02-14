#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_5__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char uint8_t ;
struct mtd_oob_ops {size_t len; size_t retlen; unsigned char* datbuf; int /*<<< orphan*/ * oobbuf; scalar_t__ ooboffs; scalar_t__ oobretlen; scalar_t__ ooblen; int /*<<< orphan*/  mode; } ;
struct mtd_ecc_stats {int corrected; } ;
typedef  int /*<<< orphan*/  oldstats ;
typedef  int /*<<< orphan*/  bitstats ;
struct TYPE_7__ {int corrected; } ;
struct TYPE_6__ {size_t writesize; TYPE_5__ ecc_stats; } ;

/* Variables and functions */
 int /*<<< orphan*/  BCLR (unsigned char,int) ; 
 scalar_t__ CBIT (unsigned char,int) ; 
 int EINTR ; 
 int EIO ; 
 int EUCLEAN ; 
 int /*<<< orphan*/  MTD_OPS_RAW ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 unsigned int max_overwrite ; 
 int /*<<< orphan*/  memcpy (struct mtd_ecc_stats*,TYPE_5__*,int) ; 
 int /*<<< orphan*/  memset (unsigned int*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* mtd ; 
 int mtd_read (TYPE_1__*,scalar_t__,size_t,size_t*,scalar_t__*) ; 
 int mtd_write_oob (TYPE_1__*,scalar_t__,struct mtd_oob_ops*) ; 
 int mtdtest_write (TYPE_1__*,scalar_t__,size_t,unsigned char*) ; 
 scalar_t__ offset ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 scalar_t__* rbuffer ; 
 unsigned int seed ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 unsigned int subcount ; 
 unsigned int subsize ; 
 unsigned char* wbuffer ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

__attribute__((used)) static uint8_t hash(unsigned offset)
{
	unsigned v = offset;
	unsigned char c;
	v ^= 0x7f7edfd3;
	v = v ^ (v >> 3);
	v = v ^ (v >> 5);
	v = v ^ (v >> 13);
	c = v & 0xFF;
	/* Reverse bits of result. */
	c = (c & 0x0F) << 4 | (c & 0xF0) >> 4;
	c = (c & 0x33) << 2 | (c & 0xCC) >> 2;
	c = (c & 0x55) << 1 | (c & 0xAA) >> 1;
	return c;
}

__attribute__((used)) static int write_page(int log)
{
	if (log)
		pr_info("write_page\n");

	return mtdtest_write(mtd, offset, mtd->writesize, wbuffer);
}

__attribute__((used)) static int rewrite_page(int log)
{
	int err = 0;
	struct mtd_oob_ops ops;

	if (log)
		pr_info("rewrite page\n");

	ops.mode      = MTD_OPS_RAW; /* No ECC */
	ops.len       = mtd->writesize;
	ops.retlen    = 0;
	ops.ooblen    = 0;
	ops.oobretlen = 0;
	ops.ooboffs   = 0;
	ops.datbuf    = wbuffer;
	ops.oobbuf    = NULL;

	err = mtd_write_oob(mtd, offset, &ops);
	if (err || ops.retlen != mtd->writesize) {
		pr_err("error: write_oob failed (%d)\n", err);
		if (!err)
			err = -EIO;
	}

	return err;
}

__attribute__((used)) static int read_page(int log)
{
	int err = 0;
	size_t read;
	struct mtd_ecc_stats oldstats;

	if (log)
		pr_info("read_page\n");

	/* Saving last mtd stats */
	memcpy(&oldstats, &mtd->ecc_stats, sizeof(oldstats));

	err = mtd_read(mtd, offset, mtd->writesize, &read, rbuffer);
	if (!err || err == -EUCLEAN)
		err = mtd->ecc_stats.corrected - oldstats.corrected;

	if (err < 0 || read != mtd->writesize) {
		pr_err("error: read failed at %#llx\n", (long long)offset);
		if (err >= 0)
			err = -EIO;
	}

	return err;
}

__attribute__((used)) static int verify_page(int log)
{
	unsigned i, errs = 0;

	if (log)
		pr_info("verify_page\n");

	for (i = 0; i < mtd->writesize; i++) {
		if (rbuffer[i] != hash(i+seed)) {
			pr_err("Error: page offset %u, expected %02x, got %02x\n",
				i, hash(i+seed), rbuffer[i]);
			errs++;
		}
	}

	if (errs)
		return -EIO;
	else
		return 0;
}

__attribute__((used)) static int insert_biterror(unsigned byte)
{
	int bit;

	while (byte < mtd->writesize) {
		for (bit = 7; bit >= 0; bit--) {
			if (CBIT(wbuffer[byte], bit)) {
				BCLR(wbuffer[byte], bit);
				pr_info("Inserted biterror @ %u/%u\n", byte, bit);
				return 0;
			}
		}
		byte++;
	}
	pr_err("biterror: Failed to find a '1' bit\n");
	return -EIO;
}

__attribute__((used)) static int incremental_errors_test(void)
{
	int err = 0;
	unsigned i;
	unsigned errs_per_subpage = 0;

	pr_info("incremental biterrors test\n");

	for (i = 0; i < mtd->writesize; i++)
		wbuffer[i] = hash(i+seed);

	err = write_page(1);
	if (err)
		goto exit;

	while (1) {

		err = rewrite_page(1);
		if (err)
			goto exit;

		err = read_page(1);
		if (err > 0)
			pr_info("Read reported %d corrected bit errors\n", err);
		if (err < 0) {
			pr_err("After %d biterrors per subpage, read reported error %d\n",
				errs_per_subpage, err);
			err = 0;
			goto exit;
		}

		err = verify_page(1);
		if (err) {
			pr_err("ECC failure, read data is incorrect despite read success\n");
			goto exit;
		}

		pr_info("Successfully corrected %d bit errors per subpage\n",
			errs_per_subpage);

		for (i = 0; i < subcount; i++) {
			err = insert_biterror(i * subsize);
			if (err < 0)
				goto exit;
		}
		errs_per_subpage++;
	}

exit:
	return err;
}

__attribute__((used)) static int overwrite_test(void)
{
	int err = 0;
	unsigned i;
	unsigned max_corrected = 0;
	unsigned opno = 0;
	/* We don't expect more than this many correctable bit errors per
	 * page. */
	#define MAXBITS 512
	static unsigned bitstats[MAXBITS]; /* bit error histogram. */

	memset(bitstats, 0, sizeof(bitstats));

	pr_info("overwrite biterrors test\n");

	for (i = 0; i < mtd->writesize; i++)
		wbuffer[i] = hash(i+seed);

	err = write_page(1);
	if (err)
		goto exit;

	while (opno < max_overwrite) {

		err = write_page(0);
		if (err)
			break;

		err = read_page(0);
		if (err >= 0) {
			if (err >= MAXBITS) {
				pr_info("Implausible number of bit errors corrected\n");
				err = -EIO;
				break;
			}
			bitstats[err]++;
			if (err > max_corrected) {
				max_corrected = err;
				pr_info("Read reported %d corrected bit errors\n",
					err);
			}
		} else { /* err < 0 */
			pr_info("Read reported error %d\n", err);
			err = 0;
			break;
		}

		err = verify_page(0);
		if (err) {
			bitstats[max_corrected] = opno;
			pr_info("ECC failure, read data is incorrect despite read success\n");
			break;
		}

		err = mtdtest_relax();
		if (err)
			break;

		opno++;
	}

	/* At this point bitstats[0] contains the number of ops with no bit
	 * errors, bitstats[1] the number of ops with 1 bit error, etc. */
	pr_info("Bit error histogram (%d operations total):\n", opno);
	for (i = 0; i < max_corrected; i++)
		pr_info("Page reads with %3d corrected bit errors: %d\n",
			i, bitstats[i]);

exit:
	return err;
}

