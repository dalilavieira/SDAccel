#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct tosa_bl_data {int comadj; TYPE_3__* bl; struct i2c_client* i2c; } ;
struct spi_device {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct backlight_properties {int brightness; int max_brightness; int /*<<< orphan*/  type; int /*<<< orphan*/  fb_blank; int /*<<< orphan*/  power; } ;
struct backlight_device {struct backlight_properties props; } ;
struct TYPE_7__ {int brightness; int /*<<< orphan*/  power; } ;
struct TYPE_9__ {TYPE_1__ props; int /*<<< orphan*/  dev; } ;
struct TYPE_8__ {int comadj; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int COMADJ_DEFAULT ; 
 int /*<<< orphan*/  DAC_CH1 ; 
 int /*<<< orphan*/  DAC_CH2 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 scalar_t__ IS_ERR (TYPE_3__*) ; 
 int PTR_ERR (TYPE_3__*) ; 
 int /*<<< orphan*/  TOSA_GPIO_BL_C20MA ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_3__*) ; 
 struct tosa_bl_data* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  bl_ops ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 struct spi_device* dev_get_platdata (int /*<<< orphan*/ *) ; 
 TYPE_3__* devm_backlight_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct tosa_bl_data*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int devm_gpio_request_one (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 struct tosa_bl_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 struct tosa_bl_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tosa_bl_data*) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int max (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 TYPE_2__ sharpsl_param ; 
 int /*<<< orphan*/  tosa_bl_enable (struct spi_device*,int) ; 

__attribute__((used)) static void tosa_bl_set_backlight(struct tosa_bl_data *data, int brightness)
{
	struct spi_device *spi = dev_get_platdata(&data->i2c->dev);

	i2c_smbus_write_byte_data(data->i2c, DAC_CH1, data->comadj);

	/* SetBacklightDuty */
	i2c_smbus_write_byte_data(data->i2c, DAC_CH2, (u8)(brightness & 0xff));

	/* SetBacklightVR */
	gpio_set_value(TOSA_GPIO_BL_C20MA, brightness & 0x100);

	tosa_bl_enable(spi, brightness);
}

__attribute__((used)) static int tosa_bl_update_status(struct backlight_device *dev)
{
	struct backlight_properties *props = &dev->props;
	struct tosa_bl_data *data = bl_get_data(dev);
	int power = max(props->power, props->fb_blank);
	int brightness = props->brightness;

	if (power)
		brightness = 0;

	tosa_bl_set_backlight(data, brightness);

	return 0;
}

__attribute__((used)) static int tosa_bl_get_brightness(struct backlight_device *dev)
{
	struct backlight_properties *props = &dev->props;

	return props->brightness;
}

__attribute__((used)) static int tosa_bl_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	struct backlight_properties props;
	struct tosa_bl_data *data;
	int ret = 0;

	data = devm_kzalloc(&client->dev, sizeof(struct tosa_bl_data),
				GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->comadj = sharpsl_param.comadj == -1 ? COMADJ_DEFAULT : sharpsl_param.comadj;

	ret = devm_gpio_request_one(&client->dev, TOSA_GPIO_BL_C20MA,
				GPIOF_OUT_INIT_LOW, "backlight");
	if (ret) {
		dev_dbg(&data->bl->dev, "Unable to request gpio!\n");
		return ret;
	}

	i2c_set_clientdata(client, data);
	data->i2c = client;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = 512 - 1;
	data->bl = devm_backlight_device_register(&client->dev, "tosa-bl",
						&client->dev, data, &bl_ops,
						&props);
	if (IS_ERR(data->bl)) {
		ret = PTR_ERR(data->bl);
		goto err_reg;
	}

	data->bl->props.brightness = 69;
	data->bl->props.power = FB_BLANK_UNBLANK;

	backlight_update_status(data->bl);

	return 0;

err_reg:
	data->bl = NULL;
	return ret;
}

__attribute__((used)) static int tosa_bl_remove(struct i2c_client *client)
{
	struct tosa_bl_data *data = i2c_get_clientdata(client);

	data->bl = NULL;
	return 0;
}

