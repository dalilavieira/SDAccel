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
struct vfio_platform_device {int (* get_irq ) (struct vfio_platform_device*,int) ;int /*<<< orphan*/  reset_required; int /*<<< orphan*/  parent_module; struct resource* (* get_resource ) (struct vfio_platform_device*,int) ;int /*<<< orphan*/  flags; int /*<<< orphan*/  name; void* opaque; } ;
struct resource {int dummy; } ;
struct platform_device {int num_resources; int /*<<< orphan*/  dev; int /*<<< orphan*/  name; struct resource* resource; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IORESOURCE_IO ; 
 int IORESOURCE_MEM ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  VFIO_DEVICE_FLAGS_PLATFORM ; 
 int /*<<< orphan*/  kfree (struct vfio_platform_device*) ; 
 struct vfio_platform_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int platform_get_irq (struct platform_device*,int) ; 
 int /*<<< orphan*/  reset_required ; 
 int resource_type (struct resource*) ; 
 int vfio_platform_probe_common (struct vfio_platform_device*,int /*<<< orphan*/ *) ; 
 struct vfio_platform_device* vfio_platform_remove_common (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct resource *get_platform_resource(struct vfio_platform_device *vdev,
					      int num)
{
	struct platform_device *dev = (struct platform_device *) vdev->opaque;
	int i;

	for (i = 0; i < dev->num_resources; i++) {
		struct resource *r = &dev->resource[i];

		if (resource_type(r) & (IORESOURCE_MEM|IORESOURCE_IO)) {
			if (!num)
				return r;

			num--;
		}
	}
	return NULL;
}

__attribute__((used)) static int get_platform_irq(struct vfio_platform_device *vdev, int i)
{
	struct platform_device *pdev = (struct platform_device *) vdev->opaque;

	return platform_get_irq(pdev, i);
}

__attribute__((used)) static int vfio_platform_probe(struct platform_device *pdev)
{
	struct vfio_platform_device *vdev;
	int ret;

	vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
	if (!vdev)
		return -ENOMEM;

	vdev->opaque = (void *) pdev;
	vdev->name = pdev->name;
	vdev->flags = VFIO_DEVICE_FLAGS_PLATFORM;
	vdev->get_resource = get_platform_resource;
	vdev->get_irq = get_platform_irq;
	vdev->parent_module = THIS_MODULE;
	vdev->reset_required = reset_required;

	ret = vfio_platform_probe_common(vdev, &pdev->dev);
	if (ret)
		kfree(vdev);

	return ret;
}

__attribute__((used)) static int vfio_platform_remove(struct platform_device *pdev)
{
	struct vfio_platform_device *vdev;

	vdev = vfio_platform_remove_common(&pdev->dev);
	if (vdev) {
		kfree(vdev);
		return 0;
	}

	return -EINVAL;
}

