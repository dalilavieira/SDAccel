#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_7__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct drm_file {int dummy; } ;
struct drm_device {TYPE_1__* dev_private; int /*<<< orphan*/  pdev; } ;
typedef  int /*<<< orphan*/  drm_via_sarea_t ;
struct TYPE_8__ {unsigned long chipset; int /*<<< orphan*/  object_idr; int /*<<< orphan*/  agpAddr; TYPE_7__* sarea; int /*<<< orphan*/ * sarea_priv; void* mmio; void* fb; } ;
typedef  TYPE_1__ drm_via_private_t ;
struct TYPE_9__ {int sarea_priv_offset; int func; int /*<<< orphan*/  agpAddr; int /*<<< orphan*/  mmio_offset; int /*<<< orphan*/  fb_offset; } ;
typedef  TYPE_2__ drm_via_init_t ;
struct TYPE_10__ {scalar_t__ handle; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  VIA_CLEANUP_MAP 129 
#define  VIA_INIT_MAP 128 
 void* drm_legacy_findmap (struct drm_device*,int /*<<< orphan*/ ) ; 
 TYPE_7__* drm_legacy_getsarea (struct drm_device*) ; 
 int drm_vblank_init (struct drm_device*,int) ; 
 int /*<<< orphan*/  idr_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  idr_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 TYPE_1__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_master (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  via_dma_cleanup (struct drm_device*) ; 
 int via_do_cleanup_map (struct drm_device*) ; 
 int /*<<< orphan*/  via_init_dmablit (struct drm_device*) ; 
 int /*<<< orphan*/  via_init_futex (TYPE_1__*) ; 

__attribute__((used)) static int via_do_init_map(struct drm_device *dev, drm_via_init_t *init)
{
	drm_via_private_t *dev_priv = dev->dev_private;

	DRM_DEBUG("\n");

	dev_priv->sarea = drm_legacy_getsarea(dev);
	if (!dev_priv->sarea) {
		DRM_ERROR("could not find sarea!\n");
		dev->dev_private = (void *)dev_priv;
		via_do_cleanup_map(dev);
		return -EINVAL;
	}

	dev_priv->fb = drm_legacy_findmap(dev, init->fb_offset);
	if (!dev_priv->fb) {
		DRM_ERROR("could not find framebuffer!\n");
		dev->dev_private = (void *)dev_priv;
		via_do_cleanup_map(dev);
		return -EINVAL;
	}
	dev_priv->mmio = drm_legacy_findmap(dev, init->mmio_offset);
	if (!dev_priv->mmio) {
		DRM_ERROR("could not find mmio region!\n");
		dev->dev_private = (void *)dev_priv;
		via_do_cleanup_map(dev);
		return -EINVAL;
	}

	dev_priv->sarea_priv =
	    (drm_via_sarea_t *) ((u8 *) dev_priv->sarea->handle +
				 init->sarea_priv_offset);

	dev_priv->agpAddr = init->agpAddr;

	via_init_futex(dev_priv);

	via_init_dmablit(dev);

	dev->dev_private = (void *)dev_priv;
	return 0;
}

int via_do_cleanup_map(struct drm_device *dev)
{
	via_dma_cleanup(dev);

	return 0;
}

int via_map_init(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
	drm_via_init_t *init = data;

	DRM_DEBUG("\n");

	switch (init->func) {
	case VIA_INIT_MAP:
		return via_do_init_map(dev, init);
	case VIA_CLEANUP_MAP:
		return via_do_cleanup_map(dev);
	}

	return -EINVAL;
}

int via_driver_load(struct drm_device *dev, unsigned long chipset)
{
	drm_via_private_t *dev_priv;
	int ret = 0;

	dev_priv = kzalloc(sizeof(drm_via_private_t), GFP_KERNEL);
	if (dev_priv == NULL)
		return -ENOMEM;

	idr_init(&dev_priv->object_idr);
	dev->dev_private = (void *)dev_priv;

	dev_priv->chipset = chipset;

	pci_set_master(dev->pdev);

	ret = drm_vblank_init(dev, 1);
	if (ret) {
		kfree(dev_priv);
		return ret;
	}

	return 0;
}

void via_driver_unload(struct drm_device *dev)
{
	drm_via_private_t *dev_priv = dev->dev_private;

	idr_destroy(&dev_priv->object_idr);

	kfree(dev_priv);
}

