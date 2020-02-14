#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int dummy; } ;
struct pwm_device {int hwpwm; } ;
struct pwm_chip {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int npwm; int base; TYPE_3__* pwms; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * dev; } ;
struct lpc32xx_pwm_chip {TYPE_1__ chip; scalar_t__ base; scalar_t__ clk; } ;
struct TYPE_5__ {int hwpwm; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ NSEC_PER_SEC ; 
 int PTR_ERR (scalar_t__) ; 
 int PWM_ENABLE ; 
 int PWM_PIN_LEVEL ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct lpc32xx_pwm_chip* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int div64_u64 (unsigned long long,int) ; 
 int /*<<< orphan*/  lpc32xx_pwm_ops ; 
 struct lpc32xx_pwm_chip* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lpc32xx_pwm_chip*) ; 
 int /*<<< orphan*/  pwm_disable (TYPE_3__*) ; 
 int pwmchip_add (TYPE_1__*) ; 
 int pwmchip_remove (TYPE_1__*) ; 
 int readl (scalar_t__) ; 
 struct lpc32xx_pwm_chip* to_lpc32xx_pwm_chip (struct pwm_chip*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int lpc32xx_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
			      int duty_ns, int period_ns)
{
	struct lpc32xx_pwm_chip *lpc32xx = to_lpc32xx_pwm_chip(chip);
	unsigned long long c;
	int period_cycles, duty_cycles;
	u32 val;
	c = clk_get_rate(lpc32xx->clk);

	/* The highest acceptable divisor is 256, which is represented by 0 */
	period_cycles = div64_u64(c * period_ns,
			       (unsigned long long)NSEC_PER_SEC * 256);
	if (!period_cycles || period_cycles > 256)
		return -ERANGE;
	if (period_cycles == 256)
		period_cycles = 0;

	/* Compute 256 x #duty/period value and care for corner cases */
	duty_cycles = div64_u64((unsigned long long)(period_ns - duty_ns) * 256,
				period_ns);
	if (!duty_cycles)
		duty_cycles = 1;
	if (duty_cycles > 255)
		duty_cycles = 255;

	val = readl(lpc32xx->base + (pwm->hwpwm << 2));
	val &= ~0xFFFF;
	val |= (period_cycles << 8) | duty_cycles;
	writel(val, lpc32xx->base + (pwm->hwpwm << 2));

	return 0;
}

__attribute__((used)) static int lpc32xx_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct lpc32xx_pwm_chip *lpc32xx = to_lpc32xx_pwm_chip(chip);
	u32 val;
	int ret;

	ret = clk_prepare_enable(lpc32xx->clk);
	if (ret)
		return ret;

	val = readl(lpc32xx->base + (pwm->hwpwm << 2));
	val |= PWM_ENABLE;
	writel(val, lpc32xx->base + (pwm->hwpwm << 2));

	return 0;
}

__attribute__((used)) static void lpc32xx_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct lpc32xx_pwm_chip *lpc32xx = to_lpc32xx_pwm_chip(chip);
	u32 val;

	val = readl(lpc32xx->base + (pwm->hwpwm << 2));
	val &= ~PWM_ENABLE;
	writel(val, lpc32xx->base + (pwm->hwpwm << 2));

	clk_disable_unprepare(lpc32xx->clk);
}

__attribute__((used)) static int lpc32xx_pwm_probe(struct platform_device *pdev)
{
	struct lpc32xx_pwm_chip *lpc32xx;
	struct resource *res;
	int ret;
	u32 val;

	lpc32xx = devm_kzalloc(&pdev->dev, sizeof(*lpc32xx), GFP_KERNEL);
	if (!lpc32xx)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	lpc32xx->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(lpc32xx->base))
		return PTR_ERR(lpc32xx->base);

	lpc32xx->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(lpc32xx->clk))
		return PTR_ERR(lpc32xx->clk);

	lpc32xx->chip.dev = &pdev->dev;
	lpc32xx->chip.ops = &lpc32xx_pwm_ops;
	lpc32xx->chip.npwm = 1;
	lpc32xx->chip.base = -1;

	ret = pwmchip_add(&lpc32xx->chip);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to add PWM chip, error %d\n", ret);
		return ret;
	}

	/* When PWM is disable, configure the output to the default value */
	val = readl(lpc32xx->base + (lpc32xx->chip.pwms[0].hwpwm << 2));
	val &= ~PWM_PIN_LEVEL;
	writel(val, lpc32xx->base + (lpc32xx->chip.pwms[0].hwpwm << 2));

	platform_set_drvdata(pdev, lpc32xx);

	return 0;
}

__attribute__((used)) static int lpc32xx_pwm_remove(struct platform_device *pdev)
{
	struct lpc32xx_pwm_chip *lpc32xx = platform_get_drvdata(pdev);
	unsigned int i;

	for (i = 0; i < lpc32xx->chip.npwm; i++)
		pwm_disable(&lpc32xx->chip.pwms[i]);

	return pwmchip_remove(&lpc32xx->chip);
}

