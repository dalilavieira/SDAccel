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
typedef  int u64 ;
struct nvkm_secboot {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct nvkm_acr {TYPE_1__* func; } ;
struct gm200_secboot {struct nvkm_secboot base; } ;
struct flcn_u64 {int lo; scalar_t__ hi; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* dtor ) (struct nvkm_acr*) ;} ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct nvkm_acr*) ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_FECS ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_GPCCS ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_SEC2 ; 
 int PTR_ERR (struct nvkm_acr*) ; 
 struct nvkm_acr* acr_r370_new (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  gp102_secboot ; 
 struct gm200_secboot* kzalloc (int,int /*<<< orphan*/ ) ; 
 int lower_32_bits (int) ; 
 int nvkm_secboot_ctor (int /*<<< orphan*/ *,struct nvkm_acr*,struct nvkm_device*,int,struct nvkm_secboot*) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_acr*) ; 
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

int
gp108_secboot_new(struct nvkm_device *device, int index,
		  struct nvkm_secboot **psb)
{
	struct gm200_secboot *gsb;
	struct nvkm_acr *acr;

	acr = acr_r370_new(NVKM_SECBOOT_FALCON_SEC2,
			   BIT(NVKM_SECBOOT_FALCON_FECS) |
			   BIT(NVKM_SECBOOT_FALCON_GPCCS) |
			   BIT(NVKM_SECBOOT_FALCON_SEC2));
	if (IS_ERR(acr))
		return PTR_ERR(acr);

	if (!(gsb = kzalloc(sizeof(*gsb), GFP_KERNEL))) {
		acr->func->dtor(acr);
		return -ENOMEM;
	}
	*psb = &gsb->base;

	return nvkm_secboot_ctor(&gp102_secboot, acr, device, index, &gsb->base);
}

