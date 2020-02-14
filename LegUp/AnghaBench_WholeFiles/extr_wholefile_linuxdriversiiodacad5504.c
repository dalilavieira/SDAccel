#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct spi_transfer {int len; void** rx_buf; void** tx_buf; } ;
struct TYPE_11__ {struct ad5504_platform_data* platform_data; } ;
struct spi_device {scalar_t__ irq; TYPE_4__ dev; } ;
struct regulator {int dummy; } ;
struct TYPE_9__ {TYPE_4__* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_2__ dev; } ;
struct TYPE_8__ {int realbits; } ;
struct iio_chan_spec {int channel; int /*<<< orphan*/  address; TYPE_1__ scan_type; } ;
struct ad5504_state {int vref_mv; int pwr_down_mode; int pwr_down_mask; struct regulator* reg; struct spi_device* spi; void** data; } ;
struct ad5504_platform_data {int vref_mv; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {scalar_t__ driver_data; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int AD5504_ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AD5504_ADDR_CTRL ; 
 int /*<<< orphan*/  AD5504_ADDR_NOOP ; 
 int AD5504_CMD_READ ; 
 int AD5504_CMD_WRITE ; 
 int AD5504_DAC_PWR (int) ; 
 int AD5504_DAC_PWRDWN_MODE (unsigned int) ; 
 int AD5504_RES_MASK ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ ID_AD5501 ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int /*<<< orphan*/  IIO_EV_DIR_RISING ; 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
 int /*<<< orphan*/  IIO_TEMP ; 
 int /*<<< orphan*/  IIO_UNMOD_EVENT_CODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IS_ERR (struct regulator*) ; 
 int /*<<< orphan*/  ad5504_channels ; 
 int /*<<< orphan*/  ad5504_info ; 
 int be16_to_cpu (void*) ; 
 void* cpu_to_be16 (int) ; 
 int /*<<< orphan*/  dev_warn (TYPE_4__*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_4__*,int) ; 
 struct regulator* devm_regulator_get (TYPE_4__*,char*) ; 
 int devm_request_threaded_irq (TYPE_4__*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (void*) ; 
 struct ad5504_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regulator_disable (struct regulator*) ; 
 int regulator_enable (struct regulator*) ; 
 int regulator_get_voltage (struct regulator*) ; 
 TYPE_3__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int) ; 
 int spi_write (struct spi_device*,void**,int) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 

__attribute__((used)) static int ad5504_spi_write(struct ad5504_state *st, u8 addr, u16 val)
{
	st->data[0] = cpu_to_be16(AD5504_CMD_WRITE | AD5504_ADDR(addr) |
			      (val & AD5504_RES_MASK));

	return spi_write(st->spi, &st->data[0], 2);
}

__attribute__((used)) static int ad5504_spi_read(struct ad5504_state *st, u8 addr)
{
	int ret;
	struct spi_transfer t = {
	    .tx_buf = &st->data[0],
	    .rx_buf = &st->data[1],
	    .len = 2,
	};

	st->data[0] = cpu_to_be16(AD5504_CMD_READ | AD5504_ADDR(addr));
	ret = spi_sync_transfer(st->spi, &t, 1);
	if (ret < 0)
		return ret;

	return be16_to_cpu(st->data[1]) & AD5504_RES_MASK;
}

__attribute__((used)) static int ad5504_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val,
			   int *val2,
			   long m)
{
	struct ad5504_state *st = iio_priv(indio_dev);
	int ret;

	switch (m) {
	case IIO_CHAN_INFO_RAW:
		ret = ad5504_spi_read(st, chan->address);
		if (ret < 0)
			return ret;

		*val = ret;

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = st->vref_mv;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	}
	return -EINVAL;
}

__attribute__((used)) static int ad5504_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       int val,
			       int val2,
			       long mask)
{
	struct ad5504_state *st = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val >= (1 << chan->scan_type.realbits) || val < 0)
			return -EINVAL;

		return ad5504_spi_write(st, chan->address, val);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int ad5504_get_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan)
{
	struct ad5504_state *st = iio_priv(indio_dev);

	return st->pwr_down_mode;
}

__attribute__((used)) static int ad5504_set_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, unsigned int mode)
{
	struct ad5504_state *st = iio_priv(indio_dev);

	st->pwr_down_mode = mode;

	return 0;
}

__attribute__((used)) static ssize_t ad5504_read_dac_powerdown(struct iio_dev *indio_dev,
	uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
	struct ad5504_state *st = iio_priv(indio_dev);

	return sprintf(buf, "%d\n",
			!(st->pwr_down_mask & (1 << chan->channel)));
}

__attribute__((used)) static ssize_t ad5504_write_dac_powerdown(struct iio_dev *indio_dev,
	uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
	size_t len)
{
	bool pwr_down;
	int ret;
	struct ad5504_state *st = iio_priv(indio_dev);

	ret = strtobool(buf, &pwr_down);
	if (ret)
		return ret;

	if (pwr_down)
		st->pwr_down_mask |= (1 << chan->channel);
	else
		st->pwr_down_mask &= ~(1 << chan->channel);

	ret = ad5504_spi_write(st, AD5504_ADDR_CTRL,
				AD5504_DAC_PWRDWN_MODE(st->pwr_down_mode) |
				AD5504_DAC_PWR(st->pwr_down_mask));

	/* writes to the CTRL register must be followed by a NOOP */
	ad5504_spi_write(st, AD5504_ADDR_NOOP, 0);

	return ret ? ret : len;
}

__attribute__((used)) static irqreturn_t ad5504_event_handler(int irq, void *private)
{
	iio_push_event(private,
		       IIO_UNMOD_EVENT_CODE(IIO_TEMP,
					    0,
					    IIO_EV_TYPE_THRESH,
					    IIO_EV_DIR_RISING),
		       iio_get_time_ns(private));

	return IRQ_HANDLED;
}

__attribute__((used)) static int ad5504_probe(struct spi_device *spi)
{
	struct ad5504_platform_data *pdata = spi->dev.platform_data;
	struct iio_dev *indio_dev;
	struct ad5504_state *st;
	struct regulator *reg;
	int ret, voltage_uv = 0;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;
	reg = devm_regulator_get(&spi->dev, "vcc");
	if (!IS_ERR(reg)) {
		ret = regulator_enable(reg);
		if (ret)
			return ret;

		ret = regulator_get_voltage(reg);
		if (ret < 0)
			goto error_disable_reg;

		voltage_uv = ret;
	}

	spi_set_drvdata(spi, indio_dev);
	st = iio_priv(indio_dev);
	if (voltage_uv)
		st->vref_mv = voltage_uv / 1000;
	else if (pdata)
		st->vref_mv = pdata->vref_mv;
	else
		dev_warn(&spi->dev, "reference voltage unspecified\n");

	st->reg = reg;
	st->spi = spi;
	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = spi_get_device_id(st->spi)->name;
	indio_dev->info = &ad5504_info;
	if (spi_get_device_id(st->spi)->driver_data == ID_AD5501)
		indio_dev->num_channels = 1;
	else
		indio_dev->num_channels = 4;
	indio_dev->channels = ad5504_channels;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (spi->irq) {
		ret = devm_request_threaded_irq(&spi->dev, spi->irq,
					   NULL,
					   &ad5504_event_handler,
					   IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
					   spi_get_device_id(st->spi)->name,
					   indio_dev);
		if (ret)
			goto error_disable_reg;
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_disable_reg;

	return 0;

error_disable_reg:
	if (!IS_ERR(reg))
		regulator_disable(reg);

	return ret;
}

__attribute__((used)) static int ad5504_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ad5504_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	if (!IS_ERR(st->reg))
		regulator_disable(st->reg);

	return 0;
}

