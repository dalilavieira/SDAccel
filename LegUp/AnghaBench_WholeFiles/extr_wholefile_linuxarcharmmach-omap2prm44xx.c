#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u32 ;
typedef  size_t u16 ;
struct prm_reset_src_map {int reg_shift; int std_shift; } ;
struct powerdomain {size_t prcm_partition; scalar_t__ prcm_offs; int context; size_t pwrstctrl_offs; int /*<<< orphan*/  name; } ;
struct omap4_vp {size_t irqstatus_mpu; int tranxdone_status; } ;
struct notifier_block {int dummy; } ;
typedef  scalar_t__ s32 ;
typedef  size_t s16 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_6__ {int nr_regs; size_t mask; size_t ack; size_t pm_ctrl; } ;
struct TYPE_5__ {int irq_enable; int pm_ctrl; } ;
struct TYPE_4__ {size_t va; } ;

/* Variables and functions */
 size_t AM43XX_PRM_DEVICE_INST ; 
 size_t AM43XX_PRM_OCP_SOCKET_INST ; 
#define  CPU_CLUSTER_PM_ENTER 129 
#define  CPU_CLUSTER_PM_EXIT 128 
 int EAGAIN ; 
 int EINVAL ; 
 int MAX_IOPAD_LATCH_TIME ; 
 int NOTIFY_OK ; 
 int OMAP4430_GLOBAL_WUEN_MASK ; 
 int OMAP4430_LASTPOWERSTATEENTERED_MASK ; 
 int OMAP4430_LASTPOWERSTATEENTERED_SHIFT ; 
 int OMAP4430_LOGICRETSTATE_MASK ; 
 int OMAP4430_LOGICRETSTATE_SHIFT ; 
 int OMAP4430_LOGICSTATEST_MASK ; 
 int OMAP4430_LOGICSTATEST_SHIFT ; 
 int OMAP4430_LOWPOWERSTATECHANGE_MASK ; 
 int OMAP4430_LOWPOWERSTATECHANGE_SHIFT ; 
 size_t OMAP4430_PRM_OCP_SOCKET_INST ; 
 size_t OMAP4430_PRM_PARTITION ; 
 int OMAP4430_WUCLK_CTRL_MASK ; 
 int OMAP4430_WUCLK_STATUS_MASK ; 
 int OMAP4430_WUCLK_STATUS_SHIFT ; 
 size_t OMAP4_PM_PWSTCTRL ; 
 size_t OMAP4_PM_PWSTST ; 
 size_t OMAP4_REVISION_PRM_OFFSET ; 
 size_t OMAP4_RM_RSTST ; 
 int OMAP_INTRANSITION_MASK ; 
 int OMAP_POWERSTATEST_MASK ; 
 int OMAP_POWERSTATEST_SHIFT ; 
 int OMAP_POWERSTATE_MASK ; 
 size_t OMAP_POWERSTATE_SHIFT ; 
 int PRM_HAS_VOLTAGE ; 
 scalar_t__ PRM_INSTANCE_UNKNOWN ; 
 int PWRDM_POWER_OFF ; 
 int PWRDM_POWER_RET ; 
 scalar_t__ PWRDM_TRANSITION_BAILOUT ; 
 int __ffs (int) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int /*<<< orphan*/  enable_off_mode ; 
 int omap2_pwrdm_get_mem_bank_onstate_mask (size_t) ; 
 int omap2_pwrdm_get_mem_bank_retst_mask (size_t) ; 
 int omap2_pwrdm_get_mem_bank_stst_mask (size_t) ; 
 struct prm_reset_src_map* omap44xx_prm_reset_src_map ; 
 TYPE_3__ omap4_prcm_irq_setup ; 
 int omap4_prminst_read_inst_reg (size_t,size_t,size_t) ; 
 int omap4_prminst_rmw_inst_reg_bits (int,size_t,size_t,scalar_t__,size_t) ; 
 int /*<<< orphan*/  omap4_prminst_write_inst_reg (int,size_t,size_t,size_t) ; 
 scalar_t__ omap4_prmst_get_prm_dev_inst () ; 
 struct omap4_vp* omap4_vp ; 
 TYPE_2__ omap_prm_context ; 
 scalar_t__ omap_rev () ; 
 int /*<<< orphan*/  omap_test_timeout (int,int,int) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 TYPE_1__ prm_base ; 
 int prm_features ; 
 int readl_relaxed (size_t) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,size_t) ; 

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

__attribute__((used)) static u32 omap4_prm_read_inst_reg(s16 inst, u16 reg)
{
	return readl_relaxed(prm_base.va + inst + reg);
}

__attribute__((used)) static void omap4_prm_write_inst_reg(u32 val, s16 inst, u16 reg)
{
	writel_relaxed(val, prm_base.va + inst + reg);
}

__attribute__((used)) static u32 omap4_prm_rmw_inst_reg_bits(u32 mask, u32 bits, s16 inst, s16 reg)
{
	u32 v;

	v = omap4_prm_read_inst_reg(inst, reg);
	v &= ~mask;
	v |= bits;
	omap4_prm_write_inst_reg(v, inst, reg);

	return v;
}

__attribute__((used)) static u32 omap4_prm_vp_check_txdone(u8 vp_id)
{
	struct omap4_vp *vp = &omap4_vp[vp_id];
	u32 irqstatus;

	irqstatus = omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
						OMAP4430_PRM_OCP_SOCKET_INST,
						vp->irqstatus_mpu);
	return irqstatus & vp->tranxdone_status;
}

__attribute__((used)) static void omap4_prm_vp_clear_txdone(u8 vp_id)
{
	struct omap4_vp *vp = &omap4_vp[vp_id];

	omap4_prminst_write_inst_reg(vp->tranxdone_status,
				     OMAP4430_PRM_PARTITION,
				     OMAP4430_PRM_OCP_SOCKET_INST,
				     vp->irqstatus_mpu);
}

u32 omap4_prm_vcvp_read(u8 offset)
{
	s32 inst = omap4_prmst_get_prm_dev_inst();

	if (inst == PRM_INSTANCE_UNKNOWN)
		return 0;

	return omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
					   inst, offset);
}

void omap4_prm_vcvp_write(u32 val, u8 offset)
{
	s32 inst = omap4_prmst_get_prm_dev_inst();

	if (inst == PRM_INSTANCE_UNKNOWN)
		return;

	omap4_prminst_write_inst_reg(val, OMAP4430_PRM_PARTITION,
				     inst, offset);
}

u32 omap4_prm_vcvp_rmw(u32 mask, u32 bits, u8 offset)
{
	s32 inst = omap4_prmst_get_prm_dev_inst();

	if (inst == PRM_INSTANCE_UNKNOWN)
		return 0;

	return omap4_prminst_rmw_inst_reg_bits(mask, bits,
					       OMAP4430_PRM_PARTITION,
					       inst,
					       offset);
}

__attribute__((used)) static inline u32 _read_pending_irq_reg(u16 irqen_offs, u16 irqst_offs)
{
	u32 mask, st;

	/* XXX read mask from RAM? */
	mask = omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
				       irqen_offs);
	st = omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST, irqst_offs);

	return mask & st;
}

__attribute__((used)) static void omap44xx_prm_read_pending_irqs(unsigned long *events)
{
	int i;

	for (i = 0; i < omap4_prcm_irq_setup.nr_regs; i++)
		events[i] = _read_pending_irq_reg(omap4_prcm_irq_setup.mask +
				i * 4, omap4_prcm_irq_setup.ack + i * 4);
}

__attribute__((used)) static void omap44xx_prm_ocp_barrier(void)
{
	omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
				OMAP4_REVISION_PRM_OFFSET);
}

__attribute__((used)) static void omap44xx_prm_save_and_clear_irqen(u32 *saved_mask)
{
	int i;
	u16 reg;

	for (i = 0; i < omap4_prcm_irq_setup.nr_regs; i++) {
		reg = omap4_prcm_irq_setup.mask + i * 4;

		saved_mask[i] =
			omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
						reg);
		omap4_prm_write_inst_reg(0, OMAP4430_PRM_OCP_SOCKET_INST, reg);
	}

	/* OCP barrier */
	omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
				OMAP4_REVISION_PRM_OFFSET);
}

__attribute__((used)) static void omap44xx_prm_restore_irqen(u32 *saved_mask)
{
	int i;

	for (i = 0; i < omap4_prcm_irq_setup.nr_regs; i++)
		omap4_prm_write_inst_reg(saved_mask[i],
					 OMAP4430_PRM_OCP_SOCKET_INST,
					 omap4_prcm_irq_setup.mask + i * 4);
}

__attribute__((used)) static void omap44xx_prm_reconfigure_io_chain(void)
{
	int i = 0;
	s32 inst = omap4_prmst_get_prm_dev_inst();

	if (inst == PRM_INSTANCE_UNKNOWN)
		return;

	/* Trigger WUCLKIN enable */
	omap4_prm_rmw_inst_reg_bits(OMAP4430_WUCLK_CTRL_MASK,
				    OMAP4430_WUCLK_CTRL_MASK,
				    inst,
				    omap4_prcm_irq_setup.pm_ctrl);
	omap_test_timeout(
		(((omap4_prm_read_inst_reg(inst,
					   omap4_prcm_irq_setup.pm_ctrl) &
		   OMAP4430_WUCLK_STATUS_MASK) >>
		  OMAP4430_WUCLK_STATUS_SHIFT) == 1),
		MAX_IOPAD_LATCH_TIME, i);
	if (i == MAX_IOPAD_LATCH_TIME)
		pr_warn("PRM: I/O chain clock line assertion timed out\n");

	/* Trigger WUCLKIN disable */
	omap4_prm_rmw_inst_reg_bits(OMAP4430_WUCLK_CTRL_MASK, 0x0,
				    inst,
				    omap4_prcm_irq_setup.pm_ctrl);
	omap_test_timeout(
		(((omap4_prm_read_inst_reg(inst,
					   omap4_prcm_irq_setup.pm_ctrl) &
		   OMAP4430_WUCLK_STATUS_MASK) >>
		  OMAP4430_WUCLK_STATUS_SHIFT) == 0),
		MAX_IOPAD_LATCH_TIME, i);
	if (i == MAX_IOPAD_LATCH_TIME)
		pr_warn("PRM: I/O chain clock line deassertion timed out\n");

	return;
}

__attribute__((used)) static void omap44xx_prm_enable_io_wakeup(void)
{
	s32 inst = omap4_prmst_get_prm_dev_inst();

	if (inst == PRM_INSTANCE_UNKNOWN)
		return;

	omap4_prm_rmw_inst_reg_bits(OMAP4430_GLOBAL_WUEN_MASK,
				    OMAP4430_GLOBAL_WUEN_MASK,
				    inst,
				    omap4_prcm_irq_setup.pm_ctrl);
}

__attribute__((used)) static u32 omap44xx_prm_read_reset_sources(void)
{
	struct prm_reset_src_map *p;
	u32 r = 0;
	u32 v;
	s32 inst = omap4_prmst_get_prm_dev_inst();

	if (inst == PRM_INSTANCE_UNKNOWN)
		return 0;


	v = omap4_prm_read_inst_reg(inst,
				    OMAP4_RM_RSTST);

	p = omap44xx_prm_reset_src_map;
	while (p->reg_shift >= 0 && p->std_shift >= 0) {
		if (v & (1 << p->reg_shift))
			r |= 1 << p->std_shift;
		p++;
	}

	return r;
}

__attribute__((used)) static bool omap44xx_prm_was_any_context_lost_old(u8 part, s16 inst, u16 idx)
{
	return (omap4_prminst_read_inst_reg(part, inst, idx)) ? 1 : 0;
}

__attribute__((used)) static void omap44xx_prm_clear_context_loss_flags_old(u8 part, s16 inst,
						      u16 idx)
{
	omap4_prminst_write_inst_reg(0xffffffff, part, inst, idx);
}

__attribute__((used)) static int omap4_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
	omap4_prminst_rmw_inst_reg_bits(OMAP_POWERSTATE_MASK,
					(pwrst << OMAP_POWERSTATE_SHIFT),
					pwrdm->prcm_partition,
					pwrdm->prcm_offs, OMAP4_PM_PWSTCTRL);
	return 0;
}

__attribute__((used)) static int omap4_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTCTRL);
	v &= OMAP_POWERSTATE_MASK;
	v >>= OMAP_POWERSTATE_SHIFT;

	return v;
}

__attribute__((used)) static int omap4_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTST);
	v &= OMAP_POWERSTATEST_MASK;
	v >>= OMAP_POWERSTATEST_SHIFT;

	return v;
}

__attribute__((used)) static int omap4_pwrdm_read_prev_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTST);
	v &= OMAP4430_LASTPOWERSTATEENTERED_MASK;
	v >>= OMAP4430_LASTPOWERSTATEENTERED_SHIFT;

	return v;
}

__attribute__((used)) static int omap4_pwrdm_set_lowpwrstchange(struct powerdomain *pwrdm)
{
	omap4_prminst_rmw_inst_reg_bits(OMAP4430_LOWPOWERSTATECHANGE_MASK,
					(1 << OMAP4430_LOWPOWERSTATECHANGE_SHIFT),
					pwrdm->prcm_partition,
					pwrdm->prcm_offs, OMAP4_PM_PWSTCTRL);
	return 0;
}

__attribute__((used)) static int omap4_pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
	omap4_prminst_rmw_inst_reg_bits(OMAP4430_LASTPOWERSTATEENTERED_MASK,
					OMAP4430_LASTPOWERSTATEENTERED_MASK,
					pwrdm->prcm_partition,
					pwrdm->prcm_offs, OMAP4_PM_PWSTST);
	return 0;
}

__attribute__((used)) static int omap4_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
	u32 v;

	v = pwrst << __ffs(OMAP4430_LOGICRETSTATE_MASK);
	omap4_prminst_rmw_inst_reg_bits(OMAP4430_LOGICRETSTATE_MASK, v,
					pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTCTRL);

	return 0;
}

__attribute__((used)) static int omap4_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
				    u8 pwrst)
{
	u32 m;

	m = omap2_pwrdm_get_mem_bank_onstate_mask(bank);

	omap4_prminst_rmw_inst_reg_bits(m, (pwrst << __ffs(m)),
					pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTCTRL);

	return 0;
}

__attribute__((used)) static int omap4_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
				     u8 pwrst)
{
	u32 m;

	m = omap2_pwrdm_get_mem_bank_retst_mask(bank);

	omap4_prminst_rmw_inst_reg_bits(m, (pwrst << __ffs(m)),
					pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTCTRL);

	return 0;
}

__attribute__((used)) static int omap4_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
	u32 v;

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTST);
	v &= OMAP4430_LOGICSTATEST_MASK;
	v >>= OMAP4430_LOGICSTATEST_SHIFT;

	return v;
}

__attribute__((used)) static int omap4_pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
	u32 v;

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTCTRL);
	v &= OMAP4430_LOGICRETSTATE_MASK;
	v >>= OMAP4430_LOGICRETSTATE_SHIFT;

	return v;
}

__attribute__((used)) static int omap4_pwrdm_read_prev_logic_pwrst(struct powerdomain *pwrdm)
{
	int state;

	state = omap4_pwrdm_read_prev_pwrst(pwrdm);

	if (state == PWRDM_POWER_OFF)
		return PWRDM_POWER_OFF;

	if (state != PWRDM_POWER_RET)
		return PWRDM_POWER_RET;

	return omap4_pwrdm_read_logic_retst(pwrdm);
}

__attribute__((used)) static int omap4_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
	u32 m, v;

	m = omap2_pwrdm_get_mem_bank_stst_mask(bank);

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTST);
	v &= m;
	v >>= __ffs(m);

	return v;
}

__attribute__((used)) static int omap4_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
	u32 m, v;

	m = omap2_pwrdm_get_mem_bank_retst_mask(bank);

	v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
					OMAP4_PM_PWSTCTRL);
	v &= m;
	v >>= __ffs(m);

	return v;
}

__attribute__((used)) static int omap4_pwrdm_read_prev_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
	int state;

	state = omap4_pwrdm_read_prev_pwrst(pwrdm);

	if (state == PWRDM_POWER_OFF)
		return PWRDM_POWER_OFF;

	if (state != PWRDM_POWER_RET)
		return PWRDM_POWER_RET;

	return omap4_pwrdm_read_mem_retst(pwrdm, bank);
}

__attribute__((used)) static int omap4_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
	u32 c = 0;

	/*
	 * REVISIT: pwrdm_wait_transition() may be better implemented
	 * via a callback and a periodic timer check -- how long do we expect
	 * powerdomain transitions to take?
	 */

	/* XXX Is this udelay() value meaningful? */
	while ((omap4_prminst_read_inst_reg(pwrdm->prcm_partition,
					    pwrdm->prcm_offs,
					    OMAP4_PM_PWSTST) &
		OMAP_INTRANSITION_MASK) &&
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

__attribute__((used)) static int omap4_check_vcvp(void)
{
	if (prm_features & PRM_HAS_VOLTAGE)
		return 1;

	return 0;
}

__attribute__((used)) static void omap4_pwrdm_save_context(struct powerdomain *pwrdm)
{
	pwrdm->context = omap4_prminst_read_inst_reg(pwrdm->prcm_partition,
						     pwrdm->prcm_offs,
						     pwrdm->pwrstctrl_offs);

	/*
	 * Do not save LOWPOWERSTATECHANGE, writing a 1 indicates a request,
	 * reading back a 1 indicates a request in progress.
	 */
	pwrdm->context &= ~OMAP4430_LOWPOWERSTATECHANGE_MASK;
}

__attribute__((used)) static void omap4_pwrdm_restore_context(struct powerdomain *pwrdm)
{
	int st, ctrl;

	st = omap4_prminst_read_inst_reg(pwrdm->prcm_partition,
					 pwrdm->prcm_offs,
					 pwrdm->pwrstctrl_offs);

	omap4_prminst_write_inst_reg(pwrdm->context,
				     pwrdm->prcm_partition,
				     pwrdm->prcm_offs,
				     pwrdm->pwrstctrl_offs);

	/* Make sure we only wait for a transition if there is one */
	st &= OMAP_POWERSTATEST_MASK;
	ctrl = OMAP_POWERSTATEST_MASK & pwrdm->context;

	if (st != ctrl)
		omap4_pwrdm_wait_transition(pwrdm);
}

void prm_save_context(void)
{
	omap_prm_context.irq_enable =
			omap4_prm_read_inst_reg(AM43XX_PRM_OCP_SOCKET_INST,
						omap4_prcm_irq_setup.mask);

	omap_prm_context.pm_ctrl =
			omap4_prm_read_inst_reg(AM43XX_PRM_DEVICE_INST,
						omap4_prcm_irq_setup.pm_ctrl);
}

void prm_restore_context(void)
{
	omap4_prm_write_inst_reg(omap_prm_context.irq_enable,
				 OMAP4430_PRM_OCP_SOCKET_INST,
				 omap4_prcm_irq_setup.mask);

	omap4_prm_write_inst_reg(omap_prm_context.pm_ctrl,
				 AM43XX_PRM_DEVICE_INST,
				 omap4_prcm_irq_setup.pm_ctrl);
}

__attribute__((used)) static int cpu_notifier(struct notifier_block *nb, unsigned long cmd, void *v)
{
	switch (cmd) {
	case CPU_CLUSTER_PM_ENTER:
		if (enable_off_mode)
			prm_save_context();
		break;
	case CPU_CLUSTER_PM_EXIT:
		if (enable_off_mode)
			prm_restore_context();
		break;
	}

	return NOTIFY_OK;
}

