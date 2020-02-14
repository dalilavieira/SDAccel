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
typedef  int u32 ;
struct isl29501_register_desc {scalar_t__ lsb; scalar_t__ msb; } ;
struct isl29501_private {unsigned int* shadow_coeffs; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {unsigned long* active_scan_mask; int** channels; int num_channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  modes; int /*<<< orphan*/  trig; } ;
struct iio_chan_spec {int type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
typedef  int ssize_t ;
typedef  scalar_t__ s32 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum isl29501_register_name { ____Placeholder_isl29501_register_name } isl29501_register_name ;
typedef  enum isl29501_correction_coeff { ____Placeholder_isl29501_correction_coeff } isl29501_correction_coeff ;

/* Variables and functions */
 int ARRAY_SIZE (int**) ; 
#define  COEFF_LIGHT_A 147 
#define  COEFF_LIGHT_B 146 
 int COEFF_MAX ; 
#define  COEFF_TEMP_A 145 
#define  COEFF_TEMP_B 144 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ERANGE ; 
#define  IIO_CHAN_INFO_CALIBBIAS 143 
#define  IIO_CHAN_INFO_INT_TIME 142 
#define  IIO_CHAN_INFO_RAW 141 
#define  IIO_CHAN_INFO_SAMP_FREQ 140 
#define  IIO_CHAN_INFO_SCALE 139 
#define  IIO_CURRENT 138 
#define  IIO_INTENSITY 137 
#define  IIO_PHASE 136 
#define  IIO_PROXIMITY 135 
#define  IIO_TEMP 134 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ ISL29501_COMMAND_REGISTER ; 
 scalar_t__ ISL29501_DEVICE_ID ; 
 int /*<<< orphan*/  ISL29501_DISTANCE_SCAN_INDEX ; 
 int ISL29501_EMUL_SAMPLE_START_PIN ; 
 int ISL29501_ID ; 
 int ISL29501_MAX_EXP_VAL ; 
 int ISL29501_RESET_ALL_REGISTERS ; 
 int ISL29501_RESET_INT_SM ; 
 int REG_AMBIENT_LIGHT ; 
#define  REG_CALIB_PHASE_LIGHT_A 133 
#define  REG_CALIB_PHASE_LIGHT_B 132 
#define  REG_CALIB_PHASE_TEMP_A 131 
#define  REG_CALIB_PHASE_TEMP_B 130 
 int REG_DISTANCE ; 
 int REG_DISTANCE_BIAS ; 
 int REG_DRIVER_RANGE ; 
 int REG_EMITTER_DAC ; 
#define  REG_GAIN 129 
#define  REG_GAIN_BIAS 128 
 int REG_INT_TIME ; 
 int REG_PHASE ; 
 int REG_PHASE_EXP ; 
 int REG_SAMPLE_TIME ; 
 int REG_TEMPERATURE ; 
 int REG_TEMPERATURE_BIAS ; 
 int U16_MAX ; 
 int U8_MAX ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int devm_iio_triggered_buffer_setup (int /*<<< orphan*/ *,struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int do_div (unsigned long long,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 scalar_t__ i2c_smbus_read_byte_data (struct i2c_client*,scalar_t__) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,scalar_t__,int) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct isl29501_private* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int** isl29501_channels ; 
 int** isl29501_current_scale_table ; 
 int /*<<< orphan*/  isl29501_info ; 
 int** isl29501_int_time ; 
 struct isl29501_register_desc* isl29501_registers ; 
 int kstrtouint (char const*,int,unsigned int*) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,unsigned long const*) ; 

__attribute__((used)) static int isl29501_register_read(struct isl29501_private *isl29501,
				  enum isl29501_register_name name,
				  u32 *val)
{
	const struct isl29501_register_desc *reg = &isl29501_registers[name];
	u8 msb = 0, lsb = 0;
	s32 ret;

	mutex_lock(&isl29501->lock);
	if (reg->msb) {
		ret = i2c_smbus_read_byte_data(isl29501->client, reg->msb);
		if (ret < 0)
			goto err;
		msb = ret;
	}

	if (reg->lsb) {
		ret = i2c_smbus_read_byte_data(isl29501->client, reg->lsb);
		if (ret < 0)
			goto err;
		lsb = ret;
	}
	mutex_unlock(&isl29501->lock);

	*val = (msb << 8) + lsb;

	return 0;
err:
	mutex_unlock(&isl29501->lock);

	return ret;
}

__attribute__((used)) static u32 isl29501_register_write(struct isl29501_private *isl29501,
				   enum isl29501_register_name name,
				   u32 value)
{
	const struct isl29501_register_desc *reg = &isl29501_registers[name];
	u8 msb, lsb;
	int ret;

	if (!reg->msb && value > U8_MAX)
		return -ERANGE;

	if (value > U16_MAX)
		return -ERANGE;

	if (!reg->msb) {
		lsb = value & 0xFF;
	} else {
		msb = (value >> 8) & 0xFF;
		lsb = value & 0xFF;
	}

	mutex_lock(&isl29501->lock);
	if (reg->msb) {
		ret = i2c_smbus_write_byte_data(isl29501->client,
						reg->msb, msb);
		if (ret < 0)
			goto err;
	}

	ret = i2c_smbus_write_byte_data(isl29501->client, reg->lsb, lsb);

err:
	mutex_unlock(&isl29501->lock);
	return ret;
}

__attribute__((used)) static ssize_t isl29501_read_ext(struct iio_dev *indio_dev,
				 uintptr_t private,
				 const struct iio_chan_spec *chan,
				 char *buf)
{
	struct isl29501_private *isl29501 = iio_priv(indio_dev);
	enum isl29501_register_name reg = private;
	int ret;
	u32 value, gain, coeff, exp;

	switch (reg) {
	case REG_GAIN:
	case REG_GAIN_BIAS:
		ret = isl29501_register_read(isl29501, reg, &gain);
		if (ret < 0)
			return ret;

		value = gain;
		break;
	case REG_CALIB_PHASE_TEMP_A:
	case REG_CALIB_PHASE_TEMP_B:
	case REG_CALIB_PHASE_LIGHT_A:
	case REG_CALIB_PHASE_LIGHT_B:
		ret = isl29501_register_read(isl29501, REG_PHASE_EXP, &exp);
		if (ret < 0)
			return ret;

		ret = isl29501_register_read(isl29501, reg, &coeff);
		if (ret < 0)
			return ret;

		value = coeff << exp;
		break;
	default:
		return -EINVAL;
	}

	return sprintf(buf, "%u\n", value);
}

__attribute__((used)) static int isl29501_set_shadow_coeff(struct isl29501_private *isl29501,
				     enum isl29501_register_name reg,
				     unsigned int val)
{
	enum isl29501_correction_coeff coeff;

	switch (reg) {
	case REG_CALIB_PHASE_TEMP_A:
		coeff = COEFF_TEMP_A;
		break;
	case REG_CALIB_PHASE_TEMP_B:
		coeff = COEFF_TEMP_B;
		break;
	case REG_CALIB_PHASE_LIGHT_A:
		coeff = COEFF_LIGHT_A;
		break;
	case REG_CALIB_PHASE_LIGHT_B:
		coeff = COEFF_LIGHT_B;
		break;
	default:
		return -EINVAL;
	}
	isl29501->shadow_coeffs[coeff] = val;

	return 0;
}

__attribute__((used)) static int isl29501_write_coeff(struct isl29501_private *isl29501,
				enum isl29501_correction_coeff coeff,
				int val)
{
	enum isl29501_register_name reg;

	switch (coeff) {
	case COEFF_TEMP_A:
		reg = REG_CALIB_PHASE_TEMP_A;
		break;
	case COEFF_TEMP_B:
		reg = REG_CALIB_PHASE_TEMP_B;
		break;
	case COEFF_LIGHT_A:
		reg = REG_CALIB_PHASE_LIGHT_A;
		break;
	case COEFF_LIGHT_B:
		reg = REG_CALIB_PHASE_LIGHT_B;
		break;
	default:
		return -EINVAL;
	}

	return isl29501_register_write(isl29501, reg, val);
}

__attribute__((used)) static unsigned int isl29501_find_corr_exp(unsigned int val,
					   unsigned int max_exp,
					   unsigned int max_mantissa)
{
	unsigned int exp = 1;

	/*
	 * Correction coefficients are represented under
	 * mantissa * 2^exponent form, where mantissa and exponent
	 * are stored in two separate registers of the sensor.
	 *
	 * Compute and return the lowest exponent such as:
	 *	     mantissa = value / 2^exponent
	 *
	 *  where mantissa < max_mantissa.
	 */
	if (val <= max_mantissa)
		return 0;

	while ((val >> exp) > max_mantissa) {
		exp++;

		if (exp > max_exp)
			return max_exp;
	}

	return exp;
}

__attribute__((used)) static ssize_t isl29501_write_ext(struct iio_dev *indio_dev,
				  uintptr_t private,
				  const struct iio_chan_spec *chan,
				  const char *buf, size_t len)
{
	struct isl29501_private *isl29501 = iio_priv(indio_dev);
	enum isl29501_register_name reg = private;
	unsigned int val;
	int max_exp = 0;
	int ret;
	int i;

	ret = kstrtouint(buf, 10, &val);
	if (ret)
		return ret;

	switch (reg) {
	case REG_GAIN_BIAS:
		if (val > U16_MAX)
			return -ERANGE;

		ret = isl29501_register_write(isl29501, reg, val);
		if (ret < 0)
			return ret;

		break;
	case REG_CALIB_PHASE_TEMP_A:
	case REG_CALIB_PHASE_TEMP_B:
	case REG_CALIB_PHASE_LIGHT_A:
	case REG_CALIB_PHASE_LIGHT_B:

		if (val > (U8_MAX << ISL29501_MAX_EXP_VAL))
			return -ERANGE;

		/* Store the correction coefficient under its exact form. */
		ret = isl29501_set_shadow_coeff(isl29501, reg, val);
		if (ret < 0)
			return ret;

		/*
		 * Find the highest exponent needed to represent
		 * correction coefficients.
		 */
		for (i = 0; i < COEFF_MAX; i++) {
			int corr;
			int corr_exp;

			corr = isl29501->shadow_coeffs[i];
			corr_exp = isl29501_find_corr_exp(corr,
							  ISL29501_MAX_EXP_VAL,
							  U8_MAX / 2);
			dev_dbg(&isl29501->client->dev,
				"found exp of corr(%d) = %d\n", corr, corr_exp);

			max_exp = max(max_exp, corr_exp);
		}

		/*
		 * Represent every correction coefficient under
		 * mantissa * 2^max_exponent form and force the
		 * writing of those coefficients on the sensor.
		 */
		for (i = 0; i < COEFF_MAX; i++) {
			int corr;
			int mantissa;

			corr = isl29501->shadow_coeffs[i];
			if (!corr)
				continue;

			mantissa = corr >> max_exp;

			ret = isl29501_write_coeff(isl29501, i, mantissa);
			if (ret < 0)
				return ret;
		}

		ret = isl29501_register_write(isl29501, REG_PHASE_EXP, max_exp);
		if (ret < 0)
			return ret;

		break;
	default:
		return -EINVAL;
	}

	return len;
}

__attribute__((used)) static int isl29501_reset_registers(struct isl29501_private *isl29501)
{
	int ret;

	ret = i2c_smbus_write_byte_data(isl29501->client,
					ISL29501_COMMAND_REGISTER,
					ISL29501_RESET_ALL_REGISTERS);
	if (ret < 0) {
		dev_err(&isl29501->client->dev,
			"cannot reset registers %d\n", ret);
		return ret;
	}

	ret = i2c_smbus_write_byte_data(isl29501->client,
					ISL29501_COMMAND_REGISTER,
					ISL29501_RESET_INT_SM);
	if (ret < 0)
		dev_err(&isl29501->client->dev,
			"cannot reset state machine %d\n", ret);

	return ret;
}

__attribute__((used)) static int isl29501_begin_acquisition(struct isl29501_private *isl29501)
{
	int ret;

	ret = i2c_smbus_write_byte_data(isl29501->client,
					ISL29501_COMMAND_REGISTER,
					ISL29501_EMUL_SAMPLE_START_PIN);
	if (ret < 0)
		dev_err(&isl29501->client->dev,
			"cannot begin acquisition %d\n", ret);

	return ret;
}

__attribute__((used)) static int isl29501_get_raw(struct isl29501_private *isl29501,
			    const struct iio_chan_spec *chan,
			    int *raw)
{
	int ret;

	switch (chan->type) {
	case IIO_PROXIMITY:
		ret = isl29501_register_read(isl29501, REG_DISTANCE, raw);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;
	case IIO_INTENSITY:
		ret = isl29501_register_read(isl29501,
					     REG_AMBIENT_LIGHT,
					     raw);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;
	case IIO_PHASE:
		ret = isl29501_register_read(isl29501, REG_PHASE, raw);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;
	case IIO_CURRENT:
		ret = isl29501_register_read(isl29501, REG_EMITTER_DAC, raw);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;
	case IIO_TEMP:
		ret = isl29501_register_read(isl29501, REG_TEMPERATURE, raw);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_get_scale(struct isl29501_private *isl29501,
			      const struct iio_chan_spec *chan,
			      int *val, int *val2)
{
	int ret;
	u32 current_scale;

	switch (chan->type) {
	case IIO_PROXIMITY:
		/* distance = raw_distance * 33.31 / 65536 (m) */
		*val = 3331;
		*val2 = 6553600;

		return IIO_VAL_FRACTIONAL;
	case IIO_PHASE:
		/* phase = raw_phase * 2pi / 65536 (rad) */
		*val = 0;
		*val2 = 95874;

		return IIO_VAL_INT_PLUS_NANO;
	case IIO_INTENSITY:
		/* light = raw_light * 35 / 10000 (mA) */
		*val = 35;
		*val2 = 10000;

		return IIO_VAL_FRACTIONAL;
	case IIO_CURRENT:
		ret = isl29501_register_read(isl29501,
					     REG_DRIVER_RANGE,
					     &current_scale);
		if (ret < 0)
			return ret;

		if (current_scale > ARRAY_SIZE(isl29501_current_scale_table))
			return -EINVAL;

		if (!current_scale) {
			*val = 0;
			*val2 = 0;
			return IIO_VAL_INT;
		}

		*val = isl29501_current_scale_table[current_scale - 1][0];
		*val2 = isl29501_current_scale_table[current_scale - 1][1];

		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_TEMP:
		/* temperature = raw_temperature * 125 / 100000 (milli °C) */
		*val = 125;
		*val2 = 100000;

		return IIO_VAL_FRACTIONAL;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_get_calibbias(struct isl29501_private *isl29501,
				  const struct iio_chan_spec *chan,
				  int *bias)
{
	switch (chan->type) {
	case IIO_PROXIMITY:
		return isl29501_register_read(isl29501,
					      REG_DISTANCE_BIAS,
					      bias);
	case IIO_TEMP:
		return isl29501_register_read(isl29501,
					      REG_TEMPERATURE_BIAS,
					      bias);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_get_inttime(struct isl29501_private *isl29501,
				int *val, int *val2)
{
	int ret;
	u32 inttime;

	ret = isl29501_register_read(isl29501, REG_INT_TIME, &inttime);
	if (ret < 0)
		return ret;

	if (inttime >= ARRAY_SIZE(isl29501_int_time))
		return -EINVAL;

	*val = isl29501_int_time[inttime][0];
	*val2 = isl29501_int_time[inttime][1];

	return IIO_VAL_INT_PLUS_MICRO;
}

__attribute__((used)) static int isl29501_get_freq(struct isl29501_private *isl29501,
			     int *val, int *val2)
{
	int ret;
	int sample_time;
	unsigned long long freq;
	u32 temp;

	ret = isl29501_register_read(isl29501, REG_SAMPLE_TIME, &sample_time);
	if (ret < 0)
		return ret;

	/* freq = 1 / (0.000450 * (sample_time + 1) * 10^-6) */
	freq = 1000000ULL * 1000000ULL;

	do_div(freq, 450 * (sample_time + 1));

	temp = do_div(freq, 1000000);
	*val = freq;
	*val2 = temp;

	return IIO_VAL_INT_PLUS_MICRO;
}

__attribute__((used)) static int isl29501_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int *val,
			     int *val2, long mask)
{
	struct isl29501_private *isl29501 = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return isl29501_get_raw(isl29501, chan, val);
	case IIO_CHAN_INFO_SCALE:
		return isl29501_get_scale(isl29501, chan, val, val2);
	case IIO_CHAN_INFO_INT_TIME:
		return isl29501_get_inttime(isl29501, val, val2);
	case IIO_CHAN_INFO_SAMP_FREQ:
		return isl29501_get_freq(isl29501, val, val2);
	case IIO_CHAN_INFO_CALIBBIAS:
		return isl29501_get_calibbias(isl29501, chan, val);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_set_raw(struct isl29501_private *isl29501,
			    const struct iio_chan_spec *chan,
			    int raw)
{
	switch (chan->type) {
	case IIO_CURRENT:
		return isl29501_register_write(isl29501, REG_EMITTER_DAC, raw);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_set_inttime(struct isl29501_private *isl29501,
				int val, int val2)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(isl29501_int_time); i++) {
		if (isl29501_int_time[i][0] == val &&
		    isl29501_int_time[i][1] == val2) {
			return isl29501_register_write(isl29501,
						       REG_INT_TIME,
						       i);
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int isl29501_set_scale(struct isl29501_private *isl29501,
			      const struct iio_chan_spec *chan,
			      int val, int val2)
{
	int i;

	if (chan->type != IIO_CURRENT)
		return -EINVAL;

	for (i = 0; i < ARRAY_SIZE(isl29501_current_scale_table); i++) {
		if (isl29501_current_scale_table[i][0] == val &&
		    isl29501_current_scale_table[i][1] == val2) {
			return isl29501_register_write(isl29501,
						       REG_DRIVER_RANGE,
						       i + 1);
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int isl29501_set_calibbias(struct isl29501_private *isl29501,
				  const struct iio_chan_spec *chan,
				  int bias)
{
	switch (chan->type) {
	case IIO_PROXIMITY:
		return isl29501_register_write(isl29501,
					      REG_DISTANCE_BIAS,
					      bias);
	case IIO_TEMP:
		return isl29501_register_write(isl29501,
					       REG_TEMPERATURE_BIAS,
					       bias);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_set_freq(struct isl29501_private *isl29501,
			     int val, int val2)
{
	int freq;
	unsigned long long sample_time;

	/* sample_freq = 1 / (0.000450 * (sample_time + 1) * 10^-6) */
	freq = val * 1000000 + val2 % 1000000;
	sample_time = 2222ULL * 1000000ULL;
	do_div(sample_time, freq);

	sample_time -= 1;

	if (sample_time > 255)
		return -ERANGE;

	return isl29501_register_write(isl29501, REG_SAMPLE_TIME, sample_time);
}

__attribute__((used)) static int isl29501_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int val, int val2, long mask)
{
	struct isl29501_private *isl29501 = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return isl29501_set_raw(isl29501, chan, val);
	case IIO_CHAN_INFO_INT_TIME:
		return isl29501_set_inttime(isl29501, val, val2);
	case IIO_CHAN_INFO_SAMP_FREQ:
		return isl29501_set_freq(isl29501, val, val2);
	case IIO_CHAN_INFO_SCALE:
		return isl29501_set_scale(isl29501, chan, val, val2);
	case IIO_CHAN_INFO_CALIBBIAS:
		return isl29501_set_calibbias(isl29501, chan, val);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int isl29501_init_chip(struct isl29501_private *isl29501)
{
	int ret;

	ret = i2c_smbus_read_byte_data(isl29501->client, ISL29501_DEVICE_ID);
	if (ret < 0) {
		dev_err(&isl29501->client->dev, "Error reading device id\n");
		return ret;
	}

	if (ret != ISL29501_ID) {
		dev_err(&isl29501->client->dev,
			"Wrong chip id, got %x expected %x\n",
			ret, ISL29501_DEVICE_ID);
		return -ENODEV;
	}

	ret = isl29501_reset_registers(isl29501);
	if (ret < 0)
		return ret;

	return isl29501_begin_acquisition(isl29501);
}

__attribute__((used)) static irqreturn_t isl29501_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct isl29501_private *isl29501 = iio_priv(indio_dev);
	const unsigned long *active_mask = indio_dev->active_scan_mask;
	u32 buffer[4] = {}; /* 1x16-bit + ts */

	if (test_bit(ISL29501_DISTANCE_SCAN_INDEX, active_mask))
		isl29501_register_read(isl29501, REG_DISTANCE, buffer);

	iio_push_to_buffers_with_timestamp(indio_dev, buffer, pf->timestamp);
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int isl29501_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct isl29501_private *isl29501;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*isl29501));
	if (!indio_dev)
		return -ENOMEM;

	isl29501 = iio_priv(indio_dev);

	i2c_set_clientdata(client, indio_dev);
	isl29501->client = client;

	mutex_init(&isl29501->lock);

	ret = isl29501_init_chip(isl29501);
	if (ret < 0)
		return ret;

	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = isl29501_channels;
	indio_dev->num_channels = ARRAY_SIZE(isl29501_channels);
	indio_dev->name = client->name;
	indio_dev->info = &isl29501_info;

	ret = devm_iio_triggered_buffer_setup(&client->dev, indio_dev,
					      iio_pollfunc_store_time,
					      isl29501_trigger_handler,
					      NULL);
	if (ret < 0) {
		dev_err(&client->dev, "unable to setup iio triggered buffer\n");
		return ret;
	}

	return devm_iio_device_register(&client->dev, indio_dev);
}

