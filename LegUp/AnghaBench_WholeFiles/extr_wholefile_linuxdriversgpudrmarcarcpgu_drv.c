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
typedef  int /*<<< orphan*/  u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {int max_width; int max_height; int /*<<< orphan*/  num_connector; int /*<<< orphan*/ * funcs; scalar_t__ min_height; scalar_t__ min_width; } ;
struct drm_device {struct arcpgu_drm_private* dev_private; TYPE_1__ mode_config; TYPE_2__* dev; } ;
struct device_node {int dummy; } ;
struct arcpgu_drm_private {struct drm_device* fbdev; struct drm_device* regs; struct drm_device* clk; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 unsigned int ARCPGU_REG_ID ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct drm_device*) ; 
 int PTR_ERR (struct drm_device*) ; 
 scalar_t__ arc_pgu_setup_crtc (struct drm_device*) ; 
 int /*<<< orphan*/  arcpgu_drm_driver ; 
 int arcpgu_drm_hdmi_init (struct drm_device*,struct device_node*) ; 
 int /*<<< orphan*/  arcpgu_drm_modecfg_funcs ; 
 int arcpgu_drm_sim_init (struct drm_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 struct drm_device* devm_clk_get (TYPE_2__*,char*) ; 
 struct drm_device* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct arcpgu_drm_private* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 scalar_t__ dma_set_mask_and_coherent (TYPE_2__*,int /*<<< orphan*/ ) ; 
 struct drm_device* drm_dev_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int drm_dev_register (struct drm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_dev_unref (struct drm_device*) ; 
 int /*<<< orphan*/  drm_dev_unregister (struct drm_device*) ; 
 int /*<<< orphan*/  drm_fbdev_cma_fini (struct drm_device*) ; 
 int /*<<< orphan*/  drm_fbdev_cma_hotplug_event (struct drm_device*) ; 
 struct drm_device* drm_fbdev_cma_init (struct drm_device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_fbdev_cma_restore_mode (struct drm_device*) ; 
 int /*<<< orphan*/  drm_kms_helper_poll_fini (struct drm_device*) ; 
 int /*<<< orphan*/  drm_kms_helper_poll_init (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_cleanup (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_init (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_reset (struct drm_device*) ; 
 int /*<<< orphan*/  ioread32 (struct drm_device*) ; 
 int /*<<< orphan*/  iowrite32 (int /*<<< orphan*/ ,struct drm_device*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int of_reserved_mem_device_init (TYPE_2__*) ; 
 struct drm_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct drm_device*) ; 
 struct platform_device* to_platform_device (TYPE_2__*) ; 

__attribute__((used)) static inline void arc_pgu_write(struct arcpgu_drm_private *arcpgu,
				 unsigned int reg, u32 value)
{
	iowrite32(value, arcpgu->regs + reg);
}

__attribute__((used)) static inline u32 arc_pgu_read(struct arcpgu_drm_private *arcpgu,
			       unsigned int reg)
{
	return ioread32(arcpgu->regs + reg);
}

__attribute__((used)) static void arcpgu_fb_output_poll_changed(struct drm_device *dev)
{
	struct arcpgu_drm_private *arcpgu = dev->dev_private;

	drm_fbdev_cma_hotplug_event(arcpgu->fbdev);
}

__attribute__((used)) static void arcpgu_setup_mode_config(struct drm_device *drm)
{
	drm_mode_config_init(drm);
	drm->mode_config.min_width = 0;
	drm->mode_config.min_height = 0;
	drm->mode_config.max_width = 1920;
	drm->mode_config.max_height = 1080;
	drm->mode_config.funcs = &arcpgu_drm_modecfg_funcs;
}

__attribute__((used)) static void arcpgu_lastclose(struct drm_device *drm)
{
	struct arcpgu_drm_private *arcpgu = drm->dev_private;

	drm_fbdev_cma_restore_mode(arcpgu->fbdev);
}

__attribute__((used)) static int arcpgu_load(struct drm_device *drm)
{
	struct platform_device *pdev = to_platform_device(drm->dev);
	struct arcpgu_drm_private *arcpgu;
	struct device_node *encoder_node;
	struct resource *res;
	int ret;

	arcpgu = devm_kzalloc(&pdev->dev, sizeof(*arcpgu), GFP_KERNEL);
	if (arcpgu == NULL)
		return -ENOMEM;

	drm->dev_private = arcpgu;

	arcpgu->clk = devm_clk_get(drm->dev, "pxlclk");
	if (IS_ERR(arcpgu->clk))
		return PTR_ERR(arcpgu->clk);

	arcpgu_setup_mode_config(drm);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	arcpgu->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(arcpgu->regs))
		return PTR_ERR(arcpgu->regs);

	dev_info(drm->dev, "arc_pgu ID: 0x%x\n",
		 arc_pgu_read(arcpgu, ARCPGU_REG_ID));

	/* Get the optional framebuffer memory resource */
	ret = of_reserved_mem_device_init(drm->dev);
	if (ret && ret != -ENODEV)
		return ret;

	if (dma_set_mask_and_coherent(drm->dev, DMA_BIT_MASK(32)))
		return -ENODEV;

	if (arc_pgu_setup_crtc(drm) < 0)
		return -ENODEV;

	/* find the encoder node and initialize it */
	encoder_node = of_parse_phandle(drm->dev->of_node, "encoder-slave", 0);
	if (encoder_node) {
		ret = arcpgu_drm_hdmi_init(drm, encoder_node);
		of_node_put(encoder_node);
		if (ret < 0)
			return ret;
	} else {
		ret = arcpgu_drm_sim_init(drm, NULL);
		if (ret < 0)
			return ret;
	}

	drm_mode_config_reset(drm);
	drm_kms_helper_poll_init(drm);

	arcpgu->fbdev = drm_fbdev_cma_init(drm, 16,
					   drm->mode_config.num_connector);
	if (IS_ERR(arcpgu->fbdev)) {
		ret = PTR_ERR(arcpgu->fbdev);
		arcpgu->fbdev = NULL;
		return -ENODEV;
	}

	platform_set_drvdata(pdev, drm);
	return 0;
}

__attribute__((used)) static int arcpgu_unload(struct drm_device *drm)
{
	struct arcpgu_drm_private *arcpgu = drm->dev_private;

	if (arcpgu->fbdev) {
		drm_fbdev_cma_fini(arcpgu->fbdev);
		arcpgu->fbdev = NULL;
	}
	drm_kms_helper_poll_fini(drm);
	drm_mode_config_cleanup(drm);

	return 0;
}

__attribute__((used)) static int arcpgu_probe(struct platform_device *pdev)
{
	struct drm_device *drm;
	int ret;

	drm = drm_dev_alloc(&arcpgu_drm_driver, &pdev->dev);
	if (IS_ERR(drm))
		return PTR_ERR(drm);

	ret = arcpgu_load(drm);
	if (ret)
		goto err_unref;

	ret = drm_dev_register(drm, 0);
	if (ret)
		goto err_unload;

	return 0;

err_unload:
	arcpgu_unload(drm);

err_unref:
	drm_dev_unref(drm);

	return ret;
}

__attribute__((used)) static int arcpgu_remove(struct platform_device *pdev)
{
	struct drm_device *drm = platform_get_drvdata(pdev);

	drm_dev_unregister(drm);
	arcpgu_unload(drm);
	drm_dev_unref(drm);

	return 0;
}

