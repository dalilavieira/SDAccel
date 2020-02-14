#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
typedef  scalar_t__ u8 ;
struct spi_nor_hwcaps {int mask; } ;
struct TYPE_16__ {scalar_t__ name; } ;
struct spi_nor {scalar_t__ program_opcode; scalar_t__ read_opcode; int read_dummy; int (* read ) (struct spi_nor*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ;int (* write ) (struct spi_nor*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/  const*) ;int (* write_reg ) (struct spi_nor*,scalar_t__,scalar_t__*,int) ;int (* read_reg ) (struct spi_nor*,scalar_t__,scalar_t__*,int) ;TYPE_6__ mtd; struct m25p* priv; TYPE_8__* dev; int /*<<< orphan*/  read_proto; int /*<<< orphan*/  addr_width; scalar_t__ sst_write_second; int /*<<< orphan*/  write_proto; } ;
struct TYPE_15__ {void* in; void* out; } ;
struct TYPE_14__ {size_t nbytes; TYPE_5__ buf; void* buswidth; } ;
struct TYPE_13__ {int buswidth; int /*<<< orphan*/  val; scalar_t__ nbytes; } ;
struct TYPE_11__ {int buswidth; int nbytes; } ;
struct TYPE_12__ {void* buswidth; } ;
struct spi_mem_op {TYPE_4__ data; TYPE_3__ addr; TYPE_1__ dummy; TYPE_2__ cmd; } ;
struct spi_mem {struct spi_device* spi; } ;
struct TYPE_17__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {int mode; char* modalias; TYPE_8__ dev; } ;
struct m25p {struct spi_nor spi_nor; struct spi_mem* spimem; } ;
struct flash_platform_data {char* type; int /*<<< orphan*/  nr_parts; int /*<<< orphan*/ * parts; scalar_t__ name; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int SNOR_HWCAPS_PP ; 
 int SNOR_HWCAPS_PP_1_1_4 ; 
 int SNOR_HWCAPS_PP_1_4_4 ; 
 int SNOR_HWCAPS_READ ; 
 int SNOR_HWCAPS_READ_1_1_2 ; 
 int SNOR_HWCAPS_READ_1_1_4 ; 
 int SNOR_HWCAPS_READ_1_2_2 ; 
 int SNOR_HWCAPS_READ_1_4_4 ; 
 int SNOR_HWCAPS_READ_FAST ; 
 scalar_t__ SPINOR_OP_AAI_WP ; 
 struct spi_mem_op SPI_MEM_OP (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPI_MEM_OP_ADDR (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_CMD (scalar_t__,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_DATA_IN (size_t,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_DATA_OUT (size_t,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_DUMMY (int,int) ; 
 int /*<<< orphan*/  SPI_MEM_OP_NO_ADDR ; 
 int /*<<< orphan*/  SPI_MEM_OP_NO_DUMMY ; 
 int SPI_RX_DUAL ; 
 int SPI_RX_QUAD ; 
 int SPI_TX_DUAL ; 
 int SPI_TX_QUAD ; 
 size_t UINT_MAX ; 
 int /*<<< orphan*/  dev_err (TYPE_8__*,char*,int,scalar_t__) ; 
 struct flash_platform_data* dev_get_platdata (TYPE_8__*) ; 
 struct m25p* devm_kzalloc (TYPE_8__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kmalloc (int,int /*<<< orphan*/ ) ; 
 void* kmemdup (scalar_t__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,void*,int) ; 
 int mtd_device_register (TYPE_6__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int mtd_device_unregister (TYPE_6__*) ; 
 int spi_mem_adjust_op_size (struct spi_mem*,struct spi_mem_op*) ; 
 int spi_mem_exec_op (struct spi_mem*,struct spi_mem_op*) ; 
 struct m25p* spi_mem_get_drvdata (struct spi_mem*) ; 
 scalar_t__ spi_mem_get_name (struct spi_mem*) ; 
 int /*<<< orphan*/  spi_mem_set_drvdata (struct spi_mem*,struct m25p*) ; 
 void* spi_nor_get_protocol_addr_nbits (int /*<<< orphan*/ ) ; 
 void* spi_nor_get_protocol_data_nbits (int /*<<< orphan*/ ) ; 
 void* spi_nor_get_protocol_inst_nbits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spi_nor_restore (struct spi_nor*) ; 
 int spi_nor_scan (struct spi_nor*,char*,struct spi_nor_hwcaps*) ; 
 int /*<<< orphan*/  spi_nor_set_flash_node (struct spi_nor*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

__attribute__((used)) static int m25p80_read_reg(struct spi_nor *nor, u8 code, u8 *val, int len)
{
	struct m25p *flash = nor->priv;
	struct spi_mem_op op = SPI_MEM_OP(SPI_MEM_OP_CMD(code, 1),
					  SPI_MEM_OP_NO_ADDR,
					  SPI_MEM_OP_NO_DUMMY,
					  SPI_MEM_OP_DATA_IN(len, NULL, 1));
	void *scratchbuf;
	int ret;

	scratchbuf = kmalloc(len, GFP_KERNEL);
	if (!scratchbuf)
		return -ENOMEM;

	op.data.buf.in = scratchbuf;
	ret = spi_mem_exec_op(flash->spimem, &op);
	if (ret < 0)
		dev_err(&flash->spimem->spi->dev, "error %d reading %x\n", ret,
			code);
	else
		memcpy(val, scratchbuf, len);

	kfree(scratchbuf);

	return ret;
}

__attribute__((used)) static int m25p80_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
	struct m25p *flash = nor->priv;
	struct spi_mem_op op = SPI_MEM_OP(SPI_MEM_OP_CMD(opcode, 1),
					  SPI_MEM_OP_NO_ADDR,
					  SPI_MEM_OP_NO_DUMMY,
					  SPI_MEM_OP_DATA_OUT(len, NULL, 1));
	void *scratchbuf;
	int ret;

	scratchbuf = kmemdup(buf, len, GFP_KERNEL);
	if (!scratchbuf)
		return -ENOMEM;

	op.data.buf.out = scratchbuf;
	ret = spi_mem_exec_op(flash->spimem, &op);
	kfree(scratchbuf);

	return ret;
}

__attribute__((used)) static ssize_t m25p80_write(struct spi_nor *nor, loff_t to, size_t len,
			    const u_char *buf)
{
	struct m25p *flash = nor->priv;
	struct spi_mem_op op =
			SPI_MEM_OP(SPI_MEM_OP_CMD(nor->program_opcode, 1),
				   SPI_MEM_OP_ADDR(nor->addr_width, to, 1),
				   SPI_MEM_OP_NO_DUMMY,
				   SPI_MEM_OP_DATA_OUT(len, buf, 1));
	size_t remaining = len;
	int ret;

	/* get transfer protocols. */
	op.cmd.buswidth = spi_nor_get_protocol_inst_nbits(nor->write_proto);
	op.addr.buswidth = spi_nor_get_protocol_addr_nbits(nor->write_proto);
	op.data.buswidth = spi_nor_get_protocol_data_nbits(nor->write_proto);

	if (nor->program_opcode == SPINOR_OP_AAI_WP && nor->sst_write_second)
		op.addr.nbytes = 0;

	while (remaining) {
		op.data.nbytes = remaining < UINT_MAX ? remaining : UINT_MAX;
		ret = spi_mem_adjust_op_size(flash->spimem, &op);
		if (ret)
			return ret;

		ret = spi_mem_exec_op(flash->spimem, &op);
		if (ret)
			return ret;

		op.addr.val += op.data.nbytes;
		remaining -= op.data.nbytes;
		op.data.buf.out += op.data.nbytes;
	}

	return len;
}

__attribute__((used)) static ssize_t m25p80_read(struct spi_nor *nor, loff_t from, size_t len,
			   u_char *buf)
{
	struct m25p *flash = nor->priv;
	struct spi_mem_op op =
			SPI_MEM_OP(SPI_MEM_OP_CMD(nor->read_opcode, 1),
				   SPI_MEM_OP_ADDR(nor->addr_width, from, 1),
				   SPI_MEM_OP_DUMMY(nor->read_dummy, 1),
				   SPI_MEM_OP_DATA_IN(len, buf, 1));
	size_t remaining = len;
	int ret;

	/* get transfer protocols. */
	op.cmd.buswidth = spi_nor_get_protocol_inst_nbits(nor->read_proto);
	op.addr.buswidth = spi_nor_get_protocol_addr_nbits(nor->read_proto);
	op.dummy.buswidth = op.addr.buswidth;
	op.data.buswidth = spi_nor_get_protocol_data_nbits(nor->read_proto);

	/* convert the dummy cycles to the number of bytes */
	op.dummy.nbytes = (nor->read_dummy * op.dummy.buswidth) / 8;

	while (remaining) {
		op.data.nbytes = remaining < UINT_MAX ? remaining : UINT_MAX;
		ret = spi_mem_adjust_op_size(flash->spimem, &op);
		if (ret)
			return ret;

		ret = spi_mem_exec_op(flash->spimem, &op);
		if (ret)
			return ret;

		op.addr.val += op.data.nbytes;
		remaining -= op.data.nbytes;
		op.data.buf.in += op.data.nbytes;
	}

	return len;
}

__attribute__((used)) static int m25p_probe(struct spi_mem *spimem)
{
	struct spi_device *spi = spimem->spi;
	struct flash_platform_data	*data;
	struct m25p *flash;
	struct spi_nor *nor;
	struct spi_nor_hwcaps hwcaps = {
		.mask = SNOR_HWCAPS_READ |
			SNOR_HWCAPS_READ_FAST |
			SNOR_HWCAPS_PP,
	};
	char *flash_name;
	int ret;

	data = dev_get_platdata(&spimem->spi->dev);

	flash = devm_kzalloc(&spimem->spi->dev, sizeof(*flash), GFP_KERNEL);
	if (!flash)
		return -ENOMEM;

	nor = &flash->spi_nor;

	/* install the hooks */
	nor->read = m25p80_read;
	nor->write = m25p80_write;
	nor->write_reg = m25p80_write_reg;
	nor->read_reg = m25p80_read_reg;

	nor->dev = &spimem->spi->dev;
	spi_nor_set_flash_node(nor, spi->dev.of_node);
	nor->priv = flash;

	spi_mem_set_drvdata(spimem, flash);
	flash->spimem = spimem;

	if (spi->mode & SPI_RX_QUAD) {
		hwcaps.mask |= SNOR_HWCAPS_READ_1_1_4;

		if (spi->mode & SPI_TX_QUAD)
			hwcaps.mask |= (SNOR_HWCAPS_READ_1_4_4 |
					SNOR_HWCAPS_PP_1_1_4 |
					SNOR_HWCAPS_PP_1_4_4);
	} else if (spi->mode & SPI_RX_DUAL) {
		hwcaps.mask |= SNOR_HWCAPS_READ_1_1_2;

		if (spi->mode & SPI_TX_DUAL)
			hwcaps.mask |= SNOR_HWCAPS_READ_1_2_2;
	}

	if (data && data->name)
		nor->mtd.name = data->name;

	if (!nor->mtd.name)
		nor->mtd.name = spi_mem_get_name(spimem);

	/* For some (historical?) reason many platforms provide two different
	 * names in flash_platform_data: "name" and "type". Quite often name is
	 * set to "m25p80" and then "type" provides a real chip name.
	 * If that's the case, respect "type" and ignore a "name".
	 */
	if (data && data->type)
		flash_name = data->type;
	else if (!strcmp(spi->modalias, "spi-nor"))
		flash_name = NULL; /* auto-detect */
	else
		flash_name = spi->modalias;

	ret = spi_nor_scan(nor, flash_name, &hwcaps);
	if (ret)
		return ret;

	return mtd_device_register(&nor->mtd, data ? data->parts : NULL,
				   data ? data->nr_parts : 0);
}

__attribute__((used)) static int m25p_remove(struct spi_mem *spimem)
{
	struct m25p	*flash = spi_mem_get_drvdata(spimem);

	spi_nor_restore(&flash->spi_nor);

	/* Clean up MTD stuff. */
	return mtd_device_unregister(&flash->spi_nor.mtd);
}

__attribute__((used)) static void m25p_shutdown(struct spi_mem *spimem)
{
	struct m25p *flash = spi_mem_get_drvdata(spimem);

	spi_nor_restore(&flash->spi_nor);
}

