#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct rpr0521_data {int als_dev_en; int pxs_dev_en; TYPE_8__* drdy_trigger0; int /*<<< orphan*/  lock; struct regmap* regmap; struct i2c_client* client; void* irq_timestamp; } ;
struct regmap {int dummy; } ;
struct iio_trigger {int dummy; } ;
struct iio_poll_func {void* timestamp; struct iio_dev* indio_dev; } ;
struct TYPE_15__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; TYPE_3__ dev; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/  id; int /*<<< orphan*/  name; int /*<<< orphan*/  modes; TYPE_4__* channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  trig; } ;
struct iio_chan_spec {int const type; size_t address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int irq; int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  raw_data ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum iio_chan_type { ____Placeholder_iio_chan_type } iio_chan_type ;
typedef  int /*<<< orphan*/  buffer ;
typedef  int* __le16 ;
struct TYPE_14__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_19__ {int /*<<< orphan*/ * ops; TYPE_2__ dev; } ;
struct TYPE_18__ {int device_mask; int /*<<< orphan*/  address; } ;
struct TYPE_17__ {int reg; int mask; int shift; int size; TYPE_1__* gain; } ;
struct TYPE_16__ {int als_hz; int als_uhz; int pxs_hz; int pxs_uhz; } ;
struct TYPE_13__ {int scale; int uscale; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 136 
#define  IIO_CHAN_INFO_RAW 135 
#define  IIO_CHAN_INFO_SAMP_FREQ 134 
#define  IIO_CHAN_INFO_SCALE 133 
#define  IIO_INTENSITY 132 
#define  IIO_PROXIMITY 131 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int RPR0521_DEFAULT_MEAS_TIME ; 
 int /*<<< orphan*/  RPR0521_DRV_NAME ; 
 int RPR0521_INTERRUPT_ALS_INT_STATUS_MASK ; 
 int RPR0521_INTERRUPT_INT_REASSERT_DISABLE ; 
 int RPR0521_INTERRUPT_INT_TRIG_ALS_DISABLE ; 
 int RPR0521_INTERRUPT_INT_TRIG_PS_DISABLE ; 
 int RPR0521_INTERRUPT_INT_TRIG_PS_ENABLE ; 
 int RPR0521_INTERRUPT_PS_INT_STATUS_MASK ; 
 int /*<<< orphan*/  RPR0521_IRQ_NAME ; 
 int RPR0521_MANUFACT_ID ; 
 int RPR0521_MODE_ALS_DISABLE ; 
 int RPR0521_MODE_ALS_ENABLE ; 
 int RPR0521_MODE_ALS_MASK ; 
 int RPR0521_MODE_MEAS_TIME_MASK ; 
 int RPR0521_MODE_PXS_DISABLE ; 
 int RPR0521_MODE_PXS_ENABLE ; 
 int RPR0521_MODE_PXS_MASK ; 
 int RPR0521_PXS_PERSISTENCE_DRDY ; 
 int RPR0521_PXS_PERSISTENCE_MASK ; 
#define  RPR0521_REG_ALS_CTRL 130 
 int RPR0521_REG_ID ; 
 int RPR0521_REG_INTERRUPT ; 
#define  RPR0521_REG_MODE_CTRL 129 
 int /*<<< orphan*/  RPR0521_REG_PS_OFFSET_LSB ; 
#define  RPR0521_REG_PXS_CTRL 128 
 int /*<<< orphan*/  RPR0521_REG_PXS_DATA ; 
 int /*<<< orphan*/  RPR0521_SLEEP_DELAY_MS ; 
 int* cpu_to_le16 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 TYPE_8__* devm_iio_trigger_alloc (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_iio_trigger_register (int /*<<< orphan*/ *,TYPE_8__*) ; 
 int devm_iio_triggered_buffer_setup (int /*<<< orphan*/ *,struct iio_dev*,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 void* iio_get_time_ns (struct iio_dev*) ; 
 struct rpr0521_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,void*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_poll_chained (TYPE_8__*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_8__*,struct iio_dev*) ; 
 scalar_t__ iio_trigger_using_own (struct iio_dev*) ; 
 int le16_to_cpu (int*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (int /*<<< orphan*/ *) ; 
 int pm_runtime_set_active (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int regmap_bulk_read (struct regmap*,int /*<<< orphan*/ ,int**,int) ; 
 int regmap_raw_write (struct regmap*,int /*<<< orphan*/ ,int**,int) ; 
 int regmap_read (struct regmap*,int,int*) ; 
 int regmap_update_bits (struct regmap*,int,int,int) ; 
 int regmap_write (struct regmap*,int,int) ; 
 int /*<<< orphan*/  rpr0521_available_scan_masks ; 
 int /*<<< orphan*/  rpr0521_buffer_setup_ops ; 
 TYPE_4__* rpr0521_channels ; 
 TYPE_6__* rpr0521_data_reg ; 
 TYPE_5__* rpr0521_gain ; 
 int /*<<< orphan*/  rpr0521_info ; 
 int /*<<< orphan*/  rpr0521_regmap_config ; 
 TYPE_4__* rpr0521_samp_freq_i ; 
 int /*<<< orphan*/  rpr0521_trigger_ops ; 

__attribute__((used)) static int rpr0521_als_enable(struct rpr0521_data *data, u8 status)
{
	int ret;

	ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
				 RPR0521_MODE_ALS_MASK,
				 status);
	if (ret < 0)
		return ret;

	if (status & RPR0521_MODE_ALS_MASK)
		data->als_dev_en = true;
	else
		data->als_dev_en = false;

	return 0;
}

__attribute__((used)) static int rpr0521_pxs_enable(struct rpr0521_data *data, u8 status)
{
	int ret;

	ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
				 RPR0521_MODE_PXS_MASK,
				 status);
	if (ret < 0)
		return ret;

	if (status & RPR0521_MODE_PXS_MASK)
		data->pxs_dev_en = true;
	else
		data->pxs_dev_en = false;

	return 0;
}

__attribute__((used)) static int rpr0521_set_power_state(struct rpr0521_data *data, bool on,
				   u8 device_mask)
{
#ifdef CONFIG_PM
	int ret;

	if (device_mask & RPR0521_MODE_ALS_MASK) {
		data->als_ps_need_en = on;
		data->als_need_dis = !on;
	}

	if (device_mask & RPR0521_MODE_PXS_MASK) {
		data->pxs_ps_need_en = on;
		data->pxs_need_dis = !on;
	}

	/*
	 * On: _resume() is called only when we are suspended
	 * Off: _suspend() is called after delay if _resume() is not
	 * called before that.
	 * Note: If either measurement is re-enabled before _suspend(),
	 * both stay enabled until _suspend().
	 */
	if (on) {
		ret = pm_runtime_get_sync(&data->client->dev);
	} else {
		pm_runtime_mark_last_busy(&data->client->dev);
		ret = pm_runtime_put_autosuspend(&data->client->dev);
	}
	if (ret < 0) {
		dev_err(&data->client->dev,
			"Failed: rpr0521_set_power_state for %d, ret %d\n",
			on, ret);
		if (on)
			pm_runtime_put_noidle(&data->client->dev);

		return ret;
	}

	if (on) {
		/* If _resume() was not called, enable measurement now. */
		if (data->als_ps_need_en) {
			ret = rpr0521_als_enable(data, RPR0521_MODE_ALS_ENABLE);
			if (ret)
				return ret;
			data->als_ps_need_en = false;
		}

		if (data->pxs_ps_need_en) {
			ret = rpr0521_pxs_enable(data, RPR0521_MODE_PXS_ENABLE);
			if (ret)
				return ret;
			data->pxs_ps_need_en = false;
		}
	}
#endif
	return 0;
}

__attribute__((used)) static inline bool rpr0521_is_triggered(struct rpr0521_data *data)
{
	int ret;
	int reg;

	ret = regmap_read(data->regmap, RPR0521_REG_INTERRUPT, &reg);
	if (ret < 0)
		return false;   /* Reg read failed. */
	if (reg &
	    (RPR0521_INTERRUPT_ALS_INT_STATUS_MASK |
	    RPR0521_INTERRUPT_PS_INT_STATUS_MASK))
		return true;
	else
		return false;   /* Int not from this sensor. */
}

__attribute__((used)) static irqreturn_t rpr0521_drdy_irq_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct rpr0521_data *data = iio_priv(indio_dev);

	data->irq_timestamp = iio_get_time_ns(indio_dev);
	/*
	 * We need to wake the thread to read the interrupt reg. It
	 * is not possible to do that here because regmap_read takes a
	 * mutex.
	 */

	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t rpr0521_drdy_irq_thread(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct rpr0521_data *data = iio_priv(indio_dev);

	if (rpr0521_is_triggered(data)) {
		iio_trigger_poll_chained(data->drdy_trigger0);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

__attribute__((used)) static irqreturn_t rpr0521_trigger_consumer_store_time(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;

	/* Other trigger polls store time here. */
	if (!iio_trigger_using_own(indio_dev))
		pf->timestamp = iio_get_time_ns(indio_dev);

	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t rpr0521_trigger_consumer_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct rpr0521_data *data = iio_priv(indio_dev);
	int err;

	u8 buffer[16]; /* 3 16-bit channels + padding + ts */

	/* Use irq timestamp when reasonable. */
	if (iio_trigger_using_own(indio_dev) && data->irq_timestamp) {
		pf->timestamp = data->irq_timestamp;
		data->irq_timestamp = 0;
	}
	/* Other chained trigger polls get timestamp only here. */
	if (!pf->timestamp)
		pf->timestamp = iio_get_time_ns(indio_dev);

	err = regmap_bulk_read(data->regmap, RPR0521_REG_PXS_DATA,
		&buffer,
		(3 * 2) + 1);	/* 3 * 16-bit + (discarded) int clear reg. */
	if (!err)
		iio_push_to_buffers_with_timestamp(indio_dev,
						   buffer, pf->timestamp);
	else
		dev_err(&data->client->dev,
			"Trigger consumer can't read from sensor.\n");
	pf->timestamp = 0;

	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int rpr0521_write_int_enable(struct rpr0521_data *data)
{
	int err;

	/* Interrupt after each measurement */
	err = regmap_update_bits(data->regmap, RPR0521_REG_PXS_CTRL,
		RPR0521_PXS_PERSISTENCE_MASK,
		RPR0521_PXS_PERSISTENCE_DRDY);
	if (err) {
		dev_err(&data->client->dev, "PS control reg write fail.\n");
		return -EBUSY;
		}

	/* Ignore latch and mode because of drdy */
	err = regmap_write(data->regmap, RPR0521_REG_INTERRUPT,
		RPR0521_INTERRUPT_INT_REASSERT_DISABLE |
		RPR0521_INTERRUPT_INT_TRIG_ALS_DISABLE |
		RPR0521_INTERRUPT_INT_TRIG_PS_ENABLE
		);
	if (err) {
		dev_err(&data->client->dev, "Interrupt setup write fail.\n");
		return -EBUSY;
		}

	return 0;
}

__attribute__((used)) static int rpr0521_write_int_disable(struct rpr0521_data *data)
{
	/* Don't care of clearing mode, assert and latch. */
	return regmap_write(data->regmap, RPR0521_REG_INTERRUPT,
				RPR0521_INTERRUPT_INT_TRIG_ALS_DISABLE |
				RPR0521_INTERRUPT_INT_TRIG_PS_DISABLE
				);
}

__attribute__((used)) static int rpr0521_pxs_drdy_set_state(struct iio_trigger *trigger,
	bool enable_drdy)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trigger);
	struct rpr0521_data *data = iio_priv(indio_dev);
	int err;

	if (enable_drdy)
		err = rpr0521_write_int_enable(data);
	else
		err = rpr0521_write_int_disable(data);
	if (err)
		dev_err(&data->client->dev, "rpr0521_pxs_drdy_set_state failed\n");

	return err;
}

__attribute__((used)) static int rpr0521_buffer_preenable(struct iio_dev *indio_dev)
{
	int err;
	struct rpr0521_data *data = iio_priv(indio_dev);

	mutex_lock(&data->lock);
	err = rpr0521_set_power_state(data, true,
		(RPR0521_MODE_PXS_MASK | RPR0521_MODE_ALS_MASK));
	mutex_unlock(&data->lock);
	if (err)
		dev_err(&data->client->dev, "_buffer_preenable fail\n");

	return err;
}

__attribute__((used)) static int rpr0521_buffer_postdisable(struct iio_dev *indio_dev)
{
	int err;
	struct rpr0521_data *data = iio_priv(indio_dev);

	mutex_lock(&data->lock);
	err = rpr0521_set_power_state(data, false,
		(RPR0521_MODE_PXS_MASK | RPR0521_MODE_ALS_MASK));
	mutex_unlock(&data->lock);
	if (err)
		dev_err(&data->client->dev, "_buffer_postdisable fail\n");

	return err;
}

__attribute__((used)) static int rpr0521_get_gain(struct rpr0521_data *data, int chan,
			    int *val, int *val2)
{
	int ret, reg, idx;

	ret = regmap_read(data->regmap, rpr0521_gain[chan].reg, &reg);
	if (ret < 0)
		return ret;

	idx = (rpr0521_gain[chan].mask & reg) >> rpr0521_gain[chan].shift;
	*val = rpr0521_gain[chan].gain[idx].scale;
	*val2 = rpr0521_gain[chan].gain[idx].uscale;

	return 0;
}

__attribute__((used)) static int rpr0521_set_gain(struct rpr0521_data *data, int chan,
			    int val, int val2)
{
	int i, idx = -EINVAL;

	/* get gain index */
	for (i = 0; i < rpr0521_gain[chan].size; i++)
		if (val == rpr0521_gain[chan].gain[i].scale &&
		    val2 == rpr0521_gain[chan].gain[i].uscale) {
			idx = i;
			break;
		}

	if (idx < 0)
		return idx;

	return regmap_update_bits(data->regmap, rpr0521_gain[chan].reg,
				  rpr0521_gain[chan].mask,
				  idx << rpr0521_gain[chan].shift);
}

__attribute__((used)) static int rpr0521_read_samp_freq(struct rpr0521_data *data,
				enum iio_chan_type chan_type,
			    int *val, int *val2)
{
	int reg, ret;

	ret = regmap_read(data->regmap, RPR0521_REG_MODE_CTRL, &reg);
	if (ret < 0)
		return ret;

	reg &= RPR0521_MODE_MEAS_TIME_MASK;
	if (reg >= ARRAY_SIZE(rpr0521_samp_freq_i))
		return -EINVAL;

	switch (chan_type) {
	case IIO_INTENSITY:
		*val = rpr0521_samp_freq_i[reg].als_hz;
		*val2 = rpr0521_samp_freq_i[reg].als_uhz;
		return 0;

	case IIO_PROXIMITY:
		*val = rpr0521_samp_freq_i[reg].pxs_hz;
		*val2 = rpr0521_samp_freq_i[reg].pxs_uhz;
		return 0;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int rpr0521_write_samp_freq_common(struct rpr0521_data *data,
				enum iio_chan_type chan_type,
				int val, int val2)
{
	int i;

	/*
	 * Ignore channel
	 * both pxs and als are setup only to same freq because of simplicity
	 */
	switch (val) {
	case 0:
		i = 0;
		break;

	case 2:
		if (val2 != 500000)
			return -EINVAL;

		i = 11;
		break;

	case 10:
		i = 6;
		break;

	default:
		return -EINVAL;
	}

	return regmap_update_bits(data->regmap,
		RPR0521_REG_MODE_CTRL,
		RPR0521_MODE_MEAS_TIME_MASK,
		i);
}

__attribute__((used)) static int rpr0521_read_ps_offset(struct rpr0521_data *data, int *offset)
{
	int ret;
	__le16 buffer;

	ret = regmap_bulk_read(data->regmap,
		RPR0521_REG_PS_OFFSET_LSB, &buffer, sizeof(buffer));

	if (ret < 0) {
		dev_err(&data->client->dev, "Failed to read PS OFFSET register\n");
		return ret;
	}
	*offset = le16_to_cpu(buffer);

	return ret;
}

__attribute__((used)) static int rpr0521_write_ps_offset(struct rpr0521_data *data, int offset)
{
	int ret;
	__le16 buffer;

	buffer = cpu_to_le16(offset & 0x3ff);
	ret = regmap_raw_write(data->regmap,
		RPR0521_REG_PS_OFFSET_LSB, &buffer, sizeof(buffer));

	if (ret < 0) {
		dev_err(&data->client->dev, "Failed to write PS OFFSET register\n");
		return ret;
	}

	return ret;
}

__attribute__((used)) static int rpr0521_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int *val,
			    int *val2, long mask)
{
	struct rpr0521_data *data = iio_priv(indio_dev);
	int ret;
	int busy;
	u8 device_mask;
	__le16 raw_data;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (chan->type != IIO_INTENSITY && chan->type != IIO_PROXIMITY)
			return -EINVAL;

		busy = iio_device_claim_direct_mode(indio_dev);
		if (busy)
			return -EBUSY;

		device_mask = rpr0521_data_reg[chan->address].device_mask;

		mutex_lock(&data->lock);
		ret = rpr0521_set_power_state(data, true, device_mask);
		if (ret < 0)
			goto rpr0521_read_raw_out;

		ret = regmap_bulk_read(data->regmap,
				       rpr0521_data_reg[chan->address].address,
				       &raw_data, sizeof(raw_data));
		if (ret < 0) {
			rpr0521_set_power_state(data, false, device_mask);
			goto rpr0521_read_raw_out;
		}

		ret = rpr0521_set_power_state(data, false, device_mask);

rpr0521_read_raw_out:
		mutex_unlock(&data->lock);
		iio_device_release_direct_mode(indio_dev);
		if (ret < 0)
			return ret;

		*val = le16_to_cpu(raw_data);

		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		mutex_lock(&data->lock);
		ret = rpr0521_get_gain(data, chan->address, val, val2);
		mutex_unlock(&data->lock);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT_PLUS_MICRO;

	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&data->lock);
		ret = rpr0521_read_samp_freq(data, chan->type, val, val2);
		mutex_unlock(&data->lock);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT_PLUS_MICRO;

	case IIO_CHAN_INFO_OFFSET:
		mutex_lock(&data->lock);
		ret = rpr0521_read_ps_offset(data, val);
		mutex_unlock(&data->lock);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int rpr0521_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int val,
			     int val2, long mask)
{
	struct rpr0521_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		mutex_lock(&data->lock);
		ret = rpr0521_set_gain(data, chan->address, val, val2);
		mutex_unlock(&data->lock);

		return ret;

	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&data->lock);
		ret = rpr0521_write_samp_freq_common(data, chan->type,
						     val, val2);
		mutex_unlock(&data->lock);

		return ret;

	case IIO_CHAN_INFO_OFFSET:
		mutex_lock(&data->lock);
		ret = rpr0521_write_ps_offset(data, val);
		mutex_unlock(&data->lock);

		return ret;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int rpr0521_init(struct rpr0521_data *data)
{
	int ret;
	int id;

	ret = regmap_read(data->regmap, RPR0521_REG_ID, &id);
	if (ret < 0) {
		dev_err(&data->client->dev, "Failed to read REG_ID register\n");
		return ret;
	}

	if (id != RPR0521_MANUFACT_ID) {
		dev_err(&data->client->dev, "Wrong id, got %x, expected %x\n",
			id, RPR0521_MANUFACT_ID);
		return -ENODEV;
	}

	/* set default measurement time - 100 ms for both ALS and PS */
	ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
				 RPR0521_MODE_MEAS_TIME_MASK,
				 RPR0521_DEFAULT_MEAS_TIME);
	if (ret) {
		pr_err("regmap_update_bits returned %d\n", ret);
		return ret;
	}

#ifndef CONFIG_PM
	ret = rpr0521_als_enable(data, RPR0521_MODE_ALS_ENABLE);
	if (ret < 0)
		return ret;
	ret = rpr0521_pxs_enable(data, RPR0521_MODE_PXS_ENABLE);
	if (ret < 0)
		return ret;
#endif

	data->irq_timestamp = 0;

	return 0;
}

__attribute__((used)) static int rpr0521_poweroff(struct rpr0521_data *data)
{
	int ret;
	int tmp;

	ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
				 RPR0521_MODE_ALS_MASK |
				 RPR0521_MODE_PXS_MASK,
				 RPR0521_MODE_ALS_DISABLE |
				 RPR0521_MODE_PXS_DISABLE);
	if (ret < 0)
		return ret;

	data->als_dev_en = false;
	data->pxs_dev_en = false;

	/*
	 * Int pin keeps state after power off. Set pin to high impedance
	 * mode to prevent power drain.
	 */
	ret = regmap_read(data->regmap, RPR0521_REG_INTERRUPT, &tmp);
	if (ret) {
		dev_err(&data->client->dev, "Failed to reset int pin.\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static bool rpr0521_is_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case RPR0521_REG_MODE_CTRL:
	case RPR0521_REG_ALS_CTRL:
	case RPR0521_REG_PXS_CTRL:
		return false;
	default:
		return true;
	}
}

__attribute__((used)) static int rpr0521_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct rpr0521_data *data;
	struct iio_dev *indio_dev;
	struct regmap *regmap;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	regmap = devm_regmap_init_i2c(client, &rpr0521_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "regmap_init failed!\n");
		return PTR_ERR(regmap);
	}

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	data->regmap = regmap;

	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &rpr0521_info;
	indio_dev->name = RPR0521_DRV_NAME;
	indio_dev->channels = rpr0521_channels;
	indio_dev->num_channels = ARRAY_SIZE(rpr0521_channels);
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = rpr0521_init(data);
	if (ret < 0) {
		dev_err(&client->dev, "rpr0521 chip init failed\n");
		return ret;
	}

	ret = pm_runtime_set_active(&client->dev);
	if (ret < 0)
		goto err_poweroff;

	pm_runtime_enable(&client->dev);
	pm_runtime_set_autosuspend_delay(&client->dev, RPR0521_SLEEP_DELAY_MS);
	pm_runtime_use_autosuspend(&client->dev);

	/*
	 * If sensor write/read is needed in _probe after _use_autosuspend,
	 * sensor needs to be _resumed first using rpr0521_set_power_state().
	 */

	/* IRQ to trigger setup */
	if (client->irq) {
		/* Trigger0 producer setup */
		data->drdy_trigger0 = devm_iio_trigger_alloc(
			indio_dev->dev.parent,
			"%s-dev%d", indio_dev->name, indio_dev->id);
		if (!data->drdy_trigger0) {
			ret = -ENOMEM;
			goto err_pm_disable;
		}
		data->drdy_trigger0->dev.parent = indio_dev->dev.parent;
		data->drdy_trigger0->ops = &rpr0521_trigger_ops;
		indio_dev->available_scan_masks = rpr0521_available_scan_masks;
		iio_trigger_set_drvdata(data->drdy_trigger0, indio_dev);

		/* Ties irq to trigger producer handler. */
		ret = devm_request_threaded_irq(&client->dev, client->irq,
			rpr0521_drdy_irq_handler, rpr0521_drdy_irq_thread,
			IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
			RPR0521_IRQ_NAME, indio_dev);
		if (ret < 0) {
			dev_err(&client->dev, "request irq %d for trigger0 failed\n",
				client->irq);
			goto err_pm_disable;
			}

		ret = devm_iio_trigger_register(indio_dev->dev.parent,
						data->drdy_trigger0);
		if (ret) {
			dev_err(&client->dev, "iio trigger register failed\n");
			goto err_pm_disable;
		}

		/*
		 * Now whole pipe from physical interrupt (irq defined by
		 * devicetree to device) to trigger0 output is set up.
		 */

		/* Trigger consumer setup */
		ret = devm_iio_triggered_buffer_setup(indio_dev->dev.parent,
			indio_dev,
			rpr0521_trigger_consumer_store_time,
			rpr0521_trigger_consumer_handler,
			&rpr0521_buffer_setup_ops);
		if (ret < 0) {
			dev_err(&client->dev, "iio triggered buffer setup failed\n");
			goto err_pm_disable;
		}
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto err_pm_disable;

	return 0;

err_pm_disable:
	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);
	pm_runtime_put_noidle(&client->dev);
err_poweroff:
	rpr0521_poweroff(data);

	return ret;
}

__attribute__((used)) static int rpr0521_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);

	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);
	pm_runtime_put_noidle(&client->dev);

	rpr0521_poweroff(iio_priv(indio_dev));

	return 0;
}

