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
struct thread_struct {int /*<<< orphan*/ ** ptrace_wp; int /*<<< orphan*/ ** ptrace_bp; } ;
struct task_struct {struct thread_struct thread; } ;
struct pt_regs {int debugcause; scalar_t__ pc; } ;
struct perf_event_attr {int bp_type; unsigned int bp_len; unsigned long bp_addr; } ;
struct TYPE_2__ {scalar_t__ bp_addr; int /*<<< orphan*/  disabled; } ;
struct perf_event {TYPE_1__ attr; } ;
struct notifier_block {int dummy; } ;
struct arch_hw_breakpoint {unsigned long address; unsigned int len; int type; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 unsigned long DBREAKC_LOAD_MASK ; 
 unsigned long DBREAKC_MASK_MASK ; 
 unsigned long DBREAKC_STOR_MASK ; 
 int DEBUGCAUSE_DBNUM_MASK ; 
 int DEBUGCAUSE_DBNUM_SHIFT ; 
 int /*<<< orphan*/  DEBUGCAUSE_DBREAK_BIT ; 
 int /*<<< orphan*/  DEBUGCAUSE_IBREAK_BIT ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOENT ; 
#define  HW_BREAKPOINT_R 133 
#define  HW_BREAKPOINT_RW 132 
#define  HW_BREAKPOINT_W 131 
#define  HW_BREAKPOINT_X 130 
 int NOTIFY_DONE ; 
 int /*<<< orphan*/  RSR (unsigned long,int /*<<< orphan*/ ) ; 
 int SREG_DBREAKA ; 
 int SREG_DBREAKC ; 
 int SREG_IBREAKA ; 
 int /*<<< orphan*/  SREG_IBREAKENABLE ; 
 unsigned long TASK_SIZE ; 
 int /*<<< orphan*/  TIF_DB_DISABLED ; 
#define  TYPE_DATA 129 
#define  TYPE_INST 128 
 int /*<<< orphan*/  WARN_ONCE (int,char*,int) ; 
 int /*<<< orphan*/  WSR (unsigned long,int /*<<< orphan*/ ) ; 
 int XCHAL_NUM_DBREAK ; 
 int XCHAL_NUM_IBREAK ; 
 scalar_t__ XTENSA_BREAKPOINT_EXECUTE ; 
 int XTENSA_BREAKPOINT_LOAD ; 
 int XTENSA_BREAKPOINT_STORE ; 
 int /*<<< orphan*/  bp_on_reg ; 
 int /*<<< orphan*/  clear_thread_flag (int /*<<< orphan*/ ) ; 
 struct arch_hw_breakpoint* counter_arch_bp (struct perf_event*) ; 
 int /*<<< orphan*/  is_power_of_2 (int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perf_bp_event (struct perf_event*,struct pt_regs*) ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 
 int /*<<< orphan*/  set_thread_flag (int /*<<< orphan*/ ) ; 
 struct perf_event** this_cpu_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unregister_hw_breakpoint (int /*<<< orphan*/ *) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 
 int /*<<< orphan*/  wp_on_reg ; 

int hw_breakpoint_slots(int type)
{
	switch (type) {
	case TYPE_INST:
		return XCHAL_NUM_IBREAK;
	case TYPE_DATA:
		return XCHAL_NUM_DBREAK;
	default:
		pr_warn("unknown slot type: %d\n", type);
		return 0;
	}
}

int arch_check_bp_in_kernelspace(struct arch_hw_breakpoint *hw)
{
	unsigned int len;
	unsigned long va;

	va = hw->address;
	len = hw->len;

	return (va >= TASK_SIZE) && ((va + len - 1) >= TASK_SIZE);
}

int hw_breakpoint_arch_parse(struct perf_event *bp,
			     const struct perf_event_attr *attr,
			     struct arch_hw_breakpoint *hw)
{
	/* Type */
	switch (attr->bp_type) {
	case HW_BREAKPOINT_X:
		hw->type = XTENSA_BREAKPOINT_EXECUTE;
		break;
	case HW_BREAKPOINT_R:
		hw->type = XTENSA_BREAKPOINT_LOAD;
		break;
	case HW_BREAKPOINT_W:
		hw->type = XTENSA_BREAKPOINT_STORE;
		break;
	case HW_BREAKPOINT_RW:
		hw->type = XTENSA_BREAKPOINT_LOAD | XTENSA_BREAKPOINT_STORE;
		break;
	default:
		return -EINVAL;
	}

	/* Len */
	hw->len = attr->bp_len;
	if (hw->len < 1 || hw->len > 64 || !is_power_of_2(hw->len))
		return -EINVAL;

	/* Address */
	hw->address = attr->bp_addr;
	if (hw->address & (hw->len - 1))
		return -EINVAL;

	return 0;
}

int hw_breakpoint_exceptions_notify(struct notifier_block *unused,
				    unsigned long val, void *data)
{
	return NOTIFY_DONE;
}

__attribute__((used)) static void xtensa_wsr(unsigned long v, u8 sr)
{
	/* We don't have indexed wsr and creating instruction dynamically
	 * doesn't seem worth it given how small XCHAL_NUM_IBREAK and
	 * XCHAL_NUM_DBREAK are. Thus the switch. In case build breaks here
	 * the switch below needs to be extended.
	 */
	BUILD_BUG_ON(XCHAL_NUM_IBREAK > 2);
	BUILD_BUG_ON(XCHAL_NUM_DBREAK > 2);

	switch (sr) {
#if XCHAL_NUM_IBREAK > 0
	case SREG_IBREAKA + 0:
		WSR(v, SREG_IBREAKA + 0);
		break;
#endif
#if XCHAL_NUM_IBREAK > 1
	case SREG_IBREAKA + 1:
		WSR(v, SREG_IBREAKA + 1);
		break;
#endif

#if XCHAL_NUM_DBREAK > 0
	case SREG_DBREAKA + 0:
		WSR(v, SREG_DBREAKA + 0);
		break;
	case SREG_DBREAKC + 0:
		WSR(v, SREG_DBREAKC + 0);
		break;
#endif
#if XCHAL_NUM_DBREAK > 1
	case SREG_DBREAKA + 1:
		WSR(v, SREG_DBREAKA + 1);
		break;

	case SREG_DBREAKC + 1:
		WSR(v, SREG_DBREAKC + 1);
		break;
#endif
	}
}

__attribute__((used)) static int alloc_slot(struct perf_event **slot, size_t n,
		      struct perf_event *bp)
{
	size_t i;

	for (i = 0; i < n; ++i) {
		if (!slot[i]) {
			slot[i] = bp;
			return i;
		}
	}
	return -EBUSY;
}

__attribute__((used)) static void set_ibreak_regs(int reg, struct perf_event *bp)
{
	struct arch_hw_breakpoint *info = counter_arch_bp(bp);
	unsigned long ibreakenable;

	xtensa_wsr(info->address, SREG_IBREAKA + reg);
	RSR(ibreakenable, SREG_IBREAKENABLE);
	WSR(ibreakenable | (1 << reg), SREG_IBREAKENABLE);
}

__attribute__((used)) static void set_dbreak_regs(int reg, struct perf_event *bp)
{
	struct arch_hw_breakpoint *info = counter_arch_bp(bp);
	unsigned long dbreakc = DBREAKC_MASK_MASK & -info->len;

	if (info->type & XTENSA_BREAKPOINT_LOAD)
		dbreakc |= DBREAKC_LOAD_MASK;
	if (info->type & XTENSA_BREAKPOINT_STORE)
		dbreakc |= DBREAKC_STOR_MASK;

	xtensa_wsr(info->address, SREG_DBREAKA + reg);
	xtensa_wsr(dbreakc, SREG_DBREAKC + reg);
}

int arch_install_hw_breakpoint(struct perf_event *bp)
{
	int i;

	if (counter_arch_bp(bp)->type == XTENSA_BREAKPOINT_EXECUTE) {
		/* Breakpoint */
		i = alloc_slot(this_cpu_ptr(bp_on_reg), XCHAL_NUM_IBREAK, bp);
		if (i < 0)
			return i;
		set_ibreak_regs(i, bp);

	} else {
		/* Watchpoint */
		i = alloc_slot(this_cpu_ptr(wp_on_reg), XCHAL_NUM_DBREAK, bp);
		if (i < 0)
			return i;
		set_dbreak_regs(i, bp);
	}
	return 0;
}

__attribute__((used)) static int free_slot(struct perf_event **slot, size_t n,
		     struct perf_event *bp)
{
	size_t i;

	for (i = 0; i < n; ++i) {
		if (slot[i] == bp) {
			slot[i] = NULL;
			return i;
		}
	}
	return -EBUSY;
}

void arch_uninstall_hw_breakpoint(struct perf_event *bp)
{
	struct arch_hw_breakpoint *info = counter_arch_bp(bp);
	int i;

	if (info->type == XTENSA_BREAKPOINT_EXECUTE) {
		unsigned long ibreakenable;

		/* Breakpoint */
		i = free_slot(this_cpu_ptr(bp_on_reg), XCHAL_NUM_IBREAK, bp);
		if (i >= 0) {
			RSR(ibreakenable, SREG_IBREAKENABLE);
			WSR(ibreakenable & ~(1 << i), SREG_IBREAKENABLE);
		}
	} else {
		/* Watchpoint */
		i = free_slot(this_cpu_ptr(wp_on_reg), XCHAL_NUM_DBREAK, bp);
		if (i >= 0)
			xtensa_wsr(0, SREG_DBREAKC + i);
	}
}

void hw_breakpoint_pmu_read(struct perf_event *bp)
{
}

void flush_ptrace_hw_breakpoint(struct task_struct *tsk)
{
	int i;
	struct thread_struct *t = &tsk->thread;

	for (i = 0; i < XCHAL_NUM_IBREAK; ++i) {
		if (t->ptrace_bp[i]) {
			unregister_hw_breakpoint(t->ptrace_bp[i]);
			t->ptrace_bp[i] = NULL;
		}
	}
	for (i = 0; i < XCHAL_NUM_DBREAK; ++i) {
		if (t->ptrace_wp[i]) {
			unregister_hw_breakpoint(t->ptrace_wp[i]);
			t->ptrace_wp[i] = NULL;
		}
	}
}

void clear_ptrace_hw_breakpoint(struct task_struct *tsk)
{
	memset(tsk->thread.ptrace_bp, 0, sizeof(tsk->thread.ptrace_bp));
	memset(tsk->thread.ptrace_wp, 0, sizeof(tsk->thread.ptrace_wp));
}

void restore_dbreak(void)
{
	int i;

	for (i = 0; i < XCHAL_NUM_DBREAK; ++i) {
		struct perf_event *bp = this_cpu_ptr(wp_on_reg)[i];

		if (bp)
			set_dbreak_regs(i, bp);
	}
	clear_thread_flag(TIF_DB_DISABLED);
}

int check_hw_breakpoint(struct pt_regs *regs)
{
	if (regs->debugcause & BIT(DEBUGCAUSE_IBREAK_BIT)) {
		int i;
		struct perf_event **bp = this_cpu_ptr(bp_on_reg);

		for (i = 0; i < XCHAL_NUM_IBREAK; ++i) {
			if (bp[i] && !bp[i]->attr.disabled &&
			    regs->pc == bp[i]->attr.bp_addr)
				perf_bp_event(bp[i], regs);
		}
		return 0;
	} else if (regs->debugcause & BIT(DEBUGCAUSE_DBREAK_BIT)) {
		struct perf_event **bp = this_cpu_ptr(wp_on_reg);
		int dbnum = (regs->debugcause & DEBUGCAUSE_DBNUM_MASK) >>
			DEBUGCAUSE_DBNUM_SHIFT;

		if (dbnum < XCHAL_NUM_DBREAK && bp[dbnum]) {
			if (user_mode(regs)) {
				perf_bp_event(bp[dbnum], regs);
			} else {
				set_thread_flag(TIF_DB_DISABLED);
				xtensa_wsr(0, SREG_DBREAKC + dbnum);
			}
		} else {
			WARN_ONCE(1,
				  "Wrong/unconfigured DBNUM reported in DEBUGCAUSE: %d\n",
				  dbnum);
		}
		return 0;
	}
	return -ENOENT;
}

