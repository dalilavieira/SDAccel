#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct timespec64 {int dummy; } ;
struct timespec {int dummy; } ;
struct etnaviv_chip_identity {scalar_t__ model; scalar_t__ revision; } ;
struct etnaviv_gpu {struct etnaviv_chip_identity identity; scalar_t__ completed_fence; scalar_t__ mmio; } ;
typedef  scalar_t__ s32 ;
struct TYPE_4__ {scalar_t__ model; scalar_t__ revision; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 size_t SIZE_MAX ; 
 TYPE_1__* etnaviv_chip_identities ; 
 int /*<<< orphan*/  ktime_get_ts64 (struct timespec64*) ; 
 int /*<<< orphan*/  memcpy (struct etnaviv_chip_identity*,TYPE_1__*,int) ; 
 scalar_t__ readl (scalar_t__) ; 
 scalar_t__ timespec64_compare (struct timespec64*,struct timespec64*) ; 
 struct timespec64 timespec64_sub (struct timespec64,struct timespec64) ; 
 unsigned long timespec64_to_jiffies (struct timespec64*) ; 
 struct timespec64 timespec_to_timespec64 (struct timespec const) ; 
 int /*<<< orphan*/  writel (scalar_t__,scalar_t__) ; 

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

bool etnaviv_fill_identity_from_hwdb(struct etnaviv_gpu *gpu)
{
	struct etnaviv_chip_identity *ident = &gpu->identity;
	int i;

	for (i = 0; i < ARRAY_SIZE(etnaviv_chip_identities); i++) {
		if (etnaviv_chip_identities[i].model == ident->model &&
		    etnaviv_chip_identities[i].revision == ident->revision) {
			memcpy(ident, &etnaviv_chip_identities[i],
			       sizeof(*ident));
			return true;
		}
	}

	return false;
}

