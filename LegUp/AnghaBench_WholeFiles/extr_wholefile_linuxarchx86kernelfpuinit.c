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
typedef  int u16 ;
struct cpuinfo_x86 {int dummy; } ;

/* Variables and functions */
 unsigned long X86_CR0_EM ; 
 unsigned long X86_CR0_TS ; 
 unsigned long X86_CR4_OSFXSR ; 
 unsigned long X86_CR4_OSXMMEXCPT ; 
 int /*<<< orphan*/  X86_FEATURE_CPUID ; 
 int /*<<< orphan*/  X86_FEATURE_FPU ; 
 int /*<<< orphan*/  X86_FEATURE_FXSR ; 
 int /*<<< orphan*/  X86_FEATURE_XMM ; 
 int /*<<< orphan*/  boot_cpu_data ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_caps_cleared ; 
 int /*<<< orphan*/  cr4_set_bits (unsigned long) ; 
 int /*<<< orphan*/  fpu__init_cpu_xstate () ; 
 int /*<<< orphan*/  pr_emerg (char*) ; 
 int /*<<< orphan*/  pr_info (char*,int,int) ; 
 unsigned long read_cr0 () ; 
 int /*<<< orphan*/  setup_clear_cpu_cap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_force_cpu_cap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  test_cpu_cap (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_cr0 (unsigned long) ; 

__attribute__((used)) static void fpu__init_cpu_generic(void)
{
	unsigned long cr0;
	unsigned long cr4_mask = 0;

	if (boot_cpu_has(X86_FEATURE_FXSR))
		cr4_mask |= X86_CR4_OSFXSR;
	if (boot_cpu_has(X86_FEATURE_XMM))
		cr4_mask |= X86_CR4_OSXMMEXCPT;
	if (cr4_mask)
		cr4_set_bits(cr4_mask);

	cr0 = read_cr0();
	cr0 &= ~(X86_CR0_TS|X86_CR0_EM); /* clear TS and EM */
	if (!boot_cpu_has(X86_FEATURE_FPU))
		cr0 |= X86_CR0_EM;
	write_cr0(cr0);

	/* Flush out any pending x87 state: */
#ifdef CONFIG_MATH_EMULATION
	if (!boot_cpu_has(X86_FEATURE_FPU))
		fpstate_init_soft(&current->thread.fpu.state.soft);
	else
#endif
		asm volatile ("fninit");
}

void fpu__init_cpu(void)
{
	fpu__init_cpu_generic();
	fpu__init_cpu_xstate();
}

__attribute__((used)) static bool fpu__probe_without_cpuid(void)
{
	unsigned long cr0;
	u16 fsw, fcw;

	fsw = fcw = 0xffff;

	cr0 = read_cr0();
	cr0 &= ~(X86_CR0_TS | X86_CR0_EM);
	write_cr0(cr0);

	asm volatile("fninit ; fnstsw %0 ; fnstcw %1" : "+m" (fsw), "+m" (fcw));

	pr_info("x86/fpu: Probing for FPU: FSW=0x%04hx FCW=0x%04hx\n", fsw, fcw);

	return fsw == 0 && (fcw & 0x103f) == 0x003f;
}

__attribute__((used)) static void fpu__init_system_early_generic(struct cpuinfo_x86 *c)
{
	if (!boot_cpu_has(X86_FEATURE_CPUID) &&
	    !test_bit(X86_FEATURE_FPU, (unsigned long *)cpu_caps_cleared)) {
		if (fpu__probe_without_cpuid())
			setup_force_cpu_cap(X86_FEATURE_FPU);
		else
			setup_clear_cpu_cap(X86_FEATURE_FPU);
	}

#ifndef CONFIG_MATH_EMULATION
	if (!test_cpu_cap(&boot_cpu_data, X86_FEATURE_FPU)) {
		pr_emerg("x86/fpu: Giving up, no FPU found and no math emulation present\n");
		for (;;)
			asm volatile("hlt");
	}
#endif
}

