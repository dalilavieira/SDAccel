#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint8_t ;
typedef  int u8 ;
struct tosa_lcd_data {int is_vga; int lcd_power; scalar_t__ i2c; int /*<<< orphan*/ * lcd; struct spi_device* spi; } ;
struct spi_transfer {int len; int* tx_buf; int /*<<< orphan*/  cs_change; } ;
struct spi_message {int dummy; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; } ;
struct lcd_device {int dummy; } ;
struct i2c_board_info {char* type; struct spi_device* platform_data; int /*<<< orphan*/  addr; } ;
struct i2c_adapter {int dummy; } ;
struct fb_videomode {int xres; int yres; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAC_BASE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int TG_GPODR2 ; 
 int TG_GPOSR ; 
 int TG_PINICTL ; 
 int TG_PNLCTL ; 
 int TG_REG0_COLOR ; 
 int TG_REG0_LR ; 
 int TG_REG0_UD ; 
 int TG_REG0_VQV ; 
 int TG_TPOSCTL ; 
 int /*<<< orphan*/  TOSA_GPIO_TG_ON ; 
 int devm_gpio_request_one (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 struct tosa_lcd_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct tosa_lcd_data*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 struct i2c_adapter* i2c_get_adapter (int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_new_device (struct i2c_adapter*,struct i2c_board_info*) ; 
 int /*<<< orphan*/  i2c_unregister_device (scalar_t__) ; 
 struct tosa_lcd_data* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 struct tosa_lcd_data* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct tosa_lcd_data*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int /*<<< orphan*/  tosa_lcd_ops ; 

__attribute__((used)) static int tosa_tg_send(struct spi_device *spi, int adrs, uint8_t data)
{
	u8 buf[1];
	struct spi_message msg;
	struct spi_transfer xfer = {
		.len		= 1,
		.cs_change	= 0,
		.tx_buf		= buf,
	};

	buf[0] = ((adrs & 0x07) << 5) | (data & 0x1f);
	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	return spi_sync(spi, &msg);
}

int tosa_bl_enable(struct spi_device *spi, int enable)
{
	/* bl_enable GP04=1 otherwise GP04=0*/
	return tosa_tg_send(spi, TG_GPODR2, enable ? 0x01 : 0x00);
}

__attribute__((used)) static void tosa_lcd_tg_init(struct tosa_lcd_data *data)
{
	/* TG on */
	gpio_set_value(TOSA_GPIO_TG_ON, 0);

	mdelay(60);

	/* delayed 0clk TCTL signal for VGA */
	tosa_tg_send(data->spi, TG_TPOSCTL, 0x00);
	/* GPOS0=powercontrol, GPOS1=GPIO, GPOS2=TCTL */
	tosa_tg_send(data->spi, TG_GPOSR, 0x02);
}

__attribute__((used)) static void tosa_lcd_tg_on(struct tosa_lcd_data *data)
{
	struct spi_device *spi = data->spi;
	int value = TG_REG0_COLOR | TG_REG0_UD | TG_REG0_LR;

	if (data->is_vga)
		value |= TG_REG0_VQV;

	tosa_tg_send(spi, TG_PNLCTL, value);

	/* TG LCD pannel power up */
	tosa_tg_send(spi, TG_PINICTL, 0x4);
	mdelay(50);

	/* TG LCD GVSS */
	tosa_tg_send(spi, TG_PINICTL, 0x0);

	if (!data->i2c) {
		/*
		 * after the pannel is powered up the first time,
		 * we can access the i2c bus so probe for the DAC
		 */
		struct i2c_adapter *adap = i2c_get_adapter(0);
		struct i2c_board_info info = {
			.type	= "tosa-bl",
			.addr	= DAC_BASE,
			.platform_data = data->spi,
		};
		data->i2c = i2c_new_device(adap, &info);
	}
}

__attribute__((used)) static void tosa_lcd_tg_off(struct tosa_lcd_data *data)
{
	struct spi_device *spi = data->spi;

	/* TG LCD VHSA off */
	tosa_tg_send(spi, TG_PINICTL, 0x4);
	mdelay(50);

	/* TG LCD signal off */
	tosa_tg_send(spi, TG_PINICTL, 0x6);
	mdelay(50);

	/* TG Off */
	gpio_set_value(TOSA_GPIO_TG_ON, 1);
	mdelay(100);
}

int tosa_lcd_set_power(struct lcd_device *lcd, int power)
{
	struct tosa_lcd_data *data = lcd_get_data(lcd);

	if (POWER_IS_ON(power) && !POWER_IS_ON(data->lcd_power))
		tosa_lcd_tg_on(data);

	if (!POWER_IS_ON(power) && POWER_IS_ON(data->lcd_power))
		tosa_lcd_tg_off(data);

	data->lcd_power = power;
	return 0;
}

__attribute__((used)) static int tosa_lcd_get_power(struct lcd_device *lcd)
{
	struct tosa_lcd_data *data = lcd_get_data(lcd);

	return data->lcd_power;
}

__attribute__((used)) static int tosa_lcd_set_mode(struct lcd_device *lcd, struct fb_videomode *mode)
{
	struct tosa_lcd_data *data = lcd_get_data(lcd);

	if (mode->xres == 320 || mode->yres == 320)
		data->is_vga = false;
	else
		data->is_vga = true;

	if (POWER_IS_ON(data->lcd_power))
		tosa_lcd_tg_on(data);

	return 0;
}

__attribute__((used)) static int tosa_lcd_probe(struct spi_device *spi)
{
	int ret;
	struct tosa_lcd_data *data;

	data = devm_kzalloc(&spi->dev, sizeof(struct tosa_lcd_data),
				GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->is_vga = true; /* default to VGA mode */

	/*
	 * bits_per_word cannot be configured in platform data
	 */
	spi->bits_per_word = 8;

	ret = spi_setup(spi);
	if (ret < 0)
		return ret;

	data->spi = spi;
	spi_set_drvdata(spi, data);

	ret = devm_gpio_request_one(&spi->dev, TOSA_GPIO_TG_ON,
				GPIOF_OUT_INIT_LOW, "tg #pwr");
	if (ret < 0)
		return ret;

	mdelay(60);

	tosa_lcd_tg_init(data);

	tosa_lcd_tg_on(data);

	data->lcd = devm_lcd_device_register(&spi->dev, "tosa-lcd", &spi->dev,
					data, &tosa_lcd_ops);

	if (IS_ERR(data->lcd)) {
		ret = PTR_ERR(data->lcd);
		data->lcd = NULL;
		goto err_register;
	}

	return 0;

err_register:
	tosa_lcd_tg_off(data);
	return ret;
}

__attribute__((used)) static int tosa_lcd_remove(struct spi_device *spi)
{
	struct tosa_lcd_data *data = spi_get_drvdata(spi);

	if (data->i2c)
		i2c_unregister_device(data->i2c);

	tosa_lcd_tg_off(data);

	return 0;
}

