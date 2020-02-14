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
typedef  int u32 ;
struct snd_soc_component {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct pistachio_internal_dac {struct regmap* supply; struct regmap* regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int /*<<< orphan*/  PISTACHIO_INTERNAL_DAC_CTRL ; 
 int PISTACHIO_INTERNAL_DAC_CTRL_PWRDN_MASK ; 
 int PISTACHIO_INTERNAL_DAC_CTRL_PWR_SEL_MASK ; 
 int /*<<< orphan*/  PISTACHIO_INTERNAL_DAC_GTI_CTRL ; 
 int PISTACHIO_INTERNAL_DAC_GTI_CTRL_ADDR_MASK ; 
 int PISTACHIO_INTERNAL_DAC_GTI_CTRL_ADDR_SHIFT ; 
 int PISTACHIO_INTERNAL_DAC_GTI_CTRL_WDATA_MASK ; 
 int PISTACHIO_INTERNAL_DAC_GTI_CTRL_WDATA_SHIFT ; 
 int PISTACHIO_INTERNAL_DAC_GTI_CTRL_WE_MASK ; 
 int PISTACHIO_INTERNAL_DAC_PWR ; 
 int PISTACHIO_INTERNAL_DAC_PWR_MASK ; 
 int /*<<< orphan*/  PISTACHIO_INTERNAL_DAC_SRST ; 
 int PISTACHIO_INTERNAL_DAC_SRST_MASK ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct pistachio_internal_dac* dev_get_drvdata (struct device*) ; 
 struct pistachio_internal_dac* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regulator_get (struct device*,char*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pistachio_internal_dac_dais ; 
 int /*<<< orphan*/  pistachio_internal_dac_driver ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pistachio_internal_dac*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_idle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regulator_disable (struct regmap*) ; 
 int regulator_enable (struct regmap*) ; 
 int regulator_get_voltage (struct regmap*) ; 
 struct pistachio_internal_dac* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,struct regmap*) ; 
 struct regmap* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void pistachio_internal_dac_reg_writel(struct regmap *top_regs,
						u32 val, u32 reg)
{
	regmap_update_bits(top_regs, PISTACHIO_INTERNAL_DAC_GTI_CTRL,
			PISTACHIO_INTERNAL_DAC_GTI_CTRL_ADDR_MASK,
			reg << PISTACHIO_INTERNAL_DAC_GTI_CTRL_ADDR_SHIFT);

	regmap_update_bits(top_regs, PISTACHIO_INTERNAL_DAC_GTI_CTRL,
			PISTACHIO_INTERNAL_DAC_GTI_CTRL_WDATA_MASK,
			val << PISTACHIO_INTERNAL_DAC_GTI_CTRL_WDATA_SHIFT);

	regmap_update_bits(top_regs, PISTACHIO_INTERNAL_DAC_GTI_CTRL,
			PISTACHIO_INTERNAL_DAC_GTI_CTRL_WE_MASK,
			PISTACHIO_INTERNAL_DAC_GTI_CTRL_WE_MASK);

	regmap_update_bits(top_regs, PISTACHIO_INTERNAL_DAC_GTI_CTRL,
			PISTACHIO_INTERNAL_DAC_GTI_CTRL_WE_MASK, 0);
}

__attribute__((used)) static void pistachio_internal_dac_pwr_off(struct pistachio_internal_dac *dac)
{
	regmap_update_bits(dac->regmap, PISTACHIO_INTERNAL_DAC_CTRL,
		PISTACHIO_INTERNAL_DAC_CTRL_PWRDN_MASK,
		PISTACHIO_INTERNAL_DAC_CTRL_PWRDN_MASK);

	pistachio_internal_dac_reg_writel(dac->regmap, 0,
					PISTACHIO_INTERNAL_DAC_PWR);
}

__attribute__((used)) static void pistachio_internal_dac_pwr_on(struct pistachio_internal_dac *dac)
{
	regmap_update_bits(dac->regmap, PISTACHIO_INTERNAL_DAC_SRST,
			PISTACHIO_INTERNAL_DAC_SRST_MASK,
			PISTACHIO_INTERNAL_DAC_SRST_MASK);

	regmap_update_bits(dac->regmap, PISTACHIO_INTERNAL_DAC_SRST,
			PISTACHIO_INTERNAL_DAC_SRST_MASK, 0);

	pistachio_internal_dac_reg_writel(dac->regmap,
					PISTACHIO_INTERNAL_DAC_PWR_MASK,
					PISTACHIO_INTERNAL_DAC_PWR);

	regmap_update_bits(dac->regmap, PISTACHIO_INTERNAL_DAC_CTRL,
			PISTACHIO_INTERNAL_DAC_CTRL_PWRDN_MASK, 0);
}

__attribute__((used)) static int pistachio_internal_dac_codec_probe(struct snd_soc_component *component)
{
	struct pistachio_internal_dac *dac = snd_soc_component_get_drvdata(component);

	snd_soc_component_init_regmap(component, dac->regmap);

	return 0;
}

__attribute__((used)) static int pistachio_internal_dac_probe(struct platform_device *pdev)
{
	struct pistachio_internal_dac *dac;
	int ret, voltage;
	struct device *dev = &pdev->dev;
	u32 reg;

	dac = devm_kzalloc(dev, sizeof(*dac), GFP_KERNEL);

	if (!dac)
		return -ENOMEM;

	platform_set_drvdata(pdev, dac);

	dac->regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
							    "img,cr-top");
	if (IS_ERR(dac->regmap))
		return PTR_ERR(dac->regmap);

	dac->supply = devm_regulator_get(dev, "VDD");
	if (IS_ERR(dac->supply)) {
		ret = PTR_ERR(dac->supply);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "failed to acquire supply 'VDD-supply': %d\n", ret);
		return ret;
	}

	ret = regulator_enable(dac->supply);
	if (ret) {
		dev_err(dev, "failed to enable supply: %d\n", ret);
		return ret;
	}

	voltage = regulator_get_voltage(dac->supply);

	switch (voltage) {
	case 1800000:
		reg = 0;
		break;
	case 3300000:
		reg = PISTACHIO_INTERNAL_DAC_CTRL_PWR_SEL_MASK;
		break;
	default:
		dev_err(dev, "invalid voltage: %d\n", voltage);
		ret = -EINVAL;
		goto err_regulator;
	}

	regmap_update_bits(dac->regmap, PISTACHIO_INTERNAL_DAC_CTRL,
			PISTACHIO_INTERNAL_DAC_CTRL_PWR_SEL_MASK, reg);

	pistachio_internal_dac_pwr_off(dac);
	pistachio_internal_dac_pwr_on(dac);

	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	pm_runtime_idle(dev);

	ret = devm_snd_soc_register_component(dev,
			&pistachio_internal_dac_driver,
			pistachio_internal_dac_dais,
			ARRAY_SIZE(pistachio_internal_dac_dais));
	if (ret) {
		dev_err(dev, "failed to register component: %d\n", ret);
		goto err_pwr;
	}

	return 0;

err_pwr:
	pm_runtime_disable(&pdev->dev);
	pistachio_internal_dac_pwr_off(dac);
err_regulator:
	regulator_disable(dac->supply);

	return ret;
}

__attribute__((used)) static int pistachio_internal_dac_remove(struct platform_device *pdev)
{
	struct pistachio_internal_dac *dac = dev_get_drvdata(&pdev->dev);

	pm_runtime_disable(&pdev->dev);
	pistachio_internal_dac_pwr_off(dac);
	regulator_disable(dac->supply);

	return 0;
}

