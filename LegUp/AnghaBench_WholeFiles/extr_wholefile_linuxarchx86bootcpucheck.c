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
typedef  int u32 ;
struct TYPE_2__ {int* flags; int level; int model; int family; } ;

/* Variables and functions */
 scalar_t__ A32 (char,char,char,char) ; 
 int /*<<< orphan*/  CONFIG_X86_64 ; 
 int /*<<< orphan*/  CONFIG_X86_PAE ; 
 int INTEL_FAM6_XEON_PHI_KNL ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int MSR_K7_HWCR ; 
 int MSR_VIA_FCR ; 
 int NCAPINTS ; 
 int /*<<< orphan*/  X86_EFLAGS_AC ; 
 int X86_FEATURE_CX8 ; 
 int /*<<< orphan*/  X86_FEATURE_LM ; 
 int X86_FEATURE_PAE ; 
 int X86_FEATURE_XMM ; 
 int X86_FEATURE_XMM2 ; 
 int check_knl_erratum () ; 
 scalar_t__ cmdline_find_option_bool (char*) ; 
 TYPE_1__ cpu ; 
 scalar_t__* cpu_vendor ; 
 int* err_flags ; 
 int /*<<< orphan*/  get_cpuflags () ; 
 scalar_t__ has_eflag (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int**,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int* req_flags ; 
 int req_level ; 
 int /*<<< orphan*/  set_bit (int,int*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int is_amd(void)
{
	return cpu_vendor[0] == A32('A', 'u', 't', 'h') &&
	       cpu_vendor[1] == A32('e', 'n', 't', 'i') &&
	       cpu_vendor[2] == A32('c', 'A', 'M', 'D');
}

__attribute__((used)) static int is_centaur(void)
{
	return cpu_vendor[0] == A32('C', 'e', 'n', 't') &&
	       cpu_vendor[1] == A32('a', 'u', 'r', 'H') &&
	       cpu_vendor[2] == A32('a', 'u', 'l', 's');
}

__attribute__((used)) static int is_transmeta(void)
{
	return cpu_vendor[0] == A32('G', 'e', 'n', 'u') &&
	       cpu_vendor[1] == A32('i', 'n', 'e', 'T') &&
	       cpu_vendor[2] == A32('M', 'x', '8', '6');
}

__attribute__((used)) static int is_intel(void)
{
	return cpu_vendor[0] == A32('G', 'e', 'n', 'u') &&
	       cpu_vendor[1] == A32('i', 'n', 'e', 'I') &&
	       cpu_vendor[2] == A32('n', 't', 'e', 'l');
}

__attribute__((used)) static int check_cpuflags(void)
{
	u32 err;
	int i;

	err = 0;
	for (i = 0; i < NCAPINTS; i++) {
		err_flags[i] = req_flags[i] & ~cpu.flags[i];
		if (err_flags[i])
			err |= 1 << i;
	}

	return err;
}

int check_cpu(int *cpu_level_ptr, int *req_level_ptr, u32 **err_flags_ptr)
{
	int err;

	memset(&cpu.flags, 0, sizeof cpu.flags);
	cpu.level = 3;

	if (has_eflag(X86_EFLAGS_AC))
		cpu.level = 4;

	get_cpuflags();
	err = check_cpuflags();

	if (test_bit(X86_FEATURE_LM, cpu.flags))
		cpu.level = 64;

	if (err == 0x01 &&
	    !(err_flags[0] &
	      ~((1 << X86_FEATURE_XMM)|(1 << X86_FEATURE_XMM2))) &&
	    is_amd()) {
		/* If this is an AMD and we're only missing SSE+SSE2, try to
		   turn them on */

		u32 ecx = MSR_K7_HWCR;
		u32 eax, edx;

		asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
		eax &= ~(1 << 15);
		asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));

		get_cpuflags();	/* Make sure it really did something */
		err = check_cpuflags();
	} else if (err == 0x01 &&
		   !(err_flags[0] & ~(1 << X86_FEATURE_CX8)) &&
		   is_centaur() && cpu.model >= 6) {
		/* If this is a VIA C3, we might have to enable CX8
		   explicitly */

		u32 ecx = MSR_VIA_FCR;
		u32 eax, edx;

		asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
		eax |= (1<<1)|(1<<7);
		asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));

		set_bit(X86_FEATURE_CX8, cpu.flags);
		err = check_cpuflags();
	} else if (err == 0x01 && is_transmeta()) {
		/* Transmeta might have masked feature bits in word 0 */

		u32 ecx = 0x80860004;
		u32 eax, edx;
		u32 level = 1;

		asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
		asm("wrmsr" : : "a" (~0), "d" (edx), "c" (ecx));
		asm("cpuid"
		    : "+a" (level), "=d" (cpu.flags[0])
		    : : "ecx", "ebx");
		asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));

		err = check_cpuflags();
	} else if (err == 0x01 &&
		   !(err_flags[0] & ~(1 << X86_FEATURE_PAE)) &&
		   is_intel() && cpu.level == 6 &&
		   (cpu.model == 9 || cpu.model == 13)) {
		/* PAE is disabled on this Pentium M but can be forced */
		if (cmdline_find_option_bool("forcepae")) {
			puts("WARNING: Forcing PAE in CPU flags\n");
			set_bit(X86_FEATURE_PAE, cpu.flags);
			err = check_cpuflags();
		}
		else {
			puts("WARNING: PAE disabled. Use parameter 'forcepae' to enable at your own risk!\n");
		}
	}
	if (!err)
		err = check_knl_erratum();

	if (err_flags_ptr)
		*err_flags_ptr = err ? err_flags : NULL;
	if (cpu_level_ptr)
		*cpu_level_ptr = cpu.level;
	if (req_level_ptr)
		*req_level_ptr = req_level;

	return (cpu.level < req_level || err) ? -1 : 0;
}

int check_knl_erratum(void)
{
	/*
	 * First check for the affected model/family:
	 */
	if (!is_intel() ||
	    cpu.family != 6 ||
	    cpu.model != INTEL_FAM6_XEON_PHI_KNL)
		return 0;

	/*
	 * This erratum affects the Accessed/Dirty bits, and can
	 * cause stray bits to be set in !Present PTEs.  We have
	 * enough bits in our 64-bit PTEs (which we have on real
	 * 64-bit mode or PAE) to avoid using these troublesome
	 * bits.  But, we do not have enough space in our 32-bit
	 * PTEs.  So, refuse to run on 32-bit non-PAE kernels.
	 */
	if (IS_ENABLED(CONFIG_X86_64) || IS_ENABLED(CONFIG_X86_PAE))
		return 0;

	puts("This 32-bit kernel can not run on this Xeon Phi x200\n"
	     "processor due to a processor erratum.  Use a 64-bit\n"
	     "kernel, or enable PAE in this 32-bit kernel.\n\n");

	return -1;
}

