#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_6__ ;
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dai {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct platform_device {TYPE_6__ dev; } ;
struct imx_pcm_fiq_params {int dummy; } ;
struct imx_dma_data {int dma_request; int peripheral_type; int /*<<< orphan*/  priority; } ;
struct device_node {int dummy; } ;
typedef  enum sdma_peripheral_type { ____Placeholder_sdma_peripheral_type } sdma_peripheral_type ;
struct TYPE_8__ {char* cpu_dai_name; char* platform_name; char* codec_name; struct device_node* platform_of_node; struct device_node* cpu_of_node; struct device_node* codec_of_node; } ;
struct TYPE_7__ {char* name; TYPE_6__* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  CODEC_CLOCK ; 
 int /*<<< orphan*/  DMA_PRIO_HIGH ; 
 int EINVAL ; 
 int ENODEV ; 
 int IMX_AUDMUX_V1_PCR_RCLKDIR ; 
 int IMX_AUDMUX_V1_PCR_RFCSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V1_PCR_RFSDIR ; 
 int IMX_AUDMUX_V1_PCR_RXDSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V1_PCR_SYN ; 
 int IMX_AUDMUX_V1_PCR_TCLKDIR ; 
 int IMX_AUDMUX_V1_PCR_TFCSEL (int /*<<< orphan*/ ) ; 
 int IMX_AUDMUX_V1_PCR_TFSDIR ; 
 int /*<<< orphan*/  IMX_AUDMUX_V2_PDCR_RXDSEL (int) ; 
 int IMX_AUDMUX_V2_PTCR_SYN ; 
 int IMX_AUDMUX_V2_PTCR_TCLKDIR ; 
 int IMX_AUDMUX_V2_PTCR_TCSEL (int) ; 
 int IMX_AUDMUX_V2_PTCR_TFSDIR ; 
 int IMX_AUDMUX_V2_PTCR_TFSEL (int) ; 
 int /*<<< orphan*/  IMX_SSP_SYS_CLK ; 
 int /*<<< orphan*/  MX27_AUDMUX_HPCR1_SSI0 ; 
 int /*<<< orphan*/  MX27_AUDMUX_HPCR3_SSI_PINS_4 ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_OUT ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 TYPE_1__ eukrea_tlv320 ; 
 TYPE_4__ eukrea_tlv320_dai ; 
 int /*<<< orphan*/  imx_audmux_v1_configure_port (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  imx_audmux_v2_configure_port (int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ machine_is_eukrea_cpuimx25sd () ; 
 scalar_t__ machine_is_eukrea_cpuimx27 () ; 
 scalar_t__ machine_is_eukrea_cpuimx35sd () ; 
 scalar_t__ machine_is_eukrea_cpuimx51sd () ; 
 scalar_t__ of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int,int,int,int /*<<< orphan*/ ) ; 
 int snd_soc_of_parse_card_name (TYPE_1__*,char*) ; 
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

__attribute__((used)) static int eukrea_tlv320_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	int ret;

	ret = snd_soc_dai_set_sysclk(codec_dai, 0,
				     CODEC_CLOCK, SND_SOC_CLOCK_OUT);
	if (ret) {
		dev_err(cpu_dai->dev,
			"Failed to set the codec sysclk.\n");
		return ret;
	}

	snd_soc_dai_set_tdm_slot(cpu_dai, 0x3, 0x3, 2, 0);

	ret = snd_soc_dai_set_sysclk(cpu_dai, IMX_SSP_SYS_CLK, 0,
				SND_SOC_CLOCK_IN);
	/* fsl_ssi lacks the set_sysclk ops */
	if (ret && ret != -EINVAL) {
		dev_err(cpu_dai->dev,
			"Can't set the IMX_SSP_SYS_CLK CPU system clock.\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int eukrea_tlv320_probe(struct platform_device *pdev)
{
	int ret;
	int int_port = 0, ext_port;
	struct device_node *np = pdev->dev.of_node;
	struct device_node *ssi_np = NULL, *codec_np = NULL;

	eukrea_tlv320.dev = &pdev->dev;
	if (np) {
		ret = snd_soc_of_parse_card_name(&eukrea_tlv320,
						 "eukrea,model");
		if (ret) {
			dev_err(&pdev->dev,
				"eukrea,model node missing or invalid.\n");
			goto err;
		}

		ssi_np = of_parse_phandle(pdev->dev.of_node,
					  "ssi-controller", 0);
		if (!ssi_np) {
			dev_err(&pdev->dev,
				"ssi-controller missing or invalid.\n");
			ret = -ENODEV;
			goto err;
		}

		codec_np = of_parse_phandle(ssi_np, "codec-handle", 0);
		if (codec_np)
			eukrea_tlv320_dai.codec_of_node = codec_np;
		else
			dev_err(&pdev->dev, "codec-handle node missing or invalid.\n");

		ret = of_property_read_u32(np, "fsl,mux-int-port", &int_port);
		if (ret) {
			dev_err(&pdev->dev,
				"fsl,mux-int-port node missing or invalid.\n");
			return ret;
		}
		ret = of_property_read_u32(np, "fsl,mux-ext-port", &ext_port);
		if (ret) {
			dev_err(&pdev->dev,
				"fsl,mux-ext-port node missing or invalid.\n");
			return ret;
		}

		/*
		 * The port numbering in the hardware manual starts at 1, while
		 * the audmux API expects it starts at 0.
		 */
		int_port--;
		ext_port--;

		eukrea_tlv320_dai.cpu_of_node = ssi_np;
		eukrea_tlv320_dai.platform_of_node = ssi_np;
	} else {
		eukrea_tlv320_dai.cpu_dai_name = "imx-ssi.0";
		eukrea_tlv320_dai.platform_name = "imx-ssi.0";
		eukrea_tlv320_dai.codec_name = "tlv320aic23-codec.0-001a";
		eukrea_tlv320.name = "cpuimx-audio";
	}

	if (machine_is_eukrea_cpuimx27() ||
	    of_find_compatible_node(NULL, NULL, "fsl,imx21-audmux")) {
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
	} else if (machine_is_eukrea_cpuimx25sd() ||
		   machine_is_eukrea_cpuimx35sd() ||
		   machine_is_eukrea_cpuimx51sd() ||
		   of_find_compatible_node(NULL, NULL, "fsl,imx31-audmux")) {
		if (!np)
			ext_port = machine_is_eukrea_cpuimx25sd() ?
				4 : 3;

		imx_audmux_v2_configure_port(int_port,
			IMX_AUDMUX_V2_PTCR_SYN |
			IMX_AUDMUX_V2_PTCR_TFSDIR |
			IMX_AUDMUX_V2_PTCR_TFSEL(ext_port) |
			IMX_AUDMUX_V2_PTCR_TCLKDIR |
			IMX_AUDMUX_V2_PTCR_TCSEL(ext_port),
			IMX_AUDMUX_V2_PDCR_RXDSEL(ext_port)
		);
		imx_audmux_v2_configure_port(ext_port,
			IMX_AUDMUX_V2_PTCR_SYN,
			IMX_AUDMUX_V2_PDCR_RXDSEL(int_port)
		);
	} else {
		if (np) {
			/* The eukrea,asoc-tlv320 driver was explicitly
			 * requested (through the device tree).
			 */
			dev_err(&pdev->dev,
				"Missing or invalid audmux DT node.\n");
			return -ENODEV;
		} else {
			/* Return happy.
			 * We might run on a totally different machine.
			 */
			return 0;
		}
	}

	ret = snd_soc_register_card(&eukrea_tlv320);
err:
	if (ret)
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
	of_node_put(ssi_np);

	return ret;
}

__attribute__((used)) static int eukrea_tlv320_remove(struct platform_device *pdev)
{
	snd_soc_unregister_card(&eukrea_tlv320);

	return 0;
}

