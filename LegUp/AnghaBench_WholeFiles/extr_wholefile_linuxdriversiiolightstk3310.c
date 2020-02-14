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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct stk3310_data {int ps_enabled; int als_enabled; int /*<<< orphan*/  lock; struct i2c_client* client; int /*<<< orphan*/  reg_flag_psint; int /*<<< orphan*/  timestamp; int /*<<< orphan*/  reg_flag_nf; struct regmap* regmap; int /*<<< orphan*/  reg_int_ps; int /*<<< orphan*/  reg_state; int /*<<< orphan*/  reg_ps_gain; int /*<<< orphan*/  reg_als_gain; int /*<<< orphan*/  reg_ps_it; int /*<<< orphan*/  reg_als_it; } ;
struct regmap {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int** channels; void* num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {scalar_t__ type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct device {int dummy; } ;
typedef  int irqreturn_t ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 void* ARRAY_SIZE (int**) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_INT_TIME 135 
#define  IIO_CHAN_INFO_RAW 134 
#define  IIO_CHAN_INFO_SCALE 133 
 int IIO_EV_DIR_FALLING ; 
 int IIO_EV_DIR_RISING ; 
 int IIO_EV_INFO_VALUE ; 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
 scalar_t__ IIO_LIGHT ; 
 scalar_t__ IIO_PROXIMITY ; 
 int /*<<< orphan*/  IIO_UNMOD_EVENT_CODE (scalar_t__,int,int /*<<< orphan*/ ,int) ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQ_HANDLED ; 
 int IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int STK3310_CHIP_ID_VAL ; 
 int /*<<< orphan*/  STK3310_DRIVER_NAME ; 
 int /*<<< orphan*/  STK3310_EVENT ; 
 int STK3310_PSINT_EN ; 
 int /*<<< orphan*/  STK3310_REGFIELD (int /*<<< orphan*/ ) ; 
#define  STK3310_REG_ALS_DATA_LSB 132 
#define  STK3310_REG_ALS_DATA_MSB 131 
#define  STK3310_REG_FLAG 130 
 int /*<<< orphan*/  STK3310_REG_ID ; 
#define  STK3310_REG_PS_DATA_LSB 129 
#define  STK3310_REG_PS_DATA_MSB 128 
 int STK3310_REG_THDH_PS ; 
 int STK3310_REG_THDL_PS ; 
 int STK3310_STATE_EN_ALS ; 
 int STK3310_STATE_EN_PS ; 
 int STK3310_STATE_STANDBY ; 
 int STK3311_CHIP_ID_VAL ; 
 int /*<<< orphan*/  als_gain ; 
 int /*<<< orphan*/  als_it ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be16 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int (*) (int,void*),int (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 int /*<<< orphan*/  flag_nf ; 
 int /*<<< orphan*/  flag_psint ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct stk3310_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  int_ps ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ps_gain ; 
 int /*<<< orphan*/  ps_it ; 
 int regmap_bulk_read (struct regmap*,int,int /*<<< orphan*/ *,int) ; 
 int regmap_bulk_write (struct regmap*,int,int /*<<< orphan*/ *,int) ; 
 int regmap_field_read (int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_field_write (int /*<<< orphan*/ ,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  state ; 
 int** stk3310_channels ; 
 int /*<<< orphan*/  stk3310_info ; 
 int** stk3310_it_table ; 
 int* stk3310_ps_max ; 
 int /*<<< orphan*/  stk3310_regmap_config ; 
 int** stk3310_scale_table ; 

__attribute__((used)) static int stk3310_get_index(const int table[][2], int table_size,
			     int val, int val2)
{
	int i;

	for (i = 0; i < table_size; i++) {
		if (val == table[i][0] && val2 == table[i][1])
			return i;
	}

	return -EINVAL;
}

__attribute__((used)) static int stk3310_read_event(struct iio_dev *indio_dev,
			      const struct iio_chan_spec *chan,
			      enum iio_event_type type,
			      enum iio_event_direction dir,
			      enum iio_event_info info,
			      int *val, int *val2)
{
	u8 reg;
	__be16 buf;
	int ret;
	struct stk3310_data *data = iio_priv(indio_dev);

	if (info != IIO_EV_INFO_VALUE)
		return -EINVAL;

	/* Only proximity interrupts are implemented at the moment. */
	if (dir == IIO_EV_DIR_RISING)
		reg = STK3310_REG_THDH_PS;
	else if (dir == IIO_EV_DIR_FALLING)
		reg = STK3310_REG_THDL_PS;
	else
		return -EINVAL;

	mutex_lock(&data->lock);
	ret = regmap_bulk_read(data->regmap, reg, &buf, 2);
	mutex_unlock(&data->lock);
	if (ret < 0) {
		dev_err(&data->client->dev, "register read failed\n");
		return ret;
	}
	*val = be16_to_cpu(buf);

	return IIO_VAL_INT;
}

__attribute__((used)) static int stk3310_write_event(struct iio_dev *indio_dev,
			       const struct iio_chan_spec *chan,
			       enum iio_event_type type,
			       enum iio_event_direction dir,
			       enum iio_event_info info,
			       int val, int val2)
{
	u8 reg;
	__be16 buf;
	int ret;
	unsigned int index;
	struct stk3310_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	ret = regmap_field_read(data->reg_ps_gain, &index);
	if (ret < 0)
		return ret;

	if (val < 0 || val > stk3310_ps_max[index])
		return -EINVAL;

	if (dir == IIO_EV_DIR_RISING)
		reg = STK3310_REG_THDH_PS;
	else if (dir == IIO_EV_DIR_FALLING)
		reg = STK3310_REG_THDL_PS;
	else
		return -EINVAL;

	buf = cpu_to_be16(val);
	ret = regmap_bulk_write(data->regmap, reg, &buf, 2);
	if (ret < 0)
		dev_err(&client->dev, "failed to set PS threshold!\n");

	return ret;
}

__attribute__((used)) static int stk3310_read_event_config(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir)
{
	unsigned int event_val;
	int ret;
	struct stk3310_data *data = iio_priv(indio_dev);

	ret = regmap_field_read(data->reg_int_ps, &event_val);
	if (ret < 0)
		return ret;

	return event_val;
}

__attribute__((used)) static int stk3310_write_event_config(struct iio_dev *indio_dev,
				      const struct iio_chan_spec *chan,
				      enum iio_event_type type,
				      enum iio_event_direction dir,
				      int state)
{
	int ret;
	struct stk3310_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	if (state < 0 || state > 7)
		return -EINVAL;

	/* Set INT_PS value */
	mutex_lock(&data->lock);
	ret = regmap_field_write(data->reg_int_ps, state);
	if (ret < 0)
		dev_err(&client->dev, "failed to set interrupt mode\n");
	mutex_unlock(&data->lock);

	return ret;
}

__attribute__((used)) static int stk3310_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	u8 reg;
	__be16 buf;
	int ret;
	unsigned int index;
	struct stk3310_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	if (chan->type != IIO_LIGHT && chan->type != IIO_PROXIMITY)
		return -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (chan->type == IIO_LIGHT)
			reg = STK3310_REG_ALS_DATA_MSB;
		else
			reg = STK3310_REG_PS_DATA_MSB;

		mutex_lock(&data->lock);
		ret = regmap_bulk_read(data->regmap, reg, &buf, 2);
		if (ret < 0) {
			dev_err(&client->dev, "register read failed\n");
			mutex_unlock(&data->lock);
			return ret;
		}
		*val = be16_to_cpu(buf);
		mutex_unlock(&data->lock);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_INT_TIME:
		if (chan->type == IIO_LIGHT)
			ret = regmap_field_read(data->reg_als_it, &index);
		else
			ret = regmap_field_read(data->reg_ps_it, &index);
		if (ret < 0)
			return ret;

		*val = stk3310_it_table[index][0];
		*val2 = stk3310_it_table[index][1];
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SCALE:
		if (chan->type == IIO_LIGHT)
			ret = regmap_field_read(data->reg_als_gain, &index);
		else
			ret = regmap_field_read(data->reg_ps_gain, &index);
		if (ret < 0)
			return ret;

		*val = stk3310_scale_table[index][0];
		*val2 = stk3310_scale_table[index][1];
		return IIO_VAL_INT_PLUS_MICRO;
	}

	return -EINVAL;
}

__attribute__((used)) static int stk3310_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	int ret;
	int index;
	struct stk3310_data *data = iio_priv(indio_dev);

	if (chan->type != IIO_LIGHT && chan->type != IIO_PROXIMITY)
		return -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_INT_TIME:
		index = stk3310_get_index(stk3310_it_table,
					  ARRAY_SIZE(stk3310_it_table),
					  val, val2);
		if (index < 0)
			return -EINVAL;
		mutex_lock(&data->lock);
		if (chan->type == IIO_LIGHT)
			ret = regmap_field_write(data->reg_als_it, index);
		else
			ret = regmap_field_write(data->reg_ps_it, index);
		if (ret < 0)
			dev_err(&data->client->dev,
				"sensor configuration failed\n");
		mutex_unlock(&data->lock);
		return ret;

	case IIO_CHAN_INFO_SCALE:
		index = stk3310_get_index(stk3310_scale_table,
					  ARRAY_SIZE(stk3310_scale_table),
					  val, val2);
		if (index < 0)
			return -EINVAL;
		mutex_lock(&data->lock);
		if (chan->type == IIO_LIGHT)
			ret = regmap_field_write(data->reg_als_gain, index);
		else
			ret = regmap_field_write(data->reg_ps_gain, index);
		if (ret < 0)
			dev_err(&data->client->dev,
				"sensor configuration failed\n");
		mutex_unlock(&data->lock);
		return ret;
	}

	return -EINVAL;
}

__attribute__((used)) static int stk3310_set_state(struct stk3310_data *data, u8 state)
{
	int ret;
	struct i2c_client *client = data->client;

	/* 3-bit state; 0b100 is not supported. */
	if (state > 7 || state == 4)
		return -EINVAL;

	mutex_lock(&data->lock);
	ret = regmap_field_write(data->reg_state, state);
	if (ret < 0) {
		dev_err(&client->dev, "failed to change sensor state\n");
	} else if (state != STK3310_STATE_STANDBY) {
		/* Don't reset the 'enabled' flags if we're going in standby */
		data->ps_enabled  = !!(state & STK3310_STATE_EN_PS);
		data->als_enabled = !!(state & STK3310_STATE_EN_ALS);
	}
	mutex_unlock(&data->lock);

	return ret;
}

__attribute__((used)) static int stk3310_init(struct iio_dev *indio_dev)
{
	int ret;
	int chipid;
	u8 state;
	struct stk3310_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	ret = regmap_read(data->regmap, STK3310_REG_ID, &chipid);
	if (ret < 0)
		return ret;

	if (chipid != STK3310_CHIP_ID_VAL &&
	    chipid != STK3311_CHIP_ID_VAL) {
		dev_err(&client->dev, "invalid chip id: 0x%x\n", chipid);
		return -ENODEV;
	}

	state = STK3310_STATE_EN_ALS | STK3310_STATE_EN_PS;
	ret = stk3310_set_state(data, state);
	if (ret < 0) {
		dev_err(&client->dev, "failed to enable sensor");
		return ret;
	}

	/* Enable PS interrupts */
	ret = regmap_field_write(data->reg_int_ps, STK3310_PSINT_EN);
	if (ret < 0)
		dev_err(&client->dev, "failed to enable interrupts!\n");

	return ret;
}

__attribute__((used)) static bool stk3310_is_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case STK3310_REG_ALS_DATA_MSB:
	case STK3310_REG_ALS_DATA_LSB:
	case STK3310_REG_PS_DATA_LSB:
	case STK3310_REG_PS_DATA_MSB:
	case STK3310_REG_FLAG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int stk3310_regmap_init(struct stk3310_data *data)
{
	struct regmap *regmap;
	struct i2c_client *client;

	client = data->client;
	regmap = devm_regmap_init_i2c(client, &stk3310_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "regmap initialization failed.\n");
		return PTR_ERR(regmap);
	}
	data->regmap = regmap;

	STK3310_REGFIELD(state);
	STK3310_REGFIELD(als_gain);
	STK3310_REGFIELD(ps_gain);
	STK3310_REGFIELD(als_it);
	STK3310_REGFIELD(ps_it);
	STK3310_REGFIELD(int_ps);
	STK3310_REGFIELD(flag_psint);
	STK3310_REGFIELD(flag_nf);

	return 0;
}

__attribute__((used)) static irqreturn_t stk3310_irq_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct stk3310_data *data = iio_priv(indio_dev);

	data->timestamp = iio_get_time_ns(indio_dev);

	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t stk3310_irq_event_handler(int irq, void *private)
{
	int ret;
	unsigned int dir;
	u64 event;

	struct iio_dev *indio_dev = private;
	struct stk3310_data *data = iio_priv(indio_dev);

	/* Read FLAG_NF to figure out what threshold has been met. */
	mutex_lock(&data->lock);
	ret = regmap_field_read(data->reg_flag_nf, &dir);
	if (ret < 0) {
		dev_err(&data->client->dev, "register read failed\n");
		mutex_unlock(&data->lock);
		return ret;
	}
	event = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, 1,
				     IIO_EV_TYPE_THRESH,
				     (dir ? IIO_EV_DIR_FALLING :
					    IIO_EV_DIR_RISING));
	iio_push_event(indio_dev, event, data->timestamp);

	/* Reset the interrupt flag */
	ret = regmap_field_write(data->reg_flag_psint, 0);
	if (ret < 0)
		dev_err(&data->client->dev, "failed to reset interrupts\n");
	mutex_unlock(&data->lock);

	return IRQ_HANDLED;
}

__attribute__((used)) static int stk3310_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	int ret;
	struct iio_dev *indio_dev;
	struct stk3310_data *data;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev) {
		dev_err(&client->dev, "iio allocation failed!\n");
		return -ENOMEM;
	}

	data = iio_priv(indio_dev);
	data->client = client;
	i2c_set_clientdata(client, indio_dev);
	mutex_init(&data->lock);

	ret = stk3310_regmap_init(data);
	if (ret < 0)
		return ret;

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &stk3310_info;
	indio_dev->name = STK3310_DRIVER_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = stk3310_channels;
	indio_dev->num_channels = ARRAY_SIZE(stk3310_channels);

	ret = stk3310_init(indio_dev);
	if (ret < 0)
		return ret;

	if (client->irq > 0) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
						stk3310_irq_handler,
						stk3310_irq_event_handler,
						IRQF_TRIGGER_FALLING |
						IRQF_ONESHOT,
						STK3310_EVENT, indio_dev);
		if (ret < 0) {
			dev_err(&client->dev, "request irq %d failed\n",
				client->irq);
			goto err_standby;
		}
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "device_register failed\n");
		goto err_standby;
	}

	return 0;

err_standby:
	stk3310_set_state(data, STK3310_STATE_STANDBY);
	return ret;
}

__attribute__((used)) static int stk3310_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	return stk3310_set_state(iio_priv(indio_dev), STK3310_STATE_STANDBY);
}

