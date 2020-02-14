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
struct elf32_hdr {scalar_t__ e_machine; int e_entry; unsigned int e_flags; } ;
struct TYPE_2__ {unsigned int personality; } ;

/* Variables and functions */
 unsigned int ADDR_LIMIT_32BIT ; 
 scalar_t__ CPU_ARCH_ARMv6 ; 
 unsigned int EF_ARM_APCS_26 ; 
 unsigned int EF_ARM_EABI_MASK ; 
 unsigned int EF_ARM_EABI_UNKNOWN ; 
 unsigned int EF_ARM_SOFT_FLOAT ; 
 unsigned int EF_ARM_VFP_FLOAT ; 
 scalar_t__ EM_ARM ; 
 int EXSTACK_DISABLE_X ; 
 int HWCAP_26BIT ; 
 int HWCAP_IWMMXT ; 
 int HWCAP_THUMB ; 
 int HWCAP_VFP ; 
 unsigned int PER_LINUX ; 
 unsigned int PER_MASK ; 
 int /*<<< orphan*/  TIF_USING_IWMMXT ; 
 int /*<<< orphan*/  clear_thread_flag (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_architecture () ; 
 TYPE_1__* current ; 
 int elf_hwcap ; 
 int /*<<< orphan*/  set_personality (unsigned int) ; 
 int /*<<< orphan*/  set_thread_flag (int /*<<< orphan*/ ) ; 

int elf_check_arch(const struct elf32_hdr *x)
{
	unsigned int eflags;

	/* Make sure it's an ARM executable */
	if (x->e_machine != EM_ARM)
		return 0;

	/* Make sure the entry address is reasonable */
	if (x->e_entry & 1) {
		if (!(elf_hwcap & HWCAP_THUMB))
			return 0;
	} else if (x->e_entry & 3)
		return 0;

	eflags = x->e_flags;
	if ((eflags & EF_ARM_EABI_MASK) == EF_ARM_EABI_UNKNOWN) {
		unsigned int flt_fmt;

		/* APCS26 is only allowed if the CPU supports it */
		if ((eflags & EF_ARM_APCS_26) && !(elf_hwcap & HWCAP_26BIT))
			return 0;

		flt_fmt = eflags & (EF_ARM_VFP_FLOAT | EF_ARM_SOFT_FLOAT);

		/* VFP requires the supporting code */
		if (flt_fmt == EF_ARM_VFP_FLOAT && !(elf_hwcap & HWCAP_VFP))
			return 0;
	}
	return 1;
}

void elf_set_personality(const struct elf32_hdr *x)
{
	unsigned int eflags = x->e_flags;
	unsigned int personality = current->personality & ~PER_MASK;

	/*
	 * We only support Linux ELF executables, so always set the
	 * personality to LINUX.
	 */
	personality |= PER_LINUX;

	/*
	 * APCS-26 is only valid for OABI executables
	 */
	if ((eflags & EF_ARM_EABI_MASK) == EF_ARM_EABI_UNKNOWN &&
	    (eflags & EF_ARM_APCS_26))
		personality &= ~ADDR_LIMIT_32BIT;
	else
		personality |= ADDR_LIMIT_32BIT;

	set_personality(personality);

	/*
	 * Since the FPA coprocessor uses CP1 and CP2, and iWMMXt uses CP0
	 * and CP1, we only enable access to the iWMMXt coprocessor if the
	 * binary is EABI or softfloat (and thus, guaranteed not to use
	 * FPA instructions.)
	 */
	if (elf_hwcap & HWCAP_IWMMXT &&
	    eflags & (EF_ARM_EABI_MASK | EF_ARM_SOFT_FLOAT)) {
		set_thread_flag(TIF_USING_IWMMXT);
	} else {
		clear_thread_flag(TIF_USING_IWMMXT);
	}
}

int arm_elf_read_implies_exec(int executable_stack)
{
	if (executable_stack != EXSTACK_DISABLE_X)
		return 1;
	if (cpu_architecture() < CPU_ARCH_ARMv6)
		return 1;
	return 0;
}

