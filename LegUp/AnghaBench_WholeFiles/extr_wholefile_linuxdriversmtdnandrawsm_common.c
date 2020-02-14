#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct sm_oob {int data_status; int block_status; } ;
struct nand_flash_dev {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/ * ops; } ;
struct nand_chip {int badblockpos; int badblockbits; int (* block_markbad ) (struct mtd_info*,scalar_t__) ;TYPE_1__ dummy_controller; int /*<<< orphan*/  options; } ;
struct mtd_oob_region {int length; int offset; } ;
struct mtd_oob_ops {scalar_t__ oobretlen; int /*<<< orphan*/ * datbuf; void* oobbuf; int /*<<< orphan*/  ooblen; scalar_t__ ooboffs; int /*<<< orphan*/  mode; } ;
struct mtd_info {scalar_t__ writesize; int /*<<< orphan*/  oobsize; } ;
typedef  scalar_t__ loff_t ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ERANGE ; 
 int /*<<< orphan*/  MTD_OPS_PLACE_OOB ; 
 int /*<<< orphan*/  NAND_SKIP_BBTSCAN ; 
 scalar_t__ SM_OOB_SIZE ; 
 scalar_t__ SM_SECTOR_SIZE ; 
 scalar_t__ SM_SMALL_PAGE ; 
 int hweight16 (int) ; 
 int /*<<< orphan*/  memcmp (struct sm_oob*,int const*,int) ; 
 int /*<<< orphan*/  memset (struct sm_oob*,int,scalar_t__) ; 
 int mtd_device_register (struct mtd_info*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtd_set_ooblayout (struct mtd_info*,int /*<<< orphan*/ *) ; 
 struct nand_chip* mtd_to_nand (struct mtd_info*) ; 
 int mtd_write_oob (struct mtd_info*,scalar_t__,struct mtd_oob_ops*) ; 
 int /*<<< orphan*/  nand_cleanup (struct nand_chip*) ; 
 int nand_scan_with_ids (struct mtd_info*,int,struct nand_flash_dev*) ; 
 struct nand_flash_dev* nand_smartmedia_flash_ids ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 
 struct nand_flash_dev* nand_xd_flash_ids ; 
 int /*<<< orphan*/  oob_sm_ops ; 
 int /*<<< orphan*/  oob_sm_small_ops ; 
 int /*<<< orphan*/  pr_notice (char*,int) ; 
 int /*<<< orphan*/  sm_controller_ops ; 

__attribute__((used)) static inline int sm_sector_valid(struct sm_oob *oob)
{
	return hweight16(oob->data_status) >= 5;
}

__attribute__((used)) static inline int sm_block_valid(struct sm_oob *oob)
{
	return hweight16(oob->block_status) >= 7;
}

__attribute__((used)) static inline int sm_block_erased(struct sm_oob *oob)
{
	static const uint32_t erased_pattern[4] = {
		0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

	/* First test for erased block */
	if (!memcmp(oob, erased_pattern, sizeof(*oob)))
		return 1;
	return 0;
}

__attribute__((used)) static int oob_sm_ooblayout_ecc(struct mtd_info *mtd, int section,
				struct mtd_oob_region *oobregion)
{
	if (section > 1)
		return -ERANGE;

	oobregion->length = 3;
	oobregion->offset = ((section + 1) * 8) - 3;

	return 0;
}

__attribute__((used)) static int oob_sm_ooblayout_free(struct mtd_info *mtd, int section,
				 struct mtd_oob_region *oobregion)
{
	switch (section) {
	case 0:
		/* reserved */
		oobregion->offset = 0;
		oobregion->length = 4;
		break;
	case 1:
		/* LBA1 */
		oobregion->offset = 6;
		oobregion->length = 2;
		break;
	case 2:
		/* LBA2 */
		oobregion->offset = 11;
		oobregion->length = 2;
		break;
	default:
		return -ERANGE;
	}

	return 0;
}

__attribute__((used)) static int oob_sm_small_ooblayout_ecc(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *oobregion)
{
	if (section)
		return -ERANGE;

	oobregion->length = 3;
	oobregion->offset = 0;

	return 0;
}

__attribute__((used)) static int oob_sm_small_ooblayout_free(struct mtd_info *mtd, int section,
				       struct mtd_oob_region *oobregion)
{
	switch (section) {
	case 0:
		/* reserved */
		oobregion->offset = 3;
		oobregion->length = 2;
		break;
	case 1:
		/* LBA1 */
		oobregion->offset = 6;
		oobregion->length = 2;
		break;
	default:
		return -ERANGE;
	}

	return 0;
}

__attribute__((used)) static int sm_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
	struct mtd_oob_ops ops;
	struct sm_oob oob;
	int ret;

	memset(&oob, -1, SM_OOB_SIZE);
	oob.block_status = 0x0F;

	/* As long as this function is called on erase block boundaries
		it will work correctly for 256 byte nand */
	ops.mode = MTD_OPS_PLACE_OOB;
	ops.ooboffs = 0;
	ops.ooblen = mtd->oobsize;
	ops.oobbuf = (void *)&oob;
	ops.datbuf = NULL;


	ret = mtd_write_oob(mtd, ofs, &ops);
	if (ret < 0 || ops.oobretlen != SM_OOB_SIZE) {
		pr_notice("sm_common: can't mark sector at %i as bad\n",
			  (int)ofs);
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int sm_attach_chip(struct nand_chip *chip)
{
	struct mtd_info *mtd = nand_to_mtd(chip);

	/* Bad block marker position */
	chip->badblockpos = 0x05;
	chip->badblockbits = 7;
	chip->block_markbad = sm_block_markbad;

	/* ECC layout */
	if (mtd->writesize == SM_SECTOR_SIZE)
		mtd_set_ooblayout(mtd, &oob_sm_ops);
	else if (mtd->writesize == SM_SMALL_PAGE)
		mtd_set_ooblayout(mtd, &oob_sm_small_ops);
	else
		return -ENODEV;

	return 0;
}

int sm_register_device(struct mtd_info *mtd, int smartmedia)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct nand_flash_dev *flash_ids;
	int ret;

	chip->options |= NAND_SKIP_BBTSCAN;

	/* Scan for card properties */
	chip->dummy_controller.ops = &sm_controller_ops;
	flash_ids = smartmedia ? nand_smartmedia_flash_ids : nand_xd_flash_ids;
	ret = nand_scan_with_ids(mtd, 1, flash_ids);
	if (ret)
		return ret;

	ret = mtd_device_register(mtd, NULL, 0);
	if (ret)
		nand_cleanup(chip);

	return ret;
}

