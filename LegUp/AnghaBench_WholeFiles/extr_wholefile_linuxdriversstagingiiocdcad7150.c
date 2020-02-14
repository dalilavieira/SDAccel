#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u64 ;
typedef  int u16 ;
struct iio_dev_attr {int /*<<< orphan*/  address; } ;
struct TYPE_6__ {TYPE_2__* parent; } ;
struct iio_dev {TYPE_1__ dev; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {size_t channel; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct TYPE_7__ {scalar_t__ platform_data; } ;
struct i2c_client {unsigned int irq; TYPE_2__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct ad7150_chip_info {scalar_t__ current_event; int** threshold; int** mag_sensitivity; int** mag_timeout; int** thresh_sensitivity; int** thresh_timeout; int old_state; struct i2c_client* client; int /*<<< orphan*/  state_lock; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;

/* Variables and functions */
 int /*<<< orphan*/  AD7150_CFG ; 
 int /*<<< orphan*/  AD7150_STATUS ; 
 int AD7150_STATUS_OUT1 ; 
 int AD7150_STATUS_OUT2 ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IIO_CAPACITANCE ; 
#define  IIO_CHAN_INFO_AVERAGE_RAW 132 
#define  IIO_CHAN_INFO_RAW 131 
 int IIO_EVENT_CODE_EXTRACT_CHAN (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_DIR (int /*<<< orphan*/ ) ; 
 int IIO_EVENT_CODE_EXTRACT_TYPE (int /*<<< orphan*/ ) ; 
 int IIO_EV_DIR_FALLING ; 
 int IIO_EV_DIR_RISING ; 
#define  IIO_EV_TYPE_MAG_ADAPTIVE 130 
#define  IIO_EV_TYPE_THRESH 129 
#define  IIO_EV_TYPE_THRESH_ADAPTIVE 128 
 scalar_t__ IIO_UNMOD_EVENT_CODE (int /*<<< orphan*/ ,int,int const,int) ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/ ** ad7150_addresses ; 
 int /*<<< orphan*/  ad7150_channels ; 
 int /*<<< orphan*/  ad7150_info ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int /*<<< orphan*/ ,unsigned int) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 int devm_iio_device_register (TYPE_2__*,struct iio_dev*) ; 
 int devm_request_threaded_irq (TYPE_2__*,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct ad7150_chip_info* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 int kstrtou8 (char const*,int,int*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int swab16 (int) ; 
 struct iio_dev_attr* to_iio_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int ad7150_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val,
			   int *val2,
			   long mask)
{
	int ret;
	struct ad7150_chip_info *chip = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = i2c_smbus_read_word_data(chip->client,
					ad7150_addresses[chan->channel][0]);
		if (ret < 0)
			return ret;
		*val = swab16(ret);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_AVERAGE_RAW:
		ret = i2c_smbus_read_word_data(chip->client,
					ad7150_addresses[chan->channel][1]);
		if (ret < 0)
			return ret;
		*val = swab16(ret);
		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int ad7150_read_event_config(struct iio_dev *indio_dev,
				    const struct iio_chan_spec *chan,
				    enum iio_event_type type,
				    enum iio_event_direction dir)
{
	int ret;
	u8 threshtype;
	bool adaptive;
	struct ad7150_chip_info *chip = iio_priv(indio_dev);

	ret = i2c_smbus_read_byte_data(chip->client, AD7150_CFG);
	if (ret < 0)
		return ret;

	threshtype = (ret >> 5) & 0x03;
	adaptive = !!(ret & 0x80);

	switch (type) {
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		if (dir == IIO_EV_DIR_RISING)
			return adaptive && (threshtype == 0x1);
		return adaptive && (threshtype == 0x0);
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		if (dir == IIO_EV_DIR_RISING)
			return adaptive && (threshtype == 0x3);
		return adaptive && (threshtype == 0x2);
	case IIO_EV_TYPE_THRESH:
		if (dir == IIO_EV_DIR_RISING)
			return !adaptive && (threshtype == 0x1);
		return !adaptive && (threshtype == 0x0);
	default:
		break;
	}
	return -EINVAL;
}

__attribute__((used)) static int ad7150_write_event_params(struct iio_dev *indio_dev,
				     unsigned int chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir)
{
	int ret;
	u16 value;
	u8 sens, timeout;
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	int rising = (dir == IIO_EV_DIR_RISING);
	u64 event_code;

	event_code = IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE, chan, type, dir);

	if (event_code != chip->current_event)
		return 0;

	switch (type) {
		/* Note completely different from the adaptive versions */
	case IIO_EV_TYPE_THRESH:
		value = chip->threshold[rising][chan];
		return i2c_smbus_write_word_data(chip->client,
						ad7150_addresses[chan][3],
						swab16(value));
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		sens = chip->mag_sensitivity[rising][chan];
		timeout = chip->mag_timeout[rising][chan];
		break;
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		sens = chip->thresh_sensitivity[rising][chan];
		timeout = chip->thresh_timeout[rising][chan];
		break;
	default:
		return -EINVAL;
	}
	ret = i2c_smbus_write_byte_data(chip->client,
					ad7150_addresses[chan][4],
					sens);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(chip->client,
					ad7150_addresses[chan][5],
					timeout);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int ad7150_write_event_config(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir, int state)
{
	u8 thresh_type, cfg, adaptive;
	int ret;
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	int rising = (dir == IIO_EV_DIR_RISING);
	u64 event_code;

	/* Something must always be turned on */
	if (!state)
		return -EINVAL;

	event_code = IIO_UNMOD_EVENT_CODE(chan->type, chan->channel, type, dir);
	if (event_code == chip->current_event)
		return 0;
	mutex_lock(&chip->state_lock);
	ret = i2c_smbus_read_byte_data(chip->client, AD7150_CFG);
	if (ret < 0)
		goto error_ret;

	cfg = ret & ~((0x03 << 5) | BIT(7));

	switch (type) {
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		adaptive = 1;
		if (rising)
			thresh_type = 0x1;
		else
			thresh_type = 0x0;
		break;
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		adaptive = 1;
		if (rising)
			thresh_type = 0x3;
		else
			thresh_type = 0x2;
		break;
	case IIO_EV_TYPE_THRESH:
		adaptive = 0;
		if (rising)
			thresh_type = 0x1;
		else
			thresh_type = 0x0;
		break;
	default:
		ret = -EINVAL;
		goto error_ret;
	}

	cfg |= (!adaptive << 7) | (thresh_type << 5);

	ret = i2c_smbus_write_byte_data(chip->client, AD7150_CFG, cfg);
	if (ret < 0)
		goto error_ret;

	chip->current_event = event_code;

	/* update control attributes */
	ret = ad7150_write_event_params(indio_dev, chan->channel, type, dir);
error_ret:
	mutex_unlock(&chip->state_lock);

	return ret;
}

__attribute__((used)) static int ad7150_read_event_value(struct iio_dev *indio_dev,
				   const struct iio_chan_spec *chan,
				   enum iio_event_type type,
				   enum iio_event_direction dir,
				   enum iio_event_info info,
				   int *val, int *val2)
{
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	int rising = (dir == IIO_EV_DIR_RISING);

	/* Complex register sharing going on here */
	switch (type) {
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		*val = chip->mag_sensitivity[rising][chan->channel];
		return IIO_VAL_INT;
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		*val = chip->thresh_sensitivity[rising][chan->channel];
		return IIO_VAL_INT;
	case IIO_EV_TYPE_THRESH:
		*val = chip->threshold[rising][chan->channel];
		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int ad7150_write_event_value(struct iio_dev *indio_dev,
				    const struct iio_chan_spec *chan,
				    enum iio_event_type type,
				    enum iio_event_direction dir,
				    enum iio_event_info info,
				    int val, int val2)
{
	int ret;
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	int rising = (dir == IIO_EV_DIR_RISING);

	mutex_lock(&chip->state_lock);
	switch (type) {
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		chip->mag_sensitivity[rising][chan->channel] = val;
		break;
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		chip->thresh_sensitivity[rising][chan->channel] = val;
		break;
	case IIO_EV_TYPE_THRESH:
		chip->threshold[rising][chan->channel] = val;
		break;
	default:
		ret = -EINVAL;
		goto error_ret;
	}

	/* write back if active */
	ret = ad7150_write_event_params(indio_dev, chan->channel, type, dir);

error_ret:
	mutex_unlock(&chip->state_lock);
	return ret;
}

__attribute__((used)) static ssize_t ad7150_show_timeout(struct device *dev,
				   struct device_attribute *attr,
				   char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
	u8 value;

	/* use the event code for consistency reasons */
	int chan = IIO_EVENT_CODE_EXTRACT_CHAN(this_attr->address);
	int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(this_attr->address)
			== IIO_EV_DIR_RISING);

	switch (IIO_EVENT_CODE_EXTRACT_TYPE(this_attr->address)) {
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		value = chip->mag_timeout[rising][chan];
		break;
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		value = chip->thresh_timeout[rising][chan];
		break;
	default:
		return -EINVAL;
	}

	return sprintf(buf, "%d\n", value);
}

__attribute__((used)) static ssize_t ad7150_store_timeout(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf,
				    size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
	int chan = IIO_EVENT_CODE_EXTRACT_CHAN(this_attr->address);
	enum iio_event_direction dir;
	enum iio_event_type type;
	int rising;
	u8 data;
	int ret;

	type = IIO_EVENT_CODE_EXTRACT_TYPE(this_attr->address);
	dir = IIO_EVENT_CODE_EXTRACT_DIR(this_attr->address);
	rising = (dir == IIO_EV_DIR_RISING);

	ret = kstrtou8(buf, 10, &data);
	if (ret < 0)
		return ret;

	mutex_lock(&chip->state_lock);
	switch (type) {
	case IIO_EV_TYPE_MAG_ADAPTIVE:
		chip->mag_timeout[rising][chan] = data;
		break;
	case IIO_EV_TYPE_THRESH_ADAPTIVE:
		chip->thresh_timeout[rising][chan] = data;
		break;
	default:
		ret = -EINVAL;
		goto error_ret;
	}

	ret = ad7150_write_event_params(indio_dev, chan, type, dir);
error_ret:
	mutex_unlock(&chip->state_lock);

	if (ret < 0)
		return ret;

	return len;
}

__attribute__((used)) static irqreturn_t ad7150_event_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct ad7150_chip_info *chip = iio_priv(indio_dev);
	u8 int_status;
	s64 timestamp = iio_get_time_ns(indio_dev);
	int ret;

	ret = i2c_smbus_read_byte_data(chip->client, AD7150_STATUS);
	if (ret < 0)
		return IRQ_HANDLED;

	int_status = ret;

	if ((int_status & AD7150_STATUS_OUT1) &&
	    !(chip->old_state & AD7150_STATUS_OUT1))
		iio_push_event(indio_dev,
			       IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
						    0,
						    IIO_EV_TYPE_THRESH,
						    IIO_EV_DIR_RISING),
				timestamp);
	else if ((!(int_status & AD7150_STATUS_OUT1)) &&
		 (chip->old_state & AD7150_STATUS_OUT1))
		iio_push_event(indio_dev,
			       IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
						    0,
						    IIO_EV_TYPE_THRESH,
						    IIO_EV_DIR_FALLING),
			       timestamp);

	if ((int_status & AD7150_STATUS_OUT2) &&
	    !(chip->old_state & AD7150_STATUS_OUT2))
		iio_push_event(indio_dev,
			       IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
						    1,
						    IIO_EV_TYPE_THRESH,
						    IIO_EV_DIR_RISING),
			       timestamp);
	else if ((!(int_status & AD7150_STATUS_OUT2)) &&
		 (chip->old_state & AD7150_STATUS_OUT2))
		iio_push_event(indio_dev,
			       IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
						    1,
						    IIO_EV_TYPE_THRESH,
						    IIO_EV_DIR_FALLING),
			       timestamp);
	/* store the status to avoid repushing same events */
	chip->old_state = int_status;

	return IRQ_HANDLED;
}

__attribute__((used)) static int ad7150_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct ad7150_chip_info *chip;
	struct iio_dev *indio_dev;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*chip));
	if (!indio_dev)
		return -ENOMEM;
	chip = iio_priv(indio_dev);
	mutex_init(&chip->state_lock);
	/* this is only used for device removal purposes */
	i2c_set_clientdata(client, indio_dev);

	chip->client = client;

	indio_dev->name = id->name;
	indio_dev->channels = ad7150_channels;
	indio_dev->num_channels = ARRAY_SIZE(ad7150_channels);
	/* Establish that the iio_dev is a child of the i2c device */
	indio_dev->dev.parent = &client->dev;

	indio_dev->info = &ad7150_info;

	indio_dev->modes = INDIO_DIRECT_MODE;

	if (client->irq) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
						NULL,
						&ad7150_event_handler,
						IRQF_TRIGGER_RISING |
						IRQF_TRIGGER_FALLING |
						IRQF_ONESHOT,
						"ad7150_irq1",
						indio_dev);
		if (ret)
			return ret;
	}

	if (client->dev.platform_data) {
		ret = devm_request_threaded_irq(&client->dev, *(unsigned int *)
						client->dev.platform_data,
						NULL,
						&ad7150_event_handler,
						IRQF_TRIGGER_RISING |
						IRQF_TRIGGER_FALLING |
						IRQF_ONESHOT,
						"ad7150_irq2",
						indio_dev);
		if (ret)
			return ret;
	}

	ret = devm_iio_device_register(indio_dev->dev.parent, indio_dev);
	if (ret)
		return ret;

	dev_info(&client->dev, "%s capacitive sensor registered,irq: %d\n",
		 id->name, client->irq);

	return 0;
}

