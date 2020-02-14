#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct tc6387xb_platform_data {int /*<<< orphan*/  (* enable ) (struct platform_device*) ;} ;
struct resource {char* name; scalar_t__ start; int /*<<< orphan*/  flags; scalar_t__ end; } ;
struct tc6387xb {struct clk* clk32k; struct resource rscr; scalar_t__ scr; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; int /*<<< orphan*/  id; } ;
struct clk {int dummy; } ;
struct TYPE_7__ {int start; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct clk*) ; 
 struct clk* clk_get (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  clk_prepare_enable (struct clk*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 struct tc6387xb_platform_data* dev_get_platdata (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*) ; 
 scalar_t__ ioremap (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct tc6387xb*) ; 
 struct tc6387xb* kzalloc (int,int /*<<< orphan*/ ) ; 
 int mfd_add_devices (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct resource*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (TYPE_2__*) ; 
 struct tc6387xb* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tc6387xb*) ; 
 int /*<<< orphan*/  release_resource (struct resource*) ; 
 int request_resource (struct resource*,struct resource*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  stub1 (struct platform_device*) ; 
 int /*<<< orphan*/  tc6387xb_cells ; 
 TYPE_1__* tc6387xb_mmc_resources ; 
 int /*<<< orphan*/  tmio_core_mmc_clk_div (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  tmio_core_mmc_enable (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  tmio_core_mmc_pwr (scalar_t__,int /*<<< orphan*/ ,int) ; 
 struct platform_device* to_platform_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tc6387xb_mmc_pwr(struct platform_device *mmc, int state)
{
	struct platform_device *dev = to_platform_device(mmc->dev.parent);
	struct tc6387xb *tc6387xb = platform_get_drvdata(dev);

	tmio_core_mmc_pwr(tc6387xb->scr + 0x200, 0, state);
}

__attribute__((used)) static void tc6387xb_mmc_clk_div(struct platform_device *mmc, int state)
{
	struct platform_device *dev = to_platform_device(mmc->dev.parent);
	struct tc6387xb *tc6387xb = platform_get_drvdata(dev);

	tmio_core_mmc_clk_div(tc6387xb->scr + 0x200, 0, state);
}

__attribute__((used)) static int tc6387xb_mmc_enable(struct platform_device *mmc)
{
	struct platform_device *dev      = to_platform_device(mmc->dev.parent);
	struct tc6387xb *tc6387xb = platform_get_drvdata(dev);

	clk_prepare_enable(tc6387xb->clk32k);

	tmio_core_mmc_enable(tc6387xb->scr + 0x200, 0,
		tc6387xb_mmc_resources[0].start & 0xfffe);

	return 0;
}

__attribute__((used)) static int tc6387xb_mmc_disable(struct platform_device *mmc)
{
	struct platform_device *dev      = to_platform_device(mmc->dev.parent);
	struct tc6387xb *tc6387xb = platform_get_drvdata(dev);

	clk_disable_unprepare(tc6387xb->clk32k);

	return 0;
}

__attribute__((used)) static int tc6387xb_probe(struct platform_device *dev)
{
	struct tc6387xb_platform_data *pdata = dev_get_platdata(&dev->dev);
	struct resource *iomem, *rscr;
	struct clk *clk32k;
	struct tc6387xb *tc6387xb;
	int irq, ret;

	iomem = platform_get_resource(dev, IORESOURCE_MEM, 0);
	if (!iomem)
		return -EINVAL;

	tc6387xb = kzalloc(sizeof(*tc6387xb), GFP_KERNEL);
	if (!tc6387xb)
		return -ENOMEM;

	ret  = platform_get_irq(dev, 0);
	if (ret >= 0)
		irq = ret;
	else
		goto err_no_irq;

	clk32k = clk_get(&dev->dev, "CLK_CK32K");
	if (IS_ERR(clk32k)) {
		ret = PTR_ERR(clk32k);
		goto err_no_clk;
	}

	rscr = &tc6387xb->rscr;
	rscr->name = "tc6387xb-core";
	rscr->start = iomem->start;
	rscr->end = iomem->start + 0xff;
	rscr->flags = IORESOURCE_MEM;

	ret = request_resource(iomem, rscr);
	if (ret)
		goto err_resource;

	tc6387xb->scr = ioremap(rscr->start, resource_size(rscr));
	if (!tc6387xb->scr) {
		ret = -ENOMEM;
		goto err_ioremap;
	}

	tc6387xb->clk32k = clk32k;
	platform_set_drvdata(dev, tc6387xb);

	if (pdata && pdata->enable)
		pdata->enable(dev);

	dev_info(&dev->dev, "Toshiba tc6387xb initialised\n");

	ret = mfd_add_devices(&dev->dev, dev->id, tc6387xb_cells,
			      ARRAY_SIZE(tc6387xb_cells), iomem, irq, NULL);

	if (!ret)
		return 0;

	iounmap(tc6387xb->scr);
err_ioremap:
	release_resource(&tc6387xb->rscr);
err_resource:
	clk_put(clk32k);
err_no_clk:
err_no_irq:
	kfree(tc6387xb);
	return ret;
}

__attribute__((used)) static int tc6387xb_remove(struct platform_device *dev)
{
	struct tc6387xb *tc6387xb = platform_get_drvdata(dev);

	mfd_remove_devices(&dev->dev);
	iounmap(tc6387xb->scr);
	release_resource(&tc6387xb->rscr);
	clk_disable_unprepare(tc6387xb->clk32k);
	clk_put(tc6387xb->clk32k);
	kfree(tc6387xb);

	return 0;
}

