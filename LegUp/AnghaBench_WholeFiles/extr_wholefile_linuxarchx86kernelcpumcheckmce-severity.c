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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct severity {int mask; int result; int mcgmask; int mcgres; scalar_t__ ser; int context; int excp; char* msg; int covered; int sev; } ;
struct notifier_block {int dummy; } ;
struct mce {scalar_t__ bank; scalar_t__ status; scalar_t__ addr; scalar_t__ misc; int cs; int mcgstatus; int /*<<< orphan*/  ip; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  enum exception { ____Placeholder_exception } exception ;
typedef  enum context { ____Placeholder_context } context ;
struct TYPE_4__ {scalar_t__ ser; } ;
struct TYPE_3__ {scalar_t__ smca; scalar_t__ overflow_recov; int /*<<< orphan*/  succor; } ;

/* Variables and functions */
 int EINVAL ; 
 int EXCP_CONTEXT ; 
 int IN_KERNEL ; 
 int IN_KERNEL_RECOV ; 
 int IN_USER ; 
 int MCE_AR_SEVERITY ; 
 int MCE_DEFERRED_SEVERITY ; 
 int MCE_KEEP_SEVERITY ; 
 int MCE_PANIC_SEVERITY ; 
 int MCE_UC_SEVERITY ; 
 int MCI_CONFIG_MCAX ; 
 int MCI_STATUS_DEFERRED ; 
 int MCI_STATUS_OVER ; 
 int MCI_STATUS_PCC ; 
 int MCI_STATUS_TCC ; 
 int MCI_STATUS_UC ; 
 int MSR_AMD64_SMCA_MCx_CONFIG (scalar_t__) ; 
 int NO_EXCP ; 
 scalar_t__ NO_SER ; 
 scalar_t__ SER_REQUIRED ; 
 scalar_t__ ex_has_fault_handler (int /*<<< orphan*/ ) ; 
 scalar_t__ mc_recoverable (int) ; 
 TYPE_2__ mca_cfg ; 
 TYPE_1__ mce_flags ; 
 scalar_t__ rdmsr_safe (int,int*,int*) ; 
 struct severity* severities ; 

__attribute__((used)) static inline bool mce_intel_cmci_poll(void) { return false; }

__attribute__((used)) static inline void mce_intel_hcpu_update(unsigned long cpu) { }

__attribute__((used)) static inline void cmci_disable_bank(int bank) { }

__attribute__((used)) static inline int apei_write_mce(struct mce *m)
{
	return -EINVAL;
}

__attribute__((used)) static inline ssize_t apei_read_mce(struct mce *m, u64 *record_id)
{
	return 0;
}

__attribute__((used)) static inline int apei_check_mce(void)
{
	return 0;
}

__attribute__((used)) static inline int apei_clear_mce(u64 record_id)
{
	return -EINVAL;
}

__attribute__((used)) static inline bool mce_cmp(struct mce *m1, struct mce *m2)
{
	return m1->bank != m2->bank ||
		m1->status != m2->status ||
		m1->addr != m2->addr ||
		m1->misc != m2->misc;
}

__attribute__((used)) static inline void mce_work_trigger(void)	{ }

__attribute__((used)) static inline void mce_register_injector_chain(struct notifier_block *nb)	{ }

__attribute__((used)) static inline void mce_unregister_injector_chain(struct notifier_block *nb)	{ }

__attribute__((used)) static int error_context(struct mce *m)
{
	if ((m->cs & 3) == 3)
		return IN_USER;
	if (mc_recoverable(m->mcgstatus) && ex_has_fault_handler(m->ip))
		return IN_KERNEL_RECOV;
	return IN_KERNEL;
}

__attribute__((used)) static int mce_severity_amd_smca(struct mce *m, enum context err_ctx)
{
	u32 addr = MSR_AMD64_SMCA_MCx_CONFIG(m->bank);
	u32 low, high;

	/*
	 * We need to look at the following bits:
	 * - "succor" bit (data poisoning support), and
	 * - TCC bit (Task Context Corrupt)
	 * in MCi_STATUS to determine error severity.
	 */
	if (!mce_flags.succor)
		return MCE_PANIC_SEVERITY;

	if (rdmsr_safe(addr, &low, &high))
		return MCE_PANIC_SEVERITY;

	/* TCC (Task context corrupt). If set and if IN_KERNEL, panic. */
	if ((low & MCI_CONFIG_MCAX) &&
	    (m->status & MCI_STATUS_TCC) &&
	    (err_ctx == IN_KERNEL))
		return MCE_PANIC_SEVERITY;

	 /* ...otherwise invoke hwpoison handler. */
	return MCE_AR_SEVERITY;
}

__attribute__((used)) static int mce_severity_amd(struct mce *m, int tolerant, char **msg, bool is_excp)
{
	enum context ctx = error_context(m);

	/* Processor Context Corrupt, no need to fumble too much, die! */
	if (m->status & MCI_STATUS_PCC)
		return MCE_PANIC_SEVERITY;

	if (m->status & MCI_STATUS_UC) {

		if (ctx == IN_KERNEL)
			return MCE_PANIC_SEVERITY;

		/*
		 * On older systems where overflow_recov flag is not present, we
		 * should simply panic if an error overflow occurs. If
		 * overflow_recov flag is present and set, then software can try
		 * to at least kill process to prolong system operation.
		 */
		if (mce_flags.overflow_recov) {
			if (mce_flags.smca)
				return mce_severity_amd_smca(m, ctx);

			/* kill current process */
			return MCE_AR_SEVERITY;
		} else {
			/* at least one error was not logged */
			if (m->status & MCI_STATUS_OVER)
				return MCE_PANIC_SEVERITY;
		}

		/*
		 * For any other case, return MCE_UC_SEVERITY so that we log the
		 * error and exit #MC handler.
		 */
		return MCE_UC_SEVERITY;
	}

	/*
	 * deferred error: poll handler catches these and adds to mce_ring so
	 * memory-failure can take recovery actions.
	 */
	if (m->status & MCI_STATUS_DEFERRED)
		return MCE_DEFERRED_SEVERITY;

	/*
	 * corrected error: poll handler catches these and passes responsibility
	 * of decoding the error to EDAC
	 */
	return MCE_KEEP_SEVERITY;
}

__attribute__((used)) static int mce_severity_intel(struct mce *m, int tolerant, char **msg, bool is_excp)
{
	enum exception excp = (is_excp ? EXCP_CONTEXT : NO_EXCP);
	enum context ctx = error_context(m);
	struct severity *s;

	for (s = severities;; s++) {
		if ((m->status & s->mask) != s->result)
			continue;
		if ((m->mcgstatus & s->mcgmask) != s->mcgres)
			continue;
		if (s->ser == SER_REQUIRED && !mca_cfg.ser)
			continue;
		if (s->ser == NO_SER && mca_cfg.ser)
			continue;
		if (s->context && ctx != s->context)
			continue;
		if (s->excp && excp != s->excp)
			continue;
		if (msg)
			*msg = s->msg;
		s->covered = 1;
		if (s->sev >= MCE_UC_SEVERITY && ctx == IN_KERNEL) {
			if (tolerant < 1)
				return MCE_PANIC_SEVERITY;
		}
		return s->sev;
	}
}

