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
struct vfio_platform_device {int (* get_irq ) (struct vfio_platform_device*,int) ;int reset_required; struct vfio_platform_device* name; int /*<<< orphan*/  parent_module; struct resource* (* get_resource ) (struct vfio_platform_device*,int) ;int /*<<< orphan*/  flags; void* opaque; } ;
struct resource {int dummy; } ;
struct amba_id {int dummy; } ;
struct amba_device {int* irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  periphid; struct resource res; } ;

/* Variables and functions */
 int AMBA_NR_IRQS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  VFIO_DEVICE_FLAGS_AMBA ; 
 struct vfio_platform_device* kasprintf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct vfio_platform_device*) ; 
 struct vfio_platform_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int vfio_platform_probe_common (struct vfio_platform_device*,int /*<<< orphan*/ *) ; 
 struct vfio_platform_device* vfio_platform_remove_common (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct resource *get_amba_resource(struct vfio_platform_device *vdev,
					  int i)
{
	struct amba_device *adev = (struct amba_device *) vdev->opaque;

	if (i == 0)
		return &adev->res;

	return NULL;
}

__attribute__((used)) static int get_amba_irq(struct vfio_platform_device *vdev, int i)
{
	struct amba_device *adev = (struct amba_device *) vdev->opaque;
	int ret = 0;

	if (i < AMBA_NR_IRQS)
		ret = adev->irq[i];

	/* zero is an unset IRQ for AMBA devices */
	return ret ? ret : -ENXIO;
}

__attribute__((used)) static int vfio_amba_probe(struct amba_device *adev, const struct amba_id *id)
{
	struct vfio_platform_device *vdev;
	int ret;

	vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
	if (!vdev)
		return -ENOMEM;

	vdev->name = kasprintf(GFP_KERNEL, "vfio-amba-%08x", adev->periphid);
	if (!vdev->name) {
		kfree(vdev);
		return -ENOMEM;
	}

	vdev->opaque = (void *) adev;
	vdev->flags = VFIO_DEVICE_FLAGS_AMBA;
	vdev->get_resource = get_amba_resource;
	vdev->get_irq = get_amba_irq;
	vdev->parent_module = THIS_MODULE;
	vdev->reset_required = false;

	ret = vfio_platform_probe_common(vdev, &adev->dev);
	if (ret) {
		kfree(vdev->name);
		kfree(vdev);
	}

	return ret;
}

__attribute__((used)) static int vfio_amba_remove(struct amba_device *adev)
{
	struct vfio_platform_device *vdev;

	vdev = vfio_platform_remove_common(&adev->dev);
	if (vdev) {
		kfree(vdev->name);
		kfree(vdev);
		return 0;
	}

	return -EINVAL;
}

