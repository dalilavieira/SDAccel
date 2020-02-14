#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct v4l2_ctrl_ops {int dummy; } ;
struct v4l2_ctrl_handler {int error; } ;
struct TYPE_6__ {int val; } ;
struct v4l2_ctrl {scalar_t__ id; int val; int /*<<< orphan*/  flags; TYPE_1__ cur; } ;
struct lm3560_platform_data {int* max_flash_brt; int* max_torch_brt; int max_flash_timeout; int peak; } ;
struct lm3560_flash {int led_mode; TYPE_2__* subdev_led; struct v4l2_ctrl_handler* ctrls_led; int /*<<< orphan*/  lock; int /*<<< orphan*/ * dev; struct lm3560_platform_data* pdata; int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  int s32 ;
typedef  enum lm3560_led_id { ____Placeholder_lm3560_led_id } lm3560_led_id ;
struct TYPE_8__ {int /*<<< orphan*/  function; } ;
struct TYPE_7__ {TYPE_4__ entity; int /*<<< orphan*/  name; int /*<<< orphan*/  flags; struct v4l2_ctrl_handler* ctrl_handler; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned int FAULT_OVERTEMP ; 
 unsigned int FAULT_SHORT_CIRCUIT ; 
 unsigned int FAULT_TIMEOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 void* LM3560_FLASH_BRT_MAX ; 
 unsigned int LM3560_FLASH_BRT_MIN ; 
 int /*<<< orphan*/  LM3560_FLASH_BRT_STEP ; 
 int LM3560_FLASH_BRT_uA_TO_REG (unsigned int) ; 
 int LM3560_FLASH_TOUT_MAX ; 
 unsigned int LM3560_FLASH_TOUT_MIN ; 
 int /*<<< orphan*/  LM3560_FLASH_TOUT_STEP ; 
 int LM3560_FLASH_TOUT_ms_TO_REG (int) ; 
 int LM3560_LED0 ; 
 size_t LM3560_LED1 ; 
 unsigned int LM3560_LED_MAX ; 
 int LM3560_PEAK_3600mA ; 
 void* LM3560_TORCH_BRT_MAX ; 
 unsigned int LM3560_TORCH_BRT_MIN ; 
 int /*<<< orphan*/  LM3560_TORCH_BRT_STEP ; 
 int LM3560_TORCH_BRT_uA_TO_REG (unsigned int) ; 
 int /*<<< orphan*/  MEDIA_ENT_F_FLASH ; 
 int MODE_FLASH ; 
 int MODE_SHDN ; 
 int MODE_TORCH ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_CONFIG1 ; 
 int /*<<< orphan*/  REG_ENABLE ; 
 int /*<<< orphan*/  REG_FLAG ; 
 int /*<<< orphan*/  REG_FLASH_BR ; 
 int /*<<< orphan*/  REG_FLASH_TOUT ; 
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
 int V4L2_FLASH_FAULT_OVER_TEMPERATURE ; 
 int V4L2_FLASH_FAULT_OVER_VOLTAGE ; 
 int V4L2_FLASH_FAULT_SHORT_CIRCUIT ; 
 int V4L2_FLASH_FAULT_TIMEOUT ; 
#define  V4L2_FLASH_LED_MODE_FLASH 130 
#define  V4L2_FLASH_LED_MODE_NONE 129 
#define  V4L2_FLASH_LED_MODE_TORCH 128 
 int const V4L2_FLASH_STROBE_SOURCE_SOFTWARE ; 
 int /*<<< orphan*/  V4L2_SUBDEV_FL_HAS_DEVNODE ; 
 struct lm3560_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct lm3560_flash* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lm3560_flash*) ; 
 struct v4l2_ctrl_ops* lm3560_led_ctrl_ops ; 
 int /*<<< orphan*/  lm3560_ops ; 
 int /*<<< orphan*/  lm3560_regmap ; 
 int /*<<< orphan*/  media_entity_cleanup (TYPE_4__*) ; 
 int media_entity_pads_init (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 struct i2c_client* to_i2c_client (int /*<<< orphan*/ *) ; 
 struct lm3560_flash* to_lm3560_flash (struct v4l2_ctrl*,int) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_free (struct v4l2_ctrl_handler*) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_init (struct v4l2_ctrl_handler*,int) ; 
 struct v4l2_ctrl* v4l2_ctrl_new_std (struct v4l2_ctrl_handler*,struct v4l2_ctrl_ops const*,int const,unsigned int,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  v4l2_ctrl_new_std_menu (struct v4l2_ctrl_handler*,struct v4l2_ctrl_ops const*,int const,int const,int,int const) ; 
 int /*<<< orphan*/  v4l2_device_unregister_subdev (TYPE_2__*) ; 
 int /*<<< orphan*/  v4l2_i2c_subdev_init (TYPE_2__*,struct i2c_client*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int lm3560_mode_ctrl(struct lm3560_flash *flash)
{
	int rval = -EINVAL;

	switch (flash->led_mode) {
	case V4L2_FLASH_LED_MODE_NONE:
		rval = regmap_update_bits(flash->regmap,
					  REG_ENABLE, 0x03, MODE_SHDN);
		break;
	case V4L2_FLASH_LED_MODE_TORCH:
		rval = regmap_update_bits(flash->regmap,
					  REG_ENABLE, 0x03, MODE_TORCH);
		break;
	case V4L2_FLASH_LED_MODE_FLASH:
		rval = regmap_update_bits(flash->regmap,
					  REG_ENABLE, 0x03, MODE_FLASH);
		break;
	}
	return rval;
}

__attribute__((used)) static int lm3560_enable_ctrl(struct lm3560_flash *flash,
			      enum lm3560_led_id led_no, bool on)
{
	int rval;

	if (led_no == LM3560_LED0) {
		if (on)
			rval = regmap_update_bits(flash->regmap,
						  REG_ENABLE, 0x08, 0x08);
		else
			rval = regmap_update_bits(flash->regmap,
						  REG_ENABLE, 0x08, 0x00);
	} else {
		if (on)
			rval = regmap_update_bits(flash->regmap,
						  REG_ENABLE, 0x10, 0x10);
		else
			rval = regmap_update_bits(flash->regmap,
						  REG_ENABLE, 0x10, 0x00);
	}
	return rval;
}

__attribute__((used)) static int lm3560_torch_brt_ctrl(struct lm3560_flash *flash,
				 enum lm3560_led_id led_no, unsigned int brt)
{
	int rval;
	u8 br_bits;

	if (brt < LM3560_TORCH_BRT_MIN)
		return lm3560_enable_ctrl(flash, led_no, false);
	else
		rval = lm3560_enable_ctrl(flash, led_no, true);

	br_bits = LM3560_TORCH_BRT_uA_TO_REG(brt);
	if (led_no == LM3560_LED0)
		rval = regmap_update_bits(flash->regmap,
					  REG_TORCH_BR, 0x07, br_bits);
	else
		rval = regmap_update_bits(flash->regmap,
					  REG_TORCH_BR, 0x38, br_bits << 3);

	return rval;
}

__attribute__((used)) static int lm3560_flash_brt_ctrl(struct lm3560_flash *flash,
				 enum lm3560_led_id led_no, unsigned int brt)
{
	int rval;
	u8 br_bits;

	if (brt < LM3560_FLASH_BRT_MIN)
		return lm3560_enable_ctrl(flash, led_no, false);
	else
		rval = lm3560_enable_ctrl(flash, led_no, true);

	br_bits = LM3560_FLASH_BRT_uA_TO_REG(brt);
	if (led_no == LM3560_LED0)
		rval = regmap_update_bits(flash->regmap,
					  REG_FLASH_BR, 0x0f, br_bits);
	else
		rval = regmap_update_bits(flash->regmap,
					  REG_FLASH_BR, 0xf0, br_bits << 4);

	return rval;
}

__attribute__((used)) static int lm3560_get_ctrl(struct v4l2_ctrl *ctrl, enum lm3560_led_id led_no)
{
	struct lm3560_flash *flash = to_lm3560_flash(ctrl, led_no);
	int rval = -EINVAL;

	mutex_lock(&flash->lock);

	if (ctrl->id == V4L2_CID_FLASH_FAULT) {
		s32 fault = 0;
		unsigned int reg_val;
		rval = regmap_read(flash->regmap, REG_FLAG, &reg_val);
		if (rval < 0)
			goto out;
		if (reg_val & FAULT_SHORT_CIRCUIT)
			fault |= V4L2_FLASH_FAULT_SHORT_CIRCUIT;
		if (reg_val & FAULT_OVERTEMP)
			fault |= V4L2_FLASH_FAULT_OVER_TEMPERATURE;
		if (reg_val & FAULT_TIMEOUT)
			fault |= V4L2_FLASH_FAULT_TIMEOUT;
		ctrl->cur.val = fault;
	}

out:
	mutex_unlock(&flash->lock);
	return rval;
}

__attribute__((used)) static int lm3560_set_ctrl(struct v4l2_ctrl *ctrl, enum lm3560_led_id led_no)
{
	struct lm3560_flash *flash = to_lm3560_flash(ctrl, led_no);
	u8 tout_bits;
	int rval = -EINVAL;

	mutex_lock(&flash->lock);

	switch (ctrl->id) {
	case V4L2_CID_FLASH_LED_MODE:
		flash->led_mode = ctrl->val;
		if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH)
			rval = lm3560_mode_ctrl(flash);
		break;

	case V4L2_CID_FLASH_STROBE_SOURCE:
		rval = regmap_update_bits(flash->regmap,
					  REG_CONFIG1, 0x04, (ctrl->val) << 2);
		if (rval < 0)
			goto err_out;
		break;

	case V4L2_CID_FLASH_STROBE:
		if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH) {
			rval = -EBUSY;
			goto err_out;
		}
		flash->led_mode = V4L2_FLASH_LED_MODE_FLASH;
		rval = lm3560_mode_ctrl(flash);
		break;

	case V4L2_CID_FLASH_STROBE_STOP:
		if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH) {
			rval = -EBUSY;
			goto err_out;
		}
		flash->led_mode = V4L2_FLASH_LED_MODE_NONE;
		rval = lm3560_mode_ctrl(flash);
		break;

	case V4L2_CID_FLASH_TIMEOUT:
		tout_bits = LM3560_FLASH_TOUT_ms_TO_REG(ctrl->val);
		rval = regmap_update_bits(flash->regmap,
					  REG_FLASH_TOUT, 0x1f, tout_bits);
		break;

	case V4L2_CID_FLASH_INTENSITY:
		rval = lm3560_flash_brt_ctrl(flash, led_no, ctrl->val);
		break;

	case V4L2_CID_FLASH_TORCH_INTENSITY:
		rval = lm3560_torch_brt_ctrl(flash, led_no, ctrl->val);
		break;
	}

err_out:
	mutex_unlock(&flash->lock);
	return rval;
}

__attribute__((used)) static int lm3560_led1_get_ctrl(struct v4l2_ctrl *ctrl)
{
	return lm3560_get_ctrl(ctrl, LM3560_LED1);
}

__attribute__((used)) static int lm3560_led1_set_ctrl(struct v4l2_ctrl *ctrl)
{
	return lm3560_set_ctrl(ctrl, LM3560_LED1);
}

__attribute__((used)) static int lm3560_led0_get_ctrl(struct v4l2_ctrl *ctrl)
{
	return lm3560_get_ctrl(ctrl, LM3560_LED0);
}

__attribute__((used)) static int lm3560_led0_set_ctrl(struct v4l2_ctrl *ctrl)
{
	return lm3560_set_ctrl(ctrl, LM3560_LED0);
}

__attribute__((used)) static int lm3560_init_controls(struct lm3560_flash *flash,
				enum lm3560_led_id led_no)
{
	struct v4l2_ctrl *fault;
	u32 max_flash_brt = flash->pdata->max_flash_brt[led_no];
	u32 max_torch_brt = flash->pdata->max_torch_brt[led_no];
	struct v4l2_ctrl_handler *hdl = &flash->ctrls_led[led_no];
	const struct v4l2_ctrl_ops *ops = &lm3560_led_ctrl_ops[led_no];

	v4l2_ctrl_handler_init(hdl, 8);

	/* flash mode */
	v4l2_ctrl_new_std_menu(hdl, ops, V4L2_CID_FLASH_LED_MODE,
			       V4L2_FLASH_LED_MODE_TORCH, ~0x7,
			       V4L2_FLASH_LED_MODE_NONE);
	flash->led_mode = V4L2_FLASH_LED_MODE_NONE;

	/* flash source */
	v4l2_ctrl_new_std_menu(hdl, ops, V4L2_CID_FLASH_STROBE_SOURCE,
			       0x1, ~0x3, V4L2_FLASH_STROBE_SOURCE_SOFTWARE);

	/* flash strobe */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_STROBE, 0, 0, 0, 0);

	/* flash strobe stop */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_STROBE_STOP, 0, 0, 0, 0);

	/* flash strobe timeout */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_TIMEOUT,
			  LM3560_FLASH_TOUT_MIN,
			  flash->pdata->max_flash_timeout,
			  LM3560_FLASH_TOUT_STEP,
			  flash->pdata->max_flash_timeout);

	/* flash brt */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_INTENSITY,
			  LM3560_FLASH_BRT_MIN, max_flash_brt,
			  LM3560_FLASH_BRT_STEP, max_flash_brt);

	/* torch brt */
	v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_TORCH_INTENSITY,
			  LM3560_TORCH_BRT_MIN, max_torch_brt,
			  LM3560_TORCH_BRT_STEP, max_torch_brt);

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

	flash->subdev_led[led_no].ctrl_handler = hdl;
	return 0;
}

__attribute__((used)) static int lm3560_subdev_init(struct lm3560_flash *flash,
			      enum lm3560_led_id led_no, char *led_name)
{
	struct i2c_client *client = to_i2c_client(flash->dev);
	int rval;

	v4l2_i2c_subdev_init(&flash->subdev_led[led_no], client, &lm3560_ops);
	flash->subdev_led[led_no].flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	strcpy(flash->subdev_led[led_no].name, led_name);
	rval = lm3560_init_controls(flash, led_no);
	if (rval)
		goto err_out;
	rval = media_entity_pads_init(&flash->subdev_led[led_no].entity, 0, NULL);
	if (rval < 0)
		goto err_out;
	flash->subdev_led[led_no].entity.function = MEDIA_ENT_F_FLASH;

	return rval;

err_out:
	v4l2_ctrl_handler_free(&flash->ctrls_led[led_no]);
	return rval;
}

__attribute__((used)) static int lm3560_init_device(struct lm3560_flash *flash)
{
	int rval;
	unsigned int reg_val;

	/* set peak current */
	rval = regmap_update_bits(flash->regmap,
				  REG_FLASH_TOUT, 0x60, flash->pdata->peak);
	if (rval < 0)
		return rval;
	/* output disable */
	flash->led_mode = V4L2_FLASH_LED_MODE_NONE;
	rval = lm3560_mode_ctrl(flash);
	if (rval < 0)
		return rval;
	/* reset faults */
	rval = regmap_read(flash->regmap, REG_FLAG, &reg_val);
	return rval;
}

__attribute__((used)) static int lm3560_probe(struct i2c_client *client,
			const struct i2c_device_id *devid)
{
	struct lm3560_flash *flash;
	struct lm3560_platform_data *pdata = dev_get_platdata(&client->dev);
	int rval;

	flash = devm_kzalloc(&client->dev, sizeof(*flash), GFP_KERNEL);
	if (flash == NULL)
		return -ENOMEM;

	flash->regmap = devm_regmap_init_i2c(client, &lm3560_regmap);
	if (IS_ERR(flash->regmap)) {
		rval = PTR_ERR(flash->regmap);
		return rval;
	}

	/* if there is no platform data, use chip default value */
	if (pdata == NULL) {
		pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
		if (pdata == NULL)
			return -ENODEV;
		pdata->peak = LM3560_PEAK_3600mA;
		pdata->max_flash_timeout = LM3560_FLASH_TOUT_MAX;
		/* led 1 */
		pdata->max_flash_brt[LM3560_LED0] = LM3560_FLASH_BRT_MAX;
		pdata->max_torch_brt[LM3560_LED0] = LM3560_TORCH_BRT_MAX;
		/* led 2 */
		pdata->max_flash_brt[LM3560_LED1] = LM3560_FLASH_BRT_MAX;
		pdata->max_torch_brt[LM3560_LED1] = LM3560_TORCH_BRT_MAX;
	}
	flash->pdata = pdata;
	flash->dev = &client->dev;
	mutex_init(&flash->lock);

	rval = lm3560_subdev_init(flash, LM3560_LED0, "lm3560-led0");
	if (rval < 0)
		return rval;

	rval = lm3560_subdev_init(flash, LM3560_LED1, "lm3560-led1");
	if (rval < 0)
		return rval;

	rval = lm3560_init_device(flash);
	if (rval < 0)
		return rval;

	i2c_set_clientdata(client, flash);

	return 0;
}

__attribute__((used)) static int lm3560_remove(struct i2c_client *client)
{
	struct lm3560_flash *flash = i2c_get_clientdata(client);
	unsigned int i;

	for (i = LM3560_LED0; i < LM3560_LED_MAX; i++) {
		v4l2_device_unregister_subdev(&flash->subdev_led[i]);
		v4l2_ctrl_handler_free(&flash->ctrls_led[i]);
		media_entity_cleanup(&flash->subdev_led[i].entity);
	}

	return 0;
}

