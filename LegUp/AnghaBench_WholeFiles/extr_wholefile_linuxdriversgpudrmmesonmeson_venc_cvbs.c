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
struct drm_connector {int interlace_allowed; struct drm_device* dev; } ;
struct drm_encoder {int /*<<< orphan*/  possible_crtcs; } ;
struct meson_venc_cvbs {struct drm_connector connector; struct drm_encoder encoder; struct meson_drm* priv; } ;
struct meson_drm {TYPE_1__* dev; struct drm_device* drm; int /*<<< orphan*/  hhi; scalar_t__ io_base; } ;
struct meson_cvbs_mode {int /*<<< orphan*/  enci; int /*<<< orphan*/  mode; } ;
struct drm_display_mode {int dummy; } ;
struct drm_device {int /*<<< orphan*/  dev; } ;
struct drm_crtc_state {struct drm_display_mode mode; } ;
struct drm_connector_state {int dummy; } ;
struct device_node {int dummy; } ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
struct TYPE_3__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_Composite ; 
 int /*<<< orphan*/  DRM_MODE_ENCODER_TVDAC ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HHI_VDAC_CNTL0 ; 
 int /*<<< orphan*/  HHI_VDAC_CNTL1 ; 
 int MESON_CVBS_MODES_COUNT ; 
 int /*<<< orphan*/  MESON_VCLK_CVBS ; 
 int /*<<< orphan*/  MESON_VCLK_TARGET_CVBS ; 
 int MODE_OK ; 
 int /*<<< orphan*/  VENC_VDAC_DACSEL0 ; 
 scalar_t__ _REG (int /*<<< orphan*/ ) ; 
 int connector_status_connected ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*) ; 
 struct meson_venc_cvbs* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_connector_attach_encoder (struct drm_connector*,struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_connector_cleanup (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_connector_helper_add (struct drm_connector*,int /*<<< orphan*/ *) ; 
 int drm_connector_init (struct drm_device*,struct drm_connector*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_encoder_cleanup (struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_encoder_helper_add (struct drm_encoder*,int /*<<< orphan*/ *) ; 
 int drm_encoder_init (struct drm_device*,struct drm_encoder*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 struct drm_display_mode* drm_mode_duplicate (struct drm_device*,int /*<<< orphan*/ *) ; 
 scalar_t__ drm_mode_equal (struct drm_display_mode*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_mode_probed_add (struct drm_connector*,struct drm_display_mode*) ; 
 struct meson_venc_cvbs* encoder_to_meson_venc_cvbs (struct drm_encoder*) ; 
 int /*<<< orphan*/  meson_cvbs_connector_funcs ; 
 int /*<<< orphan*/  meson_cvbs_connector_helper_funcs ; 
 struct meson_cvbs_mode* meson_cvbs_modes ; 
 int /*<<< orphan*/  meson_vclk_setup (struct meson_drm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  meson_venc_cvbs_encoder_funcs ; 
 int /*<<< orphan*/  meson_venc_cvbs_encoder_helper_funcs ; 
 int /*<<< orphan*/  meson_venci_cvbs_mode_set (struct meson_drm*,int /*<<< orphan*/ ) ; 
 int of_device_is_compatible (int /*<<< orphan*/ ,char const*) ; 
 struct device_node* of_graph_get_remote_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  writel_bits_relaxed (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline int meson_vpu_is_compatible(struct meson_drm *priv,
					  const char *compat)
{
	return of_device_is_compatible(priv->dev->of_node, compat);
}

__attribute__((used)) static void meson_cvbs_connector_destroy(struct drm_connector *connector)
{
	drm_connector_cleanup(connector);
}

__attribute__((used)) static enum drm_connector_status
meson_cvbs_connector_detect(struct drm_connector *connector, bool force)
{
	/* FIXME: Add load-detect or jack-detect if possible */
	return connector_status_connected;
}

__attribute__((used)) static int meson_cvbs_connector_get_modes(struct drm_connector *connector)
{
	struct drm_device *dev = connector->dev;
	struct drm_display_mode *mode;
	int i;

	for (i = 0; i < MESON_CVBS_MODES_COUNT; ++i) {
		struct meson_cvbs_mode *meson_mode = &meson_cvbs_modes[i];

		mode = drm_mode_duplicate(dev, &meson_mode->mode);
		if (!mode) {
			DRM_ERROR("Failed to create a new display mode\n");
			return 0;
		}

		drm_mode_probed_add(connector, mode);
	}

	return i;
}

__attribute__((used)) static int meson_cvbs_connector_mode_valid(struct drm_connector *connector,
					   struct drm_display_mode *mode)
{
	/* Validate the modes added in get_modes */
	return MODE_OK;
}

__attribute__((used)) static void meson_venc_cvbs_encoder_destroy(struct drm_encoder *encoder)
{
	drm_encoder_cleanup(encoder);
}

__attribute__((used)) static int meson_venc_cvbs_encoder_atomic_check(struct drm_encoder *encoder,
					struct drm_crtc_state *crtc_state,
					struct drm_connector_state *conn_state)
{
	int i;

	for (i = 0; i < MESON_CVBS_MODES_COUNT; ++i) {
		struct meson_cvbs_mode *meson_mode = &meson_cvbs_modes[i];

		if (drm_mode_equal(&crtc_state->mode, &meson_mode->mode))
			return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static void meson_venc_cvbs_encoder_disable(struct drm_encoder *encoder)
{
	struct meson_venc_cvbs *meson_venc_cvbs =
					encoder_to_meson_venc_cvbs(encoder);
	struct meson_drm *priv = meson_venc_cvbs->priv;

	/* Disable CVBS VDAC */
	regmap_write(priv->hhi, HHI_VDAC_CNTL0, 0);
	regmap_write(priv->hhi, HHI_VDAC_CNTL1, 8);
}

__attribute__((used)) static void meson_venc_cvbs_encoder_enable(struct drm_encoder *encoder)
{
	struct meson_venc_cvbs *meson_venc_cvbs =
					encoder_to_meson_venc_cvbs(encoder);
	struct meson_drm *priv = meson_venc_cvbs->priv;

	/* VDAC0 source is not from ATV */
	writel_bits_relaxed(BIT(5), 0, priv->io_base + _REG(VENC_VDAC_DACSEL0));

	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
		regmap_write(priv->hhi, HHI_VDAC_CNTL0, 1);
	else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
		 meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
		regmap_write(priv->hhi, HHI_VDAC_CNTL0, 0xf0001);

	regmap_write(priv->hhi, HHI_VDAC_CNTL1, 0);
}

__attribute__((used)) static void meson_venc_cvbs_encoder_mode_set(struct drm_encoder *encoder,
				   struct drm_display_mode *mode,
				   struct drm_display_mode *adjusted_mode)
{
	struct meson_venc_cvbs *meson_venc_cvbs =
					encoder_to_meson_venc_cvbs(encoder);
	struct meson_drm *priv = meson_venc_cvbs->priv;
	int i;

	for (i = 0; i < MESON_CVBS_MODES_COUNT; ++i) {
		struct meson_cvbs_mode *meson_mode = &meson_cvbs_modes[i];

		if (drm_mode_equal(mode, &meson_mode->mode)) {
			meson_venci_cvbs_mode_set(priv,
						  meson_mode->enci);

			/* Setup 27MHz vclk2 for ENCI and VDAC */
			meson_vclk_setup(priv, MESON_VCLK_TARGET_CVBS,
					 MESON_VCLK_CVBS, MESON_VCLK_CVBS,
					 MESON_VCLK_CVBS, true);
			break;
		}
	}
}

__attribute__((used)) static bool meson_venc_cvbs_connector_is_available(struct meson_drm *priv)
{
	struct device_node *remote;

	remote = of_graph_get_remote_node(priv->dev->of_node, 0, 0);
	if (!remote)
		return false;

	of_node_put(remote);
	return true;
}

int meson_venc_cvbs_create(struct meson_drm *priv)
{
	struct drm_device *drm = priv->drm;
	struct meson_venc_cvbs *meson_venc_cvbs;
	struct drm_connector *connector;
	struct drm_encoder *encoder;
	int ret;

	if (!meson_venc_cvbs_connector_is_available(priv)) {
		dev_info(drm->dev, "CVBS Output connector not available\n");
		return 0;
	}

	meson_venc_cvbs = devm_kzalloc(priv->dev, sizeof(*meson_venc_cvbs),
				       GFP_KERNEL);
	if (!meson_venc_cvbs)
		return -ENOMEM;

	meson_venc_cvbs->priv = priv;
	encoder = &meson_venc_cvbs->encoder;
	connector = &meson_venc_cvbs->connector;

	/* Connector */

	drm_connector_helper_add(connector,
				 &meson_cvbs_connector_helper_funcs);

	ret = drm_connector_init(drm, connector, &meson_cvbs_connector_funcs,
				 DRM_MODE_CONNECTOR_Composite);
	if (ret) {
		dev_err(priv->dev, "Failed to init CVBS connector\n");
		return ret;
	}

	connector->interlace_allowed = 1;

	/* Encoder */

	drm_encoder_helper_add(encoder, &meson_venc_cvbs_encoder_helper_funcs);

	ret = drm_encoder_init(drm, encoder, &meson_venc_cvbs_encoder_funcs,
			       DRM_MODE_ENCODER_TVDAC, "meson_venc_cvbs");
	if (ret) {
		dev_err(priv->dev, "Failed to init CVBS encoder\n");
		return ret;
	}

	encoder->possible_crtcs = BIT(0);

	drm_connector_attach_encoder(connector, encoder);

	return 0;
}

