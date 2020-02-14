#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct spi_nor_hwcaps {int mask; } ;
struct spi_nor {int program_opcode; int addr_width; int erase_opcode; int read_proto; int read_opcode; int read_dummy; int (* read_reg ) (struct spi_nor*,int,int*,int) ;int (* read ) (struct spi_nor*,int,size_t,int /*<<< orphan*/ *) ;int (* write ) (struct spi_nor*,int,size_t,int /*<<< orphan*/  const*) ;int (* erase ) (struct spi_nor*,int) ;int (* write_reg ) (struct spi_nor*,int,int*,int) ;int /*<<< orphan*/  mtd; struct nxp_spifi* priv; TYPE_1__* dev; } ;
struct resource {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct nxp_spifi {int io_base; int memory_mode; int mcmd; int flash_base; int clk_spifi; int clk_reg; struct spi_nor nor; TYPE_1__* dev; } ;
struct device_node {int dummy; } ;
typedef  int ssize_t ;
typedef  int loff_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int) ; 
 int PTR_ERR (int) ; 
 int SNOR_HWCAPS_PP ; 
 int SNOR_HWCAPS_READ ; 
 int SNOR_HWCAPS_READ_1_1_2 ; 
 int SNOR_HWCAPS_READ_1_1_4 ; 
 int SNOR_HWCAPS_READ_FAST ; 
#define  SNOR_PROTO_1_1_1 132 
#define  SNOR_PROTO_1_1_2 131 
#define  SNOR_PROTO_1_1_4 130 
 int SPIFI_ADDR ; 
 int SPIFI_CMD ; 
 int SPIFI_CMD_DATALEN (size_t) ; 
 int SPIFI_CMD_DOUT ; 
 int SPIFI_CMD_FIELDFORM_ALL_SERIAL ; 
 int SPIFI_CMD_FIELDFORM_QUAD_DUAL_DATA ; 
 int SPIFI_CMD_FRAMEFORM (int) ; 
 int SPIFI_CMD_FRAMEFORM_OPCODE_ONLY ; 
 int SPIFI_CMD_INTLEN (int) ; 
 int SPIFI_CMD_OPCODE (int) ; 
 int SPIFI_CTRL ; 
 int SPIFI_CTRL_CSHIGH (int) ; 
 int SPIFI_CTRL_DUAL ; 
 int SPIFI_CTRL_FBCLK ; 
 int SPIFI_CTRL_MODE3 ; 
 int SPIFI_CTRL_TIMEOUT (int) ; 
 int SPIFI_DATA ; 
 int SPIFI_IDATA ; 
 int SPIFI_MCMD ; 
 int SPIFI_STAT ; 
 int SPIFI_STAT_CMD ; 
 int SPIFI_STAT_MCINIT ; 
 int SPIFI_STAT_RESET ; 
 int SPINOR_OP_RDID ; 
 int SPI_CPHA ; 
 int SPI_CPOL ; 
#define  SPI_MODE_0 129 
#define  SPI_MODE_3 128 
 int SPI_NOR_MAX_ID_LEN ; 
 int SPI_RX_DUAL ; 
 int SPI_RX_QUAD ; 
 int /*<<< orphan*/  clk_disable_unprepare (int) ; 
 int clk_prepare_enable (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 void* devm_clk_get (TYPE_1__*,char*) ; 
 void* devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 struct nxp_spifi* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy_fromio (int /*<<< orphan*/ *,int,size_t) ; 
 int mtd_device_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtd_device_unregister (int /*<<< orphan*/ *) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct device_node* of_get_next_available_child (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct nxp_spifi* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct nxp_spifi*) ; 
 int /*<<< orphan*/  readb (int) ; 
 int readb_poll_timeout (int,int,int,int,int) ; 
 int spi_nor_scan (struct spi_nor*,int /*<<< orphan*/ *,struct spi_nor_hwcaps*) ; 
 int /*<<< orphan*/  spi_nor_set_flash_node (struct spi_nor*,struct device_node*) ; 
 int stub1 (struct spi_nor*,int,int*,int) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/  const,int) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static int nxp_spifi_wait_for_cmd(struct nxp_spifi *spifi)
{
	u8 stat;
	int ret;

	ret = readb_poll_timeout(spifi->io_base + SPIFI_STAT, stat,
				 !(stat & SPIFI_STAT_CMD), 10, 30);
	if (ret)
		dev_warn(spifi->dev, "command timed out\n");

	return ret;
}

__attribute__((used)) static int nxp_spifi_reset(struct nxp_spifi *spifi)
{
	u8 stat;
	int ret;

	writel(SPIFI_STAT_RESET, spifi->io_base + SPIFI_STAT);
	ret = readb_poll_timeout(spifi->io_base + SPIFI_STAT, stat,
				 !(stat & SPIFI_STAT_RESET), 10, 30);
	if (ret)
		dev_warn(spifi->dev, "state reset timed out\n");

	return ret;
}

__attribute__((used)) static int nxp_spifi_set_memory_mode_off(struct nxp_spifi *spifi)
{
	int ret;

	if (!spifi->memory_mode)
		return 0;

	ret = nxp_spifi_reset(spifi);
	if (ret)
		dev_err(spifi->dev, "unable to enter command mode\n");
	else
		spifi->memory_mode = false;

	return ret;
}

__attribute__((used)) static int nxp_spifi_set_memory_mode_on(struct nxp_spifi *spifi)
{
	u8 stat;
	int ret;

	if (spifi->memory_mode)
		return 0;

	writel(spifi->mcmd, spifi->io_base + SPIFI_MCMD);
	ret = readb_poll_timeout(spifi->io_base + SPIFI_STAT, stat,
				 stat & SPIFI_STAT_MCINIT, 10, 30);
	if (ret)
		dev_err(spifi->dev, "unable to enter memory mode\n");
	else
		spifi->memory_mode = true;

	return ret;
}

__attribute__((used)) static int nxp_spifi_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
	struct nxp_spifi *spifi = nor->priv;
	u32 cmd;
	int ret;

	ret = nxp_spifi_set_memory_mode_off(spifi);
	if (ret)
		return ret;

	cmd = SPIFI_CMD_DATALEN(len) |
	      SPIFI_CMD_OPCODE(opcode) |
	      SPIFI_CMD_FIELDFORM_ALL_SERIAL |
	      SPIFI_CMD_FRAMEFORM_OPCODE_ONLY;
	writel(cmd, spifi->io_base + SPIFI_CMD);

	while (len--)
		*buf++ = readb(spifi->io_base + SPIFI_DATA);

	return nxp_spifi_wait_for_cmd(spifi);
}

__attribute__((used)) static int nxp_spifi_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
	struct nxp_spifi *spifi = nor->priv;
	u32 cmd;
	int ret;

	ret = nxp_spifi_set_memory_mode_off(spifi);
	if (ret)
		return ret;

	cmd = SPIFI_CMD_DOUT |
	      SPIFI_CMD_DATALEN(len) |
	      SPIFI_CMD_OPCODE(opcode) |
	      SPIFI_CMD_FIELDFORM_ALL_SERIAL |
	      SPIFI_CMD_FRAMEFORM_OPCODE_ONLY;
	writel(cmd, spifi->io_base + SPIFI_CMD);

	while (len--)
		writeb(*buf++, spifi->io_base + SPIFI_DATA);

	return nxp_spifi_wait_for_cmd(spifi);
}

__attribute__((used)) static ssize_t nxp_spifi_read(struct spi_nor *nor, loff_t from, size_t len,
			      u_char *buf)
{
	struct nxp_spifi *spifi = nor->priv;
	int ret;

	ret = nxp_spifi_set_memory_mode_on(spifi);
	if (ret)
		return ret;

	memcpy_fromio(buf, spifi->flash_base + from, len);

	return len;
}

__attribute__((used)) static ssize_t nxp_spifi_write(struct spi_nor *nor, loff_t to, size_t len,
			       const u_char *buf)
{
	struct nxp_spifi *spifi = nor->priv;
	u32 cmd;
	int ret;
	size_t i;

	ret = nxp_spifi_set_memory_mode_off(spifi);
	if (ret)
		return ret;

	writel(to, spifi->io_base + SPIFI_ADDR);

	cmd = SPIFI_CMD_DOUT |
	      SPIFI_CMD_DATALEN(len) |
	      SPIFI_CMD_FIELDFORM_ALL_SERIAL |
	      SPIFI_CMD_OPCODE(nor->program_opcode) |
	      SPIFI_CMD_FRAMEFORM(spifi->nor.addr_width + 1);
	writel(cmd, spifi->io_base + SPIFI_CMD);

	for (i = 0; i < len; i++)
		writeb(buf[i], spifi->io_base + SPIFI_DATA);

	ret = nxp_spifi_wait_for_cmd(spifi);
	if (ret)
		return ret;

	return len;
}

__attribute__((used)) static int nxp_spifi_erase(struct spi_nor *nor, loff_t offs)
{
	struct nxp_spifi *spifi = nor->priv;
	u32 cmd;
	int ret;

	ret = nxp_spifi_set_memory_mode_off(spifi);
	if (ret)
		return ret;

	writel(offs, spifi->io_base + SPIFI_ADDR);

	cmd = SPIFI_CMD_FIELDFORM_ALL_SERIAL |
	      SPIFI_CMD_OPCODE(nor->erase_opcode) |
	      SPIFI_CMD_FRAMEFORM(spifi->nor.addr_width + 1);
	writel(cmd, spifi->io_base + SPIFI_CMD);

	return nxp_spifi_wait_for_cmd(spifi);
}

__attribute__((used)) static int nxp_spifi_setup_memory_cmd(struct nxp_spifi *spifi)
{
	switch (spifi->nor.read_proto) {
	case SNOR_PROTO_1_1_1:
		spifi->mcmd = SPIFI_CMD_FIELDFORM_ALL_SERIAL;
		break;
	case SNOR_PROTO_1_1_2:
	case SNOR_PROTO_1_1_4:
		spifi->mcmd = SPIFI_CMD_FIELDFORM_QUAD_DUAL_DATA;
		break;
	default:
		dev_err(spifi->dev, "unsupported SPI read mode\n");
		return -EINVAL;
	}

	/* Memory mode supports address length between 1 and 4 */
	if (spifi->nor.addr_width < 1 || spifi->nor.addr_width > 4)
		return -EINVAL;

	spifi->mcmd |= SPIFI_CMD_OPCODE(spifi->nor.read_opcode) |
		       SPIFI_CMD_INTLEN(spifi->nor.read_dummy / 8) |
		       SPIFI_CMD_FRAMEFORM(spifi->nor.addr_width + 1);

	return 0;
}

__attribute__((used)) static void nxp_spifi_dummy_id_read(struct spi_nor *nor)
{
	u8 id[SPI_NOR_MAX_ID_LEN];
	nor->read_reg(nor, SPINOR_OP_RDID, id, SPI_NOR_MAX_ID_LEN);
}

__attribute__((used)) static int nxp_spifi_setup_flash(struct nxp_spifi *spifi,
				 struct device_node *np)
{
	struct spi_nor_hwcaps hwcaps = {
		.mask = SNOR_HWCAPS_READ |
			SNOR_HWCAPS_READ_FAST |
			SNOR_HWCAPS_PP,
	};
	u32 ctrl, property;
	u16 mode = 0;
	int ret;

	if (!of_property_read_u32(np, "spi-rx-bus-width", &property)) {
		switch (property) {
		case 1:
			break;
		case 2:
			mode |= SPI_RX_DUAL;
			break;
		case 4:
			mode |= SPI_RX_QUAD;
			break;
		default:
			dev_err(spifi->dev, "unsupported rx-bus-width\n");
			return -EINVAL;
		}
	}

	if (of_find_property(np, "spi-cpha", NULL))
		mode |= SPI_CPHA;

	if (of_find_property(np, "spi-cpol", NULL))
		mode |= SPI_CPOL;

	/* Setup control register defaults */
	ctrl = SPIFI_CTRL_TIMEOUT(1000) |
	       SPIFI_CTRL_CSHIGH(15) |
	       SPIFI_CTRL_FBCLK;

	if (mode & SPI_RX_DUAL) {
		ctrl |= SPIFI_CTRL_DUAL;
		hwcaps.mask |= SNOR_HWCAPS_READ_1_1_2;
	} else if (mode & SPI_RX_QUAD) {
		ctrl &= ~SPIFI_CTRL_DUAL;
		hwcaps.mask |= SNOR_HWCAPS_READ_1_1_4;
	} else {
		ctrl |= SPIFI_CTRL_DUAL;
	}

	switch (mode & (SPI_CPHA | SPI_CPOL)) {
	case SPI_MODE_0:
		ctrl &= ~SPIFI_CTRL_MODE3;
		break;
	case SPI_MODE_3:
		ctrl |= SPIFI_CTRL_MODE3;
		break;
	default:
		dev_err(spifi->dev, "only mode 0 and 3 supported\n");
		return -EINVAL;
	}

	writel(ctrl, spifi->io_base + SPIFI_CTRL);

	spifi->nor.dev   = spifi->dev;
	spi_nor_set_flash_node(&spifi->nor, np);
	spifi->nor.priv  = spifi;
	spifi->nor.read  = nxp_spifi_read;
	spifi->nor.write = nxp_spifi_write;
	spifi->nor.erase = nxp_spifi_erase;
	spifi->nor.read_reg  = nxp_spifi_read_reg;
	spifi->nor.write_reg = nxp_spifi_write_reg;

	/*
	 * The first read on a hard reset isn't reliable so do a
	 * dummy read of the id before calling spi_nor_scan().
	 * The reason for this problem is unknown.
	 *
	 * The official NXP spifilib uses more or less the same
	 * workaround that is applied here by reading the device
	 * id multiple times.
	 */
	nxp_spifi_dummy_id_read(&spifi->nor);

	ret = spi_nor_scan(&spifi->nor, NULL, &hwcaps);
	if (ret) {
		dev_err(spifi->dev, "device scan failed\n");
		return ret;
	}

	ret = nxp_spifi_setup_memory_cmd(spifi);
	if (ret) {
		dev_err(spifi->dev, "memory command setup failed\n");
		return ret;
	}

	ret = mtd_device_register(&spifi->nor.mtd, NULL, 0);
	if (ret) {
		dev_err(spifi->dev, "mtd device parse failed\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int nxp_spifi_probe(struct platform_device *pdev)
{
	struct device_node *flash_np;
	struct nxp_spifi *spifi;
	struct resource *res;
	int ret;

	spifi = devm_kzalloc(&pdev->dev, sizeof(*spifi), GFP_KERNEL);
	if (!spifi)
		return -ENOMEM;

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "spifi");
	spifi->io_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(spifi->io_base))
		return PTR_ERR(spifi->io_base);

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "flash");
	spifi->flash_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(spifi->flash_base))
		return PTR_ERR(spifi->flash_base);

	spifi->clk_spifi = devm_clk_get(&pdev->dev, "spifi");
	if (IS_ERR(spifi->clk_spifi)) {
		dev_err(&pdev->dev, "spifi clock not found\n");
		return PTR_ERR(spifi->clk_spifi);
	}

	spifi->clk_reg = devm_clk_get(&pdev->dev, "reg");
	if (IS_ERR(spifi->clk_reg)) {
		dev_err(&pdev->dev, "reg clock not found\n");
		return PTR_ERR(spifi->clk_reg);
	}

	ret = clk_prepare_enable(spifi->clk_reg);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable reg clock\n");
		return ret;
	}

	ret = clk_prepare_enable(spifi->clk_spifi);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable spifi clock\n");
		goto dis_clk_reg;
	}

	spifi->dev = &pdev->dev;
	platform_set_drvdata(pdev, spifi);

	/* Initialize and reset device */
	nxp_spifi_reset(spifi);
	writel(0, spifi->io_base + SPIFI_IDATA);
	writel(0, spifi->io_base + SPIFI_MCMD);
	nxp_spifi_reset(spifi);

	flash_np = of_get_next_available_child(pdev->dev.of_node, NULL);
	if (!flash_np) {
		dev_err(&pdev->dev, "no SPI flash device to configure\n");
		ret = -ENODEV;
		goto dis_clks;
	}

	ret = nxp_spifi_setup_flash(spifi, flash_np);
	of_node_put(flash_np);
	if (ret) {
		dev_err(&pdev->dev, "unable to setup flash chip\n");
		goto dis_clks;
	}

	return 0;

dis_clks:
	clk_disable_unprepare(spifi->clk_spifi);
dis_clk_reg:
	clk_disable_unprepare(spifi->clk_reg);
	return ret;
}

__attribute__((used)) static int nxp_spifi_remove(struct platform_device *pdev)
{
	struct nxp_spifi *spifi = platform_get_drvdata(pdev);

	mtd_device_unregister(&spifi->nor.mtd);
	clk_disable_unprepare(spifi->clk_spifi);
	clk_disable_unprepare(spifi->clk_reg);

	return 0;
}

