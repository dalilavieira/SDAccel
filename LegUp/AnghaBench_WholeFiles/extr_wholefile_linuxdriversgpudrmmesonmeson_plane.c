#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct drm_plane {struct drm_plane_state* state; } ;
struct meson_plane {struct drm_plane base; struct meson_drm* priv; } ;
struct TYPE_10__ {int osd1_ctrl_stat; int* osd1_blk0_cfg; int osd1_interlace; int /*<<< orphan*/  osd1_height; int /*<<< orphan*/  osd1_stride; int /*<<< orphan*/  osd1_addr; } ;
struct meson_drm {struct drm_plane* primary_plane; TYPE_5__* drm; scalar_t__ io_base; TYPE_4__ viu; TYPE_1__* dev; } ;
struct drm_rect {int x1; int y1; int x2; int y2; } ;
struct drm_plane_state {int src_x; int src_y; int src_w; int src_h; int crtc_x; int crtc_y; int crtc_w; int crtc_h; TYPE_6__* crtc; struct drm_framebuffer* fb; int /*<<< orphan*/  state; } ;
struct drm_gem_cma_object {int /*<<< orphan*/  paddr; } ;
struct drm_framebuffer {int /*<<< orphan*/  height; int /*<<< orphan*/ * pitches; TYPE_2__* format; } ;
struct drm_crtc_state {int dummy; } ;
typedef  int int64_t ;
struct TYPE_9__ {int flags; } ;
struct TYPE_12__ {TYPE_3__ mode; } ;
struct TYPE_11__ {int /*<<< orphan*/  dev; int /*<<< orphan*/  event_lock; } ;
struct TYPE_8__ {int format; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
#define  DRM_FORMAT_ARGB8888 131 
#define  DRM_FORMAT_RGB565 130 
#define  DRM_FORMAT_RGB888 129 
#define  DRM_FORMAT_XRGB8888 128 
 int DRM_MODE_FLAG_INTERLACE ; 
 int /*<<< orphan*/  DRM_PLANE_HELPER_NO_SCALING ; 
 int /*<<< orphan*/  DRM_PLANE_TYPE_PRIMARY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct drm_crtc_state*) ; 
 int MESON_CANVAS_ID_OSD1 ; 
 int OSD_BLK0_ENABLE ; 
 int OSD_BLK_MODE_16 ; 
 int OSD_BLK_MODE_24 ; 
 int OSD_BLK_MODE_32 ; 
 int OSD_CANVAS_SEL ; 
 int OSD_COLOR_MATRIX_16_RGB565 ; 
 int OSD_COLOR_MATRIX_24_RGB ; 
 int OSD_COLOR_MATRIX_32_ARGB ; 
 int OSD_ENABLE ; 
 int OSD_ENDIANNESS_LE ; 
 int OSD_GLOBAL_ALPHA_SHIFT ; 
 int OSD_OUTPUT_COLOR_RGB ; 
 int /*<<< orphan*/  OSD_REPLACE_EN ; 
 int PTR_ERR (struct drm_crtc_state*) ; 
 int /*<<< orphan*/  VIU_OSD1_CTRL_STAT2 ; 
 int /*<<< orphan*/  VPP_MISC ; 
 int /*<<< orphan*/  VPP_OSD1_POSTBLEND ; 
 scalar_t__ _REG (int /*<<< orphan*/ ) ; 
 struct meson_plane* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct drm_crtc_state* drm_atomic_get_crtc_state (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int drm_atomic_helper_check_plane_state (struct drm_plane_state*,struct drm_crtc_state*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 struct drm_gem_cma_object* drm_fb_cma_get_gem_obj (struct drm_framebuffer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_plane_helper_add (struct drm_plane*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_universal_plane_init (TYPE_5__*,struct drm_plane*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  meson_plane_funcs ; 
 int /*<<< orphan*/  meson_plane_helper_funcs ; 
 int of_device_is_compatible (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  supported_drm_formats ; 
 struct meson_plane* to_meson_plane (struct drm_plane*) ; 
 int /*<<< orphan*/  writel_bits_relaxed (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline int meson_vpu_is_compatible(struct meson_drm *priv,
					  const char *compat)
{
	return of_device_is_compatible(priv->dev->of_node, compat);
}

__attribute__((used)) static int meson_plane_atomic_check(struct drm_plane *plane,
				    struct drm_plane_state *state)
{
	struct drm_crtc_state *crtc_state;

	if (!state->crtc)
		return 0;

	crtc_state = drm_atomic_get_crtc_state(state->state, state->crtc);
	if (IS_ERR(crtc_state))
		return PTR_ERR(crtc_state);

	return drm_atomic_helper_check_plane_state(state, crtc_state,
						   DRM_PLANE_HELPER_NO_SCALING,
						   DRM_PLANE_HELPER_NO_SCALING,
						   true, true);
}

__attribute__((used)) static inline int64_t fixed16_to_int(int64_t value)
{
	return value >> 16;
}

__attribute__((used)) static void meson_plane_atomic_update(struct drm_plane *plane,
				      struct drm_plane_state *old_state)
{
	struct meson_plane *meson_plane = to_meson_plane(plane);
	struct drm_plane_state *state = plane->state;
	struct drm_framebuffer *fb = state->fb;
	struct meson_drm *priv = meson_plane->priv;
	struct drm_gem_cma_object *gem;
	struct drm_rect src = {
		.x1 = (state->src_x),
		.y1 = (state->src_y),
		.x2 = (state->src_x + state->src_w),
		.y2 = (state->src_y + state->src_h),
	};
	struct drm_rect dest = {
		.x1 = state->crtc_x,
		.y1 = state->crtc_y,
		.x2 = state->crtc_x + state->crtc_w,
		.y2 = state->crtc_y + state->crtc_h,
	};
	unsigned long flags;

	/*
	 * Update Coordinates
	 * Update Formats
	 * Update Buffer
	 * Enable Plane
	 */
	spin_lock_irqsave(&priv->drm->event_lock, flags);

	/* Enable OSD and BLK0, set max global alpha */
	priv->viu.osd1_ctrl_stat = OSD_ENABLE |
				   (0xFF << OSD_GLOBAL_ALPHA_SHIFT) |
				   OSD_BLK0_ENABLE;

	/* Set up BLK0 to point to the right canvas */
	priv->viu.osd1_blk0_cfg[0] = ((MESON_CANVAS_ID_OSD1 << OSD_CANVAS_SEL) |
				      OSD_ENDIANNESS_LE);

	/* On GXBB, Use the old non-HDR RGB2YUV converter */
	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
		priv->viu.osd1_blk0_cfg[0] |= OSD_OUTPUT_COLOR_RGB;

	switch (fb->format->format) {
	case DRM_FORMAT_XRGB8888:
		/* For XRGB, replace the pixel's alpha by 0xFF */
		writel_bits_relaxed(OSD_REPLACE_EN, OSD_REPLACE_EN,
				    priv->io_base + _REG(VIU_OSD1_CTRL_STAT2));
		priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_32 |
					      OSD_COLOR_MATRIX_32_ARGB;
		break;
	case DRM_FORMAT_ARGB8888:
		/* For ARGB, use the pixel's alpha */
		writel_bits_relaxed(OSD_REPLACE_EN, 0,
				    priv->io_base + _REG(VIU_OSD1_CTRL_STAT2));
		priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_32 |
					      OSD_COLOR_MATRIX_32_ARGB;
		break;
	case DRM_FORMAT_RGB888:
		priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_24 |
					      OSD_COLOR_MATRIX_24_RGB;
		break;
	case DRM_FORMAT_RGB565:
		priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_16 |
					      OSD_COLOR_MATRIX_16_RGB565;
		break;
	};

	if (state->crtc->mode.flags & DRM_MODE_FLAG_INTERLACE) {
		priv->viu.osd1_interlace = true;

		dest.y1 /= 2;
		dest.y2 /= 2;
	} else
		priv->viu.osd1_interlace = false;

	/*
	 * The format of these registers is (x2 << 16 | x1),
	 * where x2 is exclusive.
	 * e.g. +30x1920 would be (1919 << 16) | 30
	 */
	priv->viu.osd1_blk0_cfg[1] = ((fixed16_to_int(src.x2) - 1) << 16) |
					fixed16_to_int(src.x1);
	priv->viu.osd1_blk0_cfg[2] = ((fixed16_to_int(src.y2) - 1) << 16) |
					fixed16_to_int(src.y1);
	priv->viu.osd1_blk0_cfg[3] = ((dest.x2 - 1) << 16) | dest.x1;
	priv->viu.osd1_blk0_cfg[4] = ((dest.y2 - 1) << 16) | dest.y1;

	/* Update Canvas with buffer address */
	gem = drm_fb_cma_get_gem_obj(fb, 0);

	priv->viu.osd1_addr = gem->paddr;
	priv->viu.osd1_stride = fb->pitches[0];
	priv->viu.osd1_height = fb->height;

	spin_unlock_irqrestore(&priv->drm->event_lock, flags);
}

__attribute__((used)) static void meson_plane_atomic_disable(struct drm_plane *plane,
				       struct drm_plane_state *old_state)
{
	struct meson_plane *meson_plane = to_meson_plane(plane);
	struct meson_drm *priv = meson_plane->priv;

	/* Disable OSD1 */
	writel_bits_relaxed(VPP_OSD1_POSTBLEND, 0,
			    priv->io_base + _REG(VPP_MISC));

}

int meson_plane_create(struct meson_drm *priv)
{
	struct meson_plane *meson_plane;
	struct drm_plane *plane;

	meson_plane = devm_kzalloc(priv->drm->dev, sizeof(*meson_plane),
				   GFP_KERNEL);
	if (!meson_plane)
		return -ENOMEM;

	meson_plane->priv = priv;
	plane = &meson_plane->base;

	drm_universal_plane_init(priv->drm, plane, 0xFF,
				 &meson_plane_funcs,
				 supported_drm_formats,
				 ARRAY_SIZE(supported_drm_formats),
				 NULL,
				 DRM_PLANE_TYPE_PRIMARY, "meson_primary_plane");

	drm_plane_helper_add(plane, &meson_plane_helper_funcs);

	priv->primary_plane = plane;

	return 0;
}

