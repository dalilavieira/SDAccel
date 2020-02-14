#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_10__ {struct device_node* port; } ;
struct hdlcd_drm_private {TYPE_3__ crtc; struct drm_device* mmio; struct drm_device* clk; } ;
struct TYPE_8__ {int /*<<< orphan*/  num_crtc; int /*<<< orphan*/ * funcs; int /*<<< orphan*/  max_height; int /*<<< orphan*/  max_width; scalar_t__ min_height; scalar_t__ min_width; } ;
struct drm_device {struct hdlcd_drm_private* dev_private; struct device* dev; TYPE_1__ mode_config; } ;
struct device_node {int dummy; } ;
struct device {void* of_node; } ;
struct component_match {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  DRM_ERROR (char*,...) ; 
 int /*<<< orphan*/  DRM_INFO (char*,int,int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long HDLCD_INTERRUPT_VSYNC ; 
 int /*<<< orphan*/  HDLCD_MAX_XRES ; 
 int /*<<< orphan*/  HDLCD_MAX_YRES ; 
 int HDLCD_PRODUCT_ID ; 
 int HDLCD_PRODUCT_MASK ; 
 unsigned int HDLCD_REG_INT_CLEAR ; 
 unsigned int HDLCD_REG_INT_MASK ; 
 unsigned int HDLCD_REG_INT_STATUS ; 
 unsigned int HDLCD_REG_VERSION ; 
 int HDLCD_VERSION_MAJOR_MASK ; 
 int HDLCD_VERSION_MINOR_MASK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct drm_device*) ; 
 int PTR_ERR (struct drm_device*) ; 
 int component_bind_all (struct device*,struct drm_device*) ; 
 int component_master_add_with_match (TYPE_2__*,int /*<<< orphan*/ *,struct component_match*) ; 
 int /*<<< orphan*/  component_master_del (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  component_unbind_all (struct device*,struct drm_device*) ; 
 struct drm_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct drm_device*) ; 
 struct drm_device* devm_clk_get (struct device*,char*) ; 
 struct drm_device* devm_ioremap_resource (struct device*,struct resource*) ; 
 struct hdlcd_drm_private* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int dma_set_mask_and_coherent (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_atomic_helper_shutdown (struct drm_device*) ; 
 int /*<<< orphan*/  drm_crtc_cleanup (TYPE_3__*) ; 
 int /*<<< orphan*/  drm_crtc_handle_vblank (TYPE_3__*) ; 
 int /*<<< orphan*/  drm_crtc_vblank_off (TYPE_3__*) ; 
 struct drm_device* drm_dev_alloc (int /*<<< orphan*/ *,struct device*) ; 
 int /*<<< orphan*/  drm_dev_put (struct drm_device*) ; 
 int drm_dev_register (struct drm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_dev_unregister (struct drm_device*) ; 
 int /*<<< orphan*/  drm_fb_cma_fbdev_fini (struct drm_device*) ; 
 int drm_fb_cma_fbdev_init (struct drm_device*,int,int /*<<< orphan*/ ) ; 
 int drm_irq_install (struct drm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_irq_uninstall (struct drm_device*) ; 
 int /*<<< orphan*/  drm_kms_helper_poll_fini (struct drm_device*) ; 
 int /*<<< orphan*/  drm_kms_helper_poll_init (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_cleanup (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_init (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_reset (struct drm_device*) ; 
 int /*<<< orphan*/  drm_of_component_match_add (TYPE_2__*,struct component_match**,int (*) (struct device*,void*),struct device_node*) ; 
 int drm_vblank_init (struct drm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hdlcd_driver ; 
 int /*<<< orphan*/  hdlcd_master_ops ; 
 int /*<<< orphan*/  hdlcd_mode_config_funcs ; 
 int hdlcd_setup_crtc (struct drm_device*) ; 
 struct device_node* of_graph_get_port_by_id (void*,int /*<<< orphan*/ ) ; 
 struct device_node* of_graph_get_remote_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_reserved_mem_device_init (struct device*) ; 
 int /*<<< orphan*/  of_reserved_mem_device_release (struct device*) ; 
 int /*<<< orphan*/  platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 scalar_t__ pm_runtime_enabled (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 int pm_runtime_set_active (struct device*) ; 
 int readl (struct drm_device*) ; 
 struct platform_device* to_platform_device (struct device*) ; 
 int /*<<< orphan*/  writel (int,struct drm_device*) ; 

__attribute__((used)) static inline void hdlcd_write(struct hdlcd_drm_private *hdlcd,
			       unsigned int reg, u32 value)
{
	writel(value, hdlcd->mmio + reg);
}

__attribute__((used)) static inline u32 hdlcd_read(struct hdlcd_drm_private *hdlcd, unsigned int reg)
{
	return readl(hdlcd->mmio + reg);
}

__attribute__((used)) static int hdlcd_load(struct drm_device *drm, unsigned long flags)
{
	struct hdlcd_drm_private *hdlcd = drm->dev_private;
	struct platform_device *pdev = to_platform_device(drm->dev);
	struct resource *res;
	u32 version;
	int ret;

	hdlcd->clk = devm_clk_get(drm->dev, "pxlclk");
	if (IS_ERR(hdlcd->clk))
		return PTR_ERR(hdlcd->clk);

#ifdef CONFIG_DEBUG_FS
	atomic_set(&hdlcd->buffer_underrun_count, 0);
	atomic_set(&hdlcd->bus_error_count, 0);
	atomic_set(&hdlcd->vsync_count, 0);
	atomic_set(&hdlcd->dma_end_count, 0);
#endif

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hdlcd->mmio = devm_ioremap_resource(drm->dev, res);
	if (IS_ERR(hdlcd->mmio)) {
		DRM_ERROR("failed to map control registers area\n");
		ret = PTR_ERR(hdlcd->mmio);
		hdlcd->mmio = NULL;
		return ret;
	}

	version = hdlcd_read(hdlcd, HDLCD_REG_VERSION);
	if ((version & HDLCD_PRODUCT_MASK) != HDLCD_PRODUCT_ID) {
		DRM_ERROR("unknown product id: 0x%x\n", version);
		return -EINVAL;
	}
	DRM_INFO("found ARM HDLCD version r%dp%d\n",
		(version & HDLCD_VERSION_MAJOR_MASK) >> 8,
		version & HDLCD_VERSION_MINOR_MASK);

	/* Get the optional framebuffer memory resource */
	ret = of_reserved_mem_device_init(drm->dev);
	if (ret && ret != -ENODEV)
		return ret;

	ret = dma_set_mask_and_coherent(drm->dev, DMA_BIT_MASK(32));
	if (ret)
		goto setup_fail;

	ret = hdlcd_setup_crtc(drm);
	if (ret < 0) {
		DRM_ERROR("failed to create crtc\n");
		goto setup_fail;
	}

	ret = drm_irq_install(drm, platform_get_irq(pdev, 0));
	if (ret < 0) {
		DRM_ERROR("failed to install IRQ handler\n");
		goto irq_fail;
	}

	return 0;

irq_fail:
	drm_crtc_cleanup(&hdlcd->crtc);
setup_fail:
	of_reserved_mem_device_release(drm->dev);

	return ret;
}

__attribute__((used)) static void hdlcd_setup_mode_config(struct drm_device *drm)
{
	drm_mode_config_init(drm);
	drm->mode_config.min_width = 0;
	drm->mode_config.min_height = 0;
	drm->mode_config.max_width = HDLCD_MAX_XRES;
	drm->mode_config.max_height = HDLCD_MAX_YRES;
	drm->mode_config.funcs = &hdlcd_mode_config_funcs;
}

__attribute__((used)) static irqreturn_t hdlcd_irq(int irq, void *arg)
{
	struct drm_device *drm = arg;
	struct hdlcd_drm_private *hdlcd = drm->dev_private;
	unsigned long irq_status;

	irq_status = hdlcd_read(hdlcd, HDLCD_REG_INT_STATUS);

#ifdef CONFIG_DEBUG_FS
	if (irq_status & HDLCD_INTERRUPT_UNDERRUN)
		atomic_inc(&hdlcd->buffer_underrun_count);

	if (irq_status & HDLCD_INTERRUPT_DMA_END)
		atomic_inc(&hdlcd->dma_end_count);

	if (irq_status & HDLCD_INTERRUPT_BUS_ERROR)
		atomic_inc(&hdlcd->bus_error_count);

	if (irq_status & HDLCD_INTERRUPT_VSYNC)
		atomic_inc(&hdlcd->vsync_count);

#endif
	if (irq_status & HDLCD_INTERRUPT_VSYNC)
		drm_crtc_handle_vblank(&hdlcd->crtc);

	/* acknowledge interrupt(s) */
	hdlcd_write(hdlcd, HDLCD_REG_INT_CLEAR, irq_status);

	return IRQ_HANDLED;
}

__attribute__((used)) static void hdlcd_irq_preinstall(struct drm_device *drm)
{
	struct hdlcd_drm_private *hdlcd = drm->dev_private;
	/* Ensure interrupts are disabled */
	hdlcd_write(hdlcd, HDLCD_REG_INT_MASK, 0);
	hdlcd_write(hdlcd, HDLCD_REG_INT_CLEAR, ~0);
}

__attribute__((used)) static int hdlcd_irq_postinstall(struct drm_device *drm)
{
#ifdef CONFIG_DEBUG_FS
	struct hdlcd_drm_private *hdlcd = drm->dev_private;
	unsigned long irq_mask = hdlcd_read(hdlcd, HDLCD_REG_INT_MASK);

	/* enable debug interrupts */
	irq_mask |= HDLCD_DEBUG_INT_MASK;

	hdlcd_write(hdlcd, HDLCD_REG_INT_MASK, irq_mask);
#endif
	return 0;
}

__attribute__((used)) static void hdlcd_irq_uninstall(struct drm_device *drm)
{
	struct hdlcd_drm_private *hdlcd = drm->dev_private;
	/* disable all the interrupts that we might have enabled */
	unsigned long irq_mask = hdlcd_read(hdlcd, HDLCD_REG_INT_MASK);

#ifdef CONFIG_DEBUG_FS
	/* disable debug interrupts */
	irq_mask &= ~HDLCD_DEBUG_INT_MASK;
#endif

	/* disable vsync interrupts */
	irq_mask &= ~HDLCD_INTERRUPT_VSYNC;

	hdlcd_write(hdlcd, HDLCD_REG_INT_MASK, irq_mask);
}

__attribute__((used)) static int hdlcd_drm_bind(struct device *dev)
{
	struct drm_device *drm;
	struct hdlcd_drm_private *hdlcd;
	int ret;

	hdlcd = devm_kzalloc(dev, sizeof(*hdlcd), GFP_KERNEL);
	if (!hdlcd)
		return -ENOMEM;

	drm = drm_dev_alloc(&hdlcd_driver, dev);
	if (IS_ERR(drm))
		return PTR_ERR(drm);

	drm->dev_private = hdlcd;
	dev_set_drvdata(dev, drm);

	hdlcd_setup_mode_config(drm);
	ret = hdlcd_load(drm, 0);
	if (ret)
		goto err_free;

	/* Set the CRTC's port so that the encoder component can find it */
	hdlcd->crtc.port = of_graph_get_port_by_id(dev->of_node, 0);

	ret = component_bind_all(dev, drm);
	if (ret) {
		DRM_ERROR("Failed to bind all components\n");
		goto err_unload;
	}

	ret = pm_runtime_set_active(dev);
	if (ret)
		goto err_pm_active;

	pm_runtime_enable(dev);

	ret = drm_vblank_init(drm, drm->mode_config.num_crtc);
	if (ret < 0) {
		DRM_ERROR("failed to initialise vblank\n");
		goto err_vblank;
	}

	drm_mode_config_reset(drm);
	drm_kms_helper_poll_init(drm);

	ret = drm_fb_cma_fbdev_init(drm, 32, 0);
	if (ret)
		goto err_fbdev;

	ret = drm_dev_register(drm, 0);
	if (ret)
		goto err_register;

	return 0;

err_register:
	drm_fb_cma_fbdev_fini(drm);
err_fbdev:
	drm_kms_helper_poll_fini(drm);
err_vblank:
	pm_runtime_disable(drm->dev);
err_pm_active:
	drm_atomic_helper_shutdown(drm);
	component_unbind_all(dev, drm);
err_unload:
	of_node_put(hdlcd->crtc.port);
	hdlcd->crtc.port = NULL;
	drm_irq_uninstall(drm);
	of_reserved_mem_device_release(drm->dev);
err_free:
	drm_mode_config_cleanup(drm);
	dev_set_drvdata(dev, NULL);
	drm_dev_put(drm);

	return ret;
}

__attribute__((used)) static void hdlcd_drm_unbind(struct device *dev)
{
	struct drm_device *drm = dev_get_drvdata(dev);
	struct hdlcd_drm_private *hdlcd = drm->dev_private;

	drm_dev_unregister(drm);
	drm_fb_cma_fbdev_fini(drm);
	drm_kms_helper_poll_fini(drm);
	component_unbind_all(dev, drm);
	of_node_put(hdlcd->crtc.port);
	hdlcd->crtc.port = NULL;
	pm_runtime_get_sync(dev);
	drm_crtc_vblank_off(&hdlcd->crtc);
	drm_irq_uninstall(drm);
	drm_atomic_helper_shutdown(drm);
	pm_runtime_put(dev);
	if (pm_runtime_enabled(dev))
		pm_runtime_disable(dev);
	of_reserved_mem_device_release(dev);
	drm_mode_config_cleanup(drm);
	drm->dev_private = NULL;
	dev_set_drvdata(dev, NULL);
	drm_dev_put(drm);
}

__attribute__((used)) static int compare_dev(struct device *dev, void *data)
{
	return dev->of_node == data;
}

__attribute__((used)) static int hdlcd_probe(struct platform_device *pdev)
{
	struct device_node *port;
	struct component_match *match = NULL;

	/* there is only one output port inside each device, find it */
	port = of_graph_get_remote_node(pdev->dev.of_node, 0, 0);
	if (!port)
		return -ENODEV;

	drm_of_component_match_add(&pdev->dev, &match, compare_dev, port);
	of_node_put(port);

	return component_master_add_with_match(&pdev->dev, &hdlcd_master_ops,
					       match);
}

__attribute__((used)) static int hdlcd_remove(struct platform_device *pdev)
{
	component_master_del(&pdev->dev, &hdlcd_master_ops);
	return 0;
}

