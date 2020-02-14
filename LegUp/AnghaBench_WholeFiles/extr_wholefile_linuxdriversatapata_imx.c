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
typedef  int u32 ;
struct resource {scalar_t__ start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct pata_imx_priv {scalar_t__ clk; scalar_t__ host_regs; } ;
struct ata_timing {int setup; int act8b; } ;
struct ata_ioports {scalar_t__ ctl_addr; scalar_t__ altstatus_addr; scalar_t__ cmd_addr; scalar_t__ command_addr; scalar_t__ status_addr; scalar_t__ device_addr; scalar_t__ lbah_addr; scalar_t__ lbam_addr; scalar_t__ lbal_addr; scalar_t__ nsect_addr; scalar_t__ feature_addr; scalar_t__ error_addr; scalar_t__ data_addr; } ;
struct ata_port {struct ata_ioports ioaddr; int /*<<< orphan*/  flags; int /*<<< orphan*/  pio_mask; int /*<<< orphan*/ * ops; TYPE_1__* host; } ;
struct ata_host {struct pata_imx_priv* private_data; struct ata_port** ports; } ;
struct ata_device {scalar_t__ pio_mode; } ;
struct TYPE_2__ {struct pata_imx_priv* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATA_FLAG_SLAVE_POSS ; 
 int /*<<< orphan*/  ATA_PIO4 ; 
 int ATA_REG_CMD ; 
 int ATA_REG_DATA ; 
 int ATA_REG_DEVICE ; 
 int ATA_REG_ERR ; 
 int ATA_REG_FEATURE ; 
 int ATA_REG_LBAH ; 
 int ATA_REG_LBAL ; 
 int ATA_REG_LBAM ; 
 int ATA_REG_NSECT ; 
 int ATA_REG_STATUS ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ PATA_IMX_ATA_CONTROL ; 
 int PATA_IMX_ATA_CTRL_ATA_RST_B ; 
 int PATA_IMX_ATA_CTRL_FIFO_RST_B ; 
 int PATA_IMX_ATA_CTRL_IORDY_EN ; 
 int PATA_IMX_ATA_INTR_ATA_INTRQ2 ; 
 scalar_t__ PATA_IMX_ATA_INT_EN ; 
 scalar_t__ PATA_IMX_ATA_TIME_1 ; 
 scalar_t__ PATA_IMX_ATA_TIME_2R ; 
 scalar_t__ PATA_IMX_ATA_TIME_2W ; 
 scalar_t__ PATA_IMX_ATA_TIME_4 ; 
 scalar_t__ PATA_IMX_ATA_TIME_9 ; 
 scalar_t__ PATA_IMX_ATA_TIME_AX ; 
 scalar_t__ PATA_IMX_ATA_TIME_OFF ; 
 scalar_t__ PATA_IMX_ATA_TIME_ON ; 
 scalar_t__ PATA_IMX_ATA_TIME_PIO_RDX ; 
 scalar_t__ PATA_IMX_DRIVE_CONTROL ; 
 scalar_t__ PATA_IMX_DRIVE_DATA ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ XFER_PIO_0 ; 
 scalar_t__ XFER_PIO_4 ; 
 int __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int,scalar_t__) ; 
 int ata_host_activate (struct ata_host*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct ata_host* ata_host_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ata_host_detach (struct ata_host*) ; 
 scalar_t__ ata_pio_need_iordy (struct ata_device*) ; 
 int /*<<< orphan*/  ata_port_desc (struct ata_port*,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ata_sff_interrupt ; 
 int /*<<< orphan*/  ata_timing_compute (struct ata_device*,scalar_t__,struct ata_timing*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct pata_imx_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pata_imx_port_ops ; 
 int /*<<< orphan*/  pata_imx_sht ; 
 int* pio_t4 ; 
 int* pio_t9 ; 
 int* pio_tA ; 
 struct ata_host* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static void pata_imx_set_timing(struct ata_device *adev,
				struct pata_imx_priv *priv)
{
	struct ata_timing timing;
	unsigned long clkrate;
	u32 T, mode;

	clkrate = clk_get_rate(priv->clk);

	if (adev->pio_mode < XFER_PIO_0 || adev->pio_mode > XFER_PIO_4 ||
	    !clkrate)
		return;

	T = 1000000000 / clkrate;
	ata_timing_compute(adev, adev->pio_mode, &timing, T * 1000, 0);

	mode = adev->pio_mode - XFER_PIO_0;

	writeb(3, priv->host_regs + PATA_IMX_ATA_TIME_OFF);
	writeb(3, priv->host_regs + PATA_IMX_ATA_TIME_ON);
	writeb(timing.setup, priv->host_regs + PATA_IMX_ATA_TIME_1);
	writeb(timing.act8b, priv->host_regs + PATA_IMX_ATA_TIME_2W);
	writeb(timing.act8b, priv->host_regs + PATA_IMX_ATA_TIME_2R);
	writeb(1, priv->host_regs + PATA_IMX_ATA_TIME_PIO_RDX);

	writeb(pio_t4[mode] / T + 1, priv->host_regs + PATA_IMX_ATA_TIME_4);
	writeb(pio_t9[mode] / T + 1, priv->host_regs + PATA_IMX_ATA_TIME_9);
	writeb(pio_tA[mode] / T + 1, priv->host_regs + PATA_IMX_ATA_TIME_AX);
}

__attribute__((used)) static void pata_imx_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
	struct pata_imx_priv *priv = ap->host->private_data;
	u32 val;

	pata_imx_set_timing(adev, priv);

	val = __raw_readl(priv->host_regs + PATA_IMX_ATA_CONTROL);
	if (ata_pio_need_iordy(adev))
		val |= PATA_IMX_ATA_CTRL_IORDY_EN;
	else
		val &= ~PATA_IMX_ATA_CTRL_IORDY_EN;
	__raw_writel(val, priv->host_regs + PATA_IMX_ATA_CONTROL);
}

__attribute__((used)) static void pata_imx_setup_port(struct ata_ioports *ioaddr)
{
	/* Fixup the port shift for platforms that need it */
	ioaddr->data_addr	= ioaddr->cmd_addr + (ATA_REG_DATA    << 2);
	ioaddr->error_addr	= ioaddr->cmd_addr + (ATA_REG_ERR     << 2);
	ioaddr->feature_addr	= ioaddr->cmd_addr + (ATA_REG_FEATURE << 2);
	ioaddr->nsect_addr	= ioaddr->cmd_addr + (ATA_REG_NSECT   << 2);
	ioaddr->lbal_addr	= ioaddr->cmd_addr + (ATA_REG_LBAL    << 2);
	ioaddr->lbam_addr	= ioaddr->cmd_addr + (ATA_REG_LBAM    << 2);
	ioaddr->lbah_addr	= ioaddr->cmd_addr + (ATA_REG_LBAH    << 2);
	ioaddr->device_addr	= ioaddr->cmd_addr + (ATA_REG_DEVICE  << 2);
	ioaddr->status_addr	= ioaddr->cmd_addr + (ATA_REG_STATUS  << 2);
	ioaddr->command_addr	= ioaddr->cmd_addr + (ATA_REG_CMD     << 2);
}

__attribute__((used)) static int pata_imx_probe(struct platform_device *pdev)
{
	struct ata_host *host;
	struct ata_port *ap;
	struct pata_imx_priv *priv;
	int irq = 0;
	struct resource *io_res;
	int ret;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	priv = devm_kzalloc(&pdev->dev,
				sizeof(struct pata_imx_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(priv->clk)) {
		dev_err(&pdev->dev, "Failed to get clock\n");
		return PTR_ERR(priv->clk);
	}

	ret = clk_prepare_enable(priv->clk);
	if (ret)
		return ret;

	host = ata_host_alloc(&pdev->dev, 1);
	if (!host) {
		ret = -ENOMEM;
		goto err;
	}

	host->private_data = priv;
	ap = host->ports[0];

	ap->ops = &pata_imx_port_ops;
	ap->pio_mask = ATA_PIO4;
	ap->flags |= ATA_FLAG_SLAVE_POSS;

	io_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->host_regs = devm_ioremap_resource(&pdev->dev, io_res);
	if (IS_ERR(priv->host_regs)) {
		ret = PTR_ERR(priv->host_regs);
		goto err;
	}

	ap->ioaddr.cmd_addr = priv->host_regs + PATA_IMX_DRIVE_DATA;
	ap->ioaddr.ctl_addr = priv->host_regs + PATA_IMX_DRIVE_CONTROL;

	ap->ioaddr.altstatus_addr = ap->ioaddr.ctl_addr;

	pata_imx_setup_port(&ap->ioaddr);

	ata_port_desc(ap, "cmd 0x%llx ctl 0x%llx",
		(unsigned long long)io_res->start + PATA_IMX_DRIVE_DATA,
		(unsigned long long)io_res->start + PATA_IMX_DRIVE_CONTROL);

	/* deassert resets */
	__raw_writel(PATA_IMX_ATA_CTRL_FIFO_RST_B |
			PATA_IMX_ATA_CTRL_ATA_RST_B,
			priv->host_regs + PATA_IMX_ATA_CONTROL);
	/* enable interrupts */
	__raw_writel(PATA_IMX_ATA_INTR_ATA_INTRQ2,
			priv->host_regs + PATA_IMX_ATA_INT_EN);

	/* activate */
	ret = ata_host_activate(host, irq, ata_sff_interrupt, 0,
				&pata_imx_sht);

	if (ret)
		goto err;

	return 0;
err:
	clk_disable_unprepare(priv->clk);

	return ret;
}

__attribute__((used)) static int pata_imx_remove(struct platform_device *pdev)
{
	struct ata_host *host = platform_get_drvdata(pdev);
	struct pata_imx_priv *priv = host->private_data;

	ata_host_detach(host);

	__raw_writel(0, priv->host_regs + PATA_IMX_ATA_INT_EN);

	clk_disable_unprepare(priv->clk);

	return 0;
}

