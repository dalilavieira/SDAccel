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
typedef  int u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
typedef  scalar_t__ s16 ;
struct TYPE_2__ {scalar_t__ va; } ;

/* Variables and functions */
 int EEXIST ; 
 int EINVAL ; 
 int OMAP_MEM0_ONSTATE_MASK ; 
 int OMAP_MEM0_RETSTATE_MASK ; 
 int OMAP_MEM0_STATEST_MASK ; 
 int OMAP_MEM1_ONSTATE_MASK ; 
 int OMAP_MEM1_RETSTATE_MASK ; 
 int OMAP_MEM1_STATEST_MASK ; 
 int OMAP_MEM2_ONSTATE_MASK ; 
 int OMAP_MEM2_RETSTATE_MASK ; 
 int OMAP_MEM2_STATEST_MASK ; 
 int OMAP_MEM3_ONSTATE_MASK ; 
 int OMAP_MEM3_RETSTATE_MASK ; 
 int OMAP_MEM3_STATEST_MASK ; 
 int OMAP_MEM4_ONSTATE_MASK ; 
 int OMAP_MEM4_RETSTATE_MASK ; 
 int OMAP_MEM4_STATEST_MASK ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __ffs (int) ; 
 TYPE_1__ prm_base ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

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

u32 omap2_pwrdm_get_mem_bank_onstate_mask(u8 bank)
{
	switch (bank) {
	case 0:
		return OMAP_MEM0_ONSTATE_MASK;
	case 1:
		return OMAP_MEM1_ONSTATE_MASK;
	case 2:
		return OMAP_MEM2_ONSTATE_MASK;
	case 3:
		return OMAP_MEM3_ONSTATE_MASK;
	case 4:
		return OMAP_MEM4_ONSTATE_MASK;
	default:
		WARN_ON(1); /* should never happen */
		return -EEXIST;
	}
	return 0;
}

u32 omap2_pwrdm_get_mem_bank_retst_mask(u8 bank)
{
	switch (bank) {
	case 0:
		return OMAP_MEM0_RETSTATE_MASK;
	case 1:
		return OMAP_MEM1_RETSTATE_MASK;
	case 2:
		return OMAP_MEM2_RETSTATE_MASK;
	case 3:
		return OMAP_MEM3_RETSTATE_MASK;
	case 4:
		return OMAP_MEM4_RETSTATE_MASK;
	default:
		WARN_ON(1); /* should never happen */
		return -EEXIST;
	}
	return 0;
}

u32 omap2_pwrdm_get_mem_bank_stst_mask(u8 bank)
{
	switch (bank) {
	case 0:
		return OMAP_MEM0_STATEST_MASK;
	case 1:
		return OMAP_MEM1_STATEST_MASK;
	case 2:
		return OMAP_MEM2_STATEST_MASK;
	case 3:
		return OMAP_MEM3_STATEST_MASK;
	case 4:
		return OMAP_MEM4_STATEST_MASK;
	default:
		WARN_ON(1); /* should never happen */
		return -EEXIST;
	}
	return 0;
}

