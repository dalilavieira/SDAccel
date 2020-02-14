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
struct xway_gphy_priv {int /*<<< orphan*/  gphy_clk_gate; int /*<<< orphan*/  membase; int /*<<< orphan*/  gphy_reset2; int /*<<< orphan*/  gphy_reset; int /*<<< orphan*/  fw_name; } ;
struct xway_gphy_match_data {int /*<<< orphan*/  ge_firmware_name; int /*<<< orphan*/  fe_firmware_name; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct firmware {size_t size; int /*<<< orphan*/  data; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  ALIGN (int /*<<< orphan*/ ,size_t) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  GPHY_MODE_FE 129 
#define  GPHY_MODE_GE 128 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 void* PTR_ALIGN (void*,size_t) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 size_t XRX200_GPHY_FW_ALIGN ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int device_property_read_u32 (struct device*,char*,int*) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_ioremap_resource (struct device*,struct resource*) ; 
 struct xway_gphy_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_reset_control_get (struct device*,char*) ; 
 int /*<<< orphan*/  devm_reset_control_get_optional (struct device*,char*) ; 
 void* dmam_alloc_coherent (struct device*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iowrite32be (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ ,size_t) ; 
 struct xway_gphy_match_data* of_device_get_match_data (struct device*) ; 
 struct xway_gphy_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xway_gphy_priv*) ; 
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  reset_control_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reset_control_deassert (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int xway_gphy_load(struct device *dev, struct xway_gphy_priv *priv,
			  dma_addr_t *dev_addr)
{
	const struct firmware *fw;
	void *fw_addr;
	dma_addr_t dma_addr;
	size_t size;
	int ret;

	ret = request_firmware(&fw, priv->fw_name, dev);
	if (ret) {
		dev_err(dev, "failed to load firmware: %s, error: %i\n",
			priv->fw_name, ret);
		return ret;
	}

	/*
	 * GPHY cores need the firmware code in a persistent and contiguous
	 * memory area with a 16 kB boundary aligned start address.
	 */
	size = fw->size + XRX200_GPHY_FW_ALIGN;

	fw_addr = dmam_alloc_coherent(dev, size, &dma_addr, GFP_KERNEL);
	if (fw_addr) {
		fw_addr = PTR_ALIGN(fw_addr, XRX200_GPHY_FW_ALIGN);
		*dev_addr = ALIGN(dma_addr, XRX200_GPHY_FW_ALIGN);
		memcpy(fw_addr, fw->data, fw->size);
	} else {
		dev_err(dev, "failed to alloc firmware memory\n");
		ret = -ENOMEM;
	}

	release_firmware(fw);

	return ret;
}

__attribute__((used)) static int xway_gphy_of_probe(struct platform_device *pdev,
			      struct xway_gphy_priv *priv)
{
	struct device *dev = &pdev->dev;
	const struct xway_gphy_match_data *gphy_fw_name_cfg;
	u32 gphy_mode;
	int ret;
	struct resource *res_gphy;

	gphy_fw_name_cfg = of_device_get_match_data(dev);

	priv->gphy_clk_gate = devm_clk_get(dev, NULL);
	if (IS_ERR(priv->gphy_clk_gate)) {
		dev_err(dev, "Failed to lookup gate clock\n");
		return PTR_ERR(priv->gphy_clk_gate);
	}

	res_gphy = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->membase = devm_ioremap_resource(dev, res_gphy);
	if (IS_ERR(priv->membase))
		return PTR_ERR(priv->membase);

	priv->gphy_reset = devm_reset_control_get(dev, "gphy");
	if (IS_ERR(priv->gphy_reset)) {
		if (PTR_ERR(priv->gphy_reset) != -EPROBE_DEFER)
			dev_err(dev, "Failed to lookup gphy reset\n");
		return PTR_ERR(priv->gphy_reset);
	}

	priv->gphy_reset2 = devm_reset_control_get_optional(dev, "gphy2");
	if (IS_ERR(priv->gphy_reset2))
		return PTR_ERR(priv->gphy_reset2);

	ret = device_property_read_u32(dev, "lantiq,gphy-mode", &gphy_mode);
	/* Default to GE mode */
	if (ret)
		gphy_mode = GPHY_MODE_GE;

	switch (gphy_mode) {
	case GPHY_MODE_FE:
		priv->fw_name = gphy_fw_name_cfg->fe_firmware_name;
		break;
	case GPHY_MODE_GE:
		priv->fw_name = gphy_fw_name_cfg->ge_firmware_name;
		break;
	default:
		dev_err(dev, "Unknown GPHY mode %d\n", gphy_mode);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int xway_gphy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct xway_gphy_priv *priv;
	dma_addr_t fw_addr = 0;
	int ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	ret = xway_gphy_of_probe(pdev, priv);
	if (ret)
		return ret;

	ret = clk_prepare_enable(priv->gphy_clk_gate);
	if (ret)
		return ret;

	ret = xway_gphy_load(dev, priv, &fw_addr);
	if (ret) {
		clk_disable_unprepare(priv->gphy_clk_gate);
		return ret;
	}

	reset_control_assert(priv->gphy_reset);
	reset_control_assert(priv->gphy_reset2);

	iowrite32be(fw_addr, priv->membase);

	reset_control_deassert(priv->gphy_reset);
	reset_control_deassert(priv->gphy_reset2);

	platform_set_drvdata(pdev, priv);

	return ret;
}

__attribute__((used)) static int xway_gphy_remove(struct platform_device *pdev)
{
	struct xway_gphy_priv *priv = platform_get_drvdata(pdev);

	iowrite32be(0, priv->membase);

	clk_disable_unprepare(priv->gphy_clk_gate);

	return 0;
}

