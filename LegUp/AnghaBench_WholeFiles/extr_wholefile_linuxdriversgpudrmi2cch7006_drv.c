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
typedef  int /*<<< orphan*/  val ;
typedef  int uint8_t ;
typedef  void* uint64_t ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int dummy; } ;
struct drm_property {int dummy; } ;
struct drm_mode_config {struct drm_property* tv_flicker_reduction_property; struct drm_property* tv_contrast_property; struct drm_property* tv_brightness_property; struct drm_property* tv_mode_property; struct drm_property* tv_bottom_margin_property; struct drm_property* tv_left_margin_property; struct drm_property* tv_select_subconnector_property; struct drm_property* tv_subconnector_property; } ;
struct drm_encoder_slave {int /*<<< orphan*/ * slave_funcs; struct ch7006_priv* slave_priv; } ;
struct drm_encoder {struct drm_crtc* crtc; struct drm_device* dev; } ;
typedef  struct drm_display_mode {int htotal; int hsync_start; int flags; } const drm_display_mode ;
struct drm_device {struct drm_mode_config mode_config; } ;
struct drm_crtc {int dummy; } ;
struct drm_connector {scalar_t__ dpms; int /*<<< orphan*/  base; } ;
struct device {int dummy; } ;
struct ch7006_tv_norm_info {int dispmode; } ;
struct ch7006_state {int* regs; } ;
struct ch7006_encoder_params {int input_format; int xcm; int pcm; scalar_t__ active_detect; scalar_t__ pout_level; scalar_t__ sync_encoding; scalar_t__ sync_direction; scalar_t__ clock_edge; scalar_t__ clock_mode; } ;
struct ch7006_priv {int last_dpms; size_t norm; int subconnector; int scale; int select_subconnector; int hmargin; int vmargin; int brightness; int contrast; int flicker; void* chip_version; struct drm_property* scale_property; struct ch7006_state state; struct ch7006_state saved_state; struct ch7006_mode* mode; struct ch7006_encoder_params params; } ;
struct TYPE_4__ {scalar_t__ clock; } ;
struct ch7006_mode {int dispmode; int valid_scales; int valid_norms; TYPE_2__ mode; } ;
typedef  int int32_t ;
typedef  int fixed ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
typedef  int /*<<< orphan*/  addr ;
struct TYPE_3__ {int /*<<< orphan*/ * slave_priv; } ;

/* Variables and functions */
 size_t CH7006_BCLKOUT ; 
 size_t CH7006_BLACK_LEVEL ; 
 size_t CH7006_BWIDTH ; 
 size_t CH7006_CLKMODE ; 
 int CH7006_CLKMODE_MASTER ; 
 int /*<<< orphan*/  CH7006_CLKMODE_PCM ; 
 int CH7006_CLKMODE_POS_EDGE ; 
 int CH7006_CLKMODE_SUBC_LOCK ; 
 int /*<<< orphan*/  CH7006_CLKMODE_XCM ; 
 size_t CH7006_CONTRAST ; 
 size_t CH7006_DETECT ; 
 int CH7006_DETECT_CVBS_TEST ; 
 int CH7006_DETECT_SENSE ; 
 int CH7006_DETECT_SVIDEO_C_TEST ; 
 int CH7006_DETECT_SVIDEO_Y_TEST ; 
 size_t CH7006_DISPMODE ; 
 size_t CH7006_FFILTER ; 
 size_t CH7006_HPOS ; 
 size_t CH7006_INPUT_FORMAT ; 
 int /*<<< orphan*/  CH7006_INPUT_FORMAT_FORMAT ; 
 size_t CH7006_INPUT_SYNC ; 
 int CH7006_INPUT_SYNC_EMBEDDED ; 
 int CH7006_INPUT_SYNC_OUTPUT ; 
 int CH7006_INPUT_SYNC_PHSYNC ; 
 int CH7006_INPUT_SYNC_PVSYNC ; 
 size_t CH7006_PLL_CONTROL ; 
 size_t CH7006_POV ; 
 int /*<<< orphan*/  CH7006_POV_START_ACTIVE_8 ; 
 size_t CH7006_POWER ; 
 int /*<<< orphan*/  CH7006_POWER_LEVEL ; 
 int CH7006_POWER_RESET ; 
 size_t CH7006_START_ACTIVE ; 
 int /*<<< orphan*/  CH7006_START_ACTIVE_0 ; 
 size_t CH7006_SUBC_INC3 ; 
 int CH7006_SUBC_INC3_POUT_3_3V ; 
 size_t CH7006_SUBC_INC4 ; 
 int CH7006_SUBC_INC4_DS_INPUT ; 
 size_t CH7006_VERSION_ID ; 
 size_t CH7006_VPOS ; 
 scalar_t__ DRM_MODE_DPMS_OFF ; 
 int DRM_MODE_FLAG_PHSYNC ; 
 int DRM_MODE_FLAG_PVSYNC ; 
 int DRM_MODE_SUBCONNECTOR_Automatic ; 
 int DRM_MODE_SUBCONNECTOR_Composite ; 
 int DRM_MODE_SUBCONNECTOR_SCART ; 
 int DRM_MODE_SUBCONNECTOR_SVIDEO ; 
 void* DRM_MODE_SUBCONNECTOR_Unknown ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MODE_BAD ; 
 int MODE_OK ; 
 int /*<<< orphan*/  NORMAL ; 
 int NUM_TV_NORMS ; 
 int TV_NORM_PAL ; 
 int bitf (int /*<<< orphan*/ ,int) ; 
 int bitfs (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ch7006_dbg (struct i2c_client*,char*) ; 
 int /*<<< orphan*/  ch7006_encoder_funcs ; 
 int /*<<< orphan*/  ch7006_err (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  ch7006_info (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  ch7006_load_reg (struct i2c_client*,struct ch7006_state*,size_t) ; 
 struct ch7006_mode* ch7006_lookup_mode (struct drm_encoder*,struct drm_display_mode const*) ; 
 struct ch7006_mode* ch7006_modes ; 
 void* ch7006_read (struct i2c_client*,size_t) ; 
 int /*<<< orphan*/  ch7006_save_reg (struct i2c_client*,struct ch7006_state*,size_t) ; 
 int ch7006_scale ; 
 int /*<<< orphan*/  ch7006_setup_levels (struct drm_encoder*) ; 
 int /*<<< orphan*/  ch7006_setup_pll (struct drm_encoder*) ; 
 int /*<<< orphan*/  ch7006_setup_power_state (struct drm_encoder*) ; 
 int /*<<< orphan*/  ch7006_setup_properties (struct drm_encoder*) ; 
 int /*<<< orphan*/  ch7006_setup_subcarrier (struct drm_encoder*) ; 
 int /*<<< orphan*/  ch7006_state_load (struct i2c_client*,struct ch7006_state*) ; 
 int /*<<< orphan*/  ch7006_state_save (struct i2c_client*,struct ch7006_state*) ; 
 int ch7006_tv_norm ; 
 int /*<<< orphan*/ * ch7006_tv_norm_names ; 
 struct ch7006_tv_norm_info* ch7006_tv_norms ; 
 int /*<<< orphan*/  ch7006_write (struct i2c_client*,int,int) ; 
 int connector_status_connected ; 
 int connector_status_disconnected ; 
 int /*<<< orphan*/  drm_crtc_force_disable (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_helper_probe_single_connector_modes (struct drm_connector*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_i2c_encoder_destroy (struct drm_encoder*) ; 
 struct i2c_client* drm_i2c_encoder_get_client (struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_mode_create_tv_properties (struct drm_device*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_mode_duplicate (struct drm_device*,TYPE_2__*) ; 
 int /*<<< orphan*/  drm_mode_probed_add (struct drm_connector*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_object_attach_property (int /*<<< orphan*/ *,struct drm_property*,int) ; 
 int /*<<< orphan*/  drm_object_property_set_value (int /*<<< orphan*/ *,struct drm_property*,int) ; 
 struct drm_property* drm_property_create_range (struct drm_device*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  drm_property_destroy (struct drm_device*,struct drm_property*) ; 
 int fixed1 ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  kfree (struct ch7006_priv*) ; 
 struct ch7006_priv* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int) ; 
 struct ch7006_priv* to_ch7006_priv (struct drm_encoder*) ; 
 TYPE_1__* to_encoder_slave (struct drm_encoder*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static inline int interpolate(int y0, int y1, int y2, int x)
{
	return y1 + (x < 50 ? y1 - y0 : y2 - y1) * (x - 50) / 50;
}

__attribute__((used)) static inline int32_t round_fixed(fixed x)
{
	return (x + fixed1/2) >> 32;
}

__attribute__((used)) static void ch7006_encoder_set_config(struct drm_encoder *encoder,
				      void *params)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);

	priv->params = *(struct ch7006_encoder_params *)params;
}

__attribute__((used)) static void ch7006_encoder_destroy(struct drm_encoder *encoder)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);

	drm_property_destroy(encoder->dev, priv->scale_property);

	kfree(priv);
	to_encoder_slave(encoder)->slave_priv = NULL;

	drm_i2c_encoder_destroy(encoder);
}

__attribute__((used)) static void  ch7006_encoder_dpms(struct drm_encoder *encoder, int mode)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct ch7006_state *state = &priv->state;

	ch7006_dbg(client, "\n");

	if (mode == priv->last_dpms)
		return;
	priv->last_dpms = mode;

	ch7006_setup_power_state(encoder);

	ch7006_load_reg(client, state, CH7006_POWER);
}

__attribute__((used)) static void ch7006_encoder_save(struct drm_encoder *encoder)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);

	ch7006_dbg(client, "\n");

	ch7006_state_save(client, &priv->saved_state);
}

__attribute__((used)) static void ch7006_encoder_restore(struct drm_encoder *encoder)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);

	ch7006_dbg(client, "\n");

	ch7006_state_load(client, &priv->saved_state);
}

__attribute__((used)) static bool ch7006_encoder_mode_fixup(struct drm_encoder *encoder,
				      const struct drm_display_mode *mode,
				      struct drm_display_mode *adjusted_mode)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);

	/* The ch7006 is painfully picky with the input timings so no
	 * custom modes for now... */

	priv->mode = ch7006_lookup_mode(encoder, mode);

	return !!priv->mode;
}

__attribute__((used)) static int ch7006_encoder_mode_valid(struct drm_encoder *encoder,
				     struct drm_display_mode *mode)
{
	if (ch7006_lookup_mode(encoder, mode))
		return MODE_OK;
	else
		return MODE_BAD;
}

__attribute__((used)) static void ch7006_encoder_mode_set(struct drm_encoder *encoder,
				     struct drm_display_mode *drm_mode,
				     struct drm_display_mode *adjusted_mode)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct ch7006_encoder_params *params = &priv->params;
	struct ch7006_state *state = &priv->state;
	uint8_t *regs = state->regs;
	const struct ch7006_mode *mode = priv->mode;
	const struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
	int start_active;

	ch7006_dbg(client, "\n");

	regs[CH7006_DISPMODE] = norm->dispmode | mode->dispmode;
	regs[CH7006_BWIDTH] = 0;
	regs[CH7006_INPUT_FORMAT] = bitf(CH7006_INPUT_FORMAT_FORMAT,
					 params->input_format);

	regs[CH7006_CLKMODE] = CH7006_CLKMODE_SUBC_LOCK
		| bitf(CH7006_CLKMODE_XCM, params->xcm)
		| bitf(CH7006_CLKMODE_PCM, params->pcm);
	if (params->clock_mode)
		regs[CH7006_CLKMODE] |= CH7006_CLKMODE_MASTER;
	if (params->clock_edge)
		regs[CH7006_CLKMODE] |= CH7006_CLKMODE_POS_EDGE;

	start_active = (drm_mode->htotal & ~0x7) - (drm_mode->hsync_start & ~0x7);
	regs[CH7006_POV] = bitf(CH7006_POV_START_ACTIVE_8, start_active);
	regs[CH7006_START_ACTIVE] = bitf(CH7006_START_ACTIVE_0, start_active);

	regs[CH7006_INPUT_SYNC] = 0;
	if (params->sync_direction)
		regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_OUTPUT;
	if (params->sync_encoding)
		regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_EMBEDDED;
	if (drm_mode->flags & DRM_MODE_FLAG_PVSYNC)
		regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_PVSYNC;
	if (drm_mode->flags & DRM_MODE_FLAG_PHSYNC)
		regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_PHSYNC;

	regs[CH7006_DETECT] = 0;
	regs[CH7006_BCLKOUT] = 0;

	regs[CH7006_SUBC_INC3] = 0;
	if (params->pout_level)
		regs[CH7006_SUBC_INC3] |= CH7006_SUBC_INC3_POUT_3_3V;

	regs[CH7006_SUBC_INC4] = 0;
	if (params->active_detect)
		regs[CH7006_SUBC_INC4] |= CH7006_SUBC_INC4_DS_INPUT;

	regs[CH7006_PLL_CONTROL] = priv->saved_state.regs[CH7006_PLL_CONTROL];

	ch7006_setup_levels(encoder);
	ch7006_setup_subcarrier(encoder);
	ch7006_setup_pll(encoder);
	ch7006_setup_power_state(encoder);
	ch7006_setup_properties(encoder);

	ch7006_state_load(client, state);
}

__attribute__((used)) static enum drm_connector_status ch7006_encoder_detect(struct drm_encoder *encoder,
						       struct drm_connector *connector)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct ch7006_state *state = &priv->state;
	int det;

	ch7006_dbg(client, "\n");

	ch7006_save_reg(client, state, CH7006_DETECT);
	ch7006_save_reg(client, state, CH7006_POWER);
	ch7006_save_reg(client, state, CH7006_CLKMODE);

	ch7006_write(client, CH7006_POWER, CH7006_POWER_RESET |
					   bitfs(CH7006_POWER_LEVEL, NORMAL));
	ch7006_write(client, CH7006_CLKMODE, CH7006_CLKMODE_MASTER);

	ch7006_write(client, CH7006_DETECT, CH7006_DETECT_SENSE);

	ch7006_write(client, CH7006_DETECT, 0);

	det = ch7006_read(client, CH7006_DETECT);

	ch7006_load_reg(client, state, CH7006_CLKMODE);
	ch7006_load_reg(client, state, CH7006_POWER);
	ch7006_load_reg(client, state, CH7006_DETECT);

	if ((det & (CH7006_DETECT_SVIDEO_Y_TEST|
		    CH7006_DETECT_SVIDEO_C_TEST|
		    CH7006_DETECT_CVBS_TEST)) == 0)
		priv->subconnector = DRM_MODE_SUBCONNECTOR_SCART;
	else if ((det & (CH7006_DETECT_SVIDEO_Y_TEST|
			 CH7006_DETECT_SVIDEO_C_TEST)) == 0)
		priv->subconnector = DRM_MODE_SUBCONNECTOR_SVIDEO;
	else if ((det & CH7006_DETECT_CVBS_TEST) == 0)
		priv->subconnector = DRM_MODE_SUBCONNECTOR_Composite;
	else
		priv->subconnector = DRM_MODE_SUBCONNECTOR_Unknown;

	drm_object_property_set_value(&connector->base,
			encoder->dev->mode_config.tv_subconnector_property,
							priv->subconnector);

	return priv->subconnector ? connector_status_connected :
					connector_status_disconnected;
}

__attribute__((used)) static int ch7006_encoder_get_modes(struct drm_encoder *encoder,
				    struct drm_connector *connector)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	const struct ch7006_mode *mode;
	int n = 0;

	for (mode = ch7006_modes; mode->mode.clock; mode++) {
		if (~mode->valid_scales & 1<<priv->scale ||
		    ~mode->valid_norms & 1<<priv->norm)
			continue;

		drm_mode_probed_add(connector,
				drm_mode_duplicate(encoder->dev, &mode->mode));

		n++;
	}

	return n;
}

__attribute__((used)) static int ch7006_encoder_create_resources(struct drm_encoder *encoder,
					   struct drm_connector *connector)
{
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct drm_device *dev = encoder->dev;
	struct drm_mode_config *conf = &dev->mode_config;

	drm_mode_create_tv_properties(dev, NUM_TV_NORMS, ch7006_tv_norm_names);

	priv->scale_property = drm_property_create_range(dev, 0, "scale", 0, 2);
	if (!priv->scale_property)
		return -ENOMEM;

	drm_object_attach_property(&connector->base, conf->tv_select_subconnector_property,
				      priv->select_subconnector);
	drm_object_attach_property(&connector->base, conf->tv_subconnector_property,
				      priv->subconnector);
	drm_object_attach_property(&connector->base, conf->tv_left_margin_property,
				      priv->hmargin);
	drm_object_attach_property(&connector->base, conf->tv_bottom_margin_property,
				      priv->vmargin);
	drm_object_attach_property(&connector->base, conf->tv_mode_property,
				      priv->norm);
	drm_object_attach_property(&connector->base, conf->tv_brightness_property,
				      priv->brightness);
	drm_object_attach_property(&connector->base, conf->tv_contrast_property,
				      priv->contrast);
	drm_object_attach_property(&connector->base, conf->tv_flicker_reduction_property,
				      priv->flicker);
	drm_object_attach_property(&connector->base, priv->scale_property,
				      priv->scale);

	return 0;
}

__attribute__((used)) static int ch7006_encoder_set_property(struct drm_encoder *encoder,
				       struct drm_connector *connector,
				       struct drm_property *property,
				       uint64_t val)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
	struct ch7006_priv *priv = to_ch7006_priv(encoder);
	struct ch7006_state *state = &priv->state;
	struct drm_mode_config *conf = &encoder->dev->mode_config;
	struct drm_crtc *crtc = encoder->crtc;
	bool modes_changed = false;

	ch7006_dbg(client, "\n");

	if (property == conf->tv_select_subconnector_property) {
		priv->select_subconnector = val;

		ch7006_setup_power_state(encoder);

		ch7006_load_reg(client, state, CH7006_POWER);

	} else if (property == conf->tv_left_margin_property) {
		priv->hmargin = val;

		ch7006_setup_properties(encoder);

		ch7006_load_reg(client, state, CH7006_POV);
		ch7006_load_reg(client, state, CH7006_HPOS);

	} else if (property == conf->tv_bottom_margin_property) {
		priv->vmargin = val;

		ch7006_setup_properties(encoder);

		ch7006_load_reg(client, state, CH7006_POV);
		ch7006_load_reg(client, state, CH7006_VPOS);

	} else if (property == conf->tv_mode_property) {
		if (connector->dpms != DRM_MODE_DPMS_OFF)
			return -EINVAL;

		priv->norm = val;

		modes_changed = true;

	} else if (property == conf->tv_brightness_property) {
		priv->brightness = val;

		ch7006_setup_levels(encoder);

		ch7006_load_reg(client, state, CH7006_BLACK_LEVEL);

	} else if (property == conf->tv_contrast_property) {
		priv->contrast = val;

		ch7006_setup_properties(encoder);

		ch7006_load_reg(client, state, CH7006_CONTRAST);

	} else if (property == conf->tv_flicker_reduction_property) {
		priv->flicker = val;

		ch7006_setup_properties(encoder);

		ch7006_load_reg(client, state, CH7006_FFILTER);

	} else if (property == priv->scale_property) {
		if (connector->dpms != DRM_MODE_DPMS_OFF)
			return -EINVAL;

		priv->scale = val;

		modes_changed = true;

	} else {
		return -EINVAL;
	}

	if (modes_changed) {
		drm_helper_probe_single_connector_modes(connector, 0, 0);

		/* Disable the crtc to ensure a full modeset is
		 * performed whenever it's turned on again. */
		if (crtc)
			drm_crtc_force_disable(crtc);
	}

	return 0;
}

__attribute__((used)) static int ch7006_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	uint8_t addr = CH7006_VERSION_ID;
	uint8_t val;
	int ret;

	ch7006_dbg(client, "\n");

	ret = i2c_master_send(client, &addr, sizeof(addr));
	if (ret < 0)
		goto fail;

	ret = i2c_master_recv(client, &val, sizeof(val));
	if (ret < 0)
		goto fail;

	ch7006_info(client, "Detected version ID: %x\n", val);

	/* I don't know what this is for, but otherwise I get no
	 * signal.
	 */
	ch7006_write(client, 0x3d, 0x0);

	return 0;

fail:
	ch7006_err(client, "Error %d reading version ID\n", ret);

	return -ENODEV;
}

__attribute__((used)) static int ch7006_remove(struct i2c_client *client)
{
	ch7006_dbg(client, "\n");

	return 0;
}

__attribute__((used)) static int ch7006_resume(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);

	ch7006_dbg(client, "\n");

	ch7006_write(client, 0x3d, 0x0);

	return 0;
}

__attribute__((used)) static int ch7006_encoder_init(struct i2c_client *client,
			       struct drm_device *dev,
			       struct drm_encoder_slave *encoder)
{
	struct ch7006_priv *priv;
	int i;

	ch7006_dbg(client, "\n");

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	encoder->slave_priv = priv;
	encoder->slave_funcs = &ch7006_encoder_funcs;

	priv->norm = TV_NORM_PAL;
	priv->select_subconnector = DRM_MODE_SUBCONNECTOR_Automatic;
	priv->subconnector = DRM_MODE_SUBCONNECTOR_Unknown;
	priv->scale = 1;
	priv->contrast = 50;
	priv->brightness = 50;
	priv->flicker = 50;
	priv->hmargin = 50;
	priv->vmargin = 50;
	priv->last_dpms = -1;
	priv->chip_version = ch7006_read(client, CH7006_VERSION_ID);

	if (ch7006_tv_norm) {
		for (i = 0; i < NUM_TV_NORMS; i++) {
			if (!strcmp(ch7006_tv_norm_names[i], ch7006_tv_norm)) {
				priv->norm = i;
				break;
			}
		}

		if (i == NUM_TV_NORMS)
			ch7006_err(client, "Invalid TV norm setting \"%s\".\n",
				   ch7006_tv_norm);
	}

	if (ch7006_scale >= 0 && ch7006_scale <= 2)
		priv->scale = ch7006_scale;
	else
		ch7006_err(client, "Invalid scale setting \"%d\".\n",
			   ch7006_scale);

	return 0;
}

