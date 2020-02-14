#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct resource {int dummy; } ;
struct device {TYPE_1__* driver; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {struct mxs_data* data; } ;
struct mxs_ocotp {scalar_t__ nvmem; scalar_t__ clk; scalar_t__ base; } ;
struct mxs_data {int /*<<< orphan*/  size; } ;
struct TYPE_5__ {struct device* dev; struct mxs_ocotp* priv; int /*<<< orphan*/  size; } ;
struct TYPE_4__ {int /*<<< orphan*/  of_match_table; } ;

/* Variables and functions */
 unsigned int BM_OCOTP_CTRL_BUSY ; 
 unsigned int BM_OCOTP_CTRL_ERROR ; 
 unsigned int BM_OCOTP_CTRL_RD_BANK_OPEN ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 unsigned int OCOTP_DATA_OFFSET ; 
 int OCOTP_TIMEOUT ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ STMP_OFFSET_REG_CLR ; 
 scalar_t__ STMP_OFFSET_REG_SET ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int clk_enable (scalar_t__) ; 
 int clk_prepare (scalar_t__) ; 
 int /*<<< orphan*/  clk_unprepare (scalar_t__) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct mxs_ocotp* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ nvmem_register (TYPE_2__*) ; 
 int nvmem_unregister (scalar_t__) ; 
 TYPE_2__ ocotp_config ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 struct mxs_ocotp* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mxs_ocotp*) ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static int mxs_ocotp_wait(struct mxs_ocotp *otp)
{
	int timeout = OCOTP_TIMEOUT;
	unsigned int status = 0;

	while (timeout--) {
		status = readl(otp->base);

		if (!(status & (BM_OCOTP_CTRL_BUSY | BM_OCOTP_CTRL_ERROR)))
			break;

		cpu_relax();
	}

	if (status & BM_OCOTP_CTRL_BUSY)
		return -EBUSY;
	else if (status & BM_OCOTP_CTRL_ERROR)
		return -EIO;

	return 0;
}

__attribute__((used)) static int mxs_ocotp_read(void *context, unsigned int offset,
			  void *val, size_t bytes)
{
	struct mxs_ocotp *otp = context;
	u32 *buf = val;
	int ret;

	ret = clk_enable(otp->clk);
	if (ret)
		return ret;

	writel(BM_OCOTP_CTRL_ERROR, otp->base + STMP_OFFSET_REG_CLR);

	ret = mxs_ocotp_wait(otp);
	if (ret)
		goto disable_clk;

	/* open OCOTP banks for read */
	writel(BM_OCOTP_CTRL_RD_BANK_OPEN, otp->base + STMP_OFFSET_REG_SET);

	/* approximately wait 33 hclk cycles */
	udelay(1);

	ret = mxs_ocotp_wait(otp);
	if (ret)
		goto close_banks;

	while (bytes) {
		if ((offset < OCOTP_DATA_OFFSET) || (offset % 16)) {
			/* fill up non-data register */
			*buf++ = 0;
		} else {
			*buf++ = readl(otp->base + offset);
		}

		bytes -= 4;
		offset += 4;
	}

close_banks:
	/* close banks for power saving */
	writel(BM_OCOTP_CTRL_RD_BANK_OPEN, otp->base + STMP_OFFSET_REG_CLR);

disable_clk:
	clk_disable(otp->clk);

	return ret;
}

__attribute__((used)) static int mxs_ocotp_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	const struct mxs_data *data;
	struct mxs_ocotp *otp;
	struct resource *res;
	const struct of_device_id *match;
	int ret;

	match = of_match_device(dev->driver->of_match_table, dev);
	if (!match || !match->data)
		return -EINVAL;

	otp = devm_kzalloc(dev, sizeof(*otp), GFP_KERNEL);
	if (!otp)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	otp->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(otp->base))
		return PTR_ERR(otp->base);

	otp->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(otp->clk))
		return PTR_ERR(otp->clk);

	ret = clk_prepare(otp->clk);
	if (ret < 0) {
		dev_err(dev, "failed to prepare clk: %d\n", ret);
		return ret;
	}

	data = match->data;

	ocotp_config.size = data->size;
	ocotp_config.priv = otp;
	ocotp_config.dev = dev;
	otp->nvmem = nvmem_register(&ocotp_config);
	if (IS_ERR(otp->nvmem)) {
		ret = PTR_ERR(otp->nvmem);
		goto err_clk;
	}

	platform_set_drvdata(pdev, otp);

	return 0;

err_clk:
	clk_unprepare(otp->clk);

	return ret;
}

__attribute__((used)) static int mxs_ocotp_remove(struct platform_device *pdev)
{
	struct mxs_ocotp *otp = platform_get_drvdata(pdev);

	clk_unprepare(otp->clk);

	return nvmem_unregister(otp->nvmem);
}

