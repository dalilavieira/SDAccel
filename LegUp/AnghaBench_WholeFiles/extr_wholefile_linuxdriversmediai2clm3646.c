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
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct v4l2_ctrl_ops {int dummy; } ;
struct v4l2_ctrl_handler {int error; } ;
struct v4l2_ctrl {scalar_t__ id; int val; int /*<<< orphan*/  flags; } ;
struct lm3646_platform_data {int flash_timeout; int /*<<< orphan*/  led1_flash_brt; int /*<<< orphan*/  led1_torch_brt; } ;
struct TYPE_6__ {int /*<<< orphan*/  function; } ;
struct TYPE_5__ {TYPE_3__ entity; int /*<<< orphan*/  name; int /*<<< orphan*/  flags; struct v4l2_ctrl_handler* ctrl_handler; } ;
struct lm3646_flash {unsigned int mode_reg; TYPE_1__ subdev_led; struct v4l2_ctrl_handler ctrls_led; int /*<<< orphan*/ * dev; struct lm3646_platform_data* pdata; int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum v4l2_flash_led_mode { ____Placeholder_v4l2_flash_led_mode } v4l2_flash_led_mode ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 unsigned int FAULT_IVFM ; 
 unsigned int FAULT_NTC_TRIP ; 
 unsigned int FAULT_OCP ; 
 unsigned int FAULT_OVERTEMP ; 
 unsigned int FAULT_OVP ; 
 unsigned int FAULT_SHORT_CIRCUIT ; 
 unsigned int FAULT_TIMEOUT ; 
 unsigned int FAULT_UVLO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int LM3646_FLASH_TOUT_MAX ; 
 int /*<<< orphan*/  LM3646_FLASH_TOUT_MIN ; 
 int /*<<< orphan*/  LM3646_FLASH_TOUT_STEP ; 
 int LM3646_FLASH_TOUT_ms_TO_REG (int) ; 
 int /*<<< orphan*/  LM3646_LED1_FLASH_BRT_MAX ; 
 int LM3646_LED1_FLASH_BRT_uA_TO_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LM3646_LED1_TORCH_BRT_MAX ; 
 int LM3646_LED1_TORCH_BRT_uA_TO_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LM3646_NAME ; 
 int LM3646_TOTAL_FLASH_BRT_MAX ; 
 int /*<<< orphan*/  LM3646_TOTAL_FLASH_BRT_MIN ; 
 int /*<<< orphan*/  LM3646_TOTAL_FLASH_BRT_STEP ; 
 int LM3646_TOTAL_FLASH_BRT_uA_TO_REG (int) ; 
 int LM3646_TOTAL_TORCH_BRT_MAX ; 
 int /*<<< orphan*/  LM3646_TOTAL_TORCH_BRT_MIN ; 
 int /*<<< orphan*/  LM3646_TOTAL_TORCH_BRT_STEP ; 
 int LM3646_TOTAL_TORCH_BRT_uA_TO_REG (int) ; 
 unsigned int MASK_ENABLE ; 
 int MASK_FLASH_BR ; 
 int MASK_FLASH_TOUT ; 
 int MASK_STROBE_SRC ; 
 int MASK_TORCH_BR ; 
 int /*<<< orphan*/  MEDIA_ENT_F_FLASH ; 
 unsigned int MODE_FLASH ; 
 unsigned int MODE_SHDN ; 
 unsigned int MODE_TORCH ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_ENABLE ; 
 int /*<<< orphan*/  REG_FLAG ; 
 int /*<<< orphan*/  REG_FLASH_BR ; 
 int /*<<< orphan*/  REG_FLASH_TOUT ; 
 int /*<<< orphan*/  REG_LED1_FLASH_BR ; 
 int /*<<< orphan*/  REG_LED1_TORCH_BR ; 
 int /*<<< orphan*/  REG_STROBE_SRC ; 
 int /*<<< orphan*/  REG_TORCH_BR ; 
 scalar_t__ V4L2_CID_FLASH_FAULT ; 
#define  V4L2_CID_FLASH_INTENSITY 137 
#define  V4L2_CID_FLASH_LED_MODE 136 
#define  V4L2_CID_FLASH_STROBE 135 
#define  V4L2_CID_FLASH_STROBE_SOURCE 134 
#define  V4L2_CID_FLASH_STROBE_STOP 133 
#define  V4L2_CID_FLASH_TIMEOUT 132 
#define  V4L2_CID_FLASH_TORCH_INTENSITY 131 
 int /*<<< orphan*/  V4L2_CTRL_FLAG_VOLATILE ; 
 int V4L2_FLASH_FAULT_INPUT_VOLTAGE ; 
 int V4L2_FLASH_FAULT_LED_OVER_TEMPERATURE ; 
 int V4L2_FLASH_FAULT_OVER_CURRENT ; 
 int V4L2_FLASH_FAULT_OVER_TEMPERATURE ; 
 int V4L2_FLASH_FAULT_OVER_VOLTAGE ; 
 int V4L2_FLASH_FAULT_SHORT_CIRCUIT ; 
 int V4L2_FLASH_FAULT_TIMEOUT ; 
 int V4L2_FLASH_FAULT_UNDER_VOLTAGE ; 
#define  V4L2_FLASH_LED_MODE_FLASH 130 
#define  V4L2_FLASH_LED_MODE_NONE 129 
#define  V4L2_FLASH_LED_MODE_TORCH 128 
 int const V4L2_FLASH_STROBE_SOURCE_SOFTWARE ; 
 int /*<<< orphan*/  V4L2_SUBDEV_FL_HAS_DEVNODE ; 
 struct lm3646_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct lm3646_flash* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lm3646_flash*) ; 
 struct v4l2_ctrl_ops lm3646_led_ctrl_ops ; 
 int /*<<< orphan*/  lm3646_ops ; 
 int /*<<< orphan*/  lm3646_regmap ; 
 int /*<<< orphan*/  media_entity_cleanup (TYPE_3__*) ; 
 int media_entity_pads_init (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct i2c_client* to_i2c_client (int /*<<< orphan*/ *) ; 
 struct lm3646_flash* to_lm3646_flash (struct v4l2_ctrl*) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_free (struct v4l2_ctrl_handler*) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_init (struct v4l2_ctrl_handler*,int) ; 
 struct v4l2_ctrl* v4l2_ctrl_new_std (struct v4l2_ctrl_handler*,struct v4l2_ctrl_ops const*,int const,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  v4l2_ctrl_new_std_menu (struct v4l2_ctrl_handler*,struct v4l2_ctrl_ops const*,int const,int const,int,int const) ; 
 int /*<<< orphan*/  v4l2_device_unregister_subdev (TYPE_1__*) ; 
 int /*<<< orphan*/  v4l2_i2c_subdev_init (TYPE_1__*,struct i2c_client*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int lm3646_mode_ctrl(struct lm3646_flash *flash,
			    enum v4l2_flash_led_mode led_mode)
{
	switch (led_mode) {
	case V4L2_FLASH_LED_MODE_NONE:
		return regmap_write(flash->regmap,
				    REG_ENABLE, flash->mode_reg | MODE_SHDN);
	case V4L2_FLASH_LED_MODE_TORCH:
		return regmap_write(flash->regmap,
				    REG_ENABLE, flash->mode_reg | MODE_TORCH);
	case V4L2_FLASH_LED_MODE_FLASH:
		return regmap_write(flash->regmap,
				    REG_ENABLE, flash->mode_reg | MODE_FLASH);
	}
	return -EINVAL;
}

__attribute__((used)) static int lm3646_get_ctrl(struct v4l2_ctrl *ctrl)
{
	struct lm3646_flash *flash = to_lm3646_flash(ctrl);
	unsigned int reg_val;
	int rval;

	if (ctrl->id != V4L2_CID_FLASH_FAULT)
		return -EINVAL;

	rval = regmap_read(flash->regmap, REG_FLAG, &reg_val);
	if (rval < 0)
		return rval;

	ctrl->val = 0;
	if (reg_val & FAULT_TIMEOUT)
		ctrl->val |= V4L2_FLASH_FAULT_TIMEOUT;
	if (reg_val & FAULT_SHORT_CIRCUIT)
		ctrl->val |= V4L2_FLASH_FAULT_SHORT_CIRCUIT;
	if (reg_val & FAULT_UVLO)
		ctrl->val |= V4L2_FLASH_FAULT_UNDER_VOLTAGE;
	if (reg_val & FAULT_IVFM)
		ctrl->val |= V4L2_FLASH_FAULT_INPUT_VOLTAGE;
	if (reg_val & FAULT_OCP)
		ctrl->val |= V4L2_FLASH_FAULT_OVER_CURRENT;
	if (reg_val & FAULT_OVERTEMP)
		ctrl->val |= V4L2_FLASH_FAULT_OVER_TEMPERATURE;
	if (reg_val & FAULT_NTC_TRIP)
		ctrl->val |= V4L2_FLASH_FAULT_LED_OVER_TEMPERATURE;
	if (reg_val & FAULT_OVP)
		ctrl->val |= V4L2_FLASH_FAULT_OVER_VOLTAGE;

	return 0;
}

__attribute__((used)) static int lm3646_set_ctrl(struct v4l2_ctrl *ctrl)
{
	struct lm3646_flash *flash = to_lm3646_flash(ctrl);
	unsigned int reg_val;
	int rval = -EINVAL;

	switch (ctrl->id) {
	case V4L2_CID_FLASH_LED_MODE:

		if (ctrl->val != V4L2_FLASH_LED_MODE_FLASH)
			return lm3646_mode_ctrl(flash, ctrl->val);
		/* switch to SHDN mode before flash strobe on */
		return lm3646_mode_ctrl(flash, V4L2_FLASH_LED_MODE_NONE);

	case V4L2_CID_FLASH_STROBE_SOURCE:
		return regmap_update_bits(flash->regmap,
					  REG_STROBE_SRC, MASK_STROBE_SRC,
					  (ctrl->val) << 7);

	case V4L2_CID_FLASH_STROBE:

		/* read and check current mode of chip to start flash */
		rval = regmap_read(flash->regmap, REG_ENABLE, &reg_val);
		if (rval < 0 || ((reg_val & MASK_ENABLE) != MODE_SHDN))
			return rval;
		/* flash on */
		return lm3646_mode_ctrl(flash, V4L2_FLASH_LED_MODE_FLASH);

	case V4L2_CID_FLASH_STROBE_STOP:

		/*
		 * flash mode will be turned automatically
		 * from FLASH mode to SHDN mode after flash duration timeout
		 * read and check current mode of chip to stop flash
		 */
		rval = regmap_read(flash->regmap, REG_ENABLE, &reg_val);
		if (rval < 0)
			return rval;
		if ((reg_val & MASK_ENABLE) == MODE_FLASH)
			return lm3646_mode_ctrl(flash,
						V4L2_FLASH_LED_MODE_NONE);
		return rval;

	case V4L2_CID_FLASH_TIMEOUT:
		return regmap_update_bits(flash->regmap,
					  REG_FLASH_TOUT, MASK_FLASH_TOUT,
					  LM3646_FLASH_TOUT_ms_TO_REG
					  (ctrl->val));

	case V4L2_CID_FLASH_INTENSITY:
		return regmap_update_bits(flash->regmap,
					  REG_FLASH_BR, MASK_FLASH_BR,
					  LM3646_TOTAL_FLASH_BRT_uA_TO_REG
					  (ctrl->val));

	case V4L2_CID_FLASH_TORCH_INTENSITY:
		return regmap_update_bits(flash->regmap,
					  REG_TORCH_BR, MASK_TORCH_BR,
					  LM3646_TOTAL_TORCH_BRT_uA_TO_REG
					  (ctrl->val) << 4);
	}

	return -EINVAL;
}

__attribute__((used)) static int lm3646_init_controls(struct lm3646_flash *flash)
{
	struct v4l2_ctrl *fault;
	struct v4l2_ctrl_handler *hdl = &flash->ctrls_led;
	const struct v4l2_ctrl_ops *ops = &lm3646_led_ctrl_ops;

	v4l2_ctrl_handler_init(hdl, 8);
	/* flash mode */
	v4l2_ctrl_new_std_menu(hdl, ops, V4L2_CID_FLASH_LED_MODE,
			       V4L2_FLASH_LED_MODE_TORCH, ~0x7,
			       V4L2_FLASH_LED_MODE_NONE);

	/* flash source */
	v4l2_ctrl_new_std_menu(hdl, ops, V4L2_CID_FLASH_STROBE_SOURCE,
			       0x1, ~0x3, V4L2_FLASH_STROBE_SOURCE_SOFTWARE);

	/* flash strobe */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_STROBE, 0, 0, 0, 0);
	/* flash strobe stop */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_STROBE_STOP, 0, 0, 0, 0);

	/* flash strobe timeout */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_TIMEOUT,
			  LM3646_FLASH_TOUT_MIN,
			  LM3646_FLASH_TOUT_MAX,
			  LM3646_FLASH_TOUT_STEP, flash->pdata->flash_timeout);

	/* max flash current */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_INTENSITY,
			  LM3646_TOTAL_FLASH_BRT_MIN,
			  LM3646_TOTAL_FLASH_BRT_MAX,
			  LM3646_TOTAL_FLASH_BRT_STEP,
			  LM3646_TOTAL_FLASH_BRT_MAX);

	/* max torch current */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_TORCH_INTENSITY,
			  LM3646_TOTAL_TORCH_BRT_MIN,
			  LM3646_TOTAL_TORCH_BRT_MAX,
			  LM3646_TOTAL_TORCH_BRT_STEP,
			  LM3646_TOTAL_TORCH_BRT_MAX);

	/* fault */
	fault = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_FAULT, 0,
				  V4L2_FLASH_FAULT_OVER_VOLTAGE
				  | V4L2_FLASH_FAULT_OVER_TEMPERATURE
				  | V4L2_FLASH_FAULT_SHORT_CIRCUIT
				  | V4L2_FLASH_FAULT_TIMEOUT, 0, 0);
	if (fault != NULL)
		fault->flags |= V4L2_CTRL_FLAG_VOLATILE;

	if (hdl->error)
		return hdl->error;

	flash->subdev_led.ctrl_handler = hdl;
	return 0;
}

__attribute__((used)) static int lm3646_subdev_init(struct lm3646_flash *flash)
{
	struct i2c_client *client = to_i2c_client(flash->dev);
	int rval;

	v4l2_i2c_subdev_init(&flash->subdev_led, client, &lm3646_ops);
	flash->subdev_led.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	strcpy(flash->subdev_led.name, LM3646_NAME);
	rval = lm3646_init_controls(flash);
	if (rval)
		goto err_out;
	rval = media_entity_pads_init(&flash->subdev_led.entity, 0, NULL);
	if (rval < 0)
		goto err_out;
	flash->subdev_led.entity.function = MEDIA_ENT_F_FLASH;
	return rval;

err_out:
	v4l2_ctrl_handler_free(&flash->ctrls_led);
	return rval;
}

__attribute__((used)) static int lm3646_init_device(struct lm3646_flash *flash)
{
	unsigned int reg_val;
	int rval;

	/* read the value of mode register to reduce redundant i2c accesses */
	rval = regmap_read(flash->regmap, REG_ENABLE, &reg_val);
	if (rval < 0)
		return rval;
	flash->mode_reg = reg_val & 0xfc;

	/* output disable */
	rval = lm3646_mode_ctrl(flash, V4L2_FLASH_LED_MODE_NONE);
	if (rval < 0)
		return rval;

	/*
	 * LED1 flash current setting
	 * LED2 flash current = Total(Max) flash current - LED1 flash current
	 */
	rval = regmap_update_bits(flash->regmap,
				  REG_LED1_FLASH_BR, 0x7F,
				  LM3646_LED1_FLASH_BRT_uA_TO_REG
				  (flash->pdata->led1_flash_brt));

	if (rval < 0)
		return rval;

	/*
	 * LED1 torch current setting
	 * LED2 torch current = Total(Max) torch current - LED1 torch current
	 */
	rval = regmap_update_bits(flash->regmap,
				  REG_LED1_TORCH_BR, 0x7F,
				  LM3646_LED1_TORCH_BRT_uA_TO_REG
				  (flash->pdata->led1_torch_brt));
	if (rval < 0)
		return rval;

	/* Reset flag register */
	return regmap_read(flash->regmap, REG_FLAG, &reg_val);
}

__attribute__((used)) static int lm3646_probe(struct i2c_client *client,
			const struct i2c_device_id *devid)
{
	struct lm3646_flash *flash;
	struct lm3646_platform_data *pdata = dev_get_platdata(&client->dev);
	int rval;

	flash = devm_kzalloc(&client->dev, sizeof(*flash), GFP_KERNEL);
	if (flash == NULL)
		return -ENOMEM;

	flash->regmap = devm_regmap_init_i2c(client, &lm3646_regmap);
	if (IS_ERR(flash->regmap))
		return PTR_ERR(flash->regmap);

	/* check device tree if there is no platform data */
	if (pdata == NULL) {
		pdata = devm_kzalloc(&client->dev,
				     sizeof(struct lm3646_platform_data),
				     GFP_KERNEL);
		if (pdata == NULL)
			return -ENOMEM;
		/* use default data in case of no platform data */
		pdata->flash_timeout = LM3646_FLASH_TOUT_MAX;
		pdata->led1_torch_brt = LM3646_LED1_TORCH_BRT_MAX;
		pdata->led1_flash_brt = LM3646_LED1_FLASH_BRT_MAX;
	}
	flash->pdata = pdata;
	flash->dev = &client->dev;

	rval = lm3646_subdev_init(flash);
	if (rval < 0)
		return rval;

	rval = lm3646_init_device(flash);
	if (rval < 0)
		return rval;

	i2c_set_clientdata(client, flash);

	return 0;
}

__attribute__((used)) static int lm3646_remove(struct i2c_client *client)
{
	struct lm3646_flash *flash = i2c_get_clientdata(client);

	v4l2_device_unregister_subdev(&flash->subdev_led);
	v4l2_ctrl_handler_free(&flash->ctrls_led);
	media_entity_cleanup(&flash->subdev_led.entity);

	return 0;
}

