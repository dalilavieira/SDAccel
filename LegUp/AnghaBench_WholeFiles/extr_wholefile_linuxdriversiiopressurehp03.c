#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct TYPE_2__ {struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  adapter; struct device dev; } ;
struct hp03_priv {int pressure; int temp; int /*<<< orphan*/  eeprom_client; int /*<<< orphan*/  eeprom_regmap; int /*<<< orphan*/  xclr_gpio; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
typedef  int /*<<< orphan*/  coefs ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int HP03_ADC_READ_PRESSURE ; 
 int /*<<< orphan*/  HP03_ADC_READ_REG ; 
 int HP03_ADC_READ_TEMP ; 
 int /*<<< orphan*/  HP03_ADC_WRITE_REG ; 
 int /*<<< orphan*/  HP03_EEPROM_ADDR ; 
 int /*<<< orphan*/  HP03_EEPROM_CX_OFFSET ; 
#define  IIO_CHAN_INFO_RAW 131 
#define  IIO_CHAN_INFO_SCALE 130 
#define  IIO_PRESSURE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  devm_gpiod_get_index (struct device*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  hp03_channels ; 
 int /*<<< orphan*/  hp03_info ; 
 int /*<<< orphan*/  hp03_regmap_config ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_new_dummy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  i2c_unregister_device (int /*<<< orphan*/ ) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct hp03_priv* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  regmap_exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_init_i2c (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool hp03_is_writeable_reg(struct device *dev, unsigned int reg)
{
	return false;
}

__attribute__((used)) static bool hp03_is_volatile_reg(struct device *dev, unsigned int reg)
{
	return false;
}

__attribute__((used)) static int hp03_get_temp_pressure(struct hp03_priv *priv, const u8 reg)
{
	int ret;

	ret = i2c_smbus_write_byte_data(priv->client, HP03_ADC_WRITE_REG, reg);
	if (ret < 0)
		return ret;

	msleep(50);	/* Wait for conversion to finish */

	return i2c_smbus_read_word_data(priv->client, HP03_ADC_READ_REG);
}

__attribute__((used)) static int hp03_update_temp_pressure(struct hp03_priv *priv)
{
	struct device *dev = &priv->client->dev;
	u8 coefs[18];
	u16 cx_val[7];
	int ab_val, d1_val, d2_val, diff_val, dut, off, sens, x;
	int i, ret;

	/* Sample coefficients from EEPROM */
	ret = regmap_bulk_read(priv->eeprom_regmap, HP03_EEPROM_CX_OFFSET,
			       coefs, sizeof(coefs));
	if (ret < 0) {
		dev_err(dev, "Failed to read EEPROM (reg=%02x)\n",
			HP03_EEPROM_CX_OFFSET);
		return ret;
	}

	/* Sample Temperature and Pressure */
	gpiod_set_value_cansleep(priv->xclr_gpio, 1);

	ret = hp03_get_temp_pressure(priv, HP03_ADC_READ_PRESSURE);
	if (ret < 0) {
		dev_err(dev, "Failed to read pressure\n");
		goto err_adc;
	}
	d1_val = ret;

	ret = hp03_get_temp_pressure(priv, HP03_ADC_READ_TEMP);
	if (ret < 0) {
		dev_err(dev, "Failed to read temperature\n");
		goto err_adc;
	}
	d2_val = ret;

	gpiod_set_value_cansleep(priv->xclr_gpio, 0);

	/* The Cx coefficients and Temp/Pressure values are MSB first. */
	for (i = 0; i < 7; i++)
		cx_val[i] = (coefs[2 * i] << 8) | (coefs[(2 * i) + 1] << 0);
	d1_val = ((d1_val >> 8) & 0xff) | ((d1_val & 0xff) << 8);
	d2_val = ((d2_val >> 8) & 0xff) | ((d2_val & 0xff) << 8);

	/* Coefficient voodoo from the HP03 datasheet. */
	if (d2_val >= cx_val[4])
		ab_val = coefs[14];	/* A-value */
	else
		ab_val = coefs[15];	/* B-value */

	diff_val = d2_val - cx_val[4];
	dut = (ab_val * (diff_val >> 7) * (diff_val >> 7)) >> coefs[16];
	dut = diff_val - dut;

	off = (cx_val[1] + (((cx_val[3] - 1024) * dut) >> 14)) * 4;
	sens = cx_val[0] + ((cx_val[2] * dut) >> 10);
	x = ((sens * (d1_val - 7168)) >> 14) - off;

	priv->pressure = ((x * 100) >> 5) + (cx_val[6] * 10);
	priv->temp = 250 + ((dut * cx_val[5]) >> 16) - (dut >> coefs[17]);

	return 0;

err_adc:
	gpiod_set_value_cansleep(priv->xclr_gpio, 0);
	return ret;
}

__attribute__((used)) static int hp03_read_raw(struct iio_dev *indio_dev,
			 struct iio_chan_spec const *chan,
			 int *val, int *val2, long mask)
{
	struct hp03_priv *priv = iio_priv(indio_dev);
	int ret;

	mutex_lock(&priv->lock);
	ret = hp03_update_temp_pressure(priv);
	mutex_unlock(&priv->lock);

	if (ret)
		return ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_PRESSURE:
			*val = priv->pressure;
			return IIO_VAL_INT;
		case IIO_TEMP:
			*val = priv->temp;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
		break;
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_PRESSURE:
			*val = 0;
			*val2 = 1000;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_TEMP:
			*val = 10;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int hp03_probe(struct i2c_client *client,
		      const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct iio_dev *indio_dev;
	struct hp03_priv *priv;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
	if (!indio_dev)
		return -ENOMEM;

	priv = iio_priv(indio_dev);
	priv->client = client;
	mutex_init(&priv->lock);

	indio_dev->dev.parent = dev;
	indio_dev->name = id->name;
	indio_dev->channels = hp03_channels;
	indio_dev->num_channels = ARRAY_SIZE(hp03_channels);
	indio_dev->info = &hp03_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	priv->xclr_gpio = devm_gpiod_get_index(dev, "xclr", 0, GPIOD_OUT_HIGH);
	if (IS_ERR(priv->xclr_gpio)) {
		dev_err(dev, "Failed to claim XCLR GPIO\n");
		ret = PTR_ERR(priv->xclr_gpio);
		return ret;
	}

	/*
	 * Allocate another device for the on-sensor EEPROM,
	 * which has it's dedicated I2C address and contains
	 * the calibration constants for the sensor.
	 */
	priv->eeprom_client = i2c_new_dummy(client->adapter, HP03_EEPROM_ADDR);
	if (!priv->eeprom_client) {
		dev_err(dev, "New EEPROM I2C device failed\n");
		return -ENODEV;
	}

	priv->eeprom_regmap = regmap_init_i2c(priv->eeprom_client,
					      &hp03_regmap_config);
	if (IS_ERR(priv->eeprom_regmap)) {
		dev_err(dev, "Failed to allocate EEPROM regmap\n");
		ret = PTR_ERR(priv->eeprom_regmap);
		goto err_cleanup_eeprom_client;
	}

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(dev, "Failed to register IIO device\n");
		goto err_cleanup_eeprom_regmap;
	}

	i2c_set_clientdata(client, indio_dev);

	return 0;

err_cleanup_eeprom_regmap:
	regmap_exit(priv->eeprom_regmap);

err_cleanup_eeprom_client:
	i2c_unregister_device(priv->eeprom_client);
	return ret;
}

__attribute__((used)) static int hp03_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct hp03_priv *priv = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	regmap_exit(priv->eeprom_regmap);
	i2c_unregister_device(priv->eeprom_client);

	return 0;
}

