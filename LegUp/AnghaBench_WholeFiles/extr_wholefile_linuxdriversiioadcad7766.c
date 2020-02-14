#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;

/* Type definitions */
struct spi_device_id {size_t driver_data; int /*<<< orphan*/  name; } ;
struct spi_device {scalar_t__ irq; int /*<<< orphan*/  dev; } ;
struct regulator {int dummy; } ;
struct iio_trigger {int dummy; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct TYPE_16__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  id; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; int /*<<< orphan*/  num_channels; TYPE_5__* channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  trig; } ;
struct TYPE_18__ {int realbits; } ;
struct iio_chan_spec {TYPE_3__ scan_type; } ;
struct TYPE_19__ {int len; int /*<<< orphan*/ * rx_buf; } ;
struct ad7766 {int /*<<< orphan*/  msg; TYPE_4__ xfer; int /*<<< orphan*/ * data; struct spi_device* spi; TYPE_7__* trig; int /*<<< orphan*/  pd_gpio; TYPE_5__* reg; int /*<<< orphan*/  mclk; TYPE_12__* chip_info; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_17__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_21__ {TYPE_2__ dev; int /*<<< orphan*/ * ops; } ;
struct TYPE_20__ {char* supply; struct regulator* consumer; } ;
struct TYPE_15__ {int decimation_factor; } ;

/* Variables and functions */
 size_t AD7766_SUPPLY_AVDD ; 
 size_t AD7766_SUPPLY_DVDD ; 
 size_t AD7766_SUPPLY_VREF ; 
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_5__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
#define  IIO_CHAN_INFO_SAMP_FREQ 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ad7766_buffer_setup_ops ; 
 TYPE_5__* ad7766_channels ; 
 TYPE_12__* ad7766_chip_info ; 
 int /*<<< orphan*/  ad7766_info ; 
 int /*<<< orphan*/  ad7766_trigger_ops ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_get_rate (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  devm_gpiod_get_optional (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 TYPE_7__* devm_iio_trigger_alloc (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_iio_trigger_register (int /*<<< orphan*/ *,TYPE_7__*) ; 
 int devm_iio_triggered_buffer_setup (int /*<<< orphan*/ *,struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int devm_regulator_bulk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_5__*) ; 
 int devm_request_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_7__*) ; 
 int /*<<< orphan*/  disable_irq (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 int /*<<< orphan*/  gpiod_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct ad7766* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct ad7766* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_poll (void*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_7__*,struct ad7766*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int regulator_bulk_enable (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int regulator_get_voltage (struct regulator*) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_message_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync (struct spi_device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t ad7766_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct ad7766 *ad7766 = iio_priv(indio_dev);
	int ret;

	ret = spi_sync(ad7766->spi, &ad7766->msg);
	if (ret < 0)
		goto done;

	iio_push_to_buffers_with_timestamp(indio_dev, ad7766->data,
		pf->timestamp);
done:
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ad7766_preenable(struct iio_dev *indio_dev)
{
	struct ad7766 *ad7766 = iio_priv(indio_dev);
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(ad7766->reg), ad7766->reg);
	if (ret < 0) {
		dev_err(&ad7766->spi->dev, "Failed to enable supplies: %d\n",
			ret);
		return ret;
	}

	ret = clk_prepare_enable(ad7766->mclk);
	if (ret < 0) {
		dev_err(&ad7766->spi->dev, "Failed to enable MCLK: %d\n", ret);
		regulator_bulk_disable(ARRAY_SIZE(ad7766->reg), ad7766->reg);
		return ret;
	}

	gpiod_set_value(ad7766->pd_gpio, 0);

	return 0;
}

__attribute__((used)) static int ad7766_postdisable(struct iio_dev *indio_dev)
{
	struct ad7766 *ad7766 = iio_priv(indio_dev);

	gpiod_set_value(ad7766->pd_gpio, 1);

	/*
	 * The PD pin is synchronous to the clock, so give it some time to
	 * notice the change before we disable the clock.
	 */
	msleep(20);

	clk_disable_unprepare(ad7766->mclk);
	regulator_bulk_disable(ARRAY_SIZE(ad7766->reg), ad7766->reg);

	return 0;
}

__attribute__((used)) static int ad7766_read_raw(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, int *val, int *val2, long info)
{
	struct ad7766 *ad7766 = iio_priv(indio_dev);
	struct regulator *vref = ad7766->reg[AD7766_SUPPLY_VREF].consumer;
	int scale_uv;

	switch (info) {
	case IIO_CHAN_INFO_SCALE:
		scale_uv = regulator_get_voltage(vref);
		if (scale_uv < 0)
			return scale_uv;
		*val = scale_uv / 1000;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = clk_get_rate(ad7766->mclk) /
			ad7766->chip_info->decimation_factor;
		return IIO_VAL_INT;
	}
	return -EINVAL;
}

__attribute__((used)) static irqreturn_t ad7766_irq(int irq, void *private)
{
	iio_trigger_poll(private);
	return IRQ_HANDLED;
}

__attribute__((used)) static int ad7766_set_trigger_state(struct iio_trigger *trig, bool enable)
{
	struct ad7766 *ad7766 = iio_trigger_get_drvdata(trig);

	if (enable)
		enable_irq(ad7766->spi->irq);
	else
		disable_irq(ad7766->spi->irq);

	return 0;
}

__attribute__((used)) static int ad7766_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct iio_dev *indio_dev;
	struct ad7766 *ad7766;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*ad7766));
	if (!indio_dev)
		return -ENOMEM;

	ad7766 = iio_priv(indio_dev);
	ad7766->chip_info = &ad7766_chip_info[id->driver_data];

	ad7766->mclk = devm_clk_get(&spi->dev, "mclk");
	if (IS_ERR(ad7766->mclk))
		return PTR_ERR(ad7766->mclk);

	ad7766->reg[AD7766_SUPPLY_AVDD].supply = "avdd";
	ad7766->reg[AD7766_SUPPLY_DVDD].supply = "dvdd";
	ad7766->reg[AD7766_SUPPLY_VREF].supply = "vref";

	ret = devm_regulator_bulk_get(&spi->dev, ARRAY_SIZE(ad7766->reg),
		ad7766->reg);
	if (ret)
		return ret;

	ad7766->pd_gpio = devm_gpiod_get_optional(&spi->dev, "powerdown",
		GPIOD_OUT_HIGH);
	if (IS_ERR(ad7766->pd_gpio))
		return PTR_ERR(ad7766->pd_gpio);

	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = spi_get_device_id(spi)->name;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = ad7766_channels;
	indio_dev->num_channels = ARRAY_SIZE(ad7766_channels);
	indio_dev->info = &ad7766_info;

	if (spi->irq > 0) {
		ad7766->trig = devm_iio_trigger_alloc(&spi->dev, "%s-dev%d",
			indio_dev->name, indio_dev->id);
		if (!ad7766->trig)
			return -ENOMEM;

		ad7766->trig->ops = &ad7766_trigger_ops;
		ad7766->trig->dev.parent = &spi->dev;
		iio_trigger_set_drvdata(ad7766->trig, ad7766);

		ret = devm_request_irq(&spi->dev, spi->irq, ad7766_irq,
			IRQF_TRIGGER_FALLING, dev_name(&spi->dev),
			ad7766->trig);
		if (ret < 0)
			return ret;

		/*
		 * The device generates interrupts as long as it is powered up.
		 * Some platforms might not allow the option to power it down so
		 * disable the interrupt to avoid extra load on the system
		 */
		disable_irq(spi->irq);

		ret = devm_iio_trigger_register(&spi->dev, ad7766->trig);
		if (ret)
			return ret;
	}

	spi_set_drvdata(spi, indio_dev);

	ad7766->spi = spi;

	/* First byte always 0 */
	ad7766->xfer.rx_buf = &ad7766->data[1];
	ad7766->xfer.len = 3;

	spi_message_init(&ad7766->msg);
	spi_message_add_tail(&ad7766->xfer, &ad7766->msg);

	ret = devm_iio_triggered_buffer_setup(&spi->dev, indio_dev,
		&iio_pollfunc_store_time, &ad7766_trigger_handler,
		&ad7766_buffer_setup_ops);
	if (ret)
		return ret;

	ret = devm_iio_device_register(&spi->dev, indio_dev);
	if (ret)
		return ret;
	return 0;
}

