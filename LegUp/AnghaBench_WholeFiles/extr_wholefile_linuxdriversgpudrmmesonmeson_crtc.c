#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int osd1_enabled; int osd1_commit; int /*<<< orphan*/  osd1_height; int /*<<< orphan*/  osd1_stride; int /*<<< orphan*/  osd1_addr; scalar_t__ osd1_interlace; int /*<<< orphan*/ * osd1_blk0_cfg; int /*<<< orphan*/  osd1_ctrl_stat; } ;
struct meson_drm {struct drm_crtc* crtc; TYPE_5__* drm; struct drm_plane* primary_plane; TYPE_4__ viu; scalar_t__ io_base; TYPE_1__* dev; } ;
struct drm_crtc {struct drm_crtc_state* state; TYPE_3__* dev; } ;
struct meson_crtc {struct drm_crtc base; struct meson_drm* priv; int /*<<< orphan*/ * event; } ;
struct drm_rect {scalar_t__ y2; scalar_t__ x2; scalar_t__ y1; scalar_t__ x1; } ;
struct drm_plane_state {scalar_t__ crtc_h; scalar_t__ crtc_y; scalar_t__ crtc_w; scalar_t__ crtc_x; } ;
struct drm_plane {struct drm_plane_state* state; } ;
struct TYPE_7__ {int /*<<< orphan*/  hdisplay; } ;
struct drm_crtc_state {int /*<<< orphan*/ * event; int /*<<< orphan*/  active; TYPE_2__ mode; } ;
struct TYPE_10__ {int /*<<< orphan*/  dev; int /*<<< orphan*/  event_lock; } ;
struct TYPE_8__ {int /*<<< orphan*/  event_lock; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MESON_CANVAS_BLKMODE_LINEAR ; 
 int /*<<< orphan*/  MESON_CANVAS_ID_OSD1 ; 
 int /*<<< orphan*/  MESON_CANVAS_WRAP_NONE ; 
 int /*<<< orphan*/  VIU_OSD1_BLK0_CFG_W0 ; 
 int /*<<< orphan*/  VIU_OSD1_BLK0_CFG_W1 ; 
 int /*<<< orphan*/  VIU_OSD1_BLK0_CFG_W2 ; 
 int /*<<< orphan*/  VIU_OSD1_BLK0_CFG_W3 ; 
 int /*<<< orphan*/  VIU_OSD1_BLK0_CFG_W4 ; 
 int /*<<< orphan*/  VIU_OSD1_CTRL_STAT ; 
 int /*<<< orphan*/  VPP_MISC ; 
 int /*<<< orphan*/  VPP_OSD1_POSTBLEND ; 
 int /*<<< orphan*/  VPP_POSTBLEND_ENABLE ; 
 int /*<<< orphan*/  VPP_POSTBLEND_H_SIZE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 scalar_t__ _REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 struct meson_crtc* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_crtc_handle_vblank (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_crtc_helper_add (struct drm_crtc*,int /*<<< orphan*/ *) ; 
 int drm_crtc_init_with_planes (TYPE_5__*,struct drm_crtc*,struct drm_plane*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  drm_crtc_send_vblank_event (struct drm_crtc*,int /*<<< orphan*/ *) ; 
 scalar_t__ drm_crtc_vblank_get (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_crtc_vblank_off (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_crtc_vblank_on (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_crtc_vblank_put (struct drm_crtc*) ; 
 int /*<<< orphan*/  meson_canvas_setup (struct meson_drm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  meson_crtc_funcs ; 
 int /*<<< orphan*/  meson_crtc_helper_funcs ; 
 int /*<<< orphan*/  meson_venc_disable_vsync (struct meson_drm*) ; 
 int /*<<< orphan*/  meson_venc_enable_vsync (struct meson_drm*) ; 
 int /*<<< orphan*/  meson_vpp_disable_interlace_vscaler_osd1 (struct meson_drm*) ; 
 int /*<<< orphan*/  meson_vpp_setup_interlace_vscaler_osd1 (struct meson_drm*,struct drm_rect*) ; 
 int of_device_is_compatible (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct meson_crtc* to_meson_crtc (struct drm_crtc*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel_bits_relaxed (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline int meson_vpu_is_compatible(struct meson_drm *priv,
					  const char *compat)
{
	return of_device_is_compatible(priv->dev->of_node, compat);
}

__attribute__((used)) static int meson_crtc_enable_vblank(struct drm_crtc *crtc)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
	struct meson_drm *priv = meson_crtc->priv;

	meson_venc_enable_vsync(priv);

	return 0;
}

__attribute__((used)) static void meson_crtc_disable_vblank(struct drm_crtc *crtc)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
	struct meson_drm *priv = meson_crtc->priv;

	meson_venc_disable_vsync(priv);
}

__attribute__((used)) static void meson_crtc_atomic_enable(struct drm_crtc *crtc,
				     struct drm_crtc_state *old_state)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
	struct drm_crtc_state *crtc_state = crtc->state;
	struct meson_drm *priv = meson_crtc->priv;

	DRM_DEBUG_DRIVER("\n");

	if (!crtc_state) {
		DRM_ERROR("Invalid crtc_state\n");
		return;
	}

	/* Enable VPP Postblend */
	writel(crtc_state->mode.hdisplay,
	       priv->io_base + _REG(VPP_POSTBLEND_H_SIZE));

	writel_bits_relaxed(VPP_POSTBLEND_ENABLE, VPP_POSTBLEND_ENABLE,
			    priv->io_base + _REG(VPP_MISC));

	drm_crtc_vblank_on(crtc);

	priv->viu.osd1_enabled = true;
}

__attribute__((used)) static void meson_crtc_atomic_disable(struct drm_crtc *crtc,
				      struct drm_crtc_state *old_state)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
	struct meson_drm *priv = meson_crtc->priv;

	drm_crtc_vblank_off(crtc);

	priv->viu.osd1_enabled = false;
	priv->viu.osd1_commit = false;

	/* Disable VPP Postblend */
	writel_bits_relaxed(VPP_POSTBLEND_ENABLE, 0,
			    priv->io_base + _REG(VPP_MISC));

	if (crtc->state->event && !crtc->state->active) {
		spin_lock_irq(&crtc->dev->event_lock);
		drm_crtc_send_vblank_event(crtc, crtc->state->event);
		spin_unlock_irq(&crtc->dev->event_lock);

		crtc->state->event = NULL;
	}
}

__attribute__((used)) static void meson_crtc_atomic_begin(struct drm_crtc *crtc,
				    struct drm_crtc_state *state)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
	unsigned long flags;

	if (crtc->state->event) {
		WARN_ON(drm_crtc_vblank_get(crtc) != 0);

		spin_lock_irqsave(&crtc->dev->event_lock, flags);
		meson_crtc->event = crtc->state->event;
		spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
		crtc->state->event = NULL;
	}
}

__attribute__((used)) static void meson_crtc_atomic_flush(struct drm_crtc *crtc,
				    struct drm_crtc_state *old_crtc_state)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
	struct meson_drm *priv = meson_crtc->priv;

	priv->viu.osd1_commit = true;
}

void meson_crtc_irq(struct meson_drm *priv)
{
	struct meson_crtc *meson_crtc = to_meson_crtc(priv->crtc);
	unsigned long flags;

	/* Update the OSD registers */
	if (priv->viu.osd1_enabled && priv->viu.osd1_commit) {
		writel_relaxed(priv->viu.osd1_ctrl_stat,
				priv->io_base + _REG(VIU_OSD1_CTRL_STAT));
		writel_relaxed(priv->viu.osd1_blk0_cfg[0],
				priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W0));
		writel_relaxed(priv->viu.osd1_blk0_cfg[1],
				priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W1));
		writel_relaxed(priv->viu.osd1_blk0_cfg[2],
				priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W2));
		writel_relaxed(priv->viu.osd1_blk0_cfg[3],
				priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W3));
		writel_relaxed(priv->viu.osd1_blk0_cfg[4],
				priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W4));

		/* If output is interlace, make use of the Scaler */
		if (priv->viu.osd1_interlace) {
			struct drm_plane *plane = priv->primary_plane;
			struct drm_plane_state *state = plane->state;
			struct drm_rect dest = {
				.x1 = state->crtc_x,
				.y1 = state->crtc_y,
				.x2 = state->crtc_x + state->crtc_w,
				.y2 = state->crtc_y + state->crtc_h,
			};

			meson_vpp_setup_interlace_vscaler_osd1(priv, &dest);
		} else
			meson_vpp_disable_interlace_vscaler_osd1(priv);

		meson_canvas_setup(priv, MESON_CANVAS_ID_OSD1,
			   priv->viu.osd1_addr, priv->viu.osd1_stride,
			   priv->viu.osd1_height, MESON_CANVAS_WRAP_NONE,
			   MESON_CANVAS_BLKMODE_LINEAR);

		/* Enable OSD1 */
		writel_bits_relaxed(VPP_OSD1_POSTBLEND, VPP_OSD1_POSTBLEND,
				    priv->io_base + _REG(VPP_MISC));

		priv->viu.osd1_commit = false;
	}

	drm_crtc_handle_vblank(priv->crtc);

	spin_lock_irqsave(&priv->drm->event_lock, flags);
	if (meson_crtc->event) {
		drm_crtc_send_vblank_event(priv->crtc, meson_crtc->event);
		drm_crtc_vblank_put(priv->crtc);
		meson_crtc->event = NULL;
	}
	spin_unlock_irqrestore(&priv->drm->event_lock, flags);
}

int meson_crtc_create(struct meson_drm *priv)
{
	struct meson_crtc *meson_crtc;
	struct drm_crtc *crtc;
	int ret;

	meson_crtc = devm_kzalloc(priv->drm->dev, sizeof(*meson_crtc),
				  GFP_KERNEL);
	if (!meson_crtc)
		return -ENOMEM;

	meson_crtc->priv = priv;
	crtc = &meson_crtc->base;
	ret = drm_crtc_init_with_planes(priv->drm, crtc,
					priv->primary_plane, NULL,
					&meson_crtc_funcs, "meson_crtc");
	if (ret) {
		dev_err(priv->drm->dev, "Failed to init CRTC\n");
		return ret;
	}

	drm_crtc_helper_add(crtc, &meson_crtc_helper_funcs);

	priv->crtc = crtc;

	return 0;
}

