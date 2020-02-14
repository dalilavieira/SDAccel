#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u32 ;
typedef  size_t u16 ;
struct omap3_vp {int tranxdone_status; } ;
struct device_node {int dummy; } ;
typedef  size_t s16 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_7__ {size_t va; } ;
struct TYPE_6__ {int irq; int /*<<< orphan*/  reconfigure_io_chain; } ;
struct TYPE_5__ {size_t va; } ;

/* Variables and functions */
 size_t CM_FCLKEN1 ; 
 size_t CM_ICLKEN1 ; 
 size_t CM_ICLKEN3 ; 
 int ENODEV ; 
 int EPROBE_DEFER ; 
 size_t OCP_MOD ; 
 size_t OMAP2_RM_RSTCTRL ; 
 size_t OMAP3430ES2_CM_FCLKEN3 ; 
 int OMAP3430ES2_EN_USBHOST2_SHIFT ; 
 size_t OMAP3430ES2_PM_MPUGRPSEL3 ; 
 size_t OMAP3430ES2_PM_WKST3 ; 
 size_t OMAP3430ES2_USBHOST_MOD ; 
 size_t OMAP3430_GR_MOD ; 
 size_t OMAP3430_PM_MPUGRPSEL ; 
 size_t OMAP3_PRM_IRQENABLE_MPU_OFFSET ; 
 size_t OMAP3_PRM_IRQSTATUS_MPU_OFFSET ; 
 size_t OMAP3_PRM_REVISION_OFFSET ; 
 int OMAP_RST_DPLL3_MASK ; 
 size_t PM_WKST1 ; 
 int PRM_HAS_IO_WAKEUP ; 
 int __ffs (int) ; 
 TYPE_4__ cm_base ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 struct device_node* of_find_matching_node (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int of_irq_get (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap3430_pre_es3_1_reconfigure_io_chain ; 
 scalar_t__ omap3_has_io_chain_ctrl () ; 
 TYPE_2__ omap3_prcm_irq_setup ; 
 int /*<<< orphan*/  omap3_prm_dt_match_table ; 
 int /*<<< orphan*/  omap3_prm_reconfigure_io_chain ; 
 struct omap3_vp* omap3_vp ; 
 int /*<<< orphan*/  omap3xxx_prm_enable_io_wakeup () ; 
 int omap_prcm_register_chain_handler (TYPE_2__*) ; 
 scalar_t__ omap_rev () ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 TYPE_1__ prm_base ; 
 int prm_features ; 
 int readl_relaxed (size_t) ; 
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

__attribute__((used)) static u32 omap3_prm_vp_check_txdone(u8 vp_id)
{
	struct omap3_vp *vp = &omap3_vp[vp_id];
	u32 irqstatus;

	irqstatus = omap2_prm_read_mod_reg(OCP_MOD,
					   OMAP3_PRM_IRQSTATUS_MPU_OFFSET);
	return irqstatus & vp->tranxdone_status;
}

__attribute__((used)) static void omap3_prm_vp_clear_txdone(u8 vp_id)
{
	struct omap3_vp *vp = &omap3_vp[vp_id];

	omap2_prm_write_mod_reg(vp->tranxdone_status,
				OCP_MOD, OMAP3_PRM_IRQSTATUS_MPU_OFFSET);
}

u32 omap3_prm_vcvp_read(u8 offset)
{
	return omap2_prm_read_mod_reg(OMAP3430_GR_MOD, offset);
}

void omap3_prm_vcvp_write(u32 val, u8 offset)
{
	omap2_prm_write_mod_reg(val, OMAP3430_GR_MOD, offset);
}

u32 omap3_prm_vcvp_rmw(u32 mask, u32 bits, u8 offset)
{
	return omap2_prm_rmw_mod_reg_bits(mask, bits, OMAP3430_GR_MOD, offset);
}

__attribute__((used)) static void omap3xxx_prm_dpll3_reset(void)
{
	omap2_prm_set_mod_reg_bits(OMAP_RST_DPLL3_MASK, OMAP3430_GR_MOD,
				   OMAP2_RM_RSTCTRL);
	/* OCP barrier */
	omap2_prm_read_mod_reg(OMAP3430_GR_MOD, OMAP2_RM_RSTCTRL);
}

__attribute__((used)) static void omap3xxx_prm_read_pending_irqs(unsigned long *events)
{
	u32 mask, st;

	/* XXX Can the mask read be avoided (e.g., can it come from RAM?) */
	mask = omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_IRQENABLE_MPU_OFFSET);
	st = omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_IRQSTATUS_MPU_OFFSET);

	events[0] = mask & st;
}

__attribute__((used)) static void omap3xxx_prm_ocp_barrier(void)
{
	omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_REVISION_OFFSET);
}

__attribute__((used)) static void omap3xxx_prm_save_and_clear_irqen(u32 *saved_mask)
{
	saved_mask[0] = omap2_prm_read_mod_reg(OCP_MOD,
					       OMAP3_PRM_IRQENABLE_MPU_OFFSET);
	omap2_prm_write_mod_reg(0, OCP_MOD, OMAP3_PRM_IRQENABLE_MPU_OFFSET);

	/* OCP barrier */
	omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_REVISION_OFFSET);
}

__attribute__((used)) static void omap3xxx_prm_restore_irqen(u32 *saved_mask)
{
	omap2_prm_write_mod_reg(saved_mask[0], OCP_MOD,
				OMAP3_PRM_IRQENABLE_MPU_OFFSET);
}

__attribute__((used)) static int omap3xxx_prm_clear_mod_irqs(s16 module, u8 regs, u32 wkst_mask)
{
	u32 wkst, fclk, iclk, clken;
	u16 wkst_off = (regs == 3) ? OMAP3430ES2_PM_WKST3 : PM_WKST1;
	u16 fclk_off = (regs == 3) ? OMAP3430ES2_CM_FCLKEN3 : CM_FCLKEN1;
	u16 iclk_off = (regs == 3) ? CM_ICLKEN3 : CM_ICLKEN1;
	u16 grpsel_off = (regs == 3) ?
		OMAP3430ES2_PM_MPUGRPSEL3 : OMAP3430_PM_MPUGRPSEL;
	int c = 0;

	wkst = omap2_prm_read_mod_reg(module, wkst_off);
	wkst &= omap2_prm_read_mod_reg(module, grpsel_off);
	wkst &= wkst_mask;
	if (wkst) {
		iclk = omap2_cm_read_mod_reg(module, iclk_off);
		fclk = omap2_cm_read_mod_reg(module, fclk_off);
		while (wkst) {
			clken = wkst;
			omap2_cm_set_mod_reg_bits(clken, module, iclk_off);
			/*
			 * For USBHOST, we don't know whether HOST1 or
			 * HOST2 woke us up, so enable both f-clocks
			 */
			if (module == OMAP3430ES2_USBHOST_MOD)
				clken |= 1 << OMAP3430ES2_EN_USBHOST2_SHIFT;
			omap2_cm_set_mod_reg_bits(clken, module, fclk_off);
			omap2_prm_write_mod_reg(wkst, module, wkst_off);
			wkst = omap2_prm_read_mod_reg(module, wkst_off);
			wkst &= wkst_mask;
			c++;
		}
		omap2_cm_write_mod_reg(iclk, module, iclk_off);
		omap2_cm_write_mod_reg(fclk, module, fclk_off);
	}

	return c;
}

__attribute__((used)) static int omap3xxx_prm_late_init(void)
{
	struct device_node *np;
	int irq_num;

	if (!(prm_features & PRM_HAS_IO_WAKEUP))
		return 0;

	if (omap3_has_io_chain_ctrl())
		omap3_prcm_irq_setup.reconfigure_io_chain =
			omap3_prm_reconfigure_io_chain;
	else
		omap3_prcm_irq_setup.reconfigure_io_chain =
			omap3430_pre_es3_1_reconfigure_io_chain;

	np = of_find_matching_node(NULL, omap3_prm_dt_match_table);
	if (!np) {
		pr_err("PRM: no device tree node for interrupt?\n");

		return -ENODEV;
	}

	irq_num = of_irq_get(np, 0);
	if (irq_num == -EPROBE_DEFER)
		return irq_num;

	omap3_prcm_irq_setup.irq = irq_num;

	omap3xxx_prm_enable_io_wakeup();

	return omap_prcm_register_chain_handler(&omap3_prcm_irq_setup);
}

