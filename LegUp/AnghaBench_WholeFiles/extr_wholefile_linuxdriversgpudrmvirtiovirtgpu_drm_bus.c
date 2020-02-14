#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  unique ;
typedef  int /*<<< orphan*/  u64 ;
struct ttm_buffer_object {int /*<<< orphan*/  vma_node; } ;
struct TYPE_9__ {TYPE_1__* dev; } ;
struct virtio_gpu_object {struct ttm_buffer_object tbo; TYPE_2__ gem_base; } ;
struct virtio_gpu_device {int /*<<< orphan*/  dev; } ;
struct TYPE_14__ {TYPE_6__* parent; } ;
struct virtio_device {TYPE_7__ dev; struct drm_device* priv; } ;
struct pci_dev {int class; int /*<<< orphan*/  dev; TYPE_4__* resource; } ;
struct drm_driver {int dummy; } ;
struct drm_device {struct pci_dev* pdev; } ;
struct apertures_struct {TYPE_3__* ranges; } ;
struct TYPE_13__ {TYPE_5__* bus; } ;
struct TYPE_12__ {int /*<<< orphan*/  name; } ;
struct TYPE_11__ {int flags; } ;
struct TYPE_10__ {int /*<<< orphan*/  size; int /*<<< orphan*/  base; } ;
struct TYPE_8__ {struct virtio_gpu_device* dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_INFO (char*,char*,char const*) ; 
 int ERESTARTSYS ; 
 int IORESOURCE_ROM_SHADOW ; 
 scalar_t__ IS_ERR (struct drm_device*) ; 
 int PCI_CLASS_DISPLAY_VGA ; 
 size_t PCI_ROM_RESOURCE ; 
 int PTR_ERR (struct drm_device*) ; 
 struct apertures_struct* alloc_apertures (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct virtio_gpu_object*) ; 
 char* dev_name (int /*<<< orphan*/ *) ; 
 struct drm_device* drm_dev_alloc (struct drm_driver*,TYPE_7__*) ; 
 int drm_dev_register (struct drm_device*,int /*<<< orphan*/ ) ; 
 int drm_dev_set_unique (struct drm_device*,char*) ; 
 int /*<<< orphan*/  drm_dev_unref (struct drm_device*) ; 
 int /*<<< orphan*/  drm_fb_helper_remove_conflicting_framebuffers (struct apertures_struct*,char*,int) ; 
 int /*<<< orphan*/  drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct apertures_struct*) ; 
 int /*<<< orphan*/  pci_resource_len (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 struct pci_dev* to_pci_dev (TYPE_6__*) ; 
 int /*<<< orphan*/  ttm_bo_reference (struct ttm_buffer_object*) ; 
 int ttm_bo_reserve (struct ttm_buffer_object*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unref (struct ttm_buffer_object**) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (struct ttm_buffer_object*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline struct virtio_gpu_object*
virtio_gpu_object_ref(struct virtio_gpu_object *bo)
{
	ttm_bo_reference(&bo->tbo);
	return bo;
}

__attribute__((used)) static inline void virtio_gpu_object_unref(struct virtio_gpu_object **bo)
{
	struct ttm_buffer_object *tbo;

	if ((*bo) == NULL)
		return;
	tbo = &((*bo)->tbo);
	ttm_bo_unref(&tbo);
	if (tbo == NULL)
		*bo = NULL;
}

__attribute__((used)) static inline u64 virtio_gpu_object_mmap_offset(struct virtio_gpu_object *bo)
{
	return drm_vma_node_offset_addr(&bo->tbo.vma_node);
}

__attribute__((used)) static inline int virtio_gpu_object_reserve(struct virtio_gpu_object *bo,
					 bool no_wait)
{
	int r;

	r = ttm_bo_reserve(&bo->tbo, true, no_wait, NULL);
	if (unlikely(r != 0)) {
		if (r != -ERESTARTSYS) {
			struct virtio_gpu_device *qdev =
				bo->gem_base.dev->dev_private;
			dev_err(qdev->dev, "%p reserve failed\n", bo);
		}
		return r;
	}
	return 0;
}

__attribute__((used)) static inline void virtio_gpu_object_unreserve(struct virtio_gpu_object *bo)
{
	ttm_bo_unreserve(&bo->tbo);
}

__attribute__((used)) static void virtio_pci_kick_out_firmware_fb(struct pci_dev *pci_dev)
{
	struct apertures_struct *ap;
	bool primary;

	ap = alloc_apertures(1);
	if (!ap)
		return;

	ap->ranges[0].base = pci_resource_start(pci_dev, 0);
	ap->ranges[0].size = pci_resource_len(pci_dev, 0);

	primary = pci_dev->resource[PCI_ROM_RESOURCE].flags
		& IORESOURCE_ROM_SHADOW;

	drm_fb_helper_remove_conflicting_framebuffers(ap, "virtiodrmfb", primary);

	kfree(ap);
}

int drm_virtio_init(struct drm_driver *driver, struct virtio_device *vdev)
{
	struct drm_device *dev;
	int ret;

	dev = drm_dev_alloc(driver, &vdev->dev);
	if (IS_ERR(dev))
		return PTR_ERR(dev);
	vdev->priv = dev;

	if (strcmp(vdev->dev.parent->bus->name, "pci") == 0) {
		struct pci_dev *pdev = to_pci_dev(vdev->dev.parent);
		const char *pname = dev_name(&pdev->dev);
		bool vga = (pdev->class >> 8) == PCI_CLASS_DISPLAY_VGA;
		char unique[20];

		DRM_INFO("pci: %s detected at %s\n",
			 vga ? "virtio-vga" : "virtio-gpu-pci",
			 pname);
		dev->pdev = pdev;
		if (vga)
			virtio_pci_kick_out_firmware_fb(pdev);

		snprintf(unique, sizeof(unique), "pci:%s", pname);
		ret = drm_dev_set_unique(dev, unique);
		if (ret)
			goto err_free;

	}

	ret = drm_dev_register(dev, 0);
	if (ret)
		goto err_free;

	return 0;

err_free:
	drm_dev_unref(dev);
	return ret;
}

