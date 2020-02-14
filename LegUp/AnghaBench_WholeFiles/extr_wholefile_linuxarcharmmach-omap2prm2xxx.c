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
struct prm_reset_src_map {int reg_shift; int std_shift; } ;
struct powerdomain {int prcm_offs; } ;
struct TYPE_6__ {TYPE_1__* ptr; } ;
struct clockdomain {TYPE_2__ pwrdm; } ;
typedef  int s16 ;
struct TYPE_8__ {int va; } ;
struct TYPE_7__ {int va; } ;
struct TYPE_5__ {int prcm_offs; } ;

/* Variables and functions */
 int EINVAL ; 
 int OMAP24XX_FORCESTATE_MASK ; 
#define  OMAP24XX_PWRDM_POWER_OFF 133 
#define  OMAP24XX_PWRDM_POWER_ON 132 
#define  OMAP24XX_PWRDM_POWER_RET 131 
 int OMAP2_PM_PWSTCTRL ; 
 int OMAP2_PM_PWSTST ; 
 int OMAP2_RM_RSTCTRL ; 
 int OMAP2_RM_RSTST ; 
 int OMAP_POWERSTATEST_MASK ; 
 int OMAP_POWERSTATE_MASK ; 
 int OMAP_POWERSTATE_SHIFT ; 
 int OMAP_RST_DPLL3_MASK ; 
#define  PWRDM_POWER_OFF 130 
#define  PWRDM_POWER_ON 129 
#define  PWRDM_POWER_RET 128 
 int WKUP_MOD ; 
 int __ffs (int) ; 
 TYPE_4__ cm_base ; 
 struct prm_reset_src_map* omap2xxx_prm_reset_src_map ; 
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

__attribute__((used)) static u32 omap2xxx_prm_read_reset_sources(void)
{
	struct prm_reset_src_map *p;
	u32 r = 0;
	u32 v;

	v = omap2_prm_read_mod_reg(WKUP_MOD, OMAP2_RM_RSTST);

	p = omap2xxx_prm_reset_src_map;
	while (p->reg_shift >= 0 && p->std_shift >= 0) {
		if (v & (1 << p->reg_shift))
			r |= 1 << p->std_shift;
		p++;
	}

	return r;
}

__attribute__((used)) static int omap2xxx_pwrst_to_common_pwrst(u8 omap2xxx_pwrst)
{
	u8 pwrst;

	switch (omap2xxx_pwrst) {
	case OMAP24XX_PWRDM_POWER_OFF:
		pwrst = PWRDM_POWER_OFF;
		break;
	case OMAP24XX_PWRDM_POWER_RET:
		pwrst = PWRDM_POWER_RET;
		break;
	case OMAP24XX_PWRDM_POWER_ON:
		pwrst = PWRDM_POWER_ON;
		break;
	default:
		return -EINVAL;
	}

	return pwrst;
}

__attribute__((used)) static void omap2xxx_prm_dpll_reset(void)
{
	omap2_prm_set_mod_reg_bits(OMAP_RST_DPLL3_MASK, WKUP_MOD,
				   OMAP2_RM_RSTCTRL);
	/* OCP barrier */
	omap2_prm_read_mod_reg(WKUP_MOD, OMAP2_RM_RSTCTRL);
}

__attribute__((used)) static int omap2xxx_prm_clear_mod_irqs(s16 module, u8 regs, u32 wkst_mask)
{
	u32 wkst;

	wkst = omap2_prm_read_mod_reg(module, regs);
	wkst &= wkst_mask;
	omap2_prm_write_mod_reg(wkst, module, regs);
	return 0;
}

int omap2xxx_clkdm_sleep(struct clockdomain *clkdm)
{
	omap2_prm_set_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
				   clkdm->pwrdm.ptr->prcm_offs,
				   OMAP2_PM_PWSTCTRL);
	return 0;
}

int omap2xxx_clkdm_wakeup(struct clockdomain *clkdm)
{
	omap2_prm_clear_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
				     clkdm->pwrdm.ptr->prcm_offs,
				     OMAP2_PM_PWSTCTRL);
	return 0;
}

__attribute__((used)) static int omap2xxx_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
	u8 omap24xx_pwrst;

	switch (pwrst) {
	case PWRDM_POWER_OFF:
		omap24xx_pwrst = OMAP24XX_PWRDM_POWER_OFF;
		break;
	case PWRDM_POWER_RET:
		omap24xx_pwrst = OMAP24XX_PWRDM_POWER_RET;
		break;
	case PWRDM_POWER_ON:
		omap24xx_pwrst = OMAP24XX_PWRDM_POWER_ON;
		break;
	default:
		return -EINVAL;
	}

	omap2_prm_rmw_mod_reg_bits(OMAP_POWERSTATE_MASK,
				   (omap24xx_pwrst << OMAP_POWERSTATE_SHIFT),
				   pwrdm->prcm_offs, OMAP2_PM_PWSTCTRL);
	return 0;
}

__attribute__((used)) static int omap2xxx_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
	u8 omap2xxx_pwrst;

	omap2xxx_pwrst = omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
						       OMAP2_PM_PWSTCTRL,
						       OMAP_POWERSTATE_MASK);

	return omap2xxx_pwrst_to_common_pwrst(omap2xxx_pwrst);
}

__attribute__((used)) static int omap2xxx_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
	u8 omap2xxx_pwrst;

	omap2xxx_pwrst = omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
						       OMAP2_PM_PWSTST,
						       OMAP_POWERSTATEST_MASK);

	return omap2xxx_pwrst_to_common_pwrst(omap2xxx_pwrst);
}

