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
typedef  int u8 ;
typedef  int u16 ;
struct spi_transfer {int len; int cs_change; int* tx_buf; } ;
struct spi_message {int dummy; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct ltv350qv {int* buffer; int power; struct lcd_device* ld; struct spi_device* spi; } ;
struct lcd_device {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 void* FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 int LTV_CHS_480 ; 
 int LTV_CLW (int) ; 
 int LTV_DATACTL ; 
 int LTV_DF_RGB ; 
 int LTV_DPL_SAMPLE_RISING ; 
 int LTV_DRIVE_CURRENT (int) ; 
 int LTV_DSC ; 
 int LTV_DS_SAME ; 
 int LTV_ENTRY_MODE ; 
 int LTV_EPL_ACTIVE_LOW ; 
 int LTV_EQ (int /*<<< orphan*/ ) ; 
 int LTV_FWI (int) ; 
 int LTV_GAMMA (int) ; 
 int LTV_GATECTL1 ; 
 int LTV_GATECTL2 ; 
 int LTV_HBP ; 
 int LTV_HSPL_ACTIVE_LOW ; 
 int LTV_IFCTL ; 
 int LTV_NL (int) ; 
 int LTV_NMD ; 
 int LTV_NW_INV_1LINE ; 
 int LTV_OPC_DATA ; 
 int LTV_OPC_INDEX ; 
 int LTV_POWER_ON ; 
 int LTV_PWRCTL1 ; 
 int LTV_PWRCTL2 ; 
 int LTV_REV ; 
 int LTV_RGB_BGR ; 
 int LTV_SDT (int) ; 
 int LTV_SOTCTL ; 
 int LTV_SS_RIGHT_TO_LEFT ; 
 int LTV_SUPPLY_CURRENT (int) ; 
 int LTV_VBP ; 
 int LTV_VCOML_ENABLE ; 
 int LTV_VCOMOUT_ENABLE ; 
 int LTV_VCOM_DISABLE ; 
 int LTV_VSPL_ACTIVE_LOW ; 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (struct lcd_device*) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct ltv350qv*,int /*<<< orphan*/ *) ; 
 struct ltv350qv* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  ltv_ops ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct ltv350qv* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ltv350qv*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int ltv350qv_write_reg(struct ltv350qv *lcd, u8 reg, u16 val)
{
	struct spi_message msg;
	struct spi_transfer index_xfer = {
		.len		= 3,
		.cs_change	= 1,
	};
	struct spi_transfer value_xfer = {
		.len		= 3,
	};

	spi_message_init(&msg);

	/* register index */
	lcd->buffer[0] = LTV_OPC_INDEX;
	lcd->buffer[1] = 0x00;
	lcd->buffer[2] = reg & 0x7f;
	index_xfer.tx_buf = lcd->buffer;
	spi_message_add_tail(&index_xfer, &msg);

	/* register value */
	lcd->buffer[4] = LTV_OPC_DATA;
	lcd->buffer[5] = val >> 8;
	lcd->buffer[6] = val;
	value_xfer.tx_buf = lcd->buffer + 4;
	spi_message_add_tail(&value_xfer, &msg);

	return spi_sync(lcd->spi, &msg);
}

__attribute__((used)) static int ltv350qv_power_on(struct ltv350qv *lcd)
{
	int ret;

	/* Power On Reset Display off State */
	if (ltv350qv_write_reg(lcd, LTV_PWRCTL1, 0x0000))
		goto err;
	usleep_range(15000, 16000);

	/* Power Setting Function 1 */
	if (ltv350qv_write_reg(lcd, LTV_PWRCTL1, LTV_VCOM_DISABLE))
		goto err;
	if (ltv350qv_write_reg(lcd, LTV_PWRCTL2, LTV_VCOML_ENABLE))
		goto err_power1;

	/* Power Setting Function 2 */
	if (ltv350qv_write_reg(lcd, LTV_PWRCTL1,
			       LTV_VCOM_DISABLE | LTV_DRIVE_CURRENT(5)
			       | LTV_SUPPLY_CURRENT(5)))
		goto err_power2;

	msleep(55);

	/* Instruction Setting */
	ret = ltv350qv_write_reg(lcd, LTV_IFCTL,
				 LTV_NMD | LTV_REV | LTV_NL(0x1d));
	ret |= ltv350qv_write_reg(lcd, LTV_DATACTL,
				  LTV_DS_SAME | LTV_CHS_480
				  | LTV_DF_RGB | LTV_RGB_BGR);
	ret |= ltv350qv_write_reg(lcd, LTV_ENTRY_MODE,
				  LTV_VSPL_ACTIVE_LOW
				  | LTV_HSPL_ACTIVE_LOW
				  | LTV_DPL_SAMPLE_RISING
				  | LTV_EPL_ACTIVE_LOW
				  | LTV_SS_RIGHT_TO_LEFT);
	ret |= ltv350qv_write_reg(lcd, LTV_GATECTL1, LTV_CLW(3));
	ret |= ltv350qv_write_reg(lcd, LTV_GATECTL2,
				  LTV_NW_INV_1LINE | LTV_FWI(3));
	ret |= ltv350qv_write_reg(lcd, LTV_VBP, 0x000a);
	ret |= ltv350qv_write_reg(lcd, LTV_HBP, 0x0021);
	ret |= ltv350qv_write_reg(lcd, LTV_SOTCTL, LTV_SDT(3) | LTV_EQ(0));
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(0), 0x0103);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(1), 0x0301);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(2), 0x1f0f);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(3), 0x1f0f);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(4), 0x0707);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(5), 0x0307);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(6), 0x0707);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(7), 0x0000);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(8), 0x0004);
	ret |= ltv350qv_write_reg(lcd, LTV_GAMMA(9), 0x0000);
	if (ret)
		goto err_settings;

	/* Wait more than 2 frames */
	msleep(20);

	/* Display On Sequence */
	ret = ltv350qv_write_reg(lcd, LTV_PWRCTL1,
				 LTV_VCOM_DISABLE | LTV_VCOMOUT_ENABLE
				 | LTV_POWER_ON | LTV_DRIVE_CURRENT(5)
				 | LTV_SUPPLY_CURRENT(5));
	ret |= ltv350qv_write_reg(lcd, LTV_GATECTL2,
				  LTV_NW_INV_1LINE | LTV_DSC | LTV_FWI(3));
	if (ret)
		goto err_disp_on;

	/* Display should now be ON. Phew. */
	return 0;

err_disp_on:
	/*
	 * Try to recover. Error handling probably isn't very useful
	 * at this point, just make a best effort to switch the panel
	 * off.
	 */
	ltv350qv_write_reg(lcd, LTV_PWRCTL1,
			   LTV_VCOM_DISABLE | LTV_DRIVE_CURRENT(5)
			   | LTV_SUPPLY_CURRENT(5));
	ltv350qv_write_reg(lcd, LTV_GATECTL2,
			   LTV_NW_INV_1LINE | LTV_FWI(3));
err_settings:
err_power2:
err_power1:
	ltv350qv_write_reg(lcd, LTV_PWRCTL2, 0x0000);
	usleep_range(1000, 1100);
err:
	ltv350qv_write_reg(lcd, LTV_PWRCTL1, LTV_VCOM_DISABLE);
	return -EIO;
}

__attribute__((used)) static int ltv350qv_power_off(struct ltv350qv *lcd)
{
	int ret;

	/* Display Off Sequence */
	ret = ltv350qv_write_reg(lcd, LTV_PWRCTL1,
				 LTV_VCOM_DISABLE
				 | LTV_DRIVE_CURRENT(5)
				 | LTV_SUPPLY_CURRENT(5));
	ret |= ltv350qv_write_reg(lcd, LTV_GATECTL2,
				  LTV_NW_INV_1LINE | LTV_FWI(3));

	/* Power down setting 1 */
	ret |= ltv350qv_write_reg(lcd, LTV_PWRCTL2, 0x0000);

	/* Wait at least 1 ms */
	usleep_range(1000, 1100);

	/* Power down setting 2 */
	ret |= ltv350qv_write_reg(lcd, LTV_PWRCTL1, LTV_VCOM_DISABLE);

	/*
	 * No point in trying to recover here. If we can't switch the
	 * panel off, what are we supposed to do other than inform the
	 * user about the failure?
	 */
	if (ret)
		return -EIO;

	/* Display power should now be OFF */
	return 0;
}

__attribute__((used)) static int ltv350qv_power(struct ltv350qv *lcd, int power)
{
	int ret = 0;

	if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
		ret = ltv350qv_power_on(lcd);
	else if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
		ret = ltv350qv_power_off(lcd);

	if (!ret)
		lcd->power = power;

	return ret;
}

__attribute__((used)) static int ltv350qv_set_power(struct lcd_device *ld, int power)
{
	struct ltv350qv *lcd = lcd_get_data(ld);

	return ltv350qv_power(lcd, power);
}

__attribute__((used)) static int ltv350qv_get_power(struct lcd_device *ld)
{
	struct ltv350qv *lcd = lcd_get_data(ld);

	return lcd->power;
}

__attribute__((used)) static int ltv350qv_probe(struct spi_device *spi)
{
	struct ltv350qv *lcd;
	struct lcd_device *ld;
	int ret;

	lcd = devm_kzalloc(&spi->dev, sizeof(struct ltv350qv), GFP_KERNEL);
	if (!lcd)
		return -ENOMEM;

	lcd->spi = spi;
	lcd->power = FB_BLANK_POWERDOWN;
	lcd->buffer = devm_kzalloc(&spi->dev, 8, GFP_KERNEL);
	if (!lcd->buffer)
		return -ENOMEM;

	ld = devm_lcd_device_register(&spi->dev, "ltv350qv", &spi->dev, lcd,
					&ltv_ops);
	if (IS_ERR(ld))
		return PTR_ERR(ld);

	lcd->ld = ld;

	ret = ltv350qv_power(lcd, FB_BLANK_UNBLANK);
	if (ret)
		return ret;

	spi_set_drvdata(spi, lcd);

	return 0;
}

__attribute__((used)) static int ltv350qv_remove(struct spi_device *spi)
{
	struct ltv350qv *lcd = spi_get_drvdata(spi);

	ltv350qv_power(lcd, FB_BLANK_POWERDOWN);
	return 0;
}

__attribute__((used)) static void ltv350qv_shutdown(struct spi_device *spi)
{
	struct ltv350qv *lcd = spi_get_drvdata(spi);

	ltv350qv_power(lcd, FB_BLANK_POWERDOWN);
}

