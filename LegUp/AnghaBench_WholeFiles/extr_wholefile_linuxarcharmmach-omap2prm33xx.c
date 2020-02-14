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
struct powerdomain {int logicretstate_mask; int* mem_on_mask; int* mem_ret_mask; int* mem_pwrst_mask; int* mem_retst_mask; int context; scalar_t__ pwrstctrl_offs; scalar_t__ prcm_offs; scalar_t__ pwrstst_offs; int /*<<< orphan*/  name; } ;
typedef  scalar_t__ s16 ;
struct TYPE_2__ {scalar_t__ va; } ;

/* Variables and functions */
 int AM33XX_LASTPOWERSTATEENTERED_MASK ; 
 int AM33XX_LOGICSTATEST_MASK ; 
 int AM33XX_LOGICSTATEST_SHIFT ; 
 int AM33XX_LOWPOWERSTATECHANGE_MASK ; 
 int AM33XX_LOWPOWERSTATECHANGE_SHIFT ; 
 scalar_t__ AM33XX_PRM_DEVICE_MOD ; 
 scalar_t__ AM33XX_PRM_RSTCTRL_OFFSET ; 
 int AM33XX_RST_GLOBAL_WARM_SW_MASK ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EEXIST ; 
 int EINVAL ; 
 int MAX_MODULE_HARDRESET_WAIT ; 
 int OMAP_INTRANSITION_MASK ; 
 int OMAP_POWERSTATEST_MASK ; 
 int OMAP_POWERSTATEST_SHIFT ; 
 int OMAP_POWERSTATE_MASK ; 
 int OMAP_POWERSTATE_SHIFT ; 
 scalar_t__ PWRDM_TRANSITION_BAILOUT ; 
 int __ffs (int) ; 
 int /*<<< orphan*/  omap_test_timeout (int,int,int) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 
 TYPE_1__ prm_base ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static u32 am33xx_prm_read_reg(s16 inst, u16 idx)
{
	return readl_relaxed(prm_base.va + inst + idx);
}

__attribute__((used)) static void am33xx_prm_write_reg(u32 val, s16 inst, u16 idx)
{
	writel_relaxed(val, prm_base.va + inst + idx);
}

__attribute__((used)) static u32 am33xx_prm_rmw_reg_bits(u32 mask, u32 bits, s16 inst, s16 idx)
{
	u32 v;

	v = am33xx_prm_read_reg(inst, idx);
	v &= ~mask;
	v |= bits;
	am33xx_prm_write_reg(v, inst, idx);

	return v;
}

__attribute__((used)) static int am33xx_prm_is_hardreset_asserted(u8 shift, u8 part, s16 inst,
					    u16 rstctrl_offs)
{
	u32 v;

	v = am33xx_prm_read_reg(inst, rstctrl_offs);
	v &= 1 << shift;
	v >>= shift;

	return v;
}

__attribute__((used)) static int am33xx_prm_assert_hardreset(u8 shift, u8 part, s16 inst,
				       u16 rstctrl_offs)
{
	u32 mask = 1 << shift;

	am33xx_prm_rmw_reg_bits(mask, mask, inst, rstctrl_offs);

	return 0;
}

__attribute__((used)) static int am33xx_prm_deassert_hardreset(u8 shift, u8 st_shift, u8 part,
					 s16 inst, u16 rstctrl_offs,
					 u16 rstst_offs)
{
	int c;
	u32 mask = 1 << st_shift;

	/* Check the current status to avoid  de-asserting the line twice */
	if (am33xx_prm_is_hardreset_asserted(shift, 0, inst, rstctrl_offs) == 0)
		return -EEXIST;

	/* Clear the reset status by writing 1 to the status bit */
	am33xx_prm_rmw_reg_bits(0xffffffff, mask, inst, rstst_offs);

	/* de-assert the reset control line */
	mask = 1 << shift;

	am33xx_prm_rmw_reg_bits(mask, 0, inst, rstctrl_offs);

	/* wait the status to be set */
	omap_test_timeout(am33xx_prm_is_hardreset_asserted(st_shift, 0, inst,
							   rstst_offs),
			  MAX_MODULE_HARDRESET_WAIT, c);

	return (c == MAX_MODULE_HARDRESET_WAIT) ? -EBUSY : 0;
}

__attribute__((used)) static int am33xx_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
	am33xx_prm_rmw_reg_bits(OMAP_POWERSTATE_MASK,
				(pwrst << OMAP_POWERSTATE_SHIFT),
				pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
	return 0;
}

__attribute__((used)) static int am33xx_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = am33xx_prm_read_reg(pwrdm->prcm_offs,  pwrdm->pwrstctrl_offs);
	v &= OMAP_POWERSTATE_MASK;
	v >>= OMAP_POWERSTATE_SHIFT;

	return v;
}

__attribute__((used)) static int am33xx_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
	v &= OMAP_POWERSTATEST_MASK;
	v >>= OMAP_POWERSTATEST_SHIFT;

	return v;
}

__attribute__((used)) static int am33xx_pwrdm_set_lowpwrstchange(struct powerdomain *pwrdm)
{
	am33xx_prm_rmw_reg_bits(AM33XX_LOWPOWERSTATECHANGE_MASK,
				(1 << AM33XX_LOWPOWERSTATECHANGE_SHIFT),
				pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
	return 0;
}

__attribute__((used)) static int am33xx_pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
	am33xx_prm_rmw_reg_bits(AM33XX_LASTPOWERSTATEENTERED_MASK,
				AM33XX_LASTPOWERSTATEENTERED_MASK,
				pwrdm->prcm_offs, pwrdm->pwrstst_offs);
	return 0;
}

__attribute__((used)) static int am33xx_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
	u32 m;

	m = pwrdm->logicretstate_mask;
	if (!m)
		return -EINVAL;

	am33xx_prm_rmw_reg_bits(m, (pwrst << __ffs(m)),
				pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);

	return 0;
}

__attribute__((used)) static int am33xx_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
	v &= AM33XX_LOGICSTATEST_MASK;
	v >>= AM33XX_LOGICSTATEST_SHIFT;

	return v;
}

__attribute__((used)) static int am33xx_pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
	u32 v, m;

	m = pwrdm->logicretstate_mask;
	if (!m)
		return -EINVAL;

	v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
	v &= m;
	v >>= __ffs(m);

	return v;
}

__attribute__((used)) static int am33xx_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
		u8 pwrst)
{
	u32 m;

	m = pwrdm->mem_on_mask[bank];
	if (!m)
		return -EINVAL;

	am33xx_prm_rmw_reg_bits(m, (pwrst << __ffs(m)),
				pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);

	return 0;
}

__attribute__((used)) static int am33xx_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
					u8 pwrst)
{
	u32 m;

	m = pwrdm->mem_ret_mask[bank];
	if (!m)
		return -EINVAL;

	am33xx_prm_rmw_reg_bits(m, (pwrst << __ffs(m)),
				pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);

	return 0;
}

__attribute__((used)) static int am33xx_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
	u32 m, v;

	m = pwrdm->mem_pwrst_mask[bank];
	if (!m)
		return -EINVAL;

	v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
	v &= m;
	v >>= __ffs(m);

	return v;
}

__attribute__((used)) static int am33xx_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
	u32 m, v;

	m = pwrdm->mem_retst_mask[bank];
	if (!m)
		return -EINVAL;

	v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
	v &= m;
	v >>= __ffs(m);

	return v;
}

__attribute__((used)) static int am33xx_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
	u32 c = 0;

	/*
	 * REVISIT: pwrdm_wait_transition() may be better implemented
	 * via a callback and a periodic timer check -- how long do we expect
	 * powerdomain transitions to take?
	 */

	/* XXX Is this udelay() value meaningful? */
	while ((am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs)
			& OMAP_INTRANSITION_MASK) &&
			(c++ < PWRDM_TRANSITION_BAILOUT))
		udelay(1);

	if (c > PWRDM_TRANSITION_BAILOUT) {
		pr_err("powerdomain: %s: waited too long to complete transition\n",
		       pwrdm->name);
		return -EAGAIN;
	}

	pr_debug("powerdomain: completed transition in %d loops\n", c);

	return 0;
}

__attribute__((used)) static int am33xx_check_vcvp(void)
{
	/* No VC/VP on am33xx devices */
	return 0;
}

__attribute__((used)) static void am33xx_prm_global_warm_sw_reset(void)
{
	am33xx_prm_rmw_reg_bits(AM33XX_RST_GLOBAL_WARM_SW_MASK,
				AM33XX_RST_GLOBAL_WARM_SW_MASK,
				AM33XX_PRM_DEVICE_MOD,
				AM33XX_PRM_RSTCTRL_OFFSET);

	/* OCP barrier */
	(void)am33xx_prm_read_reg(AM33XX_PRM_DEVICE_MOD,
				  AM33XX_PRM_RSTCTRL_OFFSET);
}

__attribute__((used)) static void am33xx_pwrdm_save_context(struct powerdomain *pwrdm)
{
	pwrdm->context = am33xx_prm_read_reg(pwrdm->prcm_offs,
						pwrdm->pwrstctrl_offs);
	/*
	 * Do not save LOWPOWERSTATECHANGE, writing a 1 indicates a request,
	 * reading back a 1 indicates a request in progress.
	 */
	pwrdm->context &= ~AM33XX_LOWPOWERSTATECHANGE_MASK;
}

__attribute__((used)) static void am33xx_pwrdm_restore_context(struct powerdomain *pwrdm)
{
	int st, ctrl;

	st = am33xx_prm_read_reg(pwrdm->prcm_offs,
				 pwrdm->pwrstst_offs);

	am33xx_prm_write_reg(pwrdm->context, pwrdm->prcm_offs,
			     pwrdm->pwrstctrl_offs);

	/* Make sure we only wait for a transition if there is one */
	st &= OMAP_POWERSTATEST_MASK;
	ctrl = OMAP_POWERSTATEST_MASK & pwrdm->context;

	if (st != ctrl)
		am33xx_pwrdm_wait_transition(pwrdm);
}

