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
typedef  scalar_t__ u8 ;
typedef  int u16 ;
struct tinydrm_device {int (* fb_dirty ) (struct drm_framebuffer*,struct drm_file*,unsigned int,unsigned int,struct drm_clip_rect*,unsigned int) ;struct drm_device* drm; } ;
struct mipi_dbi {scalar_t__* read_commands; int (* command ) (struct mipi_dbi*,scalar_t__,scalar_t__*,size_t) ;int swap_bytes; int enabled; unsigned int rotation; scalar_t__ reset; scalar_t__ regulator; struct tinydrm_device tinydrm; void* tx_buf; int /*<<< orphan*/  cmdlock; scalar_t__ backlight; int /*<<< orphan*/  dc; } ;
struct drm_simple_display_pipe_funcs {int dummy; } ;
struct drm_simple_display_pipe {int dummy; } ;
struct drm_plane_state {struct drm_framebuffer* fb; } ;
struct TYPE_8__ {struct dma_buf_attachment* import_attach; } ;
struct drm_gem_cma_object {void* vaddr; TYPE_3__ base; } ;
struct TYPE_6__ {int /*<<< orphan*/  id; } ;
struct drm_framebuffer {TYPE_4__* format; TYPE_1__ base; int /*<<< orphan*/  height; int /*<<< orphan*/  width; TYPE_5__* dev; } ;
struct drm_format_name_buf {int dummy; } ;
struct drm_file {int dummy; } ;
struct drm_driver {int dummy; } ;
struct drm_display_mode {int vdisplay; int hdisplay; } ;
struct TYPE_7__ {int min_height; int min_width; int preferred_depth; } ;
struct drm_device {struct device* dev; TYPE_2__ mode_config; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_clip_rect {int x1; int x2; int y1; int y2; } ;
struct dma_buf_attachment {int /*<<< orphan*/  dmabuf; } ;
struct device {int dummy; } ;
struct TYPE_10__ {struct tinydrm_device* dev_private; int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int format; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 scalar_t__ DCS_POWER_MODE_DISPLAY ; 
 scalar_t__ DCS_POWER_MODE_DISPLAY_NORMAL_MODE ; 
 scalar_t__ DCS_POWER_MODE_RESERVED_MASK ; 
 scalar_t__ DCS_POWER_MODE_SLEEP_MODE ; 
 int /*<<< orphan*/  DMA_FROM_DEVICE ; 
 int /*<<< orphan*/  DRM_DEBUG (char*,int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*) ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,...) ; 
 int /*<<< orphan*/  DRM_DEV_ERROR (struct device*,char*,int) ; 
#define  DRM_FORMAT_RGB565 129 
#define  DRM_FORMAT_XRGB8888 128 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_VIRTUAL ; 
 int EACCES ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ MIPI_DCS_GET_POWER_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_COLUMN_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PAGE_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SOFT_RESET ; 
 scalar_t__ MIPI_DCS_WRITE_MEMORY_START ; 
 int /*<<< orphan*/  backlight_disable (scalar_t__) ; 
 int /*<<< orphan*/  backlight_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err_once (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 void* devm_kmalloc (struct device*,size_t,int /*<<< orphan*/ ) ; 
 int devm_tinydrm_init (struct device*,struct tinydrm_device*,int /*<<< orphan*/ *,struct drm_driver*) ; 
 int dma_buf_begin_cpu_access (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dma_buf_end_cpu_access (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct drm_gem_cma_object* drm_fb_cma_get_gem_obj (struct drm_framebuffer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_get_format_name (int,struct drm_format_name_buf*) ; 
 int /*<<< orphan*/  drm_mode_config_reset (struct drm_device*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (scalar_t__,int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 
 int mipi_dbi_command (struct mipi_dbi*,int /*<<< orphan*/ ,...) ; 
 int mipi_dbi_command_buf (struct mipi_dbi*,scalar_t__,scalar_t__*,size_t) ; 
 int /*<<< orphan*/  mipi_dbi_fb_funcs ; 
 int /*<<< orphan*/  mipi_dbi_formats ; 
 struct mipi_dbi* mipi_dbi_from_tinydrm (struct tinydrm_device*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct tinydrm_device* pipe_to_tinydrm (struct drm_simple_display_pipe*) ; 
 int /*<<< orphan*/  regulator_disable (scalar_t__) ; 
 int regulator_enable (scalar_t__) ; 
 int stub1 (struct mipi_dbi*,scalar_t__,scalar_t__*,size_t) ; 
 int stub2 (struct drm_framebuffer*,struct drm_file*,unsigned int,unsigned int,struct drm_clip_rect*,unsigned int) ; 
 int tinydrm_display_pipe_init (struct tinydrm_device*,struct drm_simple_display_pipe_funcs const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct drm_display_mode const*,unsigned int) ; 
 int /*<<< orphan*/  tinydrm_memcpy (void*,void*,struct drm_framebuffer*,struct drm_clip_rect*) ; 
 int tinydrm_merge_clips (struct drm_clip_rect*,struct drm_clip_rect*,unsigned int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tinydrm_swab16 (void*,void*,struct drm_framebuffer*,struct drm_clip_rect*) ; 
 int /*<<< orphan*/  tinydrm_xrgb8888_to_rgb565 (void*,void*,struct drm_framebuffer*,struct drm_clip_rect*,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static bool mipi_dbi_command_is_read(struct mipi_dbi *mipi, u8 cmd)
{
	unsigned int i;

	if (!mipi->read_commands)
		return false;

	for (i = 0; i < 0xff; i++) {
		if (!mipi->read_commands[i])
			return false;
		if (cmd == mipi->read_commands[i])
			return true;
	}

	return false;
}

int mipi_dbi_command_read(struct mipi_dbi *mipi, u8 cmd, u8 *val)
{
	if (!mipi->read_commands)
		return -EACCES;

	if (!mipi_dbi_command_is_read(mipi, cmd))
		return -EINVAL;

	return mipi_dbi_command_buf(mipi, cmd, val, 1);
}

int mipi_dbi_command_buf(struct mipi_dbi *mipi, u8 cmd, u8 *data, size_t len)
{
	int ret;

	mutex_lock(&mipi->cmdlock);
	ret = mipi->command(mipi, cmd, data, len);
	mutex_unlock(&mipi->cmdlock);

	return ret;
}

int mipi_dbi_buf_copy(void *dst, struct drm_framebuffer *fb,
		      struct drm_clip_rect *clip, bool swap)
{
	struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
	struct dma_buf_attachment *import_attach = cma_obj->base.import_attach;
	struct drm_format_name_buf format_name;
	void *src = cma_obj->vaddr;
	int ret = 0;

	if (import_attach) {
		ret = dma_buf_begin_cpu_access(import_attach->dmabuf,
					       DMA_FROM_DEVICE);
		if (ret)
			return ret;
	}

	switch (fb->format->format) {
	case DRM_FORMAT_RGB565:
		if (swap)
			tinydrm_swab16(dst, src, fb, clip);
		else
			tinydrm_memcpy(dst, src, fb, clip);
		break;
	case DRM_FORMAT_XRGB8888:
		tinydrm_xrgb8888_to_rgb565(dst, src, fb, clip, swap);
		break;
	default:
		dev_err_once(fb->dev->dev, "Format is not supported: %s\n",
			     drm_get_format_name(fb->format->format,
						 &format_name));
		return -EINVAL;
	}

	if (import_attach)
		ret = dma_buf_end_cpu_access(import_attach->dmabuf,
					     DMA_FROM_DEVICE);
	return ret;
}

__attribute__((used)) static int mipi_dbi_fb_dirty(struct drm_framebuffer *fb,
			     struct drm_file *file_priv,
			     unsigned int flags, unsigned int color,
			     struct drm_clip_rect *clips,
			     unsigned int num_clips)
{
	struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
	struct tinydrm_device *tdev = fb->dev->dev_private;
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
	bool swap = mipi->swap_bytes;
	struct drm_clip_rect clip;
	int ret = 0;
	bool full;
	void *tr;

	if (!mipi->enabled)
		return 0;

	full = tinydrm_merge_clips(&clip, clips, num_clips, flags,
				   fb->width, fb->height);

	DRM_DEBUG("Flushing [FB:%d] x1=%u, x2=%u, y1=%u, y2=%u\n", fb->base.id,
		  clip.x1, clip.x2, clip.y1, clip.y2);

	if (!mipi->dc || !full || swap ||
	    fb->format->format == DRM_FORMAT_XRGB8888) {
		tr = mipi->tx_buf;
		ret = mipi_dbi_buf_copy(mipi->tx_buf, fb, &clip, swap);
		if (ret)
			return ret;
	} else {
		tr = cma_obj->vaddr;
	}

	mipi_dbi_command(mipi, MIPI_DCS_SET_COLUMN_ADDRESS,
			 (clip.x1 >> 8) & 0xFF, clip.x1 & 0xFF,
			 (clip.x2 >> 8) & 0xFF, (clip.x2 - 1) & 0xFF);
	mipi_dbi_command(mipi, MIPI_DCS_SET_PAGE_ADDRESS,
			 (clip.y1 >> 8) & 0xFF, clip.y1 & 0xFF,
			 (clip.y2 >> 8) & 0xFF, (clip.y2 - 1) & 0xFF);

	ret = mipi_dbi_command_buf(mipi, MIPI_DCS_WRITE_MEMORY_START, tr,
				(clip.x2 - clip.x1) * (clip.y2 - clip.y1) * 2);

	return ret;
}

void mipi_dbi_enable_flush(struct mipi_dbi *mipi,
			   struct drm_crtc_state *crtc_state,
			   struct drm_plane_state *plane_state)
{
	struct tinydrm_device *tdev = &mipi->tinydrm;
	struct drm_framebuffer *fb = plane_state->fb;

	mipi->enabled = true;
	if (fb)
		tdev->fb_dirty(fb, NULL, 0, 0, NULL, 0);

	backlight_enable(mipi->backlight);
}

__attribute__((used)) static void mipi_dbi_blank(struct mipi_dbi *mipi)
{
	struct drm_device *drm = mipi->tinydrm.drm;
	u16 height = drm->mode_config.min_height;
	u16 width = drm->mode_config.min_width;
	size_t len = width * height * 2;

	memset(mipi->tx_buf, 0, len);

	mipi_dbi_command(mipi, MIPI_DCS_SET_COLUMN_ADDRESS, 0, 0,
			 (width >> 8) & 0xFF, (width - 1) & 0xFF);
	mipi_dbi_command(mipi, MIPI_DCS_SET_PAGE_ADDRESS, 0, 0,
			 (height >> 8) & 0xFF, (height - 1) & 0xFF);
	mipi_dbi_command_buf(mipi, MIPI_DCS_WRITE_MEMORY_START,
			     (u8 *)mipi->tx_buf, len);
}

void mipi_dbi_pipe_disable(struct drm_simple_display_pipe *pipe)
{
	struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);

	DRM_DEBUG_KMS("\n");

	mipi->enabled = false;

	if (mipi->backlight)
		backlight_disable(mipi->backlight);
	else
		mipi_dbi_blank(mipi);

	if (mipi->regulator)
		regulator_disable(mipi->regulator);
}

int mipi_dbi_init(struct device *dev, struct mipi_dbi *mipi,
		  const struct drm_simple_display_pipe_funcs *pipe_funcs,
		  struct drm_driver *driver,
		  const struct drm_display_mode *mode, unsigned int rotation)
{
	size_t bufsize = mode->vdisplay * mode->hdisplay * sizeof(u16);
	struct tinydrm_device *tdev = &mipi->tinydrm;
	int ret;

	if (!mipi->command)
		return -EINVAL;

	mutex_init(&mipi->cmdlock);

	mipi->tx_buf = devm_kmalloc(dev, bufsize, GFP_KERNEL);
	if (!mipi->tx_buf)
		return -ENOMEM;

	ret = devm_tinydrm_init(dev, tdev, &mipi_dbi_fb_funcs, driver);
	if (ret)
		return ret;

	tdev->fb_dirty = mipi_dbi_fb_dirty;

	/* TODO: Maybe add DRM_MODE_CONNECTOR_SPI */
	ret = tinydrm_display_pipe_init(tdev, pipe_funcs,
					DRM_MODE_CONNECTOR_VIRTUAL,
					mipi_dbi_formats,
					ARRAY_SIZE(mipi_dbi_formats), mode,
					rotation);
	if (ret)
		return ret;

	tdev->drm->mode_config.preferred_depth = 16;
	mipi->rotation = rotation;

	drm_mode_config_reset(tdev->drm);

	DRM_DEBUG_KMS("preferred_depth=%u, rotation = %u\n",
		      tdev->drm->mode_config.preferred_depth, rotation);

	return 0;
}

void mipi_dbi_hw_reset(struct mipi_dbi *mipi)
{
	if (!mipi->reset)
		return;

	gpiod_set_value_cansleep(mipi->reset, 0);
	usleep_range(20, 1000);
	gpiod_set_value_cansleep(mipi->reset, 1);
	msleep(120);
}

bool mipi_dbi_display_is_on(struct mipi_dbi *mipi)
{
	u8 val;

	if (mipi_dbi_command_read(mipi, MIPI_DCS_GET_POWER_MODE, &val))
		return false;

	val &= ~DCS_POWER_MODE_RESERVED_MASK;

	/* The poweron/reset value is 08h DCS_POWER_MODE_DISPLAY_NORMAL_MODE */
	if (val != (DCS_POWER_MODE_DISPLAY |
	    DCS_POWER_MODE_DISPLAY_NORMAL_MODE | DCS_POWER_MODE_SLEEP_MODE))
		return false;

	DRM_DEBUG_DRIVER("Display is ON\n");

	return true;
}

__attribute__((used)) static int mipi_dbi_poweron_reset_conditional(struct mipi_dbi *mipi, bool cond)
{
	struct device *dev = mipi->tinydrm.drm->dev;
	int ret;

	if (mipi->regulator) {
		ret = regulator_enable(mipi->regulator);
		if (ret) {
			DRM_DEV_ERROR(dev, "Failed to enable regulator (%d)\n", ret);
			return ret;
		}
	}

	if (cond && mipi_dbi_display_is_on(mipi))
		return 1;

	mipi_dbi_hw_reset(mipi);
	ret = mipi_dbi_command(mipi, MIPI_DCS_SOFT_RESET);
	if (ret) {
		DRM_DEV_ERROR(dev, "Failed to send reset command (%d)\n", ret);
		if (mipi->regulator)
			regulator_disable(mipi->regulator);
		return ret;
	}

	/*
	 * If we did a hw reset, we know the controller is in Sleep mode and
	 * per MIPI DSC spec should wait 5ms after soft reset. If we didn't,
	 * we assume worst case and wait 120ms.
	 */
	if (mipi->reset)
		usleep_range(5000, 20000);
	else
		msleep(120);

	return 0;
}

int mipi_dbi_poweron_reset(struct mipi_dbi *mipi)
{
	return mipi_dbi_poweron_reset_conditional(mipi, false);
}

int mipi_dbi_poweron_conditional_reset(struct mipi_dbi *mipi)
{
	return mipi_dbi_poweron_reset_conditional(mipi, true);
}

