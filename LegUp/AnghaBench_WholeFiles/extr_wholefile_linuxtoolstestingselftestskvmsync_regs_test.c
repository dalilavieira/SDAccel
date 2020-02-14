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
struct kvm_vm {int dummy; } ;
struct kvm_vcpu_events {int dummy; } ;
struct kvm_sregs {int apic_base; } ;
struct kvm_regs {scalar_t__ rax; scalar_t__ rbx; scalar_t__ rcx; scalar_t__ rdx; scalar_t__ rsi; scalar_t__ rdi; scalar_t__ rsp; scalar_t__ rbp; scalar_t__ r8; scalar_t__ r9; scalar_t__ r10; scalar_t__ r11; scalar_t__ r12; scalar_t__ r13; scalar_t__ r14; scalar_t__ r15; scalar_t__ rip; scalar_t__ rflags; } ;
struct TYPE_3__ {struct kvm_regs regs; struct kvm_vcpu_events events; struct kvm_sregs sregs; } ;
struct TYPE_4__ {TYPE_1__ regs; } ;
struct kvm_run {int kvm_valid_regs; int kvm_dirty_regs; TYPE_2__ s; int /*<<< orphan*/  exit_reason; } ;

/* Variables and functions */
 scalar_t__ EINVAL ; 
 int /*<<< orphan*/  GUEST_SYNC (int /*<<< orphan*/ ) ; 
 int INVALID_SYNC_FIELD ; 
 int /*<<< orphan*/  KSFT_SKIP ; 
 int /*<<< orphan*/  KVM_CAP_SYNC_REGS ; 
 int /*<<< orphan*/  KVM_EXIT_IO ; 
 int KVM_SYNC_X86_REGS ; 
 int KVM_SYNC_X86_SREGS ; 
 int /*<<< orphan*/  TEST_ASSERT (int,char*,int,...) ; 
 int TEST_SYNC_FIELDS ; 
 int /*<<< orphan*/  VCPU_ID ; 
 int _vcpu_run (struct kvm_vm*,int /*<<< orphan*/ ) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit_reason_str (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int kvm_check_cap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_vm_free (struct kvm_vm*) ; 
 int /*<<< orphan*/  setbuf (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  vcpu_events_get (struct kvm_vm*,int /*<<< orphan*/ ,struct kvm_vcpu_events*) ; 
 int /*<<< orphan*/  vcpu_regs_get (struct kvm_vm*,int /*<<< orphan*/ ,struct kvm_regs*) ; 
 int /*<<< orphan*/  vcpu_regs_set (struct kvm_vm*,int /*<<< orphan*/ ,struct kvm_regs*) ; 
 int /*<<< orphan*/  vcpu_sregs_get (struct kvm_vm*,int /*<<< orphan*/ ,struct kvm_sregs*) ; 
 struct kvm_run* vcpu_state (struct kvm_vm*,int /*<<< orphan*/ ) ; 
 struct kvm_vm* vm_create_default (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) ()) ; 

void guest_code(void)
{
	for (;;) {
		GUEST_SYNC(0);
		asm volatile ("inc %r11");
	}
}

__attribute__((used)) static void compare_regs(struct kvm_regs *left, struct kvm_regs *right)
{
#define REG_COMPARE(reg) \
	TEST_ASSERT(left->reg == right->reg, \
		    "Register " #reg \
		    " values did not match: 0x%llx, 0x%llx\n", \
		    left->reg, right->reg)
	REG_COMPARE(rax);
	REG_COMPARE(rbx);
	REG_COMPARE(rcx);
	REG_COMPARE(rdx);
	REG_COMPARE(rsi);
	REG_COMPARE(rdi);
	REG_COMPARE(rsp);
	REG_COMPARE(rbp);
	REG_COMPARE(r8);
	REG_COMPARE(r9);
	REG_COMPARE(r10);
	REG_COMPARE(r11);
	REG_COMPARE(r12);
	REG_COMPARE(r13);
	REG_COMPARE(r14);
	REG_COMPARE(r15);
	REG_COMPARE(rip);
	REG_COMPARE(rflags);
#undef REG_COMPARE
}

__attribute__((used)) static void compare_sregs(struct kvm_sregs *left, struct kvm_sregs *right)
{
}

__attribute__((used)) static void compare_vcpu_events(struct kvm_vcpu_events *left,
				struct kvm_vcpu_events *right)
{
}

int main(int argc, char *argv[])
{
	struct kvm_vm *vm;
	struct kvm_run *run;
	struct kvm_regs regs;
	struct kvm_sregs sregs;
	struct kvm_vcpu_events events;
	int rv, cap;

	/* Tell stdout not to buffer its content */
	setbuf(stdout, NULL);

	cap = kvm_check_cap(KVM_CAP_SYNC_REGS);
	if ((cap & TEST_SYNC_FIELDS) != TEST_SYNC_FIELDS) {
		fprintf(stderr, "KVM_CAP_SYNC_REGS not supported, skipping test\n");
		exit(KSFT_SKIP);
	}
	if ((cap & INVALID_SYNC_FIELD) != 0) {
		fprintf(stderr, "The \"invalid\" field is not invalid, skipping test\n");
		exit(KSFT_SKIP);
	}

	/* Create VM */
	vm = vm_create_default(VCPU_ID, 0, guest_code);

	run = vcpu_state(vm, VCPU_ID);

	/* Request reading invalid register set from VCPU. */
	run->kvm_valid_regs = INVALID_SYNC_FIELD;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(rv < 0 && errno == EINVAL,
		    "Invalid kvm_valid_regs did not cause expected KVM_RUN error: %d\n",
		    rv);
	vcpu_state(vm, VCPU_ID)->kvm_valid_regs = 0;

	run->kvm_valid_regs = INVALID_SYNC_FIELD | TEST_SYNC_FIELDS;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(rv < 0 && errno == EINVAL,
		    "Invalid kvm_valid_regs did not cause expected KVM_RUN error: %d\n",
		    rv);
	vcpu_state(vm, VCPU_ID)->kvm_valid_regs = 0;

	/* Request setting invalid register set into VCPU. */
	run->kvm_dirty_regs = INVALID_SYNC_FIELD;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(rv < 0 && errno == EINVAL,
		    "Invalid kvm_dirty_regs did not cause expected KVM_RUN error: %d\n",
		    rv);
	vcpu_state(vm, VCPU_ID)->kvm_dirty_regs = 0;

	run->kvm_dirty_regs = INVALID_SYNC_FIELD | TEST_SYNC_FIELDS;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(rv < 0 && errno == EINVAL,
		    "Invalid kvm_dirty_regs did not cause expected KVM_RUN error: %d\n",
		    rv);
	vcpu_state(vm, VCPU_ID)->kvm_dirty_regs = 0;

	/* Request and verify all valid register sets. */
	/* TODO: BUILD TIME CHECK: TEST_ASSERT(KVM_SYNC_X86_NUM_FIELDS != 3); */
	run->kvm_valid_regs = TEST_SYNC_FIELDS;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
		    "Unexpected exit reason: %u (%s),\n",
		    run->exit_reason,
		    exit_reason_str(run->exit_reason));

	vcpu_regs_get(vm, VCPU_ID, &regs);
	compare_regs(&regs, &run->s.regs.regs);

	vcpu_sregs_get(vm, VCPU_ID, &sregs);
	compare_sregs(&sregs, &run->s.regs.sregs);

	vcpu_events_get(vm, VCPU_ID, &events);
	compare_vcpu_events(&events, &run->s.regs.events);

	/* Set and verify various register values. */
	run->s.regs.regs.r11 = 0xBAD1DEA;
	run->s.regs.sregs.apic_base = 1 << 11;
	/* TODO run->s.regs.events.XYZ = ABC; */

	run->kvm_valid_regs = TEST_SYNC_FIELDS;
	run->kvm_dirty_regs = KVM_SYNC_X86_REGS | KVM_SYNC_X86_SREGS;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
		    "Unexpected exit reason: %u (%s),\n",
		    run->exit_reason,
		    exit_reason_str(run->exit_reason));
	TEST_ASSERT(run->s.regs.regs.r11 == 0xBAD1DEA + 1,
		    "r11 sync regs value incorrect 0x%llx.",
		    run->s.regs.regs.r11);
	TEST_ASSERT(run->s.regs.sregs.apic_base == 1 << 11,
		    "apic_base sync regs value incorrect 0x%llx.",
		    run->s.regs.sregs.apic_base);

	vcpu_regs_get(vm, VCPU_ID, &regs);
	compare_regs(&regs, &run->s.regs.regs);

	vcpu_sregs_get(vm, VCPU_ID, &sregs);
	compare_sregs(&sregs, &run->s.regs.sregs);

	vcpu_events_get(vm, VCPU_ID, &events);
	compare_vcpu_events(&events, &run->s.regs.events);

	/* Clear kvm_dirty_regs bits, verify new s.regs values are
	 * overwritten with existing guest values.
	 */
	run->kvm_valid_regs = TEST_SYNC_FIELDS;
	run->kvm_dirty_regs = 0;
	run->s.regs.regs.r11 = 0xDEADBEEF;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
		    "Unexpected exit reason: %u (%s),\n",
		    run->exit_reason,
		    exit_reason_str(run->exit_reason));
	TEST_ASSERT(run->s.regs.regs.r11 != 0xDEADBEEF,
		    "r11 sync regs value incorrect 0x%llx.",
		    run->s.regs.regs.r11);

	/* Clear kvm_valid_regs bits and kvm_dirty_bits.
	 * Verify s.regs values are not overwritten with existing guest values
	 * and that guest values are not overwritten with kvm_sync_regs values.
	 */
	run->kvm_valid_regs = 0;
	run->kvm_dirty_regs = 0;
	run->s.regs.regs.r11 = 0xAAAA;
	regs.r11 = 0xBAC0;
	vcpu_regs_set(vm, VCPU_ID, &regs);
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
		    "Unexpected exit reason: %u (%s),\n",
		    run->exit_reason,
		    exit_reason_str(run->exit_reason));
	TEST_ASSERT(run->s.regs.regs.r11 == 0xAAAA,
		    "r11 sync regs value incorrect 0x%llx.",
		    run->s.regs.regs.r11);
	vcpu_regs_get(vm, VCPU_ID, &regs);
	TEST_ASSERT(regs.r11 == 0xBAC0 + 1,
		    "r11 guest value incorrect 0x%llx.",
		    regs.r11);

	/* Clear kvm_valid_regs bits. Verify s.regs values are not overwritten
	 * with existing guest values but that guest values are overwritten
	 * with kvm_sync_regs values.
	 */
	run->kvm_valid_regs = 0;
	run->kvm_dirty_regs = TEST_SYNC_FIELDS;
	run->s.regs.regs.r11 = 0xBBBB;
	rv = _vcpu_run(vm, VCPU_ID);
	TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
		    "Unexpected exit reason: %u (%s),\n",
		    run->exit_reason,
		    exit_reason_str(run->exit_reason));
	TEST_ASSERT(run->s.regs.regs.r11 == 0xBBBB,
		    "r11 sync regs value incorrect 0x%llx.",
		    run->s.regs.regs.r11);
	vcpu_regs_get(vm, VCPU_ID, &regs);
	TEST_ASSERT(regs.r11 == 0xBBBB + 1,
		    "r11 guest value incorrect 0x%llx.",
		    regs.r11);

	kvm_vm_free(vm);

	return 0;
}

