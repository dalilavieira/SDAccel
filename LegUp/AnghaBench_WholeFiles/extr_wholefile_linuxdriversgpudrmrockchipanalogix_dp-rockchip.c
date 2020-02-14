#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int u32 ;
struct TYPE_6__ {int (* power_on_start ) (struct drm_encoder*) ;int (* power_on_end ) (struct drm_encoder*) ;int (* power_off ) (struct drm_encoder*) ;int (* get_modes ) (struct drm_encoder*,struct drm_connector*) ;struct drm_panel* panel; int /*<<< orphan*/  dev_type; struct drm_encoder* encoder; } ;
struct drm_encoder {TYPE_2__* funcs; int /*<<< orphan*/  possible_crtcs; int /*<<< orphan*/  crtc; } ;
struct rockchip_dp_device {TYPE_3__ plat_data; int /*<<< orphan*/ * adp; struct device* dev; struct drm_encoder encoder; struct drm_device* drm_dev; struct rockchip_dp_chip_data const* data; int /*<<< orphan*/ * rst; int /*<<< orphan*/ * pclk; int /*<<< orphan*/ * grfclk; int /*<<< orphan*/ * grf; } ;
struct rockchip_dp_chip_data {int lcdsel_lit; int lcdsel_big; int /*<<< orphan*/  chip_type; int /*<<< orphan*/  lcdsel_grf_reg; } ;
struct rockchip_crtc_state {int output_bpc; int /*<<< orphan*/  output_type; int /*<<< orphan*/  output_mode; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct drm_panel {int dummy; } ;
struct drm_display_mode {int dummy; } ;
struct drm_display_info {int color_formats; int bpc; } ;
struct drm_device {int dummy; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_connector_state {TYPE_1__* connector; } ;
struct drm_connector {struct drm_display_info display_info; } ;
struct device_node {int dummy; } ;
struct analogix_dp_plat_data {TYPE_2__* funcs; int /*<<< orphan*/  possible_crtcs; int /*<<< orphan*/  crtc; } ;
typedef  enum scale_mode { ____Placeholder_scale_mode } scale_mode ;
struct TYPE_5__ {int /*<<< orphan*/  (* destroy ) (struct drm_encoder*) ;} ;
struct TYPE_4__ {struct drm_display_info display_info; } ;

/* Variables and functions */
 int DRM_COLOR_FORMAT_RGB444 ; 
 int DRM_COLOR_FORMAT_YCRCB422 ; 
 int DRM_COLOR_FORMAT_YCRCB444 ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,...) ; 
 int /*<<< orphan*/  DRM_DEV_DEBUG (struct device*,char*,char*) ; 
 int /*<<< orphan*/  DRM_DEV_ERROR (struct device*,char*,...) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_eDP ; 
 int /*<<< orphan*/  DRM_MODE_ENCODER_TMDS ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 void* ERR_PTR (int) ; 
 int ETIMEDOUT ; 
 int GET_SCL_FT_BILI_DN (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int LB_RGB_1920X5 ; 
 int LB_RGB_2560X4 ; 
 int LB_RGB_3840X2 ; 
 int LB_YUV_2560X8 ; 
 int LB_YUV_3840X5 ; 
 int MIN_SCL_FT_AFTER_VSKIP ; 
 int /*<<< orphan*/  PSR_WAIT_LINE_FLAG_TIMEOUT_MS ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ROCKCHIP_OUT_MODE_AAAA ; 
 int SCALE_DOWN ; 
 int SCALE_NONE ; 
 int SCALE_UP ; 
 int SCL_MAX_VSKIPLINES ; 
 int /*<<< orphan*/ * analogix_dp_bind (struct device*,struct drm_device*,TYPE_3__*) ; 
 int analogix_dp_disable_psr (int /*<<< orphan*/ *) ; 
 int analogix_dp_enable_psr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  analogix_dp_psr_enabled (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  analogix_dp_unbind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ *) ; 
 int clk_prepare_enable (int /*<<< orphan*/ *) ; 
 int component_add (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  component_del (struct device*,int /*<<< orphan*/ *) ; 
 struct rockchip_dp_device* dev_get_drvdata (struct device*) ; 
 void* devm_clk_get (struct device*,char*) ; 
 struct rockchip_dp_device* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * devm_reset_control_get (struct device*,char*) ; 
 int /*<<< orphan*/  drm_encoder_helper_add (struct drm_encoder*,int /*<<< orphan*/ *) ; 
 int drm_encoder_init (struct drm_device*,struct drm_encoder*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int drm_of_encoder_active_endpoint_id (struct device_node*,struct drm_encoder*) ; 
 int drm_of_find_panel_or_bridge (struct device_node*,int,int /*<<< orphan*/ ,struct drm_panel**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_of_find_possible_crtcs (struct drm_device*,struct device_node*) ; 
 struct rockchip_dp_chip_data* of_device_get_match_data (struct device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rockchip_dp_device*) ; 
 int regmap_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  reset_control_assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reset_control_deassert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rockchip_dp_component_ops ; 
 int /*<<< orphan*/  rockchip_dp_encoder_funcs ; 
 int /*<<< orphan*/  rockchip_dp_encoder_helper_funcs ; 
 int rockchip_drm_psr_inhibit_get (struct drm_encoder*) ; 
 int rockchip_drm_psr_inhibit_put (struct drm_encoder*) ; 
 int rockchip_drm_psr_register (struct drm_encoder*,int (*) (struct drm_encoder*,int)) ; 
 int /*<<< orphan*/  rockchip_drm_psr_unregister (struct drm_encoder*) ; 
 int rockchip_drm_wait_vact_end (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct drm_encoder*) ; 
 int /*<<< orphan*/  stub2 (struct drm_encoder*) ; 
 int /*<<< orphan*/ * syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 
 struct rockchip_dp_device* to_dp (struct drm_encoder*) ; 
 struct rockchip_crtc_state* to_rockchip_crtc_state (struct drm_crtc_state*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline uint16_t scl_cal_scale(int src, int dst, int shift)
{
	return ((src * 2 - 3) << (shift - 1)) / (dst - 1);
}

__attribute__((used)) static inline uint16_t scl_cal_scale2(int src, int dst)
{
	return ((src - 1) << 12) / (dst - 1);
}

__attribute__((used)) static inline uint16_t scl_get_bili_dn_vskip(int src_h, int dst_h,
					     int vskiplines)
{
	int act_height;

	act_height = (src_h + vskiplines - 1) / vskiplines;

	if (act_height == dst_h)
		return GET_SCL_FT_BILI_DN(src_h, dst_h) / vskiplines;

	return GET_SCL_FT_BILI_DN(act_height, dst_h);
}

__attribute__((used)) static inline enum scale_mode scl_get_scl_mode(int src, int dst)
{
	if (src < dst)
		return SCALE_UP;
	else if (src > dst)
		return SCALE_DOWN;

	return SCALE_NONE;
}

__attribute__((used)) static inline int scl_get_vskiplines(uint32_t srch, uint32_t dsth)
{
	uint32_t vskiplines;

	for (vskiplines = SCL_MAX_VSKIPLINES; vskiplines > 1; vskiplines /= 2)
		if (srch >= vskiplines * dsth * MIN_SCL_FT_AFTER_VSKIP)
			break;

	return vskiplines;
}

__attribute__((used)) static inline int scl_vop_cal_lb_mode(int width, bool is_yuv)
{
	int lb_mode;

	if (is_yuv) {
		if (width > 1280)
			lb_mode = LB_YUV_3840X5;
		else
			lb_mode = LB_YUV_2560X8;
	} else {
		if (width > 2560)
			lb_mode = LB_RGB_3840X2;
		else if (width > 1920)
			lb_mode = LB_RGB_2560X4;
		else
			lb_mode = LB_RGB_1920X5;
	}

	return lb_mode;
}

__attribute__((used)) static int analogix_dp_psr_set(struct drm_encoder *encoder, bool enabled)
{
	struct rockchip_dp_device *dp = to_dp(encoder);
	int ret;

	if (!analogix_dp_psr_enabled(dp->adp))
		return 0;

	DRM_DEV_DEBUG(dp->dev, "%s PSR...\n", enabled ? "Entry" : "Exit");

	ret = rockchip_drm_wait_vact_end(dp->encoder.crtc,
					 PSR_WAIT_LINE_FLAG_TIMEOUT_MS);
	if (ret) {
		DRM_DEV_ERROR(dp->dev, "line flag interrupt did not arrive\n");
		return -ETIMEDOUT;
	}

	if (enabled)
		return analogix_dp_enable_psr(dp->adp);
	else
		return analogix_dp_disable_psr(dp->adp);
}

__attribute__((used)) static int rockchip_dp_pre_init(struct rockchip_dp_device *dp)
{
	reset_control_assert(dp->rst);
	usleep_range(10, 20);
	reset_control_deassert(dp->rst);

	return 0;
}

__attribute__((used)) static int rockchip_dp_poweron_start(struct analogix_dp_plat_data *plat_data)
{
	struct rockchip_dp_device *dp = to_dp(plat_data);
	int ret;

	ret = clk_prepare_enable(dp->pclk);
	if (ret < 0) {
		DRM_DEV_ERROR(dp->dev, "failed to enable pclk %d\n", ret);
		return ret;
	}

	ret = rockchip_dp_pre_init(dp);
	if (ret < 0) {
		DRM_DEV_ERROR(dp->dev, "failed to dp pre init %d\n", ret);
		clk_disable_unprepare(dp->pclk);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int rockchip_dp_poweron_end(struct analogix_dp_plat_data *plat_data)
{
	struct rockchip_dp_device *dp = to_dp(plat_data);

	return rockchip_drm_psr_inhibit_put(&dp->encoder);
}

__attribute__((used)) static int rockchip_dp_powerdown(struct analogix_dp_plat_data *plat_data)
{
	struct rockchip_dp_device *dp = to_dp(plat_data);
	int ret;

	ret = rockchip_drm_psr_inhibit_get(&dp->encoder);
	if (ret != 0)
		return ret;

	clk_disable_unprepare(dp->pclk);

	return 0;
}

__attribute__((used)) static int rockchip_dp_get_modes(struct analogix_dp_plat_data *plat_data,
				 struct drm_connector *connector)
{
	struct drm_display_info *di = &connector->display_info;
	/* VOP couldn't output YUV video format for eDP rightly */
	u32 mask = DRM_COLOR_FORMAT_YCRCB444 | DRM_COLOR_FORMAT_YCRCB422;

	if ((di->color_formats & mask)) {
		DRM_DEBUG_KMS("Swapping display color format from YUV to RGB\n");
		di->color_formats &= ~mask;
		di->color_formats |= DRM_COLOR_FORMAT_RGB444;
		di->bpc = 8;
	}

	return 0;
}

__attribute__((used)) static bool
rockchip_dp_drm_encoder_mode_fixup(struct drm_encoder *encoder,
				   const struct drm_display_mode *mode,
				   struct drm_display_mode *adjusted_mode)
{
	/* do nothing */
	return true;
}

__attribute__((used)) static void rockchip_dp_drm_encoder_mode_set(struct drm_encoder *encoder,
					     struct drm_display_mode *mode,
					     struct drm_display_mode *adjusted)
{
	/* do nothing */
}

__attribute__((used)) static void rockchip_dp_drm_encoder_enable(struct drm_encoder *encoder)
{
	struct rockchip_dp_device *dp = to_dp(encoder);
	int ret;
	u32 val;

	ret = drm_of_encoder_active_endpoint_id(dp->dev->of_node, encoder);
	if (ret < 0)
		return;

	if (ret)
		val = dp->data->lcdsel_lit;
	else
		val = dp->data->lcdsel_big;

	DRM_DEV_DEBUG(dp->dev, "vop %s output to dp\n", (ret) ? "LIT" : "BIG");

	ret = clk_prepare_enable(dp->grfclk);
	if (ret < 0) {
		DRM_DEV_ERROR(dp->dev, "failed to enable grfclk %d\n", ret);
		return;
	}

	ret = regmap_write(dp->grf, dp->data->lcdsel_grf_reg, val);
	if (ret != 0)
		DRM_DEV_ERROR(dp->dev, "Could not write to GRF: %d\n", ret);

	clk_disable_unprepare(dp->grfclk);
}

__attribute__((used)) static void rockchip_dp_drm_encoder_nop(struct drm_encoder *encoder)
{
	/* do nothing */
}

__attribute__((used)) static int
rockchip_dp_drm_encoder_atomic_check(struct drm_encoder *encoder,
				      struct drm_crtc_state *crtc_state,
				      struct drm_connector_state *conn_state)
{
	struct rockchip_crtc_state *s = to_rockchip_crtc_state(crtc_state);
	struct drm_display_info *di = &conn_state->connector->display_info;

	/*
	 * The hardware IC designed that VOP must output the RGB10 video
	 * format to eDP controller, and if eDP panel only support RGB8,
	 * then eDP controller should cut down the video data, not via VOP
	 * controller, that's why we need to hardcode the VOP output mode
	 * to RGA10 here.
	 */

	s->output_mode = ROCKCHIP_OUT_MODE_AAAA;
	s->output_type = DRM_MODE_CONNECTOR_eDP;
	s->output_bpc = di->bpc;

	return 0;
}

__attribute__((used)) static int rockchip_dp_of_probe(struct rockchip_dp_device *dp)
{
	struct device *dev = dp->dev;
	struct device_node *np = dev->of_node;

	dp->grf = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
	if (IS_ERR(dp->grf)) {
		DRM_DEV_ERROR(dev, "failed to get rockchip,grf property\n");
		return PTR_ERR(dp->grf);
	}

	dp->grfclk = devm_clk_get(dev, "grf");
	if (PTR_ERR(dp->grfclk) == -ENOENT) {
		dp->grfclk = NULL;
	} else if (PTR_ERR(dp->grfclk) == -EPROBE_DEFER) {
		return -EPROBE_DEFER;
	} else if (IS_ERR(dp->grfclk)) {
		DRM_DEV_ERROR(dev, "failed to get grf clock\n");
		return PTR_ERR(dp->grfclk);
	}

	dp->pclk = devm_clk_get(dev, "pclk");
	if (IS_ERR(dp->pclk)) {
		DRM_DEV_ERROR(dev, "failed to get pclk property\n");
		return PTR_ERR(dp->pclk);
	}

	dp->rst = devm_reset_control_get(dev, "dp");
	if (IS_ERR(dp->rst)) {
		DRM_DEV_ERROR(dev, "failed to get dp reset control\n");
		return PTR_ERR(dp->rst);
	}

	return 0;
}

__attribute__((used)) static int rockchip_dp_drm_create_encoder(struct rockchip_dp_device *dp)
{
	struct drm_encoder *encoder = &dp->encoder;
	struct drm_device *drm_dev = dp->drm_dev;
	struct device *dev = dp->dev;
	int ret;

	encoder->possible_crtcs = drm_of_find_possible_crtcs(drm_dev,
							     dev->of_node);
	DRM_DEBUG_KMS("possible_crtcs = 0x%x\n", encoder->possible_crtcs);

	ret = drm_encoder_init(drm_dev, encoder, &rockchip_dp_encoder_funcs,
			       DRM_MODE_ENCODER_TMDS, NULL);
	if (ret) {
		DRM_ERROR("failed to initialize encoder with drm\n");
		return ret;
	}

	drm_encoder_helper_add(encoder, &rockchip_dp_encoder_helper_funcs);

	return 0;
}

__attribute__((used)) static int rockchip_dp_bind(struct device *dev, struct device *master,
			    void *data)
{
	struct rockchip_dp_device *dp = dev_get_drvdata(dev);
	const struct rockchip_dp_chip_data *dp_data;
	struct drm_device *drm_dev = data;
	int ret;

	dp_data = of_device_get_match_data(dev);
	if (!dp_data)
		return -ENODEV;

	dp->data = dp_data;
	dp->drm_dev = drm_dev;

	ret = rockchip_dp_drm_create_encoder(dp);
	if (ret) {
		DRM_ERROR("failed to create drm encoder\n");
		return ret;
	}

	dp->plat_data.encoder = &dp->encoder;

	dp->plat_data.dev_type = dp->data->chip_type;
	dp->plat_data.power_on_start = rockchip_dp_poweron_start;
	dp->plat_data.power_on_end = rockchip_dp_poweron_end;
	dp->plat_data.power_off = rockchip_dp_powerdown;
	dp->plat_data.get_modes = rockchip_dp_get_modes;

	ret = rockchip_drm_psr_register(&dp->encoder, analogix_dp_psr_set);
	if (ret < 0)
		goto err_cleanup_encoder;

	dp->adp = analogix_dp_bind(dev, dp->drm_dev, &dp->plat_data);
	if (IS_ERR(dp->adp)) {
		ret = PTR_ERR(dp->adp);
		goto err_unreg_psr;
	}

	return 0;
err_unreg_psr:
	rockchip_drm_psr_unregister(&dp->encoder);
err_cleanup_encoder:
	dp->encoder.funcs->destroy(&dp->encoder);
	return ret;
}

__attribute__((used)) static void rockchip_dp_unbind(struct device *dev, struct device *master,
			       void *data)
{
	struct rockchip_dp_device *dp = dev_get_drvdata(dev);

	analogix_dp_unbind(dp->adp);
	rockchip_drm_psr_unregister(&dp->encoder);
	dp->encoder.funcs->destroy(&dp->encoder);

	dp->adp = ERR_PTR(-ENODEV);
}

__attribute__((used)) static int rockchip_dp_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct drm_panel *panel = NULL;
	struct rockchip_dp_device *dp;
	int ret;

	ret = drm_of_find_panel_or_bridge(dev->of_node, 1, 0, &panel, NULL);
	if (ret < 0)
		return ret;

	dp = devm_kzalloc(dev, sizeof(*dp), GFP_KERNEL);
	if (!dp)
		return -ENOMEM;

	dp->dev = dev;
	dp->adp = ERR_PTR(-ENODEV);
	dp->plat_data.panel = panel;

	ret = rockchip_dp_of_probe(dp);
	if (ret < 0)
		return ret;

	platform_set_drvdata(pdev, dp);

	return component_add(dev, &rockchip_dp_component_ops);
}

__attribute__((used)) static int rockchip_dp_remove(struct platform_device *pdev)
{
	component_del(&pdev->dev, &rockchip_dp_component_ops);

	return 0;
}

