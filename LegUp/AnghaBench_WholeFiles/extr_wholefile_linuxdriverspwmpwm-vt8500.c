#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned long u32 ;
struct TYPE_8__ {int of_pwm_n_cells; int base; int /*<<< orphan*/  npwm; int /*<<< orphan*/  of_xlate; int /*<<< orphan*/ * ops; TYPE_3__* dev; } ;
struct vt8500_chip {TYPE_1__ chip; scalar_t__ clk; scalar_t__ base; } ;
struct resource {int dummy; } ;
struct pwm_device {int hwpwm; } ;
struct pwm_chip {TYPE_3__* dev; } ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct device_node {int dummy; } ;
typedef  enum pwm_polarity { ____Placeholder_pwm_polarity } pwm_polarity ;

/* Variables and functions */
 unsigned long CTRL_AUTOLOAD ; 
 unsigned long CTRL_ENABLE ; 
 unsigned long CTRL_INVERT ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int PWM_POLARITY_INVERSED ; 
 scalar_t__ REG_CTRL (int) ; 
 scalar_t__ REG_DUTY (int) ; 
 scalar_t__ REG_PERIOD (int) ; 
 scalar_t__ REG_SCALAR (int) ; 
 scalar_t__ REG_STATUS ; 
 int STATUS_CTRL_UPDATE ; 
 int STATUS_DUTY_UPDATE ; 
 int STATUS_PERIOD_UPDATE ; 
 int STATUS_SCALAR_UPDATE ; 
 int /*<<< orphan*/  VT8500_NR_PWMS ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int clk_enable (scalar_t__) ; 
 unsigned long long clk_get_rate (scalar_t__) ; 
 int clk_prepare (scalar_t__) ; 
 int /*<<< orphan*/  clk_unprepare (scalar_t__) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,unsigned long) ; 
 scalar_t__ devm_clk_get (TYPE_3__*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (TYPE_3__*,struct resource*) ; 
 struct vt8500_chip* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (unsigned long long,int) ; 
 int msecs_to_loops (int) ; 
 int /*<<< orphan*/  of_pwm_xlate_with_flags ; 
 struct vt8500_chip* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct vt8500_chip*) ; 
 int pwmchip_add (TYPE_1__*) ; 
 int pwmchip_remove (TYPE_1__*) ; 
 unsigned long readl (scalar_t__) ; 
 struct vt8500_chip* to_vt8500_chip (struct pwm_chip*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  vt8500_pwm_ops ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static inline void pwm_busy_wait(struct vt8500_chip *vt8500, int nr, u8 bitmask)
{
	int loops = msecs_to_loops(10);
	u32 mask = bitmask << (nr << 8);

	while ((readl(vt8500->base + REG_STATUS) & mask) && --loops)
		cpu_relax();

	if (unlikely(!loops))
		dev_warn(vt8500->chip.dev, "Waiting for status bits 0x%x to clear timed out\n",
			 mask);
}

__attribute__((used)) static int vt8500_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
		int duty_ns, int period_ns)
{
	struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
	unsigned long long c;
	unsigned long period_cycles, prescale, pv, dc;
	int err;
	u32 val;

	err = clk_enable(vt8500->clk);
	if (err < 0) {
		dev_err(chip->dev, "failed to enable clock\n");
		return err;
	}

	c = clk_get_rate(vt8500->clk);
	c = c * period_ns;
	do_div(c, 1000000000);
	period_cycles = c;

	if (period_cycles < 1)
		period_cycles = 1;
	prescale = (period_cycles - 1) / 4096;
	pv = period_cycles / (prescale + 1) - 1;
	if (pv > 4095)
		pv = 4095;

	if (prescale > 1023) {
		clk_disable(vt8500->clk);
		return -EINVAL;
	}

	c = (unsigned long long)pv * duty_ns;
	do_div(c, period_ns);
	dc = c;

	writel(prescale, vt8500->base + REG_SCALAR(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_SCALAR_UPDATE);

	writel(pv, vt8500->base + REG_PERIOD(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_PERIOD_UPDATE);

	writel(dc, vt8500->base + REG_DUTY(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_DUTY_UPDATE);

	val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
	val |= CTRL_AUTOLOAD;
	writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);

	clk_disable(vt8500->clk);
	return 0;
}

__attribute__((used)) static int vt8500_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
	int err;
	u32 val;

	err = clk_enable(vt8500->clk);
	if (err < 0) {
		dev_err(chip->dev, "failed to enable clock\n");
		return err;
	}

	val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
	val |= CTRL_ENABLE;
	writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);

	return 0;
}

__attribute__((used)) static void vt8500_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
	u32 val;

	val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
	val &= ~CTRL_ENABLE;
	writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);

	clk_disable(vt8500->clk);
}

__attribute__((used)) static int vt8500_pwm_set_polarity(struct pwm_chip *chip,
				   struct pwm_device *pwm,
				   enum pwm_polarity polarity)
{
	struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
	u32 val;

	val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));

	if (polarity == PWM_POLARITY_INVERSED)
		val |= CTRL_INVERT;
	else
		val &= ~CTRL_INVERT;

	writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
	pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);

	return 0;
}

__attribute__((used)) static int vt8500_pwm_probe(struct platform_device *pdev)
{
	struct vt8500_chip *chip;
	struct resource *r;
	struct device_node *np = pdev->dev.of_node;
	int ret;

	if (!np) {
		dev_err(&pdev->dev, "invalid devicetree node\n");
		return -EINVAL;
	}

	chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
	if (chip == NULL)
		return -ENOMEM;

	chip->chip.dev = &pdev->dev;
	chip->chip.ops = &vt8500_pwm_ops;
	chip->chip.of_xlate = of_pwm_xlate_with_flags;
	chip->chip.of_pwm_n_cells = 3;
	chip->chip.base = -1;
	chip->chip.npwm = VT8500_NR_PWMS;

	chip->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(chip->clk)) {
		dev_err(&pdev->dev, "clock source not specified\n");
		return PTR_ERR(chip->clk);
	}

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	chip->base = devm_ioremap_resource(&pdev->dev, r);
	if (IS_ERR(chip->base))
		return PTR_ERR(chip->base);

	ret = clk_prepare(chip->clk);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to prepare clock\n");
		return ret;
	}

	ret = pwmchip_add(&chip->chip);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to add PWM chip\n");
		clk_unprepare(chip->clk);
		return ret;
	}

	platform_set_drvdata(pdev, chip);
	return ret;
}

__attribute__((used)) static int vt8500_pwm_remove(struct platform_device *pdev)
{
	struct vt8500_chip *chip;

	chip = platform_get_drvdata(pdev);
	if (chip == NULL)
		return -ENODEV;

	clk_unprepare(chip->clk);

	return pwmchip_remove(&chip->chip);
}

