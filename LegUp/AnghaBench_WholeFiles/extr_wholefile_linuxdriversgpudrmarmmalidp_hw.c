#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct videomode {int flags; unsigned long hfront_porch; unsigned long hback_porch; unsigned long hsync_len; int hactive; int vactive; unsigned long pixelclock; int /*<<< orphan*/  vsync_len; int /*<<< orphan*/  vback_porch; int /*<<< orphan*/  vfront_porch; } ;
struct malidp_se_config {scalar_t__ hcoeff; scalar_t__ vcoeff; unsigned long input_w; unsigned long input_h; unsigned long output_h; unsigned long output_w; scalar_t__ scale_enable; } ;
struct malidp_irq_map {scalar_t__ irq_mask; scalar_t__ err_mask; scalar_t__ vsync_irq; } ;
struct malidp_hw_regmap {unsigned int n_pixel_formats; TYPE_1__* pixel_formats; } ;
struct malidp_hw_device {int pm_suspended; scalar_t__ regs; int min_line_size; int max_line_size; int* rotation_memory; scalar_t__ output_color_depth; scalar_t__ mw_state; struct malidp_hw* hw; int /*<<< orphan*/  mclk; } ;
struct TYPE_7__ {scalar_t__ vsync_irq; scalar_t__ irq_mask; } ;
struct TYPE_8__ {scalar_t__ se_base; scalar_t__ dc_base; int bus_align_bytes; int features; scalar_t__ out_depth_base; struct malidp_irq_map se_irq_map; TYPE_2__ dc_irq_map; struct malidp_irq_map de_irq_map; } ;
struct malidp_hw {TYPE_3__ map; int /*<<< orphan*/  (* set_config_valid ) (struct malidp_hw_device*,int) ;int /*<<< orphan*/  (* disable_memwrite ) (struct malidp_hw_device*) ;} ;
struct TYPE_9__ {scalar_t__ enabled; } ;
struct malidp_drm {struct malidp_hw_device* dev; int /*<<< orphan*/  config_valid; int /*<<< orphan*/  mw_connector; int /*<<< orphan*/  wq; TYPE_4__ crtc; int /*<<< orphan*/ * event; } ;
struct drm_device {int /*<<< orphan*/  dev; struct malidp_drm* dev_private; int /*<<< orphan*/  event_lock; } ;
typedef  int s32 ;
typedef  scalar_t__ s16 ;
typedef  scalar_t__ irqreturn_t ;
typedef  enum malidp_scaling_coeff_set { ____Placeholder_malidp_scaling_coeff_set } malidp_scaling_coeff_set ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_6__ {int layer; scalar_t__ format; int id; } ;

/* Variables and functions */
 int ARRAY_SIZE (int const*) ; 
 int DISPLAY_FLAGS_HSYNC_HIGH ; 
 int DISPLAY_FLAGS_INTERLACED ; 
 int DISPLAY_FLAGS_VSYNC_HIGH ; 
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,unsigned long) ; 
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
#define  DRM_FORMAT_ABGR1555 155 
#define  DRM_FORMAT_ABGR2101010 154 
#define  DRM_FORMAT_ABGR8888 153 
#define  DRM_FORMAT_ARGB2101010 152 
#define  DRM_FORMAT_ARGB8888 151 
#define  DRM_FORMAT_BGR565 150 
#define  DRM_FORMAT_BGR888 149 
#define  DRM_FORMAT_BGRA1010102 148 
#define  DRM_FORMAT_BGRA8888 147 
#define  DRM_FORMAT_BGRX8888 146 
#define  DRM_FORMAT_NV12 145 
#define  DRM_FORMAT_RGB565 144 
#define  DRM_FORMAT_RGB888 143 
#define  DRM_FORMAT_RGBA1010102 142 
#define  DRM_FORMAT_RGBA5551 141 
#define  DRM_FORMAT_RGBA8888 140 
#define  DRM_FORMAT_RGBX8888 139 
#define  DRM_FORMAT_UYVY 138 
#define  DRM_FORMAT_XBGR8888 137 
#define  DRM_FORMAT_XRGB8888 136 
#define  DRM_FORMAT_YUV420 135 
#define  DRM_FORMAT_YUYV 134 
 int EINVAL ; 
 scalar_t__ FP_0_36363 ; 
 scalar_t__ FP_0_50000 ; 
 scalar_t__ FP_0_66667 ; 
 scalar_t__ FP_1_00000 ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 scalar_t__ IRQ_HANDLED ; 
 scalar_t__ IRQ_NONE ; 
 scalar_t__ IRQ_WAKE_THREAD ; 
 scalar_t__ MALIDP500_BGND_COLOR ; 
 scalar_t__ MALIDP500_CONFIG_ID ; 
 scalar_t__ MALIDP500_CONFIG_VALID ; 
 scalar_t__ MALIDP500_DC_CLEAR_MASK ; 
 scalar_t__ MALIDP500_DC_CONFIG_REQ ; 
 scalar_t__ MALIDP500_DC_CONTROL ; 
 scalar_t__ MALIDP500_DE_V_FRONTPORCH (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP500_HSYNCPOL ; 
 scalar_t__ MALIDP500_SE_CONTROL ; 
 scalar_t__ MALIDP500_SE_MEMWRITE_BASE ; 
 scalar_t__ MALIDP500_SE_MEMWRITE_OUT_SIZE ; 
 scalar_t__ MALIDP500_SE_RGB_YUV_COEFFS ; 
 scalar_t__ MALIDP500_TIMINGS_BASE ; 
 scalar_t__ MALIDP500_VSYNCPOL ; 
 scalar_t__ MALIDP550_CONFIG_ID ; 
 scalar_t__ MALIDP550_CONFIG_VALID ; 
 scalar_t__ MALIDP550_DC_CONFIG_REQ ; 
 scalar_t__ MALIDP550_DC_CONTROL ; 
 scalar_t__ MALIDP550_DE_BGND_COLOR ; 
 scalar_t__ MALIDP550_DE_CONTROL ; 
 scalar_t__ MALIDP550_DE_V_FRONTPORCH (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP550_HSYNCPOL ; 
 scalar_t__ MALIDP550_SE_CONTROL ; 
 scalar_t__ MALIDP550_SE_CTL_HCSEL (scalar_t__) ; 
 scalar_t__ MALIDP550_SE_CTL_SEL_MASK ; 
 scalar_t__ MALIDP550_SE_CTL_VCSEL (scalar_t__) ; 
 scalar_t__ MALIDP550_SE_MEMWRITE_BASE ; 
 scalar_t__ MALIDP550_SE_MEMWRITE_ONESHOT ; 
 scalar_t__ MALIDP550_SE_MEMWRITE_OUT_SIZE ; 
 scalar_t__ MALIDP550_SE_RGB_YUV_COEFFS ; 
 scalar_t__ MALIDP550_TIMINGS_BASE ; 
 scalar_t__ MALIDP550_VSYNCPOL ; 
 int MALIDP_BGND_COLOR_B ; 
 int MALIDP_BGND_COLOR_G ; 
 int MALIDP_BGND_COLOR_R ; 
 scalar_t__ MALIDP_CFG_VALID ; 
 int MALIDP_COLORADJ_NUM_COEFFS ; 
 int /*<<< orphan*/  MALIDP_CONFIG_START ; 
 int /*<<< orphan*/  MALIDP_CONFIG_VALID_DONE ; 
#define  MALIDP_DC_BLOCK 133 
 int MALIDP_DE_BLOCK ; 
 scalar_t__ MALIDP_DE_DEFAULT_PREFETCH_START ; 
 scalar_t__ MALIDP_DE_DISPLAY_FUNC ; 
 scalar_t__ MALIDP_DE_HV_ACTIVE ; 
 scalar_t__ MALIDP_DE_H_ACTIVE (int) ; 
 scalar_t__ MALIDP_DE_H_BACKPORCH (unsigned long) ; 
 scalar_t__ MALIDP_DE_H_FRONTPORCH (unsigned long) ; 
 scalar_t__ MALIDP_DE_H_SYNCWIDTH (unsigned long) ; 
 scalar_t__ MALIDP_DE_H_TIMINGS ; 
 scalar_t__ MALIDP_DE_SYNC_WIDTH ; 
 scalar_t__ MALIDP_DE_V_ACTIVE (int) ; 
 scalar_t__ MALIDP_DE_V_BACKPORCH (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP_DE_V_SYNCWIDTH (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP_DE_V_TIMINGS ; 
 scalar_t__ MALIDP_DISP_FUNC_ILACED ; 
 int MALIDP_DOWNSCALING_1_5_COEFFS ; 
 int MALIDP_DOWNSCALING_2_75_COEFFS ; 
 int MALIDP_DOWNSCALING_2_COEFFS ; 
 int MALIDP_DOWNSCALING_4_COEFFS ; 
 int MALIDP_INVALID_FORMAT_ID ; 
 scalar_t__ MALIDP_MW_FORMAT ; 
 scalar_t__ MALIDP_MW_P1_PTR_HIGH ; 
 scalar_t__ MALIDP_MW_P1_PTR_LOW ; 
 scalar_t__ MALIDP_MW_P1_STRIDE ; 
 scalar_t__ MALIDP_MW_P2_PTR_HIGH ; 
 scalar_t__ MALIDP_MW_P2_PTR_LOW ; 
 scalar_t__ MALIDP_MW_P2_STRIDE ; 
 int MALIDP_REGMAP_HAS_CLEARIRQ ; 
 scalar_t__ MALIDP_REG_CLEARIRQ ; 
 scalar_t__ MALIDP_REG_MASKIRQ ; 
 scalar_t__ MALIDP_REG_STATUS ; 
 scalar_t__ MALIDP_SCALE_ENGINE_EN ; 
#define  MALIDP_SE_BLOCK 132 
 int MALIDP_SE_COEFFTAB_ADDR ; 
 int MALIDP_SE_COEFFTAB_ADDR_MASK ; 
 int MALIDP_SE_COEFFTAB_DATA ; 
 scalar_t__ MALIDP_SE_ENH_COEFF0 ; 
 int /*<<< orphan*/  MALIDP_SE_ENH_HIGH_LEVEL ; 
 int /*<<< orphan*/  MALIDP_SE_ENH_LOW_LEVEL ; 
 scalar_t__ MALIDP_SE_H_COEFFTAB ; 
 scalar_t__ MALIDP_SE_IMAGE_ENH ; 
 scalar_t__ MALIDP_SE_MEMWRITE_EN ; 
 scalar_t__ MALIDP_SE_SCALING_CONTROL ; 
 scalar_t__ MALIDP_SE_SET_COEFFTAB_DATA (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP_SE_SET_ENH_LIMIT_HIGH (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP_SE_SET_ENH_LIMIT_LOW (int /*<<< orphan*/ ) ; 
 scalar_t__ MALIDP_SE_V_COEFFTAB ; 
 int MALIDP_UPSCALING_COEFFS ; 
 scalar_t__ MW_NOT_ENABLED ; 
#define  MW_ONESHOT 131 
#define  MW_RESTART 130 
#define  MW_START 129 
#define  MW_STOP 128 
 int SZ_1K ; 
 int SZ_2K ; 
 void* SZ_4K ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 long clk_get_rate (int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ ,int,scalar_t__ (*) (int,void*),scalar_t__ (*) (int,void*),int /*<<< orphan*/ ,char*,struct drm_device*) ; 
 int /*<<< orphan*/ ** dp500_se_scaling_coeffs ; 
 int /*<<< orphan*/  drm_crtc_handle_vblank (TYPE_4__*) ; 
 int /*<<< orphan*/  drm_crtc_send_vblank_event (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int drm_format_plane_cpp (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_writeback_signal_completion (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ lower_32_bits (int /*<<< orphan*/ ) ; 
 unsigned long max (unsigned long,unsigned long) ; 
 unsigned long min (unsigned long,unsigned long) ; 
 scalar_t__ readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct malidp_hw_device*) ; 
 int /*<<< orphan*/  stub2 (struct malidp_hw_device*,int) ; 
 scalar_t__ upper_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline u32 malidp_hw_read(struct malidp_hw_device *hwdev, u32 reg)
{
	WARN_ON(hwdev->pm_suspended);
	return readl(hwdev->regs + reg);
}

__attribute__((used)) static inline void malidp_hw_write(struct malidp_hw_device *hwdev,
				   u32 value, u32 reg)
{
	WARN_ON(hwdev->pm_suspended);
	writel(value, hwdev->regs + reg);
}

__attribute__((used)) static inline void malidp_hw_setbits(struct malidp_hw_device *hwdev,
				     u32 mask, u32 reg)
{
	u32 data = malidp_hw_read(hwdev, reg);

	data |= mask;
	malidp_hw_write(hwdev, data, reg);
}

__attribute__((used)) static inline void malidp_hw_clearbits(struct malidp_hw_device *hwdev,
				       u32 mask, u32 reg)
{
	u32 data = malidp_hw_read(hwdev, reg);

	data &= ~mask;
	malidp_hw_write(hwdev, data, reg);
}

__attribute__((used)) static inline u32 malidp_get_block_base(struct malidp_hw_device *hwdev,
					u8 block)
{
	switch (block) {
	case MALIDP_SE_BLOCK:
		return hwdev->hw->map.se_base;
	case MALIDP_DC_BLOCK:
		return hwdev->hw->map.dc_base;
	}

	return 0;
}

__attribute__((used)) static inline void malidp_hw_disable_irq(struct malidp_hw_device *hwdev,
					 u8 block, u32 irq)
{
	u32 base = malidp_get_block_base(hwdev, block);

	malidp_hw_clearbits(hwdev, irq, base + MALIDP_REG_MASKIRQ);
}

__attribute__((used)) static inline void malidp_hw_enable_irq(struct malidp_hw_device *hwdev,
					u8 block, u32 irq)
{
	u32 base = malidp_get_block_base(hwdev, block);

	malidp_hw_setbits(hwdev, irq, base + MALIDP_REG_MASKIRQ);
}

__attribute__((used)) static inline u8 malidp_hw_get_pitch_align(struct malidp_hw_device *hwdev, bool rotated)
{
	/*
	 * only hardware that cannot do 8 bytes bus alignments have further
	 * constraints on rotated planes
	 */
	if (hwdev->hw->map.bus_align_bytes == 8)
		return 8;
	else
		return hwdev->hw->map.bus_align_bytes << (rotated ? 2 : 0);
}

__attribute__((used)) static inline enum malidp_scaling_coeff_set
malidp_se_select_coeffs(u32 upscale_factor)
{
	return (upscale_factor >= FP_1_00000) ? MALIDP_UPSCALING_COEFFS :
	       (upscale_factor >= FP_0_66667) ? MALIDP_DOWNSCALING_1_5_COEFFS :
	       (upscale_factor >= FP_0_50000) ? MALIDP_DOWNSCALING_2_COEFFS :
	       (upscale_factor >= FP_0_36363) ? MALIDP_DOWNSCALING_2_75_COEFFS :
	       MALIDP_DOWNSCALING_4_COEFFS;
}

__attribute__((used)) static inline void malidp_se_set_enh_coeffs(struct malidp_hw_device *hwdev)
{
	static const s32 enhancer_coeffs[] = {
		-8, -8, -8, -8, 128, -8, -8, -8, -8
	};
	u32 val = MALIDP_SE_SET_ENH_LIMIT_LOW(MALIDP_SE_ENH_LOW_LEVEL) |
		  MALIDP_SE_SET_ENH_LIMIT_HIGH(MALIDP_SE_ENH_HIGH_LEVEL);
	u32 image_enh = hwdev->hw->map.se_base +
			((hwdev->hw->map.features & MALIDP_REGMAP_HAS_CLEARIRQ) ?
			 0x10 : 0xC) + MALIDP_SE_IMAGE_ENH;
	u32 enh_coeffs = image_enh + MALIDP_SE_ENH_COEFF0;
	int i;

	malidp_hw_write(hwdev, val, image_enh);
	for (i = 0; i < ARRAY_SIZE(enhancer_coeffs); ++i)
		malidp_hw_write(hwdev, enhancer_coeffs[i], enh_coeffs + i * 4);
}

__attribute__((used)) static int malidp500_query_hw(struct malidp_hw_device *hwdev)
{
	u32 conf = malidp_hw_read(hwdev, MALIDP500_CONFIG_ID);
	/* bit 4 of the CONFIG_ID register holds the line size multiplier */
	u8 ln_size_mult = conf & 0x10 ? 2 : 1;

	hwdev->min_line_size = 2;
	hwdev->max_line_size = SZ_2K * ln_size_mult;
	hwdev->rotation_memory[0] = SZ_1K * 64 * ln_size_mult;
	hwdev->rotation_memory[1] = 0; /* no second rotation memory bank */

	return 0;
}

__attribute__((used)) static void malidp500_enter_config_mode(struct malidp_hw_device *hwdev)
{
	u32 status, count = 100;

	malidp_hw_setbits(hwdev, MALIDP500_DC_CONFIG_REQ, MALIDP500_DC_CONTROL);
	while (count) {
		status = malidp_hw_read(hwdev, hwdev->hw->map.dc_base + MALIDP_REG_STATUS);
		if ((status & MALIDP500_DC_CONFIG_REQ) == MALIDP500_DC_CONFIG_REQ)
			break;
		/*
		 * entering config mode can take as long as the rendering
		 * of a full frame, hence the long sleep here
		 */
		usleep_range(1000, 10000);
		count--;
	}
	WARN(count == 0, "timeout while entering config mode");
}

__attribute__((used)) static void malidp500_leave_config_mode(struct malidp_hw_device *hwdev)
{
	u32 status, count = 100;

	malidp_hw_clearbits(hwdev, MALIDP_CFG_VALID, MALIDP500_CONFIG_VALID);
	malidp_hw_clearbits(hwdev, MALIDP500_DC_CONFIG_REQ, MALIDP500_DC_CONTROL);
	while (count) {
		status = malidp_hw_read(hwdev, hwdev->hw->map.dc_base + MALIDP_REG_STATUS);
		if ((status & MALIDP500_DC_CONFIG_REQ) == 0)
			break;
		usleep_range(100, 1000);
		count--;
	}
	WARN(count == 0, "timeout while leaving config mode");
}

__attribute__((used)) static bool malidp500_in_config_mode(struct malidp_hw_device *hwdev)
{
	u32 status;

	status = malidp_hw_read(hwdev, hwdev->hw->map.dc_base + MALIDP_REG_STATUS);
	if ((status & MALIDP500_DC_CONFIG_REQ) == MALIDP500_DC_CONFIG_REQ)
		return true;

	return false;
}

__attribute__((used)) static void malidp500_set_config_valid(struct malidp_hw_device *hwdev, u8 value)
{
	if (value)
		malidp_hw_setbits(hwdev, MALIDP_CFG_VALID, MALIDP500_CONFIG_VALID);
	else
		malidp_hw_clearbits(hwdev, MALIDP_CFG_VALID, MALIDP500_CONFIG_VALID);
}

__attribute__((used)) static void malidp500_modeset(struct malidp_hw_device *hwdev, struct videomode *mode)
{
	u32 val = 0;

	malidp_hw_write(hwdev, hwdev->output_color_depth,
		hwdev->hw->map.out_depth_base);
	malidp_hw_clearbits(hwdev, MALIDP500_DC_CLEAR_MASK, MALIDP500_DC_CONTROL);
	if (mode->flags & DISPLAY_FLAGS_HSYNC_HIGH)
		val |= MALIDP500_HSYNCPOL;
	if (mode->flags & DISPLAY_FLAGS_VSYNC_HIGH)
		val |= MALIDP500_VSYNCPOL;
	val |= MALIDP_DE_DEFAULT_PREFETCH_START;
	malidp_hw_setbits(hwdev, val, MALIDP500_DC_CONTROL);

	/*
	 * Mali-DP500 encodes the background color like this:
	 *    - red   @ MALIDP500_BGND_COLOR[12:0]
	 *    - green @ MALIDP500_BGND_COLOR[27:16]
	 *    - blue  @ (MALIDP500_BGND_COLOR + 4)[12:0]
	 */
	val = ((MALIDP_BGND_COLOR_G & 0xfff) << 16) |
	      (MALIDP_BGND_COLOR_R & 0xfff);
	malidp_hw_write(hwdev, val, MALIDP500_BGND_COLOR);
	malidp_hw_write(hwdev, MALIDP_BGND_COLOR_B, MALIDP500_BGND_COLOR + 4);

	val = MALIDP_DE_H_FRONTPORCH(mode->hfront_porch) |
		MALIDP_DE_H_BACKPORCH(mode->hback_porch);
	malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_H_TIMINGS);

	val = MALIDP500_DE_V_FRONTPORCH(mode->vfront_porch) |
		MALIDP_DE_V_BACKPORCH(mode->vback_porch);
	malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_V_TIMINGS);

	val = MALIDP_DE_H_SYNCWIDTH(mode->hsync_len) |
		MALIDP_DE_V_SYNCWIDTH(mode->vsync_len);
	malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_SYNC_WIDTH);

	val = MALIDP_DE_H_ACTIVE(mode->hactive) | MALIDP_DE_V_ACTIVE(mode->vactive);
	malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_HV_ACTIVE);

	if (mode->flags & DISPLAY_FLAGS_INTERLACED)
		malidp_hw_setbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
	else
		malidp_hw_clearbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
}

__attribute__((used)) static int malidp500_rotmem_required(struct malidp_hw_device *hwdev, u16 w, u16 h, u32 fmt)
{
	/* RGB888 or BGR888 can't be rotated */
	if ((fmt == DRM_FORMAT_RGB888) || (fmt == DRM_FORMAT_BGR888))
		return -EINVAL;

	/*
	 * Each layer needs enough rotation memory to fit 8 lines
	 * worth of pixel data. Required size is then:
	 *    size = rotated_width * (bpp / 8) * 8;
	 */
	return w * drm_format_plane_cpp(fmt, 0) * 8;
}

__attribute__((used)) static void malidp500_se_write_pp_coefftab(struct malidp_hw_device *hwdev,
					   u32 direction,
					   u16 addr,
					   u8 coeffs_id)
{
	int i;
	u16 scaling_control = MALIDP500_SE_CONTROL + MALIDP_SE_SCALING_CONTROL;

	malidp_hw_write(hwdev,
			direction | (addr & MALIDP_SE_COEFFTAB_ADDR_MASK),
			scaling_control + MALIDP_SE_COEFFTAB_ADDR);
	for (i = 0; i < ARRAY_SIZE(dp500_se_scaling_coeffs); ++i)
		malidp_hw_write(hwdev, MALIDP_SE_SET_COEFFTAB_DATA(
				dp500_se_scaling_coeffs[coeffs_id][i]),
				scaling_control + MALIDP_SE_COEFFTAB_DATA);
}

__attribute__((used)) static int malidp500_se_set_scaling_coeffs(struct malidp_hw_device *hwdev,
					   struct malidp_se_config *se_config,
					   struct malidp_se_config *old_config)
{
	/* Get array indices into dp500_se_scaling_coeffs. */
	u8 h = (u8)se_config->hcoeff - 1;
	u8 v = (u8)se_config->vcoeff - 1;

	if (WARN_ON(h >= ARRAY_SIZE(dp500_se_scaling_coeffs) ||
		    v >= ARRAY_SIZE(dp500_se_scaling_coeffs)))
		return -EINVAL;

	if ((h == v) && (se_config->hcoeff != old_config->hcoeff ||
			 se_config->vcoeff != old_config->vcoeff)) {
		malidp500_se_write_pp_coefftab(hwdev,
					       (MALIDP_SE_V_COEFFTAB |
						MALIDP_SE_H_COEFFTAB),
					       0, v);
	} else {
		if (se_config->vcoeff != old_config->vcoeff)
			malidp500_se_write_pp_coefftab(hwdev,
						       MALIDP_SE_V_COEFFTAB,
						       0, v);
		if (se_config->hcoeff != old_config->hcoeff)
			malidp500_se_write_pp_coefftab(hwdev,
						       MALIDP_SE_H_COEFFTAB,
						       0, h);
	}

	return 0;
}

__attribute__((used)) static long malidp500_se_calc_mclk(struct malidp_hw_device *hwdev,
				   struct malidp_se_config *se_config,
				   struct videomode *vm)
{
	unsigned long mclk;
	unsigned long pxlclk = vm->pixelclock; /* Hz */
	unsigned long htotal = vm->hactive + vm->hfront_porch +
			       vm->hback_porch + vm->hsync_len;
	unsigned long input_size = se_config->input_w * se_config->input_h;
	unsigned long a = 10;
	long ret;

	/*
	 * mclk = max(a, 1.5) * pxlclk
	 *
	 * To avoid float calculaiton, using 15 instead of 1.5 and div by
	 * 10 to get mclk.
	 */
	if (se_config->scale_enable) {
		a = 15 * input_size / (htotal * se_config->output_h);
		if (a < 15)
			a = 15;
	}
	mclk = a * pxlclk / 10;
	ret = clk_get_rate(hwdev->mclk);
	if (ret < mclk) {
		DRM_DEBUG_DRIVER("mclk requirement of %lu kHz can't be met.\n",
				 mclk / 1000);
		return -EINVAL;
	}
	return ret;
}

__attribute__((used)) static int malidp500_enable_memwrite(struct malidp_hw_device *hwdev,
				     dma_addr_t *addrs, s32 *pitches,
				     int num_planes, u16 w, u16 h, u32 fmt_id,
				     const s16 *rgb2yuv_coeffs)
{
	u32 base = MALIDP500_SE_MEMWRITE_BASE;
	u32 de_base = malidp_get_block_base(hwdev, MALIDP_DE_BLOCK);

	/* enable the scaling engine block */
	malidp_hw_setbits(hwdev, MALIDP_SCALE_ENGINE_EN, de_base + MALIDP_DE_DISPLAY_FUNC);

	/* restart the writeback if already enabled */
	if (hwdev->mw_state != MW_NOT_ENABLED)
		hwdev->mw_state = MW_RESTART;
	else
		hwdev->mw_state = MW_START;

	malidp_hw_write(hwdev, fmt_id, base + MALIDP_MW_FORMAT);
	switch (num_planes) {
	case 2:
		malidp_hw_write(hwdev, lower_32_bits(addrs[1]), base + MALIDP_MW_P2_PTR_LOW);
		malidp_hw_write(hwdev, upper_32_bits(addrs[1]), base + MALIDP_MW_P2_PTR_HIGH);
		malidp_hw_write(hwdev, pitches[1], base + MALIDP_MW_P2_STRIDE);
		/* fall through */
	case 1:
		malidp_hw_write(hwdev, lower_32_bits(addrs[0]), base + MALIDP_MW_P1_PTR_LOW);
		malidp_hw_write(hwdev, upper_32_bits(addrs[0]), base + MALIDP_MW_P1_PTR_HIGH);
		malidp_hw_write(hwdev, pitches[0], base + MALIDP_MW_P1_STRIDE);
		break;
	default:
		WARN(1, "Invalid number of planes");
	}

	malidp_hw_write(hwdev, MALIDP_DE_H_ACTIVE(w) | MALIDP_DE_V_ACTIVE(h),
			MALIDP500_SE_MEMWRITE_OUT_SIZE);

	if (rgb2yuv_coeffs) {
		int i;

		for (i = 0; i < MALIDP_COLORADJ_NUM_COEFFS; i++) {
			malidp_hw_write(hwdev, rgb2yuv_coeffs[i],
					MALIDP500_SE_RGB_YUV_COEFFS + i * 4);
		}
	}

	malidp_hw_setbits(hwdev, MALIDP_SE_MEMWRITE_EN, MALIDP500_SE_CONTROL);

	return 0;
}

__attribute__((used)) static void malidp500_disable_memwrite(struct malidp_hw_device *hwdev)
{
	u32 base = malidp_get_block_base(hwdev, MALIDP_DE_BLOCK);

	if (hwdev->mw_state == MW_START || hwdev->mw_state == MW_RESTART)
		hwdev->mw_state = MW_STOP;
	malidp_hw_clearbits(hwdev, MALIDP_SE_MEMWRITE_EN, MALIDP500_SE_CONTROL);
	malidp_hw_clearbits(hwdev, MALIDP_SCALE_ENGINE_EN, base + MALIDP_DE_DISPLAY_FUNC);
}

__attribute__((used)) static int malidp550_query_hw(struct malidp_hw_device *hwdev)
{
	u32 conf = malidp_hw_read(hwdev, MALIDP550_CONFIG_ID);
	u8 ln_size = (conf >> 4) & 0x3, rsize;

	hwdev->min_line_size = 2;

	switch (ln_size) {
	case 0:
		hwdev->max_line_size = SZ_2K;
		/* two banks of 64KB for rotation memory */
		rsize = 64;
		break;
	case 1:
		hwdev->max_line_size = SZ_4K;
		/* two banks of 128KB for rotation memory */
		rsize = 128;
		break;
	case 2:
		hwdev->max_line_size = 1280;
		/* two banks of 40KB for rotation memory */
		rsize = 40;
		break;
	case 3:
		/* reserved value */
		hwdev->max_line_size = 0;
		return -EINVAL;
	}

	hwdev->rotation_memory[0] = hwdev->rotation_memory[1] = rsize * SZ_1K;
	return 0;
}

__attribute__((used)) static void malidp550_enter_config_mode(struct malidp_hw_device *hwdev)
{
	u32 status, count = 100;

	malidp_hw_setbits(hwdev, MALIDP550_DC_CONFIG_REQ, MALIDP550_DC_CONTROL);
	while (count) {
		status = malidp_hw_read(hwdev, hwdev->hw->map.dc_base + MALIDP_REG_STATUS);
		if ((status & MALIDP550_DC_CONFIG_REQ) == MALIDP550_DC_CONFIG_REQ)
			break;
		/*
		 * entering config mode can take as long as the rendering
		 * of a full frame, hence the long sleep here
		 */
		usleep_range(1000, 10000);
		count--;
	}
	WARN(count == 0, "timeout while entering config mode");
}

__attribute__((used)) static void malidp550_leave_config_mode(struct malidp_hw_device *hwdev)
{
	u32 status, count = 100;

	malidp_hw_clearbits(hwdev, MALIDP_CFG_VALID, MALIDP550_CONFIG_VALID);
	malidp_hw_clearbits(hwdev, MALIDP550_DC_CONFIG_REQ, MALIDP550_DC_CONTROL);
	while (count) {
		status = malidp_hw_read(hwdev, hwdev->hw->map.dc_base + MALIDP_REG_STATUS);
		if ((status & MALIDP550_DC_CONFIG_REQ) == 0)
			break;
		usleep_range(100, 1000);
		count--;
	}
	WARN(count == 0, "timeout while leaving config mode");
}

__attribute__((used)) static bool malidp550_in_config_mode(struct malidp_hw_device *hwdev)
{
	u32 status;

	status = malidp_hw_read(hwdev, hwdev->hw->map.dc_base + MALIDP_REG_STATUS);
	if ((status & MALIDP550_DC_CONFIG_REQ) == MALIDP550_DC_CONFIG_REQ)
		return true;

	return false;
}

__attribute__((used)) static void malidp550_set_config_valid(struct malidp_hw_device *hwdev, u8 value)
{
	if (value)
		malidp_hw_setbits(hwdev, MALIDP_CFG_VALID, MALIDP550_CONFIG_VALID);
	else
		malidp_hw_clearbits(hwdev, MALIDP_CFG_VALID, MALIDP550_CONFIG_VALID);
}

__attribute__((used)) static void malidp550_modeset(struct malidp_hw_device *hwdev, struct videomode *mode)
{
	u32 val = MALIDP_DE_DEFAULT_PREFETCH_START;

	malidp_hw_write(hwdev, hwdev->output_color_depth,
		hwdev->hw->map.out_depth_base);
	malidp_hw_write(hwdev, val, MALIDP550_DE_CONTROL);
	/*
	 * Mali-DP550 and Mali-DP650 encode the background color like this:
	 *   - red   @ MALIDP550_DE_BGND_COLOR[23:16]
	 *   - green @ MALIDP550_DE_BGND_COLOR[15:8]
	 *   - blue  @ MALIDP550_DE_BGND_COLOR[7:0]
	 *
	 * We need to truncate the least significant 4 bits from the default
	 * MALIDP_BGND_COLOR_x values
	 */
	val = (((MALIDP_BGND_COLOR_R >> 4) & 0xff) << 16) |
	      (((MALIDP_BGND_COLOR_G >> 4) & 0xff) << 8) |
	      ((MALIDP_BGND_COLOR_B >> 4) & 0xff);
	malidp_hw_write(hwdev, val, MALIDP550_DE_BGND_COLOR);

	val = MALIDP_DE_H_FRONTPORCH(mode->hfront_porch) |
		MALIDP_DE_H_BACKPORCH(mode->hback_porch);
	malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_H_TIMINGS);

	val = MALIDP550_DE_V_FRONTPORCH(mode->vfront_porch) |
		MALIDP_DE_V_BACKPORCH(mode->vback_porch);
	malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_V_TIMINGS);

	val = MALIDP_DE_H_SYNCWIDTH(mode->hsync_len) |
		MALIDP_DE_V_SYNCWIDTH(mode->vsync_len);
	if (mode->flags & DISPLAY_FLAGS_HSYNC_HIGH)
		val |= MALIDP550_HSYNCPOL;
	if (mode->flags & DISPLAY_FLAGS_VSYNC_HIGH)
		val |= MALIDP550_VSYNCPOL;
	malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_SYNC_WIDTH);

	val = MALIDP_DE_H_ACTIVE(mode->hactive) | MALIDP_DE_V_ACTIVE(mode->vactive);
	malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_HV_ACTIVE);

	if (mode->flags & DISPLAY_FLAGS_INTERLACED)
		malidp_hw_setbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
	else
		malidp_hw_clearbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
}

__attribute__((used)) static int malidp550_rotmem_required(struct malidp_hw_device *hwdev, u16 w, u16 h, u32 fmt)
{
	u32 bytes_per_col;

	/* raw RGB888 or BGR888 can't be rotated */
	if ((fmt == DRM_FORMAT_RGB888) || (fmt == DRM_FORMAT_BGR888))
		return -EINVAL;

	switch (fmt) {
	/* 8 lines at 4 bytes per pixel */
	case DRM_FORMAT_ARGB2101010:
	case DRM_FORMAT_ABGR2101010:
	case DRM_FORMAT_RGBA1010102:
	case DRM_FORMAT_BGRA1010102:
	case DRM_FORMAT_ARGB8888:
	case DRM_FORMAT_ABGR8888:
	case DRM_FORMAT_RGBA8888:
	case DRM_FORMAT_BGRA8888:
	case DRM_FORMAT_XRGB8888:
	case DRM_FORMAT_XBGR8888:
	case DRM_FORMAT_RGBX8888:
	case DRM_FORMAT_BGRX8888:
	case DRM_FORMAT_RGB888:
	case DRM_FORMAT_BGR888:
	/* 16 lines at 2 bytes per pixel */
	case DRM_FORMAT_RGBA5551:
	case DRM_FORMAT_ABGR1555:
	case DRM_FORMAT_RGB565:
	case DRM_FORMAT_BGR565:
	case DRM_FORMAT_UYVY:
	case DRM_FORMAT_YUYV:
		bytes_per_col = 32;
		break;
	/* 16 lines at 1.5 bytes per pixel */
	case DRM_FORMAT_NV12:
	case DRM_FORMAT_YUV420:
		bytes_per_col = 24;
		break;
	default:
		return -EINVAL;
	}

	return w * bytes_per_col;
}

__attribute__((used)) static int malidp550_se_set_scaling_coeffs(struct malidp_hw_device *hwdev,
					   struct malidp_se_config *se_config,
					   struct malidp_se_config *old_config)
{
	u32 mask = MALIDP550_SE_CTL_VCSEL(MALIDP550_SE_CTL_SEL_MASK) |
		   MALIDP550_SE_CTL_HCSEL(MALIDP550_SE_CTL_SEL_MASK);
	u32 new_value = MALIDP550_SE_CTL_VCSEL(se_config->vcoeff) |
			MALIDP550_SE_CTL_HCSEL(se_config->hcoeff);

	malidp_hw_clearbits(hwdev, mask, MALIDP550_SE_CONTROL);
	malidp_hw_setbits(hwdev, new_value, MALIDP550_SE_CONTROL);
	return 0;
}

__attribute__((used)) static long malidp550_se_calc_mclk(struct malidp_hw_device *hwdev,
				   struct malidp_se_config *se_config,
				   struct videomode *vm)
{
	unsigned long mclk;
	unsigned long pxlclk = vm->pixelclock;
	unsigned long htotal = vm->hactive + vm->hfront_porch +
			       vm->hback_porch + vm->hsync_len;
	unsigned long numerator = 1, denominator = 1;
	long ret;

	if (se_config->scale_enable) {
		numerator = max(se_config->input_w, se_config->output_w) *
			    se_config->input_h;
		numerator += se_config->output_w *
			     (se_config->output_h -
			      min(se_config->input_h, se_config->output_h));
		denominator = (htotal - 2) * se_config->output_h;
	}

	/* mclk can't be slower than pxlclk. */
	if (numerator < denominator)
		numerator = denominator = 1;
	mclk = (pxlclk * numerator) / denominator;
	ret = clk_get_rate(hwdev->mclk);
	if (ret < mclk) {
		DRM_DEBUG_DRIVER("mclk requirement of %lu kHz can't be met.\n",
				 mclk / 1000);
		return -EINVAL;
	}
	return ret;
}

__attribute__((used)) static int malidp550_enable_memwrite(struct malidp_hw_device *hwdev,
				     dma_addr_t *addrs, s32 *pitches,
				     int num_planes, u16 w, u16 h, u32 fmt_id,
				     const s16 *rgb2yuv_coeffs)
{
	u32 base = MALIDP550_SE_MEMWRITE_BASE;
	u32 de_base = malidp_get_block_base(hwdev, MALIDP_DE_BLOCK);

	/* enable the scaling engine block */
	malidp_hw_setbits(hwdev, MALIDP_SCALE_ENGINE_EN, de_base + MALIDP_DE_DISPLAY_FUNC);

	hwdev->mw_state = MW_ONESHOT;

	malidp_hw_write(hwdev, fmt_id, base + MALIDP_MW_FORMAT);
	switch (num_planes) {
	case 2:
		malidp_hw_write(hwdev, lower_32_bits(addrs[1]), base + MALIDP_MW_P2_PTR_LOW);
		malidp_hw_write(hwdev, upper_32_bits(addrs[1]), base + MALIDP_MW_P2_PTR_HIGH);
		malidp_hw_write(hwdev, pitches[1], base + MALIDP_MW_P2_STRIDE);
		/* fall through */
	case 1:
		malidp_hw_write(hwdev, lower_32_bits(addrs[0]), base + MALIDP_MW_P1_PTR_LOW);
		malidp_hw_write(hwdev, upper_32_bits(addrs[0]), base + MALIDP_MW_P1_PTR_HIGH);
		malidp_hw_write(hwdev, pitches[0], base + MALIDP_MW_P1_STRIDE);
		break;
	default:
		WARN(1, "Invalid number of planes");
	}

	malidp_hw_write(hwdev, MALIDP_DE_H_ACTIVE(w) | MALIDP_DE_V_ACTIVE(h),
			MALIDP550_SE_MEMWRITE_OUT_SIZE);
	malidp_hw_setbits(hwdev, MALIDP550_SE_MEMWRITE_ONESHOT | MALIDP_SE_MEMWRITE_EN,
			  MALIDP550_SE_CONTROL);

	if (rgb2yuv_coeffs) {
		int i;

		for (i = 0; i < MALIDP_COLORADJ_NUM_COEFFS; i++) {
			malidp_hw_write(hwdev, rgb2yuv_coeffs[i],
					MALIDP550_SE_RGB_YUV_COEFFS + i * 4);
		}
	}

	return 0;
}

__attribute__((used)) static void malidp550_disable_memwrite(struct malidp_hw_device *hwdev)
{
	u32 base = malidp_get_block_base(hwdev, MALIDP_DE_BLOCK);

	malidp_hw_clearbits(hwdev, MALIDP550_SE_MEMWRITE_ONESHOT | MALIDP_SE_MEMWRITE_EN,
			    MALIDP550_SE_CONTROL);
	malidp_hw_clearbits(hwdev, MALIDP_SCALE_ENGINE_EN, base + MALIDP_DE_DISPLAY_FUNC);
}

__attribute__((used)) static int malidp650_query_hw(struct malidp_hw_device *hwdev)
{
	u32 conf = malidp_hw_read(hwdev, MALIDP550_CONFIG_ID);
	u8 ln_size = (conf >> 4) & 0x3, rsize;

	hwdev->min_line_size = 4;

	switch (ln_size) {
	case 0:
	case 2:
		/* reserved values */
		hwdev->max_line_size = 0;
		return -EINVAL;
	case 1:
		hwdev->max_line_size = SZ_4K;
		/* two banks of 128KB for rotation memory */
		rsize = 128;
		break;
	case 3:
		hwdev->max_line_size = 2560;
		/* two banks of 80KB for rotation memory */
		rsize = 80;
	}

	hwdev->rotation_memory[0] = hwdev->rotation_memory[1] = rsize * SZ_1K;
	return 0;
}

u8 malidp_hw_get_format_id(const struct malidp_hw_regmap *map,
			   u8 layer_id, u32 format)
{
	unsigned int i;

	for (i = 0; i < map->n_pixel_formats; i++) {
		if (((map->pixel_formats[i].layer & layer_id) == layer_id) &&
		    (map->pixel_formats[i].format == format))
			return map->pixel_formats[i].id;
	}

	return MALIDP_INVALID_FORMAT_ID;
}

__attribute__((used)) static void malidp_hw_clear_irq(struct malidp_hw_device *hwdev, u8 block, u32 irq)
{
	u32 base = malidp_get_block_base(hwdev, block);

	if (hwdev->hw->map.features & MALIDP_REGMAP_HAS_CLEARIRQ)
		malidp_hw_write(hwdev, irq, base + MALIDP_REG_CLEARIRQ);
	else
		malidp_hw_write(hwdev, irq, base + MALIDP_REG_STATUS);
}

__attribute__((used)) static irqreturn_t malidp_de_irq(int irq, void *arg)
{
	struct drm_device *drm = arg;
	struct malidp_drm *malidp = drm->dev_private;
	struct malidp_hw_device *hwdev;
	struct malidp_hw *hw;
	const struct malidp_irq_map *de;
	u32 status, mask, dc_status;
	irqreturn_t ret = IRQ_NONE;

	hwdev = malidp->dev;
	hw = hwdev->hw;
	de = &hw->map.de_irq_map;

	/*
	 * if we are suspended it is likely that we were invoked because
	 * we share an interrupt line with some other driver, don't try
	 * to read the hardware registers
	 */
	if (hwdev->pm_suspended)
		return IRQ_NONE;

	/* first handle the config valid IRQ */
	dc_status = malidp_hw_read(hwdev, hw->map.dc_base + MALIDP_REG_STATUS);
	if (dc_status & hw->map.dc_irq_map.vsync_irq) {
		malidp_hw_clear_irq(hwdev, MALIDP_DC_BLOCK, dc_status);
		/* do we have a page flip event? */
		if (malidp->event != NULL) {
			spin_lock(&drm->event_lock);
			drm_crtc_send_vblank_event(&malidp->crtc, malidp->event);
			malidp->event = NULL;
			spin_unlock(&drm->event_lock);
		}
		atomic_set(&malidp->config_valid, MALIDP_CONFIG_VALID_DONE);
		ret = IRQ_WAKE_THREAD;
	}

	status = malidp_hw_read(hwdev, MALIDP_REG_STATUS);
	if (!(status & de->irq_mask))
		return ret;

	mask = malidp_hw_read(hwdev, MALIDP_REG_MASKIRQ);
	/* keep the status of the enabled interrupts, plus the error bits */
	status &= (mask | de->err_mask);
	if ((status & de->vsync_irq) && malidp->crtc.enabled)
		drm_crtc_handle_vblank(&malidp->crtc);

#ifdef CONFIG_DEBUG_FS
	if (status & de->err_mask) {
		malidp_error(malidp, &malidp->de_errors, status,
			     drm_crtc_vblank_count(&malidp->crtc));
	}
#endif
	malidp_hw_clear_irq(hwdev, MALIDP_DE_BLOCK, status);

	return (ret == IRQ_NONE) ? IRQ_HANDLED : ret;
}

__attribute__((used)) static irqreturn_t malidp_de_irq_thread_handler(int irq, void *arg)
{
	struct drm_device *drm = arg;
	struct malidp_drm *malidp = drm->dev_private;

	wake_up(&malidp->wq);

	return IRQ_HANDLED;
}

void malidp_de_irq_hw_init(struct malidp_hw_device *hwdev)
{
	/* ensure interrupts are disabled */
	malidp_hw_disable_irq(hwdev, MALIDP_DE_BLOCK, 0xffffffff);
	malidp_hw_clear_irq(hwdev, MALIDP_DE_BLOCK, 0xffffffff);
	malidp_hw_disable_irq(hwdev, MALIDP_DC_BLOCK, 0xffffffff);
	malidp_hw_clear_irq(hwdev, MALIDP_DC_BLOCK, 0xffffffff);

	/* first enable the DC block IRQs */
	malidp_hw_enable_irq(hwdev, MALIDP_DC_BLOCK,
			     hwdev->hw->map.dc_irq_map.irq_mask);

	/* now enable the DE block IRQs */
	malidp_hw_enable_irq(hwdev, MALIDP_DE_BLOCK,
			     hwdev->hw->map.de_irq_map.irq_mask);
}

int malidp_de_irq_init(struct drm_device *drm, int irq)
{
	struct malidp_drm *malidp = drm->dev_private;
	struct malidp_hw_device *hwdev = malidp->dev;
	int ret;

	/* ensure interrupts are disabled */
	malidp_hw_disable_irq(hwdev, MALIDP_DE_BLOCK, 0xffffffff);
	malidp_hw_clear_irq(hwdev, MALIDP_DE_BLOCK, 0xffffffff);
	malidp_hw_disable_irq(hwdev, MALIDP_DC_BLOCK, 0xffffffff);
	malidp_hw_clear_irq(hwdev, MALIDP_DC_BLOCK, 0xffffffff);

	ret = devm_request_threaded_irq(drm->dev, irq, malidp_de_irq,
					malidp_de_irq_thread_handler,
					IRQF_SHARED, "malidp-de", drm);
	if (ret < 0) {
		DRM_ERROR("failed to install DE IRQ handler\n");
		return ret;
	}

	malidp_de_irq_hw_init(hwdev);

	return 0;
}

void malidp_de_irq_fini(struct malidp_hw_device *hwdev)
{
	malidp_hw_disable_irq(hwdev, MALIDP_DE_BLOCK,
			      hwdev->hw->map.de_irq_map.irq_mask);
	malidp_hw_disable_irq(hwdev, MALIDP_DC_BLOCK,
			      hwdev->hw->map.dc_irq_map.irq_mask);
}

__attribute__((used)) static irqreturn_t malidp_se_irq(int irq, void *arg)
{
	struct drm_device *drm = arg;
	struct malidp_drm *malidp = drm->dev_private;
	struct malidp_hw_device *hwdev = malidp->dev;
	struct malidp_hw *hw = hwdev->hw;
	const struct malidp_irq_map *se = &hw->map.se_irq_map;
	u32 status, mask;

	/*
	 * if we are suspended it is likely that we were invoked because
	 * we share an interrupt line with some other driver, don't try
	 * to read the hardware registers
	 */
	if (hwdev->pm_suspended)
		return IRQ_NONE;

	status = malidp_hw_read(hwdev, hw->map.se_base + MALIDP_REG_STATUS);
	if (!(status & (se->irq_mask | se->err_mask)))
		return IRQ_NONE;

#ifdef CONFIG_DEBUG_FS
	if (status & se->err_mask)
		malidp_error(malidp, &malidp->se_errors, status,
			     drm_crtc_vblank_count(&malidp->crtc));
#endif
	mask = malidp_hw_read(hwdev, hw->map.se_base + MALIDP_REG_MASKIRQ);
	status &= mask;

	if (status & se->vsync_irq) {
		switch (hwdev->mw_state) {
		case MW_ONESHOT:
			drm_writeback_signal_completion(&malidp->mw_connector, 0);
			break;
		case MW_STOP:
			drm_writeback_signal_completion(&malidp->mw_connector, 0);
			/* disable writeback after stop */
			hwdev->mw_state = MW_NOT_ENABLED;
			break;
		case MW_RESTART:
			drm_writeback_signal_completion(&malidp->mw_connector, 0);
			/* fall through to a new start */
		case MW_START:
			/* writeback started, need to emulate one-shot mode */
			hw->disable_memwrite(hwdev);
			/*
			 * only set config_valid HW bit if there is no other update
			 * in progress or if we raced ahead of the DE IRQ handler
			 * and config_valid flag will not be update until later
			 */
			status = malidp_hw_read(hwdev, hw->map.dc_base + MALIDP_REG_STATUS);
			if ((atomic_read(&malidp->config_valid) != MALIDP_CONFIG_START) ||
			    (status & hw->map.dc_irq_map.vsync_irq))
				hw->set_config_valid(hwdev, 1);
			break;
		}
	}

	malidp_hw_clear_irq(hwdev, MALIDP_SE_BLOCK, status);

	return IRQ_HANDLED;
}

void malidp_se_irq_hw_init(struct malidp_hw_device *hwdev)
{
	/* ensure interrupts are disabled */
	malidp_hw_disable_irq(hwdev, MALIDP_SE_BLOCK, 0xffffffff);
	malidp_hw_clear_irq(hwdev, MALIDP_SE_BLOCK, 0xffffffff);

	malidp_hw_enable_irq(hwdev, MALIDP_SE_BLOCK,
			     hwdev->hw->map.se_irq_map.irq_mask);
}

__attribute__((used)) static irqreturn_t malidp_se_irq_thread_handler(int irq, void *arg)
{
	return IRQ_HANDLED;
}

int malidp_se_irq_init(struct drm_device *drm, int irq)
{
	struct malidp_drm *malidp = drm->dev_private;
	struct malidp_hw_device *hwdev = malidp->dev;
	int ret;

	/* ensure interrupts are disabled */
	malidp_hw_disable_irq(hwdev, MALIDP_SE_BLOCK, 0xffffffff);
	malidp_hw_clear_irq(hwdev, MALIDP_SE_BLOCK, 0xffffffff);

	ret = devm_request_threaded_irq(drm->dev, irq, malidp_se_irq,
					malidp_se_irq_thread_handler,
					IRQF_SHARED, "malidp-se", drm);
	if (ret < 0) {
		DRM_ERROR("failed to install SE IRQ handler\n");
		return ret;
	}

	hwdev->mw_state = MW_NOT_ENABLED;
	malidp_se_irq_hw_init(hwdev);

	return 0;
}

void malidp_se_irq_fini(struct malidp_hw_device *hwdev)
{
	malidp_hw_disable_irq(hwdev, MALIDP_SE_BLOCK,
			      hwdev->hw->map.se_irq_map.irq_mask);
}

