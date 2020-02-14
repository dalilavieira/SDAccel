#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct notifier_block {int dummy; } ;
typedef  scalar_t__ s16 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_4__ {scalar_t__ va; } ;
struct TYPE_3__ {scalar_t__ va; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
#define  CPU_CLUSTER_PM_ENTER 129 
#define  CPU_CLUSTER_PM_EXIT 128 
 int EINVAL ; 
 int NOTIFY_OK ; 
 scalar_t__ OMAP_SDRC_REGADDR (scalar_t__) ; 
 scalar_t__ OMAP_SMS_REGADDR (scalar_t__) ; 
 int __ffs (int) ; 
 int /*<<< orphan*/ * am33xx_control_vals ; 
 int /*<<< orphan*/ * am43xx_control_reg_offsets ; 
 TYPE_2__ cm_base ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int /*<<< orphan*/  enable_off_mode ; 
 int /*<<< orphan*/  omap_ctrl_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_ctrl_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ omap_rev () ; 
 TYPE_1__ prm_base ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline int soc_is_omap(void)
{
	return omap_rev() != 0;
}

__attribute__((used)) static inline int omap2_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap3_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_pm_init_early(void)
{
	return 0;
}

__attribute__((used)) static inline int amx3_common_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap_l2_cache_init(void)
{
	return 0;
}

__attribute__((used)) static inline void omap_soc_device_init(void)
{
}

__attribute__((used)) static inline void omap2xxx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void am33xx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void omap3xxx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void ti81xx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void omap44xx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void omap_barrier_reserve_memblock(void)
{
}

__attribute__((used)) static inline int omap4_enter_lowpower(unsigned int cpu,
					unsigned int power_state)
{
	cpu_do_idle();
	return 0;
}

__attribute__((used)) static inline int omap4_hotplug_cpu(unsigned int cpu, unsigned int power_state)
{
	cpu_do_idle();
	return 0;
}

__attribute__((used)) static inline int omap4_mpuss_init(void)
{
	return 0;
}

__attribute__((used)) static inline void omap4_secondary_startup(void)
{
}

__attribute__((used)) static inline void omap4460_secondary_startup(void)
{
}

__attribute__((used)) static inline int omap4_finish_suspend(unsigned long cpu_state)
{
	return 0;
}

__attribute__((used)) static inline void omap4_cpu_resume(void)
{
}

__attribute__((used)) static inline void omap5_secondary_startup(void)
{
}

__attribute__((used)) static inline void omap5_secondary_hyp_startup(void)
{
}

__attribute__((used)) static inline u32 omap2_prm_read_mod_reg(s16 module, u16 idx)
{
	return readl_relaxed(prm_base.va + module + idx);
}

__attribute__((used)) static inline void omap2_prm_write_mod_reg(u32 val, s16 module, u16 idx)
{
	writel_relaxed(val, prm_base.va + module + idx);
}

__attribute__((used)) static inline u32 omap2_prm_rmw_mod_reg_bits(u32 mask, u32 bits, s16 module,
					     s16 idx)
{
	u32 v;

	v = omap2_prm_read_mod_reg(module, idx);
	v &= ~mask;
	v |= bits;
	omap2_prm_write_mod_reg(v, module, idx);

	return v;
}

__attribute__((used)) static inline u32 omap2_prm_read_mod_bits_shift(s16 domain, s16 idx, u32 mask)
{
	u32 v;

	v = omap2_prm_read_mod_reg(domain, idx);
	v &= mask;
	v >>= __ffs(mask);

	return v;
}

__attribute__((used)) static inline u32 omap2_prm_set_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
	return omap2_prm_rmw_mod_reg_bits(bits, bits, module, idx);
}

__attribute__((used)) static inline u32 omap2_prm_clear_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
	return omap2_prm_rmw_mod_reg_bits(bits, 0x0, module, idx);
}

__attribute__((used)) static inline u32 omap2_cm_read_mod_reg(s16 module, u16 idx)
{
	return readl_relaxed(cm_base.va + module + idx);
}

__attribute__((used)) static inline void omap2_cm_write_mod_reg(u32 val, s16 module, u16 idx)
{
	writel_relaxed(val, cm_base.va + module + idx);
}

__attribute__((used)) static inline u32 omap2_cm_rmw_mod_reg_bits(u32 mask, u32 bits, s16 module,
					    s16 idx)
{
	u32 v;

	v = omap2_cm_read_mod_reg(module, idx);
	v &= ~mask;
	v |= bits;
	omap2_cm_write_mod_reg(v, module, idx);

	return v;
}

__attribute__((used)) static inline u32 omap2_cm_read_mod_bits_shift(s16 domain, s16 idx, u32 mask)
{
	u32 v;

	v = omap2_cm_read_mod_reg(domain, idx);
	v &= mask;
	v >>= __ffs(mask);

	return v;
}

__attribute__((used)) static inline u32 omap2_cm_set_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
	return omap2_cm_rmw_mod_reg_bits(bits, bits, module, idx);
}

__attribute__((used)) static inline u32 omap2_cm_clear_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
	return omap2_cm_rmw_mod_reg_bits(bits, 0x0, module, idx);
}

__attribute__((used)) static inline void sdrc_write_reg(u32 val, u16 reg)
{
	writel_relaxed(val, OMAP_SDRC_REGADDR(reg));
}

__attribute__((used)) static inline u32 sdrc_read_reg(u16 reg)
{
	return readl_relaxed(OMAP_SDRC_REGADDR(reg));
}

__attribute__((used)) static inline void sms_write_reg(u32 val, u16 reg)
{
	writel_relaxed(val, OMAP_SMS_REGADDR(reg));
}

__attribute__((used)) static inline u32 sms_read_reg(u16 reg)
{
	return readl_relaxed(OMAP_SMS_REGADDR(reg));
}

__attribute__((used)) static inline int omap3_idle_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_idle_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap3_opp_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline int omap4_opp_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void enable_omap3630_toggle_l2_on_restore(void) { }

__attribute__((used)) static inline int omap_devinit_smartreflex(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void omap_enable_smartreflex_on_init(void) {}

__attribute__((used)) static inline int omap3_twl_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline int omap4_twl_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void omap_pm_setup_oscillator(u32 tstart, u32 tshut) { }

__attribute__((used)) static inline void omap_pm_get_oscillator(u32 *tstart, u32 *tshut) { *tstart = *tshut = 0; }

__attribute__((used)) static inline void omap_pm_setup_sr_i2c_pcb_length(u32 mm) { }

__attribute__((used)) static inline void omap_common_suspend_init(void *pm_suspend)
{
}

void am43xx_control_save_context(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(am43xx_control_reg_offsets); i++)
		am33xx_control_vals[i] =
				omap_ctrl_readl(am43xx_control_reg_offsets[i]);
}

void am43xx_control_restore_context(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(am43xx_control_reg_offsets); i++)
		omap_ctrl_writel(am33xx_control_vals[i],
				 am43xx_control_reg_offsets[i]);
}

__attribute__((used)) static int cpu_notifier(struct notifier_block *nb, unsigned long cmd, void *v)
{
	switch (cmd) {
	case CPU_CLUSTER_PM_ENTER:
		if (enable_off_mode)
			am43xx_control_save_context();
		break;
	case CPU_CLUSTER_PM_EXIT:
		if (enable_off_mode)
			am43xx_control_restore_context();
		break;
	}

	return NOTIFY_OK;
}

