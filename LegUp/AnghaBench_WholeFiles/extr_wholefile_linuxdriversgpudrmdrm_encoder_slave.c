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
struct module {int dummy; } ;
struct TYPE_3__ {TYPE_2__* driver; } ;
struct i2c_client {TYPE_1__ dev; } ;
struct i2c_board_info {scalar_t__ platform_data; int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct drm_i2c_encoder_driver {int (* encoder_init ) (struct i2c_client*,struct drm_device*,struct drm_encoder_slave*) ;} ;
struct drm_encoder_slave_funcs {int (* mode_fixup ) (struct drm_encoder*,struct drm_display_mode const*,struct drm_display_mode*) ;int (* detect ) (struct drm_encoder*,struct drm_connector*) ;int /*<<< orphan*/  (* restore ) (struct drm_encoder*) ;int /*<<< orphan*/  (* save ) (struct drm_encoder*) ;int /*<<< orphan*/  (* mode_set ) (struct drm_encoder*,struct drm_display_mode*,struct drm_display_mode*) ;int /*<<< orphan*/  (* dpms ) (struct drm_encoder*,int) ;int /*<<< orphan*/  (* set_config ) (int /*<<< orphan*/ *,scalar_t__) ;} ;
struct drm_encoder_slave {struct drm_encoder_slave_funcs const* slave_funcs; struct i2c_client* bus_priv; int /*<<< orphan*/  base; } ;
struct drm_encoder {int dummy; } ;
struct drm_display_mode {int dummy; } ;
struct drm_device {int dummy; } ;
struct drm_connector {int dummy; } ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
struct TYPE_4__ {struct module* owner; } ;

/* Variables and functions */
 int DRM_MODE_DPMS_OFF ; 
 int DRM_MODE_DPMS_ON ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  I2C_MODULE_PREFIX ; 
 struct i2c_client* drm_i2c_encoder_get_client (struct drm_encoder*) ; 
 struct i2c_client* i2c_new_device (struct i2c_adapter*,struct i2c_board_info const*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  module_put (struct module*) ; 
 int /*<<< orphan*/  request_module (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (struct i2c_client*,struct drm_device*,struct drm_encoder_slave*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  stub3 (struct drm_encoder*,int) ; 
 int stub4 (struct drm_encoder*,struct drm_display_mode const*,struct drm_display_mode*) ; 
 int /*<<< orphan*/  stub5 (struct drm_encoder*,struct drm_display_mode*,struct drm_display_mode*) ; 
 int stub6 (struct drm_encoder*,struct drm_connector*) ; 
 int /*<<< orphan*/  stub7 (struct drm_encoder*) ; 
 int /*<<< orphan*/  stub8 (struct drm_encoder*) ; 
 struct drm_i2c_encoder_driver* to_drm_i2c_encoder_driver (int /*<<< orphan*/ ) ; 
 struct drm_encoder_slave* to_encoder_slave (struct drm_encoder*) ; 
 int /*<<< orphan*/  to_i2c_driver (TYPE_2__*) ; 
 int /*<<< orphan*/  try_module_get (struct module*) ; 

int drm_i2c_encoder_init(struct drm_device *dev,
			 struct drm_encoder_slave *encoder,
			 struct i2c_adapter *adap,
			 const struct i2c_board_info *info)
{
	struct module *module = NULL;
	struct i2c_client *client;
	struct drm_i2c_encoder_driver *encoder_drv;
	int err = 0;

	request_module("%s%s", I2C_MODULE_PREFIX, info->type);

	client = i2c_new_device(adap, info);
	if (!client) {
		err = -ENOMEM;
		goto fail;
	}

	if (!client->dev.driver) {
		err = -ENODEV;
		goto fail_unregister;
	}

	module = client->dev.driver->owner;
	if (!try_module_get(module)) {
		err = -ENODEV;
		goto fail_unregister;
	}

	encoder->bus_priv = client;

	encoder_drv = to_drm_i2c_encoder_driver(to_i2c_driver(client->dev.driver));

	err = encoder_drv->encoder_init(client, dev, encoder);
	if (err)
		goto fail_unregister;

	if (info->platform_data)
		encoder->slave_funcs->set_config(&encoder->base,
						 info->platform_data);

	return 0;

fail_unregister:
	i2c_unregister_device(client);
	module_put(module);
fail:
	return err;
}

void drm_i2c_encoder_destroy(struct drm_encoder *drm_encoder)
{
	struct drm_encoder_slave *encoder = to_encoder_slave(drm_encoder);
	struct i2c_client *client = drm_i2c_encoder_get_client(drm_encoder);
	struct module *module = client->dev.driver->owner;

	i2c_unregister_device(client);
	encoder->bus_priv = NULL;

	module_put(module);
}

__attribute__((used)) static inline const struct drm_encoder_slave_funcs *
get_slave_funcs(struct drm_encoder *enc)
{
	return to_encoder_slave(enc)->slave_funcs;
}

void drm_i2c_encoder_dpms(struct drm_encoder *encoder, int mode)
{
	get_slave_funcs(encoder)->dpms(encoder, mode);
}

bool drm_i2c_encoder_mode_fixup(struct drm_encoder *encoder,
		const struct drm_display_mode *mode,
		struct drm_display_mode *adjusted_mode)
{
	if (!get_slave_funcs(encoder)->mode_fixup)
		return true;

	return get_slave_funcs(encoder)->mode_fixup(encoder, mode, adjusted_mode);
}

void drm_i2c_encoder_prepare(struct drm_encoder *encoder)
{
	drm_i2c_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);
}

void drm_i2c_encoder_commit(struct drm_encoder *encoder)
{
	drm_i2c_encoder_dpms(encoder, DRM_MODE_DPMS_ON);
}

void drm_i2c_encoder_mode_set(struct drm_encoder *encoder,
		struct drm_display_mode *mode,
		struct drm_display_mode *adjusted_mode)
{
	get_slave_funcs(encoder)->mode_set(encoder, mode, adjusted_mode);
}

enum drm_connector_status drm_i2c_encoder_detect(struct drm_encoder *encoder,
	    struct drm_connector *connector)
{
	return get_slave_funcs(encoder)->detect(encoder, connector);
}

void drm_i2c_encoder_save(struct drm_encoder *encoder)
{
	get_slave_funcs(encoder)->save(encoder);
}

void drm_i2c_encoder_restore(struct drm_encoder *encoder)
{
	get_slave_funcs(encoder)->restore(encoder);
}

