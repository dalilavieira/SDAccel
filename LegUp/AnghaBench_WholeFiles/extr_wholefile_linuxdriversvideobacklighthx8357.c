#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  xfer ;
typedef  int u8 ;
typedef  int u16 ;
struct spi_transfer {int len; int bits_per_word; int* tx_buf; int* rx_buf; } ;
struct spi_message {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {TYPE_1__ dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct lcd_device {TYPE_1__ dev; } ;
struct hx8357_data {int reset; int use_im_pins; int* im_pins; int state; struct spi_device* spi; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_HIGH ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 int HX8357_ENTER_SLEEP_MODE ; 
 int HX8357_EXIT_SLEEP_MODE ; 
 int HX8357_NUM_IM_PINS ; 
 int HX8357_SET_DISPLAY_OFF ; 
 int HX8357_SET_DISPLAY_ON ; 
 int HX8357_WRITE_MEMORY_START ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (struct lcd_device*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,int) ; 
 int devm_gpio_request_one (TYPE_1__*,int,int /*<<< orphan*/ ,char*) ; 
 struct hx8357_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (TYPE_1__*,char*,TYPE_1__*,struct hx8357_data*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gpio_is_valid (int) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  gpio_set_value_cansleep (int,int) ; 
 int /*<<< orphan*/  hx8357_dt_ids ; 
 int /*<<< orphan*/  hx8357_ops ; 
 int* hx8357_seq_address_mode ; 
 int* hx8357_seq_column_address ; 
 int* hx8357_seq_display_frame ; 
 int* hx8357_seq_display_mode ; 
 int* hx8357_seq_gamma ; 
 int* hx8357_seq_page_address ; 
 int* hx8357_seq_panel_driving ; 
 int* hx8357_seq_panel_related ; 
 int* hx8357_seq_pixel_format ; 
 int* hx8357_seq_power ; 
 int* hx8357_seq_power_normal ; 
 int* hx8357_seq_rgb ; 
 int* hx8357_seq_undefined1 ; 
 int* hx8357_seq_undefined2 ; 
 int* hx8357_seq_vcom ; 
 int* hx8369_seq_display_related ; 
 int* hx8369_seq_extension_command ; 
 int* hx8369_seq_gamma_curve_related ; 
 int* hx8369_seq_gip ; 
 int* hx8369_seq_panel_waveform_cycle ; 
 int* hx8369_seq_power ; 
 int* hx8369_seq_set_address_mode ; 
 int* hx8369_seq_set_display_brightness ; 
 int* hx8369_seq_vcom ; 
 int* hx8369_seq_write_CABC_control ; 
 int* hx8369_seq_write_CABC_control_setting ; 
 int* hx8369_seq_write_CABC_min_brightness ; 
 int* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 struct hx8357_data* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  memset (struct spi_transfer*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ of_find_property (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 void* of_get_named_gpio (int /*<<< orphan*/ ,char*,int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct lcd_device*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int stub1 (struct lcd_device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int hx8357_spi_write_then_read(struct lcd_device *lcdev,
				u8 *txbuf, u16 txlen,
				u8 *rxbuf, u16 rxlen)
{
	struct hx8357_data *lcd = lcd_get_data(lcdev);
	struct spi_message msg;
	struct spi_transfer xfer[2];
	u16 *local_txbuf = NULL;
	int ret = 0;

	memset(xfer, 0, sizeof(xfer));
	spi_message_init(&msg);

	if (txlen) {
		int i;

		local_txbuf = kcalloc(txlen, sizeof(*local_txbuf), GFP_KERNEL);

		if (!local_txbuf)
			return -ENOMEM;

		for (i = 0; i < txlen; i++) {
			local_txbuf[i] = txbuf[i];
			if (i > 0)
				local_txbuf[i] |= 1 << 8;
		}

		xfer[0].len = 2 * txlen;
		xfer[0].bits_per_word = 9;
		xfer[0].tx_buf = local_txbuf;
		spi_message_add_tail(&xfer[0], &msg);
	}

	if (rxlen) {
		xfer[1].len = rxlen;
		xfer[1].bits_per_word = 8;
		xfer[1].rx_buf = rxbuf;
		spi_message_add_tail(&xfer[1], &msg);
	}

	ret = spi_sync(lcd->spi, &msg);
	if (ret < 0)
		dev_err(&lcdev->dev, "Couldn't send SPI data\n");

	if (txlen)
		kfree(local_txbuf);

	return ret;
}

__attribute__((used)) static inline int hx8357_spi_write_array(struct lcd_device *lcdev,
					u8 *value, u8 len)
{
	return hx8357_spi_write_then_read(lcdev, value, len, NULL, 0);
}

__attribute__((used)) static inline int hx8357_spi_write_byte(struct lcd_device *lcdev,
					u8 value)
{
	return hx8357_spi_write_then_read(lcdev, &value, 1, NULL, 0);
}

__attribute__((used)) static int hx8357_enter_standby(struct lcd_device *lcdev)
{
	int ret;

	ret = hx8357_spi_write_byte(lcdev, HX8357_SET_DISPLAY_OFF);
	if (ret < 0)
		return ret;

	usleep_range(10000, 12000);

	ret = hx8357_spi_write_byte(lcdev, HX8357_ENTER_SLEEP_MODE);
	if (ret < 0)
		return ret;

	/*
	 * The controller needs 120ms when entering in sleep mode before we can
	 * send the command to go off sleep mode
	 */
	msleep(120);

	return 0;
}

__attribute__((used)) static int hx8357_exit_standby(struct lcd_device *lcdev)
{
	int ret;

	ret = hx8357_spi_write_byte(lcdev, HX8357_EXIT_SLEEP_MODE);
	if (ret < 0)
		return ret;

	/*
	 * The controller needs 120ms when exiting from sleep mode before we
	 * can send the command to enter in sleep mode
	 */
	msleep(120);

	ret = hx8357_spi_write_byte(lcdev, HX8357_SET_DISPLAY_ON);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static void hx8357_lcd_reset(struct lcd_device *lcdev)
{
	struct hx8357_data *lcd = lcd_get_data(lcdev);

	/* Reset the screen */
	gpio_set_value(lcd->reset, 1);
	usleep_range(10000, 12000);
	gpio_set_value(lcd->reset, 0);
	usleep_range(10000, 12000);
	gpio_set_value(lcd->reset, 1);

	/* The controller needs 120ms to recover from reset */
	msleep(120);
}

__attribute__((used)) static int hx8357_lcd_init(struct lcd_device *lcdev)
{
	struct hx8357_data *lcd = lcd_get_data(lcdev);
	int ret;

	/*
	 * Set the interface selection pins to SPI mode, with three
	 * wires
	 */
	if (lcd->use_im_pins) {
		gpio_set_value_cansleep(lcd->im_pins[0], 1);
		gpio_set_value_cansleep(lcd->im_pins[1], 0);
		gpio_set_value_cansleep(lcd->im_pins[2], 1);
	}

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_power,
				ARRAY_SIZE(hx8357_seq_power));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_vcom,
				ARRAY_SIZE(hx8357_seq_vcom));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_power_normal,
				ARRAY_SIZE(hx8357_seq_power_normal));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_panel_driving,
				ARRAY_SIZE(hx8357_seq_panel_driving));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_display_frame,
				ARRAY_SIZE(hx8357_seq_display_frame));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_panel_related,
				ARRAY_SIZE(hx8357_seq_panel_related));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_undefined1,
				ARRAY_SIZE(hx8357_seq_undefined1));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_undefined2,
				ARRAY_SIZE(hx8357_seq_undefined2));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_gamma,
				ARRAY_SIZE(hx8357_seq_gamma));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_address_mode,
				ARRAY_SIZE(hx8357_seq_address_mode));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_pixel_format,
				ARRAY_SIZE(hx8357_seq_pixel_format));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_column_address,
				ARRAY_SIZE(hx8357_seq_column_address));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_page_address,
				ARRAY_SIZE(hx8357_seq_page_address));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_rgb,
				ARRAY_SIZE(hx8357_seq_rgb));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8357_seq_display_mode,
				ARRAY_SIZE(hx8357_seq_display_mode));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_byte(lcdev, HX8357_EXIT_SLEEP_MODE);
	if (ret < 0)
		return ret;

	/*
	 * The controller needs 120ms to fully recover from exiting sleep mode
	 */
	msleep(120);

	ret = hx8357_spi_write_byte(lcdev, HX8357_SET_DISPLAY_ON);
	if (ret < 0)
		return ret;

	usleep_range(5000, 7000);

	ret = hx8357_spi_write_byte(lcdev, HX8357_WRITE_MEMORY_START);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int hx8369_lcd_init(struct lcd_device *lcdev)
{
	int ret;

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_extension_command,
				ARRAY_SIZE(hx8369_seq_extension_command));
	if (ret < 0)
		return ret;
	usleep_range(10000, 12000);

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_display_related,
				ARRAY_SIZE(hx8369_seq_display_related));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_panel_waveform_cycle,
				ARRAY_SIZE(hx8369_seq_panel_waveform_cycle));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_set_address_mode,
				ARRAY_SIZE(hx8369_seq_set_address_mode));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_vcom,
				ARRAY_SIZE(hx8369_seq_vcom));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_gip,
				ARRAY_SIZE(hx8369_seq_gip));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_power,
				ARRAY_SIZE(hx8369_seq_power));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_byte(lcdev, HX8357_EXIT_SLEEP_MODE);
	if (ret < 0)
		return ret;

	/*
	 * The controller needs 120ms to fully recover from exiting sleep mode
	 */
	msleep(120);

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_gamma_curve_related,
				ARRAY_SIZE(hx8369_seq_gamma_curve_related));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_byte(lcdev, HX8357_EXIT_SLEEP_MODE);
	if (ret < 0)
		return ret;
	usleep_range(1000, 1200);

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_write_CABC_control,
				ARRAY_SIZE(hx8369_seq_write_CABC_control));
	if (ret < 0)
		return ret;
	usleep_range(10000, 12000);

	ret = hx8357_spi_write_array(lcdev,
			hx8369_seq_write_CABC_control_setting,
			ARRAY_SIZE(hx8369_seq_write_CABC_control_setting));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_array(lcdev,
			hx8369_seq_write_CABC_min_brightness,
			ARRAY_SIZE(hx8369_seq_write_CABC_min_brightness));
	if (ret < 0)
		return ret;
	usleep_range(10000, 12000);

	ret = hx8357_spi_write_array(lcdev, hx8369_seq_set_display_brightness,
				ARRAY_SIZE(hx8369_seq_set_display_brightness));
	if (ret < 0)
		return ret;

	ret = hx8357_spi_write_byte(lcdev, HX8357_SET_DISPLAY_ON);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int hx8357_set_power(struct lcd_device *lcdev, int power)
{
	struct hx8357_data *lcd = lcd_get_data(lcdev);
	int ret = 0;

	if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->state))
		ret = hx8357_exit_standby(lcdev);
	else if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->state))
		ret = hx8357_enter_standby(lcdev);

	if (ret == 0)
		lcd->state = power;
	else
		dev_warn(&lcdev->dev, "failed to set power mode %d\n", power);

	return ret;
}

__attribute__((used)) static int hx8357_get_power(struct lcd_device *lcdev)
{
	struct hx8357_data *lcd = lcd_get_data(lcdev);

	return lcd->state;
}

__attribute__((used)) static int hx8357_probe(struct spi_device *spi)
{
	struct lcd_device *lcdev;
	struct hx8357_data *lcd;
	const struct of_device_id *match;
	int i, ret;

	lcd = devm_kzalloc(&spi->dev, sizeof(*lcd), GFP_KERNEL);
	if (!lcd)
		return -ENOMEM;

	ret = spi_setup(spi);
	if (ret < 0) {
		dev_err(&spi->dev, "SPI setup failed.\n");
		return ret;
	}

	lcd->spi = spi;

	match = of_match_device(hx8357_dt_ids, &spi->dev);
	if (!match || !match->data)
		return -EINVAL;

	lcd->reset = of_get_named_gpio(spi->dev.of_node, "gpios-reset", 0);
	if (!gpio_is_valid(lcd->reset)) {
		dev_err(&spi->dev, "Missing dt property: gpios-reset\n");
		return -EINVAL;
	}

	ret = devm_gpio_request_one(&spi->dev, lcd->reset,
				    GPIOF_OUT_INIT_HIGH,
				    "hx8357-reset");
	if (ret) {
		dev_err(&spi->dev,
			"failed to request gpio %d: %d\n",
			lcd->reset, ret);
		return -EINVAL;
	}

	if (of_find_property(spi->dev.of_node, "im-gpios", NULL)) {
		lcd->use_im_pins = 1;

		for (i = 0; i < HX8357_NUM_IM_PINS; i++) {
			lcd->im_pins[i] = of_get_named_gpio(spi->dev.of_node,
							    "im-gpios", i);
			if (lcd->im_pins[i] == -EPROBE_DEFER) {
				dev_info(&spi->dev, "GPIO requested is not here yet, deferring the probe\n");
				return -EPROBE_DEFER;
			}
			if (!gpio_is_valid(lcd->im_pins[i])) {
				dev_err(&spi->dev, "Missing dt property: im-gpios\n");
				return -EINVAL;
			}

			ret = devm_gpio_request_one(&spi->dev, lcd->im_pins[i],
						    GPIOF_OUT_INIT_LOW,
						    "im_pins");
			if (ret) {
				dev_err(&spi->dev, "failed to request gpio %d: %d\n",
					lcd->im_pins[i], ret);
				return -EINVAL;
			}
		}
	} else {
		lcd->use_im_pins = 0;
	}

	lcdev = devm_lcd_device_register(&spi->dev, "mxsfb", &spi->dev, lcd,
					&hx8357_ops);
	if (IS_ERR(lcdev)) {
		ret = PTR_ERR(lcdev);
		return ret;
	}
	spi_set_drvdata(spi, lcdev);

	hx8357_lcd_reset(lcdev);

	ret = ((int (*)(struct lcd_device *))match->data)(lcdev);
	if (ret) {
		dev_err(&spi->dev, "Couldn't initialize panel\n");
		return ret;
	}

	dev_info(&spi->dev, "Panel probed\n");

	return 0;
}

