#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct spi_transfer {unsigned char* tx_buf; unsigned char* rx_buf; int len; } ;
struct spi_message {int dummy; } ;
struct spi_device_id {scalar_t__ driver_data; } ;
struct TYPE_9__ {scalar_t__ of_node; } ;
struct spi_device {int mode; int max_speed_hz; TYPE_1__ dev; int /*<<< orphan*/  irq; } ;
struct of_device_id {void* data; } ;
struct mc13xxx {void* variant; int /*<<< orphan*/  regmap; int /*<<< orphan*/  irq; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 char const MC13783_AUDIO_CODEC ; 
 char const MC13783_AUDIO_DAC ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int SPI_CS_HIGH ; 
 int SPI_MODE_0 ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_1__*,struct mc13xxx*) ; 
 struct mc13xxx* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init (TYPE_1__*,int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int mc13xxx_common_exit (TYPE_1__*) ; 
 int mc13xxx_common_init (TYPE_1__*) ; 
 int /*<<< orphan*/  mc13xxx_dt_ids ; 
 int /*<<< orphan*/  mc13xxx_regmap_spi_config ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  regmap_mc13xxx_bus ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int spi_write (struct spi_device*,void const*,size_t) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int mc13xxx_spi_read(void *context, const void *reg, size_t reg_size,
				void *val, size_t val_size)
{
	unsigned char w[4] = { *((unsigned char *) reg), 0, 0, 0};
	unsigned char r[4];
	unsigned char *p = val;
	struct device *dev = context;
	struct spi_device *spi = to_spi_device(dev);
	struct spi_transfer t = {
		.tx_buf = w,
		.rx_buf = r,
		.len = 4,
	};

	struct spi_message m;
	int ret;

	if (val_size != 3 || reg_size != 1)
		return -ENOTSUPP;

	spi_message_init(&m);
	spi_message_add_tail(&t, &m);
	ret = spi_sync(spi, &m);

	memcpy(p, &r[1], 3);

	return ret;
}

__attribute__((used)) static int mc13xxx_spi_write(void *context, const void *data, size_t count)
{
	struct device *dev = context;
	struct spi_device *spi = to_spi_device(dev);
	const char *reg = data;

	if (count != 4)
		return -ENOTSUPP;

	/* include errata fix for spi audio problems */
	if (*reg == MC13783_AUDIO_CODEC || *reg == MC13783_AUDIO_DAC)
		spi_write(spi, data, count);

	return spi_write(spi, data, count);
}

__attribute__((used)) static int mc13xxx_spi_probe(struct spi_device *spi)
{
	struct mc13xxx *mc13xxx;
	int ret;

	mc13xxx = devm_kzalloc(&spi->dev, sizeof(*mc13xxx), GFP_KERNEL);
	if (!mc13xxx)
		return -ENOMEM;

	dev_set_drvdata(&spi->dev, mc13xxx);

	spi->mode = SPI_MODE_0 | SPI_CS_HIGH;

	mc13xxx->irq = spi->irq;

	spi->max_speed_hz = spi->max_speed_hz ? : 26000000;
	ret = spi_setup(spi);
	if (ret)
		return ret;

	mc13xxx->regmap = devm_regmap_init(&spi->dev, &regmap_mc13xxx_bus,
					   &spi->dev,
					   &mc13xxx_regmap_spi_config);
	if (IS_ERR(mc13xxx->regmap)) {
		ret = PTR_ERR(mc13xxx->regmap);
		dev_err(&spi->dev, "Failed to initialize regmap: %d\n", ret);
		return ret;
	}

	if (spi->dev.of_node) {
		const struct of_device_id *of_id =
			of_match_device(mc13xxx_dt_ids, &spi->dev);

		mc13xxx->variant = of_id->data;
	} else {
		const struct spi_device_id *id_entry = spi_get_device_id(spi);

		mc13xxx->variant = (void *)id_entry->driver_data;
	}

	return mc13xxx_common_init(&spi->dev);
}

__attribute__((used)) static int mc13xxx_spi_remove(struct spi_device *spi)
{
	return mc13xxx_common_exit(&spi->dev);
}

