#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct regmap {int dummy; } ;
struct mxc4005_data {int trigger_enabled; TYPE_6__* dready_trig; int /*<<< orphan*/  mutex; struct regmap* regmap; int /*<<< orphan*/ * dev; scalar_t__ buffer; } ;
struct iio_trigger {int dummy; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct TYPE_14__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; TYPE_6__* trig; int /*<<< orphan*/  id; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  available_scan_masks; TYPE_4__* channels; TYPE_1__ dev; } ;
struct TYPE_16__ {int shift; int /*<<< orphan*/  realbits; } ;
struct iio_chan_spec {unsigned int address; TYPE_3__ scan_type; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {scalar_t__ irq; int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_15__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_18__ {int /*<<< orphan*/ * ops; TYPE_2__ dev; } ;
struct TYPE_17__ {int scale; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_ACCEL 140 
#define  IIO_CHAN_INFO_RAW 139 
#define  IIO_CHAN_INFO_SCALE 138 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 unsigned int MXC4005_CONTROL_FSR_SHIFT ; 
 int /*<<< orphan*/  MXC4005_DRV_NAME ; 
 int /*<<< orphan*/  MXC4005_IRQ_NAME ; 
#define  MXC4005_REG_CONTROL 137 
 int /*<<< orphan*/  MXC4005_REG_CONTROL_MASK_FSR ; 
#define  MXC4005_REG_DEVICE_ID 136 
#define  MXC4005_REG_INT_CLR1 135 
 int /*<<< orphan*/  MXC4005_REG_INT_CLR1_BIT_DRDYC ; 
#define  MXC4005_REG_INT_MASK1 134 
 int /*<<< orphan*/  MXC4005_REG_INT_MASK1_BIT_DRDYE ; 
#define  MXC4005_REG_XOUT_LOWER 133 
#define  MXC4005_REG_XOUT_UPPER 132 
#define  MXC4005_REG_YOUT_LOWER 131 
#define  MXC4005_REG_YOUT_UPPER 130 
#define  MXC4005_REG_ZOUT_LOWER 129 
#define  MXC4005_REG_ZOUT_UPPER 128 
 int PTR_ERR (struct regmap*) ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 TYPE_6__* devm_iio_trigger_alloc (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,TYPE_6__*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_buffer_enabled (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct mxc4005_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_generic_data_rdy_poll ; 
 int /*<<< orphan*/  iio_trigger_get (TYPE_6__*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (TYPE_6__*) ; 
 int iio_trigger_register (TYPE_6__*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_6__*,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (TYPE_6__*) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_4__* mxc4005_channels ; 
 int /*<<< orphan*/  mxc4005_info ; 
 int /*<<< orphan*/  mxc4005_regmap_config ; 
 TYPE_4__* mxc4005_scale_table ; 
 int /*<<< orphan*/  mxc4005_scan_masks ; 
 int /*<<< orphan*/  mxc4005_trigger_ops ; 
 int regmap_bulk_read (struct regmap*,int const,int /*<<< orphan*/ *,int) ; 
 int regmap_read (struct regmap*,int const,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int const,int /*<<< orphan*/ ,unsigned int) ; 
 int regmap_write (struct regmap*,int const,int /*<<< orphan*/ ) ; 
 int sign_extend32 (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool mxc4005_is_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MXC4005_REG_XOUT_UPPER:
	case MXC4005_REG_XOUT_LOWER:
	case MXC4005_REG_YOUT_UPPER:
	case MXC4005_REG_YOUT_LOWER:
	case MXC4005_REG_ZOUT_UPPER:
	case MXC4005_REG_ZOUT_LOWER:
	case MXC4005_REG_DEVICE_ID:
	case MXC4005_REG_CONTROL:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool mxc4005_is_writeable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MXC4005_REG_INT_CLR1:
	case MXC4005_REG_INT_MASK1:
	case MXC4005_REG_CONTROL:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int mxc4005_read_xyz(struct mxc4005_data *data)
{
	int ret;

	ret = regmap_bulk_read(data->regmap, MXC4005_REG_XOUT_UPPER,
			       (u8 *) data->buffer, sizeof(data->buffer));
	if (ret < 0) {
		dev_err(data->dev, "failed to read axes\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int mxc4005_read_axis(struct mxc4005_data *data,
			     unsigned int addr)
{
	__be16 reg;
	int ret;

	ret = regmap_bulk_read(data->regmap, addr, (u8 *) &reg, sizeof(reg));
	if (ret < 0) {
		dev_err(data->dev, "failed to read reg %02x\n", addr);
		return ret;
	}

	return be16_to_cpu(reg);
}

__attribute__((used)) static int mxc4005_read_scale(struct mxc4005_data *data)
{
	unsigned int reg;
	int ret;
	int i;

	ret = regmap_read(data->regmap, MXC4005_REG_CONTROL, &reg);
	if (ret < 0) {
		dev_err(data->dev, "failed to read reg_control\n");
		return ret;
	}

	i = reg >> MXC4005_CONTROL_FSR_SHIFT;

	if (i < 0 || i >= ARRAY_SIZE(mxc4005_scale_table))
		return -EINVAL;

	return mxc4005_scale_table[i].scale;
}

__attribute__((used)) static int mxc4005_set_scale(struct mxc4005_data *data, int val)
{
	unsigned int reg;
	int i;
	int ret;

	for (i = 0; i < ARRAY_SIZE(mxc4005_scale_table); i++) {
		if (mxc4005_scale_table[i].scale == val) {
			reg = i << MXC4005_CONTROL_FSR_SHIFT;
			ret = regmap_update_bits(data->regmap,
						 MXC4005_REG_CONTROL,
						 MXC4005_REG_CONTROL_MASK_FSR,
						 reg);
			if (ret < 0)
				dev_err(data->dev,
					"failed to write reg_control\n");
			return ret;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int mxc4005_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mxc4005_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_ACCEL:
			if (iio_buffer_enabled(indio_dev))
				return -EBUSY;

			ret = mxc4005_read_axis(data, chan->address);
			if (ret < 0)
				return ret;
			*val = sign_extend32(ret >> chan->scan_type.shift,
					     chan->scan_type.realbits - 1);
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SCALE:
		ret = mxc4005_read_scale(data);
		if (ret < 0)
			return ret;

		*val = 0;
		*val2 = ret;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mxc4005_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct mxc4005_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		if (val != 0)
			return -EINVAL;

		return mxc4005_set_scale(data, val2);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static irqreturn_t mxc4005_trigger_handler(int irq, void *private)
{
	struct iio_poll_func *pf = private;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct mxc4005_data *data = iio_priv(indio_dev);
	int ret;

	ret = mxc4005_read_xyz(data);
	if (ret < 0)
		goto err;

	iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
					   pf->timestamp);

err:
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int mxc4005_clr_intr(struct mxc4005_data *data)
{
	int ret;

	/* clear interrupt */
	ret = regmap_write(data->regmap, MXC4005_REG_INT_CLR1,
			   MXC4005_REG_INT_CLR1_BIT_DRDYC);
	if (ret < 0) {
		dev_err(data->dev, "failed to write to reg_int_clr1\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int mxc4005_set_trigger_state(struct iio_trigger *trig,
				     bool state)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct mxc4005_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);
	if (state) {
		ret = regmap_write(data->regmap, MXC4005_REG_INT_MASK1,
				   MXC4005_REG_INT_MASK1_BIT_DRDYE);
	} else {
		ret = regmap_write(data->regmap, MXC4005_REG_INT_MASK1,
				   ~MXC4005_REG_INT_MASK1_BIT_DRDYE);
	}

	if (ret < 0) {
		mutex_unlock(&data->mutex);
		dev_err(data->dev, "failed to update reg_int_mask1");
		return ret;
	}

	data->trigger_enabled = state;
	mutex_unlock(&data->mutex);

	return 0;
}

__attribute__((used)) static int mxc4005_trigger_try_reen(struct iio_trigger *trig)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct mxc4005_data *data = iio_priv(indio_dev);

	if (!data->dready_trig)
		return 0;

	return mxc4005_clr_intr(data);
}

__attribute__((used)) static int mxc4005_chip_init(struct mxc4005_data *data)
{
	int ret;
	unsigned int reg;

	ret = regmap_read(data->regmap, MXC4005_REG_DEVICE_ID, &reg);
	if (ret < 0) {
		dev_err(data->dev, "failed to read chip id\n");
		return ret;
	}

	dev_dbg(data->dev, "MXC4005 chip id %02x\n", reg);

	return 0;
}

__attribute__((used)) static int mxc4005_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct mxc4005_data *data;
	struct iio_dev *indio_dev;
	struct regmap *regmap;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	regmap = devm_regmap_init_i2c(client, &mxc4005_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "failed to initialize regmap\n");
		return PTR_ERR(regmap);
	}

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->dev = &client->dev;
	data->regmap = regmap;

	ret = mxc4005_chip_init(data);
	if (ret < 0) {
		dev_err(&client->dev, "failed to initialize chip\n");
		return ret;
	}

	mutex_init(&data->mutex);

	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = mxc4005_channels;
	indio_dev->num_channels = ARRAY_SIZE(mxc4005_channels);
	indio_dev->available_scan_masks = mxc4005_scan_masks;
	indio_dev->name = MXC4005_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &mxc4005_info;

	ret = iio_triggered_buffer_setup(indio_dev,
					 iio_pollfunc_store_time,
					 mxc4005_trigger_handler,
					 NULL);
	if (ret < 0) {
		dev_err(&client->dev,
			"failed to setup iio triggered buffer\n");
		return ret;
	}

	if (client->irq > 0) {
		data->dready_trig = devm_iio_trigger_alloc(&client->dev,
							   "%s-dev%d",
							   indio_dev->name,
							   indio_dev->id);
		if (!data->dready_trig)
			return -ENOMEM;

		ret = devm_request_threaded_irq(&client->dev, client->irq,
						iio_trigger_generic_data_rdy_poll,
						NULL,
						IRQF_TRIGGER_FALLING |
						IRQF_ONESHOT,
						MXC4005_IRQ_NAME,
						data->dready_trig);
		if (ret) {
			dev_err(&client->dev,
				"failed to init threaded irq\n");
			goto err_buffer_cleanup;
		}

		data->dready_trig->dev.parent = &client->dev;
		data->dready_trig->ops = &mxc4005_trigger_ops;
		iio_trigger_set_drvdata(data->dready_trig, indio_dev);
		indio_dev->trig = data->dready_trig;
		iio_trigger_get(indio_dev->trig);
		ret = iio_trigger_register(data->dready_trig);
		if (ret) {
			dev_err(&client->dev,
				"failed to register trigger\n");
			goto err_trigger_unregister;
		}
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev,
			"unable to register iio device %d\n", ret);
		goto err_buffer_cleanup;
	}

	return 0;

err_trigger_unregister:
	iio_trigger_unregister(data->dready_trig);
err_buffer_cleanup:
	iio_triggered_buffer_cleanup(indio_dev);

	return ret;
}

__attribute__((used)) static int mxc4005_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct mxc4005_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	iio_triggered_buffer_cleanup(indio_dev);
	if (data->dready_trig)
		iio_trigger_unregister(data->dready_trig);

	return 0;
}

