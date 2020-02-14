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
struct nvkm_secboot {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct nvkm_acr {int dummy; } ;
struct gm200_secboot {struct nvkm_secboot base; } ;
struct flcn_u64 {int lo; scalar_t__ hi; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct nvkm_acr*) ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_FECS ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_GPCCS ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_PMU ; 
 int PTR_ERR (struct nvkm_acr*) ; 
 int /*<<< orphan*/  TEGRA186_MC_BASE ; 
 struct nvkm_acr* acr_r352_new (int) ; 
 struct gm200_secboot* gm200_secboot (struct nvkm_secboot*) ; 
 int gm200_secboot_oneinit (struct nvkm_secboot*) ; 
 int gm20b_secboot_tegra_read_wpr (struct gm200_secboot*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gp10b_secboot ; 
 struct gm200_secboot* kzalloc (int,int /*<<< orphan*/ ) ; 
 int lower_32_bits (int) ; 
 int nvkm_secboot_ctor (int /*<<< orphan*/ *,struct nvkm_acr*,struct nvkm_device*,int,struct nvkm_secboot*) ; 
 scalar_t__ upper_32_bits (int) ; 

__attribute__((used)) static inline u64 flcn64_to_u64(const struct flcn_u64 f)
{
	return ((u64)f.hi) << 32 | f.lo;
}

__attribute__((used)) static inline struct flcn_u64 u64_to_flcn64(u64 u)
{
	struct flcn_u64 ret;

	ret.hi = upper_32_bits(u);
	ret.lo = lower_32_bits(u);

	return ret;
}

__attribute__((used)) static int
gp10b_secboot_oneinit(struct nvkm_secboot *sb)
{
	struct gm200_secboot *gsb = gm200_secboot(sb);
	int ret;

	ret = gm20b_secboot_tegra_read_wpr(gsb, TEGRA186_MC_BASE);
	if (ret)
		return ret;

	return gm200_secboot_oneinit(sb);
}

int
gp10b_secboot_new(struct nvkm_device *device, int index,
		  struct nvkm_secboot **psb)
{
	int ret;
	struct gm200_secboot *gsb;
	struct nvkm_acr *acr;

	acr = acr_r352_new(BIT(NVKM_SECBOOT_FALCON_FECS) |
			   BIT(NVKM_SECBOOT_FALCON_GPCCS) |
			   BIT(NVKM_SECBOOT_FALCON_PMU));
	if (IS_ERR(acr))
		return PTR_ERR(acr);

	gsb = kzalloc(sizeof(*gsb), GFP_KERNEL);
	if (!gsb) {
		psb = NULL;
		return -ENOMEM;
	}
	*psb = &gsb->base;

	ret = nvkm_secboot_ctor(&gp10b_secboot, acr, device, index, &gsb->base);
	if (ret)
		return ret;

	return 0;
}

