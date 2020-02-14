#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_4__ {int* data; } ;
struct spinand_device {TYPE_2__ id; int /*<<< orphan*/  spimem; } ;
struct spi_mem_op {int dummy; } ;
struct TYPE_3__ {int strength; } ;
struct nand_device {TYPE_1__ eccreq; } ;
struct mtd_oob_region {int offset; scalar_t__ length; } ;
struct mtd_info {scalar_t__ oobsize; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EBADMSG ; 
 int EINVAL ; 
 int ERANGE ; 
 int SPINAND_MFR_MACRONIX ; 
 struct spi_mem_op SPI_MEM_OP (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPI_MEM_OP_CMD (int,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_DATA_IN (int,int*,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_DUMMY (int,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_NO_ADDR ; 
#define  STATUS_ECC_HAS_BITFLIPS 130 
 int STATUS_ECC_MASK ; 
#define  STATUS_ECC_NO_BITFLIPS 129 
#define  STATUS_ECC_UNCOR_ERROR 128 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  macronix_spinand_table ; 
 int spi_mem_exec_op (int /*<<< orphan*/ ,struct spi_mem_op*) ; 
 int spinand_match_and_init (struct spinand_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct nand_device* spinand_to_nand (struct spinand_device*) ; 

__attribute__((used)) static int mx35lfxge4ab_ooblayout_ecc(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	return -ERANGE;
}

__attribute__((used)) static int mx35lfxge4ab_ooblayout_free(struct mtd_info *mtd, int section,
				       struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	region->offset = 2;
	region->length = mtd->oobsize - 2;

	return 0;
}

__attribute__((used)) static int mx35lf1ge4ab_get_eccsr(struct spinand_device *spinand, u8 *eccsr)
{
	struct spi_mem_op op = SPI_MEM_OP(SPI_MEM_OP_CMD(0x7c, 1),
					  SPI_MEM_OP_NO_ADDR,
					  SPI_MEM_OP_DUMMY(1, 1),
					  SPI_MEM_OP_DATA_IN(1, eccsr, 1));

	return spi_mem_exec_op(spinand->spimem, &op);
}

__attribute__((used)) static int mx35lf1ge4ab_ecc_get_status(struct spinand_device *spinand,
				       u8 status)
{
	struct nand_device *nand = spinand_to_nand(spinand);
	u8 eccsr;

	switch (status & STATUS_ECC_MASK) {
	case STATUS_ECC_NO_BITFLIPS:
		return 0;

	case STATUS_ECC_UNCOR_ERROR:
		return -EBADMSG;

	case STATUS_ECC_HAS_BITFLIPS:
		/*
		 * Let's try to retrieve the real maximum number of bitflips
		 * in order to avoid forcing the wear-leveling layer to move
		 * data around if it's not necessary.
		 */
		if (mx35lf1ge4ab_get_eccsr(spinand, &eccsr))
			return nand->eccreq.strength;

		if (WARN_ON(eccsr > nand->eccreq.strength || !eccsr))
			return nand->eccreq.strength;

		return eccsr;

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int macronix_spinand_detect(struct spinand_device *spinand)
{
	u8 *id = spinand->id.data;
	int ret;

	/*
	 * Macronix SPI NAND read ID needs a dummy byte, so the first byte in
	 * raw_id is garbage.
	 */
	if (id[1] != SPINAND_MFR_MACRONIX)
		return 0;

	ret = spinand_match_and_init(spinand, macronix_spinand_table,
				     ARRAY_SIZE(macronix_spinand_table),
				     id[2]);
	if (ret)
		return ret;

	return 1;
}

