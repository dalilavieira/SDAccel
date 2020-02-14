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
typedef  size_t u32 ;
struct timespec64 {int dummy; } ;
struct timespec {int dummy; } ;
struct etnaviv_pm_signal {size_t data; size_t (* sample ) (struct etnaviv_gpu*,struct etnaviv_pm_domain const*,struct etnaviv_pm_signal const*) ;int /*<<< orphan*/  name; } ;
struct etnaviv_pm_domain_meta {scalar_t__ nr_domains; struct etnaviv_pm_domain* domains; } ;
struct etnaviv_pm_domain {size_t profile_config; size_t profile_read; scalar_t__ nr_signals; struct etnaviv_pm_signal* signal; int /*<<< orphan*/  name; } ;
struct etnaviv_perfmon_request {size_t* bo_vma; int domain; size_t signal; int offset; } ;
struct TYPE_2__ {unsigned int pixel_pipes; } ;
struct etnaviv_gpu {size_t mmio; size_t completed_fence; TYPE_1__ identity; } ;
struct drm_etnaviv_pm_signal {size_t pipe; scalar_t__ domain; scalar_t__ iter; size_t id; int /*<<< orphan*/  name; } ;
struct drm_etnaviv_pm_domain {size_t pipe; scalar_t__ iter; int id; scalar_t__ nr_signals; int /*<<< orphan*/  name; } ;
struct drm_etnaviv_gem_submit_pmr {scalar_t__ domain; scalar_t__ signal; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int EINVAL ; 
 size_t SIZE_MAX ; 
 size_t VIVS_HI_CLOCK_CONTROL ; 
 size_t VIVS_HI_CLOCK_CONTROL_DEBUG_PIXEL_PIPE (unsigned int) ; 
 size_t VIVS_HI_CLOCK_CONTROL_DEBUG_PIXEL_PIPE__MASK ; 
 struct etnaviv_pm_domain_meta* doms_meta ; 
 int /*<<< orphan*/  ktime_get_ts64 (struct timespec64*) ; 
 size_t readl (size_t) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 size_t stub1 (struct etnaviv_gpu*,struct etnaviv_pm_domain const*,struct etnaviv_pm_signal const*) ; 
 scalar_t__ timespec64_compare (struct timespec64*,struct timespec64*) ; 
 struct timespec64 timespec64_sub (struct timespec64,struct timespec64) ; 
 unsigned long timespec64_to_jiffies (struct timespec64*) ; 
 struct timespec64 timespec_to_timespec64 (struct timespec const) ; 
 int /*<<< orphan*/  writel (size_t,size_t) ; 

__attribute__((used)) static inline size_t size_vstruct(size_t nelem, size_t elem_size, size_t base)
{
	if (elem_size && nelem > (SIZE_MAX - base) / elem_size)
		return 0;
	return base + nelem * elem_size;
}

__attribute__((used)) static inline bool fence_after(u32 a, u32 b)
{
	return (s32)(a - b) > 0;
}

__attribute__((used)) static inline bool fence_after_eq(u32 a, u32 b)
{
	return (s32)(a - b) >= 0;
}

__attribute__((used)) static inline unsigned long etnaviv_timeout_to_jiffies(
	const struct timespec *timeout)
{
	struct timespec64 ts, to;

	to = timespec_to_timespec64(*timeout);

	ktime_get_ts64(&ts);

	/* timeouts before "now" have already expired */
	if (timespec64_compare(&to, &ts) <= 0)
		return 0;

	ts = timespec64_sub(to, ts);

	return timespec64_to_jiffies(&ts);
}

__attribute__((used)) static inline void gpu_write(struct etnaviv_gpu *gpu, u32 reg, u32 data)
{
	writel(data, gpu->mmio + reg);
}

__attribute__((used)) static inline u32 gpu_read(struct etnaviv_gpu *gpu, u32 reg)
{
	return readl(gpu->mmio + reg);
}

__attribute__((used)) static inline bool fence_completed(struct etnaviv_gpu *gpu, u32 fence)
{
	return fence_after_eq(gpu->completed_fence, fence);
}

__attribute__((used)) static u32 simple_reg_read(struct etnaviv_gpu *gpu,
	const struct etnaviv_pm_domain *domain,
	const struct etnaviv_pm_signal *signal)
{
	return gpu_read(gpu, signal->data);
}

__attribute__((used)) static u32 perf_reg_read(struct etnaviv_gpu *gpu,
	const struct etnaviv_pm_domain *domain,
	const struct etnaviv_pm_signal *signal)
{
	gpu_write(gpu, domain->profile_config, signal->data);

	return gpu_read(gpu, domain->profile_read);
}

__attribute__((used)) static u32 pipe_reg_read(struct etnaviv_gpu *gpu,
	const struct etnaviv_pm_domain *domain,
	const struct etnaviv_pm_signal *signal)
{
	u32 clock = gpu_read(gpu, VIVS_HI_CLOCK_CONTROL);
	u32 value = 0;
	unsigned i;

	for (i = 0; i < gpu->identity.pixel_pipes; i++) {
		clock &= ~(VIVS_HI_CLOCK_CONTROL_DEBUG_PIXEL_PIPE__MASK);
		clock |= VIVS_HI_CLOCK_CONTROL_DEBUG_PIXEL_PIPE(i);
		gpu_write(gpu, VIVS_HI_CLOCK_CONTROL, clock);
		gpu_write(gpu, domain->profile_config, signal->data);
		value += gpu_read(gpu, domain->profile_read);
	}

	/* switch back to pixel pipe 0 to prevent GPU hang */
	clock &= ~(VIVS_HI_CLOCK_CONTROL_DEBUG_PIXEL_PIPE__MASK);
	clock |= VIVS_HI_CLOCK_CONTROL_DEBUG_PIXEL_PIPE(0);
	gpu_write(gpu, VIVS_HI_CLOCK_CONTROL, clock);

	return value;
}

int etnaviv_pm_query_dom(struct etnaviv_gpu *gpu,
	struct drm_etnaviv_pm_domain *domain)
{
	const struct etnaviv_pm_domain_meta *meta = &doms_meta[domain->pipe];
	const struct etnaviv_pm_domain *dom;

	if (domain->iter >= meta->nr_domains)
		return -EINVAL;

	dom = meta->domains + domain->iter;

	domain->id = domain->iter;
	domain->nr_signals = dom->nr_signals;
	strncpy(domain->name, dom->name, sizeof(domain->name));

	domain->iter++;
	if (domain->iter == meta->nr_domains)
		domain->iter = 0xff;

	return 0;
}

int etnaviv_pm_query_sig(struct etnaviv_gpu *gpu,
	struct drm_etnaviv_pm_signal *signal)
{
	const struct etnaviv_pm_domain_meta *meta = &doms_meta[signal->pipe];
	const struct etnaviv_pm_domain *dom;
	const struct etnaviv_pm_signal *sig;

	if (signal->domain >= meta->nr_domains)
		return -EINVAL;

	dom = meta->domains + signal->domain;

	if (signal->iter > dom->nr_signals)
		return -EINVAL;

	sig = &dom->signal[signal->iter];

	signal->id = signal->iter;
	strncpy(signal->name, sig->name, sizeof(signal->name));

	signal->iter++;
	if (signal->iter == dom->nr_signals)
		signal->iter = 0xffff;

	return 0;
}

int etnaviv_pm_req_validate(const struct drm_etnaviv_gem_submit_pmr *r,
	u32 exec_state)
{
	const struct etnaviv_pm_domain_meta *meta = &doms_meta[exec_state];
	const struct etnaviv_pm_domain *dom;

	if (r->domain >= meta->nr_domains)
		return -EINVAL;

	dom = meta->domains + r->domain;

	if (r->signal > dom->nr_signals)
		return -EINVAL;

	return 0;
}

void etnaviv_perfmon_process(struct etnaviv_gpu *gpu,
	const struct etnaviv_perfmon_request *pmr, u32 exec_state)
{
	const struct etnaviv_pm_domain_meta *meta = &doms_meta[exec_state];
	const struct etnaviv_pm_domain *dom;
	const struct etnaviv_pm_signal *sig;
	u32 *bo = pmr->bo_vma;
	u32 val;

	dom = meta->domains + pmr->domain;
	sig = &dom->signal[pmr->signal];
	val = sig->sample(gpu, dom, sig);

	*(bo + pmr->offset) = val;
}

