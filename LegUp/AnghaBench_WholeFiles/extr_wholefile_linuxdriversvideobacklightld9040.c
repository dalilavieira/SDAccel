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
typedef  int u16 ;
struct spi_transfer {int len; int* tx_buf; } ;
struct spi_message {int dummy; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; } ;
struct ld9040 {int enabled; int power; struct lcd_platform_data* lcd_pd; struct lcd_device* bd; struct lcd_device* ld; int /*<<< orphan*/ * dev; int /*<<< orphan*/  lock; struct spi_device* spi; } ;
struct lcd_platform_data {unsigned short const power_on_delay; unsigned short const reset_delay; unsigned short const power_off_delay; int /*<<< orphan*/  lcd_enabled; int /*<<< orphan*/  (* reset ) (struct lcd_device*) ;} ;
struct TYPE_3__ {int brightness; int max_brightness; } ;
struct lcd_device {TYPE_1__ props; int /*<<< orphan*/  dev; } ;
struct backlight_properties {void* max_brightness; int /*<<< orphan*/  type; } ;
struct backlight_device {TYPE_1__ props; int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {unsigned int** gamma_22_table; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned short const**) ; 
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 unsigned char COMMAND_ONLY ; 
 unsigned char DATA_ONLY ; 
 unsigned short const DEFMASK ; 
 int EINVAL ; 
 int EIO ; 
 unsigned short const ENDDEF ; 
 int ENOMEM ; 
 int FB_BLANK_NORMAL ; 
 int FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 unsigned int GAMMA_TABLE_COUNT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 void* MAX_BRIGHTNESS ; 
 int MIN_BRIGHTNESS ; 
 int PTR_ERR (struct lcd_device*) ; 
 unsigned short const SLEEPMSEC ; 
 struct ld9040* bl_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct lcd_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 struct lcd_device* devm_backlight_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct ld9040*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct ld9040* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct ld9040*,int /*<<< orphan*/ *) ; 
 int devm_regulator_bulk_get (int /*<<< orphan*/ *,int,unsigned short const**) ; 
 TYPE_2__ gamma_table ; 
 struct ld9040* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  ld9040_backlight_ops ; 
 int /*<<< orphan*/  ld9040_lcd_ops ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (unsigned short const) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regulator_bulk_disable (int,unsigned short const**) ; 
 int regulator_bulk_enable (int,unsigned short const**) ; 
#define  seq_display_ctrl 136 
 unsigned short* seq_display_off ; 
 unsigned short* seq_display_on ; 
#define  seq_elvss_on 135 
#define  seq_gamma_ctrl 134 
#define  seq_gamma_set1 133 
 unsigned short* seq_gamma_start ; 
#define  seq_gtcon 132 
#define  seq_manual_pwr 131 
#define  seq_panel_condition 130 
 unsigned short* seq_sleep_in ; 
#define  seq_sleep_out 129 
#define  seq_user_setting 128 
 struct ld9040* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ld9040*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int /*<<< orphan*/  stub1 (struct lcd_device*) ; 
 unsigned short const** supplies ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void ld9040_regulator_enable(struct ld9040 *lcd)
{
	int ret = 0;
	struct lcd_platform_data *pd = NULL;

	pd = lcd->lcd_pd;
	mutex_lock(&lcd->lock);
	if (!lcd->enabled) {
		ret = regulator_bulk_enable(ARRAY_SIZE(supplies), supplies);
		if (ret)
			goto out;

		lcd->enabled = true;
	}
	msleep(pd->power_on_delay);
out:
	mutex_unlock(&lcd->lock);
}

__attribute__((used)) static void ld9040_regulator_disable(struct ld9040 *lcd)
{
	int ret = 0;

	mutex_lock(&lcd->lock);
	if (lcd->enabled) {
		ret = regulator_bulk_disable(ARRAY_SIZE(supplies), supplies);
		if (ret)
			goto out;

		lcd->enabled = false;
	}
out:
	mutex_unlock(&lcd->lock);
}

__attribute__((used)) static int ld9040_spi_write_byte(struct ld9040 *lcd, int addr, int data)
{
	u16 buf[1];
	struct spi_message msg;

	struct spi_transfer xfer = {
		.len		= 2,
		.tx_buf		= buf,
	};

	buf[0] = (addr << 8) | data;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	return spi_sync(lcd->spi, &msg);
}

__attribute__((used)) static int ld9040_spi_write(struct ld9040 *lcd, unsigned char address,
	unsigned char command)
{
	int ret = 0;

	if (address != DATA_ONLY)
		ret = ld9040_spi_write_byte(lcd, 0x0, address);
	if (command != COMMAND_ONLY)
		ret = ld9040_spi_write_byte(lcd, 0x1, command);

	return ret;
}

__attribute__((used)) static int ld9040_panel_send_sequence(struct ld9040 *lcd,
	const unsigned short *wbuf)
{
	int ret = 0, i = 0;

	while ((wbuf[i] & DEFMASK) != ENDDEF) {
		if ((wbuf[i] & DEFMASK) != SLEEPMSEC) {
			ret = ld9040_spi_write(lcd, wbuf[i], wbuf[i+1]);
			if (ret)
				break;
		} else {
			msleep(wbuf[i+1]);
		}
		i += 2;
	}

	return ret;
}

__attribute__((used)) static int _ld9040_gamma_ctl(struct ld9040 *lcd, const unsigned int *gamma)
{
	unsigned int i = 0;
	int ret = 0;

	/* start gamma table updating. */
	ret = ld9040_panel_send_sequence(lcd, seq_gamma_start);
	if (ret) {
		dev_err(lcd->dev, "failed to disable gamma table updating.\n");
		goto gamma_err;
	}

	for (i = 0 ; i < GAMMA_TABLE_COUNT; i++) {
		ret = ld9040_spi_write(lcd, DATA_ONLY, gamma[i]);
		if (ret) {
			dev_err(lcd->dev, "failed to set gamma table.\n");
			goto gamma_err;
		}
	}

	/* update gamma table. */
	ret = ld9040_panel_send_sequence(lcd, seq_gamma_ctrl);
	if (ret)
		dev_err(lcd->dev, "failed to update gamma table.\n");

gamma_err:
	return ret;
}

__attribute__((used)) static int ld9040_gamma_ctl(struct ld9040 *lcd, int gamma)
{
	return _ld9040_gamma_ctl(lcd, gamma_table.gamma_22_table[gamma]);
}

__attribute__((used)) static int ld9040_ldi_init(struct ld9040 *lcd)
{
	int ret, i;
	static const unsigned short *init_seq[] = {
		seq_user_setting,
		seq_panel_condition,
		seq_display_ctrl,
		seq_manual_pwr,
		seq_elvss_on,
		seq_gtcon,
		seq_gamma_set1,
		seq_gamma_ctrl,
		seq_sleep_out,
	};

	for (i = 0; i < ARRAY_SIZE(init_seq); i++) {
		ret = ld9040_panel_send_sequence(lcd, init_seq[i]);
		/* workaround: minimum delay time for transferring CMD */
		usleep_range(300, 310);
		if (ret)
			break;
	}

	return ret;
}

__attribute__((used)) static int ld9040_ldi_enable(struct ld9040 *lcd)
{
	return ld9040_panel_send_sequence(lcd, seq_display_on);
}

__attribute__((used)) static int ld9040_ldi_disable(struct ld9040 *lcd)
{
	int ret;

	ret = ld9040_panel_send_sequence(lcd, seq_display_off);
	ret = ld9040_panel_send_sequence(lcd, seq_sleep_in);

	return ret;
}

__attribute__((used)) static int ld9040_power_is_on(int power)
{
	return power <= FB_BLANK_NORMAL;
}

__attribute__((used)) static int ld9040_power_on(struct ld9040 *lcd)
{
	int ret = 0;
	struct lcd_platform_data *pd;

	pd = lcd->lcd_pd;

	/* lcd power on */
	ld9040_regulator_enable(lcd);

	if (!pd->reset) {
		dev_err(lcd->dev, "reset is NULL.\n");
		return -EINVAL;
	}

	pd->reset(lcd->ld);
	msleep(pd->reset_delay);

	ret = ld9040_ldi_init(lcd);
	if (ret) {
		dev_err(lcd->dev, "failed to initialize ldi.\n");
		return ret;
	}

	ret = ld9040_ldi_enable(lcd);
	if (ret) {
		dev_err(lcd->dev, "failed to enable ldi.\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int ld9040_power_off(struct ld9040 *lcd)
{
	int ret;
	struct lcd_platform_data *pd;

	pd = lcd->lcd_pd;

	ret = ld9040_ldi_disable(lcd);
	if (ret) {
		dev_err(lcd->dev, "lcd setting failed.\n");
		return -EIO;
	}

	msleep(pd->power_off_delay);

	/* lcd power off */
	ld9040_regulator_disable(lcd);

	return 0;
}

__attribute__((used)) static int ld9040_power(struct ld9040 *lcd, int power)
{
	int ret = 0;

	if (ld9040_power_is_on(power) && !ld9040_power_is_on(lcd->power))
		ret = ld9040_power_on(lcd);
	else if (!ld9040_power_is_on(power) && ld9040_power_is_on(lcd->power))
		ret = ld9040_power_off(lcd);

	if (!ret)
		lcd->power = power;

	return ret;
}

__attribute__((used)) static int ld9040_set_power(struct lcd_device *ld, int power)
{
	struct ld9040 *lcd = lcd_get_data(ld);

	if (power != FB_BLANK_UNBLANK && power != FB_BLANK_POWERDOWN &&
		power != FB_BLANK_NORMAL) {
		dev_err(lcd->dev, "power value should be 0, 1 or 4.\n");
		return -EINVAL;
	}

	return ld9040_power(lcd, power);
}

__attribute__((used)) static int ld9040_get_power(struct lcd_device *ld)
{
	struct ld9040 *lcd = lcd_get_data(ld);

	return lcd->power;
}

__attribute__((used)) static int ld9040_set_brightness(struct backlight_device *bd)
{
	int ret = 0, brightness = bd->props.brightness;
	struct ld9040 *lcd = bl_get_data(bd);

	if (brightness < MIN_BRIGHTNESS ||
		brightness > bd->props.max_brightness) {
		dev_err(&bd->dev, "lcd brightness should be %d to %d.\n",
			MIN_BRIGHTNESS, MAX_BRIGHTNESS);
		return -EINVAL;
	}

	ret = ld9040_gamma_ctl(lcd, bd->props.brightness);
	if (ret) {
		dev_err(&bd->dev, "lcd brightness setting failed.\n");
		return -EIO;
	}

	return ret;
}

__attribute__((used)) static int ld9040_probe(struct spi_device *spi)
{
	int ret = 0;
	struct ld9040 *lcd = NULL;
	struct lcd_device *ld = NULL;
	struct backlight_device *bd = NULL;
	struct backlight_properties props;

	lcd = devm_kzalloc(&spi->dev, sizeof(struct ld9040), GFP_KERNEL);
	if (!lcd)
		return -ENOMEM;

	/* ld9040 lcd panel uses 3-wire 9bits SPI Mode. */
	spi->bits_per_word = 9;

	ret = spi_setup(spi);
	if (ret < 0) {
		dev_err(&spi->dev, "spi setup failed.\n");
		return ret;
	}

	lcd->spi = spi;
	lcd->dev = &spi->dev;

	lcd->lcd_pd = dev_get_platdata(&spi->dev);
	if (!lcd->lcd_pd) {
		dev_err(&spi->dev, "platform data is NULL.\n");
		return -EINVAL;
	}

	mutex_init(&lcd->lock);

	ret = devm_regulator_bulk_get(lcd->dev, ARRAY_SIZE(supplies), supplies);
	if (ret) {
		dev_err(lcd->dev, "Failed to get regulators: %d\n", ret);
		return ret;
	}

	ld = devm_lcd_device_register(&spi->dev, "ld9040", &spi->dev, lcd,
					&ld9040_lcd_ops);
	if (IS_ERR(ld))
		return PTR_ERR(ld);

	lcd->ld = ld;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = MAX_BRIGHTNESS;

	bd = devm_backlight_device_register(&spi->dev, "ld9040-bl", &spi->dev,
					lcd, &ld9040_backlight_ops, &props);
	if (IS_ERR(bd))
		return PTR_ERR(bd);

	bd->props.brightness = MAX_BRIGHTNESS;
	lcd->bd = bd;

	/*
	 * if lcd panel was on from bootloader like u-boot then
	 * do not lcd on.
	 */
	if (!lcd->lcd_pd->lcd_enabled) {
		/*
		 * if lcd panel was off from bootloader then
		 * current lcd status is powerdown and then
		 * it enables lcd panel.
		 */
		lcd->power = FB_BLANK_POWERDOWN;

		ld9040_power(lcd, FB_BLANK_UNBLANK);
	} else {
		lcd->power = FB_BLANK_UNBLANK;
	}

	spi_set_drvdata(spi, lcd);

	dev_info(&spi->dev, "ld9040 panel driver has been probed.\n");
	return 0;
}

__attribute__((used)) static int ld9040_remove(struct spi_device *spi)
{
	struct ld9040 *lcd = spi_get_drvdata(spi);

	ld9040_power(lcd, FB_BLANK_POWERDOWN);
	return 0;
}

__attribute__((used)) static void ld9040_shutdown(struct spi_device *spi)
{
	struct ld9040 *lcd = spi_get_drvdata(spi);

	ld9040_power(lcd, FB_BLANK_POWERDOWN);
}

