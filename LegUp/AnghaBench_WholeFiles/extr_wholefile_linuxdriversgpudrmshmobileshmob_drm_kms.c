#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct shmob_drm_format_info {int fourcc; int bpp; scalar_t__ yuv; } ;
struct TYPE_6__ {int /*<<< orphan*/  encoder; } ;
struct shmob_drm_device {int mmio; TYPE_3__* ddev; TYPE_1__ encoder; } ;
struct drm_mode_fb_cmd2 {int pixel_format; int* pitches; } ;
struct drm_framebuffer {int dummy; } ;
struct drm_file {int dummy; } ;
struct drm_device {int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {int max_width; int max_height; int /*<<< orphan*/ * funcs; scalar_t__ min_height; scalar_t__ min_width; } ;
struct TYPE_8__ {TYPE_2__ mode_config; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct shmob_drm_format_info const*) ; 
 int /*<<< orphan*/  EINVAL ; 
 struct drm_framebuffer* ERR_PTR (int /*<<< orphan*/ ) ; 
 int ETIMEDOUT ; 
 int LCDC_MIRROR_OFFSET ; 
 int LCDC_SIDE_B_OFFSET ; 
 int LDBnBBGCL (int /*<<< orphan*/ ) ; 
 int LDBnBPPCR (int) ; 
#define  LDDFR 145 
#define  LDHAJR 144 
#define  LDHCNR 143 
#define  LDHPDR 142 
#define  LDHSYNR 141 
#define  LDMLSR 140 
#define  LDMT1R 139 
#define  LDMT2R 138 
#define  LDMT3R 137 
#define  LDSA1R 136 
#define  LDSA2R 135 
#define  LDSM1R 134 
#define  LDVLNR 133 
#define  LDVPDR 132 
#define  LDVSYNR 131 
#define  LDWBAR 130 
#define  LDWBCNTR 129 
#define  LDWBFR 128 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 struct drm_framebuffer* drm_gem_fb_create (struct drm_device*,struct drm_file*,struct drm_mode_fb_cmd2 const*) ; 
 int /*<<< orphan*/  drm_helper_disable_unused_functions (TYPE_3__*) ; 
 int /*<<< orphan*/  drm_kms_helper_poll_init (TYPE_3__*) ; 
 int /*<<< orphan*/  drm_mode_config_init (TYPE_3__*) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  shmob_drm_connector_create (struct shmob_drm_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  shmob_drm_crtc_create (struct shmob_drm_device*) ; 
 int /*<<< orphan*/  shmob_drm_encoder_create (struct shmob_drm_device*) ; 
 struct shmob_drm_format_info const* shmob_drm_format_infos ; 
 int /*<<< orphan*/  shmob_drm_mode_config_funcs ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 

__attribute__((used)) static inline bool lcdc_is_banked(u32 reg)
{
	switch (reg) {
	case LDMT1R:
	case LDMT2R:
	case LDMT3R:
	case LDDFR:
	case LDSM1R:
	case LDSA1R:
	case LDSA2R:
	case LDMLSR:
	case LDWBFR:
	case LDWBCNTR:
	case LDWBAR:
	case LDHCNR:
	case LDHSYNR:
	case LDVLNR:
	case LDVSYNR:
	case LDHPDR:
	case LDVPDR:
	case LDHAJR:
		return true;
	default:
		return reg >= LDBnBBGCL(0) && reg <= LDBnBPPCR(3);
	}
}

__attribute__((used)) static inline void lcdc_write_mirror(struct shmob_drm_device *sdev, u32 reg,
				     u32 data)
{
	iowrite32(data, sdev->mmio + reg + LCDC_MIRROR_OFFSET);
}

__attribute__((used)) static inline void lcdc_write(struct shmob_drm_device *sdev, u32 reg, u32 data)
{
	iowrite32(data, sdev->mmio + reg);
	if (lcdc_is_banked(reg))
		iowrite32(data, sdev->mmio + reg + LCDC_SIDE_B_OFFSET);
}

__attribute__((used)) static inline u32 lcdc_read(struct shmob_drm_device *sdev, u32 reg)
{
	return ioread32(sdev->mmio + reg);
}

__attribute__((used)) static inline int lcdc_wait_bit(struct shmob_drm_device *sdev, u32 reg,
				u32 mask, u32 until)
{
	unsigned long timeout = jiffies + msecs_to_jiffies(5);

	while ((lcdc_read(sdev, reg) & mask) != until) {
		if (time_after(jiffies, timeout))
			return -ETIMEDOUT;
		cpu_relax();
	}

	return 0;
}

const struct shmob_drm_format_info *shmob_drm_format_info(u32 fourcc)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(shmob_drm_format_infos); ++i) {
		if (shmob_drm_format_infos[i].fourcc == fourcc)
			return &shmob_drm_format_infos[i];
	}

	return NULL;
}

__attribute__((used)) static struct drm_framebuffer *
shmob_drm_fb_create(struct drm_device *dev, struct drm_file *file_priv,
		    const struct drm_mode_fb_cmd2 *mode_cmd)
{
	const struct shmob_drm_format_info *format;

	format = shmob_drm_format_info(mode_cmd->pixel_format);
	if (format == NULL) {
		dev_dbg(dev->dev, "unsupported pixel format %08x\n",
			mode_cmd->pixel_format);
		return ERR_PTR(-EINVAL);
	}

	if (mode_cmd->pitches[0] & 7 || mode_cmd->pitches[0] >= 65536) {
		dev_dbg(dev->dev, "invalid pitch value %u\n",
			mode_cmd->pitches[0]);
		return ERR_PTR(-EINVAL);
	}

	if (format->yuv) {
		unsigned int chroma_cpp = format->bpp == 24 ? 2 : 1;

		if (mode_cmd->pitches[1] != mode_cmd->pitches[0] * chroma_cpp) {
			dev_dbg(dev->dev,
				"luma and chroma pitches do not match\n");
			return ERR_PTR(-EINVAL);
		}
	}

	return drm_gem_fb_create(dev, file_priv, mode_cmd);
}

int shmob_drm_modeset_init(struct shmob_drm_device *sdev)
{
	drm_mode_config_init(sdev->ddev);

	shmob_drm_crtc_create(sdev);
	shmob_drm_encoder_create(sdev);
	shmob_drm_connector_create(sdev, &sdev->encoder.encoder);

	drm_kms_helper_poll_init(sdev->ddev);

	sdev->ddev->mode_config.min_width = 0;
	sdev->ddev->mode_config.min_height = 0;
	sdev->ddev->mode_config.max_width = 4095;
	sdev->ddev->mode_config.max_height = 4095;
	sdev->ddev->mode_config.funcs = &shmob_drm_mode_config_funcs;

	drm_helper_disable_unused_functions(sdev->ddev);

	return 0;
}

