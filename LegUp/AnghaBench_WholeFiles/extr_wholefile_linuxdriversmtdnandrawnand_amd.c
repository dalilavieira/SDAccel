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
struct TYPE_2__ {int* data; } ;
struct nand_chip {int /*<<< orphan*/  bbt_options; TYPE_1__ id; } ;
struct mtd_info {int writesize; int erasesize; } ;

/* Variables and functions */
 int /*<<< orphan*/  NAND_BBT_SCAN2NDPAGE ; 
 int /*<<< orphan*/  nand_decode_ext_id (struct nand_chip*) ; 
 scalar_t__ nand_is_slc (struct nand_chip*) ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 

__attribute__((used)) static void amd_nand_decode_id(struct nand_chip *chip)
{
	struct mtd_info *mtd = nand_to_mtd(chip);

	nand_decode_ext_id(chip);

	/*
	 * Check for Spansion/AMD ID + repeating 5th, 6th byte since
	 * some Spansion chips have erasesize that conflicts with size
	 * listed in nand_ids table.
	 * Data sheet (5 byte ID): Spansion S30ML-P ORNAND (p.39)
	 */
	if (chip->id.data[4] != 0x00 && chip->id.data[5] == 0x00 &&
	    chip->id.data[6] == 0x00 && chip->id.data[7] == 0x00 &&
	    mtd->writesize == 512) {
		mtd->erasesize = 128 * 1024;
		mtd->erasesize <<= ((chip->id.data[3] & 0x03) << 1);
	}
}

__attribute__((used)) static int amd_nand_init(struct nand_chip *chip)
{
	if (nand_is_slc(chip))
		chip->bbt_options |= NAND_BBT_SCAN2NDPAGE;

	return 0;
}

