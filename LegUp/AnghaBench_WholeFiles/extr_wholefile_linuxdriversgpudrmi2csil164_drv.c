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
typedef  int /*<<< orphan*/  uint64_t ;
struct sil164_encoder_params {int input_skew; int duallink_skew; scalar_t__ pll_filter; scalar_t__ input_dual; scalar_t__ input_width; scalar_t__ input_edge; } ;
struct sil164_priv {int* saved_state; int* saved_slave_state; struct i2c_client* duallink_slave; struct sil164_encoder_params config; } ;
struct i2c_msg {int /*<<< orphan*/  len; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  member_0; } ;
struct i2c_adapter {int dummy; } ;
struct drm_property {int dummy; } ;
struct drm_encoder_slave {int /*<<< orphan*/ * slave_funcs; struct sil164_priv* slave_priv; } ;
struct drm_encoder {TYPE_2__* crtc; } ;
struct drm_display_mode {int clock; } ;
struct drm_device {int dummy; } ;
struct drm_connector {int dummy; } ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
typedef  int /*<<< orphan*/  addr ;
struct TYPE_3__ {int clock; } ;
struct TYPE_4__ {TYPE_1__ mode; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int DRM_MODE_DPMS_ON ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_BOARD_INFO (char*,int /*<<< orphan*/ ) ; 
 int MODE_CLOCK_HIGH ; 
 int MODE_CLOCK_LOW ; 
 int MODE_OK ; 
 int SIL164_CONTROL0 ; 
 int SIL164_CONTROL0_DUAL_EDGE ; 
 int SIL164_CONTROL0_EDGE_RISING ; 
 int SIL164_CONTROL0_HSYNC_ON ; 
 int SIL164_CONTROL0_INPUT_24BIT ; 
 int SIL164_CONTROL0_POWER_ON ; 
 int SIL164_CONTROL0_VSYNC_ON ; 
 int SIL164_CONTROL1 ; 
 int SIL164_CONTROL1_DESKEW_ENABLE ; 
 int SIL164_CONTROL1_DESKEW_INCR_SHIFT ; 
 int SIL164_CONTROL2 ; 
 int SIL164_CONTROL2_FILTER_ENABLE ; 
 int SIL164_CONTROL2_FILTER_SETTING_SHIFT ; 
 int SIL164_CONTROL2_SYNC_CONT ; 
 int SIL164_DETECT ; 
 int SIL164_DETECT_HOTPLUG_STAT ; 
 int SIL164_DETECT_INTR_STAT ; 
 int SIL164_DETECT_OUT_MODE_RECEIVER ; 
 int SIL164_DEVICE_HI ; 
 int SIL164_DEVICE_LO ; 
 int SIL164_DUALLINK ; 
 int SIL164_DUALLINK_ENABLE ; 
 int SIL164_DUALLINK_SKEW_SHIFT ; 
 int /*<<< orphan*/  SIL164_I2C_ADDR_SLAVE ; 
 int SIL164_PLLZONE ; 
 int SIL164_REVISION ; 
 int SIL164_VENDOR_HI ; 
 int SIL164_VENDOR_LO ; 
 int connector_status_connected ; 
 int connector_status_disconnected ; 
 int /*<<< orphan*/  drm_i2c_encoder_destroy (struct drm_encoder*) ; 
 struct i2c_client* drm_i2c_encoder_get_client (struct drm_encoder*) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 struct i2c_client* i2c_new_device (struct i2c_adapter*,struct i2c_board_info const*) ; 
 int i2c_transfer (struct i2c_adapter*,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  kfree (struct sil164_priv*) ; 
 struct sil164_priv* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sil164_dbg (struct i2c_client*,char*,...) ; 
 int /*<<< orphan*/  sil164_encoder_funcs ; 
 int /*<<< orphan*/  sil164_err (struct i2c_client*,char*,int,int) ; 
 int /*<<< orphan*/  sil164_info (struct i2c_client*,char*,int,int,int) ; 
 struct sil164_priv* to_sil164_priv (struct drm_encoder*) ; 

__attribute__((used)) static void
sil164_write(struct i2c_client *client, uint8_t addr, uint8_t val)
{
	uint8_t buf[] = {addr, val};
	int ret;

	ret = i2c_master_send(client, buf, ARRAY_SIZE(buf));
	if (ret < 0)
		sil164_err(client, "Error %d writing to subaddress 0x%x\n",
			   ret, addr);
}

__attribute__((used)) static uint8_t
sil164_read(struct i2c_client *client, uint8_t addr)
{
	uint8_t val;
	int ret;

	ret = i2c_master_send(client, &addr, sizeof(addr));
	if (ret < 0)
		goto fail;

	ret = i2c_master_recv(client, &val, sizeof(val));
	if (ret < 0)
		goto fail;

	return val;

fail:
	sil164_err(client, "Error %d reading from subaddress 0x%x\n",
		   ret, addr);
	return 0;
}

__attribute__((used)) static void
sil164_save_state(struct i2c_client *client, uint8_t *state)
{
	int i;

	for (i = 0x8; i <= 0xe; i++)
		state[i] = sil164_read(client, i);
}

__attribute__((used)) static void
sil164_restore_state(struct i2c_client *client, uint8_t *state)
{
	int i;

	for (i = 0x8; i <= 0xe; i++)
		sil164_write(client, i, state[i]);
}

__attribute__((used)) static void
sil164_set_power_state(struct i2c_client *client, bool on)
{
	uint8_t control0 = sil164_read(client, SIL164_CONTROL0);

	if (on)
		control0 |= SIL164_CONTROL0_POWER_ON;
	else
		control0 &= ~SIL164_CONTROL0_POWER_ON;

	sil164_write(client, SIL164_CONTROL0, control0);
}

__attribute__((used)) static void
sil164_init_state(struct i2c_client *client,
		  struct sil164_encoder_params *config,
		  bool duallink)
{
	sil164_write(client, SIL164_CONTROL0,
		     SIL164_CONTROL0_HSYNC_ON |
		     SIL164_CONTROL0_VSYNC_ON |
		     (config->input_edge ? SIL164_CONTROL0_EDGE_RISING : 0) |
		     (config->input_width ? SIL164_CONTROL0_INPUT_24BIT : 0) |
		     (config->input_dual ? SIL164_CONTROL0_DUAL_EDGE : 0));

	sil164_write(client, SIL164_DETECT,
		     SIL164_DETECT_INTR_STAT |
		     SIL164_DETECT_OUT_MODE_RECEIVER);

	sil164_write(client, SIL164_CONTROL1,
		     (config->input_skew ? SIL164_CONTROL1_DESKEW_ENABLE : 0) |
		     (((config->input_skew + 4) & 0x7)
		      << SIL164_CONTROL1_DESKEW_INCR_SHIFT));

	sil164_write(client, SIL164_CONTROL2,
		     SIL164_CONTROL2_SYNC_CONT |
		     (config->pll_filter ? 0 : SIL164_CONTROL2_FILTER_ENABLE) |
		     (4 << SIL164_CONTROL2_FILTER_SETTING_SHIFT));

	sil164_write(client, SIL164_PLLZONE, 0);

	if (duallink)
		sil164_write(client, SIL164_DUALLINK,
			     SIL164_DUALLINK_ENABLE |
			     (((config->duallink_skew + 4) & 0x7)
			      << SIL164_DUALLINK_SKEW_SHIFT));
	else
		sil164_write(client, SIL164_DUALLINK, 0);
}

__attribute__((used)) static void
sil164_encoder_set_config(struct drm_encoder *encoder, void *params)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);

	priv->config = *(struct sil164_encoder_params *)params;
}

__attribute__((used)) static void
sil164_encoder_dpms(struct drm_encoder *encoder, int mode)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);
	bool on = (mode == DRM_MODE_DPMS_ON);
	bool duallink = (on && encoder->crtc->mode.clock > 165000);

	sil164_set_power_state(drm_i2c_encoder_get_client(encoder), on);

	if (priv->duallink_slave)
		sil164_set_power_state(priv->duallink_slave, duallink);
}

__attribute__((used)) static void
sil164_encoder_save(struct drm_encoder *encoder)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);

	sil164_save_state(drm_i2c_encoder_get_client(encoder),
			  priv->saved_state);

	if (priv->duallink_slave)
		sil164_save_state(priv->duallink_slave,
				  priv->saved_slave_state);
}

__attribute__((used)) static void
sil164_encoder_restore(struct drm_encoder *encoder)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);

	sil164_restore_state(drm_i2c_encoder_get_client(encoder),
			     priv->saved_state);

	if (priv->duallink_slave)
		sil164_restore_state(priv->duallink_slave,
				     priv->saved_slave_state);
}

__attribute__((used)) static int
sil164_encoder_mode_valid(struct drm_encoder *encoder,
			  struct drm_display_mode *mode)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);

	if (mode->clock < 32000)
		return MODE_CLOCK_LOW;

	if (mode->clock > 330000 ||
	    (mode->clock > 165000 && !priv->duallink_slave))
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

__attribute__((used)) static void
sil164_encoder_mode_set(struct drm_encoder *encoder,
			struct drm_display_mode *mode,
			struct drm_display_mode *adjusted_mode)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);
	bool duallink = adjusted_mode->clock > 165000;

	sil164_init_state(drm_i2c_encoder_get_client(encoder),
			  &priv->config, duallink);

	if (priv->duallink_slave)
		sil164_init_state(priv->duallink_slave,
				  &priv->config, duallink);

	sil164_encoder_dpms(encoder, DRM_MODE_DPMS_ON);
}

__attribute__((used)) static enum drm_connector_status
sil164_encoder_detect(struct drm_encoder *encoder,
		      struct drm_connector *connector)
{
	struct i2c_client *client = drm_i2c_encoder_get_client(encoder);

	if (sil164_read(client, SIL164_DETECT) & SIL164_DETECT_HOTPLUG_STAT)
		return connector_status_connected;
	else
		return connector_status_disconnected;
}

__attribute__((used)) static int
sil164_encoder_get_modes(struct drm_encoder *encoder,
			 struct drm_connector *connector)
{
	return 0;
}

__attribute__((used)) static int
sil164_encoder_create_resources(struct drm_encoder *encoder,
				struct drm_connector *connector)
{
	return 0;
}

__attribute__((used)) static int
sil164_encoder_set_property(struct drm_encoder *encoder,
			    struct drm_connector *connector,
			    struct drm_property *property,
			    uint64_t val)
{
	return 0;
}

__attribute__((used)) static void
sil164_encoder_destroy(struct drm_encoder *encoder)
{
	struct sil164_priv *priv = to_sil164_priv(encoder);

	i2c_unregister_device(priv->duallink_slave);

	kfree(priv);
	drm_i2c_encoder_destroy(encoder);
}

__attribute__((used)) static int
sil164_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int vendor = sil164_read(client, SIL164_VENDOR_HI) << 8 |
		sil164_read(client, SIL164_VENDOR_LO);
	int device = sil164_read(client, SIL164_DEVICE_HI) << 8 |
		sil164_read(client, SIL164_DEVICE_LO);
	int rev = sil164_read(client, SIL164_REVISION);

	if (vendor != 0x1 || device != 0x6) {
		sil164_dbg(client, "Unknown device %x:%x.%x\n",
			   vendor, device, rev);
		return -ENODEV;
	}

	sil164_info(client, "Detected device %x:%x.%x\n",
		    vendor, device, rev);

	return 0;
}

__attribute__((used)) static int
sil164_remove(struct i2c_client *client)
{
	return 0;
}

__attribute__((used)) static struct i2c_client *
sil164_detect_slave(struct i2c_client *client)
{
	struct i2c_adapter *adap = client->adapter;
	struct i2c_msg msg = {
		.addr = SIL164_I2C_ADDR_SLAVE,
		.len = 0,
	};
	const struct i2c_board_info info = {
		I2C_BOARD_INFO("sil164", SIL164_I2C_ADDR_SLAVE)
	};

	if (i2c_transfer(adap, &msg, 1) != 1) {
		sil164_dbg(adap, "No dual-link slave found.");
		return NULL;
	}

	return i2c_new_device(adap, &info);
}

__attribute__((used)) static int
sil164_encoder_init(struct i2c_client *client,
		    struct drm_device *dev,
		    struct drm_encoder_slave *encoder)
{
	struct sil164_priv *priv;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	encoder->slave_priv = priv;
	encoder->slave_funcs = &sil164_encoder_funcs;

	priv->duallink_slave = sil164_detect_slave(client);

	return 0;
}

