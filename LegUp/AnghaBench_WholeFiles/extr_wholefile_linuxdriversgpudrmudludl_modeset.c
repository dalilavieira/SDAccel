#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct urb {scalar_t__ transfer_buffer; } ;
struct TYPE_6__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct udl_framebuffer {int active_16; TYPE_3__ base; } ;
struct udl_device {int mode_buf_len; struct drm_crtc* crtc; scalar_t__ mode_buf; } ;
struct drm_pending_vblank_event {int dummy; } ;
struct drm_modeset_acquire_ctx {int dummy; } ;
struct drm_framebuffer {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct drm_encoder {int dummy; } ;
struct drm_display_mode {int crtc_htotal; int crtc_hsync_start; int crtc_hdisplay; int crtc_vtotal; int crtc_vsync_start; int crtc_vdisplay; int crtc_hsync_end; int hdisplay; int crtc_vsync_end; int clock; int vdisplay; } ;
struct TYPE_4__ {int min_width; int min_height; int max_width; int max_height; int preferred_depth; int /*<<< orphan*/ * funcs; scalar_t__ prefer_shadow; } ;
struct drm_device {struct udl_device* dev_private; TYPE_1__ mode_config; int /*<<< orphan*/  event_lock; } ;
struct drm_crtc {TYPE_2__* primary; struct drm_device* dev; } ;
struct drm_connector {int dummy; } ;
struct TYPE_5__ {struct drm_framebuffer* fb; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*,int) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
#define  DRM_MODE_DPMS_OFF 131 
#define  DRM_MODE_DPMS_ON 130 
#define  DRM_MODE_DPMS_STANDBY 129 
#define  DRM_MODE_DPMS_SUSPEND 128 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  drm_crtc_cleanup (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_crtc_helper_add (struct drm_crtc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_crtc_init (struct drm_device*,struct drm_crtc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_crtc_send_vblank_event (struct drm_crtc*,struct drm_pending_vblank_event*) ; 
 int /*<<< orphan*/  drm_mode_config_cleanup (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_init (struct drm_device*) ; 
 int /*<<< orphan*/  kfree (struct drm_crtc*) ; 
 struct drm_crtc* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,scalar_t__,int) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 struct udl_framebuffer* to_udl_fb (struct drm_framebuffer*) ; 
 int /*<<< orphan*/  udl_connector_init (struct drm_device*,struct drm_encoder*) ; 
 int /*<<< orphan*/  udl_crtc_funcs ; 
 struct drm_encoder* udl_encoder_init (struct drm_device*) ; 
 struct urb* udl_get_urb (struct drm_device*) ; 
 int /*<<< orphan*/  udl_handle_damage (struct udl_framebuffer*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udl_helper_funcs ; 
 int /*<<< orphan*/  udl_mode_funcs ; 
 int udl_submit_urb (struct drm_device*,struct urb*,int) ; 

__attribute__((used)) static char *udl_set_register(char *buf, u8 reg, u8 val)
{
	*buf++ = 0xAF;
	*buf++ = 0x20;
	*buf++ = reg;
	*buf++ = val;
	return buf;
}

__attribute__((used)) static char *udl_vidreg_lock(char *buf)
{
	return udl_set_register(buf, 0xFF, 0x00);
}

__attribute__((used)) static char *udl_vidreg_unlock(char *buf)
{
	return udl_set_register(buf, 0xFF, 0xFF);
}

__attribute__((used)) static char *udl_set_blank(char *buf, int dpms_mode)
{
	u8 reg;
	switch (dpms_mode) {
	case DRM_MODE_DPMS_OFF:
		reg = 0x07;
		break;
	case DRM_MODE_DPMS_STANDBY:
		reg = 0x05;
		break;
	case DRM_MODE_DPMS_SUSPEND:
		reg = 0x01;
		break;
	case DRM_MODE_DPMS_ON:
		reg = 0x00;
		break;
	}

	return udl_set_register(buf, 0x1f, reg);
}

__attribute__((used)) static char *udl_set_color_depth(char *buf, u8 selection)
{
	return udl_set_register(buf, 0x00, selection);
}

__attribute__((used)) static char *udl_set_base16bpp(char *wrptr, u32 base)
{
	/* the base pointer is 16 bits wide, 0x20 is hi byte. */
	wrptr = udl_set_register(wrptr, 0x20, base >> 16);
	wrptr = udl_set_register(wrptr, 0x21, base >> 8);
	return udl_set_register(wrptr, 0x22, base);
}

__attribute__((used)) static char *udl_set_base8bpp(char *wrptr, u32 base)
{
	wrptr = udl_set_register(wrptr, 0x26, base >> 16);
	wrptr = udl_set_register(wrptr, 0x27, base >> 8);
	return udl_set_register(wrptr, 0x28, base);
}

__attribute__((used)) static char *udl_set_register_16(char *wrptr, u8 reg, u16 value)
{
	wrptr = udl_set_register(wrptr, reg, value >> 8);
	return udl_set_register(wrptr, reg+1, value);
}

__attribute__((used)) static char *udl_set_register_16be(char *wrptr, u8 reg, u16 value)
{
	wrptr = udl_set_register(wrptr, reg, value);
	return udl_set_register(wrptr, reg+1, value >> 8);
}

__attribute__((used)) static u16 udl_lfsr16(u16 actual_count)
{
	u32 lv = 0xFFFF; /* This is the lfsr value that the hw starts with */

	while (actual_count--) {
		lv =	 ((lv << 1) |
			(((lv >> 15) ^ (lv >> 4) ^ (lv >> 2) ^ (lv >> 1)) & 1))
			& 0xFFFF;
	}

	return (u16) lv;
}

__attribute__((used)) static char *udl_set_register_lfsr16(char *wrptr, u8 reg, u16 value)
{
	return udl_set_register_16(wrptr, reg, udl_lfsr16(value));
}

__attribute__((used)) static char *udl_set_vid_cmds(char *wrptr, struct drm_display_mode *mode)
{
	u16 xds, yds;
	u16 xde, yde;
	u16 yec;

	/* x display start */
	xds = mode->crtc_htotal - mode->crtc_hsync_start;
	wrptr = udl_set_register_lfsr16(wrptr, 0x01, xds);
	/* x display end */
	xde = xds + mode->crtc_hdisplay;
	wrptr = udl_set_register_lfsr16(wrptr, 0x03, xde);

	/* y display start */
	yds = mode->crtc_vtotal - mode->crtc_vsync_start;
	wrptr = udl_set_register_lfsr16(wrptr, 0x05, yds);
	/* y display end */
	yde = yds + mode->crtc_vdisplay;
	wrptr = udl_set_register_lfsr16(wrptr, 0x07, yde);

	/* x end count is active + blanking - 1 */
	wrptr = udl_set_register_lfsr16(wrptr, 0x09,
					mode->crtc_htotal - 1);

	/* libdlo hardcodes hsync start to 1 */
	wrptr = udl_set_register_lfsr16(wrptr, 0x0B, 1);

	/* hsync end is width of sync pulse + 1 */
	wrptr = udl_set_register_lfsr16(wrptr, 0x0D,
					mode->crtc_hsync_end - mode->crtc_hsync_start + 1);

	/* hpixels is active pixels */
	wrptr = udl_set_register_16(wrptr, 0x0F, mode->hdisplay);

	/* yendcount is vertical active + vertical blanking */
	yec = mode->crtc_vtotal;
	wrptr = udl_set_register_lfsr16(wrptr, 0x11, yec);

	/* libdlo hardcodes vsync start to 0 */
	wrptr = udl_set_register_lfsr16(wrptr, 0x13, 0);

	/* vsync end is width of vsync pulse */
	wrptr = udl_set_register_lfsr16(wrptr, 0x15, mode->crtc_vsync_end - mode->crtc_vsync_start);

	/* vpixels is active pixels */
	wrptr = udl_set_register_16(wrptr, 0x17, mode->crtc_vdisplay);

	wrptr = udl_set_register_16be(wrptr, 0x1B,
				      mode->clock / 5);

	return wrptr;
}

__attribute__((used)) static char *udl_dummy_render(char *wrptr)
{
	*wrptr++ = 0xAF;
	*wrptr++ = 0x6A; /* copy */
	*wrptr++ = 0x00; /* from addr */
	*wrptr++ = 0x00;
	*wrptr++ = 0x00;
	*wrptr++ = 0x01; /* one pixel */
	*wrptr++ = 0x00; /* to address */
	*wrptr++ = 0x00;
	*wrptr++ = 0x00;
	return wrptr;
}

__attribute__((used)) static int udl_crtc_write_mode_to_hw(struct drm_crtc *crtc)
{
	struct drm_device *dev = crtc->dev;
	struct udl_device *udl = dev->dev_private;
	struct urb *urb;
	char *buf;
	int retval;

	urb = udl_get_urb(dev);
	if (!urb)
		return -ENOMEM;

	buf = (char *)urb->transfer_buffer;

	memcpy(buf, udl->mode_buf, udl->mode_buf_len);
	retval = udl_submit_urb(dev, urb, udl->mode_buf_len);
	DRM_DEBUG("write mode info %d\n", udl->mode_buf_len);
	return retval;
}

__attribute__((used)) static void udl_crtc_dpms(struct drm_crtc *crtc, int mode)
{
	struct drm_device *dev = crtc->dev;
	struct udl_device *udl = dev->dev_private;
	int retval;

	if (mode == DRM_MODE_DPMS_OFF) {
		char *buf;
		struct urb *urb;
		urb = udl_get_urb(dev);
		if (!urb)
			return;

		buf = (char *)urb->transfer_buffer;
		buf = udl_vidreg_lock(buf);
		buf = udl_set_blank(buf, mode);
		buf = udl_vidreg_unlock(buf);

		buf = udl_dummy_render(buf);
		retval = udl_submit_urb(dev, urb, buf - (char *)
					urb->transfer_buffer);
	} else {
		if (udl->mode_buf_len == 0) {
			DRM_ERROR("Trying to enable DPMS with no mode\n");
			return;
		}
		udl_crtc_write_mode_to_hw(crtc);
	}

}

__attribute__((used)) static int udl_crtc_mode_set(struct drm_crtc *crtc,
			       struct drm_display_mode *mode,
			       struct drm_display_mode *adjusted_mode,
			       int x, int y,
			       struct drm_framebuffer *old_fb)

{
	struct drm_device *dev = crtc->dev;
	struct udl_framebuffer *ufb = to_udl_fb(crtc->primary->fb);
	struct udl_device *udl = dev->dev_private;
	char *buf;
	char *wrptr;
	int color_depth = 0;

	udl->crtc = crtc;

	buf = (char *)udl->mode_buf;

	/* for now we just clip 24 -> 16 - if we fix that fix this */
	/*if  (crtc->fb->bits_per_pixel != 16)
	  color_depth = 1; */

	/* This first section has to do with setting the base address on the
	* controller * associated with the display. There are 2 base
	* pointers, currently, we only * use the 16 bpp segment.
	*/
	wrptr = udl_vidreg_lock(buf);
	wrptr = udl_set_color_depth(wrptr, color_depth);
	/* set base for 16bpp segment to 0 */
	wrptr = udl_set_base16bpp(wrptr, 0);
	/* set base for 8bpp segment to end of fb */
	wrptr = udl_set_base8bpp(wrptr, 2 * mode->vdisplay * mode->hdisplay);

	wrptr = udl_set_vid_cmds(wrptr, adjusted_mode);
	wrptr = udl_set_blank(wrptr, DRM_MODE_DPMS_ON);
	wrptr = udl_vidreg_unlock(wrptr);

	wrptr = udl_dummy_render(wrptr);

	if (old_fb) {
		struct udl_framebuffer *uold_fb = to_udl_fb(old_fb);
		uold_fb->active_16 = false;
	}
	ufb->active_16 = true;
	udl->mode_buf_len = wrptr - buf;

	/* damage all of it */
	udl_handle_damage(ufb, 0, 0, ufb->base.width, ufb->base.height);
	return 0;
}

__attribute__((used)) static void udl_crtc_disable(struct drm_crtc *crtc)
{
	udl_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
}

__attribute__((used)) static void udl_crtc_destroy(struct drm_crtc *crtc)
{
	drm_crtc_cleanup(crtc);
	kfree(crtc);
}

__attribute__((used)) static int udl_crtc_page_flip(struct drm_crtc *crtc,
			      struct drm_framebuffer *fb,
			      struct drm_pending_vblank_event *event,
			      uint32_t page_flip_flags,
			      struct drm_modeset_acquire_ctx *ctx)
{
	struct udl_framebuffer *ufb = to_udl_fb(fb);
	struct drm_device *dev = crtc->dev;

	struct drm_framebuffer *old_fb = crtc->primary->fb;
	if (old_fb) {
		struct udl_framebuffer *uold_fb = to_udl_fb(old_fb);
		uold_fb->active_16 = false;
	}
	ufb->active_16 = true;

	udl_handle_damage(ufb, 0, 0, fb->width, fb->height);

	spin_lock_irq(&dev->event_lock);
	if (event)
		drm_crtc_send_vblank_event(crtc, event);
	spin_unlock_irq(&dev->event_lock);
	crtc->primary->fb = fb;

	return 0;
}

__attribute__((used)) static void udl_crtc_prepare(struct drm_crtc *crtc)
{
}

__attribute__((used)) static void udl_crtc_commit(struct drm_crtc *crtc)
{
	udl_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
}

__attribute__((used)) static int udl_crtc_init(struct drm_device *dev)
{
	struct drm_crtc *crtc;

	crtc = kzalloc(sizeof(struct drm_crtc) + sizeof(struct drm_connector *), GFP_KERNEL);
	if (crtc == NULL)
		return -ENOMEM;

	drm_crtc_init(dev, crtc, &udl_crtc_funcs);
	drm_crtc_helper_add(crtc, &udl_helper_funcs);

	return 0;
}

int udl_modeset_init(struct drm_device *dev)
{
	struct drm_encoder *encoder;
	drm_mode_config_init(dev);

	dev->mode_config.min_width = 640;
	dev->mode_config.min_height = 480;

	dev->mode_config.max_width = 2048;
	dev->mode_config.max_height = 2048;

	dev->mode_config.prefer_shadow = 0;
	dev->mode_config.preferred_depth = 24;

	dev->mode_config.funcs = &udl_mode_funcs;

	udl_crtc_init(dev);

	encoder = udl_encoder_init(dev);

	udl_connector_init(dev, encoder);

	return 0;
}

void udl_modeset_restore(struct drm_device *dev)
{
	struct udl_device *udl = dev->dev_private;
	struct udl_framebuffer *ufb;

	if (!udl->crtc || !udl->crtc->primary->fb)
		return;
	udl_crtc_commit(udl->crtc);
	ufb = to_udl_fb(udl->crtc->primary->fb);
	udl_handle_damage(ufb, 0, 0, ufb->base.width, ufb->base.height);
}

void udl_modeset_cleanup(struct drm_device *dev)
{
	drm_mode_config_cleanup(dev);
}

