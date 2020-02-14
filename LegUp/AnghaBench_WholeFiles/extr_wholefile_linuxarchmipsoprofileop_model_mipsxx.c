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
struct op_counter_config {scalar_t__ count; scalar_t__ exl; scalar_t__ user; scalar_t__ kernel; int /*<<< orphan*/  event; int /*<<< orphan*/  enabled; } ;
typedef  int irqreturn_t ;
struct TYPE_4__ {unsigned int num_counters; } ;
struct TYPE_3__ {unsigned int* control; scalar_t__* counter; } ;

/* Variables and functions */
 int CAUSEF_PCI ; 
#define  CPU_R10000 131 
#define  CPU_R12000 130 
#define  CPU_R14000 129 
#define  CPU_R16000 128 
 scalar_t__ CPU_XLR ; 
 int IRQ_HANDLED ; 
 int IRQ_NONE ; 
 unsigned int MIPS_PERFCTRL_EXL ; 
 unsigned int MIPS_PERFCTRL_IE ; 
 unsigned int MIPS_PERFCTRL_K ; 
 int MIPS_PERFCTRL_M ; 
 unsigned int MIPS_PERFCTRL_U ; 
 unsigned int M_COUNTER_OVERFLOW ; 
 unsigned int M_PERFCTL_EVENT (int /*<<< orphan*/ ) ; 
 int WHAT ; 
 unsigned int XLR_PERFCTRL_ALLTHREADS ; 
 scalar_t__ boot_cpu_type () ; 
 scalar_t__ cpu_has_mips_r2 ; 
 int /*<<< orphan*/  cpu_has_perf ; 
 int current_cpu_type () ; 
 int /*<<< orphan*/  get_irq_regs () ; 
 TYPE_2__ op_model_mipsxx_ops ; 
 int /*<<< orphan*/  oprofile_add_sample (int /*<<< orphan*/ ,int) ; 
 scalar_t__ oprofile_skip_cpu (int /*<<< orphan*/ ) ; 
 unsigned int r_c0_perfcntr0 () ; 
 unsigned int r_c0_perfcntr1 () ; 
 unsigned int r_c0_perfcntr2 () ; 
 unsigned int r_c0_perfcntr3 () ; 
 unsigned int r_c0_perfctrl0 () ; 
 unsigned int r_c0_perfctrl1 () ; 
 unsigned int r_c0_perfctrl2 () ; 
 unsigned int r_c0_perfctrl3 () ; 
 int read_c0_cause () ; 
 int read_c0_perfctrl0 () ; 
 int read_c0_perfctrl1 () ; 
 int read_c0_perfctrl2 () ; 
 TYPE_1__ reg ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  w_c0_perfcntr0 (scalar_t__) ; 
 int /*<<< orphan*/  w_c0_perfcntr1 (scalar_t__) ; 
 int /*<<< orphan*/  w_c0_perfcntr2 (scalar_t__) ; 
 int /*<<< orphan*/  w_c0_perfcntr3 (scalar_t__) ; 
 int /*<<< orphan*/  w_c0_perfctrl0 (int) ; 
 int /*<<< orphan*/  w_c0_perfctrl1 (int) ; 
 int /*<<< orphan*/  w_c0_perfctrl2 (int) ; 
 int /*<<< orphan*/  w_c0_perfctrl3 (int) ; 

__attribute__((used)) static inline unsigned int vpe_shift(void)
{
	return 0;
}

__attribute__((used)) static inline unsigned int counters_total_to_per_cpu(unsigned int counters)
{
	return counters >> vpe_shift();
}

__attribute__((used)) static inline unsigned int counters_per_cpu_to_total(unsigned int counters)
{
	return counters << vpe_shift();
}

__attribute__((used)) static void mipsxx_reg_setup(struct op_counter_config *ctr)
{
	unsigned int counters = op_model_mipsxx_ops.num_counters;
	int i;

	/* Compute the performance counter control word.  */
	for (i = 0; i < counters; i++) {
		reg.control[i] = 0;
		reg.counter[i] = 0;

		if (!ctr[i].enabled)
			continue;

		reg.control[i] = M_PERFCTL_EVENT(ctr[i].event) |
				 MIPS_PERFCTRL_IE;
		if (ctr[i].kernel)
			reg.control[i] |= MIPS_PERFCTRL_K;
		if (ctr[i].user)
			reg.control[i] |= MIPS_PERFCTRL_U;
		if (ctr[i].exl)
			reg.control[i] |= MIPS_PERFCTRL_EXL;
		if (boot_cpu_type() == CPU_XLR)
			reg.control[i] |= XLR_PERFCTRL_ALLTHREADS;
		reg.counter[i] = 0x80000000 - ctr[i].count;
	}
}

__attribute__((used)) static void mipsxx_cpu_setup(void *args)
{
	unsigned int counters = op_model_mipsxx_ops.num_counters;

	if (oprofile_skip_cpu(smp_processor_id()))
		return;

	switch (counters) {
	case 4:
		w_c0_perfctrl3(0);
		w_c0_perfcntr3(reg.counter[3]);
	case 3:
		w_c0_perfctrl2(0);
		w_c0_perfcntr2(reg.counter[2]);
	case 2:
		w_c0_perfctrl1(0);
		w_c0_perfcntr1(reg.counter[1]);
	case 1:
		w_c0_perfctrl0(0);
		w_c0_perfcntr0(reg.counter[0]);
	}
}

__attribute__((used)) static void mipsxx_cpu_start(void *args)
{
	unsigned int counters = op_model_mipsxx_ops.num_counters;

	if (oprofile_skip_cpu(smp_processor_id()))
		return;

	switch (counters) {
	case 4:
		w_c0_perfctrl3(WHAT | reg.control[3]);
	case 3:
		w_c0_perfctrl2(WHAT | reg.control[2]);
	case 2:
		w_c0_perfctrl1(WHAT | reg.control[1]);
	case 1:
		w_c0_perfctrl0(WHAT | reg.control[0]);
	}
}

__attribute__((used)) static void mipsxx_cpu_stop(void *args)
{
	unsigned int counters = op_model_mipsxx_ops.num_counters;

	if (oprofile_skip_cpu(smp_processor_id()))
		return;

	switch (counters) {
	case 4:
		w_c0_perfctrl3(0);
	case 3:
		w_c0_perfctrl2(0);
	case 2:
		w_c0_perfctrl1(0);
	case 1:
		w_c0_perfctrl0(0);
	}
}

__attribute__((used)) static int mipsxx_perfcount_handler(void)
{
	unsigned int counters = op_model_mipsxx_ops.num_counters;
	unsigned int control;
	unsigned int counter;
	int handled = IRQ_NONE;

	if (cpu_has_mips_r2 && !(read_c0_cause() & CAUSEF_PCI))
		return handled;

	switch (counters) {
#define HANDLE_COUNTER(n)						\
	case n + 1:							\
		control = r_c0_perfctrl ## n();				\
		counter = r_c0_perfcntr ## n();				\
		if ((control & MIPS_PERFCTRL_IE) &&			\
		    (counter & M_COUNTER_OVERFLOW)) {			\
			oprofile_add_sample(get_irq_regs(), n);		\
			w_c0_perfcntr ## n(reg.counter[n]);		\
			handled = IRQ_HANDLED;				\
		}
	HANDLE_COUNTER(3)
	HANDLE_COUNTER(2)
	HANDLE_COUNTER(1)
	HANDLE_COUNTER(0)
	}

	return handled;
}

__attribute__((used)) static inline int __n_counters(void)
{
	if (!cpu_has_perf)
		return 0;
	if (!(read_c0_perfctrl0() & MIPS_PERFCTRL_M))
		return 1;
	if (!(read_c0_perfctrl1() & MIPS_PERFCTRL_M))
		return 2;
	if (!(read_c0_perfctrl2() & MIPS_PERFCTRL_M))
		return 3;

	return 4;
}

__attribute__((used)) static inline int n_counters(void)
{
	int counters;

	switch (current_cpu_type()) {
	case CPU_R10000:
		counters = 2;
		break;

	case CPU_R12000:
	case CPU_R14000:
	case CPU_R16000:
		counters = 4;
		break;

	default:
		counters = __n_counters();
	}

	return counters;
}

__attribute__((used)) static void reset_counters(void *arg)
{
	int counters = (int)(long)arg;
	switch (counters) {
	case 4:
		w_c0_perfctrl3(0);
		w_c0_perfcntr3(0);
	case 3:
		w_c0_perfctrl2(0);
		w_c0_perfcntr2(0);
	case 2:
		w_c0_perfctrl1(0);
		w_c0_perfcntr1(0);
	case 1:
		w_c0_perfctrl0(0);
		w_c0_perfcntr0(0);
	}
}

__attribute__((used)) static irqreturn_t mipsxx_perfcount_int(int irq, void *dev_id)
{
	return mipsxx_perfcount_handler();
}

