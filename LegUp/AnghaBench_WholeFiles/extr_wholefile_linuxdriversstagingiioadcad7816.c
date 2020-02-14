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
struct device {int dummy; } ;
struct spi_device {struct device dev; scalar_t__ irq; } ;
struct TYPE_3__ {struct device* parent; } ;
struct iio_dev {char const* name; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct ad7816_chip_info {unsigned short rdwr_pin; int channel_id; scalar_t__ mode; unsigned short convert_pin; unsigned short busy_pin; long* oti_data; struct spi_device* spi_dev; } ;
typedef  size_t ssize_t ;
typedef  scalar_t__ s8 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  data ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_4__ {char const* name; } ;

/* Variables and functions */
 long AD7816_BOUND_VALUE_BASE ; 
 long AD7816_BOUND_VALUE_MAX ; 
 long AD7816_BOUND_VALUE_MIN ; 
 unsigned long AD7816_CS_MASK ; 
 unsigned long AD7816_CS_MAX ; 
 scalar_t__ AD7816_FULL ; 
 scalar_t__ AD7816_PD ; 
 int AD7816_TEMP_FLOAT_MASK ; 
 int AD7816_TEMP_FLOAT_OFFSET ; 
 int AD7816_VALUE_OFFSET ; 
 size_t EINVAL ; 
 size_t EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IIO_EVENT_CODE_AD7816_OTI ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  ad7816_info ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 unsigned short* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,char const*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 int devm_gpio_request (struct device*,unsigned short,char const*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 int devm_request_threaded_irq (struct device*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char const*,struct iio_dev*) ; 
 int /*<<< orphan*/  gpio_direction_input (unsigned long) ; 
 scalar_t__ gpio_get_value (unsigned short) ; 
 int /*<<< orphan*/  gpio_set_value (unsigned short,int) ; 
 int /*<<< orphan*/  iio_get_time_ns (void*) ; 
 struct ad7816_chip_info* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 TYPE_2__* spi_get_device_id (struct spi_device*) ; 
 int spi_read (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 size_t sprintf (char*,char*,...) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int ad7816_spi_read(struct ad7816_chip_info *chip, u16 *data)
{
	struct spi_device *spi_dev = chip->spi_dev;
	int ret = 0;
	__be16 buf;

	gpio_set_value(chip->rdwr_pin, 1);
	gpio_set_value(chip->rdwr_pin, 0);
	ret = spi_write(spi_dev, &chip->channel_id, sizeof(chip->channel_id));
	if (ret < 0) {
		dev_err(&spi_dev->dev, "SPI channel setting error\n");
		return ret;
	}
	gpio_set_value(chip->rdwr_pin, 1);

	if (chip->mode == AD7816_PD) { /* operating mode 2 */
		gpio_set_value(chip->convert_pin, 1);
		gpio_set_value(chip->convert_pin, 0);
	} else { /* operating mode 1 */
		gpio_set_value(chip->convert_pin, 0);
		gpio_set_value(chip->convert_pin, 1);
	}

	while (gpio_get_value(chip->busy_pin))
		cpu_relax();

	gpio_set_value(chip->rdwr_pin, 0);
	gpio_set_value(chip->rdwr_pin, 1);
	ret = spi_read(spi_dev, &buf, sizeof(*data));
	if (ret < 0) {
		dev_err(&spi_dev->dev, "SPI data read error\n");
		return ret;
	}

	*data = be16_to_cpu(buf);

	return ret;
}

__attribute__((used)) static int ad7816_spi_write(struct ad7816_chip_info *chip, u8 data)
{
	struct spi_device *spi_dev = chip->spi_dev;
	int ret = 0;

	gpio_set_value(chip->rdwr_pin, 1);
	gpio_set_value(chip->rdwr_pin, 0);
	ret = spi_write(spi_dev, &data, sizeof(data));
	if (ret < 0)
		dev_err(&spi_dev->dev, "SPI oti data write error\n");

	return ret;
}

__attribute__((used)) static ssize_t ad7816_show_mode(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);

	if (chip->mode)
		return sprintf(buf, "power-save\n");
	return sprintf(buf, "full\n");
}

__attribute__((used)) static ssize_t ad7816_store_mode(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf,
				 size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);

	if (strcmp(buf, "full")) {
		gpio_set_value(chip->rdwr_pin, 1);
		chip->mode = AD7816_FULL;
	} else {
		gpio_set_value(chip->rdwr_pin, 0);
		chip->mode = AD7816_PD;
	}

	return len;
}

__attribute__((used)) static ssize_t ad7816_show_available_modes(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	return sprintf(buf, "full\npower-save\n");
}

__attribute__((used)) static ssize_t ad7816_show_channel(struct device *dev,
				   struct device_attribute *attr,
				   char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", chip->channel_id);
}

__attribute__((used)) static ssize_t ad7816_store_channel(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf,
				    size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);
	unsigned long data;
	int ret;

	ret = kstrtoul(buf, 10, &data);
	if (ret)
		return ret;

	if (data > AD7816_CS_MAX && data != AD7816_CS_MASK) {
		dev_err(&chip->spi_dev->dev, "Invalid channel id %lu for %s.\n",
			data, indio_dev->name);
		return -EINVAL;
	} else if (strcmp(indio_dev->name, "ad7818") == 0 && data > 1) {
		dev_err(&chip->spi_dev->dev,
			"Invalid channel id %lu for ad7818.\n", data);
		return -EINVAL;
	} else if (strcmp(indio_dev->name, "ad7816") == 0 && data > 0) {
		dev_err(&chip->spi_dev->dev,
			"Invalid channel id %lu for ad7816.\n", data);
		return -EINVAL;
	}

	chip->channel_id = data;

	return len;
}

__attribute__((used)) static ssize_t ad7816_show_value(struct device *dev,
				 struct device_attribute *attr,
				 char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);
	u16 data;
	s8 value;
	int ret;

	ret = ad7816_spi_read(chip, &data);
	if (ret)
		return -EIO;

	data >>= AD7816_VALUE_OFFSET;

	if (chip->channel_id == 0) {
		value = (s8)((data >> AD7816_TEMP_FLOAT_OFFSET) - 103);
		data &= AD7816_TEMP_FLOAT_MASK;
		if (value < 0)
			data = (1 << AD7816_TEMP_FLOAT_OFFSET) - data;
		return sprintf(buf, "%d.%.2d\n", value, data * 25);
	}
	return sprintf(buf, "%u\n", data);
}

__attribute__((used)) static irqreturn_t ad7816_event_handler(int irq, void *private)
{
	iio_push_event(private, IIO_EVENT_CODE_AD7816_OTI,
		       iio_get_time_ns(private));
	return IRQ_HANDLED;
}

__attribute__((used)) static ssize_t ad7816_show_oti(struct device *dev,
			       struct device_attribute *attr,
			       char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);
	int value;

	if (chip->channel_id > AD7816_CS_MAX) {
		dev_err(dev, "Invalid oti channel id %d.\n", chip->channel_id);
		return -EINVAL;
	} else if (chip->channel_id == 0) {
		value = AD7816_BOUND_VALUE_MIN +
			(chip->oti_data[chip->channel_id] -
			AD7816_BOUND_VALUE_BASE);
		return sprintf(buf, "%d\n", value);
	}
	return sprintf(buf, "%u\n", chip->oti_data[chip->channel_id]);
}

__attribute__((used)) static inline ssize_t ad7816_set_oti(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf,
				     size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ad7816_chip_info *chip = iio_priv(indio_dev);
	long value;
	u8 data;
	int ret;

	ret = kstrtol(buf, 10, &value);
	if (ret)
		return ret;

	if (chip->channel_id > AD7816_CS_MAX) {
		dev_err(dev, "Invalid oti channel id %d.\n", chip->channel_id);
		return -EINVAL;
	} else if (chip->channel_id == 0) {
		if (value < AD7816_BOUND_VALUE_MIN ||
		    value > AD7816_BOUND_VALUE_MAX)
			return -EINVAL;

		data = (u8)(value - AD7816_BOUND_VALUE_MIN +
			AD7816_BOUND_VALUE_BASE);
	} else {
		if (value < AD7816_BOUND_VALUE_BASE || value > 255)
			return -EINVAL;

		data = (u8)value;
	}

	ret = ad7816_spi_write(chip, data);
	if (ret)
		return -EIO;

	chip->oti_data[chip->channel_id] = data;

	return len;
}

__attribute__((used)) static int ad7816_probe(struct spi_device *spi_dev)
{
	struct ad7816_chip_info *chip;
	struct iio_dev *indio_dev;
	unsigned short *pins = dev_get_platdata(&spi_dev->dev);
	int ret = 0;
	int i;

	if (!pins) {
		dev_err(&spi_dev->dev, "No necessary GPIO platform data.\n");
		return -EINVAL;
	}

	indio_dev = devm_iio_device_alloc(&spi_dev->dev, sizeof(*chip));
	if (!indio_dev)
		return -ENOMEM;
	chip = iio_priv(indio_dev);
	/* this is only used for device removal purposes */
	dev_set_drvdata(&spi_dev->dev, indio_dev);

	chip->spi_dev = spi_dev;
	for (i = 0; i <= AD7816_CS_MAX; i++)
		chip->oti_data[i] = 203;
	chip->rdwr_pin = pins[0];
	chip->convert_pin = pins[1];
	chip->busy_pin = pins[2];

	ret = devm_gpio_request(&spi_dev->dev, chip->rdwr_pin,
				spi_get_device_id(spi_dev)->name);
	if (ret) {
		dev_err(&spi_dev->dev, "Fail to request rdwr gpio PIN %d.\n",
			chip->rdwr_pin);
		return ret;
	}
	gpio_direction_input(chip->rdwr_pin);
	ret = devm_gpio_request(&spi_dev->dev, chip->convert_pin,
				spi_get_device_id(spi_dev)->name);
	if (ret) {
		dev_err(&spi_dev->dev, "Fail to request convert gpio PIN %d.\n",
			chip->convert_pin);
		return ret;
	}
	gpio_direction_input(chip->convert_pin);
	ret = devm_gpio_request(&spi_dev->dev, chip->busy_pin,
				spi_get_device_id(spi_dev)->name);
	if (ret) {
		dev_err(&spi_dev->dev, "Fail to request busy gpio PIN %d.\n",
			chip->busy_pin);
		return ret;
	}
	gpio_direction_input(chip->busy_pin);

	indio_dev->name = spi_get_device_id(spi_dev)->name;
	indio_dev->dev.parent = &spi_dev->dev;
	indio_dev->info = &ad7816_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (spi_dev->irq) {
		/* Only low trigger is supported in ad7816/7/8 */
		ret = devm_request_threaded_irq(&spi_dev->dev, spi_dev->irq,
						NULL,
						&ad7816_event_handler,
						IRQF_TRIGGER_LOW | IRQF_ONESHOT,
						indio_dev->name,
						indio_dev);
		if (ret)
			return ret;
	}

	ret = devm_iio_device_register(&spi_dev->dev, indio_dev);
	if (ret)
		return ret;

	dev_info(&spi_dev->dev, "%s temperature sensor and ADC registered.\n",
		 indio_dev->name);

	return 0;
}

