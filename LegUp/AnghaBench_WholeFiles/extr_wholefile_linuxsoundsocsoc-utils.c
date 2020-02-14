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
struct snd_soc_pcm_runtime {TYPE_1__* dai_link; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {int /*<<< orphan*/ * driver; } ;
struct snd_soc_component {int /*<<< orphan*/  name_prefix; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  no_pcm; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dummy_codec ; 
 int /*<<< orphan*/  dummy_dai ; 
 int /*<<< orphan*/  dummy_dma_hardware ; 
 int /*<<< orphan*/  dummy_platform ; 
 char* kasprintf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 int snd_soc_dapm_disable_pin (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_disable_pin_unlocked (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_enable_pin (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_enable_pin_unlocked (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_force_enable_pin (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_force_enable_pin_unlocked (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_get_pin_status (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_nc_pin (struct snd_soc_dapm_context*,char const*) ; 
 int snd_soc_dapm_nc_pin_unlocked (struct snd_soc_dapm_context*,char const*) ; 
 int /*<<< orphan*/  snd_soc_set_runtime_hwparams (struct snd_pcm_substream*,int /*<<< orphan*/ *) ; 

int snd_soc_calc_frame_size(int sample_size, int channels, int tdm_slots)
{
	return sample_size * channels * tdm_slots;
}

int snd_soc_params_to_frame_size(struct snd_pcm_hw_params *params)
{
	int sample_size;

	sample_size = snd_pcm_format_width(params_format(params));
	if (sample_size < 0)
		return sample_size;

	return snd_soc_calc_frame_size(sample_size, params_channels(params),
				       1);
}

int snd_soc_calc_bclk(int fs, int sample_size, int channels, int tdm_slots)
{
	return fs * snd_soc_calc_frame_size(sample_size, channels, tdm_slots);
}

int snd_soc_params_to_bclk(struct snd_pcm_hw_params *params)
{
	int ret;

	ret = snd_soc_params_to_frame_size(params);

	if (ret > 0)
		return ret * params_rate(params);
	else
		return ret;
}

int snd_soc_component_enable_pin(struct snd_soc_component *component,
				 const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_enable_pin(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_enable_pin(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_enable_pin_unlocked(struct snd_soc_component *component,
					  const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_enable_pin_unlocked(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_enable_pin_unlocked(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_disable_pin(struct snd_soc_component *component,
				  const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_disable_pin(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_disable_pin(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_disable_pin_unlocked(struct snd_soc_component *component,
					   const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_disable_pin_unlocked(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_disable_pin_unlocked(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_nc_pin(struct snd_soc_component *component,
			     const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_nc_pin(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_nc_pin(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_nc_pin_unlocked(struct snd_soc_component *component,
				      const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_nc_pin_unlocked(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_nc_pin_unlocked(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_get_pin_status(struct snd_soc_component *component,
				     const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_get_pin_status(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_get_pin_status(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_force_enable_pin(struct snd_soc_component *component,
				       const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_force_enable_pin(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_force_enable_pin(dapm, full_name);
	kfree(full_name);

	return ret;
}

int snd_soc_component_force_enable_pin_unlocked(
					struct snd_soc_component *component,
					const char *pin)
{
	struct snd_soc_dapm_context *dapm =
		snd_soc_component_get_dapm(component);
	char *full_name;
	int ret;

	if (!component->name_prefix)
		return snd_soc_dapm_force_enable_pin_unlocked(dapm, pin);

	full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
	if (!full_name)
		return -ENOMEM;

	ret = snd_soc_dapm_force_enable_pin_unlocked(dapm, full_name);
	kfree(full_name);

	return ret;
}

__attribute__((used)) static int dummy_dma_open(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;

	/* BE's dont need dummy params */
	if (!rtd->dai_link->no_pcm)
		snd_soc_set_runtime_hwparams(substream, &dummy_dma_hardware);

	return 0;
}

int snd_soc_dai_is_dummy(struct snd_soc_dai *dai)
{
	if (dai->driver == &dummy_dai)
		return 1;
	return 0;
}

__attribute__((used)) static int snd_soc_dummy_probe(struct platform_device *pdev)
{
	int ret;

	ret = devm_snd_soc_register_component(&pdev->dev,
					      &dummy_codec, &dummy_dai, 1);
	if (ret < 0)
		return ret;

	ret = devm_snd_soc_register_component(&pdev->dev, &dummy_platform,
					      NULL, 0);

	return ret;
}

