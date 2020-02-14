#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct spi_transfer {int len; int* rx_buf; int* tx_buf; } ;
struct device {TYPE_1__* platform_data; } ;
struct spi_device {unsigned int max_speed_hz; int /*<<< orphan*/  mode; struct device dev; } ;
struct iio_dev_attr {unsigned char address; } ;
struct TYPE_5__ {struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; struct gpio* channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_2__ dev; } ;
struct iio_chan_spec {int type; } ;
struct gpio {unsigned long member_1; char* member_2; int /*<<< orphan*/  member_0; } ;
struct device_attribute {int dummy; } ;
struct ad2s1210_state {int mode; int* tx; int* rx; int fexcit; int fclkin; int resolution; int hysteresis; struct spi_device* sdev; int /*<<< orphan*/  lock; TYPE_1__* pdata; } ;
typedef  int ssize_t ;
typedef  int s16 ;
typedef  enum ad2s1210_mode { ____Placeholder_ad2s1210_mode } ad2s1210_mode ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_6__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int /*<<< orphan*/ * res; int /*<<< orphan*/ * a; int /*<<< orphan*/  sample; scalar_t__ gpioin; } ;

/* Variables and functions */
 unsigned char AD2S1210_DEF_CONTROL ; 
 unsigned int AD2S1210_DEF_EXCIT ; 
 unsigned char AD2S1210_ENABLE_HYSTERESIS ; 
 unsigned int AD2S1210_MAX_CLKIN ; 
 unsigned int AD2S1210_MAX_EXCIT ; 
 unsigned char AD2S1210_MAX_FCW ; 
 unsigned int AD2S1210_MIN_CLKIN ; 
 unsigned int AD2S1210_MIN_EXCIT ; 
 unsigned char AD2S1210_MIN_FCW ; 
 unsigned char AD2S1210_MSB_IS_HIGH ; 
 unsigned char AD2S1210_MSB_IS_LOW ; 
 void* AD2S1210_REG_CONTROL ; 
 int AD2S1210_REG_EXCIT_FREQ ; 
 void* AD2S1210_REG_FAULT ; 
 int AD2S1210_REG_SOFT_RESET ; 
 unsigned char AD2S1210_SET_RESOLUTION ; 
 int /*<<< orphan*/  ARRAY_SIZE (struct gpio*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ERANGE ; 
 unsigned long GPIOF_DIR_IN ; 
 unsigned long GPIOF_DIR_OUT ; 
#define  IIO_ANGL 129 
#define  IIO_ANGL_VEL 128 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 void* MOD_CONFIG ; 
 int MOD_POS ; 
 int MOD_VEL ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 struct gpio* ad2s1210_channels ; 
 int /*<<< orphan*/  ad2s1210_info ; 
 int** ad2s1210_mode_vals ; 
 int** ad2s1210_res_pins ; 
 unsigned char* ad2s1210_resolution_value ; 
 int be16_to_cpup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int /*<<< orphan*/  gpio_free_array (struct gpio*,int /*<<< orphan*/ ) ; 
 int gpio_get_value (int /*<<< orphan*/ ) ; 
 int gpio_request_array (struct gpio*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ad2s1210_state* iio_priv (struct iio_dev*) ; 
 int kstrtou8 (char const*,int,unsigned char*) ; 
 int kstrtouint (char const*,int,unsigned int*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_3__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int spi_read (struct spi_device*,int*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int sprintf (char*,char*,int) ; 
 struct iio_dev_attr* to_iio_dev_attr (struct device_attribute*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void ad2s1210_set_mode(enum ad2s1210_mode mode,
				     struct ad2s1210_state *st)
{
	gpio_set_value(st->pdata->a[0], ad2s1210_mode_vals[mode][0]);
	gpio_set_value(st->pdata->a[1], ad2s1210_mode_vals[mode][1]);
	st->mode = mode;
}

__attribute__((used)) static int ad2s1210_config_write(struct ad2s1210_state *st, u8 data)
{
	int ret;

	ad2s1210_set_mode(MOD_CONFIG, st);
	st->tx[0] = data;
	ret = spi_write(st->sdev, st->tx, 1);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int ad2s1210_config_read(struct ad2s1210_state *st,
				unsigned char address)
{
	struct spi_transfer xfer = {
		.len = 2,
		.rx_buf = st->rx,
		.tx_buf = st->tx,
	};
	int ret = 0;

	ad2s1210_set_mode(MOD_CONFIG, st);
	st->tx[0] = address | AD2S1210_MSB_IS_HIGH;
	st->tx[1] = AD2S1210_REG_FAULT;
	ret = spi_sync_transfer(st->sdev, &xfer, 1);
	if (ret < 0)
		return ret;

	return st->rx[1];
}

__attribute__((used)) static inline
int ad2s1210_update_frequency_control_word(struct ad2s1210_state *st)
{
	int ret;
	unsigned char fcw;

	fcw = (unsigned char)(st->fexcit * (1 << 15) / st->fclkin);
	if (fcw < AD2S1210_MIN_FCW || fcw > AD2S1210_MAX_FCW) {
		dev_err(&st->sdev->dev, "ad2s1210: FCW out of range\n");
		return -ERANGE;
	}

	ret = ad2s1210_config_write(st, AD2S1210_REG_EXCIT_FREQ);
	if (ret < 0)
		return ret;

	return ad2s1210_config_write(st, fcw);
}

__attribute__((used)) static unsigned char ad2s1210_read_resolution_pin(struct ad2s1210_state *st)
{
	int resolution = (gpio_get_value(st->pdata->res[0]) << 1) |
			  gpio_get_value(st->pdata->res[1]);

	return ad2s1210_resolution_value[resolution];
}

__attribute__((used)) static inline void ad2s1210_set_resolution_pin(struct ad2s1210_state *st)
{
	gpio_set_value(st->pdata->res[0],
		       ad2s1210_res_pins[(st->resolution - 10) / 2][0]);
	gpio_set_value(st->pdata->res[1],
		       ad2s1210_res_pins[(st->resolution - 10) / 2][1]);
}

__attribute__((used)) static inline int ad2s1210_soft_reset(struct ad2s1210_state *st)
{
	int ret;

	ret = ad2s1210_config_write(st, AD2S1210_REG_SOFT_RESET);
	if (ret < 0)
		return ret;

	return ad2s1210_config_write(st, 0x0);
}

__attribute__((used)) static ssize_t ad2s1210_show_fclkin(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));

	return sprintf(buf, "%u\n", st->fclkin);
}

__attribute__((used)) static ssize_t ad2s1210_store_fclkin(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf,
				     size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	unsigned int fclkin;
	int ret;

	ret = kstrtouint(buf, 10, &fclkin);
	if (ret)
		return ret;
	if (fclkin < AD2S1210_MIN_CLKIN || fclkin > AD2S1210_MAX_CLKIN) {
		dev_err(dev, "ad2s1210: fclkin out of range\n");
		return -EINVAL;
	}

	mutex_lock(&st->lock);
	st->fclkin = fclkin;

	ret = ad2s1210_update_frequency_control_word(st);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_soft_reset(st);
error_ret:
	mutex_unlock(&st->lock);

	return ret < 0 ? ret : len;
}

__attribute__((used)) static ssize_t ad2s1210_show_fexcit(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));

	return sprintf(buf, "%u\n", st->fexcit);
}

__attribute__((used)) static ssize_t ad2s1210_store_fexcit(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf, size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	unsigned int fexcit;
	int ret;

	ret = kstrtouint(buf, 10, &fexcit);
	if (ret < 0)
		return ret;
	if (fexcit < AD2S1210_MIN_EXCIT || fexcit > AD2S1210_MAX_EXCIT) {
		dev_err(dev,
			"ad2s1210: excitation frequency out of range\n");
		return -EINVAL;
	}
	mutex_lock(&st->lock);
	st->fexcit = fexcit;
	ret = ad2s1210_update_frequency_control_word(st);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_soft_reset(st);
error_ret:
	mutex_unlock(&st->lock);

	return ret < 0 ? ret : len;
}

__attribute__((used)) static ssize_t ad2s1210_show_control(struct device *dev,
				     struct device_attribute *attr,
				     char *buf)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	int ret;

	mutex_lock(&st->lock);
	ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
	mutex_unlock(&st->lock);
	return ret < 0 ? ret : sprintf(buf, "0x%x\n", ret);
}

__attribute__((used)) static ssize_t ad2s1210_store_control(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	unsigned char udata;
	unsigned char data;
	int ret;

	ret = kstrtou8(buf, 16, &udata);
	if (ret)
		return -EINVAL;

	mutex_lock(&st->lock);
	ret = ad2s1210_config_write(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;
	data = udata & AD2S1210_MSB_IS_LOW;
	ret = ad2s1210_config_write(st, data);
	if (ret < 0)
		goto error_ret;

	ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;
	if (ret & AD2S1210_MSB_IS_HIGH) {
		ret = -EIO;
		dev_err(dev,
			"ad2s1210: write control register fail\n");
		goto error_ret;
	}
	st->resolution
		= ad2s1210_resolution_value[data & AD2S1210_SET_RESOLUTION];
	if (st->pdata->gpioin) {
		data = ad2s1210_read_resolution_pin(st);
		if (data != st->resolution)
			dev_warn(dev, "ad2s1210: resolution settings not match\n");
	} else {
		ad2s1210_set_resolution_pin(st);
	}
	ret = len;
	st->hysteresis = !!(data & AD2S1210_ENABLE_HYSTERESIS);

error_ret:
	mutex_unlock(&st->lock);
	return ret;
}

__attribute__((used)) static ssize_t ad2s1210_show_resolution(struct device *dev,
					struct device_attribute *attr,
					char *buf)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));

	return sprintf(buf, "%d\n", st->resolution);
}

__attribute__((used)) static ssize_t ad2s1210_store_resolution(struct device *dev,
					 struct device_attribute *attr,
					 const char *buf, size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	unsigned char data;
	unsigned char udata;
	int ret;

	ret = kstrtou8(buf, 10, &udata);
	if (ret || udata < 10 || udata > 16) {
		dev_err(dev, "ad2s1210: resolution out of range\n");
		return -EINVAL;
	}
	mutex_lock(&st->lock);
	ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;
	data = ret;
	data &= ~AD2S1210_SET_RESOLUTION;
	data |= (udata - 10) >> 1;
	ret = ad2s1210_config_write(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_config_write(st, data & AD2S1210_MSB_IS_LOW);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;
	data = ret;
	if (data & AD2S1210_MSB_IS_HIGH) {
		ret = -EIO;
		dev_err(dev, "ad2s1210: setting resolution fail\n");
		goto error_ret;
	}
	st->resolution
		= ad2s1210_resolution_value[data & AD2S1210_SET_RESOLUTION];
	if (st->pdata->gpioin) {
		data = ad2s1210_read_resolution_pin(st);
		if (data != st->resolution)
			dev_warn(dev, "ad2s1210: resolution settings not match\n");
	} else {
		ad2s1210_set_resolution_pin(st);
	}
	ret = len;
error_ret:
	mutex_unlock(&st->lock);
	return ret;
}

__attribute__((used)) static ssize_t ad2s1210_show_fault(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	int ret;

	mutex_lock(&st->lock);
	ret = ad2s1210_config_read(st, AD2S1210_REG_FAULT);
	mutex_unlock(&st->lock);

	return ret ? ret : sprintf(buf, "0x%x\n", ret);
}

__attribute__((used)) static ssize_t ad2s1210_clear_fault(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf,
				    size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	int ret;

	mutex_lock(&st->lock);
	gpio_set_value(st->pdata->sample, 0);
	/* delay (2 * tck + 20) nano seconds */
	udelay(1);
	gpio_set_value(st->pdata->sample, 1);
	ret = ad2s1210_config_read(st, AD2S1210_REG_FAULT);
	if (ret < 0)
		goto error_ret;
	gpio_set_value(st->pdata->sample, 0);
	gpio_set_value(st->pdata->sample, 1);
error_ret:
	mutex_unlock(&st->lock);

	return ret < 0 ? ret : len;
}

__attribute__((used)) static ssize_t ad2s1210_show_reg(struct device *dev,
				 struct device_attribute *attr,
				 char *buf)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	struct iio_dev_attr *iattr = to_iio_dev_attr(attr);
	int ret;

	mutex_lock(&st->lock);
	ret = ad2s1210_config_read(st, iattr->address);
	mutex_unlock(&st->lock);

	return ret < 0 ? ret : sprintf(buf, "%d\n", ret);
}

__attribute__((used)) static ssize_t ad2s1210_store_reg(struct device *dev,
				  struct device_attribute *attr,
				  const char *buf, size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	unsigned char data;
	int ret;
	struct iio_dev_attr *iattr = to_iio_dev_attr(attr);

	ret = kstrtou8(buf, 10, &data);
	if (ret)
		return -EINVAL;
	mutex_lock(&st->lock);
	ret = ad2s1210_config_write(st, iattr->address);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_config_write(st, data & AD2S1210_MSB_IS_LOW);
error_ret:
	mutex_unlock(&st->lock);
	return ret < 0 ? ret : len;
}

__attribute__((used)) static int ad2s1210_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val,
			     int *val2,
			     long m)
{
	struct ad2s1210_state *st = iio_priv(indio_dev);
	u16 negative;
	int ret = 0;
	u16 pos;
	s16 vel;

	mutex_lock(&st->lock);
	gpio_set_value(st->pdata->sample, 0);
	/* delay (6 * tck + 20) nano seconds */
	udelay(1);

	switch (chan->type) {
	case IIO_ANGL:
		ad2s1210_set_mode(MOD_POS, st);
		break;
	case IIO_ANGL_VEL:
		ad2s1210_set_mode(MOD_VEL, st);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	if (ret < 0)
		goto error_ret;
	ret = spi_read(st->sdev, st->rx, 2);
	if (ret < 0)
		goto error_ret;

	switch (chan->type) {
	case IIO_ANGL:
		pos = be16_to_cpup((__be16 *)st->rx);
		if (st->hysteresis)
			pos >>= 16 - st->resolution;
		*val = pos;
		ret = IIO_VAL_INT;
		break;
	case IIO_ANGL_VEL:
		negative = st->rx[0] & 0x80;
		vel = be16_to_cpup((__be16 *)st->rx);
		vel >>= 16 - st->resolution;
		if (vel & 0x8000) {
			negative = (0xffff >> st->resolution) << st->resolution;
			vel |= negative;
		}
		*val = vel;
		ret = IIO_VAL_INT;
		break;
	default:
		mutex_unlock(&st->lock);
		return -EINVAL;
	}

error_ret:
	gpio_set_value(st->pdata->sample, 1);
	/* delay (2 * tck + 20) nano seconds */
	udelay(1);
	mutex_unlock(&st->lock);
	return ret;
}

__attribute__((used)) static int ad2s1210_initial(struct ad2s1210_state *st)
{
	unsigned char data;
	int ret;

	mutex_lock(&st->lock);
	if (st->pdata->gpioin)
		st->resolution = ad2s1210_read_resolution_pin(st);
	else
		ad2s1210_set_resolution_pin(st);

	ret = ad2s1210_config_write(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;
	data = AD2S1210_DEF_CONTROL & ~(AD2S1210_SET_RESOLUTION);
	data |= (st->resolution - 10) >> 1;
	ret = ad2s1210_config_write(st, data);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
	if (ret < 0)
		goto error_ret;

	if (ret & AD2S1210_MSB_IS_HIGH) {
		ret = -EIO;
		goto error_ret;
	}

	ret = ad2s1210_update_frequency_control_word(st);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_soft_reset(st);
error_ret:
	mutex_unlock(&st->lock);
	return ret;
}

__attribute__((used)) static int ad2s1210_setup_gpios(struct ad2s1210_state *st)
{
	unsigned long flags = st->pdata->gpioin ? GPIOF_DIR_IN : GPIOF_DIR_OUT;
	struct gpio ad2s1210_gpios[] = {
		{ st->pdata->sample, GPIOF_DIR_IN, "sample" },
		{ st->pdata->a[0], flags, "a0" },
		{ st->pdata->a[1], flags, "a1" },
		{ st->pdata->res[0], flags, "res0" },
		{ st->pdata->res[0], flags, "res1" },
	};

	return gpio_request_array(ad2s1210_gpios, ARRAY_SIZE(ad2s1210_gpios));
}

__attribute__((used)) static void ad2s1210_free_gpios(struct ad2s1210_state *st)
{
	unsigned long flags = st->pdata->gpioin ? GPIOF_DIR_IN : GPIOF_DIR_OUT;
	struct gpio ad2s1210_gpios[] = {
		{ st->pdata->sample, GPIOF_DIR_IN, "sample" },
		{ st->pdata->a[0], flags, "a0" },
		{ st->pdata->a[1], flags, "a1" },
		{ st->pdata->res[0], flags, "res0" },
		{ st->pdata->res[0], flags, "res1" },
	};

	gpio_free_array(ad2s1210_gpios, ARRAY_SIZE(ad2s1210_gpios));
}

__attribute__((used)) static int ad2s1210_probe(struct spi_device *spi)
{
	struct iio_dev *indio_dev;
	struct ad2s1210_state *st;
	int ret;

	if (!spi->dev.platform_data)
		return -EINVAL;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;
	st = iio_priv(indio_dev);
	st->pdata = spi->dev.platform_data;
	ret = ad2s1210_setup_gpios(st);
	if (ret < 0)
		return ret;

	spi_set_drvdata(spi, indio_dev);

	mutex_init(&st->lock);
	st->sdev = spi;
	st->hysteresis = true;
	st->mode = MOD_CONFIG;
	st->resolution = 12;
	st->fexcit = AD2S1210_DEF_EXCIT;

	indio_dev->dev.parent = &spi->dev;
	indio_dev->info = &ad2s1210_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = ad2s1210_channels;
	indio_dev->num_channels = ARRAY_SIZE(ad2s1210_channels);
	indio_dev->name = spi_get_device_id(spi)->name;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_free_gpios;

	st->fclkin = spi->max_speed_hz;
	spi->mode = SPI_MODE_3;
	spi_setup(spi);
	ad2s1210_initial(st);

	return 0;

error_free_gpios:
	ad2s1210_free_gpios(st);
	return ret;
}

__attribute__((used)) static int ad2s1210_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);

	iio_device_unregister(indio_dev);
	ad2s1210_free_gpios(iio_priv(indio_dev));

	return 0;
}

