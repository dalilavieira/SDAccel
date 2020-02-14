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
typedef  scalar_t__ u8 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {TYPE_1__* dev; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct davinci_vc {int /*<<< orphan*/  regmap; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_2__ {struct davinci_vc* platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAVINCI_VC_REG09 ; 
 scalar_t__ DAVINCI_VC_REG09_MUTE ; 
 int /*<<< orphan*/  DAVINCI_VC_REG12 ; 
 int /*<<< orphan*/  DAVINCI_VC_REG12_POWER_ALL_OFF ; 
 int /*<<< orphan*/  DAVINCI_VC_REG12_POWER_ALL_ON ; 
 int EINVAL ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int /*<<< orphan*/  cq93vc_dai ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_cq93vc ; 

__attribute__((used)) static int cq93vc_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u8 reg;

	if (mute)
		reg = DAVINCI_VC_REG09_MUTE;
	else
		reg = 0;

	snd_soc_component_update_bits(component, DAVINCI_VC_REG09, DAVINCI_VC_REG09_MUTE,
			    reg);

	return 0;
}

__attribute__((used)) static int cq93vc_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	switch (freq) {
	case 22579200:
	case 27000000:
	case 33868800:
		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int cq93vc_set_bias_level(struct snd_soc_component *component,
				enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
		snd_soc_component_write(component, DAVINCI_VC_REG12,
			     DAVINCI_VC_REG12_POWER_ALL_ON);
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		snd_soc_component_write(component, DAVINCI_VC_REG12,
			     DAVINCI_VC_REG12_POWER_ALL_OFF);
		break;
	case SND_SOC_BIAS_OFF:
		/* force all power off */
		snd_soc_component_write(component, DAVINCI_VC_REG12,
			     DAVINCI_VC_REG12_POWER_ALL_OFF);
		break;
	}

	return 0;
}

__attribute__((used)) static int cq93vc_probe(struct snd_soc_component *component)
{
	struct davinci_vc *davinci_vc = component->dev->platform_data;

	snd_soc_component_init_regmap(component, davinci_vc->regmap);

	return 0;
}

__attribute__((used)) static int cq93vc_platform_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
			&soc_component_dev_cq93vc, &cq93vc_dai, 1);
}

__attribute__((used)) static int cq93vc_platform_remove(struct platform_device *pdev)
{
	return 0;
}

