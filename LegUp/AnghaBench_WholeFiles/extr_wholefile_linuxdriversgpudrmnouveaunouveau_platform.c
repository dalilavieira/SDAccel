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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct nvkm_device_tegra_func {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct nvif_mmu {TYPE_2__* type; } ;
struct TYPE_6__ {size_t* type_host; } ;
struct TYPE_4__ {struct nvif_mmu mmu; } ;
struct nouveau_drm {TYPE_3__ ttm; TYPE_1__ client; } ;
struct nouveau_cli {int dummy; } ;
struct drm_file {struct nouveau_cli* driver_priv; } ;
struct drm_device {struct nouveau_drm* dev_private; } ;
struct TYPE_5__ {int type; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct drm_device*) ; 
 int NVIF_MEM_UNCACHED ; 
 int PTR_ERR (struct drm_device*) ; 
 int /*<<< orphan*/  drm_dev_put (struct drm_device*) ; 
 int drm_dev_register (struct drm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nouveau_drm_device_remove (struct drm_device*) ; 
 struct drm_device* nouveau_platform_device_create (struct nvkm_device_tegra_func const*,struct platform_device*,struct nvkm_device**) ; 
 struct nvkm_device_tegra_func* of_device_get_match_data (int /*<<< orphan*/ *) ; 
 struct drm_device* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static inline struct nouveau_cli *
nouveau_cli(struct drm_file *fpriv)
{
	return fpriv ? fpriv->driver_priv : NULL;
}

__attribute__((used)) static inline struct nouveau_drm *
nouveau_drm(struct drm_device *dev)
{
	return dev->dev_private;
}

__attribute__((used)) static inline bool
nouveau_drm_use_coherent_gpu_mapping(struct nouveau_drm *drm)
{
	struct nvif_mmu *mmu = &drm->client.mmu;
	return !(mmu->type[drm->ttm.type_host[0]].type & NVIF_MEM_UNCACHED);
}

__attribute__((used)) static int nouveau_platform_probe(struct platform_device *pdev)
{
	const struct nvkm_device_tegra_func *func;
	struct nvkm_device *device = NULL;
	struct drm_device *drm;
	int ret;

	func = of_device_get_match_data(&pdev->dev);

	drm = nouveau_platform_device_create(func, pdev, &device);
	if (IS_ERR(drm))
		return PTR_ERR(drm);

	ret = drm_dev_register(drm, 0);
	if (ret < 0) {
		drm_dev_put(drm);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int nouveau_platform_remove(struct platform_device *pdev)
{
	struct drm_device *dev = platform_get_drvdata(pdev);
	nouveau_drm_device_remove(dev);
	return 0;
}

