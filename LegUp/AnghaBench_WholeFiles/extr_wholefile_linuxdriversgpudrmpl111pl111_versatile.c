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
typedef  int u32 ;
struct regmap {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct pl111_drm_dev_private {void (* variant_display_enable ) (struct drm_device*,int) ;void (* variant_display_disable ) (struct drm_device*) ;int /*<<< orphan*/ * variant; int /*<<< orphan*/  ctrl; int /*<<< orphan*/  ienb; } ;
struct of_device_id {scalar_t__ data; } ;
struct drm_device {struct device* dev; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  enum versatile_clcd { ____Placeholder_versatile_clcd } versatile_clcd ;

/* Variables and functions */
 int /*<<< orphan*/  CLCD_PL111_CNTL ; 
 int /*<<< orphan*/  CLCD_PL111_IENB ; 
#define  DRM_FORMAT_ABGR1555 145 
#define  DRM_FORMAT_ABGR8888 144 
#define  DRM_FORMAT_ARGB1555 143 
#define  DRM_FORMAT_ARGB8888 142 
#define  DRM_FORMAT_BGR565 141 
#define  DRM_FORMAT_RGB565 140 
#define  DRM_FORMAT_XBGR1555 139 
#define  DRM_FORMAT_XBGR8888 138 
#define  DRM_FORMAT_XRGB1555 137 
#define  DRM_FORMAT_XRGB8888 136 
 int ENODEV ; 
 int EPROBE_DEFER ; 
#define  INTEGRATOR_CLCD_CM 135 
 int INTEGRATOR_CLCD_LCD0_EN ; 
 int INTEGRATOR_CLCD_LCD1_EN ; 
 int INTEGRATOR_CLCD_LCDMUX_VGA24 ; 
 int INTEGRATOR_CLCD_LCDMUX_VGA555 ; 
 int INTEGRATOR_CLCD_LCD_STATIC1 ; 
 int INTEGRATOR_CLCD_LCD_STATIC2 ; 
 int /*<<< orphan*/  INTEGRATOR_CLCD_MASK ; 
 int /*<<< orphan*/  INTEGRATOR_HDR_CTRL_OFFSET ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
#define  REALVIEW_CLCD_EB 134 
#define  REALVIEW_CLCD_PB1176 133 
#define  REALVIEW_CLCD_PB11MP 132 
#define  REALVIEW_CLCD_PBA8 131 
#define  REALVIEW_CLCD_PBX 130 
 int /*<<< orphan*/  SYS_CLCD ; 
 int /*<<< orphan*/  SYS_CLCD_CONNECTOR_MASK ; 
 int SYS_CLCD_MODE_5551 ; 
 int SYS_CLCD_MODE_565_B_LSB ; 
 int SYS_CLCD_MODE_565_R_LSB ; 
 int SYS_CLCD_MODE_888 ; 
 int /*<<< orphan*/  SYS_CLCD_MODE_MASK ; 
 int SYS_CLCD_NLCDIOON ; 
 int SYS_CLCD_PWR3V5SWITCH ; 
#define  VERSATILE_CLCD 129 
#define  VEXPRESS_CLCD_V2M 128 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct regmap* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 struct platform_device* of_find_device_by_node (struct device_node*) ; 
 struct device_node* of_find_matching_node_and_match (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct of_device_id const**) ; 
 int /*<<< orphan*/  pl110_integrator ; 
 int /*<<< orphan*/  pl110_versatile ; 
 int /*<<< orphan*/  pl111_realview ; 
 int /*<<< orphan*/  pl111_vexpress ; 
 int /*<<< orphan*/  platform_device_put (struct platform_device*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct regmap* syscon_node_to_regmap (struct device_node*) ; 
 int /*<<< orphan*/  versatile_clcd_of_match ; 
 struct regmap* versatile_syscon_map ; 

__attribute__((used)) static inline int pl111_vexpress_clcd_init(struct device *dev,
					   struct pl111_drm_dev_private *priv,
					   struct regmap *map)
{
	return -ENODEV;
}

__attribute__((used)) static inline int vexpress_muxfpga_init(void)
{
	return 0;
}

__attribute__((used)) static void pl111_integrator_enable(struct drm_device *drm, u32 format)
{
	u32 val;

	dev_info(drm->dev, "enable Integrator CLCD connectors\n");

	/* FIXME: really needed? */
	val = INTEGRATOR_CLCD_LCD_STATIC1 | INTEGRATOR_CLCD_LCD_STATIC2 |
		INTEGRATOR_CLCD_LCD0_EN | INTEGRATOR_CLCD_LCD1_EN;

	switch (format) {
	case DRM_FORMAT_XBGR8888:
	case DRM_FORMAT_XRGB8888:
		/* 24bit formats */
		val |= INTEGRATOR_CLCD_LCDMUX_VGA24;
		break;
	case DRM_FORMAT_XBGR1555:
	case DRM_FORMAT_XRGB1555:
		/* Pseudocolor, RGB555, BGR555 */
		val |= INTEGRATOR_CLCD_LCDMUX_VGA555;
		break;
	default:
		dev_err(drm->dev, "unhandled format on Integrator 0x%08x\n",
			format);
		break;
	}

	regmap_update_bits(versatile_syscon_map,
			   INTEGRATOR_HDR_CTRL_OFFSET,
			   INTEGRATOR_CLCD_MASK,
			   val);
}

__attribute__((used)) static void pl111_versatile_disable(struct drm_device *drm)
{
	dev_info(drm->dev, "disable Versatile CLCD connectors\n");
	regmap_update_bits(versatile_syscon_map,
			   SYS_CLCD,
			   SYS_CLCD_CONNECTOR_MASK,
			   0);
}

__attribute__((used)) static void pl111_versatile_enable(struct drm_device *drm, u32 format)
{
	u32 val = 0;

	dev_info(drm->dev, "enable Versatile CLCD connectors\n");

	switch (format) {
	case DRM_FORMAT_ABGR8888:
	case DRM_FORMAT_XBGR8888:
	case DRM_FORMAT_ARGB8888:
	case DRM_FORMAT_XRGB8888:
		val |= SYS_CLCD_MODE_888;
		break;
	case DRM_FORMAT_BGR565:
		val |= SYS_CLCD_MODE_565_R_LSB;
		break;
	case DRM_FORMAT_RGB565:
		val |= SYS_CLCD_MODE_565_B_LSB;
		break;
	case DRM_FORMAT_ABGR1555:
	case DRM_FORMAT_XBGR1555:
	case DRM_FORMAT_ARGB1555:
	case DRM_FORMAT_XRGB1555:
		val |= SYS_CLCD_MODE_5551;
		break;
	default:
		dev_err(drm->dev, "unhandled format on Versatile 0x%08x\n",
			format);
		break;
	}

	/* Set up the MUX */
	regmap_update_bits(versatile_syscon_map,
			   SYS_CLCD,
			   SYS_CLCD_MODE_MASK,
			   val);

	/* Then enable the display */
	regmap_update_bits(versatile_syscon_map,
			   SYS_CLCD,
			   SYS_CLCD_CONNECTOR_MASK,
			   SYS_CLCD_NLCDIOON | SYS_CLCD_PWR3V5SWITCH);
}

__attribute__((used)) static void pl111_realview_clcd_disable(struct drm_device *drm)
{
	dev_info(drm->dev, "disable RealView CLCD connectors\n");
	regmap_update_bits(versatile_syscon_map,
			   SYS_CLCD,
			   SYS_CLCD_CONNECTOR_MASK,
			   0);
}

__attribute__((used)) static void pl111_realview_clcd_enable(struct drm_device *drm, u32 format)
{
	dev_info(drm->dev, "enable RealView CLCD connectors\n");
	regmap_update_bits(versatile_syscon_map,
			   SYS_CLCD,
			   SYS_CLCD_CONNECTOR_MASK,
			   SYS_CLCD_NLCDIOON | SYS_CLCD_PWR3V5SWITCH);
}

int pl111_versatile_init(struct device *dev, struct pl111_drm_dev_private *priv)
{
	const struct of_device_id *clcd_id;
	enum versatile_clcd versatile_clcd_type;
	struct device_node *np;
	struct regmap *map;
	int ret;

	np = of_find_matching_node_and_match(NULL, versatile_clcd_of_match,
					     &clcd_id);
	if (!np) {
		/* Non-ARM reference designs, just bail out */
		return 0;
	}
	versatile_clcd_type = (enum versatile_clcd)clcd_id->data;

	/* Versatile Express special handling */
	if (versatile_clcd_type == VEXPRESS_CLCD_V2M) {
		struct platform_device *pdev;

		/* Registers a driver for the muxfpga */
		ret = vexpress_muxfpga_init();
		if (ret) {
			dev_err(dev, "unable to initialize muxfpga driver\n");
			return ret;
		}

		/* Call into deep Vexpress configuration API */
		pdev = of_find_device_by_node(np);
		if (!pdev) {
			dev_err(dev, "can't find the sysreg device, deferring\n");
			return -EPROBE_DEFER;
		}
		map = dev_get_drvdata(&pdev->dev);
		if (!map) {
			dev_err(dev, "sysreg has not yet probed\n");
			platform_device_put(pdev);
			return -EPROBE_DEFER;
		}
	} else {
		map = syscon_node_to_regmap(np);
	}

	if (IS_ERR(map)) {
		dev_err(dev, "no Versatile syscon regmap\n");
		return PTR_ERR(map);
	}

	switch (versatile_clcd_type) {
	case INTEGRATOR_CLCD_CM:
		versatile_syscon_map = map;
		priv->variant = &pl110_integrator;
		priv->variant_display_enable = pl111_integrator_enable;
		dev_info(dev, "set up callbacks for Integrator PL110\n");
		break;
	case VERSATILE_CLCD:
		versatile_syscon_map = map;
		/* This can do RGB565 with external PLD */
		priv->variant = &pl110_versatile;
		priv->variant_display_enable = pl111_versatile_enable;
		priv->variant_display_disable = pl111_versatile_disable;
		/*
		 * The Versatile has a variant halfway between PL110
		 * and PL111 where these two registers have already been
		 * swapped.
		 */
		priv->ienb = CLCD_PL111_IENB;
		priv->ctrl = CLCD_PL111_CNTL;
		dev_info(dev, "set up callbacks for Versatile PL110\n");
		break;
	case REALVIEW_CLCD_EB:
	case REALVIEW_CLCD_PB1176:
	case REALVIEW_CLCD_PB11MP:
	case REALVIEW_CLCD_PBA8:
	case REALVIEW_CLCD_PBX:
		versatile_syscon_map = map;
		priv->variant = &pl111_realview;
		priv->variant_display_enable = pl111_realview_clcd_enable;
		priv->variant_display_disable = pl111_realview_clcd_disable;
		dev_info(dev, "set up callbacks for RealView PL111\n");
		break;
	case VEXPRESS_CLCD_V2M:
		priv->variant = &pl111_vexpress;
		dev_info(dev, "initializing Versatile Express PL111\n");
		ret = pl111_vexpress_clcd_init(dev, priv, map);
		if (ret)
			return ret;
		break;
	default:
		dev_info(dev, "unknown Versatile system controller\n");
		break;
	}

	return 0;
}

