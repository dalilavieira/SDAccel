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
typedef  int u32 ;
struct nvkm_subdev {int dummy; } ;
struct nvkm_falcon {scalar_t__ debug; } ;
struct hsf_fw_header {int patch_loc; int patch_sig; int sig_dbg_offset; int sig_dbg_size; int sig_prod_offset; int sig_prod_size; } ;
struct fw_bin_header {int header_offset; int data_offset; } ;
struct flcn_u64 {int lo; scalar_t__ hi; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 void* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (void*) ; 
 int lower_32_bits (int) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 void* nvkm_acr_load_firmware (struct nvkm_subdev*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*,char const*) ; 
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

__attribute__((used)) static void
hs_ucode_patch_signature(const struct nvkm_falcon *falcon, void *acr_image,
			 bool new_format)
{
	struct fw_bin_header *hsbin_hdr = acr_image;
	struct hsf_fw_header *fw_hdr = acr_image + hsbin_hdr->header_offset;
	void *hs_data = acr_image + hsbin_hdr->data_offset;
	void *sig;
	u32 sig_size;
	u32 patch_loc, patch_sig;

	/*
	 * I had the brilliant idea to "improve" the binary format by
	 * removing this useless indirection. However to make NVIDIA files
	 * directly compatible, let's support both format.
	 */
	if (new_format) {
		patch_loc = fw_hdr->patch_loc;
		patch_sig = fw_hdr->patch_sig;
	} else {
		patch_loc = *(u32 *)(acr_image + fw_hdr->patch_loc);
		patch_sig = *(u32 *)(acr_image + fw_hdr->patch_sig);
	}

	/* Falcon in debug or production mode? */
	if (falcon->debug) {
		sig = acr_image + fw_hdr->sig_dbg_offset;
		sig_size = fw_hdr->sig_dbg_size;
	} else {
		sig = acr_image + fw_hdr->sig_prod_offset;
		sig_size = fw_hdr->sig_prod_size;
	}

	/* Patch signature */
	memcpy(hs_data + patch_loc, sig + patch_sig, sig_size);
}

void *
hs_ucode_load_blob(struct nvkm_subdev *subdev, const struct nvkm_falcon *falcon,
		   const char *fw)
{
	void *acr_image;
	bool new_format;

	acr_image = nvkm_acr_load_firmware(subdev, fw, 0);
	if (IS_ERR(acr_image))
		return acr_image;

	/* detect the format to define how signature should be patched */
	switch (((u32 *)acr_image)[0]) {
	case 0x3b1d14f0:
		new_format = true;
		break;
	case 0x000010de:
		new_format = false;
		break;
	default:
		nvkm_error(subdev, "unknown header for HS blob %s\n", fw);
		return ERR_PTR(-EINVAL);
	}

	hs_ucode_patch_signature(falcon, acr_image, new_format);

	return acr_image;
}

