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
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct fpga_region {struct fpga_manager* mgr; int /*<<< orphan*/  compat_id; struct dfl_fme_region_pdata* priv; int /*<<< orphan*/  bridge_list; int /*<<< orphan*/  info; } ;
struct fpga_manager {int /*<<< orphan*/  compat_id; } ;
struct dfl_fme_region_pdata {TYPE_2__* mgr; TYPE_1__* br; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {struct device dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 scalar_t__ IS_ERR (struct fpga_manager*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct fpga_region* dev_get_drvdata (struct device*) ; 
 struct dfl_fme_region_pdata* dev_get_platdata (struct device*) ; 
 int fpga_bridge_get_to_list (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct fpga_manager* fpga_mgr_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fpga_mgr_put (struct fpga_manager*) ; 
 struct fpga_region* fpga_region_create (struct device*,struct fpga_manager*,int (*) (struct fpga_region*)) ; 
 int /*<<< orphan*/  fpga_region_free (struct fpga_region*) ; 
 int fpga_region_register (struct fpga_region*) ; 
 int /*<<< orphan*/  fpga_region_unregister (struct fpga_region*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct fpga_region*) ; 

__attribute__((used)) static int fme_region_get_bridges(struct fpga_region *region)
{
	struct dfl_fme_region_pdata *pdata = region->priv;
	struct device *dev = &pdata->br->dev;

	return fpga_bridge_get_to_list(dev, region->info, &region->bridge_list);
}

__attribute__((used)) static int fme_region_probe(struct platform_device *pdev)
{
	struct dfl_fme_region_pdata *pdata = dev_get_platdata(&pdev->dev);
	struct device *dev = &pdev->dev;
	struct fpga_region *region;
	struct fpga_manager *mgr;
	int ret;

	mgr = fpga_mgr_get(&pdata->mgr->dev);
	if (IS_ERR(mgr))
		return -EPROBE_DEFER;

	region = fpga_region_create(dev, mgr, fme_region_get_bridges);
	if (!region) {
		ret = -ENOMEM;
		goto eprobe_mgr_put;
	}

	region->priv = pdata;
	region->compat_id = mgr->compat_id;
	platform_set_drvdata(pdev, region);

	ret = fpga_region_register(region);
	if (ret)
		goto region_free;

	dev_dbg(dev, "DFL FME FPGA Region probed\n");

	return 0;

region_free:
	fpga_region_free(region);
eprobe_mgr_put:
	fpga_mgr_put(mgr);
	return ret;
}

__attribute__((used)) static int fme_region_remove(struct platform_device *pdev)
{
	struct fpga_region *region = dev_get_drvdata(&pdev->dev);
	struct fpga_manager *mgr = region->mgr;

	fpga_region_unregister(region);
	fpga_mgr_put(mgr);

	return 0;
}

