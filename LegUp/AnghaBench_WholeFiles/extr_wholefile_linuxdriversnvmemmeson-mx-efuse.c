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
typedef  int u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct meson_mx_efuse_platform_data {unsigned int word_size; int /*<<< orphan*/  name; } ;
struct TYPE_2__ {int word_size; unsigned int stride; int read_only; int (* reg_read ) (void*,unsigned int,void*,size_t) ;int /*<<< orphan*/  size; struct meson_mx_efuse* priv; int /*<<< orphan*/ * dev; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; } ;
struct meson_mx_efuse {int base; int core_clk; int /*<<< orphan*/  nvmem; TYPE_1__ config; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int FIELD_PREP (int,unsigned int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int) ; 
 int MESON_MX_EFUSE_CNTL1 ; 
 int MESON_MX_EFUSE_CNTL1_AUTO_RD_BUSY ; 
 int MESON_MX_EFUSE_CNTL1_AUTO_RD_ENABLE ; 
 int MESON_MX_EFUSE_CNTL1_AUTO_RD_START ; 
 int MESON_MX_EFUSE_CNTL1_BYTE_ADDR_MASK ; 
 int MESON_MX_EFUSE_CNTL1_BYTE_ADDR_SET ; 
 int MESON_MX_EFUSE_CNTL1_PD_ENABLE ; 
 int MESON_MX_EFUSE_CNTL2 ; 
 int MESON_MX_EFUSE_CNTL4 ; 
 int MESON_MX_EFUSE_CNTL4_ENCRYPT_ENABLE ; 
 int PTR_ERR (int) ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SZ_512 ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  clk_disable_unprepare (int) ; 
 int clk_prepare_enable (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 int /*<<< orphan*/  devm_kstrdup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct meson_mx_efuse* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_nvmem_register (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (void*,int*,unsigned int) ; 
 struct meson_mx_efuse_platform_data* of_device_get_match_data (int /*<<< orphan*/ *) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl (int) ; 
 int readl_poll_timeout_atomic (int,int,int,int,int) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static void meson_mx_efuse_mask_bits(struct meson_mx_efuse *efuse, u32 reg,
				     u32 mask, u32 set)
{
	u32 data;

	data = readl(efuse->base + reg);
	data &= ~mask;
	data |= (set & mask);

	writel(data, efuse->base + reg);
}

__attribute__((used)) static int meson_mx_efuse_hw_enable(struct meson_mx_efuse *efuse)
{
	int err;

	err = clk_prepare_enable(efuse->core_clk);
	if (err)
		return err;

	/* power up the efuse */
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_PD_ENABLE, 0);

	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL4,
				 MESON_MX_EFUSE_CNTL4_ENCRYPT_ENABLE, 0);

	return 0;
}

__attribute__((used)) static void meson_mx_efuse_hw_disable(struct meson_mx_efuse *efuse)
{
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_PD_ENABLE,
				 MESON_MX_EFUSE_CNTL1_PD_ENABLE);

	clk_disable_unprepare(efuse->core_clk);
}

__attribute__((used)) static int meson_mx_efuse_read_addr(struct meson_mx_efuse *efuse,
				    unsigned int addr, u32 *value)
{
	int err;
	u32 regval;

	/* write the address to read */
	regval = FIELD_PREP(MESON_MX_EFUSE_CNTL1_BYTE_ADDR_MASK, addr);
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_BYTE_ADDR_MASK, regval);

	/* inform the hardware that we changed the address */
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_BYTE_ADDR_SET,
				 MESON_MX_EFUSE_CNTL1_BYTE_ADDR_SET);
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_BYTE_ADDR_SET, 0);

	/* start the read process */
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_AUTO_RD_START,
				 MESON_MX_EFUSE_CNTL1_AUTO_RD_START);
	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_AUTO_RD_START, 0);

	/*
	 * perform a dummy read to ensure that the HW has the RD_BUSY bit set
	 * when polling for the status below.
	 */
	readl(efuse->base + MESON_MX_EFUSE_CNTL1);

	err = readl_poll_timeout_atomic(efuse->base + MESON_MX_EFUSE_CNTL1,
			regval,
			(!(regval & MESON_MX_EFUSE_CNTL1_AUTO_RD_BUSY)),
			1, 1000);
	if (err) {
		dev_err(efuse->config.dev,
			"Timeout while reading efuse address %u\n", addr);
		return err;
	}

	*value = readl(efuse->base + MESON_MX_EFUSE_CNTL2);

	return 0;
}

__attribute__((used)) static int meson_mx_efuse_read(void *context, unsigned int offset,
			       void *buf, size_t bytes)
{
	struct meson_mx_efuse *efuse = context;
	u32 tmp;
	int err, i, addr;

	err = meson_mx_efuse_hw_enable(efuse);
	if (err)
		return err;

	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_AUTO_RD_ENABLE,
				 MESON_MX_EFUSE_CNTL1_AUTO_RD_ENABLE);

	for (i = 0; i < bytes; i += efuse->config.word_size) {
		addr = (offset + i) / efuse->config.word_size;

		err = meson_mx_efuse_read_addr(efuse, addr, &tmp);
		if (err)
			break;

		memcpy(buf + i, &tmp, efuse->config.word_size);
	}

	meson_mx_efuse_mask_bits(efuse, MESON_MX_EFUSE_CNTL1,
				 MESON_MX_EFUSE_CNTL1_AUTO_RD_ENABLE, 0);

	meson_mx_efuse_hw_disable(efuse);

	return err;
}

__attribute__((used)) static int meson_mx_efuse_probe(struct platform_device *pdev)
{
	const struct meson_mx_efuse_platform_data *drvdata;
	struct meson_mx_efuse *efuse;
	struct resource *res;

	drvdata = of_device_get_match_data(&pdev->dev);
	if (!drvdata)
		return -EINVAL;

	efuse = devm_kzalloc(&pdev->dev, sizeof(*efuse), GFP_KERNEL);
	if (!efuse)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	efuse->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(efuse->base))
		return PTR_ERR(efuse->base);

	efuse->config.name = devm_kstrdup(&pdev->dev, drvdata->name,
					  GFP_KERNEL);
	efuse->config.owner = THIS_MODULE;
	efuse->config.dev = &pdev->dev;
	efuse->config.priv = efuse;
	efuse->config.stride = drvdata->word_size;
	efuse->config.word_size = drvdata->word_size;
	efuse->config.size = SZ_512;
	efuse->config.read_only = true;
	efuse->config.reg_read = meson_mx_efuse_read;

	efuse->core_clk = devm_clk_get(&pdev->dev, "core");
	if (IS_ERR(efuse->core_clk)) {
		dev_err(&pdev->dev, "Failed to get core clock\n");
		return PTR_ERR(efuse->core_clk);
	}

	efuse->nvmem = devm_nvmem_register(&pdev->dev, &efuse->config);

	return PTR_ERR_OR_ZERO(efuse->nvmem);
}

