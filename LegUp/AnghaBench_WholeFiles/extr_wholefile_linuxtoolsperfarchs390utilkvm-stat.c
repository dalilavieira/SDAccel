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
struct perf_sample {int dummy; } ;
struct perf_kvm_stat {char* exit_reasons_isa; int /*<<< orphan*/  exit_reasons; } ;
struct perf_evsel {int dummy; } ;
struct event_key {int /*<<< orphan*/  exit_reasons; void* key; } ;

/* Variables and functions */
 int ENOTSUP ; 
 void* icpt_insn_decoder (unsigned long) ; 
 void* perf_evsel__intval (struct perf_evsel*,struct perf_sample*,char*) ; 
 int /*<<< orphan*/  sie_diagnose_codes ; 
 int /*<<< orphan*/  sie_exit_reasons ; 
 int /*<<< orphan*/  sie_icpt_insn_codes ; 
 int /*<<< orphan*/  sie_icpt_prog_codes ; 
 int /*<<< orphan*/  sie_sigp_order_codes ; 
 scalar_t__ strstr (char const*,char*) ; 

__attribute__((used)) static void event_icpt_insn_get_key(struct perf_evsel *evsel,
				    struct perf_sample *sample,
				    struct event_key *key)
{
	unsigned long insn;

	insn = perf_evsel__intval(evsel, sample, "instruction");
	key->key = icpt_insn_decoder(insn);
	key->exit_reasons = sie_icpt_insn_codes;
}

__attribute__((used)) static void event_sigp_get_key(struct perf_evsel *evsel,
			       struct perf_sample *sample,
			       struct event_key *key)
{
	key->key = perf_evsel__intval(evsel, sample, "order_code");
	key->exit_reasons = sie_sigp_order_codes;
}

__attribute__((used)) static void event_diag_get_key(struct perf_evsel *evsel,
			       struct perf_sample *sample,
			       struct event_key *key)
{
	key->key = perf_evsel__intval(evsel, sample, "code");
	key->exit_reasons = sie_diagnose_codes;
}

__attribute__((used)) static void event_icpt_prog_get_key(struct perf_evsel *evsel,
				    struct perf_sample *sample,
				    struct event_key *key)
{
	key->key = perf_evsel__intval(evsel, sample, "code");
	key->exit_reasons = sie_icpt_prog_codes;
}

int cpu_isa_init(struct perf_kvm_stat *kvm, const char *cpuid)
{
	if (strstr(cpuid, "IBM")) {
		kvm->exit_reasons = sie_exit_reasons;
		kvm->exit_reasons_isa = "SIE";
	} else
		return -ENOTSUP;

	return 0;
}

