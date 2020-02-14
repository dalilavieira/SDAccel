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
typedef  int u16 ;
struct tinydrm_device {int (* fb_dirty ) (struct drm_framebuffer*,struct drm_file*,unsigned int,unsigned int,struct drm_clip_rect*,unsigned int) ;TYPE_5__* drm; } ;
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct mipi_dbi {int swap_bytes; int enabled; int rotation; int (* command ) (struct mipi_dbi*,int,int*,size_t) ;struct tinydrm_device tinydrm; struct gpio_desc* reset; void* tx_buf; int /*<<< orphan*/  cmdlock; int /*<<< orphan*/  dc; struct spi_device* spi; } ;
struct gpio_desc {int dummy; } ;
struct drm_simple_display_pipe_funcs {int dummy; } ;
struct drm_simple_display_pipe {int dummy; } ;
struct drm_plane_state {int dummy; } ;
struct drm_gem_cma_object {void* vaddr; } ;
struct TYPE_6__ {int /*<<< orphan*/  id; } ;
struct drm_framebuffer {int width; int height; TYPE_2__* format; TYPE_1__ base; TYPE_4__* dev; } ;
struct drm_file {int dummy; } ;
struct drm_driver {int dummy; } ;
struct drm_display_mode {int vdisplay; int hdisplay; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_clip_rect {int x1; int x2; int y1; int y2; } ;
struct TYPE_8__ {int preferred_depth; } ;
struct TYPE_10__ {TYPE_3__ mode_config; struct device* dev; } ;
struct TYPE_9__ {struct tinydrm_device* dev_private; } ;
struct TYPE_7__ {scalar_t__ format; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DRM_DEBUG (char*,int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,...) ; 
 int /*<<< orphan*/  DRM_DEV_ERROR (struct device*,char*,...) ; 
 scalar_t__ DRM_FORMAT_XRGB8888 ; 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_VIRTUAL ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 int ILI9225_BLANK_PERIOD_CONTROL_1 ; 
 int ILI9225_DISPLAY_CONTROL_1 ; 
 int ILI9225_DRIVER_OUTPUT_CONTROL ; 
 int ILI9225_ENTRY_MODE ; 
 int ILI9225_FRAME_CYCLE_CONTROL ; 
 int ILI9225_GAMMA_CONTROL_1 ; 
 int ILI9225_GAMMA_CONTROL_10 ; 
 int ILI9225_GAMMA_CONTROL_2 ; 
 int ILI9225_GAMMA_CONTROL_3 ; 
 int ILI9225_GAMMA_CONTROL_4 ; 
 int ILI9225_GAMMA_CONTROL_5 ; 
 int ILI9225_GAMMA_CONTROL_6 ; 
 int ILI9225_GAMMA_CONTROL_7 ; 
 int ILI9225_GAMMA_CONTROL_8 ; 
 int ILI9225_GAMMA_CONTROL_9 ; 
 int ILI9225_GATE_SCAN_CONTROL ; 
 int ILI9225_HORIZ_WINDOW_ADDR_1 ; 
 int ILI9225_HORIZ_WINDOW_ADDR_2 ; 
 int ILI9225_INTERFACE_CONTROL ; 
 int ILI9225_LCD_AC_DRIVING_CONTROL ; 
 int ILI9225_OSCILLATION_CONTROL ; 
 int ILI9225_PARTIAL_DRIVING_POS_1 ; 
 int ILI9225_PARTIAL_DRIVING_POS_2 ; 
 int ILI9225_POWER_CONTROL_1 ; 
 int ILI9225_POWER_CONTROL_2 ; 
 int ILI9225_POWER_CONTROL_3 ; 
 int ILI9225_POWER_CONTROL_4 ; 
 int ILI9225_POWER_CONTROL_5 ; 
 int ILI9225_RAM_ADDRESS_SET_1 ; 
 int ILI9225_RAM_ADDRESS_SET_2 ; 
 int ILI9225_VCI_RECYCLING ; 
 int ILI9225_VERTICAL_SCROLL_1 ; 
 int ILI9225_VERTICAL_SCROLL_2 ; 
 int ILI9225_VERTICAL_SCROLL_3 ; 
 int ILI9225_VERT_WINDOW_ADDR_1 ; 
 int ILI9225_VERT_WINDOW_ADDR_2 ; 
 int ILI9225_WRITE_DATA_TO_GRAM ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int PTR_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  device_property_read_u32 (struct device*,char*,unsigned int*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_kmalloc (struct device*,size_t,int /*<<< orphan*/ ) ; 
 struct mipi_dbi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_tinydrm_init (struct device*,struct tinydrm_device*,int /*<<< orphan*/ *,struct drm_driver*) ; 
 int devm_tinydrm_register (struct tinydrm_device*) ; 
 struct drm_gem_cma_object* drm_fb_cma_get_gem_obj (struct drm_framebuffer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_mode_config_reset (TYPE_5__*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 struct drm_driver ili9225_driver ; 
 int /*<<< orphan*/  ili9225_fb_funcs ; 
 int /*<<< orphan*/  ili9225_formats ; 
 struct drm_display_mode ili9225_mode ; 
 struct drm_simple_display_pipe_funcs ili9225_pipe_funcs ; 
 int mipi_dbi_buf_copy (void*,struct drm_framebuffer*,struct drm_clip_rect*,int) ; 
 int mipi_dbi_command_buf (struct mipi_dbi*,int,void*,int) ; 
 int /*<<< orphan*/  mipi_dbi_enable_flush (struct mipi_dbi*,struct drm_crtc_state*,struct drm_plane_state*) ; 
 struct mipi_dbi* mipi_dbi_from_tinydrm (struct tinydrm_device*) ; 
 int /*<<< orphan*/  mipi_dbi_hw_reset (struct mipi_dbi*) ; 
 unsigned int mipi_dbi_spi_cmd_max_speed (struct spi_device*,size_t) ; 
 int mipi_dbi_spi_init (struct spi_device*,struct mipi_dbi*,struct gpio_desc*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 struct tinydrm_device* pipe_to_tinydrm (struct drm_simple_display_pipe*) ; 
 struct mipi_dbi* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct mipi_dbi*) ; 
 int tinydrm_display_pipe_init (struct tinydrm_device*,struct drm_simple_display_pipe_funcs const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct drm_display_mode const*,unsigned int) ; 
 int tinydrm_merge_clips (struct drm_clip_rect*,struct drm_clip_rect*,unsigned int,unsigned int,int,int) ; 
 int /*<<< orphan*/  tinydrm_shutdown (struct tinydrm_device*) ; 
 int tinydrm_spi_transfer (struct spi_device*,unsigned int,int /*<<< orphan*/ *,unsigned int,int*,size_t) ; 

__attribute__((used)) static inline int ili9225_command(struct mipi_dbi *mipi, u8 cmd, u16 data)
{
	u8 par[2] = { data >> 8, data & 0xff };

	return mipi_dbi_command_buf(mipi, cmd, par, 2);
}

__attribute__((used)) static int ili9225_fb_dirty(struct drm_framebuffer *fb,
			    struct drm_file *file_priv, unsigned int flags,
			    unsigned int color, struct drm_clip_rect *clips,
			    unsigned int num_clips)
{
	struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
	struct tinydrm_device *tdev = fb->dev->dev_private;
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
	bool swap = mipi->swap_bytes;
	struct drm_clip_rect clip;
	u16 x_start, y_start;
	u16 x1, x2, y1, y2;
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

	switch (mipi->rotation) {
	default:
		x1 = clip.x1;
		x2 = clip.x2 - 1;
		y1 = clip.y1;
		y2 = clip.y2 - 1;
		x_start = x1;
		y_start = y1;
		break;
	case 90:
		x1 = clip.y1;
		x2 = clip.y2 - 1;
		y1 = fb->width - clip.x2;
		y2 = fb->width - clip.x1 - 1;
		x_start = x1;
		y_start = y2;
		break;
	case 180:
		x1 = fb->width - clip.x2;
		x2 = fb->width - clip.x1 - 1;
		y1 = fb->height - clip.y2;
		y2 = fb->height - clip.y1 - 1;
		x_start = x2;
		y_start = y2;
		break;
	case 270:
		x1 = fb->height - clip.y2;
		x2 = fb->height - clip.y1 - 1;
		y1 = clip.x1;
		y2 = clip.x2 - 1;
		x_start = x2;
		y_start = y1;
		break;
	}

	ili9225_command(mipi, ILI9225_HORIZ_WINDOW_ADDR_1, x2);
	ili9225_command(mipi, ILI9225_HORIZ_WINDOW_ADDR_2, x1);
	ili9225_command(mipi, ILI9225_VERT_WINDOW_ADDR_1, y2);
	ili9225_command(mipi, ILI9225_VERT_WINDOW_ADDR_2, y1);

	ili9225_command(mipi, ILI9225_RAM_ADDRESS_SET_1, x_start);
	ili9225_command(mipi, ILI9225_RAM_ADDRESS_SET_2, y_start);

	ret = mipi_dbi_command_buf(mipi, ILI9225_WRITE_DATA_TO_GRAM, tr,
				(clip.x2 - clip.x1) * (clip.y2 - clip.y1) * 2);

	return ret;
}

__attribute__((used)) static void ili9225_pipe_enable(struct drm_simple_display_pipe *pipe,
				struct drm_crtc_state *crtc_state,
				struct drm_plane_state *plane_state)
{
	struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
	struct device *dev = tdev->drm->dev;
	int ret;
	u8 am_id;

	DRM_DEBUG_KMS("\n");

	mipi_dbi_hw_reset(mipi);

	/*
	 * There don't seem to be two example init sequences that match, so
	 * using the one from the popular Arduino library for this display.
	 * https://github.com/Nkawu/TFT_22_ILI9225/blob/master/src/TFT_22_ILI9225.cpp
	 */

	ret = ili9225_command(mipi, ILI9225_POWER_CONTROL_1, 0x0000);
	if (ret) {
		DRM_DEV_ERROR(dev, "Error sending command %d\n", ret);
		return;
	}
	ili9225_command(mipi, ILI9225_POWER_CONTROL_2, 0x0000);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_3, 0x0000);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_4, 0x0000);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_5, 0x0000);

	msleep(40);

	ili9225_command(mipi, ILI9225_POWER_CONTROL_2, 0x0018);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_3, 0x6121);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_4, 0x006f);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_5, 0x495f);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_1, 0x0800);

	msleep(10);

	ili9225_command(mipi, ILI9225_POWER_CONTROL_2, 0x103b);

	msleep(50);

	switch (mipi->rotation) {
	default:
		am_id = 0x30;
		break;
	case 90:
		am_id = 0x18;
		break;
	case 180:
		am_id = 0x00;
		break;
	case 270:
		am_id = 0x28;
		break;
	}
	ili9225_command(mipi, ILI9225_DRIVER_OUTPUT_CONTROL, 0x011c);
	ili9225_command(mipi, ILI9225_LCD_AC_DRIVING_CONTROL, 0x0100);
	ili9225_command(mipi, ILI9225_ENTRY_MODE, 0x1000 | am_id);
	ili9225_command(mipi, ILI9225_DISPLAY_CONTROL_1, 0x0000);
	ili9225_command(mipi, ILI9225_BLANK_PERIOD_CONTROL_1, 0x0808);
	ili9225_command(mipi, ILI9225_FRAME_CYCLE_CONTROL, 0x1100);
	ili9225_command(mipi, ILI9225_INTERFACE_CONTROL, 0x0000);
	ili9225_command(mipi, ILI9225_OSCILLATION_CONTROL, 0x0d01);
	ili9225_command(mipi, ILI9225_VCI_RECYCLING, 0x0020);
	ili9225_command(mipi, ILI9225_RAM_ADDRESS_SET_1, 0x0000);
	ili9225_command(mipi, ILI9225_RAM_ADDRESS_SET_2, 0x0000);

	ili9225_command(mipi, ILI9225_GATE_SCAN_CONTROL, 0x0000);
	ili9225_command(mipi, ILI9225_VERTICAL_SCROLL_1, 0x00db);
	ili9225_command(mipi, ILI9225_VERTICAL_SCROLL_2, 0x0000);
	ili9225_command(mipi, ILI9225_VERTICAL_SCROLL_3, 0x0000);
	ili9225_command(mipi, ILI9225_PARTIAL_DRIVING_POS_1, 0x00db);
	ili9225_command(mipi, ILI9225_PARTIAL_DRIVING_POS_2, 0x0000);

	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_1, 0x0000);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_2, 0x0808);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_3, 0x080a);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_4, 0x000a);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_5, 0x0a08);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_6, 0x0808);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_7, 0x0000);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_8, 0x0a00);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_9, 0x0710);
	ili9225_command(mipi, ILI9225_GAMMA_CONTROL_10, 0x0710);

	ili9225_command(mipi, ILI9225_DISPLAY_CONTROL_1, 0x0012);

	msleep(50);

	ili9225_command(mipi, ILI9225_DISPLAY_CONTROL_1, 0x1017);

	mipi_dbi_enable_flush(mipi, crtc_state, plane_state);
}

__attribute__((used)) static void ili9225_pipe_disable(struct drm_simple_display_pipe *pipe)
{
	struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
	struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);

	DRM_DEBUG_KMS("\n");

	if (!mipi->enabled)
		return;

	ili9225_command(mipi, ILI9225_DISPLAY_CONTROL_1, 0x0000);
	msleep(50);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_2, 0x0007);
	msleep(50);
	ili9225_command(mipi, ILI9225_POWER_CONTROL_1, 0x0a02);

	mipi->enabled = false;
}

__attribute__((used)) static int ili9225_dbi_command(struct mipi_dbi *mipi, u8 cmd, u8 *par,
			       size_t num)
{
	struct spi_device *spi = mipi->spi;
	unsigned int bpw = 8;
	u32 speed_hz;
	int ret;

	gpiod_set_value_cansleep(mipi->dc, 0);
	speed_hz = mipi_dbi_spi_cmd_max_speed(spi, 1);
	ret = tinydrm_spi_transfer(spi, speed_hz, NULL, 8, &cmd, 1);
	if (ret || !num)
		return ret;

	if (cmd == ILI9225_WRITE_DATA_TO_GRAM && !mipi->swap_bytes)
		bpw = 16;

	gpiod_set_value_cansleep(mipi->dc, 1);
	speed_hz = mipi_dbi_spi_cmd_max_speed(spi, num);

	return tinydrm_spi_transfer(spi, speed_hz, NULL, bpw, par, num);
}

__attribute__((used)) static int ili9225_init(struct device *dev, struct mipi_dbi *mipi,
			const struct drm_simple_display_pipe_funcs *pipe_funcs,
			struct drm_driver *driver,
			const struct drm_display_mode *mode,
			unsigned int rotation)
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

	ret = devm_tinydrm_init(dev, tdev, &ili9225_fb_funcs, driver);
	if (ret)
		return ret;

	tdev->fb_dirty = ili9225_fb_dirty;

	ret = tinydrm_display_pipe_init(tdev, pipe_funcs,
					DRM_MODE_CONNECTOR_VIRTUAL,
					ili9225_formats,
					ARRAY_SIZE(ili9225_formats), mode,
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

__attribute__((used)) static int ili9225_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	struct mipi_dbi *mipi;
	struct gpio_desc *rs;
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

	rs = devm_gpiod_get(dev, "rs", GPIOD_OUT_LOW);
	if (IS_ERR(rs)) {
		DRM_DEV_ERROR(dev, "Failed to get gpio 'rs'\n");
		return PTR_ERR(rs);
	}

	device_property_read_u32(dev, "rotation", &rotation);

	ret = mipi_dbi_spi_init(spi, mipi, rs);
	if (ret)
		return ret;

	/* override the command function set in  mipi_dbi_spi_init() */
	mipi->command = ili9225_dbi_command;

	ret = ili9225_init(&spi->dev, mipi, &ili9225_pipe_funcs,
			   &ili9225_driver, &ili9225_mode, rotation);
	if (ret)
		return ret;

	spi_set_drvdata(spi, mipi);

	return devm_tinydrm_register(&mipi->tinydrm);
}

__attribute__((used)) static void ili9225_shutdown(struct spi_device *spi)
{
	struct mipi_dbi *mipi = spi_get_drvdata(spi);

	tinydrm_shutdown(&mipi->tinydrm);
}

