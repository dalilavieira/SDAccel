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
struct msm_kms {TYPE_2__* funcs; } ;
struct msm_edp {int /*<<< orphan*/  encoder; int /*<<< orphan*/  dev; int /*<<< orphan*/  ctrl; } ;
struct msm_drm_private {struct msm_kms* kms; } ;
struct TYPE_6__ {int bpc; } ;
struct drm_connector {int interlace_allowed; int doublescan_allowed; int /*<<< orphan*/  polled; TYPE_3__ display_info; TYPE_1__* dev; } ;
struct edp_connector {struct drm_connector base; struct msm_edp* edp; } ;
struct edid {int dummy; } ;
struct drm_display_mode {int clock; } ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
struct TYPE_5__ {long (* round_pixclk ) (struct msm_kms*,long,int /*<<< orphan*/ ) ;} ;
struct TYPE_4__ {struct msm_drm_private* dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*,...) ; 
 int /*<<< orphan*/  DRM_CONNECTOR_POLL_CONNECT ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_eDP ; 
 int ENOMEM ; 
 struct drm_connector* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MODE_BAD ; 
 int MODE_CLOCK_RANGE ; 
 int MODE_OK ; 
 int connector_status_connected ; 
 int connector_status_disconnected ; 
 int drm_add_edid_modes (struct drm_connector*,struct edid*) ; 
 int /*<<< orphan*/  drm_connector_attach_encoder (struct drm_connector*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_connector_cleanup (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_connector_helper_add (struct drm_connector*,int /*<<< orphan*/ *) ; 
 int drm_connector_init (int /*<<< orphan*/ ,struct drm_connector*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_connector_update_edid_property (struct drm_connector*,struct edid*) ; 
 int /*<<< orphan*/  edp_connector_funcs ; 
 int /*<<< orphan*/  edp_connector_helper_funcs ; 
 int /*<<< orphan*/  kfree (struct edp_connector*) ; 
 struct edp_connector* kzalloc (int,int /*<<< orphan*/ ) ; 
 int msm_edp_ctrl_get_panel_info (int /*<<< orphan*/ ,struct drm_connector*,struct edid**) ; 
 scalar_t__ msm_edp_ctrl_panel_connected (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msm_edp_ctrl_pixel_clock_valid (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 long stub1 (struct msm_kms*,long,int /*<<< orphan*/ ) ; 
 struct edp_connector* to_edp_connector (struct drm_connector*) ; 

__attribute__((used)) static enum drm_connector_status edp_connector_detect(
		struct drm_connector *connector, bool force)
{
	struct edp_connector *edp_connector = to_edp_connector(connector);
	struct msm_edp *edp = edp_connector->edp;

	DBG("");
	return msm_edp_ctrl_panel_connected(edp->ctrl) ?
		connector_status_connected : connector_status_disconnected;
}

__attribute__((used)) static void edp_connector_destroy(struct drm_connector *connector)
{
	struct edp_connector *edp_connector = to_edp_connector(connector);

	DBG("");

	drm_connector_cleanup(connector);

	kfree(edp_connector);
}

__attribute__((used)) static int edp_connector_get_modes(struct drm_connector *connector)
{
	struct edp_connector *edp_connector = to_edp_connector(connector);
	struct msm_edp *edp = edp_connector->edp;

	struct edid *drm_edid = NULL;
	int ret = 0;

	DBG("");
	ret = msm_edp_ctrl_get_panel_info(edp->ctrl, connector, &drm_edid);
	if (ret)
		return ret;

	drm_connector_update_edid_property(connector, drm_edid);
	if (drm_edid)
		ret = drm_add_edid_modes(connector, drm_edid);

	return ret;
}

__attribute__((used)) static int edp_connector_mode_valid(struct drm_connector *connector,
				 struct drm_display_mode *mode)
{
	struct edp_connector *edp_connector = to_edp_connector(connector);
	struct msm_edp *edp = edp_connector->edp;
	struct msm_drm_private *priv = connector->dev->dev_private;
	struct msm_kms *kms = priv->kms;
	long actual, requested;

	requested = 1000 * mode->clock;
	actual = kms->funcs->round_pixclk(kms,
			requested, edp_connector->edp->encoder);

	DBG("requested=%ld, actual=%ld", requested, actual);
	if (actual != requested)
		return MODE_CLOCK_RANGE;

	if (!msm_edp_ctrl_pixel_clock_valid(
		edp->ctrl, mode->clock, NULL, NULL))
		return MODE_CLOCK_RANGE;

	/* Invalidate all modes if color format is not supported */
	if (connector->display_info.bpc > 8)
		return MODE_BAD;

	return MODE_OK;
}

struct drm_connector *msm_edp_connector_init(struct msm_edp *edp)
{
	struct drm_connector *connector = NULL;
	struct edp_connector *edp_connector;
	int ret;

	edp_connector = kzalloc(sizeof(*edp_connector), GFP_KERNEL);
	if (!edp_connector)
		return ERR_PTR(-ENOMEM);

	edp_connector->edp = edp;

	connector = &edp_connector->base;

	ret = drm_connector_init(edp->dev, connector, &edp_connector_funcs,
			DRM_MODE_CONNECTOR_eDP);
	if (ret)
		return ERR_PTR(ret);

	drm_connector_helper_add(connector, &edp_connector_helper_funcs);

	/* We don't support HPD, so only poll status until connected. */
	connector->polled = DRM_CONNECTOR_POLL_CONNECT;

	/* Display driver doesn't support interlace now. */
	connector->interlace_allowed = false;
	connector->doublescan_allowed = false;

	drm_connector_attach_encoder(connector, edp->encoder);

	return connector;
}

