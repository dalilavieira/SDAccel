#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct resource {int /*<<< orphan*/  end; struct resource* sibling; } ;
struct drm_local_map {scalar_t__ type; unsigned long offset; unsigned long size; void* handle; } ;
struct drm_device {TYPE_1__* agp; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
struct TYPE_4__ {struct resource* child; } ;
struct TYPE_3__ {scalar_t__ cant_use_aperture; } ;

/* Variables and functions */
 scalar_t__ _DRM_AGP ; 
 TYPE_2__ iomem_resource ; 
 void* ioremap (unsigned long,unsigned long) ; 
 void* ioremap_wc (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  iounmap (void*) ; 
 int /*<<< orphan*/  max (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vunmap (void*) ; 

__attribute__((used)) static inline void drm_legacy_vma_flush(struct drm_device *d)
{
	/* do nothing */
}

__attribute__((used)) static inline void *agp_remap(unsigned long offset, unsigned long size,
			      struct drm_device * dev)
{
	return NULL;
}

void drm_legacy_ioremap(struct drm_local_map *map, struct drm_device *dev)
{
	if (dev->agp && dev->agp->cant_use_aperture && map->type == _DRM_AGP)
		map->handle = agp_remap(map->offset, map->size, dev);
	else
		map->handle = ioremap(map->offset, map->size);
}

void drm_legacy_ioremap_wc(struct drm_local_map *map, struct drm_device *dev)
{
	if (dev->agp && dev->agp->cant_use_aperture && map->type == _DRM_AGP)
		map->handle = agp_remap(map->offset, map->size, dev);
	else
		map->handle = ioremap_wc(map->offset, map->size);
}

void drm_legacy_ioremapfree(struct drm_local_map *map, struct drm_device *dev)
{
	if (!map->handle || !map->size)
		return;

	if (dev->agp && dev->agp->cant_use_aperture && map->type == _DRM_AGP)
		vunmap(map->handle);
	else
		iounmap(map->handle);
}

u64 drm_get_max_iomem(void)
{
	struct resource *tmp;
	resource_size_t max_iomem = 0;

	for (tmp = iomem_resource.child; tmp; tmp = tmp->sibling) {
		max_iomem = max(max_iomem,  tmp->end);
	}

	return max_iomem;
}

