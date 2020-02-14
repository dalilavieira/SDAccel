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
typedef  int /*<<< orphan*/  tmp ;
struct TYPE_6__ {int /*<<< orphan*/  platform_data; } ;
struct spi_device {int bits_per_word; TYPE_1__ dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  mode; } ;
struct lis3lv02d {int (* read ) (struct lis3lv02d*,int /*<<< orphan*/ ,int*) ;int (* write ) (struct lis3lv02d*,int /*<<< orphan*/ ,int) ;struct spi_device* bus_priv; } ;
struct TYPE_7__ {int (* init ) (struct lis3lv02d*) ;int (* read ) (struct lis3lv02d*,int,int*) ;int (* write ) (struct lis3lv02d*,int,int) ;int /*<<< orphan*/  pdata; int /*<<< orphan*/  ac; int /*<<< orphan*/  irq; struct spi_device* bus_priv; } ;

/* Variables and functions */
 int CTRL1_PD0 ; 
 int CTRL1_Xen ; 
 int CTRL1_Yen ; 
 int CTRL1_Zen ; 
 int /*<<< orphan*/  CTRL_REG1 ; 
 int EINVAL ; 
 int LIS3_SPI_READ ; 
 int /*<<< orphan*/  SPI_MODE_0 ; 
 TYPE_2__ lis3_dev ; 
 int /*<<< orphan*/  lis3lv02d_axis_normal ; 
 int lis3lv02d_init_device (TYPE_2__*) ; 
 int /*<<< orphan*/  lis3lv02d_joystick_disable (struct lis3lv02d*) ; 
 int /*<<< orphan*/  lis3lv02d_poweroff (struct lis3lv02d*) ; 
 int lis3lv02d_remove_fs (TYPE_2__*) ; 
 struct lis3lv02d* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,TYPE_2__*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_w8r8 (struct spi_device*,int) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int stub1 (struct lis3lv02d*,int /*<<< orphan*/ ,int*) ; 
 int stub2 (struct lis3lv02d*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int lis3_spi_read(struct lis3lv02d *lis3, int reg, u8 *v)
{
	struct spi_device *spi = lis3->bus_priv;
	int ret = spi_w8r8(spi, reg | LIS3_SPI_READ);
	if (ret < 0)
		return -EINVAL;

	*v = (u8) ret;
	return 0;
}

__attribute__((used)) static int lis3_spi_write(struct lis3lv02d *lis3, int reg, u8 val)
{
	u8 tmp[2] = { reg, val };
	struct spi_device *spi = lis3->bus_priv;
	return spi_write(spi, tmp, sizeof(tmp));
}

__attribute__((used)) static int lis3_spi_init(struct lis3lv02d *lis3)
{
	u8 reg;
	int ret;

	/* power up the device */
	ret = lis3->read(lis3, CTRL_REG1, &reg);
	if (ret < 0)
		return ret;

	reg |= CTRL1_PD0 | CTRL1_Xen | CTRL1_Yen | CTRL1_Zen;
	return lis3->write(lis3, CTRL_REG1, reg);
}

__attribute__((used)) static int lis302dl_spi_probe(struct spi_device *spi)
{
	int ret;

	spi->bits_per_word = 8;
	spi->mode = SPI_MODE_0;
	ret = spi_setup(spi);
	if (ret < 0)
		return ret;

	lis3_dev.bus_priv	= spi;
	lis3_dev.init		= lis3_spi_init;
	lis3_dev.read		= lis3_spi_read;
	lis3_dev.write		= lis3_spi_write;
	lis3_dev.irq		= spi->irq;
	lis3_dev.ac		= lis3lv02d_axis_normal;
	lis3_dev.pdata		= spi->dev.platform_data;

#ifdef CONFIG_OF
	if (of_match_device(lis302dl_spi_dt_ids, &spi->dev)) {
		lis3_dev.of_node = spi->dev.of_node;
		ret = lis3lv02d_init_dt(&lis3_dev);
		if (ret)
			return ret;
	}
#endif
	spi_set_drvdata(spi, &lis3_dev);

	return lis3lv02d_init_device(&lis3_dev);
}

__attribute__((used)) static int lis302dl_spi_remove(struct spi_device *spi)
{
	struct lis3lv02d *lis3 = spi_get_drvdata(spi);
	lis3lv02d_joystick_disable(lis3);
	lis3lv02d_poweroff(lis3);

	return lis3lv02d_remove_fs(&lis3_dev);
}

