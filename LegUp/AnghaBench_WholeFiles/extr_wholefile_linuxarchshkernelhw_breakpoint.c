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
typedef  int u16 ;
struct thread_struct {int /*<<< orphan*/ ** ptrace_bps; } ;
struct task_struct {struct thread_struct thread; } ;
struct perf_event_attr {unsigned long bp_addr; int bp_len; int bp_type; } ;
struct perf_event {int dummy; } ;
struct arch_hw_breakpoint {unsigned long address; int len; int type; } ;
struct TYPE_2__ {int num_events; int /*<<< orphan*/  clk; int /*<<< orphan*/  (* disable ) (struct arch_hw_breakpoint*,int) ;int /*<<< orphan*/  (* enable ) (struct arch_hw_breakpoint*,int) ;} ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
#define  HW_BREAKPOINT_LEN_1 140 
#define  HW_BREAKPOINT_LEN_2 139 
#define  HW_BREAKPOINT_LEN_4 138 
#define  HW_BREAKPOINT_LEN_8 137 
#define  HW_BREAKPOINT_R 136 
#define  HW_BREAKPOINT_W 135 
#define  SH_BREAKPOINT_LEN_1 134 
#define  SH_BREAKPOINT_LEN_2 133 
#define  SH_BREAKPOINT_LEN_4 132 
#define  SH_BREAKPOINT_LEN_8 131 
#define  SH_BREAKPOINT_READ 130 
#define  SH_BREAKPOINT_RW 129 
#define  SH_BREAKPOINT_WRITE 128 
 unsigned long TASK_SIZE ; 
 scalar_t__ WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/ * bp_per_reg ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 struct arch_hw_breakpoint* counter_arch_bp (struct perf_event*) ; 
 TYPE_1__* sh_ubc ; 
 int /*<<< orphan*/  stub1 (struct arch_hw_breakpoint*,int) ; 
 int /*<<< orphan*/  stub2 (struct arch_hw_breakpoint*,int) ; 
 struct perf_event** this_cpu_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unregister_hw_breakpoint (int /*<<< orphan*/ *) ; 

int arch_install_hw_breakpoint(struct perf_event *bp)
{
	struct arch_hw_breakpoint *info = counter_arch_bp(bp);
	int i;

	for (i = 0; i < sh_ubc->num_events; i++) {
		struct perf_event **slot = this_cpu_ptr(&bp_per_reg[i]);

		if (!*slot) {
			*slot = bp;
			break;
		}
	}

	if (WARN_ONCE(i == sh_ubc->num_events, "Can't find any breakpoint slot"))
		return -EBUSY;

	clk_enable(sh_ubc->clk);
	sh_ubc->enable(info, i);

	return 0;
}

void arch_uninstall_hw_breakpoint(struct perf_event *bp)
{
	struct arch_hw_breakpoint *info = counter_arch_bp(bp);
	int i;

	for (i = 0; i < sh_ubc->num_events; i++) {
		struct perf_event **slot = this_cpu_ptr(&bp_per_reg[i]);

		if (*slot == bp) {
			*slot = NULL;
			break;
		}
	}

	if (WARN_ONCE(i == sh_ubc->num_events, "Can't find any breakpoint slot"))
		return;

	sh_ubc->disable(info, i);
	clk_disable(sh_ubc->clk);
}

__attribute__((used)) static int get_hbp_len(u16 hbp_len)
{
	unsigned int len_in_bytes = 0;

	switch (hbp_len) {
	case SH_BREAKPOINT_LEN_1:
		len_in_bytes = 1;
		break;
	case SH_BREAKPOINT_LEN_2:
		len_in_bytes = 2;
		break;
	case SH_BREAKPOINT_LEN_4:
		len_in_bytes = 4;
		break;
	case SH_BREAKPOINT_LEN_8:
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
	len = get_hbp_len(hw->len);

	return (va >= TASK_SIZE) && ((va + len - 1) >= TASK_SIZE);
}

int arch_bp_generic_fields(int sh_len, int sh_type,
			   int *gen_len, int *gen_type)
{
	/* Len */
	switch (sh_len) {
	case SH_BREAKPOINT_LEN_1:
		*gen_len = HW_BREAKPOINT_LEN_1;
		break;
	case SH_BREAKPOINT_LEN_2:
		*gen_len = HW_BREAKPOINT_LEN_2;
		break;
	case SH_BREAKPOINT_LEN_4:
		*gen_len = HW_BREAKPOINT_LEN_4;
		break;
	case SH_BREAKPOINT_LEN_8:
		*gen_len = HW_BREAKPOINT_LEN_8;
		break;
	default:
		return -EINVAL;
	}

	/* Type */
	switch (sh_type) {
	case SH_BREAKPOINT_READ:
		*gen_type = HW_BREAKPOINT_R;
	case SH_BREAKPOINT_WRITE:
		*gen_type = HW_BREAKPOINT_W;
		break;
	case SH_BREAKPOINT_RW:
		*gen_type = HW_BREAKPOINT_W | HW_BREAKPOINT_R;
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
	hw->address = attr->bp_addr;

	/* Len */
	switch (attr->bp_len) {
	case HW_BREAKPOINT_LEN_1:
		hw->len = SH_BREAKPOINT_LEN_1;
		break;
	case HW_BREAKPOINT_LEN_2:
		hw->len = SH_BREAKPOINT_LEN_2;
		break;
	case HW_BREAKPOINT_LEN_4:
		hw->len = SH_BREAKPOINT_LEN_4;
		break;
	case HW_BREAKPOINT_LEN_8:
		hw->len = SH_BREAKPOINT_LEN_8;
		break;
	default:
		return -EINVAL;
	}

	/* Type */
	switch (attr->bp_type) {
	case HW_BREAKPOINT_R:
		hw->type = SH_BREAKPOINT_READ;
		break;
	case HW_BREAKPOINT_W:
		hw->type = SH_BREAKPOINT_WRITE;
		break;
	case HW_BREAKPOINT_W | HW_BREAKPOINT_R:
		hw->type = SH_BREAKPOINT_RW;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

int hw_breakpoint_arch_parse(struct perf_event *bp,
			     const struct perf_event_attr *attr,
			     struct arch_hw_breakpoint *hw)
{
	unsigned int align;
	int ret;

	ret = arch_build_bp_info(bp, attr, hw);
	if (ret)
		return ret;

	ret = -EINVAL;

	switch (hw->len) {
	case SH_BREAKPOINT_LEN_1:
		align = 0;
		break;
	case SH_BREAKPOINT_LEN_2:
		align = 1;
		break;
	case SH_BREAKPOINT_LEN_4:
		align = 3;
		break;
	case SH_BREAKPOINT_LEN_8:
		align = 7;
		break;
	default:
		return ret;
	}

	/*
	 * Check that the low-order bits of the address are appropriate
	 * for the alignment implied by len.
	 */
	if (hw->address & align)
		return -EINVAL;

	return 0;
}

void flush_ptrace_hw_breakpoint(struct task_struct *tsk)
{
	int i;
	struct thread_struct *t = &tsk->thread;

	for (i = 0; i < sh_ubc->num_events; i++) {
		unregister_hw_breakpoint(t->ptrace_bps[i]);
		t->ptrace_bps[i] = NULL;
	}
}

