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
typedef  scalar_t__ s16 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_4__ {int slow_dll_ctrl; int fast_dll_ctrl; int m_type; int base_cs; int /*<<< orphan*/  dll_mode; } ;
struct TYPE_3__ {scalar_t__ va; } ;

/* Variables and functions */
 int CORE_CLK_SRC_DPLL ; 
 int CORE_CLK_SRC_DPLL_X2 ; 
 int M_DDR ; 
 int /*<<< orphan*/  M_LOCK ; 
 int M_LOCK_CTRL ; 
 int /*<<< orphan*/  M_UNLOCK ; 
 scalar_t__ OMAP2420_PRCM_VOLTSETUP ; 
 scalar_t__ OMAP2430_PRCM_VOLTSETUP ; 
 scalar_t__ OMAP_SDRC_REGADDR (scalar_t__) ; 
 scalar_t__ OMAP_SMS_REGADDR (scalar_t__) ; 
 scalar_t__ SDRC_DLLA_CTRL ; 
 scalar_t__ SDRC_DLLA_STATUS ; 
 scalar_t__ SDRC_DLLB_CTRL ; 
 scalar_t__ SDRC_DLLB_STATUS ; 
 scalar_t__ SDRC_MR_0 ; 
 int __ffs (int) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 scalar_t__ cpu_is_omap2420 () ; 
 scalar_t__ cpu_is_omap2422 () ; 
 int curr_perf_level ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 TYPE_2__ mem_timings ; 
 int /*<<< orphan*/  omap2_sram_ddr_init (int*,int,int,int) ; 
 int /*<<< orphan*/  omap2_sram_reprogram_sdrc (int,int,int) ; 
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

__attribute__((used)) static inline void omap_push_sram_idle(void) {}

__attribute__((used)) static u32 omap2xxx_sdrc_get_slow_dll_ctrl(void)
{
	return mem_timings.slow_dll_ctrl;
}

__attribute__((used)) static u32 omap2xxx_sdrc_get_fast_dll_ctrl(void)
{
	return mem_timings.fast_dll_ctrl;
}

__attribute__((used)) static u32 omap2xxx_sdrc_get_type(void)
{
	return mem_timings.m_type;
}

u32 omap2xxx_sdrc_dll_is_unlocked(void)
{
	/* dlla and dllb are a set */
	u32 dll_state = sdrc_read_reg(SDRC_DLLA_CTRL);

	if ((dll_state & (1 << 2)) == (1 << 2))
		return 1;
	else
		return 0;
}

u32 omap2xxx_sdrc_reprogram(u32 level, u32 force)
{
	u32 dll_ctrl, m_type;
	u32 prev = curr_perf_level;
	unsigned long flags;

	if ((curr_perf_level == level) && !force)
		return prev;

	if (level == CORE_CLK_SRC_DPLL)
		dll_ctrl = omap2xxx_sdrc_get_slow_dll_ctrl();
	else if (level == CORE_CLK_SRC_DPLL_X2)
		dll_ctrl = omap2xxx_sdrc_get_fast_dll_ctrl();
	else
		return prev;

	m_type = omap2xxx_sdrc_get_type();

	local_irq_save(flags);
	/*
	 * XXX These calls should be abstracted out through a
	 * prm2xxx.c function
	 */
	if (cpu_is_omap2420())
		writel_relaxed(0xffff, OMAP2420_PRCM_VOLTSETUP);
	else
		writel_relaxed(0xffff, OMAP2430_PRCM_VOLTSETUP);
	omap2_sram_reprogram_sdrc(level, dll_ctrl, m_type);
	curr_perf_level = level;
	local_irq_restore(flags);

	return prev;
}

void omap2xxx_sdrc_init_params(u32 force_lock_to_unlock_mode)
{
	unsigned long dll_cnt;
	u32 fast_dll = 0;

	/* DDR = 1, SDR = 0 */
	mem_timings.m_type = !((sdrc_read_reg(SDRC_MR_0) & 0x3) == 0x1);

	/* 2422 es2.05 and beyond has a single SIP DDR instead of 2 like others.
	 * In the case of 2422, its ok to use CS1 instead of CS0.
	 */
	if (cpu_is_omap2422())
		mem_timings.base_cs = 1;
	else
		mem_timings.base_cs = 0;

	if (mem_timings.m_type != M_DDR)
		return;

	/* With DDR we need to determine the low frequency DLL value */
	if (((mem_timings.fast_dll_ctrl & (1 << 2)) == M_LOCK_CTRL))
		mem_timings.dll_mode = M_UNLOCK;
	else
		mem_timings.dll_mode = M_LOCK;

	if (mem_timings.base_cs == 0) {
		fast_dll = sdrc_read_reg(SDRC_DLLA_CTRL);
		dll_cnt = sdrc_read_reg(SDRC_DLLA_STATUS) & 0xff00;
	} else {
		fast_dll = sdrc_read_reg(SDRC_DLLB_CTRL);
		dll_cnt = sdrc_read_reg(SDRC_DLLB_STATUS) & 0xff00;
	}
	if (force_lock_to_unlock_mode) {
		fast_dll &= ~0xff00;
		fast_dll |= dll_cnt;		/* Current lock mode */
	}
	/* set fast timings with DLL filter disabled */
	mem_timings.fast_dll_ctrl = (fast_dll | (3 << 8));

	/* No disruptions, DDR will be offline & C-ABI not followed */
	omap2_sram_ddr_init(&mem_timings.slow_dll_ctrl,
			    mem_timings.fast_dll_ctrl,
			    mem_timings.base_cs,
			    force_lock_to_unlock_mode);
	mem_timings.slow_dll_ctrl &= 0xff00;	/* Keep lock value */

	/* Turn status into unlock ctrl */
	mem_timings.slow_dll_ctrl |=
		((mem_timings.fast_dll_ctrl & 0xF) | (1 << 2));

	/* 90 degree phase for anything below 133MHz + disable DLL filter */
	mem_timings.slow_dll_ctrl |= ((1 << 1) | (3 << 8));
}

