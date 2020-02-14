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
typedef  int /*<<< orphan*/  u8 ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {struct imx_iim_drvdata* data; } ;
struct nvmem_device {int dummy; } ;
struct nvmem_config {char* name; int read_only; int word_size; int stride; int (* reg_read ) (void*,unsigned int,void*,size_t) ;struct iim_priv* priv; int /*<<< orphan*/  size; struct device* dev; } ;
struct imx_iim_drvdata {int /*<<< orphan*/  nregs; } ;
struct iim_priv {scalar_t__ clk; scalar_t__ base; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IIM_BANK_BASE (int) ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int PTR_ERR_OR_ZERO (struct nvmem_device*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct iim_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct nvmem_device* devm_nvmem_register (struct device*,struct nvmem_config*) ; 
 int /*<<< orphan*/  imx_iim_dt_ids ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 

__attribute__((used)) static int imx_iim_read(void *context, unsigned int offset,
			  void *buf, size_t bytes)
{
	struct iim_priv *iim = context;
	int i, ret;
	u8 *buf8 = buf;

	ret = clk_prepare_enable(iim->clk);
	if (ret)
		return ret;

	for (i = offset; i < offset + bytes; i++) {
		int bank = i >> 5;
		int reg = i & 0x1f;

		*buf8++ = readl(iim->base + IIM_BANK_BASE(bank) + reg * 4);
	}

	clk_disable_unprepare(iim->clk);

	return 0;
}

__attribute__((used)) static int imx_iim_probe(struct platform_device *pdev)
{
	const struct of_device_id *of_id;
	struct device *dev = &pdev->dev;
	struct resource *res;
	struct iim_priv *iim;
	struct nvmem_device *nvmem;
	struct nvmem_config cfg = {};
	const struct imx_iim_drvdata *drvdata = NULL;

	iim = devm_kzalloc(dev, sizeof(*iim), GFP_KERNEL);
	if (!iim)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	iim->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(iim->base))
		return PTR_ERR(iim->base);

	of_id = of_match_device(imx_iim_dt_ids, dev);
	if (!of_id)
		return -ENODEV;

	drvdata = of_id->data;

	iim->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(iim->clk))
		return PTR_ERR(iim->clk);

	cfg.name = "imx-iim",
	cfg.read_only = true,
	cfg.word_size = 1,
	cfg.stride = 1,
	cfg.reg_read = imx_iim_read,
	cfg.dev = dev;
	cfg.size = drvdata->nregs;
	cfg.priv = iim;

	nvmem = devm_nvmem_register(dev, &cfg);

	return PTR_ERR_OR_ZERO(nvmem);
}

