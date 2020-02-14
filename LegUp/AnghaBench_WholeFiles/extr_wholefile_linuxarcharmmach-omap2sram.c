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
typedef  scalar_t__ u16 ;
typedef  scalar_t__ s16 ;
struct TYPE_2__ {scalar_t__ va; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 scalar_t__ OMAP24XX_VA_READPERM0 ; 
 scalar_t__ OMAP24XX_VA_REQINFOPERM0 ; 
 scalar_t__ OMAP24XX_VA_WRITEPERM0 ; 
 scalar_t__ OMAP2_DEVICE_TYPE_GP ; 
 scalar_t__ OMAP34XX_VA_ADDR_MATCH2 ; 
 scalar_t__ OMAP34XX_VA_READPERM0 ; 
 scalar_t__ OMAP34XX_VA_REQINFOPERM0 ; 
 scalar_t__ OMAP34XX_VA_SMS_RG_ATT0 ; 
 scalar_t__ OMAP34XX_VA_WRITEPERM0 ; 
 scalar_t__ OMAP_SDRC_REGADDR (scalar_t__) ; 
 scalar_t__ OMAP_SMS_REGADDR (scalar_t__) ; 
 int __ffs (int) ; 
 int _omap2_set_prcm (int,int,int) ; 
 int /*<<< orphan*/  _omap2_sram_ddr_init (int*,int,int,int) ; 
 int /*<<< orphan*/  _omap2_sram_reprogram_sdrc (int,int,int) ; 
 scalar_t__ cpu_is_omap242x () ; 
 scalar_t__ cpu_is_omap34xx () ; 
 scalar_t__ omap_rev () ; 
 scalar_t__ omap_type () ; 
 TYPE_1__ prm_base ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline int soc_is_omap(void)
{
	return omap_rev() != 0;
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

__attribute__((used)) static int is_sram_locked(void)
{
	if (OMAP2_DEVICE_TYPE_GP == omap_type()) {
		/* RAMFW: R/W access to all initiators for all qualifier sets */
		if (cpu_is_omap242x()) {
			writel_relaxed(0xFF, OMAP24XX_VA_REQINFOPERM0); /* all q-vects */
			writel_relaxed(0xCFDE, OMAP24XX_VA_READPERM0);  /* all i-read */
			writel_relaxed(0xCFDE, OMAP24XX_VA_WRITEPERM0); /* all i-write */
		}
		if (cpu_is_omap34xx()) {
			writel_relaxed(0xFFFF, OMAP34XX_VA_REQINFOPERM0); /* all q-vects */
			writel_relaxed(0xFFFF, OMAP34XX_VA_READPERM0);  /* all i-read */
			writel_relaxed(0xFFFF, OMAP34XX_VA_WRITEPERM0); /* all i-write */
			writel_relaxed(0x0, OMAP34XX_VA_ADDR_MATCH2);
			writel_relaxed(0xFFFFFFFF, OMAP34XX_VA_SMS_RG_ATT0);
		}
		return 0;
	} else
		return 1; /* assume locked with no PPA or security driver */
}

void omap2_sram_ddr_init(u32 *slow_dll_ctrl, u32 fast_dll_ctrl,
		   u32 base_cs, u32 force_unlock)
{
	BUG_ON(!_omap2_sram_ddr_init);
	_omap2_sram_ddr_init(slow_dll_ctrl, fast_dll_ctrl,
			     base_cs, force_unlock);
}

void omap2_sram_reprogram_sdrc(u32 perf_level, u32 dll_val, u32 mem_type)
{
	BUG_ON(!_omap2_sram_reprogram_sdrc);
	_omap2_sram_reprogram_sdrc(perf_level, dll_val, mem_type);
}

u32 omap2_set_prcm(u32 dpll_ctrl_val, u32 sdrc_rfr_val, int bypass)
{
	BUG_ON(!_omap2_set_prcm);
	return _omap2_set_prcm(dpll_ctrl_val, sdrc_rfr_val, bypass);
}

__attribute__((used)) static inline int omap242x_sram_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap243x_sram_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap34xx_sram_init(void)
{
	return 0;
}

