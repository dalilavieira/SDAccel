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
typedef  int u8 ;
typedef  unsigned int u32 ;
struct tinydrm_device {int (* fb_dirty ) (struct drm_framebuffer*,struct drm_file*,unsigned int,unsigned int,struct drm_clip_rect*,unsigned int) ;TYPE_5__* drm; } ;
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct mipi_dbi {int enabled; int rotation; int swap_bytes; struct tinydrm_device tinydrm; int /*<<< orphan*/ * read_commands; struct gpio_desc* reset; void* tx_buf; int /*<<< orphan*/  cmdlock; } ;
struct gpio_desc {int dummy; } ;
struct drm_simple_display_pipe_funcs {int dummy; } ;
struct drm_simple_display_pipe {int dummy; } ;
struct drm_plane_state {int dummy; } ;
struct TYPE_7__ {struct dma_buf_attachment* import_attach; } ;
struct drm_gem_cma_object {void* vaddr; TYPE_2__ base; } ;
struct TYPE_9__ {int /*<<< orphan*/  id; } ;
struct drm_framebuffer {TYPE_4__ base; int /*<<< orphan*/  height; int /*<<< orphan*/  width; TYPE_3__* dev; } ;
struct drm_file {int dummy; } ;
struct drm_driver {int dummy; } ;
struct drm_display_mode {int vdisplay; int hdisplay; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_clip_rect {size_t x2; size_t x1; size_t y2; size_t y1; } ;
struct dma_buf_attachment {int /*<<< orphan*/  dmabuf; } ;
struct TYPE_6__ {int preferred_depth; } ;
struct TYPE_10__ {TYPE_1__ mode_config; } ;
struct TYPE_8__ {struct tinydrm_device* dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMA_FROM_DEVICE ; 
 int /*<<< orphan*/  DRM_DEBUG (char*,int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,...) ; 
 int /*<<< orphan*/  DRM_DEV_ERROR (struct device*,char*) ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_VIRTUAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  MIPI_DCS_EXIT_INVERT_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_EXIT_SLEEP_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_ADDRESS_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_COLUMN_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_DISPLAY_OFF ; 
 int /*<<< orphan*/  MIPI_DCS_SET_DISPLAY_ON ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PAGE_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PARTIAL_AREA ; 
 int /*<<< orphan*/  MIPI_DCS_WRITE_MEMORY_START ; 
 int PTR_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  ST7586_AUTO_READ_CTRL ; 
 int ST7586_DISP_CTRL_MX ; 
 int ST7586_DISP_CTRL_MY ; 
 int /*<<< orphan*/  ST7586_DISP_MODE_GRAY ; 
 int /*<<< orphan*/  ST7586_ENABLE_ANALOG ; 
 int /*<<< orphan*/  ST7586_ENABLE_DDRAM ; 
 int /*<<< orphan*/  ST7586_OTP_CTRL_OUT ; 
 int /*<<< orphan*/  ST7586_OTP_READ ; 
 int /*<<< orphan*/  ST7586_OTP_RW_CTRL ; 
 int /*<<< orphan*/  ST7586_SET_BIAS_SYSTEM ; 
 int /*<<< orphan*/  ST7586_SET_BOOST_LEVEL ; 
 int /*<<< orphan*/  ST7586_SET_DISP_DUTY ; 
 int /*<<< orphan*/  ST7586_SET_NLINE_INV ; 
 int /*<<< orphan*/  ST7586_SET_PART_DISP ; 
 int /*<<< orphan*/  ST7586_SET_VOP ; 
 int /*<<< orphan*/  ST7586_SET_VOP_OFFSET ; 
 int /*<<< orphan*/  device_property_read_u32 (struct device*,char*,unsigned int*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_kmalloc (struct device*,size_t,int /*<<< orphan*/ ) ; 
 struct mipi_dbi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_tinydrm_init (struct device*,struct tinydrm_device*,int /*<<< orphan*/ *,struct drm_driver*) ; 
 int devm_tinydrm_register (struct tinydrm_device*) ; 
 int dma_buf_begin_cpu_access (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dma_buf_end_cpu_access (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct drm_gem_cma_object* drm_fb_cma_get_gem_obj (struct drm_framebuffer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_mode_config_reset (TYPE_5__*) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mipi_dbi_command (struct mipi_dbi*,int /*<<< orphan*/ ,...) ; 
 int mipi_dbi_command_buf (struct mipi_dbi*,int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  mipi_dbi_enable_flush (struct mipi_dbi*,struct drm_crtc_state*,struct drm_plane_state*) ; 
 struct mipi_dbi* mipi_dbi_from_tinydrm (struct tinydrm_device*) ; 
 int mipi_dbi_poweron_reset (struct mipi_dbi*) ; 
 int mipi_dbi_spi_init (struct spi_device*,struct mipi_dbi*,struct gpio_desc*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 struct tinydrm_device* pipe_to_tinydrm (struct drm_simple_display_pipe*) ; 
 unsigned int rounddown (unsigned int,int) ; 
 unsigned int roundup (unsigned int,int) ; 
 struct mipi_dbi* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct mipi_dbi*) ; 
 struct drm_driver st7586_driver ; 
 int /*<<< orphan*/  st7586_fb_funcs ; 
 int /*<<< orphan*/  st7586_formats ; 
 int* st7586_lookup ; 
 struct drm_display_mode st7586_mode ; 
 struct drm_simple_display_pipe_funcs st7586_pipe_funcs ; 
 int tinydrm_display_pipe_init (struct tinydrm_device*,struct drm_simple_display_pipe_funcs const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct drm_display_mode const*,unsigned int) ; 
 int /*<<< orphan*/  tinydrm_merge_clips (struct drm_clip_rect*,struct drm_clip_rect*,unsigned int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tinydrm_shutdown (struct tinydrm_device*) ; 
 int /*<<< orphan*/  tinydrm_xrgb8888_to_gray8 (int*,void*,struct drm_framebuffer*,struct drm_clip_rect*) ; 

__attribute__((used)) static void st7586_xrgb8888_to_gray332(u8 *dst, void *vaddr,
				       struct drm_framebuffer *fb,
				       struct drm_clip_rect *clip)
{
	size_t len = (clip->x2 - clip->x1) * (clip->y2 - clip->y1);
	unsigned int x, y;
	u8 *src, *buf, val;

	buf = kmalloc(len, GFP_KERNEL);
	if (!buf)
		return;

	tinydrm_xrgb8888_to_gray8(buf, vaddr, fb, clip);
	src = buf;

	for (y = clip->y1; y < clip->y2; y++) {
		for (x = clip->x1; x < clip->x2; x += 3) {
			val = st7586_lookup[*src++ >> 6] << 5;
			val |= st7586_lookup[*src++ >> 6] << 2;
			val |= st7586_lookup[*src++ >> 6] >> 1;
			*dst++ = val;
		}
	}

	kfree(buf);
}

__attribute__((used)) static int st7586_buf_copy(void *dst, struct drm_framebuffer *fb,
			   struct drm_clip_rect *clip)
{
	struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
	struct dma_buf_attachment *import_attach = cma_obj->base.import_attach;
	void *src = cma_obj->vaddr;
	int ret = 0;

	if (import_attach) {
		ret = dma_buf_begin_cpu_access(import_attach->dmabuf,
					       DMA_FROM_DEVICE);
		if (ret)
			return ret;
	}

	st7586_xrgb8888_to_gray332(dst, src, fb, clip);

	if (import_attach)
		ret = dma_buf_end_cpu_access(import_attach->dmabuf,
					     DMA_FROM_DEVICE);

	return ret;
}

__attribute__((used)) static int st7586_fb_dirty(struct drm_framebuffer *fb,
			   struct drm_file *file_priv, unsigned int flags,
			   unsigned int color, struct drm_clip_rect *clips,
			   unsigned int num_clips)
{
	struct tinydrm_device *tdev = fb->dev->dev_private;
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
	struct drm_clip_rect clip;
	int start, end;
	int ret = 0;

	if (!mipi->enabled)
		return 0;

	tinydrm_merge_clips(&clip, clips, num_clips, flags, fb->width,
			    fb->height);

	/* 3 pixels per byte, so grow clip to nearest multiple of 3 */
	clip.x1 = rounddown(clip.x1, 3);
	clip.x2 = roundup(clip.x2, 3);

	DRM_DEBUG("Flushing [FB:%d] x1=%u, x2=%u, y1=%u, y2=%u\n", fb->base.id,
		  clip.x1, clip.x2, clip.y1, clip.y2);

	ret = st7586_buf_copy(mipi->tx_buf, fb, &clip);
	if (ret)
		return ret;

	/* Pixels are packed 3 per byte */
	start = clip.x1 / 3;
	end = clip.x2 / 3;

	mipi_dbi_command(mipi, MIPI_DCS_SET_COLUMN_ADDRESS,
			 (start >> 8) & 0xFF, start & 0xFF,
			 (end >> 8) & 0xFF, (end - 1) & 0xFF);
	mipi_dbi_command(mipi, MIPI_DCS_SET_PAGE_ADDRESS,
			 (clip.y1 >> 8) & 0xFF, clip.y1 & 0xFF,
			 (clip.y2 >> 8) & 0xFF, (clip.y2 - 1) & 0xFF);

	ret = mipi_dbi_command_buf(mipi, MIPI_DCS_WRITE_MEMORY_START,
				   (u8 *)mipi->tx_buf,
				   (end - start) * (clip.y2 - clip.y1));

	return ret;
}

__attribute__((used)) static void st7586_pipe_enable(struct drm_simple_display_pipe *pipe,
			       struct drm_crtc_state *crtc_state,
			       struct drm_plane_state *plane_state)
{
	struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
	int ret;
	u8 addr_mode;

	DRM_DEBUG_KMS("\n");

	ret = mipi_dbi_poweron_reset(mipi);
	if (ret)
		return;

	mipi_dbi_command(mipi, ST7586_AUTO_READ_CTRL, 0x9f);
	mipi_dbi_command(mipi, ST7586_OTP_RW_CTRL, 0x00);

	msleep(10);

	mipi_dbi_command(mipi, ST7586_OTP_READ);

	msleep(20);

	mipi_dbi_command(mipi, ST7586_OTP_CTRL_OUT);
	mipi_dbi_command(mipi, MIPI_DCS_EXIT_SLEEP_MODE);
	mipi_dbi_command(mipi, MIPI_DCS_SET_DISPLAY_OFF);

	msleep(50);

	mipi_dbi_command(mipi, ST7586_SET_VOP_OFFSET, 0x00);
	mipi_dbi_command(mipi, ST7586_SET_VOP, 0xe3, 0x00);
	mipi_dbi_command(mipi, ST7586_SET_BIAS_SYSTEM, 0x02);
	mipi_dbi_command(mipi, ST7586_SET_BOOST_LEVEL, 0x04);
	mipi_dbi_command(mipi, ST7586_ENABLE_ANALOG, 0x1d);
	mipi_dbi_command(mipi, ST7586_SET_NLINE_INV, 0x00);
	mipi_dbi_command(mipi, ST7586_DISP_MODE_GRAY);
	mipi_dbi_command(mipi, ST7586_ENABLE_DDRAM, 0x02);

	switch (mipi->rotation) {
	default:
		addr_mode = 0x00;
		break;
	case 90:
		addr_mode = ST7586_DISP_CTRL_MY;
		break;
	case 180:
		addr_mode = ST7586_DISP_CTRL_MX | ST7586_DISP_CTRL_MY;
		break;
	case 270:
		addr_mode = ST7586_DISP_CTRL_MX;
		break;
	}
	mipi_dbi_command(mipi, MIPI_DCS_SET_ADDRESS_MODE, addr_mode);

	mipi_dbi_command(mipi, ST7586_SET_DISP_DUTY, 0x7f);
	mipi_dbi_command(mipi, ST7586_SET_PART_DISP, 0xa0);
	mipi_dbi_command(mipi, MIPI_DCS_SET_PARTIAL_AREA, 0x00, 0x00, 0x00, 0x77);
	mipi_dbi_command(mipi, MIPI_DCS_EXIT_INVERT_MODE);

	msleep(100);

	mipi_dbi_command(mipi, MIPI_DCS_SET_DISPLAY_ON);

	mipi_dbi_enable_flush(mipi, crtc_state, plane_state);
}

__attribute__((used)) static void st7586_pipe_disable(struct drm_simple_display_pipe *pipe)
{
	struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);

	DRM_DEBUG_KMS("\n");

	if (!mipi->enabled)
		return;

	mipi_dbi_command(mipi, MIPI_DCS_SET_DISPLAY_OFF);
	mipi->enabled = false;
}

__attribute__((used)) static int st7586_init(struct device *dev, struct mipi_dbi *mipi,
		const struct drm_simple_display_pipe_funcs *pipe_funcs,
		struct drm_driver *driver, const struct drm_display_mode *mode,
		unsigned int rotation)
{
	size_t bufsize = (mode->vdisplay + 2) / 3 * mode->hdisplay;
	struct tinydrm_device *tdev = &mipi->tinydrm;
	int ret;

	mutex_init(&mipi->cmdlock);

	mipi->tx_buf = devm_kmalloc(dev, bufsize, GFP_KERNEL);
	if (!mipi->tx_buf)
		return -ENOMEM;

	ret = devm_tinydrm_init(dev, tdev, &st7586_fb_funcs, driver);
	if (ret)
		return ret;

	tdev->fb_dirty = st7586_fb_dirty;

	ret = tinydrm_display_pipe_init(tdev, pipe_funcs,
					DRM_MODE_CONNECTOR_VIRTUAL,
					st7586_formats,
					ARRAY_SIZE(st7586_formats),
					mode, rotation);
	if (ret)
		return ret;

	tdev->drm->mode_config.preferred_depth = 32;
	mipi->rotation = rotation;

	drm_mode_config_reset(tdev->drm);

	DRM_DEBUG_KMS("preferred_depth=%u, rotation = %u\n",
		      tdev->drm->mode_config.preferred_depth, rotation);

	return 0;
}

__attribute__((used)) static int st7586_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	struct mipi_dbi *mipi;
	struct gpio_desc *a0;
	u32 rotation = 0;
	int ret;

	mipi = devm_kzalloc(dev, sizeof(*mipi), GFP_KERNEL);
	if (!mipi)
		return -ENOMEM;

	mipi->reset = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(mipi->reset)) {
		DRM_DEV_ERROR(dev, "Failed to get gpio 'reset'\n");
		return PTR_ERR(mipi->reset);
	}

	a0 = devm_gpiod_get(dev, "a0", GPIOD_OUT_LOW);
	if (IS_ERR(a0)) {
		DRM_DEV_ERROR(dev, "Failed to get gpio 'a0'\n");
		return PTR_ERR(a0);
	}

	device_property_read_u32(dev, "rotation", &rotation);

	ret = mipi_dbi_spi_init(spi, mipi, a0);
	if (ret)
		return ret;

	/* Cannot read from this controller via SPI */
	mipi->read_commands = NULL;

	/*
	 * we are using 8-bit data, so we are not actually swapping anything,
	 * but setting mipi->swap_bytes makes mipi_dbi_typec3_command() do the
	 * right thing and not use 16-bit transfers (which results in swapped
	 * bytes on little-endian systems and causes out of order data to be
	 * sent to the display).
	 */
	mipi->swap_bytes = true;

	ret = st7586_init(&spi->dev, mipi, &st7586_pipe_funcs, &st7586_driver,
			  &st7586_mode, rotation);
	if (ret)
		return ret;

	spi_set_drvdata(spi, mipi);

	return devm_tinydrm_register(&mipi->tinydrm);
}

__attribute__((used)) static void st7586_shutdown(struct spi_device *spi)
{
	struct mipi_dbi *mipi = spi_get_drvdata(spi);

	tinydrm_shutdown(&mipi->tinydrm);
}

