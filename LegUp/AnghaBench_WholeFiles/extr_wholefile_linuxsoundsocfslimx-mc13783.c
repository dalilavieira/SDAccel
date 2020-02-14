#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct imx_pcm_fiq_params {int dummy; } ;
struct imx_dma_data {int dma_request; int peripheral_type; int /*<<< orphan*/  priority; } ;
typedef  enum sdma_peripheral_type { ____Placeholder_sdma_peripheral_type } sdma_peripheral_type ;
struct TYPE_4__ {int /*<<< orphan*/ * dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_PRIO_HIGH ; 
 int ENODEV ; 
 int IMX_AUDMUX_V1_PCR_RCLKDIR ; 
 int IMX_AUDMUX_V1_PCR_RFCSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V1_PCR_RFSDIR ; 
 int IMX_AUDMUX_V1_PCR_RXDSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V1_PCR_SYN ; 
 int IMX_AUDMUX_V1_PCR_TCLKDIR ; 
 int IMX_AUDMUX_V1_PCR_TFCSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V1_PCR_TFSDIR ; 
 int IMX_AUDMUX_V2_PDCR_INMMASK (int) ; 
 int IMX_AUDMUX_V2_PDCR_MODE (int) ; 
 int IMX_AUDMUX_V2_PDCR_RXDSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V2_PTCR_RCLKDIR ; 
 int IMX_AUDMUX_V2_PTCR_RCSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V2_PTCR_RFSDIR ; 
 int IMX_AUDMUX_V2_PTCR_RFSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V2_PTCR_SYN ; 
 int IMX_AUDMUX_V2_PTCR_TCLKDIR ; 
 int IMX_AUDMUX_V2_PTCR_TCSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V2_PTCR_TFSDIR ; 
 int IMX_AUDMUX_V2_PTCR_TFSEL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MC13783_CLK_CLIA ; 
 int /*<<< orphan*/  MX27_AUDMUX_HPCR1_SSI0 ; 
 int /*<<< orphan*/  MX27_AUDMUX_HPCR3_SSI_PINS_4 ; 
 int /*<<< orphan*/  MX31_AUDMUX_PORT1_SSI0 ; 
 int /*<<< orphan*/  MX31_AUDMUX_PORT4_SSI_PINS_4 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  imx_audmux_v1_configure_port (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  imx_audmux_v2_configure_port (int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ imx_mc13783 ; 
 scalar_t__ machine_is_mx27_3ds () ; 
 scalar_t__ machine_is_mx31_3ds () ; 
 scalar_t__ machine_is_mx31moboard () ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int,int,int,int) ; 
 int snd_soc_register_card (TYPE_1__*) ; 
 int /*<<< orphan*/  snd_soc_unregister_card (TYPE_1__*) ; 

__attribute__((used)) static inline void
imx_pcm_dma_params_init_data(struct imx_dma_data *dma_data,
	int dma, enum sdma_peripheral_type peripheral_type)
{
	dma_data->dma_request = dma;
	dma_data->priority = DMA_PRIO_HIGH;
	dma_data->peripheral_type = peripheral_type;
}

__attribute__((used)) static inline int imx_pcm_dma_init(struct platform_device *pdev, size_t size)
{
	return -ENODEV;
}

__attribute__((used)) static inline int imx_pcm_fiq_init(struct platform_device *pdev,
		struct imx_pcm_fiq_params *params)
{
	return -ENODEV;
}

__attribute__((used)) static inline void imx_pcm_fiq_exit(struct platform_device *pdev)
{
}

__attribute__((used)) static int imx_mc13783_hifi_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	int ret;

	ret = snd_soc_dai_set_tdm_slot(codec_dai, 0x3, 0x3, 4, 16);
	if (ret)
		return ret;

	ret = snd_soc_dai_set_sysclk(codec_dai, MC13783_CLK_CLIA, 26000000, 0);
	if (ret)
		return ret;

	return snd_soc_dai_set_tdm_slot(cpu_dai, 0x3, 0x3, 2, 16);
}

__attribute__((used)) static int imx_mc13783_probe(struct platform_device *pdev)
{
	int ret;

	imx_mc13783.dev = &pdev->dev;

	ret = snd_soc_register_card(&imx_mc13783);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
			ret);
		return ret;
	}

	if (machine_is_mx31_3ds() || machine_is_mx31moboard()) {
		imx_audmux_v2_configure_port(MX31_AUDMUX_PORT4_SSI_PINS_4,
			IMX_AUDMUX_V2_PTCR_SYN,
			IMX_AUDMUX_V2_PDCR_RXDSEL(MX31_AUDMUX_PORT1_SSI0) |
			IMX_AUDMUX_V2_PDCR_MODE(1) |
			IMX_AUDMUX_V2_PDCR_INMMASK(0xfc));
		imx_audmux_v2_configure_port(MX31_AUDMUX_PORT1_SSI0,
			IMX_AUDMUX_V2_PTCR_SYN |
			IMX_AUDMUX_V2_PTCR_TFSDIR |
			IMX_AUDMUX_V2_PTCR_TFSEL(MX31_AUDMUX_PORT4_SSI_PINS_4) |
			IMX_AUDMUX_V2_PTCR_TCLKDIR |
			IMX_AUDMUX_V2_PTCR_TCSEL(MX31_AUDMUX_PORT4_SSI_PINS_4) |
			IMX_AUDMUX_V2_PTCR_RFSDIR |
			IMX_AUDMUX_V2_PTCR_RFSEL(MX31_AUDMUX_PORT4_SSI_PINS_4) |
			IMX_AUDMUX_V2_PTCR_RCLKDIR |
			IMX_AUDMUX_V2_PTCR_RCSEL(MX31_AUDMUX_PORT4_SSI_PINS_4),
			IMX_AUDMUX_V2_PDCR_RXDSEL(MX31_AUDMUX_PORT4_SSI_PINS_4));
	} else if (machine_is_mx27_3ds()) {
		imx_audmux_v1_configure_port(MX27_AUDMUX_HPCR1_SSI0,
			IMX_AUDMUX_V1_PCR_SYN |
			IMX_AUDMUX_V1_PCR_TFSDIR |
			IMX_AUDMUX_V1_PCR_TCLKDIR |
			IMX_AUDMUX_V1_PCR_RFSDIR |
			IMX_AUDMUX_V1_PCR_RCLKDIR |
			IMX_AUDMUX_V1_PCR_TFCSEL(MX27_AUDMUX_HPCR3_SSI_PINS_4) |
			IMX_AUDMUX_V1_PCR_RFCSEL(MX27_AUDMUX_HPCR3_SSI_PINS_4) |
			IMX_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_HPCR3_SSI_PINS_4)
		);
		imx_audmux_v1_configure_port(MX27_AUDMUX_HPCR3_SSI_PINS_4,
			IMX_AUDMUX_V1_PCR_SYN |
			IMX_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_HPCR1_SSI0)
		);
	}

	return ret;
}

__attribute__((used)) static int imx_mc13783_remove(struct platform_device *pdev)
{
	snd_soc_unregister_card(&imx_mc13783);

	return 0;
}

