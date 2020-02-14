#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  TYPE_1__* thread_t ;
struct kpcdata {int running; int counterc; int* counterv; int configc; int* configv; int /*<<< orphan*/  curcpu; } ;
struct TYPE_5__ {scalar_t__ kperf_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUF_DATA (int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  BUF_INFO (int,int,...) ; 
 int DBG_FUNC_END ; 
 int DBG_FUNC_START ; 
 int /*<<< orphan*/  KPC_CLASS_FIXED_MASK ; 
 int KPC_MAX_COUNTERS ; 
 int /*<<< orphan*/  PERF_KPC_CFG_REG ; 
 int /*<<< orphan*/  PERF_KPC_CONFIG ; 
 int PERF_KPC_CPU_SAMPLE ; 
 int /*<<< orphan*/  PERF_KPC_DATA ; 
 int /*<<< orphan*/  PERF_KPC_DATA32 ; 
 int /*<<< orphan*/  PERF_KPC_DATA_THREAD ; 
 int /*<<< orphan*/  PERF_KPC_DATA_THREAD32 ; 
 int PERF_KPC_THREAD_SAMPLE ; 
 int /*<<< orphan*/  kpc_get_config (int,int*) ; 
 void* kpc_get_config_count (int) ; 
 int kpc_get_counter_count (int /*<<< orphan*/ ) ; 
 int kpc_get_cpu_counters (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int*) ; 
 scalar_t__ kpc_get_curthread_counters (int*,int*) ; 
 void* kpc_get_running () ; 
 int /*<<< orphan*/  kpc_thread_ast_handler (TYPE_1__*) ; 
 int /*<<< orphan*/  kperf_thread_ast_handler (TYPE_1__*) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 

void
kperf_kpc_thread_ast(thread_t thread)
{
	kpc_thread_ast_handler(thread);
	kperf_thread_ast_handler(thread);

	thread->kperf_flags = 0;
}

void
kperf_kpc_thread_sample(struct kpcdata *kpcd, int sample_config)
{
	BUF_INFO(PERF_KPC_THREAD_SAMPLE | DBG_FUNC_START, sample_config);

	kpcd->running = kpc_get_running();
	/* let kpc_get_curthread_counters set the correct count */
	kpcd->counterc = KPC_MAX_COUNTERS;
	if (kpc_get_curthread_counters(&kpcd->counterc,
	                               kpcd->counterv)) {
		/* if thread counters aren't ready, default to 0 */
		memset(kpcd->counterv, 0,
		       sizeof(uint64_t) * kpcd->counterc);
	}
	/* help out Instruments by sampling KPC's config */
	if (!sample_config) {
		kpcd->configc = 0;
	} else {
		kpcd->configc = kpc_get_config_count(kpcd->running);
		kpc_get_config(kpcd->running, kpcd->configv);
	}

	BUF_INFO(PERF_KPC_THREAD_SAMPLE | DBG_FUNC_END, kpcd->running, kpcd->counterc);
}

void
kperf_kpc_cpu_sample(struct kpcdata *kpcd, int sample_config)
{
	BUF_INFO(PERF_KPC_CPU_SAMPLE | DBG_FUNC_START, sample_config);

	kpcd->running  = kpc_get_running();
	kpcd->counterc = kpc_get_cpu_counters(0, kpcd->running,
	                                      &kpcd->curcpu,
	                                      kpcd->counterv);
	if (!sample_config) {
		kpcd->configc = 0;
	} else {
		kpcd->configc = kpc_get_config_count(kpcd->running);
		kpc_get_config(kpcd->running, kpcd->configv);
	}

	BUF_INFO(PERF_KPC_CPU_SAMPLE | DBG_FUNC_END, kpcd->running, kpcd->counterc);
}

__attribute__((used)) static void
kperf_kpc_config_log(const struct kpcdata *kpcd)
{
	BUF_DATA(PERF_KPC_CONFIG,
	         kpcd->running,
	         kpcd->counterc,
	         kpc_get_counter_count(KPC_CLASS_FIXED_MASK),
	         kpcd->configc);
}

__attribute__((used)) static void
kperf_kpc_log(uint32_t code, uint32_t code32, const struct kpcdata *kpcd)
{
	unsigned i;

#if __LP64__
	(void)code32;
	/* config registers */
	for (i = 0; i < ((kpcd->configc + 3) / 4); i++) {
		BUF_DATA(PERF_KPC_CFG_REG,
		         kpcd->configv[0 + i * 4],
		         kpcd->configv[1 + i * 4],
		         kpcd->configv[2 + i * 4],
		         kpcd->configv[3 + i * 4]);
	}

	/* and the actual counts with one 64-bit argument each */
	for (i = 0; i < ((kpcd->counterc + 3) / 4); i++) {
		BUF_DATA(code,
		         kpcd->counterv[0 + i * 4],
		         kpcd->counterv[1 + i * 4],
		         kpcd->counterv[2 + i * 4],
		         kpcd->counterv[3 + i * 4]);
	}
#else
	(void)code;
	/* config registers */
	for (i = 0; i < ((kpcd->configc + 1) / 2); i++) {
		BUF_DATA(PERF_KPC_CFG_REG32,
		         (kpcd->configv[0 + i * 2] >> 32ULL),
		         kpcd->configv[0 + i * 2] & 0xffffffffULL,
		         (kpcd->configv[1 + i * 2] >> 32ULL),
		         kpcd->configv[1 + i * 2] & 0xffffffffULL);
	}

	/* and the actual counts with two 32-bit trace arguments each */
	for (i = 0; i < ((kpcd->counterc + 1) / 2); i++) {
		BUF_DATA(code32,
		         (kpcd->counterv[0 + i * 2] >> 32ULL),
		         kpcd->counterv[0 + i * 2] & 0xffffffffULL,
		         (kpcd->counterv[1 + i * 2] >> 32ULL),
		         kpcd->counterv[1 + i * 2] & 0xffffffffULL);
	}
#endif
}

void
kperf_kpc_cpu_log(const struct kpcdata *kpcd)
{
	kperf_kpc_config_log(kpcd);
	kperf_kpc_log(PERF_KPC_DATA, PERF_KPC_DATA32, kpcd);
}

void
kperf_kpc_thread_log(const struct kpcdata *kpcd)
{
	kperf_kpc_config_log(kpcd);
	kperf_kpc_log(PERF_KPC_DATA_THREAD, PERF_KPC_DATA_THREAD32, kpcd);
}

