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
typedef  int /*<<< orphan*/  tmp ;
struct device {int dummy; } ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  modalias; int /*<<< orphan*/  mode; struct device dev; } ;
struct sensor_device_attribute {int index; } ;
struct device_attribute {int dummy; } ;
struct ads7871_data {struct spi_device* spi; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INST_16BIT_BM ; 
 int INST_READ_BM ; 
 int MUX_CNV_BM ; 
 int MUX_CNV_BV ; 
 int MUX_M3_BM ; 
 int OSC_BUFE_BM ; 
 int OSC_OSCE_BM ; 
 int OSC_OSCR_BM ; 
 int OSC_REFE_BM ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int REG_AD_CONTROL ; 
 int REG_GAIN_MUX ; 
 int REG_LS_BYTE ; 
 int REG_OSC_CONTROL ; 
 int REG_SER_CONTROL ; 
 int /*<<< orphan*/  SPI_MODE_0 ; 
 int /*<<< orphan*/  ads7871_groups ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int) ; 
 struct ads7871_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ads7871_data*,int /*<<< orphan*/ ) ; 
 struct ads7871_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep_interruptible (int) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 int spi_w8r16 (struct spi_device*,int) ; 
 int spi_w8r8 (struct spi_device*,int) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int sprintf (char*,char*,int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int ads7871_read_reg8(struct spi_device *spi, int reg)
{
	int ret;
	reg = reg | INST_READ_BM;
	ret = spi_w8r8(spi, reg);
	return ret;
}

__attribute__((used)) static int ads7871_read_reg16(struct spi_device *spi, int reg)
{
	int ret;
	reg = reg | INST_READ_BM | INST_16BIT_BM;
	ret = spi_w8r16(spi, reg);
	return ret;
}

__attribute__((used)) static int ads7871_write_reg8(struct spi_device *spi, int reg, u8 val)
{
	u8 tmp[2] = {reg, val};
	return spi_write(spi, tmp, sizeof(tmp));
}

__attribute__((used)) static ssize_t show_voltage(struct device *dev,
		struct device_attribute *da, char *buf)
{
	struct ads7871_data *pdata = dev_get_drvdata(dev);
	struct spi_device *spi = pdata->spi;
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	int ret, val, i = 0;
	uint8_t channel, mux_cnv;

	channel = attr->index;
	/*
	 * TODO: add support for conversions
	 * other than single ended with a gain of 1
	 */
	/*MUX_M3_BM forces single ended*/
	/*This is also where the gain of the PGA would be set*/
	ads7871_write_reg8(spi, REG_GAIN_MUX,
		(MUX_CNV_BM | MUX_M3_BM | channel));

	ret = ads7871_read_reg8(spi, REG_GAIN_MUX);
	mux_cnv = ((ret & MUX_CNV_BM) >> MUX_CNV_BV);
	/*
	 * on 400MHz arm9 platform the conversion
	 * is already done when we do this test
	 */
	while ((i < 2) && mux_cnv) {
		i++;
		ret = ads7871_read_reg8(spi, REG_GAIN_MUX);
		mux_cnv = ((ret & MUX_CNV_BM) >> MUX_CNV_BV);
		msleep_interruptible(1);
	}

	if (mux_cnv == 0) {
		val = ads7871_read_reg16(spi, REG_LS_BYTE);
		/*result in volts*10000 = (val/8192)*2.5*10000*/
		val = ((val >> 2) * 25000) / 8192;
		return sprintf(buf, "%d\n", val);
	} else {
		return -1;
	}
}

__attribute__((used)) static int ads7871_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	int ret;
	uint8_t val;
	struct ads7871_data *pdata;
	struct device *hwmon_dev;

	/* Configure the SPI bus */
	spi->mode = (SPI_MODE_0);
	spi->bits_per_word = 8;
	spi_setup(spi);

	ads7871_write_reg8(spi, REG_SER_CONTROL, 0);
	ads7871_write_reg8(spi, REG_AD_CONTROL, 0);

	val = (OSC_OSCR_BM | OSC_OSCE_BM | OSC_REFE_BM | OSC_BUFE_BM);
	ads7871_write_reg8(spi, REG_OSC_CONTROL, val);
	ret = ads7871_read_reg8(spi, REG_OSC_CONTROL);

	dev_dbg(dev, "REG_OSC_CONTROL write:%x, read:%x\n", val, ret);
	/*
	 * because there is no other error checking on an SPI bus
	 * we need to make sure we really have a chip
	 */
	if (val != ret)
		return -ENODEV;

	pdata = devm_kzalloc(dev, sizeof(struct ads7871_data), GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;

	pdata->spi = spi;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, spi->modalias,
							   pdata,
							   ads7871_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

