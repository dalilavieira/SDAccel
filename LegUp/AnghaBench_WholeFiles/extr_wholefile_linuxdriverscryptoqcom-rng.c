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
typedef  int u32 ;
struct resource {int dummy; } ;
struct qcom_rng_ctx {struct qcom_rng* rng; } ;
struct qcom_rng {unsigned long skip_init; scalar_t__ clk; scalar_t__ base; int /*<<< orphan*/  lock; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_rng {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ PRNG_CONFIG ; 
 int PRNG_CONFIG_HW_ENABLE ; 
 scalar_t__ PRNG_DATA_OUT ; 
 scalar_t__ PRNG_LFSR_CFG ; 
 int PRNG_LFSR_CFG_CLOCKS ; 
 int PRNG_LFSR_CFG_MASK ; 
 scalar_t__ PRNG_STATUS ; 
 int PRNG_STATUS_DATA_AVAIL ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned int WORD_SZ ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int crypto_register_rng (int /*<<< orphan*/ *) ; 
 struct qcom_rng_ctx* crypto_rng_ctx (struct crypto_rng*) ; 
 struct qcom_rng_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  crypto_unregister_rng (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ device_get_match_data (int /*<<< orphan*/ *) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct qcom_rng* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  has_acpi_companion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int*,unsigned int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct qcom_rng*) ; 
 int /*<<< orphan*/  qcom_rng_alg ; 
 struct qcom_rng* qcom_rng_dev ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int qcom_rng_read(struct qcom_rng *rng, u8 *data, unsigned int max)
{
	unsigned int currsize = 0;
	u32 val;

	/* read random data from hardware */
	do {
		val = readl_relaxed(rng->base + PRNG_STATUS);
		if (!(val & PRNG_STATUS_DATA_AVAIL))
			break;

		val = readl_relaxed(rng->base + PRNG_DATA_OUT);
		if (!val)
			break;

		if ((max - currsize) >= WORD_SZ) {
			memcpy(data, &val, WORD_SZ);
			data += WORD_SZ;
			currsize += WORD_SZ;
		} else {
			/* copy only remaining bytes */
			memcpy(data, &val, max - currsize);
			break;
		}
	} while (currsize < max);

	return currsize;
}

__attribute__((used)) static int qcom_rng_generate(struct crypto_rng *tfm,
			     const u8 *src, unsigned int slen,
			     u8 *dstn, unsigned int dlen)
{
	struct qcom_rng_ctx *ctx = crypto_rng_ctx(tfm);
	struct qcom_rng *rng = ctx->rng;
	int ret;

	ret = clk_prepare_enable(rng->clk);
	if (ret)
		return ret;

	mutex_lock(&rng->lock);

	ret = qcom_rng_read(rng, dstn, dlen);

	mutex_unlock(&rng->lock);
	clk_disable_unprepare(rng->clk);

	return 0;
}

__attribute__((used)) static int qcom_rng_seed(struct crypto_rng *tfm, const u8 *seed,
			 unsigned int slen)
{
	return 0;
}

__attribute__((used)) static int qcom_rng_enable(struct qcom_rng *rng)
{
	u32 val;
	int ret;

	ret = clk_prepare_enable(rng->clk);
	if (ret)
		return ret;

	/* Enable PRNG only if it is not already enabled */
	val = readl_relaxed(rng->base + PRNG_CONFIG);
	if (val & PRNG_CONFIG_HW_ENABLE)
		goto already_enabled;

	val = readl_relaxed(rng->base + PRNG_LFSR_CFG);
	val &= ~PRNG_LFSR_CFG_MASK;
	val |= PRNG_LFSR_CFG_CLOCKS;
	writel(val, rng->base + PRNG_LFSR_CFG);

	val = readl_relaxed(rng->base + PRNG_CONFIG);
	val |= PRNG_CONFIG_HW_ENABLE;
	writel(val, rng->base + PRNG_CONFIG);

already_enabled:
	clk_disable_unprepare(rng->clk);

	return 0;
}

__attribute__((used)) static int qcom_rng_init(struct crypto_tfm *tfm)
{
	struct qcom_rng_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->rng = qcom_rng_dev;

	if (!ctx->rng->skip_init)
		return qcom_rng_enable(ctx->rng);

	return 0;
}

__attribute__((used)) static int qcom_rng_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct qcom_rng *rng;
	int ret;

	rng = devm_kzalloc(&pdev->dev, sizeof(*rng), GFP_KERNEL);
	if (!rng)
		return -ENOMEM;

	platform_set_drvdata(pdev, rng);
	mutex_init(&rng->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	rng->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(rng->base))
		return PTR_ERR(rng->base);

	/* ACPI systems have clk already on, so skip clk_get */
	if (!has_acpi_companion(&pdev->dev)) {
		rng->clk = devm_clk_get(&pdev->dev, "core");
		if (IS_ERR(rng->clk))
			return PTR_ERR(rng->clk);
	}


	rng->skip_init = (unsigned long)device_get_match_data(&pdev->dev);

	qcom_rng_dev = rng;
	ret = crypto_register_rng(&qcom_rng_alg);
	if (ret) {
		dev_err(&pdev->dev, "Register crypto rng failed: %d\n", ret);
		qcom_rng_dev = NULL;
	}

	return ret;
}

__attribute__((used)) static int qcom_rng_remove(struct platform_device *pdev)
{
	crypto_unregister_rng(&qcom_rng_alg);

	qcom_rng_dev = NULL;

	return 0;
}

