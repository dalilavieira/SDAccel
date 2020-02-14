#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct i2c_device_id {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct i2c_client {struct device dev; int /*<<< orphan*/  adapter; } ;
struct device_node {int dummy; } ;
struct backlight_properties {scalar_t__ max_brightness; scalar_t__ brightness; int /*<<< orphan*/  type; } ;
struct TYPE_8__ {int brightness; int state; scalar_t__ power; } ;
struct backlight_device {TYPE_2__ props; } ;
struct arcxcnn {TYPE_3__* bl; struct i2c_client* client; struct device* dev; TYPE_4__* pdata; } ;
struct TYPE_10__ {scalar_t__ initial_brightness; int led_config_0; int led_config_1; int dim_freq; int comp_config; int filter_config; int trim_config; int leden; int /*<<< orphan*/ * name; } ;
struct TYPE_7__ {scalar_t__ brightness; } ;
struct TYPE_9__ {TYPE_1__ props; } ;

/* Variables and functions */
 int ARCXCNN_CMD ; 
 int ARCXCNN_CMD_RESET ; 
 int ARCXCNN_CMD_STDBY ; 
 int ARCXCNN_COMP_CONFIG ; 
 int ARCXCNN_DIMFREQ ; 
 int ARCXCNN_FADECTRL ; 
 int ARCXCNN_FILT_CONFIG ; 
 int ARCXCNN_ILED_CONFIG ; 
 int ARCXCNN_ILED_DIM_INT ; 
 int ARCXCNN_IMAXTUNE ; 
 int ARCXCNN_LEDEN ; 
 int ARCXCNN_LEDEN_BITS ; 
 void* ARCXCNN_LEDEN_MASK ; 
 int ARCXCNN_WLED_ISET_LSB ; 
 int ARCXCNN_WLED_ISET_LSB_SHIFT ; 
 int ARCXCNN_WLED_ISET_MSB ; 
 int /*<<< orphan*/  BACKLIGHT_PLATFORM ; 
 int BL_CORE_FBBLANK ; 
 int BL_CORE_SUSPENDED ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int INIT_BRIGHT ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ MAX_BRIGHTNESS ; 
 int PTR_ERR_OR_ZERO (TYPE_3__*) ; 
 int /*<<< orphan*/  arcxcnn_bl_ops ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_3__*) ; 
 struct arcxcnn* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 TYPE_4__* dev_get_platdata (struct device*) ; 
 TYPE_3__* devm_backlight_device_register (struct device*,char const*,struct device*,struct arcxcnn*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct arcxcnn* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct arcxcnn*) ; 
 void* i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int of_property_count_u32_elems (struct device_node*,char*) ; 
 int of_property_read_string (struct device_node*,char*,int /*<<< orphan*/ **) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 int of_property_read_u32_array (struct device_node*,char*,int*,int) ; 

__attribute__((used)) static int arcxcnn_update_field(struct arcxcnn *lp, u8 reg, u8 mask, u8 data)
{
	int ret;
	u8 tmp;

	ret = i2c_smbus_read_byte_data(lp->client, reg);
	if (ret < 0) {
		dev_err(lp->dev, "failed to read 0x%.2x\n", reg);
		return ret;
	}

	tmp = (u8)ret;
	tmp &= ~mask;
	tmp |= data & mask;

	return i2c_smbus_write_byte_data(lp->client, reg, tmp);
}

__attribute__((used)) static int arcxcnn_set_brightness(struct arcxcnn *lp, u32 brightness)
{
	int ret;
	u8 val;

	/* lower nibble of brightness goes in upper nibble of LSB register */
	val = (brightness & 0xF) << ARCXCNN_WLED_ISET_LSB_SHIFT;
	ret = i2c_smbus_write_byte_data(lp->client,
		ARCXCNN_WLED_ISET_LSB, val);
	if (ret < 0)
		return ret;

	/* remaining 8 bits of brightness go in MSB register */
	val = (brightness >> 4);
	return i2c_smbus_write_byte_data(lp->client,
		ARCXCNN_WLED_ISET_MSB, val);
}

__attribute__((used)) static int arcxcnn_bl_update_status(struct backlight_device *bl)
{
	struct arcxcnn *lp = bl_get_data(bl);
	u32 brightness = bl->props.brightness;
	int ret;

	if (bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
		brightness = 0;

	ret = arcxcnn_set_brightness(lp, brightness);
	if (ret)
		return ret;

	/* set power-on/off/save modes */
	return arcxcnn_update_field(lp, ARCXCNN_CMD, ARCXCNN_CMD_STDBY,
		(bl->props.power == 0) ? 0 : ARCXCNN_CMD_STDBY);
}

__attribute__((used)) static int arcxcnn_backlight_register(struct arcxcnn *lp)
{
	struct backlight_properties *props;
	const char *name = lp->pdata->name ? : "arctic_bl";

	props = devm_kzalloc(lp->dev, sizeof(*props), GFP_KERNEL);
	if (!props)
		return -ENOMEM;

	props->type = BACKLIGHT_PLATFORM;
	props->max_brightness = MAX_BRIGHTNESS;

	if (lp->pdata->initial_brightness > props->max_brightness)
		lp->pdata->initial_brightness = props->max_brightness;

	props->brightness = lp->pdata->initial_brightness;

	lp->bl = devm_backlight_device_register(lp->dev, name, lp->dev, lp,
				       &arcxcnn_bl_ops, props);
	return PTR_ERR_OR_ZERO(lp->bl);
}

__attribute__((used)) static void arcxcnn_parse_dt(struct arcxcnn *lp)
{
	struct device *dev = lp->dev;
	struct device_node *node = dev->of_node;
	u32 prog_val, num_entry, entry, sources[ARCXCNN_LEDEN_BITS];
	int ret;

	/* device tree entry isn't required, defaults are OK */
	if (!node)
		return;

	ret = of_property_read_string(node, "label", &lp->pdata->name);
	if (ret < 0)
		lp->pdata->name = NULL;

	ret = of_property_read_u32(node, "default-brightness", &prog_val);
	if (ret == 0)
		lp->pdata->initial_brightness = prog_val;

	ret = of_property_read_u32(node, "arc,led-config-0", &prog_val);
	if (ret == 0)
		lp->pdata->led_config_0 = (u8)prog_val;

	ret = of_property_read_u32(node, "arc,led-config-1", &prog_val);
	if (ret == 0)
		lp->pdata->led_config_1 = (u8)prog_val;

	ret = of_property_read_u32(node, "arc,dim-freq", &prog_val);
	if (ret == 0)
		lp->pdata->dim_freq = (u8)prog_val;

	ret = of_property_read_u32(node, "arc,comp-config", &prog_val);
	if (ret == 0)
		lp->pdata->comp_config = (u8)prog_val;

	ret = of_property_read_u32(node, "arc,filter-config", &prog_val);
	if (ret == 0)
		lp->pdata->filter_config = (u8)prog_val;

	ret = of_property_read_u32(node, "arc,trim-config", &prog_val);
	if (ret == 0)
		lp->pdata->trim_config = (u8)prog_val;

	ret = of_property_count_u32_elems(node, "led-sources");
	if (ret < 0) {
		lp->pdata->leden = ARCXCNN_LEDEN_MASK; /* all on is default */
	} else {
		num_entry = ret;
		if (num_entry > ARCXCNN_LEDEN_BITS)
			num_entry = ARCXCNN_LEDEN_BITS;

		ret = of_property_read_u32_array(node, "led-sources", sources,
					num_entry);
		if (ret < 0) {
			dev_err(dev, "led-sources node is invalid.\n");
			return;
		}

		lp->pdata->leden = 0;

		/* for each enable in source, set bit in led enable */
		for (entry = 0; entry < num_entry; entry++) {
			u8 onbit = 1 << sources[entry];

			lp->pdata->leden |= onbit;
		}
	}
}

__attribute__((used)) static int arcxcnn_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
	struct arcxcnn *lp;
	int ret;

	if (!i2c_check_functionality(cl->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -EIO;

	lp = devm_kzalloc(&cl->dev, sizeof(*lp), GFP_KERNEL);
	if (!lp)
		return -ENOMEM;

	lp->client = cl;
	lp->dev = &cl->dev;
	lp->pdata = dev_get_platdata(&cl->dev);

	/* reset the device */
	ret = i2c_smbus_write_byte_data(lp->client,
		ARCXCNN_CMD, ARCXCNN_CMD_RESET);
	if (ret)
		goto probe_err;

	if (!lp->pdata) {
		lp->pdata = devm_kzalloc(lp->dev,
				sizeof(*lp->pdata), GFP_KERNEL);
		if (!lp->pdata)
			return -ENOMEM;

		/* Setup defaults based on power-on defaults */
		lp->pdata->name = NULL;
		lp->pdata->initial_brightness = INIT_BRIGHT;
		lp->pdata->leden = ARCXCNN_LEDEN_MASK;

		lp->pdata->led_config_0 = i2c_smbus_read_byte_data(
			lp->client, ARCXCNN_FADECTRL);

		lp->pdata->led_config_1 = i2c_smbus_read_byte_data(
			lp->client, ARCXCNN_ILED_CONFIG);
		/* insure dim mode is not default pwm */
		lp->pdata->led_config_1 |= ARCXCNN_ILED_DIM_INT;

		lp->pdata->dim_freq = i2c_smbus_read_byte_data(
			lp->client, ARCXCNN_DIMFREQ);

		lp->pdata->comp_config = i2c_smbus_read_byte_data(
			lp->client, ARCXCNN_COMP_CONFIG);

		lp->pdata->filter_config = i2c_smbus_read_byte_data(
			lp->client, ARCXCNN_FILT_CONFIG);

		lp->pdata->trim_config = i2c_smbus_read_byte_data(
			lp->client, ARCXCNN_IMAXTUNE);

		if (IS_ENABLED(CONFIG_OF))
			arcxcnn_parse_dt(lp);
	}

	i2c_set_clientdata(cl, lp);

	/* constrain settings to what is possible */
	if (lp->pdata->initial_brightness > MAX_BRIGHTNESS)
		lp->pdata->initial_brightness = MAX_BRIGHTNESS;

	/* set initial brightness */
	ret = arcxcnn_set_brightness(lp, lp->pdata->initial_brightness);
	if (ret)
		goto probe_err;

	/* set other register values directly */
	ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_FADECTRL,
		lp->pdata->led_config_0);
	if (ret)
		goto probe_err;

	ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_ILED_CONFIG,
		lp->pdata->led_config_1);
	if (ret)
		goto probe_err;

	ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_DIMFREQ,
		lp->pdata->dim_freq);
	if (ret)
		goto probe_err;

	ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_COMP_CONFIG,
		lp->pdata->comp_config);
	if (ret)
		goto probe_err;

	ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_FILT_CONFIG,
		lp->pdata->filter_config);
	if (ret)
		goto probe_err;

	ret = i2c_smbus_write_byte_data(lp->client, ARCXCNN_IMAXTUNE,
		lp->pdata->trim_config);
	if (ret)
		goto probe_err;

	/* set initial LED Enables */
	arcxcnn_update_field(lp, ARCXCNN_LEDEN,
		ARCXCNN_LEDEN_MASK, lp->pdata->leden);

	ret = arcxcnn_backlight_register(lp);
	if (ret)
		goto probe_register_err;

	backlight_update_status(lp->bl);

	return 0;

probe_register_err:
	dev_err(lp->dev,
		"failed to register backlight.\n");

probe_err:
	dev_err(lp->dev,
		"failure ret: %d\n", ret);
	return ret;
}

__attribute__((used)) static int arcxcnn_remove(struct i2c_client *cl)
{
	struct arcxcnn *lp = i2c_get_clientdata(cl);

	/* disable all strings (ignore errors) */
	i2c_smbus_write_byte_data(lp->client,
		ARCXCNN_LEDEN, 0x00);
	/* reset the device (ignore errors) */
	i2c_smbus_write_byte_data(lp->client,
		ARCXCNN_CMD, ARCXCNN_CMD_RESET);

	lp->bl->props.brightness = 0;

	backlight_update_status(lp->bl);

	return 0;
}

