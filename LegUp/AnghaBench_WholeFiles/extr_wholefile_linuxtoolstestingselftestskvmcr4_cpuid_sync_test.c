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
typedef  int uint32_t ;
struct kvm_vm {int dummy; } ;
struct kvm_sregs {int cr4; } ;
struct TYPE_2__ {int port; } ;
struct kvm_run {scalar_t__ exit_reason; TYPE_1__ io; } ;
struct kvm_cpuid_entry2 {int ecx; } ;

/* Variables and functions */
 int /*<<< orphan*/  GUEST_ASSERT (int) ; 
 int /*<<< orphan*/  GUEST_DONE () ; 
#define  GUEST_PORT_ABORT 130 
#define  GUEST_PORT_DONE 129 
#define  GUEST_PORT_SYNC 128 
 int /*<<< orphan*/  GUEST_SYNC (int /*<<< orphan*/ ) ; 
 scalar_t__ KVM_EXIT_IO ; 
 int /*<<< orphan*/  TEST_ASSERT (int,char*,...) ; 
 int /*<<< orphan*/  VCPU_ID ; 
 int X86_CR4_OSXSAVE ; 
 int X86_FEATURE_OSXSAVE ; 
 int X86_FEATURE_XSAVE ; 
 int _vcpu_run (struct kvm_vm*,int /*<<< orphan*/ ) ; 
 int get_cr4 () ; 
 int /*<<< orphan*/  kvm_get_supported_cpuid () ; 
 struct kvm_cpuid_entry2* kvm_get_supported_cpuid_entry (int) ; 
 int /*<<< orphan*/  kvm_vm_free (struct kvm_vm*) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  set_cr4 (int) ; 
 int /*<<< orphan*/  setbuf (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  vcpu_set_cpuid (struct kvm_vm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vcpu_sregs_get (struct kvm_vm*,int /*<<< orphan*/ ,struct kvm_sregs*) ; 
 int /*<<< orphan*/  vcpu_sregs_set (struct kvm_vm*,int /*<<< orphan*/ ,struct kvm_sregs*) ; 
 struct kvm_run* vcpu_state (struct kvm_vm*,int /*<<< orphan*/ ) ; 
 struct kvm_vm* vm_create_default (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) ()) ; 

__attribute__((used)) static inline bool cr4_cpuid_is_sync(void)
{
	int func, subfunc;
	uint32_t eax, ebx, ecx, edx;
	uint64_t cr4;

	func = 0x1;
	subfunc = 0x0;
	__asm__ __volatile__("cpuid"
			     : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
			     : "a"(func), "c"(subfunc));

	cr4 = get_cr4();

	return (!!(ecx & X86_FEATURE_OSXSAVE)) == (!!(cr4 & X86_CR4_OSXSAVE));
}

__attribute__((used)) static void guest_code(void)
{
	uint64_t cr4;

	/* turn on CR4.OSXSAVE */
	cr4 = get_cr4();
	cr4 |= X86_CR4_OSXSAVE;
	set_cr4(cr4);

	/* verify CR4.OSXSAVE == CPUID.OSXSAVE */
	GUEST_ASSERT(cr4_cpuid_is_sync());

	/* notify hypervisor to change CR4 */
	GUEST_SYNC(0);

	/* check again */
	GUEST_ASSERT(cr4_cpuid_is_sync());

	GUEST_DONE();
}

int main(int argc, char *argv[])
{
	struct kvm_run *run;
	struct kvm_vm *vm;
	struct kvm_sregs sregs;
	struct kvm_cpuid_entry2 *entry;
	int rc;

	entry = kvm_get_supported_cpuid_entry(1);
	if (!(entry->ecx & X86_FEATURE_XSAVE)) {
		printf("XSAVE feature not supported, skipping test\n");
		return 0;
	}

	/* Tell stdout not to buffer its content */
	setbuf(stdout, NULL);

	/* Create VM */
	vm = vm_create_default(VCPU_ID, 0, guest_code);
	vcpu_set_cpuid(vm, VCPU_ID, kvm_get_supported_cpuid());
	run = vcpu_state(vm, VCPU_ID);

	while (1) {
		rc = _vcpu_run(vm, VCPU_ID);

		if (run->exit_reason == KVM_EXIT_IO) {
			switch (run->io.port) {
			case GUEST_PORT_SYNC:
				/* emulate hypervisor clearing CR4.OSXSAVE */
				vcpu_sregs_get(vm, VCPU_ID, &sregs);
				sregs.cr4 &= ~X86_CR4_OSXSAVE;
				vcpu_sregs_set(vm, VCPU_ID, &sregs);
				break;
			case GUEST_PORT_ABORT:
				TEST_ASSERT(false, "Guest CR4 bit (OSXSAVE) unsynchronized with CPUID bit.");
				break;
			case GUEST_PORT_DONE:
				goto done;
			default:
				TEST_ASSERT(false, "Unknown port 0x%x.",
					    run->io.port);
			}
		}
	}

	kvm_vm_free(vm);

done:
	return 0;
}

