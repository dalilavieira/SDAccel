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
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct spi_transfer {int len; int* tx_buf; int /*<<< orphan*/  cs_change; } ;
struct spi_message {int dummy; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {scalar_t__ brightness; void* power; } ;
struct lcd_device {TYPE_2__ props; } ;
struct fb_videomode {int xres; } ;
struct corgi_lcd_platform_data {int gpio_backlight_on; int gpio_backlight_cont; int const init_mode; int limit_mask; int /*<<< orphan*/  (* kick_battery ) () ;scalar_t__ default_intensity; int /*<<< orphan*/  max_intensity; } ;
struct corgi_lcd {int* buf; int mode; int power; int intensity; int gpio_backlight_cont_inverted; int gpio_backlight_cont; int gpio_backlight_on; int limit_mask; struct lcd_device* lcd_dev; struct lcd_device* bl_dev; int /*<<< orphan*/  (* kick_battery ) () ;struct spi_device* spi_dev; } ;
struct backlight_properties {int /*<<< orphan*/  max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_4__ {int brightness; void* power; void* fb_blank; } ;
struct backlight_device {TYPE_1__ props; } ;
struct TYPE_6__ {int phadadj; int comadj; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int CORGIBL_BATTLOW ; 
 int CORGIBL_SUSPENDED ; 
#define  CORGI_LCD_MODE_QVGA 129 
#define  CORGI_LCD_MODE_VGA 128 
 int DEFAULT_COMADJ ; 
 int DEFAULT_PHAD_QVGA ; 
 int DUTYCTRL_ADRS ; 
 int EINVAL ; 
 int ENOMEM ; 
 void* FB_BLANK_POWERDOWN ; 
 void* FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 int PHACTRL_ADRS ; 
 int PHACTRL_PHASE_MANUAL ; 
 int PICTRL_ADRS ; 
 int PICTRL_COM_SIGNAL_OFF ; 
 int PICTRL_DAC_SIGNAL_OFF ; 
 int PICTRL_INIOFF ; 
 int PICTRL_INIT_STATE ; 
 int PICTRL_POWER_DOWN ; 
 int POLCTRL_ADRS ; 
 int POLCTRL_DATA_POL_RISE ; 
 int POLCTRL_EN_ACT_H ; 
 int POLCTRL_EN_POL_RISE ; 
 int POLCTRL_SYNC_ACT_L ; 
 int POLCTRL_SYNC_POL_RISE ; 
 int POWER0_COM_DCLK ; 
 int POWER0_COM_DOUT ; 
 int POWER0_COM_OFF ; 
 int POWER0_COM_ON ; 
 int POWER0_DAC_OFF ; 
 int POWER0_DAC_ON ; 
 int POWER0_VCC5_OFF ; 
 int POWER0_VCC5_ON ; 
 int POWER1_GVSS_OFF ; 
 int POWER1_GVSS_ON ; 
 int POWER1_VDD_OFF ; 
 int POWER1_VDD_ON ; 
 int POWER1_VW_OFF ; 
 int POWER1_VW_ON ; 
 int POWERREG0_ADRS ; 
 int POWERREG1_ADRS ; 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (struct lcd_device*) ; 
 int RESCTL_ADRS ; 
 int RESCTL_QVGA ; 
 int RESCTL_VGA ; 
 int /*<<< orphan*/  backlight_update_status (struct lcd_device*) ; 
 struct corgi_lcd* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  corgi_bl_ops ; 
 int /*<<< orphan*/  corgi_lcd_ops ; 
static  int corgi_ssp_lcdtg_send (struct corgi_lcd*,int,int) ; 
 int corgibl_flags ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct corgi_lcd_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct lcd_device* devm_backlight_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct corgi_lcd*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int devm_gpio_request (int /*<<< orphan*/ *,int,char*) ; 
 struct corgi_lcd* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct corgi_lcd*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gpio_direction_output (int,int) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int /*<<< orphan*/  gpio_set_value_cansleep (int,int) ; 
 struct corgi_lcd* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 TYPE_3__ sharpsl_param ; 
 struct corgi_lcd* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct corgi_lcd*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int /*<<< orphan*/  stub1 () ; 
 struct corgi_lcd* the_corgi_lcd ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void lcdtg_ssp_i2c_send(struct corgi_lcd *lcd, uint8_t data)
{
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS, data);
	udelay(10);
}

__attribute__((used)) static void lcdtg_i2c_send_bit(struct corgi_lcd *lcd, uint8_t data)
{
	lcdtg_ssp_i2c_send(lcd, data);
	lcdtg_ssp_i2c_send(lcd, data | POWER0_COM_DCLK);
	lcdtg_ssp_i2c_send(lcd, data);
}

__attribute__((used)) static void lcdtg_i2c_send_start(struct corgi_lcd *lcd, uint8_t base)
{
	lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK | POWER0_COM_DOUT);
	lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK);
	lcdtg_ssp_i2c_send(lcd, base);
}

__attribute__((used)) static void lcdtg_i2c_send_stop(struct corgi_lcd *lcd, uint8_t base)
{
	lcdtg_ssp_i2c_send(lcd, base);
	lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK);
	lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK | POWER0_COM_DOUT);
}

__attribute__((used)) static void lcdtg_i2c_send_byte(struct corgi_lcd *lcd,
				uint8_t base, uint8_t data)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (data & 0x80)
			lcdtg_i2c_send_bit(lcd, base | POWER0_COM_DOUT);
		else
			lcdtg_i2c_send_bit(lcd, base);
		data <<= 1;
	}
}

__attribute__((used)) static void lcdtg_i2c_wait_ack(struct corgi_lcd *lcd, uint8_t base)
{
	lcdtg_i2c_send_bit(lcd, base);
}

__attribute__((used)) static void lcdtg_set_common_voltage(struct corgi_lcd *lcd,
				     uint8_t base_data, uint8_t data)
{
	/* Set Common Voltage to M62332FP via I2C */
	lcdtg_i2c_send_start(lcd, base_data);
	lcdtg_i2c_send_byte(lcd, base_data, 0x9c);
	lcdtg_i2c_wait_ack(lcd, base_data);
	lcdtg_i2c_send_byte(lcd, base_data, 0x00);
	lcdtg_i2c_wait_ack(lcd, base_data);
	lcdtg_i2c_send_byte(lcd, base_data, data);
	lcdtg_i2c_wait_ack(lcd, base_data);
	lcdtg_i2c_send_stop(lcd, base_data);
}

__attribute__((used)) static int corgi_ssp_lcdtg_send(struct corgi_lcd *lcd, int adrs, uint8_t data)
{
	struct spi_message msg;
	struct spi_transfer xfer = {
		.len		= 1,
		.cs_change	= 0,
		.tx_buf		= lcd->buf,
	};

	lcd->buf[0] = ((adrs & 0x07) << 5) | (data & 0x1f);
	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	return spi_sync(lcd->spi_dev, &msg);
}

__attribute__((used)) static void lcdtg_set_phadadj(struct corgi_lcd *lcd, int mode)
{
	int adj;

	switch (mode) {
	case CORGI_LCD_MODE_VGA:
		/* Setting for VGA */
		adj = sharpsl_param.phadadj;
		adj = (adj < 0) ? PHACTRL_PHASE_MANUAL :
				  PHACTRL_PHASE_MANUAL | ((adj & 0xf) << 1);
		break;
	case CORGI_LCD_MODE_QVGA:
	default:
		/* Setting for QVGA */
		adj = (DEFAULT_PHAD_QVGA << 1) | PHACTRL_PHASE_MANUAL;
		break;
	}

	corgi_ssp_lcdtg_send(lcd, PHACTRL_ADRS, adj);
}

__attribute__((used)) static void corgi_lcd_power_on(struct corgi_lcd *lcd)
{
	int comadj;

	/* Initialize Internal Logic & Port */
	corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS,
			PICTRL_POWER_DOWN | PICTRL_INIOFF |
			PICTRL_INIT_STATE | PICTRL_COM_SIGNAL_OFF |
			PICTRL_DAC_SIGNAL_OFF);

	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_OFF |
			POWER0_COM_OFF | POWER0_VCC5_OFF);

	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_OFF);

	/* VDD(+8V), SVSS(-4V) ON */
	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_ON);
	mdelay(3);

	/* DAC ON */
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_ON |
			POWER0_COM_OFF | POWER0_VCC5_OFF);

	/* INIB = H, INI = L  */
	/* PICTL[0] = H , PICTL[1] = PICTL[2] = PICTL[4] = L */
	corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS,
			PICTRL_INIT_STATE | PICTRL_COM_SIGNAL_OFF);

	/* Set Common Voltage */
	comadj = sharpsl_param.comadj;
	if (comadj < 0)
		comadj = DEFAULT_COMADJ;

	lcdtg_set_common_voltage(lcd, POWER0_DAC_ON | POWER0_COM_OFF |
				 POWER0_VCC5_OFF, comadj);

	/* VCC5 ON, DAC ON */
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_ON |
			POWER0_COM_OFF | POWER0_VCC5_ON);

	/* GVSS(-8V) ON, VDD ON */
	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_OFF | POWER1_GVSS_ON | POWER1_VDD_ON);
	mdelay(2);

	/* COM SIGNAL ON (PICTL[3] = L) */
	corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS, PICTRL_INIT_STATE);

	/* COM ON, DAC ON, VCC5_ON */
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_ON |
			POWER0_COM_ON | POWER0_VCC5_ON);

	/* VW ON, GVSS ON, VDD ON */
	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_ON | POWER1_GVSS_ON | POWER1_VDD_ON);

	/* Signals output enable */
	corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS, 0);

	/* Set Phase Adjust */
	lcdtg_set_phadadj(lcd, lcd->mode);

	/* Initialize for Input Signals from ATI */
	corgi_ssp_lcdtg_send(lcd, POLCTRL_ADRS,
			POLCTRL_SYNC_POL_RISE | POLCTRL_EN_POL_RISE |
			POLCTRL_DATA_POL_RISE | POLCTRL_SYNC_ACT_L |
			POLCTRL_EN_ACT_H);
	udelay(1000);

	switch (lcd->mode) {
	case CORGI_LCD_MODE_VGA:
		corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_VGA);
		break;
	case CORGI_LCD_MODE_QVGA:
	default:
		corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_QVGA);
		break;
	}
}

__attribute__((used)) static void corgi_lcd_power_off(struct corgi_lcd *lcd)
{
	/* 60Hz x 2 frame = 16.7msec x 2 = 33.4 msec */
	msleep(34);

	/* (1)VW OFF */
	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_OFF | POWER1_GVSS_ON | POWER1_VDD_ON);

	/* (2)COM OFF */
	corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS, PICTRL_COM_SIGNAL_OFF);
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_DAC_ON | POWER0_COM_OFF | POWER0_VCC5_ON);

	/* (3)Set Common Voltage Bias 0V */
	lcdtg_set_common_voltage(lcd, POWER0_DAC_ON | POWER0_COM_OFF |
			POWER0_VCC5_ON, 0);

	/* (4)GVSS OFF */
	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_ON);

	/* (5)VCC5 OFF */
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_DAC_ON | POWER0_COM_OFF | POWER0_VCC5_OFF);

	/* (6)Set PDWN, INIOFF, DACOFF */
	corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS,
			PICTRL_INIOFF | PICTRL_DAC_SIGNAL_OFF |
			PICTRL_POWER_DOWN | PICTRL_COM_SIGNAL_OFF);

	/* (7)DAC OFF */
	corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
			POWER0_DAC_OFF | POWER0_COM_OFF | POWER0_VCC5_OFF);

	/* (8)VDD OFF */
	corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
			POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_OFF);
}

__attribute__((used)) static int corgi_lcd_set_mode(struct lcd_device *ld, struct fb_videomode *m)
{
	struct corgi_lcd *lcd = lcd_get_data(ld);
	int mode = CORGI_LCD_MODE_QVGA;

	if (m->xres == 640 || m->xres == 480)
		mode = CORGI_LCD_MODE_VGA;

	if (lcd->mode == mode)
		return 0;

	lcdtg_set_phadadj(lcd, mode);

	switch (mode) {
	case CORGI_LCD_MODE_VGA:
		corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_VGA);
		break;
	case CORGI_LCD_MODE_QVGA:
	default:
		corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_QVGA);
		break;
	}

	lcd->mode = mode;
	return 0;
}

__attribute__((used)) static int corgi_lcd_set_power(struct lcd_device *ld, int power)
{
	struct corgi_lcd *lcd = lcd_get_data(ld);

	if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
		corgi_lcd_power_on(lcd);

	if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
		corgi_lcd_power_off(lcd);

	lcd->power = power;
	return 0;
}

__attribute__((used)) static int corgi_lcd_get_power(struct lcd_device *ld)
{
	struct corgi_lcd *lcd = lcd_get_data(ld);

	return lcd->power;
}

__attribute__((used)) static int corgi_bl_get_intensity(struct backlight_device *bd)
{
	struct corgi_lcd *lcd = bl_get_data(bd);

	return lcd->intensity;
}

__attribute__((used)) static int corgi_bl_set_intensity(struct corgi_lcd *lcd, int intensity)
{
	int cont;

	if (intensity > 0x10)
		intensity += 0x10;

	corgi_ssp_lcdtg_send(lcd, DUTYCTRL_ADRS, intensity);

	/* Bit 5 via GPIO_BACKLIGHT_CONT */
	cont = !!(intensity & 0x20) ^ lcd->gpio_backlight_cont_inverted;

	if (gpio_is_valid(lcd->gpio_backlight_cont))
		gpio_set_value_cansleep(lcd->gpio_backlight_cont, cont);

	if (gpio_is_valid(lcd->gpio_backlight_on))
		gpio_set_value_cansleep(lcd->gpio_backlight_on, intensity);

	if (lcd->kick_battery)
		lcd->kick_battery();

	lcd->intensity = intensity;
	return 0;
}

__attribute__((used)) static int corgi_bl_update_status(struct backlight_device *bd)
{
	struct corgi_lcd *lcd = bl_get_data(bd);
	int intensity = bd->props.brightness;

	if (bd->props.power != FB_BLANK_UNBLANK)
		intensity = 0;

	if (bd->props.fb_blank != FB_BLANK_UNBLANK)
		intensity = 0;

	if (corgibl_flags & CORGIBL_SUSPENDED)
		intensity = 0;

	if ((corgibl_flags & CORGIBL_BATTLOW) && intensity > lcd->limit_mask)
		intensity = lcd->limit_mask;

	return corgi_bl_set_intensity(lcd, intensity);
}

void corgi_lcd_limit_intensity(int limit)
{
	if (limit)
		corgibl_flags |= CORGIBL_BATTLOW;
	else
		corgibl_flags &= ~CORGIBL_BATTLOW;

	backlight_update_status(the_corgi_lcd->bl_dev);
}

__attribute__((used)) static int setup_gpio_backlight(struct corgi_lcd *lcd,
				struct corgi_lcd_platform_data *pdata)
{
	struct spi_device *spi = lcd->spi_dev;
	int err;

	lcd->gpio_backlight_on = -1;
	lcd->gpio_backlight_cont = -1;

	if (gpio_is_valid(pdata->gpio_backlight_on)) {
		err = devm_gpio_request(&spi->dev, pdata->gpio_backlight_on,
					"BL_ON");
		if (err) {
			dev_err(&spi->dev,
				"failed to request GPIO%d for backlight_on\n",
				pdata->gpio_backlight_on);
			return err;
		}

		lcd->gpio_backlight_on = pdata->gpio_backlight_on;
		gpio_direction_output(lcd->gpio_backlight_on, 0);
	}

	if (gpio_is_valid(pdata->gpio_backlight_cont)) {
		err = devm_gpio_request(&spi->dev, pdata->gpio_backlight_cont,
					"BL_CONT");
		if (err) {
			dev_err(&spi->dev,
				"failed to request GPIO%d for backlight_cont\n",
				pdata->gpio_backlight_cont);
			return err;
		}

		lcd->gpio_backlight_cont = pdata->gpio_backlight_cont;

		/* spitz and akita use both GPIOs for backlight, and
		 * have inverted polarity of GPIO_BACKLIGHT_CONT
		 */
		if (gpio_is_valid(lcd->gpio_backlight_on)) {
			lcd->gpio_backlight_cont_inverted = 1;
			gpio_direction_output(lcd->gpio_backlight_cont, 1);
		} else {
			lcd->gpio_backlight_cont_inverted = 0;
			gpio_direction_output(lcd->gpio_backlight_cont, 0);
		}
	}
	return 0;
}

__attribute__((used)) static int corgi_lcd_probe(struct spi_device *spi)
{
	struct backlight_properties props;
	struct corgi_lcd_platform_data *pdata = dev_get_platdata(&spi->dev);
	struct corgi_lcd *lcd;
	int ret = 0;

	if (pdata == NULL) {
		dev_err(&spi->dev, "platform data not available\n");
		return -EINVAL;
	}

	lcd = devm_kzalloc(&spi->dev, sizeof(struct corgi_lcd), GFP_KERNEL);
	if (!lcd)
		return -ENOMEM;

	lcd->spi_dev = spi;

	lcd->lcd_dev = devm_lcd_device_register(&spi->dev, "corgi_lcd",
						&spi->dev, lcd, &corgi_lcd_ops);
	if (IS_ERR(lcd->lcd_dev))
		return PTR_ERR(lcd->lcd_dev);

	lcd->power = FB_BLANK_POWERDOWN;
	lcd->mode = (pdata) ? pdata->init_mode : CORGI_LCD_MODE_VGA;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = pdata->max_intensity;
	lcd->bl_dev = devm_backlight_device_register(&spi->dev, "corgi_bl",
						&spi->dev, lcd, &corgi_bl_ops,
						&props);
	if (IS_ERR(lcd->bl_dev))
		return PTR_ERR(lcd->bl_dev);

	lcd->bl_dev->props.brightness = pdata->default_intensity;
	lcd->bl_dev->props.power = FB_BLANK_UNBLANK;

	ret = setup_gpio_backlight(lcd, pdata);
	if (ret)
		return ret;

	lcd->kick_battery = pdata->kick_battery;

	spi_set_drvdata(spi, lcd);
	corgi_lcd_set_power(lcd->lcd_dev, FB_BLANK_UNBLANK);
	backlight_update_status(lcd->bl_dev);

	lcd->limit_mask = pdata->limit_mask;
	the_corgi_lcd = lcd;
	return 0;
}

__attribute__((used)) static int corgi_lcd_remove(struct spi_device *spi)
{
	struct corgi_lcd *lcd = spi_get_drvdata(spi);

	lcd->bl_dev->props.power = FB_BLANK_UNBLANK;
	lcd->bl_dev->props.brightness = 0;
	backlight_update_status(lcd->bl_dev);
	corgi_lcd_set_power(lcd->lcd_dev, FB_BLANK_POWERDOWN);
	return 0;
}

