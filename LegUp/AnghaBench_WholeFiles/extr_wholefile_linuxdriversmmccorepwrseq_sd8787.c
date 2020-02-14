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
struct mmc_pwrseq_sd8787 {struct mmc_pwrseq pwrseq; void* reset_gpio; void* pwrdn_gpio; } ;
struct mmc_host {int /*<<< orphan*/  pwrseq; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct mmc_pwrseq_sd8787* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  mmc_pwrseq_sd8787_ops ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct mmc_pwrseq_sd8787* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mmc_pwrseq_sd8787*) ; 
 struct mmc_pwrseq_sd8787* to_pwrseq_sd8787 (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static void mmc_pwrseq_sd8787_pre_power_on(struct mmc_host *host)
{
	struct mmc_pwrseq_sd8787 *pwrseq = to_pwrseq_sd8787(host->pwrseq);

	gpiod_set_value_cansleep(pwrseq->reset_gpio, 1);

	msleep(300);
	gpiod_set_value_cansleep(pwrseq->pwrdn_gpio, 1);
}

__attribute__((used)) static void mmc_pwrseq_sd8787_power_off(struct mmc_host *host)
{
	struct mmc_pwrseq_sd8787 *pwrseq = to_pwrseq_sd8787(host->pwrseq);

	gpiod_set_value_cansleep(pwrseq->pwrdn_gpio, 0);
	gpiod_set_value_cansleep(pwrseq->reset_gpio, 0);
}

__attribute__((used)) static int mmc_pwrseq_sd8787_probe(struct platform_device *pdev)
{
	struct mmc_pwrseq_sd8787 *pwrseq;
	struct device *dev = &pdev->dev;

	pwrseq = devm_kzalloc(dev, sizeof(*pwrseq), GFP_KERNEL);
	if (!pwrseq)
		return -ENOMEM;

	pwrseq->pwrdn_gpio = devm_gpiod_get(dev, "powerdown", GPIOD_OUT_LOW);
	if (IS_ERR(pwrseq->pwrdn_gpio))
		return PTR_ERR(pwrseq->pwrdn_gpio);

	pwrseq->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(pwrseq->reset_gpio))
		return PTR_ERR(pwrseq->reset_gpio);

	pwrseq->pwrseq.dev = dev;
	pwrseq->pwrseq.ops = &mmc_pwrseq_sd8787_ops;
	pwrseq->pwrseq.owner = THIS_MODULE;
	platform_set_drvdata(pdev, pwrseq);

	return mmc_pwrseq_register(&pwrseq->pwrseq);
}

__attribute__((used)) static int mmc_pwrseq_sd8787_remove(struct platform_device *pdev)
{
	struct mmc_pwrseq_sd8787 *pwrseq = platform_get_drvdata(pdev);

	mmc_pwrseq_unregister(&pwrseq->pwrseq);

	return 0;
}

