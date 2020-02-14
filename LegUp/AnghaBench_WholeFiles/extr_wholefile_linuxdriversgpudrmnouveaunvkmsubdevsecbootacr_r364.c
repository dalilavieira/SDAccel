#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  size_t u32 ;
struct nvkm_secboot {scalar_t__ wpr_size; } ;
struct nvkm_gpuobj {int addr; int size; } ;
struct nvkm_acr {int dummy; } ;
struct hsf_load_header {size_t* apps; size_t num_apps; } ;
struct flcn_u64 {int lo; scalar_t__ hi; } ;
struct TYPE_6__ {int no_regions; TYPE_2__* region_props; } ;
struct acr_r364_hsflcn_desc {int wpr_region_id; int ucode_blob_base; int ucode_blob_size; TYPE_3__ regions; } ;
struct acr_r352 {TYPE_1__* func; struct nvkm_gpuobj* ls_blob; } ;
struct TYPE_5__ {int start_addr; int end_addr; int region_id; int read_mask; int write_mask; int client_mask; int shadow_mem_start_addr; } ;
struct TYPE_4__ {scalar_t__ shadow_blob; } ;

/* Variables and functions */
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_PMU ; 
 struct nvkm_acr* acr_r352_new_ (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  acr_r364_func ; 
 int lower_32_bits (int) ; 
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

__attribute__((used)) static inline u32
hsf_load_header_app_off(const struct hsf_load_header *hdr, u32 app)
{
	return hdr->apps[app];
}

__attribute__((used)) static inline u32
hsf_load_header_app_size(const struct hsf_load_header *hdr, u32 app)
{
	return hdr->apps[hdr->num_apps + app];
}

__attribute__((used)) static void
acr_r364_fixup_hs_desc(struct acr_r352 *acr, struct nvkm_secboot *sb,
		       void *_desc)
{
	struct acr_r364_hsflcn_desc *desc = _desc;
	struct nvkm_gpuobj *ls_blob = acr->ls_blob;

	/* WPR region information if WPR is not fixed */
	if (sb->wpr_size == 0) {
		u64 wpr_start = ls_blob->addr;
		u64 wpr_end = ls_blob->addr + ls_blob->size;

		if (acr->func->shadow_blob)
			wpr_start += ls_blob->size / 2;

		desc->wpr_region_id = 1;
		desc->regions.no_regions = 2;
		desc->regions.region_props[0].start_addr = wpr_start >> 8;
		desc->regions.region_props[0].end_addr = wpr_end >> 8;
		desc->regions.region_props[0].region_id = 1;
		desc->regions.region_props[0].read_mask = 0xf;
		desc->regions.region_props[0].write_mask = 0xc;
		desc->regions.region_props[0].client_mask = 0x2;
		if (acr->func->shadow_blob)
			desc->regions.region_props[0].shadow_mem_start_addr =
							     ls_blob->addr >> 8;
		else
			desc->regions.region_props[0].shadow_mem_start_addr = 0;
	} else {
		desc->ucode_blob_base = ls_blob->addr;
		desc->ucode_blob_size = ls_blob->size;
	}
}

struct nvkm_acr *
acr_r364_new(unsigned long managed_falcons)
{
	return acr_r352_new_(&acr_r364_func, NVKM_SECBOOT_FALCON_PMU,
			     managed_falcons);
}

