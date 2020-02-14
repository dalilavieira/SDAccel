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
struct timespec64 {int /*<<< orphan*/  tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct system_device_crosststamp {int dummy; } ;
struct system_counterval_t {unsigned long cycles; int /*<<< orphan*/ * cs; } ;
struct pvclock_vcpu_time_info {int dummy; } ;
struct ptp_clock_request {int dummy; } ;
struct ptp_clock_info {int dummy; } ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  s32 ;
typedef  int /*<<< orphan*/  ktime_t ;
struct TYPE_4__ {int /*<<< orphan*/  nsec; int /*<<< orphan*/  sec; int /*<<< orphan*/  tsc; } ;
struct TYPE_3__ {struct pvclock_vcpu_time_info pvti; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  KVM_CLOCK_PAIRING_WALLCLOCK ; 
 int /*<<< orphan*/  KVM_HC_CLOCK_PAIRING ; 
 unsigned long __pvclock_read_cycles (struct pvclock_vcpu_time_info*,int /*<<< orphan*/ ) ; 
 TYPE_2__ clock_pair ; 
 int /*<<< orphan*/  clock_pair_gpa ; 
 int get_device_system_crosststamp (int (*) (int /*<<< orphan*/ *,struct system_counterval_t*,void*),int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct system_device_crosststamp*) ; 
 TYPE_1__* hv_clock ; 
 int /*<<< orphan*/  kvm_clock ; 
 unsigned long kvm_hypercall2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_ptp_lock ; 
 int /*<<< orphan*/  memcpy (struct timespec64*,struct timespec64*,int) ; 
 int /*<<< orphan*/  pr_err_ratelimited (char*,unsigned long) ; 
 int /*<<< orphan*/  preempt_disable_notrace () ; 
 int /*<<< orphan*/  preempt_enable_notrace () ; 
 unsigned int pvclock_read_begin (struct pvclock_vcpu_time_info*) ; 
 scalar_t__ pvclock_read_retry (struct pvclock_vcpu_time_info*,unsigned int) ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timespec64_to_ktime (struct timespec64) ; 

__attribute__((used)) static int ptp_kvm_get_time_fn(ktime_t *device_time,
			       struct system_counterval_t *system_counter,
			       void *ctx)
{
	unsigned long ret;
	struct timespec64 tspec;
	unsigned version;
	int cpu;
	struct pvclock_vcpu_time_info *src;

	spin_lock(&kvm_ptp_lock);

	preempt_disable_notrace();
	cpu = smp_processor_id();
	src = &hv_clock[cpu].pvti;

	do {
		/*
		 * We are using a TSC value read in the hosts
		 * kvm_hc_clock_pairing handling.
		 * So any changes to tsc_to_system_mul
		 * and tsc_shift or any other pvclock
		 * data invalidate that measurement.
		 */
		version = pvclock_read_begin(src);

		ret = kvm_hypercall2(KVM_HC_CLOCK_PAIRING,
				     clock_pair_gpa,
				     KVM_CLOCK_PAIRING_WALLCLOCK);
		if (ret != 0) {
			pr_err_ratelimited("clock pairing hypercall ret %lu\n", ret);
			spin_unlock(&kvm_ptp_lock);
			preempt_enable_notrace();
			return -EOPNOTSUPP;
		}

		tspec.tv_sec = clock_pair.sec;
		tspec.tv_nsec = clock_pair.nsec;
		ret = __pvclock_read_cycles(src, clock_pair.tsc);
	} while (pvclock_read_retry(src, version));

	preempt_enable_notrace();

	system_counter->cycles = ret;
	system_counter->cs = &kvm_clock;

	*device_time = timespec64_to_ktime(tspec);

	spin_unlock(&kvm_ptp_lock);

	return 0;
}

__attribute__((used)) static int ptp_kvm_getcrosststamp(struct ptp_clock_info *ptp,
				  struct system_device_crosststamp *xtstamp)
{
	return get_device_system_crosststamp(ptp_kvm_get_time_fn, NULL,
					     NULL, xtstamp);
}

__attribute__((used)) static int ptp_kvm_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static int ptp_kvm_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static int ptp_kvm_settime(struct ptp_clock_info *ptp,
			   const struct timespec64 *ts)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static int ptp_kvm_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
	unsigned long ret;
	struct timespec64 tspec;

	spin_lock(&kvm_ptp_lock);

	ret = kvm_hypercall2(KVM_HC_CLOCK_PAIRING,
			     clock_pair_gpa,
			     KVM_CLOCK_PAIRING_WALLCLOCK);
	if (ret != 0) {
		pr_err_ratelimited("clock offset hypercall ret %lu\n", ret);
		spin_unlock(&kvm_ptp_lock);
		return -EOPNOTSUPP;
	}

	tspec.tv_sec = clock_pair.sec;
	tspec.tv_nsec = clock_pair.nsec;
	spin_unlock(&kvm_ptp_lock);

	memcpy(ts, &tspec, sizeof(struct timespec64));

	return 0;
}

__attribute__((used)) static int ptp_kvm_enable(struct ptp_clock_info *ptp,
			  struct ptp_clock_request *rq, int on)
{
	return -EOPNOTSUPP;
}

