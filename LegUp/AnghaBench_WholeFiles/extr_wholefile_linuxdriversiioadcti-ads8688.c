#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u32 ;
typedef  int u16 ;
struct spi_transfer {int scale; int offset; int len; int cs_change; int reg; size_t range; int /*<<< orphan*/ * rx_buf; int /*<<< orphan*/ * tx_buf; } ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {TYPE_4__ dev; int /*<<< orphan*/  mode; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; TYPE_4__* parent; } ;
struct iio_dev {int masklength; int /*<<< orphan*/ * info; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; TYPE_2__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  trig; int /*<<< orphan*/  active_scan_mask; } ;
struct iio_chan_spec {unsigned int channel; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct ads8688_state {int vref_mv; size_t* range; int /*<<< orphan*/  reg; int /*<<< orphan*/  lock; TYPE_7__* chip_info; struct spi_device* spi; TYPE_1__* data; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum ads8688_range { ____Placeholder_ads8688_range } ads8688_range ;
struct TYPE_12__ {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; } ;
struct TYPE_10__ {size_t driver_data; int /*<<< orphan*/  name; } ;
struct TYPE_8__ {void* d32; int /*<<< orphan*/ * d8; } ;

/* Variables and functions */
 unsigned int ADS8688_CMD_DONT_CARE_BITS ; 
 unsigned int ADS8688_CMD_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ADS8688_CMD_REG_MAN_CH (unsigned int) ; 
 int /*<<< orphan*/  ADS8688_CMD_REG_NOOP ; 
 int /*<<< orphan*/  ADS8688_CMD_REG_RST ; 
 int /*<<< orphan*/  ADS8688_MAX_CHANNELS ; 
 size_t ADS8688_PLUSMINUS25VREF ; 
 unsigned int ADS8688_PROG_DONT_CARE_BITS ; 
 unsigned int ADS8688_PROG_REG (unsigned int) ; 
 unsigned int ADS8688_PROG_REG_RANGE_CH (size_t) ; 
 unsigned int ADS8688_PROG_WR_BIT ; 
 int ADS8688_VREF_MV ; 
 int ARRAY_SIZE (struct spi_transfer*) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPI_MODE_1 ; 
 TYPE_7__* ads8688_chip_info_tbl ; 
 int /*<<< orphan*/  ads8688_info ; 
 struct spi_transfer* ads8688_range_def ; 
 int be32_to_cpu (void*) ; 
 void* cpu_to_be32 (unsigned int) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_4__*,int) ; 
 int /*<<< orphan*/  devm_regulator_get_optional (TYPE_4__*,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ads8688_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 TYPE_3__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int) ; 
 int spi_write (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int,...) ; 
 int /*<<< orphan*/  test_bit (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t ads8688_show_scales(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct ads8688_state *st = iio_priv(dev_to_iio_dev(dev));

	return sprintf(buf, "0.%09u 0.%09u 0.%09u\n",
		       ads8688_range_def[0].scale * st->vref_mv,
		       ads8688_range_def[1].scale * st->vref_mv,
		       ads8688_range_def[2].scale * st->vref_mv);
}

__attribute__((used)) static ssize_t ads8688_show_offsets(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d %d\n", ads8688_range_def[0].offset,
		       ads8688_range_def[3].offset);
}

__attribute__((used)) static int ads8688_prog_write(struct iio_dev *indio_dev, unsigned int addr,
			      unsigned int val)
{
	struct ads8688_state *st = iio_priv(indio_dev);
	u32 tmp;

	tmp = ADS8688_PROG_REG(addr) | ADS8688_PROG_WR_BIT | val;
	tmp <<= ADS8688_PROG_DONT_CARE_BITS;
	st->data[0].d32 = cpu_to_be32(tmp);

	return spi_write(st->spi, &st->data[0].d8[1], 3);
}

__attribute__((used)) static int ads8688_reset(struct iio_dev *indio_dev)
{
	struct ads8688_state *st = iio_priv(indio_dev);
	u32 tmp;

	tmp = ADS8688_CMD_REG(ADS8688_CMD_REG_RST);
	tmp <<= ADS8688_CMD_DONT_CARE_BITS;
	st->data[0].d32 = cpu_to_be32(tmp);

	return spi_write(st->spi, &st->data[0].d8[0], 4);
}

__attribute__((used)) static int ads8688_read(struct iio_dev *indio_dev, unsigned int chan)
{
	struct ads8688_state *st = iio_priv(indio_dev);
	int ret;
	u32 tmp;
	struct spi_transfer t[] = {
		{
			.tx_buf = &st->data[0].d8[0],
			.len = 4,
			.cs_change = 1,
		}, {
			.tx_buf = &st->data[1].d8[0],
			.rx_buf = &st->data[1].d8[0],
			.len = 4,
		},
	};

	tmp = ADS8688_CMD_REG(ADS8688_CMD_REG_MAN_CH(chan));
	tmp <<= ADS8688_CMD_DONT_CARE_BITS;
	st->data[0].d32 = cpu_to_be32(tmp);

	tmp = ADS8688_CMD_REG(ADS8688_CMD_REG_NOOP);
	tmp <<= ADS8688_CMD_DONT_CARE_BITS;
	st->data[1].d32 = cpu_to_be32(tmp);

	ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
	if (ret < 0)
		return ret;

	return be32_to_cpu(st->data[1].d32) & 0xffff;
}

__attribute__((used)) static int ads8688_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long m)
{
	int ret, offset;
	unsigned long scale_mv;

	struct ads8688_state *st = iio_priv(indio_dev);

	mutex_lock(&st->lock);
	switch (m) {
	case IIO_CHAN_INFO_RAW:
		ret = ads8688_read(indio_dev, chan->channel);
		mutex_unlock(&st->lock);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		scale_mv = st->vref_mv;
		scale_mv *= ads8688_range_def[st->range[chan->channel]].scale;
		*val = 0;
		*val2 = scale_mv;
		mutex_unlock(&st->lock);
		return IIO_VAL_INT_PLUS_NANO;
	case IIO_CHAN_INFO_OFFSET:
		offset = ads8688_range_def[st->range[chan->channel]].offset;
		*val = offset;
		mutex_unlock(&st->lock);
		return IIO_VAL_INT;
	}
	mutex_unlock(&st->lock);

	return -EINVAL;
}

__attribute__((used)) static int ads8688_write_reg_range(struct iio_dev *indio_dev,
				   struct iio_chan_spec const *chan,
				   enum ads8688_range range)
{
	unsigned int tmp;
	int ret;

	tmp = ADS8688_PROG_REG_RANGE_CH(chan->channel);
	ret = ads8688_prog_write(indio_dev, tmp, range);

	return ret;
}

__attribute__((used)) static int ads8688_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct ads8688_state *st = iio_priv(indio_dev);
	unsigned int scale = 0;
	int ret = -EINVAL, i, offset = 0;

	mutex_lock(&st->lock);
	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		/* If the offset is 0 the ±2.5 * VREF mode is not available */
		offset = ads8688_range_def[st->range[chan->channel]].offset;
		if (offset == 0 && val2 == ads8688_range_def[0].scale * st->vref_mv) {
			mutex_unlock(&st->lock);
			return -EINVAL;
		}

		/* Lookup new mode */
		for (i = 0; i < ARRAY_SIZE(ads8688_range_def); i++)
			if (val2 == ads8688_range_def[i].scale * st->vref_mv &&
			    offset == ads8688_range_def[i].offset) {
				ret = ads8688_write_reg_range(indio_dev, chan,
					ads8688_range_def[i].reg);
				break;
			}
		break;
	case IIO_CHAN_INFO_OFFSET:
		/*
		 * There are only two available offsets:
		 * 0 and -(1 << (ADS8688_REALBITS - 1))
		 */
		if (!(ads8688_range_def[0].offset == val ||
		    ads8688_range_def[3].offset == val)) {
			mutex_unlock(&st->lock);
			return -EINVAL;
		}

		/*
		 * If the device are in ±2.5 * VREF mode, it's not allowed to
		 * switch to a mode where the offset is 0
		 */
		if (val == 0 &&
		    st->range[chan->channel] == ADS8688_PLUSMINUS25VREF) {
			mutex_unlock(&st->lock);
			return -EINVAL;
		}

		scale = ads8688_range_def[st->range[chan->channel]].scale;

		/* Lookup new mode */
		for (i = 0; i < ARRAY_SIZE(ads8688_range_def); i++)
			if (val == ads8688_range_def[i].offset &&
			    scale == ads8688_range_def[i].scale) {
				ret = ads8688_write_reg_range(indio_dev, chan,
					ads8688_range_def[i].reg);
				break;
			}
		break;
	}

	if (!ret)
		st->range[chan->channel] = ads8688_range_def[i].range;

	mutex_unlock(&st->lock);

	return ret;
}

__attribute__((used)) static int ads8688_write_raw_get_fmt(struct iio_dev *indio_dev,
				     struct iio_chan_spec const *chan,
				     long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		return IIO_VAL_INT_PLUS_NANO;
	case IIO_CHAN_INFO_OFFSET:
		return IIO_VAL_INT;
	}

	return -EINVAL;
}

__attribute__((used)) static irqreturn_t ads8688_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	u16 buffer[ADS8688_MAX_CHANNELS + sizeof(s64)/sizeof(u16)];
	int i, j = 0;

	for (i = 0; i < indio_dev->masklength; i++) {
		if (!test_bit(i, indio_dev->active_scan_mask))
			continue;
		buffer[j] = ads8688_read(indio_dev, i);
		j++;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, buffer,
			pf->timestamp);

	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ads8688_probe(struct spi_device *spi)
{
	struct ads8688_state *st;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (indio_dev == NULL)
		return -ENOMEM;

	st = iio_priv(indio_dev);

	st->reg = devm_regulator_get_optional(&spi->dev, "vref");
	if (!IS_ERR(st->reg)) {
		ret = regulator_enable(st->reg);
		if (ret)
			return ret;

		ret = regulator_get_voltage(st->reg);
		if (ret < 0)
			goto err_regulator_disable;

		st->vref_mv = ret / 1000;
	} else {
		/* Use internal reference */
		st->vref_mv = ADS8688_VREF_MV;
	}

	st->chip_info =	&ads8688_chip_info_tbl[spi_get_device_id(spi)->driver_data];

	spi->mode = SPI_MODE_1;

	spi_set_drvdata(spi, indio_dev);

	st->spi = spi;

	indio_dev->name = spi_get_device_id(spi)->name;
	indio_dev->dev.parent = &spi->dev;
	indio_dev->dev.of_node = spi->dev.of_node;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = st->chip_info->channels;
	indio_dev->num_channels = st->chip_info->num_channels;
	indio_dev->info = &ads8688_info;

	ads8688_reset(indio_dev);

	mutex_init(&st->lock);

	ret = iio_triggered_buffer_setup(indio_dev, NULL, ads8688_trigger_handler, NULL);
	if (ret < 0) {
		dev_err(&spi->dev, "iio triggered buffer setup failed\n");
		goto err_regulator_disable;
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto err_buffer_cleanup;

	return 0;

err_buffer_cleanup:
	iio_triggered_buffer_cleanup(indio_dev);

err_regulator_disable:
	if (!IS_ERR(st->reg))
		regulator_disable(st->reg);

	return ret;
}

__attribute__((used)) static int ads8688_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ads8688_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);

	if (!IS_ERR(st->reg))
		regulator_disable(st->reg);

	return 0;
}

