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
typedef  int u64 ;
struct cpuinfo_x86 {int x86; int x86_model; int x86_cache_bits; } ;

/* Variables and functions */
#define  INTEL_FAM6_BROADWELL_CORE 140 
#define  INTEL_FAM6_BROADWELL_GT3E 139 
#define  INTEL_FAM6_HASWELL_CORE 138 
#define  INTEL_FAM6_HASWELL_GT3E 137 
#define  INTEL_FAM6_HASWELL_ULT 136 
#define  INTEL_FAM6_IVYBRIDGE 135 
#define  INTEL_FAM6_KABYLAKE_DESKTOP 134 
#define  INTEL_FAM6_KABYLAKE_MOBILE 133 
#define  INTEL_FAM6_NEHALEM 132 
#define  INTEL_FAM6_SANDYBRIDGE 131 
#define  INTEL_FAM6_SKYLAKE_DESKTOP 130 
#define  INTEL_FAM6_SKYLAKE_MOBILE 129 
#define  INTEL_FAM6_WESTMERE 128 
 int /*<<< orphan*/  MSR_AMD64_LS_CFG ; 
 int /*<<< orphan*/  MSR_AMD64_VIRT_SPEC_CTRL ; 
 int SPEC_CTRL_SSBD ; 
 int /*<<< orphan*/  X86_FEATURE_LS_CFG_SSBD ; 
 int /*<<< orphan*/  X86_FEATURE_VIRT_SSBD ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,char const*,int) ; 
 int /*<<< orphan*/  wrmsrl (int /*<<< orphan*/ ,int) ; 
 int x86_amd_ls_cfg_base ; 
 int x86_amd_ls_cfg_ssbd_mask ; 

__attribute__((used)) static void x86_amd_ssb_disable(void)
{
	u64 msrval = x86_amd_ls_cfg_base | x86_amd_ls_cfg_ssbd_mask;

	if (boot_cpu_has(X86_FEATURE_VIRT_SSBD))
		wrmsrl(MSR_AMD64_VIRT_SPEC_CTRL, SPEC_CTRL_SSBD);
	else if (boot_cpu_has(X86_FEATURE_LS_CFG_SSBD))
		wrmsrl(MSR_AMD64_LS_CFG, msrval);
}

__attribute__((used)) static inline const char *spectre_v2_module_string(void) { return ""; }

__attribute__((used)) static inline bool match_option(const char *arg, int arglen, const char *opt)
{
	int len = strlen(opt);

	return len == arglen && !strncmp(arg, opt, len);
}

__attribute__((used)) static void override_cache_bits(struct cpuinfo_x86 *c)
{
	if (c->x86 != 6)
		return;

	switch (c->x86_model) {
	case INTEL_FAM6_NEHALEM:
	case INTEL_FAM6_WESTMERE:
	case INTEL_FAM6_SANDYBRIDGE:
	case INTEL_FAM6_IVYBRIDGE:
	case INTEL_FAM6_HASWELL_CORE:
	case INTEL_FAM6_HASWELL_ULT:
	case INTEL_FAM6_HASWELL_GT3E:
	case INTEL_FAM6_BROADWELL_CORE:
	case INTEL_FAM6_BROADWELL_GT3E:
	case INTEL_FAM6_SKYLAKE_MOBILE:
	case INTEL_FAM6_SKYLAKE_DESKTOP:
	case INTEL_FAM6_KABYLAKE_MOBILE:
	case INTEL_FAM6_KABYLAKE_DESKTOP:
		if (c->x86_cache_bits < 44)
			c->x86_cache_bits = 44;
		break;
	}
}

