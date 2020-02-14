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
struct spi_device_id {unsigned long driver_data; } ;
struct spi_device {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct regmap_config {int dummy; } ;
struct madera {unsigned long type; char const* type_name; int /*<<< orphan*/  irq; int /*<<< orphan*/ * dev; void* regmap_32bit; void* regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_MFD_CS47L35 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L85 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L90 ; 
#define  CS47L35 132 
#define  CS47L85 131 
#define  CS47L90 130 
#define  CS47L91 129 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
#define  WM1840 128 
 struct regmap_config cs47l35_16bit_spi_regmap ; 
 struct regmap_config cs47l35_32bit_spi_regmap ; 
 struct regmap_config cs47l85_16bit_spi_regmap ; 
 struct regmap_config cs47l85_32bit_spi_regmap ; 
 struct regmap_config cs47l90_16bit_spi_regmap ; 
 struct regmap_config cs47l90_32bit_spi_regmap ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct madera* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_spi (struct spi_device*,struct regmap_config const*) ; 
 int /*<<< orphan*/  madera_dev_exit (struct madera*) ; 
 int madera_dev_init (struct madera*) ; 
 char* madera_name_from_type (unsigned long) ; 
 void* of_device_get_match_data (int /*<<< orphan*/ *) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct madera* spi_get_drvdata (struct spi_device*) ; 

__attribute__((used)) static int madera_spi_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct madera *madera;
	const struct regmap_config *regmap_16bit_config = NULL;
	const struct regmap_config *regmap_32bit_config = NULL;
	const void *of_data;
	unsigned long type;
	const char *name;
	int ret;

	of_data = of_device_get_match_data(&spi->dev);
	if (of_data)
		type = (unsigned long)of_data;
	else
		type = id->driver_data;

	switch (type) {
	case CS47L35:
		if (IS_ENABLED(CONFIG_MFD_CS47L35)) {
			regmap_16bit_config = &cs47l35_16bit_spi_regmap;
			regmap_32bit_config = &cs47l35_32bit_spi_regmap;
		}
		break;
	case CS47L85:
	case WM1840:
		if (IS_ENABLED(CONFIG_MFD_CS47L85)) {
			regmap_16bit_config = &cs47l85_16bit_spi_regmap;
			regmap_32bit_config = &cs47l85_32bit_spi_regmap;
		}
		break;
	case CS47L90:
	case CS47L91:
		if (IS_ENABLED(CONFIG_MFD_CS47L90)) {
			regmap_16bit_config = &cs47l90_16bit_spi_regmap;
			regmap_32bit_config = &cs47l90_32bit_spi_regmap;
		}
		break;
	default:
		dev_err(&spi->dev,
			"Unknown Madera SPI device type %ld\n", type);
		return -EINVAL;
	}

	name = madera_name_from_type(type);

	if (!regmap_16bit_config) {
		/* it's polite to say which codec isn't built into the kernel */
		dev_err(&spi->dev,
			"Kernel does not include support for %s\n", name);
		return -EINVAL;
	}

	madera = devm_kzalloc(&spi->dev, sizeof(*madera), GFP_KERNEL);
	if (!madera)
		return -ENOMEM;

	madera->regmap = devm_regmap_init_spi(spi, regmap_16bit_config);
	if (IS_ERR(madera->regmap)) {
		ret = PTR_ERR(madera->regmap);
		dev_err(&spi->dev,
			"Failed to allocate 16-bit register map: %d\n",	ret);
		return ret;
	}

	madera->regmap_32bit = devm_regmap_init_spi(spi, regmap_32bit_config);
	if (IS_ERR(madera->regmap_32bit)) {
		ret = PTR_ERR(madera->regmap_32bit);
		dev_err(&spi->dev,
			"Failed to allocate 32-bit register map: %d\n",	ret);
		return ret;
	}

	madera->type = type;
	madera->type_name = name;
	madera->dev = &spi->dev;
	madera->irq = spi->irq;

	return madera_dev_init(madera);
}

__attribute__((used)) static int madera_spi_remove(struct spi_device *spi)
{
	struct madera *madera = spi_get_drvdata(spi);

	madera_dev_exit(madera);

	return 0;
}

