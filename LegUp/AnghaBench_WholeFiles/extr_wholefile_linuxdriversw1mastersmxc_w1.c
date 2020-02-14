#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {int (* reset_bus ) (void*) ;int (* touch_bit ) (void*,int) ;struct mxc_w1_device* data; } ;
struct mxc_w1_device {scalar_t__ clk; TYPE_1__ bus_master; scalar_t__ regs; } ;

/* Variables and functions */
 unsigned int DIV_ROUND_CLOSEST (unsigned long,int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ MXC_W1_CONTROL ; 
 int MXC_W1_CONTROL_PST ; 
 int MXC_W1_CONTROL_RDST ; 
 int MXC_W1_CONTROL_RPP ; 
 int MXC_W1_CONTROL_WR (int) ; 
 scalar_t__ MXC_W1_RESET ; 
 unsigned int MXC_W1_RESET_RST ; 
 scalar_t__ MXC_W1_TIME_DIVIDER ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct mxc_w1_device* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 struct mxc_w1_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mxc_w1_device*) ; 
 int readb (scalar_t__) ; 
 scalar_t__ time_is_after_jiffies (unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 unsigned long usecs_to_jiffies (int) ; 
 int w1_add_master_device (TYPE_1__*) ; 
 int /*<<< orphan*/  w1_remove_master_device (TYPE_1__*) ; 
 int /*<<< orphan*/  writeb (unsigned int,scalar_t__) ; 

__attribute__((used)) static u8 mxc_w1_ds2_reset_bus(void *data)
{
	struct mxc_w1_device *dev = data;
	unsigned long timeout;

	writeb(MXC_W1_CONTROL_RPP, dev->regs + MXC_W1_CONTROL);

	/* Wait for reset sequence 511+512us, use 1500us for sure */
	timeout = jiffies + usecs_to_jiffies(1500);

	udelay(511 + 512);

	do {
		u8 ctrl = readb(dev->regs + MXC_W1_CONTROL);

		/* PST bit is valid after the RPP bit is self-cleared */
		if (!(ctrl & MXC_W1_CONTROL_RPP))
			return !(ctrl & MXC_W1_CONTROL_PST);
	} while (time_is_after_jiffies(timeout));

	return 1;
}

__attribute__((used)) static u8 mxc_w1_ds2_touch_bit(void *data, u8 bit)
{
	struct mxc_w1_device *dev = data;
	unsigned long timeout;

	writeb(MXC_W1_CONTROL_WR(bit), dev->regs + MXC_W1_CONTROL);

	/* Wait for read/write bit (60us, Max 120us), use 200us for sure */
	timeout = jiffies + usecs_to_jiffies(200);

	udelay(60);

	do {
		u8 ctrl = readb(dev->regs + MXC_W1_CONTROL);

		/* RDST bit is valid after the WR1/RD bit is self-cleared */
		if (!(ctrl & MXC_W1_CONTROL_WR(bit)))
			return !!(ctrl & MXC_W1_CONTROL_RDST);
	} while (time_is_after_jiffies(timeout));

	return 0;
}

__attribute__((used)) static int mxc_w1_probe(struct platform_device *pdev)
{
	struct mxc_w1_device *mdev;
	unsigned long clkrate;
	struct resource *res;
	unsigned int clkdiv;
	int err;

	mdev = devm_kzalloc(&pdev->dev, sizeof(struct mxc_w1_device),
			    GFP_KERNEL);
	if (!mdev)
		return -ENOMEM;

	mdev->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(mdev->clk))
		return PTR_ERR(mdev->clk);

	err = clk_prepare_enable(mdev->clk);
	if (err)
		return err;

	clkrate = clk_get_rate(mdev->clk);
	if (clkrate < 10000000)
		dev_warn(&pdev->dev,
			 "Low clock frequency causes improper function\n");

	clkdiv = DIV_ROUND_CLOSEST(clkrate, 1000000);
	clkrate /= clkdiv;
	if ((clkrate < 980000) || (clkrate > 1020000))
		dev_warn(&pdev->dev,
			 "Incorrect time base frequency %lu Hz\n", clkrate);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	mdev->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mdev->regs)) {
		err = PTR_ERR(mdev->regs);
		goto out_disable_clk;
	}

	/* Software reset 1-Wire module */
	writeb(MXC_W1_RESET_RST, mdev->regs + MXC_W1_RESET);
	writeb(0, mdev->regs + MXC_W1_RESET);

	writeb(clkdiv - 1, mdev->regs + MXC_W1_TIME_DIVIDER);

	mdev->bus_master.data = mdev;
	mdev->bus_master.reset_bus = mxc_w1_ds2_reset_bus;
	mdev->bus_master.touch_bit = mxc_w1_ds2_touch_bit;

	platform_set_drvdata(pdev, mdev);

	err = w1_add_master_device(&mdev->bus_master);
	if (err)
		goto out_disable_clk;

	return 0;

out_disable_clk:
	clk_disable_unprepare(mdev->clk);
	return err;
}

__attribute__((used)) static int mxc_w1_remove(struct platform_device *pdev)
{
	struct mxc_w1_device *mdev = platform_get_drvdata(pdev);

	w1_remove_master_device(&mdev->bus_master);

	clk_disable_unprepare(mdev->clk);

	return 0;
}

