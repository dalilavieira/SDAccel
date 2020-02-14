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
typedef  int u8 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct sharpsl_nand_partinfo {int /*<<< orphan*/  start; int /*<<< orphan*/  end; int /*<<< orphan*/  magic; } ;
struct sharpsl_ftl {unsigned int logmax; unsigned int* log2phy; } ;
struct mtd_partition {char* name; scalar_t__ size; scalar_t__ offset; } ;
struct mtd_part_parser_data {int dummy; } ;
struct mtd_oob_region {int length; int offset; } ;
struct mtd_oob_ops {scalar_t__ ooblen; int* oobbuf; scalar_t__ oobretlen; int /*<<< orphan*/  mode; } ;
struct mtd_info {scalar_t__ oobsize; int erasesize; int /*<<< orphan*/  size; } ;
typedef  int loff_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int BIT (int) ; 
 int BLOCK_IS_RESERVED ; 
 int BLOCK_UNMASK_COMPLEMENT ; 
 scalar_t__ BOOT_MAGIC ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 scalar_t__ FSRO_MAGIC ; 
 scalar_t__ FSRW_MAGIC ; 
 int GENMASK (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MTD_OPS_PLACE_OOB ; 
 size_t NAND_NOOB_LOGADDR_00 ; 
 size_t NAND_NOOB_LOGADDR_01 ; 
 size_t NAND_NOOB_LOGADDR_10 ; 
 size_t NAND_NOOB_LOGADDR_11 ; 
 size_t NAND_NOOB_LOGADDR_20 ; 
 size_t NAND_NOOB_LOGADDR_21 ; 
 scalar_t__ SHARPSL_FTL_PART_SIZE ; 
 int SHARPSL_NAND_PARTS ; 
 int SHARPSL_PARTINFO1_LADDR ; 
 int SHARPSL_PARTINFO2_LADDR ; 
 unsigned int UINT_MAX ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int hweight16 (int) ; 
 struct mtd_partition* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 unsigned int* kmalloc_array (unsigned int,int,int /*<<< orphan*/ ) ; 
 int* kzalloc (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ le32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ mtd_block_isbad (struct mtd_info*,int) ; 
 unsigned int mtd_div_by_eb (scalar_t__,struct mtd_info*) ; 
 scalar_t__ mtd_is_bitflip (int) ; 
 int mtd_mod_by_eb (scalar_t__,struct mtd_info*) ; 
 int mtd_ooblayout_free (struct mtd_info*,int /*<<< orphan*/ ,struct mtd_oob_region*) ; 
 int mtd_read (struct mtd_info*,int,size_t,size_t*,void*) ; 
 int mtd_read_oob (struct mtd_info*,int,struct mtd_oob_ops*) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 

__attribute__((used)) static int sharpsl_nand_check_ooblayout(struct mtd_info *mtd)
{
	u8 freebytes = 0;
	int section = 0;

	while (true) {
		struct mtd_oob_region oobfree = { };
		int ret, i;

		ret = mtd_ooblayout_free(mtd, section++, &oobfree);
		if (ret)
			break;

		if (!oobfree.length || oobfree.offset > 15 ||
		    (oobfree.offset + oobfree.length) < 8)
			continue;

		i = oobfree.offset >= 8 ? oobfree.offset : 8;
		for (; i < oobfree.offset + oobfree.length && i < 16; i++)
			freebytes |= BIT(i - 8);

		if (freebytes == 0xff)
			return 0;
	}

	return -ENOTSUPP;
}

__attribute__((used)) static int sharpsl_nand_read_oob(struct mtd_info *mtd, loff_t offs, u8 *buf)
{
	struct mtd_oob_ops ops = { };
	int ret;

	ops.mode = MTD_OPS_PLACE_OOB;
	ops.ooblen = mtd->oobsize;
	ops.oobbuf = buf;

	ret = mtd_read_oob(mtd, offs, &ops);
	if (ret != 0 || mtd->oobsize != ops.oobretlen)
		return -1;

	return 0;
}

__attribute__((used)) static int sharpsl_nand_get_logical_num(u8 *oob)
{
	u16 us;
	int good0, good1;

	if (oob[NAND_NOOB_LOGADDR_00] == oob[NAND_NOOB_LOGADDR_10] &&
	    oob[NAND_NOOB_LOGADDR_01] == oob[NAND_NOOB_LOGADDR_11]) {
		good0 = NAND_NOOB_LOGADDR_00;
		good1 = NAND_NOOB_LOGADDR_01;
	} else if (oob[NAND_NOOB_LOGADDR_10] == oob[NAND_NOOB_LOGADDR_20] &&
		   oob[NAND_NOOB_LOGADDR_11] == oob[NAND_NOOB_LOGADDR_21]) {
		good0 = NAND_NOOB_LOGADDR_10;
		good1 = NAND_NOOB_LOGADDR_11;
	} else if (oob[NAND_NOOB_LOGADDR_20] == oob[NAND_NOOB_LOGADDR_00] &&
		   oob[NAND_NOOB_LOGADDR_21] == oob[NAND_NOOB_LOGADDR_01]) {
		good0 = NAND_NOOB_LOGADDR_20;
		good1 = NAND_NOOB_LOGADDR_21;
	} else {
		return -EINVAL;
	}

	us = oob[good0] | oob[good1] << 8;

	/* parity check */
	if (hweight16(us) & BLOCK_UNMASK_COMPLEMENT)
		return -EINVAL;

	/* reserved */
	if (us == BLOCK_IS_RESERVED)
		return BLOCK_IS_RESERVED;

	return (us >> 1) & GENMASK(9, 0);
}

__attribute__((used)) static int sharpsl_nand_init_ftl(struct mtd_info *mtd, struct sharpsl_ftl *ftl)
{
	unsigned int block_num, log_num, phymax;
	loff_t block_adr;
	u8 *oob;
	int i, ret;

	oob = kzalloc(mtd->oobsize, GFP_KERNEL);
	if (!oob)
		return -ENOMEM;

	phymax = mtd_div_by_eb(SHARPSL_FTL_PART_SIZE, mtd);

	/* FTL reserves 5% of the blocks + 1 spare  */
	ftl->logmax = ((phymax * 95) / 100) - 1;

	ftl->log2phy = kmalloc_array(ftl->logmax, sizeof(*ftl->log2phy),
				     GFP_KERNEL);
	if (!ftl->log2phy) {
		ret = -ENOMEM;
		goto exit;
	}

	/* initialize ftl->log2phy */
	for (i = 0; i < ftl->logmax; i++)
		ftl->log2phy[i] = UINT_MAX;

	/* create physical-logical table */
	for (block_num = 0; block_num < phymax; block_num++) {
		block_adr = (loff_t)block_num * mtd->erasesize;

		if (mtd_block_isbad(mtd, block_adr))
			continue;

		if (sharpsl_nand_read_oob(mtd, block_adr, oob))
			continue;

		/* get logical block */
		log_num = sharpsl_nand_get_logical_num(oob);

		/* cut-off errors and skip the out-of-range values */
		if (log_num > 0 && log_num < ftl->logmax) {
			if (ftl->log2phy[log_num] == UINT_MAX)
				ftl->log2phy[log_num] = block_num;
		}
	}

	pr_info("Sharp SL FTL: %d blocks used (%d logical, %d reserved)\n",
		phymax, ftl->logmax, phymax - ftl->logmax);

	ret = 0;
exit:
	kfree(oob);
	return ret;
}

__attribute__((used)) static void sharpsl_nand_cleanup_ftl(struct sharpsl_ftl *ftl)
{
	kfree(ftl->log2phy);
}

__attribute__((used)) static int sharpsl_nand_read_laddr(struct mtd_info *mtd,
				   loff_t from,
				   size_t len,
				   void *buf,
				   struct sharpsl_ftl *ftl)
{
	unsigned int log_num, final_log_num;
	unsigned int block_num;
	loff_t block_adr;
	loff_t block_ofs;
	size_t retlen;
	int err;

	log_num = mtd_div_by_eb((u32)from, mtd);
	final_log_num = mtd_div_by_eb(((u32)from + len - 1), mtd);

	if (len <= 0 || log_num >= ftl->logmax || final_log_num > log_num)
		return -EINVAL;

	block_num = ftl->log2phy[log_num];
	block_adr = (loff_t)block_num * mtd->erasesize;
	block_ofs = mtd_mod_by_eb((u32)from, mtd);

	err = mtd_read(mtd, block_adr + block_ofs, len, &retlen, buf);
	/* Ignore corrected ECC errors */
	if (mtd_is_bitflip(err))
		err = 0;

	if (!err && retlen != len)
		err = -EIO;

	if (err)
		pr_err("sharpslpart: error, read failed at %#llx\n",
		       block_adr + block_ofs);

	return err;
}

__attribute__((used)) static int sharpsl_nand_read_partinfo(struct mtd_info *master,
				      loff_t from,
				      size_t len,
				      struct sharpsl_nand_partinfo *buf,
				      struct sharpsl_ftl *ftl)
{
	int ret;

	ret = sharpsl_nand_read_laddr(master, from, len, buf, ftl);
	if (ret)
		return ret;

	/* check for magics */
	if (be32_to_cpu(buf[0].magic) != BOOT_MAGIC ||
	    be32_to_cpu(buf[1].magic) != FSRO_MAGIC ||
	    be32_to_cpu(buf[2].magic) != FSRW_MAGIC) {
		pr_err("sharpslpart: magic values mismatch\n");
		return -EINVAL;
	}

	/* fixup for hardcoded value 64 MiB (for older models) */
	buf[2].end = cpu_to_le32(master->size);

	/* extra sanity check */
	if (le32_to_cpu(buf[0].end) <= le32_to_cpu(buf[0].start) ||
	    le32_to_cpu(buf[1].start) < le32_to_cpu(buf[0].end) ||
	    le32_to_cpu(buf[1].end) <= le32_to_cpu(buf[1].start) ||
	    le32_to_cpu(buf[2].start) < le32_to_cpu(buf[1].end) ||
	    le32_to_cpu(buf[2].end) <= le32_to_cpu(buf[2].start)) {
		pr_err("sharpslpart: partition sizes mismatch\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int sharpsl_parse_mtd_partitions(struct mtd_info *master,
					const struct mtd_partition **pparts,
					struct mtd_part_parser_data *data)
{
	struct sharpsl_ftl ftl;
	struct sharpsl_nand_partinfo buf[SHARPSL_NAND_PARTS];
	struct mtd_partition *sharpsl_nand_parts;
	int err;

	/* check that OOB bytes 8 to 15 used by the FTL are actually free */
	err = sharpsl_nand_check_ooblayout(master);
	if (err)
		return err;

	/* init logical mgmt (FTL) */
	err = sharpsl_nand_init_ftl(master, &ftl);
	if (err)
		return err;

	/* read and validate first partition table */
	pr_info("sharpslpart: try reading first partition table\n");
	err = sharpsl_nand_read_partinfo(master,
					 SHARPSL_PARTINFO1_LADDR,
					 sizeof(buf), buf, &ftl);
	if (err) {
		/* fallback: read second partition table */
		pr_warn("sharpslpart: first partition table is invalid, retry using the second\n");
		err = sharpsl_nand_read_partinfo(master,
						 SHARPSL_PARTINFO2_LADDR,
						 sizeof(buf), buf, &ftl);
	}

	/* cleanup logical mgmt (FTL) */
	sharpsl_nand_cleanup_ftl(&ftl);

	if (err) {
		pr_err("sharpslpart: both partition tables are invalid\n");
		return err;
	}

	sharpsl_nand_parts = kcalloc(SHARPSL_NAND_PARTS,
				     sizeof(*sharpsl_nand_parts),
				     GFP_KERNEL);
	if (!sharpsl_nand_parts)
		return -ENOMEM;

	/* original names */
	sharpsl_nand_parts[0].name = "smf";
	sharpsl_nand_parts[0].offset = le32_to_cpu(buf[0].start);
	sharpsl_nand_parts[0].size = le32_to_cpu(buf[0].end) -
				     le32_to_cpu(buf[0].start);

	sharpsl_nand_parts[1].name = "root";
	sharpsl_nand_parts[1].offset = le32_to_cpu(buf[1].start);
	sharpsl_nand_parts[1].size = le32_to_cpu(buf[1].end) -
				     le32_to_cpu(buf[1].start);

	sharpsl_nand_parts[2].name = "home";
	sharpsl_nand_parts[2].offset = le32_to_cpu(buf[2].start);
	sharpsl_nand_parts[2].size = le32_to_cpu(buf[2].end) -
				     le32_to_cpu(buf[2].start);

	*pparts = sharpsl_nand_parts;
	return SHARPSL_NAND_PARTS;
}

