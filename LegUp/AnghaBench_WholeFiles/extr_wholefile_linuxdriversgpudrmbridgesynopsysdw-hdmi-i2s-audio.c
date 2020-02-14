#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct snd_soc_component {int dummy; } ;
struct platform_device_info {int size_data; int /*<<< orphan*/  dma_mask; struct hdmi_codec_pdata* data; int /*<<< orphan*/  name; int /*<<< orphan*/  id; int /*<<< orphan*/  parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  parent; struct dw_hdmi_i2s_audio_data* platform_data; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_endpoint {int port; } ;
struct hdmi_codec_pdata {int i2s; int max_i2s_channels; struct dw_hdmi_i2s_audio_data* data; int /*<<< orphan*/ * ops; } ;
struct hdmi_codec_params {int sample_width; int /*<<< orphan*/  sample_rate; } ;
struct hdmi_codec_daifmt {scalar_t__ fmt; int bit_clk_master; int frame_clk_master; } ;
struct dw_hdmi_i2s_audio_data {struct dw_hdmi* hdmi; int /*<<< orphan*/  (* read ) (struct dw_hdmi*,int) ;int /*<<< orphan*/  (* write ) (struct dw_hdmi*,int /*<<< orphan*/ ,int) ;} ;
struct dw_hdmi {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  pdevinfo ;
typedef  int /*<<< orphan*/  pdata ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int EINVAL ; 
 int HDMI_AUD_CONF0 ; 
 int /*<<< orphan*/  HDMI_AUD_CONF0_I2S_ALL_ENABLE ; 
 int /*<<< orphan*/  HDMI_AUD_CONF0_SW_RESET ; 
 int HDMI_AUD_CONF1 ; 
 int /*<<< orphan*/  HDMI_AUD_CONF1_WIDTH_16 ; 
 int /*<<< orphan*/  HDMI_AUD_CONF1_WIDTH_24 ; 
 int HDMI_AUD_INPUTCLKFS ; 
 int /*<<< orphan*/  HDMI_AUD_INPUTCLKFS_64FS ; 
 int /*<<< orphan*/  HDMI_CODEC_DRV_NAME ; 
 scalar_t__ HDMI_I2S ; 
 scalar_t__ IS_ERR (struct platform_device*) ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int PTR_ERR (struct platform_device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct platform_device* dev_get_drvdata (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_1__*,struct platform_device*) ; 
 int /*<<< orphan*/  dw_hdmi_audio_disable (struct dw_hdmi*) ; 
 int /*<<< orphan*/  dw_hdmi_audio_enable (struct dw_hdmi*) ; 
 int /*<<< orphan*/  dw_hdmi_i2s_ops ; 
 int /*<<< orphan*/  dw_hdmi_set_sample_rate (struct dw_hdmi*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct platform_device_info*,int /*<<< orphan*/ ,int) ; 
 int of_graph_parse_endpoint (struct device_node*,struct of_endpoint*) ; 
 struct platform_device* platform_device_register_full (struct platform_device_info*) ; 
 int /*<<< orphan*/  platform_device_unregister (struct platform_device*) ; 
 int /*<<< orphan*/  stub1 (struct dw_hdmi*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub2 (struct dw_hdmi*,int) ; 

__attribute__((used)) static inline void hdmi_write(struct dw_hdmi_i2s_audio_data *audio,
			      u8 val, int offset)
{
	struct dw_hdmi *hdmi = audio->hdmi;

	audio->write(hdmi, val, offset);
}

__attribute__((used)) static inline u8 hdmi_read(struct dw_hdmi_i2s_audio_data *audio, int offset)
{
	struct dw_hdmi *hdmi = audio->hdmi;

	return audio->read(hdmi, offset);
}

__attribute__((used)) static int dw_hdmi_i2s_hw_params(struct device *dev, void *data,
				 struct hdmi_codec_daifmt *fmt,
				 struct hdmi_codec_params *hparms)
{
	struct dw_hdmi_i2s_audio_data *audio = data;
	struct dw_hdmi *hdmi = audio->hdmi;
	u8 conf0 = 0;
	u8 conf1 = 0;
	u8 inputclkfs = 0;

	/* it cares I2S only */
	if ((fmt->fmt != HDMI_I2S) ||
	    (fmt->bit_clk_master | fmt->frame_clk_master)) {
		dev_err(dev, "unsupported format/settings\n");
		return -EINVAL;
	}

	inputclkfs	= HDMI_AUD_INPUTCLKFS_64FS;
	conf0		= HDMI_AUD_CONF0_I2S_ALL_ENABLE;

	switch (hparms->sample_width) {
	case 16:
		conf1 = HDMI_AUD_CONF1_WIDTH_16;
		break;
	case 24:
	case 32:
		conf1 = HDMI_AUD_CONF1_WIDTH_24;
		break;
	}

	dw_hdmi_set_sample_rate(hdmi, hparms->sample_rate);

	hdmi_write(audio, inputclkfs, HDMI_AUD_INPUTCLKFS);
	hdmi_write(audio, conf0, HDMI_AUD_CONF0);
	hdmi_write(audio, conf1, HDMI_AUD_CONF1);

	dw_hdmi_audio_enable(hdmi);

	return 0;
}

__attribute__((used)) static void dw_hdmi_i2s_audio_shutdown(struct device *dev, void *data)
{
	struct dw_hdmi_i2s_audio_data *audio = data;
	struct dw_hdmi *hdmi = audio->hdmi;

	dw_hdmi_audio_disable(hdmi);

	hdmi_write(audio, HDMI_AUD_CONF0_SW_RESET, HDMI_AUD_CONF0);
}

__attribute__((used)) static int dw_hdmi_i2s_get_dai_id(struct snd_soc_component *component,
				  struct device_node *endpoint)
{
	struct of_endpoint of_ep;
	int ret;

	ret = of_graph_parse_endpoint(endpoint, &of_ep);
	if (ret < 0)
		return ret;

	/*
	 * HDMI sound should be located as reg = <2>
	 * Then, it is sound port 0
	 */
	if (of_ep.port == 2)
		return 0;

	return -EINVAL;
}

__attribute__((used)) static int snd_dw_hdmi_probe(struct platform_device *pdev)
{
	struct dw_hdmi_i2s_audio_data *audio = pdev->dev.platform_data;
	struct platform_device_info pdevinfo;
	struct hdmi_codec_pdata pdata;
	struct platform_device *platform;

	pdata.ops		= &dw_hdmi_i2s_ops;
	pdata.i2s		= 1;
	pdata.max_i2s_channels	= 6;
	pdata.data		= audio;

	memset(&pdevinfo, 0, sizeof(pdevinfo));
	pdevinfo.parent		= pdev->dev.parent;
	pdevinfo.id		= PLATFORM_DEVID_AUTO;
	pdevinfo.name		= HDMI_CODEC_DRV_NAME;
	pdevinfo.data		= &pdata;
	pdevinfo.size_data	= sizeof(pdata);
	pdevinfo.dma_mask	= DMA_BIT_MASK(32);

	platform = platform_device_register_full(&pdevinfo);
	if (IS_ERR(platform))
		return PTR_ERR(platform);

	dev_set_drvdata(&pdev->dev, platform);

	return 0;
}

__attribute__((used)) static int snd_dw_hdmi_remove(struct platform_device *pdev)
{
	struct platform_device *platform = dev_get_drvdata(&pdev->dev);

	platform_device_unregister(platform);

	return 0;
}

