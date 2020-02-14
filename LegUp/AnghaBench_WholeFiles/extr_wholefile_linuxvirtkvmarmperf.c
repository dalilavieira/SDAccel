#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 struct kvm_vcpu* kvm_arm_get_running_vcpu () ; 
 int /*<<< orphan*/  kvm_guest_cbs ; 
 int perf_register_guest_info_callbacks (int /*<<< orphan*/ *) ; 
 int perf_unregister_guest_info_callbacks (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vcpu_mode_priv (struct kvm_vcpu*) ; 
 unsigned long* vcpu_pc (struct kvm_vcpu*) ; 

__attribute__((used)) static int kvm_is_in_guest(void)
{
        return kvm_arm_get_running_vcpu() != NULL;
}

__attribute__((used)) static int kvm_is_user_mode(void)
{
	struct kvm_vcpu *vcpu;

	vcpu = kvm_arm_get_running_vcpu();

	if (vcpu)
		return !vcpu_mode_priv(vcpu);

	return 0;
}

__attribute__((used)) static unsigned long kvm_get_guest_ip(void)
{
	struct kvm_vcpu *vcpu;

	vcpu = kvm_arm_get_running_vcpu();

	if (vcpu)
		return *vcpu_pc(vcpu);

	return 0;
}

int kvm_perf_init(void)
{
	return perf_register_guest_info_callbacks(&kvm_guest_cbs);
}

int kvm_perf_teardown(void)
{
	return perf_unregister_guest_info_callbacks(&kvm_guest_cbs);
}

