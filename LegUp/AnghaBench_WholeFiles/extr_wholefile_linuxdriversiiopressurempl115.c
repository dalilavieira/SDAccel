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
typedef  int u16 ;
struct mpl115_ops {int (* write ) (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* read ) (struct device*,int /*<<< orphan*/ ) ;int (* init ) (struct device*) ;} ;
struct mpl115_data {int b1; int c12; int a0; int b2; struct device* dev; struct mpl115_ops const* ops; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {struct device* parent; } ;
struct iio_dev {char const* name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/ * info; } ;
struct iio_chan_spec {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 131 
#define  IIO_CHAN_INFO_PROCESSED 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  MPL115_A0 ; 
 int /*<<< orphan*/  MPL115_B1 ; 
 int /*<<< orphan*/  MPL115_B2 ; 
 int /*<<< orphan*/  MPL115_C12 ; 
 int /*<<< orphan*/  MPL115_CONVERT ; 
 int /*<<< orphan*/  MPL115_PADC ; 
 int /*<<< orphan*/  MPL115_TADC ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 struct mpl115_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mpl115_channels ; 
 int /*<<< orphan*/  mpl115_info ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub2 (struct device*,int /*<<< orphan*/ ) ; 
 int stub3 (struct device*,int /*<<< orphan*/ ) ; 
 int stub4 (struct device*,int /*<<< orphan*/ ) ; 
 int stub5 (struct device*) ; 
 int stub6 (struct device*,int /*<<< orphan*/ ) ; 
 int stub7 (struct device*,int /*<<< orphan*/ ) ; 
 int stub8 (struct device*,int /*<<< orphan*/ ) ; 
 int stub9 (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int mpl115_request(struct mpl115_data *data)
{
	int ret = data->ops->write(data->dev, MPL115_CONVERT, 0);

	if (ret < 0)
		return ret;

	usleep_range(3000, 4000);

	return 0;
}

__attribute__((used)) static int mpl115_comp_pressure(struct mpl115_data *data, int *val, int *val2)
{
	int ret;
	u16 padc, tadc;
	int a1, y1, pcomp;
	unsigned kpa;

	mutex_lock(&data->lock);
	ret = mpl115_request(data);
	if (ret < 0)
		goto done;

	ret = data->ops->read(data->dev, MPL115_PADC);
	if (ret < 0)
		goto done;
	padc = ret >> 6;

	ret = data->ops->read(data->dev, MPL115_TADC);
	if (ret < 0)
		goto done;
	tadc = ret >> 6;

	/* see Freescale AN3785 */
	a1 = data->b1 + ((data->c12 * tadc) >> 11);
	y1 = (data->a0 << 10) + a1 * padc;

	/* compensated pressure with 4 fractional bits */
	pcomp = (y1 + ((data->b2 * (int) tadc) >> 1)) >> 9;

	kpa = pcomp * (115 - 50) / 1023 + (50 << 4);
	*val = kpa >> 4;
	*val2 = (kpa & 15) * (1000000 >> 4);
done:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int mpl115_read_temp(struct mpl115_data *data)
{
	int ret;

	mutex_lock(&data->lock);
	ret = mpl115_request(data);
	if (ret < 0)
		goto done;
	ret = data->ops->read(data->dev, MPL115_TADC);
done:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int mpl115_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mpl115_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		ret = mpl115_comp_pressure(data, val, val2);
		if (ret < 0)
			return ret;
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_RAW:
		/* temperature -5.35 C / LSB, 472 LSB is 25 C */
		ret = mpl115_read_temp(data);
		if (ret < 0)
			return ret;
		*val = ret >> 6;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_OFFSET:
		*val = -605;
		*val2 = 750000;
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SCALE:
		*val = -186;
		*val2 = 915888;
		return IIO_VAL_INT_PLUS_MICRO;
	}
	return -EINVAL;
}

int mpl115_probe(struct device *dev, const char *name,
			const struct mpl115_ops *ops)
{
	struct mpl115_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	data->dev = dev;
	data->ops = ops;
	mutex_init(&data->lock);

	indio_dev->info = &mpl115_info;
	indio_dev->name = name;
	indio_dev->dev.parent = dev;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = mpl115_channels;
	indio_dev->num_channels = ARRAY_SIZE(mpl115_channels);

	ret = data->ops->init(data->dev);
	if (ret)
		return ret;

	ret = data->ops->read(data->dev, MPL115_A0);
	if (ret < 0)
		return ret;
	data->a0 = ret;
	ret = data->ops->read(data->dev, MPL115_B1);
	if (ret < 0)
		return ret;
	data->b1 = ret;
	ret = data->ops->read(data->dev, MPL115_B2);
	if (ret < 0)
		return ret;
	data->b2 = ret;
	ret = data->ops->read(data->dev, MPL115_C12);
	if (ret < 0)
		return ret;
	data->c12 = ret;

	return devm_iio_device_register(dev, indio_dev);
}

