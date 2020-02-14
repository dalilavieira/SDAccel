#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  void* u_char ;
typedef  void* u8 ;
typedef  int u32 ;
struct TYPE_9__ {int /*<<< orphan*/  algo; int /*<<< orphan*/  mode; } ;
struct TYPE_10__ {void (* cmd_ctrl ) (struct mtd_info*,int,unsigned int) ;int (* dev_ready ) (struct mtd_info*) ;void (* select_chip ) (struct mtd_info*,int) ;void (* write_buf ) (struct mtd_info*,void* const*,int) ;void (* read_buf ) (struct mtd_info*,void**,int) ;unsigned char (* read_byte ) (struct mtd_info*) ;int chip_delay; TYPE_2__ ecc; } ;
struct xway_nand_data {TYPE_3__ chip; scalar_t__ nandaddr; int /*<<< orphan*/  csflags; } ;
struct resource {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_6__ dev; } ;
struct nand_chip {int dummy; } ;
struct TYPE_8__ {TYPE_6__* parent; } ;
struct mtd_info {TYPE_1__ dev; } ;

/* Variables and functions */
 int ADDSEL1_MASK (int) ; 
 int ADDSEL1_REGEN ; 
 int /*<<< orphan*/  BUG () ; 
 int BUSCON1_BCGEN_RES ; 
 int BUSCON1_CMULT4 ; 
 int BUSCON1_HOLDC1 ; 
 int BUSCON1_RECOVC1 ; 
 int BUSCON1_SETUP ; 
 int BUSCON1_WAITRDC2 ; 
 int BUSCON1_WAITWRC2 ; 
 int CPHYSADDR (scalar_t__) ; 
 int /*<<< orphan*/  EBU_ADDSEL1 ; 
 int /*<<< orphan*/  EBU_NAND_CON ; 
 int /*<<< orphan*/  EBU_NAND_WAIT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int /*<<< orphan*/  LTQ_EBU_BUSCON1 ; 
 unsigned int NAND_ALE ; 
 unsigned int NAND_CLE ; 
 int NAND_CMD_NONE ; 
 int NAND_CON_CE ; 
 int NAND_CON_CSMUX ; 
 int NAND_CON_CS_P ; 
 int NAND_CON_IN_CS1 ; 
 int NAND_CON_NANDM ; 
 int NAND_CON_OUT_CS1 ; 
 int NAND_CON_PRE_P ; 
 int NAND_CON_SE_P ; 
 int NAND_CON_WP_P ; 
 int /*<<< orphan*/  NAND_ECC_HAMMING ; 
 int /*<<< orphan*/  NAND_ECC_SOFT ; 
 int NAND_READ_DATA ; 
 int NAND_WAIT_RD ; 
 int NAND_WAIT_WR_C ; 
 int NAND_WRITE_ADDR ; 
 int NAND_WRITE_CMD ; 
 int NAND_WRITE_DATA ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ devm_ioremap_resource (TYPE_6__*,struct resource*) ; 
 struct xway_nand_data* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ebu_lock ; 
 int ltq_ebu_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_ebu_w32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_ebu_w32_mask (int,int,int /*<<< orphan*/ ) ; 
 int mtd_device_register (struct mtd_info*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct nand_chip* mtd_to_nand (struct mtd_info*) ; 
 struct xway_nand_data* nand_get_controller_data (struct nand_chip*) ; 
 int /*<<< orphan*/  nand_release (struct mtd_info*) ; 
 int nand_scan (struct mtd_info*,int) ; 
 int /*<<< orphan*/  nand_set_controller_data (TYPE_3__*,struct xway_nand_data*) ; 
 int /*<<< orphan*/  nand_set_flash_node (TYPE_3__*,int /*<<< orphan*/ ) ; 
 struct mtd_info* nand_to_mtd (TYPE_3__*) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 struct xway_nand_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xway_nand_data*) ; 
 void* readb (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeb (void*,scalar_t__) ; 

__attribute__((used)) static u8 xway_readb(struct mtd_info *mtd, int op)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct xway_nand_data *data = nand_get_controller_data(chip);

	return readb(data->nandaddr + op);
}

__attribute__((used)) static void xway_writeb(struct mtd_info *mtd, int op, u8 value)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct xway_nand_data *data = nand_get_controller_data(chip);

	writeb(value, data->nandaddr + op);
}

__attribute__((used)) static void xway_select_chip(struct mtd_info *mtd, int select)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct xway_nand_data *data = nand_get_controller_data(chip);

	switch (select) {
	case -1:
		ltq_ebu_w32_mask(NAND_CON_CE, 0, EBU_NAND_CON);
		ltq_ebu_w32_mask(NAND_CON_NANDM, 0, EBU_NAND_CON);
		spin_unlock_irqrestore(&ebu_lock, data->csflags);
		break;
	case 0:
		spin_lock_irqsave(&ebu_lock, data->csflags);
		ltq_ebu_w32_mask(0, NAND_CON_NANDM, EBU_NAND_CON);
		ltq_ebu_w32_mask(0, NAND_CON_CE, EBU_NAND_CON);
		break;
	default:
		BUG();
	}
}

__attribute__((used)) static void xway_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
	if (cmd == NAND_CMD_NONE)
		return;

	if (ctrl & NAND_CLE)
		xway_writeb(mtd, NAND_WRITE_CMD, cmd);
	else if (ctrl & NAND_ALE)
		xway_writeb(mtd, NAND_WRITE_ADDR, cmd);

	while ((ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_WR_C) == 0)
		;
}

__attribute__((used)) static int xway_dev_ready(struct mtd_info *mtd)
{
	return ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_RD;
}

__attribute__((used)) static unsigned char xway_read_byte(struct mtd_info *mtd)
{
	return xway_readb(mtd, NAND_READ_DATA);
}

__attribute__((used)) static void xway_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
	int i;

	for (i = 0; i < len; i++)
		buf[i] = xway_readb(mtd, NAND_WRITE_DATA);
}

__attribute__((used)) static void xway_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
	int i;

	for (i = 0; i < len; i++)
		xway_writeb(mtd, NAND_WRITE_DATA, buf[i]);
}

__attribute__((used)) static int xway_nand_probe(struct platform_device *pdev)
{
	struct xway_nand_data *data;
	struct mtd_info *mtd;
	struct resource *res;
	int err;
	u32 cs;
	u32 cs_flag = 0;

	/* Allocate memory for the device structure (and zero it) */
	data = devm_kzalloc(&pdev->dev, sizeof(struct xway_nand_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	data->nandaddr = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(data->nandaddr))
		return PTR_ERR(data->nandaddr);

	nand_set_flash_node(&data->chip, pdev->dev.of_node);
	mtd = nand_to_mtd(&data->chip);
	mtd->dev.parent = &pdev->dev;

	data->chip.cmd_ctrl = xway_cmd_ctrl;
	data->chip.dev_ready = xway_dev_ready;
	data->chip.select_chip = xway_select_chip;
	data->chip.write_buf = xway_write_buf;
	data->chip.read_buf = xway_read_buf;
	data->chip.read_byte = xway_read_byte;
	data->chip.chip_delay = 30;

	data->chip.ecc.mode = NAND_ECC_SOFT;
	data->chip.ecc.algo = NAND_ECC_HAMMING;

	platform_set_drvdata(pdev, data);
	nand_set_controller_data(&data->chip, data);

	/* load our CS from the DT. Either we find a valid 1 or default to 0 */
	err = of_property_read_u32(pdev->dev.of_node, "lantiq,cs", &cs);
	if (!err && cs == 1)
		cs_flag = NAND_CON_IN_CS1 | NAND_CON_OUT_CS1;

	/* setup the EBU to run in NAND mode on our base addr */
	ltq_ebu_w32(CPHYSADDR(data->nandaddr)
		    | ADDSEL1_MASK(3) | ADDSEL1_REGEN, EBU_ADDSEL1);

	ltq_ebu_w32(BUSCON1_SETUP | BUSCON1_BCGEN_RES | BUSCON1_WAITWRC2
		    | BUSCON1_WAITRDC2 | BUSCON1_HOLDC1 | BUSCON1_RECOVC1
		    | BUSCON1_CMULT4, LTQ_EBU_BUSCON1);

	ltq_ebu_w32(NAND_CON_NANDM | NAND_CON_CSMUX | NAND_CON_CS_P
		    | NAND_CON_SE_P | NAND_CON_WP_P | NAND_CON_PRE_P
		    | cs_flag, EBU_NAND_CON);

	/* Scan to find existence of the device */
	err = nand_scan(mtd, 1);
	if (err)
		return err;

	err = mtd_device_register(mtd, NULL, 0);
	if (err)
		nand_release(mtd);

	return err;
}

__attribute__((used)) static int xway_nand_remove(struct platform_device *pdev)
{
	struct xway_nand_data *data = platform_get_drvdata(pdev);

	nand_release(nand_to_mtd(&data->chip));

	return 0;
}

