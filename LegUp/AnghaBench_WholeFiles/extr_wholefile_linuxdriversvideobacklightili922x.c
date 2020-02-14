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
struct spi_transfer {unsigned char* tx_buf; unsigned char* rx_buf; int cs_change; int bits_per_word; int len; } ;
struct spi_message {int dummy; } ;
struct spi_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  mode; int /*<<< orphan*/  max_speed_hz; } ;
struct lcd_device {int dummy; } ;
struct ili922x {int power; struct lcd_device* ld; struct spi_device* spi; } ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK_FREQ_REG (struct spi_device*,struct spi_transfer*) ; 
 int CMD_BUFSIZE ; 
 int ENODEV ; 
 int ENOMEM ; 
 int FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int ILITEK_DEVICE_ID ; 
 int ILITEK_DEVICE_ID_MASK ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 scalar_t__ POWER_IS_ON (int) ; 
 int PTR_ERR (struct lcd_device*) ; 
 int REG_COMPARE_1 ; 
 int REG_COMPARE_2 ; 
 int REG_DISPLAY_CONTROL_1 ; 
 int REG_DISPLAY_CONTROL_2 ; 
 int REG_DISPLAY_CONTROL_3 ; 
 int REG_DRIVER_CODE_READ ; 
 int REG_DRIVER_OUTPUT_CONTROL ; 
 int REG_ENTRY_MODE ; 
 int REG_EXT_INTF_CONTROL ; 
 int REG_FIRST_SCREEN_DRIVE_POS ; 
 int REG_FRAME_CYCLE_CONTROL ; 
 int REG_GAMMA_CONTROL_1 ; 
 int REG_GAMMA_CONTROL_10 ; 
 int REG_GAMMA_CONTROL_2 ; 
 int REG_GAMMA_CONTROL_3 ; 
 int REG_GAMMA_CONTROL_4 ; 
 int REG_GAMMA_CONTROL_5 ; 
 int REG_GAMMA_CONTROL_6 ; 
 int REG_GAMMA_CONTROL_7 ; 
 int REG_GAMMA_CONTROL_8 ; 
 int REG_GAMMA_CONTROL_9 ; 
 int REG_GATE_SCAN_CONTROL ; 
 int REG_LCD_AC_DRIVEING_CONTROL ; 
 int REG_POWER_CONTROL_1 ; 
 int REG_POWER_CONTROL_2 ; 
 int REG_POWER_CONTROL_3 ; 
 int REG_POWER_CONTROL_4 ; 
 int REG_RAM_ADDRESS_SET ; 
 int REG_RAM_ADDR_POS_H ; 
 int REG_RAM_ADDR_POS_V ; 
 int REG_SECOND_SCREEN_DRIVE_POS ; 
 int REG_START_OSCILLATION ; 
 int REG_VERT_SCROLL_CONTROL ; 
 unsigned char REG_WRITE_DATA_TO_GRAM ; 
 int START_BYTE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  START_RS_INDEX ; 
 int /*<<< orphan*/  START_RS_REG ; 
 int /*<<< orphan*/  START_RW_READ ; 
 int /*<<< orphan*/  START_RW_WRITE ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ili922x* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct ili922x*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ili922x_id ; 
 int /*<<< orphan*/  ili922x_ops ; 
 struct ili922x* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  memset (struct spi_transfer*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 unsigned char set_tx_byte (int) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ili922x*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int ili922x_read_status(struct spi_device *spi, u16 *rs)
{
	struct spi_message msg;
	struct spi_transfer xfer;
	unsigned char tbuf[CMD_BUFSIZE];
	unsigned char rbuf[CMD_BUFSIZE];
	int ret, i;

	memset(&xfer, 0, sizeof(struct spi_transfer));
	spi_message_init(&msg);
	xfer.tx_buf = tbuf;
	xfer.rx_buf = rbuf;
	xfer.cs_change = 1;
	CHECK_FREQ_REG(spi, &xfer);

	tbuf[0] = set_tx_byte(START_BYTE(ili922x_id, START_RS_INDEX,
					 START_RW_READ));
	/*
	 * we need 4-byte xfer here due to invalid dummy byte
	 * received after start byte
	 */
	for (i = 1; i < 4; i++)
		tbuf[i] = set_tx_byte(0);	/* dummy */

	xfer.bits_per_word = 8;
	xfer.len = 4;
	spi_message_add_tail(&xfer, &msg);
	ret = spi_sync(spi, &msg);
	if (ret < 0) {
		dev_dbg(&spi->dev, "Error sending SPI message 0x%x", ret);
		return ret;
	}

	*rs = (rbuf[2] << 8) + rbuf[3];
	return 0;
}

__attribute__((used)) static int ili922x_read(struct spi_device *spi, u8 reg, u16 *rx)
{
	struct spi_message msg;
	struct spi_transfer xfer_regindex, xfer_regvalue;
	unsigned char tbuf[CMD_BUFSIZE];
	unsigned char rbuf[CMD_BUFSIZE];
	int ret, len = 0, send_bytes;

	memset(&xfer_regindex, 0, sizeof(struct spi_transfer));
	memset(&xfer_regvalue, 0, sizeof(struct spi_transfer));
	spi_message_init(&msg);
	xfer_regindex.tx_buf = tbuf;
	xfer_regindex.rx_buf = rbuf;
	xfer_regindex.cs_change = 1;
	CHECK_FREQ_REG(spi, &xfer_regindex);

	tbuf[0] = set_tx_byte(START_BYTE(ili922x_id, START_RS_INDEX,
					 START_RW_WRITE));
	tbuf[1] = set_tx_byte(0);
	tbuf[2] = set_tx_byte(reg);
	xfer_regindex.bits_per_word = 8;
	len = xfer_regindex.len = 3;
	spi_message_add_tail(&xfer_regindex, &msg);

	send_bytes = len;

	tbuf[len++] = set_tx_byte(START_BYTE(ili922x_id, START_RS_REG,
					     START_RW_READ));
	tbuf[len++] = set_tx_byte(0);
	tbuf[len] = set_tx_byte(0);

	xfer_regvalue.cs_change = 1;
	xfer_regvalue.len = 3;
	xfer_regvalue.tx_buf = &tbuf[send_bytes];
	xfer_regvalue.rx_buf = &rbuf[send_bytes];
	CHECK_FREQ_REG(spi, &xfer_regvalue);

	spi_message_add_tail(&xfer_regvalue, &msg);
	ret = spi_sync(spi, &msg);
	if (ret < 0) {
		dev_dbg(&spi->dev, "Error sending SPI message 0x%x", ret);
		return ret;
	}

	*rx = (rbuf[1 + send_bytes] << 8) + rbuf[2 + send_bytes];
	return 0;
}

__attribute__((used)) static int ili922x_write(struct spi_device *spi, u8 reg, u16 value)
{
	struct spi_message msg;
	struct spi_transfer xfer_regindex, xfer_regvalue;
	unsigned char tbuf[CMD_BUFSIZE];
	unsigned char rbuf[CMD_BUFSIZE];
	int ret;

	memset(&xfer_regindex, 0, sizeof(struct spi_transfer));
	memset(&xfer_regvalue, 0, sizeof(struct spi_transfer));

	spi_message_init(&msg);
	xfer_regindex.tx_buf = tbuf;
	xfer_regindex.rx_buf = rbuf;
	xfer_regindex.cs_change = 1;
	CHECK_FREQ_REG(spi, &xfer_regindex);

	tbuf[0] = set_tx_byte(START_BYTE(ili922x_id, START_RS_INDEX,
					 START_RW_WRITE));
	tbuf[1] = set_tx_byte(0);
	tbuf[2] = set_tx_byte(reg);
	xfer_regindex.bits_per_word = 8;
	xfer_regindex.len = 3;
	spi_message_add_tail(&xfer_regindex, &msg);

	ret = spi_sync(spi, &msg);

	spi_message_init(&msg);
	tbuf[0] = set_tx_byte(START_BYTE(ili922x_id, START_RS_REG,
					 START_RW_WRITE));
	tbuf[1] = set_tx_byte((value & 0xFF00) >> 8);
	tbuf[2] = set_tx_byte(value & 0x00FF);

	xfer_regvalue.cs_change = 1;
	xfer_regvalue.len = 3;
	xfer_regvalue.tx_buf = tbuf;
	xfer_regvalue.rx_buf = rbuf;
	CHECK_FREQ_REG(spi, &xfer_regvalue);

	spi_message_add_tail(&xfer_regvalue, &msg);

	ret = spi_sync(spi, &msg);
	if (ret < 0) {
		dev_err(&spi->dev, "Error sending SPI message 0x%x", ret);
		return ret;
	}
	return 0;
}

__attribute__((used)) static inline void ili922x_reg_dump(struct spi_device *spi) {}

__attribute__((used)) static void set_write_to_gram_reg(struct spi_device *spi)
{
	struct spi_message msg;
	struct spi_transfer xfer;
	unsigned char tbuf[CMD_BUFSIZE];

	memset(&xfer, 0, sizeof(struct spi_transfer));

	spi_message_init(&msg);
	xfer.tx_buf = tbuf;
	xfer.rx_buf = NULL;
	xfer.cs_change = 1;

	tbuf[0] = START_BYTE(ili922x_id, START_RS_INDEX, START_RW_WRITE);
	tbuf[1] = 0;
	tbuf[2] = REG_WRITE_DATA_TO_GRAM;

	xfer.bits_per_word = 8;
	xfer.len = 3;
	spi_message_add_tail(&xfer, &msg);
	spi_sync(spi, &msg);
}

__attribute__((used)) static int ili922x_poweron(struct spi_device *spi)
{
	int ret;

	/* Power on */
	ret = ili922x_write(spi, REG_POWER_CONTROL_1, 0x0000);
	usleep_range(10000, 10500);
	ret += ili922x_write(spi, REG_POWER_CONTROL_2, 0x0000);
	ret += ili922x_write(spi, REG_POWER_CONTROL_3, 0x0000);
	msleep(40);
	ret += ili922x_write(spi, REG_POWER_CONTROL_4, 0x0000);
	msleep(40);
	/* register 0x56 is not documented in the datasheet */
	ret += ili922x_write(spi, 0x56, 0x080F);
	ret += ili922x_write(spi, REG_POWER_CONTROL_1, 0x4240);
	usleep_range(10000, 10500);
	ret += ili922x_write(spi, REG_POWER_CONTROL_2, 0x0000);
	ret += ili922x_write(spi, REG_POWER_CONTROL_3, 0x0014);
	msleep(40);
	ret += ili922x_write(spi, REG_POWER_CONTROL_4, 0x1319);
	msleep(40);

	return ret;
}

__attribute__((used)) static int ili922x_poweroff(struct spi_device *spi)
{
	int ret;

	/* Power off */
	ret = ili922x_write(spi, REG_POWER_CONTROL_1, 0x0000);
	usleep_range(10000, 10500);
	ret += ili922x_write(spi, REG_POWER_CONTROL_2, 0x0000);
	ret += ili922x_write(spi, REG_POWER_CONTROL_3, 0x0000);
	msleep(40);
	ret += ili922x_write(spi, REG_POWER_CONTROL_4, 0x0000);
	msleep(40);

	return ret;
}

__attribute__((used)) static void ili922x_display_init(struct spi_device *spi)
{
	ili922x_write(spi, REG_START_OSCILLATION, 1);
	usleep_range(10000, 10500);
	ili922x_write(spi, REG_DRIVER_OUTPUT_CONTROL, 0x691B);
	ili922x_write(spi, REG_LCD_AC_DRIVEING_CONTROL, 0x0700);
	ili922x_write(spi, REG_ENTRY_MODE, 0x1030);
	ili922x_write(spi, REG_COMPARE_1, 0x0000);
	ili922x_write(spi, REG_COMPARE_2, 0x0000);
	ili922x_write(spi, REG_DISPLAY_CONTROL_1, 0x0037);
	ili922x_write(spi, REG_DISPLAY_CONTROL_2, 0x0202);
	ili922x_write(spi, REG_DISPLAY_CONTROL_3, 0x0000);
	ili922x_write(spi, REG_FRAME_CYCLE_CONTROL, 0x0000);

	/* Set RGB interface */
	ili922x_write(spi, REG_EXT_INTF_CONTROL, 0x0110);

	ili922x_poweron(spi);

	ili922x_write(spi, REG_GAMMA_CONTROL_1, 0x0302);
	ili922x_write(spi, REG_GAMMA_CONTROL_2, 0x0407);
	ili922x_write(spi, REG_GAMMA_CONTROL_3, 0x0304);
	ili922x_write(spi, REG_GAMMA_CONTROL_4, 0x0203);
	ili922x_write(spi, REG_GAMMA_CONTROL_5, 0x0706);
	ili922x_write(spi, REG_GAMMA_CONTROL_6, 0x0407);
	ili922x_write(spi, REG_GAMMA_CONTROL_7, 0x0706);
	ili922x_write(spi, REG_GAMMA_CONTROL_8, 0x0000);
	ili922x_write(spi, REG_GAMMA_CONTROL_9, 0x0C06);
	ili922x_write(spi, REG_GAMMA_CONTROL_10, 0x0F00);
	ili922x_write(spi, REG_RAM_ADDRESS_SET, 0x0000);
	ili922x_write(spi, REG_GATE_SCAN_CONTROL, 0x0000);
	ili922x_write(spi, REG_VERT_SCROLL_CONTROL, 0x0000);
	ili922x_write(spi, REG_FIRST_SCREEN_DRIVE_POS, 0xDB00);
	ili922x_write(spi, REG_SECOND_SCREEN_DRIVE_POS, 0xDB00);
	ili922x_write(spi, REG_RAM_ADDR_POS_H, 0xAF00);
	ili922x_write(spi, REG_RAM_ADDR_POS_V, 0xDB00);
	ili922x_reg_dump(spi);
	set_write_to_gram_reg(spi);
}

__attribute__((used)) static int ili922x_lcd_power(struct ili922x *lcd, int power)
{
	int ret = 0;

	if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
		ret = ili922x_poweron(lcd->spi);
	else if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
		ret = ili922x_poweroff(lcd->spi);

	if (!ret)
		lcd->power = power;

	return ret;
}

__attribute__((used)) static int ili922x_set_power(struct lcd_device *ld, int power)
{
	struct ili922x *ili = lcd_get_data(ld);

	return ili922x_lcd_power(ili, power);
}

__attribute__((used)) static int ili922x_get_power(struct lcd_device *ld)
{
	struct ili922x *ili = lcd_get_data(ld);

	return ili->power;
}

__attribute__((used)) static int ili922x_probe(struct spi_device *spi)
{
	struct ili922x *ili;
	struct lcd_device *lcd;
	int ret;
	u16 reg = 0;

	ili = devm_kzalloc(&spi->dev, sizeof(*ili), GFP_KERNEL);
	if (!ili)
		return -ENOMEM;

	ili->spi = spi;
	spi_set_drvdata(spi, ili);

	/* check if the device is connected */
	ret = ili922x_read(spi, REG_DRIVER_CODE_READ, &reg);
	if (ret || ((reg & ILITEK_DEVICE_ID_MASK) != ILITEK_DEVICE_ID)) {
		dev_err(&spi->dev,
			"no LCD found: Chip ID 0x%x, ret %d\n",
			reg, ret);
		return -ENODEV;
	}

	dev_info(&spi->dev, "ILI%x found, SPI freq %d, mode %d\n",
		 reg, spi->max_speed_hz, spi->mode);

	ret = ili922x_read_status(spi, &reg);
	if (ret) {
		dev_err(&spi->dev, "reading RS failed...\n");
		return ret;
	}

	dev_dbg(&spi->dev, "status: 0x%x\n", reg);

	ili922x_display_init(spi);

	ili->power = FB_BLANK_POWERDOWN;

	lcd = devm_lcd_device_register(&spi->dev, "ili922xlcd", &spi->dev, ili,
					&ili922x_ops);
	if (IS_ERR(lcd)) {
		dev_err(&spi->dev, "cannot register LCD\n");
		return PTR_ERR(lcd);
	}

	ili->ld = lcd;
	spi_set_drvdata(spi, ili);

	ili922x_lcd_power(ili, FB_BLANK_UNBLANK);

	return 0;
}

__attribute__((used)) static int ili922x_remove(struct spi_device *spi)
{
	ili922x_poweroff(spi);
	return 0;
}

