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
typedef  int /*<<< orphan*/  uint32_t ;
struct tilcdc_module {int dummy; } ;
struct tilcdc_drm_private {int /*<<< orphan*/  crtc; int /*<<< orphan*/  num_connectors; struct drm_connector** connectors; int /*<<< orphan*/  num_encoders; struct drm_encoder** encoders; } ;
struct tfp410_module {scalar_t__ gpio; int /*<<< orphan*/  i2c; struct tilcdc_module base; } ;
struct drm_encoder {int possible_crtcs; } ;
struct tfp410_encoder {int dpms; struct drm_encoder base; struct tfp410_module* mod; } ;
struct drm_connector {int polled; scalar_t__ doublescan_allowed; scalar_t__ interlace_allowed; TYPE_1__* dev; } ;
struct tfp410_connector {struct drm_connector base; struct tfp410_module* mod; struct drm_encoder* encoder; } ;
struct TYPE_8__ {struct tilcdc_module* platform_data; struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct pinctrl {int dummy; } ;
struct edid {int dummy; } ;
struct drm_display_mode {int dummy; } ;
struct drm_device {struct tilcdc_drm_private* dev_private; TYPE_2__* dev; } ;
struct device_node {int dummy; } ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
struct TYPE_7__ {struct tilcdc_drm_private* dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*) ; 
 int DRM_CONNECTOR_POLL_CONNECT ; 
 int DRM_CONNECTOR_POLL_DISCONNECT ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_DVID ; 
 void* DRM_MODE_DPMS_OFF ; 
 int DRM_MODE_DPMS_ON ; 
 int /*<<< orphan*/  DRM_MODE_ENCODER_TMDS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct pinctrl*) ; 
 int connector_status_connected ; 
 int connector_status_unknown ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 struct tilcdc_module* dev_get_platdata (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 void* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct pinctrl* devm_pinctrl_get_select_default (TYPE_2__*) ; 
 int drm_add_edid_modes (struct drm_connector*,struct edid*) ; 
 int drm_connector_attach_encoder (struct drm_connector*,struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_connector_cleanup (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_connector_helper_add (struct drm_connector*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_connector_init (struct drm_device*,struct drm_connector*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_connector_unregister (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_connector_update_edid_property (struct drm_connector*,struct edid*) ; 
 int /*<<< orphan*/  drm_encoder_cleanup (struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_encoder_helper_add (struct drm_encoder*,int /*<<< orphan*/ *) ; 
 int drm_encoder_init (struct drm_device*,struct drm_encoder*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct edid* drm_get_edid (struct drm_connector*,int /*<<< orphan*/ ) ; 
 scalar_t__ drm_probe_ddc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dvi_info ; 
 int /*<<< orphan*/  gpio_direction_output (scalar_t__,int) ; 
 int /*<<< orphan*/  gpio_free (scalar_t__) ; 
 int gpio_request (scalar_t__,char*) ; 
 int /*<<< orphan*/  i2c_put_adapter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct edid*) ; 
 int /*<<< orphan*/  of_find_i2c_adapter_by_node (struct device_node*) ; 
 struct device_node* of_find_node_by_phandle (int /*<<< orphan*/ ) ; 
 scalar_t__ of_get_named_gpio_flags (struct device_node*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tfp410_connector_funcs ; 
 int /*<<< orphan*/  tfp410_connector_helper_funcs ; 
 int /*<<< orphan*/  tfp410_encoder_funcs ; 
 int /*<<< orphan*/  tfp410_encoder_helper_funcs ; 
 int /*<<< orphan*/  tfp410_module_ops ; 
 int tilcdc_crtc_mode_valid (int /*<<< orphan*/ ,struct drm_display_mode*) ; 
 int /*<<< orphan*/  tilcdc_crtc_set_panel_info (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tilcdc_module_cleanup (struct tilcdc_module*) ; 
 int /*<<< orphan*/  tilcdc_module_init (struct tilcdc_module*,char*,int /*<<< orphan*/ *) ; 
 struct tfp410_connector* to_tfp410_connector (struct drm_connector*) ; 
 struct tfp410_encoder* to_tfp410_encoder (struct drm_encoder*) ; 
 struct tfp410_module* to_tfp410_module (struct tilcdc_module*) ; 

__attribute__((used)) static void tfp410_encoder_dpms(struct drm_encoder *encoder, int mode)
{
	struct tfp410_encoder *tfp410_encoder = to_tfp410_encoder(encoder);

	if (tfp410_encoder->dpms == mode)
		return;

	if (mode == DRM_MODE_DPMS_ON) {
		DBG("Power on");
		gpio_direction_output(tfp410_encoder->mod->gpio, 1);
	} else {
		DBG("Power off");
		gpio_direction_output(tfp410_encoder->mod->gpio, 0);
	}

	tfp410_encoder->dpms = mode;
}

__attribute__((used)) static void tfp410_encoder_prepare(struct drm_encoder *encoder)
{
	tfp410_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);
}

__attribute__((used)) static void tfp410_encoder_commit(struct drm_encoder *encoder)
{
	tfp410_encoder_dpms(encoder, DRM_MODE_DPMS_ON);
}

__attribute__((used)) static void tfp410_encoder_mode_set(struct drm_encoder *encoder,
		struct drm_display_mode *mode,
		struct drm_display_mode *adjusted_mode)
{
	/* nothing needed */
}

__attribute__((used)) static struct drm_encoder *tfp410_encoder_create(struct drm_device *dev,
		struct tfp410_module *mod)
{
	struct tfp410_encoder *tfp410_encoder;
	struct drm_encoder *encoder;
	int ret;

	tfp410_encoder = devm_kzalloc(dev->dev, sizeof(*tfp410_encoder),
				      GFP_KERNEL);
	if (!tfp410_encoder)
		return NULL;

	tfp410_encoder->dpms = DRM_MODE_DPMS_OFF;
	tfp410_encoder->mod = mod;

	encoder = &tfp410_encoder->base;
	encoder->possible_crtcs = 1;

	ret = drm_encoder_init(dev, encoder, &tfp410_encoder_funcs,
			DRM_MODE_ENCODER_TMDS, NULL);
	if (ret < 0)
		goto fail;

	drm_encoder_helper_add(encoder, &tfp410_encoder_helper_funcs);

	return encoder;

fail:
	drm_encoder_cleanup(encoder);
	return NULL;
}

__attribute__((used)) static void tfp410_connector_destroy(struct drm_connector *connector)
{
	drm_connector_unregister(connector);
	drm_connector_cleanup(connector);
}

__attribute__((used)) static enum drm_connector_status tfp410_connector_detect(
		struct drm_connector *connector,
		bool force)
{
	struct tfp410_connector *tfp410_connector = to_tfp410_connector(connector);

	if (drm_probe_ddc(tfp410_connector->mod->i2c))
		return connector_status_connected;

	return connector_status_unknown;
}

__attribute__((used)) static int tfp410_connector_get_modes(struct drm_connector *connector)
{
	struct tfp410_connector *tfp410_connector = to_tfp410_connector(connector);
	struct edid *edid;
	int ret = 0;

	edid = drm_get_edid(connector, tfp410_connector->mod->i2c);

	drm_connector_update_edid_property(connector, edid);

	if (edid) {
		ret = drm_add_edid_modes(connector, edid);
		kfree(edid);
	}

	return ret;
}

__attribute__((used)) static int tfp410_connector_mode_valid(struct drm_connector *connector,
		  struct drm_display_mode *mode)
{
	struct tilcdc_drm_private *priv = connector->dev->dev_private;
	/* our only constraints are what the crtc can generate: */
	return tilcdc_crtc_mode_valid(priv->crtc, mode);
}

__attribute__((used)) static struct drm_encoder *tfp410_connector_best_encoder(
		struct drm_connector *connector)
{
	struct tfp410_connector *tfp410_connector = to_tfp410_connector(connector);
	return tfp410_connector->encoder;
}

__attribute__((used)) static struct drm_connector *tfp410_connector_create(struct drm_device *dev,
		struct tfp410_module *mod, struct drm_encoder *encoder)
{
	struct tfp410_connector *tfp410_connector;
	struct drm_connector *connector;
	int ret;

	tfp410_connector = devm_kzalloc(dev->dev, sizeof(*tfp410_connector),
					GFP_KERNEL);
	if (!tfp410_connector)
		return NULL;

	tfp410_connector->encoder = encoder;
	tfp410_connector->mod = mod;

	connector = &tfp410_connector->base;

	drm_connector_init(dev, connector, &tfp410_connector_funcs,
			DRM_MODE_CONNECTOR_DVID);
	drm_connector_helper_add(connector, &tfp410_connector_helper_funcs);

	connector->polled = DRM_CONNECTOR_POLL_CONNECT |
			DRM_CONNECTOR_POLL_DISCONNECT;

	connector->interlace_allowed = 0;
	connector->doublescan_allowed = 0;

	ret = drm_connector_attach_encoder(connector, encoder);
	if (ret)
		goto fail;

	return connector;

fail:
	tfp410_connector_destroy(connector);
	return NULL;
}

__attribute__((used)) static int tfp410_modeset_init(struct tilcdc_module *mod, struct drm_device *dev)
{
	struct tfp410_module *tfp410_mod = to_tfp410_module(mod);
	struct tilcdc_drm_private *priv = dev->dev_private;
	struct drm_encoder *encoder;
	struct drm_connector *connector;

	encoder = tfp410_encoder_create(dev, tfp410_mod);
	if (!encoder)
		return -ENOMEM;

	connector = tfp410_connector_create(dev, tfp410_mod, encoder);
	if (!connector)
		return -ENOMEM;

	priv->encoders[priv->num_encoders++] = encoder;
	priv->connectors[priv->num_connectors++] = connector;

	tilcdc_crtc_set_panel_info(priv->crtc, &dvi_info);
	return 0;
}

__attribute__((used)) static int tfp410_probe(struct platform_device *pdev)
{
	struct device_node *node = pdev->dev.of_node;
	struct device_node *i2c_node;
	struct tfp410_module *tfp410_mod;
	struct tilcdc_module *mod;
	struct pinctrl *pinctrl;
	uint32_t i2c_phandle;
	int ret = -EINVAL;

	/* bail out early if no DT data: */
	if (!node) {
		dev_err(&pdev->dev, "device-tree data is missing\n");
		return -ENXIO;
	}

	tfp410_mod = devm_kzalloc(&pdev->dev, sizeof(*tfp410_mod), GFP_KERNEL);
	if (!tfp410_mod)
		return -ENOMEM;

	mod = &tfp410_mod->base;
	pdev->dev.platform_data = mod;

	tilcdc_module_init(mod, "tfp410", &tfp410_module_ops);

	pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
	if (IS_ERR(pinctrl))
		dev_warn(&pdev->dev, "pins are not configured\n");

	if (of_property_read_u32(node, "i2c", &i2c_phandle)) {
		dev_err(&pdev->dev, "could not get i2c bus phandle\n");
		goto fail;
	}

	i2c_node = of_find_node_by_phandle(i2c_phandle);
	if (!i2c_node) {
		dev_err(&pdev->dev, "could not get i2c bus node\n");
		goto fail;
	}

	tfp410_mod->i2c = of_find_i2c_adapter_by_node(i2c_node);
	if (!tfp410_mod->i2c) {
		dev_err(&pdev->dev, "could not get i2c\n");
		of_node_put(i2c_node);
		goto fail;
	}

	of_node_put(i2c_node);

	tfp410_mod->gpio = of_get_named_gpio_flags(node, "powerdn-gpio",
			0, NULL);
	if (tfp410_mod->gpio < 0) {
		dev_warn(&pdev->dev, "No power down GPIO\n");
	} else {
		ret = gpio_request(tfp410_mod->gpio, "DVI_PDn");
		if (ret) {
			dev_err(&pdev->dev, "could not get DVI_PDn gpio\n");
			goto fail_adapter;
		}
	}

	return 0;

fail_adapter:
	i2c_put_adapter(tfp410_mod->i2c);

fail:
	tilcdc_module_cleanup(mod);
	return ret;
}

__attribute__((used)) static int tfp410_remove(struct platform_device *pdev)
{
	struct tilcdc_module *mod = dev_get_platdata(&pdev->dev);
	struct tfp410_module *tfp410_mod = to_tfp410_module(mod);

	i2c_put_adapter(tfp410_mod->i2c);
	gpio_free(tfp410_mod->gpio);

	tilcdc_module_cleanup(mod);

	return 0;
}

