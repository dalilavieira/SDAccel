#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  prev_count; } ;
struct TYPE_3__ {int type; int /*<<< orphan*/  config; } ;
struct perf_event {int /*<<< orphan*/  count; TYPE_2__ hw; TYPE_1__ attr; } ;
typedef  int s64 ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  DTLB_LOAD_MISS ; 
 int ENOENT ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  ITLB_LOAD_MISS ; 
#define  PERF_8xx_ID_CPU_CYCLES 134 
#define  PERF_8xx_ID_DTLB_LOAD_MISS 133 
#define  PERF_8xx_ID_HW_INSTRUCTIONS 132 
#define  PERF_8xx_ID_ITLB_LOAD_MISS 131 
 int /*<<< orphan*/  PERF_COUNT_HW_CPU_CYCLES ; 
 int /*<<< orphan*/  PERF_COUNT_HW_INSTRUCTIONS ; 
#define  PERF_TYPE_HARDWARE 130 
#define  PERF_TYPE_HW_CACHE 129 
#define  PERF_TYPE_RAW 128 
 unsigned int PPC_INST_MFSPR ; 
 int /*<<< orphan*/  R10 ; 
 int /*<<< orphan*/  SPRN_CMPA ; 
 int /*<<< orphan*/  SPRN_COUNTA ; 
 int /*<<< orphan*/  SPRN_ICTRL ; 
 int /*<<< orphan*/  SPRN_SPRG_SCRATCH0 ; 
 unsigned int __PPC_RS (int /*<<< orphan*/ ) ; 
 unsigned int __PPC_SPR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_dec_return (int /*<<< orphan*/ *) ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int dtlb_miss_counter ; 
 int /*<<< orphan*/  dtlb_miss_exit_1 ; 
 int /*<<< orphan*/  dtlb_miss_exit_2 ; 
 int /*<<< orphan*/  dtlb_miss_exit_3 ; 
 int /*<<< orphan*/  dtlb_miss_perf ; 
 int /*<<< orphan*/  dtlb_miss_ref ; 
 int get_tb () ; 
 int /*<<< orphan*/  insn_ctr_ref ; 
 int /*<<< orphan*/  instruction_counter ; 
 int itlb_miss_counter ; 
 int /*<<< orphan*/  itlb_miss_exit_1 ; 
 int /*<<< orphan*/  itlb_miss_exit_2 ; 
 int /*<<< orphan*/  itlb_miss_perf ; 
 int /*<<< orphan*/  itlb_miss_ref ; 
 int /*<<< orphan*/  local64_add (int,int /*<<< orphan*/ *) ; 
 int local64_cmpxchg (int /*<<< orphan*/ *,int,int) ; 
 int local64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  local64_set (int /*<<< orphan*/ *,int) ; 
 unsigned long mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpc8xx_pmu ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  patch_branch (int /*<<< orphan*/ *,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  patch_instruction (int /*<<< orphan*/ *,unsigned int) ; 
 int perf_pmu_register (int /*<<< orphan*/ *,char*,int const) ; 

__attribute__((used)) static s64 get_insn_ctr(void)
{
	int ctr;
	unsigned long counta;

	do {
		ctr = atomic_read(&instruction_counter);
		counta = mfspr(SPRN_COUNTA);
	} while (ctr != atomic_read(&instruction_counter));

	return ((s64)ctr << 16) | (counta >> 16);
}

__attribute__((used)) static int event_type(struct perf_event *event)
{
	switch (event->attr.type) {
	case PERF_TYPE_HARDWARE:
		if (event->attr.config == PERF_COUNT_HW_CPU_CYCLES)
			return PERF_8xx_ID_CPU_CYCLES;
		if (event->attr.config == PERF_COUNT_HW_INSTRUCTIONS)
			return PERF_8xx_ID_HW_INSTRUCTIONS;
		break;
	case PERF_TYPE_HW_CACHE:
		if (event->attr.config == ITLB_LOAD_MISS)
			return PERF_8xx_ID_ITLB_LOAD_MISS;
		if (event->attr.config == DTLB_LOAD_MISS)
			return PERF_8xx_ID_DTLB_LOAD_MISS;
		break;
	case PERF_TYPE_RAW:
		break;
	default:
		return -ENOENT;
	}
	return -EOPNOTSUPP;
}

__attribute__((used)) static int mpc8xx_pmu_event_init(struct perf_event *event)
{
	int type = event_type(event);

	if (type < 0)
		return type;
	return 0;
}

__attribute__((used)) static int mpc8xx_pmu_add(struct perf_event *event, int flags)
{
	int type = event_type(event);
	s64 val = 0;

	if (type < 0)
		return type;

	switch (type) {
	case PERF_8xx_ID_CPU_CYCLES:
		val = get_tb();
		break;
	case PERF_8xx_ID_HW_INSTRUCTIONS:
		if (atomic_inc_return(&insn_ctr_ref) == 1)
			mtspr(SPRN_ICTRL, 0xc0080007);
		val = get_insn_ctr();
		break;
	case PERF_8xx_ID_ITLB_LOAD_MISS:
		if (atomic_inc_return(&itlb_miss_ref) == 1) {
			unsigned long target = (unsigned long)&itlb_miss_perf;

			patch_branch(&itlb_miss_exit_1, target, 0);
#ifndef CONFIG_PIN_TLB_TEXT
			patch_branch(&itlb_miss_exit_2, target, 0);
#endif
		}
		val = itlb_miss_counter;
		break;
	case PERF_8xx_ID_DTLB_LOAD_MISS:
		if (atomic_inc_return(&dtlb_miss_ref) == 1) {
			unsigned long target = (unsigned long)&dtlb_miss_perf;

			patch_branch(&dtlb_miss_exit_1, target, 0);
			patch_branch(&dtlb_miss_exit_2, target, 0);
			patch_branch(&dtlb_miss_exit_3, target, 0);
		}
		val = dtlb_miss_counter;
		break;
	}
	local64_set(&event->hw.prev_count, val);
	return 0;
}

__attribute__((used)) static void mpc8xx_pmu_read(struct perf_event *event)
{
	int type = event_type(event);
	s64 prev, val = 0, delta = 0;

	if (type < 0)
		return;

	do {
		prev = local64_read(&event->hw.prev_count);
		switch (type) {
		case PERF_8xx_ID_CPU_CYCLES:
			val = get_tb();
			delta = 16 * (val - prev);
			break;
		case PERF_8xx_ID_HW_INSTRUCTIONS:
			val = get_insn_ctr();
			delta = prev - val;
			if (delta < 0)
				delta += 0x1000000000000LL;
			break;
		case PERF_8xx_ID_ITLB_LOAD_MISS:
			val = itlb_miss_counter;
			delta = (s64)((s32)val - (s32)prev);
			break;
		case PERF_8xx_ID_DTLB_LOAD_MISS:
			val = dtlb_miss_counter;
			delta = (s64)((s32)val - (s32)prev);
			break;
		}
	} while (local64_cmpxchg(&event->hw.prev_count, prev, val) != prev);

	local64_add(delta, &event->count);
}

__attribute__((used)) static void mpc8xx_pmu_del(struct perf_event *event, int flags)
{
	/* mfspr r10, SPRN_SPRG_SCRATCH0 */
	unsigned int insn = PPC_INST_MFSPR | __PPC_RS(R10) |
			    __PPC_SPR(SPRN_SPRG_SCRATCH0);

	mpc8xx_pmu_read(event);

	/* If it was the last user, stop counting to avoid useles overhead */
	switch (event_type(event)) {
	case PERF_8xx_ID_CPU_CYCLES:
		break;
	case PERF_8xx_ID_HW_INSTRUCTIONS:
		if (atomic_dec_return(&insn_ctr_ref) == 0)
			mtspr(SPRN_ICTRL, 7);
		break;
	case PERF_8xx_ID_ITLB_LOAD_MISS:
		if (atomic_dec_return(&itlb_miss_ref) == 0) {
			patch_instruction(&itlb_miss_exit_1, insn);
#ifndef CONFIG_PIN_TLB_TEXT
			patch_instruction(&itlb_miss_exit_2, insn);
#endif
		}
		break;
	case PERF_8xx_ID_DTLB_LOAD_MISS:
		if (atomic_dec_return(&dtlb_miss_ref) == 0) {
			patch_instruction(&dtlb_miss_exit_1, insn);
			patch_instruction(&dtlb_miss_exit_2, insn);
			patch_instruction(&dtlb_miss_exit_3, insn);
		}
		break;
	}
}

__attribute__((used)) static int init_mpc8xx_pmu(void)
{
	mtspr(SPRN_ICTRL, 7);
	mtspr(SPRN_CMPA, 0);
	mtspr(SPRN_COUNTA, 0xffff);

	return perf_pmu_register(&mpc8xx_pmu, "cpu", PERF_TYPE_RAW);
}

