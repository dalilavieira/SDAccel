#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct slb_shadow {TYPE_2__* save_area; int /*<<< orphan*/  persistent; } ;
struct machine_check_event {scalar_t__ version; scalar_t__ severity; scalar_t__ disposition; } ;
struct TYPE_18__ {unsigned long msr; unsigned long dsisr; } ;
struct TYPE_16__ {void* pinned_end; struct slb_shadow* pinned_addr; } ;
struct TYPE_21__ {struct machine_check_event mce_evt; TYPE_3__ shregs; TYPE_1__ slb_shadow; } ;
struct kvm_vcpu {TYPE_6__ arch; TYPE_5__* kvm; } ;
struct TYPE_24__ {int* in_guest; int /*<<< orphan*/  flags; } ;
struct TYPE_23__ {TYPE_7__* kvm_split_mode; } ;
struct TYPE_22__ {int subcore_size; } ;
struct TYPE_19__ {scalar_t__ fwnmi_enabled; int /*<<< orphan*/  radix; } ;
struct TYPE_20__ {TYPE_4__ arch; } ;
struct TYPE_17__ {int /*<<< orphan*/  vsid; int /*<<< orphan*/  esid; } ;
struct TYPE_15__ {int /*<<< orphan*/  hmi_exceptions; } ;
struct TYPE_14__ {TYPE_9__* sibling_subcore_state; int /*<<< orphan*/  paca_index; TYPE_8__ kvm_hstate; } ;
struct TYPE_13__ {int /*<<< orphan*/  (* hmi_exception_early ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CORE_TB_RESYNC_REQ_BIT ; 
 unsigned long DSISR_MC_DERAT_MULTI ; 
 unsigned long DSISR_MC_SLB_MULTI ; 
 unsigned long DSISR_MC_SLB_PARITY ; 
 unsigned long DSISR_MC_SLB_PARMULTI ; 
 unsigned long DSISR_MC_TLB_MULTI ; 
 scalar_t__ MCE_DISPOSITION_RECOVERED ; 
 int /*<<< orphan*/  MCE_EVENT_DONTRELEASE ; 
 int /*<<< orphan*/  MCE_EVENT_RELEASE ; 
 scalar_t__ MCE_SEV_NO_ERROR ; 
 scalar_t__ MCE_V1 ; 
 int /*<<< orphan*/  SLB_MIN_SIZE ; 
 unsigned long SRR1_MC_IFETCH_MASK ; 
 unsigned long SRR1_MC_IFETCH_SH ; 
#define  SRR1_MC_IFETCH_SLBMULTI 131 
#define  SRR1_MC_IFETCH_SLBPAR 130 
#define  SRR1_MC_IFETCH_SLBPARMULTI 129 
#define  SRR1_MC_IFETCH_TLBMULTI 128 
 unsigned long SRR1_MC_LDSTERR ; 
 int /*<<< orphan*/  __this_cpu_inc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/ ) ; 
 unsigned long be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int cpu_thread_in_core (int /*<<< orphan*/ ) ; 
 scalar_t__ get_mce_event (struct machine_check_event*,int /*<<< orphan*/ ) ; 
 scalar_t__ hmi_handle_debugtrig (int /*<<< orphan*/ *) ; 
 TYPE_12__ irq_stat ; 
 TYPE_11__* local_paca ; 
 int /*<<< orphan*/  machine_check_queue_event () ; 
 int /*<<< orphan*/  memset (struct machine_check_event*,int /*<<< orphan*/ ,int) ; 
 unsigned long min_t (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  opal_resync_timebase () ; 
 TYPE_10__ ppc_md ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int threads_per_subcore ; 
 int /*<<< orphan*/  tlbiel_all_lpid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  u32 ; 
 int /*<<< orphan*/  wait_for_subcore_guest_exit () ; 
 int /*<<< orphan*/  wait_for_tb_resync () ; 

__attribute__((used)) static void reload_slb(struct kvm_vcpu *vcpu)
{
	struct slb_shadow *slb;
	unsigned long i, n;

	/* First clear out SLB */
	asm volatile("slbmte %0,%0; slbia" : : "r" (0));

	/* Do they have an SLB shadow buffer registered? */
	slb = vcpu->arch.slb_shadow.pinned_addr;
	if (!slb)
		return;

	/* Sanity check */
	n = min_t(u32, be32_to_cpu(slb->persistent), SLB_MIN_SIZE);
	if ((void *) &slb->save_area[n] > vcpu->arch.slb_shadow.pinned_end)
		return;

	/* Load up the SLB from that */
	for (i = 0; i < n; ++i) {
		unsigned long rb = be64_to_cpu(slb->save_area[i].esid);
		unsigned long rs = be64_to_cpu(slb->save_area[i].vsid);

		rb = (rb & ~0xFFFul) | i;	/* insert entry number */
		asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
	}
}

__attribute__((used)) static long kvmppc_realmode_mc_power7(struct kvm_vcpu *vcpu)
{
	unsigned long srr1 = vcpu->arch.shregs.msr;
	struct machine_check_event mce_evt;
	long handled = 1;

	if (srr1 & SRR1_MC_LDSTERR) {
		/* error on load/store */
		unsigned long dsisr = vcpu->arch.shregs.dsisr;

		if (dsisr & (DSISR_MC_SLB_PARMULTI | DSISR_MC_SLB_MULTI |
			     DSISR_MC_SLB_PARITY | DSISR_MC_DERAT_MULTI)) {
			/* flush and reload SLB; flushes D-ERAT too */
			reload_slb(vcpu);
			dsisr &= ~(DSISR_MC_SLB_PARMULTI | DSISR_MC_SLB_MULTI |
				   DSISR_MC_SLB_PARITY | DSISR_MC_DERAT_MULTI);
		}
		if (dsisr & DSISR_MC_TLB_MULTI) {
			tlbiel_all_lpid(vcpu->kvm->arch.radix);
			dsisr &= ~DSISR_MC_TLB_MULTI;
		}
		/* Any other errors we don't understand? */
		if (dsisr & 0xffffffffUL)
			handled = 0;
	}

	switch ((srr1 >> SRR1_MC_IFETCH_SH) & SRR1_MC_IFETCH_MASK) {
	case 0:
		break;
	case SRR1_MC_IFETCH_SLBPAR:
	case SRR1_MC_IFETCH_SLBMULTI:
	case SRR1_MC_IFETCH_SLBPARMULTI:
		reload_slb(vcpu);
		break;
	case SRR1_MC_IFETCH_TLBMULTI:
		tlbiel_all_lpid(vcpu->kvm->arch.radix);
		break;
	default:
		handled = 0;
	}

	/*
	 * See if we have already handled the condition in the linux host.
	 * We assume that if the condition is recovered then linux host
	 * will have generated an error log event that we will pick
	 * up and log later.
	 * Don't release mce event now. We will queue up the event so that
	 * we can log the MCE event info on host console.
	 */
	if (!get_mce_event(&mce_evt, MCE_EVENT_DONTRELEASE))
		goto out;

	if (mce_evt.version == MCE_V1 &&
	    (mce_evt.severity == MCE_SEV_NO_ERROR ||
	     mce_evt.disposition == MCE_DISPOSITION_RECOVERED))
		handled = 1;

out:
	/*
	 * For guest that supports FWNMI capability, hook the MCE event into
	 * vcpu structure. We are going to exit the guest with KVM_EXIT_NMI
	 * exit reason. On our way to exit we will pull this event from vcpu
	 * structure and print it from thread 0 of the core/subcore.
	 *
	 * For guest that does not support FWNMI capability (old QEMU):
	 * We are now going enter guest either through machine check
	 * interrupt (for unhandled errors) or will continue from
	 * current HSRR0 (for handled errors) in guest. Hence
	 * queue up the event so that we can log it from host console later.
	 */
	if (vcpu->kvm->arch.fwnmi_enabled) {
		/*
		 * Hook up the mce event on to vcpu structure.
		 * First clear the old event.
		 */
		memset(&vcpu->arch.mce_evt, 0, sizeof(vcpu->arch.mce_evt));
		if (get_mce_event(&mce_evt, MCE_EVENT_RELEASE)) {
			vcpu->arch.mce_evt = mce_evt;
		}
	} else
		machine_check_queue_event();

	return handled;
}

long kvmppc_realmode_machine_check(struct kvm_vcpu *vcpu)
{
	return kvmppc_realmode_mc_power7(vcpu);
}

__attribute__((used)) static inline int kvmppc_cur_subcore_size(void)
{
	if (local_paca->kvm_hstate.kvm_split_mode)
		return local_paca->kvm_hstate.kvm_split_mode->subcore_size;

	return threads_per_subcore;
}

void kvmppc_subcore_enter_guest(void)
{
	int thread_id, subcore_id;

	thread_id = cpu_thread_in_core(local_paca->paca_index);
	subcore_id = thread_id / kvmppc_cur_subcore_size();

	local_paca->sibling_subcore_state->in_guest[subcore_id] = 1;
}

void kvmppc_subcore_exit_guest(void)
{
	int thread_id, subcore_id;

	thread_id = cpu_thread_in_core(local_paca->paca_index);
	subcore_id = thread_id / kvmppc_cur_subcore_size();

	local_paca->sibling_subcore_state->in_guest[subcore_id] = 0;
}

__attribute__((used)) static bool kvmppc_tb_resync_required(void)
{
	if (test_and_set_bit(CORE_TB_RESYNC_REQ_BIT,
				&local_paca->sibling_subcore_state->flags))
		return false;

	return true;
}

__attribute__((used)) static void kvmppc_tb_resync_done(void)
{
	clear_bit(CORE_TB_RESYNC_REQ_BIT,
			&local_paca->sibling_subcore_state->flags);
}

long kvmppc_realmode_hmi_handler(void)
{
	bool resync_req;

	__this_cpu_inc(irq_stat.hmi_exceptions);

	if (hmi_handle_debugtrig(NULL) >= 0)
		return 1;

	/*
	 * By now primary thread has already completed guest->host
	 * partition switch but haven't signaled secondaries yet.
	 * All the secondary threads on this subcore is waiting
	 * for primary thread to signal them to go ahead.
	 *
	 * For threads from subcore which isn't in guest, they all will
	 * wait until all other subcores on this core exit the guest.
	 *
	 * Now set the resync required bit. If you are the first to
	 * set this bit then kvmppc_tb_resync_required() function will
	 * return true. For rest all other subcores
	 * kvmppc_tb_resync_required() will return false.
	 *
	 * If resync_req == true, then this thread is responsible to
	 * initiate TB resync after hmi handler has completed.
	 * All other threads on this core will wait until this thread
	 * clears the resync required bit flag.
	 */
	resync_req = kvmppc_tb_resync_required();

	/* Reset the subcore status to indicate it has exited guest */
	kvmppc_subcore_exit_guest();

	/*
	 * Wait for other subcores on this core to exit the guest.
	 * All the primary threads and threads from subcore that are
	 * not in guest will wait here until all subcores are out
	 * of guest context.
	 */
	wait_for_subcore_guest_exit();

	/*
	 * At this point we are sure that primary threads from each
	 * subcore on this core have completed guest->host partition
	 * switch. Now it is safe to call HMI handler.
	 */
	if (ppc_md.hmi_exception_early)
		ppc_md.hmi_exception_early(NULL);

	/*
	 * Check if this thread is responsible to resync TB.
	 * All other threads will wait until this thread completes the
	 * TB resync.
	 */
	if (resync_req) {
		opal_resync_timebase();
		/* Reset TB resync req bit */
		kvmppc_tb_resync_done();
	} else {
		wait_for_tb_resync();
	}
	return 0;
}

