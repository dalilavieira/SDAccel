#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_13__ {TYPE_1__* driver; } ;
struct platform_device {TYPE_2__ dev; } ;
struct of_device_id {char* compatible; } ;
struct mem_ctl_info {int dummy; } ;
struct hb_l2_drvdata {int sb_irq; int db_irq; scalar_t__ base; } ;
struct file_operations {int dummy; } ;
struct edac_device_ctl_info {char* ctl_name; int /*<<< orphan*/  dev_name; int /*<<< orphan*/  mod_name; TYPE_2__* dev; struct hb_l2_drvdata* pvt_info; } ;
struct dentry {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_12__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ SR_CLR_DB_ECC_INTR ; 
 scalar_t__ SR_CLR_SB_ECC_INTR ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 scalar_t__ devm_ioremap (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct edac_device_ctl_info*) ; 
 int /*<<< orphan*/  devm_request_mem_region (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devres_close_group (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devres_open_group (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devres_release_group (TYPE_2__*,int /*<<< orphan*/ *) ; 
 scalar_t__ edac_device_add_device (struct edac_device_ctl_info*) ; 
 struct edac_device_ctl_info* edac_device_alloc_ctl_info (int,char*,int,char*,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  edac_device_del_device (TYPE_2__*) ; 
 int /*<<< orphan*/  edac_device_free_ctl_info (struct edac_device_ctl_info*) ; 
 int /*<<< orphan*/  edac_device_handle_ce (struct edac_device_ctl_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  edac_device_handle_ue (struct edac_device_ctl_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  hb_l2_err_of_match ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_2__*) ; 
 struct edac_device_ctl_info* platform_get_drvdata (struct platform_device*) ; 
 void* platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct edac_device_ctl_info*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline int edac_debugfs_init(void)					{ return -ENODEV; }

__attribute__((used)) static inline void edac_debugfs_exit(void)					{ }

__attribute__((used)) static inline int edac_create_debugfs_nodes(struct mem_ctl_info *mci)		{ return 0; }

__attribute__((used)) static inline struct dentry *edac_debugfs_create_dir(const char *dirname)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_dir_at(const char *dirname, struct dentry *parent)		{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_file(const char *name, umode_t mode, struct dentry *parent,
			 void *data, const struct file_operations *fops)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x8(const char *name, umode_t mode,
		       struct dentry *parent, u8 *value)			{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x16(const char *name, umode_t mode,
		       struct dentry *parent, u16 *value)			{ return NULL; }

__attribute__((used)) static irqreturn_t highbank_l2_err_handler(int irq, void *dev_id)
{
	struct edac_device_ctl_info *dci = dev_id;
	struct hb_l2_drvdata *drvdata = dci->pvt_info;

	if (irq == drvdata->sb_irq) {
		writel(1, drvdata->base + SR_CLR_SB_ECC_INTR);
		edac_device_handle_ce(dci, 0, 0, dci->ctl_name);
	}
	if (irq == drvdata->db_irq) {
		writel(1, drvdata->base + SR_CLR_DB_ECC_INTR);
		edac_device_handle_ue(dci, 0, 0, dci->ctl_name);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int highbank_l2_err_probe(struct platform_device *pdev)
{
	const struct of_device_id *id;
	struct edac_device_ctl_info *dci;
	struct hb_l2_drvdata *drvdata;
	struct resource *r;
	int res = 0;

	dci = edac_device_alloc_ctl_info(sizeof(*drvdata), "cpu",
		1, "L", 1, 2, NULL, 0, 0);
	if (!dci)
		return -ENOMEM;

	drvdata = dci->pvt_info;
	dci->dev = &pdev->dev;
	platform_set_drvdata(pdev, dci);

	if (!devres_open_group(&pdev->dev, NULL, GFP_KERNEL))
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!r) {
		dev_err(&pdev->dev, "Unable to get mem resource\n");
		res = -ENODEV;
		goto err;
	}

	if (!devm_request_mem_region(&pdev->dev, r->start,
				     resource_size(r), dev_name(&pdev->dev))) {
		dev_err(&pdev->dev, "Error while requesting mem region\n");
		res = -EBUSY;
		goto err;
	}

	drvdata->base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (!drvdata->base) {
		dev_err(&pdev->dev, "Unable to map regs\n");
		res = -ENOMEM;
		goto err;
	}

	id = of_match_device(hb_l2_err_of_match, &pdev->dev);
	dci->mod_name = pdev->dev.driver->name;
	dci->ctl_name = id ? id->compatible : "unknown";
	dci->dev_name = dev_name(&pdev->dev);

	if (edac_device_add_device(dci))
		goto err;

	drvdata->db_irq = platform_get_irq(pdev, 0);
	res = devm_request_irq(&pdev->dev, drvdata->db_irq,
			       highbank_l2_err_handler,
			       0, dev_name(&pdev->dev), dci);
	if (res < 0)
		goto err2;

	drvdata->sb_irq = platform_get_irq(pdev, 1);
	res = devm_request_irq(&pdev->dev, drvdata->sb_irq,
			       highbank_l2_err_handler,
			       0, dev_name(&pdev->dev), dci);
	if (res < 0)
		goto err2;

	devres_close_group(&pdev->dev, NULL);
	return 0;
err2:
	edac_device_del_device(&pdev->dev);
err:
	devres_release_group(&pdev->dev, NULL);
	edac_device_free_ctl_info(dci);
	return res;
}

__attribute__((used)) static int highbank_l2_err_remove(struct platform_device *pdev)
{
	struct edac_device_ctl_info *dci = platform_get_drvdata(pdev);

	edac_device_del_device(&pdev->dev);
	edac_device_free_ctl_info(dci);
	return 0;
}

