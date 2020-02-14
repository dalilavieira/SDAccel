#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct spi_transfer {int* tx_buf; unsigned int len; int cs_change; int* rx_buf; } ;
struct spi_message {int dummy; } ;
struct spi_device {int irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  master; } ;
struct TYPE_8__ {int /*<<< orphan*/ * parent; } ;
struct iio_trigger {TYPE_4__ dev; int /*<<< orphan*/ * ops; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct iio_dev {int /*<<< orphan*/  trig; int /*<<< orphan*/  name; int /*<<< orphan*/  id; TYPE_3__* channels; int /*<<< orphan*/  masklength; int /*<<< orphan*/  active_scan_mask; int /*<<< orphan*/  mlock; } ;
struct TYPE_5__ {unsigned int realbits; unsigned int shift; } ;
struct iio_chan_spec {unsigned int address; TYPE_1__ scan_type; } ;
struct ad_sigma_delta_info {unsigned int addr_shift; int read_mask; scalar_t__ has_registers; } ;
struct ad_sigma_delta {int comm; int* data; int bus_locked; int irq_dis; struct ad_sigma_delta_info const* info; struct spi_device* spi; struct iio_trigger* trig; int /*<<< orphan*/  completion; } ;
struct ad_sd_calib_data {unsigned int mode; unsigned int channel; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {unsigned int realbits; unsigned int shift; } ;
struct TYPE_7__ {unsigned int address; TYPE_2__ scan_type; } ;

/* Variables and functions */
 int AD_SD_COMM_CHAN_MASK ; 
 unsigned int AD_SD_MODE_CONTINUOUS ; 
 unsigned int AD_SD_MODE_IDLE ; 
 unsigned int AD_SD_MODE_SINGLE ; 
 unsigned int AD_SD_REG_DATA ; 
 unsigned int DIV_ROUND_UP (unsigned int,int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  ad_sd_buffer_setup_ops ; 
 int /*<<< orphan*/  ad_sd_trigger_ops ; 
 int ad_sigma_delta_postprocess_sample (struct ad_sigma_delta*,unsigned int) ; 
 int ad_sigma_delta_set_channel (struct ad_sigma_delta*,unsigned int) ; 
 int ad_sigma_delta_set_mode (struct ad_sigma_delta*,unsigned int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  disable_irq_nosync (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 unsigned int find_first_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,struct ad_sigma_delta*) ; 
 unsigned int get_unaligned_be16 (int*) ; 
 unsigned int get_unaligned_be32 (int*) ; 
 scalar_t__ iio_buffer_enabled (struct iio_dev*) ; 
 struct ad_sigma_delta* iio_device_get_drvdata (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_set_drvdata (struct iio_dev*,struct ad_sigma_delta*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 struct iio_trigger* iio_trigger_alloc (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_free (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_get (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_poll (struct iio_trigger*) ; 
 int iio_trigger_register (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct ad_sigma_delta*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_postenable (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int* kcalloc (unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_unaligned_be16 (unsigned int,int*) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ad_sigma_delta*) ; 
 int /*<<< orphan*/  spi_bus_lock (int /*<<< orphan*/ ) ; 
 int spi_bus_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int spi_sync_locked (struct spi_device*,struct spi_message*) ; 
 int spi_write (struct spi_device*,int*,unsigned int) ; 
 int wait_for_completion_interruptible_timeout (int /*<<< orphan*/ *,int) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int) ; 

void ad_sd_set_comm(struct ad_sigma_delta *sigma_delta, uint8_t comm)
{
	/* Some variants use the lower two bits of the communications register
	 * to select the channel */
	sigma_delta->comm = comm & AD_SD_COMM_CHAN_MASK;
}

int ad_sd_write_reg(struct ad_sigma_delta *sigma_delta, unsigned int reg,
	unsigned int size, unsigned int val)
{
	uint8_t *data = sigma_delta->data;
	struct spi_transfer t = {
		.tx_buf		= data,
		.len		= size + 1,
		.cs_change	= sigma_delta->bus_locked,
	};
	struct spi_message m;
	int ret;

	data[0] = (reg << sigma_delta->info->addr_shift) | sigma_delta->comm;

	switch (size) {
	case 3:
		data[1] = val >> 16;
		data[2] = val >> 8;
		data[3] = val;
		break;
	case 2:
		put_unaligned_be16(val, &data[1]);
		break;
	case 1:
		data[1] = val;
		break;
	case 0:
		break;
	default:
		return -EINVAL;
	}

	spi_message_init(&m);
	spi_message_add_tail(&t, &m);

	if (sigma_delta->bus_locked)
		ret = spi_sync_locked(sigma_delta->spi, &m);
	else
		ret = spi_sync(sigma_delta->spi, &m);

	return ret;
}

__attribute__((used)) static int ad_sd_read_reg_raw(struct ad_sigma_delta *sigma_delta,
	unsigned int reg, unsigned int size, uint8_t *val)
{
	uint8_t *data = sigma_delta->data;
	int ret;
	struct spi_transfer t[] = {
		{
			.tx_buf = data,
			.len = 1,
		}, {
			.rx_buf = val,
			.len = size,
			.cs_change = sigma_delta->bus_locked,
		},
	};
	struct spi_message m;

	spi_message_init(&m);

	if (sigma_delta->info->has_registers) {
		data[0] = reg << sigma_delta->info->addr_shift;
		data[0] |= sigma_delta->info->read_mask;
		data[0] |= sigma_delta->comm;
		spi_message_add_tail(&t[0], &m);
	}
	spi_message_add_tail(&t[1], &m);

	if (sigma_delta->bus_locked)
		ret = spi_sync_locked(sigma_delta->spi, &m);
	else
		ret = spi_sync(sigma_delta->spi, &m);

	return ret;
}

int ad_sd_read_reg(struct ad_sigma_delta *sigma_delta,
	unsigned int reg, unsigned int size, unsigned int *val)
{
	int ret;

	ret = ad_sd_read_reg_raw(sigma_delta, reg, size, sigma_delta->data);
	if (ret < 0)
		goto out;

	switch (size) {
	case 4:
		*val = get_unaligned_be32(sigma_delta->data);
		break;
	case 3:
		*val = (sigma_delta->data[0] << 16) |
			(sigma_delta->data[1] << 8) |
			sigma_delta->data[2];
		break;
	case 2:
		*val = get_unaligned_be16(sigma_delta->data);
		break;
	case 1:
		*val = sigma_delta->data[0];
		break;
	default:
		ret = -EINVAL;
		break;
	}

out:
	return ret;
}

int ad_sd_reset(struct ad_sigma_delta *sigma_delta,
	unsigned int reset_length)
{
	uint8_t *buf;
	unsigned int size;
	int ret;

	size = DIV_ROUND_UP(reset_length, 8);
	buf = kcalloc(size, sizeof(*buf), GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	memset(buf, 0xff, size);
	ret = spi_write(sigma_delta->spi, buf, size);
	kfree(buf);

	return ret;
}

__attribute__((used)) static int ad_sd_calibrate(struct ad_sigma_delta *sigma_delta,
	unsigned int mode, unsigned int channel)
{
	int ret;
	unsigned long timeout;

	ret = ad_sigma_delta_set_channel(sigma_delta, channel);
	if (ret)
		return ret;

	spi_bus_lock(sigma_delta->spi->master);
	sigma_delta->bus_locked = true;
	reinit_completion(&sigma_delta->completion);

	ret = ad_sigma_delta_set_mode(sigma_delta, mode);
	if (ret < 0)
		goto out;

	sigma_delta->irq_dis = false;
	enable_irq(sigma_delta->spi->irq);
	timeout = wait_for_completion_timeout(&sigma_delta->completion, 2 * HZ);
	if (timeout == 0) {
		sigma_delta->irq_dis = true;
		disable_irq_nosync(sigma_delta->spi->irq);
		ret = -EIO;
	} else {
		ret = 0;
	}
out:
	sigma_delta->bus_locked = false;
	spi_bus_unlock(sigma_delta->spi->master);
	ad_sigma_delta_set_mode(sigma_delta, AD_SD_MODE_IDLE);

	return ret;
}

int ad_sd_calibrate_all(struct ad_sigma_delta *sigma_delta,
	const struct ad_sd_calib_data *cb, unsigned int n)
{
	unsigned int i;
	int ret;

	for (i = 0; i < n; i++) {
		ret = ad_sd_calibrate(sigma_delta, cb[i].mode, cb[i].channel);
		if (ret)
			return ret;
	}

	return 0;
}

int ad_sigma_delta_single_conversion(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, int *val)
{
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);
	unsigned int sample, raw_sample;
	int ret = 0;

	if (iio_buffer_enabled(indio_dev))
		return -EBUSY;

	mutex_lock(&indio_dev->mlock);
	ad_sigma_delta_set_channel(sigma_delta, chan->address);

	spi_bus_lock(sigma_delta->spi->master);
	sigma_delta->bus_locked = true;
	reinit_completion(&sigma_delta->completion);

	ad_sigma_delta_set_mode(sigma_delta, AD_SD_MODE_SINGLE);

	sigma_delta->irq_dis = false;
	enable_irq(sigma_delta->spi->irq);
	ret = wait_for_completion_interruptible_timeout(
			&sigma_delta->completion, HZ);

	sigma_delta->bus_locked = false;
	spi_bus_unlock(sigma_delta->spi->master);

	if (ret == 0)
		ret = -EIO;
	if (ret < 0)
		goto out;

	ret = ad_sd_read_reg(sigma_delta, AD_SD_REG_DATA,
		DIV_ROUND_UP(chan->scan_type.realbits + chan->scan_type.shift, 8),
		&raw_sample);

out:
	if (!sigma_delta->irq_dis) {
		disable_irq_nosync(sigma_delta->spi->irq);
		sigma_delta->irq_dis = true;
	}

	ad_sigma_delta_set_mode(sigma_delta, AD_SD_MODE_IDLE);
	mutex_unlock(&indio_dev->mlock);

	if (ret)
		return ret;

	sample = raw_sample >> chan->scan_type.shift;
	sample &= (1 << chan->scan_type.realbits) - 1;
	*val = sample;

	ret = ad_sigma_delta_postprocess_sample(sigma_delta, raw_sample);
	if (ret)
		return ret;

	return IIO_VAL_INT;
}

__attribute__((used)) static int ad_sd_buffer_postenable(struct iio_dev *indio_dev)
{
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);
	unsigned int channel;
	int ret;

	ret = iio_triggered_buffer_postenable(indio_dev);
	if (ret < 0)
		return ret;

	channel = find_first_bit(indio_dev->active_scan_mask,
				 indio_dev->masklength);
	ret = ad_sigma_delta_set_channel(sigma_delta,
		indio_dev->channels[channel].address);
	if (ret)
		goto err_predisable;

	spi_bus_lock(sigma_delta->spi->master);
	sigma_delta->bus_locked = true;
	ret = ad_sigma_delta_set_mode(sigma_delta, AD_SD_MODE_CONTINUOUS);
	if (ret)
		goto err_unlock;

	sigma_delta->irq_dis = false;
	enable_irq(sigma_delta->spi->irq);

	return 0;

err_unlock:
	spi_bus_unlock(sigma_delta->spi->master);
err_predisable:

	return ret;
}

__attribute__((used)) static int ad_sd_buffer_postdisable(struct iio_dev *indio_dev)
{
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);

	reinit_completion(&sigma_delta->completion);
	wait_for_completion_timeout(&sigma_delta->completion, HZ);

	if (!sigma_delta->irq_dis) {
		disable_irq_nosync(sigma_delta->spi->irq);
		sigma_delta->irq_dis = true;
	}

	ad_sigma_delta_set_mode(sigma_delta, AD_SD_MODE_IDLE);

	sigma_delta->bus_locked = false;
	return spi_bus_unlock(sigma_delta->spi->master);
}

__attribute__((used)) static irqreturn_t ad_sd_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);
	unsigned int reg_size;
	uint8_t data[16];
	int ret;

	memset(data, 0x00, 16);

	reg_size = indio_dev->channels[0].scan_type.realbits +
			indio_dev->channels[0].scan_type.shift;
	reg_size = DIV_ROUND_UP(reg_size, 8);

	switch (reg_size) {
	case 4:
	case 2:
	case 1:
		ret = ad_sd_read_reg_raw(sigma_delta, AD_SD_REG_DATA,
			reg_size, &data[0]);
		break;
	case 3:
		/* We store 24 bit samples in a 32 bit word. Keep the upper
		 * byte set to zero. */
		ret = ad_sd_read_reg_raw(sigma_delta, AD_SD_REG_DATA,
			reg_size, &data[1]);
		break;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, data, pf->timestamp);

	iio_trigger_notify_done(indio_dev->trig);
	sigma_delta->irq_dis = false;
	enable_irq(sigma_delta->spi->irq);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t ad_sd_data_rdy_trig_poll(int irq, void *private)
{
	struct ad_sigma_delta *sigma_delta = private;

	complete(&sigma_delta->completion);
	disable_irq_nosync(irq);
	sigma_delta->irq_dis = true;
	iio_trigger_poll(sigma_delta->trig);

	return IRQ_HANDLED;
}

int ad_sd_validate_trigger(struct iio_dev *indio_dev, struct iio_trigger *trig)
{
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);

	if (sigma_delta->trig != trig)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int ad_sd_probe_trigger(struct iio_dev *indio_dev)
{
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);
	int ret;

	sigma_delta->trig = iio_trigger_alloc("%s-dev%d", indio_dev->name,
						indio_dev->id);
	if (sigma_delta->trig == NULL) {
		ret = -ENOMEM;
		goto error_ret;
	}
	sigma_delta->trig->ops = &ad_sd_trigger_ops;
	init_completion(&sigma_delta->completion);

	ret = request_irq(sigma_delta->spi->irq,
			  ad_sd_data_rdy_trig_poll,
			  IRQF_TRIGGER_LOW,
			  indio_dev->name,
			  sigma_delta);
	if (ret)
		goto error_free_trig;

	if (!sigma_delta->irq_dis) {
		sigma_delta->irq_dis = true;
		disable_irq_nosync(sigma_delta->spi->irq);
	}
	sigma_delta->trig->dev.parent = &sigma_delta->spi->dev;
	iio_trigger_set_drvdata(sigma_delta->trig, sigma_delta);

	ret = iio_trigger_register(sigma_delta->trig);
	if (ret)
		goto error_free_irq;

	/* select default trigger */
	indio_dev->trig = iio_trigger_get(sigma_delta->trig);

	return 0;

error_free_irq:
	free_irq(sigma_delta->spi->irq, sigma_delta);
error_free_trig:
	iio_trigger_free(sigma_delta->trig);
error_ret:
	return ret;
}

__attribute__((used)) static void ad_sd_remove_trigger(struct iio_dev *indio_dev)
{
	struct ad_sigma_delta *sigma_delta = iio_device_get_drvdata(indio_dev);

	iio_trigger_unregister(sigma_delta->trig);
	free_irq(sigma_delta->spi->irq, sigma_delta);
	iio_trigger_free(sigma_delta->trig);
}

int ad_sd_setup_buffer_and_trigger(struct iio_dev *indio_dev)
{
	int ret;

	ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
			&ad_sd_trigger_handler, &ad_sd_buffer_setup_ops);
	if (ret)
		return ret;

	ret = ad_sd_probe_trigger(indio_dev);
	if (ret) {
		iio_triggered_buffer_cleanup(indio_dev);
		return ret;
	}

	return 0;
}

void ad_sd_cleanup_buffer_and_trigger(struct iio_dev *indio_dev)
{
	ad_sd_remove_trigger(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);
}

int ad_sd_init(struct ad_sigma_delta *sigma_delta, struct iio_dev *indio_dev,
	struct spi_device *spi, const struct ad_sigma_delta_info *info)
{
	sigma_delta->spi = spi;
	sigma_delta->info = info;
	iio_device_set_drvdata(indio_dev, sigma_delta);

	return 0;
}

