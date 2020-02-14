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
typedef  int /*<<< orphan*/  u8 ;
struct max30100_data {int /*<<< orphan*/  regmap; int /*<<< orphan*/  lock; struct i2c_client* client; struct iio_dev* indio_dev; int /*<<< orphan*/  buffer; } ;
struct TYPE_2__ {struct device* parent; } ;
struct iio_dev {unsigned int* channels; int num_channels; int modes; TYPE_1__ dev; int /*<<< orphan*/ * setup_ops; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int dummy; } ;
struct iio_buffer {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct i2c_client {unsigned int irq; struct device dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int*) ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 137 
#define  IIO_CHAN_INFO_SCALE 136 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int INDIO_BUFFER_SOFTWARE ; 
 int INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX30100_DRV_NAME ; 
#define  MAX30100_REG_FIFO_DATA 135 
 int MAX30100_REG_FIFO_DATA_ENTRY_COUNT ; 
 int MAX30100_REG_FIFO_DATA_ENTRY_LEN ; 
#define  MAX30100_REG_FIFO_OVR_CTR 134 
#define  MAX30100_REG_FIFO_RD_PTR 133 
#define  MAX30100_REG_FIFO_WR_PTR 132 
 int const MAX30100_REG_INT_ENABLE ; 
 int MAX30100_REG_INT_ENABLE_FIFO_EN ; 
 int MAX30100_REG_INT_ENABLE_MASK ; 
 int MAX30100_REG_INT_ENABLE_MASK_SHIFT ; 
#define  MAX30100_REG_INT_STATUS 131 
 unsigned int MAX30100_REG_INT_STATUS_FIFO_RDY ; 
 int const MAX30100_REG_LED_CONFIG ; 
 int MAX30100_REG_LED_CONFIG_24MA ; 
 int MAX30100_REG_LED_CONFIG_50MA ; 
 int MAX30100_REG_LED_CONFIG_LED_MASK ; 
 int MAX30100_REG_LED_CONFIG_RED_LED_SHIFT ; 
#define  MAX30100_REG_MODE_CONFIG 130 
 int MAX30100_REG_MODE_CONFIG_MODE_HR_EN ; 
 int MAX30100_REG_MODE_CONFIG_MODE_MASK ; 
 int MAX30100_REG_MODE_CONFIG_MODE_SPO2_EN ; 
 int MAX30100_REG_MODE_CONFIG_PWR ; 
 int MAX30100_REG_MODE_CONFIG_TEMP_EN ; 
 int const MAX30100_REG_SPO2_CONFIG ; 
 int MAX30100_REG_SPO2_CONFIG_100HZ ; 
 int MAX30100_REG_SPO2_CONFIG_HI_RES_EN ; 
#define  MAX30100_REG_TEMP_FRACTION 129 
#define  MAX30100_REG_TEMP_INTEGER 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 struct iio_buffer* devm_iio_kfifo_allocate (struct device*) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (struct device*,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct iio_dev*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int const,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iio_buffer_enabled (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_attach_buffer (struct iio_dev*,struct iio_buffer*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct max30100_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers (struct iio_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max30100_buffer_setup_ops ; 
 unsigned int* max30100_channels ; 
 int /*<<< orphan*/  max30100_info ; 
 unsigned int* max30100_led_current_mapping ; 
 int /*<<< orphan*/  max30100_regmap_config ; 
 int /*<<< orphan*/  max30100_scan_masks ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int of_property_read_u32_array (struct device_node*,char*,unsigned int*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int const,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int const,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int const,int) ; 
 int sign_extend32 (int,int) ; 

__attribute__((used)) static bool max30100_is_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX30100_REG_INT_STATUS:
	case MAX30100_REG_MODE_CONFIG:
	case MAX30100_REG_FIFO_WR_PTR:
	case MAX30100_REG_FIFO_OVR_CTR:
	case MAX30100_REG_FIFO_RD_PTR:
	case MAX30100_REG_FIFO_DATA:
	case MAX30100_REG_TEMP_INTEGER:
	case MAX30100_REG_TEMP_FRACTION:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int max30100_set_powermode(struct max30100_data *data, bool state)
{
	return regmap_update_bits(data->regmap, MAX30100_REG_MODE_CONFIG,
				  MAX30100_REG_MODE_CONFIG_PWR,
				  state ? 0 : MAX30100_REG_MODE_CONFIG_PWR);
}

__attribute__((used)) static int max30100_clear_fifo(struct max30100_data *data)
{
	int ret;

	ret = regmap_write(data->regmap, MAX30100_REG_FIFO_WR_PTR, 0);
	if (ret)
		return ret;

	ret = regmap_write(data->regmap, MAX30100_REG_FIFO_OVR_CTR, 0);
	if (ret)
		return ret;

	return regmap_write(data->regmap, MAX30100_REG_FIFO_RD_PTR, 0);
}

__attribute__((used)) static int max30100_buffer_postenable(struct iio_dev *indio_dev)
{
	struct max30100_data *data = iio_priv(indio_dev);
	int ret;

	ret = max30100_set_powermode(data, true);
	if (ret)
		return ret;

	return max30100_clear_fifo(data);
}

__attribute__((used)) static int max30100_buffer_predisable(struct iio_dev *indio_dev)
{
	struct max30100_data *data = iio_priv(indio_dev);

	return max30100_set_powermode(data, false);
}

__attribute__((used)) static inline int max30100_fifo_count(struct max30100_data *data)
{
	unsigned int val;
	int ret;

	ret = regmap_read(data->regmap, MAX30100_REG_INT_STATUS, &val);
	if (ret)
		return ret;

	/* FIFO is almost full */
	if (val & MAX30100_REG_INT_STATUS_FIFO_RDY)
		return MAX30100_REG_FIFO_DATA_ENTRY_COUNT - 1;

	return 0;
}

__attribute__((used)) static int max30100_read_measurement(struct max30100_data *data)
{
	int ret;

	ret = i2c_smbus_read_i2c_block_data(data->client,
					    MAX30100_REG_FIFO_DATA,
					    MAX30100_REG_FIFO_DATA_ENTRY_LEN,
					    (u8 *) &data->buffer);

	return (ret == MAX30100_REG_FIFO_DATA_ENTRY_LEN) ? 0 : ret;
}

__attribute__((used)) static irqreturn_t max30100_interrupt_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct max30100_data *data = iio_priv(indio_dev);
	int ret, cnt = 0;

	mutex_lock(&data->lock);

	while (cnt || (cnt = max30100_fifo_count(data)) > 0) {
		ret = max30100_read_measurement(data);
		if (ret)
			break;

		iio_push_to_buffers(data->indio_dev, data->buffer);
		cnt--;
	}

	mutex_unlock(&data->lock);

	return IRQ_HANDLED;
}

__attribute__((used)) static int max30100_get_current_idx(unsigned int val, int *reg)
{
	int idx;

	/* LED turned off */
	if (val == 0) {
		*reg = 0;
		return 0;
	}

	for (idx = 0; idx < ARRAY_SIZE(max30100_led_current_mapping); idx++) {
		if (max30100_led_current_mapping[idx] == val) {
			*reg = idx + 1;
			return 0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int max30100_led_init(struct max30100_data *data)
{
	struct device *dev = &data->client->dev;
	struct device_node *np = dev->of_node;
	unsigned int val[2];
	int reg, ret;

	ret = of_property_read_u32_array(np, "maxim,led-current-microamp",
					(unsigned int *) &val, 2);
	if (ret) {
		/* Default to 24 mA RED LED, 50 mA IR LED */
		reg = (MAX30100_REG_LED_CONFIG_24MA <<
			MAX30100_REG_LED_CONFIG_RED_LED_SHIFT) |
			MAX30100_REG_LED_CONFIG_50MA;
		dev_warn(dev, "no led-current-microamp set");

		return regmap_write(data->regmap, MAX30100_REG_LED_CONFIG, reg);
	}

	/* RED LED current */
	ret = max30100_get_current_idx(val[0], &reg);
	if (ret) {
		dev_err(dev, "invalid RED current setting %d", val[0]);
		return ret;
	}

	ret = regmap_update_bits(data->regmap, MAX30100_REG_LED_CONFIG,
		MAX30100_REG_LED_CONFIG_LED_MASK <<
		MAX30100_REG_LED_CONFIG_RED_LED_SHIFT,
		reg << MAX30100_REG_LED_CONFIG_RED_LED_SHIFT);
	if (ret)
		return ret;

	/* IR LED current */
	ret = max30100_get_current_idx(val[1], &reg);
	if (ret) {
		dev_err(dev, "invalid IR current setting %d", val[1]);
		return ret;
	}

	return regmap_update_bits(data->regmap, MAX30100_REG_LED_CONFIG,
		MAX30100_REG_LED_CONFIG_LED_MASK, reg);
}

__attribute__((used)) static int max30100_chip_init(struct max30100_data *data)
{
	int ret;

	/* setup LED current settings */
	ret = max30100_led_init(data);
	if (ret)
		return ret;

	/* enable hi-res SPO2 readings at 100Hz */
	ret = regmap_write(data->regmap, MAX30100_REG_SPO2_CONFIG,
				 MAX30100_REG_SPO2_CONFIG_HI_RES_EN |
				 MAX30100_REG_SPO2_CONFIG_100HZ);
	if (ret)
		return ret;

	/* enable SPO2 mode */
	ret = regmap_update_bits(data->regmap, MAX30100_REG_MODE_CONFIG,
				 MAX30100_REG_MODE_CONFIG_MODE_MASK,
				 MAX30100_REG_MODE_CONFIG_MODE_HR_EN |
				 MAX30100_REG_MODE_CONFIG_MODE_SPO2_EN);
	if (ret)
		return ret;

	/* enable FIFO interrupt */
	return regmap_update_bits(data->regmap, MAX30100_REG_INT_ENABLE,
				 MAX30100_REG_INT_ENABLE_MASK,
				 MAX30100_REG_INT_ENABLE_FIFO_EN
				 << MAX30100_REG_INT_ENABLE_MASK_SHIFT);
}

__attribute__((used)) static int max30100_read_temp(struct max30100_data *data, int *val)
{
	int ret;
	unsigned int reg;

	ret = regmap_read(data->regmap, MAX30100_REG_TEMP_INTEGER, &reg);
	if (ret < 0)
		return ret;
	*val = reg << 4;

	ret = regmap_read(data->regmap, MAX30100_REG_TEMP_FRACTION, &reg);
	if (ret < 0)
		return ret;

	*val |= reg & 0xf;
	*val = sign_extend32(*val, 11);

	return 0;
}

__attribute__((used)) static int max30100_get_temp(struct max30100_data *data, int *val)
{
	int ret;

	/* start acquisition */
	ret = regmap_update_bits(data->regmap, MAX30100_REG_MODE_CONFIG,
				 MAX30100_REG_MODE_CONFIG_TEMP_EN,
				 MAX30100_REG_MODE_CONFIG_TEMP_EN);
	if (ret)
		return ret;

	msleep(35);

	return max30100_read_temp(data, val);
}

__attribute__((used)) static int max30100_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val, int *val2, long mask)
{
	struct max30100_data *data = iio_priv(indio_dev);
	int ret = -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		/*
		 * Temperature reading can only be acquired while engine
		 * is running
		 */
		mutex_lock(&indio_dev->mlock);

		if (!iio_buffer_enabled(indio_dev))
			ret = -EAGAIN;
		else {
			ret = max30100_get_temp(data, val);
			if (!ret)
				ret = IIO_VAL_INT;

		}

		mutex_unlock(&indio_dev->mlock);
		break;
	case IIO_CHAN_INFO_SCALE:
		*val = 1;  /* 0.0625 */
		*val2 = 16;
		ret = IIO_VAL_FRACTIONAL;
		break;
	}

	return ret;
}

__attribute__((used)) static int max30100_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct max30100_data *data;
	struct iio_buffer *buffer;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	buffer = devm_iio_kfifo_allocate(&client->dev);
	if (!buffer)
		return -ENOMEM;

	iio_device_attach_buffer(indio_dev, buffer);

	indio_dev->name = MAX30100_DRV_NAME;
	indio_dev->channels = max30100_channels;
	indio_dev->info = &max30100_info;
	indio_dev->num_channels = ARRAY_SIZE(max30100_channels);
	indio_dev->available_scan_masks = max30100_scan_masks;
	indio_dev->modes = (INDIO_BUFFER_SOFTWARE | INDIO_DIRECT_MODE);
	indio_dev->setup_ops = &max30100_buffer_setup_ops;
	indio_dev->dev.parent = &client->dev;

	data = iio_priv(indio_dev);
	data->indio_dev = indio_dev;
	data->client = client;

	mutex_init(&data->lock);
	i2c_set_clientdata(client, indio_dev);

	data->regmap = devm_regmap_init_i2c(client, &max30100_regmap_config);
	if (IS_ERR(data->regmap)) {
		dev_err(&client->dev, "regmap initialization failed.\n");
		return PTR_ERR(data->regmap);
	}
	max30100_set_powermode(data, false);

	ret = max30100_chip_init(data);
	if (ret)
		return ret;

	if (client->irq <= 0) {
		dev_err(&client->dev, "no valid irq defined\n");
		return -EINVAL;
	}
	ret = devm_request_threaded_irq(&client->dev, client->irq,
					NULL, max30100_interrupt_handler,
					IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
					"max30100_irq", indio_dev);
	if (ret) {
		dev_err(&client->dev, "request irq (%d) failed\n", client->irq);
		return ret;
	}

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int max30100_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct max30100_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	max30100_set_powermode(data, false);

	return 0;
}

