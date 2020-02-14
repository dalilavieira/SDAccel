#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_6__ {TYPE_1__* ptr; } ;
struct clockdomain {int clktrctrl_mask; int flags; TYPE_2__ pwrdm; } ;
struct clk_omap_reg {int offset; } ;
typedef  int s16 ;
struct TYPE_8__ {int va; } ;
struct TYPE_7__ {int va; } ;
struct TYPE_5__ {int prcm_offs; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int CLKDM_CAN_FORCE_SLEEP ; 
 int CLKDM_CAN_FORCE_WAKEUP ; 
 int CM_AUTOIDLE ; 
 int CM_CLKEN ; 
 int CM_CLKSEL ; 
 int CM_CLKSEL1 ; 
 int CM_CLKSEL2 ; 
 int CM_FCLKEN1 ; 
 int CORE_MOD ; 
 int DPLL_AUTOIDLE_DISABLE ; 
 int EBUSY ; 
 int EINVAL ; 
 int EN_APLL_LOCKED ; 
 int GFX_MOD ; 
 int MAX_MODULE_READY_TIME ; 
 int MPU_MOD ; 
 int OMAP2420_EN_MMC_MASK ; 
 int OMAP2430_MDM_MOD ; 
 int OMAP24XX_AUTO_54M_MASK ; 
 int OMAP24XX_AUTO_96M_MASK ; 
 int OMAP24XX_AUTO_DPLL_MASK ; 
 int OMAP24XX_AUTO_DPLL_SHIFT ; 
 int OMAP24XX_CLKSEL_DSS2_MASK ; 
 int OMAP24XX_CLKSTCTRL_DISABLE_AUTO ; 
 int OMAP24XX_CLKSTCTRL_ENABLE_AUTO ; 
 int OMAP24XX_CM_FCLKEN2 ; 
 int OMAP24XX_CORE_CLK_SRC_MASK ; 
 int OMAP24XX_DSP_MOD ; 
 int OMAP24XX_EN_54M_PLL_SHIFT ; 
 int OMAP24XX_EN_96M_PLL_SHIFT ; 
 int OMAP24XX_EN_DSS1_MASK ; 
 int OMAP24XX_EN_MCSPI1_MASK ; 
 int OMAP24XX_EN_MCSPI2_MASK ; 
 int OMAP24XX_EN_UART1_MASK ; 
 int OMAP24XX_EN_UART2_MASK ; 
 int OMAP24XX_EN_UART3_MASK ; 
 int OMAP24XX_ST_54M_APLL_SHIFT ; 
 int OMAP24XX_ST_96M_APLL_SHIFT ; 
 int OMAP2XXX_APLL_AUTOIDLE_DISABLE ; 
 int OMAP2XXX_APLL_AUTOIDLE_LOW_POWER_STOP ; 
 int OMAP2XXX_DPLL_AUTOIDLE_LOW_POWER_STOP ; 
 int OMAP2_CM_CLKSTCTRL ; 
 int PLL_MOD ; 
 int __ffs (int) ; 
 TYPE_4__ cm_base ; 
 int /*<<< orphan*/  omap2xxx_clkdm_sleep (struct clockdomain*) ; 
 int /*<<< orphan*/  omap2xxx_clkdm_wakeup (struct clockdomain*) ; 
 int* omap2xxx_cm_idlest_offs ; 
 int omap2xxx_cm_wait_module_ready (int,int,int,int) ; 
 int /*<<< orphan*/  omap_test_timeout (int,int,int) ; 
 TYPE_3__ prm_base ; 
 int readl_relaxed (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,int) ; 

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

__attribute__((used)) static void _write_clktrctrl(u8 c, s16 module, u32 mask)
{
	u32 v;

	v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
	v &= ~mask;
	v |= c << __ffs(mask);
	omap2_cm_write_mod_reg(v, module, OMAP2_CM_CLKSTCTRL);
}

__attribute__((used)) static bool omap2xxx_cm_is_clkdm_in_hwsup(s16 module, u32 mask)
{
	u32 v;

	v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
	v &= mask;
	v >>= __ffs(mask);

	return (v == OMAP24XX_CLKSTCTRL_ENABLE_AUTO) ? 1 : 0;
}

__attribute__((used)) static void omap2xxx_cm_clkdm_enable_hwsup(s16 module, u32 mask)
{
	_write_clktrctrl(OMAP24XX_CLKSTCTRL_ENABLE_AUTO, module, mask);
}

__attribute__((used)) static void omap2xxx_cm_clkdm_disable_hwsup(s16 module, u32 mask)
{
	_write_clktrctrl(OMAP24XX_CLKSTCTRL_DISABLE_AUTO, module, mask);
}

__attribute__((used)) static void _omap2xxx_set_dpll_autoidle(u8 m)
{
	u32 v;

	v = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
	v &= ~OMAP24XX_AUTO_DPLL_MASK;
	v |= m << OMAP24XX_AUTO_DPLL_SHIFT;
	omap2_cm_write_mod_reg(v, PLL_MOD, CM_AUTOIDLE);
}

void omap2xxx_cm_set_dpll_disable_autoidle(void)
{
	_omap2xxx_set_dpll_autoidle(OMAP2XXX_DPLL_AUTOIDLE_LOW_POWER_STOP);
}

void omap2xxx_cm_set_dpll_auto_low_power_stop(void)
{
	_omap2xxx_set_dpll_autoidle(DPLL_AUTOIDLE_DISABLE);
}

__attribute__((used)) static void _omap2xxx_set_apll_autoidle(u8 m, u32 mask)
{
	u32 v;

	v = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
	v &= ~mask;
	v |= m << __ffs(mask);
	omap2_cm_write_mod_reg(v, PLL_MOD, CM_AUTOIDLE);
}

void omap2xxx_cm_set_apll54_disable_autoidle(void)
{
	_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_LOW_POWER_STOP,
				    OMAP24XX_AUTO_54M_MASK);
}

void omap2xxx_cm_set_apll54_auto_low_power_stop(void)
{
	_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_DISABLE,
				    OMAP24XX_AUTO_54M_MASK);
}

void omap2xxx_cm_set_apll96_disable_autoidle(void)
{
	_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_LOW_POWER_STOP,
				    OMAP24XX_AUTO_96M_MASK);
}

void omap2xxx_cm_set_apll96_auto_low_power_stop(void)
{
	_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_DISABLE,
				    OMAP24XX_AUTO_96M_MASK);
}

__attribute__((used)) static int _omap2xxx_apll_enable(u8 enable_bit, u8 status_bit)
{
	u32 v, m;

	m = EN_APLL_LOCKED << enable_bit;

	v = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
	if (v & m)
		return 0;   /* apll already enabled */

	v |= m;
	omap2_cm_write_mod_reg(v, PLL_MOD, CM_CLKEN);

	omap2xxx_cm_wait_module_ready(0, PLL_MOD, 1, status_bit);

	/*
	 * REVISIT: Should we return an error code if
	 * omap2xxx_cm_wait_module_ready() fails?
	 */
	return 0;
}

__attribute__((used)) static void _omap2xxx_apll_disable(u8 enable_bit)
{
	u32 v;

	v = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
	v &= ~(EN_APLL_LOCKED << enable_bit);
	omap2_cm_write_mod_reg(v, PLL_MOD, CM_CLKEN);
}

int omap2xxx_cm_apll54_enable(void)
{
	return _omap2xxx_apll_enable(OMAP24XX_EN_54M_PLL_SHIFT,
				     OMAP24XX_ST_54M_APLL_SHIFT);
}

int omap2xxx_cm_apll96_enable(void)
{
	return _omap2xxx_apll_enable(OMAP24XX_EN_96M_PLL_SHIFT,
				     OMAP24XX_ST_96M_APLL_SHIFT);
}

void omap2xxx_cm_apll54_disable(void)
{
	_omap2xxx_apll_disable(OMAP24XX_EN_54M_PLL_SHIFT);
}

void omap2xxx_cm_apll96_disable(void)
{
	_omap2xxx_apll_disable(OMAP24XX_EN_96M_PLL_SHIFT);
}

__attribute__((used)) static int omap2xxx_cm_split_idlest_reg(struct clk_omap_reg *idlest_reg,
					s16 *prcm_inst,
					u8 *idlest_reg_id)
{
	unsigned long offs;
	u8 idlest_offs;
	int i;

	idlest_offs = idlest_reg->offset & 0xff;
	for (i = 0; i < ARRAY_SIZE(omap2xxx_cm_idlest_offs); i++) {
		if (idlest_offs == omap2xxx_cm_idlest_offs[i]) {
			*idlest_reg_id = i + 1;
			break;
		}
	}

	if (i == ARRAY_SIZE(omap2xxx_cm_idlest_offs))
		return -EINVAL;

	offs = idlest_reg->offset;
	offs &= 0xff00;
	*prcm_inst = offs;

	return 0;
}

int omap2xxx_cm_wait_module_ready(u8 part, s16 prcm_mod, u16 idlest_id,
				  u8 idlest_shift)
{
	int ena = 0, i = 0;
	u8 cm_idlest_reg;
	u32 mask;

	if (!idlest_id || (idlest_id > ARRAY_SIZE(omap2xxx_cm_idlest_offs)))
		return -EINVAL;

	cm_idlest_reg = omap2xxx_cm_idlest_offs[idlest_id - 1];

	mask = 1 << idlest_shift;
	ena = mask;

	omap_test_timeout(((omap2_cm_read_mod_reg(prcm_mod, cm_idlest_reg) &
			    mask) == ena), MAX_MODULE_READY_TIME, i);

	return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}

__attribute__((used)) static void omap2xxx_clkdm_allow_idle(struct clockdomain *clkdm)
{
	omap2xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
				       clkdm->clktrctrl_mask);
}

__attribute__((used)) static void omap2xxx_clkdm_deny_idle(struct clockdomain *clkdm)
{
	omap2xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					clkdm->clktrctrl_mask);
}

__attribute__((used)) static int omap2xxx_clkdm_clk_enable(struct clockdomain *clkdm)
{
	bool hwsup = false;

	if (!clkdm->clktrctrl_mask)
		return 0;

	hwsup = omap2xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					      clkdm->clktrctrl_mask);
	if (!hwsup && clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
		omap2xxx_clkdm_wakeup(clkdm);

	return 0;
}

__attribute__((used)) static int omap2xxx_clkdm_clk_disable(struct clockdomain *clkdm)
{
	bool hwsup = false;

	if (!clkdm->clktrctrl_mask)
		return 0;

	hwsup = omap2xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					      clkdm->clktrctrl_mask);

	if (!hwsup && clkdm->flags & CLKDM_CAN_FORCE_SLEEP)
		omap2xxx_clkdm_sleep(clkdm);

	return 0;
}

int omap2xxx_cm_fclks_active(void)
{
	u32 f1, f2;

	f1 = omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
	f2 = omap2_cm_read_mod_reg(CORE_MOD, OMAP24XX_CM_FCLKEN2);

	return (f1 | f2) ? 1 : 0;
}

int omap2xxx_cm_mpu_retention_allowed(void)
{
	u32 l;

	/* Check for MMC, UART2, UART1, McSPI2, McSPI1 and DSS1. */
	l = omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
	if (l & (OMAP2420_EN_MMC_MASK | OMAP24XX_EN_UART2_MASK |
		 OMAP24XX_EN_UART1_MASK | OMAP24XX_EN_MCSPI2_MASK |
		 OMAP24XX_EN_MCSPI1_MASK | OMAP24XX_EN_DSS1_MASK))
		return 0;
	/* Check for UART3. */
	l = omap2_cm_read_mod_reg(CORE_MOD, OMAP24XX_CM_FCLKEN2);
	if (l & OMAP24XX_EN_UART3_MASK)
		return 0;

	return 1;
}

u32 omap2xxx_cm_get_core_clk_src(void)
{
	u32 v;

	v = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKSEL2);
	v &= OMAP24XX_CORE_CLK_SRC_MASK;

	return v;
}

u32 omap2xxx_cm_get_core_pll_config(void)
{
	return omap2_cm_read_mod_reg(PLL_MOD, CM_CLKSEL2);
}

void omap2xxx_cm_set_mod_dividers(u32 mpu, u32 dsp, u32 gfx, u32 core, u32 mdm)
{
	u32 tmp;

	omap2_cm_write_mod_reg(mpu, MPU_MOD, CM_CLKSEL);
	omap2_cm_write_mod_reg(dsp, OMAP24XX_DSP_MOD, CM_CLKSEL);
	omap2_cm_write_mod_reg(gfx, GFX_MOD, CM_CLKSEL);
	tmp = omap2_cm_read_mod_reg(CORE_MOD, CM_CLKSEL1) &
		OMAP24XX_CLKSEL_DSS2_MASK;
	omap2_cm_write_mod_reg(core | tmp, CORE_MOD, CM_CLKSEL1);
	if (mdm)
		omap2_cm_write_mod_reg(mdm, OMAP2430_MDM_MOD, CM_CLKSEL);
}

