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
struct nvkm_subdev {int /*<<< orphan*/  device; } ;
struct flcn_u64 {int lo; scalar_t__ hi; } ;
struct firmware {size_t size; int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 void* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* kmemdup (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ) ; 
 int lower_32_bits (int) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev const*,char*,char const*,size_t) ; 
 int nvkm_firmware_get (int /*<<< orphan*/ ,char const*,struct firmware const**) ; 
 int /*<<< orphan*/  nvkm_firmware_put (struct firmware const*) ; 
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

void *
nvkm_acr_load_firmware(const struct nvkm_subdev *subdev, const char *name,
		       size_t min_size)
{
	const struct firmware *fw;
	void *blob;
	int ret;

	ret = nvkm_firmware_get(subdev->device, name, &fw);
	if (ret)
		return ERR_PTR(ret);
	if (fw->size < min_size) {
		nvkm_error(subdev, "%s is smaller than expected size %zu\n",
			   name, min_size);
		nvkm_firmware_put(fw);
		return ERR_PTR(-EINVAL);
	}
	blob = kmemdup(fw->data, fw->size, GFP_KERNEL);
	nvkm_firmware_put(fw);
	if (!blob)
		return ERR_PTR(-ENOMEM);

	return blob;
}

