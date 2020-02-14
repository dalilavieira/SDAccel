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
struct ms5611_state {int (* reset ) (struct device*) ;int (* read_prom_word ) (struct device*,int,int*) ;int (* read_adc_temp_and_pressure ) (struct device*,int*,int*) ;struct i2c_client* client; struct ms5611_osr* pressure_osr; struct ms5611_osr* temp_osr; } ;
struct ms5611_osr {unsigned long conv_usec; int /*<<< orphan*/  cmd; } ;
struct iio_dev {int dummy; } ;
struct i2c_device_id {int /*<<< orphan*/  driver_data; int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct device {int dummy; } ;
typedef  int s32 ;

/* Variables and functions */
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int I2C_FUNC_SMBUS_READ_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_READ_WORD_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 int /*<<< orphan*/  MS5611_READ_ADC ; 
 scalar_t__ MS5611_READ_PROM_WORD ; 
 int /*<<< orphan*/  MS5611_RESET ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,int*) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,scalar_t__) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 struct ms5611_state* iio_priv (struct iio_dev*) ; 
 int ms5611_probe (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ms5611_remove (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (unsigned long,unsigned long) ; 

__attribute__((used)) static int ms5611_i2c_reset(struct device *dev)
{
	struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));

	return i2c_smbus_write_byte(st->client, MS5611_RESET);
}

__attribute__((used)) static int ms5611_i2c_read_prom_word(struct device *dev, int index, u16 *word)
{
	int ret;
	struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));

	ret = i2c_smbus_read_word_swapped(st->client,
			MS5611_READ_PROM_WORD + (index << 1));
	if (ret < 0)
		return ret;

	*word = ret;

	return 0;
}

__attribute__((used)) static int ms5611_i2c_read_adc(struct ms5611_state *st, s32 *val)
{
	int ret;
	u8 buf[3];

	ret = i2c_smbus_read_i2c_block_data(st->client, MS5611_READ_ADC,
					    3, buf);
	if (ret < 0)
		return ret;

	*val = (buf[0] << 16) | (buf[1] << 8) | buf[2];

	return 0;
}

__attribute__((used)) static int ms5611_i2c_read_adc_temp_and_pressure(struct device *dev,
						 s32 *temp, s32 *pressure)
{
	int ret;
	struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
	const struct ms5611_osr *osr = st->temp_osr;

	ret = i2c_smbus_write_byte(st->client, osr->cmd);
	if (ret < 0)
		return ret;

	usleep_range(osr->conv_usec, osr->conv_usec + (osr->conv_usec / 10UL));
	ret = ms5611_i2c_read_adc(st, temp);
	if (ret < 0)
		return ret;

	osr = st->pressure_osr;
	ret = i2c_smbus_write_byte(st->client, osr->cmd);
	if (ret < 0)
		return ret;

	usleep_range(osr->conv_usec, osr->conv_usec + (osr->conv_usec / 10UL));
	return ms5611_i2c_read_adc(st, pressure);
}

__attribute__((used)) static int ms5611_i2c_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct ms5611_state *st;
	struct iio_dev *indio_dev;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_WRITE_BYTE |
				     I2C_FUNC_SMBUS_READ_WORD_DATA |
				     I2C_FUNC_SMBUS_READ_I2C_BLOCK))
		return -EOPNOTSUPP;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;

	st = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	st->reset = ms5611_i2c_reset;
	st->read_prom_word = ms5611_i2c_read_prom_word;
	st->read_adc_temp_and_pressure = ms5611_i2c_read_adc_temp_and_pressure;
	st->client = client;

	return ms5611_probe(indio_dev, &client->dev, id->name, id->driver_data);
}

__attribute__((used)) static int ms5611_i2c_remove(struct i2c_client *client)
{
	return ms5611_remove(i2c_get_clientdata(client));
}

