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
typedef  int uint64_t ;
struct kvm_vm {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  port; } ;
struct kvm_run {scalar_t__ exit_reason; TYPE_1__ io; } ;
struct kvm_enable_cap {int* args; scalar_t__ flags; int /*<<< orphan*/  cap; } ;
struct guest_args {scalar_t__ port; int arg1; } ;

/* Variables and functions */
 scalar_t__ GUEST_PORT_SYNC ; 
 int /*<<< orphan*/  GUEST_SYNC (int) ; 
 int /*<<< orphan*/  KSFT_SKIP ; 
 int /*<<< orphan*/  KVM_CAP_MSR_PLATFORM_INFO ; 
 scalar_t__ KVM_EXIT_IO ; 
 scalar_t__ KVM_EXIT_SHUTDOWN ; 
 int /*<<< orphan*/  MSR_PLATFORM_INFO ; 
 int MSR_PLATFORM_INFO_MAX_TURBO_RATIO ; 
 int /*<<< orphan*/  TEST_ASSERT (int,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  VCPU_ID ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit_reason_str (scalar_t__) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  guest_args_read (struct kvm_vm*,int /*<<< orphan*/ ,struct guest_args*) ; 
 int kvm_check_cap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_vm_free (struct kvm_vm*) ; 
 int rdmsr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setbuf (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int vcpu_get_msr (struct kvm_vm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vcpu_run (struct kvm_vm*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vcpu_set_msr (struct kvm_vm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct kvm_run* vcpu_state (struct kvm_vm*,int /*<<< orphan*/ ) ; 
 struct kvm_vm* vm_create_default (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) ()) ; 
 int /*<<< orphan*/  vm_enable_cap (struct kvm_vm*,struct kvm_enable_cap*) ; 

__attribute__((used)) static void guest_code(void)
{
	uint64_t msr_platform_info;

	for (;;) {
		msr_platform_info = rdmsr(MSR_PLATFORM_INFO);
		GUEST_SYNC(msr_platform_info);
		asm volatile ("inc %r11");
	}
}

__attribute__((used)) static void set_msr_platform_info_enabled(struct kvm_vm *vm, bool enable)
{
	struct kvm_enable_cap cap = {};

	cap.cap = KVM_CAP_MSR_PLATFORM_INFO;
	cap.flags = 0;
	cap.args[0] = (int)enable;
	vm_enable_cap(vm, &cap);
}

__attribute__((used)) static void test_msr_platform_info_enabled(struct kvm_vm *vm)
{
	struct kvm_run *run = vcpu_state(vm, VCPU_ID);
	struct guest_args args;

	set_msr_platform_info_enabled(vm, true);
	vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
			"Exit_reason other than KVM_EXIT_IO: %u (%s),\n",
			run->exit_reason,
			exit_reason_str(run->exit_reason));
	guest_args_read(vm, VCPU_ID, &args);
	TEST_ASSERT(args.port == GUEST_PORT_SYNC,
			"Received IO from port other than PORT_HOST_SYNC: %u\n",
			run->io.port);
	TEST_ASSERT((args.arg1 & MSR_PLATFORM_INFO_MAX_TURBO_RATIO) ==
		MSR_PLATFORM_INFO_MAX_TURBO_RATIO,
		"Expected MSR_PLATFORM_INFO to have max turbo ratio mask: %i.",
		MSR_PLATFORM_INFO_MAX_TURBO_RATIO);
}

__attribute__((used)) static void test_msr_platform_info_disabled(struct kvm_vm *vm)
{
	struct kvm_run *run = vcpu_state(vm, VCPU_ID);

	set_msr_platform_info_enabled(vm, false);
	vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_SHUTDOWN,
			"Exit_reason other than KVM_EXIT_SHUTDOWN: %u (%s)\n",
			run->exit_reason,
			exit_reason_str(run->exit_reason));
}

int main(int argc, char *argv[])
{
	struct kvm_vm *vm;
	struct kvm_run *state;
	int rv;
	uint64_t msr_platform_info;

	/* Tell stdout not to buffer its content */
	setbuf(stdout, NULL);

	rv = kvm_check_cap(KVM_CAP_MSR_PLATFORM_INFO);
	if (!rv) {
		fprintf(stderr,
			"KVM_CAP_MSR_PLATFORM_INFO not supported, skip test\n");
		exit(KSFT_SKIP);
	}

	vm = vm_create_default(VCPU_ID, 0, guest_code);

	msr_platform_info = vcpu_get_msr(vm, VCPU_ID, MSR_PLATFORM_INFO);
	vcpu_set_msr(vm, VCPU_ID, MSR_PLATFORM_INFO,
		msr_platform_info | MSR_PLATFORM_INFO_MAX_TURBO_RATIO);
	test_msr_platform_info_disabled(vm);
	test_msr_platform_info_enabled(vm);
	vcpu_set_msr(vm, VCPU_ID, MSR_PLATFORM_INFO, msr_platform_info);

	kvm_vm_free(vm);

	return 0;
}

