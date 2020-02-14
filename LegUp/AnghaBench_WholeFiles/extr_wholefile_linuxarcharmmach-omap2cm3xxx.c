#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_9__ {TYPE_2__* ptr; } ;
struct clockdomain {int dep_bit; int clktrctrl_mask; scalar_t__ usecount; int flags; TYPE_3__ pwrdm; struct clkdm_dep* sleepdep_srcs; } ;
struct clkdm_dep {scalar_t__ sleepdep_usecount; TYPE_1__* clkdm; scalar_t__ clkdm_name; } ;
struct clk_omap_reg {int offset; } ;
typedef  int s16 ;
struct TYPE_12__ {int va; } ;
struct TYPE_11__ {int iva2_cm_clksel1; int iva2_cm_clksel2; int cm_sysconfig; int sgx_cm_clksel; int dss_cm_clksel; int cam_cm_clksel; int per_cm_clksel; int emu_cm_clksel; int emu_cm_clkstctrl; int pll_cm_autoidle; int pll_cm_autoidle2; int pll_cm_clksel4; int pll_cm_clksel5; int pll_cm_clken2; int cm_polctrl; int iva2_cm_fclken; int iva2_cm_clken_pll; int core_cm_fclken1; int core_cm_fclken3; int sgx_cm_fclken; int wkup_cm_fclken; int dss_cm_fclken; int cam_cm_fclken; int per_cm_fclken; int usbhost_cm_fclken; int core_cm_iclken1; int core_cm_iclken2; int core_cm_iclken3; int sgx_cm_iclken; int wkup_cm_iclken; int dss_cm_iclken; int cam_cm_iclken; int per_cm_iclken; int usbhost_cm_iclken; int iva2_cm_autoidle2; int mpu_cm_autoidle2; int iva2_cm_clkstctrl; int mpu_cm_clkstctrl; int core_cm_clkstctrl; int sgx_cm_clkstctrl; int dss_cm_clkstctrl; int cam_cm_clkstctrl; int per_cm_clkstctrl; int neon_cm_clkstctrl; int usbhost_cm_clkstctrl; int core_cm_autoidle1; int core_cm_autoidle2; int core_cm_autoidle3; int wkup_cm_autoidle; int dss_cm_autoidle; int cam_cm_autoidle; int per_cm_autoidle; int usbhost_cm_autoidle; int sgx_cm_sleepdep; int dss_cm_sleepdep; int cam_cm_sleepdep; int per_cm_sleepdep; int usbhost_cm_sleepdep; int cm_clkout_ctrl; } ;
struct TYPE_10__ {int va; } ;
struct TYPE_8__ {int prcm_offs; } ;
struct TYPE_7__ {int dep_bit; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int CLKDM_CAN_FORCE_SLEEP ; 
 int CLKDM_CAN_FORCE_WAKEUP ; 
 int CLKDM_MISSING_IDLE_REPORTING ; 
 int CM_AUTOIDLE ; 
 int CM_AUTOIDLE1 ; 
 int CM_AUTOIDLE2 ; 
 int CM_AUTOIDLE3 ; 
 int CM_CLKEN ; 
 int CM_CLKSEL ; 
 int CM_CLKSEL1 ; 
 int CM_CLKSEL2 ; 
 int CM_FCLKEN ; 
 int CM_FCLKEN1 ; 
 int CM_ICLKEN ; 
 int CM_ICLKEN1 ; 
 int CM_ICLKEN2 ; 
 int CM_ICLKEN3 ; 
 int CORE_MOD ; 
 int EBUSY ; 
 int EINVAL ; 
 int MAX_MODULE_READY_TIME ; 
 int MPU_MOD ; 
 int OCP_MOD ; 
 int OMAP2_CM_CLKSTCTRL ; 
 int OMAP3430ES2_CM_CLKEN2 ; 
 int OMAP3430ES2_CM_CLKSEL4 ; 
 int OMAP3430ES2_CM_CLKSEL5 ; 
 int OMAP3430ES2_CM_FCLKEN3 ; 
 int OMAP3430ES2_SGX_MOD ; 
 int OMAP3430ES2_USBHOST_MOD ; 
 int OMAP3430_AUTO_PERIPH_DPLL_MASK ; 
 int OMAP3430_CAM_MOD ; 
 int OMAP3430_CCR_MOD ; 
 int OMAP3430_CM_AUTOIDLE_PLL ; 
 int OMAP3430_CM_CLKEN_PLL ; 
 int OMAP3430_CM_CLKSEL1_PLL ; 
 int OMAP3430_CM_CLKSEL2_PLL ; 
 int OMAP3430_CM_CLKSEL3 ; 
 int OMAP3430_CM_POLCTRL ; 
 int OMAP3430_CM_SLEEPDEP ; 
 int OMAP3430_CM_SYSCONFIG ; 
 int OMAP3430_DSS_MOD ; 
 int OMAP3430_EMU_MOD ; 
 int OMAP3430_IVA2_MOD ; 
 int OMAP3430_NEON_MOD ; 
 int OMAP3430_PER_MOD ; 
 int OMAP34XX_CLKSTCTRL_DISABLE_AUTO ; 
 int OMAP34XX_CLKSTCTRL_ENABLE_AUTO ; 
 int OMAP34XX_CLKSTCTRL_FORCE_SLEEP ; 
 int OMAP34XX_CLKSTCTRL_FORCE_WAKEUP ; 
 int OMAP3_CM_CLKOUT_CTRL_OFFSET ; 
 int PLL_MOD ; 
 int WKUP_MOD ; 
 int __ffs (int) ; 
 int /*<<< orphan*/  clkdm_add_autodeps (struct clockdomain*) ; 
 int /*<<< orphan*/  clkdm_del_autodeps (struct clockdomain*) ; 
 TYPE_6__ cm_base ; 
 TYPE_5__ cm_context ; 
 int* omap3xxx_cm_idlest_offs ; 
 int /*<<< orphan*/  omap_test_timeout (int,int,int) ; 
 TYPE_4__ prm_base ; 
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

__attribute__((used)) static bool omap3xxx_cm_is_clkdm_in_hwsup(s16 module, u32 mask)
{
	u32 v;

	v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
	v &= mask;
	v >>= __ffs(mask);

	return (v == OMAP34XX_CLKSTCTRL_ENABLE_AUTO) ? 1 : 0;
}

__attribute__((used)) static void omap3xxx_cm_clkdm_enable_hwsup(s16 module, u32 mask)
{
	_write_clktrctrl(OMAP34XX_CLKSTCTRL_ENABLE_AUTO, module, mask);
}

__attribute__((used)) static void omap3xxx_cm_clkdm_disable_hwsup(s16 module, u32 mask)
{
	_write_clktrctrl(OMAP34XX_CLKSTCTRL_DISABLE_AUTO, module, mask);
}

__attribute__((used)) static void omap3xxx_cm_clkdm_force_sleep(s16 module, u32 mask)
{
	_write_clktrctrl(OMAP34XX_CLKSTCTRL_FORCE_SLEEP, module, mask);
}

__attribute__((used)) static void omap3xxx_cm_clkdm_force_wakeup(s16 module, u32 mask)
{
	_write_clktrctrl(OMAP34XX_CLKSTCTRL_FORCE_WAKEUP, module, mask);
}

__attribute__((used)) static int omap3xxx_cm_wait_module_ready(u8 part, s16 prcm_mod, u16 idlest_id,
					 u8 idlest_shift)
{
	int ena = 0, i = 0;
	u8 cm_idlest_reg;
	u32 mask;

	if (!idlest_id || (idlest_id > ARRAY_SIZE(omap3xxx_cm_idlest_offs)))
		return -EINVAL;

	cm_idlest_reg = omap3xxx_cm_idlest_offs[idlest_id - 1];

	mask = 1 << idlest_shift;
	ena = 0;

	omap_test_timeout(((omap2_cm_read_mod_reg(prcm_mod, cm_idlest_reg) &
			    mask) == ena), MAX_MODULE_READY_TIME, i);

	return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}

__attribute__((used)) static int omap3xxx_cm_split_idlest_reg(struct clk_omap_reg *idlest_reg,
					s16 *prcm_inst,
					u8 *idlest_reg_id)
{
	unsigned long offs;
	u8 idlest_offs;
	int i;

	idlest_offs = idlest_reg->offset & 0xff;
	for (i = 0; i < ARRAY_SIZE(omap3xxx_cm_idlest_offs); i++) {
		if (idlest_offs == omap3xxx_cm_idlest_offs[i]) {
			*idlest_reg_id = i + 1;
			break;
		}
	}

	if (i == ARRAY_SIZE(omap3xxx_cm_idlest_offs))
		return -EINVAL;

	offs = idlest_reg->offset;
	offs &= 0xff00;
	*prcm_inst = offs;

	return 0;
}

__attribute__((used)) static int omap3xxx_clkdm_add_sleepdep(struct clockdomain *clkdm1,
				       struct clockdomain *clkdm2)
{
	omap2_cm_set_mod_reg_bits((1 << clkdm2->dep_bit),
				  clkdm1->pwrdm.ptr->prcm_offs,
				  OMAP3430_CM_SLEEPDEP);
	return 0;
}

__attribute__((used)) static int omap3xxx_clkdm_del_sleepdep(struct clockdomain *clkdm1,
				       struct clockdomain *clkdm2)
{
	omap2_cm_clear_mod_reg_bits((1 << clkdm2->dep_bit),
				    clkdm1->pwrdm.ptr->prcm_offs,
				    OMAP3430_CM_SLEEPDEP);
	return 0;
}

__attribute__((used)) static int omap3xxx_clkdm_read_sleepdep(struct clockdomain *clkdm1,
					struct clockdomain *clkdm2)
{
	return omap2_cm_read_mod_bits_shift(clkdm1->pwrdm.ptr->prcm_offs,
					    OMAP3430_CM_SLEEPDEP,
					    (1 << clkdm2->dep_bit));
}

__attribute__((used)) static int omap3xxx_clkdm_clear_all_sleepdeps(struct clockdomain *clkdm)
{
	struct clkdm_dep *cd;
	u32 mask = 0;

	for (cd = clkdm->sleepdep_srcs; cd && cd->clkdm_name; cd++) {
		if (!cd->clkdm)
			continue; /* only happens if data is erroneous */

		mask |= 1 << cd->clkdm->dep_bit;
		cd->sleepdep_usecount = 0;
	}
	omap2_cm_clear_mod_reg_bits(mask, clkdm->pwrdm.ptr->prcm_offs,
				    OMAP3430_CM_SLEEPDEP);
	return 0;
}

__attribute__((used)) static int omap3xxx_clkdm_sleep(struct clockdomain *clkdm)
{
	omap3xxx_cm_clkdm_force_sleep(clkdm->pwrdm.ptr->prcm_offs,
				      clkdm->clktrctrl_mask);
	return 0;
}

__attribute__((used)) static int omap3xxx_clkdm_wakeup(struct clockdomain *clkdm)
{
	omap3xxx_cm_clkdm_force_wakeup(clkdm->pwrdm.ptr->prcm_offs,
				       clkdm->clktrctrl_mask);
	return 0;
}

__attribute__((used)) static void omap3xxx_clkdm_allow_idle(struct clockdomain *clkdm)
{
	if (clkdm->usecount > 0)
		clkdm_add_autodeps(clkdm);

	omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
				       clkdm->clktrctrl_mask);
}

__attribute__((used)) static void omap3xxx_clkdm_deny_idle(struct clockdomain *clkdm)
{
	omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					clkdm->clktrctrl_mask);

	if (clkdm->usecount > 0)
		clkdm_del_autodeps(clkdm);
}

__attribute__((used)) static int omap3xxx_clkdm_clk_enable(struct clockdomain *clkdm)
{
	bool hwsup = false;

	if (!clkdm->clktrctrl_mask)
		return 0;

	/*
	 * The CLKDM_MISSING_IDLE_REPORTING flag documentation has
	 * more details on the unpleasant problem this is working
	 * around
	 */
	if ((clkdm->flags & CLKDM_MISSING_IDLE_REPORTING) &&
	    (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)) {
		omap3xxx_clkdm_wakeup(clkdm);
		return 0;
	}

	hwsup = omap3xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					      clkdm->clktrctrl_mask);

	if (hwsup) {
		/* Disable HW transitions when we are changing deps */
		omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
						clkdm->clktrctrl_mask);
		clkdm_add_autodeps(clkdm);
		omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					       clkdm->clktrctrl_mask);
	} else {
		if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
			omap3xxx_clkdm_wakeup(clkdm);
	}

	return 0;
}

__attribute__((used)) static int omap3xxx_clkdm_clk_disable(struct clockdomain *clkdm)
{
	bool hwsup = false;

	if (!clkdm->clktrctrl_mask)
		return 0;

	/*
	 * The CLKDM_MISSING_IDLE_REPORTING flag documentation has
	 * more details on the unpleasant problem this is working
	 * around
	 */
	if (clkdm->flags & CLKDM_MISSING_IDLE_REPORTING &&
	    !(clkdm->flags & CLKDM_CAN_FORCE_SLEEP)) {
		omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					       clkdm->clktrctrl_mask);
		return 0;
	}

	hwsup = omap3xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					      clkdm->clktrctrl_mask);

	if (hwsup) {
		/* Disable HW transitions when we are changing deps */
		omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
						clkdm->clktrctrl_mask);
		clkdm_del_autodeps(clkdm);
		omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
					       clkdm->clktrctrl_mask);
	} else {
		if (clkdm->flags & CLKDM_CAN_FORCE_SLEEP)
			omap3xxx_clkdm_sleep(clkdm);
	}

	return 0;
}

void omap3_cm_save_context(void)
{
	cm_context.iva2_cm_clksel1 =
		omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_CLKSEL1);
	cm_context.iva2_cm_clksel2 =
		omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_CLKSEL2);
	cm_context.cm_sysconfig =
		omap2_cm_read_mod_reg(OCP_MOD, OMAP3430_CM_SYSCONFIG);
	cm_context.sgx_cm_clksel =
		omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, CM_CLKSEL);
	cm_context.dss_cm_clksel =
		omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_CLKSEL);
	cm_context.cam_cm_clksel =
		omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_CLKSEL);
	cm_context.per_cm_clksel =
		omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_CLKSEL);
	cm_context.emu_cm_clksel =
		omap2_cm_read_mod_reg(OMAP3430_EMU_MOD, CM_CLKSEL1);
	cm_context.emu_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430_EMU_MOD, OMAP2_CM_CLKSTCTRL);
	/*
	 * As per erratum i671, ROM code does not respect the PER DPLL
	 * programming scheme if CM_AUTOIDLE_PLL.AUTO_PERIPH_DPLL == 1.
	 * In this case, even though this register has been saved in
	 * scratchpad contents, we need to restore AUTO_PERIPH_DPLL
	 * by ourselves. So, we need to save it anyway.
	 */
	cm_context.pll_cm_autoidle =
		omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
	cm_context.pll_cm_autoidle2 =
		omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE2);
	cm_context.pll_cm_clksel4 =
		omap2_cm_read_mod_reg(PLL_MOD, OMAP3430ES2_CM_CLKSEL4);
	cm_context.pll_cm_clksel5 =
		omap2_cm_read_mod_reg(PLL_MOD, OMAP3430ES2_CM_CLKSEL5);
	cm_context.pll_cm_clken2 =
		omap2_cm_read_mod_reg(PLL_MOD, OMAP3430ES2_CM_CLKEN2);
	cm_context.cm_polctrl =
		omap2_cm_read_mod_reg(OCP_MOD, OMAP3430_CM_POLCTRL);
	cm_context.iva2_cm_fclken =
		omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_FCLKEN);
	cm_context.iva2_cm_clken_pll =
		omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, OMAP3430_CM_CLKEN_PLL);
	cm_context.core_cm_fclken1 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
	cm_context.core_cm_fclken3 =
		omap2_cm_read_mod_reg(CORE_MOD, OMAP3430ES2_CM_FCLKEN3);
	cm_context.sgx_cm_fclken =
		omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, CM_FCLKEN);
	cm_context.wkup_cm_fclken =
		omap2_cm_read_mod_reg(WKUP_MOD, CM_FCLKEN);
	cm_context.dss_cm_fclken =
		omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_FCLKEN);
	cm_context.cam_cm_fclken =
		omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_FCLKEN);
	cm_context.per_cm_fclken =
		omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_FCLKEN);
	cm_context.usbhost_cm_fclken =
		omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD, CM_FCLKEN);
	cm_context.core_cm_iclken1 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_ICLKEN1);
	cm_context.core_cm_iclken2 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_ICLKEN2);
	cm_context.core_cm_iclken3 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_ICLKEN3);
	cm_context.sgx_cm_iclken =
		omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, CM_ICLKEN);
	cm_context.wkup_cm_iclken =
		omap2_cm_read_mod_reg(WKUP_MOD, CM_ICLKEN);
	cm_context.dss_cm_iclken =
		omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_ICLKEN);
	cm_context.cam_cm_iclken =
		omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_ICLKEN);
	cm_context.per_cm_iclken =
		omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_ICLKEN);
	cm_context.usbhost_cm_iclken =
		omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD, CM_ICLKEN);
	cm_context.iva2_cm_autoidle2 =
		omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_AUTOIDLE2);
	cm_context.mpu_cm_autoidle2 =
		omap2_cm_read_mod_reg(MPU_MOD, CM_AUTOIDLE2);
	cm_context.iva2_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.mpu_cm_clkstctrl =
		omap2_cm_read_mod_reg(MPU_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.core_cm_clkstctrl =
		omap2_cm_read_mod_reg(CORE_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.sgx_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.dss_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.cam_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.per_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430_PER_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.neon_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430_NEON_MOD, OMAP2_CM_CLKSTCTRL);
	cm_context.usbhost_cm_clkstctrl =
		omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD,
				      OMAP2_CM_CLKSTCTRL);
	cm_context.core_cm_autoidle1 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_AUTOIDLE1);
	cm_context.core_cm_autoidle2 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_AUTOIDLE2);
	cm_context.core_cm_autoidle3 =
		omap2_cm_read_mod_reg(CORE_MOD, CM_AUTOIDLE3);
	cm_context.wkup_cm_autoidle =
		omap2_cm_read_mod_reg(WKUP_MOD, CM_AUTOIDLE);
	cm_context.dss_cm_autoidle =
		omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_AUTOIDLE);
	cm_context.cam_cm_autoidle =
		omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_AUTOIDLE);
	cm_context.per_cm_autoidle =
		omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_AUTOIDLE);
	cm_context.usbhost_cm_autoidle =
		omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD, CM_AUTOIDLE);
	cm_context.sgx_cm_sleepdep =
		omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD,
				      OMAP3430_CM_SLEEPDEP);
	cm_context.dss_cm_sleepdep =
		omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, OMAP3430_CM_SLEEPDEP);
	cm_context.cam_cm_sleepdep =
		omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, OMAP3430_CM_SLEEPDEP);
	cm_context.per_cm_sleepdep =
		omap2_cm_read_mod_reg(OMAP3430_PER_MOD, OMAP3430_CM_SLEEPDEP);
	cm_context.usbhost_cm_sleepdep =
		omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD,
				      OMAP3430_CM_SLEEPDEP);
	cm_context.cm_clkout_ctrl =
		omap2_cm_read_mod_reg(OMAP3430_CCR_MOD,
				      OMAP3_CM_CLKOUT_CTRL_OFFSET);
}

void omap3_cm_restore_context(void)
{
	omap2_cm_write_mod_reg(cm_context.iva2_cm_clksel1, OMAP3430_IVA2_MOD,
			       CM_CLKSEL1);
	omap2_cm_write_mod_reg(cm_context.iva2_cm_clksel2, OMAP3430_IVA2_MOD,
			       CM_CLKSEL2);
	omap2_cm_write_mod_reg(cm_context.cm_sysconfig, OCP_MOD,
			       OMAP3430_CM_SYSCONFIG);
	omap2_cm_write_mod_reg(cm_context.sgx_cm_clksel, OMAP3430ES2_SGX_MOD,
			       CM_CLKSEL);
	omap2_cm_write_mod_reg(cm_context.dss_cm_clksel, OMAP3430_DSS_MOD,
			       CM_CLKSEL);
	omap2_cm_write_mod_reg(cm_context.cam_cm_clksel, OMAP3430_CAM_MOD,
			       CM_CLKSEL);
	omap2_cm_write_mod_reg(cm_context.per_cm_clksel, OMAP3430_PER_MOD,
			       CM_CLKSEL);
	omap2_cm_write_mod_reg(cm_context.emu_cm_clksel, OMAP3430_EMU_MOD,
			       CM_CLKSEL1);
	omap2_cm_write_mod_reg(cm_context.emu_cm_clkstctrl, OMAP3430_EMU_MOD,
			       OMAP2_CM_CLKSTCTRL);
	/*
	 * As per erratum i671, ROM code does not respect the PER DPLL
	 * programming scheme if CM_AUTOIDLE_PLL.AUTO_PERIPH_DPLL == 1.
	 * In this case, we need to restore AUTO_PERIPH_DPLL by ourselves.
	 */
	omap2_cm_write_mod_reg(cm_context.pll_cm_autoidle, PLL_MOD,
			       CM_AUTOIDLE);
	omap2_cm_write_mod_reg(cm_context.pll_cm_autoidle2, PLL_MOD,
			       CM_AUTOIDLE2);
	omap2_cm_write_mod_reg(cm_context.pll_cm_clksel4, PLL_MOD,
			       OMAP3430ES2_CM_CLKSEL4);
	omap2_cm_write_mod_reg(cm_context.pll_cm_clksel5, PLL_MOD,
			       OMAP3430ES2_CM_CLKSEL5);
	omap2_cm_write_mod_reg(cm_context.pll_cm_clken2, PLL_MOD,
			       OMAP3430ES2_CM_CLKEN2);
	omap2_cm_write_mod_reg(cm_context.cm_polctrl, OCP_MOD,
			       OMAP3430_CM_POLCTRL);
	omap2_cm_write_mod_reg(cm_context.iva2_cm_fclken, OMAP3430_IVA2_MOD,
			       CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.iva2_cm_clken_pll, OMAP3430_IVA2_MOD,
			       OMAP3430_CM_CLKEN_PLL);
	omap2_cm_write_mod_reg(cm_context.core_cm_fclken1, CORE_MOD,
			       CM_FCLKEN1);
	omap2_cm_write_mod_reg(cm_context.core_cm_fclken3, CORE_MOD,
			       OMAP3430ES2_CM_FCLKEN3);
	omap2_cm_write_mod_reg(cm_context.sgx_cm_fclken, OMAP3430ES2_SGX_MOD,
			       CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.wkup_cm_fclken, WKUP_MOD, CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.dss_cm_fclken, OMAP3430_DSS_MOD,
			       CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.cam_cm_fclken, OMAP3430_CAM_MOD,
			       CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.per_cm_fclken, OMAP3430_PER_MOD,
			       CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.usbhost_cm_fclken,
			       OMAP3430ES2_USBHOST_MOD, CM_FCLKEN);
	omap2_cm_write_mod_reg(cm_context.core_cm_iclken1, CORE_MOD,
			       CM_ICLKEN1);
	omap2_cm_write_mod_reg(cm_context.core_cm_iclken2, CORE_MOD,
			       CM_ICLKEN2);
	omap2_cm_write_mod_reg(cm_context.core_cm_iclken3, CORE_MOD,
			       CM_ICLKEN3);
	omap2_cm_write_mod_reg(cm_context.sgx_cm_iclken, OMAP3430ES2_SGX_MOD,
			       CM_ICLKEN);
	omap2_cm_write_mod_reg(cm_context.wkup_cm_iclken, WKUP_MOD, CM_ICLKEN);
	omap2_cm_write_mod_reg(cm_context.dss_cm_iclken, OMAP3430_DSS_MOD,
			       CM_ICLKEN);
	omap2_cm_write_mod_reg(cm_context.cam_cm_iclken, OMAP3430_CAM_MOD,
			       CM_ICLKEN);
	omap2_cm_write_mod_reg(cm_context.per_cm_iclken, OMAP3430_PER_MOD,
			       CM_ICLKEN);
	omap2_cm_write_mod_reg(cm_context.usbhost_cm_iclken,
			       OMAP3430ES2_USBHOST_MOD, CM_ICLKEN);
	omap2_cm_write_mod_reg(cm_context.iva2_cm_autoidle2, OMAP3430_IVA2_MOD,
			       CM_AUTOIDLE2);
	omap2_cm_write_mod_reg(cm_context.mpu_cm_autoidle2, MPU_MOD,
			       CM_AUTOIDLE2);
	omap2_cm_write_mod_reg(cm_context.iva2_cm_clkstctrl, OMAP3430_IVA2_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.mpu_cm_clkstctrl, MPU_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.core_cm_clkstctrl, CORE_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.sgx_cm_clkstctrl, OMAP3430ES2_SGX_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.dss_cm_clkstctrl, OMAP3430_DSS_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.cam_cm_clkstctrl, OMAP3430_CAM_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.per_cm_clkstctrl, OMAP3430_PER_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.neon_cm_clkstctrl, OMAP3430_NEON_MOD,
			       OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.usbhost_cm_clkstctrl,
			       OMAP3430ES2_USBHOST_MOD, OMAP2_CM_CLKSTCTRL);
	omap2_cm_write_mod_reg(cm_context.core_cm_autoidle1, CORE_MOD,
			       CM_AUTOIDLE1);
	omap2_cm_write_mod_reg(cm_context.core_cm_autoidle2, CORE_MOD,
			       CM_AUTOIDLE2);
	omap2_cm_write_mod_reg(cm_context.core_cm_autoidle3, CORE_MOD,
			       CM_AUTOIDLE3);
	omap2_cm_write_mod_reg(cm_context.wkup_cm_autoidle, WKUP_MOD,
			       CM_AUTOIDLE);
	omap2_cm_write_mod_reg(cm_context.dss_cm_autoidle, OMAP3430_DSS_MOD,
			       CM_AUTOIDLE);
	omap2_cm_write_mod_reg(cm_context.cam_cm_autoidle, OMAP3430_CAM_MOD,
			       CM_AUTOIDLE);
	omap2_cm_write_mod_reg(cm_context.per_cm_autoidle, OMAP3430_PER_MOD,
			       CM_AUTOIDLE);
	omap2_cm_write_mod_reg(cm_context.usbhost_cm_autoidle,
			       OMAP3430ES2_USBHOST_MOD, CM_AUTOIDLE);
	omap2_cm_write_mod_reg(cm_context.sgx_cm_sleepdep, OMAP3430ES2_SGX_MOD,
			       OMAP3430_CM_SLEEPDEP);
	omap2_cm_write_mod_reg(cm_context.dss_cm_sleepdep, OMAP3430_DSS_MOD,
			       OMAP3430_CM_SLEEPDEP);
	omap2_cm_write_mod_reg(cm_context.cam_cm_sleepdep, OMAP3430_CAM_MOD,
			       OMAP3430_CM_SLEEPDEP);
	omap2_cm_write_mod_reg(cm_context.per_cm_sleepdep, OMAP3430_PER_MOD,
			       OMAP3430_CM_SLEEPDEP);
	omap2_cm_write_mod_reg(cm_context.usbhost_cm_sleepdep,
			       OMAP3430ES2_USBHOST_MOD, OMAP3430_CM_SLEEPDEP);
	omap2_cm_write_mod_reg(cm_context.cm_clkout_ctrl, OMAP3430_CCR_MOD,
			       OMAP3_CM_CLKOUT_CTRL_OFFSET);
}

void omap3_cm_save_scratchpad_contents(u32 *ptr)
{
	*ptr++ = omap2_cm_read_mod_reg(CORE_MOD, CM_CLKSEL);
	*ptr++ = omap2_cm_read_mod_reg(WKUP_MOD, CM_CLKSEL);
	*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);

	/*
	 * As per erratum i671, ROM code does not respect the PER DPLL
	 * programming scheme if CM_AUTOIDLE_PLL..AUTO_PERIPH_DPLL == 1.
	 * Then,  in any case, clear these bits to avoid extra latencies.
	 */
	*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE) &
		~OMAP3430_AUTO_PERIPH_DPLL_MASK;
	*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL1_PLL);
	*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL2_PLL);
	*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL3);
	*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKEN_PLL);
	*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_AUTOIDLE_PLL);
	*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKSEL1_PLL);
	*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKSEL2_PLL);
}

