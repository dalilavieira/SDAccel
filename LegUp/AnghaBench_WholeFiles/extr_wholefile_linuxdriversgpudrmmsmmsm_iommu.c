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
typedef  int /*<<< orphan*/  uint64_t ;
struct timespec {int dummy; } ;
struct sg_table {int /*<<< orphan*/  nents; int /*<<< orphan*/  sgl; } ;
struct msm_rd_state {int dummy; } ;
struct msm_mmu_funcs {int dummy; } ;
struct msm_mmu {void* arg; int (* handler ) (void*,unsigned long,int) ;struct device* dev; struct msm_mmu_funcs const* funcs; } ;
struct msm_iommu {struct msm_mmu base; struct iommu_domain* domain; } ;
struct msm_gem_submit {int dummy; } ;
struct msm_drm_private {int dummy; } ;
struct iommu_domain {int dummy; } ;
struct drm_device {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ktime_t ;

/* Variables and functions */
 int ALIGN (int,int) ; 
 int EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct msm_mmu* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 struct msm_mmu_funcs funcs ; 
 int iommu_attach_device (struct iommu_domain*,struct device*) ; 
 int /*<<< orphan*/  iommu_detach_device (struct iommu_domain*,struct device*) ; 
 int /*<<< orphan*/  iommu_domain_free (struct iommu_domain*) ; 
 size_t iommu_map_sg (struct iommu_domain*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iommu_set_fault_handler (struct iommu_domain*,int (*) (struct iommu_domain*,struct device*,unsigned long,int,void*),struct msm_iommu*) ; 
 int /*<<< orphan*/  iommu_unmap (struct iommu_domain*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  kfree (struct msm_iommu*) ; 
 scalar_t__ ktime_compare (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get () ; 
 int /*<<< orphan*/  ktime_sub (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 struct timespec ktime_to_timespec (int /*<<< orphan*/ ) ; 
 struct msm_iommu* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int /*<<< orphan*/  pr_warn_ratelimited (char*,unsigned long,int) ; 
 int stub1 (void*,unsigned long,int) ; 
 unsigned long timespec_to_jiffies (struct timespec*) ; 
 struct msm_iommu* to_msm_iommu (struct msm_mmu*) ; 

__attribute__((used)) static inline int msm_debugfs_late_init(struct drm_device *dev) { return 0; }

__attribute__((used)) static inline void msm_rd_dump_submit(struct msm_rd_state *rd, struct msm_gem_submit *submit,
		const char *fmt, ...) {}

__attribute__((used)) static inline void msm_rd_debugfs_cleanup(struct msm_drm_private *priv) {}

__attribute__((used)) static inline void msm_perf_debugfs_cleanup(struct msm_drm_private *priv) {}

__attribute__((used)) static inline int align_pitch(int width, int bpp)
{
	int bytespp = (bpp + 7) / 8;
	/* adreno needs pitch aligned to 32 pixels: */
	return bytespp * ALIGN(width, 32);
}

__attribute__((used)) static inline unsigned long timeout_to_jiffies(const ktime_t *timeout)
{
	ktime_t now = ktime_get();
	unsigned long remaining_jiffies;

	if (ktime_compare(*timeout, now) < 0) {
		remaining_jiffies = 0;
	} else {
		ktime_t rem = ktime_sub(*timeout, now);
		struct timespec ts = ktime_to_timespec(rem);
		remaining_jiffies = timespec_to_jiffies(&ts);
	}

	return remaining_jiffies;
}

__attribute__((used)) static inline void msm_mmu_init(struct msm_mmu *mmu, struct device *dev,
		const struct msm_mmu_funcs *funcs)
{
	mmu->dev = dev;
	mmu->funcs = funcs;
}

__attribute__((used)) static inline void msm_mmu_set_fault_handler(struct msm_mmu *mmu, void *arg,
		int (*handler)(void *arg, unsigned long iova, int flags))
{
	mmu->arg = arg;
	mmu->handler = handler;
}

__attribute__((used)) static int msm_fault_handler(struct iommu_domain *domain, struct device *dev,
		unsigned long iova, int flags, void *arg)
{
	struct msm_iommu *iommu = arg;
	if (iommu->base.handler)
		return iommu->base.handler(iommu->base.arg, iova, flags);
	pr_warn_ratelimited("*** fault: iova=%08lx, flags=%d\n", iova, flags);
	return 0;
}

__attribute__((used)) static int msm_iommu_attach(struct msm_mmu *mmu, const char * const *names,
			    int cnt)
{
	struct msm_iommu *iommu = to_msm_iommu(mmu);
	int ret;

	pm_runtime_get_sync(mmu->dev);
	ret = iommu_attach_device(iommu->domain, mmu->dev);
	pm_runtime_put_sync(mmu->dev);

	return ret;
}

__attribute__((used)) static void msm_iommu_detach(struct msm_mmu *mmu, const char * const *names,
			     int cnt)
{
	struct msm_iommu *iommu = to_msm_iommu(mmu);

	pm_runtime_get_sync(mmu->dev);
	iommu_detach_device(iommu->domain, mmu->dev);
	pm_runtime_put_sync(mmu->dev);
}

__attribute__((used)) static int msm_iommu_map(struct msm_mmu *mmu, uint64_t iova,
		struct sg_table *sgt, unsigned len, int prot)
{
	struct msm_iommu *iommu = to_msm_iommu(mmu);
	size_t ret;

//	pm_runtime_get_sync(mmu->dev);
	ret = iommu_map_sg(iommu->domain, iova, sgt->sgl, sgt->nents, prot);
//	pm_runtime_put_sync(mmu->dev);
	WARN_ON(!ret);

	return (ret == len) ? 0 : -EINVAL;
}

__attribute__((used)) static int msm_iommu_unmap(struct msm_mmu *mmu, uint64_t iova,
		struct sg_table *sgt, unsigned len)
{
	struct msm_iommu *iommu = to_msm_iommu(mmu);

	pm_runtime_get_sync(mmu->dev);
	iommu_unmap(iommu->domain, iova, len);
	pm_runtime_put_sync(mmu->dev);

	return 0;
}

__attribute__((used)) static void msm_iommu_destroy(struct msm_mmu *mmu)
{
	struct msm_iommu *iommu = to_msm_iommu(mmu);
	iommu_domain_free(iommu->domain);
	kfree(iommu);
}

struct msm_mmu *msm_iommu_new(struct device *dev, struct iommu_domain *domain)
{
	struct msm_iommu *iommu;

	iommu = kzalloc(sizeof(*iommu), GFP_KERNEL);
	if (!iommu)
		return ERR_PTR(-ENOMEM);

	iommu->domain = domain;
	msm_mmu_init(&iommu->base, dev, &funcs);
	iommu_set_fault_handler(domain, msm_fault_handler, iommu);

	return &iommu->base;
}

