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
typedef  int uint32_t ;
struct tdo24m_platform_data {int model; } ;
struct spi_transfer {int len; int* tx_buf; scalar_t__ cs_change; } ;
struct spi_message {int dummy; } ;
struct tdo24m {int color_invert; int* buf; int mode; int (* adj_mode ) (struct tdo24m*,int) ;int power; int /*<<< orphan*/  lcd_dev; struct spi_transfer xfer; struct spi_message msg; struct spi_device* spi_dev; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; int /*<<< orphan*/  mode; } ;
struct lcd_device {int dummy; } ;
struct fb_videomode {int xres; } ;
typedef  enum tdo24m_model { ____Placeholder_tdo24m_model } tdo24m_model ;

/* Variables and functions */
 int const CMD0 (int) ; 
 int const CMD_NULL ; 
 int EINVAL ; 
 int ENOMEM ; 
 void* FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  MODE_QVGA 131 
#define  MODE_VGA 130 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
#define  TDO24M 129 
 int TDO24M_SPI_BUFF_SIZE ; 
#define  TDO35S 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct tdo24m_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct tdo24m*,int /*<<< orphan*/ *) ; 
 struct tdo24m* lcd_get_data (struct lcd_device*) ; 
 int* lcd_panel_config ; 
 int* lcd_panel_off ; 
 int* lcd_panel_on ; 
 int* lcd_panel_reset ; 
 int* lcd_qvga_pass_through_tdo24m ; 
 int* lcd_qvga_pass_through_tdo35s ; 
 int* lcd_qvga_transfer ; 
 int* lcd_vga_pass_through_tdo24m ; 
 int* lcd_vga_pass_through_tdo35s ; 
 int* lcd_vga_transfer_tdo24m ; 
 int* lcd_vga_transfer_tdo35s ; 
 struct tdo24m* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct tdo24m*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int stub1 (struct tdo24m*,int) ; 
 int stub2 (struct tdo24m*,int) ; 
 int /*<<< orphan*/  tdo24m_ops ; 

__attribute__((used)) static int tdo24m_writes(struct tdo24m *lcd, const uint32_t *array)
{
	struct spi_transfer *x = &lcd->xfer;
	const uint32_t *p = array;
	uint32_t data;
	int nparams, err = 0;

	for (; *p != CMD_NULL; p++) {
		if (!lcd->color_invert && *p == CMD0(0x21))
			continue;

		nparams = (*p >> 30) & 0x3;

		data = *p << (7 - nparams);
		switch (nparams) {
		case 0:
			lcd->buf[0] = (data >> 8) & 0xff;
			lcd->buf[1] = data & 0xff;
			break;
		case 1:
			lcd->buf[0] = (data >> 16) & 0xff;
			lcd->buf[1] = (data >> 8) & 0xff;
			lcd->buf[2] = data & 0xff;
			break;
		case 2:
			lcd->buf[0] = (data >> 24) & 0xff;
			lcd->buf[1] = (data >> 16) & 0xff;
			lcd->buf[2] = (data >> 8) & 0xff;
			lcd->buf[3] = data & 0xff;
			break;
		default:
			continue;
		}
		x->len = nparams + 2;
		err = spi_sync(lcd->spi_dev, &lcd->msg);
		if (err)
			break;
	}

	return err;
}

__attribute__((used)) static int tdo24m_adj_mode(struct tdo24m *lcd, int mode)
{
	switch (mode) {
	case MODE_VGA:
		tdo24m_writes(lcd, lcd_vga_pass_through_tdo24m);
		tdo24m_writes(lcd, lcd_panel_config);
		tdo24m_writes(lcd, lcd_vga_transfer_tdo24m);
		break;
	case MODE_QVGA:
		tdo24m_writes(lcd, lcd_qvga_pass_through_tdo24m);
		tdo24m_writes(lcd, lcd_panel_config);
		tdo24m_writes(lcd, lcd_qvga_transfer);
		break;
	default:
		return -EINVAL;
	}

	lcd->mode = mode;
	return 0;
}

__attribute__((used)) static int tdo35s_adj_mode(struct tdo24m *lcd, int mode)
{
	switch (mode) {
	case MODE_VGA:
		tdo24m_writes(lcd, lcd_vga_pass_through_tdo35s);
		tdo24m_writes(lcd, lcd_panel_config);
		tdo24m_writes(lcd, lcd_vga_transfer_tdo35s);
		break;
	case MODE_QVGA:
		tdo24m_writes(lcd, lcd_qvga_pass_through_tdo35s);
		tdo24m_writes(lcd, lcd_panel_config);
		tdo24m_writes(lcd, lcd_qvga_transfer);
		break;
	default:
		return -EINVAL;
	}

	lcd->mode = mode;
	return 0;
}

__attribute__((used)) static int tdo24m_power_on(struct tdo24m *lcd)
{
	int err;

	err = tdo24m_writes(lcd, lcd_panel_on);
	if (err)
		goto out;

	err = tdo24m_writes(lcd, lcd_panel_reset);
	if (err)
		goto out;

	err = lcd->adj_mode(lcd, lcd->mode);
out:
	return err;
}

__attribute__((used)) static int tdo24m_power_off(struct tdo24m *lcd)
{
	return tdo24m_writes(lcd, lcd_panel_off);
}

__attribute__((used)) static int tdo24m_power(struct tdo24m *lcd, int power)
{
	int ret = 0;

	if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
		ret = tdo24m_power_on(lcd);
	else if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
		ret = tdo24m_power_off(lcd);

	if (!ret)
		lcd->power = power;

	return ret;
}

__attribute__((used)) static int tdo24m_set_power(struct lcd_device *ld, int power)
{
	struct tdo24m *lcd = lcd_get_data(ld);

	return tdo24m_power(lcd, power);
}

__attribute__((used)) static int tdo24m_get_power(struct lcd_device *ld)
{
	struct tdo24m *lcd = lcd_get_data(ld);

	return lcd->power;
}

__attribute__((used)) static int tdo24m_set_mode(struct lcd_device *ld, struct fb_videomode *m)
{
	struct tdo24m *lcd = lcd_get_data(ld);
	int mode = MODE_QVGA;

	if (m->xres == 640 || m->xres == 480)
		mode = MODE_VGA;

	if (lcd->mode == mode)
		return 0;

	return lcd->adj_mode(lcd, mode);
}

__attribute__((used)) static int tdo24m_probe(struct spi_device *spi)
{
	struct tdo24m *lcd;
	struct spi_message *m;
	struct spi_transfer *x;
	struct tdo24m_platform_data *pdata;
	enum tdo24m_model model;
	int err;

	pdata = dev_get_platdata(&spi->dev);
	if (pdata)
		model = pdata->model;
	else
		model = TDO24M;

	spi->bits_per_word = 8;
	spi->mode = SPI_MODE_3;
	err = spi_setup(spi);
	if (err)
		return err;

	lcd = devm_kzalloc(&spi->dev, sizeof(struct tdo24m), GFP_KERNEL);
	if (!lcd)
		return -ENOMEM;

	lcd->spi_dev = spi;
	lcd->power = FB_BLANK_POWERDOWN;
	lcd->mode = MODE_VGA;	/* default to VGA */

	lcd->buf = devm_kzalloc(&spi->dev, TDO24M_SPI_BUFF_SIZE, GFP_KERNEL);
	if (lcd->buf == NULL)
		return -ENOMEM;

	m = &lcd->msg;
	x = &lcd->xfer;

	spi_message_init(m);

	x->cs_change = 0;
	x->tx_buf = &lcd->buf[0];
	spi_message_add_tail(x, m);

	switch (model) {
	case TDO24M:
		lcd->color_invert = 1;
		lcd->adj_mode = tdo24m_adj_mode;
		break;
	case TDO35S:
		lcd->adj_mode = tdo35s_adj_mode;
		lcd->color_invert = 0;
		break;
	default:
		dev_err(&spi->dev, "Unsupported model");
		return -EINVAL;
	}

	lcd->lcd_dev = devm_lcd_device_register(&spi->dev, "tdo24m", &spi->dev,
						lcd, &tdo24m_ops);
	if (IS_ERR(lcd->lcd_dev))
		return PTR_ERR(lcd->lcd_dev);

	spi_set_drvdata(spi, lcd);
	err = tdo24m_power(lcd, FB_BLANK_UNBLANK);
	if (err)
		return err;

	return 0;
}

__attribute__((used)) static int tdo24m_remove(struct spi_device *spi)
{
	struct tdo24m *lcd = spi_get_drvdata(spi);

	tdo24m_power(lcd, FB_BLANK_POWERDOWN);
	return 0;
}

__attribute__((used)) static void tdo24m_shutdown(struct spi_device *spi)
{
	struct tdo24m *lcd = spi_get_drvdata(spi);

	tdo24m_power(lcd, FB_BLANK_POWERDOWN);
}

