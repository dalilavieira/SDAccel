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
typedef  int suspend_state_t ;
struct TYPE_2__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  PM_SUSPEND_MEM 128 
 int SIRFSOC_DEEP_SLEEP_MODE ; 
 scalar_t__ SIRFSOC_PWRC_PDN_CTRL ; 
 scalar_t__ SIRFSOC_PWRC_SCRATCH_PAD1 ; 
 scalar_t__ SIRFSOC_PWRC_TRIGGER_EN ; 
 int SIRFSOC_SLEEP_MODE_MASK ; 
 int __pa_symbol (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_resume ; 
 int /*<<< orphan*/  cpu_suspend (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outer_disable () ; 
 int /*<<< orphan*/  outer_resume () ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  sirfsoc_finish_suspend ; 
 int /*<<< orphan*/  sirfsoc_memc_base ; 
 scalar_t__ sirfsoc_pwrc_base ; 
 int sirfsoc_rtc_iobrg_readl (scalar_t__) ; 
 int /*<<< orphan*/  sirfsoc_rtc_iobrg_writel (int,scalar_t__) ; 

__attribute__((used)) static void sirfsoc_set_wakeup_source(void)
{
	u32 pwr_trigger_en_reg;
	pwr_trigger_en_reg = sirfsoc_rtc_iobrg_readl(sirfsoc_pwrc_base +
		SIRFSOC_PWRC_TRIGGER_EN);
#define X_ON_KEY_B (1 << 0)
#define RTC_ALARM0_B (1 << 2)
#define RTC_ALARM1_B (1 << 3)
	sirfsoc_rtc_iobrg_writel(pwr_trigger_en_reg | X_ON_KEY_B |
		RTC_ALARM0_B | RTC_ALARM1_B,
		sirfsoc_pwrc_base + SIRFSOC_PWRC_TRIGGER_EN);
}

__attribute__((used)) static void sirfsoc_set_sleep_mode(u32 mode)
{
	u32 sleep_mode = sirfsoc_rtc_iobrg_readl(sirfsoc_pwrc_base +
		SIRFSOC_PWRC_PDN_CTRL);
	sleep_mode &= ~(SIRFSOC_SLEEP_MODE_MASK << 1);
	sleep_mode |= mode << 1;
	sirfsoc_rtc_iobrg_writel(sleep_mode, sirfsoc_pwrc_base +
		SIRFSOC_PWRC_PDN_CTRL);
}

__attribute__((used)) static int sirfsoc_pre_suspend_power_off(void)
{
	u32 wakeup_entry = __pa_symbol(cpu_resume);

	sirfsoc_rtc_iobrg_writel(wakeup_entry, sirfsoc_pwrc_base +
		SIRFSOC_PWRC_SCRATCH_PAD1);

	sirfsoc_set_wakeup_source();

	sirfsoc_set_sleep_mode(SIRFSOC_DEEP_SLEEP_MODE);

	return 0;
}

__attribute__((used)) static int sirfsoc_pm_enter(suspend_state_t state)
{
	switch (state) {
	case PM_SUSPEND_MEM:
		sirfsoc_pre_suspend_power_off();

		outer_disable();
		/* go zzz */
		cpu_suspend(0, sirfsoc_finish_suspend);
		outer_resume();
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int sirfsoc_memc_probe(struct platform_device *op)
{
	struct device_node *np = op->dev.of_node;

	sirfsoc_memc_base = of_iomap(np, 0);
	if (!sirfsoc_memc_base)
		panic("unable to map memc registers\n");

	return 0;
}

