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
struct st_thermal_sensor {int irq; struct regmap* regmap; struct regmap* mmio_base; struct device* dev; struct regmap* int_enable; TYPE_1__* cdata; struct regmap* int_thresh_hi; int /*<<< orphan*/  thermal_dev; } ;
struct resource {int dummy; } ;
struct regmap {int dummy; } ;
struct reg_field {int dummy; } ;
struct platform_device {int dummy; } ;
struct device {TYPE_2__* driver; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum st_thermal_power_state { ____Placeholder_st_thermal_power_state } st_thermal_power_state ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;
struct TYPE_3__ {int crit_temp; int temp_adjust_val; struct reg_field* reg_fields; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 size_t INT_ENABLE ; 
 size_t INT_THRESH_HI ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  STIH416_MPE_CONF ; 
 int /*<<< orphan*/  THERMAL_EVENT_UNSPECIFIED ; 
 unsigned int THERMAL_PDN ; 
 unsigned int THERMAL_SRSTN ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct regmap* devm_ioremap_resource (struct device*,struct resource*) ; 
 void* devm_regmap_field_alloc (struct device*,struct regmap*,struct reg_field const) ; 
 struct regmap* devm_regmap_init_mmio (struct device*,struct regmap*,int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct st_thermal_sensor*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_field_write (struct regmap*,int) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int const,unsigned int const) ; 
 int /*<<< orphan*/  st_416mpe_regmap_config ; 
 int /*<<< orphan*/  st_mmap_thermal_of_match ; 
 int st_thermal_register (struct platform_device*,int /*<<< orphan*/ ) ; 
 int st_thermal_unregister (struct platform_device*) ; 
 int /*<<< orphan*/  thermal_zone_device_update (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct platform_device* to_platform_device (struct device*) ; 

__attribute__((used)) static irqreturn_t st_mmap_thermal_trip_handler(int irq, void *sdata)
{
	struct st_thermal_sensor *sensor = sdata;

	thermal_zone_device_update(sensor->thermal_dev,
				   THERMAL_EVENT_UNSPECIFIED);

	return IRQ_HANDLED;
}

__attribute__((used)) static int st_mmap_power_ctrl(struct st_thermal_sensor *sensor,
			      enum st_thermal_power_state power_state)
{
	const unsigned int mask = (THERMAL_PDN | THERMAL_SRSTN);
	const unsigned int val = power_state ? mask : 0;

	return regmap_update_bits(sensor->regmap, STIH416_MPE_CONF, mask, val);
}

__attribute__((used)) static int st_mmap_alloc_regfields(struct st_thermal_sensor *sensor)
{
	struct device *dev = sensor->dev;
	struct regmap *regmap = sensor->regmap;
	const struct reg_field *reg_fields = sensor->cdata->reg_fields;

	sensor->int_thresh_hi = devm_regmap_field_alloc(dev, regmap,
						reg_fields[INT_THRESH_HI]);
	sensor->int_enable = devm_regmap_field_alloc(dev, regmap,
						reg_fields[INT_ENABLE]);

	if (IS_ERR(sensor->int_thresh_hi) || IS_ERR(sensor->int_enable)) {
		dev_err(dev, "failed to alloc mmap regfields\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int st_mmap_enable_irq(struct st_thermal_sensor *sensor)
{
	int ret;

	/* Set upper critical threshold */
	ret = regmap_field_write(sensor->int_thresh_hi,
				 sensor->cdata->crit_temp -
				 sensor->cdata->temp_adjust_val);
	if (ret)
		return ret;

	return regmap_field_write(sensor->int_enable, 1);
}

__attribute__((used)) static int st_mmap_register_enable_irq(struct st_thermal_sensor *sensor)
{
	struct device *dev = sensor->dev;
	struct platform_device *pdev = to_platform_device(dev);
	int ret;

	sensor->irq = platform_get_irq(pdev, 0);
	if (sensor->irq < 0) {
		dev_err(dev, "failed to register IRQ\n");
		return sensor->irq;
	}

	ret = devm_request_threaded_irq(dev, sensor->irq,
					NULL, st_mmap_thermal_trip_handler,
					IRQF_TRIGGER_RISING | IRQF_ONESHOT,
					dev->driver->name, sensor);
	if (ret) {
		dev_err(dev, "failed to register IRQ %d\n", sensor->irq);
		return ret;
	}

	return st_mmap_enable_irq(sensor);
}

__attribute__((used)) static int st_mmap_regmap_init(struct st_thermal_sensor *sensor)
{
	struct device *dev = sensor->dev;
	struct platform_device *pdev = to_platform_device(dev);
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(dev, "no memory resources defined\n");
		return -ENODEV;
	}

	sensor->mmio_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(sensor->mmio_base)) {
		dev_err(dev, "failed to remap IO\n");
		return PTR_ERR(sensor->mmio_base);
	}

	sensor->regmap = devm_regmap_init_mmio(dev, sensor->mmio_base,
				&st_416mpe_regmap_config);
	if (IS_ERR(sensor->regmap)) {
		dev_err(dev, "failed to initialise regmap\n");
		return PTR_ERR(sensor->regmap);
	}

	return 0;
}

__attribute__((used)) static int st_mmap_probe(struct platform_device *pdev)
{
	return st_thermal_register(pdev,  st_mmap_thermal_of_match);
}

__attribute__((used)) static int st_mmap_remove(struct platform_device *pdev)
{
	return st_thermal_unregister(pdev);
}

