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
typedef  int u64 ;
struct regmap {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct intel_soc_pmic {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_HANDLE (int /*<<< orphan*/ ) ; 
 int EIO ; 
 int /*<<< orphan*/  acpi_walk_dep_device_list (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  chtdc_ti_pmic_opregion_data ; 
 struct intel_soc_pmic* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int intel_pmic_install_opregion_handler (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ regmap_bulk_read (struct regmap*,int,int*,int) ; 
 scalar_t__ regmap_read (struct regmap*,int,int*) ; 
 int regmap_update_bits (struct regmap*,int,int,int) ; 

__attribute__((used)) static int chtdc_ti_pmic_get_power(struct regmap *regmap, int reg, int bit,
				   u64 *value)
{
	int data;

	if (regmap_read(regmap, reg, &data))
		return -EIO;

	*value = data & 1;
	return 0;
}

__attribute__((used)) static int chtdc_ti_pmic_update_power(struct regmap *regmap, int reg, int bit,
				      bool on)
{
	return regmap_update_bits(regmap, reg, 1, on);
}

__attribute__((used)) static int chtdc_ti_pmic_get_raw_temp(struct regmap *regmap, int reg)
{
	u8 buf[2];

	if (regmap_bulk_read(regmap, reg, buf, 2))
		return -EIO;

	/* stored in big-endian */
	return ((buf[0] & 0x03) << 8) | buf[1];
}

__attribute__((used)) static int chtdc_ti_pmic_opregion_probe(struct platform_device *pdev)
{
	struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
	int err;

	err = intel_pmic_install_opregion_handler(&pdev->dev,
			ACPI_HANDLE(pdev->dev.parent), pmic->regmap,
			&chtdc_ti_pmic_opregion_data);
	if (err < 0)
		return err;

	/* Re-enumerate devices depending on PMIC */
	acpi_walk_dep_device_list(ACPI_HANDLE(pdev->dev.parent));
	return 0;
}

