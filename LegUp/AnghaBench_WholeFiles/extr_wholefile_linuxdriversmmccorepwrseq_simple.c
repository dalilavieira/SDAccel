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
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct mmc_pwrseq {int /*<<< orphan*/  owner; int /*<<< orphan*/ * ops; struct device* dev; } ;
struct mmc_pwrseq_simple {int clk_enabled; int post_power_on_delay_ms; int power_off_delay_us; struct mmc_pwrseq pwrseq; struct gpio_descs* reset_gpios; struct gpio_descs* ext_clk; } ;
struct mmc_host {int /*<<< orphan*/  pwrseq; } ;
struct gpio_descs {int ndescs; int /*<<< orphan*/  desc; } ;

/* Variables and functions */
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (struct gpio_descs*) ; 
 int PTR_ERR (struct gpio_descs*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct gpio_descs*) ; 
 int /*<<< orphan*/  clk_prepare_enable (struct gpio_descs*) ; 
 int /*<<< orphan*/  device_property_read_u32 (struct device*,char*,int*) ; 
 struct gpio_descs* devm_clk_get (struct device*,char*) ; 
 struct gpio_descs* devm_gpiod_get_array (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct mmc_pwrseq_simple* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_array_value_cansleep (int,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc_array (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_pwrseq_simple_ops ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct mmc_pwrseq_simple* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mmc_pwrseq_simple*) ; 
 struct mmc_pwrseq_simple* to_pwrseq_simple (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline int mmc_pwrseq_register(struct mmc_pwrseq *pwrseq)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void mmc_pwrseq_unregister(struct mmc_pwrseq *pwrseq) {}

__attribute__((used)) static inline int mmc_pwrseq_alloc(struct mmc_host *host) { return 0; }

__attribute__((used)) static inline void mmc_pwrseq_pre_power_on(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_post_power_on(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_power_off(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_reset(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_free(struct mmc_host *host) {}

__attribute__((used)) static void mmc_pwrseq_simple_set_gpios_value(struct mmc_pwrseq_simple *pwrseq,
					      int value)
{
	struct gpio_descs *reset_gpios = pwrseq->reset_gpios;

	if (!IS_ERR(reset_gpios)) {
		int i, *values;
		int nvalues = reset_gpios->ndescs;

		values = kmalloc_array(nvalues, sizeof(int), GFP_KERNEL);
		if (!values)
			return;

		for (i = 0; i < nvalues; i++)
			values[i] = value;

		gpiod_set_array_value_cansleep(nvalues, reset_gpios->desc, values);
		kfree(values);
	}
}

__attribute__((used)) static void mmc_pwrseq_simple_pre_power_on(struct mmc_host *host)
{
	struct mmc_pwrseq_simple *pwrseq = to_pwrseq_simple(host->pwrseq);

	if (!IS_ERR(pwrseq->ext_clk) && !pwrseq->clk_enabled) {
		clk_prepare_enable(pwrseq->ext_clk);
		pwrseq->clk_enabled = true;
	}

	mmc_pwrseq_simple_set_gpios_value(pwrseq, 1);
}

__attribute__((used)) static void mmc_pwrseq_simple_post_power_on(struct mmc_host *host)
{
	struct mmc_pwrseq_simple *pwrseq = to_pwrseq_simple(host->pwrseq);

	mmc_pwrseq_simple_set_gpios_value(pwrseq, 0);

	if (pwrseq->post_power_on_delay_ms)
		msleep(pwrseq->post_power_on_delay_ms);
}

__attribute__((used)) static void mmc_pwrseq_simple_power_off(struct mmc_host *host)
{
	struct mmc_pwrseq_simple *pwrseq = to_pwrseq_simple(host->pwrseq);

	mmc_pwrseq_simple_set_gpios_value(pwrseq, 1);

	if (pwrseq->power_off_delay_us)
		usleep_range(pwrseq->power_off_delay_us,
			2 * pwrseq->power_off_delay_us);

	if (!IS_ERR(pwrseq->ext_clk) && pwrseq->clk_enabled) {
		clk_disable_unprepare(pwrseq->ext_clk);
		pwrseq->clk_enabled = false;
	}
}

__attribute__((used)) static int mmc_pwrseq_simple_probe(struct platform_device *pdev)
{
	struct mmc_pwrseq_simple *pwrseq;
	struct device *dev = &pdev->dev;

	pwrseq = devm_kzalloc(dev, sizeof(*pwrseq), GFP_KERNEL);
	if (!pwrseq)
		return -ENOMEM;

	pwrseq->ext_clk = devm_clk_get(dev, "ext_clock");
	if (IS_ERR(pwrseq->ext_clk) && PTR_ERR(pwrseq->ext_clk) != -ENOENT)
		return PTR_ERR(pwrseq->ext_clk);

	pwrseq->reset_gpios = devm_gpiod_get_array(dev, "reset",
							GPIOD_OUT_HIGH);
	if (IS_ERR(pwrseq->reset_gpios) &&
	    PTR_ERR(pwrseq->reset_gpios) != -ENOENT &&
	    PTR_ERR(pwrseq->reset_gpios) != -ENOSYS) {
		return PTR_ERR(pwrseq->reset_gpios);
	}

	device_property_read_u32(dev, "post-power-on-delay-ms",
				 &pwrseq->post_power_on_delay_ms);
	device_property_read_u32(dev, "power-off-delay-us",
				 &pwrseq->power_off_delay_us);

	pwrseq->pwrseq.dev = dev;
	pwrseq->pwrseq.ops = &mmc_pwrseq_simple_ops;
	pwrseq->pwrseq.owner = THIS_MODULE;
	platform_set_drvdata(pdev, pwrseq);

	return mmc_pwrseq_register(&pwrseq->pwrseq);
}

__attribute__((used)) static int mmc_pwrseq_simple_remove(struct platform_device *pdev)
{
	struct mmc_pwrseq_simple *pwrseq = platform_get_drvdata(pdev);

	mmc_pwrseq_unregister(&pwrseq->pwrseq);

	return 0;
}

