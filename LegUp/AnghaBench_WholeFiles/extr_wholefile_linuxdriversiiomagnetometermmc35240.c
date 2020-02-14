#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct regmap {int dummy; } ;
struct mmc35240_data {unsigned int res; int* axis_coef; int* axis_scale; int /*<<< orphan*/  mutex; struct regmap* regmap; struct i2c_client* client; } ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; TYPE_2__* channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  otp_data ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_8__ {int* sens; int nfo; } ;
struct TYPE_7__ {int val; int val2; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
#define  AXIS_X 143 
#define  AXIS_Y 142 
#define  AXIS_Z 141 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 140 
#define  IIO_CHAN_INFO_SAMP_FREQ 139 
#define  IIO_CHAN_INFO_SCALE 138 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 size_t MMC35240_16_BITS_SLOW ; 
 unsigned int MMC35240_CTRL0_REFILL_BIT ; 
 int MMC35240_CTRL0_RESET_BIT ; 
 int MMC35240_CTRL0_SET_BIT ; 
 int /*<<< orphan*/  MMC35240_CTRL0_TM_BIT ; 
 unsigned int MMC35240_CTRL1_BW_MASK ; 
 unsigned int MMC35240_CTRL1_BW_SHIFT ; 
 int /*<<< orphan*/  MMC35240_DRV_NAME ; 
 int MMC35240_OTP_CONVERT_Y (int) ; 
 int MMC35240_OTP_CONVERT_Z (int) ; 
 int MMC35240_OTP_START_ADDR ; 
#define  MMC35240_REG_CTRL0 137 
#define  MMC35240_REG_CTRL1 136 
#define  MMC35240_REG_ID 135 
#define  MMC35240_REG_STATUS 134 
#define  MMC35240_REG_XOUT_H 133 
#define  MMC35240_REG_XOUT_L 132 
#define  MMC35240_REG_YOUT_H 131 
#define  MMC35240_REG_YOUT_L 130 
#define  MMC35240_REG_ZOUT_H 129 
#define  MMC35240_REG_ZOUT_L 128 
 unsigned int MMC35240_STATUS_MEAS_DONE_BIT ; 
 int MMC35240_WAIT_CHARGE_PUMP ; 
 int MMC35240_X_COEFF (int) ; 
 int MMC35240_Y_COEFF (int) ; 
 int MMC35240_Z_COEFF (int) ; 
 int MMC53240_WAIT_SET_RESET ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 struct mmc35240_data* iio_priv (struct iio_dev*) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 TYPE_2__* mmc35240_channels ; 
 int /*<<< orphan*/  mmc35240_info ; 
 TYPE_3__* mmc35240_props_table ; 
 int /*<<< orphan*/  mmc35240_regmap_config ; 
 TYPE_2__* mmc35240_samp_freq ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (struct regmap*,int,int*,int) ; 
 int regmap_read (struct regmap*,int,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int,unsigned int,int) ; 
 int regmap_write (struct regmap*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int mmc35240_get_samp_freq_index(struct mmc35240_data *data,
					int val, int val2)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(mmc35240_samp_freq); i++)
		if (mmc35240_samp_freq[i].val == val &&
		    mmc35240_samp_freq[i].val2 == val2)
			return i;
	return -EINVAL;
}

__attribute__((used)) static int mmc35240_hw_set(struct mmc35240_data *data, bool set)
{
	int ret;
	u8 coil_bit;

	/*
	 * Recharge the capacitor at VCAP pin, requested to be issued
	 * before a SET/RESET command.
	 */
	ret = regmap_update_bits(data->regmap, MMC35240_REG_CTRL0,
				 MMC35240_CTRL0_REFILL_BIT,
				 MMC35240_CTRL0_REFILL_BIT);
	if (ret < 0)
		return ret;
	usleep_range(MMC35240_WAIT_CHARGE_PUMP, MMC35240_WAIT_CHARGE_PUMP + 1);

	if (set)
		coil_bit = MMC35240_CTRL0_SET_BIT;
	else
		coil_bit = MMC35240_CTRL0_RESET_BIT;

	return regmap_update_bits(data->regmap, MMC35240_REG_CTRL0,
				  coil_bit, coil_bit);

}

__attribute__((used)) static int mmc35240_init(struct mmc35240_data *data)
{
	int ret, y_convert, z_convert;
	unsigned int reg_id;
	u8 otp_data[6];

	ret = regmap_read(data->regmap, MMC35240_REG_ID, &reg_id);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading product id\n");
		return ret;
	}

	dev_dbg(&data->client->dev, "MMC35240 chip id %x\n", reg_id);

	/*
	 * make sure we restore sensor characteristics, by doing
	 * a SET/RESET sequence, the axis polarity being naturally
	 * aligned after RESET
	 */
	ret = mmc35240_hw_set(data, true);
	if (ret < 0)
		return ret;
	usleep_range(MMC53240_WAIT_SET_RESET, MMC53240_WAIT_SET_RESET + 1);

	ret = mmc35240_hw_set(data, false);
	if (ret < 0)
		return ret;

	/* set default sampling frequency */
	ret = regmap_update_bits(data->regmap, MMC35240_REG_CTRL1,
				 MMC35240_CTRL1_BW_MASK,
				 data->res << MMC35240_CTRL1_BW_SHIFT);
	if (ret < 0)
		return ret;

	ret = regmap_bulk_read(data->regmap, MMC35240_OTP_START_ADDR,
			       (u8 *)otp_data, sizeof(otp_data));
	if (ret < 0)
		return ret;

	y_convert = MMC35240_OTP_CONVERT_Y(((otp_data[1] & 0x03) << 4) |
					   (otp_data[2] >> 4));
	z_convert = MMC35240_OTP_CONVERT_Z(otp_data[3] & 0x3f);

	data->axis_coef[0] = MMC35240_X_COEFF(1);
	data->axis_coef[1] = MMC35240_Y_COEFF(y_convert);
	data->axis_coef[2] = MMC35240_Z_COEFF(z_convert);

	data->axis_scale[0] = 1;
	data->axis_scale[1] = 1000;
	data->axis_scale[2] = 10000;

	return 0;
}

__attribute__((used)) static int mmc35240_take_measurement(struct mmc35240_data *data)
{
	int ret, tries = 100;
	unsigned int reg_status;

	ret = regmap_write(data->regmap, MMC35240_REG_CTRL0,
			   MMC35240_CTRL0_TM_BIT);
	if (ret < 0)
		return ret;

	while (tries-- > 0) {
		ret = regmap_read(data->regmap, MMC35240_REG_STATUS,
				  &reg_status);
		if (ret < 0)
			return ret;
		if (reg_status & MMC35240_STATUS_MEAS_DONE_BIT)
			break;
		/* minimum wait time to complete measurement is 10 ms */
		usleep_range(10000, 11000);
	}

	if (tries < 0) {
		dev_err(&data->client->dev, "data not ready\n");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int mmc35240_read_measurement(struct mmc35240_data *data, __le16 buf[3])
{
	int ret;

	ret = mmc35240_take_measurement(data);
	if (ret < 0)
		return ret;

	return regmap_bulk_read(data->regmap, MMC35240_REG_XOUT_L, (u8 *)buf,
				3 * sizeof(__le16));
}

__attribute__((used)) static int mmc35240_raw_to_mgauss(struct mmc35240_data *data, int index,
				  __le16 buf[], int *val)
{
	int raw[3];
	int sens[3];
	int nfo;

	raw[AXIS_X] = le16_to_cpu(buf[AXIS_X]);
	raw[AXIS_Y] = le16_to_cpu(buf[AXIS_Y]);
	raw[AXIS_Z] = le16_to_cpu(buf[AXIS_Z]);

	sens[AXIS_X] = mmc35240_props_table[data->res].sens[AXIS_X];
	sens[AXIS_Y] = mmc35240_props_table[data->res].sens[AXIS_Y];
	sens[AXIS_Z] = mmc35240_props_table[data->res].sens[AXIS_Z];

	nfo = mmc35240_props_table[data->res].nfo;

	switch (index) {
	case AXIS_X:
		*val = (raw[AXIS_X] - nfo) * 1000 / sens[AXIS_X];
		break;
	case AXIS_Y:
		*val = (raw[AXIS_Y] - nfo) * 1000 / sens[AXIS_Y] -
			(raw[AXIS_Z] - nfo)  * 1000 / sens[AXIS_Z];
		break;
	case AXIS_Z:
		*val = (raw[AXIS_Y] - nfo) * 1000 / sens[AXIS_Y] +
			(raw[AXIS_Z] - nfo) * 1000 / sens[AXIS_Z];
		break;
	default:
		return -EINVAL;
	}
	/* apply OTP compensation */
	*val = (*val) * data->axis_coef[index] / data->axis_scale[index];

	return 0;
}

__attribute__((used)) static int mmc35240_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int *val,
			     int *val2, long mask)
{
	struct mmc35240_data *data = iio_priv(indio_dev);
	int ret, i;
	unsigned int reg;
	__le16 buf[3];

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&data->mutex);
		ret = mmc35240_read_measurement(data, buf);
		mutex_unlock(&data->mutex);
		if (ret < 0)
			return ret;
		ret = mmc35240_raw_to_mgauss(data, chan->address, buf, val);
		if (ret < 0)
			return ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = 1000;
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&data->mutex);
		ret = regmap_read(data->regmap, MMC35240_REG_CTRL1, &reg);
		mutex_unlock(&data->mutex);
		if (ret < 0)
			return ret;

		i = (reg & MMC35240_CTRL1_BW_MASK) >> MMC35240_CTRL1_BW_SHIFT;
		if (i < 0 || i >= ARRAY_SIZE(mmc35240_samp_freq))
			return -EINVAL;

		*val = mmc35240_samp_freq[i].val;
		*val2 = mmc35240_samp_freq[i].val2;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mmc35240_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan, int val,
			      int val2, long mask)
{
	struct mmc35240_data *data = iio_priv(indio_dev);
	int i, ret;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		i = mmc35240_get_samp_freq_index(data, val, val2);
		if (i < 0)
			return -EINVAL;
		mutex_lock(&data->mutex);
		ret = regmap_update_bits(data->regmap, MMC35240_REG_CTRL1,
					 MMC35240_CTRL1_BW_MASK,
					 i << MMC35240_CTRL1_BW_SHIFT);
		mutex_unlock(&data->mutex);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static bool mmc35240_is_writeable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MMC35240_REG_CTRL0:
	case MMC35240_REG_CTRL1:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool mmc35240_is_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MMC35240_REG_XOUT_L:
	case MMC35240_REG_XOUT_H:
	case MMC35240_REG_YOUT_L:
	case MMC35240_REG_YOUT_H:
	case MMC35240_REG_ZOUT_L:
	case MMC35240_REG_ZOUT_H:
	case MMC35240_REG_STATUS:
	case MMC35240_REG_ID:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool mmc35240_is_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MMC35240_REG_CTRL0:
	case MMC35240_REG_CTRL1:
		return false;
	default:
		return true;
	}
}

__attribute__((used)) static int mmc35240_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct mmc35240_data *data;
	struct iio_dev *indio_dev;
	struct regmap *regmap;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	regmap = devm_regmap_init_i2c(client, &mmc35240_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "regmap initialization failed\n");
		return PTR_ERR(regmap);
	}

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	data->regmap = regmap;
	data->res = MMC35240_16_BITS_SLOW;

	mutex_init(&data->mutex);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &mmc35240_info;
	indio_dev->name = MMC35240_DRV_NAME;
	indio_dev->channels = mmc35240_channels;
	indio_dev->num_channels = ARRAY_SIZE(mmc35240_channels);
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = mmc35240_init(data);
	if (ret < 0) {
		dev_err(&client->dev, "mmc35240 chip init failed\n");
		return ret;
	}
	return devm_iio_device_register(&client->dev, indio_dev);
}

