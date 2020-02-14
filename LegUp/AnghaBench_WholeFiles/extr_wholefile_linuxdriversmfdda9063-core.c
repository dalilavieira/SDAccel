#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct da9063_pdata {int irq_base; int (* init ) (struct da9063*) ;int /*<<< orphan*/  flags; } ;
struct da9063 {int irq_base; unsigned int chip_irq; int variant_code; scalar_t__ type; TYPE_1__* dev; int /*<<< orphan*/  regmap_irq; int /*<<< orphan*/  regmap; int /*<<< orphan*/  flags; } ;
struct TYPE_5__ {struct da9063_pdata* platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int DA9063_CHIP_VARIANT_SHIFT ; 
 int DA9063_KEY_RESET ; 
 int DA9063_NSHUTDOWN ; 
 int DA9063_POR ; 
 int /*<<< orphan*/  DA9063_REG_CHIP_ID ; 
 int /*<<< orphan*/  DA9063_REG_CHIP_VARIANT ; 
 int /*<<< orphan*/  DA9063_REG_FAULT_LOG ; 
 int DA9063_TEMP_CRIT ; 
 int DA9063_TWD_ERROR ; 
 int DA9063_VDD_FAULT ; 
 int DA9063_VDD_START ; 
 int DA9063_WAIT_SHUT ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  PLATFORM_DEVID_NONE ; 
 int PMIC_CHIP_ID_DA9063 ; 
 int PMIC_DA9063_AD ; 
 int PMIC_DA9063_BB ; 
 scalar_t__ PMIC_TYPE_DA9063 ; 
 int /*<<< orphan*/  da9063_common_devs ; 
 int /*<<< orphan*/  da9063_devs ; 
 int da9063_irq_init (struct da9063*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,int,int) ; 
 int devm_mfd_add_devices (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int regmap_irq_chip_get_base (int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int stub1 (struct da9063*) ; 

__attribute__((used)) static int da9063_clear_fault_log(struct da9063 *da9063)
{
	int ret = 0;
	int fault_log = 0;

	ret = regmap_read(da9063->regmap, DA9063_REG_FAULT_LOG, &fault_log);
	if (ret < 0) {
		dev_err(da9063->dev, "Cannot read FAULT_LOG.\n");
		return -EIO;
	}

	if (fault_log) {
		if (fault_log & DA9063_TWD_ERROR)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_TWD_ERROR\n");
		if (fault_log & DA9063_POR)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_POR\n");
		if (fault_log & DA9063_VDD_FAULT)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_VDD_FAULT\n");
		if (fault_log & DA9063_VDD_START)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_VDD_START\n");
		if (fault_log & DA9063_TEMP_CRIT)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_TEMP_CRIT\n");
		if (fault_log & DA9063_KEY_RESET)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_KEY_RESET\n");
		if (fault_log & DA9063_NSHUTDOWN)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_NSHUTDOWN\n");
		if (fault_log & DA9063_WAIT_SHUT)
			dev_dbg(da9063->dev,
				"Fault log entry detected: DA9063_WAIT_SHUT\n");
	}

	ret = regmap_write(da9063->regmap,
			   DA9063_REG_FAULT_LOG,
			   fault_log);
	if (ret < 0)
		dev_err(da9063->dev,
			"Cannot reset FAULT_LOG values %d\n", ret);

	return ret;
}

int da9063_device_init(struct da9063 *da9063, unsigned int irq)
{
	struct da9063_pdata *pdata = da9063->dev->platform_data;
	int model, variant_id, variant_code;
	int ret;

	ret = da9063_clear_fault_log(da9063);
	if (ret < 0)
		dev_err(da9063->dev, "Cannot clear fault log\n");

	if (pdata) {
		da9063->flags = pdata->flags;
		da9063->irq_base = pdata->irq_base;
	} else {
		da9063->flags = 0;
		da9063->irq_base = -1;
	}
	da9063->chip_irq = irq;

	if (pdata && pdata->init != NULL) {
		ret = pdata->init(da9063);
		if (ret != 0) {
			dev_err(da9063->dev,
				"Platform initialization failed.\n");
			return ret;
		}
	}

	ret = regmap_read(da9063->regmap, DA9063_REG_CHIP_ID, &model);
	if (ret < 0) {
		dev_err(da9063->dev, "Cannot read chip model id.\n");
		return -EIO;
	}
	if (model != PMIC_CHIP_ID_DA9063) {
		dev_err(da9063->dev, "Invalid chip model id: 0x%02x\n", model);
		return -ENODEV;
	}

	ret = regmap_read(da9063->regmap, DA9063_REG_CHIP_VARIANT, &variant_id);
	if (ret < 0) {
		dev_err(da9063->dev, "Cannot read chip variant id.\n");
		return -EIO;
	}

	variant_code = variant_id >> DA9063_CHIP_VARIANT_SHIFT;

	dev_info(da9063->dev,
		 "Device detected (chip-ID: 0x%02X, var-ID: 0x%02X)\n",
		 model, variant_id);

	if (variant_code < PMIC_DA9063_BB && variant_code != PMIC_DA9063_AD) {
		dev_err(da9063->dev,
			"Cannot support variant code: 0x%02X\n", variant_code);
		return -ENODEV;
	}

	da9063->variant_code = variant_code;

	ret = da9063_irq_init(da9063);
	if (ret) {
		dev_err(da9063->dev, "Cannot initialize interrupts.\n");
		return ret;
	}

	da9063->irq_base = regmap_irq_chip_get_base(da9063->regmap_irq);

	ret = devm_mfd_add_devices(da9063->dev, PLATFORM_DEVID_NONE,
				   da9063_common_devs,
				   ARRAY_SIZE(da9063_common_devs),
				   NULL, da9063->irq_base, NULL);
	if (ret) {
		dev_err(da9063->dev, "Failed to add child devices\n");
		return ret;
	}

	if (da9063->type == PMIC_TYPE_DA9063) {
		ret = devm_mfd_add_devices(da9063->dev, PLATFORM_DEVID_NONE,
					   da9063_devs, ARRAY_SIZE(da9063_devs),
					   NULL, da9063->irq_base, NULL);
		if (ret) {
			dev_err(da9063->dev, "Failed to add child devices\n");
			return ret;
		}
	}

	return ret;
}

