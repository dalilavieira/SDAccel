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
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct debug_info {int bps_disabled; int wps_disabled; int suspended_step; } ;
struct TYPE_10__ {struct debug_info debug; } ;
struct task_struct {TYPE_3__ thread; } ;
struct pt_regs {int dummy; } ;
struct perf_event_attr {int bp_type; int bp_len; unsigned long bp_addr; int /*<<< orphan*/  disabled; } ;
struct TYPE_8__ {struct task_struct* target; } ;
struct perf_event {TYPE_1__ hw; } ;
struct notifier_block {int dummy; } ;
struct arch_hw_breakpoint_ctrl {int type; int len; } ;
struct TYPE_12__ {int privilege; scalar_t__ type; int len; int enabled; } ;
struct arch_hw_breakpoint {int address; int trigger; TYPE_6__ ctrl; } ;
typedef  enum hw_breakpoint_ops { ____Placeholder_hw_breakpoint_ops } hw_breakpoint_ops ;
typedef  enum dbg_active_el { ____Placeholder_dbg_active_el } dbg_active_el ;
struct TYPE_9__ {struct debug_info debug; } ;
struct TYPE_11__ {TYPE_2__ thread; } ;

/* Variables and functions */
#define  AARCH64_BREAKPOINT_EL0 159 
#define  AARCH64_BREAKPOINT_EL1 158 
#define  AARCH64_DBG_REG_BCR 157 
 int AARCH64_DBG_REG_BVR ; 
 int /*<<< orphan*/  AARCH64_DBG_REG_NAME_BCR ; 
 int /*<<< orphan*/  AARCH64_DBG_REG_NAME_BVR ; 
 int /*<<< orphan*/  AARCH64_DBG_REG_NAME_WCR ; 
 int /*<<< orphan*/  AARCH64_DBG_REG_NAME_WVR ; 
#define  AARCH64_DBG_REG_WCR 156 
 int AARCH64_DBG_REG_WVR ; 
 unsigned int AARCH64_ESR_ACCESS_MASK ; 
#define  ARM_BREAKPOINT_EXECUTE 155 
#define  ARM_BREAKPOINT_LEN_1 154 
#define  ARM_BREAKPOINT_LEN_2 153 
#define  ARM_BREAKPOINT_LEN_3 152 
#define  ARM_BREAKPOINT_LEN_4 151 
#define  ARM_BREAKPOINT_LEN_5 150 
#define  ARM_BREAKPOINT_LEN_6 149 
#define  ARM_BREAKPOINT_LEN_7 148 
#define  ARM_BREAKPOINT_LEN_8 147 
#define  ARM_BREAKPOINT_LOAD 146 
#define  ARM_BREAKPOINT_STORE 145 
 int ARM_KERNEL_STEP_ACTIVE ; 
 int ARM_KERNEL_STEP_NONE ; 
 int ARM_KERNEL_STEP_SUSPEND ; 
 int DBG_ACTIVE_EL0 ; 
 int DBG_ACTIVE_EL1 ; 
 int EINVAL ; 
 int ENOSPC ; 
 int /*<<< orphan*/  GEN_READ_WB_REG_CASES (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GEN_WRITE_WB_REG_CASES (int,int /*<<< orphan*/ ,int) ; 
#define  HW_BREAKPOINT_INSTALL 144 
#define  HW_BREAKPOINT_LEN_1 143 
#define  HW_BREAKPOINT_LEN_2 142 
#define  HW_BREAKPOINT_LEN_3 141 
#define  HW_BREAKPOINT_LEN_4 140 
#define  HW_BREAKPOINT_LEN_5 139 
#define  HW_BREAKPOINT_LEN_6 138 
#define  HW_BREAKPOINT_LEN_7 137 
#define  HW_BREAKPOINT_LEN_8 136 
#define  HW_BREAKPOINT_R 135 
#define  HW_BREAKPOINT_RESTORE 134 
#define  HW_BREAKPOINT_RW 133 
#define  HW_BREAKPOINT_UNINSTALL 132 
#define  HW_BREAKPOINT_W 131 
#define  HW_BREAKPOINT_X 130 
 int NOTIFY_DONE ; 
 unsigned long TASK_SIZE ; 
 int /*<<< orphan*/  TIF_SINGLESTEP ; 
#define  TYPE_DATA 129 
#define  TYPE_INST 128 
 scalar_t__ WARN_ONCE (int,char*) ; 
 int __ffs (int) ; 
 int __fls (int) ; 
 int /*<<< orphan*/ * bp_on_reg ; 
 int core_num_brps ; 
 int core_num_wrps ; 
 struct arch_hw_breakpoint* counter_arch_bp (struct perf_event*) ; 
 TYPE_4__* current ; 
 int /*<<< orphan*/  decode_ctrl_reg (int,struct arch_hw_breakpoint_ctrl*) ; 
 int /*<<< orphan*/  disable_debug_monitors (int) ; 
 int /*<<< orphan*/  enable_debug_monitors (int) ; 
 int encode_ctrl_reg (TYPE_6__) ; 
 int get_num_brps () ; 
 int get_num_wrps () ; 
 int hw_breakpoint_type (struct perf_event*) ; 
 int instruction_pointer (struct pt_regs*) ; 
 scalar_t__ is_compat_thread (int /*<<< orphan*/ ) ; 
 scalar_t__ is_default_overflow_handler (struct perf_event*) ; 
 int /*<<< orphan*/  isb () ; 
 scalar_t__ kernel_active_single_step () ; 
 int /*<<< orphan*/  kernel_disable_single_step () ; 
 int /*<<< orphan*/  kernel_enable_single_step (struct pt_regs*) ; 
 int /*<<< orphan*/  perf_bp_event (struct perf_event*,struct pt_regs*) ; 
 int /*<<< orphan*/  pr_warn_once (char*,int) ; 
 int /*<<< orphan*/  pr_warning (char*,int) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  stepping_kernel_bp ; 
 int /*<<< orphan*/  task_thread_info (struct task_struct*) ; 
 scalar_t__ test_thread_flag (int /*<<< orphan*/ ) ; 
 void* this_cpu_ptr (int /*<<< orphan*/ *) ; 
 unsigned long untagged_addr (unsigned long) ; 
 int /*<<< orphan*/  user_disable_single_step (TYPE_4__*) ; 
 int /*<<< orphan*/  user_enable_single_step (TYPE_4__*) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 
 int /*<<< orphan*/ * wp_on_reg ; 

int hw_breakpoint_slots(int type)
{
	/*
	 * We can be called early, so don't rely on
	 * our static variables being initialised.
	 */
	switch (type) {
	case TYPE_INST:
		return get_num_brps();
	case TYPE_DATA:
		return get_num_wrps();
	default:
		pr_warning("unknown slot type: %d\n", type);
		return 0;
	}
}

__attribute__((used)) static u64 read_wb_reg(int reg, int n)
{
	u64 val = 0;

	switch (reg + n) {
	GEN_READ_WB_REG_CASES(AARCH64_DBG_REG_BVR, AARCH64_DBG_REG_NAME_BVR, val);
	GEN_READ_WB_REG_CASES(AARCH64_DBG_REG_BCR, AARCH64_DBG_REG_NAME_BCR, val);
	GEN_READ_WB_REG_CASES(AARCH64_DBG_REG_WVR, AARCH64_DBG_REG_NAME_WVR, val);
	GEN_READ_WB_REG_CASES(AARCH64_DBG_REG_WCR, AARCH64_DBG_REG_NAME_WCR, val);
	default:
		pr_warning("attempt to read from unknown breakpoint register %d\n", n);
	}

	return val;
}

__attribute__((used)) static void write_wb_reg(int reg, int n, u64 val)
{
	switch (reg + n) {
	GEN_WRITE_WB_REG_CASES(AARCH64_DBG_REG_BVR, AARCH64_DBG_REG_NAME_BVR, val);
	GEN_WRITE_WB_REG_CASES(AARCH64_DBG_REG_BCR, AARCH64_DBG_REG_NAME_BCR, val);
	GEN_WRITE_WB_REG_CASES(AARCH64_DBG_REG_WVR, AARCH64_DBG_REG_NAME_WVR, val);
	GEN_WRITE_WB_REG_CASES(AARCH64_DBG_REG_WCR, AARCH64_DBG_REG_NAME_WCR, val);
	default:
		pr_warning("attempt to write to unknown breakpoint register %d\n", n);
	}
	isb();
}

__attribute__((used)) static enum dbg_active_el debug_exception_level(int privilege)
{
	switch (privilege) {
	case AARCH64_BREAKPOINT_EL0:
		return DBG_ACTIVE_EL0;
	case AARCH64_BREAKPOINT_EL1:
		return DBG_ACTIVE_EL1;
	default:
		pr_warning("invalid breakpoint privilege level %d\n", privilege);
		return -EINVAL;
	}
}

__attribute__((used)) static int is_compat_bp(struct perf_event *bp)
{
	struct task_struct *tsk = bp->hw.target;

	/*
	 * tsk can be NULL for per-cpu (non-ptrace) breakpoints.
	 * In this case, use the native interface, since we don't have
	 * the notion of a "compat CPU" and could end up relying on
	 * deprecated behaviour if we use unaligned watchpoints in
	 * AArch64 state.
	 */
	return tsk && is_compat_thread(task_thread_info(tsk));
}

__attribute__((used)) static int hw_breakpoint_slot_setup(struct perf_event **slots, int max_slots,
				    struct perf_event *bp,
				    enum hw_breakpoint_ops ops)
{
	int i;
	struct perf_event **slot;

	for (i = 0; i < max_slots; ++i) {
		slot = &slots[i];
		switch (ops) {
		case HW_BREAKPOINT_INSTALL:
			if (!*slot) {
				*slot = bp;
				return i;
			}
			break;
		case HW_BREAKPOINT_UNINSTALL:
			if (*slot == bp) {
				*slot = NULL;
				return i;
			}
			break;
		case HW_BREAKPOINT_RESTORE:
			if (*slot == bp)
				return i;
			break;
		default:
			pr_warn_once("Unhandled hw breakpoint ops %d\n", ops);
			return -EINVAL;
		}
	}
	return -ENOSPC;
}

__attribute__((used)) static int hw_breakpoint_control(struct perf_event *bp,
				 enum hw_breakpoint_ops ops)
{
	struct arch_hw_breakpoint *info = counter_arch_bp(bp);
	struct perf_event **slots;
	struct debug_info *debug_info = &current->thread.debug;
	int i, max_slots, ctrl_reg, val_reg, reg_enable;
	enum dbg_active_el dbg_el = debug_exception_level(info->ctrl.privilege);
	u32 ctrl;

	if (info->ctrl.type == ARM_BREAKPOINT_EXECUTE) {
		/* Breakpoint */
		ctrl_reg = AARCH64_DBG_REG_BCR;
		val_reg = AARCH64_DBG_REG_BVR;
		slots = this_cpu_ptr(bp_on_reg);
		max_slots = core_num_brps;
		reg_enable = !debug_info->bps_disabled;
	} else {
		/* Watchpoint */
		ctrl_reg = AARCH64_DBG_REG_WCR;
		val_reg = AARCH64_DBG_REG_WVR;
		slots = this_cpu_ptr(wp_on_reg);
		max_slots = core_num_wrps;
		reg_enable = !debug_info->wps_disabled;
	}

	i = hw_breakpoint_slot_setup(slots, max_slots, bp, ops);

	if (WARN_ONCE(i < 0, "Can't find any breakpoint slot"))
		return i;

	switch (ops) {
	case HW_BREAKPOINT_INSTALL:
		/*
		 * Ensure debug monitors are enabled at the correct exception
		 * level.
		 */
		enable_debug_monitors(dbg_el);
		/* Fall through */
	case HW_BREAKPOINT_RESTORE:
		/* Setup the address register. */
		write_wb_reg(val_reg, i, info->address);

		/* Setup the control register. */
		ctrl = encode_ctrl_reg(info->ctrl);
		write_wb_reg(ctrl_reg, i,
			     reg_enable ? ctrl | 0x1 : ctrl & ~0x1);
		break;
	case HW_BREAKPOINT_UNINSTALL:
		/* Reset the control register. */
		write_wb_reg(ctrl_reg, i, 0);

		/*
		 * Release the debug monitors for the correct exception
		 * level.
		 */
		disable_debug_monitors(dbg_el);
		break;
	}

	return 0;
}

int arch_install_hw_breakpoint(struct perf_event *bp)
{
	return hw_breakpoint_control(bp, HW_BREAKPOINT_INSTALL);
}

void arch_uninstall_hw_breakpoint(struct perf_event *bp)
{
	hw_breakpoint_control(bp, HW_BREAKPOINT_UNINSTALL);
}

__attribute__((used)) static int get_hbp_len(u8 hbp_len)
{
	unsigned int len_in_bytes = 0;

	switch (hbp_len) {
	case ARM_BREAKPOINT_LEN_1:
		len_in_bytes = 1;
		break;
	case ARM_BREAKPOINT_LEN_2:
		len_in_bytes = 2;
		break;
	case ARM_BREAKPOINT_LEN_3:
		len_in_bytes = 3;
		break;
	case ARM_BREAKPOINT_LEN_4:
		len_in_bytes = 4;
		break;
	case ARM_BREAKPOINT_LEN_5:
		len_in_bytes = 5;
		break;
	case ARM_BREAKPOINT_LEN_6:
		len_in_bytes = 6;
		break;
	case ARM_BREAKPOINT_LEN_7:
		len_in_bytes = 7;
		break;
	case ARM_BREAKPOINT_LEN_8:
		len_in_bytes = 8;
		break;
	}

	return len_in_bytes;
}

int arch_check_bp_in_kernelspace(struct arch_hw_breakpoint *hw)
{
	unsigned int len;
	unsigned long va;

	va = hw->address;
	len = get_hbp_len(hw->ctrl.len);

	return (va >= TASK_SIZE) && ((va + len - 1) >= TASK_SIZE);
}

int arch_bp_generic_fields(struct arch_hw_breakpoint_ctrl ctrl,
			   int *gen_len, int *gen_type, int *offset)
{
	/* Type */
	switch (ctrl.type) {
	case ARM_BREAKPOINT_EXECUTE:
		*gen_type = HW_BREAKPOINT_X;
		break;
	case ARM_BREAKPOINT_LOAD:
		*gen_type = HW_BREAKPOINT_R;
		break;
	case ARM_BREAKPOINT_STORE:
		*gen_type = HW_BREAKPOINT_W;
		break;
	case ARM_BREAKPOINT_LOAD | ARM_BREAKPOINT_STORE:
		*gen_type = HW_BREAKPOINT_RW;
		break;
	default:
		return -EINVAL;
	}

	if (!ctrl.len)
		return -EINVAL;
	*offset = __ffs(ctrl.len);

	/* Len */
	switch (ctrl.len >> *offset) {
	case ARM_BREAKPOINT_LEN_1:
		*gen_len = HW_BREAKPOINT_LEN_1;
		break;
	case ARM_BREAKPOINT_LEN_2:
		*gen_len = HW_BREAKPOINT_LEN_2;
		break;
	case ARM_BREAKPOINT_LEN_3:
		*gen_len = HW_BREAKPOINT_LEN_3;
		break;
	case ARM_BREAKPOINT_LEN_4:
		*gen_len = HW_BREAKPOINT_LEN_4;
		break;
	case ARM_BREAKPOINT_LEN_5:
		*gen_len = HW_BREAKPOINT_LEN_5;
		break;
	case ARM_BREAKPOINT_LEN_6:
		*gen_len = HW_BREAKPOINT_LEN_6;
		break;
	case ARM_BREAKPOINT_LEN_7:
		*gen_len = HW_BREAKPOINT_LEN_7;
		break;
	case ARM_BREAKPOINT_LEN_8:
		*gen_len = HW_BREAKPOINT_LEN_8;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int arch_build_bp_info(struct perf_event *bp,
			      const struct perf_event_attr *attr,
			      struct arch_hw_breakpoint *hw)
{
	/* Type */
	switch (attr->bp_type) {
	case HW_BREAKPOINT_X:
		hw->ctrl.type = ARM_BREAKPOINT_EXECUTE;
		break;
	case HW_BREAKPOINT_R:
		hw->ctrl.type = ARM_BREAKPOINT_LOAD;
		break;
	case HW_BREAKPOINT_W:
		hw->ctrl.type = ARM_BREAKPOINT_STORE;
		break;
	case HW_BREAKPOINT_RW:
		hw->ctrl.type = ARM_BREAKPOINT_LOAD | ARM_BREAKPOINT_STORE;
		break;
	default:
		return -EINVAL;
	}

	/* Len */
	switch (attr->bp_len) {
	case HW_BREAKPOINT_LEN_1:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_1;
		break;
	case HW_BREAKPOINT_LEN_2:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_2;
		break;
	case HW_BREAKPOINT_LEN_3:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_3;
		break;
	case HW_BREAKPOINT_LEN_4:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_4;
		break;
	case HW_BREAKPOINT_LEN_5:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_5;
		break;
	case HW_BREAKPOINT_LEN_6:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_6;
		break;
	case HW_BREAKPOINT_LEN_7:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_7;
		break;
	case HW_BREAKPOINT_LEN_8:
		hw->ctrl.len = ARM_BREAKPOINT_LEN_8;
		break;
	default:
		return -EINVAL;
	}

	/*
	 * On AArch64, we only permit breakpoints of length 4, whereas
	 * AArch32 also requires breakpoints of length 2 for Thumb.
	 * Watchpoints can be of length 1, 2, 4 or 8 bytes.
	 */
	if (hw->ctrl.type == ARM_BREAKPOINT_EXECUTE) {
		if (is_compat_bp(bp)) {
			if (hw->ctrl.len != ARM_BREAKPOINT_LEN_2 &&
			    hw->ctrl.len != ARM_BREAKPOINT_LEN_4)
				return -EINVAL;
		} else if (hw->ctrl.len != ARM_BREAKPOINT_LEN_4) {
			/*
			 * FIXME: Some tools (I'm looking at you perf) assume
			 *	  that breakpoints should be sizeof(long). This
			 *	  is nonsense. For now, we fix up the parameter
			 *	  but we should probably return -EINVAL instead.
			 */
			hw->ctrl.len = ARM_BREAKPOINT_LEN_4;
		}
	}

	/* Address */
	hw->address = attr->bp_addr;

	/*
	 * Privilege
	 * Note that we disallow combined EL0/EL1 breakpoints because
	 * that would complicate the stepping code.
	 */
	if (arch_check_bp_in_kernelspace(hw))
		hw->ctrl.privilege = AARCH64_BREAKPOINT_EL1;
	else
		hw->ctrl.privilege = AARCH64_BREAKPOINT_EL0;

	/* Enabled? */
	hw->ctrl.enabled = !attr->disabled;

	return 0;
}

int hw_breakpoint_arch_parse(struct perf_event *bp,
			     const struct perf_event_attr *attr,
			     struct arch_hw_breakpoint *hw)
{
	int ret;
	u64 alignment_mask, offset;

	/* Build the arch_hw_breakpoint. */
	ret = arch_build_bp_info(bp, attr, hw);
	if (ret)
		return ret;

	/*
	 * Check address alignment.
	 * We don't do any clever alignment correction for watchpoints
	 * because using 64-bit unaligned addresses is deprecated for
	 * AArch64.
	 *
	 * AArch32 tasks expect some simple alignment fixups, so emulate
	 * that here.
	 */
	if (is_compat_bp(bp)) {
		if (hw->ctrl.len == ARM_BREAKPOINT_LEN_8)
			alignment_mask = 0x7;
		else
			alignment_mask = 0x3;
		offset = hw->address & alignment_mask;
		switch (offset) {
		case 0:
			/* Aligned */
			break;
		case 1:
			/* Allow single byte watchpoint. */
			if (hw->ctrl.len == ARM_BREAKPOINT_LEN_1)
				break;
		case 2:
			/* Allow halfword watchpoints and breakpoints. */
			if (hw->ctrl.len == ARM_BREAKPOINT_LEN_2)
				break;
		default:
			return -EINVAL;
		}
	} else {
		if (hw->ctrl.type == ARM_BREAKPOINT_EXECUTE)
			alignment_mask = 0x3;
		else
			alignment_mask = 0x7;
		offset = hw->address & alignment_mask;
	}

	hw->address &= ~alignment_mask;
	hw->ctrl.len <<= offset;

	/*
	 * Disallow per-task kernel breakpoints since these would
	 * complicate the stepping code.
	 */
	if (hw->ctrl.privilege == AARCH64_BREAKPOINT_EL1 && bp->hw.target)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static void toggle_bp_registers(int reg, enum dbg_active_el el, int enable)
{
	int i, max_slots, privilege;
	u32 ctrl;
	struct perf_event **slots;

	switch (reg) {
	case AARCH64_DBG_REG_BCR:
		slots = this_cpu_ptr(bp_on_reg);
		max_slots = core_num_brps;
		break;
	case AARCH64_DBG_REG_WCR:
		slots = this_cpu_ptr(wp_on_reg);
		max_slots = core_num_wrps;
		break;
	default:
		return;
	}

	for (i = 0; i < max_slots; ++i) {
		if (!slots[i])
			continue;

		privilege = counter_arch_bp(slots[i])->ctrl.privilege;
		if (debug_exception_level(privilege) != el)
			continue;

		ctrl = read_wb_reg(reg, i);
		if (enable)
			ctrl |= 0x1;
		else
			ctrl &= ~0x1;
		write_wb_reg(reg, i, ctrl);
	}
}

__attribute__((used)) static int breakpoint_handler(unsigned long unused, unsigned int esr,
			      struct pt_regs *regs)
{
	int i, step = 0, *kernel_step;
	u32 ctrl_reg;
	u64 addr, val;
	struct perf_event *bp, **slots;
	struct debug_info *debug_info;
	struct arch_hw_breakpoint_ctrl ctrl;

	slots = this_cpu_ptr(bp_on_reg);
	addr = instruction_pointer(regs);
	debug_info = &current->thread.debug;

	for (i = 0; i < core_num_brps; ++i) {
		rcu_read_lock();

		bp = slots[i];

		if (bp == NULL)
			goto unlock;

		/* Check if the breakpoint value matches. */
		val = read_wb_reg(AARCH64_DBG_REG_BVR, i);
		if (val != (addr & ~0x3))
			goto unlock;

		/* Possible match, check the byte address select to confirm. */
		ctrl_reg = read_wb_reg(AARCH64_DBG_REG_BCR, i);
		decode_ctrl_reg(ctrl_reg, &ctrl);
		if (!((1 << (addr & 0x3)) & ctrl.len))
			goto unlock;

		counter_arch_bp(bp)->trigger = addr;
		perf_bp_event(bp, regs);

		/* Do we need to handle the stepping? */
		if (is_default_overflow_handler(bp))
			step = 1;
unlock:
		rcu_read_unlock();
	}

	if (!step)
		return 0;

	if (user_mode(regs)) {
		debug_info->bps_disabled = 1;
		toggle_bp_registers(AARCH64_DBG_REG_BCR, DBG_ACTIVE_EL0, 0);

		/* If we're already stepping a watchpoint, just return. */
		if (debug_info->wps_disabled)
			return 0;

		if (test_thread_flag(TIF_SINGLESTEP))
			debug_info->suspended_step = 1;
		else
			user_enable_single_step(current);
	} else {
		toggle_bp_registers(AARCH64_DBG_REG_BCR, DBG_ACTIVE_EL1, 0);
		kernel_step = this_cpu_ptr(&stepping_kernel_bp);

		if (*kernel_step != ARM_KERNEL_STEP_NONE)
			return 0;

		if (kernel_active_single_step()) {
			*kernel_step = ARM_KERNEL_STEP_SUSPEND;
		} else {
			*kernel_step = ARM_KERNEL_STEP_ACTIVE;
			kernel_enable_single_step(regs);
		}
	}

	return 0;
}

__attribute__((used)) static u64 get_distance_from_watchpoint(unsigned long addr, u64 val,
					struct arch_hw_breakpoint_ctrl *ctrl)
{
	u64 wp_low, wp_high;
	u32 lens, lene;

	addr = untagged_addr(addr);

	lens = __ffs(ctrl->len);
	lene = __fls(ctrl->len);

	wp_low = val + lens;
	wp_high = val + lene;
	if (addr < wp_low)
		return wp_low - addr;
	else if (addr > wp_high)
		return addr - wp_high;
	else
		return 0;
}

__attribute__((used)) static int watchpoint_handler(unsigned long addr, unsigned int esr,
			      struct pt_regs *regs)
{
	int i, step = 0, *kernel_step, access, closest_match = 0;
	u64 min_dist = -1, dist;
	u32 ctrl_reg;
	u64 val;
	struct perf_event *wp, **slots;
	struct debug_info *debug_info;
	struct arch_hw_breakpoint *info;
	struct arch_hw_breakpoint_ctrl ctrl;

	slots = this_cpu_ptr(wp_on_reg);
	debug_info = &current->thread.debug;

	/*
	 * Find all watchpoints that match the reported address. If no exact
	 * match is found. Attribute the hit to the closest watchpoint.
	 */
	rcu_read_lock();
	for (i = 0; i < core_num_wrps; ++i) {
		wp = slots[i];
		if (wp == NULL)
			continue;

		/*
		 * Check that the access type matches.
		 * 0 => load, otherwise => store
		 */
		access = (esr & AARCH64_ESR_ACCESS_MASK) ? HW_BREAKPOINT_W :
			 HW_BREAKPOINT_R;
		if (!(access & hw_breakpoint_type(wp)))
			continue;

		/* Check if the watchpoint value and byte select match. */
		val = read_wb_reg(AARCH64_DBG_REG_WVR, i);
		ctrl_reg = read_wb_reg(AARCH64_DBG_REG_WCR, i);
		decode_ctrl_reg(ctrl_reg, &ctrl);
		dist = get_distance_from_watchpoint(addr, val, &ctrl);
		if (dist < min_dist) {
			min_dist = dist;
			closest_match = i;
		}
		/* Is this an exact match? */
		if (dist != 0)
			continue;

		info = counter_arch_bp(wp);
		info->trigger = addr;
		perf_bp_event(wp, regs);

		/* Do we need to handle the stepping? */
		if (is_default_overflow_handler(wp))
			step = 1;
	}
	if (min_dist > 0 && min_dist != -1) {
		/* No exact match found. */
		wp = slots[closest_match];
		info = counter_arch_bp(wp);
		info->trigger = addr;
		perf_bp_event(wp, regs);

		/* Do we need to handle the stepping? */
		if (is_default_overflow_handler(wp))
			step = 1;
	}
	rcu_read_unlock();

	if (!step)
		return 0;

	/*
	 * We always disable EL0 watchpoints because the kernel can
	 * cause these to fire via an unprivileged access.
	 */
	toggle_bp_registers(AARCH64_DBG_REG_WCR, DBG_ACTIVE_EL0, 0);

	if (user_mode(regs)) {
		debug_info->wps_disabled = 1;

		/* If we're already stepping a breakpoint, just return. */
		if (debug_info->bps_disabled)
			return 0;

		if (test_thread_flag(TIF_SINGLESTEP))
			debug_info->suspended_step = 1;
		else
			user_enable_single_step(current);
	} else {
		toggle_bp_registers(AARCH64_DBG_REG_WCR, DBG_ACTIVE_EL1, 0);
		kernel_step = this_cpu_ptr(&stepping_kernel_bp);

		if (*kernel_step != ARM_KERNEL_STEP_NONE)
			return 0;

		if (kernel_active_single_step()) {
			*kernel_step = ARM_KERNEL_STEP_SUSPEND;
		} else {
			*kernel_step = ARM_KERNEL_STEP_ACTIVE;
			kernel_enable_single_step(regs);
		}
	}

	return 0;
}

int reinstall_suspended_bps(struct pt_regs *regs)
{
	struct debug_info *debug_info = &current->thread.debug;
	int handled_exception = 0, *kernel_step;

	kernel_step = this_cpu_ptr(&stepping_kernel_bp);

	/*
	 * Called from single-step exception handler.
	 * Return 0 if execution can resume, 1 if a SIGTRAP should be
	 * reported.
	 */
	if (user_mode(regs)) {
		if (debug_info->bps_disabled) {
			debug_info->bps_disabled = 0;
			toggle_bp_registers(AARCH64_DBG_REG_BCR, DBG_ACTIVE_EL0, 1);
			handled_exception = 1;
		}

		if (debug_info->wps_disabled) {
			debug_info->wps_disabled = 0;
			toggle_bp_registers(AARCH64_DBG_REG_WCR, DBG_ACTIVE_EL0, 1);
			handled_exception = 1;
		}

		if (handled_exception) {
			if (debug_info->suspended_step) {
				debug_info->suspended_step = 0;
				/* Allow exception handling to fall-through. */
				handled_exception = 0;
			} else {
				user_disable_single_step(current);
			}
		}
	} else if (*kernel_step != ARM_KERNEL_STEP_NONE) {
		toggle_bp_registers(AARCH64_DBG_REG_BCR, DBG_ACTIVE_EL1, 1);
		toggle_bp_registers(AARCH64_DBG_REG_WCR, DBG_ACTIVE_EL1, 1);

		if (!debug_info->wps_disabled)
			toggle_bp_registers(AARCH64_DBG_REG_WCR, DBG_ACTIVE_EL0, 1);

		if (*kernel_step != ARM_KERNEL_STEP_SUSPEND) {
			kernel_disable_single_step();
			handled_exception = 1;
		} else {
			handled_exception = 0;
		}

		*kernel_step = ARM_KERNEL_STEP_NONE;
	}

	return !handled_exception;
}

void hw_breakpoint_thread_switch(struct task_struct *next)
{
	/*
	 *           current        next
	 * disabled: 0              0     => The usual case, NOTIFY_DONE
	 *           0              1     => Disable the registers
	 *           1              0     => Enable the registers
	 *           1              1     => NOTIFY_DONE. per-task bps will
	 *                                   get taken care of by perf.
	 */

	struct debug_info *current_debug_info, *next_debug_info;

	current_debug_info = &current->thread.debug;
	next_debug_info = &next->thread.debug;

	/* Update breakpoints. */
	if (current_debug_info->bps_disabled != next_debug_info->bps_disabled)
		toggle_bp_registers(AARCH64_DBG_REG_BCR,
				    DBG_ACTIVE_EL0,
				    !next_debug_info->bps_disabled);

	/* Update watchpoints. */
	if (current_debug_info->wps_disabled != next_debug_info->wps_disabled)
		toggle_bp_registers(AARCH64_DBG_REG_WCR,
				    DBG_ACTIVE_EL0,
				    !next_debug_info->wps_disabled);
}

__attribute__((used)) static int hw_breakpoint_reset(unsigned int cpu)
{
	int i;
	struct perf_event **slots;
	/*
	 * When a CPU goes through cold-boot, it does not have any installed
	 * slot, so it is safe to share the same function for restoring and
	 * resetting breakpoints; when a CPU is hotplugged in, it goes
	 * through the slots, which are all empty, hence it just resets control
	 * and value for debug registers.
	 * When this function is triggered on warm-boot through a CPU PM
	 * notifier some slots might be initialized; if so they are
	 * reprogrammed according to the debug slots content.
	 */
	for (slots = this_cpu_ptr(bp_on_reg), i = 0; i < core_num_brps; ++i) {
		if (slots[i]) {
			hw_breakpoint_control(slots[i], HW_BREAKPOINT_RESTORE);
		} else {
			write_wb_reg(AARCH64_DBG_REG_BCR, i, 0UL);
			write_wb_reg(AARCH64_DBG_REG_BVR, i, 0UL);
		}
	}

	for (slots = this_cpu_ptr(wp_on_reg), i = 0; i < core_num_wrps; ++i) {
		if (slots[i]) {
			hw_breakpoint_control(slots[i], HW_BREAKPOINT_RESTORE);
		} else {
			write_wb_reg(AARCH64_DBG_REG_WCR, i, 0UL);
			write_wb_reg(AARCH64_DBG_REG_WVR, i, 0UL);
		}
	}

	return 0;
}

__attribute__((used)) static inline void cpu_suspend_set_dbg_restorer(int (*hw_bp_restore)(unsigned int))
{
}

void hw_breakpoint_pmu_read(struct perf_event *bp)
{
}

int hw_breakpoint_exceptions_notify(struct notifier_block *unused,
				    unsigned long val, void *data)
{
	return NOTIFY_DONE;
}

