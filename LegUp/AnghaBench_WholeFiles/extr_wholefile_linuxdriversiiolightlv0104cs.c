#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct lv0104cs_private {size_t scale; size_t int_time; size_t calibscale; struct i2c_client* client; int /*<<< orphan*/  lock; } ;
struct TYPE_7__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_2__* channels; TYPE_1__ dev; int /*<<< orphan*/  modes; } ;
struct iio_chan_spec {scalar_t__ type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  regval ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_8__ {int val; int val2; int /*<<< orphan*/  regval; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_CALIBSCALE 138 
#define  IIO_CHAN_INFO_INT_TIME 137 
#define  IIO_CHAN_INFO_PROCESSED 136 
#define  IIO_CHAN_INFO_SCALE 135 
 scalar_t__ IIO_LIGHT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 size_t LV0104CS_CALIBSCALE_UNITY ; 
#define  LV0104CS_INTEG_100MS 134 
#define  LV0104CS_INTEG_12_5MS 133 
#define  LV0104CS_INTEG_200MS 132 
 int /*<<< orphan*/  LV0104CS_REGVAL_MEASURE ; 
 int /*<<< orphan*/  LV0104CS_REGVAL_SLEEP ; 
#define  LV0104CS_SCALE_0_25X 131 
#define  LV0104CS_SCALE_1X 130 
#define  LV0104CS_SCALE_2X 129 
#define  LV0104CS_SCALE_8X 128 
 scalar_t__ PAGE_SIZE ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int i2c_master_send (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lv0104cs_private*) ; 
 struct lv0104cs_private* iio_priv (struct iio_dev*) ; 
 TYPE_2__* lv0104cs_calibscales ; 
 TYPE_2__* lv0104cs_channels ; 
 int /*<<< orphan*/  lv0104cs_info ; 
 TYPE_2__* lv0104cs_int_times ; 
 TYPE_2__* lv0104cs_scales ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,int,int) ; 

__attribute__((used)) static int lv0104cs_write_reg(struct i2c_client *client, u8 regval)
{
	int ret;

	ret = i2c_master_send(client, (char *)&regval, sizeof(regval));
	if (ret < 0)
		return ret;
	if (ret != sizeof(regval))
		return -EIO;

	return 0;
}

__attribute__((used)) static int lv0104cs_read_adc(struct i2c_client *client, u16 *adc_output)
{
	__be16 regval;
	int ret;

	ret = i2c_master_recv(client, (char *)&regval, sizeof(regval));
	if (ret < 0)
		return ret;
	if (ret != sizeof(regval))
		return -EIO;

	*adc_output = be16_to_cpu(regval);

	return 0;
}

__attribute__((used)) static int lv0104cs_get_lux(struct lv0104cs_private *lv0104cs,
				int *val, int *val2)
{
	u8 regval = LV0104CS_REGVAL_MEASURE;
	u16 adc_output;
	int ret;

	regval |= lv0104cs_scales[lv0104cs->scale].regval;
	regval |= lv0104cs_int_times[lv0104cs->int_time].regval;
	ret = lv0104cs_write_reg(lv0104cs->client, regval);
	if (ret)
		return ret;

	/* wait for integration time to pass (with margin) */
	switch (lv0104cs->int_time) {
	case LV0104CS_INTEG_12_5MS:
		msleep(50);
		break;

	case LV0104CS_INTEG_100MS:
		msleep(150);
		break;

	case LV0104CS_INTEG_200MS:
		msleep(250);
		break;

	default:
		return -EINVAL;
	}

	ret = lv0104cs_read_adc(lv0104cs->client, &adc_output);
	if (ret)
		return ret;

	ret = lv0104cs_write_reg(lv0104cs->client, LV0104CS_REGVAL_SLEEP);
	if (ret)
		return ret;

	/* convert ADC output to lux */
	switch (lv0104cs->scale) {
	case LV0104CS_SCALE_0_25X:
		*val = adc_output * 4;
		*val2 = 0;
		return 0;

	case LV0104CS_SCALE_1X:
		*val = adc_output;
		*val2 = 0;
		return 0;

	case LV0104CS_SCALE_2X:
		*val = adc_output / 2;
		*val2 = (adc_output % 2) * 500000;
		return 0;

	case LV0104CS_SCALE_8X:
		*val = adc_output / 8;
		*val2 = (adc_output % 8) * 125000;
		return 0;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int lv0104cs_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct lv0104cs_private *lv0104cs = iio_priv(indio_dev);
	int ret;

	if (chan->type != IIO_LIGHT)
		return -EINVAL;

	mutex_lock(&lv0104cs->lock);

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		ret = lv0104cs_get_lux(lv0104cs, val, val2);
		if (ret)
			goto err_mutex;
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;

	case IIO_CHAN_INFO_CALIBSCALE:
		*val = lv0104cs_calibscales[lv0104cs->calibscale].val;
		*val2 = lv0104cs_calibscales[lv0104cs->calibscale].val2;
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;

	case IIO_CHAN_INFO_SCALE:
		*val = lv0104cs_scales[lv0104cs->scale].val;
		*val2 = lv0104cs_scales[lv0104cs->scale].val2;
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;

	case IIO_CHAN_INFO_INT_TIME:
		*val = lv0104cs_int_times[lv0104cs->int_time].val;
		*val2 = lv0104cs_int_times[lv0104cs->int_time].val2;
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;

	default:
		ret = -EINVAL;
	}

err_mutex:
	mutex_unlock(&lv0104cs->lock);

	return ret;
}

__attribute__((used)) static int lv0104cs_set_calibscale(struct lv0104cs_private *lv0104cs,
				int val, int val2)
{
	int calibscale = val * 1000000 + val2;
	int floor, ceil, mid;
	int ret, i, index;

	/* round to nearest quantized calibscale (sensitivity) */
	for (i = 0; i < ARRAY_SIZE(lv0104cs_calibscales) - 1; i++) {
		floor = lv0104cs_calibscales[i].val * 1000000
				+ lv0104cs_calibscales[i].val2;
		ceil = lv0104cs_calibscales[i + 1].val * 1000000
				+ lv0104cs_calibscales[i + 1].val2;
		mid = (floor + ceil) / 2;

		/* round down */
		if (calibscale >= floor && calibscale < mid) {
			index = i;
			break;
		}

		/* round up */
		if (calibscale >= mid && calibscale <= ceil) {
			index = i + 1;
			break;
		}
	}

	if (i == ARRAY_SIZE(lv0104cs_calibscales) - 1)
		return -EINVAL;

	mutex_lock(&lv0104cs->lock);

	/* set calibscale (sensitivity) */
	ret = lv0104cs_write_reg(lv0104cs->client,
			lv0104cs_calibscales[index].regval);
	if (ret)
		goto err_mutex;

	lv0104cs->calibscale = index;

err_mutex:
	mutex_unlock(&lv0104cs->lock);

	return ret;
}

__attribute__((used)) static int lv0104cs_set_scale(struct lv0104cs_private *lv0104cs,
				int val, int val2)
{
	int i;

	/* hard matching */
	for (i = 0; i < ARRAY_SIZE(lv0104cs_scales); i++) {
		if (val != lv0104cs_scales[i].val)
			continue;

		if (val2 == lv0104cs_scales[i].val2)
			break;
	}

	if (i == ARRAY_SIZE(lv0104cs_scales))
		return -EINVAL;

	mutex_lock(&lv0104cs->lock);
	lv0104cs->scale = i;
	mutex_unlock(&lv0104cs->lock);

	return 0;
}

__attribute__((used)) static int lv0104cs_set_int_time(struct lv0104cs_private *lv0104cs,
				int val, int val2)
{
	int i;

	/* hard matching */
	for (i = 0; i < ARRAY_SIZE(lv0104cs_int_times); i++) {
		if (val != lv0104cs_int_times[i].val)
			continue;

		if (val2 == lv0104cs_int_times[i].val2)
			break;
	}

	if (i == ARRAY_SIZE(lv0104cs_int_times))
		return -EINVAL;

	mutex_lock(&lv0104cs->lock);
	lv0104cs->int_time = i;
	mutex_unlock(&lv0104cs->lock);

	return 0;
}

__attribute__((used)) static int lv0104cs_write_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int val, int val2, long mask)
{
	struct lv0104cs_private *lv0104cs = iio_priv(indio_dev);

	if (chan->type != IIO_LIGHT)
		return -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_CALIBSCALE:
		return lv0104cs_set_calibscale(lv0104cs, val, val2);

	case IIO_CHAN_INFO_SCALE:
		return lv0104cs_set_scale(lv0104cs, val, val2);

	case IIO_CHAN_INFO_INT_TIME:
		return lv0104cs_set_int_time(lv0104cs, val, val2);

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static ssize_t lv0104cs_show_calibscale_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(lv0104cs_calibscales); i++) {
		len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06d ",
				lv0104cs_calibscales[i].val,
				lv0104cs_calibscales[i].val2);
	}

	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static ssize_t lv0104cs_show_scale_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(lv0104cs_scales); i++) {
		len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06d ",
				lv0104cs_scales[i].val,
				lv0104cs_scales[i].val2);
	}

	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static ssize_t lv0104cs_show_int_time_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(lv0104cs_int_times); i++) {
		len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06d ",
				lv0104cs_int_times[i].val,
				lv0104cs_int_times[i].val2);
	}

	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static int lv0104cs_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct lv0104cs_private *lv0104cs;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*lv0104cs));
	if (!indio_dev)
		return -ENOMEM;

	lv0104cs = iio_priv(indio_dev);

	i2c_set_clientdata(client, lv0104cs);
	lv0104cs->client = client;

	mutex_init(&lv0104cs->lock);

	lv0104cs->calibscale = LV0104CS_CALIBSCALE_UNITY;
	lv0104cs->scale = LV0104CS_SCALE_1X;
	lv0104cs->int_time = LV0104CS_INTEG_200MS;

	ret = lv0104cs_write_reg(lv0104cs->client,
			lv0104cs_calibscales[LV0104CS_CALIBSCALE_UNITY].regval);
	if (ret)
		return ret;

	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = lv0104cs_channels;
	indio_dev->num_channels = ARRAY_SIZE(lv0104cs_channels);
	indio_dev->name = client->name;
	indio_dev->info = &lv0104cs_info;

	return devm_iio_device_register(&client->dev, indio_dev);
}

