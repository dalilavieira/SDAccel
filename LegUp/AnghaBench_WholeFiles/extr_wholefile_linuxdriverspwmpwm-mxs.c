#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct resource {int dummy; } ;
struct pwm_device {int hwpwm; } ;
struct pwm_chip {int dummy; } ;
struct TYPE_8__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct TYPE_7__ {int base; int /*<<< orphan*/  npwm; int /*<<< orphan*/ * ops; TYPE_3__* dev; } ;
struct mxs_pwm_chip {TYPE_1__ chip; scalar_t__ base; scalar_t__ clk; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 scalar_t__ CLR ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PERIOD_ACTIVE_HIGH ; 
 int PERIOD_CDIV (int) ; 
 int PERIOD_CDIV_MAX ; 
 int PERIOD_INACTIVE_LOW ; 
 int PERIOD_PERIOD (unsigned int) ; 
 unsigned long long PERIOD_PERIOD_MAX ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ PWM_ACTIVE0 ; 
 scalar_t__ PWM_CTRL ; 
 scalar_t__ PWM_PERIOD0 ; 
 scalar_t__ SET ; 
 unsigned long* cdiv ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 scalar_t__ devm_clk_get (TYPE_3__*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (TYPE_3__*,struct resource*) ; 
 struct mxs_pwm_chip* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (unsigned long long,int) ; 
 int /*<<< orphan*/  mxs_pwm_ops ; 
 int of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct mxs_pwm_chip* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mxs_pwm_chip*) ; 
 int /*<<< orphan*/  pwm_is_enabled (struct pwm_device*) ; 
 int pwmchip_add (TYPE_1__*) ; 
 int pwmchip_remove (TYPE_1__*) ; 
 int stmp_reset_block (scalar_t__) ; 
 struct mxs_pwm_chip* to_mxs_pwm_chip (struct pwm_chip*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int mxs_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
			  int duty_ns, int period_ns)
{
	struct mxs_pwm_chip *mxs = to_mxs_pwm_chip(chip);
	int ret, div = 0;
	unsigned int period_cycles, duty_cycles;
	unsigned long rate;
	unsigned long long c;

	rate = clk_get_rate(mxs->clk);
	while (1) {
		c = rate / cdiv[div];
		c = c * period_ns;
		do_div(c, 1000000000);
		if (c < PERIOD_PERIOD_MAX)
			break;
		div++;
		if (div >= PERIOD_CDIV_MAX)
			return -EINVAL;
	}

	period_cycles = c;
	c *= duty_ns;
	do_div(c, period_ns);
	duty_cycles = c;

	/*
	 * If the PWM channel is disabled, make sure to turn on the clock
	 * before writing the register. Otherwise, keep it enabled.
	 */
	if (!pwm_is_enabled(pwm)) {
		ret = clk_prepare_enable(mxs->clk);
		if (ret)
			return ret;
	}

	writel(duty_cycles << 16,
			mxs->base + PWM_ACTIVE0 + pwm->hwpwm * 0x20);
	writel(PERIOD_PERIOD(period_cycles) | PERIOD_ACTIVE_HIGH |
	       PERIOD_INACTIVE_LOW | PERIOD_CDIV(div),
			mxs->base + PWM_PERIOD0 + pwm->hwpwm * 0x20);

	/*
	 * If the PWM is not enabled, turn the clock off again to save power.
	 */
	if (!pwm_is_enabled(pwm))
		clk_disable_unprepare(mxs->clk);

	return 0;
}

__attribute__((used)) static int mxs_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct mxs_pwm_chip *mxs = to_mxs_pwm_chip(chip);
	int ret;

	ret = clk_prepare_enable(mxs->clk);
	if (ret)
		return ret;

	writel(1 << pwm->hwpwm, mxs->base + PWM_CTRL + SET);

	return 0;
}

__attribute__((used)) static void mxs_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct mxs_pwm_chip *mxs = to_mxs_pwm_chip(chip);

	writel(1 << pwm->hwpwm, mxs->base + PWM_CTRL + CLR);

	clk_disable_unprepare(mxs->clk);
}

__attribute__((used)) static int mxs_pwm_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct mxs_pwm_chip *mxs;
	struct resource *res;
	int ret;

	mxs = devm_kzalloc(&pdev->dev, sizeof(*mxs), GFP_KERNEL);
	if (!mxs)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	mxs->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mxs->base))
		return PTR_ERR(mxs->base);

	mxs->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(mxs->clk))
		return PTR_ERR(mxs->clk);

	mxs->chip.dev = &pdev->dev;
	mxs->chip.ops = &mxs_pwm_ops;
	mxs->chip.base = -1;

	ret = of_property_read_u32(np, "fsl,pwm-number", &mxs->chip.npwm);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to get pwm number: %d\n", ret);
		return ret;
	}

	ret = pwmchip_add(&mxs->chip);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to add pwm chip %d\n", ret);
		return ret;
	}

	platform_set_drvdata(pdev, mxs);

	ret = stmp_reset_block(mxs->base);
	if (ret)
		goto pwm_remove;

	return 0;

pwm_remove:
	pwmchip_remove(&mxs->chip);
	return ret;
}

__attribute__((used)) static int mxs_pwm_remove(struct platform_device *pdev)
{
	struct mxs_pwm_chip *mxs = platform_get_drvdata(pdev);

	return pwmchip_remove(&mxs->chip);
}

