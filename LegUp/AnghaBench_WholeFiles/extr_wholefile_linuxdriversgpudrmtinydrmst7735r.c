#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct tinydrm_device {int dummy; } ;
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct mipi_dbi {int rotation; int /*<<< orphan*/  tinydrm; int /*<<< orphan*/ * read_commands; struct gpio_desc* backlight; struct gpio_desc* reset; } ;
struct gpio_desc {int dummy; } ;
struct drm_simple_display_pipe {int dummy; } ;
struct drm_plane_state {int dummy; } ;
struct drm_crtc_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*) ; 
 int /*<<< orphan*/  DRM_DEV_ERROR (struct device*,char*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  MIPI_DCS_ENTER_NORMAL_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_EXIT_INVERT_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_EXIT_SLEEP_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_PIXEL_FMT_16BIT ; 
 int /*<<< orphan*/  MIPI_DCS_SET_ADDRESS_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_DISPLAY_ON ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PIXEL_FORMAT ; 
 int PTR_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  ST7735R_FRMCTR1 ; 
 int /*<<< orphan*/  ST7735R_FRMCTR2 ; 
 int /*<<< orphan*/  ST7735R_FRMCTR3 ; 
 int /*<<< orphan*/  ST7735R_GAMCTRN1 ; 
 int /*<<< orphan*/  ST7735R_GAMCTRP1 ; 
 int /*<<< orphan*/  ST7735R_INVCTR ; 
 int ST7735R_MV ; 
 int ST7735R_MX ; 
 int ST7735R_MY ; 
 int /*<<< orphan*/  ST7735R_PWCTR1 ; 
 int /*<<< orphan*/  ST7735R_PWCTR2 ; 
 int /*<<< orphan*/  ST7735R_PWCTR3 ; 
 int /*<<< orphan*/  ST7735R_PWCTR4 ; 
 int /*<<< orphan*/  ST7735R_PWCTR5 ; 
 int /*<<< orphan*/  ST7735R_VMCTR1 ; 
 int /*<<< orphan*/  device_property_read_u32 (struct device*,char*,int /*<<< orphan*/ *) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct mipi_dbi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct gpio_desc* devm_of_find_backlight (struct device*) ; 
 int devm_tinydrm_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jd_t18003_t01_mode ; 
 int /*<<< orphan*/  jd_t18003_t01_pipe_funcs ; 
 int /*<<< orphan*/  mipi_dbi_command (struct mipi_dbi*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  mipi_dbi_enable_flush (struct mipi_dbi*,struct drm_crtc_state*,struct drm_plane_state*) ; 
 struct mipi_dbi* mipi_dbi_from_tinydrm (struct tinydrm_device*) ; 
 int mipi_dbi_init (struct device*,struct mipi_dbi*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int mipi_dbi_poweron_reset (struct mipi_dbi*) ; 
 int mipi_dbi_spi_init (struct spi_device*,struct mipi_dbi*,struct gpio_desc*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct tinydrm_device* pipe_to_tinydrm (struct drm_simple_display_pipe*) ; 
 struct mipi_dbi* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct mipi_dbi*) ; 
 int /*<<< orphan*/  st7735r_driver ; 
 int /*<<< orphan*/  tinydrm_shutdown (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void jd_t18003_t01_pipe_enable(struct drm_simple_display_pipe *pipe,
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

	msleep(150);

	mipi_dbi_command(mipi, MIPI_DCS_EXIT_SLEEP_MODE);
	msleep(500);

	mipi_dbi_command(mipi, ST7735R_FRMCTR1, 0x01, 0x2c, 0x2d);
	mipi_dbi_command(mipi, ST7735R_FRMCTR2, 0x01, 0x2c, 0x2d);
	mipi_dbi_command(mipi, ST7735R_FRMCTR3, 0x01, 0x2c, 0x2d, 0x01, 0x2c,
			 0x2d);
	mipi_dbi_command(mipi, ST7735R_INVCTR, 0x07);
	mipi_dbi_command(mipi, ST7735R_PWCTR1, 0xa2, 0x02, 0x84);
	mipi_dbi_command(mipi, ST7735R_PWCTR2, 0xc5);
	mipi_dbi_command(mipi, ST7735R_PWCTR3, 0x0a, 0x00);
	mipi_dbi_command(mipi, ST7735R_PWCTR4, 0x8a, 0x2a);
	mipi_dbi_command(mipi, ST7735R_PWCTR5, 0x8a, 0xee);
	mipi_dbi_command(mipi, ST7735R_VMCTR1, 0x0e);
	mipi_dbi_command(mipi, MIPI_DCS_EXIT_INVERT_MODE);
	switch (mipi->rotation) {
	default:
		addr_mode = ST7735R_MX | ST7735R_MY;
		break;
	case 90:
		addr_mode = ST7735R_MX | ST7735R_MV;
		break;
	case 180:
		addr_mode = 0;
		break;
	case 270:
		addr_mode = ST7735R_MY | ST7735R_MV;
		break;
	}
	mipi_dbi_command(mipi, MIPI_DCS_SET_ADDRESS_MODE, addr_mode);
	mipi_dbi_command(mipi, MIPI_DCS_SET_PIXEL_FORMAT,
			 MIPI_DCS_PIXEL_FMT_16BIT);
	mipi_dbi_command(mipi, ST7735R_GAMCTRP1, 0x02, 0x1c, 0x07, 0x12, 0x37,
			 0x32, 0x29, 0x2d, 0x29, 0x25, 0x2b, 0x39, 0x00, 0x01,
			 0x03, 0x10);
	mipi_dbi_command(mipi, ST7735R_GAMCTRN1, 0x03, 0x1d, 0x07, 0x06, 0x2e,
			 0x2c, 0x29, 0x2d, 0x2e, 0x2e, 0x37, 0x3f, 0x00, 0x00,
			 0x02, 0x10);
	mipi_dbi_command(mipi, MIPI_DCS_SET_DISPLAY_ON);

	msleep(100);

	mipi_dbi_command(mipi, MIPI_DCS_ENTER_NORMAL_MODE);

	msleep(20);

	mipi_dbi_enable_flush(mipi, crtc_state, plane_state);
}

__attribute__((used)) static int st7735r_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	struct mipi_dbi *mipi;
	struct gpio_desc *dc;
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

	dc = devm_gpiod_get(dev, "dc", GPIOD_OUT_LOW);
	if (IS_ERR(dc)) {
		DRM_DEV_ERROR(dev, "Failed to get gpio 'dc'\n");
		return PTR_ERR(dc);
	}

	mipi->backlight = devm_of_find_backlight(dev);
	if (IS_ERR(mipi->backlight))
		return PTR_ERR(mipi->backlight);

	device_property_read_u32(dev, "rotation", &rotation);

	ret = mipi_dbi_spi_init(spi, mipi, dc);
	if (ret)
		return ret;

	/* Cannot read from Adafruit 1.8" display via SPI */
	mipi->read_commands = NULL;

	ret = mipi_dbi_init(&spi->dev, mipi, &jd_t18003_t01_pipe_funcs,
			    &st7735r_driver, &jd_t18003_t01_mode, rotation);
	if (ret)
		return ret;

	spi_set_drvdata(spi, mipi);

	return devm_tinydrm_register(&mipi->tinydrm);
}

__attribute__((used)) static void st7735r_shutdown(struct spi_device *spi)
{
	struct mipi_dbi *mipi = spi_get_drvdata(spi);

	tinydrm_shutdown(&mipi->tinydrm);
}

