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
struct reservation_object {int dummy; } ;
struct mtk_plane_state {int dummy; } ;
struct mtk_ddp_comp {TYPE_1__* funcs; } ;
struct drm_mode_fb_cmd2 {unsigned int width; unsigned int height; unsigned int* pitches; scalar_t__* offsets; int /*<<< orphan*/  pixel_format; int /*<<< orphan*/ * handles; } ;
struct drm_gem_object {unsigned int size; TYPE_2__* dma_buf; } ;
struct drm_framebuffer {struct drm_gem_object** obj; } ;
struct drm_file {int dummy; } ;
struct drm_device {int dummy; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_crtc {int dummy; } ;
struct TYPE_4__ {struct reservation_object* resv; } ;
struct TYPE_3__ {unsigned int (* layer_nr ) (struct mtk_ddp_comp*) ;int /*<<< orphan*/  (* gamma_set ) (struct mtk_ddp_comp*,struct drm_crtc_state*) ;int /*<<< orphan*/  (* layer_config ) (struct mtk_ddp_comp*,unsigned int,struct mtk_plane_state*) ;int /*<<< orphan*/  (* layer_off ) (struct mtk_ddp_comp*,unsigned int) ;int /*<<< orphan*/  (* layer_on ) (struct mtk_ddp_comp*,unsigned int) ;int /*<<< orphan*/  (* disable_vblank ) (struct mtk_ddp_comp*) ;int /*<<< orphan*/  (* enable_vblank ) (struct mtk_ddp_comp*,struct drm_crtc*) ;int /*<<< orphan*/  (* stop ) (struct mtk_ddp_comp*) ;int /*<<< orphan*/  (* start ) (struct mtk_ddp_comp*) ;int /*<<< orphan*/  (* config ) (struct mtk_ddp_comp*,unsigned int,unsigned int,unsigned int,unsigned int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 struct drm_framebuffer* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct drm_framebuffer*) ; 
 int /*<<< orphan*/  MAX_SCHEDULE_TIMEOUT ; 
 int PTR_ERR (struct drm_framebuffer*) ; 
 scalar_t__ WARN_ON (int) ; 
 int drm_format_num_planes (int /*<<< orphan*/ ) ; 
 unsigned int drm_format_plane_cpp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int drm_framebuffer_init (struct drm_device*,struct drm_framebuffer*,int /*<<< orphan*/ *) ; 
 struct drm_gem_object* drm_gem_object_lookup (struct drm_file*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_gem_object_put_unlocked (struct drm_gem_object*) ; 
 int /*<<< orphan*/  drm_helper_mode_fill_fb_struct (struct drm_device*,struct drm_framebuffer*,struct drm_mode_fb_cmd2 const*) ; 
 int /*<<< orphan*/  kfree (struct drm_framebuffer*) ; 
 struct drm_framebuffer* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_drm_fb_funcs ; 
 long reservation_object_wait_timeout_rcu (struct reservation_object*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct mtk_ddp_comp*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  stub10 (struct mtk_ddp_comp*,struct drm_crtc_state*) ; 
 int /*<<< orphan*/  stub2 (struct mtk_ddp_comp*) ; 
 int /*<<< orphan*/  stub3 (struct mtk_ddp_comp*) ; 
 int /*<<< orphan*/  stub4 (struct mtk_ddp_comp*,struct drm_crtc*) ; 
 int /*<<< orphan*/  stub5 (struct mtk_ddp_comp*) ; 
 unsigned int stub6 (struct mtk_ddp_comp*) ; 
 int /*<<< orphan*/  stub7 (struct mtk_ddp_comp*,unsigned int) ; 
 int /*<<< orphan*/  stub8 (struct mtk_ddp_comp*,unsigned int) ; 
 int /*<<< orphan*/  stub9 (struct mtk_ddp_comp*,unsigned int,struct mtk_plane_state*) ; 

__attribute__((used)) static inline void mtk_ddp_comp_config(struct mtk_ddp_comp *comp,
				       unsigned int w, unsigned int h,
				       unsigned int vrefresh, unsigned int bpc)
{
	if (comp->funcs && comp->funcs->config)
		comp->funcs->config(comp, w, h, vrefresh, bpc);
}

__attribute__((used)) static inline void mtk_ddp_comp_start(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->start)
		comp->funcs->start(comp);
}

__attribute__((used)) static inline void mtk_ddp_comp_stop(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->stop)
		comp->funcs->stop(comp);
}

__attribute__((used)) static inline void mtk_ddp_comp_enable_vblank(struct mtk_ddp_comp *comp,
					      struct drm_crtc *crtc)
{
	if (comp->funcs && comp->funcs->enable_vblank)
		comp->funcs->enable_vblank(comp, crtc);
}

__attribute__((used)) static inline void mtk_ddp_comp_disable_vblank(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->disable_vblank)
		comp->funcs->disable_vblank(comp);
}

__attribute__((used)) static inline unsigned int mtk_ddp_comp_layer_nr(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->layer_nr)
		return comp->funcs->layer_nr(comp);

	return 0;
}

__attribute__((used)) static inline void mtk_ddp_comp_layer_on(struct mtk_ddp_comp *comp,
					 unsigned int idx)
{
	if (comp->funcs && comp->funcs->layer_on)
		comp->funcs->layer_on(comp, idx);
}

__attribute__((used)) static inline void mtk_ddp_comp_layer_off(struct mtk_ddp_comp *comp,
					  unsigned int idx)
{
	if (comp->funcs && comp->funcs->layer_off)
		comp->funcs->layer_off(comp, idx);
}

__attribute__((used)) static inline void mtk_ddp_comp_layer_config(struct mtk_ddp_comp *comp,
					     unsigned int idx,
					     struct mtk_plane_state *state)
{
	if (comp->funcs && comp->funcs->layer_config)
		comp->funcs->layer_config(comp, idx, state);
}

__attribute__((used)) static inline void mtk_ddp_gamma_set(struct mtk_ddp_comp *comp,
				     struct drm_crtc_state *state)
{
	if (comp->funcs && comp->funcs->gamma_set)
		comp->funcs->gamma_set(comp, state);
}

__attribute__((used)) static struct drm_framebuffer *mtk_drm_framebuffer_init(struct drm_device *dev,
					const struct drm_mode_fb_cmd2 *mode,
					struct drm_gem_object *obj)
{
	struct drm_framebuffer *fb;
	int ret;

	if (drm_format_num_planes(mode->pixel_format) != 1)
		return ERR_PTR(-EINVAL);

	fb = kzalloc(sizeof(*fb), GFP_KERNEL);
	if (!fb)
		return ERR_PTR(-ENOMEM);

	drm_helper_mode_fill_fb_struct(dev, fb, mode);

	fb->obj[0] = obj;

	ret = drm_framebuffer_init(dev, fb, &mtk_drm_fb_funcs);
	if (ret) {
		DRM_ERROR("failed to initialize framebuffer\n");
		kfree(fb);
		return ERR_PTR(ret);
	}

	return fb;
}

int mtk_fb_wait(struct drm_framebuffer *fb)
{
	struct drm_gem_object *gem;
	struct reservation_object *resv;
	long ret;

	if (!fb)
		return 0;

	gem = fb->obj[0];
	if (!gem || !gem->dma_buf || !gem->dma_buf->resv)
		return 0;

	resv = gem->dma_buf->resv;
	ret = reservation_object_wait_timeout_rcu(resv, false, true,
						  MAX_SCHEDULE_TIMEOUT);
	/* MAX_SCHEDULE_TIMEOUT on success, -ERESTARTSYS if interrupted */
	if (WARN_ON(ret < 0))
		return ret;

	return 0;
}

struct drm_framebuffer *mtk_drm_mode_fb_create(struct drm_device *dev,
					       struct drm_file *file,
					       const struct drm_mode_fb_cmd2 *cmd)
{
	struct drm_framebuffer *fb;
	struct drm_gem_object *gem;
	unsigned int width = cmd->width;
	unsigned int height = cmd->height;
	unsigned int size, bpp;
	int ret;

	if (drm_format_num_planes(cmd->pixel_format) != 1)
		return ERR_PTR(-EINVAL);

	gem = drm_gem_object_lookup(file, cmd->handles[0]);
	if (!gem)
		return ERR_PTR(-ENOENT);

	bpp = drm_format_plane_cpp(cmd->pixel_format, 0);
	size = (height - 1) * cmd->pitches[0] + width * bpp;
	size += cmd->offsets[0];

	if (gem->size < size) {
		ret = -EINVAL;
		goto unreference;
	}

	fb = mtk_drm_framebuffer_init(dev, cmd, gem);
	if (IS_ERR(fb)) {
		ret = PTR_ERR(fb);
		goto unreference;
	}

	return fb;

unreference:
	drm_gem_object_put_unlocked(gem);
	return ERR_PTR(ret);
}

