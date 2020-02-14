#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct mma9551_data {int* event_enabled; int* irqs; int /*<<< orphan*/  mutex; struct i2c_client* client; } ;
struct TYPE_4__ {struct device* parent; } ;
struct iio_dev {char const* name; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; TYPE_2__ dev; } ;
struct iio_chan_spec {int channel2; int type; } ;
struct i2c_device_id {char* name; } ;
struct device {TYPE_1__* driver; } ;
struct i2c_client {struct device dev; } ;
struct gpio_desc {int dummy; } ;
struct acpi_device_id {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum mma9551_tilt_axis { ____Placeholder_mma9551_tilt_axis } mma9551_tilt_axis ;
typedef  enum mma9551_gpio_pin { ____Placeholder_mma9551_gpio_pin } mma9551_gpio_pin ;
typedef  enum iio_modifier { ____Placeholder_iio_modifier } iio_modifier ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;
struct TYPE_3__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 scalar_t__ ACPI_HANDLE (struct device*) ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_IN ; 
#define  IIO_ACCEL 138 
#define  IIO_CHAN_INFO_PROCESSED 137 
#define  IIO_CHAN_INFO_RAW 136 
#define  IIO_CHAN_INFO_SCALE 135 
 int /*<<< orphan*/  IIO_EV_DIR_RISING ; 
 int /*<<< orphan*/  IIO_EV_TYPE_ROC ; 
#define  IIO_INCLI 134 
 int /*<<< orphan*/  IIO_MOD_EVENT_CODE (int const,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  IIO_MOD_X 133 
#define  IIO_MOD_Y 132 
#define  IIO_MOD_Z 131 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  MMA9551_APPID_NONE ; 
 int /*<<< orphan*/  MMA9551_APPID_TILT ; 
 int /*<<< orphan*/  MMA9551_AUTO_SUSPEND_DELAY_MS ; 
 int MMA9551_GPIO_COUNT ; 
 int /*<<< orphan*/  MMA9551_IRQ_NAME ; 
 int MMA9551_TILT_ANGFLG ; 
 int MMA9551_TILT_ANG_THRESH_MASK ; 
 int /*<<< orphan*/  MMA9551_TILT_CFG_REG ; 
 int MMA9551_TILT_QUAD_REG ; 
 int MMA9551_TILT_XY_ANG_REG ; 
 int MMA9551_TILT_XY_QUAD_SHIFT ; 
 int MMA9551_TILT_XZ_ANG_REG ; 
 int MMA9551_TILT_XZ_QUAD_SHIFT ; 
 int MMA9551_TILT_YZ_ANG_REG ; 
 int MMA9551_TILT_YZ_QUAD_SHIFT ; 
 int PTR_ERR (struct gpio_desc*) ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  desc_to_gpio (struct gpio_desc*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 char const* dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 struct gpio_desc* devm_gpiod_get_index (struct device*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 int gpiod_to_irq (struct gpio_desc*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct mma9551_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mma9551_channels ; 
 int mma9551_gpio_config (struct i2c_client*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mma9551_info ; 
 int mma9551_read_accel_chan (struct i2c_client*,struct iio_chan_spec const*,int*,int*) ; 
 int mma9551_read_accel_scale (int*,int*) ; 
 int mma9551_read_config_byte (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int mma9551_read_status_byte (struct i2c_client*,int /*<<< orphan*/ ,int,int*) ; 
 int mma9551_read_version (struct i2c_client*) ; 
 int mma9551_set_device_state (struct i2c_client*,int) ; 
 int mma9551_set_power_state (struct i2c_client*,int) ; 
 int mma9551_update_config_bits (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
#define  mma9551_x 130 
#define  mma9551_y 129 
#define  mma9551_z 128 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (struct device*) ; 

__attribute__((used)) static int mma9551_read_incli_chan(struct i2c_client *client,
				   const struct iio_chan_spec *chan,
				   int *val)
{
	u8 quad_shift, angle, quadrant;
	u16 reg_addr;
	int ret;

	switch (chan->channel2) {
	case IIO_MOD_X:
		reg_addr = MMA9551_TILT_YZ_ANG_REG;
		quad_shift = MMA9551_TILT_YZ_QUAD_SHIFT;
		break;
	case IIO_MOD_Y:
		reg_addr = MMA9551_TILT_XZ_ANG_REG;
		quad_shift = MMA9551_TILT_XZ_QUAD_SHIFT;
		break;
	case IIO_MOD_Z:
		reg_addr = MMA9551_TILT_XY_ANG_REG;
		quad_shift = MMA9551_TILT_XY_QUAD_SHIFT;
		break;
	default:
		return -EINVAL;
	}

	ret = mma9551_set_power_state(client, true);
	if (ret < 0)
		return ret;

	ret = mma9551_read_status_byte(client, MMA9551_APPID_TILT,
				       reg_addr, &angle);
	if (ret < 0)
		goto out_poweroff;

	ret = mma9551_read_status_byte(client, MMA9551_APPID_TILT,
				       MMA9551_TILT_QUAD_REG, &quadrant);
	if (ret < 0)
		goto out_poweroff;

	angle &= ~MMA9551_TILT_ANGFLG;
	quadrant = (quadrant >> quad_shift) & 0x03;

	if (quadrant == 1 || quadrant == 3)
		*val = 90 * (quadrant + 1) - angle;
	else
		*val = angle + 90 * quadrant;

	ret = IIO_VAL_INT;

out_poweroff:
	mma9551_set_power_state(client, false);
	return ret;
}

__attribute__((used)) static int mma9551_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mma9551_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		switch (chan->type) {
		case IIO_INCLI:
			mutex_lock(&data->mutex);
			ret = mma9551_read_incli_chan(data->client, chan, val);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_ACCEL:
			mutex_lock(&data->mutex);
			ret = mma9551_read_accel_chan(data->client,
						      chan, val, val2);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ACCEL:
			return mma9551_read_accel_scale(val, val2);
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9551_read_event_config(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir)
{
	struct mma9551_data *data = iio_priv(indio_dev);

	switch (chan->type) {
	case IIO_INCLI:
		/* IIO counts axes from 1, because IIO_NO_MOD is 0. */
		return data->event_enabled[chan->channel2 - 1];
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9551_config_incli_event(struct iio_dev *indio_dev,
				      enum iio_modifier axis,
				      int state)
{
	struct mma9551_data *data = iio_priv(indio_dev);
	enum mma9551_tilt_axis mma_axis;
	int ret;

	/* IIO counts axes from 1, because IIO_NO_MOD is 0. */
	mma_axis = axis - 1;

	if (data->event_enabled[mma_axis] == state)
		return 0;

	if (state == 0) {
		ret = mma9551_gpio_config(data->client,
					  (enum mma9551_gpio_pin)mma_axis,
					  MMA9551_APPID_NONE, 0, 0);
		if (ret < 0)
			return ret;

		ret = mma9551_set_power_state(data->client, false);
		if (ret < 0)
			return ret;
	} else {
		int bitnum;

		/* Bit 7 of each angle register holds the angle flag. */
		switch (axis) {
		case IIO_MOD_X:
			bitnum = 7 + 8 * MMA9551_TILT_YZ_ANG_REG;
			break;
		case IIO_MOD_Y:
			bitnum = 7 + 8 * MMA9551_TILT_XZ_ANG_REG;
			break;
		case IIO_MOD_Z:
			bitnum = 7 + 8 * MMA9551_TILT_XY_ANG_REG;
			break;
		default:
			return -EINVAL;
		}


		ret = mma9551_set_power_state(data->client, true);
		if (ret < 0)
			return ret;

		ret = mma9551_gpio_config(data->client,
					  (enum mma9551_gpio_pin)mma_axis,
					  MMA9551_APPID_TILT, bitnum, 0);
		if (ret < 0) {
			mma9551_set_power_state(data->client, false);
			return ret;
		}
	}

	data->event_enabled[mma_axis] = state;

	return ret;
}

__attribute__((used)) static int mma9551_write_event_config(struct iio_dev *indio_dev,
				      const struct iio_chan_spec *chan,
				      enum iio_event_type type,
				      enum iio_event_direction dir,
				      int state)
{
	struct mma9551_data *data = iio_priv(indio_dev);
	int ret;

	switch (chan->type) {
	case IIO_INCLI:
		mutex_lock(&data->mutex);
		ret = mma9551_config_incli_event(indio_dev,
						 chan->channel2, state);
		mutex_unlock(&data->mutex);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9551_write_event_value(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir,
				     enum iio_event_info info,
				     int val, int val2)
{
	struct mma9551_data *data = iio_priv(indio_dev);
	int ret;

	switch (chan->type) {
	case IIO_INCLI:
		if (val2 != 0 || val < 1 || val > 10)
			return -EINVAL;
		mutex_lock(&data->mutex);
		ret = mma9551_update_config_bits(data->client,
						 MMA9551_APPID_TILT,
						 MMA9551_TILT_CFG_REG,
						 MMA9551_TILT_ANG_THRESH_MASK,
						 val);
		mutex_unlock(&data->mutex);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9551_read_event_value(struct iio_dev *indio_dev,
				    const struct iio_chan_spec *chan,
				    enum iio_event_type type,
				    enum iio_event_direction dir,
				    enum iio_event_info info,
				    int *val, int *val2)
{
	struct mma9551_data *data = iio_priv(indio_dev);
	int ret;
	u8 tmp;

	switch (chan->type) {
	case IIO_INCLI:
		mutex_lock(&data->mutex);
		ret = mma9551_read_config_byte(data->client,
					       MMA9551_APPID_TILT,
					       MMA9551_TILT_CFG_REG, &tmp);
		mutex_unlock(&data->mutex);
		if (ret < 0)
			return ret;
		*val = tmp & MMA9551_TILT_ANG_THRESH_MASK;
		*val2 = 0;
		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static irqreturn_t mma9551_event_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct mma9551_data *data = iio_priv(indio_dev);
	int i, ret, mma_axis = -1;
	u16 reg;
	u8 val;

	mutex_lock(&data->mutex);

	for (i = 0; i < 3; i++)
		if (irq == data->irqs[i]) {
			mma_axis = i;
			break;
		}

	if (mma_axis == -1) {
		/* IRQ was triggered on 4th line, which we don't use. */
		dev_warn(&data->client->dev,
			 "irq triggered on unused line %d\n", data->irqs[3]);
		goto out;
	}

	switch (mma_axis) {
	case mma9551_x:
		reg = MMA9551_TILT_YZ_ANG_REG;
		break;
	case mma9551_y:
		reg = MMA9551_TILT_XZ_ANG_REG;
		break;
	case mma9551_z:
		reg = MMA9551_TILT_XY_ANG_REG;
		break;
	}

	/*
	 * Read the angle even though we don't use it, otherwise we
	 * won't get any further interrupts.
	 */
	ret = mma9551_read_status_byte(data->client, MMA9551_APPID_TILT,
				       reg, &val);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"error %d reading tilt register in IRQ\n", ret);
		goto out;
	}

	iio_push_event(indio_dev,
		       IIO_MOD_EVENT_CODE(IIO_INCLI, 0, (mma_axis + 1),
					  IIO_EV_TYPE_ROC, IIO_EV_DIR_RISING),
		       iio_get_time_ns(indio_dev));

out:
	mutex_unlock(&data->mutex);

	return IRQ_HANDLED;
}

__attribute__((used)) static int mma9551_init(struct mma9551_data *data)
{
	int ret;

	ret = mma9551_read_version(data->client);
	if (ret)
		return ret;

	return mma9551_set_device_state(data->client, true);
}

__attribute__((used)) static int mma9551_gpio_probe(struct iio_dev *indio_dev)
{
	struct gpio_desc *gpio;
	int i, ret;
	struct mma9551_data *data = iio_priv(indio_dev);
	struct device *dev = &data->client->dev;

	for (i = 0; i < MMA9551_GPIO_COUNT; i++) {
		gpio = devm_gpiod_get_index(dev, NULL, i, GPIOD_IN);
		if (IS_ERR(gpio)) {
			dev_err(dev, "acpi gpio get index failed\n");
			return PTR_ERR(gpio);
		}

		ret = gpiod_to_irq(gpio);
		if (ret < 0)
			return ret;

		data->irqs[i] = ret;
		ret = devm_request_threaded_irq(dev, data->irqs[i],
				NULL, mma9551_event_handler,
				IRQF_TRIGGER_RISING | IRQF_ONESHOT,
				MMA9551_IRQ_NAME, indio_dev);
		if (ret < 0) {
			dev_err(dev, "request irq %d failed\n", data->irqs[i]);
			return ret;
		}

		dev_dbg(dev, "gpio resource, no:%d irq:%d\n",
			desc_to_gpio(gpio), data->irqs[i]);
	}

	return 0;
}

__attribute__((used)) static const char *mma9551_match_acpi_device(struct device *dev)
{
	const struct acpi_device_id *id;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return NULL;

	return dev_name(dev);
}

__attribute__((used)) static int mma9551_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct mma9551_data *data;
	struct iio_dev *indio_dev;
	const char *name = NULL;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	if (id)
		name = id->name;
	else if (ACPI_HANDLE(&client->dev))
		name = mma9551_match_acpi_device(&client->dev);

	ret = mma9551_init(data);
	if (ret < 0)
		return ret;

	mutex_init(&data->mutex);

	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = mma9551_channels;
	indio_dev->num_channels = ARRAY_SIZE(mma9551_channels);
	indio_dev->name = name;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &mma9551_info;

	ret = mma9551_gpio_probe(indio_dev);
	if (ret < 0)
		goto out_poweroff;

	ret = pm_runtime_set_active(&client->dev);
	if (ret < 0)
		goto out_poweroff;

	pm_runtime_enable(&client->dev);
	pm_runtime_set_autosuspend_delay(&client->dev,
					 MMA9551_AUTO_SUSPEND_DELAY_MS);
	pm_runtime_use_autosuspend(&client->dev);

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "unable to register iio device\n");
		goto out_poweroff;
	}

	return 0;

out_poweroff:
	mma9551_set_device_state(client, false);

	return ret;
}

__attribute__((used)) static int mma9551_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct mma9551_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);
	pm_runtime_put_noidle(&client->dev);

	mutex_lock(&data->mutex);
	mma9551_set_device_state(data->client, false);
	mutex_unlock(&data->mutex);

	return 0;
}

