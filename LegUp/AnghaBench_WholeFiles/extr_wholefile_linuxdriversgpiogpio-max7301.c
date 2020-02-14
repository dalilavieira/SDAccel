#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  word ;
typedef  int u16 ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; } ;
struct max7301 {int (* read ) (struct device*,unsigned int) ;int (* write ) (struct device*,unsigned int,unsigned int) ;int /*<<< orphan*/ * dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int __max730x_probe (struct max7301*) ; 
 int __max730x_remove (int /*<<< orphan*/ *) ; 
 struct max7301* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_write_then_read (struct spi_device*,int*,int,int*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int max7301_spi_write(struct device *dev, unsigned int reg,
				unsigned int val)
{
	struct spi_device *spi = to_spi_device(dev);
	u16 word = ((reg & 0x7F) << 8) | (val & 0xFF);

	return spi_write_then_read(spi, &word, sizeof(word), NULL, 0);
}

__attribute__((used)) static int max7301_spi_read(struct device *dev, unsigned int reg)
{
	int ret;
	u16 word;
	struct spi_device *spi = to_spi_device(dev);

	word = 0x8000 | (reg << 8);
	ret = spi_write_then_read(spi, &word, sizeof(word), &word,
				  sizeof(word));
	if (ret)
		return ret;
	return word & 0xff;
}

__attribute__((used)) static int max7301_probe(struct spi_device *spi)
{
	struct max7301 *ts;
	int ret;

	/* bits_per_word cannot be configured in platform data */
	spi->bits_per_word = 16;
	ret = spi_setup(spi);
	if (ret < 0)
		return ret;

	ts = devm_kzalloc(&spi->dev, sizeof(struct max7301), GFP_KERNEL);
	if (!ts)
		return -ENOMEM;

	ts->read = max7301_spi_read;
	ts->write = max7301_spi_write;
	ts->dev = &spi->dev;

	ret = __max730x_probe(ts);
	return ret;
}

__attribute__((used)) static int max7301_remove(struct spi_device *spi)
{
	return __max730x_remove(&spi->dev);
}

