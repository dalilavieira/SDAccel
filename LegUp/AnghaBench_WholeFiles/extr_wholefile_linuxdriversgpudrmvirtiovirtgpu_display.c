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
typedef  int /*<<< orphan*/  u64 ;
struct drm_framebuffer {struct drm_gem_object** obj; } ;
struct TYPE_10__ {void* height; void* width; } ;
struct TYPE_11__ {TYPE_3__ r; void* enabled; } ;
struct TYPE_8__ {int /*<<< orphan*/  vdisplay; int /*<<< orphan*/  hdisplay; } ;
struct drm_crtc {struct drm_device* dev; TYPE_2__* state; TYPE_1__ mode; } ;
struct drm_encoder {int possible_crtcs; } ;
struct drm_connector {int /*<<< orphan*/  dev; } ;
struct virtio_gpu_output {int index; struct drm_framebuffer base; TYPE_4__ info; struct drm_crtc crtc; struct drm_encoder enc; struct drm_connector conn; scalar_t__ y2; scalar_t__ x2; int /*<<< orphan*/  y1; int /*<<< orphan*/  x1; int /*<<< orphan*/  dirty_lock; } ;
struct ttm_buffer_object {int /*<<< orphan*/  vma_node; } ;
struct TYPE_14__ {TYPE_6__* dev; } ;
struct virtio_gpu_object {struct ttm_buffer_object tbo; TYPE_7__ gem_base; } ;
struct virtio_gpu_framebuffer {int index; struct drm_framebuffer base; TYPE_4__ info; struct drm_crtc crtc; struct drm_encoder enc; struct drm_connector conn; scalar_t__ y2; scalar_t__ x2; int /*<<< orphan*/  y1; int /*<<< orphan*/  x1; int /*<<< orphan*/  dirty_lock; } ;
struct virtio_gpu_device {int num_scanouts; struct drm_device* ddev; struct virtio_gpu_output* outputs; int /*<<< orphan*/  dev; } ;
struct drm_plane {int dummy; } ;
struct drm_mode_fb_cmd2 {int /*<<< orphan*/ * handles; } ;
struct drm_gem_object {int dummy; } ;
struct drm_file {int dummy; } ;
struct drm_display_mode {int type; int hdisplay; int vdisplay; } ;
struct TYPE_12__ {int /*<<< orphan*/  max_height; int /*<<< orphan*/  max_width; int /*<<< orphan*/  min_height; int /*<<< orphan*/  min_width; int /*<<< orphan*/ * helper_private; int /*<<< orphan*/ * funcs; } ;
struct drm_device {TYPE_5__ mode_config; int /*<<< orphan*/  event_lock; struct virtio_gpu_device* dev_private; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_clip_rect {int dummy; } ;
struct drm_atomic_state {struct drm_device* dev; } ;
typedef  enum drm_mode_status { ____Placeholder_drm_mode_status } drm_mode_status ;
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
struct TYPE_13__ {struct virtio_gpu_device* dev_private; } ;
struct TYPE_9__ {int /*<<< orphan*/ * event; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*,int,int) ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_VIRTUAL ; 
 int /*<<< orphan*/  DRM_MODE_ENCODER_VIRTUAL ; 
 int DRM_MODE_TYPE_PREFERRED ; 
 int /*<<< orphan*/  DRM_PLANE_TYPE_CURSOR ; 
 int /*<<< orphan*/  DRM_PLANE_TYPE_PRIMARY ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int ERESTARTSYS ; 
 struct drm_framebuffer* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INT_MAX ; 
 scalar_t__ IS_ERR (struct drm_plane*) ; 
 int MODE_BAD ; 
 int MODE_OK ; 
 int PTR_ERR (struct drm_plane*) ; 
 int XRES_DEF ; 
 int /*<<< orphan*/  XRES_MAX ; 
 int /*<<< orphan*/  XRES_MIN ; 
 int YRES_DEF ; 
 int /*<<< orphan*/  YRES_MAX ; 
 int /*<<< orphan*/  YRES_MIN ; 
 int connector_status_connected ; 
 int connector_status_disconnected ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,struct virtio_gpu_object*) ; 
 int drm_add_modes_noedid (struct drm_connector*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_atomic_helper_cleanup_planes (struct drm_device*,struct drm_atomic_state*) ; 
 int /*<<< orphan*/  drm_atomic_helper_commit_hw_done (struct drm_atomic_state*) ; 
 int /*<<< orphan*/  drm_atomic_helper_commit_modeset_disables (struct drm_device*,struct drm_atomic_state*) ; 
 int /*<<< orphan*/  drm_atomic_helper_commit_modeset_enables (struct drm_device*,struct drm_atomic_state*) ; 
 int /*<<< orphan*/  drm_atomic_helper_commit_planes (struct drm_device*,struct drm_atomic_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_atomic_helper_wait_for_vblanks (struct drm_device*,struct drm_atomic_state*) ; 
 int /*<<< orphan*/  drm_connector_attach_encoder (struct drm_connector*,struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_connector_cleanup (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_connector_helper_add (struct drm_connector*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_connector_init (struct drm_device*,struct drm_connector*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_connector_register (struct drm_connector*) ; 
 struct virtio_gpu_output* drm_connector_to_virtio_gpu_output (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_connector_unregister (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_crtc_helper_add (struct drm_crtc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_crtc_init_with_planes (struct drm_device*,struct drm_crtc*,struct drm_plane*,struct drm_plane*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_crtc_send_vblank_event (struct drm_crtc*,int /*<<< orphan*/ *) ; 
 struct virtio_gpu_output* drm_crtc_to_virtio_gpu_output (struct drm_crtc*) ; 
 struct drm_display_mode* drm_cvt_mode (int /*<<< orphan*/ ,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  drm_encoder_helper_add (struct drm_encoder*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_encoder_init (struct drm_device*,struct drm_encoder*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int drm_framebuffer_init (struct drm_device*,struct drm_framebuffer*,int /*<<< orphan*/ *) ; 
 struct drm_gem_object* drm_gem_object_lookup (struct drm_file*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_gem_object_put_unlocked (struct drm_gem_object*) ; 
 int /*<<< orphan*/  drm_helper_mode_fill_fb_struct (struct drm_device*,struct drm_framebuffer*,struct drm_mode_fb_cmd2 const*) ; 
 int /*<<< orphan*/  drm_mode_config_cleanup (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_init (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_reset (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_probed_add (struct drm_connector*,struct drm_display_mode*) ; 
 int /*<<< orphan*/  drm_set_preferred_mode (struct drm_connector*,int,int) ; 
 int /*<<< orphan*/  drm_vma_node_offset_addr (int /*<<< orphan*/ *) ; 
 struct virtio_gpu_object* gem_to_virtio_gpu_obj (struct drm_gem_object*) ; 
 int /*<<< orphan*/  kfree (struct virtio_gpu_output*) ; 
 struct virtio_gpu_output* kzalloc (int,int /*<<< orphan*/ ) ; 
 int le32_to_cpu (void*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct virtio_gpu_output* to_virtio_gpu_framebuffer (struct drm_framebuffer*) ; 
 int /*<<< orphan*/  ttm_bo_reference (struct ttm_buffer_object*) ; 
 int ttm_bo_reserve (struct ttm_buffer_object*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_unref (struct ttm_buffer_object**) ; 
 int /*<<< orphan*/  ttm_bo_unreserve (struct ttm_buffer_object*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  virtio_gpu_cmd_set_scanout (struct virtio_gpu_device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virtio_gpu_conn_helper_funcs ; 
 int /*<<< orphan*/  virtio_gpu_connector_funcs ; 
 int /*<<< orphan*/  virtio_gpu_crtc_funcs ; 
 int /*<<< orphan*/  virtio_gpu_crtc_helper_funcs ; 
 int /*<<< orphan*/  virtio_gpu_enc_funcs ; 
 int /*<<< orphan*/  virtio_gpu_enc_helper_funcs ; 
 int /*<<< orphan*/  virtio_gpu_fb_funcs ; 
 int /*<<< orphan*/  virtio_gpu_fbdev_fini (struct virtio_gpu_device*) ; 
 int /*<<< orphan*/  virtio_gpu_mode_funcs ; 
 struct drm_plane* virtio_gpu_plane_init (struct virtio_gpu_device*,int /*<<< orphan*/ ,int) ; 
 int virtio_gpu_surface_dirty (struct virtio_gpu_output*,struct drm_clip_rect*,unsigned int) ; 
 int /*<<< orphan*/  virtio_mode_config_helpers ; 

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

__attribute__((used)) static int
virtio_gpu_framebuffer_surface_dirty(struct drm_framebuffer *fb,
				     struct drm_file *file_priv,
				     unsigned int flags, unsigned int color,
				     struct drm_clip_rect *clips,
				     unsigned int num_clips)
{
	struct virtio_gpu_framebuffer *virtio_gpu_fb
		= to_virtio_gpu_framebuffer(fb);

	return virtio_gpu_surface_dirty(virtio_gpu_fb, clips, num_clips);
}

int
virtio_gpu_framebuffer_init(struct drm_device *dev,
			    struct virtio_gpu_framebuffer *vgfb,
			    const struct drm_mode_fb_cmd2 *mode_cmd,
			    struct drm_gem_object *obj)
{
	int ret;
	struct virtio_gpu_object *bo;

	vgfb->base.obj[0] = obj;

	bo = gem_to_virtio_gpu_obj(obj);

	drm_helper_mode_fill_fb_struct(dev, &vgfb->base, mode_cmd);

	ret = drm_framebuffer_init(dev, &vgfb->base, &virtio_gpu_fb_funcs);
	if (ret) {
		vgfb->base.obj[0] = NULL;
		return ret;
	}

	spin_lock_init(&vgfb->dirty_lock);
	vgfb->x1 = vgfb->y1 = INT_MAX;
	vgfb->x2 = vgfb->y2 = 0;
	return 0;
}

__attribute__((used)) static void virtio_gpu_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
	struct drm_device *dev = crtc->dev;
	struct virtio_gpu_device *vgdev = dev->dev_private;
	struct virtio_gpu_output *output = drm_crtc_to_virtio_gpu_output(crtc);

	virtio_gpu_cmd_set_scanout(vgdev, output->index, 0,
				   crtc->mode.hdisplay,
				   crtc->mode.vdisplay, 0, 0);
}

__attribute__((used)) static void virtio_gpu_crtc_atomic_enable(struct drm_crtc *crtc,
					  struct drm_crtc_state *old_state)
{
}

__attribute__((used)) static void virtio_gpu_crtc_atomic_disable(struct drm_crtc *crtc,
					   struct drm_crtc_state *old_state)
{
	struct drm_device *dev = crtc->dev;
	struct virtio_gpu_device *vgdev = dev->dev_private;
	struct virtio_gpu_output *output = drm_crtc_to_virtio_gpu_output(crtc);

	virtio_gpu_cmd_set_scanout(vgdev, output->index, 0, 0, 0, 0, 0);
}

__attribute__((used)) static int virtio_gpu_crtc_atomic_check(struct drm_crtc *crtc,
					struct drm_crtc_state *state)
{
	return 0;
}

__attribute__((used)) static void virtio_gpu_crtc_atomic_flush(struct drm_crtc *crtc,
					 struct drm_crtc_state *old_state)
{
	unsigned long flags;

	spin_lock_irqsave(&crtc->dev->event_lock, flags);
	if (crtc->state->event)
		drm_crtc_send_vblank_event(crtc, crtc->state->event);
	crtc->state->event = NULL;
	spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
}

__attribute__((used)) static void virtio_gpu_enc_mode_set(struct drm_encoder *encoder,
				    struct drm_display_mode *mode,
				    struct drm_display_mode *adjusted_mode)
{
}

__attribute__((used)) static void virtio_gpu_enc_enable(struct drm_encoder *encoder)
{
}

__attribute__((used)) static void virtio_gpu_enc_disable(struct drm_encoder *encoder)
{
}

__attribute__((used)) static int virtio_gpu_conn_get_modes(struct drm_connector *connector)
{
	struct virtio_gpu_output *output =
		drm_connector_to_virtio_gpu_output(connector);
	struct drm_display_mode *mode = NULL;
	int count, width, height;

	width  = le32_to_cpu(output->info.r.width);
	height = le32_to_cpu(output->info.r.height);
	count = drm_add_modes_noedid(connector, XRES_MAX, YRES_MAX);

	if (width == 0 || height == 0) {
		width = XRES_DEF;
		height = YRES_DEF;
		drm_set_preferred_mode(connector, XRES_DEF, YRES_DEF);
	} else {
		DRM_DEBUG("add mode: %dx%d\n", width, height);
		mode = drm_cvt_mode(connector->dev, width, height, 60,
				    false, false, false);
		mode->type |= DRM_MODE_TYPE_PREFERRED;
		drm_mode_probed_add(connector, mode);
		count++;
	}

	return count;
}

__attribute__((used)) static enum drm_mode_status virtio_gpu_conn_mode_valid(struct drm_connector *connector,
				      struct drm_display_mode *mode)
{
	struct virtio_gpu_output *output =
		drm_connector_to_virtio_gpu_output(connector);
	int width, height;

	width  = le32_to_cpu(output->info.r.width);
	height = le32_to_cpu(output->info.r.height);

	if (!(mode->type & DRM_MODE_TYPE_PREFERRED))
		return MODE_OK;
	if (mode->hdisplay == XRES_DEF && mode->vdisplay == YRES_DEF)
		return MODE_OK;
	if (mode->hdisplay <= width  && mode->hdisplay >= width - 16 &&
	    mode->vdisplay <= height && mode->vdisplay >= height - 16)
		return MODE_OK;

	DRM_DEBUG("del mode: %dx%d\n", mode->hdisplay, mode->vdisplay);
	return MODE_BAD;
}

__attribute__((used)) static enum drm_connector_status virtio_gpu_conn_detect(
			struct drm_connector *connector,
			bool force)
{
	struct virtio_gpu_output *output =
		drm_connector_to_virtio_gpu_output(connector);

	if (output->info.enabled)
		return connector_status_connected;
	else
		return connector_status_disconnected;
}

__attribute__((used)) static void virtio_gpu_conn_destroy(struct drm_connector *connector)
{
	struct virtio_gpu_output *virtio_gpu_output =
		drm_connector_to_virtio_gpu_output(connector);

	drm_connector_unregister(connector);
	drm_connector_cleanup(connector);
	kfree(virtio_gpu_output);
}

__attribute__((used)) static int vgdev_output_init(struct virtio_gpu_device *vgdev, int index)
{
	struct drm_device *dev = vgdev->ddev;
	struct virtio_gpu_output *output = vgdev->outputs + index;
	struct drm_connector *connector = &output->conn;
	struct drm_encoder *encoder = &output->enc;
	struct drm_crtc *crtc = &output->crtc;
	struct drm_plane *primary, *cursor;

	output->index = index;
	if (index == 0) {
		output->info.enabled = cpu_to_le32(true);
		output->info.r.width = cpu_to_le32(XRES_DEF);
		output->info.r.height = cpu_to_le32(YRES_DEF);
	}

	primary = virtio_gpu_plane_init(vgdev, DRM_PLANE_TYPE_PRIMARY, index);
	if (IS_ERR(primary))
		return PTR_ERR(primary);
	cursor = virtio_gpu_plane_init(vgdev, DRM_PLANE_TYPE_CURSOR, index);
	if (IS_ERR(cursor))
		return PTR_ERR(cursor);
	drm_crtc_init_with_planes(dev, crtc, primary, cursor,
				  &virtio_gpu_crtc_funcs, NULL);
	drm_crtc_helper_add(crtc, &virtio_gpu_crtc_helper_funcs);

	drm_connector_init(dev, connector, &virtio_gpu_connector_funcs,
			   DRM_MODE_CONNECTOR_VIRTUAL);
	drm_connector_helper_add(connector, &virtio_gpu_conn_helper_funcs);

	drm_encoder_init(dev, encoder, &virtio_gpu_enc_funcs,
			 DRM_MODE_ENCODER_VIRTUAL, NULL);
	drm_encoder_helper_add(encoder, &virtio_gpu_enc_helper_funcs);
	encoder->possible_crtcs = 1 << index;

	drm_connector_attach_encoder(connector, encoder);
	drm_connector_register(connector);
	return 0;
}

__attribute__((used)) static struct drm_framebuffer *
virtio_gpu_user_framebuffer_create(struct drm_device *dev,
				   struct drm_file *file_priv,
				   const struct drm_mode_fb_cmd2 *mode_cmd)
{
	struct drm_gem_object *obj = NULL;
	struct virtio_gpu_framebuffer *virtio_gpu_fb;
	int ret;

	/* lookup object associated with res handle */
	obj = drm_gem_object_lookup(file_priv, mode_cmd->handles[0]);
	if (!obj)
		return ERR_PTR(-EINVAL);

	virtio_gpu_fb = kzalloc(sizeof(*virtio_gpu_fb), GFP_KERNEL);
	if (virtio_gpu_fb == NULL)
		return ERR_PTR(-ENOMEM);

	ret = virtio_gpu_framebuffer_init(dev, virtio_gpu_fb, mode_cmd, obj);
	if (ret) {
		kfree(virtio_gpu_fb);
		drm_gem_object_put_unlocked(obj);
		return NULL;
	}

	return &virtio_gpu_fb->base;
}

__attribute__((used)) static void vgdev_atomic_commit_tail(struct drm_atomic_state *state)
{
	struct drm_device *dev = state->dev;

	drm_atomic_helper_commit_modeset_disables(dev, state);
	drm_atomic_helper_commit_modeset_enables(dev, state);
	drm_atomic_helper_commit_planes(dev, state, 0);

	drm_atomic_helper_commit_hw_done(state);

	drm_atomic_helper_wait_for_vblanks(dev, state);
	drm_atomic_helper_cleanup_planes(dev, state);
}

int virtio_gpu_modeset_init(struct virtio_gpu_device *vgdev)
{
	int i;

	drm_mode_config_init(vgdev->ddev);
	vgdev->ddev->mode_config.funcs = &virtio_gpu_mode_funcs;
	vgdev->ddev->mode_config.helper_private = &virtio_mode_config_helpers;

	/* modes will be validated against the framebuffer size */
	vgdev->ddev->mode_config.min_width = XRES_MIN;
	vgdev->ddev->mode_config.min_height = YRES_MIN;
	vgdev->ddev->mode_config.max_width = XRES_MAX;
	vgdev->ddev->mode_config.max_height = YRES_MAX;

	for (i = 0 ; i < vgdev->num_scanouts; ++i)
		vgdev_output_init(vgdev, i);

	drm_mode_config_reset(vgdev->ddev);
	return 0;
}

void virtio_gpu_modeset_fini(struct virtio_gpu_device *vgdev)
{
	virtio_gpu_fbdev_fini(vgdev);
	drm_mode_config_cleanup(vgdev->ddev);
}

