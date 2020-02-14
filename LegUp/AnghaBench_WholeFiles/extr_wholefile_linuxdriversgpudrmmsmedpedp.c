#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct platform_device {int /*<<< orphan*/  dev; } ;
struct msm_edp {struct platform_device* pdev; int /*<<< orphan*/ * ctrl; } ;
struct msm_drm_private {struct msm_edp* edp; } ;
struct drm_device {struct msm_drm_private* dev_private; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*,...) ; 
 int ENOMEM ; 
 int ENXIO ; 
 struct msm_edp* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct msm_edp*) ; 
 int PTR_ERR (struct msm_edp*) ; 
 int component_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  component_del (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct drm_device* dev_get_drvdata (struct device*) ; 
 struct msm_edp* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  edp_ops ; 
 int /*<<< orphan*/  msm_edp_ctrl_destroy (int /*<<< orphan*/ *) ; 
 int msm_edp_ctrl_init (struct msm_edp*) ; 
 int /*<<< orphan*/  msm_edp_ctrl_irq (int /*<<< orphan*/ *) ; 
 struct msm_edp* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct msm_edp*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 struct platform_device* to_platform_device (struct device*) ; 

__attribute__((used)) static irqreturn_t edp_irq(int irq, void *dev_id)
{
	struct msm_edp *edp = dev_id;

	/* Process eDP irq */
	return msm_edp_ctrl_irq(edp->ctrl);
}

__attribute__((used)) static void edp_destroy(struct platform_device *pdev)
{
	struct msm_edp *edp = platform_get_drvdata(pdev);

	if (!edp)
		return;

	if (edp->ctrl) {
		msm_edp_ctrl_destroy(edp->ctrl);
		edp->ctrl = NULL;
	}

	platform_set_drvdata(pdev, NULL);
}

__attribute__((used)) static struct msm_edp *edp_init(struct platform_device *pdev)
{
	struct msm_edp *edp = NULL;
	int ret;

	if (!pdev) {
		pr_err("no eDP device\n");
		ret = -ENXIO;
		goto fail;
	}

	edp = devm_kzalloc(&pdev->dev, sizeof(*edp), GFP_KERNEL);
	if (!edp) {
		ret = -ENOMEM;
		goto fail;
	}
	DBG("eDP probed=%p", edp);

	edp->pdev = pdev;
	platform_set_drvdata(pdev, edp);

	ret = msm_edp_ctrl_init(edp);
	if (ret)
		goto fail;

	return edp;

fail:
	if (edp)
		edp_destroy(pdev);

	return ERR_PTR(ret);
}

__attribute__((used)) static int edp_bind(struct device *dev, struct device *master, void *data)
{
	struct drm_device *drm = dev_get_drvdata(master);
	struct msm_drm_private *priv = drm->dev_private;
	struct msm_edp *edp;

	DBG("");
	edp = edp_init(to_platform_device(dev));
	if (IS_ERR(edp))
		return PTR_ERR(edp);
	priv->edp = edp;

	return 0;
}

__attribute__((used)) static void edp_unbind(struct device *dev, struct device *master, void *data)
{
	struct drm_device *drm = dev_get_drvdata(master);
	struct msm_drm_private *priv = drm->dev_private;

	DBG("");
	if (priv->edp) {
		edp_destroy(to_platform_device(dev));
		priv->edp = NULL;
	}
}

__attribute__((used)) static int edp_dev_probe(struct platform_device *pdev)
{
	DBG("");
	return component_add(&pdev->dev, &edp_ops);
}

__attribute__((used)) static int edp_dev_remove(struct platform_device *pdev)
{
	DBG("");
	component_del(&pdev->dev, &edp_ops);
	return 0;
}

