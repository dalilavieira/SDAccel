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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
typedef  int /*<<< orphan*/  s16 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP44XX_PRCM_MPU_REGADDR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int /*<<< orphan*/  readl_relaxed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

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

u32 omap4_prcm_mpu_read_inst_reg(s16 inst, u16 reg)
{
	return readl_relaxed(OMAP44XX_PRCM_MPU_REGADDR(inst, reg));
}

void omap4_prcm_mpu_write_inst_reg(u32 val, s16 inst, u16 reg)
{
	writel_relaxed(val, OMAP44XX_PRCM_MPU_REGADDR(inst, reg));
}

u32 omap4_prcm_mpu_rmw_inst_reg_bits(u32 mask, u32 bits, s16 inst, s16 reg)
{
	u32 v;

	v = omap4_prcm_mpu_read_inst_reg(inst, reg);
	v &= ~mask;
	v |= bits;
	omap4_prcm_mpu_write_inst_reg(v, inst, reg);

	return v;
}

