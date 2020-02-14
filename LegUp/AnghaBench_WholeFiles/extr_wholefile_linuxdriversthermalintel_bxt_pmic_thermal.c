#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct thermal_zone_device {int dummy; } ;
struct regmap_irq_chip_data {int dummy; } ;
struct regmap {int dummy; } ;
struct pmic_thermal_data {int num_maps; TYPE_2__* maps; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; } ;
struct intel_soc_pmic {struct regmap_irq_chip_data* irq_chip_data; struct regmap* regmap; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {scalar_t__ driver_data; } ;
struct TYPE_5__ {int num_trips; TYPE_1__* trip_config; int /*<<< orphan*/  handle; } ;
struct TYPE_4__ {int irq_mask; int irq_en_mask; int /*<<< orphan*/  irq_en; int /*<<< orphan*/  evt_stat; int /*<<< orphan*/  irq_reg; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IS_ERR (struct thermal_zone_device*) ; 
 int /*<<< orphan*/  THERMAL_EVENT_UNSPECIFIED ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct intel_soc_pmic* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct platform_device*) ; 
 TYPE_3__* platform_get_device_id (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int) ; 
 int regmap_irq_get_virq (struct regmap_irq_chip_data*,int) ; 
 scalar_t__ regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  thermal_zone_device_update (struct thermal_zone_device*,int /*<<< orphan*/ ) ; 
 struct thermal_zone_device* thermal_zone_get_zone_by_name (int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t pmic_thermal_irq_handler(int irq, void *data)
{
	struct platform_device *pdev = data;
	struct thermal_zone_device *tzd;
	struct pmic_thermal_data *td;
	struct intel_soc_pmic *pmic;
	struct regmap *regmap;
	u8 reg_val, mask, irq_stat;
	u16 reg, evt_stat_reg;
	int i, j, ret;

	pmic = dev_get_drvdata(pdev->dev.parent);
	regmap = pmic->regmap;
	td = (struct pmic_thermal_data *)
		platform_get_device_id(pdev)->driver_data;

	/* Resolve thermal irqs */
	for (i = 0; i < td->num_maps; i++) {
		for (j = 0; j < td->maps[i].num_trips; j++) {
			reg = td->maps[i].trip_config[j].irq_reg;
			mask = td->maps[i].trip_config[j].irq_mask;
			/*
			 * Read the irq register to resolve whether the
			 * interrupt was triggered for this sensor
			 */
			if (regmap_read(regmap, reg, &ret))
				return IRQ_HANDLED;

			reg_val = (u8)ret;
			irq_stat = ((u8)ret & mask);

			if (!irq_stat)
				continue;

			/*
			 * Read the status register to find out what
			 * event occurred i.e a high or a low
			 */
			evt_stat_reg = td->maps[i].trip_config[j].evt_stat;
			if (regmap_read(regmap, evt_stat_reg, &ret))
				return IRQ_HANDLED;

			tzd = thermal_zone_get_zone_by_name(td->maps[i].handle);
			if (!IS_ERR(tzd))
				thermal_zone_device_update(tzd,
						THERMAL_EVENT_UNSPECIFIED);

			/* Clear the appropriate irq */
			regmap_write(regmap, reg, reg_val & mask);
		}
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int pmic_thermal_probe(struct platform_device *pdev)
{
	struct regmap_irq_chip_data *regmap_irq_chip;
	struct pmic_thermal_data *thermal_data;
	int ret, irq, virq, i, j, pmic_irq_count;
	struct intel_soc_pmic *pmic;
	struct regmap *regmap;
	struct device *dev;
	u16 reg;
	u8 mask;

	dev = &pdev->dev;
	pmic = dev_get_drvdata(pdev->dev.parent);
	if (!pmic) {
		dev_err(dev, "Failed to get struct intel_soc_pmic pointer\n");
		return -ENODEV;
	}

	thermal_data = (struct pmic_thermal_data *)
				platform_get_device_id(pdev)->driver_data;
	if (!thermal_data) {
		dev_err(dev, "No thermal data initialized!!\n");
		return -ENODEV;
	}

	regmap = pmic->regmap;
	regmap_irq_chip = pmic->irq_chip_data;

	pmic_irq_count = 0;
	while ((irq = platform_get_irq(pdev, pmic_irq_count)) != -ENXIO) {
		virq = regmap_irq_get_virq(regmap_irq_chip, irq);
		if (virq < 0) {
			dev_err(dev, "failed to get virq by irq %d\n", irq);
			return virq;
		}

		ret = devm_request_threaded_irq(&pdev->dev, virq,
				NULL, pmic_thermal_irq_handler,
				IRQF_ONESHOT, "pmic_thermal", pdev);

		if (ret) {
			dev_err(dev, "request irq(%d) failed: %d\n", virq, ret);
			return ret;
		}
		pmic_irq_count++;
	}

	/* Enable thermal interrupts */
	for (i = 0; i < thermal_data->num_maps; i++) {
		for (j = 0; j < thermal_data->maps[i].num_trips; j++) {
			reg = thermal_data->maps[i].trip_config[j].irq_en;
			mask = thermal_data->maps[i].trip_config[j].irq_en_mask;
			ret = regmap_update_bits(regmap, reg, mask, 0x00);
			if (ret)
				return ret;
		}
	}

	return 0;
}

