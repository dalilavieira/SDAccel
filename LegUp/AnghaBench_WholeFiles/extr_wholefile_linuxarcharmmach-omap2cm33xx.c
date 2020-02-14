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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct clockdomain {scalar_t__ cm_inst; scalar_t__ clkdm_offs; int flags; int context; } ;
typedef  scalar_t__ s16 ;
struct TYPE_2__ {scalar_t__ va; scalar_t__ pa; } ;

/* Variables and functions */
 scalar_t__ AM33XX_CLKTRCTRL_MASK ; 
 scalar_t__ AM33XX_CLKTRCTRL_SHIFT ; 
 scalar_t__ AM33XX_IDLEST_MASK ; 
 scalar_t__ AM33XX_IDLEST_SHIFT ; 
 scalar_t__ AM33XX_MODULEMODE_MASK ; 
 scalar_t__ AM33XX_MODULEMODE_SHIFT ; 
 scalar_t__ CLKCTRL_IDLEST_DISABLED ; 
 scalar_t__ CLKCTRL_IDLEST_FUNCTIONAL ; 
 scalar_t__ CLKCTRL_IDLEST_INTERFACE_IDLE ; 
 int CLKDM_CAN_FORCE_SLEEP ; 
 int CLKDM_CAN_FORCE_WAKEUP ; 
 int EBUSY ; 
 int MAX_MODULE_READY_TIME ; 
#define  OMAP34XX_CLKSTCTRL_DISABLE_AUTO 131 
#define  OMAP34XX_CLKSTCTRL_ENABLE_AUTO 130 
#define  OMAP34XX_CLKSTCTRL_FORCE_SLEEP 129 
#define  OMAP34XX_CLKSTCTRL_FORCE_WAKEUP 128 
 scalar_t__ __ffs (scalar_t__) ; 
 TYPE_1__ cm_base ; 
 int /*<<< orphan*/  omap_test_timeout (int,int,int) ; 
 scalar_t__ readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline u32 am33xx_cm_read_reg(u16 inst, u16 idx)
{
	return readl_relaxed(cm_base.va + inst + idx);
}

__attribute__((used)) static inline void am33xx_cm_write_reg(u32 val, u16 inst, u16 idx)
{
	writel_relaxed(val, cm_base.va + inst + idx);
}

__attribute__((used)) static inline u32 am33xx_cm_rmw_reg_bits(u32 mask, u32 bits, s16 inst, s16 idx)
{
	u32 v;

	v = am33xx_cm_read_reg(inst, idx);
	v &= ~mask;
	v |= bits;
	am33xx_cm_write_reg(v, inst, idx);

	return v;
}

__attribute__((used)) static inline u32 am33xx_cm_read_reg_bits(u16 inst, s16 idx, u32 mask)
{
	u32 v;

	v = am33xx_cm_read_reg(inst, idx);
	v &= mask;
	v >>= __ffs(mask);

	return v;
}

__attribute__((used)) static u32 _clkctrl_idlest(u16 inst, u16 clkctrl_offs)
{
	u32 v = am33xx_cm_read_reg(inst, clkctrl_offs);
	v &= AM33XX_IDLEST_MASK;
	v >>= AM33XX_IDLEST_SHIFT;
	return v;
}

__attribute__((used)) static bool _is_module_ready(u16 inst, u16 clkctrl_offs)
{
	u32 v;

	v = _clkctrl_idlest(inst, clkctrl_offs);

	return (v == CLKCTRL_IDLEST_FUNCTIONAL ||
		v == CLKCTRL_IDLEST_INTERFACE_IDLE) ? true : false;
}

__attribute__((used)) static void _clktrctrl_write(u8 c, u16 inst, u16 cdoffs)
{
	u32 v;

	v = am33xx_cm_read_reg(inst, cdoffs);
	v &= ~AM33XX_CLKTRCTRL_MASK;
	v |= c << AM33XX_CLKTRCTRL_SHIFT;
	am33xx_cm_write_reg(v, inst, cdoffs);
}

__attribute__((used)) static bool am33xx_cm_is_clkdm_in_hwsup(u16 inst, u16 cdoffs)
{
	u32 v;

	v = am33xx_cm_read_reg(inst, cdoffs);
	v &= AM33XX_CLKTRCTRL_MASK;
	v >>= AM33XX_CLKTRCTRL_SHIFT;

	return (v == OMAP34XX_CLKSTCTRL_ENABLE_AUTO) ? true : false;
}

__attribute__((used)) static void am33xx_cm_clkdm_enable_hwsup(u16 inst, u16 cdoffs)
{
	_clktrctrl_write(OMAP34XX_CLKSTCTRL_ENABLE_AUTO, inst, cdoffs);
}

__attribute__((used)) static void am33xx_cm_clkdm_disable_hwsup(u16 inst, u16 cdoffs)
{
	_clktrctrl_write(OMAP34XX_CLKSTCTRL_DISABLE_AUTO, inst, cdoffs);
}

__attribute__((used)) static void am33xx_cm_clkdm_force_sleep(u16 inst, u16 cdoffs)
{
	_clktrctrl_write(OMAP34XX_CLKSTCTRL_FORCE_SLEEP, inst, cdoffs);
}

__attribute__((used)) static void am33xx_cm_clkdm_force_wakeup(u16 inst, u16 cdoffs)
{
	_clktrctrl_write(OMAP34XX_CLKSTCTRL_FORCE_WAKEUP, inst, cdoffs);
}

__attribute__((used)) static int am33xx_cm_wait_module_ready(u8 part, s16 inst, u16 clkctrl_offs,
				       u8 bit_shift)
{
	int i = 0;

	omap_test_timeout(_is_module_ready(inst, clkctrl_offs),
			  MAX_MODULE_READY_TIME, i);

	return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}

__attribute__((used)) static int am33xx_cm_wait_module_idle(u8 part, s16 inst, u16 clkctrl_offs,
				      u8 bit_shift)
{
	int i = 0;

	omap_test_timeout((_clkctrl_idlest(inst, clkctrl_offs) ==
				CLKCTRL_IDLEST_DISABLED),
				MAX_MODULE_READY_TIME, i);

	return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}

__attribute__((used)) static void am33xx_cm_module_enable(u8 mode, u8 part, u16 inst,
				    u16 clkctrl_offs)
{
	u32 v;

	v = am33xx_cm_read_reg(inst, clkctrl_offs);
	v &= ~AM33XX_MODULEMODE_MASK;
	v |= mode << AM33XX_MODULEMODE_SHIFT;
	am33xx_cm_write_reg(v, inst, clkctrl_offs);
}

__attribute__((used)) static void am33xx_cm_module_disable(u8 part, u16 inst, u16 clkctrl_offs)
{
	u32 v;

	v = am33xx_cm_read_reg(inst, clkctrl_offs);
	v &= ~AM33XX_MODULEMODE_MASK;
	am33xx_cm_write_reg(v, inst, clkctrl_offs);
}

__attribute__((used)) static int am33xx_clkdm_sleep(struct clockdomain *clkdm)
{
	am33xx_cm_clkdm_force_sleep(clkdm->cm_inst, clkdm->clkdm_offs);
	return 0;
}

__attribute__((used)) static int am33xx_clkdm_wakeup(struct clockdomain *clkdm)
{
	am33xx_cm_clkdm_force_wakeup(clkdm->cm_inst, clkdm->clkdm_offs);
	return 0;
}

__attribute__((used)) static void am33xx_clkdm_allow_idle(struct clockdomain *clkdm)
{
	am33xx_cm_clkdm_enable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}

__attribute__((used)) static void am33xx_clkdm_deny_idle(struct clockdomain *clkdm)
{
	am33xx_cm_clkdm_disable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}

__attribute__((used)) static int am33xx_clkdm_clk_enable(struct clockdomain *clkdm)
{
	if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
		return am33xx_clkdm_wakeup(clkdm);

	return 0;
}

__attribute__((used)) static int am33xx_clkdm_clk_disable(struct clockdomain *clkdm)
{
	bool hwsup = false;

	hwsup = am33xx_cm_is_clkdm_in_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);

	if (!hwsup && (clkdm->flags & CLKDM_CAN_FORCE_SLEEP))
		am33xx_clkdm_sleep(clkdm);

	return 0;
}

__attribute__((used)) static u32 am33xx_cm_xlate_clkctrl(u8 part, u16 inst, u16 offset)
{
	return cm_base.pa + inst + offset;
}

__attribute__((used)) static int am33xx_clkdm_save_context(struct clockdomain *clkdm)
{
	clkdm->context = am33xx_cm_read_reg_bits(clkdm->cm_inst,
						 clkdm->clkdm_offs,
						 AM33XX_CLKTRCTRL_MASK);

	return 0;
}

__attribute__((used)) static int am33xx_clkdm_restore_context(struct clockdomain *clkdm)
{
	switch (clkdm->context) {
	case OMAP34XX_CLKSTCTRL_DISABLE_AUTO:
		am33xx_clkdm_deny_idle(clkdm);
		break;
	case OMAP34XX_CLKSTCTRL_FORCE_SLEEP:
		am33xx_clkdm_sleep(clkdm);
		break;
	case OMAP34XX_CLKSTCTRL_FORCE_WAKEUP:
		am33xx_clkdm_wakeup(clkdm);
		break;
	case OMAP34XX_CLKSTCTRL_ENABLE_AUTO:
		am33xx_clkdm_allow_idle(clkdm);
		break;
	}
	return 0;
}

