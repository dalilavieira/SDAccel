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
struct spi_device {int bits_per_word; int /*<<< orphan*/  dev; int /*<<< orphan*/  mode; } ;
struct device {int dummy; } ;
struct altr_a10sr {int /*<<< orphan*/ * dev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
#define  ALTR_A10SR_FMCAB_REG 143 
#define  ALTR_A10SR_HPS_RST_REG 142 
#define  ALTR_A10SR_I2C_M_REG 141 
#define  ALTR_A10SR_LED_REG 140 
#define  ALTR_A10SR_PBDSW_IRQ_REG 139 
#define  ALTR_A10SR_PBDSW_REG 138 
#define  ALTR_A10SR_PMBUS_REG 137 
#define  ALTR_A10SR_PWR_GOOD1_REG 136 
#define  ALTR_A10SR_PWR_GOOD2_REG 135 
#define  ALTR_A10SR_PWR_GOOD3_REG 134 
#define  ALTR_A10SR_SFPA_REG 133 
#define  ALTR_A10SR_SFPB_REG 132 
#define  ALTR_A10SR_USB_QSPI_REG 131 
#define  ALTR_A10SR_VERSION_READ 130 
#define  ALTR_A10SR_WARM_RST_REG 129 
#define  ALTR_A10SR_WR_KEY_REG 128 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  altr_a10sr_regmap_config ; 
 int /*<<< orphan*/  altr_a10sr_subdev_info ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct altr_a10sr* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regmap_init_spi (struct spi_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct altr_a10sr*) ; 
 int /*<<< orphan*/  spi_setup (struct spi_device*) ; 

__attribute__((used)) static bool altr_a10sr_reg_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ALTR_A10SR_VERSION_READ:
	case ALTR_A10SR_LED_REG:
	case ALTR_A10SR_PBDSW_REG:
	case ALTR_A10SR_PBDSW_IRQ_REG:
	case ALTR_A10SR_PWR_GOOD1_REG:
	case ALTR_A10SR_PWR_GOOD2_REG:
	case ALTR_A10SR_PWR_GOOD3_REG:
	case ALTR_A10SR_FMCAB_REG:
	case ALTR_A10SR_HPS_RST_REG:
	case ALTR_A10SR_USB_QSPI_REG:
	case ALTR_A10SR_SFPA_REG:
	case ALTR_A10SR_SFPB_REG:
	case ALTR_A10SR_I2C_M_REG:
	case ALTR_A10SR_WARM_RST_REG:
	case ALTR_A10SR_WR_KEY_REG:
	case ALTR_A10SR_PMBUS_REG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool altr_a10sr_reg_writeable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ALTR_A10SR_LED_REG:
	case ALTR_A10SR_PBDSW_IRQ_REG:
	case ALTR_A10SR_FMCAB_REG:
	case ALTR_A10SR_HPS_RST_REG:
	case ALTR_A10SR_USB_QSPI_REG:
	case ALTR_A10SR_SFPA_REG:
	case ALTR_A10SR_SFPB_REG:
	case ALTR_A10SR_WARM_RST_REG:
	case ALTR_A10SR_WR_KEY_REG:
	case ALTR_A10SR_PMBUS_REG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool altr_a10sr_reg_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ALTR_A10SR_PBDSW_REG:
	case ALTR_A10SR_PBDSW_IRQ_REG:
	case ALTR_A10SR_PWR_GOOD1_REG:
	case ALTR_A10SR_PWR_GOOD2_REG:
	case ALTR_A10SR_PWR_GOOD3_REG:
	case ALTR_A10SR_HPS_RST_REG:
	case ALTR_A10SR_I2C_M_REG:
	case ALTR_A10SR_WARM_RST_REG:
	case ALTR_A10SR_WR_KEY_REG:
	case ALTR_A10SR_PMBUS_REG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int altr_a10sr_spi_probe(struct spi_device *spi)
{
	int ret;
	struct altr_a10sr *a10sr;

	a10sr = devm_kzalloc(&spi->dev, sizeof(*a10sr),
			     GFP_KERNEL);
	if (!a10sr)
		return -ENOMEM;

	spi->mode = SPI_MODE_3;
	spi->bits_per_word = 8;
	spi_setup(spi);

	a10sr->dev = &spi->dev;

	spi_set_drvdata(spi, a10sr);

	a10sr->regmap = devm_regmap_init_spi(spi, &altr_a10sr_regmap_config);
	if (IS_ERR(a10sr->regmap)) {
		ret = PTR_ERR(a10sr->regmap);
		dev_err(&spi->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	ret = devm_mfd_add_devices(a10sr->dev, PLATFORM_DEVID_AUTO,
				   altr_a10sr_subdev_info,
				   ARRAY_SIZE(altr_a10sr_subdev_info),
				   NULL, 0, NULL);
	if (ret)
		dev_err(a10sr->dev, "Failed to register sub-devices: %d\n",
			ret);

	return ret;
}

