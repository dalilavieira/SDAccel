#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_11__ {void* y; void* x; } ;
struct TYPE_10__ {void* type; } ;
struct TYPE_12__ {TYPE_3__ pos; TYPE_2__ hdr; void* hot_y; void* hot_x; void* resource_id; } ;
struct virtio_gpu_output {TYPE_4__ cursor; int /*<<< orphan*/  index; } ;
struct ttm_buffer_object {int /*<<< orphan*/  resv; int /*<<< orphan*/  vma_node; } ;
struct TYPE_15__ {TYPE_6__* dev; } ;
struct virtio_gpu_object {int hw_res_handle; struct ttm_buffer_object tbo; scalar_t__ dumb; TYPE_7__ gem_base; } ;
struct TYPE_9__ {int /*<<< orphan*/ * obj; } ;
struct virtio_gpu_framebuffer {TYPE_1__ base; } ;
struct virtio_gpu_fence {int /*<<< orphan*/  f; } ;
struct virtio_gpu_device {struct drm_device* ddev; int /*<<< orphan*/  dev; } ;
struct drm_plane_state {TYPE_8__* fb; scalar_t__ crtc; } ;
struct drm_plane_helper_funcs {int dummy; } ;
struct drm_plane {TYPE_5__* state; struct drm_device* dev; } ;
struct drm_device {struct virtio_gpu_device* dev_private; } ;
typedef  enum drm_plane_type { ____Placeholder_drm_plane_type } drm_plane_type ;
struct TYPE_16__ {int hot_x; int hot_y; } ;
struct TYPE_14__ {struct virtio_gpu_device* dev_private; } ;
struct TYPE_13__ {int src_w; int src_h; int src_x; int src_y; int crtc_w; int crtc_h; int crtc_x; int crtc_y; TYPE_8__* fb; scalar_t__ crtc; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  DRM_DEBUG (char*,int,int,...) ; 
#define  DRM_FORMAT_ABGR8888 135 
#define  DRM_FORMAT_ARGB8888 134 
#define  DRM_FORMAT_BGRA8888 133 
#define  DRM_FORMAT_BGRX8888 132 
#define  DRM_FORMAT_RGBA8888 131 
#define  DRM_FORMAT_RGBX8888 130 
#define  DRM_FORMAT_XBGR8888 129 
#define  DRM_FORMAT_XRGB8888 128 
 int DRM_PLANE_TYPE_CURSOR ; 
 int ENOMEM ; 
 int ERESTARTSYS ; 
 struct drm_plane* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int VIRTIO_GPU_CMD_MOVE_CURSOR ; 
 int VIRTIO_GPU_CMD_UPDATE_CURSOR ; 
 int VIRTIO_GPU_FORMAT_A8B8G8R8_UNORM ; 
 int VIRTIO_GPU_FORMAT_A8R8G8B8_UNORM ; 
 int VIRTIO_GPU_FORMAT_B8G8R8A8_UNORM ; 
 int VIRTIO_GPU_FORMAT_B8G8R8X8_UNORM ; 
 int VIRTIO_GPU_FORMAT_R8G8B8A8_UNORM ; 
 int VIRTIO_GPU_FORMAT_R8G8B8X8_UNORM ; 
 int VIRTIO_GPU_FORMAT_X8B8G8R8_UNORM ; 
 int VIRTIO_GPU_FORMAT_X8R8G8B8_UNORM ; 
 scalar_t__ WARN_ON (int) ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct virtio_gpu_object*) ; 
 int /*<<< orphan*/  dma_fence_put (int /*<<< orphan*/ *) ; 
 struct virtio_gpu_output* drm_crtc_to_virtio_gpu_output (scalar_t__) ; 
 int /*<<< orphan*/  drm_plane_cleanup (struct drm_plane*) ; 
 int /*<<< orphan*/  drm_plane_helper_add (struct drm_plane*,struct drm_plane_helper_funcs const*) ; 
 int drm_universal_plane_init (struct drm_device*,struct drm_plane*,int,int /*<<< orphan*/ *,int const*,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 struct virtio_gpu_object* gem_to_virtio_gpu_obj (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct drm_plane*) ; 
 struct drm_plane* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reservation_object_add_excl_fence (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct virtio_gpu_framebuffer* to_virtio_gpu_framebuffer (TYPE_8__*) ; 
 int /*<<< orphan*/  ttm_bo_reference (struct ttm_buffer_object*) ; 
 int ttm_bo_reserve (struct ttm_buffer_object*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unref (struct ttm_buffer_object**) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (struct ttm_buffer_object*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  virtio_gpu_cmd_resource_flush (struct virtio_gpu_device*,int,int,int,int,int) ; 
 int /*<<< orphan*/  virtio_gpu_cmd_set_scanout (struct virtio_gpu_device*,int /*<<< orphan*/ ,int,int,int,int,int) ; 
 int /*<<< orphan*/  virtio_gpu_cmd_transfer_to_host_2d (struct virtio_gpu_device*,int,int /*<<< orphan*/ ,void*,void*,void*,void*,struct virtio_gpu_fence**) ; 
 int* virtio_gpu_cursor_formats ; 
 struct drm_plane_helper_funcs virtio_gpu_cursor_helper_funcs ; 
 int /*<<< orphan*/  virtio_gpu_cursor_ping (struct virtio_gpu_device*,struct virtio_gpu_output*) ; 
 int* virtio_gpu_formats ; 
 int /*<<< orphan*/  virtio_gpu_object_wait (struct virtio_gpu_object*,int) ; 
 int /*<<< orphan*/  virtio_gpu_plane_funcs ; 
 struct drm_plane_helper_funcs virtio_gpu_primary_helper_funcs ; 

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

uint32_t virtio_gpu_translate_format(uint32_t drm_fourcc)
{
	uint32_t format;

	switch (drm_fourcc) {
#ifdef __BIG_ENDIAN
	case DRM_FORMAT_XRGB8888:
		format = VIRTIO_GPU_FORMAT_X8R8G8B8_UNORM;
		break;
	case DRM_FORMAT_ARGB8888:
		format = VIRTIO_GPU_FORMAT_A8R8G8B8_UNORM;
		break;
	case DRM_FORMAT_BGRX8888:
		format = VIRTIO_GPU_FORMAT_B8G8R8X8_UNORM;
		break;
	case DRM_FORMAT_BGRA8888:
		format = VIRTIO_GPU_FORMAT_B8G8R8A8_UNORM;
		break;
	case DRM_FORMAT_RGBX8888:
		format = VIRTIO_GPU_FORMAT_R8G8B8X8_UNORM;
		break;
	case DRM_FORMAT_RGBA8888:
		format = VIRTIO_GPU_FORMAT_R8G8B8A8_UNORM;
		break;
	case DRM_FORMAT_XBGR8888:
		format = VIRTIO_GPU_FORMAT_X8B8G8R8_UNORM;
		break;
	case DRM_FORMAT_ABGR8888:
		format = VIRTIO_GPU_FORMAT_A8B8G8R8_UNORM;
		break;
#else
	case DRM_FORMAT_XRGB8888:
		format = VIRTIO_GPU_FORMAT_B8G8R8X8_UNORM;
		break;
	case DRM_FORMAT_ARGB8888:
		format = VIRTIO_GPU_FORMAT_B8G8R8A8_UNORM;
		break;
	case DRM_FORMAT_BGRX8888:
		format = VIRTIO_GPU_FORMAT_X8R8G8B8_UNORM;
		break;
	case DRM_FORMAT_BGRA8888:
		format = VIRTIO_GPU_FORMAT_A8R8G8B8_UNORM;
		break;
	case DRM_FORMAT_RGBX8888:
		format = VIRTIO_GPU_FORMAT_X8B8G8R8_UNORM;
		break;
	case DRM_FORMAT_RGBA8888:
		format = VIRTIO_GPU_FORMAT_A8B8G8R8_UNORM;
		break;
	case DRM_FORMAT_XBGR8888:
		format = VIRTIO_GPU_FORMAT_R8G8B8X8_UNORM;
		break;
	case DRM_FORMAT_ABGR8888:
		format = VIRTIO_GPU_FORMAT_R8G8B8A8_UNORM;
		break;
#endif
	default:
		/*
		 * This should not happen, we handle everything listed
		 * in virtio_gpu_formats[].
		 */
		format = 0;
		break;
	}
	WARN_ON(format == 0);
	return format;
}

__attribute__((used)) static void virtio_gpu_plane_destroy(struct drm_plane *plane)
{
	drm_plane_cleanup(plane);
	kfree(plane);
}

__attribute__((used)) static int virtio_gpu_plane_atomic_check(struct drm_plane *plane,
					 struct drm_plane_state *state)
{
	return 0;
}

__attribute__((used)) static void virtio_gpu_primary_plane_update(struct drm_plane *plane,
					    struct drm_plane_state *old_state)
{
	struct drm_device *dev = plane->dev;
	struct virtio_gpu_device *vgdev = dev->dev_private;
	struct virtio_gpu_output *output = NULL;
	struct virtio_gpu_framebuffer *vgfb;
	struct virtio_gpu_object *bo;
	uint32_t handle;

	if (plane->state->crtc)
		output = drm_crtc_to_virtio_gpu_output(plane->state->crtc);
	if (old_state->crtc)
		output = drm_crtc_to_virtio_gpu_output(old_state->crtc);
	if (WARN_ON(!output))
		return;

	if (plane->state->fb) {
		vgfb = to_virtio_gpu_framebuffer(plane->state->fb);
		bo = gem_to_virtio_gpu_obj(vgfb->base.obj[0]);
		handle = bo->hw_res_handle;
		if (bo->dumb) {
			virtio_gpu_cmd_transfer_to_host_2d
				(vgdev, handle, 0,
				 cpu_to_le32(plane->state->src_w >> 16),
				 cpu_to_le32(plane->state->src_h >> 16),
				 cpu_to_le32(plane->state->src_x >> 16),
				 cpu_to_le32(plane->state->src_y >> 16), NULL);
		}
	} else {
		handle = 0;
	}

	DRM_DEBUG("handle 0x%x, crtc %dx%d+%d+%d, src %dx%d+%d+%d\n", handle,
		  plane->state->crtc_w, plane->state->crtc_h,
		  plane->state->crtc_x, plane->state->crtc_y,
		  plane->state->src_w >> 16,
		  plane->state->src_h >> 16,
		  plane->state->src_x >> 16,
		  plane->state->src_y >> 16);
	virtio_gpu_cmd_set_scanout(vgdev, output->index, handle,
				   plane->state->src_w >> 16,
				   plane->state->src_h >> 16,
				   plane->state->src_x >> 16,
				   plane->state->src_y >> 16);
	virtio_gpu_cmd_resource_flush(vgdev, handle,
				      plane->state->src_x >> 16,
				      plane->state->src_y >> 16,
				      plane->state->src_w >> 16,
				      plane->state->src_h >> 16);
}

__attribute__((used)) static void virtio_gpu_cursor_plane_update(struct drm_plane *plane,
					   struct drm_plane_state *old_state)
{
	struct drm_device *dev = plane->dev;
	struct virtio_gpu_device *vgdev = dev->dev_private;
	struct virtio_gpu_output *output = NULL;
	struct virtio_gpu_framebuffer *vgfb;
	struct virtio_gpu_fence *fence = NULL;
	struct virtio_gpu_object *bo = NULL;
	uint32_t handle;
	int ret = 0;

	if (plane->state->crtc)
		output = drm_crtc_to_virtio_gpu_output(plane->state->crtc);
	if (old_state->crtc)
		output = drm_crtc_to_virtio_gpu_output(old_state->crtc);
	if (WARN_ON(!output))
		return;

	if (plane->state->fb) {
		vgfb = to_virtio_gpu_framebuffer(plane->state->fb);
		bo = gem_to_virtio_gpu_obj(vgfb->base.obj[0]);
		handle = bo->hw_res_handle;
	} else {
		handle = 0;
	}

	if (bo && bo->dumb && (plane->state->fb != old_state->fb)) {
		/* new cursor -- update & wait */
		virtio_gpu_cmd_transfer_to_host_2d
			(vgdev, handle, 0,
			 cpu_to_le32(plane->state->crtc_w),
			 cpu_to_le32(plane->state->crtc_h),
			 0, 0, &fence);
		ret = virtio_gpu_object_reserve(bo, false);
		if (!ret) {
			reservation_object_add_excl_fence(bo->tbo.resv,
							  &fence->f);
			dma_fence_put(&fence->f);
			fence = NULL;
			virtio_gpu_object_unreserve(bo);
			virtio_gpu_object_wait(bo, false);
		}
	}

	if (plane->state->fb != old_state->fb) {
		DRM_DEBUG("update, handle %d, pos +%d+%d, hot %d,%d\n", handle,
			  plane->state->crtc_x,
			  plane->state->crtc_y,
			  plane->state->fb ? plane->state->fb->hot_x : 0,
			  plane->state->fb ? plane->state->fb->hot_y : 0);
		output->cursor.hdr.type =
			cpu_to_le32(VIRTIO_GPU_CMD_UPDATE_CURSOR);
		output->cursor.resource_id = cpu_to_le32(handle);
		if (plane->state->fb) {
			output->cursor.hot_x =
				cpu_to_le32(plane->state->fb->hot_x);
			output->cursor.hot_y =
				cpu_to_le32(plane->state->fb->hot_y);
		} else {
			output->cursor.hot_x = cpu_to_le32(0);
			output->cursor.hot_y = cpu_to_le32(0);
		}
	} else {
		DRM_DEBUG("move +%d+%d\n",
			  plane->state->crtc_x,
			  plane->state->crtc_y);
		output->cursor.hdr.type =
			cpu_to_le32(VIRTIO_GPU_CMD_MOVE_CURSOR);
	}
	output->cursor.pos.x = cpu_to_le32(plane->state->crtc_x);
	output->cursor.pos.y = cpu_to_le32(plane->state->crtc_y);
	virtio_gpu_cursor_ping(vgdev, output);
}

struct drm_plane *virtio_gpu_plane_init(struct virtio_gpu_device *vgdev,
					enum drm_plane_type type,
					int index)
{
	struct drm_device *dev = vgdev->ddev;
	const struct drm_plane_helper_funcs *funcs;
	struct drm_plane *plane;
	const uint32_t *formats;
	int ret, nformats;

	plane = kzalloc(sizeof(*plane), GFP_KERNEL);
	if (!plane)
		return ERR_PTR(-ENOMEM);

	if (type == DRM_PLANE_TYPE_CURSOR) {
		formats = virtio_gpu_cursor_formats;
		nformats = ARRAY_SIZE(virtio_gpu_cursor_formats);
		funcs = &virtio_gpu_cursor_helper_funcs;
	} else {
		formats = virtio_gpu_formats;
		nformats = ARRAY_SIZE(virtio_gpu_formats);
		funcs = &virtio_gpu_primary_helper_funcs;
	}
	ret = drm_universal_plane_init(dev, plane, 1 << index,
				       &virtio_gpu_plane_funcs,
				       formats, nformats,
				       NULL, type, NULL);
	if (ret)
		goto err_plane_init;

	drm_plane_helper_add(plane, funcs);
	return plane;

err_plane_init:
	kfree(plane);
	return ERR_PTR(ret);
}

