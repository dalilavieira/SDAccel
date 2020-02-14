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
typedef  int u32 ;
struct drm_mode_map_dumb {int /*<<< orphan*/  offset; int /*<<< orphan*/  handle; } ;
struct drm_mode_destroy_dumb {int handle; } ;
struct drm_mode_create_dumb {int width; int height; int bpp; scalar_t__ size; scalar_t__ pitch; scalar_t__ handle; } ;
struct drm_file {int dummy; } ;
struct drm_device {TYPE_1__* driver; } ;
struct TYPE_2__ {int (* dumb_create ) (struct drm_file*,struct drm_device*,struct drm_mode_create_dumb*) ;int (* dumb_map_offset ) (struct drm_file*,struct drm_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;int (* dumb_destroy ) (struct drm_file*,struct drm_device*,int) ;} ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int EINVAL ; 
 int ENOSYS ; 
 scalar_t__ PAGE_ALIGN (int) ; 
 int U32_MAX ; 
 int drm_gem_dumb_destroy (struct drm_file*,struct drm_device*,int) ; 
 int drm_gem_dumb_map_offset (struct drm_file*,struct drm_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub1 (struct drm_file*,struct drm_device*,struct drm_mode_create_dumb*) ; 
 int stub2 (struct drm_file*,struct drm_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub3 (struct drm_file*,struct drm_device*,int) ; 

int drm_mode_create_dumb(struct drm_device *dev,
			 struct drm_mode_create_dumb *args,
			 struct drm_file *file_priv)
{
	u32 cpp, stride, size;

	if (!dev->driver->dumb_create)
		return -ENOSYS;
	if (!args->width || !args->height || !args->bpp)
		return -EINVAL;

	/* overflow checks for 32bit size calculations */
	if (args->bpp > U32_MAX - 8)
		return -EINVAL;
	cpp = DIV_ROUND_UP(args->bpp, 8);
	if (cpp > U32_MAX / args->width)
		return -EINVAL;
	stride = cpp * args->width;
	if (args->height > U32_MAX / stride)
		return -EINVAL;

	/* test for wrap-around */
	size = args->height * stride;
	if (PAGE_ALIGN(size) == 0)
		return -EINVAL;

	/*
	 * handle, pitch and size are output parameters. Zero them out to
	 * prevent drivers from accidentally using uninitialized data. Since
	 * not all existing userspace is clearing these fields properly we
	 * cannot reject IOCTL with garbage in them.
	 */
	args->handle = 0;
	args->pitch = 0;
	args->size = 0;

	return dev->driver->dumb_create(file_priv, dev, args);
}

int drm_mode_create_dumb_ioctl(struct drm_device *dev,
			       void *data, struct drm_file *file_priv)
{
	return drm_mode_create_dumb(dev, data, file_priv);
}

int drm_mode_mmap_dumb_ioctl(struct drm_device *dev,
			     void *data, struct drm_file *file_priv)
{
	struct drm_mode_map_dumb *args = data;

	if (!dev->driver->dumb_create)
		return -ENOSYS;

	if (dev->driver->dumb_map_offset)
		return dev->driver->dumb_map_offset(file_priv, dev,
						    args->handle,
						    &args->offset);
	else
		return drm_gem_dumb_map_offset(file_priv, dev, args->handle,
					       &args->offset);
}

int drm_mode_destroy_dumb(struct drm_device *dev, u32 handle,
			  struct drm_file *file_priv)
{
	if (!dev->driver->dumb_create)
		return -ENOSYS;

	if (dev->driver->dumb_destroy)
		return dev->driver->dumb_destroy(file_priv, dev, handle);
	else
		return drm_gem_dumb_destroy(file_priv, dev, handle);
}

int drm_mode_destroy_dumb_ioctl(struct drm_device *dev,
				void *data, struct drm_file *file_priv)
{
	struct drm_mode_destroy_dumb *args = data;

	return drm_mode_destroy_dumb(dev, args->handle, file_priv);
}

